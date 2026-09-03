"""Source-only S-CPU interrupt/vector rediscovery for V10.2.

All non-reserved header vectors are entered in every architecturally legal
E/M/X state.  The exact interrupt frame is represented on the abstract stack
so handler-local calls and pushes are proved without inventing a return PC.
RTI is intentionally the terminal boundary: asynchronous re-entry is admitted
later only to an already-produced interrupted context.
"""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from analysis.v03c_discovery import ROM_SHA256, ROM_SIZE
from analysis.v10_2_dynamic_call_proofs import require, table_targets
from analysis.v10_2_scpu_reset_rediscovery import State, StackItem, analyse

VECTOR_OFFSETS = {
    "native_cop": 0x7FE4,
    "native_brk": 0x7FE6,
    "native_abort": 0x7FE8,
    "native_nmi": 0x7FEA,
    "native_irq": 0x7FEE,
    "emulation_cop": 0x7FF4,
    "emulation_abort": 0x7FF8,
    "emulation_nmi": 0x7FFA,
    "emulation_irq_brk": 0x7FFE,
}
CLOSURE_STATUS = "SEMANTIC_GRAPH_CLOSED_WITH_REDUNDANT_STACK_HISTORY_RESIDUAL"


def u16_at(rom: bytes, offset: int) -> int:
    return rom[offset] | (rom[offset + 1] << 8)


def roots_from_vectors(rom: bytes) -> tuple[list[tuple[State, str]], dict[str, str]]:
    vectors = {name: u16_at(rom, offset) for name, offset in VECTOR_OFFSETS.items()}
    roots: list[tuple[State, str]] = []
    # RESET starts with I=1 and NMITIMEN disabled.  The RESET graph executes
    # CLC/XCE and enters native mode before either interrupt can be admitted.
    # No RESET-reached BRK/COP instruction exists, and the SNES has no exposed
    # ABORT source.  Therefore only native NMI/IRQ are executable roots; the
    # other exact vector words remain audited metadata, not invented code.
    executable_vectors = {"native_nmi", "native_irq"}
    for name, pc in sorted(vectors.items()):
        if name not in executable_vectors:
            continue
        if pc == 0:
            continue
        for m in (0, 1):
            for x in (0, 1):
                frame = (
                    StackItem("DATA", 1),
                    StackItem("DATA", 2),
                    StackItem("STATUS", 1, e=0, m=m, x=x, carry=-1),
                )
                roots.append((State(0, pc, 0, m, x, stack=frame),
                              f"exact {name} header vector/native interrupt frame"))
    unique: dict[State, str] = {}
    for state, reason in roots:
        unique.setdefault(state, reason)
    return sorted(unique.items(), key=lambda item: item[0]), {
        name: f"00:{pc:04X}" for name, pc in sorted(vectors.items())
    }


