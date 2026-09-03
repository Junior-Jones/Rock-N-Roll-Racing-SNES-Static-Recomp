import unittest
from analysis.w65c816.opcodes import OPCODES,iter_raw_contexts,instruction_length
from analysis.w65c816.access_contract import access_contract
class AccessContractTests(unittest.TestCase):
 def c(self,op,e=0,m=1,x=1): return access_contract(OPCODES[op],e,m,x)
 def test_fetch_matches_instruction_length_for_all_legal_contexts(self):
  for s,e,m,x,ok in iter_raw_contexts():
   if ok:self.assertEqual(instruction_length(s,m,x),access_contract(s,e,m,x).fetch_bytes)
 def test_width_access_shapes(self):
  self.assertEqual((1,0),(self.c(0xAD,m=1).data_read_bytes,self.c(0xAD,m=1).data_write_bytes))
  self.assertEqual(2,self.c(0xAD,m=0).data_read_bytes)
  self.assertEqual(2,self.c(0x8D,m=0).data_write_bytes)
  self.assertEqual(2,self.c(0x9C,m=0).data_write_bytes) # STZ width-aware
  self.assertEqual(2,self.c(0xAE,x=0).data_read_bytes)
 def test_rmw_write_order_and_emulation_dummy_write(self):
  c16=self.c(0x0E,e=0,m=0); self.assertEqual((2,2,'HIGH_THEN_LOW'),(c16.data_read_bytes,c16.data_write_bytes,c16.rmw_write_order))
  c8e=self.c(0x0E,e=1,m=1,x=1); self.assertEqual(1,c8e.dummy_write_bytes); self.assertEqual('LOW_FINAL',c8e.rmw_write_order)
  self.assertEqual(0,self.c(0x0E,e=0,m=1).dummy_write_bytes)
 def test_pointer_stack_vector_counts(self):
  self.assertEqual(2,self.c(0xB2).pointer_read_bytes); self.assertEqual(3,self.c(0xB7).pointer_read_bytes)
  self.assertEqual(2,self.c(0xD4).pointer_read_bytes); self.assertEqual(2,self.c(0xD4).stack_write_bytes)
  self.assertEqual((3,2),(self.c(0x00,e=1).stack_write_bytes,self.c(0x00,e=1).vector_read_bytes))
  self.assertEqual((4,2),(self.c(0x00,e=0).stack_write_bytes,self.c(0x00,e=0).vector_read_bytes))
  self.assertEqual(4,self.c(0x40,e=0).stack_read_bytes); self.assertEqual(3,self.c(0x40,e=1).stack_read_bytes)
 def test_context_cycle_adjustments_and_dynamic_ranges(self):
  self.assertEqual((2,3),(self.c(0xA9,m=1).cycle_min,self.c(0xA9,m=0).cycle_min))
  self.assertEqual(5,self.c(0xAD,m=0).cycle_min)
  self.assertEqual(6,self.c(0xBD,m=0,x=0).cycle_min)
  self.assertEqual(8,self.c(0x00,e=0,m=1,x=1).cycle_min)
  self.assertEqual(6,self.c(0x40,e=1,m=1,x=1).cycle_min)
  b=self.c(0xD0,e=1,m=1,x=1); self.assertEqual((2,4),(b.cycle_min,b.cycle_max)); self.assertIn('BRANCH_TAKEN:+1',b.dynamic_cycle_tags)
  bra=self.c(0x80,e=1,m=1,x=1); self.assertEqual((3,4),(bra.cycle_min,bra.cycle_max))
 def test_direct_page_penalty_wait_stop_block_annotations(self):
  self.assertIn('DIRECT_LOW_NONZERO:+1',self.c(0xA5).dynamic_cycle_tags)
  self.assertEqual('WAIT_UNTIL_INTERRUPT_SIGNAL',self.c(0xCB).wait_or_repeat)
  self.assertEqual('STOP_UNTIL_RESET',self.c(0xDB).wait_or_repeat)
  self.assertIn('REPEAT_7_CYCLES_PER_BYTE',self.c(0x54).wait_or_repeat)
 def test_every_legal_contract_has_sane_nonnegative_counts_and_cycles(self):
  for s,e,m,x,ok in iter_raw_contexts():
   if not ok: continue
   c=access_contract(s,e,m,x)
   for v in (c.fetch_bytes,c.pointer_read_bytes,c.data_read_bytes,c.data_write_bytes,c.dummy_write_bytes,c.stack_read_bytes,c.stack_write_bytes,c.vector_read_bytes,c.cycle_min,c.cycle_max): self.assertGreaterEqual(v,0)
   self.assertGreaterEqual(c.cycle_max,c.cycle_min)
if __name__=='__main__': unittest.main()
