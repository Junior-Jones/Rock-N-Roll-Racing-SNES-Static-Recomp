"""Pure W65C816 semantic primitives used by the V02C offline analyser/tests.

These routines deliberately operate on already-decoded operations.  They do not
fetch opcodes and are never a production runtime decoder.  Address resolution is
kept in addressing.py and bus timing is intentionally deferred to later C-line
milestones.
"""
from __future__ import annotations

from dataclasses import dataclass, field
from typing import Iterable

C = 0x01
Z = 0x02
I = 0x04
D = 0x08
XFLAG = 0x10
MFLAG = 0x20
V = 0x40
N = 0x80

INTERRUPT_VECTOR_ADDRESSES = {
    0: {"COP":0xFFE4,"BRK":0xFFE6,"ABORT":0xFFE8,"NMI":0xFFEA,"IRQ":0xFFEE},
    1: {"COP":0xFFF4,"ABORT":0xFFF8,"NMI":0xFFFA,"RESET":0xFFFC,"IRQ":0xFFFE,"BRK":0xFFFE},
}

def interrupt_vector_address(kind: str, e: int) -> int:
    try: return INTERRUPT_VECTOR_ADDRESSES[1 if e else 0][kind.upper()]
    except KeyError: raise KeyError((kind,e)) from None



@dataclass
class CPUState:
    a: int = 0
    x: int = 0
    y: int = 0
    d: int = 0
    s: int = 0x01FF
    dbr: int = 0
    pbr: int = 0
    pc: int = 0
    p: int = I | MFLAG | XFLAG
    e: int = 1
    waiting: bool = False
    stopped: bool = False

    def clone(self) -> "CPUState":
        return CPUState(**vars(self))

    @property
    def m8(self) -> bool:
        return bool(self.e or (self.p & MFLAG))

    @property
    def x8(self) -> bool:
        return bool(self.e or (self.p & XFLAG))

    def normalize(self) -> None:
        self.a &= 0xFFFF
        self.x &= 0xFFFF
        self.y &= 0xFFFF
        self.d &= 0xFFFF
        self.s &= 0xFFFF
        self.dbr &= 0xFF
        self.pbr &= 0xFF
        self.pc &= 0xFFFF
        self.p &= 0xFF
        self.e = 1 if self.e else 0
        if self.e:
            self.p |= MFLAG | XFLAG
            self.s = 0x0100 | (self.s & 0xFF)
        if self.p & XFLAG:
            self.x &= 0xFF
            self.y &= 0xFF


@dataclass
class Memory:
    """Sparse 24-bit byte memory with an access log for semantic tests."""

    bytes: dict[int, int] = field(default_factory=dict)
    accesses: list[tuple[str, int, int]] = field(default_factory=list)

    def read8(self, addr: int) -> int:
        addr &= 0xFFFFFF
        value = self.bytes.get(addr, 0) & 0xFF
        self.accesses.append(("R", addr, value))
        return value

    def write8(self, addr: int, value: int) -> None:
        addr &= 0xFFFFFF
        value &= 0xFF
        self.bytes[addr] = value
        self.accesses.append(("W", addr, value))

    def set_bytes(self, start: int, values: Iterable[int]) -> None:
        for i, value in enumerate(values):
            self.bytes[(start + i) & 0xFFFFFF] = value & 0xFF


LOGIC_MNEMONICS = {"AND", "EOR", "ORA"}
COMPARE_MNEMONICS = {"CMP", "CPX", "CPY"}
SHIFT_MNEMONICS = {"ASL", "LSR", "ROL", "ROR"}
BRANCH_MNEMONICS = {"BCC", "BCS", "BEQ", "BMI", "BNE", "BPL", "BRA", "BVC", "BVS", "BRL"}
FLAG_MNEMONICS = {"CLC", "CLD", "CLI", "CLV", "SEC", "SED", "SEI", "REP", "SEP"}
LOAD_STORE_MNEMONICS = {"LDA", "LDX", "LDY", "STA", "STX", "STY", "STZ"}
TRANSFER_MNEMONICS = {"TAX", "TAY", "TCD", "TCS", "TDC", "TSC", "TSX", "TXA", "TXS", "TXY", "TYA", "TYX", "XBA", "XCE"}
STACK_MNEMONICS = {"PEA", "PEI", "PER", "PHA", "PHB", "PHD", "PHK", "PHP", "PHX", "PHY", "PLA", "PLB", "PLD", "PLP", "PLX", "PLY"}
CONTROL_MNEMONICS = {"JML", "JMP", "JSL", "JSR", "RTI", "RTL", "RTS", "BRK", "COP"}
MISC_MNEMONICS = {"MVN", "MVP", "NOP", "WDM", "WAI", "STP"}
RMW_MNEMONICS = {"DEC", "INC", "TRB", "TSB"} | SHIFT_MNEMONICS

