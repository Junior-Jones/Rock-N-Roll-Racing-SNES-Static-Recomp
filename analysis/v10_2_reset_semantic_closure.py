#!/usr/bin/env python3
"""Certify semantic RESET-graph closure without hiding stack-history residue.

The RESET analyzer carries the complete abstract return stack in each state.
After the instruction/call/return graph stabilizes, deeper permutations of the
same already-proved stack histories can keep the raw queue non-empty.  This
gate compares two source-only runs separated by a large state window and only
accepts the residual when every semantic coverage counter is unchanged and the
sole frontier is the resource safety limit.  It never rewrites the discovery
report or claims that the raw queue is empty.
"""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path


SCHEMA = "RRR_V10_2_RESET_SEMANTIC_CLOSURE_V1"
STATUS = "SEMANTIC_GRAPH_CLOSED_WITH_REDUNDANT_STACK_HISTORY_RESIDUAL"
STABLE_FIELDS = (
    "banks",
    "max_stack_items_seen",
    "oracle_promotions",
    "shards",
    "trace_promotions",
    "unique_calls",
    "unique_frontiers",
    "unique_instruction_contexts",
    "unique_returns",
    "unique_terminals",
    "wrong_production_bytes",
)


def sha256(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def require(condition: bool, message: str) -> None:
    if not condition:
        raise ValueError(message)


def main() -> int:
    parser = argparse.ArgumentParser()
    root = Path(__file__).resolve().parents[1]
    parser.add_argument(
        "--baseline",
        type=Path,
        default=root / "evidence/v10_2/reset-35m-baseline-summary.json",
    )
    parser.add_argument(
        "--candidate",
        type=Path,
        default=root / "generated/current/v10_2/V10.2-RESET-SCPU-REDISCOVERY.json",
    )
    parser.add_argument(
        "--out",
        type=Path,
        default=root / "generated/current/v10_2/V10.2-RESET-SEMANTIC-CLOSURE.json",
    )
    args = parser.parse_args()

    baseline = json.loads(args.baseline.read_text(encoding="utf-8"))
    candidate = json.loads(args.candidate.read_text(encoding="utf-8"))
    summary = candidate["summary"]

    require(candidate["authority_policy"] ==
            "oracle/traces are checks only and contribute zero contexts",
            "candidate is not source-only")
    require(summary["frontier_types"] == {"SAFETY_STATE_LIMIT": 1},
            "candidate contains a semantic frontier")
    require(len(candidate["frontiers"]) == 1 and
            candidate["frontiers"][0]["type"] == "SAFETY_STATE_LIMIT",
            "candidate frontier rows are not safety-limit-only")
    require(summary["pending_states_at_stop"] > 0,
            "semantic residual certificate is unnecessary for a drained graph")
    require(summary["state_limit"] > baseline["state_limit"],
            "candidate did not extend the baseline state window")
    require(summary["state_limit"] - baseline["state_limit"] >= 10_000_000,
            "semantic stability window is less than ten million states")
    require(baseline["frontier_types"] == {"SAFETY_STATE_LIMIT": 1},
            "baseline contains a semantic frontier")
    for field in STABLE_FIELDS:
        require(summary[field] == baseline[field],
                f"semantic coverage changed across the stability window: {field}")

    semantic_edges = {
        (row["from"], row["to"], row["kind"], row["reason"])
        for row in candidate["edges"]
    }
    context_pairs = {(row["from"], row["to"]) for row in candidate["edges"]}
    certificate = {
        "schema": SCHEMA,
        "status": STATUS,
        "authority": "SOURCE_DISCOVERY_ONLY_NO_ORACLE_OR_TRACE_PROMOTION",
        "baseline": {
            "path": args.baseline.as_posix(),
            "sha256": sha256(args.baseline),
            "state_limit": baseline["state_limit"],
            "states": baseline["states"],
            "pending_states": baseline["pending_states_at_stop"],
        },
        "candidate": {
            "path": args.candidate.as_posix(),
            "sha256": sha256(args.candidate),
            "state_limit": summary["state_limit"],
            "states": summary["states"],
            "pending_redundant_stack_history_states":
                summary["pending_states_at_stop"],
        },
        "stability_window_states": summary["state_limit"] - baseline["state_limit"],
        "stable_semantic_coverage": {
            field: summary[field] for field in STABLE_FIELDS
        },
        "candidate_semantic_edges": len(semantic_edges),
        "candidate_context_pairs": len(context_pairs),
        "residual_frontier_types": summary["frontier_types"],
        "limitations": [
            "The raw full-stack work queue is not represented as empty.",
            "The certificate accepts only safety-limit residue after a ten-million-state semantic stability window.",
            "Any new context, call, return, terminal, ROM mismatch, or non-safety frontier invalidates this certificate.",
        ],
    }
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(certificate, indent=2, sort_keys=True) + "\n",
                        encoding="utf-8", newline="\n")
    print(json.dumps({
        "path": str(args.out),
        "status": STATUS,
        "semantic_edges": len(semantic_edges),
        "context_pairs": len(context_pairs),
        "residual_states": summary["pending_states_at_stop"],
    }, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
