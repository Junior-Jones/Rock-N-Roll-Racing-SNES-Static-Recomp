"""V04C source-proof control-flow analyser for Rock n' Roll Racing (SNES).

Offline proof tool only.  It extends V03C with path identity, logical stack facts,
direct call/return pairing, status push/pull provenance, finite known indexed target
sets, DBR/effective-address facts, and explicit fail-closed boundaries.

Oracle/traces are never inputs.  Candidate V03C contexts are never promoted merely
because they decode; only source-proved roots and source-proved successors enter the
V04C admitted graph.
"""
from __future__ import annotations

from collections import Counter, defaultdict, deque
from dataclasses import dataclass, replace
import csv
import hashlib
import json
from pathlib import Path
from typing import Iterable, Optional

from analysis.v01c_cartridge_profile import canonical_lorom_offset
from analysis.v03c_discovery import (
    ROM_SHA256, ROM_SIZE, LEGAL_CONTEXTS, CONDITIONAL_BRANCHES,
    State as V03State, read_instruction, next_pc, u16, u24, s8, s16,
    vector_roots, mmio_bank, APUIO_REGS,
)

MAX_FINITE_VALUES = 32
MAX_STACK_ENTRIES = 48
MAX_TRACKED_STACK_BYTES = 20
MAX_STATE_VARIANTS_PER_SITE = 8
HARD_CONTEXT_LIMIT = 250_000
NO_SP_REL = 1 << 30

READ_MNEMONICS = {"LDA","LDX","LDY","CMP","CPX","CPY","BIT","ADC","SBC","AND","ORA","EOR"}
WRITE_MNEMONICS = {"STA","STX","STY","STZ"}
RMW_MNEMONICS = {"ASL","LSR","ROL","ROR","INC","DEC","TRB","TSB"}


@dataclass(frozen=True, order=True)
class StackEntry:
    kind: str
    width: int
    values: tuple[int, ...] = ()
    # STATUS and interrupt frame metadata
    e: int = -1
    m: int = -1
    x: int = -1
    c: int = -1
    n: int = -1
    z: int = -1
    v: int = -1
    pbr: int = -1
    pc: int = -1

    @staticmethod
    def data(width: int, values: Optional[Iterable[int]], kind: str = "DATA") -> "StackEntry":
        vals = finite(values, (1 << (8 * width)) - 1)
        return StackEntry(kind, width, vals or ())


@dataclass(frozen=True, order=True)
class V04State:
    pbr: int
    pc: int
    e: int
    m: int
    x: int
    c: int = -1
    n: int = -1
    z: int = -1
    v: int = -1
    dbr: int = -1
    d: int = -1
    a_full: tuple[int, ...] = ()
    a_low: tuple[int, ...] = ()
    xr: tuple[int, ...] = ()
    yr: tuple[int, ...] = ()
    # Affine provenance relative to the *current* hardware stack pointer S.
    # A/X relation r means register == S + r (native 16-bit form).  This is
    # intentionally separate from finite numeric values so TSX/TXA/ADC/TAX/TXS
    # stack-cleanup idioms can be proved without inventing an absolute S value.
    a_sp_rel: int = NO_SP_REL
    x_sp_rel: int = NO_SP_REL
    stack: tuple[StackEntry, ...] = ()
    stack_base_unknown: bool = True
    origin: str = ""

    def short(self) -> str:
        def f(b: int) -> str: return "?" if b < 0 else str(b)
        db = "??" if self.dbr < 0 else f"{self.dbr:02X}"
        return f"{self.pbr:02X}:{self.pc:04X}:E{self.e}M{self.m}X{self.x}:C{f(self.c)}:DBR{db}:S{len(self.stack)}"

    def decoder_state(self) -> V03State:
        return V03State(self.pbr, self.pc, self.e, self.m, self.x, self.c, self.dbr, -1, "PROVED")


@dataclass
class V04Result:
    summary: dict
    contexts: list[dict]
    edges: list[dict]
    boundaries: list[dict]
    dynamic_proofs: list[dict]
    memory_accesses: list[dict]
    v03_frontier_dispositions: list[dict]
    v03_root_dispositions: list[dict]
    v03_conflict_dispositions: list[dict]
    apuio_dispositions: list[dict]
    ownership: list[dict]
    frontier_ledger: list[dict]


def finite(values: Optional[Iterable[int]], mask: int = 0xFFFF) -> Optional[tuple[int, ...]]:
    if values is None:
        return None
    vals = tuple(sorted({int(v) & mask for v in values}))
    if len(vals) > MAX_FINITE_VALUES:
        return None
    return vals


def vals_or_none(v: tuple[int, ...]) -> Optional[tuple[int, ...]]:
    return v if v else None


def set_a(st: V04State, vals: Optional[Iterable[int]], width: int) -> V04State:
    if width == 16:
        full = finite(vals, 0xFFFF)
        low = finite(((v & 0xFF) for v in full), 0xFF) if full is not None else None
        return replace(st, a_full=full or (), a_low=low or (), a_sp_rel=NO_SP_REL)
    low = finite(vals, 0xFF)
    # Preserve known high byte if every prior full value has the same high byte.
    old = vals_or_none(st.a_full)
    full = None
    if old is not None and low is not None:
        highs = {v & 0xFF00 for v in old}
        if len(highs) == 1:
            hi = next(iter(highs))
            full = finite((hi | lo for lo in low), 0xFFFF)
    return replace(st, a_full=full or (), a_low=low or (), a_sp_rel=NO_SP_REL)


def a_values(st: V04State, width: int) -> Optional[tuple[int, ...]]:
    return vals_or_none(st.a_full if width == 16 else st.a_low)


def x_values(st: V04State) -> Optional[tuple[int, ...]]:
    return vals_or_none(st.xr)


def y_values(st: V04State) -> Optional[tuple[int, ...]]:
    return vals_or_none(st.yr)


def nz_for_values(vals: Optional[Iterable[int]], width: int) -> tuple[int,int]:
    if vals is None: return -1,-1
    vs=tuple(vals)
    if not vs: return -1,-1
    mask=(1<<width)-1; sign=1<<(width-1)
    zs={1 if (v&mask)==0 else 0 for v in vs}
    ns={1 if (v&sign) else 0 for v in vs}
    return (next(iter(ns)) if len(ns)==1 else -1, next(iter(zs)) if len(zs)==1 else -1)


def normalize_widths(st: V04State) -> V04State:
    if st.e:
        st=replace(st,m=1,x=1)
    if st.x:
        xv=finite(vals_or_none(st.xr),0xFF)
        yv=finite(vals_or_none(st.yr),0xFF)
        st=replace(st,xr=xv or (),yr=yv or (),x_sp_rel=NO_SP_REL)
    if st.m:
        st=replace(st,a_sp_rel=NO_SP_REL)
    return st


def _shift_sp_rel(rel: int, delta_s: int) -> int:
    """Update register-S relation after S changes by delta_s."""
    return rel if rel == NO_SP_REL else rel - delta_s


def _with_stack_change(st: V04State, stack: tuple[StackEntry, ...], delta_s: int) -> V04State:
    # S-relative register facts are intentionally short-lived.  Keeping an
    # affine identity alive across arbitrary pushes/pulls is correct but causes
    # large, useless path products in loops.  The only V04 proof that needs the
    # relation has no intervening stack mutation (TSX/TXA/ADC/TAX/TXS), so any
    # real stack change conservatively invalidates the captured relation.
    return replace(st,stack=stack,a_sp_rel=NO_SP_REL,x_sp_rel=NO_SP_REL)


def push(st: V04State, entry: StackEntry) -> Optional[V04State]:
    if len(st.stack) >= MAX_STACK_ENTRIES:
        return None
    # Native stack grows downward: pushing N bytes changes S by -N.
    ns=_with_stack_change(st,st.stack+(entry,),-entry.width)
    if stack_bytes(ns)>MAX_TRACKED_STACK_BYTES:
        items=list(ns.stack)
        # Preserve an exact top-of-stack window and mark everything below it
        # unknown.  This is a sound finite call-string abstraction: code inside
        # the window is still proved exactly; a return/pull that crosses the
        # truncated base fails closed rather than guessing an older caller.
        while items and sum(e.width for e in items)>MAX_TRACKED_STACK_BYTES:
            items.pop(0)
        ns=replace(ns,stack=tuple(items),stack_base_unknown=True)
    return ns


