import unittest

from analysis.v03c_discovery import State as V03State, Decoded
from analysis.w65c816.opcodes import OPCODES, instruction_length
from analysis.v04c_control_flow import (
    V04State, StackEntry, NO_SP_REL, MAX_TRACKED_STACK_BYTES,
    update_linear_state, pop, push, stack_bytes,
)


def decoded(st: V04State, raw: bytes) -> Decoded:
    spec=OPCODES[raw[0]]
    ln=instruction_length(spec,st.m,st.x)
    assert ln==len(raw),(spec,ln,raw)
    base=V03State(st.pbr,st.pc,st.e,st.m,st.x,st.c,st.dbr,-1,'PROVED')
    return Decoded(base,0,spec,raw,ln)


def step(st: V04State, raw: bytes, rom: bytes=b'') -> V04State:
    ns,fail=update_linear_state(st,decoded(st,raw),rom)
    if fail: raise AssertionError(fail)
    return ns


class V04CControlFlowTests(unittest.TestCase):
    def test_mixed_width_stack_pulls_recover_original_php_status(self):
        # Mirrors the important shape at 80:F9C2: PHP; widen; save 16-bit
        # registers; narrow; consume the saved A as two 8-bit pulls; widen;
        # restore Y/X/P.  Byte-accurate pulls must leave PHP on top for PLP.
        s=V04State(0x80,0x9000,0,1,1,c=1,n=0,z=1,v=0,dbr=0x80)
        s=step(s,b'\x08')              # PHP
        s=step(s,b'\xC2\x30')          # REP #$30
        s=step(s,b'\xDA')              # PHX 16
        s=step(s,b'\x5A')              # PHY 16
        s=step(s,b'\x48')              # PHA 16
        self.assertEqual(7,stack_bytes(s))
        s=step(s,b'\xE2\x30')          # SEP #$30
        s=step(s,b'\x68')              # PLA low byte of saved A
        s=step(s,b'\x68')              # PLA high byte of saved A
        self.assertEqual(5,stack_bytes(s))
        s=step(s,b'\xC2\x30')          # REP #$30
        s=step(s,b'\x7A')              # PLY 16
        s=step(s,b'\xFA')              # PLX 16
        self.assertEqual(1,stack_bytes(s))
        s=step(s,b'\x28')              # PLP exact saved STATUS
        self.assertEqual(0,stack_bytes(s))
        self.assertEqual((0,1,1,1,0,1,0),(s.e,s.m,s.x,s.c,s.n,s.z,s.v))

    def test_tsx_affine_stack_cleanup_exposes_exact_return_frame(self):
        ret=StackEntry('RET16',2,(0x83A0,),pbr=0x80,pc=0x83A1)
        locals_=(
            StackEntry.data(2,None,'A'), StackEntry.data(2,None,'X'),
            StackEntry.data(2,None,'A'), StackEntry.data(2,(0xCB00,),'PEA'),
            StackEntry.data(2,(0x1000,),'PEA'),
        )
        s=V04State(0x80,0x83C5,0,0,0,dbr=0x80,stack=(ret,)+locals_)
        self.assertEqual(12,stack_bytes(s))
        s=step(s,b'\xBA')               # TSX: X == S
        self.assertEqual(0,s.x_sp_rel)
        s=step(s,b'\x8A')               # TXA
        self.assertEqual(0,s.a_sp_rel)
        s=step(s,b'\x18')               # CLC
        s=step(s,b'\x69\x0A\x00')      # ADC #$000A
        self.assertEqual(10,s.a_sp_rel)
        s=step(s,b'\xAA')               # TAX
        self.assertEqual(10,s.x_sp_rel)
        s=step(s,b'\x9A')               # TXS: discard exactly 10 bytes
        self.assertEqual(2,stack_bytes(s))
        ent,s2,ok=pop(s,2)
        self.assertTrue(ok)
        self.assertEqual('RET16',ent.kind)
        self.assertEqual((0x80,0x83A1),(ent.pbr,ent.pc))
        self.assertEqual(0,stack_bytes(s2))

    def test_partial_pull_value_order_is_low_byte_first(self):
        s=V04State(0x80,0x9000,0,1,1)
        s=push(s,StackEntry.data(2,(0x1234,),'WORD'))
        lo,s,ok=pop(s,1); self.assertTrue(ok); self.assertEqual((0x34,),lo.values)
        hi,s,ok=pop(s,1); self.assertTrue(ok); self.assertEqual((0x12,),hi.values)

    def test_stack_window_truncation_is_fail_closed_below_exact_top(self):
        s=V04State(0x80,0x9000,0,0,0)
        for i in range(16):
            s=push(s,StackEntry('RET16',2,(i,),pbr=0x80,pc=0x9000+i))
        self.assertLessEqual(stack_bytes(s),MAX_TRACKED_STACK_BYTES)
        # Exact top frames remain usable.
        for _ in range(MAX_TRACKED_STACK_BYTES//2):
            ent,s,ok=pop(s,2); self.assertTrue(ok); self.assertEqual('RET16',ent.kind)
        # Older caller bytes were intentionally not guessed.
        ent,s,ok=pop(s,2); self.assertFalse(ok); self.assertIsNone(ent)

    def test_plp_from_unknown_stack_base_fails_status_proof(self):
        s=V04State(0x80,0x9000,0,0,0)
        ns,fail=update_linear_state(s,decoded(s,b'\x28'),b'')
        self.assertIsNotNone(fail)
        self.assertIn('PLP',fail)
        self.assertEqual(0,stack_bytes(ns))

    def test_stack_mutation_invalidates_short_lived_sp_affine_fact(self):
        s=V04State(0x80,0x9000,0,0,0,x_sp_rel=0,a_sp_rel=3)
        s=push(s,StackEntry.data(1,(0x12,),'DATA'))
        self.assertEqual(NO_SP_REL,s.x_sp_rel)
        self.assertEqual(NO_SP_REL,s.a_sp_rel)


if __name__=='__main__':
    unittest.main()
