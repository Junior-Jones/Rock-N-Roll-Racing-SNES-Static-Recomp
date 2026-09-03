#!/usr/bin/env python3
"""Generate exact per-context S-CPU timing plans for the V10.2 union."""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
from pathlib import Path

try:
    from generator.v07c_scheduler_gen import ACCESS_FIELDS
except ModuleNotFoundError:
    from v07c_scheduler_gen import ACCESS_FIELDS

ROOT = Path(__file__).resolve().parents[1]
MODES = [
    "ABS", "ABS_IND", "ABS_JUMP", "ABS_LONG", "ABS_LONG_X", "ABS_X",
    "ABS_X_IND", "ABS_Y", "ABSL_JUMP", "ACC", "BLOCK", "DP", "DP_IND",
    "DP_IND_LONG", "DP_IND_LONG_Y", "DP_IND_Y", "DP_X", "IMM_M", "IMM_X",
    "IMM16", "IMM8", "IMP", "REL16", "REL8", "STACK_REL",
]
MODE_ID = {mode: index for index, mode in enumerate(MODES)}
PUSH = {"PHA", "PHB", "PHK", "PHP", "PHX", "PHY", "PHD", "PEA", "PEI"}
PULL = {"PLA", "PLB", "PLP", "PLX", "PLY", "PLD"}
RMW = {"INC", "DEC", "ASL", "LSR", "ROL", "ROR"}
RULE_BITS = {
    "DYN_DIRECT_LOW_PRE_IDLE": 1 << 0,
    "DYN_INDEX_PRE_DATA_IDLE": 1 << 1,
    "DYN_BRANCH_TAKEN_POST_IDLE": 1 << 2,
    "DYN_BRANCH_PAGE_POST_IDLE": 1 << 3,
    "JSL_AFTER_PBR_PUSH_IDLE": 1 << 4,
    "JSR_PRE_STACK_IDLE": 1 << 5,
    "JSR_XIND_MID_IDLE": 1 << 6,
    "RETURN_PRE_IDLE": 1 << 7,
    "RTS_POST_POP_IDLE": 1 << 8,
    "PUSH_PRE_IDLE": 1 << 9,
    "PULL_PRE_IDLE": 1 << 10,
    "IMPLIED_PRE_IDLE": 1 << 11,
    "XBA_EXTRA_IDLE": 1 << 12,
    "STATUS_PRE_IDLE": 1 << 13,
    "BRANCH_ALWAYS_POST_IDLE": 1 << 14,
    "RELLONG_PRE_IDLE": 1 << 15,
    "RMW_INTERMEDIATE_IDLE": 1 << 16,
    "STACK_REL_PRE_DATA_IDLE": 1 << 17,
    "INDEX_FIXED_PRE_DATA_IDLE": 1 << 18,
    "JUMP_XIND_PRE_POINTER_IDLE": 1 << 19,
    "BLOCK_MOVE_PRE_READ_IDLE": 1 << 20,
    "BLOCK_MOVE_POST_WRITE_IDLE": 1 << 21,
}


def read_csv(path: Path) -> list[dict]:
    with path.open(encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle))


def write_csv(path: Path, fields: list[str], rows: list[dict]) -> None:
    with path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=fields, lineterminator="\n")
        writer.writeheader()
        writer.writerows(rows)


