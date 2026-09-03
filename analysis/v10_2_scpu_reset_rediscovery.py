"""Independent RESET-forward S-CPU rediscovery for Rock n' Roll Racing V10.2.

This is the same repair discipline used for Rock n' Roll Racing: build a fresh
W65C816 context graph from the exact ROM bytes first, record every boundary,
and compare it with the currently generated production context set only after
the new graph is complete.  Emulator/oracle output is never a discovery input.
"""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
from collections import Counter, defaultdict, deque
from dataclasses import dataclass
from pathlib import Path
import sys
import time

ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from analysis.v03c_discovery import (  # CPU specification/mapping only
    Decoded,
    ROM_SHA256,
    ROM_SIZE,
    State as DecodeState,
    next_pc,
    s8,
    s16,
    u16,
    u24,
)
from analysis.w65c816.opcodes import OPCODES, instruction_length

MAX_STATES = 35_000_000
MAX_CALL_DEPTH = 48
CONDITIONAL = {"BPL", "BMI", "BVC", "BVS", "BCC", "BCS", "BNE", "BEQ"}
CARRY_UNKNOWN = {"ADC", "SBC", "CMP", "CPX", "CPY", "ASL", "LSR", "ROL", "ROR"}
STOP_MNEMONICS = {"WAI", "STP", "BRK", "COP", "RTI"}
NO_SP_REL = 1 << 30


def runtime_lorom_offset(bank: int, pc: int, rom_size: int) -> int:
    """Map the exact cartridge's complete LoROM bus window, including mirrors.

    V01C intentionally accepted only one unique source window.  Execution is
    broader: banks $40-$7D/$C0-$FF expose ROM in both halves, and ROM address
    lines mirror this 1 MiB image.  This is the same mature mapping rule used
    by the Top Gear runtime; PBR is still retained in the context key.
    """
    bank &= 0xFF
    pc &= 0xFFFF
    if bank in (0x7E, 0x7F):
        raise ValueError("WRAM bank is not cartridge ROM")
    low_bank = bank & 0x7F
    if low_bank < 0x40 and pc < 0x8000:
        raise ValueError("CPU low-bank lower half is not cartridge ROM")
    return (((low_bank << 15) | (pc & 0x7FFF)) % rom_size)


def read_source_instruction(rom: bytes, state: DecodeState) -> Decoded:
    physical = runtime_lorom_offset(state.pbr, state.pc, len(rom))
    opcode = rom[physical]
    spec = OPCODES[opcode]
    length = instruction_length(spec, state.m, state.x)
    raw = bytearray()
    for index in range(length):
        pc = (state.pc + index) & 0xFFFF
        raw.append(rom[runtime_lorom_offset(state.pbr, pc, len(rom))])
    return Decoded(state, physical, spec, bytes(raw), length)


@dataclass(frozen=True, order=True)
class StackItem:
    kind: str
    width: int
    bank: int = -1
    pc: int = -1
    caller: str = ""
    e: int = -1
    m: int = -1
    x: int = -1
    carry: int = -1


@dataclass(frozen=True, order=True)
class State:
    bank: int
    pc: int
    e: int
    m: int
    x: int
    carry: int = -1
    stack: tuple[StackItem, ...] = ()
    a_sp_rel: int = NO_SP_REL
    x_sp_rel: int = NO_SP_REL
    saved_s_stack: tuple[StackItem, ...] = ()
    saved_s_valid: bool = False
    a_from_saved_s: bool = False
    x_from_saved_s: bool = False

    @property
    def context(self) -> str:
        return f"{self.bank:02X}:{self.pc:04X}:E{self.e}M{self.m}X{self.x}"

    def decode_state(self) -> DecodeState:
        return DecodeState(self.bank, self.pc, self.e, self.m, self.x,
                           self.carry, -1, -1, "PROVED")


def change(st: State, *, bank: int | None = None, pc: int | None = None,
           e: int | None = None, m: int | None = None, x: int | None = None,
           carry: int | None = None,
           stack: tuple[StackItem, ...] | None = None,
           a_sp_rel: int | None = None,
           x_sp_rel: int | None = None,
           saved_s_stack: tuple[StackItem, ...] | None = None,
           saved_s_valid: bool | None = None,
           a_from_saved_s: bool | None = None,
           x_from_saved_s: bool | None = None) -> State:
    return State(st.bank if bank is None else bank,
                 st.pc if pc is None else pc,
                 st.e if e is None else e,
                 st.m if m is None else m,
                 st.x if x is None else x,
                 st.carry if carry is None else carry,
                 st.stack if stack is None else stack,
                 st.a_sp_rel if a_sp_rel is None else a_sp_rel,
                 st.x_sp_rel if x_sp_rel is None else x_sp_rel,
                 st.saved_s_stack if saved_s_stack is None else saved_s_stack,
                 st.saved_s_valid if saved_s_valid is None else saved_s_valid,
                 st.a_from_saved_s if a_from_saved_s is None else a_from_saved_s,
                 st.x_from_saved_s if x_from_saved_s is None else x_from_saved_s)