SUPPORTED_MNEMONICS = (
    {"ADC", "SBC", "BIT", "DEC", "DEX", "DEY", "INC", "INX", "INY", "TRB", "TSB"}
    | LOGIC_MNEMONICS
    | COMPARE_MNEMONICS
    | SHIFT_MNEMONICS
    | BRANCH_MNEMONICS
    | FLAG_MNEMONICS
    | LOAD_STORE_MNEMONICS
    | TRANSFER_MNEMONICS
    | STACK_MNEMONICS
    | CONTROL_MNEMONICS
    | MISC_MNEMONICS
)


def semantic_family(mnemonic: str) -> str:
    if mnemonic in {"ADC", "SBC"}:
        return "arithmetic"
    if mnemonic in LOGIC_MNEMONICS:
        return "logic"
    if mnemonic in COMPARE_MNEMONICS:
        return "compare"
    if mnemonic in SHIFT_MNEMONICS:
        return "shift_rotate"
    if mnemonic in {"BIT", "TRB", "TSB"}:
        return "bit_test_modify"
    if mnemonic in {"DEC", "DEX", "DEY", "INC", "INX", "INY"}:
        return "inc_dec"
    if mnemonic in BRANCH_MNEMONICS:
        return "branch"
    if mnemonic in FLAG_MNEMONICS:
        return "flags"
    if mnemonic in LOAD_STORE_MNEMONICS:
        return "load_store"
    if mnemonic in TRANSFER_MNEMONICS:
        return "transfer"
    if mnemonic in STACK_MNEMONICS:
        return "stack"
    if mnemonic in CONTROL_MNEMONICS:
        return "control_interrupt"
    if mnemonic in {"MVN", "MVP"}:
        return "block_move"
    if mnemonic in {"NOP", "WDM", "WAI", "STP"}:
        return "misc"
    raise KeyError(mnemonic)


