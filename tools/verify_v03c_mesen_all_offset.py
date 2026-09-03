#!/usr/bin/env python3
"""Independently verify the V03C all-offset decode census from pinned MesenCE RunOp.

This checker intentionally does not import the project opcode table or V03C decoder.
It derives opcode address modes from the pinned MesenCE 2.2.1 source and independently
computes instruction lengths for every physical ROM offset in every legal E/M/X state.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import re
import struct
import zipfile
from collections import Counter
from pathlib import Path

ROM_SHA256 = "9d721753301278325c851f1843d669a697aed757dcf6495a31fc31ddf664b182"
ROM_SIZE = 0x100000
MEMBER = r"Mesen Linux Source\Core\SNES\SnesCpu.Shared.h"
LEGAL_CONTEXTS = ((0,0,0),(0,0,1),(0,1,0),(0,1,1),(1,1,1))

MODE_MAP = {
    "Abs":"ABS", "AbsIdxX":"ABS_X", "AbsIdxY":"ABS_Y", "AbsLng":"ABS_LONG", "AbsLngIdxX":"ABS_LONG_X",
    "AbsJmp":"ABS_JUMP", "AbsLngJmp":"ABSL_JUMP", "AbsInd":"ABS_IND", "AbsIndLng":"ABS_IND_LONG",
    "Acc":"ACC", "BlkMov":"BLOCK", "Dir":"DP", "DirIdxX":"DP_X", "DirIdxY":"DP_Y", "DirInd":"DP_IND",
    "DirIdxIndX":"DP_X_IND", "DirIndIdxY":"DP_IND_Y", "DirIndLng":"DP_IND_LONG", "DirIndLngIdxY":"DP_IND_LONG_Y",
    "Imm8":"SIG8", "Imm16":"IMM16", "ImmX":"IMM_X", "ImmM":"IMM_M", "Imp":"IMP", "RelLng":"REL16", "Rel":"REL8",
    "StkRel":"STACK_REL", "StkRelIndIdxY":"STACK_REL_IND_Y",
}
SPECIAL_MODE = {0x22:"ABSL_JUMP", 0x7C:"ABS_X_IND", 0xFC:"ABS_X_IND"}

LEN1 = {"IMP", "ACC"}
LEN2 = {"SIG8", "IMM8", "DP", "DP_X", "DP_Y", "DP_IND", "DP_X_IND", "DP_IND_Y", "DP_IND_LONG", "DP_IND_LONG_Y",
        "STACK_REL", "STACK_REL_IND_Y", "REL8"}
LEN3 = {"ABS", "ABS_X", "ABS_Y", "ABS_JUMP", "ABS_IND", "ABS_X_IND", "ABS_IND_LONG", "REL16", "IMM16", "BLOCK"}
LEN4 = {"ABS_LONG", "ABS_LONG_X", "ABSL_JUMP"}


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def parse_cases(text: str) -> dict[int, str]:
    pat = re.compile(r"case\s+0x([0-9A-Fa-f]{2}):\s*(.*?)\s*break;", re.S)
    cases = {int(h, 16): body.strip() for h, body in pat.findall(text)}
    if set(cases) != set(range(256)):
        missing = sorted(set(range(256)) - set(cases))
        raise RuntimeError(f"RunOp coverage invalid: count={len(cases)} missing={missing}")
    return cases


def mode_for(op: int, body: str) -> str:
    if op in SPECIAL_MODE:
        return SPECIAL_MODE[op]
    match = re.search(r"AddrMode_([A-Za-z0-9]+)\s*\(", body)
    if not match:
        return "IMP"
    key = match.group(1)
    if key not in MODE_MAP:
        raise RuntimeError(f"unknown Mesen address mode {key!r} for opcode ${op:02X}")
    mode = MODE_MAP[key]
    if key == "Imm8" and op in (0xC2, 0xE2):
        mode = "IMM8"
    return mode


def insn_len(mode: str, m: int, x: int) -> int:
    if mode in LEN1: return 1
    if mode in LEN2: return 2
    if mode in LEN3: return 3
    if mode in LEN4: return 4
    if mode == "IMM_M": return 2 if m else 3
    if mode == "IMM_X": return 2 if x else 3
    raise RuntimeError(f"no independent length rule for mode {mode}")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("rom", type=Path)
    ap.add_argument("mesen_source_zip", type=Path)
    ap.add_argument("summary", type=Path)
    ap.add_argument("--output", type=Path)
    ns = ap.parse_args()

    rom = ns.rom.read_bytes()
    if len(rom) != ROM_SIZE or sha256(rom) != ROM_SHA256:
        raise SystemExit("refusing verification: ROM identity/size does not match frozen V01C authority")

    source_zip_raw = ns.mesen_source_zip.read_bytes()
    with zipfile.ZipFile(ns.mesen_source_zip) as zf:
        src = zf.read(MEMBER)
    text = src.decode("utf-8-sig")
    cases = parse_cases(text[text.index("void SnesCpu::RunOp"):])
    modes = [mode_for(op, cases[op]) for op in range(256)]
    mode_hist = Counter(modes)

    h = hashlib.sha256()
    length_hist = Counter()
    invalid = 0
    rows = 0
    for off, opcode in enumerate(rom):
        within = off & 0x7FFF
        mode = modes[opcode]
        for idx, (_e, m, x) in enumerate(LEGAL_CONTEXTS):
            n = insn_len(mode, m, x)
            valid = 1 if within + n <= 0x8000 else 0
            invalid += 1 - valid
            length_hist[str(n)] += 1
            rows += 1
            h.update(struct.pack("<IBBBB", off, idx, opcode, n, valid))

    expected = json.loads(ns.summary.read_text(encoding="utf-8"))["all_offset_scan"]
    checks = {
        "physical_offsets": len(rom) == expected["physical_offsets"],
        "legal_contexts_per_offset": len(LEGAL_CONTEXTS) == expected["legal_contexts_per_offset"],
        "rows": rows == expected["rows"],
        "invalid_fetch_rows_at_lorom_bank_boundary": invalid == expected["invalid_fetch_rows_at_lorom_bank_boundary"],
        "instruction_length_histogram": dict(sorted(length_hist.items())) == expected["instruction_length_histogram"],
        "row_digest_sha256": h.hexdigest() == expected["row_digest_sha256"],
    }
    ok = all(checks.values())
    lines = [
        "V03C MESENCE INDEPENDENT ALL-OFFSET DECODER CHECK",
        f"ROM SHA-256: {sha256(rom)}",
        f"Mesen source ZIP SHA-256: {sha256(source_zip_raw)}",
        f"{MEMBER} SHA-256: {sha256(src)}",
        f"RunOp cases parsed: {len(cases)}",
        f"Independent Mesen-derived mode classes used: {len(mode_hist)}",
        f"Rows independently recomputed: {rows}",
        f"Invalid LoROM bank-boundary fetch rows: {invalid}",
        f"Independent row digest: {h.hexdigest()}",
        f"Expected row digest: {expected['row_digest_sha256']}",
    ]
    lines.extend(f"Check {name}: {'PASS' if passed else 'FAIL'}" for name, passed in checks.items())
    lines.append(f"Result: {'PASS' if ok else 'FAIL'}")
    out = "\n".join(lines) + "\n"
    if ns.output:
        ns.output.parent.mkdir(parents=True, exist_ok=True)
        ns.output.write_text(out, encoding="utf-8")
    print(out, end="")
    return 0 if ok else 1


if __name__ == "__main__":
    raise SystemExit(main())
