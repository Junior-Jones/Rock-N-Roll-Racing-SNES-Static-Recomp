import csv, unittest
from pathlib import Path
from analysis.w65c816.opcodes import OPCODES,iter_raw_contexts,instruction_length
from analysis.w65c816.semantics import SUPPORTED_MNEMONICS,semantic_family
from analysis.w65c816.access_contract import access_contract
from analysis.w65c816.decode import decode_context,DecodeContextError
ROOT=Path(__file__).resolve().parents[2]
class OpcodeMatrixTests(unittest.TestCase):
 def test_256_opcodes_and_2048_raw_contexts_exact(self):
  self.assertEqual(256,len(OPCODES)); self.assertEqual(set(range(256)),{s.opcode for s in OPCODES})
  rows=list(iter_raw_contexts()); self.assertEqual(2048,len(rows))
  self.assertEqual(1280,sum(ok for *_,ok in rows)); self.assertEqual(768,sum(not ok for *_,ok in rows))
  self.assertTrue(all((not e) or (m==1 and x==1) for _,e,m,x,ok in rows if ok))
 def test_all_mnemonics_have_semantic_family(self):
  mn={s.mnemonic for s in OPCODES}; self.assertEqual(mn,SUPPORTED_MNEMONICS); self.assertEqual(92,len(mn))
  for m in mn: self.assertTrue(semantic_family(m))
 def test_fail_closed_decoder_all_raw_contexts(self):
  for spec,e,m,x,ok in iter_raw_contexts():
   if ok:
    d=decode_context(spec.opcode,e,m,x); self.assertEqual(spec,d.spec); self.assertEqual(instruction_length(spec,m,x),d.length)
   else:
    with self.assertRaises(DecodeContextError): decode_context(spec.opcode,e,m,x)
  for bad in (-1,256):
   with self.assertRaises(DecodeContextError): decode_context(bad,0,1,1)
  with self.assertRaises(DecodeContextError): decode_context(0,2,1,1)
 def test_variable_immediate_lengths(self):
  lda=OPCODES[0xA9]; ldx=OPCODES[0xA2]
  self.assertEqual((2,3),(instruction_length(lda,1,1),instruction_length(lda,0,1)))
  self.assertEqual((2,3),(instruction_length(ldx,1,1),instruction_length(ldx,1,0)))
 def test_every_legal_row_is_named_for_semantic_and_address_regression(self):
  n=0
  for s,e,m,x,ok in iter_raw_contexts():
   if ok:
    c=access_contract(s,e,m,x); n+=1
    self.assertTrue(c.semantic_test.startswith('SEM_')); self.assertTrue(c.addressing_test.startswith('ADDR_'))
  self.assertEqual(1280,n)
 def test_committed_wdc_reference_has_256_exact_rows(self):
  p=ROOT/'docs/reference/V02C-WDC-TABLE-5-4.csv'
  with p.open(encoding='utf-8') as f: rows=list(csv.DictReader(f))
  self.assertEqual(256,len(rows))
  for spec,row in zip(OPCODES,rows):
   self.assertEqual(f'{spec.opcode:02X}',row['Opcode']); self.assertEqual(spec.wdc_mnemonic,row['WDC_Mnemonic'])
   self.assertEqual(spec.mode,row['Project_Mode']); self.assertEqual(spec.base_cycles,int(row['Base_Cycles'])); self.assertEqual(spec.base_bytes,int(row['Base_Bytes']))
if __name__=='__main__': unittest.main()