class SemanticEngine:
    def __init__(self, state: CPUState | None = None, memory: Memory | None = None):
        self.s = state or CPUState()
        self.mem = memory or Memory()
        self.s.normalize()

    def flag(self, mask: int) -> bool:
        return bool(self.s.p & mask)

    def _set_flag(self, mask: int, value: bool) -> None:
        self.s.p = (self.s.p | mask) if value else (self.s.p & ~mask)
        self.s.p &= 0xFF

    def _set_nz(self, value: int, bits: int) -> None:
        mask = (1 << bits) - 1
        value &= mask
        self._set_flag(Z, value == 0)
        self._set_flag(N, bool(value & (1 << (bits - 1))))

    def _write_reg_width(self, name: str, value: int, bits: int) -> None:
        old = getattr(self.s, name)
        if bits == 8:
            # A keeps its hidden B byte when M=1. X/Y do not: entering or
            # operating in 8-bit index mode guarantees their high bytes are 0.
            value = ((old & 0xFF00) | (value & 0xFF)) if name == "a" else (value & 0xFF)
            self._set_nz(value & 0xFF, 8)
        else:
            value &= 0xFFFF
            self._set_nz(value, 16)
        setattr(self.s, name, value)

    @staticmethod
    def _decimal_add_digits(a: int, b: int, carry_in: int, bits: int) -> tuple[int, int, int]:
        """Digit-oriented BCD result plus pre-final-correction value for V."""
        lower = 0
        carry = 1 if carry_in else 0
        top_shift = bits - 4
        pre_final = 0
        for shift in range(0, bits, 4):
            raw = ((a >> shift) & 0xF) + ((b >> shift) & 0xF) + carry
            if shift == top_shift:
                pre_final = lower | (raw << shift)
            adjusted = raw + 6 if raw > 9 else raw
            carry = 1 if adjusted > 0xF else 0
            digit = adjusted & 0xF
            if shift != top_shift:
                lower |= digit << shift
            else:
                lower |= digit << shift
        return lower & ((1 << bits) - 1), carry, pre_final

    @staticmethod
    def _decimal_sub_digits(a: int, b: int, carry_in: int, bits: int) -> tuple[int, int, int]:
        lower = 0
        borrow = 0 if carry_in else 1
        top_shift = bits - 4
        pre_final = 0
        for shift in range(0, bits, 4):
            raw = ((a >> shift) & 0xF) - ((b >> shift) & 0xF) - borrow
            if shift == top_shift:
                # Preserve the lower corrected digits but leave the top digit
                # uncorrected, matching the 816's V evaluation point.
                pre_final = lower | ((raw & 0x1F) << shift)
            if raw < 0:
                adjusted = raw - 6
                borrow = 1
            else:
                adjusted = raw
                borrow = 0
            lower |= (adjusted & 0xF) << shift
        return lower & ((1 << bits) - 1), (0 if borrow else 1), pre_final

    def adc(self, value: int, bits: int) -> int:
        mask = (1 << bits) - 1
        sign = 1 << (bits - 1)
        a = self.s.a & mask
        b = value & mask
        cin = 1 if self.flag(C) else 0
        if self.flag(D):
            result, carry, overflow_probe = self._decimal_add_digits(a, b, cin, bits)
        else:
            wide = a + b + cin
            result, carry, overflow_probe = wide & mask, int(wide > mask), wide
        self._set_flag(V, bool((~(a ^ b) & (a ^ overflow_probe) & sign) & mask))
        self._set_flag(C, bool(carry))
        if bits == 8:
            self.s.a = (self.s.a & 0xFF00) | result
        else:
            self.s.a = result
        self._set_nz(result, bits)
        return result

    def sbc(self, value: int, bits: int) -> int:
        mask = (1 << bits) - 1
        sign = 1 << (bits - 1)
        a = self.s.a & mask
        b = value & mask
        cin = 1 if self.flag(C) else 0
        if self.flag(D):
            result, carry, overflow_probe = self._decimal_sub_digits(a, b, cin, bits)
        else:
            signed_wide = a - b - (1 - cin)
            result = signed_wide & mask
            carry = int(signed_wide >= 0)
            overflow_probe = result
        self._set_flag(V, bool((a ^ b) & (a ^ overflow_probe) & sign))
        self._set_flag(C, bool(carry))
        if bits == 8:
            self.s.a = (self.s.a & 0xFF00) | result
        else:
            self.s.a = result
        self._set_nz(result, bits)
        return result

    def logic(self, mnemonic: str, value: int, bits: int) -> int:
        mask = (1 << bits) - 1
        a = self.s.a & mask
        if mnemonic == "AND": result = a & value
        elif mnemonic == "EOR": result = a ^ value
        elif mnemonic == "ORA": result = a | value
        else: raise KeyError(mnemonic)
        result &= mask
        if bits == 8:
            self.s.a = (self.s.a & 0xFF00) | result
        else:
            self.s.a = result
        self._set_nz(result, bits)
        return result

    def compare(self, reg_value: int, value: int, bits: int) -> int:
        mask = (1 << bits) - 1
        lhs, rhs = reg_value & mask, value & mask
        result = (lhs - rhs) & mask
        self._set_flag(C, lhs >= rhs)
        self._set_nz(result, bits)
        return result

    def shift(self, mnemonic: str, value: int, bits: int) -> int:
        mask = (1 << bits) - 1
        sign = 1 << (bits - 1)
        value &= mask
        cin = 1 if self.flag(C) else 0
        if mnemonic == "ASL":
            self._set_flag(C, bool(value & sign)); result = (value << 1) & mask
        elif mnemonic == "LSR":
            self._set_flag(C, bool(value & 1)); result = value >> 1
        elif mnemonic == "ROL":
            self._set_flag(C, bool(value & sign)); result = ((value << 1) | cin) & mask
        elif mnemonic == "ROR":
            self._set_flag(C, bool(value & 1)); result = (value >> 1) | (cin << (bits - 1))
        else:
            raise KeyError(mnemonic)
        self._set_nz(result, bits)
        return result

    def bit(self, value: int, bits: int, immediate: bool) -> None:
        mask = (1 << bits) - 1
        a = self.s.a & mask
        value &= mask
        self._set_flag(Z, (a & value) == 0)
        if not immediate:
            self._set_flag(N, bool(value & (1 << (bits - 1))))
            self._set_flag(V, bool(value & (1 << (bits - 2))))

    def tsb(self, value: int, bits: int) -> int:
        mask = (1 << bits) - 1
        self._set_flag(Z, ((self.s.a & mask) & (value & mask)) == 0)
        return (value | self.s.a) & mask

    def trb(self, value: int, bits: int) -> int:
        mask = (1 << bits) - 1
        self._set_flag(Z, ((self.s.a & mask) & (value & mask)) == 0)
        return (value & ~self.s.a) & mask

    def incdec_value(self, value: int, delta: int, bits: int) -> int:
        result = (value + delta) & ((1 << bits) - 1)
        self._set_nz(result, bits)
        return result

    def load(self, reg: str, value: int, bits: int) -> None:
        self._write_reg_width(reg, value, bits)

    def store_value(self, reg: str | None, bits: int) -> int:
        value = 0 if reg is None else getattr(self.s, reg)
        return value & ((1 << bits) - 1)

    def branch8(self, offset: int, take: bool) -> int:
        if take:
            signed = offset if offset < 0x80 else offset - 0x100
            self.s.pc = (self.s.pc + signed) & 0xFFFF
        return self.s.pc

    def branch16(self, offset: int) -> int:
        signed = offset if offset < 0x8000 else offset - 0x10000
        self.s.pc = (self.s.pc + signed) & 0xFFFF
        return self.s.pc


    def branch_condition(self, mnemonic: str) -> bool:
        table = {
            "BCC": not self.flag(C), "BCS": self.flag(C), "BEQ": self.flag(Z),
            "BMI": self.flag(N), "BNE": not self.flag(Z), "BPL": not self.flag(N),
            "BVC": not self.flag(V), "BVS": self.flag(V), "BRA": True, "BRL": True,
        }
        try: return bool(table[mnemonic])
        except KeyError: raise KeyError(mnemonic) from None

    def incdec_register(self, mnemonic: str) -> int:
        if mnemonic in {"DEX", "INX"}: reg,delta,bits="x",(-1 if mnemonic=="DEX" else 1),(8 if self.s.x8 else 16)
        elif mnemonic in {"DEY", "INY"}: reg,delta,bits="y",(-1 if mnemonic=="DEY" else 1),(8 if self.s.x8 else 16)
        elif mnemonic in {"DEC", "INC"}: reg,delta,bits="a",(-1 if mnemonic=="DEC" else 1),(8 if self.s.m8 else 16)
        else: raise KeyError(mnemonic)
        result=(getattr(self.s,reg)+delta)&((1<<bits)-1)
        self._write_reg_width(reg,result,bits)
        return result

    def nop(self) -> None:
        pass

    def wdm(self, signature: int) -> None:
        # Signature is architecturally consumed by decode/fetch but has no
        # W65C816S state effect. Future processors may assign it meaning.
        _ = signature & 0xFF

    def set_or_clear_flag(self, mnemonic: str) -> None:
        table = {
            "CLC": (C, False), "CLD": (D, False), "CLI": (I, False), "CLV": (V, False),
            "SEC": (C, True), "SED": (D, True), "SEI": (I, True),
        }
        mask, value = table[mnemonic]
        self._set_flag(mask, value)

    def rep(self, mask: int) -> None:
        self.s.p &= ~(mask & 0xFF)
        if self.s.e:
            self.s.p |= MFLAG | XFLAG
        self.s.normalize()

    def sep(self, mask: int) -> None:
        self.s.p |= mask & 0xFF
        self.s.normalize()

    def xce(self) -> None:
        old_c = 1 if self.flag(C) else 0
        old_e = self.s.e
        self._set_flag(C, bool(old_e))
        self.s.e = old_c
        self.s.normalize()

    def transfer(self, mnemonic: str) -> None:
        if mnemonic == "TAX": self._write_reg_width("x", self.s.a, 8 if self.s.x8 else 16)
        elif mnemonic == "TAY": self._write_reg_width("y", self.s.a, 8 if self.s.x8 else 16)
        elif mnemonic == "TCD": self._write_reg_width("d", self.s.a, 16)
        elif mnemonic == "TCS": self.s.s = self.s.a & 0xFFFF; self.s.normalize()
        elif mnemonic == "TDC": self._write_reg_width("a", self.s.d, 16)
        elif mnemonic == "TSC": self._write_reg_width("a", self.s.s, 16)
        elif mnemonic == "TSX": self._write_reg_width("x", self.s.s, 8 if self.s.x8 else 16)
        elif mnemonic == "TXA": self._write_reg_width("a", self.s.x, 8 if self.s.m8 else 16)
        elif mnemonic == "TXS": self.s.s = self.s.x & 0xFFFF; self.s.normalize()
        elif mnemonic == "TXY": self._write_reg_width("y", self.s.x, 8 if self.s.x8 else 16)
        elif mnemonic == "TYA": self._write_reg_width("a", self.s.y, 8 if self.s.m8 else 16)
        elif mnemonic == "TYX": self._write_reg_width("x", self.s.y, 8 if self.s.x8 else 16)
        else: raise KeyError(mnemonic)

    def xba(self) -> None:
        self.s.a = ((self.s.a & 0xFF) << 8) | ((self.s.a >> 8) & 0xFF)
        self._set_nz(self.s.a & 0xFF, 8)

    def push8(self, value: int, allow_emulation_wrap: bool = True) -> None:
        self.mem.write8(self.s.s & 0xFFFF, value)
        self.s.s = (self.s.s - 1) & 0xFFFF
        if allow_emulation_wrap and self.s.e:
            self.s.s = 0x0100 | (self.s.s & 0xFF)

    def pop8(self, allow_emulation_wrap: bool = True) -> int:
        self.s.s = (self.s.s + 1) & 0xFFFF
        if allow_emulation_wrap and self.s.e:
            self.s.s = 0x0100 | (self.s.s & 0xFF)
        return self.mem.read8(self.s.s & 0xFFFF)

    def push16(self, value: int, allow_emulation_wrap: bool = True) -> None:
        self.push8((value >> 8) & 0xFF, allow_emulation_wrap)
        self.push8(value & 0xFF, allow_emulation_wrap)

    def pop16(self, allow_emulation_wrap: bool = True) -> int:
        lo = self.pop8(allow_emulation_wrap)
        hi = self.pop8(allow_emulation_wrap)
        return lo | (hi << 8)

    def php(self) -> None: self.push8(self.s.p)
    def phb(self) -> None: self.push8(self.s.dbr)
    def phk(self) -> None: self.push8(self.s.pbr)
    def pha(self) -> None:
        if self.s.m8: self.push8(self.s.a)
        else: self.push16(self.s.a)
    def phx(self) -> None:
        if self.s.x8: self.push8(self.s.x)
        else: self.push16(self.s.x)
    def phy(self) -> None:
        if self.s.x8: self.push8(self.s.y)
        else: self.push16(self.s.y)
    def phd(self) -> None:
        self.push16(self.s.d, False); self.s.normalize()
    def pea(self, value: int) -> None:
        self.push16(value, False); self.s.normalize()
    def per(self, relative: int) -> None:
        signed = relative if relative < 0x8000 else relative - 0x10000
        self.push16((self.s.pc + signed) & 0xFFFF, False); self.s.normalize()
    def pei(self, pointer_word: int) -> None:
        self.push16(pointer_word, False); self.s.normalize()

    def plp(self) -> None:
        pulled = self.pop8()
        self.s.p = pulled | (MFLAG | XFLAG if self.s.e else 0)
        self.s.normalize()
    def plb(self) -> None:
        value = self.pop8(False); self.s.dbr = value; self._set_nz(value, 8); self.s.normalize()
    def pld(self) -> None:
        value = self.pop16(False); self.s.d = value; self._set_nz(value, 16); self.s.normalize()
    def pla(self) -> None:
        if self.s.m8: self._write_reg_width("a", self.pop8(), 8)
        else: self._write_reg_width("a", self.pop16(), 16)
    def plx(self) -> None:
        if self.s.x8: self._write_reg_width("x", self.pop8(), 8)
        else: self._write_reg_width("x", self.pop16(), 16)
    def ply(self) -> None:
        if self.s.x8: self._write_reg_width("y", self.pop8(), 8)
        else: self._write_reg_width("y", self.pop16(), 16)

    def jmp(self, target: int, long: bool = False) -> None:
        if long: self.s.pbr = (target >> 16) & 0xFF
        self.s.pc = target & 0xFFFF

    def jsr(self, target: int, *, indexed_indirect: bool = False) -> None:
        # JSR (a,x) is one of the emulation-mode stack exceptions: its two
        # pushes may cross the page-1 boundary before S is restricted again.
        self.push16((self.s.pc - 1) & 0xFFFF, not indexed_indirect)
        self.s.pc = target & 0xFFFF
        if indexed_indirect:
            self.s.normalize()

    def jsl(self, target: int) -> None:
        self.push8(self.s.pbr, False)
        self.push16((self.s.pc - 1) & 0xFFFF, False)
        self.s.pbr = (target >> 16) & 0xFF
        self.s.pc = target & 0xFFFF
        self.s.normalize()

    def rts(self) -> None:
        self.s.pc = (self.pop16() + 1) & 0xFFFF

    def rtl(self) -> None:
        self.s.pc = (self.pop16(False) + 1) & 0xFFFF
        self.s.pbr = self.pop8(False)
        self.s.normalize()

    def rti(self) -> None:
        self.s.p = self.pop8() | (MFLAG | XFLAG if self.s.e else 0)
        self.s.normalize()
        self.s.pc = self.pop16()
        if not self.s.e:
            self.s.pbr = self.pop8()
        self.s.normalize()

    def interrupt_entry(self, vector: int, *, hardware: bool, software_kind: str | None = None) -> None:
        """Enter IRQ/NMI/ABORT/BRK/COP after instruction fetch semantics.

        `vector` is the resolved 16-bit target supplied by the bus/vector layer.
        This routine verifies stack/flag/mode semantics only; vector bus reads are
        accounted by the V02C access contract.
        """
        if software_kind not in (None, "BRK", "COP"):
            raise ValueError(software_kind)
        if self.s.e:
            self.push16(self.s.pc)
            pushed_p = self.s.p | 0x20
            if software_kind == "BRK":
                pushed_p |= 0x10
            elif hardware or software_kind == "COP":
                pushed_p &= ~0x10
            self.push8(pushed_p)
        else:
            self.push8(self.s.pbr)
            self.push16(self.s.pc)
            self.push8(self.s.p)
        self._set_flag(I, True)
        self._set_flag(D, False)
        self.s.pbr = 0
        self.s.pc = vector & 0xFFFF
        self.s.waiting = False
        self.s.normalize()

    def block_move_step(self, *, increment: bool, source_bank: int, dest_bank: int) -> tuple[int, int, int]:
        src = ((source_bank & 0xFF) << 16) | self.s.x
        dst = ((dest_bank & 0xFF) << 16) | self.s.y
        value = self.mem.read8(src)
        self.mem.write8(dst, value)
        self.s.dbr = dest_bank & 0xFF
        delta = 1 if increment else -1
        self.s.x = (self.s.x + delta) & 0xFFFF
        self.s.y = (self.s.y + delta) & 0xFFFF
        if self.s.x8:
            self.s.x &= 0xFF
            self.s.y &= 0xFF
        self.s.a = (self.s.a - 1) & 0xFFFF
        if self.s.a != 0xFFFF:
            self.s.pc = (self.s.pc - 3) & 0xFFFF
        return src, dst, value

    def wai(self) -> None:
        self.s.waiting = True
        self.s.stopped = False

    def stp(self) -> None:
        self.s.stopped = True
        self.s.waiting = False
