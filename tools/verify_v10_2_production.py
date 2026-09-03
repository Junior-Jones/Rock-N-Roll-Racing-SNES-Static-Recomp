#!/usr/bin/env python3
"""Independent, source-artifact-only V10.2 production reconciliation gate."""

from __future__ import annotations

import argparse
import csv
import hashlib
import json
import re
from collections import Counter
from pathlib import Path


EXPECTED_ROM_SHA256 = "9d721753301278325c851f1843d669a697aed757dcf6495a31fc31ddf664b182"
EXPECTED_ROM_BYTES = 0x100000
CLOSURE_STATUS = "SEMANTIC_GRAPH_CLOSED_WITH_REDUNDANT_STACK_HISTORY_RESIDUAL"


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def load_json(path: Path) -> dict:
    return json.loads(path.read_text(encoding="utf-8"))


def rows(path: Path) -> list[dict[str, str]]:
    with path.open(newline="", encoding="utf-8-sig") as stream:
        return list(csv.DictReader(stream))


def require(condition: bool, message: str) -> None:
    if not condition:
        raise ValueError(message)


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("rom", type=Path)
    parser.add_argument("--project", type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()
    root = args.project.resolve()
    rom = args.rom.resolve()

    require(rom.stat().st_size == EXPECTED_ROM_BYTES, "canonical ROM size mismatch")
    require(sha(rom) == EXPECTED_ROM_SHA256, "canonical ROM SHA-256 mismatch")
    rom_bytes = rom.read_bytes()

    generated = root / "generated/current/v10_2"
    reset = load_json(generated / "V10.2-RESET-SCPU-REDISCOVERY.json")
    closure_path = generated / "V10.2-RESET-SEMANTIC-CLOSURE.json"
    closure = load_json(closure_path)
    vector = load_json(generated / "V10.2-VECTOR-SCPU-REDISCOVERY.json")
    dynamic = load_json(generated / "V10.2-DYNAMIC-CALL-PROOFS.json")
    production = load_json(generated / "scpu/V10.2-SCPU-PRODUCTION-SUMMARY.json")
    compact = load_json(generated / "scpu/V10.2-SCPU-COMPACT-MANIFEST.json")
    timing_summary = load_json(generated / "timing/V10.2-SCPU-TIMING-SUMMARY.json")
    smp = load_json(generated / "V10.2-SMP-DIRECT-REDISCOVERY.json")
    smp_aot = load_json(generated / "V10.2-SMP-AOT-GENERATION.json")
    hardware = load_json(root / "docs/V10.2-SCPU-HARDWARE-ACCESS-SUMMARY.json")
    ppu_contract = load_json(root / "docs/V10.2-PPU-MODE-CONTRACT.json")
    wram = load_json(root / "docs/V10.2-executable-wram-summary.json")

    reset_contexts = {row["context"] for row in reset["instructions"]}
    vector_contexts = {row["context"] for row in vector["instructions"]}
    discovery_union = reset_contexts | vector_contexts
    require(len(reset_contexts) == 22741, "RESET context total drift")
    require(len(vector_contexts) == 3143, "vector context total drift")
    require(reset["summary"]["states"] == 45000001, "RESET state-space total drift")
    require(reset["summary"]["frontier_types"] == {"SAFETY_STATE_LIMIT": 1},
            "RESET contains a semantic frontier")
    require({row["type"] for row in reset["frontiers"]} == {"SAFETY_STATE_LIMIT"},
            "RESET contains a non-safety frontier")
    require(closure["status"] == CLOSURE_STATUS, "RESET semantic closure not certified")
    require(closure["candidate"]["sha256"] == sha(generated / "V10.2-RESET-SCPU-REDISCOVERY.json"),
            "RESET semantic certificate input hash drift")
    require(closure["candidate"]["pending_redundant_stack_history_states"] ==
            reset["summary"]["pending_states_at_stop"],
            "RESET residual stack-history total drift")
    require(closure["stability_window_states"] >= 10000000,
            "RESET semantic stability window too small")
    require(vector["summary"]["pending_states_at_stop"] == 0, "vector pending states remain")
    require(vector["summary"]["frontier_types"] == {"RTI": 5}, "unexpected vector frontier")
    require({row["type"] for row in vector["frontiers"]} == {"RTI"}, "non-RTI vector frontier")
    require(reset["summary"]["oracle_promotions"] == 0 and reset["summary"]["trace_promotions"] == 0,
            "RESET contains observational promotion")
    require(vector["summary"]["oracle_promotions"] == 0 and vector["summary"]["trace_promotions"] == 0,
            "vector graph contains observational promotion")
    require(dynamic["summary"] == {"proved_call_sites": 35, "unique_targets": 208},
            "dynamic-call proof totals drift")
    require(dynamic["authority_policy"]["source_bytes_only"], "dynamic calls are not source-only")
    require(dynamic["authority_policy"]["oracle_promotions"] == 0 and
            dynamic["authority_policy"]["trace_promotions"] == 0,
            "dynamic calls contain observational promotion")
    handler_proof = next(
        row for row in dynamic["proofs"] if row["context"] == "81:809B:E0M0X0"
    )
    direct_handler_values = set()
    generic_handler_values = set()
    for offset in range(len(rom_bytes) - 5):
        window = rom_bytes[offset:offset + 6]
        if window[0] == 0xA9 and window[3:] == bytes((0x9D, 0x41, 0x0F)):
            direct_handler_values.add(window[1] | (window[2] << 8))
        if window[0] == 0xA9 and window[3:] == bytes((0x20, 0xCC, 0x95)):
            generic_handler_values.add(window[1] | (window[2] << 8))
    require(len(direct_handler_values) == 49 and len(generic_handler_values) == 4,
            "synthetic-handler ROM writer census drift")
    expected_handler_targets = {
        f"81:{value:04X}" for value in direct_handler_values | generic_handler_values
    }
    require(set(handler_proof["targets"]) == expected_handler_targets,
            "synthetic-handler proof does not equal the complete ROM writer census")
    d991_records = next(
        row for row in dynamic["proofs"] if row["context"] == "92:A69E:E0M0X0"
    )
    require(d991_records["targets"] == ["92:D9AB", "92:D9C2"],
            "92:A69E counted-record target pair drift")
    fb31 = next(row for row in dynamic["proofs"] if row["context"] == "81:FB31:E0M1X1")
    require(fb31["targets"] == [
        "81:A6BE", "81:FB3E", "81:FBA8", "81:FC12", "81:FC5D", "81:FC9B"
    ], "81:FB31 finite dispatch domain drift")
    fd5a = next(row for row in dynamic["proofs"] if row["context"] == "81:FD5A:E0M1X1")
    require(fd5a["targets"] == [
        "81:FD77", "81:FD7F", "81:FD80", "81:FD91",
        "81:FD9F", "81:FDB3", "81:FDC7", "81:FDDB"
    ], "81:FD5A finite dispatch domain drift")

    manifest_path = root / "docs/V10.2-SCPU-PRODUCTION-MANIFEST.csv"
    successor_path = root / "docs/V10.2-SCPU-SUCCESSORS.csv"
    timing_path = root / "docs/V10.2-SCPU-TIMING-MANIFEST.csv"
    manifest = rows(manifest_path)
    timing = rows(timing_path)
    successor = rows(successor_path)
    manifest_contexts = {row["context"] for row in manifest}
    require(len(manifest) == len(manifest_contexts) == 24835,
            "production context total/uniqueness mismatch")
    require(manifest_contexts == discovery_union, "discovery union differs from production")
    require(len({row["production_id"] for row in manifest}) == len(manifest), "duplicate production ID")
    require(len({row["key_hex"] for row in manifest}) == len(manifest), "duplicate production key")
    dispositions = Counter(row["disposition"] for row in manifest)
    require(dispositions == {"NATIVE_BODY": 24827, "SCHEDULER_OWNED_RTI": 5,
                             "SOURCE_PROVED_TERMINAL": 3}, "production dispositions drift")
    for row in manifest:
        physical = int(row["physical"], 16)
        encoded = bytes.fromhex(row["bytes"])
        require(len(encoded) == int(row["length"]), f"length mismatch at {row['context']}")
        require(rom_bytes[physical:physical + len(encoded)] == encoded,
                f"ROM guard mismatch at {row['context']}")

    timing_by_context = {row["context"]: row for row in timing}
    require(len(timing) == len(timing_by_context) == len(manifest), "timing context total mismatch")
    timing_source = (generated / "timing/js_v10_2_timing.c").read_text(encoding="utf-8")
    generated_timing = {}
    timing_entry = re.compile(
        r"^\s*\{0x([0-9A-Fa-f]{8})u,0x[0-9A-Fa-f]+u,0x[0-9A-Fa-f]+u,"
        r"0x([0-9A-Fa-f]{8})u,.*?,\"[^\"]*\",\"([^\"]*)\"\},\s*$",
        re.MULTILINE,
    )
    for match in timing_entry.finditer(timing_source):
        key = match.group(1).upper()
        require(key not in generated_timing, f"duplicate generated timing key {key}")
        generated_timing[key] = {
            "rule_flags": match.group(2).upper(),
            "timing_rules": match.group(3),
        }
    require(len(generated_timing) == len(timing), "generated timing table total mismatch")
    for row in manifest:
        plan = timing_by_context.get(row["context"])
        require(plan is not None, f"missing timing row {row['context']}")
        for field in ("production_id", "key_hex", "bytes"):
            require(plan[field] == row[field], f"timing {field} mismatch at {row['context']}")
        expected_executable = "0" if row["disposition"] == "SOURCE_PROVED_TERMINAL" else "1"
        require(plan["executable"] == expected_executable,
                f"timing disposition mismatch at {row['context']}")
        require("RMW_INTERMEDIATE_IDLE;RMW_INTERMEDIATE_IDLE" not in plan["timing_rules"],
                f"duplicated RMW timing rule at {row['context']}")
        if plan["timing_class"] == "RMW_SEQUENCE" and plan["mode"] in {"ABS_X", "DP_X"}:
            flags = int(plan["rule_flags"], 16)
            require((flags & 0x00050000) == 0x00050000,
                    f"indexed RMW idle family incomplete at {row['context']}")
            rules = plan["timing_rules"].split(";")
            require(rules.count("INDEX_FIXED_PRE_DATA_IDLE") == 1 and
                    rules.count("RMW_INTERMEDIATE_IDLE") == 1,
                    f"indexed RMW rule family malformed at {row['context']}")
        generated_plan = generated_timing.get(plan["key_hex"].upper())
        require(generated_plan is not None, f"generated timing plan missing {plan['key_hex']}")
        require(generated_plan["rule_flags"] == plan["rule_flags"].upper(),
                f"generated timing flags mismatch at {row['context']}")
        require(generated_plan["timing_rules"] == plan["timing_rules"],
                f"generated timing rules mismatch at {row['context']}")

    outgoing = Counter(row["from"] for row in successor)
    successor_pairs = {(row["from"], row["to"]) for row in successor}
    require(("80:BD35:E0M1X1", "80:810D:E0M1X1") in successor_pairs,
            "saved-S TXS return edge missing")
    require(("80:8113:E0M1X1", "80:8069:E0M1X1") in successor_pairs,
            "saved-S TCS return edge missing")
    for edge in successor:
        require(edge["from"] in manifest_contexts, f"unknown successor source {edge['from']}")
        require(edge["to"] in manifest_contexts, f"unclosed successor target {edge['to']}")
    for row in manifest:
        require(outgoing[row["context"]] == int(row["successor_count"]),
                f"successor count mismatch at {row['context']}")

    require(production["discovery_union_equals_production"] is True, "production equality flag false")
    require(production["production_contexts"] == len(manifest), "production summary count mismatch")
    require(production["unresolved_frontiers"] == 0,
            "production has unresolved semantic frontiers")
    require(production["reset_closure_status"] == CLOSURE_STATUS,
            "production did not record semantic RESET closure")
    require(production["reset_closure_certificate_sha256"] == sha(closure_path),
            "production RESET closure certificate hash drift")
    require(production["pending_states"] ==
            closure["candidate"]["pending_redundant_stack_history_states"],
            "production residual stack-history count drift")
    require(production["residual_redundant_stack_history_states"] ==
            production["pending_states"],
            "production residual stack-history classification drift")
    require(production["runtime_opcode_decoder"] is False, "runtime opcode decoder selected")
    require(production["oracle_promotions"] == 0 and production["trace_promotions"] == 0,
            "production contains observational promotion")
    require(compact["runtime_context_identity"] == "PBR:PC:E:M:X",
            "compact runtime context identity drift")
    require(compact["runtime_context_count"] == len(manifest),
            "compact authority context total drift")
    require(compact["all_context_semantics_reconstructed_exactly"] is True and
            compact["original_semantics_sha256"] == compact["reconstructed_semantics_sha256"],
            "compact semantic reconstruction mismatch")
    require(compact["runtime_rom_opcode_decode"] is False and
            compact["runtime_target_learning"] is False and
            compact["runtime_emulator_fallback"] is False,
            "compact authority introduced a decoder, learning, or fallback")
    require(compact["exact_context_resume_points_preserved"] is True and
            compact["unknown_contexts_fail_closed"] is True,
            "compact authority did not preserve exact/fail-closed behavior")
    compact_dispatch = (generated / "scpu/js_v10_2_scpu_dispatch.c").read_text(encoding="utf-8")
    compact_keys = {
        match.upper() for match in re.findall(r"\b0x([0-9A-Fa-f]{8})u\b", compact_dispatch)
    }
    require({row["key_hex"].upper() for row in manifest} == compact_keys,
            "compact dispatcher key set differs from the production manifest")
    for filename, artifact in compact["output_files"].items():
        path = generated / "scpu" / filename
        require(path.stat().st_size == artifact["bytes"] and
                sha(path) == artifact["sha256"],
                f"compact output receipt mismatch: {filename}")
    for artifact in production["generated_files"]:
        path = generated / "scpu" / artifact["path"]
        require(path.stat().st_size == artifact["size"], f"generated size mismatch: {path.name}")
        require(sha(path) == artifact["sha256"], f"generated hash mismatch: {path.name}")

    require(timing_summary["contexts"] == len(manifest), "timing summary total mismatch")
    require(timing_summary["manifest_sha256"] == sha(manifest_path), "timing input hash mismatch")
    require(timing_summary["smp_ratio"]["numerator"] == 15664 and
            timing_summary["smp_ratio"]["denominator"] == 328125,
            "active S-SMP clock profile mismatch")
    require(timing_summary["normal_scanline_clocks"] == 1364 and
            timing_summary["short_scanline_clocks"] == 1360 and
            timing_summary["dram_refresh_clocks"] == 40,
            "master/raster timing constants drift")

    require(wram["status"] == "COMPLETE_ZERO_EXECUTABLE_WRAM_EPOCHS", "WRAM execution remains open")
    require(not wram["admitted_executable_wram_contexts"], "executable WRAM was admitted")
    require(hardware["union_instruction_contexts"] == len(manifest), "hardware contract union drift")
    require(hardware["area_context_counts"] == {
        "APUIO": 30, "CPU_IO": 150, "DMA_HDMA": 205,
        "INPUT": 2, "PPU": 500, "WRAM_PORT": 3,
    }, "hardware access census drift")
    require(ppu_contract["selected_modes"] == [0, 1, 3, 4, 7], "target PPU mode set drift")
    require(not ppu_contract["interlace_selected"] and not ppu_contract["overscan_selected"] and
            not ppu_contract["pseudo_hires_selected"], "unsupported target display feature selected")

    smp_summary = smp["summary"]
    require(smp["schema"] == "RRR_V10_2_SMP_DIRECT_REDISCOVERY_V4", "S-SMP schema mismatch")
    require(smp_summary["abstract_states"] == 79482 and
            smp_summary["unique_instruction_pcs"] == 1629 and
            smp_summary["frontier_count"] == 0,
            "S-SMP graph is not closed")
    require(smp_summary["source_proved_dynamic_return_sites"] == 3 and
            smp_summary["source_proved_dynamic_return_targets"] == 69,
            "S-SMP dynamic-return proof drift")
    require(smp_summary["oracle_promotions"] == 0 and smp_summary["trace_promotions"] == 0,
            "S-SMP contains observational promotion")
    require(smp_aot["result"] == "pass" and smp_aot["source_only"] is True,
            "S-SMP AOT generation is not source-only/pass")
    require(smp_aot["exact_pc_opcode_contexts"] == 1629 and
            smp_aot["protected_driver_code_bytes"] == 3417 and
            smp_aot["used_opcode_count"] == 101,
            "S-SMP AOT totals drift")
    for field, relative in (
        ("lookup_sha256", "runtime/v10_2_audio/smp/sc_smp_aot_lookup.inc"),
        ("dispatch_sha256", "runtime/v10_2_audio/smp/sc_smp_aot_dispatch.inc"),
        ("bitmap_include_sha256", "runtime/v10_2_audio/smp/sc_smp_aot_code_bitmap.inc"),
    ):
        require(smp_aot[field] == sha(root / relative), f"S-SMP AOT hash mismatch: {relative}")

    require(smp_aot["dispatch_authority"] == "exact_pc" and
            smp_aot["generic_runtime_dispatcher"] is False and
            smp_aot["fallback"] is False,
            "S-SMP production dispatch is not exact-PC/fail-closed")
    require(smp_aot["shard_count"] == len(smp_aot["shard_sha256"]),
            "S-SMP shard count drift")
    for filename, digest in smp_aot["shard_sha256"].items():
        require(digest == sha(generated / "smp" / filename),
                f"S-SMP shard hash mismatch: {filename}")

    dsp_source = (root / "runtime/v10_2_audio/dsp/project_static_dsp.c").read_text(encoding="utf-8")
    phase_switch = re.search(r"switch\(p\)\{(.*?)\bdefault:", dsp_source, re.DOTALL)
    require(phase_switch is not None, "S-DSP static phase switch missing")
    dsp_phases = [int(value) for value in re.findall(r"\bcase\s+(\d+)\s*:", phase_switch.group(1))]
    require(dsp_phases == list(range(32)), "S-DSP static phase program is not exactly 0..31")
    require("decode_brr_group" in dsp_source and "echo_step30" in dsp_source and
            "gaussian4" in dsp_source and "pcm_read_with_knownness" in dsp_source,
            "project S-DSP BRR/echo/interpolation/knownness owner incomplete")
    require(not (root / "runtime/v10_2_audio/dsp/SPC_DSP.cpp").exists() and
            not (root / "runtime/v10_2_audio/dsp/sdsp.cpp").exists(),
            "retired snes_spc runtime DSP source remains")

    cmake = (root / "CMakeLists.txt").read_text(encoding="utf-8")
    selected = (
        "runtime/v05c_static_cpu.c", "runtime/v10_2_ppu.c", "runtime/v10_2_renderer.c",
        "runtime/v10_2_apu.cpp", "runtime/v10_2_audio/smp/smp.cpp",
        "runtime/v10_2_audio/dsp/project_static_dsp.c", "runtime/v10_2_audio/sc_static_apu.cpp",
        "runtime/v10_2_machine.c", "generated/current/v10_2/timing/js_v10_2_timing.c",
    )
    require(all(path in cmake for path in selected), "selected V10.2 owner missing from CMake")
    retired = ("runtime/v06c_machine.c", "runtime/v07c_machine.c", "runtime/v08c_machine.c",
               "runtime/v09c_machine.c", "runtime/v10_1_machine.c", "runtime/v10_1_apu.c")
    require(not any(path in cmake for path in retired), "retired machine/APU owner selected in CMake")
    require("SC_SMP_AOT=1" in cmake, "S-SMP AOT compile gate missing")

    forbidden_roms = [path for path in root.rglob("*") if path.is_file() and
                      path.suffix.lower() in {".sfc", ".smc", ".fig", ".swc"}]
    require(not forbidden_roms, "copyrighted ROM image present in source tree")

    receipt = {
        "schema": "RRR_V10_2_PRODUCTION_RECONCILIATION_V1",
        "result": "PASS",
        "rom_sha256": EXPECTED_ROM_SHA256,
        "reset_abstract_states": reset["summary"]["states"],
        "reset_residual_stack_history_states": reset["summary"]["pending_states_at_stop"],
        "reset_closure_status": closure["status"],
        "reset_contexts": len(reset_contexts),
        "vector_contexts": len(vector_contexts),
        "production_contexts": len(manifest),
        "native_bodies": dispositions["NATIVE_BODY"],
        "scheduler_owned_rti": dispositions["SCHEDULER_OWNED_RTI"],
        "source_terminals": dispositions["SOURCE_PROVED_TERMINAL"],
        "successor_relations": len(successor),
        "timing_rows": len(timing),
        "executable_wram_epochs": 0,
        "smp_abstract_states": smp_summary["abstract_states"],
        "smp_exact_pcs": smp_summary["unique_instruction_pcs"],
        "sdsp_static_phases": len(dsp_phases),
        "oracle_promotions": 0,
        "trace_promotions": 0,
        "runtime_opcode_decoder": False,
        "retired_runtime_owners_selected": False,
    }
    text = json.dumps(receipt, indent=2) + "\n"
    if args.output:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(text, encoding="utf-8", newline="\n")
    print(text, end="")
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (OSError, ValueError, KeyError, json.JSONDecodeError) as error:
        print(json.dumps({"schema": "RRR_V10_2_PRODUCTION_RECONCILIATION_V1",
                          "result": "FAIL", "error": str(error)}, indent=2))
        raise SystemExit(1)
