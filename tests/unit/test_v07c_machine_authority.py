from __future__ import annotations
import csv,hashlib,json,re,subprocess,unittest
from pathlib import Path
P=Path(__file__).resolve().parents[2]

def rr(p):
 with p.open(newline='',encoding='utf-8') as f:return list(csv.DictReader(f))
def sha(b):return hashlib.sha256(b).hexdigest()

class V07MachineAuthorityTests(unittest.TestCase):
 def test_01_one_active_scheduler_build_authority_no_compile(self):
  lines=[x for x in (P/'config/build-source-allowlist.txt').read_text().splitlines() if x and not x.startswith('#')]
  self.assertEqual(sum(x.endswith('.c') for x in lines),22)
  self.assertEqual(sum(x.endswith('.h') for x in lines),4)
  self.assertFalse(any('v06c_machine' in x or '/v06c/' in x for x in lines))
  self.assertIn('runtime/v07c_machine.c',lines);self.assertIn('generated/current/v07c/js_v07c_timing.c',lines)
  self.assertTrue(all((P/x).is_file() for x in lines))

 def test_02_active_runtime_has_monotonic_scheduler_not_access_sum(self):
  c=(P/'runtime/v07c_machine.c').read_text();h=(P/'runtime/v07c_machine.h').read_text()
  self.assertNotIn('access_clock_sum',c+h)
  self.assertIn('master_clock',c);self.assertIn('JSV07_RESET_STARTUP_CLOCKS',c)
  self.assertIn('clocks-4u',c);self.assertIn('jsv07_read_effect',c)
  self.assertRegex(c,r'js_v07c_scheduler_advance_wall\(&m->scheduler,clocks\);jsv07_event\(&m->scheduler,24u,a\);return jsv07_write_effect')
  self.assertIn('JSV07_DRAM_REFRESH_CLOCKS',c);self.assertIn('JSV07_HDMA_LINE_HCLOCK',c)
  self.assertIn('JSV07_SMP_RATIO_NUM',c);self.assertIn('JSV07_SMP_RATIO_DEN',c)
  self.assertNotIn('switch(opcode',c);self.assertNotIn('RunOp',c)

 def test_03_v06_accepted_machine_files_remain_byte_exact(self):
  rels=('runtime/v06c_machine.c','runtime/v06c_machine.h','generated/current/v06c/js_v06c_fetch.c','generated/current/v06c/js_v06c_fetch.h')
  if (P/'.git').exists():
   for rel in rels:
    accepted=subprocess.check_output(['git','show',f'V06C:{rel}'],cwd=P)
    self.assertEqual(sha((P/rel).read_bytes()),sha(accepted),rel)
  else:
   cert=json.loads((P/'config/accepted-predecessor-certificate.json').read_text())
   self.assertEqual(cert['git_tag'],'V06C')
   for rel in rels:self.assertEqual(sha((P/rel).read_bytes()),cert['files'][rel],rel)

 def test_04_interrupt_reentry_uses_existing_keys_only(self):
  rows=rr(P/'docs/V07C-timing-manifest.csv');keys={r['Key_Hex'] for r in rows}
  self.assertEqual(len(keys),2258)
  rti=[r for r in rows if r['V07_Disposition']=='SCHEDULER_INTERRUPT_RETURN_BODY']
  self.assertEqual(len(rti),12);self.assertTrue(all(r['Mnemonic']=='RTI' for r in rti))
  self.assertEqual(sum(r['V07_Disposition']=='NAMED_BOUNDARY' for r in rows),8)
  for addr in ('008166','0081FD'):
   xs=[r for r in rows if r['Address']==addr]
   self.assertEqual(len(xs),5);self.assertTrue(all(r['V07_Disposition']=='NATIVE_BODY' for r in xs))

 def test_05_runtime_interrupt_and_rti_fail_closed(self):
  c=(P/'runtime/v07c_machine.c').read_text()
  self.assertIn('0xFFFAu:0xFFFEu',c);self.assertIn('0xFFEAu:0xFFEEu',c)
  self.assertGreaterEqual(c.count('js_v07c_timing_plan('),3)
  self.assertIn('JSV07_STOP_UNADMITTED_INTERRUPT_TARGET',c)
  self.assertIn('if(p->opcode==0x40u&&p->v07_executable)',c)
  self.assertIn('p->opcode==0xFCu',c)

 def test_06_timing_runtime_owns_special_ordering(self):
  c=(P/'runtime/v07c_machine.c').read_text()
  for name in ('JSV07_RULE_JSL_AFTER_PBR_PUSH_IDLE','JSV07_RULE_JSR_PRE_STACK_IDLE','JSV07_RULE_RETURN_PRE_IDLE',
               'JSV07_RULE_RTS_POST_POP_IDLE','JSV07_RULE_RMW_INTERMEDIATE_IDLE','JSV07_RULE_DYN_DIRECT_LOW_PRE_IDLE',
               'JSV07_RULE_DYN_INDEX_PRE_DATA_IDLE','JSV07_RULE_DYN_BRANCH_TAKEN_POST_IDLE'):
   self.assertIn(name,c)
  self.assertIn('JSV07_STOP_TIMING_PLAN_MISMATCH',c)
  self.assertIn('cycles!=expected',c)

 def test_07_later_subsystems_are_named_seams(self):
  c=(P/'runtime/v07c_machine.c').read_text()
  for name in ('JSV07_STOP_PPU_UNAVAILABLE','JSV07_STOP_APU_UNAVAILABLE','JSV07_STOP_DMA_TRANSFER_V08','JSV07_STOP_INPUT_V11'):
   self.assertIn(name,c)
  self.assertIn('jsv07_queue_dma(sc,JSV07_DMA_MANUAL)',c)
  self.assertIn('sc->hdma_enable_mask=v',c)
  self.assertNotIn('dma_transfer_byte',c.lower())

 def test_08_summary_and_policy_match_no_build_no_promotions(self):
  s=json.loads((P/'docs/V07C-scheduler-summary.json').read_text())
  self.assertEqual(s['scheduler_executable_contexts'],2250);self.assertEqual(s['remaining_boundary_contexts'],8)
  for k in ('gameplay_promotion_count','trace_promotion_count','oracle_promotion_count','context_promotion_count'):self.assertEqual(s[k],0)
  self.assertEqual(s['compile_build_gate'],'DEFERRED_BY_USER_POLICY_NOT_RUN_AT_VERSION_END')
  policy=json.loads((P/'config/workflow-policy.json').read_text())
  self.assertFalse(policy['compile_or_build_at_version_end'])

if __name__=='__main__':unittest.main()