def digest(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def operand(raw: bytes) -> int:
    value = 0
    for index, byte in enumerate(raw[1:]):
        value |= byte << (index * 8)
    return value


def context_modes(context: str) -> tuple[str, str, str]:
    modes = context.rsplit(":", 1)[1]
    return modes[1], modes[3], modes[5]


def rule_mask(rules: list[str]) -> int:
    result = 0
    for rule in rules:
        if rule != "BOUNDARY_NO_EXECUTION":
            result |= RULE_BITS[rule]
    return result


def timing_rules(production: dict, contract: dict) -> tuple[list[str], int, int]:
    if production["disposition"] == "SOURCE_PROVED_TERMINAL":
        return ["BOUNDARY_NO_EXECUTION"], 0, 0
    bus_cycles = sum(int(contract[field]) for field in ACCESS_FIELDS)
    idle_min = int(contract["Cycle_Min"]) - bus_cycles
    idle_max = int(contract["Cycle_Max"]) - bus_cycles
    mnemonic = production["mnemonic"]
    mode = production["mode"]
    dynamic = contract["Dynamic_Cycle_Tags"]
    fixed: list[str] = []
    variable: list[str] = []
    if idle_min:
        if mnemonic == "JSL":
            fixed = ["JSL_AFTER_PBR_PUSH_IDLE"]
        elif mnemonic == "JSR" and mode == "ABS_JUMP":
            fixed = ["JSR_PRE_STACK_IDLE"]
        elif mnemonic == "JSR" and mode == "ABS_X_IND":
            fixed = ["JSR_XIND_MID_IDLE"]
        elif mnemonic == "JMP" and mode == "ABS_X_IND":
            fixed = ["JUMP_XIND_PRE_POINTER_IDLE"]
        elif mnemonic == "RTS":
            fixed = ["RETURN_PRE_IDLE", "RETURN_PRE_IDLE", "RTS_POST_POP_IDLE"]
        elif mnemonic in {"RTL", "RTI"}:
            fixed = ["RETURN_PRE_IDLE", "RETURN_PRE_IDLE"]
        elif mnemonic in PUSH:
            fixed = ["PUSH_PRE_IDLE"] * idle_min
        elif mnemonic in PULL:
            fixed = ["PULL_PRE_IDLE"] * idle_min
        elif mnemonic == "XBA":
            fixed = ["IMPLIED_PRE_IDLE", "XBA_EXTRA_IDLE"]
        elif mnemonic in {"REP", "SEP"}:
            fixed = ["STATUS_PRE_IDLE"]
        elif mnemonic == "BRA":
            fixed = ["BRANCH_ALWAYS_POST_IDLE"]
        elif mnemonic == "BRL":
            fixed = ["RELLONG_PRE_IDLE"]
        elif mnemonic == "MVN":
            fixed = ["BLOCK_MOVE_PRE_READ_IDLE", "BLOCK_MOVE_POST_WRITE_IDLE"]
        elif mode in {"IMP", "ACC"}:
            fixed = ["IMPLIED_PRE_IDLE"] * idle_min
        elif mnemonic in RMW and mode != "ACC":
            # Mesen's 65816 implementation performs two distinct idles for
            # indexed memory RMW instructions: the addressing-mode index idle
            # before the data access, then the RMW idle between read and write.
            # Repeating the RMW label collapses those into one runtime action.
            fixed = ["RMW_INTERMEDIATE_IDLE"]
            if mode in {"ABS_X", "DP_X"}:
                fixed.insert(0, "INDEX_FIXED_PRE_DATA_IDLE")
        elif mode == "STACK_REL":
            fixed = ["STACK_REL_PRE_DATA_IDLE"] * idle_min
        elif mode in {"ABS_X", "ABS_Y", "DP_IND_Y", "DP_X"}:
            fixed = ["INDEX_FIXED_PRE_DATA_IDLE"] * idle_min
        else:
            raise ValueError(
                f"unclassified fixed idle {production['context']} {mnemonic}/{mode} {idle_min}"
            )
    if "DIRECT_LOW_NONZERO" in dynamic:
        variable.append("DYN_DIRECT_LOW_PRE_IDLE")
    if "INDEX_PAGE_CROSS" in dynamic:
        variable.append("DYN_INDEX_PRE_DATA_IDLE")
    if "BRANCH_TAKEN" in dynamic:
        variable.append("DYN_BRANCH_TAKEN_POST_IDLE")
    if "BRANCH_PAGE_CROSS_EMULATION" in dynamic:
        variable.append("DYN_BRANCH_PAGE_POST_IDLE")
    if len(fixed) != idle_min or idle_max != idle_min + len(variable):
        raise ValueError(
            f"idle mismatch {production['context']}: {idle_min}/{idle_max} "
            f"fixed={fixed} dynamic={variable}"
        )
    return fixed + variable, idle_min, idle_max


def timing_class(rules: list[str]) -> str:
    if rules == ["BOUNDARY_NO_EXECUTION"]:
        return "BOUNDARY_NO_EXECUTION"
    tags = set(rules)
    if any("BLOCK_MOVE" in tag for tag in tags):
        return "BLOCK_MOVE_SEQUENCE"
    if any("JSL_" in tag for tag in tags):
        return "JSL_DEFERRED_BANK_FETCH"
    if any(tag.startswith("RETURN_") or tag.startswith("RTS_") for tag in tags):
        return "RETURN_SEQUENCE"
    if any("BRANCH" in tag for tag in tags):
        return "BRANCH_SEQUENCE"
    if any(tag.startswith("RMW_") for tag in tags):
        return "RMW_SEQUENCE"
    if any("INDEX" in tag or "XIND" in tag for tag in tags):
        return "INDEX_SEQUENCE"
    if any(tag.startswith("DYN_DIRECT") for tag in tags):
        return "DIRECT_SEQUENCE"
    return "FIXED_IDLE_SEQUENCE" if rules else "LINEAR_BUS_SEQUENCE"


def header() -> str:
    mode_lines = ",\n    ".join(
        f"JSV10_2_MODE_{mode}={index}" for index, mode in enumerate(MODES)
    )
    rule_lines = "\n".join(
        f"#define JSV10_2_RULE_{name} 0x{value:08X}u"
        for name, value in RULE_BITS.items()
    )
    return f"""#ifndef ROCKNROLL_V10_2_TIMING_H
#define ROCKNROLL_V10_2_TIMING_H
#include <stddef.h>
#include <stdint.h>
#ifdef __cplusplus
extern \"C\" {{
#endif
typedef enum JSV10_2Mode {{
    {mode_lines}
}} JSV10_2Mode;
{rule_lines}
typedef struct JSV10_2TimingPlan {{
    uint32_t key, address, operand, rule_flags;
    uint8_t opcode, length, e, m, x, mode, cycle_min, cycle_max;
    uint8_t fetch_bytes, pointer_reads, data_reads, data_writes, dummy_writes;
    uint8_t stack_reads, stack_writes, vector_reads, fixed_idles, dynamic_idle_max;
    uint8_t executable;
    uint8_t bytes[4];
    const char *timing_class;
    const char *rules;
}} JSV10_2TimingPlan;
const JSV10_2TimingPlan *js_v10_2_timing_plan(uint32_t key);
size_t js_v10_2_timing_plan_count(void);
#ifdef __cplusplus
}}
#endif
#endif
"""


def generate(root: Path) -> dict:
    manifest_path = root / "docs/V10.2-SCPU-PRODUCTION-MANIFEST.csv"
    matrix_path = root / "docs/V02C-opcode-context-matrix.csv"
    production = read_csv(manifest_path)
    contracts = {
        (row["Opcode"], row["E"], row["M"], row["X"]): row
        for row in read_csv(matrix_path) if row["Status"] == "LEGAL"
    }
    rows: list[dict] = []
    for item in production:
        e, m, x = context_modes(item["context"])
        opcode = item["bytes"][:2]
        contract = contracts[(opcode, e, m, x)]
        rules, idle_min, idle_max = timing_rules(item, contract)
        raw = bytes.fromhex(item["bytes"])
        bank_pc = item["context"].split(":")
        rows.append({
            "production_id": item["production_id"],
            "context": item["context"], "key_hex": item["key_hex"],
            "pbr": bank_pc[0], "pc": bank_pc[1], "e": e, "m": m, "x": x,
            "opcode": opcode, "mnemonic": item["mnemonic"], "mode": item["mode"],
            "length": item["length"], "bytes": item["bytes"],
            "production_disposition": item["disposition"],
            "cycle_min": contract["Cycle_Min"], "cycle_max": contract["Cycle_Max"],
            "dynamic_cycle_tags": contract["Dynamic_Cycle_Tags"],
            "fetch_bytes": contract["Fetch_Bytes"],
            "pointer_reads": contract["Pointer_Read_Bytes"],
            "data_reads": contract["Data_Read_Bytes"],
            "data_writes": contract["Data_Write_Bytes"],
            "dummy_writes": contract["Dummy_Write_Bytes"],
            "stack_reads": contract["Stack_Read_Bytes"],
            "stack_writes": contract["Stack_Write_Bytes"],
            "vector_reads": contract["Vector_Read_Bytes"],
            "fixed_idles": idle_min, "dynamic_idle_max": idle_max - idle_min,
            "timing_class": timing_class(rules), "timing_rules": ";".join(rules),
            "rule_flags": f"{rule_mask(rules):08X}",
            "operand": f"{operand(raw):06X}",
            "address": f"{(int(bank_pc[0], 16) << 16) | int(bank_pc[1], 16):06X}",
            "executable": 0 if item["disposition"] == "SOURCE_PROVED_TERMINAL" else 1,
            "authority": "V02C exact opcode contract plus V10.2 source-proved context union",
        })
    write_csv(root / "docs/V10.2-SCPU-TIMING-MANIFEST.csv", list(rows[0]), rows)

    out = root / "generated/current/v10_2/timing"
    out.mkdir(parents=True, exist_ok=True)
    (out / "js_v10_2_timing.h").write_text(header(), encoding="utf-8", newline="\n")
    lines = [
        '#include "js_v10_2_timing.h"', "",
        "static const JSV10_2TimingPlan PLANS[] = {",
    ]
    for row in rows:
        raw = bytes.fromhex(row["bytes"]) + bytes(4)
        byte_text = ",".join(f"0x{byte:02X}u" for byte in raw[:4])
        timing_name = row["timing_class"].replace('"', '\\"')
        rule_text = row["timing_rules"].replace('"', '\\"')
        scalars = [
            int(row["opcode"], 16), int(row["length"]), int(row["e"]),
            int(row["m"]), int(row["x"]), MODE_ID[row["mode"]],
            int(row["cycle_min"]), int(row["cycle_max"]), int(row["fetch_bytes"]),
            int(row["pointer_reads"]), int(row["data_reads"]), int(row["data_writes"]),
            int(row["dummy_writes"]), int(row["stack_reads"]), int(row["stack_writes"]),
            int(row["vector_reads"]), int(row["fixed_idles"]),
            int(row["dynamic_idle_max"]), int(row["executable"]),
        ]
        scalar_text = ",".join(f"{value}u" for value in scalars)
        lines.append(
            f"    {{0x{row['key_hex']}u,0x{row['address']}u,0x{row['operand']}u,"
            f"0x{row['rule_flags']}u,{scalar_text},{{{byte_text}}},"
            f"\"{timing_name}\",\"{rule_text}\"}},"
        )
    lines.extend([
        "};", "",
        "size_t js_v10_2_timing_plan_count(void) { return sizeof PLANS / sizeof PLANS[0]; }",
        "const JSV10_2TimingPlan *js_v10_2_timing_plan(uint32_t key) {",
        "    size_t lo = 0u, hi = js_v10_2_timing_plan_count();",
        "    while (lo < hi) { size_t mid = lo + (hi - lo) / 2u;",
        "        if (PLANS[mid].key < key) lo = mid + 1u; else hi = mid; }",
        "    return lo < js_v10_2_timing_plan_count() && PLANS[lo].key == key ? &PLANS[lo] : 0;",
        "}", "",
    ])
    (out / "js_v10_2_timing.c").write_text("\n".join(lines), encoding="utf-8", newline="\n")
    class_counts: dict[str, int] = {}
    for row in rows:
        class_counts[row["timing_class"]] = class_counts.get(row["timing_class"], 0) + 1
    summary = {
        "schema": "rock-n-roll-racing-v10.2-scpu-timing-v1",
        "contexts": len(rows),
        "executable_contexts": sum(int(row["executable"]) for row in rows),
        "terminal_contexts": sum(not int(row["executable"]) for row in rows),
        "timing_class_counts": dict(sorted(class_counts.items())),
        "master_time_unit": "one SNES master clock",
        "normal_scanline_clocks": 1364,
        "short_scanline_clocks": 1360,
        "dram_refresh_clocks": 40,
        "reset_startup_clocks": 186,
        "smp_ratio": {
            "numerator": 15664,
            "denominator": 328125,
            "domain": "S-SMP clocks per SNES master clock",
            "profile": "ntsc-measured-32040",
            "derived_smp_hz": 1025279.8698057142,
            "derived_stereo_pcm_hz": 32039.99593142857,
        },
        "oracle_promotions": 0,
        "trace_promotions": 0,
        "manifest_sha256": digest(manifest_path),
        "opcode_matrix_sha256": digest(matrix_path),
        "generator_sha256": digest(Path(__file__)),
    }
    (out / "V10.2-SCPU-TIMING-SUMMARY.json").write_text(
        json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8", newline="\n"
    )
    print(json.dumps(summary, sort_keys=True))
    return summary


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--project", type=Path, default=ROOT)
    args = parser.parse_args()
    generate(args.project.resolve())


if __name__ == "__main__":
    main()
