"""Fail-closed offline W65C816 decoder for V02C analysis.

This module is analysis-only.  Later production static code is generated from
proved contexts and must never call this decoder at runtime.
"""
from __future__ import annotations
from dataclasses import dataclass
from .opcodes import OPCODES,OpcodeSpec,context_is_legal,instruction_length
from .access_contract import AccessContract,access_contract

class DecodeContextError(ValueError): pass

@dataclass(frozen=True)
class DecodedContext:
    spec: OpcodeSpec
    e: int
    m: int
    x: int
    length: int
    access: AccessContract

def decode_context(opcode:int,e:int,m:int,x:int)->DecodedContext:
    if not 0 <= opcode <= 0xff: raise DecodeContextError(f'opcode outside byte range: {opcode!r}')
    if any(v not in (0,1) for v in (e,m,x)): raise DecodeContextError(f'E/M/X must each be 0 or 1: {(e,m,x)!r}')
    if not context_is_legal(e,m,x): raise DecodeContextError(f'contradictory emulation context E/M/X={e}/{m}/{x}: E=1 requires M=X=1')
    spec=OPCODES[opcode]
    return DecodedContext(spec,e,m,x,instruction_length(spec,m,x),access_contract(spec,e,m,x))