def consume_data(stack: tuple[StackItem, ...], width: int) -> tuple[tuple[StackItem, ...], bool]:
    """Consume exactly `width` data bytes, allowing width-changing split pulls."""
    items = list(stack)
    remaining = width
    while remaining and items:
        top = items[-1]
        if top.kind != "DATA":
            return stack, False
        if top.width <= remaining:
            remaining -= top.width
            items.pop()
        else:
            items[-1] = StackItem("DATA", top.width - remaining)
            remaining = 0
    return (tuple(items), remaining == 0)


def discard_stack_bytes(stack: tuple[StackItem, ...], width: int) -> tuple[tuple[StackItem, ...], bool]:
    """Apply a source-proved positive TXS cleanup without crossing a return."""
    return consume_data(stack, width)


def production_contexts() -> tuple[set[str], dict[str, str]]:
    path = ROOT / "docs/V05C-production-manifest.csv"
    contexts: set[str] = set()
    dispositions: dict[str, str] = {}
    with path.open(encoding="utf-8", newline="") as handle:
        for row in csv.DictReader(handle):
            contexts.add(row["Key"])
            dispositions[row["Key"]] = row["Disposition"]
    return contexts, dispositions


def dynamic_call_proofs() -> dict[str, dict]:
    path = ROOT / "generated/current/v10_2/V10.2-DYNAMIC-CALL-PROOFS.json"
    if not path.exists():
        return {}
    report = json.loads(path.read_text(encoding="utf-8"))
    if report.get("schema") != "RRR_V10_2_DYNAMIC_CALL_PROOFS_V1":
        raise ValueError(f"unsupported dynamic-call proof schema: {path}")
    policy = report.get("authority_policy", {})
    if not policy.get("source_bytes_only") or policy.get("oracle_promotions") != 0 \
            or policy.get("trace_promotions") != 0:
        raise ValueError(f"dynamic-call proofs violate source-only policy: {path}")
    return {row["context"]: row for row in report["proofs"]}


def hardware_access(mode: str, raw: bytes) -> dict | None:
    if mode not in {"ABS", "ABS_X", "ABS_Y"} or len(raw) < 3:
        return None
    address = u16(raw)
    if 0x2100 <= address <= 0x21FF:
        area = "PPU_APU_WRAM_PORT"
    elif 0x4016 <= address <= 0x4017:
        area = "CONTROLLER"
    elif 0x4200 <= address <= 0x421F:
        area = "CPU_IO"
    elif 0x4300 <= address <= 0x437F:
        area = "DMA_HDMA"
    else:
        return None
    return {"address": f"00:{address:04X}", "area": area,
            "indexed": mode in {"ABS_X", "ABS_Y"}}


