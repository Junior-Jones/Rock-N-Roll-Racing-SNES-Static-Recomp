import unittest
from analysis.w65c816.semantics import *
class InstructionEdgeTests(unittest.TestCase):
 def e(self,**kw):
  d=dict(e=0,p=0,a=0,x=0,y=0,s=0x01ff,pc=0x8000,pbr=0x12,dbr=0x34,d=0); d.update(kw); return SemanticEngine(CPUState(**d))
 def test_all_simple_flag_instructions(self):
  e=self.e(p=C|D|I|V)
  for mnemonic,mask,want in [('CLC',C,0),('CLD',D,0),('CLI',I,0),('CLV',V,0),('SEC',C,1),('SED',D,1),('SEI',I,1)]:
   if want: e.s.p &= ~mask
   else: e.s.p |= mask
   e.set_or_clear_flag(mnemonic); self.assertEqual(bool(want),e.flag(mask),mnemonic)
 def test_all_logic_operators_and_both_widths(self):
  for mnemonic,want in [('AND',0x0000),('EOR',0xffff),('ORA',0xffff)]:
   e=self.e(a=0x0f0f); got=e.logic(mnemonic,0xf0f0,16); self.assertEqual(want,got)
  e=self.e(a=0xab55,p=MFLAG); self.assertEqual(0xaa,e.logic('EOR',0xff,8)); self.assertEqual(0xabaa,e.s.a)
 def test_compare_cpx_cpy_width_semantics_shared_primitive(self):
  e=self.e(); e.compare(0x80,0x7f,8); self.assertTrue(e.flag(C)); self.assertFalse(e.flag(N)); self.assertFalse(e.flag(Z))
  e.compare(0x1234,0x1234,16); self.assertTrue(e.flag(C)); self.assertTrue(e.flag(Z))
 def test_all_shift_rotate_forms(self):
  e=self.e(); self.assertEqual(0,e.shift('ASL',0x80,8)); self.assertTrue(e.flag(C)); self.assertTrue(e.flag(Z))
  e=self.e(); self.assertEqual(0x40,e.shift('LSR',0x81,8)); self.assertTrue(e.flag(C)); self.assertFalse(e.flag(N))
  e=self.e(p=C); self.assertEqual(0x01,e.shift('ROL',0x80,8)); self.assertTrue(e.flag(C))
  e=self.e(p=C); self.assertEqual(0xc0,e.shift('ROR',0x81,8)); self.assertTrue(e.flag(C)); self.assertTrue(e.flag(N))
 def test_load_store_register_width_rules(self):
  e=self.e(a=0xab00,p=MFLAG); e.load('a',0x1234,8); self.assertEqual(0xab34,e.s.a); self.assertEqual(0x34,e.store_value('a',8))
  e=self.e(x=0,y=0,p=XFLAG); e.load('x',0x12ff,8); e.load('y',0x1280,8); self.assertEqual((0xff,0x80),(e.s.x,e.s.y)); self.assertEqual(0x80,e.store_value('y',8))
  e=self.e(); e.load('a',0x8000,16); self.assertTrue(e.flag(N)); self.assertEqual(0x8000,e.store_value('a',16))
 def test_push_pull_register_widths_and_status_banks(self):
  e=self.e(a=0x1234,x=0x5678,y=0x9abc,d=0xdef0,dbr=0x44,pbr=0x55,p=0,s=0x01ff)
  e.pha(); self.assertEqual([0x12,0x34],[v for _,_,v in e.mem.accesses]); e.mem.accesses.clear()
  e.phx(); self.assertEqual([0x56,0x78],[v for _,_,v in e.mem.accesses]); e.mem.accesses.clear()
  e.phy(); self.assertEqual([0x9a,0xbc],[v for _,_,v in e.mem.accesses]); e.mem.accesses.clear()
  e.phd(); self.assertEqual([0xde,0xf0],[v for _,_,v in e.mem.accesses]); e.mem.accesses.clear()
  e.phb(); e.phk(); e.php(); self.assertEqual([0x44,0x55,e.s.p],[v for _,_,v in e.mem.accesses])
 def test_pull_registers_and_flags(self):
  e=self.e(p=0,s=0x01f9,a=0,x=0,y=0,d=0,dbr=0)
  # PLB, PLD, PLA, PLX, PLY in isolated engines to make expected stack simple.
  x=self.e(s=0x01fe); x.mem.bytes[0x01ff]=0x80; x.plb(); self.assertEqual(0x80,x.s.dbr); self.assertTrue(x.flag(N))
  x=self.e(s=0x01fd); x.mem.bytes.update({0x01fe:0x34,0x01ff:0x12}); x.pld(); self.assertEqual(0x1234,x.s.d)
  x=self.e(s=0x01fd,p=0); x.mem.bytes.update({0x01fe:0x78,0x01ff:0x56}); x.pla(); self.assertEqual(0x5678,x.s.a)
  x=self.e(s=0x01fd,p=0); x.mem.bytes.update({0x01fe:0x78,0x01ff:0x56}); x.plx(); self.assertEqual(0x5678,x.s.x)
  x=self.e(s=0x01fd,p=0); x.mem.bytes.update({0x01fe:0xbc,0x01ff:0x9a}); x.ply(); self.assertEqual(0x9abc,x.s.y)
 def test_all_register_transfer_mnemonics(self):
  # Each is checked in a fresh native 16-bit engine so source values are unambiguous.
  cases=[('TAX','x',0x1234),('TAY','y',0x1234),('TCD','d',0x1234),('TCS','s',0x1234)]
  for m,reg,w in cases:
   e=self.e(a=0x1234); e.transfer(m); self.assertEqual(w,getattr(e.s,reg),m)
  e=self.e(d=0x2345); e.transfer('TDC'); self.assertEqual(0x2345,e.s.a)
  e=self.e(s=0x3456); e.transfer('TSC'); self.assertEqual(0x3456,e.s.a)
  e=self.e(s=0x4567); e.transfer('TSX'); self.assertEqual(0x4567,e.s.x)
  e=self.e(x=0x5678); e.transfer('TXA'); self.assertEqual(0x5678,e.s.a)
  e=self.e(x=0x6789); e.transfer('TXS'); self.assertEqual(0x6789,e.s.s)
  e=self.e(x=0x789a); e.transfer('TXY'); self.assertEqual(0x789a,e.s.y)
  e=self.e(y=0x89ab); e.transfer('TYA'); self.assertEqual(0x89ab,e.s.a)
  e=self.e(y=0x9abc); e.transfer('TYX'); self.assertEqual(0x9abc,e.s.x)
 def test_push_effective_forms(self):
  e=self.e(pc=0x8003,s=0x01ff); e.pea(0x1234); self.assertEqual([0x12,0x34],[v for _,_,v in e.mem.accesses])
  e=self.e(pc=0x8003,s=0x01ff); e.per(0xfffd); self.assertEqual([0x80,0x00],[v for _,_,v in e.mem.accesses])
  e=self.e(s=0x01ff); e.pei(0xabcd); self.assertEqual([0xab,0xcd],[v for _,_,v in e.mem.accesses])
 def test_jump_variants(self):
  e=self.e(pbr=0x12); e.jmp(0x3456); self.assertEqual((0x12,0x3456),(e.s.pbr,e.s.pc)); e.jmp(0xab789a,long=True); self.assertEqual((0xab,0x789a),(e.s.pbr,e.s.pc))
 def test_interrupt_software_cop_and_hardware_break_bit(self):
  h=self.e(e=1,p=MFLAG|XFLAG,pc=0x8002); h.interrupt_entry(0x9000,hardware=True); self.assertEqual(0,[v for k,a,v in h.mem.accesses if k=='W'][-1]&0x10)
  b=self.e(e=1,p=MFLAG|XFLAG,pc=0x8002); b.interrupt_entry(0x9000,hardware=False,software_kind='BRK'); self.assertNotEqual(0,[v for k,a,v in b.mem.accesses if k=='W'][-1]&0x10)
  c=self.e(e=1,p=MFLAG|XFLAG,pc=0x8002); c.interrupt_entry(0x9000,hardware=False,software_kind='COP'); self.assertEqual(0,[v for k,a,v in c.mem.accesses if k=='W'][-1]&0x10)
if __name__=='__main__': unittest.main()
