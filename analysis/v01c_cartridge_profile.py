#!/usr/bin/env python3
"""Rock n' Roll Racing V01C cartridge identity/census generator.

This is a read-only, game-targeted intake analyser.  It does not disassemble code,
execute CPU instructions, or infer targets from traces.  It emits deterministic
V01C evidence from the supplied ROM bytes and fails closed on unsupported or
ambiguous cartridge identity.
"""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
import sys
import zlib
from dataclasses import dataclass
from pathlib import Path

SCHEMA = 1
EXPECTED_CANONICAL_SHA256 = "9d721753301278325c851f1843d669a697aed757dcf6495a31fc31ddf664b182"
EXPECTED_CANONICAL_SIZE = 1_048_576
EXPECTED_TITLE = "ROCK N' ROLL RACING"


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def canonicalize(raw: bytes) -> tuple[bytes, int]:
    # SNES copier headers are conventionally 512 bytes.  Never rewrite input.
    if len(raw) % 1024 == 512:
        return raw[512:], 512
    return raw, 0


def u16le(data: bytes, off: int) -> int:
    if off < 0 or off + 2 > len(data):
        raise ValueError(f"u16 read out of range at 0x{off:X}")
    return data[off] | (data[off + 1] << 8)


def printable_title(data: bytes) -> tuple[str, int]:
    printable = sum(1 for b in data if b == 0x20 or 0x21 <= b <= 0x7E)
    return data.decode("ascii", "replace").rstrip(" \0"), printable


def mapping_from_mode(mode: int) -> tuple[str, str] | None:
    return {
        0x20: ("LoROM", "SlowROM"),
        0x21: ("HiROM", "SlowROM"),
        0x30: ("LoROM", "FastROM"),
        0x31: ("HiROM", "FastROM"),
    }.get(mode)


@dataclass(frozen=True)
class HeaderCandidate:
    file_offset: int
    site_name: str
    expected_mapping: str


def parse_candidate(rom: bytes, candidate: HeaderCandidate, rom_sum16: int) -> dict:
    h = candidate.file_offset
    if h + 0x40 > len(rom):
        return {
            "site": candidate.site_name,
            "header_file_offset": f"0x{h:X}",
            "present": False,
            "score": -999,
            "reasons": ["candidate lies outside canonical ROM"],
        }
    title_raw = rom[h:h + 21]
    title, printable = printable_title(title_raw)
    mode = rom[h + 0x15]
    rom_type = rom[h + 0x16]
    rom_size_code = rom[h + 0x17]
    sram_size_code = rom[h + 0x18]
    region_code = rom[h + 0x19]
    maker_code = rom[h + 0x1A]
    version = rom[h + 0x1B]
    complement = u16le(rom, h + 0x1C)
    checksum = u16le(rom, h + 0x1E)
    mapping = mapping_from_mode(mode)
    emu_reset = u16le(rom, h + 0x3C)

    score = 0
    reasons: list[str] = []
    if printable >= 18 and title:
        score += 4
        reasons.append("mostly printable nonempty title")
    if ((checksum + complement) & 0xFFFF) == 0xFFFF and checksum != 0:
        score += 4
        reasons.append("checksum/complement pair sums to 0xFFFF")
    if checksum == rom_sum16 and checksum != 0:
        score += 4
        reasons.append("stored checksum equals canonical ROM byte sum")
    if emu_reset >= 0x8000:
        score += 2
        reasons.append("emulation RESET vector is in upper bank half")
    if mapping is not None:
        score += 2
        reasons.append(f"recognized map mode 0x{mode:02X}")
        if mapping[0] == candidate.expected_mapping:
            score += 2
            reasons.append("map mode agrees with candidate header site")
        else:
            score -= 4
            reasons.append("map mode conflicts with candidate header site")
    if 8 <= rom_size_code <= 13:
        score += 1
        reasons.append("plausible ROM size code")

    return {
        "site": candidate.site_name,
        "header_file_offset": f"0x{h:06X}",
        "present": True,
        "score": score,
        "title": title,
        "title_bytes_hex": title_raw.hex(),
        "map_mode": f"0x{mode:02X}",
        "mapping": mapping[0] if mapping else "UNKNOWN",
        "speed": mapping[1] if mapping else "UNKNOWN",
        "rom_type": f"0x{rom_type:02X}",
        "rom_size_code": rom_size_code,
        "sram_size_code": sram_size_code,
        "region_code": f"0x{region_code:02X}",
        "maker_code": f"0x{maker_code:02X}",
        "version": version,
        "checksum_complement": f"0x{complement:04X}",
        "checksum": f"0x{checksum:04X}",
        "emulation_reset": f"0x{emu_reset:04X}",
        "reasons": reasons,
    }