def analyse(rom: bytes, roots: list[tuple[State, str]] | None = None,
            *, schema: str = "rock-n-roll-racing-v10.2-reset-rediscovery-v1",
            method: str = "independent ROM-byte RESET-forward W65C816 context reconstruction",
            indirect_proof_overrides: dict[str, dict] | None = None,
            max_states: int = MAX_STATES,
            progress_every: int = 0) -> dict:
    digest = hashlib.sha256(rom).hexdigest()
    if len(rom) != ROM_SIZE or digest != ROM_SHA256:
        raise ValueError(f"wrong ROM identity: size={len(rom)} sha256={digest}")

    reset = rom[0x7FFC] | (rom[0x7FFD] << 8)
    initial = State(0, reset, 1, 1, 1)
    indirect_proofs = dynamic_call_proofs()
    if indirect_proof_overrides:
        indirect_proofs.update(indirect_proof_overrides)
    root_rows = roots if roots is not None else [
        (initial, "hardware emulation RESET vector")
    ]
    queue = deque(root_rows)
    seen: set[State] = set()
    rows: dict[str, dict] = {}
    edges_by_key: dict[tuple[str, str, str, str, int], dict] = {}
    frontiers: list[dict] = []
    calls: list[dict] = []
    returns: list[dict] = []
    terminals: list[dict] = []
    max_stack_items_seen = 0
    raw_edge_rows = 0
    started = time.monotonic()

    def push(src: State, dst: State, kind: str, reason: str) -> None:
        nonlocal raw_edge_rows
        raw_edge_rows += 1
        row = {"from": src.context, "to": dst.context,
               "kind": kind, "reason": reason,
               "source_stack_depth": len(src.stack)}
        key = (src.context, dst.context, kind, reason, len(src.stack))
        edges_by_key.setdefault(key, row)
        queue.append((dst, reason))

    while queue:
        st, origin = queue.popleft()
        if st in seen:
            continue
        seen.add(st)
        max_stack_items_seen = max(max_stack_items_seen, len(st.stack))
        if progress_every and len(seen) % progress_every == 0:
            elapsed = time.monotonic() - started
            print(
                json.dumps({
                    "discovery_progress": {
                        "elapsed_seconds": round(elapsed, 1),
                        "pending_states": len(queue),
                        "states": len(seen),
                    }
                }, sort_keys=True),
                file=sys.stderr,
                flush=True,
            )
        if len(seen) > max_states:
            frontiers.append({"type": "SAFETY_STATE_LIMIT", "states": len(seen)})
            break
        try:
            decoded = read_source_instruction(rom, st.decode_state())
        except (IndexError, ValueError) as exc:
            frontiers.append({"type": "NON_ROM_EXECUTION", "context": st.context,
                              "detail": str(exc)})
            continue
        raw = decoded.raw
        mnemonic = decoded.spec.mnemonic
        mode = decoded.spec.mode
        after = next_pc(decoded)
        row = rows.setdefault(st.context, {
            "context": st.context,
            "bank": st.bank,
            "pc": st.pc,
            "e": st.e,
            "m": st.m,
            "x": st.x,
            "physical": decoded.physical,
            "bytes": raw.hex().upper(),
            "mnemonic": mnemonic,
            "mode": mode,
            "length": decoded.length,
            "hardware_access": hardware_access(mode, raw),
            "origins": set(),
            "stack_depths": set(),
        })
        row["origins"].add(origin)
        row["stack_depths"].add(len(st.stack))

        terminal_proof = indirect_proofs.get(st.context)
        if terminal_proof and terminal_proof.get("flow_kind") == "TERMINAL_PATH":
            terminals.append({
                "context": st.context,
                "instruction": mnemonic,
                "proof_kind": terminal_proof["proof_kind"],
                "reason": terminal_proof["terminal_reason"],
            })
            continue

        if mnemonic == "CLC":
            push(st, change(st, pc=after, carry=0), "fallthrough", "CLC")
            continue
        if mnemonic == "SEC":
            push(st, change(st, pc=after, carry=1), "fallthrough", "SEC")
            continue
        if mnemonic == "XCE":
            if st.carry < 0:
                frontiers.append({"type": "UNKNOWN_XCE_CARRY", "context": st.context,
                                  "bytes": raw.hex().upper()})
                continue
            new_e = st.carry
            push(st, change(st, pc=after, e=new_e,
                            m=1 if new_e else st.m,
                            x=1 if new_e else st.x,
                            carry=st.e), "fallthrough", "exact XCE C/E exchange")
            continue
        if mnemonic in {"REP", "SEP"}:
            mask = raw[1]
            new_m, new_x, new_c = st.m, st.x, st.carry
            if not st.e:
                if mask & 0x20:
                    new_m = 0 if mnemonic == "REP" else 1
                if mask & 0x10:
                    new_x = 0 if mnemonic == "REP" else 1
            if mask & 0x01:
                new_c = 0 if mnemonic == "REP" else 1
            push(st, change(st, pc=after, m=new_m, x=new_x, carry=new_c),
                 "fallthrough", f"{mnemonic} #${mask:02X}")
            continue
        if mnemonic == "PLP":
            if not st.stack or st.stack[-1].kind != "STATUS" or st.stack[-1].width != 1:
                frontiers.append({"type": "STATUS_PULL", "context": st.context,
                                  "bytes": raw.hex().upper(),
                                  "detail": "E/M/X require a source-proved top-of-stack PHP producer"})
                continue
            status = st.stack[-1]
            new_e = st.e
            new_m = 1 if new_e else status.m
            new_x = 1 if new_e else status.x
            push(st, change(st, pc=after, m=new_m, x=new_x,
                            carry=status.carry, stack=st.stack[:-1]),
                 "fallthrough", "PLP paired with exact PHP status byte")
            continue
        if mnemonic == "PHP":
            item = StackItem("STATUS", 1, e=st.e, m=st.m, x=st.x, carry=st.carry)
            push(st, change(st, pc=after, stack=st.stack + (item,)),
                 "fallthrough", "PHP exact status producer")
            continue
        push_widths = {
            "PHA": 1 if st.m else 2,
            "PHX": 1 if st.x else 2,
            "PHY": 1 if st.x else 2,
            "PHB": 1,
            "PHK": 1,
            "PHD": 2,
            "PEA": 2,
            "PEI": 2,
            "PER": 2,
        }
        if mnemonic in push_widths:
            width = push_widths[mnemonic]
            item = StackItem("DATA", width)
            push(st, change(st, pc=after, stack=st.stack + (item,)),
                 "fallthrough", f"{mnemonic} source-known stack width")
            continue
        pull_widths = {
            "PLA": 1 if st.m else 2,
            "PLX": 1 if st.x else 2,
            "PLY": 1 if st.x else 2,
            "PLB": 1,
            "PLD": 2,
        }
        if mnemonic in pull_widths:
            width = pull_widths[mnemonic]
            proof = indirect_proofs.get(st.context)
            if mnemonic == "PLA" and proof \
                    and proof.get("flow_kind") == "STACK_RETURN_REWRITE":
                expected_tail = (("DATA", 2), ("DATA", 2), ("RET16", 2))
                actual_tail = tuple((item.kind, item.width) for item in st.stack[-3:])
                if len(st.stack) < 3 or actual_tail != expected_tail:
                    frontiers.append({
                        "type": "STACK_RETURN_REWRITE_MISMATCH",
                        "context": st.context,
                        "expected_tail": expected_tail,
                        "stack_tail": [
                            {"kind": item.kind, "width": item.width,
                             "bank": item.bank, "pc": item.pc,
                             "caller": item.caller}
                            for item in st.stack[-5:]
                        ],
                    })
                    continue
                return_frame = st.stack[-1]
                upper_record_word = st.stack[-2]
                new_stack = st.stack[:-3] + (return_frame, upper_record_word)
                push(st, change(st, pc=after, stack=new_stack), "fallthrough",
                     "source-proved PLA/STA $03,S/PLA/RTS return rewrite")
                continue
            new_stack, ok = consume_data(st.stack, width)
            if not ok:
                frontiers.append({"type": "DATA_PULL", "context": st.context,
                                  "instruction": mnemonic, "width": width,
                                  "detail": "source stack item absent or width differs",
                                  "stack_tail": [
                                      {"kind": item.kind, "width": item.width,
                                       "bank": item.bank, "pc": item.pc,
                                       "caller": item.caller}
                                      for item in st.stack[-4:]
                                  ]})
                continue
            push(st, change(st, pc=after, stack=new_stack), "fallthrough",
                 f"{mnemonic} paired with exact-width source push")
            continue
        # Preserve only the small affine stack-pointer idiom needed for the
        # ROM's TSX/TXA/ADC/TAX/TXS caller cleanup. This is the exact RockNRollRacing
        # Strike repair technique; it proves a byte count instead of guessing.
        if mnemonic == "TSX" and not st.x:
            push(st, change(st, pc=after, x_sp_rel=0, x_from_saved_s=False), "fallthrough",
                 "TSX establishes X=S")
            continue
        if mnemonic == "TSC" and not st.m:
            push(st, change(st, pc=after, a_sp_rel=0, a_from_saved_s=False),
                 "fallthrough", "TSC establishes A=S")
            continue
        if mnemonic == "STA" and mode == "ABS" and u16(raw) == 0x02C8 \
                and st.a_sp_rel == 0:
            push(st, change(st, pc=after, saved_s_stack=st.stack,
                            saved_s_valid=True, a_from_saved_s=False),
                 "fallthrough", "source-proved save of S to $02C8")
            continue
        if mnemonic == "STX" and mode == "ABS" and u16(raw) == 0x035D \
                and st.x_sp_rel == 0:
            push(st, change(st, pc=after, saved_s_stack=st.stack,
                            saved_s_valid=True, x_from_saved_s=False),
                 "fallthrough", "source-proved save of S to $035D")
            continue
        # The two save slots are ordinary WRAM.  Any other absolute store to
        # either one overwrites the proof token; retaining an older abstract
        # stack here would be both unsound and a source of unbounded variants.
        if mnemonic in {"STA", "STX", "STY", "STZ"} and mode == "ABS" \
                and u16(raw) in {0x02C8, 0x035D}:
            push(st, change(st, pc=after, saved_s_stack=(),
                            saved_s_valid=False,
                            a_from_saved_s=False, x_from_saved_s=False),
                 "fallthrough", "write invalidates saved-S proof token")
            continue
        if mnemonic == "LDA" and mode == "ABS" and u16(raw) == 0x02C8 \
                and st.saved_s_valid:
            push(st, change(st, pc=after, a_sp_rel=NO_SP_REL,
                            a_from_saved_s=True),
                 "fallthrough", "source-proved reload of saved S from $02C8")
            continue
        if mnemonic == "LDX" and mode == "ABS" and u16(raw) == 0x035D \
                and st.saved_s_valid:
            push(st, change(st, pc=after, x_sp_rel=NO_SP_REL,
                            x_from_saved_s=True),
                 "fallthrough", "source-proved reload of saved S from $035D")
            continue
        if mnemonic == "TCS" and st.a_from_saved_s and st.saved_s_valid:
            push(st, change(st, pc=after, stack=st.saved_s_stack,
                            a_sp_rel=NO_SP_REL, x_sp_rel=NO_SP_REL,
                            saved_s_stack=(), saved_s_valid=False,
                            a_from_saved_s=False, x_from_saved_s=False),
                 "fallthrough", "TCS restores exact stack saved in $02C8")
            continue
        if mnemonic == "TXS" and st.x_from_saved_s and st.saved_s_valid:
            push(st, change(st, pc=after, stack=st.saved_s_stack,
                            a_sp_rel=NO_SP_REL, x_sp_rel=NO_SP_REL,
                            saved_s_stack=(), saved_s_valid=False,
                            a_from_saved_s=False, x_from_saved_s=False),
                 "fallthrough", "TXS restores exact stack saved in $035D")
            continue
        if mnemonic == "TCS" and st.a_sp_rel != NO_SP_REL:
            if st.a_sp_rel < 0:
                new_stack = st.stack + (StackItem("DATA", -st.a_sp_rel),)
                reason = f"TCS source-proved allocation of {-st.a_sp_rel} bytes"
            else:
                new_stack, ok = discard_stack_bytes(st.stack, st.a_sp_rel)
                if not ok:
                    frontiers.append({"type": "STACK_POINTER_REBASE", "context": st.context,
                                      "detail": f"cannot prove discard of {st.a_sp_rel} data bytes"})
                    continue
                reason = f"TCS source-proved discard of {st.a_sp_rel} bytes"
            push(st, change(st, pc=after, stack=new_stack,
                            a_sp_rel=NO_SP_REL, x_sp_rel=NO_SP_REL,
                            a_from_saved_s=False), "fallthrough", reason)
            continue
        if mnemonic == "TXA" and not st.m and not st.x:
            push(st, change(st, pc=after, a_sp_rel=st.x_sp_rel), "fallthrough",
                 "TXA preserves affine S relation")
            continue
        if mnemonic == "TAX" and not st.m and not st.x:
            push(st, change(st, pc=after, x_sp_rel=st.a_sp_rel,
                            x_from_saved_s=False), "fallthrough",
                 "TAX preserves affine S relation")
            continue
        if mnemonic == "ADC" and mode == "IMM_M" and not st.m and st.carry == 0 \
                and st.a_sp_rel != NO_SP_REL:
            value = u16(raw)
            push(st, change(st, pc=after, a_sp_rel=st.a_sp_rel + value,
                            carry=-1), "fallthrough",
                 f"ADC #${value:04X} advances affine S relation")
            continue
        if mnemonic == "SBC" and mode == "IMM_M" and not st.m and st.carry == 1 \
                and st.a_sp_rel != NO_SP_REL:
            value = u16(raw)
            push(st, change(st, pc=after, a_sp_rel=st.a_sp_rel - value,
                            carry=-1), "fallthrough",
                 f"SBC #${value:04X} retreats affine S relation")
            continue
        if mnemonic == "TXS" and st.x_sp_rel != NO_SP_REL:
            if st.x_sp_rel < 0:
                frontiers.append({"type": "STACK_POINTER_REBASE", "context": st.context,
                                  "detail": "negative TXS stack adjustment unsupported"})
                continue
            new_stack, ok = discard_stack_bytes(st.stack, st.x_sp_rel)
            if not ok:
                frontiers.append({"type": "STACK_POINTER_REBASE", "context": st.context,
                                  "detail": f"cannot prove discard of {st.x_sp_rel} data bytes"})
                continue
            push(st, change(st, pc=after, stack=new_stack,
                            a_sp_rel=NO_SP_REL, x_sp_rel=NO_SP_REL,
                            x_from_saved_s=False),
                 "fallthrough", f"TXS source-proved discard of {st.x_sp_rel} bytes")
            continue
        if mnemonic in CONDITIONAL:
            target = (after + s8(raw[1])) & 0xFFFF
            push(st, change(st, pc=after), "branch_not_taken",
                 "data-dependent condition")
            push(st, change(st, pc=target), "branch_taken",
                 "data-dependent condition")
            continue
        if mnemonic in {"BRA", "BRL"}:
            displacement = s8(raw[1]) if mnemonic == "BRA" else s16(u16(raw))
            push(st, change(st, pc=(after + displacement) & 0xFFFF), "branch",
                 "encoded relative branch")
            continue
        if mnemonic in {"JSR", "JSL"}:
            if len(st.stack) >= MAX_CALL_DEPTH:
                frontiers.append({"type": "CALL_DEPTH_LIMIT", "context": st.context})
                continue
            if mnemonic == "JSR" and mode == "ABS_JUMP":
                bank, pc, kind = st.bank, u16(raw), "JSR"
            elif mnemonic == "JSL" and mode == "ABSL_JUMP":
                bank, pc, kind = raw[3], u16(raw), "JSL"
            elif mnemonic == "JSR" and mode == "ABS_X_IND" \
                    and st.context in indirect_proofs:
                proof = indirect_proofs[st.context]
                if proof.get("flow_kind") != "CALL":
                    raise ValueError(f"jump proof used at call site {st.context}")
                for target in proof["targets"]:
                    bank = int(target[0:2], 16)
                    pc = int(target[3:7], 16)
                    frame = StackItem("RET16", 2, st.bank, after, st.context)
                    dst = change(st, bank=bank, pc=pc, stack=st.stack + (frame,))
                    calls.append({"context": st.context, "kind": "JSR_INDEXED_PROVED",
                                  "target": dst.context,
                                  "continuation": f"{st.bank:02X}:{after:04X}",
                                  "proof_kind": proof["proof_kind"]})
                    push(st, dst, "call", f"source-proved finite indirect call: {proof['proof_kind']}")
                continue
            else:
                frontiers.append({"type": "DYNAMIC_CALL", "context": st.context,
                                  "instruction": mnemonic, "mode": mode,
                                  "bytes": raw.hex().upper()})
                continue
            frame = StackItem("RET16" if kind == "JSR" else "RET24",
                              2 if kind == "JSR" else 3,
                              st.bank, after, st.context)
            dst = change(st, bank=bank, pc=pc, stack=st.stack + (frame,))
            calls.append({"context": st.context, "kind": kind,
                          "target": dst.context, "continuation": f"{st.bank:02X}:{after:04X}"})
            push(st, dst, "call", "encoded direct call")
            continue
        if mnemonic in {"JMP", "JML"}:
            if mnemonic == "JMP" and mode == "ABS_JUMP":
                dst = change(st, pc=u16(raw))
            elif mnemonic == "JML" and mode == "ABSL_JUMP":
                dst = change(st, bank=raw[3], pc=u16(raw))
            elif mnemonic == "JMP" and mode in {"ABS_X_IND", "ABS_IND"} \
                    and st.context in indirect_proofs:
                proof = indirect_proofs[st.context]
                if proof.get("flow_kind") != "JUMP":
                    raise ValueError(f"call proof used at jump site {st.context}")
                for target in proof["targets"]:
                    bank = int(target[0:2], 16)
                    pc = int(target[3:7], 16)
                    jump_stack = st.stack
                    synthetic_continuation = proof.get("synthetic_return_continuation")
                    if synthetic_continuation:
                        if not jump_stack or jump_stack[-1].kind != "DATA" \
                                or jump_stack[-1].width != 2:
                            raise ValueError(
                                f"synthetic return producer missing at {st.context}"
                            )
                        cont_bank = int(synthetic_continuation[0:2], 16)
                        cont_pc = int(synthetic_continuation[3:7], 16)
                        jump_stack = jump_stack[:-1] + (
                            StackItem("RET16", 2, cont_bank, cont_pc, st.context),
                        )
                    dst = change(st, bank=bank, pc=pc, stack=jump_stack)
                    push(st, dst, "jump",
                         f"source-proved finite indirect jump: {proof['proof_kind']}")
                continue
            else:
                frontiers.append({"type": "DYNAMIC_JUMP", "context": st.context,
                                  "instruction": mnemonic, "mode": mode,
                                  "bytes": raw.hex().upper()})
                continue
            push(st, dst, "jump", "encoded direct jump")
            continue
        if mnemonic in {"RTS", "RTL"}:
            proof = indirect_proofs.get(st.context)
            if mnemonic == "RTS" and proof \
                    and proof.get("flow_kind") == "SYNTHETIC_RTS_CALL":
                synthetic_tail = len(st.stack) >= 2 and all(
                    item.kind == "DATA" and item.width == 2
                    for item in st.stack[-2:]
                )
                # Some trampolines deliberately return to the same RTS.  Once
                # the synthetic callee has consumed its PEA continuation, the
                # top item is the ordinary RET16 and normal return handling
                # below must run instead of re-entering the trampoline.
                if not synthetic_tail and st.stack \
                        and st.stack[-1].kind == "RET16":
                    proof = None
                elif not synthetic_tail:
                    frontiers.append({
                        "type": "SYNTHETIC_CALL_STACK_MISMATCH",
                        "context": st.context,
                        "stack_tail": [
                            {"kind": item.kind, "width": item.width}
                            for item in st.stack[-4:]
                        ],
                    })
                    continue
                if proof is not None:
                    cont = proof["continuation"]
                    cont_bank = int(cont[0:2], 16)
                    cont_pc = int(cont[3:7], 16)
                    base_stack = st.stack[:-2] + (
                        StackItem("RET16", 2, cont_bank, cont_pc, st.context),
                    )
                    for target in proof["targets"]:
                        bank = int(target[0:2], 16)
                        pc = int(target[3:7], 16)
                        dst = change(st, bank=bank, pc=pc, stack=base_stack)
                        calls.append({
                            "context": st.context,
                            "kind": "SYNTHETIC_RTS_CALL_PROVED",
                            "target": dst.context,
                            "continuation": cont,
                            "proof_kind": proof["proof_kind"],
                        })
                        push(st, dst, "call", "source-proved synthetic RTS call")
                    continue
            if not st.stack:
                frontiers.append({"type": "ROOT_RETURN", "context": st.context,
                                  "instruction": mnemonic})
                continue
            frame = st.stack[-1]
            expected = "RET16" if mnemonic == "RTS" else "RET24"
            if frame.kind != expected:
                # RTL always consumes three bytes.  Some 65816 programs use a
                # preceding JSR frame as the first two bytes and deliberately
                # take the low byte of the next JSR frame as PBR.  Both values
                # are exact source products here: a RET16 stores the JSR
                # continuation, whose pushed low byte is (continuation-1)&FF.
                # Keep the unconsumed high byte as one raw stack byte.
                if mnemonic == "RTL" and frame.kind == "RET16" \
                        and len(st.stack) >= 2 \
                        and st.stack[-2].kind == "RET16" \
                        and st.stack[-2].width == 2:
                    bank_source = st.stack[-2]
                    return_bank = (bank_source.pc - 1) & 0xFF
                    remainder = StackItem("DATA", 1)
                    dst = change(
                        st,
                        bank=return_bank,
                        pc=frame.pc,
                        stack=st.stack[:-2] + (remainder,),
                    )
                    returns.append({
                        "context": st.context,
                        "instruction": "RTL_CROSS_RET16",
                        "callsite": frame.caller,
                        "continuation": dst.context,
                        "bank_byte_source": bank_source.caller,
                    })
                    push(st, dst, "return",
                         "exact RTL crossing adjacent JSR return frames")
                    continue
                frontiers.append({"type": "RETURN_KIND_MISMATCH", "context": st.context,
                                  "instruction": mnemonic, "callsite": frame.caller,
                                  "stack_kind": frame.kind,
                                  "stack_tail": [
                                      {"kind": item.kind, "width": item.width,
                                       "bank": item.bank, "pc": item.pc,
                                       "caller": item.caller}
                                      for item in st.stack[-6:]
                                  ]})
                continue
            dst = change(st, bank=frame.bank, pc=frame.pc, stack=st.stack[:-1])
            returns.append({"context": st.context, "instruction": mnemonic,
                            "callsite": frame.caller, "continuation": dst.context})
            push(st, dst, "return", f"paired {mnemonic} return")
            continue
        if mnemonic in STOP_MNEMONICS:
            frontiers.append({"type": mnemonic, "context": st.context,
                              "bytes": raw.hex().upper(),
                              "detail": "requires interrupt/machine-state authority"})
            continue

        next_carry = -1 if mnemonic in CARRY_UNKNOWN else st.carry
        next_a_rel = st.a_sp_rel
        next_x_rel = st.x_sp_rel
        next_saved_a = st.a_from_saved_s
        next_saved_x = st.x_from_saved_s
        if mnemonic not in {"CLC", "SEC"} and mnemonic not in {"TSX", "TXA", "TAX"}:
            if mnemonic in {"LDA", "PLA", "TSC", "XBA", "AND", "ORA", "EOR", "SBC",
                            "ASL", "LSR", "ROL", "ROR", "INC", "DEC"}:
                next_a_rel = NO_SP_REL
                next_saved_a = False
            if mnemonic in {"LDX", "PLX", "TYX", "INX", "DEX"}:
                next_x_rel = NO_SP_REL
                next_saved_x = False
        push(st, change(st, pc=after, carry=next_carry,
                        a_sp_rel=next_a_rel, x_sp_rel=next_x_rel,
                        a_from_saved_s=next_saved_a,
                        x_from_saved_s=next_saved_x),
             "fallthrough", mnemonic)

    raw_call_rows = len(calls)
    raw_return_rows = len(returns)
    raw_frontier_rows = len(frontiers)
    edges = list(edges_by_key.values())
    calls = list({json.dumps(row, sort_keys=True): row for row in calls}.values())
    returns = list({json.dumps(row, sort_keys=True): row for row in returns}.values())
    terminals = list({json.dumps(row, sort_keys=True): row for row in terminals}.values())
    frontiers = list({json.dumps(row, sort_keys=True): row for row in frontiers}.values())
    edges.sort(key=lambda row: (row["from"], row["to"], row["kind"], row["source_stack_depth"]))
    calls.sort(key=lambda row: (row["context"], row["target"], row["continuation"]))
    returns.sort(key=lambda row: (row["context"], row["continuation"], row["callsite"]))
    terminals.sort(key=lambda row: (row["context"], row["proof_kind"]))
    frontiers.sort(key=lambda row: (row.get("type", ""), row.get("context", ""),
                                    json.dumps(row, sort_keys=True)))

    discovered = set(rows)
    production, dispositions = production_contexts()
    missing = sorted(discovered - production)
    stale = sorted(production - discovered)
    wrong_bytes: list[dict] = []
    production_rows: dict[str, dict] = {}
    with (ROOT / "docs/V05C-production-manifest.csv").open(
            encoding="utf-8", newline="") as handle:
        for prod in csv.DictReader(handle):
            production_rows[prod["Key"]] = prod
    for context, row in rows.items():
        prod = production_rows.get(context)
        if prod is not None and prod["Bytes"] != row["bytes"]:
            wrong_bytes.append({"context": context, "rom": row["bytes"],
                                "production": prod["Bytes"]})

    normalized_rows = []
    for key in sorted(rows):
        row = dict(rows[key])
        row["origins"] = sorted(set(row["origins"]))
        row["stack_depths"] = sorted(set(row["stack_depths"]))
        normalized_rows.append(row)
    bank_counts = Counter(f"{row['bank']:02X}" for row in normalized_rows)
    shard_counts = Counter(f"{((row['bank'] << 16 | row['pc']) >> 10):04X}"
                           for row in normalized_rows)
    frontier_counts = Counter(row["type"] for row in frontiers)
    return {
        "schema": schema,
        "method": method,
        "authority_policy": "oracle/traces are checks only and contribute zero contexts",
        "rom": {"size": len(rom), "sha256": digest,
                "emulation_reset_vector": f"00:{reset:04X}"},
        "roots": [
            {"context": state.context, "origin": origin,
             "stack_depth": len(state.stack)}
            for state, origin in root_rows
        ],
        "summary": {
            "states": len(seen),
            "state_limit": max_states,
            "pending_states_at_stop": len(queue),
            "max_stack_items_seen": max_stack_items_seen,
            "unique_instruction_contexts": len(normalized_rows),
            "unique_rom_bytes": len({offset for row in normalized_rows
                                     for offset in range(row["physical"],
                                                         row["physical"] + row["length"])}),
            "raw_path_edge_rows": raw_edge_rows,
            "raw_path_call_rows": raw_call_rows,
            "raw_path_return_rows": raw_return_rows,
            "raw_path_frontier_rows": raw_frontier_rows,
            "unique_edges": len(edges),
            "unique_calls": len(calls),
            "unique_returns": len(returns),
            "unique_terminals": len(terminals),
            "unique_frontiers": len(frontiers),
            "frontier_types": dict(sorted(frontier_counts.items())),
            "banks": len(bank_counts),
            "shards": len(shard_counts),
            "missing_from_v10_1_production": len(missing),
            "v10_1_production_not_in_reset_slice": len(stale),
            "wrong_production_bytes": len(wrong_bytes),
            "oracle_promotions": 0,
            "trace_promotions": 0,
        },
        "bank_context_counts": dict(sorted(bank_counts.items())),
        "shard_context_counts": dict(sorted(shard_counts.items())),
        "instructions": normalized_rows,
        "edges": edges,
        "calls": calls,
        "returns": returns,
        "terminals": terminals,
        "frontiers": frontiers,
        "production_comparison": {
            "missing_contexts": missing,
            "wrong_bytes": wrong_bytes,
            "production_only_contexts": stale,
            "missing_dispositions": {key: dispositions.get(key, "ABSENT") for key in missing},
        },
        "limitations": [
            "Both outcomes of data-dependent conditional branches are retained.",
            "PLP, indirect transfers, interrupts and non-ROM execution stop at explicit frontiers.",
            "Separate producer/table proofs are required to close each frontier before production.",
        ],
    }


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("rom", type=Path)
    parser.add_argument("--out", type=Path,
                        default=ROOT / "generated/current/v10_2/V10.2-RESET-SCPU-REDISCOVERY.json")
    parser.add_argument("--max-states", type=int, default=MAX_STATES)
    parser.add_argument("--progress-every", type=int, default=1_000_000)
    args = parser.parse_args()
    if args.max_states <= 0:
        parser.error("--max-states must be positive")
    if args.progress_every < 0:
        parser.error("--progress-every must be zero or positive")
    product = analyse(
        args.rom.read_bytes(),
        max_states=args.max_states,
        progress_every=args.progress_every,
    )
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(product, indent=2, sort_keys=True) + "\n",
                        encoding="utf-8", newline="\n")
    print(json.dumps({"summary": product["summary"], "path": str(args.out)},
                     sort_keys=True))


if __name__ == "__main__":
    main()