def _entry_low(entry: StackEntry, width: int) -> StackEntry:
    """Top `width` bytes of one pushed entry (low-order bytes are on top)."""
    assert 0 < width <= entry.width
    if width == entry.width:
        return entry
    vals = finite((v & ((1 << (8*width))-1) for v in entry.values), (1 << (8*width))-1) if entry.values else None
    return StackEntry.data(width,vals,f"{entry.kind}_LOW")


def _entry_high_remainder(entry: StackEntry, consumed_low: int) -> Optional[StackEntry]:
    remain=entry.width-consumed_low
    if remain<=0:return None
    vals = finite((v >> (8*consumed_low) for v in entry.values),(1 << (8*remain))-1) if entry.values else None
    return StackEntry.data(remain,vals,f"{entry.kind}_HIGH")


def pop(st: V04State, expected_width: Optional[int]=None) -> tuple[Optional[StackEntry],V04State,bool]:
    """Pull bytes from the symbolic hardware stack, byte-accurately.

    A 65C816 can push a 16-bit value, change M/X, and then pull one byte (or
    vice versa).  Treating a push as an indivisible object loses stack
    provenance and creates false PLP/return frontiers.  This routine consumes
    exactly the requested number of bytes, splitting/combining entries while
    retaining exact finite byte values when available.
    """
    width=expected_width
    if width is None:
        if not st.stack:return None,st,False
        width=st.stack[-1].width
    if width<=0:return None,st,False
    stack=list(st.stack); need=width; shift=0; parts=[]; combined={0}
    exact_single = bool(stack and stack[-1].width==width)
    exact_entry = stack[-1] if exact_single else None
    while need>0 and stack:
        ent=stack.pop(); take=min(need,ent.width)
        part=_entry_low(ent,take); parts.append(part)
        if part.values:
            combined={base | (v << shift) for base in combined for v in part.values}
            if len(combined)>MAX_FINITE_VALUES: combined=set()
        else:
            combined=set()
        rem=_entry_high_remainder(ent,take)
        if rem is not None: stack.append(rem)
        need-=take; shift+=8*take
    consumed=width-need
    ns=_with_stack_change(st,tuple(stack),consumed)
    if need:
        # We crossed below the source-modelled segment into an unknown stack
        # base.  Data pulls may continue with an unknown value; status/control
        # consumers receive ok=False and therefore fail closed.
        return None,ns,False
    if exact_single and exact_entry is not None:
        return exact_entry,ns,True
    vals=finite(combined,(1 << (8*width))-1) if combined else None
    kind="+".join(p.kind for p in parts) if parts else "DATA"
    return StackEntry.data(width,vals,kind),ns,True


def drop_stack_bytes(st: V04State, count: int) -> tuple[V04State,bool]:
    """Advance S by an exact positive byte count without interpreting values."""
    if count<0:return st,False
    if count==0:return st,True
    stack=list(st.stack); need=count
    while need>0 and stack:
        ent=stack.pop(); take=min(need,ent.width)
        rem=_entry_high_remainder(ent,take)
        if rem is not None: stack.append(rem)
        need-=take
    consumed=count-need
    ns=_with_stack_change(st,tuple(stack),consumed)
    return ns,need==0


def stack_bytes(st: V04State) -> int:
    return sum(e.width for e in st.stack)


def stack_summary(st: V04State) -> str:
    def one(e:StackEntry)->str:
        vals="?" if not e.values else "/".join(f"{v:0{e.width*2}X}" for v in e.values[:4])+("..." if len(e.values)>4 else "")
        if e.kind.startswith("RET"):
            return f"{e.kind}[{e.width}]=>{e.pbr:02X}:{e.pc:04X}"
        return f"{e.kind}[{e.width}]={vals}"
    return "|".join(one(e) for e in st.stack[-12:]) or "EMPTY"


def status_entry(st: V04State) -> StackEntry:
    return StackEntry("STATUS",1,(),st.e,st.m,st.x,st.c,st.n,st.z,st.v)


def data_entry_for_a(st: V04State) -> StackEntry:
    width=1 if st.m else 2
    vals=a_values(st,8 if width==1 else 16)
    return StackEntry.data(width,vals,"A")


def data_entry_for_index(vals: Optional[tuple[int,...]], width8: int, kind: str) -> StackEntry:
    width=1 if width8 else 2
    return StackEntry.data(width,vals,kind)


def entry_values(entry: Optional[StackEntry]) -> Optional[tuple[int,...]]:
    if entry is None or not entry.values: return None
    return entry.values


def cpu24(pbr: int,pc: int)->int: return ((pbr&0xFF)<<16)|(pc&0xFFFF)


def map_rom_addr(addr: int, rom_size: int=ROM_SIZE) -> Optional[int]:
    try: return canonical_lorom_offset(addr & 0xFFFFFF,rom_size)
    except ValueError: return None