def read_vectors(rom: bytes, header_off: int) -> dict[str, str]:
    # Header-relative native table: +24..+2F; emulation table: +34..+3F.
    vector_offsets = {
        "native_cop": 0x24,
        "native_brk": 0x26,
        "native_abort": 0x28,
        "native_nmi": 0x2A,
        "native_reset_reserved": 0x2C,
        "native_irq": 0x2E,
        "emulation_cop": 0x34,
        "emulation_reserved": 0x36,
        "emulation_abort": 0x38,
        "emulation_nmi": 0x3A,
        "emulation_reset": 0x3C,
        "emulation_irq_brk": 0x3E,
    }
    return {name: f"0x{u16le(rom, header_off + rel):04X}" for name, rel in vector_offsets.items()}


def canonical_lorom_offset(cpu_address: int, rom_size: int) -> int:
    """Translate only unique 1 MiB LoROM analysis windows; reject aliases/invalids.

    This is deliberately not the later runtime bus mapper.  V01C only needs an
    unambiguous physical-byte translator for source evidence.  Mirror aliases are
    not guessed or folded with modulo arithmetic.
    """
    if not 0 <= cpu_address <= 0xFFFFFF:
        raise ValueError("CPU address must be 24-bit")
    bank = (cpu_address >> 16) & 0xFF
    addr = cpu_address & 0xFFFF
    if addr < 0x8000:
        raise ValueError("not in canonical LoROM ROM half-bank")
    logical_bank = bank & 0x7F
    unique_banks = rom_size // 0x8000
    if logical_bank >= unique_banks:
        raise ValueError("LoROM alias/mirror is outside V01C canonical unique window")
    physical = logical_bank * 0x8000 + (addr - 0x8000)
    if physical >= rom_size:
        raise ValueError("translated physical offset outside ROM")
    return physical


def census_rows(rom_size: int, header_off: int) -> list[dict[str, str]]:
    if header_off != 0x7FC0:
        raise ValueError("V01C census generator currently accepts selected LoROM header at 0x7FC0 only")
    header_end = header_off + 0x3F
    rows = [
        {
            "Physical_Start": "000000",
            "Physical_End": f"{header_off - 1:06X}",
            "Classification": "UNRESOLVED",
            "Confidence": "EXPLICIT_UNKNOWN",
            "Mapped_CPU_Addresses": "canonical LoROM physical bytes; exact code/data roles deferred to 03C",
            "Producer": "exact ROM bytes",
            "Consumer": "future whole-ROM discovery",
            "Proof_ID": "BYTE-V01C-UNRESOLVED-A",
            "Conflict_ID": "",
            "Phase": "V01C",
            "Notes": "No disassembly is permitted in 01C; do not relabel as data.",
        },
        {
            "Physical_Start": f"{header_off:06X}",
            "Physical_End": f"{header_end:06X}",
            "Classification": "HEADER_VECTOR",
            "Confidence": "SOURCE_PROVED",
            "Mapped_CPU_Addresses": "00:FFC0-FFFF and 80:FFC0-FFFF canonical LoROM aliases",
            "Producer": "SNES internal header/vector layout + exact ROM bytes",
            "Consumer": "cartridge identity and vector seeding in later milestones",
            "Proof_ID": "BYTE-V01C-HEADER-VECTORS",
            "Conflict_ID": "",
            "Phase": "V01C",
            "Notes": "Selected by checksum/title/map-mode/reset-vector evidence; HiROM candidate rejected.",
        },
        {
            "Physical_Start": f"{header_end + 1:06X}",
            "Physical_End": f"{rom_size - 1:06X}",
            "Classification": "UNRESOLVED",
            "Confidence": "EXPLICIT_UNKNOWN",
            "Mapped_CPU_Addresses": "canonical LoROM physical bytes; exact code/data roles deferred to 03C",
            "Producer": "exact ROM bytes",
            "Consumer": "future whole-ROM discovery",
            "Proof_ID": "BYTE-V01C-UNRESOLVED-B",
            "Conflict_ID": "",
            "Phase": "V01C",
            "Notes": "No disassembly is permitted in 01C; do not relabel as data.",
        },
    ]
    return rows


