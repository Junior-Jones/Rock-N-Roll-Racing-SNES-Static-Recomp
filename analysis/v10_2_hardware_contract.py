"""Build the V10.2 source-derived S-CPU hardware-access contract.

The input is the closed RESET/native-vector instruction union.  This tool does
not use oracle traces or gameplay observations and cannot promote execution.
Indexed absolute sites are deliberately retained as indexed bases: the runtime
must implement the complete hardware register ranges rather than guessing a
single observed X/Y value.
"""
from __future__ import annotations

import csv
import json
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
INPUTS = (
    ROOT / "generated/current/v10_2/V10.2-RESET-SCPU-REDISCOVERY.json",
    ROOT / "generated/current/v10_2/V10.2-VECTOR-SCPU-REDISCOVERY.json",
)
CSV_OUT = ROOT / "docs/V10.2-SCPU-HARDWARE-ACCESS-CONTRACT.csv"
JSON_OUT = ROOT / "docs/V10.2-SCPU-HARDWARE-ACCESS-SUMMARY.json"

WRITE_MNEMONICS = {"STA", "STX", "STY", "STZ"}
READ_MODIFY_WRITE = {"ASL", "DEC", "INC", "LSR", "ROL", "ROR", "TRB", "TSB"}


def classify(address: int) -> tuple[str, str]:
    if 0x2100 <= address <= 0x213F:
        return "PPU", f"{address:04X}"
    if 0x2140 <= address <= 0x217F:
        return "APUIO", f"{0x2140 + (address & 3):04X}"
    if 0x2180 <= address <= 0x2183:
        return "WRAM_PORT", f"{address:04X}"
    if address in (0x4016, 0x4017) or 0x4218 <= address <= 0x421F:
        return "INPUT", f"{address:04X}"
    if 0x4200 <= address <= 0x421F:
        return "CPU_IO", f"{address:04X}"
    if 0x4300 <= address <= 0x437F:
        return "DMA_HDMA", f"{address:04X}"
    raise ValueError(f"unexpected hardware address ${address:04X}")


def access_kind(mnemonic: str) -> str:
    if mnemonic in WRITE_MNEMONICS:
        return "WRITE"
    if mnemonic in READ_MODIFY_WRITE:
        return "READ_MODIFY_WRITE"
    return "READ"


def main() -> None:
    contexts: dict[str, dict] = {}
    input_counts: dict[str, int] = {}
    for path in INPUTS:
        report = json.loads(path.read_text(encoding="utf-8"))
        policy = report["authority_policy"]
        summary = report["summary"]
        if policy != "oracle/traces are checks only and contribute zero contexts" \
                or summary["oracle_promotions"] != 0 or summary["trace_promotions"] != 0:
            raise ValueError(f"non-source promotion in {path}")
        input_counts[path.name] = len(report["instructions"])
        for row in report["instructions"]:
            prior = contexts.setdefault(row["context"], row)
            if (prior["bytes"], prior["mnemonic"], prior["mode"]) != (
                row["bytes"], row["mnemonic"], row["mode"]
            ):
                raise ValueError(f"context disagreement: {row['context']}")

    rows: list[dict] = []
    for context, instruction in sorted(contexts.items()):
        hardware = instruction.get("hardware_access")
        if hardware is None:
            continue
        address = int(hardware["address"].split(":", 1)[1], 16)
        area, canonical = classify(address)
        rows.append({
            "context": context,
            "physical": f"{instruction['physical']:06X}",
            "bytes": instruction["bytes"],
            "mnemonic": instruction["mnemonic"],
            "mode": instruction["mode"],
            "access": access_kind(instruction["mnemonic"]),
            "base_address": f"{address:04X}",
            "canonical_register": canonical,
            "area": area,
            "indexed": "YES" if hardware["indexed"] else "NO",
            "authority": "ROM_SOURCE_STATIC_PROOF_ONLY",
        })

    fieldnames = list(rows[0])
    with CSV_OUT.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(rows)

    area_counts = Counter(row["area"] for row in rows)
    registers: dict[str, set[str]] = defaultdict(set)
    access_types: dict[str, set[str]] = defaultdict(set)
    for row in rows:
        registers[row["area"]].add(row["canonical_register"])
        access_types[row["area"]].add(row["access"])
    indexed = [row for row in rows if row["indexed"] == "YES"]
    summary = {
        "schema": "RRR_V10_2_SCPU_HARDWARE_ACCESS_CONTRACT_V1",
        "authority": {
            "source_bytes_only": True,
            "oracle_promotions": 0,
            "trace_promotions": 0,
            "runtime_policy": "implement complete hardware ranges; fail closed outside owned semantics",
        },
        "input_instruction_counts": input_counts,
        "union_instruction_contexts": len(contexts),
        "hardware_access_contexts": len(rows),
        "area_context_counts": dict(sorted(area_counts.items())),
        "area_registers": {key: sorted(value) for key, value in sorted(registers.items())},
        "area_access_types": {key: sorted(value) for key, value in sorted(access_types.items())},
        "indexed_base_sites": [
            {key: row[key] for key in ("context", "mnemonic", "mode", "base_address", "area")}
            for row in indexed
        ],
        "indexed_policy": (
            "An ABS_X/ABS_Y base is not collapsed to an observed index. Device ownership covers "
            "the full architectural register ranges, and runtime addresses are validated there."
        ),
        "required_machine_domains": [
            "LoROM/open-bus/WRAM mapping and access speed",
            "PPU registers and rendering",
            "APUIO and complete static SMP/DSP execution",
            "WRAM data port",
            "controller serial and auto-joy",
            "CPU interrupt/timer/multiply/divide registers",
            "all eight architectural DMA/HDMA channels",
        ],
    }
    JSON_OUT.write_text(json.dumps(summary, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(summary, indent=2))


if __name__ == "__main__":
    main()
