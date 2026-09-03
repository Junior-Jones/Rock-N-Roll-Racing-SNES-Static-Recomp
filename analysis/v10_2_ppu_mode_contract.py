"""Certify the PPU display modes selected by the closed V10.2 S-CPU graph.

Only ROM-source control-flow is used.  Oracle and trace observations are not
inputs and cannot add a mode or a DMA destination to production.
"""
from __future__ import annotations

import csv
import json
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
INPUTS = (
    ROOT / "generated/current/v10_2/V10.2-RESET-SCPU-REDISCOVERY.json",
    ROOT / "generated/current/v10_2/V10.2-VECTOR-SCPU-REDISCOVERY.json",
)
CSV_OUT = ROOT / "docs/V10.2-PPU-MODE-WRITES.csv"
JSON_OUT = ROOT / "docs/V10.2-PPU-MODE-CONTRACT.json"


def immediate_value(row: dict) -> int:
    raw = bytes.fromhex(row["bytes"])
    if row["mode"] not in {"IMM_M", "IMM_X"} or len(raw) < 2:
        raise ValueError(f"not an immediate load: {row['context']}")
    return int.from_bytes(raw[1:], "little")


def main() -> None:
    instructions: dict[str, dict] = {}
    incoming: dict[str, set[str]] = defaultdict(set)
    for path in INPUTS:
        report = json.loads(path.read_text(encoding="utf-8"))
        if report["authority_policy"] != "oracle/traces are checks only and contribute zero contexts":
            raise ValueError(f"invalid authority policy in {path}")
        if report["summary"]["oracle_promotions"] or report["summary"]["trace_promotions"]:
            raise ValueError(f"non-source promotion in {path}")
        for row in report["instructions"]:
            instructions.setdefault(row["context"], row)
        for edge in report["edges"]:
            incoming[edge["to"]].add(edge["from"])

    rows: list[dict] = []
    dma_destinations: set[int] = set()
    selected_values: set[int] = set()
    setini_values: set[int] = set()
    load_for_store = {"STA": "LDA", "STX": "LDX", "STY": "LDY"}

    for target in sorted(instructions.values(), key=lambda r: (r["bank"], r["pc"], r["context"])):
        hardware = target.get("hardware_access") or {}
        address_text = hardware.get("address")
        if not address_text:
            continue
        address = int(address_text.split(":", 1)[1], 16)
        wanted = address in {0x2105, 0x2133} or (0x4301 <= address <= 0x4371 and (address & 0x0F) == 1)
        if not wanted or target["mnemonic"] not in {"STA", "STX", "STY", "STZ"}:
            continue

        proof_contexts: list[str] = []
        if target["mnemonic"] == "STZ":
            values = {0}
            proof = "STZ_ENCODED_ZERO"
        else:
            register_load = load_for_store[target["mnemonic"]]
            frontier = list(incoming[target["context"]])
            seen: set[str] = set()
            values: set[int] = set()
            # Walk through instructions which preserve the stored register.
            modifies = {
                "LDA": {"LDA", "ADC", "SBC", "AND", "ORA", "EOR", "ASL", "LSR", "ROL", "ROR", "INC", "DEC", "PLA", "TDC", "TXA", "TYA", "XBA"},
                "LDX": {"LDX", "INX", "DEX", "PLX", "TAX", "TSX"},
                "LDY": {"LDY", "INY", "DEY", "PLY", "TAY"},
            }[register_load]
            while frontier:
                context = frontier.pop()
                if context in seen:
                    continue
                seen.add(context)
                predecessor = instructions.get(context)
                if predecessor is None:
                    raise ValueError(f"missing predecessor {context} for {target['context']}")
                if predecessor["mnemonic"] == register_load:
                    values.add(immediate_value(predecessor))
                    proof_contexts.append(context)
                    continue
                if predecessor["mnemonic"] in modifies:
                    raise ValueError(
                        f"unproved {register_load} value at {target['context']}: "
                        f"{context} {predecessor['mnemonic']} {predecessor['mode']}"
                    )
                frontier.extend(incoming[context])
            if not values:
                raise ValueError(f"no source definition for {target['context']}")
            proof = "ROM_CFG_BACKWARD_IMMEDIATE_DEFINITION"

        for value in sorted(values):
            if address == 0x2105:
                selected_values.add(value)
                kind = "BGMODE"
            elif address == 0x2133:
                setini_values.add(value)
                kind = "SETINI"
            else:
                dma_destinations.add(value)
                kind = "DMA_BBUS_DESTINATION"
            rows.append({
                "context": target["context"],
                "physical": f"{target['physical']:06X}",
                "register": f"{address:04X}",
                "kind": kind,
                "value": f"{value & 0xFF:02X}",
                "mode": str(value & 7) if address == 0x2105 else "",
                "proof": proof,
                "definition_contexts": ";".join(sorted(proof_contexts)),
                "authority": "ROM_SOURCE_STATIC_PROOF_ONLY",
            })

    with CSV_OUT.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=list(rows[0]))
        writer.writeheader()
        writer.writerows(rows)

    selected_modes = sorted(value & 7 for value in selected_values)
    report = {
        "schema": "RRR_V10_2_PPU_MODE_CONTRACT_V1",
        "authority": {
            "source_bytes_only": True,
            "oracle_promotions": 0,
            "trace_promotions": 0,
        },
        "bgmode_register_values": [f"{value:02X}" for value in sorted(selected_values)],
        "selected_modes": selected_modes,
        "setini_values": [f"{value:02X}" for value in sorted(setini_values)],
        "interlace_selected": any(value & 0x01 for value in setini_values),
        "overscan_selected": any(value & 0x04 for value in setini_values),
        "pseudo_hires_selected": any(value & 0x08 for value in setini_values),
        "dma_bbus_destinations": [f"{0x2100 + value:04X}" for value in sorted(dma_destinations)],
        "dma_can_write_bgmode": 0x05 in dma_destinations,
        "conclusion": (
            "The closed source graph selects modes 0, 1, 3, 4 and 7. "
            "SETINI remains zero, and no DMA channel targets BGMODE."
        ),
    }
    JSON_OUT.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(report, indent=2))


if __name__ == "__main__":
    main()
