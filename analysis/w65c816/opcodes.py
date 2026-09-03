"""Complete W65C816 opcode/context metadata for the V02C offline decoder.

The compact matrix below is a project transcription of WDC W65C816S datasheet
Table 5-4 (2024-03-13).  `wdc_mnemonic` preserves the spelling used by that
matrix; `mnemonic` normalizes the long-jump alias at opcode $5C to JML so it can
be compared directly with the pinned MesenCE RunOp implementation.

WDC's cycle/byte entries assume M=X=1, conditional branches not taken, no page
crossing, BRK/COP in emulation mode, and RTI in native mode.  V02C keeps these
base numbers separate from context/dynamic penalties.
"""
from __future__ import annotations

from dataclasses import dataclass
from typing import Iterator


_MNEMONIC_ROWS = [
"BRK ORA COP ORA TSB ORA ASL ORA PHP ORA ASL PHD TSB ORA ASL ORA",
"BPL ORA ORA ORA TRB ORA ASL ORA CLC ORA INC TCS TRB ORA ASL ORA",
"JSR AND JSL AND BIT AND ROL AND PLP AND ROL PLD BIT AND ROL AND",
"BMI AND AND AND BIT AND ROL AND SEC AND DEC TSC BIT AND ROL AND",
"RTI EOR WDM EOR MVP EOR LSR EOR PHA EOR LSR PHK JMP EOR LSR EOR",
"BVC EOR EOR EOR MVN EOR LSR EOR CLI EOR PHY TCD JMP EOR LSR EOR",
"RTS ADC PER ADC STZ ADC ROR ADC PLA ADC ROR RTL JMP ADC ROR ADC",
"BVS ADC ADC ADC STZ ADC ROR ADC SEI ADC PLY TDC JMP ADC ROR ADC",
"BRA STA BRL STA STY STA STX STA DEY BIT TXA PHB STY STA STX STA",
"BCC STA STA STA STY STA STX STA TYA STA TXS TXY STZ STA STZ STA",
"LDY LDA LDX LDA LDY LDA LDX LDA TAY LDA TAX PLB LDY LDA LDX LDA",
"BCS LDA LDA LDA LDY LDA LDX LDA CLV LDA TSX TYX LDY LDA LDX LDA",
"CPY CMP REP CMP CPY CMP DEC CMP INY CMP DEX WAI CPY CMP DEC CMP",
"BNE CMP CMP CMP PEI CMP DEC CMP CLD CMP PHX STP JML CMP DEC CMP",
"CPX SBC SEP SBC CPX SBC INC SBC INX SBC NOP XBA CPX SBC INC SBC",
"BEQ SBC SBC SBC PEA SBC INC SBC SED SBC PLX XCE JSR SBC INC SBC",
]

_MODE_ROWS = [
"s (d,x) s d,s d d d [d] s # A s a a a al",
"r (d),y (d) (d,s),y d d,x d,x [d],y i a,y A i a a,x a,x al,x",
"a (d,x) al d,s d d d [d] s # A s a a a al",
"r (d),y (d) (d,s),y d,x d,x d,x [d],y i a,y A i a,x a,x a,x al,x",
"s (d,x) i d,s xyc d d [d] s # A s a a a al",
"r (d),y (d) (d,s),y xyc d,x d,x [d],y i a,y s i al a,x a,x al,x",
"s (d,x) s d,s d d d [d] s # A s (a) a a al",
"r (d),y (d) (d,s),y d,x d,x d,x [d],y i a,y s i (a,x) a,x a,x al,x",
"r (d,x) rl d,s d d d [d] i # i s a a a al",
"r (d),y (d) (d,s),y d,x d,x d,y [d],y i a,y i i a a,x a,x al,x",
"# (d,x) # d,s d d d [d] i # i s a a a al",
"r (d),y (d) (d,s),y d,x d,x d,y [d],y i a,y i i a,x a,x a,y al,x",
"# (d,x) # d,s d d d [d] i # i i a a a al",
"r (d),y (d) (d,s),y s d,x d,x [d],y i a,y s i (a) a,x a,x al,x",
"# (d,x) # d,s d d d [d] i # i i a a a al",
"r (d),y (d) (d,s),y s d,x d,x [d],y i a,y s i (a,x) a,x a,x al,x",
]

_CYCLE_BYTE_ROWS = [
"7,2 6,2 7,2 4,2 5,2 3,2 5,2 6,2 3,1 2,2 2,1 4,1 6,3 4,3 6,3 5,4",
"2,2 5,2 5,2 7,2 5,2 4,2 6,2 6,2 2,1 4,3 2,1 2,1 6,3 4,3 7,3 5,4",
"6,3 6,2 8,4 4,2 3,2 3,2 5,2 6,2 4,1 2,2 2,1 5,1 4,3 4,3 6,3 5,4",
"2,2 5,2 5,2 7,2 4,2 4,2 6,2 6,2 2,1 4,3 2,1 2,1 4,3 4,3 7,3 5,4",
"7,1 6,2 2,2 4,2 7,3 3,2 5,2 6,2 3,1 2,2 2,1 3,1 3,3 4,3 6,3 5,4",
"2,2 5,2 5,2 7,2 7,3 4,2 6,2 6,2 2,1 4,3 3,1 2,1 4,4 4,3 7,3 5,4",
"6,1 6,2 6,3 4,2 3,2 3,2 5,2 6,2 4,1 2,2 2,1 6,1 5,3 4,3 6,3 5,4",
"2,2 5,2 5,2 7,2 4,2 4,2 6,2 6,2 2,1 4,3 4,1 2,1 6,3 4,3 7,3 5,4",
"2,2 6,2 4,3 4,2 3,2 3,2 3,2 6,2 2,1 2,2 2,1 3,1 4,3 4,3 4,3 5,4",
"2,2 6,2 5,2 7,2 4,2 4,2 4,2 6,2 2,1 5,3 2,1 2,1 4,3 5,3 5,3 5,4",
"2,2 6,2 2,2 4,2 3,2 3,2 3,2 6,2 2,1 2,2 2,1 4,1 4,3 4,3 4,3 5,4",
"2,2 5,2 5,2 7,2 4,2 4,2 4,2 6,2 2,1 4,3 2,1 2,1 4,3 4,3 4,3 5,4",
"2,2 6,2 3,2 4,2 3,2 3,2 5,2 6,2 2,1 2,2 2,1 3,1 4,3 4,3 6,3 5,4",
"2,2 5,2 5,2 7,2 6,2 4,2 6,2 6,2 2,1 4,3 3,1 3,1 6,3 4,3 7,3 5,4",
"2,2 6,2 3,2 4,2 3,2 3,2 5,2 6,2 2,1 2,2 2,1 3,1 4,3 4,3 6,3 5,4",
"2,2 5,2 5,2 7,2 5,3 4,2 6,2 6,2 2,1 4,3 4,1 2,1 8,3 4,3 7,3 5,4",
]


