from __future__ import annotations
import json,unittest
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
class V10_1MachineAuthority(unittest.TestCase):
 def test_active_build_selects_v10_1_and_frozen_predecessors(self):
  b=[x for x in (ROOT/'config/build-source-allowlist.txt').read_text().splitlines() if x and not x.startswith('#')]
  for x in ('runtime/v10_1_machine.c','runtime/v10_1_machine.h','runtime/v10_1_apu.c','runtime/v10_1_apu.h','runtime/v09c_ppu.c','runtime/v09c_ppu.h','generated/current/v07c/js_v07c_timing.c','generated/current/v07c/js_v07c_timing.h'):self.assertIn(x,b)
  self.assertNotIn('runtime/v09c_machine.c',b)
 def test_cpu_and_dma_share_one_apu(self):
  h=(ROOT/'runtime/v10_1_machine.h').read_text();c=(ROOT/'runtime/v10_1_machine.c').read_text();self.assertEqual(h.count('JSV10_1Apu apu;'),1);self.assertIn('jsv10_1_dma_read_b',c);self.assertIn('jsv10_1_apu_read(m,a,out,s)',c);self.assertIn('jsv10_1_apu_write(m,a,v,s)',c)
 def test_frontier_is_exact_0400_aot(self):
  h=(ROOT/'runtime/v10_1_machine.h').read_text();c=(ROOT/'runtime/v10_1_machine.c').read_text();self.assertIn('JSV10_1_STOP_SMP_AOT_REQUIRED',h);self.assertIn('s->smp_pc=m->apu.entry_pc',c)
 def test_rational_scheduler_seam_reused(self):
  c=(ROOT/'runtime/v10_1_machine.c').read_text();self.assertIn('m->scheduler.smp_target_cycle',c);self.assertIn('js_v10_1_apu_sync',c)
 def test_v09_ppu_retained_not_forked(self):
  h=(ROOT/'runtime/v10_1_machine.h').read_text();c=(ROOT/'runtime/v10_1_machine.c').read_text();self.assertIn('#include "v09c_ppu.h"',h);self.assertIn('js_v09c_ppu_read',c);self.assertIn('js_v09c_ppu_write',c)
 def test_no_runtime_spc_opcode_decoder(self):
  s=(ROOT/'runtime/v10_1_apu.c').read_text()+(ROOT/'runtime/v10_1_machine.c').read_text();self.assertNotIn('switch(opcode',s);self.assertNotIn('switch(_opCode',s);self.assertNotIn('RunOp',s)
 def test_generated_claim_boundary(self):
  s=json.loads((ROOT/'docs/V10.1-aram-summary.json').read_text());self.assertEqual((s['production_s_cpu_contexts'],s['scheduler_executable_s_cpu_contexts'],s['source_proved_s_cpu_rom_bytes']),(2258,2250,4803));self.assertEqual(s['known_aram_bytes_at_frontier'],58607);self.assertFalse(s['exact_uploaded_spc700_aot_implemented']);self.assertFalse(s['static_core_compilation_performed'])
 def test_policy_keeps_build_deferred(self):
  p=json.loads((ROOT/'config/workflow-policy.json').read_text());self.assertFalse(p['compile_or_build_at_version_end']);self.assertTrue(p['compile_or_build_only_on_explicit_user_request'])
if __name__=='__main__':unittest.main()
