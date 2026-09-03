"""Discover the source-derived SPC700 control-flow graph at $0400.

Direct flow and paired calls/returns are followed structurally.  The driver's
PUSH/PUSH/RET dispatch idiom is admitted only from its exact instruction
producer and exact uploaded-ARAM target tables.  Oracle traces are checks only
and are never input to this graph.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import sys
from collections import Counter, deque
from dataclasses import dataclass
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from analysis.spc700_spec import OP_CYCLES, decode
from analysis.v10_1_apu_model import IPL_BYTES, parse_upload_records, reconstruct_aram, require_rom

OUT = ROOT / "generated/current/v10_2/V10.2-SMP-DIRECT-REDISCOVERY.json"
ARAM_OUT = ROOT / "generated/current/v10_2/rnr_v10_2_initial_aram.bin"
KNOWN_OUT = ROOT / "generated/current/v10_2/rnr_v10_2_initial_aram_known.bin"
SCPU_RESET_REPORT = ROOT / "generated/current/v10_2/V10.2-RESET-SCPU-REDISCOVERY.json"

SIMPLE_BRANCHES = {0x10, 0x30, 0x50, 0x70, 0x90, 0xB0, 0xD0, 0xF0}
BIT_BRANCHES = set(range(0x03, 0x100, 0x10))
COUNT_BRANCHES = {0x2E, 0x6E, 0xDE, 0xFE}
CONDITIONAL_BRANCHES = SIMPLE_BRANCHES | BIT_BRANCHES | COUNT_BRANCHES
RETURN_OPCODES = {0x6F, 0x7F}
HALT_OPCODES = {0xEF, 0xFF}
MAX_RETURN_DEPTH = 32


@dataclass(frozen=True, order=True)
class State:
    pc: int
    returns: tuple[int, ...] = ()


def read16(aram: bytes, known: bytes, address: int) -> int:
    lo = address & 0xFFFF
    hi = (lo + 1) & 0xFFFF
    if not known[lo] or not known[hi]:
        raise ValueError(f"unknown ARAM vector/table word at ${lo:04X}")
    return aram[lo] | (aram[hi] << 8)


def pushed_return_table(aram: bytes, known: bytes, ret_pc: int) -> dict | None:
    """Prove the exact driver idiom which turns RET into a table dispatcher.

    BPL not taken proves A>=80, then CMP A,#BA followed by BCS not taken proves
    A<BA.  ASL A; MOV Y,A therefore proves Y={00,02,...,72}.  The following two
    MOV A,abs+Y / PUSH pairs place the target on the hardware stack before RET.
    No observed runtime register value is used.
    """
    start = (ret_pc - 16) & 0xFFFF
    addresses = [(start + index) & 0xFFFF for index in range(17)]
    if not all(known[address] for address in addresses):
        return None
    raw = bytes(aram[address] for address in addresses)
    if not (raw[0:6] == bytes((0x10, 0x14, 0x68, 0xBA, 0xB0, 0x0B)) and
            raw[6:8] == bytes((0x1C, 0xFD)) and
            raw[8] == 0xF6 and raw[11] == 0x2D and
            raw[12] == 0xF6 and raw[15:] == bytes((0x2D, 0x6F))):
        return None
    first_push_base = raw[9] | (raw[10] << 8)
    second_push_base = raw[13] | (raw[14] << 8)
    targets: dict[int, list[int]] = {}
    table_bytes: set[int] = set()
    accumulator_domain = range(0x80, 0xBA)
    index_domain = [(a << 1) & 0xFF for a in accumulator_domain]
    for y in index_domain:
        first_address = (first_push_base + y) & 0xFFFF
        second_address = (second_push_base + y) & 0xFFFF
        if not known[first_address] or not known[second_address]:
            raise ValueError(f"unknown pushed-RET table byte for Y=${y:02X} at ${ret_pc:04X}")
        # RET pops the last value pushed first.  Therefore the second table byte
        # becomes target low and the first table byte becomes target high.
        target = aram[second_address] | (aram[first_address] << 8)
        targets.setdefault(target, []).append(y)
        table_bytes.update((first_address, second_address))
    return {
        "pc": f"{ret_pc:04X}",
        "idiom_start": f"{start:04X}",
        "producer_bytes": raw.hex().upper(),
        "accumulator_domain_proof": "BPL not taken => A>=80; CMP A,#BA and BCS not taken => A<BA",
        "accumulator_domain": [f"{a:02X}" for a in accumulator_domain],
        "index_proof": "ASL A then MOV Y,A maps A=80..B9 to even Y=00..72",
        "index_domain": [f"{y:02X}" for y in index_domain],
        "first_push_table_base_target_high": f"{first_push_base:04X}",
        "second_push_table_base_target_low": f"{second_push_base:04X}",
        "table_byte_addresses": [f"{address:04X}" for address in sorted(table_bytes)],
        "targets": [
            {"pc": f"{target:04X}", "indices": [f"{y:02X}" for y in values]}
            for target, values in sorted(targets.items())
        ],
    }


def lorom_bytes(rom: bytes, bank: int, address: int, size: int) -> bytes:
    """Read an exact upper-half LoROM source interval without mirroring."""
    if address < 0x8000 or address + size > 0x10000:
        raise ValueError(f"invalid LoROM source interval ${bank:02X}:{address:04X}+{size}")
    physical = ((bank & 0x7F) * 0x8000) + (address - 0x8000)
    if physical + size > len(rom):
        raise ValueError(f"LoROM source interval exceeds the pinned ROM at ${bank:02X}:{address:04X}")
    return rom[physical:physical + size]


def host_audio_command_proof(rom: bytes) -> dict:
    """Prove every command ID which the 65C816 can place in S-SMP port 2.

    The reset rediscovery graph is the authority for reachable callers of the
    queue routine.  Exact ROM producer sequences then prove the low byte saved
    in $1AA2,X.  The queue transmitter ORs that byte into the low six bits sent
    to APUIO2 ($2142); the upper two bits are only the handshake sequence.
    """
    reset = json.loads(SCPU_RESET_REPORT.read_text(encoding="utf-8"))
    incoming = {
        edge["from"]
        for edge in reset["edges"]
        if edge["to"].startswith("80:F9C2:")
    }
    expected_incoming = {
        "80:F915:E0M1X1",
        "80:F922:E0M1X1",
        "80:F93A:E0M1X0",
        "80:F93A:E0M1X1",
        "80:F952:E0M1X1",
        "80:F961:E0M1X1",
        "80:F97E:E0M1X1",
    }
    if incoming != expected_incoming:
        raise ValueError(
            "65C816 audio queue caller set changed: "
            f"expected {sorted(expected_incoming)}, observed {sorted(incoming)}"
        )

    producers = (
        (0xF910, bytes.fromhex("A902EBA90120C2F960"), (0x01,), "fixed command 01"),
        (0xF91D, bytes.fromhex("A901EBA90120C2F960"), (0x01,), "fixed command 01"),
        (0xF933, bytes.fromhex("C932B009EBA90220C2F9"), (0x02,), "A<32 path selects command 02"),
        (0xF940, bytes.fromhex("38E932EBA90B80F2"), (0x0B,), "A>=32 path selects command 0B"),
        (0xF94C, bytes.fromhex("08E220EBA90C20C2F92860"), (0x0C,), "fixed command 0C"),
        (0xF95B, bytes.fromhex("08E220EBA90D20C2F92860"), (0x0D,), "fixed command 0D"),
        (0xF97B, bytes.fromhex("EBA90720C2F960"), (0x07,), "fixed command 07"),
    )
    producer_rows = []
    command_ids: set[int] = set()
    for address, expected, commands, reason in producers:
        observed = lorom_bytes(rom, 0x80, address, len(expected))
        if observed != expected:
            raise ValueError(
                f"65C816 audio command producer changed at $80:{address:04X}: "
                f"expected {expected.hex().upper()}, observed {observed.hex().upper()}"
            )
        command_ids.update(commands)
        producer_rows.append({
            "address": f"80:{address:04X}",
            "bytes": expected.hex().upper(),
            "command_ids": [f"{command:02X}" for command in commands],
            "proof": reason,
        })

    queue_address = 0xF9C2
    queue_bytes = bytes.fromhex(
        "08C230DA5A48E230AD5E1AAA1A293FCD5C1AF015"
        "689DA21A689D621AE88A293F8D5E1AC2307AFA2860"
    )
    if lorom_bytes(rom, 0x80, queue_address, len(queue_bytes)) != queue_bytes:
        raise ValueError("65C816 audio queue byte-store contract changed")
    transmit_address = 0xFA0F
    transmit_bytes = bytes.fromhex(
        "BD621A48EB49C08D601A1DA21A488A1A293F8D5C1AC220688D4221"
    )
    if lorom_bytes(rom, 0x80, transmit_address, len(transmit_bytes)) != transmit_bytes:
        raise ValueError("65C816 APUIO2 transmit contract changed")

    return {
        "authority": SCPU_RESET_REPORT.name,
        "authority_policy": "source rediscovery and exact pinned ROM bytes; trace/oracle values excluded",
        "reachable_queue_call_contexts": sorted(incoming),
        "producer_paths": producer_rows,
        "queue_contract": {
            "address": "80:F9C2",
            "bytes": queue_bytes.hex().upper(),
            "proof": "16-bit PHA followed by 8-bit PLA stores the caller low byte at $1AA2,X",
        },
        "transmit_contract": {
            "address": "80:FA0F",
            "bytes": transmit_bytes.hex().upper(),
            "proof": "$1AA2,X is ORed into the handshake byte and the 16-bit word is written to $2142/$2143",
        },
        "port2_command_mask": "3F",
        "command_ids": [f"{command:02X}" for command in sorted(command_ids)],
    }


def host_command_return_table(
    rom: bytes, aram: bytes, known: bytes, ret_pc: int
) -> dict | None:
    """Prove the S-SMP port-command PUSH/PUSH/RET dispatcher at $0583."""
    start = (ret_pc - 35) & 0xFFFF
    addresses = [(start + index) & 0xFFFF for index in range(36)]
    if not all(known[address] for address in addresses):
        return None
    raw = bytes(aram[address] for address in addresses)
    expected = bytes.fromhex(
        "E4F6FD28C064D1D01948C0C4D1DD283F5D"
        "F524062DF517062DE4F72DDD28C0C4F6AE606F"
    )
    if raw != expected:
        return None

    host = host_audio_command_proof(rom)
    commands = [int(value, 16) for value in host["command_ids"]]
    first_push_base = 0x0624
    second_push_base = 0x0617
    targets: dict[int, list[int]] = {}
    table_bytes: set[int] = set()
    for command in commands:
        first_address = first_push_base + command
        second_address = second_push_base + command
        if not known[first_address] or not known[second_address]:
            raise ValueError(f"unknown host-command table byte for command ${command:02X}")
        target = aram[second_address] | (aram[first_address] << 8)
        targets.setdefault(target, []).append(command)
        table_bytes.update((first_address, second_address))
    return {
        "pc": f"{ret_pc:04X}",
        "idiom_start": f"{start:04X}",
        "producer_bytes": raw.hex().upper(),
        "cross_cpu_command_proof": host,
        "index_proof": "MOV A,$F6; MOV Y,A; later MOV A,Y; AND A,#$3F; MOV X,A",
        "index_domain": [f"{command:02X}" for command in commands],
        "first_push_table_base_target_high": f"{first_push_base:04X}",
        "second_push_table_base_target_low": f"{second_push_base:04X}",
        "table_byte_addresses": [f"{address:04X}" for address in sorted(table_bytes)],
        "targets": [
            {"pc": f"{target:04X}", "indices": [f"{value:02X}" for value in values]}
            for target, values in sorted(targets.items())
        ],
    }


def envelope_stage_return_table(aram: bytes, known: bytes, ret_pc: int) -> dict | None:
    """Prove the five-state per-voice envelope PUSH/PUSH/RET dispatcher.

    $A1+X is initialized/reset to zero, explicitly started at three, and only
    advanced by the stage handlers.  Stages 0, 1, and 3 advance once to 1, 2,
    and 4 respectively; stage 2 and stage 4 return without advancing.  Thus the
    complete source-derived domain is 0..4 and the five bytes at each table
    base are the whole valid table, not a runtime-observed subset.
    """
    start = (ret_pc - 26) & 0xFFFF
    addresses = [(start + index) & 0xFFFF for index in range(27)]
    if not all(known[address] for address in addresses):
        return None
    raw = bytes(aram[address] for address in addresses)
    expected = bytes.fromhex(
        "FBA1F6AE0B2DF6A90B2D7DC4E51C1C1C80A4E55CFDF60403D4A06F"
    )
    if raw != expected:
        return None

    source_contracts = (
        (0x0811, "E800D50001D400D401D410D411D420D421D451D460D470D471D481D490D491D4A0D4A1",
         "voice initialization writes stage 0"),
        (0x0B7E, "E803D4A1", "envelope start writes stage 3"),
        (0x0BD3, "F6060374B0D006BBA1E800D4B0", "stage 0 terminal condition advances to stage 1"),
        (0x0C0F, "F60903D421BBA1E800D4B0", "stage 1 terminal path advances to stage 2"),
        (0x0C42, "E800D421BBA1", "stage 3 terminal path advances to stage 4"),
        (0x0D08, "E800D4A1D4B0BCD4A0", "voice stop resets stage to 0"),
    )
    contracts = []
    for address, expected_hex, proof in source_contracts:
        expected_bytes = bytes.fromhex(expected_hex)
        contract_addresses = [(address + index) & 0xFFFF for index in range(len(expected_bytes))]
        if not all(known[item] for item in contract_addresses):
            raise ValueError(f"unknown envelope-state source contract at ${address:04X}")
        observed = bytes(aram[item] for item in contract_addresses)
        if observed != expected_bytes:
            raise ValueError(f"envelope-state source contract changed at ${address:04X}")
        contracts.append({
            "address": f"{address:04X}",
            "bytes": expected_hex,
            "proof": proof,
        })

    first_push_base = 0x0BAE
    second_push_base = 0x0BA9
    stage_domain = range(5)
    targets: dict[int, list[int]] = {}
    table_bytes: set[int] = set()
    for stage in stage_domain:
        first_address = first_push_base + stage
        second_address = second_push_base + stage
        if not known[first_address] or not known[second_address]:
            raise ValueError(f"unknown envelope table byte for stage {stage}")
        target = aram[second_address] | (aram[first_address] << 8)
        targets.setdefault(target, []).append(stage)
        table_bytes.update((first_address, second_address))
    return {
        "pc": f"{ret_pc:04X}",
        "idiom_start": f"{start:04X}",
        "producer_bytes": raw.hex().upper(),
        "state_variable": "$A1+X",
        "state_domain_proof": contracts,
        "index_proof": "MOV Y,$A1+X indexes the complete five-state envelope table",
        "index_domain": [f"{stage:02X}" for stage in stage_domain],
        "first_push_table_base_target_high": f"{first_push_base:04X}",
        "second_push_table_base_target_low": f"{second_push_base:04X}",
        "table_byte_addresses": [f"{address:04X}" for address in sorted(table_bytes)],
        "targets": [
            {"pc": f"{target:04X}", "indices": [f"{value:02X}" for value in values]}
            for target, values in sorted(targets.items())
        ],
    }


def analyse(rom: bytes, aram: bytes, known: bytes) -> dict:
    queue = deque([(State(0x0400), "source-proved final IPL entry")])
    seen: set[State] = set()
    instructions: dict[int, dict] = {}
    edges: set[tuple[int, int, str, int]] = set()
    frontiers: dict[int, dict] = {}
    terminals: set[tuple[int, str]] = set()
    dynamic_return_proofs: dict[int, dict] = {}
    maximum_depth = 0

    def push(source: State, pc: int, returns: tuple[int, ...], kind: str) -> None:
        edges.add((source.pc, pc & 0xFFFF, kind, len(source.returns)))
        queue.append((State(pc & 0xFFFF, returns), kind))

    while queue:
        state, origin = queue.popleft()
        if state in seen:
            continue
        seen.add(state)
        maximum_depth = max(maximum_depth, len(state.returns))
        if len(state.returns) > MAX_RETURN_DEPTH:
            raise ValueError(f"SMP return depth exceeded at ${state.pc:04X}")
        if state.pc == 0xFFC0:
            terminals.add((state.pc, "fixed IPL reset epoch transition"))
            continue
        if not known[state.pc]:
            raise ValueError(f"execution reached unknown ARAM at ${state.pc:04X}")
        instruction = decode(aram, state.pc)
        for index in range(instruction.length):
            address = (state.pc + index) & 0xFFFF
            if not known[address]:
                raise ValueError(f"instruction ${state.pc:04X} crosses unknown ARAM ${address:04X}")
        prior = instructions.setdefault(state.pc, {
            "pc": f"{state.pc:04X}",
            "opcode": f"{instruction.opcode:02X}",
            "bytes": instruction.raw.hex().upper(),
            "name": instruction.name,
            "length": instruction.length,
            "base_cycles": OP_CYCLES[instruction.opcode],
            "origins": set(),
            "return_depths": set(),
            "epoch": "UPLOADED_DRIVER",
        })
        if prior["opcode"] != f"{instruction.opcode:02X}":
            raise ValueError(f"self-modifying initial epoch conflict at ${state.pc:04X}")
        prior["origins"].add(origin)
        prior["return_depths"].add(len(state.returns))
        opcode = instruction.opcode
        next_pc = instruction.next_pc

        if opcode in CONDITIONAL_BRANCHES:
            assert instruction.branch_target is not None
            push(state, next_pc, state.returns, "conditional fallthrough")
            push(state, instruction.branch_target, state.returns, "conditional branch")
        elif opcode == 0x2F:  # BRA rel
            assert instruction.branch_target is not None
            push(state, instruction.branch_target, state.returns, "unconditional branch")
        elif opcode == 0x5F:  # JMP abs
            assert instruction.absolute is not None
            push(state, instruction.absolute, state.returns, "direct jump")
        elif opcode == 0x1F:  # JMP [abs+X]
            frontiers.setdefault(state.pc, {
                "pc": f"{state.pc:04X}",
                "opcode": "1F",
                "bytes": instruction.raw.hex().upper(),
                "base": f"{instruction.absolute:04X}",
                "type": "INDIRECT_JUMP_TABLE_PROOF_REQUIRED",
                "return_depths": set(),
            })["return_depths"].add(len(state.returns))
        elif opcode == 0x3F:  # CALL abs
            assert instruction.absolute is not None
            push(state, instruction.absolute, state.returns + (next_pc,), "direct call")
        elif opcode == 0x4F:  # PCALL upage
            target = 0xFF00 | instruction.raw[1]
            push(state, target, state.returns + (next_pc,), "page call")
        elif (opcode & 0x0F) == 0x01:  # TCALL n
            vector = 0xFFDE - ((opcode >> 4) * 2)
            target = read16(aram, known, vector)
            push(state, target, state.returns + (next_pc,), f"table call vector ${vector:04X}")
        elif opcode == 0x0F:  # BRK vector
            target = read16(aram, known, 0xFFDE)
            push(state, target, state.returns + (next_pc,), "BRK vector")
        elif opcode in RETURN_OPCODES:
            table = None
            if opcode == 0x6F:
                table = pushed_return_table(aram, known, state.pc)
                if table is None:
                    table = host_command_return_table(rom, aram, known, state.pc)
                if table is None:
                    table = envelope_stage_return_table(aram, known, state.pc)
            if table:
                dynamic_return_proofs[state.pc] = table
                for target in table["targets"]:
                    push(state, int(target["pc"], 16), state.returns,
                         "source-proved pushed-RET table dispatch")
            elif state.returns:
                push(state, state.returns[-1], state.returns[:-1], "return")
            else:
                terminals.add((state.pc, "return with empty static call stack"))
        elif opcode in HALT_OPCODES:
            terminals.add((state.pc, "sleep/stop"))
        else:
            push(state, next_pc, state.returns, "fallthrough")

    normalized = []
    for pc in sorted(instructions):
        row = instructions[pc]
        row["origins"] = sorted(row["origins"])
        row["return_depths"] = sorted(row["return_depths"])
        normalized.append(row)
    # The fixed 64-byte IPL is immutable hardware ROM, but it executes on every
    # upload epoch before the uploaded driver.  Its reachable instruction starts
    # are derived directly from the pinned IPL bytes.  $FFFB has exactly the
    # four source-proved uploader command entries: three restart at $FFC0 and
    # the final record enters uploaded code at $0400.
    ipl_memory = bytearray(0x10000)
    ipl_memory[0xFFC0:0x10000] = IPL_BYTES
    ipl_pcs = []
    pc = 0xFFC0
    while pc <= 0xFFFB:
        instruction = decode(ipl_memory, pc)
        ipl_pcs.append(pc)
        normalized.append({
            "pc": f"{pc:04X}",
            "opcode": f"{instruction.opcode:02X}",
            "bytes": instruction.raw.hex().upper(),
            "name": instruction.name,
            "length": instruction.length,
            "base_cycles": OP_CYCLES[instruction.opcode],
            "origins": ["immutable fixed IPL ROM"],
            "return_depths": [0],
            "epoch": "FIXED_IPL_ROM",
        })
        pc += instruction.length
    normalized.sort(key=lambda row: (int(row["pc"], 16), row["epoch"]))
    frontier_rows = []
    for pc in sorted(frontiers):
        row = frontiers[pc]
        row["return_depths"] = sorted(row["return_depths"])
        frontier_rows.append(row)
    return {
        "schema": "RRR_V10_2_SMP_DIRECT_REDISCOVERY_V4",
        "authority_policy": "ROM-uploaded ARAM and documented SPC700 semantics only; oracle/traces promote zero contexts",
        "initial_entry": "0400",
        "initial_register_contract": {
            "A": "00", "X": "00", "Y": "00", "SP": "EF",
            "proof": "fixed IPL terminal path MOVW YA,$F4; MOV $F4,A; MOV A,Y; MOV X,A; BNE not taken; JMP [$0000+X], with uploader port1 command zero",
        },
        "summary": {
            "abstract_states": len(seen),
            "unique_instruction_pcs": len(normalized),
            "uploaded_driver_instruction_pcs": len(instructions),
            "fixed_ipl_instruction_pcs": len(ipl_pcs),
            "edge_count": len(edges),
            "frontier_count": len(frontier_rows),
            "frontier_types": dict(Counter(row["type"] for row in frontier_rows)),
            "terminal_count": len(terminals),
            "maximum_return_depth": maximum_depth,
            "source_proved_dynamic_return_sites": len(dynamic_return_proofs),
            "source_proved_dynamic_return_targets": sum(
                len(proof["targets"]) for proof in dynamic_return_proofs.values()),
            "oracle_promotions": 0,
            "trace_promotions": 0,
        },
        "instructions": normalized,
        "fixed_ipl_edges": {
            "indirect_site": "FFFB",
            "source_proved_targets": ["0400", "FFC0"],
            "upload_command_entries": ["FFC0", "FFC0", "FFC0", "0400"],
        },
        "edges": [
            {"from": f"{source:04X}", "to": f"{target:04X}", "kind": kind, "source_return_depth": depth}
            for source, target, kind, depth in sorted(edges)
        ],
        "frontiers": frontier_rows,
        "dynamic_return_table_proofs": [
            dynamic_return_proofs[pc] for pc in sorted(dynamic_return_proofs)
        ],
        "terminals": [
            {"pc": f"{pc:04X}", "kind": kind} for pc, kind in sorted(terminals)
        ],
    }


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--rom", type=Path, required=True)
    args = parser.parse_args()
    rom = require_rom(args.rom)
    aram, known, _ = reconstruct_aram(rom, parse_upload_records(rom, 4))
    ARAM_OUT.parent.mkdir(parents=True, exist_ok=True)
    ARAM_OUT.write_bytes(aram)
    KNOWN_OUT.write_bytes(known)
    report = analyse(rom, aram, known)
    report["initial_aram_sha256"] = hashlib.sha256(aram).hexdigest()
    report["initial_aram_known_sha256"] = hashlib.sha256(known).hexdigest()
    OUT.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(report["summary"], indent=2))
    if report["frontiers"]:
        print(json.dumps(report["frontiers"], indent=2))


if __name__ == "__main__":
    main()
