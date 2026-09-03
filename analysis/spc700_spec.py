#!/usr/bin/env python3
"""Documented SPC700 instruction decoder for offline static analysis.

This module is an offline development tool.  It contains an explicit opcode
name and length table and performs no runtime interpretation in production.
"""
from __future__ import annotations
from dataclasses import dataclass

OP_LENGTHS = (
    1,1,2,3,2,3,1,2,2,3,3,2,3,1,3,1,
    2,1,2,3,2,3,3,2,3,1,2,2,1,1,3,3,
    1,1,2,3,2,3,1,2,2,3,3,2,3,1,3,2,
    2,1,2,3,2,3,3,2,3,1,2,2,1,1,2,3,
    1,1,2,3,2,3,1,2,2,3,3,2,3,1,3,2,
    2,1,2,3,2,3,3,2,3,1,2,2,1,1,3,3,
    1,1,2,3,2,3,1,2,2,3,3,2,3,1,3,1,
    2,1,2,3,2,3,3,2,3,1,2,2,1,1,2,1,
    1,1,2,3,2,3,1,2,2,3,3,2,3,2,1,3,
    2,1,2,3,2,3,3,2,3,1,2,2,1,1,1,1,
    1,1,2,3,2,3,1,2,2,3,3,2,3,2,1,1,
    2,1,2,3,2,3,3,2,3,1,2,2,1,1,1,1,
    1,1,2,3,2,3,1,2,2,3,3,2,3,2,1,1,
    2,1,2,3,2,3,3,2,2,2,2,2,1,1,3,1,
    1,1,2,3,2,3,1,2,2,3,3,2,3,1,1,1,
    2,1,2,3,2,3,3,2,2,2,3,2,1,1,2,1,
)

_ROWS = (
('NOP','TCALL 0','SET1 dp.0','BBS dp.0,rel','OR A,dp','OR A,abs','OR A,(X)','OR A,[dp+X]','OR A,#imm','OR dp,dp','OR1 C,bit','ASL dp','ASL abs','PUSH PSW','TSET1 abs','BRK'),
('BPL rel','TCALL 1','CLR1 dp.0','BBC dp.0,rel','OR A,dp+X','OR A,abs+X','OR A,abs+Y','OR A,[dp]+Y','OR dp,#imm','OR (X),(Y)','DECW dp','ASL dp+X','ASL A','DEC X','CMP X,abs','JMP [abs+X]'),
('CLRP','TCALL 2','SET1 dp.1','BBS dp.1,rel','AND A,dp','AND A,abs','AND A,(X)','AND A,[dp+X]','AND A,#imm','AND dp,dp','OR1 C,/bit','ROL dp','ROL abs','PUSH A','CBNE dp,rel','BRA rel'),
('BMI rel','TCALL 3','CLR1 dp.1','BBC dp.1,rel','AND A,dp+X','AND A,abs+X','AND A,abs+Y','AND A,abs+Y','AND dp,#imm','AND (X),(Y)','INCW dp','ROL dp+X','ROL A','INC X','CMP X,dp','CALL abs'),
('SETP','TCALL 4','SET1 dp.2','BBS dp.2,rel','EOR A,dp','EOR A,abs','EOR A,(X)','EOR A,[dp+X]','EOR A,#imm','EOR dp,dp','AND1 C,bit','LSR dp','LSR abs','PUSH X','TCLR1 abs','PCALL upage'),
('BVC rel','TCALL 5','CLR1 dp.2','BBC dp.2,rel','EOR A,dp+X','EOR A,abs+X','EOR A,abs+Y','EOR A,[dp]+Y','EOR dp,#imm','EOR (X),(Y)','CMPW YA,dp','LSR dp+X','LSR A','MOV X,A','CMP Y,abs','JMP abs'),
('CLRC','TCALL 6','SET1 dp.3','BBS dp.3,rel','CMP A,dp','CMP A,abs','CMP A,(X)','CMP A,[dp+X]','CMP A,#imm','CMP dp,dp','AND1 C,/bit','ROR dp','ROR abs','PUSH Y','DBNZ dp,rel','RET'),
('BVS rel','TCALL 7','CLR1 dp.3','BBC dp.3,rel','CMP A,dp+X','CMP A,abs+X','CMP A,abs+Y','CMP A,[dp]+Y','CMP dp,#imm','CMP (X),(Y)','ADDW YA,dp','ROR dp+X','ROR A','MOV A,X','CMP Y,dp','RETI'),
('SETC','TCALL 8','SET1 dp.4','BBS dp.4,rel','ADC A,dp','ADC A,abs','ADC A,(X)','ADC A,[dp+X]','ADC A,#imm','ADC dp,dp','EOR1 C,bit','DEC dp','DEC abs','MOV Y,#imm','POP PSW','MOV dp,#imm'),
('BCC rel','TCALL 9','CLR1 dp.4','BBC dp.4,rel','ADC A,dp+X','ADC A,abs+X','ADC A,abs+Y','ADC A,[dp]+Y','ADC dp,#imm','ADC (X),(Y)','SUBW YA,dp','DEC dp+X','DEC A','MOV X,SP','DIV YA,X','XCN A'),
('EI','TCALL 10','SET1 dp.5','BBS dp.5,rel','SBC A,dp','SBC A,abs','SBC A,(X)','SBC A,[dp+X]','SBC A,#imm','SBC dp,dp','MOV1 C,bit','INC dp','INC abs','CMP Y,#imm','POP A','MOV (X)+,A'),
('BCS rel','TCALL 11','CLR1 dp.5','BBC dp.5,rel','SBC A,dp+X','SBC A,abs+X','SBC A,abs+Y','SBC A,[dp]+Y','SBC dp,#imm','SBC (X),(Y)','MOVW YA,dp','INC dp+X','INC A','MOV SP,X','DAS A','MOV A,(X)+'),
('DI','TCALL 12','SET1 dp.6','BBS dp.6,rel','MOV dp,A','MOV abs,A','MOV (X),A','MOV [dp+X],A','CMP X,#imm','MOV abs,X','MOV1 bit,C','MOV dp,Y','MOV abs,Y','MOV X,#imm','POP X','MUL YA'),
('BNE rel','TCALL 13','CLR1 dp.6','BBC dp.6,rel','MOV dp+X,A','MOV abs+X,A','MOV abs+Y,A','MOV [dp]+Y,A','MOV dp,X','MOV dp+Y,X','MOVW dp,YA','MOV dp+X,Y','DEC Y','MOV A,Y','CBNE dp+X,rel','DAA A'),
('CLRV','TCALL 14','SET1 dp.7','BBS dp.7,rel','MOV A,dp','MOV A,abs','MOV A,(X)','MOV A,[dp+X]','MOV A,#imm','MOV X,abs','NOT1 bit','MOV Y,dp','MOV Y,abs','NOTC','POP Y','SLEEP'),
('BEQ rel','TCALL 15','CLR1 dp.7','BBC dp.7,rel','MOV A,dp+X','MOV A,abs+X','MOV A,abs+Y','MOV A,[dp]+Y','MOV X,dp','MOV X,dp+Y','MOV dp,dp','MOV Y,dp+X','INC Y','MOV Y,A','DBNZ Y,rel','STOP'),
)
OP_NAMES = tuple(name for row in _ROWS for name in row)