def selector_proofs(rom: bytes) -> tuple[dict[str, dict], dict]:
    """Prove the NMI/IRQ selector domains from every RESET-reached writer.

    These selectors live in WRAM mirrors $0355/$0356.  Every direct writer in
    the complete converged RESET graph is either STZ or an immediate LDA/STA
    pair.  The production call still checks both X and the fetched target, so
    any future indirect/unproved writer fails closed rather than adding code.
    """
    reset_path = ROOT / "generated/current/v10_2/V10.2-RESET-SCPU-REDISCOVERY.json"
    closure_path = ROOT / "generated/current/v10_2/V10.2-RESET-SEMANTIC-CLOSURE.json"
    reset = json.loads(reset_path.read_text(encoding="utf-8"))
    closure = json.loads(closure_path.read_text(encoding="utf-8"))
    summary = reset["summary"]
    reset_hash = hashlib.sha256(reset_path.read_bytes()).hexdigest()
    reset_closed = summary["unique_frontiers"] == 0 \
        and summary["pending_states_at_stop"] == 0
    reset_certified = closure.get("status") == CLOSURE_STATUS \
        and closure.get("candidate", {}).get("sha256") == reset_hash \
        and summary["frontier_types"] == {"SAFETY_STATE_LIMIT": 1} \
        and {row["type"] for row in reset["frontiers"]} == {"SAFETY_STATE_LIMIT"}
    if not (reset_closed or reset_certified) \
            or reset["rom"]["sha256"] != ROM_SHA256:
        raise ValueError("selector proof requires source-only RESET semantic closure")
    instructions = {row["context"]: row for row in reset["instructions"]}
    incoming: dict[str, list[str]] = {}
    for edge in reset["edges"]:
        incoming.setdefault(edge["to"], []).append(edge["from"])

    values: dict[int, set[int]] = {0x0355: set(), 0x0356: set()}
    writers: dict[int, list[dict]] = {0x0355: [], 0x0356: []}
    for row in reset["instructions"]:
        raw = bytes.fromhex(row["bytes"])
        if row["mode"] != "ABS" or len(raw) != 3:
            continue
        address = raw[1] | (raw[2] << 8)
        if address not in values or row["mnemonic"] not in {"STA", "STZ"}:
            continue
        if row["mnemonic"] == "STZ":
            value = 0
            producer = "STZ literal zero"
        else:
            candidates = []
            for source in incoming.get(row["context"], []):
                pred = instructions[source]
                pred_raw = bytes.fromhex(pred["bytes"])
                if pred["mnemonic"] == "LDA" and pred["mode"] == "IMM_M" \
                        and len(pred_raw) == 2:
                    candidates.append((pred_raw[1], source))
            candidate_values = {item[0] for item in candidates}
            if len(candidate_values) != 1:
                raise ValueError(f"unproved selector writer {row['context']}: {candidates}")
            value = next(iter(candidate_values))
            producer = ",".join(sorted({item[1] for item in candidates}))
        if value & 1:
            raise ValueError(f"odd indexed-call selector ${value:02X} at {row['context']}")
        values[address].add(value)
        writers[address].append({"writer": row["context"], "value": value,
                                 "producer": producer})

    expected = {
        0x0355: {0x00, 0x02, 0x04, 0x06, 0x08, 0x0A, 0x0C, 0x0E, 0x10,
                 0x12, 0x14, 0x16, 0x18, 0x1A, 0x1C, 0x1E, 0x20, 0x22},
        0x0356: {0x00, 0x02, 0x04, 0x06, 0x08},
    }
    if values != expected:
        raise ValueError(f"interrupt selector domains changed: {values}")

    proofs: dict[str, dict] = {}
    specs = [
        (0x0355, 0x8197, ("80:8181:E0M1X1", "80:8181:E1M1X1")),
        (0x0356, 0x8228, ("80:821A:E0M1X1", "80:821A:E1M1X1")),
    ]
    for address, table, contexts in specs:
        offsets = sorted(values[address])
        targets = table_targets(rom, 0x80, table, offsets)
        for context in contexts:
            proofs[context] = {
                "context": context,
                "flow_kind": "CALL",
                "table": f"80:{table:04X}",
                "proved_x_offsets": offsets,
                "targets": targets,
                "source_proof": [
                    f"complete converged RESET graph direct-writer census for WRAM ${address:04X}",
                    "every writer is STZ or an exact immediate LDA/STA pair",
                    "runtime must guard both the X domain and fetched target set",
                ],
                "proof_kind": "COMPLETE_RESET_WRITER_CENSUS_WITH_FAIL_CLOSED_GUARDS",
                "reachability_class": "SOURCE_DERIVED_FINITE_CANDIDATE_SET",
                "production_guards_required": ["index domain", "fetched target set"],
            }

    # $80:FC24 dispatches a bounded nine-state transfer engine.  The complete
    # source writer family initializes $1AE6 to 0 or 1, advances it through
    # four fixed INC sites, can explicitly select state 5, and resets it to 0.
    # The adjacent nine-word table therefore has the exact offset domain
    # {0,2,...,16}; limiting this to its first two states drops live handlers.
    require(rom, 0x80, 0xFB34, "C2209CE61A", "$1AE6 zero initializer")
    require(rom, 0x80, 0xFC0F, "A201008EE61A", "$1AE6 one initializer")
    require(rom, 0x80, 0xFC29,
            "28FC3BFC46FC4FFC94FC3BFC94FC94FCBCFC",
            "complete nine-entry $1AE6 handler table")
    require(rom, 0x80, 0xFC3B,
            "E220A9FD20AEFCEEE61A60A9FE20AEFCEEE61A60",
            "first two $1AE6 state advances")
    require(rom, 0x80, 0xFC8A, "1007E22064DBEEE61A60",
            "third $1AE6 state advance")
    require(rom, 0x80, 0xFCA1, "D0FBE888D0F49C4021EEE61A60",
            "fourth $1AE6 state advance")
    require(rom, 0x80, 0xFCBC, "9CE61A60", "$1AE6 terminal reset")
    require(rom, 0x80, 0xFCF4, "E220A90564DB8DE61A2860",
            "$1AE6 explicit state-five selector")

    # Handler-local finite tables that are not reached by the RESET slice.
    # Each table ends at adjacent executable code.  Their call sites must
    # retain index and target guards; out-of-domain state is a fail-closed
    # cartridge invariant violation, never a request for a runtime decoder.
    bounded = [
        {
            "context": "80:FC24:E0M1X1", "flow_kind": "CALL",
            "bank": 0x80, "base": 0xFC29, "offsets": list(range(0, 18, 2)),
            "sig_pc": 0xFC1F, "signature": "ADE61A0AAAFC29FC",
            "description": "$1AE6 complete source-writer family bounds states to 0 through 8",
        },
        {
            "context": "81:AB23:E0M1X1", "flow_kind": "CALL",
            "bank": 0x81, "base": 0xAB2B, "offsets": list(range(0, 14, 2)),
            "sig_pc": 0xAB1E, "signature": "AD98020AAAFC2BAB",
            "description": "seven-entry $0298 state table ending at code $AB39",
        },
        {
            "context": "80:BF5A:E0M1X1", "flow_kind": "JUMP",
            "bank": 0x80, "base": 0xBF5D, "offsets": list(range(0, 12, 2)),
            "sig_pc": 0xBF55, "signature": "ADEC0B0AAA7C5DBF",
            "description": "six-entry $0BEC state tail table ending at code $BF69",
        },
        {
            "context": "92:E545:E0M1X1", "flow_kind": "JUMP",
            "bank": 0x92, "base": 0xE548, "offsets": list(range(0, 12, 2)),
            "sig_pc": 0xE53E, "signature": "AD970229070AAA7C48E5",
            "description": "six-entry $0297 state tail table ending at code $E554",
        },
    ]
    for spec in bounded:
        require(rom, spec["bank"], spec["sig_pc"], spec["signature"],
                spec["description"])
        proofs[spec["context"]] = {
            "context": spec["context"],
            "flow_kind": spec["flow_kind"],
            "table": f"{spec['bank']:02X}:{spec['base']:04X}",
            "proved_x_offsets": spec["offsets"],
            "targets": table_targets(rom, spec["bank"], spec["base"], spec["offsets"]),
            "source_proof": [
                spec["description"],
                "exact call-site signature and adjacent finite ROM table",
                "production guards both the X domain and fetched target set",
            ],
            "proof_kind": "FINITE_INTERRUPT_HANDLER_TABLE_WITH_FAIL_CLOSED_GUARDS",
            "reachability_class": "SOURCE_DERIVED_FINITE_CANDIDATE_SET",
            "production_guards_required": ["index domain", "fetched target set"],
        }
    evidence = {
        f"{address:04X}": {
            "values": sorted(values[address]),
            "writers": sorted(writers[address], key=lambda row: row["writer"]),
        }
        for address in sorted(values)
    }
    return proofs, evidence


