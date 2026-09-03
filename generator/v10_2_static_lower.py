#!/usr/bin/env python3
"""Lower the semantically closed V10.2 RESET and interrupt graphs to native C.

The generator consumes only the exact-ROM source discovery report.  It emits
one case for every PBR:PC:E:M:X context, source-specific successor guards, and
named source-proved terminal cases.  No opcode decoder, trace, oracle PC list,
or gameplay observation is linked into production.
"""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
from collections import defaultdict
from pathlib import Path

try:
    from generator.v05c_static_lower import emit_semantics, key_int, key_text
except ModuleNotFoundError:
    # Direct execution places generator/ rather than the workspace root on
    # sys.path.  Keep both invocation forms deterministic.
    from v05c_static_lower import emit_semantics, key_int, key_text


ROM_SHA256 = "9d721753301278325c851f1843d669a697aed757dcf6495a31fc31ddf664b182"
SCHEMA = "rock-n-roll-racing-v10.2-static-scpu-production-v1"
CLOSURE_STATUS = "SEMANTIC_GRAPH_CLOSED_WITH_REDUNDANT_STACK_HISTORY_RESIDUAL"


def sha256(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def csv_write(path: Path, fields: list[str], rows: list[dict]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=fields, lineterminator="\n")
        writer.writeheader()
        writer.writerows(rows)


def parse_context(text: str) -> tuple[int, int, int, int, int]:
    bank_pc, modes = text.rsplit(":", 1)
    bank, pc = bank_pc.split(":")
    return int(bank, 16), int(pc, 16), int(modes[1]), int(modes[3]), int(modes[5])


def ckey(key: tuple[int, int, int, int, int]) -> str:
    return f"0x{key_int(key):08X}u"


def build(root: Path, rom_path: Path) -> dict:
    if sha256(rom_path) != ROM_SHA256:
        raise ValueError("target ROM SHA-256 mismatch")
    discovery_path = root / "generated/current/v10_2/V10.2-RESET-SCPU-REDISCOVERY.json"
    closure_path = root / "generated/current/v10_2/V10.2-RESET-SEMANTIC-CLOSURE.json"
    vector_path = root / "generated/current/v10_2/V10.2-VECTOR-SCPU-REDISCOVERY.json"
    proof_path = root / "generated/current/v10_2/V10.2-DYNAMIC-CALL-PROOFS.json"
    discovery = json.loads(discovery_path.read_text(encoding="utf-8"))
    closure = json.loads(closure_path.read_text(encoding="utf-8"))
    vector = json.loads(vector_path.read_text(encoding="utf-8"))
    reset_drained = discovery["summary"]["unique_frontiers"] == 0 \
        and discovery["summary"]["pending_states_at_stop"] == 0
    reset_certified = (
        closure.get("status") == CLOSURE_STATUS
        and closure.get("candidate", {}).get("sha256") == sha256(discovery_path)
        and closure.get("candidate", {}).get(
            "pending_redundant_stack_history_states"
        ) == discovery["summary"]["pending_states_at_stop"]
        and discovery["summary"]["frontier_types"] == {"SAFETY_STATE_LIMIT": 1}
        and {row["type"] for row in discovery["frontiers"]} == {"SAFETY_STATE_LIMIT"}
    )
    if not (reset_drained or reset_certified):
        raise ValueError("S-CPU discovery lacks frontier-free or certified semantic closure")
    if discovery["summary"]["oracle_promotions"] != 0 \
            or discovery["summary"]["trace_promotions"] != 0:
        raise ValueError("non-source authority contaminated S-CPU discovery")
    if vector["interrupt_summary"]["unexpected_frontiers"] != 0 \
            or vector["summary"]["pending_states_at_stop"] != 0:
        raise ValueError("interrupt S-CPU discovery has not converged")
    if vector["interrupt_summary"]["oracle_promotions"] != 0 \
            or vector["interrupt_summary"]["trace_promotions"] != 0:
        raise ValueError("non-source authority contaminated interrupt discovery")

    proof_report = json.loads(proof_path.read_text(encoding="utf-8"))
    proofs_by_context = {row["context"]: row for row in proof_report["proofs"]}
    for row in vector["selector_call_proofs"]:
        existing = proofs_by_context.get(row["context"])
        if existing is not None and existing != row:
            raise ValueError(f"conflicting dynamic proof for {row['context']}")
        proofs_by_context[row["context"]] = row

    instructions: dict[tuple[int, int, int, int, int], dict] = {}
    for report in (discovery, vector):
        for item in report["instructions"]:
            key = (item["bank"], item["pc"], item["e"], item["m"], item["x"])
            existing = instructions.get(key)
            if existing is not None:
                fields = ("physical", "bytes", "mnemonic", "mode", "length")
                if any(existing[field] != item[field] for field in fields):
                    raise ValueError(f"conflicting instruction context {key_text(key)}")
                continue
            instructions[key] = item

    successors: dict[tuple[int, int, int, int, int], set[tuple[int, int, int, int, int]]] = defaultdict(set)
    for report in (discovery, vector):
        for edge in report["edges"]:
            successors[parse_context(edge["from"])].add(parse_context(edge["to"]))
    terminals = {parse_context(item["context"]): item for item in discovery["terminals"]}
    rtis = {
        parse_context(item["context"])
        for item in vector["frontiers"] if item["type"] == "RTI"
    }

    keys = set(instructions)
    if set(successors) - keys:
        raise ValueError("successor source outside discovered instruction set")
    for source, targets in successors.items():
        missing = targets - keys
        if missing:
            raise ValueError(f"successors outside discovery from {key_text(source)}: {sorted(missing)}")
    for key in keys:
        if key in terminals:
            if successors.get(key):
                raise ValueError(f"terminal has live successor {key_text(key)}")
        elif key in rtis:
            if instructions[key]["mnemonic"] != "RTI":
                raise ValueError(f"non-RTI interrupt boundary {key_text(key)}")
            if successors.get(key):
                raise ValueError(f"RTI has static successor {key_text(key)}")
        elif not successors.get(key):
            raise ValueError(f"nonterminal lacks successor {key_text(key)}")

    groups: dict[int, list[tuple[int, int, int, int, int]]] = defaultdict(list)
    for key in sorted(keys, key=key_int):
        groups[((key[0] << 16) | key[1]) >> 10].append(key)

    out = root / "generated/current/v10_2/scpu"
    out.mkdir(parents=True, exist_ok=True)
    for stale in list(out.glob("js_v10_2_scpu_*.c")) \
            + list(out.glob("js_v10_2_scpu_*.h")) \
            + list(out.glob("js_v10_2_compact_*.c")):
        stale.unlink()
    compact_manifest_path = out / "V10.2-SCPU-COMPACT-MANIFEST.json"
    if compact_manifest_path.exists():
        compact_manifest_path.unlink()
    header = """#ifndef ROCKNROLL_V10_2_SCPU_DISPATCH_H
#define ROCKNROLL_V10_2_SCPU_DISPATCH_H

#include "v05c_static_cpu.h"

#ifdef __cplusplus
extern "C" {
#endif

int js_v10_2_scpu_has_context(const JSCPU *cpu);
int js_v10_2_scpu_index_allowed(uint16_t value, const uint16_t *allowed, size_t count);
JSExecResult js_v10_2_scpu_step(JSCPU *cpu, const JSBus *bus, JSStop *stop);

#ifdef __cplusplus
}
#endif
#endif
"""
    (out / "js_v10_2_scpu_dispatch.h").write_text(header, encoding="utf-8", newline="\n")

    shard_rows: list[dict] = []
    for group in sorted(groups):
        name = f"js_v10_2_scpu_shard_{group:04X}"
        lines = [
            '#include "js_v10_2_scpu_dispatch.h"',
            "",
            f"JSExecResult {name}(JSCPU *cpu, const JSBus *bus, JSStop *stop) {{",
            "    (void)bus;",
            "    switch (js_cpu_context_key(cpu)) {",
        ]
        for key in groups[group]:
            item = instructions[key]
            lines.append(f"        case {ckey(key)}: {{")
            lines.append(f"            const uint32_t source_key = {ckey(key)};")
            if key in terminals:
                lines.append("            return js_stop_now(stop, JS_STOP_STATIC_TERMINAL, source_key, source_key);")
            elif key in rtis:
                lines.extend([
                    "            { uint8_t status = 0u, bank = 0u; uint16_t return_pc = 0u;",
                    "              if (!js_stack_pop8(cpu, bus, &status, 1, stop, source_key)) return JS_EXEC_STOP;",
                    "              if (!js_stack_pop16(cpu, bus, &return_pc, 1, stop, source_key)) return JS_EXEC_STOP;",
                    "              cpu->p = status; cpu->pc = return_pc;",
                    "              if (!cpu->e) {",
                    "                  if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP;",
                    "                  cpu->pbr = bank;",
                    "              } else { cpu->pbr = 0u; }",
                    "              js_cpu_normalize(cpu);",
                    "              if (!js_v10_2_scpu_has_context(cpu))",
                    "                  return js_stop_now(stop, JS_STOP_UNPROVED_INTERRUPT_REENTRY, source_key, js_cpu_context_key(cpu));",
                    "              return JS_EXEC_OK; }",
                ])
            else:
                row = {
                    "Context_ID": item["context"],
                    "Bytes": item["bytes"],
                    "Length": str(item["length"]),
                    "Mnemonic": item["mnemonic"],
                    "Mode": item["mode"],
                }
                proof = proofs_by_context.get(item["context"])
                if item["mode"] == "ABS_X_IND" and item["mnemonic"] in {"JSR", "JMP"}:
                    if proof is None or not proof.get("proved_x_offsets"):
                        raise ValueError(f"dynamic indexed site lacks X proof {item['context']}")
                    x_values = ", ".join(f"0x{value:04X}u" for value in proof["proved_x_offsets"])
                    lines.append(f"            static const uint16_t allowed_x[] = {{ {x_values} }};")
                    lines.append("            if (!js_v10_2_scpu_index_allowed(cpu->x, allowed_x, sizeof allowed_x / sizeof allowed_x[0]))")
                    lines.append("                return js_stop_now(stop, JS_STOP_UNPROVED_DYNAMIC_TARGET, source_key, js_cpu_context_key(cpu));")
                for statement in emit_semantics(key, row):
                    lines.append("            " + statement)
                allowed = sorted(successors[key], key=key_int)
                values = ", ".join(ckey(target) for target in allowed)
                lines.append(f"            static const uint32_t allowed[] = {{ {values} }};")
                lines.append("            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);")
            lines.append("        }")
        lines.extend(["        default: return JS_EXEC_NOT_MINE;", "    }", "}", ""])
        path = out / f"{name}.c"
        path.write_text("\n".join(lines), encoding="utf-8", newline="\n")
        shard_rows.append({"group": f"{group:04X}", "function": name,
                           "contexts": len(groups[group]), "path": path.name})

    sorted_key_values = [key_int(key) for key in sorted(keys, key=key_int)]
    dispatch = [
        '#include "js_v10_2_scpu_dispatch.h"',
        "",
        "static const uint32_t js_v10_2_context_keys[] = {",
    ]
    for start in range(0, len(sorted_key_values), 8):
        values = ", ".join(f"0x{value:08X}u" for value in sorted_key_values[start:start + 8])
        dispatch.append(f"    {values},")
    dispatch.extend([
        "};",
        "",
        "int js_v10_2_scpu_has_context(const JSCPU *cpu) {",
        "    size_t lo = 0u, hi = sizeof js_v10_2_context_keys / sizeof js_v10_2_context_keys[0];",
        "    uint32_t key;",
        "    if (!cpu) return 0;",
        "    key = js_cpu_context_key(cpu);",
        "    while (lo < hi) {",
        "        size_t mid = lo + (hi - lo) / 2u;",
        "        uint32_t candidate = js_v10_2_context_keys[mid];",
        "        if (candidate < key) lo = mid + 1u; else hi = mid;",
        "    }",
        "    return lo < (sizeof js_v10_2_context_keys / sizeof js_v10_2_context_keys[0])",
        "        && js_v10_2_context_keys[lo] == key;",
        "}",
        "",
        "int js_v10_2_scpu_index_allowed(uint16_t value, const uint16_t *allowed, size_t count) {",
        "    size_t index;",
        "    if (!allowed) return 0;",
        "    for (index = 0u; index < count; ++index) if (allowed[index] == value) return 1;",
        "    return 0;",
        "}",
        "",
    ])
    for row in shard_rows:
        dispatch.append(f"JSExecResult {row['function']}(JSCPU *cpu, const JSBus *bus, JSStop *stop);")
    dispatch.extend([
        "",
        "JSExecResult js_v10_2_scpu_step(JSCPU *cpu, const JSBus *bus, JSStop *stop) {",
        "    JSExecResult result;",
        "    uint32_t group;",
        "    if (!cpu) return js_stop_now(stop, JS_STOP_INVALID_CPU_STATE, 0u, 0u);",
        "    js_stop_clear(stop);",
        "    if (cpu->e > 1u || (cpu->e && ((cpu->p & (JS_P_M|JS_P_X)) != (JS_P_M|JS_P_X))))",
        "        return js_stop_now(stop, JS_STOP_INVALID_CPU_STATE, js_cpu_context_key(cpu), js_cpu_context_key(cpu));",
        "    if ((cpu->p & JS_P_X) && ((cpu->x & 0xFF00u) || (cpu->y & 0xFF00u)))",
        "        return js_stop_now(stop, JS_STOP_INVALID_CPU_STATE, js_cpu_context_key(cpu), js_cpu_context_key(cpu));",
        "    group = ((((uint32_t)cpu->pbr << 16) | cpu->pc) >> 10);",
        "    switch (group) {",
    ])
    for row in shard_rows:
        dispatch.append(f"        case 0x{row['group']}u: result = {row['function']}(cpu, bus, stop); break;")
    dispatch.extend([
        "        default: result = JS_EXEC_NOT_MINE; break;",
        "    }",
        "    if (result == JS_EXEC_NOT_MINE)",
        "        return js_stop_now(stop, JS_STOP_UNKNOWN_CONTEXT, js_cpu_context_key(cpu), js_cpu_context_key(cpu));",
        "    return result;",
        "}",
        "",
    ])
    (out / "js_v10_2_scpu_dispatch.c").write_text("\n".join(dispatch), encoding="utf-8", newline="\n")

    manifest: list[dict] = []
    successor_rows: list[dict] = []
    for index, key in enumerate(sorted(keys, key=key_int), 1):
        item = instructions[key]
        targets = sorted(successors.get(key, set()), key=key_int)
        manifest.append({
            "production_id": f"V10.2-SCPU-{index:06d}",
            "context": key_text(key),
            "key_hex": f"{key_int(key):08X}",
            "physical": f"{item['physical']:06X}",
            "bytes": item["bytes"],
            "mnemonic": item["mnemonic"],
            "mode": item["mode"],
            "length": item["length"],
            "shard": f"{(((key[0] << 16) | key[1]) >> 10):04X}",
            "successor_count": len(targets),
            "disposition": (
                "SOURCE_PROVED_TERMINAL" if key in terminals else
                "SCHEDULER_OWNED_RTI" if key in rtis else
                "NATIVE_BODY"
            ),
        })
        for target in targets:
            successor_rows.append({"from": key_text(key), "to": key_text(target)})
    csv_write(root / "docs/V10.2-SCPU-PRODUCTION-MANIFEST.csv", list(manifest[0]), manifest)
    csv_write(root / "docs/V10.2-SCPU-SUCCESSORS.csv", ["from", "to"], successor_rows)

    # Replace the verbose one-body-per-case representation with a lossless
    # exact-key/template representation.  The compactor reconstructs and
    # byte-compares every normalized body before it writes any compact source.
    try:
        from generator.v10_2_compact_generated import compact
    except ModuleNotFoundError:
        from v10_2_compact_generated import compact
    compaction = compact(out, out, rom_path)

    # The summary cannot truthfully hash itself.  Excluding it also makes a
    # cache-cold run and a run over an existing output directory identical.
    generated_files = sorted(
        path for path in out.iterdir()
        if path.is_file() and path.name != "V10.2-SCPU-PRODUCTION-SUMMARY.json"
    )
    summary = {
        "schema": SCHEMA,
        "rom_sha256": ROM_SHA256,
        "reset_discovery_sha256": sha256(discovery_path),
        "reset_closure_certificate_sha256": sha256(closure_path),
        "reset_closure_status": "FRONTIER_FREE" if reset_drained else CLOSURE_STATUS,
        "vector_discovery_sha256": sha256(vector_path),
        "dynamic_proofs_sha256": sha256(proof_path),
        "generator_sha256": sha256(Path(__file__)),
        "production_contexts": len(keys),
        "reset_contexts": discovery["summary"]["unique_instruction_contexts"],
        "vector_contexts": vector["summary"]["unique_instruction_contexts"],
        "vector_only_contexts": len(keys) - discovery["summary"]["unique_instruction_contexts"],
        "native_body_contexts": len(keys) - len(terminals) - len(rtis),
        "source_proved_terminals": len(terminals),
        "scheduler_owned_rti_contexts": len(rtis),
        "successor_relations": len(successor_rows),
        "shards": len(groups),
        "discovery_union_equals_production": len(keys) == len({
            parse_context(row["context"])
            for report in (discovery, vector) for row in report["instructions"]
        }),
        "unresolved_frontiers": vector["interrupt_summary"]["unexpected_frontiers"],
        "pending_states": discovery["summary"]["pending_states_at_stop"]
                          + vector["summary"]["pending_states_at_stop"],
        "residual_redundant_stack_history_states": (
            0 if reset_drained else discovery["summary"]["pending_states_at_stop"]
        ),
        "runtime_opcode_decoder": False,
        "oracle_promotions": 0,
        "trace_promotions": 0,
        "compact_exact_context_authority": True,
        "semantic_templates": compaction["semantic_template_count"],
        "compact_parameter_words": compaction["parameter_word_count"],
        "compact_semantics_sha256": compaction["original_semantics_sha256"],
        "compact_semantics_reconstructed_exactly": compaction[
            "all_context_semantics_reconstructed_exactly"
        ],
        "generated_files": [
            {"path": path.name, "size": path.stat().st_size, "sha256": sha256(path)}
            for path in generated_files
        ],
    }
    (out / "V10.2-SCPU-PRODUCTION-SUMMARY.json").write_text(
        json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8", newline="\n"
    )
    return summary


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("rom", type=Path)
    parser.add_argument("--project-root", type=Path,
                        default=Path(__file__).resolve().parents[1])
    args = parser.parse_args()
    summary = build(args.project_root.resolve(), args.rom.resolve())
    print(json.dumps({key: value for key, value in summary.items()
                      if key != "generated_files"}, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