def read_rom_value(rom: bytes, addr: int, width: int) -> Optional[int]:
    vals=[]
    for i in range(width//8):
        a=(addr & 0xFF0000) | ((addr+i)&0xFFFF)
        off=map_rom_addr(a,len(rom))
        if off is None: return None
        vals.append(rom[off])
    out=0
    for i,b in enumerate(vals): out |= b << (8*i)
    return out


def is_wram_addr(addr: int) -> bool:
    bank=(addr>>16)&0xFF; a=addr&0xFFFF
    if bank in (0x7E,0x7F): return True
    if ((0x00<=bank<=0x3F) or (0x80<=bank<=0xBF)) and a<=0x1FFF: return True
    return False


def is_mmio_addr(addr: int) -> bool:
    bank=(addr>>16)&0xFF; a=addr&0xFFFF
    return mmio_bank(bank) and 0x2000<=a<=0x5FFF


def effective_addresses(st: V04State, d) -> Optional[tuple[int,...]]:
    """Finite effective address set for common data modes; None means unproved."""
    mode=d.spec.mode; raw=d.raw
    dbr=st.dbr
    xv=x_values(st); yv=y_values(st)
    base16=u16(raw) if len(raw)>=3 else 0
    if mode=="ABS":
        if dbr<0: return None
        return (cpu24(dbr,base16),)
    if mode=="ABS_X":
        if dbr<0 or xv is None: return None
        return finite((cpu24(dbr,(base16+x)&0xFFFF) for x in xv),0xFFFFFF)
    if mode=="ABS_Y":
        if dbr<0 or yv is None: return None
        return finite((cpu24(dbr,(base16+y)&0xFFFF) for y in yv),0xFFFFFF)
    if mode=="ABS_LONG": return (u24(raw),)
    if mode=="ABS_LONG_X":
        if xv is None: return None
        b=u24(raw); bank=b&0xFF0000; lo=b&0xFFFF
        return finite((bank|((lo+x)&0xFFFF) for x in xv),0xFFFFFF)
    if mode=="DP" and st.d>=0:
        return (cpu24(0,(st.d+raw[1])&0xFFFF),)
    if mode=="DP_X" and st.d>=0 and xv is not None:
        return finite((cpu24(0,(st.d+raw[1]+x)&0xFFFF) for x in xv),0xFFFFFF)
    if mode=="DP_Y" and st.d>=0 and yv is not None:
        return finite((cpu24(0,(st.d+raw[1]+y)&0xFFFF) for y in yv),0xFFFFFF)
    return None


def operand_values_from_rom(st: V04State,d,rom:bytes,width:int) -> Optional[tuple[int,...]]:
    if d.spec.mode in {"IMM_M","IMM_X","IMM8"}:
        if width==8: return (d.raw[1],)
        if len(d.raw)>=3: return (u16(d.raw),)
        return None
    addrs=effective_addresses(st,d)
    if addrs is None: return None
    vals=[]
    for a in addrs:
        v=read_rom_value(rom,a,width)
        if v is None: return None
        vals.append(v)
    return finite(vals,(1<<width)-1)


def branch_decision(st: V04State,mn:str)->Optional[bool]:
    flag=None; want=1
    if mn=="BPL": flag=st.n; want=0
    elif mn=="BMI": flag=st.n; want=1
    elif mn=="BVC": flag=st.v; want=0
    elif mn=="BVS": flag=st.v; want=1
    elif mn=="BCC": flag=st.c; want=0
    elif mn=="BCS": flag=st.c; want=1
    elif mn=="BNE": flag=st.z; want=0
    elif mn=="BEQ": flag=st.z; want=1
    if flag is None or flag<0: return None
    return flag==want


def compare_values(lhs: Optional[tuple[int,...]], rhs: Optional[tuple[int,...]], width:int)->tuple[int,int,int]:
    if lhs is None or rhs is None: return -1,-1,-1
    mask=(1<<width)-1; sign=1<<(width-1)
    cs=set(); zs=set(); ns=set()
    for a in lhs:
        for b in rhs:
            a&=mask; b&=mask; r=(a-b)&mask
            cs.add(1 if a>=b else 0); zs.add(1 if r==0 else 0); ns.add(1 if r&sign else 0)
    one=lambda s: next(iter(s)) if len(s)==1 else -1
    return one(cs),one(ns),one(zs)


def update_linear_state(st:V04State,d,rom:bytes)->tuple[V04State,Optional[str]]:
    """Apply conservative register/stack/DBR facts for a non-control instruction.

    Returns (state at next PC, fail_reason).  fail_reason is used when stack/status
    provenance is insufficient for a source-proved continuation.
    """
    mn=d.spec.mnemonic; mode=d.spec.mode
    ns=replace(st,pc=next_pc(d))
    # Most instructions that don't explicitly set C/N/Z/V below invalidate only
    # flags they architecturally modify.  Registers are preserved unless named.
    if mn=="CLC": ns=replace(ns,c=0)
    elif mn=="SEC": ns=replace(ns,c=1)
    elif mn=="CLV": ns=replace(ns,v=0)
    elif mn in {"CLD","SED","CLI","SEI","NOP","WDM"}: pass
    elif mn in {"REP","SEP"}:
        imm=d.raw[1]; e=st.e; m=st.m; x=st.x; c=st.c
        if mn=="REP":
            if imm&1:c=0
            if not e:
                if imm&0x20:m=0
                if imm&0x10:x=0
        else:
            if imm&1:c=1
            if imm&0x20:m=1
            if imm&0x10:x=1
        ns=normalize_widths(replace(ns,m=m,x=x,c=c))
    elif mn=="XCE":
        if st.c not in (0,1): return ns,"XCE carry provenance unknown"
        ne=st.c; nc=st.e
        ns=normalize_widths(replace(ns,e=ne,c=nc))
    elif mn=="PHP":
        p=push(ns,status_entry(st))
        if p is None:return ns,"symbolic stack depth exceeded"
        ns=p
    elif mn=="PHB":
        p=push(ns,StackEntry.data(1,(st.dbr,) if st.dbr>=0 else None,"DBR"));
        if p is None:return ns,"symbolic stack depth exceeded"
        ns=p
    elif mn=="PHK":
        p=push(ns,StackEntry.data(1,(st.pbr,),"PBR"));
        if p is None:return ns,"symbolic stack depth exceeded"
        ns=p
    elif mn=="PHA":
        p=push(ns,data_entry_for_a(st));
        if p is None:return ns,"symbolic stack depth exceeded"
        ns=p
    elif mn=="PHX":
        p=push(ns,data_entry_for_index(x_values(st),st.x,"X"));
        if p is None:return ns,"symbolic stack depth exceeded"
        ns=p
    elif mn=="PHY":
        p=push(ns,data_entry_for_index(y_values(st),st.x,"Y"));
        if p is None:return ns,"symbolic stack depth exceeded"
        ns=p
    elif mn=="PHD":
        p=push(ns,StackEntry.data(2,(st.d,) if st.d>=0 else None,"D"));
        if p is None:return ns,"symbolic stack depth exceeded"
        ns=p
    elif mn=="PEA":
        p=push(ns,StackEntry.data(2,(u16(d.raw),),"PEA"));
        if p is None:return ns,"symbolic stack depth exceeded"
        ns=p
    elif mn=="PER":
        val=(next_pc(d)+s16(u16(d.raw)))&0xFFFF
        p=push(ns,StackEntry.data(2,(val,),"PER"));
        if p is None:return ns,"symbolic stack depth exceeded"
        ns=p
    elif mn=="PEI":
        p=push(ns,StackEntry.data(2,None,"PEI"));
        if p is None:return ns,"symbolic stack depth exceeded"
        ns=p
    elif mn=="PLP":
        ent,tmp,ok=pop(ns,1)
        if not ok: return tmp,"PLP status producer/stack width unproved"
        if ent and ent.kind=="STATUS":
            m,x,c,n,z,v=ent.m,ent.x,ent.c,ent.n,ent.z,ent.v
        elif ent and ent.values and len(ent.values)==1:
            pv=ent.values[0]; m=(pv>>5)&1; x=(pv>>4)&1; c=pv&1; n=(pv>>7)&1; z=(pv>>1)&1; v=(pv>>6)&1
        else:
            return tmp,"PLP status byte provenance unproved"
        if st.e:m=x=1
        ns=normalize_widths(replace(tmp,m=m,x=x,c=c,n=n,z=z,v=v))
    elif mn=="PLB":
        ent,tmp,ok=pop(ns,1); vals=entry_values(ent)
        ns=replace(tmp,dbr=vals[0] if ok and vals and len(vals)==1 else -1,n=-1,z=-1)
        if ns.dbr>=0: ns=replace(ns,n=1 if ns.dbr&0x80 else 0,z=1 if ns.dbr==0 else 0)
    elif mn=="PLD":
        ent,tmp,ok=pop(ns,2); vals=entry_values(ent)
        ns=replace(tmp,d=vals[0] if ok and vals and len(vals)==1 else -1,n=-1,z=-1)
        if ns.d>=0: ns=replace(ns,n=1 if ns.d&0x8000 else 0,z=1 if ns.d==0 else 0)
    elif mn=="PLA":
        width=8 if st.m else 16; ent,tmp,ok=pop(ns,1 if st.m else 2); vals=entry_values(ent) if ok else None
        ns=set_a(tmp,vals,width); n,z=nz_for_values(vals,width); ns=replace(ns,n=n,z=z)
    elif mn=="PLX":
        width=8 if st.x else 16; ent,tmp,ok=pop(ns,1 if st.x else 2); vals=entry_values(ent) if ok else None
        vv=finite(vals,(1<<width)-1); n,z=nz_for_values(vv,width); ns=replace(tmp,xr=vv or (),n=n,z=z)
    elif mn=="PLY":
        width=8 if st.x else 16; ent,tmp,ok=pop(ns,1 if st.x else 2); vals=entry_values(ent) if ok else None
        vv=finite(vals,(1<<width)-1); n,z=nz_for_values(vv,width); ns=replace(tmp,yr=vv or (),n=n,z=z)
    elif mn=="LDA":
        width=8 if st.m else 16; vals=operand_values_from_rom(st,d,rom,width); ns=set_a(ns,vals,width); n,z=nz_for_values(vals,width); ns=replace(ns,n=n,z=z)
    elif mn=="LDX":
        width=8 if st.x else 16; vals=operand_values_from_rom(st,d,rom,width); vv=finite(vals,(1<<width)-1); n,z=nz_for_values(vv,width); ns=replace(ns,xr=vv or (),x_sp_rel=NO_SP_REL,n=n,z=z)
    elif mn=="LDY":
        width=8 if st.x else 16; vals=operand_values_from_rom(st,d,rom,width); vv=finite(vals,(1<<width)-1); n,z=nz_for_values(vv,width); ns=replace(ns,yr=vv or (),n=n,z=z)
    elif mn in {"CMP","CPX","CPY"}:
        if mn=="CMP": width=8 if st.m else 16; lhs=a_values(st,width)
        elif mn=="CPX": width=8 if st.x else 16; lhs=x_values(st)
        else: width=8 if st.x else 16; lhs=y_values(st)
        rhs=operand_values_from_rom(st,d,rom,width); c,n,z=compare_values(lhs,rhs,width); ns=replace(ns,c=c,n=n,z=z)
    elif mn in {"AND","ORA","EOR"}:
        width=8 if st.m else 16; lhs=a_values(st,width); rhs=operand_values_from_rom(st,d,rom,width)
        vals=None
        if lhs is not None and rhs is not None:
            op=(lambda a,b:a&b) if mn=="AND" else ((lambda a,b:a|b) if mn=="ORA" else (lambda a,b:a^b))
            vals=finite((op(a,b) for a in lhs for b in rhs),(1<<width)-1)
        ns=set_a(ns,vals,width); n,z=nz_for_values(vals,width); ns=replace(ns,n=n,z=z)
    elif mn in {"ADC","SBC"}:
        # Decimal mode and carry interactions are fully proved in V02C, but V04C
        # needs only producer facts.  Preserve the one affine S-relative idiom
        # required to prove TSX/TXA/CLC/ADC #const/TAX/TXS stack cleanup.
        sprel=NO_SP_REL
        if mn=="ADC" and not st.m and st.a_sp_rel!=NO_SP_REL and st.c in (0,1):
            rhs=operand_values_from_rom(st,d,rom,16)
            if rhs is not None and len(rhs)==1:
                sprel=(st.a_sp_rel+rhs[0]+st.c)&0xFFFF
        ns=set_a(ns,None,8 if st.m else 16); ns=replace(ns,c=-1,n=-1,z=-1,v=-1,a_sp_rel=sprel)
    elif mn in {"INX","DEX"}:
        width=8 if st.x else 16; vals=x_values(st); delta=1 if mn=="INX" else -1
        vv=finite(((v+delta)&((1<<width)-1) for v in vals), (1<<width)-1) if vals is not None else None
        rel=(st.x_sp_rel+delta)&0xFFFF if (not st.x and st.x_sp_rel!=NO_SP_REL) else NO_SP_REL
        n,z=nz_for_values(vv,width); ns=replace(ns,xr=vv or (),x_sp_rel=rel,n=n,z=z)
    elif mn in {"INY","DEY"}:
        width=8 if st.x else 16; vals=y_values(st); delta=1 if mn=="INY" else -1
        vv=finite(((v+delta)&((1<<width)-1) for v in vals), (1<<width)-1) if vals is not None else None
        n,z=nz_for_values(vv,width); ns=replace(ns,yr=vv or (),n=n,z=z)
    elif mn in {"INC","DEC"} and mode=="ACC":
        width=8 if st.m else 16; vals=a_values(st,width); delta=1 if mn=="INC" else -1
        vv=finite(((v+delta)&((1<<width)-1) for v in vals),(1<<width)-1) if vals is not None else None
        ns=set_a(ns,vv,width); n,z=nz_for_values(vv,width); ns=replace(ns,n=n,z=z)
    elif mn in {"TAX","TAY"}:
        vals=a_values(st,8 if st.x else 16); vv=finite(vals,0xFF if st.x else 0xFFFF); n,z=nz_for_values(vv,8 if st.x else 16)
        if mn=="TAX":
            rel=st.a_sp_rel if (not st.m and not st.x) else NO_SP_REL
            ns=replace(ns,xr=vv or (),x_sp_rel=rel,n=n,z=z)
        else:
            ns=replace(ns,yr=vv or (),n=n,z=z)
    elif mn in {"TXA","TYA"}:
        vals=x_values(st) if mn=="TXA" else y_values(st); ns=set_a(ns,vals,8 if st.m else 16); n,z=nz_for_values(vals,8 if st.m else 16)
        rel=st.x_sp_rel if (mn=="TXA" and not st.m and not st.x) else NO_SP_REL
        ns=replace(ns,n=n,z=z,a_sp_rel=rel)
    elif mn=="TXY":
        vals=x_values(st); vv=finite(vals,0xFF if st.x else 0xFFFF); n,z=nz_for_values(vv,8 if st.x else 16); ns=replace(ns,yr=vv or (),n=n,z=z)
    elif mn=="TYX":
        vals=y_values(st); vv=finite(vals,0xFF if st.x else 0xFFFF); n,z=nz_for_values(vv,8 if st.x else 16); ns=replace(ns,xr=vv or (),x_sp_rel=NO_SP_REL,n=n,z=z)
    elif mn=="TCD":
        vals=a_values(st,16); ns=replace(ns,d=vals[0] if vals and len(vals)==1 else -1); n,z=nz_for_values(vals,16); ns=replace(ns,n=n,z=z)
    elif mn=="TDC":
        vals=(st.d,) if st.d>=0 else None; ns=set_a(ns,vals,16); n,z=nz_for_values(vals,16); ns=replace(ns,n=n,z=z)
    elif mn in {"TCS","TXS"}:
        # If the new S is source-proved as old S + N, discard exactly N bytes
        # from the symbolic stack.  This proves real compiler/game idioms that
        # bulk-pop locals before RTS.  Otherwise replacement invalidates the
        # modelled segment and later control consumers fail closed.
        rel=st.a_sp_rel if mn=="TCS" else st.x_sp_rel
        if not st.e and rel!=NO_SP_REL:
            rel &= 0xFFFF
            # Only a forward stack adjustment entirely inside the modelled
            # segment is admitted.  Backward/new-memory stack synthesis needs
            # a separate WRAM producer proof and therefore remains unsupported.
            if rel <= stack_bytes(st):
                tmp,ok=drop_stack_bytes(ns,rel)
                if ok:
                    ns=replace(tmp,x_sp_rel=0 if mn=="TXS" else _shift_sp_rel(tmp.x_sp_rel,0),a_sp_rel=0 if mn=="TCS" else tmp.a_sp_rel)
                else:
                    ns=replace(ns,stack=(),stack_base_unknown=True,a_sp_rel=NO_SP_REL,x_sp_rel=NO_SP_REL)
            else:
                ns=replace(ns,stack=(),stack_base_unknown=True,a_sp_rel=NO_SP_REL,x_sp_rel=NO_SP_REL)
        else:
            ns=replace(ns,stack=(),stack_base_unknown=True,a_sp_rel=NO_SP_REL,x_sp_rel=NO_SP_REL)
    elif mn=="TSX":
        ns=replace(ns,xr=(),x_sp_rel=0 if not st.e and not st.x else NO_SP_REL,n=-1,z=-1)
    elif mn=="XBA":
        vals=vals_or_none(st.a_full)
        vv=finite((((v&0xFF)<<8)|((v>>8)&0xFF) for v in vals),0xFFFF) if vals is not None else None
        ns=set_a(ns,vv,16); low=finite(((v&0xFF) for v in vv),0xFF) if vv is not None else None; n,z=nz_for_values(low,8); ns=replace(ns,n=n,z=z)
    elif mn in {"MVN","MVP"}:
        # Encoding is dest,source on 65C816.  DBR becomes destination bank.
        ns=replace(ns,dbr=d.raw[1],a_full=(),a_low=(),xr=(),yr=(),n=-1,z=-1)
    elif mn in {"ASL","LSR","ROL","ROR"} and mode=="ACC":
        # Widen accumulator/flags rather than risk a false producer claim.
        ns=set_a(ns,None,8 if st.m else 16); ns=replace(ns,c=-1,n=-1,z=-1)
    elif mn in {"BIT","TRB","TSB"}:
        ns=replace(ns,n=-1,z=-1,v=-1)
    elif mn in WRITE_MNEMONICS or mn in RMW_MNEMONICS:
        if mn in RMW_MNEMONICS: ns=replace(ns,n=-1,z=-1,c=-1 if mn in {"ASL","LSR","ROL","ROR"} else ns.c)
    else:
        # Instructions not relevant to producer proof are allowed to fall through,
        # but unknown flag/register side effects must not survive.  Explicitly cover
        # common no-register control-neutral operations; widen conservatively else.
        if mn not in {"STZ","STX","STY","STA"}:
            # BRK/COP/branches/calls/returns are handled by graph_control before here.
            pass
    return normalize_widths(ns),None


def root_states(profile:dict)->list[tuple[V04State,str]]:
    out=[]
    for s,origin in vector_roots(profile):
        out.append((V04State(pbr=s.pbr,pc=s.pc,e=s.e,m=s.m,x=s.x,c=s.carry,dbr=s.dbr,origin=origin),origin))
    return out


def context_core_from_v03(text:str)->tuple[int,int,int,int,int]:
    # 80:8181:E1M1X1:C?:DBR80:P
    parts=text.split(':')
    pbr=int(parts[0],16); pc=int(parts[1],16)
    emx=parts[2]
    return pbr,pc,int(emx[1]),int(emx[3]),int(emx[5])


def site_key(st:V04State)->tuple:
    # Keep control-relevant stack path identity while grouping ordinary saved
    # register values.  After a few variants those data values are widened;
    # exact return/status/bank/PEA/PER producers remain path-sensitive.
    return (st.pbr,st.pc,st.e,st.m,st.x,st.dbr,st.d,abstract_stack(st.stack),st.origin)


def abstract_stack(stack:tuple[StackEntry,...])->tuple[StackEntry,...]:
    keep_prefixes=("RET","STATUS","INT_FRAME","PEA","PER","DBR","PBR","D")
    out=[]
    for e in stack:
        if e.kind.startswith(keep_prefixes): out.append(e)
        else: out.append(replace(e,values=()))
    return tuple(out)


def widened(st:V04State)->V04State:
    return replace(st,c=-1,n=-1,z=-1,v=-1,a_full=(),a_low=(),xr=(),yr=(),stack=abstract_stack(st.stack))


def record_memory_access(st:V04State,d,seq:int)->Optional[dict]:
    mn=d.spec.mnemonic
    if mn not in READ_MNEMONICS|WRITE_MNEMONICS|RMW_MNEMONICS: return None
    addrs=effective_addresses(st,d)
    kind="READ" if mn in READ_MNEMONICS else ("WRITE" if mn in WRITE_MNEMONICS else "READ_MODIFY_WRITE")
    if addrs is None:
        return {"Access_ID":f"V04M{seq:06d}","Context":"","Physical":f"{d.physical:06X}","Instruction":f"{mn}/{d.spec.mode}","Access":kind,"Effective_Addresses":"UNPROVED","Address_Count":"","DBR":"??" if st.dbr<0 else f"{st.dbr:02X}","MMIO":"UNPROVED","WRAM":"UNPROVED","Notes":"Finite effective-address producer not proved."}
    mmios=[a for a in addrs if is_mmio_addr(a)]; wrams=[a for a in addrs if is_wram_addr(a)]
    return {"Access_ID":f"V04M{seq:06d}","Context":"","Physical":f"{d.physical:06X}","Instruction":f"{mn}/{d.spec.mode}","Access":kind,"Effective_Addresses":";".join(f"{a:06X}" for a in addrs),"Address_Count":len(addrs),"DBR":"??" if st.dbr<0 else f"{st.dbr:02X}","MMIO":";".join(f"{a:06X}" for a in mmios),"WRAM":";".join(f"{a:06X}" for a in wrams),"Notes":"SOURCE_PROVED finite effective address set."}


def analyse(rom:bytes, profile:dict, v03_root_rows:list[dict], v03_frontiers:list[dict], v03_conflicts:list[dict], v03_apuio:list[dict], v03_ownership:list[dict], predecessor_commit:str)->V04Result:
    if len(rom)!=ROM_SIZE: raise ValueError("V04C requires exact 1 MiB target ROM")
    if hashlib.sha256(rom).hexdigest()!=ROM_SHA256: raise ValueError("unsupported Rock n' Roll Racing ROM SHA-256")

    q=deque(st for st,_ in root_states(profile))
    seen:set[V04State]=set(); variant_counts=Counter(); queued:set[V04State]=set(q)
    contexts=[]; edges=[]; boundaries=[]; dynproofs=[]; mem=[]
    ctxid_by_state={}
    role_bytes=defaultdict(list)
    boundary_seq=0; proof_seq=0; mem_seq=0

    def add_boundary(st:V04State,d,cls:str,reason:str,kind:str="FAIL_CLOSED",candidate:str=""):
        nonlocal boundary_seq
        boundary_seq+=1
        boundaries.append({"Boundary_ID":f"V04B{boundary_seq:05d}","Context":st.short(),"Physical":f"{d.physical:06X}","Instruction":f"{d.spec.mnemonic}/{d.spec.mode}","Class":cls,"Disposition":kind,"Reason":reason,"Candidate_Target":candidate,"Stack_Bytes":stack_bytes(st),"Stack_Proof":stack_summary(st),"A_SP_Rel":"?" if st.a_sp_rel==NO_SP_REL else st.a_sp_rel,"X_SP_Rel":"?" if st.x_sp_rel==NO_SP_REL else st.x_sp_rel,"Failure_Rule":"static dispatch must reject this context/edge; no generic runtime decoder or guessed continuation"})

    def enqueue(ns:V04State,fromid:str,kind:str,reason:str):
        ns=normalize_widths(ns)
        key=site_key(ns); variant_counts[key]+=1
        if variant_counts[key]>MAX_STATE_VARIANTS_PER_SITE:
            ns=widened(ns)
        edges.append({"From":fromid,"Edge_Kind":kind,"To":ns.short(),"Reason":reason})
        if ns not in seen and ns not in queued:
            q.append(ns); queued.add(ns)

    while q:
        st=q.popleft(); queued.discard(st)
        if st in seen: continue
        seen.add(st)
        if len(seen)>HARD_CONTEXT_LIMIT:
            hottest=variant_counts.most_common(8)
            raise RuntimeError(
                f"V04C context hard limit exceeded {HARD_CONTEXT_LIMIT}; "
                f"at={st.short()} stack_bytes={stack_bytes(st)} stack={stack_summary(st)} "
                f"hottest={hottest}"
            )
        try: d=read_instruction(rom,st.decoder_state())
        except ValueError as ex:
            # synthetic Decoded unavailable; make boundary using a tiny dummy shape impossible here
            boundary_seq+=1
            boundaries.append({"Boundary_ID":f"V04B{boundary_seq:05d}","Context":st.short(),"Physical":"","Instruction":"UNMAPPED","Class":"EXECUTABLE_WRAM_OR_UNMAPPED","Disposition":"FAIL_CLOSED","Reason":str(ex),"Candidate_Target":f"{st.pbr:02X}:{st.pc:04X}","Failure_Rule":"no ROM mapping/WRAM epoch proof; static dispatch rejects"})
            continue
        cid=f"V04C{len(contexts)+1:06d}"; ctxid_by_state[st]=cid
        fmtvals=lambda v,w: "?" if not v else ";".join(f"{x:0{w}X}" for x in v)
        ctx={"Context_ID":cid,"PBR":f"{st.pbr:02X}","PC":f"{st.pc:04X}","E":st.e,"M":st.m,"X":st.x,"Carry":"?" if st.c<0 else st.c,"N":"?" if st.n<0 else st.n,"Z":"?" if st.z<0 else st.z,"V":"?" if st.v<0 else st.v,"DBR":"??" if st.dbr<0 else f"{st.dbr:02X}","D":"????" if st.d<0 else f"{st.d:04X}","A16":fmtvals(st.a_full,4),"A8":fmtvals(st.a_low,2),"XR":fmtvals(st.xr,4),"YR":fmtvals(st.yr,4),"A_SP_Rel":"?" if st.a_sp_rel==NO_SP_REL else st.a_sp_rel,"X_SP_Rel":"?" if st.x_sp_rel==NO_SP_REL else st.x_sp_rel,"Stack_Depth":len(st.stack),"Stack_Bytes":stack_bytes(st),"Stack_Proof":stack_summary(st),"Root":st.origin,"Physical":f"{d.physical:06X}","Opcode":f"{d.spec.opcode:02X}","Mnemonic":d.spec.mnemonic,"Mode":d.spec.mode,"Length":d.length,"Bytes":d.raw.hex().upper()}
        contexts.append(ctx)
        for i in range(d.length):
            off=map_rom_addr(cpu24(st.pbr,(st.pc+i)&0xFFFF),len(rom))
            if off is not None: role_bytes[off].append((d.physical,d.length))
        mem_seq+=1; mr=record_memory_access(st,d,mem_seq)
        if mr:
            mr["Context"]=cid; mem.append(mr)
        mn=d.spec.mnemonic; mode=d.spec.mode

        # Terminal / special status control.
        if mn=="STP":
            edges.append({"From":cid,"Edge_Kind":"TERMINAL_STOP","To":"","Reason":"CPU remains stopped until reset"}); continue
        if mn=="WAI":
            add_boundary(st,d,"INTERRUPT_REENTRY","WAI resume requires scheduler/interrupt event proof not present in V04C source graph"); continue

        if mn in {"RTS","RTL"}:
            expected="RET16" if mn=="RTS" else "RET24"
            ent,tmp,ok=pop(st,2 if mn=="RTS" else 3)
            if not ok or ent is None or ent.kind!=expected:
                add_boundary(st,d,"RETURN","logical call-frame producer not on top of source-proved stack"); continue
            ns=replace(tmp,pbr=ent.pbr,pc=ent.pc)
            enqueue(ns,cid,"SOURCE_PROVED_RETURN",f"paired {mn} with exact {expected} call frame")
            proof_seq+=1; dynproofs.append({"Proof_ID":f"V04P{proof_seq:05d}","Class":"RETURN","Consumer":f"{st.pbr:02X}:{st.pc:04X}","Producer":"logical direct call frame","Width":"16-bit return" if mn=="RTS" else "24-bit return","Bank":f"{ent.pbr:02X}","Phase":"V04C source graph","Index_Domain":"N/A","Table_Bytes":"N/A","Admitted_Targets":f"{ent.pbr:02X}:{ent.pc:04X}","Rejected_Values":"any stack value not produced by paired call frame","Failure_Rule":"fail closed when exact return frame absent","Evidence":cid}); continue

        if mn=="RTI":
            ent,tmp,ok=pop(st,3 if st.e else 4)
            if not ok or ent is None or ent.kind!="INT_FRAME":
                add_boundary(st,d,"INTERRUPT_REENTRY","asynchronous vector root has no source-proved interrupted context frame"); continue
            ns=replace(tmp,pbr=ent.pbr,pc=ent.pc,e=ent.e,m=ent.m,x=ent.x,c=ent.c,n=ent.n,z=ent.z,v=ent.v)
            enqueue(ns,cid,"SOURCE_PROVED_RTI", "paired RTI with software-interrupt frame")
            proof_seq+=1; dynproofs.append({"Proof_ID":f"V04P{proof_seq:05d}","Class":"INTERRUPT_REENTRY","Consumer":f"{st.pbr:02X}:{st.pc:04X}","Producer":"source-proved BRK/COP interrupt frame","Width":"E/M/X/status+PC/PBR","Bank":f"{ent.pbr:02X}","Phase":"V04C source graph","Index_Domain":"N/A","Table_Bytes":"N/A","Admitted_Targets":f"{ent.pbr:02X}:{ent.pc:04X}","Rejected_Values":"asynchronous/unpaired frames","Failure_Rule":"fail closed without exact frame","Evidence":cid}); continue

        # Branches.
        if mn in CONDITIONAL_BRANCHES:
            linear,fail=update_linear_state(st,d,rom)
            if fail: add_boundary(st,d,"STATUS_WIDTH",fail); continue
            target=(next_pc(d)+s8(d.raw[1]))&0xFFFF; decision=branch_decision(st,mn)
            if decision is not False: enqueue(replace(linear,pc=target),cid,"BRANCH_TAKEN","source instruction plus proved/unknown condition")
            if decision is not True: enqueue(linear,cid,"BRANCH_NOT_TAKEN","source instruction plus proved/unknown condition")
            continue
        if mn in {"BRA","BRL"}:
            linear,fail=update_linear_state(st,d,rom)
            if fail: add_boundary(st,d,"STATUS_WIDTH",fail); continue
            target=(next_pc(d)+(s8(d.raw[1]) if mn=="BRA" else s16(u16(d.raw))))&0xFFFF
            enqueue(replace(linear,pc=target),cid,"BRANCH","encoded relative target"); continue

        # Direct/indirect jumps.
        if mn in {"JMP","JML"}:
            linear,fail=update_linear_state(st,d,rom)
            if fail: add_boundary(st,d,"STATUS_WIDTH",fail); continue
            targets=[]; producer=""
            if mode=="ABS_JUMP": targets=[cpu24(st.pbr,u16(d.raw))]; producer="encoded 16-bit target"
            elif mode=="ABSL_JUMP": targets=[u24(d.raw)]; producer="encoded 24-bit target"
            elif mode=="ABS_IND":
                # 65C816 absolute indirect pointer is read from bank 0; target PBR stays current.
                ptr=u16(d.raw); lo=read_rom_value(rom,cpu24(0,ptr),16)
                if lo is not None: targets=[cpu24(st.pbr,lo)]; producer=f"bank-00 ROM pointer ${ptr:04X}"
            elif mode=="ABS_IND_LONG":
                ptr=u16(d.raw); lo=read_rom_value(rom,cpu24(0,ptr),16); bank=read_rom_value(rom,cpu24(0,(ptr+2)&0xFFFF),8)
                if lo is not None and bank is not None: targets=[cpu24(bank,lo)]; producer=f"bank-00 24-bit ROM pointer ${ptr:04X}"
            elif mode=="ABS_X_IND":
                xv=x_values(st)
                if xv is not None:
                    base=u16(d.raw); vals=[]; table=[]
                    for xval in xv:
                        pa=(base+xval)&0xFFFF; tv=read_rom_value(rom,cpu24(st.pbr,pa),16)
                        if tv is None: vals=[]; break
                        vals.append(cpu24(st.pbr,tv)); table.append(f"{st.pbr:02X}:{pa:04X}={tv:04X}")
                    targets=list(dict.fromkeys(vals)); producer=";".join(table)
            if not targets:
                add_boundary(st,d,"DYNAMIC_TARGET","finite indirect target producer/index domain unproved"); continue
            if any(map_rom_addr(t,len(rom)) is None for t in targets):
                add_boundary(st,d,"EXECUTABLE_WRAM","target set includes non-ROM address without a proved executable-WRAM epoch",candidate=";".join(f"{t:06X}" for t in targets)); continue
            proof_seq+=1; dynproofs.append({"Proof_ID":f"V04P{proof_seq:05d}","Class":"DYNAMIC_TARGET" if "IND" in mode else "DIRECT_TARGET","Consumer":f"{st.pbr:02X}:{st.pc:04X}","Producer":producer,"Width":"16/24-bit target","Bank":f"{st.pbr:02X}","Phase":"V04C source graph","Index_Domain":";".join(f"{v:04X}" for v in x_values(st) or ()) if mode=="ABS_X_IND" else "N/A","Table_Bytes":producer if "IND" in mode else "encoded instruction bytes","Admitted_Targets":";".join(f"{(t>>16)&0xFF:02X}:{t&0xFFFF:04X}" for t in targets),"Rejected_Values":"unproved/misaligned/non-ROM values fail closed","Failure_Rule":"no target outside exact finite set","Evidence":cid})
            for t in targets: enqueue(replace(linear,pbr=(t>>16)&0xFF,pc=t&0xFFFF),cid,"SOURCE_PROVED_JUMP","finite source target")
            continue

        # Calls.
        if mn in {"JSR","JSL"}:
            linear,fail=update_linear_state(st,d,rom)
            if fail: add_boundary(st,d,"STATUS_WIDTH",fail); continue
            targets=[]; producer=""; idxdomain="N/A"; tablebytes="encoded instruction bytes"
            if mn=="JSR" and mode=="ABS_JUMP": targets=[cpu24(st.pbr,u16(d.raw))]; producer="encoded absolute call"
            elif mn=="JSL" and mode=="ABSL_JUMP": targets=[u24(d.raw)]; producer="encoded long call"
            elif mn=="JSR" and mode=="ABS_X_IND":
                xv=x_values(st)
                if xv is not None:
                    base=u16(d.raw); vals=[]; tb=[]
                    for xval in xv:
                        pa=(base+xval)&0xFFFF; tv=read_rom_value(rom,cpu24(st.pbr,pa),16)
                        if tv is None: vals=[]; break
                        vals.append(cpu24(st.pbr,tv)); tb.append(f"{st.pbr:02X}:{pa:04X}={tv:04X}")
                    targets=list(dict.fromkeys(vals)); producer="finite X-indexed ROM pointer table"; idxdomain=";".join(f"{v:04X}" for v in xv); tablebytes=";".join(tb)
            if not targets:
                add_boundary(st,d,"DYNAMIC_TARGET","indexed/indirect call lacks finite source-proved index/target producer"); continue
            if any(map_rom_addr(t,len(rom)) is None for t in targets):
                add_boundary(st,d,"EXECUTABLE_WRAM","call target set includes non-ROM address without executable-WRAM epoch proof",candidate=";".join(f"{t:06X}" for t in targets)); continue
            retkind="RET16" if mn=="JSR" else "RET24"; retwidth=2 if mn=="JSR" else 3
            raw_ret=((st.pbr<<16)|((next_pc(d)-1)&0xFFFF)) if mn=="JSL" else ((next_pc(d)-1)&0xFFFF)
            ret=StackEntry(retkind,retwidth,(raw_ret,),pbr=st.pbr,pc=next_pc(d))
            pushed=push(linear,ret)
            if pushed is None: add_boundary(st,d,"RETURN","symbolic call-stack depth exceeded"); continue
            proof_seq+=1; dynproofs.append({"Proof_ID":f"V04P{proof_seq:05d}","Class":"DYNAMIC_CALL" if mode=="ABS_X_IND" else "DIRECT_CALL","Consumer":f"{st.pbr:02X}:{st.pc:04X}","Producer":producer,"Width":"16-bit" if mn=="JSR" else "24-bit","Bank":f"{st.pbr:02X}","Phase":"V04C source graph","Index_Domain":idxdomain,"Table_Bytes":tablebytes,"Admitted_Targets":";".join(f"{(t>>16)&0xFF:02X}:{t&0xFFFF:04X}" for t in targets),"Rejected_Values":"all values outside exact producer domain","Failure_Rule":"fail closed if table/index proof changes","Evidence":cid})
            for t in targets: enqueue(replace(pushed,pbr=(t>>16)&0xFF,pc=t&0xFFFF),cid,"SOURCE_PROVED_CALL","call target plus logical return frame")
            continue

        # Software interrupt: exact vector plus exact logical frame.
        if mn in {"BRK","COP"}:
            linear,fail=update_linear_state(st,d,rom)
            if fail: add_boundary(st,d,"STATUS_WIDTH",fail); continue
            frame=StackEntry("INT_FRAME",3 if st.e else 4,(),st.e,st.m,st.x,st.c,st.n,st.z,st.v,st.pbr,next_pc(d))
            pushed=push(linear,frame)
            if pushed is None: add_boundary(st,d,"INTERRUPT_REENTRY","symbolic stack depth exceeded"); continue
            vn=("emulation_irq_brk" if mn=="BRK" else "emulation_cop") if st.e else ("native_brk" if mn=="BRK" else "native_cop")
            target=int(profile["vectors"][vn],16)
            enqueue(replace(pushed,pbr=0,pc=target),cid,"SOFTWARE_INTERRUPT",f"exact {vn} vector and source-proved frame"); continue

        linear,fail=update_linear_state(st,d,rom)
        if fail:
            add_boundary(st,d,"STATUS_WIDTH",fail); continue
        enqueue(linear,cid,"FALLTHROUGH","source-proved sequential successor")

    # Disposition every V03 frontier and candidate root explicitly.
    proved_cores={(int(r["PBR"],16),int(r["PC"],16),int(r["E"]),int(r["M"]),int(r["X"])) for r in contexts}
    closed_sites={(int(p["Consumer"].split(':')[0],16),int(p["Consumer"].split(':')[1],16),p["Class"]) for p in dynproofs if ':' in p["Consumer"]}
    boundary_sites={(int(b["Context"].split(':')[0],16),int(b["Context"].split(':')[1],16),b["Class"]) for b in boundaries if b["Context"]}
    fd=[]
    for r in v03_frontiers:
        core=context_core_from_v03(r["Context"]); cls=r["Class"]
        physical=r["Instruction"].split('$')[-1] if '$' in r["Instruction"] else ""
        if r["Level"]=="CANDIDATE":
            disp="REJECTED_V03_CANDIDATE"
            reason="V03 candidate path is not an admitted V04 source-proof root/edge."
            if core in proved_cores:
                disp="SUPERSEDED_BY_SOURCE_PROVED_CONTEXT"; reason="Same PBR:PC:E:M:X is independently reached by V04 source proof; V03 speculative path itself remains rejected."
        else:
            # Match by site and broad class; RETURN proofs use class RETURN, dynamic call proofs DYNAMIC_CALL.
            site=(core[0],core[1])
            if cls=="RETURN" and any(a==site[0] and b==site[1] and c=="RETURN" for a,b,c in closed_sites): disp="CLOSED_SOURCE_PROVED"; reason="paired logical call frame proves exact return"
            elif cls=="STATUS_WIDTH" and core in proved_cores and not any(a==site[0] and b==site[1] and c=="STATUS_WIDTH" for a,b,c in boundary_sites): disp="CLOSED_SOURCE_PROVED"; reason="stack/status producer proves continuation width"
            elif cls=="DYNAMIC_TARGET" and any(a==site[0] and b==site[1] and c in {"DYNAMIC_CALL","DYNAMIC_TARGET"} for a,b,c in closed_sites): disp="CLOSED_SOURCE_PROVED"; reason="finite producer/index/table proof recorded"
            elif cls=="INTERRUPT_REENTRY" and any(a==site[0] and b==site[1] and c=="INTERRUPT_REENTRY" for a,b,c in closed_sites): disp="CLOSED_SOURCE_PROVED"; reason="paired interrupt frame proves re-entry"
            else: disp="FAIL_CLOSED_UNSUPPORTED"; reason="source-proved entry exists but required dynamic/re-entry producer remains unproved; static continuation is rejected"
        fd.append({"V03_Frontier_ID":r["Frontier_ID"],"V03_Level":r["Level"],"V03_Class":cls,"V03_Context":r["Context"],"Physical":physical,"Disposition":disp,"V04_Proof_or_Boundary":"","Reason":reason,"Failure_Rule":"candidate never promoted; unsupported source edge stops immediately"})

    rd=[]
    for r in v03_root_rows:
        core=(int(r["PBR"],16),int(r["PC"],16),int(r["E"]),int(r["M"]),int(r["X"]))
        if r["Level"]=="PROVED": disp="PRESERVED_SOURCE_ROOT" if core in proved_cores else "FAIL_CLOSED_ROOT"
        else: disp="SUPERSEDED_BY_SOURCE_PROOF" if core in proved_cores else "REJECTED_CANDIDATE_ROOT"
        rd.append({"V03_Root_ID":r["Root_ID"],"Root_Type":r["Root_Type"],"V03_Level":r["Level"],"Context":f"{r['PBR']}:{r['PC']}:E{r['E']}M{r['M']}X{r['X']}","Disposition":disp,"Reason":"V04 admits only exact source-root/direct-flow paths; speculative V03 roots do not create authority."})

    # Candidate conflict rows are dispositioned against actual admitted ownership.
    admitted_starts=defaultdict(set)
    for r in contexts: admitted_starts[int(r["Physical"],16)].add(int(r["Length"]))
    cd=[]
    for r in v03_conflicts:
        off=int(r["Physical"],16); lens=admitted_starts.get(off,set())
        if len(lens)>1: disp="BLOCKER_PROVED_AMBIGUITY"
        elif lens: disp="RESOLVED_BY_SOURCE_CONTEXT"
        else: disp="CANDIDATE_AMBIGUITY_NOT_ADMITTED"
        cd.append({**r,"V04_Disposition":disp,"V04_Admitted_Lengths":",".join(map(str,sorted(lens))),"Notes":"Any proved ambiguity is a release blocker; candidate ambiguity remains non-authoritative."})

    # APUIO disposition from exact V04 memory effective-address facts.
    access_by_phys=defaultdict(list)
    for mrow in mem:
        if mrow["Effective_Addresses"]!="UNPROVED": access_by_phys[mrow["Physical"]].append(mrow)
    ad=[]
    for r in v03_apuio:
        reg=int(r["Register"],16); hits=[]
        for mrow in access_by_phys.get(r["Physical"],[]):
            for a in str(mrow["Effective_Addresses"]).split(';'):
                if a and int(a,16)&0xFFFF==reg and is_mmio_addr(int(a,16)): hits.append(a)
        claim="SOURCE_PROVED_MMIO" if hits else ("REJECTED_V03_CANDIDATE" if not access_by_phys.get(r["Physical"]) else "BANK_OR_INDEX_UNPROVED")
        ad.append({"Candidate_ID":r["Candidate_ID"],"Physical":r["Physical"],"Canonical_CPU":r["Canonical_CPU"],"Register":r["Register"],"V03_Claim":r["Claim"],"V04_Disposition":claim,"Effective_Addresses":";".join(sorted(set(hits))),"Notes":"Only source-proved path+effective-bank facts may establish MMIO."})

    # Ownership: retain the complete V03 classification as predecessor authority,
    # then promote only bytes owned by admitted V04 source contexts.  This keeps
    # the full-ROM candidate queue visible rather than silently demoting candidate
    # bytes to unknown merely because V04 did not revisit them.
    classes=["UNRESOLVED"]*ROM_SIZE
    for row in v03_ownership:
        lo=int(row["Physical_Start"],16); hi=int(row["Physical_End"],16); cls=row["Classification"]
        if not (0<=lo<=hi<ROM_SIZE): raise ValueError(f"invalid V03 ownership range {row}")
        for off in range(lo,hi+1): classes[off]=cls
    for off,items in role_bytes.items():
        if not (0x7FC0<=off<=0x7FFF): classes[off]="PROVED_CODE"
    own=[]; start=0
    for i in range(1,ROM_SIZE+1):
        if i==ROM_SIZE or classes[i]!=classes[start]:
            cls=classes[start]
            if cls=="PROVED_CODE": conf="SOURCE_PROVED"; prod="V03C/V04C admitted source graph"; proof="BYTE-V04C-CONTROL"; phase="V04C"
            elif cls=="CANDIDATE": conf="CANDIDATE_ONLY"; prod="V03C decode/candidate graph retained without promotion"; proof="BYTE-V03C-CANDIDATE"; phase="V03C_CANDIDATE"
            elif cls=="HEADER_VECTOR": conf="SOURCE_PROVED"; prod="V01C exact header/vector proof"; proof="BYTE-V01C-HEADER-VECTORS"; phase="V01C"
            else: conf="EXPLICIT_UNKNOWN"; prod="none"; proof="PENDING"; phase="OPEN"
            own.append({"Physical_Start":f"{start:06X}","Physical_End":f"{i-1:06X}","Classification":cls,"Confidence":conf,"Producer":prod,"Consumer":"V05C static lowering" if cls=="PROVED_CODE" else "later proof/data classification","Proof_ID":proof,"Phase":phase,"Notes":"Candidate remains non-authoritative; unresolved is not inferred to be data."})
            start=i
    totals=Counter(classes)

    # Active frontier ledger contains only source-proved fail-closed boundaries;
    # V03 candidate frontier rows are dispositioned, not carried as runtime roots.
    ledger=[]
    for b in boundaries:
        ledger.append({"Frontier_ID":b["Boundary_ID"],"Milestone":"V04C","Predecessor_SHA256":predecessor_commit,"Context":b["Context"],"Expected_Bytes":b["Instruction"],"Master_Clock":"NOT_RUNTIME_TRAVERSED","Class":b["Class"],"Stop_Reason":b["Reason"],"Authority_Needed":"source proof in a later milestone or explicit unsupported route","Proof_ID":"FAIL_CLOSED_V04C","Regression_Test":"V04C-FLOW-001","Status":"FAIL_CLOSED","Successor_Package":"","Notes":b["Failure_Rule"]})

    bcount=Counter(b["Class"] for b in boundaries); dispcount=Counter(r["Disposition"] for r in fd)
    apcount=Counter(r["V04_Disposition"] for r in ad); rootdisp=Counter(r["Disposition"] for r in rd)
    summary={
        "schema":1,"milestone":"04C","authority":"source-proved dynamic flow/control closure with explicit fail-closed unsupported boundaries; still zero production execution authority",
        "rom_sha256":ROM_SHA256,"rom_size":ROM_SIZE,"predecessor_v03c_commit":predecessor_commit,
        "admitted_context_rows":len(contexts),"admitted_unique_context_keys":len({(r['PBR'],r['PC'],r['E'],r['M'],r['X']) for r in contexts}),
        "admitted_edge_rows":len(edges),"dynamic_proof_rows":len(dynproofs),"dynamic_proofs_by_class":dict(sorted(Counter(r['Class'] for r in dynproofs).items())),
        "fail_closed_boundary_rows":len(boundaries),"fail_closed_by_class":dict(sorted(bcount.items())),
        "v03_frontiers_dispositioned":len(fd),"v03_frontier_dispositions":dict(sorted(dispcount.items())),
        "v03_roots_dispositioned":len(rd),"v03_root_dispositions":dict(sorted(rootdisp.items())),
        "v03_conflicts_dispositioned":len(cd),"proved_conflict_blockers":sum(r['V04_Disposition']=='BLOCKER_PROVED_AMBIGUITY' for r in cd),
        "apuio_candidates_dispositioned":len(ad),"apuio_dispositions":dict(sorted(apcount.items())),
        "memory_access_rows":len(mem),"source_proved_mmio_rows":sum(bool(r['MMIO']) and r['MMIO']!='UNPROVED' for r in mem),
        "source_proved_wram_access_rows":sum(bool(r['WRAM']) and r['WRAM']!='UNPROVED' for r in mem),
        "executable_wram_epochs":0,"executable_wram_policy":"No admitted V04 control target enters WRAM; any non-ROM target fails closed until producer/copy/epoch proof exists.",
        "stack_tracking_window_bytes":MAX_TRACKED_STACK_BYTES,"stack_window_policy":"Exact top-of-stack bytes are retained. Older caller state is deliberately truncated; any pull/return crossing that unknown base fails closed.",
        "ownership_bytes":dict(sorted(totals.items())),"ownership_range_rows":len(own),
        "trace_promotions":0,"oracle_promotions":0,"runtime_decoder_added":False,
        "gate":"Every admitted successor is direct/source-proved, finite-table-proved, paired-return/re-entry-proved, or stops at an explicit fail-closed boundary."
    }
    return V04Result(summary,contexts,edges,boundaries,dynproofs,mem,fd,rd,cd,ad,own,ledger)


def write_csv(path:Path, rows:list[dict], fields:list[str]):
    path.parent.mkdir(parents=True,exist_ok=True)
    with path.open('w',encoding='utf-8',newline='') as f:
        w=csv.DictWriter(f,fieldnames=fields,lineterminator='\n'); w.writeheader(); w.writerows(rows)


def write_result(res:V04Result, root:Path)->list[str]:
    rels=[
        'docs/V04C-control-summary.json','docs/V04C-contexts.csv','docs/V04C-edges.csv','docs/V04C-fail-closed-boundaries.csv','docs/V04C-dynamic-proofs.csv','docs/V04C-memory-accesses.csv','docs/V04C-v03-frontier-dispositions.csv','docs/V04C-v03-root-dispositions.csv','docs/V04C-v03-conflict-dispositions.csv','docs/V04C-apuio-dispositions.csv','config/byte-ownership.csv','config/frontier-ledger.csv'
    ]
    (root/'docs').mkdir(parents=True,exist_ok=True); (root/'config').mkdir(parents=True,exist_ok=True)
    (root/rels[0]).write_text(json.dumps(res.summary,indent=2,sort_keys=True)+'\n',encoding='utf-8',newline='\n')
    write_csv(root/rels[1],res.contexts,['Context_ID','PBR','PC','E','M','X','Carry','N','Z','V','DBR','D','A16','A8','XR','YR','A_SP_Rel','X_SP_Rel','Stack_Depth','Stack_Bytes','Stack_Proof','Root','Physical','Opcode','Mnemonic','Mode','Length','Bytes'])
    write_csv(root/rels[2],res.edges,['From','Edge_Kind','To','Reason'])
    write_csv(root/rels[3],res.boundaries,['Boundary_ID','Context','Physical','Instruction','Class','Disposition','Reason','Candidate_Target','Stack_Bytes','Stack_Proof','A_SP_Rel','X_SP_Rel','Failure_Rule'])
    write_csv(root/rels[4],res.dynamic_proofs,['Proof_ID','Class','Consumer','Producer','Width','Bank','Phase','Index_Domain','Table_Bytes','Admitted_Targets','Rejected_Values','Failure_Rule','Evidence'])
    write_csv(root/rels[5],res.memory_accesses,['Access_ID','Context','Physical','Instruction','Access','Effective_Addresses','Address_Count','DBR','MMIO','WRAM','Notes'])
    write_csv(root/rels[6],res.v03_frontier_dispositions,['V03_Frontier_ID','V03_Level','V03_Class','V03_Context','Physical','Disposition','V04_Proof_or_Boundary','Reason','Failure_Rule'])
    write_csv(root/rels[7],res.v03_root_dispositions,['V03_Root_ID','Root_Type','V03_Level','Context','Disposition','Reason'])
    write_csv(root/rels[8],res.v03_conflict_dispositions,['Conflict_ID','Severity','Type','Physical','Details','V04_Disposition','V04_Admitted_Lengths','Notes'])
    write_csv(root/rels[9],res.apuio_dispositions,['Candidate_ID','Physical','Canonical_CPU','Register','V03_Claim','V04_Disposition','Effective_Addresses','Notes'])
    write_csv(root/rels[10],res.ownership,['Physical_Start','Physical_End','Classification','Confidence','Producer','Consumer','Proof_ID','Phase','Notes'])
    write_csv(root/rels[11],res.frontier_ledger,['Frontier_ID','Milestone','Predecessor_SHA256','Context','Expected_Bytes','Master_Clock','Class','Stop_Reason','Authority_Needed','Proof_ID','Regression_Test','Status','Successor_Package','Notes'])
    return rels


def load_csv(path:Path)->list[dict]:
    with path.open(encoding='utf-8',newline='') as f:return list(csv.DictReader(f))
