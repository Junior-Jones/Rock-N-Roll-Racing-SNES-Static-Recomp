#!/usr/bin/env python3
"""Compare observational Mesen CDL coverage with the source-proved V10.2 graph.

This is deliberately a one-way validation tool.  The CDL may expose an omission,
but it is never accepted as production/discovery authority and it never edits a
manifest or generated source.
"""

from __future__ import annotations

import argparse
import csv
import hashlib
import json
from pathlib import Path


CDL_CODE = 0x01
CDL_INDEX_8 = 0x10
CDL_MEMORY_8 = 0x20


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def context_modes(context: str) -> int:
    suffix = context.rsplit(":", 1)[-1]
    flags = 0
    if "M1" in suffix:
        flags |= CDL_MEMORY_8
    if "X1" in suffix:
        flags |= CDL_INDEX_8
    return flags


def load_manifest(path: Path) -> tuple[set[int], dict[int, int], int]:
    owned: set[int] = set()
    start_mode_union: dict[int, int] = {}
    rows = 0
    with path.open(newline="", encoding="utf-8-sig") as stream:
        for row in csv.DictReader(stream):
            rows += 1
            physical = int(row["physical"], 16)
            encoded = bytes.fromhex(row["bytes"])
            owned.update(range(physical, physical + len(encoded)))
            start_mode_union[physical] = (
                start_mode_union.get(physical, 0) | context_modes(row["context"])
            )
    return owned, start_mode_union, rows


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--manifest", type=Path, required=True)
    parser.add_argument("--cdl", type=Path, required=True)
    parser.add_argument("--rom", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()

    rom_size = args.rom.stat().st_size
    cdl = args.cdl.read_bytes()
    # The V02 Windows oracle emits one fewer byte for this exact 1 MiB image.
    # Treat that as an explicitly recorded tool limitation, not silent padding.
    if len(cdl) not in (rom_size, rom_size - 1):
        raise SystemExit(f"unexpected CDL size {len(cdl)} for ROM size {rom_size}")

    owned, start_mode_union, manifest_rows = load_manifest(args.manifest)
    # V02's CDL writer serializes this image as memory[1:] (the file is exactly
    # one byte short and every known entry point is one byte early).  Normalize
    # those observational offsets before comparison while recording the quirk.
    cdl_offset_bias = 1 if len(cdl) == rom_size - 1 else 0
    observed = {
        offset + cdl_offset_bias
        for offset, flags in enumerate(cdl)
        if flags & CDL_CODE
    }
    missing = sorted(observed - owned)

    # CDL mode flags are OR-accumulated.  Therefore the valid assertion is that
    # every observed mode bit on a known instruction start exists in at least
    # one source-proved context for that physical start.
    mode_mismatches = []
    observed_starts = 0
    for offset in sorted(observed & start_mode_union.keys()):
        observed_starts += 1
        observed_modes = cdl[offset - cdl_offset_bias] & (
            CDL_MEMORY_8 | CDL_INDEX_8
        )
        impossible = observed_modes & ~start_mode_union[offset]
        if impossible:
            mode_mismatches.append(
                {
                    "physical": f"{offset:06X}",
                    "observed_mode_bits": f"{observed_modes:02X}",
                    "source_mode_union": f"{start_mode_union[offset]:02X}",
                    "impossible_bits": f"{impossible:02X}",
                }
            )

    receipt = {
        "schema": "RRR_V10_2_ORACLE_RECONCILIATION_V1",
        "authority": "OBSERVATION_ONLY_NO_PROMOTION",
        "result": "PASS" if not missing and not mode_mismatches else "FAIL",
        "rom": {
            "bytes": rom_size,
            "sha256": sha256(args.rom),
        },
        "manifest": {
            "path": args.manifest.as_posix(),
            "rows": manifest_rows,
            "owned_instruction_bytes": len(owned),
            "instruction_start_offsets": len(start_mode_union),
            "sha256": sha256(args.manifest),
        },
        "cdl": {
            "path": args.cdl.as_posix(),
            "bytes": len(cdl),
            "sha256": sha256(args.cdl),
            "code_bytes_observed": len(observed),
            "source_known_starts_observed": observed_starts,
            "oracle_one_byte_short_limitation": len(cdl) == rom_size - 1,
            "normalized_physical_offset_bias": cdl_offset_bias,
        },
        "observed_code_bytes_outside_source_graph": len(missing),
        "observed_mode_mismatches": len(mode_mismatches),
        "first_outside_source_graph": [f"{offset:06X}" for offset in missing[:64]],
        "first_mode_mismatches": mode_mismatches[:64],
    }
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(receipt, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(receipt, indent=2))
    return 0 if receipt["result"] == "PASS" else 1


if __name__ == "__main__":
    raise SystemExit(main())