# Documented base SPC700 instruction cycles. Conditional branches add two
# cycles when taken. These values are used by offline generation and receipts;
# production execution remains fixed-context and contains no opcode decoder.
OP_CYCLES = (
    2,8,4,5,3,4,3,6,2,6,5,4,5,4,6,8,
    2,8,4,5,4,5,5,6,5,5,6,5,2,2,4,6,
    2,8,4,5,3,4,3,6,2,6,5,4,5,4,5,4,
    2,8,4,5,4,5,5,6,5,5,6,5,2,2,3,8,
    2,8,4,5,3,4,3,6,2,6,4,4,5,4,6,6,
    2,8,4,5,4,5,5,6,5,5,4,5,2,2,4,3,
    2,8,4,5,3,4,3,6,2,6,4,4,5,4,5,5,
    2,8,4,5,4,5,5,6,5,5,5,5,2,2,3,6,
    2,8,4,5,3,4,3,6,2,6,5,4,5,2,4,5,
    2,8,4,5,4,5,5,6,5,5,5,5,2,2,12,5,
    3,8,4,5,3,4,3,6,2,6,4,4,5,2,4,4,
    2,8,4,5,4,5,5,6,5,5,5,5,2,2,3,4,
    3,8,4,5,4,5,4,7,2,5,6,4,5,2,4,9,
    2,8,4,5,5,6,6,7,4,5,4,5,2,2,6,3,
    2,8,4,5,3,4,3,6,2,4,5,3,4,3,4,3,
    2,8,4,5,4,5,5,6,3,4,5,4,2,2,4,3,
)

assert len(OP_NAMES) == 256 and len(OP_LENGTHS) == 256 and len(OP_CYCLES) == 256

@dataclass(frozen=True)
class Instruction:
    pc:int
    opcode:int
    length:int
    raw:bytes
    name:str
    next_pc:int
    branch_target:int|None=None
    absolute:int|None=None
    dp:int|None=None
    imm:int|None=None


def s8(v:int)->int:
    return v-0x100 if v&0x80 else v

def decode(mem:bytes|bytearray,pc:int)->Instruction:
    pc &= 0xffff
    op=mem[pc]
    ln=OP_LENGTHS[op]
    raw=bytes(mem[(pc+i)&0xffff] for i in range(ln))
    name=OP_NAMES[op]
    nxt=(pc+ln)&0xffff
    branch=None; absolute=None; dp=None; imm=None
    if op in {0x10,0x30,0x50,0x70,0x90,0xB0,0xD0,0xF0,0x2F,0xFE}:
        branch=(nxt+s8(raw[1]))&0xffff
    elif op in {x for x in range(0x03,0x100,0x10)} | {0x2E,0x6E,0xDE}:
        dp=raw[1]; branch=(nxt+s8(raw[2]))&0xffff
    if ln==3 and op not in {0x03,0x13,0x23,0x33,0x43,0x53,0x63,0x73,0x83,0x93,0xA3,0xB3,0xC3,0xD3,0xE3,0xF3,0x2E,0x6E,0xDE}:
        absolute=raw[1]|(raw[2]<<8)
    # Common direct/immediate operand classifications used by the reference executor.
    if ln>=2:
        if 'dp' in name: dp=raw[-1] if op in {0x18,0x38,0x58,0x78,0x98,0xB8,0x8F} else raw[1]
        if '#imm' in name: imm=raw[1]
    return Instruction(pc,op,ln,raw,name,nxt,branch,absolute,dp,imm)
