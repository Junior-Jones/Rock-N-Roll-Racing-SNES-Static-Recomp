"""Prove the V10.2 executable-WRAM result from the complete S-CPU union."""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ROM_SHA256 = "9d721753301278325c851f1843d669a697aed757dcf6495a31fc31ddf664b182"
CLOSURE_STATUS = "SEMANTIC_GRAPH_CLOSED_WITH_REDUNDANT_STACK_HISTORY_RESIDUAL"


def parse_context(text: str) -> tuple[int, int]:
    address, _modes = text.rsplit(":", 1)
    bank, pc = address.split(":")
    return int(bank, 16), int(pc, 16)


def is_wram_execution(bank: int, pc: int) -> bool:
    if bank in (0x7E, 0x7F):
        return True
    return (bank & 0x7F) < 0x40 and pc < 0x2000


def build(root: Path) -> dict:
    manifest_path = root / "docs/V10.2-SCPU-PRODUCTION-MANIFEST.csv"
    successors_path = root / "docs/V10.2-SCPU-SUCCESSORS.csv"
    summary_path = root / "generated/current/v10_2/scpu/V10.2-SCPU-PRODUCTION-SUMMARY.json"
    production = json.loads(summary_path.read_text(encoding="utf-8"))
    residual_is_certified = (
        production.get("reset_closure_status") == CLOSURE_STATUS
        and production.get("pending_states") ==
            production.get("residual_redundant_stack_history_states")
    )
    if not production["discovery_union_equals_production"] \
            or production["unresolved_frontiers"] \
            or (production["pending_states"] and not residual_is_certified):
        raise ValueError("WRAM audit requires a complete S-CPU production union")

    with manifest_path.open(encoding="utf-8", newline="") as handle:
        manifest = list(csv.DictReader(handle))
    with successors_path.open(encoding="utf-8", newline="") as handle:
        successors = list(csv.DictReader(handle))
    contexts = {row["context"] for row in manifest}
    if len(contexts) != production["production_contexts"]:
        raise ValueError("manifest count differs from production summary")

    wram_contexts = sorted(
        context for context in contexts if is_wram_execution(*parse_context(context))
    )
    missing_targets = sorted({row["to"] for row in successors} - contexts)
    wram_targets = sorted({
        row["to"] for row in successors
        if is_wram_execution(*parse_context(row["to"]))
    })
    if missing_targets or wram_contexts or wram_targets:
        raise ValueError(
            f"unexpected executable-WRAM authority: contexts={wram_contexts[:8]} "
            f"targets={wram_targets[:8]} missing={missing_targets[:8]}"
        )

    return {
        "schema": "rock-n-roll-racing-v10.2-executable-wram-audit-v1",
        "rom_sha256": ROM_SHA256,
        "production_summary_sha256": hashlib.sha256(summary_path.read_bytes()).hexdigest(),
        "production_contexts_checked": len(contexts),
        "static_successor_relations_checked": len(successors),
        "interrupt_reentry_policy": "generated membership permits only an existing ROM production context",
        "source_terminal_policy": "three proved invalid cartridge paths stop and cannot seed mutable execution",
        "admitted_executable_wram_epochs": 0,
        "admitted_executable_wram_contexts": [],
        "admitted_executable_wram_targets": [],
        "unknown_mutable_targets_fail_closed": True,
        "oracle_promotions": 0,
        "trace_promotions": 0,
        "status": "COMPLETE_ZERO_EXECUTABLE_WRAM_EPOCHS",
    }


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--project", type=Path, default=ROOT)
    parser.add_argument(
        "--out", type=Path,
        default=ROOT / "docs/V10.2-executable-wram-summary.json",
    )
    args = parser.parse_args()
    result = build(args.project.resolve())
    args.out.write_text(json.dumps(result, indent=2, sort_keys=True) + "\n",
                        encoding="utf-8", newline="\n")
    print(json.dumps(result, sort_keys=True))


if __name__ == "__main__":
    main()
