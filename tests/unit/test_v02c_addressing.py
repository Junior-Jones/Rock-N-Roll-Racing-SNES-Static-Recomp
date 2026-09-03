import unittest
from analysis.w65c816.opcodes import OPCODES
from analysis.w65c816.addressing import *
from analysis.w65c816.semantics import CPUState,Memory
class AddressingTests(unittest.TestCase):
 def state(self,**kw):
  d=dict(e=0,p=0,pbr=0x12,dbr=0x34,pc=0x8000,d=0,s=0x01f0,x=0,y=0); d.update(kw); return CPUState(**d)
 def test_all_declared_modes_resolve(self):
  modes={s.mode for s in OPCODES}; self.assertEqual(30,len(modes))
  mem=Memory(); mem.set_bytes(0,[0x34,0x12,0x56]); mem.set_bytes(0x120000,[0x78,0x56,0x34])
  for mode in modes:
   s=self.state(); operand=0
   try: resolve(mode,s,operand,mem)
   except KeyError as exc: self.fail(f'unimplemented mode {mode}: {exc}')
 def test_program_data_long_and_wrap(self):
  s=self.state(x=2,y=2)
  self.assertEqual(0x125678,resolve('ABS_JUMP',s,0x5678).effective)
  self.assertEqual(0x345678,resolve('ABS',s,0x5678).effective)
  self.assertEqual(0x350000,resolve('ABS_X',s,0xfffe).effective)
  self.assertEqual(0x000001,resolve('ABS_LONG_X',s,0xffffff).effective)
 def test_relative_wrap_and_page_cross(self):
  s=self.state(pc=0x0001,pbr=0x88)
  r=resolve('REL8',s,0xfe); self.assertEqual(0x88ffff,r.effective); self.assertTrue(r.page_crossed)
  self.assertEqual(0x88ffff,resolve('REL16',s,0xfffe).effective)
 def test_direct_emulation_page_rule_and_native_add(self):
  e=self.state(e=1,p=0x30,d=0x1200,x=2); e.normalize()
  self.assertEqual(0x12ff,direct_address(e,0xff)); self.assertEqual(0x1201,direct_address(e,0x101))
  n=self.state(e=0,d=0x12ff,x=2); self.assertEqual(0x1301,direct_address(n,2))
 def test_dp_indexed_indirect_emulation_cross_page_bug(self):
  s=self.state(e=1,p=0x30,d=0x12ff,x=0); s.normalize(); mem=Memory(); mem.bytes[0x12ff]=0x34; mem.bytes[0x1200]=0x56; mem.bytes[0x1300]=0xaa
  ptr,reads=direct_indirect_word(s,mem,0,indexed_x_bug=True)
  self.assertEqual(0x5634,ptr); self.assertEqual((0x12ff,0x1200),reads)
 def test_long_direct_indirect_does_not_use_emulation_page_shortcut(self):
  s=self.state(e=1,p=0x30,d=0x1200); s.normalize(); mem=Memory(); mem.bytes.update({0x12ff:1,0x1300:2,0x1301:3})
  ptr,reads=direct_indirect_long(s,mem,0xff); self.assertEqual(0x030201,ptr); self.assertEqual((0x12ff,0x1300,0x1301),reads)
 def test_pei_direct_word_crosses_page_in_emulation(self):
  s=self.state(e=1,p=0x30,d=0); s.normalize(); mem=Memory(); mem.bytes.update({0xff:0x34,0x100:0x12,0:0xaa})
  value,reads=pei_pointer_word(s,mem,0xff); self.assertEqual(0x1234,value); self.assertEqual((0xff,0x100),reads)
 def test_indirect_pointer_wraps(self):
  s=self.state(pbr=0x44,x=1); mem=Memory(); mem.bytes.update({0xffff:0x78,0:0x56,0x440000:0x34,0x440001:0x12})
  r=resolve('ABS_IND',s,0xffff,mem); self.assertEqual((0xffff,0),r.pointer_reads); self.assertEqual(0x445678,r.effective)
  r=resolve('ABS_X_IND',s,0xffff,mem); self.assertEqual((0x440000,0x440001),r.pointer_reads); self.assertEqual(0x441234,r.effective)
 def test_stack_relative_and_stack_relative_indirect_y(self):
  s=self.state(s=0xfffe,y=2,dbr=0x7e); mem=Memory(); mem.bytes.update({0x0003:0xfe,0x0004:0xff})
  self.assertEqual(3,resolve('STACK_REL',s,5).effective)
  r=resolve('STACK_REL_IND_Y',s,5,mem); self.assertEqual((3,4),r.pointer_reads); self.assertEqual(0x7f0000,r.effective)
if __name__=='__main__': unittest.main()
