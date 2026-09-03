from __future__ import annotations
import csv,json,unittest
from pathlib import Path
P=Path(__file__).resolve().parents[2]

def rr(path):
 with path.open(newline='',encoding='utf-8') as f:return list(csv.DictReader(f))

class V07TimingProjectionTests(unittest.TestCase):
 def test_01_exact_v05_key_projection_and_boundary_split(self):
  v5={r['Key_Hex']:r for r in rr(P/'docs/V05C-production-manifest.csv')}
  v7={r['Key_Hex']:r for r in rr(P/'docs/V07C-timing-manifest.csv')}
  self.assertEqual(set(v5),set(v7));self.assertEqual(len(v7),2258)
  self.assertEqual(sum(r['V07_Disposition']=='NATIVE_BODY' for r in v7.values()),2238)
  self.assertEqual(sum(r['V07_Disposition']=='SCHEDULER_INTERRUPT_RETURN_BODY' for r in v7.values()),12)
  self.assertEqual(sum(r['Timing_Class']=='BOUNDARY_NO_EXECUTION' for r in v7.values()),8)
  for k,r in v7.items():
   self.assertEqual(r['Opcode'],v5[k]['Opcode']);self.assertEqual(r['Mnemonic'],v5[k]['Mnemonic']);self.assertEqual(r['Mode'],v5[k]['Mode'])

 def test_02_cycle_and_access_accounting_matches_v02(self):
  v2={(r['Opcode'],r['E'],r['M'],r['X']):r for r in rr(P/'docs/V02C-opcode-context-matrix.csv') if r['Status']=='LEGAL'}
  for r in rr(P/'docs/V07C-timing-manifest.csv'):
   q=v2[(r['Opcode'],r['E'],r['M'],r['X'])]
   for k in ('Cycle_Min','Cycle_Max','Dynamic_Cycle_Tags','Fetch_Bytes','Pointer_Read_Bytes','Data_Read_Bytes','Data_Write_Bytes','Dummy_Write_Bytes','Stack_Read_Bytes','Stack_Write_Bytes','Vector_Read_Bytes'):
    self.assertEqual(r[k],q[k],(r['Key'],k))
   if r['V07_Disposition']!='NAMED_BOUNDARY':
    bus=sum(int(r[k]) for k in ('Fetch_Bytes','Pointer_Read_Bytes','Data_Read_Bytes','Data_Write_Bytes','Dummy_Write_Bytes','Stack_Read_Bytes','Stack_Write_Bytes','Vector_Read_Bytes'))
    self.assertEqual(int(r['Fixed_Idle_Cycles']),int(r['Cycle_Min'])-bus,r['Key'])
    self.assertEqual(int(r['Dynamic_Idle_Max']),int(r['Cycle_Max'])-int(r['Cycle_Min']),r['Key'])

 def test_03_special_order_classes_are_present(self):
  rows=rr(P/'docs/V07C-timing-manifest.csv')
  jsl=[r for r in rows if r['Mnemonic']=='JSL'];self.assertEqual(len(jsl),40)
  self.assertTrue(all(r['Timing_Class']=='JSL_DEFERRED_BANK_FETCH' and 'JSL_AFTER_PBR_PUSH_IDLE' in r['Timing_Rules'] for r in jsl))
  rts=[r for r in rows if r['Mnemonic']=='RTS'];self.assertEqual(len(rts),90)
  native_rts=[r for r in rts if r['V07_Disposition']=='NATIVE_BODY'];boundary_rts=[r for r in rts if r['V07_Disposition']=='NAMED_BOUNDARY']
  self.assertEqual(len(native_rts),87);self.assertEqual(len(boundary_rts),3)
  self.assertTrue(all(r['Timing_Class']=='RETURN_SEQUENCE' and r['Fixed_Idle_Cycles']=='3' for r in native_rts))
  self.assertTrue(all(r['Timing_Class']=='BOUNDARY_NO_EXECUTION' and r['Fixed_Idle_Cycles']=='0' for r in boundary_rts))
  rti=[r for r in rows if r['Mnemonic']=='RTI'];self.assertEqual(len(rti),12)
  self.assertTrue(all(r['V07_Disposition']=='SCHEDULER_INTERRUPT_RETURN_BODY' and r['Timing_Class']=='RETURN_SEQUENCE' and r['Fixed_Idle_Cycles']=='2' for r in rti))
  branches=[r for r in rows if r['Mode']=='REL8'];self.assertTrue(all(r['Timing_Class']=='BRANCH_SEQUENCE' for r in branches))

 def test_04_summary_forbids_approximate_path_and_promotions(self):
  s=json.loads((P/'docs/V07C-scheduler-summary.json').read_text())
  self.assertFalse(s['historical_approximate_v06_timing_path_active'])
  self.assertFalse(s['v06_files_modified'])
  self.assertEqual(s['production_contexts'],2258);self.assertEqual(s['scheduler_executable_contexts'],2250);self.assertEqual(s['v05_native_contexts'],2238);self.assertEqual(s['interrupt_return_contexts'],12);self.assertEqual(s['remaining_boundary_contexts'],8)
  for k in ('gameplay_promotion_count','trace_promotion_count','oracle_promotion_count','context_promotion_count'):self.assertEqual(s[k],0)
  self.assertEqual(s['compile_build_gate'],'DEFERRED_BY_USER_POLICY_NOT_RUN_AT_VERSION_END')

 def test_05_generated_lookup_is_context_key_not_opcode_decoder(self):
  text=(P/'generated/current/v07c/js_v07c_timing.c').read_text()
  self.assertIn('PLANS[m].key<key',text);self.assertNotIn('switch(opcode',text);self.assertNotIn('RunOp',text)
  self.assertEqual(text.count('BOUNDARY_NO_EXECUTION'),8)  # static rule metadata; never runtime opcode decode

if __name__=='__main__':unittest.main()
