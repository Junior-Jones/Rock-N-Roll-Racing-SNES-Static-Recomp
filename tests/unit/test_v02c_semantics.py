import unittest
from analysis.w65c816.semantics import *

class SemanticTests(unittest.TestCase):
 def eng(self,**kw):
  d=dict(e=0,p=0,a=0,x=0,y=0,s=0x01ff,pc=0x8000,pbr=0x12,dbr=0x34,d=0); d.update(kw); s=CPUState(**d); return SemanticEngine(s)
 def flags(self,e): return e.flag(N),e.flag(V),e.flag(Z),e.flag(C)
 def test_8bit_accumulator_load_and_alu_preserve_b(self):
  e=self.eng(a=0xab00,p=MFLAG|XFLAG); e.load('a',0x12,8); self.assertEqual(0xab12,e.s.a)
  e.logic('ORA',0x80,8); self.assertEqual(0xab92,e.s.a)
  e.s.p=MFLAG|XFLAG; e.s.a=0xabff; e.adc(1,8); self.assertEqual(0xab00,e.s.a); self.assertTrue(e.flag(C)); self.assertTrue(e.flag(Z))
 def test_index_load_normalization_and_stz_width(self):
  e=self.eng(x=0xab00,p=XFLAG|MFLAG); e.load('x',0x1234,8); self.assertEqual(0x34,e.s.x)
  self.assertEqual(0,e.store_value(None,8)); self.assertEqual(0,e.store_value(None,16))
 def test_binary_adc_sbc_edge_flags(self):
  e=self.eng(a=0x7fff,p=0); e.adc(1,16); self.assertEqual(0x8000,e.s.a); self.assertTrue(e.flag(V)); self.assertTrue(e.flag(N)); self.assertFalse(e.flag(C))
  e=self.eng(a=0x0000,p=C); e.sbc(1,16); self.assertEqual(0xffff,e.s.a); self.assertFalse(e.flag(C)); self.assertTrue(e.flag(N))
 def test_decimal_adc_sbc_examples(self):
  e=self.eng(a=0x9999,p=D); e.adc(1,16); self.assertEqual(0x0000,e.s.a); self.assertTrue(e.flag(C)); self.assertTrue(e.flag(Z))
  e=self.eng(a=0x1000,p=D|C); e.sbc(1,16); self.assertEqual(0x0999,e.s.a); self.assertTrue(e.flag(C))
 def test_logic_compare_shift_bit_trb_tsb(self):
  e=self.eng(a=0x00f0); self.assertEqual(0x0000,e.logic('AND',0x0f0f,16)); self.assertTrue(e.flag(Z))
  e=self.eng(); e.compare(1,2,8); self.assertFalse(e.flag(C)); self.assertTrue(e.flag(N))
  e=self.eng(p=C); self.assertEqual(0x0001,e.shift('ROL',0x8000,16)); self.assertTrue(e.flag(C))
  e=self.eng(a=0x000f,p=N|V); e.bit(0x4000,16,True); self.assertTrue(e.flag(Z)); self.assertTrue(e.flag(N)); self.assertTrue(e.flag(V))
  e.bit(0xc000,16,False); self.assertTrue(e.flag(N)); self.assertTrue(e.flag(V))
  e=self.eng(a=0x0f0f); self.assertEqual(0xffff,e.tsb(0xf0f0,16)); self.assertTrue(e.flag(Z)); self.assertEqual(0xf000,e.trb(0xff0f,16)); self.assertFalse(e.flag(Z))
 def test_inc_dec_and_branch_wrap(self):
  e=self.eng(); self.assertEqual(0,e.incdec_value(0xffff,1,16)); self.assertTrue(e.flag(Z))
  e=self.eng(a=0xab00,p=MFLAG|XFLAG); self.assertEqual(0xff,e.incdec_register('DEC')); self.assertEqual(0xabff,e.s.a)
  e=self.eng(x=0xff,p=MFLAG|XFLAG); self.assertEqual(0,e.incdec_register('INX')); self.assertEqual(0,e.s.x)
  e.s.pc=1; self.assertEqual(0xffff,e.branch8(0xfe,True)); e.s.pc=1; self.assertEqual(0xffff,e.branch16(0xfffe))
  e.s.p=C|Z|N|V; self.assertTrue(e.branch_condition('BCS')); self.assertTrue(e.branch_condition('BEQ')); self.assertTrue(e.branch_condition('BMI')); self.assertTrue(e.branch_condition('BVS')); self.assertFalse(e.branch_condition('BCC')); self.assertTrue(e.branch_condition('BRA')); self.assertTrue(e.branch_condition('BRL'))
 def test_rep_sep_xce_width_transitions(self):
  e=self.eng(e=0,p=0,x=0x1234,y=0x5678); e.sep(XFLAG); self.assertEqual((0x34,0x78),(e.s.x,e.s.y))
  e.rep(XFLAG|MFLAG); self.assertFalse(e.flag(XFLAG)); self.assertFalse(e.flag(MFLAG))
  e.s.e=1; e.s.p=MFLAG|XFLAG; e.s.s=0x12aa; e.s.x=0x1234; e.s.y=0x5678; e.s.p &= ~C; e.xce(); self.assertEqual(0,e.s.e); self.assertTrue(e.flag(C))
  e.s.p|=C; e.s.e=0; e.s.s=0x12aa; e.s.x=0x1234; e.s.y=0x5678; e.xce(); self.assertEqual(1,e.s.e); self.assertEqual(0x01aa,e.s.s); self.assertEqual((0x34,0x78),(e.s.x,e.s.y)); self.assertFalse(e.flag(C))
 def test_transfers_full_source_and_destination_width(self):
  e=self.eng(a=0xabcd,p=XFLAG|MFLAG); e.transfer('TAX'); self.assertEqual(0xcd,e.s.x)
  e=self.eng(a=0xabcd,p=0); e.transfer('TCS'); self.assertEqual(0xabcd,e.s.s)
  e=self.eng(e=1,p=MFLAG|XFLAG,a=0xabcd,s=0x01ff); e.transfer('TCS'); self.assertEqual(0x01cd,e.s.s)
  e=self.eng(a=0x1234); e.xba(); self.assertEqual(0x3412,e.s.a); self.assertFalse(e.flag(Z)); self.assertFalse(e.flag(N))
 def test_stack_wrap_and_exception_forms(self):
  e=self.eng(e=1,p=MFLAG|XFLAG,s=0x0100); e.push8(0xaa); self.assertEqual(0x01ff,e.s.s); self.assertEqual(0xaa,e.mem.bytes[0x0100])
  e=self.eng(e=1,p=MFLAG|XFLAG,s=0x0100,pc=0x8000); e.pea(0x1234); self.assertEqual(0x01fe,e.s.s); self.assertEqual([('W',0x0100,0x12),('W',0x00ff,0x34)],e.mem.accesses)
  e=self.eng(e=1,p=MFLAG|XFLAG,s=0x0100,pc=0x8000); e.jsr(0x9000,indexed_indirect=True); self.assertEqual(0x01fe,e.s.s); self.assertEqual([0x0100,0x00ff],[a for _,a,_ in e.mem.accesses])
 def test_plp_forces_emulation_width_and_truncates_indexes(self):
  e=self.eng(e=1,p=MFLAG|XFLAG,s=0x01fe,x=0xabcd,y=0x9876); e.mem.bytes[0x01ff]=0; e.plp(); self.assertTrue(e.s.p&MFLAG); self.assertTrue(e.s.p&XFLAG); self.assertEqual((0xcd,0x76),(e.s.x,e.s.y))
 def test_control_returns(self):
  e=self.eng(pc=0x8003,s=0x01ff); e.jsr(0x9000); self.assertEqual(0x9000,e.s.pc); self.assertEqual([0x80,0x02],[v for _,_,v in e.mem.accesses]); e.rts(); self.assertEqual(0x8003,e.s.pc)
  e=self.eng(pc=0x8004,pbr=0x12,s=0x01ff); e.jsl(0x349000); self.assertEqual((0x34,0x9000),(e.s.pbr,e.s.pc)); e.rtl(); self.assertEqual((0x12,0x8004),(e.s.pbr,e.s.pc))
 def test_interrupt_native_and_emulation_stack_flag_effects(self):
  e=self.eng(e=0,p=D|V,pc=0x8123,pbr=0x45,s=0x01ff); e.interrupt_entry(0x9000,hardware=True); self.assertEqual((0,0x9000),(e.s.pbr,e.s.pc)); self.assertTrue(e.flag(I)); self.assertFalse(e.flag(D)); self.assertEqual(4,len([a for a in e.mem.accesses if a[0]=='W']))
  e=self.eng(e=1,p=MFLAG|XFLAG|D,pc=0x8123,pbr=0x45,s=0x01ff); e.interrupt_entry(0x9000,hardware=True); self.assertEqual((0,0x9000),(e.s.pbr,e.s.pc)); writes=[v for k,a,v in e.mem.accesses if k=='W']; self.assertEqual(3,len(writes)); self.assertEqual(0,writes[-1]&0x10)
  e=self.eng(e=1,p=MFLAG|XFLAG,pc=0x8123,s=0x01ff); e.interrupt_entry(0x9000,hardware=False,software_kind='BRK'); self.assertTrue([v for k,a,v in e.mem.accesses if k=='W'][-1]&0x10)
 def test_interrupt_vector_forms(self):
  self.assertEqual(0xffe4,interrupt_vector_address('COP',0)); self.assertEqual(0xffe6,interrupt_vector_address('BRK',0)); self.assertEqual(0xffe8,interrupt_vector_address('ABORT',0)); self.assertEqual(0xffea,interrupt_vector_address('NMI',0)); self.assertEqual(0xffee,interrupt_vector_address('IRQ',0))
  self.assertEqual(0xfff4,interrupt_vector_address('COP',1)); self.assertEqual(0xfff8,interrupt_vector_address('ABORT',1)); self.assertEqual(0xfffa,interrupt_vector_address('NMI',1)); self.assertEqual(0xfffc,interrupt_vector_address('RESET',1)); self.assertEqual(0xfffe,interrupt_vector_address('IRQ',1)); self.assertEqual(0xfffe,interrupt_vector_address('BRK',1))
 def test_rti_native_and_emulation(self):
  e=self.eng(e=0,s=0x01fb); e.mem.bytes.update({0x01fc:0,0x01fd:0x34,0x01fe:0x12,0x01ff:0x56}); e.rti(); self.assertEqual((0x56,0x1234),(e.s.pbr,e.s.pc))
  e=self.eng(e=1,p=MFLAG|XFLAG,s=0x01fc); e.mem.bytes.update({0x01fd:0,0x01fe:0x78,0x01ff:0x56}); e.rti(); self.assertEqual(0x5678,e.s.pc); self.assertTrue(e.s.p&MFLAG|XFLAG)
 def test_nop_wdm_have_no_state_effect(self):
  e=self.eng(a=0x1234,x=0x55,y=0xaa,p=C|D); before=e.s.clone(); e.nop(); e.wdm(0x7f); self.assertEqual(vars(before),vars(e.s))
 def test_block_moves_and_wait_stop(self):
  e=self.eng(a=1,x=0xff,y=0xff,p=XFLAG,pc=0x8003); e.mem.bytes[0x1200ff]=0xaa; src,dst,val=e.block_move_step(increment=True,source_bank=0x12,dest_bank=0x34); self.assertEqual((0x1200ff,0x3400ff,0xaa),(src,dst,val)); self.assertEqual((0,0,0,0x34,0x8000),(e.s.a,e.s.x,e.s.y,e.s.dbr,e.s.pc))
  e.wai(); self.assertTrue(e.s.waiting); self.assertFalse(e.s.stopped); e.stp(); self.assertTrue(e.s.stopped); self.assertFalse(e.s.waiting)
if __name__=='__main__': unittest.main()
