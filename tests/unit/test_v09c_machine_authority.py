from __future__ import annotations
import json,re,unittest
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
class V09CMachineAuthority(unittest.TestCase):
 def test_active_build_selects_v09_and_frozen_v07_timing(self):
  b=[x for x in (ROOT/'config/build-source-allowlist.txt').read_text().splitlines() if x and not x.startswith('#')]
  for x in ('runtime/v09c_machine.c','runtime/v09c_machine.h','runtime/v09c_ppu.c','runtime/v09c_ppu.h','generated/current/v07c/js_v07c_timing.c','generated/current/v07c/js_v07c_timing.h'):self.assertIn(x,b)
  self.assertNotIn('runtime/v08c_machine.c',b);self.assertNotIn('runtime/v08c_machine.h',b)
 def test_v08_general_dma_controller_is_retained_in_v09(self):
  c=(ROOT/'runtime/v09c_machine.c').read_text();self.assertIn('jsv09_dma_count[8]',c);self.assertIn('jsv09_dma_offset[8][4]',c);self.assertIn('channel[i]',c)
 def test_ppu_write_updates_scheduler_display_contract(self):
  c=(ROOT/'runtime/v09c_machine.c').read_text();self.assertIn('m->scheduler.forced_blank=m->ppu.forced_blank',c);self.assertIn('js_v09c_scheduler_set_display(&m->scheduler,m->ppu.overscan,m->ppu.screen_interlace)',c)
 def test_no_runtime_opcode_decoder_added(self):
  s=(ROOT/'runtime/v09c_machine.c').read_text()+(ROOT/'runtime/v09c_ppu.c').read_text();self.assertNotIn('switch(opcode',s);self.assertNotIn('RunOp',s)
 def test_policy_keeps_build_deferred(self):
  p=json.loads((ROOT/'config/workflow-policy.json').read_text());self.assertFalse(p['compile_or_build_at_version_end']);self.assertTrue(p['compile_or_build_only_on_explicit_user_request'])
if __name__=='__main__':unittest.main()
