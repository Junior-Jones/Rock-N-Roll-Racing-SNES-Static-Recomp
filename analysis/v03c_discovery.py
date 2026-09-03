"""V03C whole-ROM discovery/classification for Rock n' Roll Racing.

This module is an OFFLINE analyser.  It never becomes production execution code.
It deliberately separates:
  * all-offset decode census (candidate discovery only),
  * SOURCE_PROVED contexts reached from exact vector roots by direct/static flow,
  * CANDIDATE contexts created at return/width/re-entry frontiers.

No oracle trace can promote a context.  Dynamic/return closure belongs to V04C.
"""
from __future__ import annotations

from collections import defaultdict, deque
from dataclasses import dataclass, replace
import csv
import hashlib
import io
import json
from pathlib import Path
import struct
from typing import Iterable

from analysis.v01c_cartridge_profile import canonical_lorom_offset
from analysis.w65c816.opcodes import OPCODES, OpcodeSpec, instruction_length

ROM_SHA256 = "9d721753301278325c851f1843d669a697aed757dcf6495a31fc31ddf664b182"
ROM_SIZE = 0x100000
HEADER_START = 0x7FC0
HEADER_END = 0x7FFF
LEGAL_CONTEXTS = ((0,0,0),(0,0,1),(0,1,0),(0,1,1),(1,1,1))
CONDITIONAL_BRANCHES = {"BPL","BMI","BVC","BVS","BCC","BCS","BNE","BEQ"}
CARRY_UNKNOWN_MNEMONICS = {"ADC","SBC","CMP","CPX","CPY","ASL","LSR","ROL","ROR"}
PUSH_MNEMONICS = {"PHA","PHX","PHY","PHP","PHD","PEA","PEI","PER"}
PULL_MNEMONICS = {"PLA","PLX","PLY","PLP","PLD"}
READ_MNEMONICS = {"LDA","LDX","LDY","CMP","CPX","CPY","BIT","ADC","SBC","AND","ORA","EOR"}
WRITE_MNEMONICS = {"STA","STX","STY","STZ"}
RMW_MNEMONICS = {"ASL","LSR","ROL","ROR","INC","DEC","TRB","TSB"}
APUIO_REGS = set(range(0x2140,0x2144))

@dataclass(frozen=True, order=True)
class State:
    pbr: int
    pc: int
    e: int
    m: int
    x: int
    carry: int = -1       # -1 unknown, 0 clear, 1 set
    dbr: int = -1         # -1 unknown, else 0..255
    stack_top: int = -1   # tiny symbolic byte model, -1 unknown
    level: str = "PROVED" # PROVED or CANDIDATE

    def context_key(self) -> tuple[int,int,int,int,int]:
        return (self.pbr,self.pc,self.e,self.m,self.x)

    def short(self) -> str:
        c = "?" if self.carry < 0 else str(self.carry)
        d = "??" if self.dbr < 0 else f"{self.dbr:02X}"
        return f"{self.pbr:02X}:{self.pc:04X}:E{self.e}M{self.m}X{self.x}:C{c}:DBR{d}:{self.level[0]}"

@dataclass(frozen=True)
class Decoded:
    state: State
    physical: int
    spec: OpcodeSpec
    raw: bytes
    length: int

@dataclass
class DiscoveryResult:
    summary: dict
    roots: list[dict]
    contexts: list[dict]
    edges: list[dict]
    frontiers: list[dict]
    conflicts: list[dict]
    apuio: list[dict]
    ownership: list[dict]
    frontier_ledger: list[dict]