@dataclass(frozen=True)
class OpcodeSpec:
    opcode: int
    mnemonic: str
    wdc_mnemonic: str
    wdc_mode: str
    mode: str
    base_cycles: int
    base_bytes: int


def _canonical_mnemonic(opcode: int, wdc: str) -> str:
    # WDC Table 5-4 spells $5C as JMP long; Mesen and this project use JML.
    return "JML" if opcode == 0x5C else wdc


def _normalize_mode(opcode: int, mnemonic: str, wdc_mode: str) -> str:
    # Opcode-specific operand encodings whose WDC presentation is semantic rather
    # than the exact decode primitive used by the offline analyzer.
    if opcode in (0x00, 0x02, 0x42):
        return "SIG8"
    if opcode == 0x22:
        return "ABSL_JUMP"
    if opcode in (0x44, 0x54):
        return "BLOCK"
    if opcode == 0x5C:
        return "ABSL_JUMP"
    if opcode == 0x62:
        return "REL16"
    if opcode == 0x6C:
        return "ABS_IND"
    if opcode in (0x7C, 0xFC):
        return "ABS_X_IND"
    if opcode == 0xD4:
        return "DP"
    if opcode == 0xDC:
        return "ABS_IND_LONG"
    if opcode == 0xF4:
        return "IMM16"

    if wdc_mode == "#":
        if mnemonic in {"REP", "SEP"}:
            return "IMM8"
        if mnemonic in {"LDX", "LDY", "CPX", "CPY"}:
            return "IMM_X"
        return "IMM_M"
    return {
        "A": "ACC",
        "a": "ABS_JUMP" if mnemonic in {"JMP", "JSR"} else "ABS",
        "a,x": "ABS_X",
        "a,y": "ABS_Y",
        "al": "ABS_LONG",
        "al,x": "ABS_LONG_X",
        "(a)": "ABS_IND",
        "(a,x)": "ABS_X_IND",
        "d": "DP",
        "d,x": "DP_X",
        "d,y": "DP_Y",
        "(d)": "DP_IND",
        "[d]": "DP_IND_LONG",
        "(d,s),y": "STACK_REL_IND_Y",
        "(d,x)": "DP_X_IND",
        "(d),y": "DP_IND_Y",
        "[d],y": "DP_IND_LONG_Y",
        "d,s": "STACK_REL",
        "i": "IMP",
        "r": "REL8",
        "rl": "REL16",
        "s": "IMP",
        "xyc": "BLOCK",
    }[wdc_mode]


def _build_opcodes() -> tuple[OpcodeSpec, ...]:
    out: list[OpcodeSpec] = []
    for hi in range(16):
        m = _MNEMONIC_ROWS[hi].split()
        a = _MODE_ROWS[hi].split()
        cb = _CYCLE_BYTE_ROWS[hi].split()
        if not (len(m) == len(a) == len(cb) == 16):
            raise AssertionError((hi, len(m), len(a), len(cb)))
        for lo in range(16):
            opcode = hi * 16 + lo
            cyc, byt = (int(x) for x in cb[lo].split(","))
            canonical = _canonical_mnemonic(opcode, m[lo])
            out.append(OpcodeSpec(
                opcode=opcode,
                mnemonic=canonical,
                wdc_mnemonic=m[lo],
                wdc_mode=a[lo],
                mode=_normalize_mode(opcode, canonical, a[lo]),
                base_cycles=cyc,
                base_bytes=byt,
            ))
    if len(out) != 256 or {x.opcode for x in out} != set(range(256)):
        raise AssertionError("opcode table is not complete")
    return tuple(out)


OPCODES = _build_opcodes()


def context_is_legal(e: int, m: int, x: int) -> bool:
    """Raw E/M/X tuple is architectural iff E=0 or E=1,M=1,X=1."""
    return e in (0, 1) and m in (0, 1) and x in (0, 1) and (e == 0 or (m == 1 and x == 1))


def instruction_length(spec: OpcodeSpec, m: int, x: int) -> int:
    if spec.mode == "IMM_M" and m == 0:
        return spec.base_bytes + 1
    if spec.mode == "IMM_X" and x == 0:
        return spec.base_bytes + 1
    return spec.base_bytes


def iter_raw_contexts() -> Iterator[tuple[OpcodeSpec, int, int, int, bool]]:
    for spec in OPCODES:
        for e in (0, 1):
            for m in (0, 1):
                for x in (0, 1):
                    yield spec, e, m, x, context_is_legal(e, m, x)