def build(rom: bytes) -> dict:
    digest = hashlib.sha256(rom).hexdigest()
    if len(rom) != ROM_SIZE or digest != ROM_SHA256:
        raise ValueError(f"wrong ROM identity: size={len(rom)} sha256={digest}")
    roots, vectors = roots_from_vectors(rom)
    selector_call_proofs, selector_evidence = selector_proofs(rom)
    report = analyse(
        rom,
        roots,
        schema="rock-n-roll-racing-v10.2-vector-rediscovery-v1",
        method="exact-header-vector source-only W65C816 handler reconstruction",
        indirect_proof_overrides=selector_call_proofs,
    )
    report["vectors"] = vectors
    report["selector_writer_evidence"] = selector_evidence
    report["selector_call_proofs"] = [
        selector_call_proofs[key] for key in sorted(selector_call_proofs)
    ]
    unexpected = [row for row in report["frontiers"] if row["type"] != "RTI"]
    report["interrupt_summary"] = {
        "root_states": len(roots),
        "rti_contexts": sum(row["type"] == "RTI" for row in report["frontiers"]),
        "unexpected_frontiers": len(unexpected),
        "oracle_promotions": 0,
        "trace_promotions": 0,
    }
    report["unexpected_frontiers"] = unexpected
    return report


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("rom", type=Path)
    parser.add_argument(
        "--out",
        type=Path,
        default=ROOT / "generated/current/v10_2/V10.2-VECTOR-SCPU-REDISCOVERY.json",
    )
    args = parser.parse_args()
    report = build(args.rom.read_bytes())
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(report, indent=2, sort_keys=True) + "\n",
                        encoding="utf-8", newline="\n")
    print(json.dumps({
        "contexts": report["summary"]["unique_instruction_contexts"],
        "states": report["summary"]["states"],
        "rti_contexts": report["interrupt_summary"]["rti_contexts"],
        "unexpected_frontiers": report["interrupt_summary"]["unexpected_frontiers"],
        "pending_states": report["summary"]["pending_states_at_stop"],
    }, sort_keys=True))
    if report["interrupt_summary"]["unexpected_frontiers"] \
            or report["summary"]["pending_states_at_stop"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