def sha256_bytes(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def phys_to_cpu(off: int) -> tuple[int,int]:
    if not 0 <= off < ROM_SIZE:
        raise ValueError(off)
    bank = off // 0x8000
    pc = 0x8000 + (off % 0x8000)
    return bank, pc


def map_cpu(pbr: int, pc: int, rom_size: int) -> int:
    return canonical_lorom_offset(((pbr & 0xFF) << 16) | (pc & 0xFFFF), rom_size)


def read_instruction(rom: bytes, state: State) -> Decoded:
    physical = map_cpu(state.pbr, state.pc, len(rom))
    opcode = rom[physical]
    spec = OPCODES[opcode]
    length = instruction_length(spec, state.m, state.x)
    raw = bytearray()
    for i in range(length):
        pc = (state.pc + i) & 0xFFFF
        off = map_cpu(state.pbr, pc, len(rom))
        raw.append(rom[off])
    return Decoded(state, physical, spec, bytes(raw), length)


def u16(raw: bytes, pos: int = 1) -> int:
    return raw[pos] | (raw[pos+1] << 8)


def u24(raw: bytes, pos: int = 1) -> int:
    return raw[pos] | (raw[pos+1] << 8) | (raw[pos+2] << 16)


def s8(v: int) -> int:
    return v - 0x100 if v & 0x80 else v


def s16(v: int) -> int:
    return v - 0x10000 if v & 0x8000 else v


def next_pc(d: Decoded) -> int:
    return (d.state.pc + d.length) & 0xFFFF


def with_flow_state(s: State, *, pc: int | None = None, pbr: int | None = None,
                    level: str | None = None, carry: int | None = None,
                    dbr: int | None = None, stack_top: int | None = None,
                    e: int | None = None, m: int | None = None, x: int | None = None) -> State:
    return State(
        s.pbr if pbr is None else pbr,
        s.pc if pc is None else pc,
        s.e if e is None else e,
        s.m if m is None else m,
        s.x if x is None else x,
        s.carry if carry is None else carry,
        s.dbr if dbr is None else dbr,
        s.stack_top if stack_top is None else stack_top,
        s.level if level is None else level,
    )


def vector_roots(profile: dict) -> list[tuple[State,str]]:
    v = profile["vectors"]
    roots: list[tuple[State,str]] = []
    # Emulation RESET is the sole cold-reset root and has architectural DBR=0.
    roots.append((State(0,int(v["emulation_reset"],16),1,1,1,-1,0,-1,"PROVED"),"emulation_reset"))
    for name in ("emulation_abort","emulation_cop","emulation_nmi","emulation_irq_brk"):
        pc=int(v[name],16)
        if pc >= 0x8000:
            roots.append((State(0,pc,1,1,1,-1,-1,-1,"PROVED"),name))
    for name in ("native_abort","native_brk","native_cop","native_nmi","native_irq"):
        pc=int(v[name],16)
        if pc < 0x8000:
            continue
        for e,m,x in LEGAL_CONTEXTS:
            if e == 0:
                roots.append((State(0,pc,e,m,x,-1,-1,-1,"PROVED"),name))
    return roots


def all_offset_scan(rom: bytes) -> dict:
    """Decode every physical offset under every legal E/M/X context.

    `fetch_valid` means all bytes of the instruction remain in the same LoROM ROM
    half-bank.  Crossing PC $FFFF into $0000 is not silently linearized.
    """
    h = hashlib.sha256()
    length_hist = defaultdict(int)
    opcode_hist = [0] * 256
    invalid_fetch_rows = 0
    rows = 0
    for off, opcode in enumerate(rom):
        opcode_hist[opcode] += 1
        within = off & 0x7FFF
        spec = OPCODES[opcode]
        for idx,(e,m,x) in enumerate(LEGAL_CONTEXTS):
            n = instruction_length(spec,m,x)
            valid = 1 if within + n <= 0x8000 else 0
            invalid_fetch_rows += 1 - valid
            length_hist[str(n)] += 1
            rows += 1
            h.update(struct.pack("<IBBBB",off,idx,opcode,n,valid))
    return {
        "physical_offsets": len(rom),
        "legal_contexts_per_offset": len(LEGAL_CONTEXTS),
        "rows": rows,
        "invalid_fetch_rows_at_lorom_bank_boundary": invalid_fetch_rows,
        "instruction_length_histogram": dict(sorted(length_hist.items())),
        "row_digest_serialization": "little-endian <IBBBB = physical_offset,legal_context_index,opcode,length,fetch_valid; context order 000,001,010,011,111 as E/M/X",
        "row_digest_sha256": h.hexdigest(),
        "opcode_byte_histogram_sha256": hashlib.sha256(json.dumps(opcode_hist,separators=(",",":")).encode()).hexdigest(),
    }


def transfer_linear(d: Decoded) -> State:
    s=d.state
    carry=s.carry; m=s.m; x=s.x; e=s.e; dbr=s.dbr; top=s.stack_top
    mn=d.spec.mnemonic
    if mn == "CLC": carry=0
    elif mn == "SEC": carry=1
    elif mn == "PLP": carry=-1
    elif mn in CARRY_UNKNOWN_MNEMONICS: carry=-1
    if mn in {"REP","SEP"}:
        imm=d.raw[1]
        if mn == "REP":
            if imm & 0x01: carry=0
            if e == 0:
                if imm & 0x20: m=0
                if imm & 0x10: x=0
        else:
            if imm & 0x01: carry=1
            if imm & 0x20: m=1
            if imm & 0x10: x=1
        if e == 1: m=x=1
    if mn == "PHK": top=s.pbr
    elif mn == "PHB": top=dbr
    elif mn in PUSH_MNEMONICS: top=-1
    elif mn == "PLB":
        dbr=top
        top=-1
    elif mn in PULL_MNEMONICS:
        top=-1
    if mn in {"MVN","MVP"}:
        # Block move changes DBR to the destination bank; byte order is source
        # encoded but this is not needed for V03C APUIO proof, so remain safe.
        dbr=-1
    return State(s.pbr,next_pc(d),e,m,x,carry,dbr,top,s.level)


def apuio_access_kind(mn: str) -> str:
    if mn in WRITE_MNEMONICS: return "WRITE"
    if mn in READ_MNEMONICS: return "READ"
    if mn in RMW_MNEMONICS: return "READ_MODIFY_WRITE"
    return "OTHER"


def mmio_bank(bank: int) -> bool:
    return bank >= 0 and ((0x00 <= bank <= 0x3F) or (0x80 <= bank <= 0xBF))


def graph_discover(rom: bytes, profile: dict) -> tuple[list[dict],list[dict],list[dict],list[dict],dict,dict,dict]:
    q: deque[State] = deque()
    seen: set[State] = set()
    root_records: dict[tuple,dict] = {}
    contexts: list[dict] = []
    edges: list[dict] = []
    frontiers: list[dict] = []
    roles: dict[int,list[tuple[int,str,str,int]]] = defaultdict(list) # byte -> start,level,role,len
    graph_at_physical: dict[int,list[dict]] = defaultdict(list)
    candidate_root_counter=0

    def root_record(st: State, root_type: str, origin: str, reason: str) -> None:
        nonlocal candidate_root_counter
        key=(root_type,st.pbr,st.pc,st.e,st.m,st.x,st.level,reason)
        r=root_records.get(key)
        if r is None:
            candidate_root_counter += 1
            r={"Root_ID":f"V03R{candidate_root_counter:05d}","Root_Type":root_type,"Level":st.level,
               "PBR":f"{st.pbr:02X}","PC":f"{st.pc:04X}","E":st.e,"M":st.m,"X":st.x,
               "Reason":reason,"Origins":origin}
            root_records[key]=r
        elif origin not in r["Origins"].split(";"):
            r["Origins"] += ";"+origin

    def enqueue(st: State, from_id: str, kind: str, reason: str, *, root_type: str | None = None) -> None:
        edges.append({"From":from_id,"Edge_Kind":kind,"To":st.short(),"To_Level":st.level,"Reason":reason})
        if root_type:
            root_record(st,root_type,from_id,reason)
        if st not in seen:
            q.append(st)

    for st,origin in vector_roots(profile):
        root_record(st,"VECTOR_SOURCE_PROVED",origin,"exact internal vector bytes")
        if st not in seen: q.append(st)

    frontier_counter=0
    context_counter=0
    hard_limit=500000
    while q:
        st=q.popleft()
        if st in seen: continue
        seen.add(st)
        if len(seen) > hard_limit:
            raise RuntimeError(f"V03C graph context hard limit exceeded: {hard_limit}")
        context_counter += 1
        cid=f"V03C{context_counter:06d}"
        try:
            d=read_instruction(rom,st)
        except ValueError as ex:
            frontier_counter += 1
            frontiers.append({"Frontier_ID":f"V03F{frontier_counter:05d}","Level":st.level,"Context":st.short(),
                              "Class":"CODE_MAPPING","Instruction":"","Reason":str(ex),"Candidate_Target":""})
            continue
        spec=d.spec; mn=spec.mnemonic
        ctx={"Context_ID":cid,"Level":st.level,"PBR":f"{st.pbr:02X}","PC":f"{st.pc:04X}","E":st.e,"M":st.m,"X":st.x,
             "Carry":"?" if st.carry<0 else st.carry,"DBR":"??" if st.dbr<0 else f"{st.dbr:02X}",
             "Physical":f"{d.physical:06X}","Opcode":f"{spec.opcode:02X}","Mnemonic":mn,"Mode":spec.mode,
             "Length":d.length,"Bytes":d.raw.hex().upper()}
        contexts.append(ctx); graph_at_physical[d.physical].append(ctx)
        for i in range(d.length):
            try: off=map_cpu(st.pbr,(st.pc+i)&0xFFFF,len(rom))
            except ValueError: continue
            roles[off].append((d.physical,st.level,"OPCODE" if i==0 else "OPERAND",d.length))

        # Direct source/candidate graph APUIO evidence is annotated later by the
        # all-offset operand inventory using graph_at_physical.
        base=transfer_linear(d)
        from_id=cid

        # Width/status frontiers first.
        if mn == "XCE":
            if st.carry in (0,1):
                ne=st.carry; nc=st.e
                nm,nx=(1,1) if ne else (st.m,st.x)
                ns=State(st.pbr,next_pc(d),ne,nm,nx,nc,st.dbr,st.stack_top,st.level)
                enqueue(ns,from_id,"FALLTHROUGH","XCE with source-known carry")
            else:
                frontier_counter += 1
                frontiers.append({"Frontier_ID":f"V03F{frontier_counter:05d}","Level":st.level,"Context":st.short(),
                                  "Class":"STATUS_WIDTH","Instruction":f"{mn} ${d.physical:06X}",
                                  "Reason":"XCE carry provenance unknown; both architectural E outcomes remain candidates","Candidate_Target":f"{st.pbr:02X}:{next_pc(d):04X}"})
                for ne in (0,1):
                    nm,nx=(1,1) if ne else (st.m,st.x)
                    ns=State(st.pbr,next_pc(d),ne,nm,nx,st.e,st.dbr,st.stack_top,"CANDIDATE")
                    enqueue(ns,from_id,"WIDTH_CANDIDATE","XCE unknown carry",root_type="WIDTH_CANDIDATE")
            continue
        if mn == "PLP" and st.e == 0:
            frontier_counter += 1
            frontiers.append({"Frontier_ID":f"V03F{frontier_counter:05d}","Level":st.level,"Context":st.short(),
                              "Class":"STATUS_WIDTH","Instruction":f"PLP ${d.physical:06X}",
                              "Reason":"native PLP restores M/X from stack; V03C does not prove stack status producers","Candidate_Target":f"{st.pbr:02X}:{next_pc(d):04X}"})
            for _,m,x in LEGAL_CONTEXTS:
                if _ != 0: continue
                ns=State(st.pbr,next_pc(d),0,m,x,-1,st.dbr,-1,"CANDIDATE")
                enqueue(ns,from_id,"WIDTH_CANDIDATE","native PLP status unknown",root_type="WIDTH_CANDIDATE")
            continue

        # Return/re-entry and stop frontiers.
        if mn in {"RTS","RTL","RTI"}:
            frontier_counter += 1
            frontiers.append({"Frontier_ID":f"V03F{frontier_counter:05d}","Level":st.level,"Context":st.short(),
                              "Class":"RETURN" if mn!="RTI" else "INTERRUPT_REENTRY","Instruction":f"{mn} ${d.physical:06X}",
                              "Reason":"return target/status provenance deferred to V04C","Candidate_Target":""})
            continue
        if mn == "STP":
            frontier_counter += 1
            frontiers.append({"Frontier_ID":f"V03F{frontier_counter:05d}","Level":st.level,"Context":st.short(),
                              "Class":"STOP","Instruction":f"STP ${d.physical:06X}","Reason":"CPU stopped until reset","Candidate_Target":""})
            continue
        if mn == "WAI":
            frontier_counter += 1
            frontiers.append({"Frontier_ID":f"V03F{frontier_counter:05d}","Level":st.level,"Context":st.short(),
                              "Class":"INTERRUPT_REENTRY","Instruction":f"WAI ${d.physical:06X}","Reason":"resume depends on interrupt/event re-entry closed in V04C","Candidate_Target":f"{st.pbr:02X}:{next_pc(d):04X}"})
            ns=replace(base,level="CANDIDATE",carry=-1,stack_top=-1)
            enqueue(ns,from_id,"REENTRY_CANDIDATE","WAI fallthrough after unclosed event",root_type="REENTRY_CANDIDATE")
            continue

        # Software interrupt vector entries are exact from the selected header.
        if mn in {"BRK","COP"}:
            if st.e:
                vn="emulation_irq_brk" if mn=="BRK" else "emulation_cop"
            else:
                vn="native_brk" if mn=="BRK" else "native_cop"
            target=int(profile["vectors"][vn],16)
            ns=State(0,target,st.e,st.m,st.x,base.carry,st.dbr,-1,st.level)
            enqueue(ns,from_id,"SOFTWARE_INTERRUPT",f"exact {vn} vector")
            continue

        # Direct branches.
        if mn in CONDITIONAL_BRANCHES:
            target=(next_pc(d)+s8(d.raw[1])) & 0xFFFF
            enqueue(replace(base,pc=target),from_id,"BRANCH_TAKEN","encoded signed 8-bit branch")
            enqueue(base,from_id,"BRANCH_NOT_TAKEN","conditional fallthrough")
            continue
        if mn == "BRA":
            target=(next_pc(d)+s8(d.raw[1])) & 0xFFFF
            enqueue(replace(base,pc=target),from_id,"BRANCH","encoded signed 8-bit branch")
            continue
        if mn == "BRL":
            target=(next_pc(d)+s16(u16(d.raw))) & 0xFFFF
            enqueue(replace(base,pc=target),from_id,"BRANCH_LONG","encoded signed 16-bit branch")
            continue

        # Direct and indirect jumps/calls.
        if mn in {"JMP","JML"}:
            if spec.mode == "ABS_JUMP":
                enqueue(replace(base,pc=u16(d.raw)),from_id,"DIRECT_JUMP","encoded absolute target")
            elif spec.mode == "ABSL_JUMP":
                t=u24(d.raw); enqueue(replace(base,pbr=(t>>16)&0xFF,pc=t&0xFFFF),from_id,"DIRECT_LONG_JUMP","encoded 24-bit target")
            else:
                frontier_counter += 1
                frontiers.append({"Frontier_ID":f"V03F{frontier_counter:05d}","Level":st.level,"Context":st.short(),
                                  "Class":"DYNAMIC_TARGET","Instruction":f"{mn}/{spec.mode} ${d.physical:06X}",
                                  "Reason":"indirect jump target set requires producer/consumer proof in V04C","Candidate_Target":""})
            continue
        if mn in {"JSR","JSL"}:
            if mn == "JSR" and spec.mode == "ABS_JUMP":
                target_state=replace(base,pc=u16(d.raw),stack_top=-1)
                enqueue(target_state,from_id,"DIRECT_CALL","encoded absolute call target")
            elif mn == "JSL" and spec.mode == "ABSL_JUMP":
                t=u24(d.raw)
                target_state=replace(base,pbr=(t>>16)&0xFF,pc=t&0xFFFF,stack_top=-1)
                enqueue(target_state,from_id,"DIRECT_LONG_CALL","encoded 24-bit call target")
            else:
                frontier_counter += 1
                frontiers.append({"Frontier_ID":f"V03F{frontier_counter:05d}","Level":st.level,"Context":st.short(),
                                  "Class":"DYNAMIC_TARGET","Instruction":f"{mn}/{spec.mode} ${d.physical:06X}",
                                  "Reason":"indexed/indirect call target set deferred to V04C","Candidate_Target":""})
            # The encoded return address is known, but actual return/status/DBR
            # provenance is not closed until V04C.  Continue it only as candidate.
            ret=State(st.pbr,next_pc(d),st.e,st.m,st.x,-1,-1,-1,"CANDIDATE")
            enqueue(ret,from_id,"RETURN_CONTINUATION_CANDIDATE","call fallthrough requires return proof",root_type="RETURN_CONTINUATION_CANDIDATE")
            continue

        enqueue(base,from_id,"FALLTHROUGH","instruction has direct sequential successor")

    return list(root_records.values()),contexts,edges,frontiers,roles,graph_at_physical,{"seen_states":seen}


def raw_apuio_candidates(rom: bytes, graph_at_physical: dict[int,list[dict]]) -> list[dict]:
    out=[]; rid=0
    for off,opcode in enumerate(rom):
        spec=OPCODES[opcode]
        # Operand positions are identical for these fixed-width forms; require bytes
        # to remain in the same ROM half-bank.
        within=off & 0x7FFF
        target=None; address_form=""; bank=""
        if spec.mode in {"ABS","ABS_X","ABS_Y"} and within+3 <= 0x8000:
            target=rom[off+1] | (rom[off+2]<<8); address_form="DBR:ABS16"
        elif spec.mode in {"ABS_LONG","ABS_LONG_X"} and within+4 <= 0x8000:
            t=rom[off+1] | (rom[off+2]<<8) | (rom[off+3]<<16)
            target=t & 0xFFFF; bank=f"{(t>>16)&0xFF:02X}"; address_form="LONG24"
            if not mmio_bank((t>>16)&0xFF): target=None
        if target not in APUIO_REGS:
            continue
        rid+=1
        pbr,pc=phys_to_cpu(off)
        graph=graph_at_physical.get(off,[])
        levels=sorted({r["Level"] for r in graph})
        known_banks=sorted({r["DBR"] for r in graph if r["DBR"]!="??"})
        exact_mmio=[]
        for r in graph:
            if r["DBR"]!="??" and mmio_bank(int(r["DBR"],16)):
                exact_mmio.append(r["Level"])
        if "PROVED" in exact_mmio: claim="SOURCE_PROVED_MMIO_ADDRESS"
        elif exact_mmio: claim="CANDIDATE_MMIO_ADDRESS"
        elif graph: claim="GRAPH_REACHED_BANK_UNPROVED"
        else: claim="ALL_OFFSET_ONLY"
        out.append({
            "Candidate_ID":f"V03A{rid:04d}","Physical":f"{off:06X}","Canonical_CPU":f"{pbr:02X}:{pc:04X}",
            "Opcode":f"{opcode:02X}","Mnemonic":spec.mnemonic,"Mode":spec.mode,"Access":apuio_access_kind(spec.mnemonic),
            "Register":f"{target:04X}","Address_Form":address_form,"Encoded_Bank":bank,
            "Graph_Levels":";".join(levels),"Known_DBRs":";".join(known_banks),"Claim":claim,
            "Notes":"All-offset source candidate; graph/DBR columns control whether the MMIO bank is actually proved."
        })
    return out


def build_ownership(roles: dict[int,list[tuple[int,str,str,int]]]) -> tuple[list[dict],list[dict],dict]:
    classes=["UNRESOLVED"]*ROM_SIZE
    conflict_ids: dict[int,set[str]]=defaultdict(set)
    conflicts=[]; conflict_counter=0
    for off in range(HEADER_START,HEADER_END+1): classes[off]="HEADER_VECTOR"
    # Group code roles and expose overlapping starts/width-dependent lengths.
    starts: dict[tuple[str,int],set[int]]=defaultdict(set)
    for off,items in roles.items():
        for start,level,role,length in items:
            starts[(level,start)].add(length)
    for (level,start),lens in sorted(starts.items()):
        if len(lens)>1:
            conflict_counter+=1; cid=f"V03X{conflict_counter:05d}"
            conflicts.append({"Conflict_ID":cid,"Severity":level,"Type":"WIDTH_LENGTH_AMBIGUITY","Physical":f"{start:06X}",
                              "Details":"instruction lengths="+",".join(map(str,sorted(lens)))})
            conflict_ids[start].add(cid)
    for off,items in sorted(roles.items()):
        proved=[x for x in items if x[1]=="PROVED"]
        cand=[x for x in items if x[1]=="CANDIDATE"]
        pstarts={x[0] for x in proved}; cstarts={x[0] for x in cand}
        if HEADER_START <= off <= HEADER_END and (proved or cand):
            conflict_counter+=1; cid=f"V03X{conflict_counter:05d}"
            sev="PROVED" if proved else "CANDIDATE"
            conflicts.append({"Conflict_ID":cid,"Severity":sev,"Type":"HEADER_CODE_OVERLAP","Physical":f"{off:06X}",
                              "Details":f"proved_starts={len(pstarts)} candidate_starts={len(cstarts)}"})
            conflict_ids[off].add(cid)
        if len(pstarts)>1:
            conflict_counter+=1; cid=f"V03X{conflict_counter:05d}"
            conflicts.append({"Conflict_ID":cid,"Severity":"PROVED","Type":"OVERLAPPING_PROVED_INSTRUCTIONS","Physical":f"{off:06X}",
                              "Details":"starts="+",".join(f"{x:06X}" for x in sorted(pstarts))})
            conflict_ids[off].add(cid)
        if HEADER_START <= off <= HEADER_END:
            continue
        if proved: classes[off]="PROVED_CODE"
        elif cand: classes[off]="CANDIDATE"
    # Any proved/header conflict is physically a conflict classification; candidate
    # ambiguity remains visible in conflict manifest without overstating ownership.
    for off,cids in conflict_ids.items():
        if any(next(c for c in conflicts if c["Conflict_ID"]==cid)["Severity"]=="PROVED" for cid in cids):
            classes[off]="CONFLICT"

    # Compress into total physical ranges.
    rows=[]; start=0
    for i in range(1,ROM_SIZE+1):
        if i==ROM_SIZE or classes[i]!=classes[start]:
            end=i-1; cls=classes[start]
            cids=sorted({cid for off in range(start,end+1) for cid in conflict_ids.get(off,set())}) if cls=="CONFLICT" else []
            rows.append({
                "Physical_Start":f"{start:06X}","Physical_End":f"{end:06X}","Classification":cls,
                "Confidence":"SOURCE_PROVED" if cls in {"PROVED_CODE","HEADER_VECTOR"} else ("CONFLICT" if cls=="CONFLICT" else ("CANDIDATE_ONLY" if cls=="CANDIDATE" else "EXPLICIT_UNKNOWN")),
                "Mapped_CPU_Addresses":"canonical LoROM physical ownership; mirrors do not duplicate bytes",
                "Producer":"V03C root/direct-flow discovery" if cls!="HEADER_VECTOR" else "V01C exact header/vector proof",
                "Consumer":"V04C dynamic/return proof" if cls in {"CANDIDATE","UNRESOLVED","CONFLICT"} else "future static generation",
                "Proof_ID":"BYTE-V03C-DISCOVERY" if cls!="HEADER_VECTOR" else "BYTE-V01C-HEADER-VECTORS",
                "Conflict_ID":";".join(cids),"Phase":"V03C" if cls!="HEADER_VECTOR" else "V01C",
                "Notes":"Candidate is not production authority." if cls=="CANDIDATE" else ("Unresolved remains explicit; never inferred as data." if cls=="UNRESOLVED" else "")
            })
            start=i
    totals=defaultdict(int)
    for i,c in enumerate(classes): totals[c]+=1
    return rows,conflicts,dict(sorted(totals.items()))


def frontier_ledger_rows(frontiers: list[dict], predecessor_sha256: str) -> list[dict]:
    rows=[]
    for f in frontiers:
        rows.append({
            "Frontier_ID":f["Frontier_ID"],"Milestone":"V03C","Predecessor_SHA256":predecessor_sha256,
            "Context":f["Context"],"Expected_Bytes":f["Instruction"],"Master_Clock":"NOT_RUNTIME_TRAVERSED",
            "Class":f["Class"],"Stop_Reason":f["Reason"],"Authority_Needed":"V04C finite source proof or later machine semantics",
            "Proof_ID":"PENDING_V04C","Regression_Test":"V03C-FLOW-001","Status":"OPEN","Successor_Package":"",
            "Notes":"Discovery frontier only; no oracle/trace promotion."
        })
    return rows


def discover(rom: bytes, profile: dict, predecessor_sha256: str) -> DiscoveryResult:
    if len(rom)!=ROM_SIZE: raise ValueError(f"expected 1 MiB ROM, got {len(rom)}")
    if sha256_bytes(rom)!=ROM_SHA256: raise ValueError("unsupported Rock n' Roll Racing ROM SHA-256")
    scan=all_offset_scan(rom)
    roots,contexts,edges,frontiers,roles,graph_at_physical,extra=graph_discover(rom,profile)
    ownership,conflicts,ownership_totals=build_ownership(roles)
    apuio=raw_apuio_candidates(rom,graph_at_physical)
    # Stable context-level counts, deliberately separating proof and candidate.
    level_counts=defaultdict(int)
    unique_keys=defaultdict(set)
    for r in contexts:
        level_counts[r["Level"]]+=1
        unique_keys[r["Level"]].add((r["PBR"],r["PC"],r["E"],r["M"],r["X"]))
    frontier_counts=defaultdict(int)
    for f in frontiers: frontier_counts[f["Class"]]+=1
    apuio_claims=defaultdict(int)
    for a in apuio: apuio_claims[a["Claim"]]+=1
    summary={
        "schema":1,"milestone":"03C","authority":"whole-ROM discovery only; candidate != admitted production execution",
        "rom_sha256":sha256_bytes(rom),"rom_size":len(rom),"predecessor_v02c_commit":predecessor_sha256,
        "all_offset_scan":scan,
        "vector_root_records":sum(1 for r in roots if r["Root_Type"]=="VECTOR_SOURCE_PROVED"),
        "candidate_root_records":sum(1 for r in roots if r["Level"]=="CANDIDATE"),
        "processed_internal_states":len(extra["seen_states"]),
        "context_rows":len(contexts),"context_rows_by_level":dict(sorted(level_counts.items())),
        "unique_context_keys_by_level":{k:len(v) for k,v in sorted(unique_keys.items())},
        "edge_rows":len(edges),"frontier_rows":len(frontiers),"frontiers_by_class":dict(sorted(frontier_counts.items())),
        "ownership_bytes":ownership_totals,"ownership_range_rows":len(ownership),"conflict_rows":len(conflicts),
        "apuio_candidate_rows":len(apuio),"apuio_claims":dict(sorted(apuio_claims.items())),
        "trace_promotions":0,"oracle_promotions":0,
        "limitations":[
            "V03C does not close return sets, indirect targets, RTI re-entry, executable WRAM, DBR path provenance, or native callback domains.",
            "Return continuations are explored only as candidates; they never upgrade byte ownership to source-proved code.",
            "All-offset legal decodes are census evidence only and do not relabel arbitrary bytes as code or data.",
            "APUIO absolute-operand matches remain candidates unless graph reach plus a known MMIO DBR proves the effective bank."
        ]
    }
    return DiscoveryResult(summary,roots,contexts,edges,frontiers,conflicts,apuio,ownership,frontier_ledger_rows(frontiers,predecessor_sha256))


def write_csv(path: Path, rows: list[dict], fieldnames: list[str] | None = None) -> None:
    path.parent.mkdir(parents=True,exist_ok=True)
    if fieldnames is None:
        fieldnames=list(rows[0]) if rows else []
    with path.open("w",encoding="utf-8",newline="") as f:
        w=csv.DictWriter(f,fieldnames=fieldnames,lineterminator="\n")
        w.writeheader(); w.writerows(rows)


def write_result(result: DiscoveryResult, root: Path) -> list[str]:
    rels=[
        "docs/V03C-discovery-summary.json","docs/V03C-root-contexts.csv","docs/V03C-contexts.csv",
        "docs/V03C-edges.csv","docs/V03C-frontiers.csv","docs/V03C-conflicts.csv","docs/V03C-apuio-candidates.csv",
        "config/byte-ownership.csv","config/frontier-ledger.csv",
    ]
    (root/"docs").mkdir(parents=True,exist_ok=True); (root/"config").mkdir(parents=True,exist_ok=True)
    (root/rels[0]).write_text(json.dumps(result.summary,indent=2,sort_keys=True)+"\n",encoding="utf-8",newline="\n")
    write_csv(root/rels[1],result.roots,["Root_ID","Root_Type","Level","PBR","PC","E","M","X","Reason","Origins"])
    write_csv(root/rels[2],result.contexts,["Context_ID","Level","PBR","PC","E","M","X","Carry","DBR","Physical","Opcode","Mnemonic","Mode","Length","Bytes"])
    write_csv(root/rels[3],result.edges,["From","Edge_Kind","To","To_Level","Reason"])
    write_csv(root/rels[4],result.frontiers,["Frontier_ID","Level","Context","Class","Instruction","Reason","Candidate_Target"])
    write_csv(root/rels[5],result.conflicts,["Conflict_ID","Severity","Type","Physical","Details"])
    write_csv(root/rels[6],result.apuio,["Candidate_ID","Physical","Canonical_CPU","Opcode","Mnemonic","Mode","Access","Register","Address_Form","Encoded_Bank","Graph_Levels","Known_DBRs","Claim","Notes"])
    write_csv(root/rels[7],result.ownership,["Physical_Start","Physical_End","Classification","Confidence","Mapped_CPU_Addresses","Producer","Consumer","Proof_ID","Conflict_ID","Phase","Notes"])
    write_csv(root/rels[8],result.frontier_ledger,["Frontier_ID","Milestone","Predecessor_SHA256","Context","Expected_Bytes","Master_Clock","Class","Stop_Reason","Authority_Needed","Proof_ID","Regression_Test","Status","Successor_Package","Notes"])
    return rels
