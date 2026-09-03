"""W65C816 addressing primitives for the V02C offline decoder.

The functions return deterministic effective-address facts only.  They do not
perform SNES bus mapping or master-clock timing; those are later milestones.
"""
from __future__ import annotations

from dataclasses import dataclass
from .semantics import CPUState, Memory


def u16(v: int) -> int: return v & 0xFFFF
def u24(v: int) -> int: return v & 0xFFFFFF


@dataclass(frozen=True)
class AddressResult:
    effective: int | None
    pointer_reads: tuple[int, ...] = ()
    page_crossed: bool = False
    direct_low_nonzero: bool = False


def program_address(s: CPUState, addr16: int) -> int:
    return ((s.pbr & 0xFF) << 16) | u16(addr16)


def data_address(s: CPUState, addr16: int) -> int:
    return ((s.dbr & 0xFF) << 16) | u16(addr16)


def direct_address(s: CPUState, offset: int, allow_emulation_page_wrap: bool = True) -> int:
    """Bank-0 direct address including the 816 emulation-page rule."""
    if allow_emulation_page_wrap and s.e and (s.d & 0xFF) == 0:
        return (s.d & 0xFF00) | (offset & 0xFF)
    return u16(s.d + offset)


def direct_indirect_word(s: CPUState, mem: Memory, offset: int, *, indexed_x_bug: bool = False) -> tuple[int, tuple[int, int]]:
    a0 = direct_address(s, offset)
    a1 = direct_address(s, offset + 1)
    if indexed_x_bug and s.e and (s.d & 0xFF) != 0 and (a1 & 0xFF) == 0:
        a1 = u16(a1 - 0x100)
    lo = mem.read8(a0)
    hi = mem.read8(a1)
    return lo | (hi << 8), (a0, a1)


def direct_indirect_long(s: CPUState, mem: Memory, offset: int) -> tuple[int, tuple[int, int, int]]:
    # Long direct-indirect does not use the emulation-page shortcut.
    addrs = tuple(direct_address(s, offset + i, False) for i in range(3))
    b0, b1, b2 = (mem.read8(a) for a in addrs)
    return b0 | (b1 << 8) | (b2 << 16), addrs



def pei_pointer_word(s: CPUState, mem: Memory, offset: int) -> tuple[int, tuple[int, int]]:
    """PEI special direct-word read: second byte increments linearly in bank 0.

    Unlike 16-bit (d) pointers in emulation/DL=0, PEI is documented to cross
    from $00FF to $0100 (or DHFF to the next page) rather than page-wrap.
    """
    a0 = direct_address(s, offset)
    a1 = u16(a0 + 1)
    lo, hi = mem.read8(a0), mem.read8(a1)
    return lo | (hi << 8), (a0, a1)


def resolve(mode: str, s: CPUState, operand: int, mem: Memory | None = None, *, is_write: bool = False) -> AddressResult:
    mem = mem or Memory()
    dp_penalty = bool(s.d & 0xFF)

    if mode in {"IMP", "ACC", "IMM8", "IMM16", "IMM_M", "IMM_X", "SIG8", "BLOCK"}:
        return AddressResult(None)
    if mode == "REL8":
        signed = operand if operand < 0x80 else operand - 0x100
        target = u16(s.pc + signed)
        return AddressResult(program_address(s, target), page_crossed=((s.pc ^ target) & 0xFF00) != 0)
    if mode == "REL16":
        signed = operand if operand < 0x8000 else operand - 0x10000
        return AddressResult(program_address(s, u16(s.pc + signed)))
    if mode == "ABS":
        return AddressResult(data_address(s, operand))
    if mode == "ABS_JUMP":
        return AddressResult(program_address(s, operand))
    if mode == "ABS_X":
        base = data_address(s, operand)
        eff = u24(base + s.x)
        return AddressResult(eff, page_crossed=((base ^ eff) & 0xFF00) != 0)
    if mode == "ABS_Y":
        base = data_address(s, operand)
        eff = u24(base + s.y)
        return AddressResult(eff, page_crossed=((base ^ eff) & 0xFF00) != 0)
    if mode == "ABS_LONG":
        return AddressResult(u24(operand))
    if mode == "ABS_LONG_X":
        return AddressResult(u24(operand + s.x))
    if mode == "ABSL_JUMP":
        return AddressResult(u24(operand))
    if mode == "DP":
        return AddressResult(direct_address(s, operand), direct_low_nonzero=dp_penalty)
    if mode == "DP_X":
        return AddressResult(direct_address(s, operand + s.x), direct_low_nonzero=dp_penalty)
    if mode == "DP_Y":
        return AddressResult(direct_address(s, operand + s.y), direct_low_nonzero=dp_penalty)
    if mode == "DP_IND":
        ptr, reads = direct_indirect_word(s, mem, operand)
        return AddressResult(data_address(s, ptr), reads, direct_low_nonzero=dp_penalty)
    if mode == "DP_X_IND":
        ptr, reads = direct_indirect_word(s, mem, operand + s.x, indexed_x_bug=True)
        return AddressResult(data_address(s, ptr), reads, direct_low_nonzero=dp_penalty)
    if mode == "DP_IND_Y":
        ptr, reads = direct_indirect_word(s, mem, operand)
        base = data_address(s, ptr)
        eff = u24(base + s.y)
        return AddressResult(eff, reads, ((base ^ eff) & 0xFF00) != 0, dp_penalty)
    if mode == "DP_IND_LONG":
        ptr, reads = direct_indirect_long(s, mem, operand)
        return AddressResult(ptr, reads, direct_low_nonzero=dp_penalty)
    if mode == "DP_IND_LONG_Y":
        ptr, reads = direct_indirect_long(s, mem, operand)
        return AddressResult(u24(ptr + s.y), reads, direct_low_nonzero=dp_penalty)
    if mode == "STACK_REL":
        return AddressResult(u16(s.s + (operand & 0xFF)))
    if mode == "STACK_REL_IND_Y":
        base = u16(s.s + (operand & 0xFF))
        r0, r1 = base, u16(base + 1)
        lo, hi = mem.read8(r0), mem.read8(r1)
        ptr = lo | (hi << 8)
        return AddressResult(u24(data_address(s, ptr) + s.y), (r0, r1))
    if mode == "ABS_IND":
        base = u16(operand)
        r0, r1 = base, u16(base + 1)
        lo, hi = mem.read8(r0), mem.read8(r1)
        return AddressResult(program_address(s, lo | (hi << 8)), (r0, r1))
    if mode == "ABS_IND_LONG":
        base = u16(operand)
        reads = (base, u16(base + 1), u16(base + 2))
        b0, b1, b2 = (mem.read8(a) for a in reads)
        return AddressResult(b0 | (b1 << 8) | (b2 << 16), reads)
    if mode == "ABS_X_IND":
        base = u16(operand + s.x)
        r0 = program_address(s, base)
        r1 = program_address(s, u16(base + 1))
        lo, hi = mem.read8(r0), mem.read8(r1)
        return AddressResult(program_address(s, lo | (hi << 8)), (r0, r1))
    raise KeyError(mode)