def validate_census(rows: list[dict[str, str]], rom_size: int) -> dict[str, int]:
    cursor = 0
    totals: dict[str, int] = {}
    for row in rows:
        start = int(row["Physical_Start"], 16)
        end = int(row["Physical_End"], 16)
        if start != cursor or end < start:
            raise ValueError(f"census gap/overlap before {row}")
        count = end - start + 1
        totals[row["Classification"]] = totals.get(row["Classification"], 0) + count
        cursor = end + 1
    if cursor != rom_size:
        raise ValueError(f"census ends at 0x{cursor:X}, expected 0x{rom_size:X}")
    if sum(totals.values()) != rom_size:
        raise ValueError("census total does not equal canonical ROM size")
    return totals


def write_json(path: Path, obj: object) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(obj, indent=2, sort_keys=True) + "\n", encoding="utf-8", newline="\n")


def write_census(path: Path, rows: list[dict[str, str]]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    fields = [
        "Physical_Start", "Physical_End", "Classification", "Confidence",
        "Mapped_CPU_Addresses", "Producer", "Consumer", "Proof_ID",
        "Conflict_ID", "Phase", "Notes",
    ]
    with path.open("w", encoding="utf-8", newline="") as f:
        w = csv.DictWriter(f, fieldnames=fields, lineterminator="\n")
        w.writeheader()
        w.writerows(rows)


def build_outputs(input_path: Path) -> tuple[dict, dict, list[dict[str, str]], dict]:
    raw = input_path.read_bytes()
    canonical, copier = canonicalize(raw)
    original_sha = sha256(raw)
    canonical_sha = sha256(canonical)
    if canonical_sha != EXPECTED_CANONICAL_SHA256:
        raise ValueError(f"unsupported ROM SHA-256 {canonical_sha}")
    if len(canonical) != EXPECTED_CANONICAL_SIZE:
        raise ValueError(f"unsupported canonical size {len(canonical)}")

    rom_sum16 = sum(canonical) & 0xFFFF
    candidates = [
        parse_candidate(canonical, HeaderCandidate(0x7FC0, "LoROM", "LoROM"), rom_sum16),
        parse_candidate(canonical, HeaderCandidate(0xFFC0, "HiROM", "HiROM"), rom_sum16),
        parse_candidate(canonical, HeaderCandidate(0x407FC0, "ExLoROM", "LoROM"), rom_sum16),
        parse_candidate(canonical, HeaderCandidate(0x40FFC0, "ExHiROM", "HiROM"), rom_sum16),
    ]
    present = [c for c in candidates if c.get("present")]
    selected = max(present, key=lambda c: int(c["score"]))
    ordered_scores = sorted((int(c["score"]) for c in present), reverse=True)
    if len(ordered_scores) < 2 or ordered_scores[0] - ordered_scores[1] < 6:
        raise ValueError("header candidate is not sufficiently unambiguous")
    if selected["header_file_offset"] != "0x007FC0":
        raise ValueError("expected LoROM header was not the selected candidate")
    if selected["title"] != EXPECTED_TITLE:
        raise ValueError(f"unexpected title {selected['title']!r}")
    if selected["map_mode"] != "0x30" or selected["mapping"] != "LoROM" or selected["speed"] != "FastROM":
        raise ValueError("unsupported mapper/speed")
    if selected["rom_type"] != "0x00" or selected["sram_size_code"] != 0:
        raise ValueError("unexpected RAM/enhancement cartridge type")
    if selected["region_code"] != "0x01":
        raise ValueError("unexpected region code")
    if selected["checksum"] != f"0x{rom_sum16:04X}":
        raise ValueError("stored checksum does not equal canonical ROM byte sum")

    vectors = read_vectors(canonical, 0x7FC0)
    rows = census_rows(len(canonical), 0x7FC0)
    totals = validate_census(rows, len(canonical))

    # Explicit unique-window mapping checks used as identity evidence, not runtime bus implementation.
    mapping_examples = {
        "00:8000": f"0x{canonical_lorom_offset(0x008000, len(canonical)):06X}",
        "00:FFFC": f"0x{canonical_lorom_offset(0x00FFFC, len(canonical)):06X}",
        "1F:FFFF": f"0x{canonical_lorom_offset(0x1FFFFF, len(canonical)):06X}",
        "80:8000": f"0x{canonical_lorom_offset(0x808000, len(canonical)):06X}",
        "9F:FFFF": f"0x{canonical_lorom_offset(0x9FFFFF, len(canonical)):06X}",
    }

    profile = {
        "schema": SCHEMA,
        "target_name": "Rock n' Roll Racing (USA) SNES static recomp",
        "rom": {
            "expected_input_filename": "Rock n' Roll Racing (USA).sfc",
            "original_sha256": original_sha,
            "canonical_sha256": canonical_sha,
            "original_size_bytes": len(raw),
            "canonical_size_bytes": len(canonical),
            "copier_header_bytes": copier,
            "crc32": f"{zlib.crc32(canonical) & 0xFFFFFFFF:08X}",
            "sum16": f"0x{rom_sum16:04X}",
            "region_revision": "USA / NTSC, header version 0",
        },
        "cartridge": {
            "selected_header_file_offset": "0x007FC0",
            "mapping": "LoROM",
            "speed": "FastROM",
            "map_mode": "0x30",
            "rom_type": "0x00 (ROM only)",
            "rom_size_code": 10,
            "sram_size_code": 0,
            "sram_bytes": 0,
            "enhancement_hardware": [],
            "exact_pcb_board_id": "UNKNOWN_FROM_ROM_IMAGE",
            "board_class_claim": "standard ROM-only FastROM LoROM cartridge profile; exact PCB marking not asserted",
            "analysis_mapping_policy": "canonical unique 1 MiB LoROM windows only; unproved mirror aliases reject instead of modulo-wrap",
            "mapping_examples": mapping_examples,
        },
        "internal_header": {
            "title": selected["title"],
            "maker_code": selected["maker_code"],
            "version": selected["version"],
            "checksum": selected["checksum"],
            "checksum_complement": selected["checksum_complement"],
            "checksum_pair_valid": True,
            "checksum_matches_canonical_byte_sum": True,
            "region_code": selected["region_code"],
        },
        "vectors": vectors,
        "context_key": ["PBR", "PC", "E", "M", "X"],
        "unknown_context_policy": "FAIL_CLOSED",
        "runtime_cpu_decoder_allowed": False,
        "candidate_observation_is_proof": False,
        "byte_ownership_manifest": "config/byte-ownership.csv",
        "recoverable_predecessor_sha256": "NONE_INITIAL_V01C",
        "notes": [
            "V01C contains no disassembly and no runtime game code.",
            "All non-header/vector ROM bytes remain explicitly UNRESOLVED until source-proof discovery milestones.",
            "Mesen observations may corroborate testing but do not authorize cartridge fields or code targets.",
        ],
    }

    evidence = {
        "schema": SCHEMA,
        "authority": "exact ROM bytes plus documented SNES header/vector layout",
        "canonical_rom_sha256": canonical_sha,
        "canonical_rom_size_bytes": len(canonical),
        "canonical_crc32": profile["rom"]["crc32"],
        "canonical_sum16": profile["rom"]["sum16"],
        "copier_header_bytes": copier,
        "header_candidates": candidates,
        "selected_header": selected,
        "selection_margin": ordered_scores[0] - ordered_scores[1],
        "vectors": vectors,
        "mapping_examples": mapping_examples,
        "census_totals": totals,
        "census_total_bytes": sum(totals.values()),
    }

    census_summary = {
        "schema": SCHEMA,
        "canonical_rom_sha256": canonical_sha,
        "total_bytes": len(canonical),
        "classification_totals": totals,
        "classified_non_unresolved_bytes": len(canonical) - totals.get("UNRESOLVED", 0),
        "unresolved_bytes": totals.get("UNRESOLVED", 0),
    }
    return profile, evidence, rows, census_summary


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("rom", type=Path)
    ap.add_argument("--output-root", type=Path, required=True)
    args = ap.parse_args(argv)
    try:
        profile, evidence, rows, census_summary = build_outputs(args.rom)
        root = args.output_root
        write_json(root / "config" / "target-profile.json", profile)
        write_json(root / "docs" / "V01C-cartridge-evidence.json", evidence)
        write_census(root / "config" / "byte-ownership.csv", rows)
        write_json(root / "docs" / "V01C-byte-census-summary.json", census_summary)
    except Exception as exc:
        print(f"V01C_FAIL {exc}", file=sys.stderr)
        return 2
    print(f"V01C_PROFILE_PASS sha256={profile['rom']['canonical_sha256']} size={profile['rom']['canonical_size_bytes']}")
    print(f"V01C_CENSUS_PASS total={census_summary['total_bytes']} unresolved={census_summary['unresolved_bytes']}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
