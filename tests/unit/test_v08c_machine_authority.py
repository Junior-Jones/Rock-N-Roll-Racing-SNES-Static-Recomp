from __future__ import annotations
import csv,hashlib,json,re,subprocess,unittest
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]

def sha(b:bytes):return hashlib.sha256(b).hexdigest()

class V08CMachineAuthorityTests(unittest.TestCase):
    def test_v07_predecessor_specific_files_unchanged_from_tag(self):
        cert=json.loads((ROOT/'config/v08c-accepted-predecessor-certificate.json').read_text())
        self.assertEqual(cert['git_tag'],'V07C')
        for rel,expected in cert['files'].items():
            self.assertEqual(sha((ROOT/rel).read_bytes()),expected,rel)
            if (ROOT/'.git').exists():
                tagged=subprocess.check_output(['git','-C',str(ROOT),'show',f"V07C:{rel}"])
                self.assertEqual(sha(tagged),expected,rel)

    def test_runtime_is_v08_with_frozen_v07_timing_plan(self):
        build=[x for x in (ROOT/'config/build-source-allowlist.txt').read_text().splitlines() if x and not x.startswith('#')]
        self.assertIn('runtime/v08c_machine.c',build)
        self.assertIn('runtime/v08c_machine.h',build)
        self.assertNotIn('runtime/v07c_machine.c',build)
        self.assertNotIn('runtime/v07c_machine.h',build)
        self.assertIn('generated/current/v07c/js_v07c_timing.c',build)
        self.assertIn('generated/current/v07c/js_v07c_timing.h',build)

    def test_runtime_controller_is_general_and_fail_closed(self):
        c=(ROOT/'runtime/v08c_machine.c').read_text();h=(ROOT/'runtime/v08c_machine.h').read_text()
        self.assertIn('jsv08_dma_count[8]',c);self.assertIn('jsv08_dma_offset[8][4]',c);self.assertIn('channel[8]',h)
        self.assertIn('js_v08c_set_ppu_dma_seam',c);self.assertIn('JSV08_STOP_PPU_UNAVAILABLE',c)
        self.assertIn('dma_pending_mask',c);self.assertIn('jsv08_dma_a_hits_controller',c);self.assertIn('jsv08_dma_a_hits_b',c)
        self.assertNotIn('STOP_DMA_TRANSFER_V08',c+h)
        self.assertNotIn('switch(opcode',c);self.assertNotIn('RunOp',c)

    def test_runtime_source_delimiters_balanced_without_compiling(self):
        for rel in ('runtime/v08c_machine.c','runtime/v08c_machine.h'):
            s=(ROOT/rel).read_text();t=re.sub(r'/\*.*?\*/','',s,flags=re.S);t=re.sub(r'//.*','',t);t=re.sub(r'"(?:\\.|[^"\\])*"','""',t);t=re.sub(r"'(?:\\.|[^'\\])*'","''",t)
            for a,b in [('(',')'),('{','}'),('[',']')]:self.assertEqual(t.count(a),t.count(b),(rel,a,b))

    def test_generated_v08_manifest_and_summary_are_self_consistent(self):
        m=json.loads((ROOT/'generated/current/v08c/V08C-GENERATED-SHA256.json').read_text())
        for rel,h in m['files'].items():self.assertEqual(sha((ROOT/rel).read_bytes()),h,rel)
        s=json.loads((ROOT/'docs/V08C-dma-summary.json').read_text())
        self.assertEqual((s['production_contexts'],s['scheduler_executable_contexts'],s['source_proved_rom_bytes']),(2258,2250,4803))
        self.assertEqual((s['general_dma_channels_implemented'],s['general_transfer_modes_implemented']),(8,8))
        self.assertEqual(s['source_reached_dma_channels'],[0,3,4]);self.assertEqual(s['source_reached_named_profiles'],8)
        self.assertFalse(any(s[k] for k in ('gameplay_promotion_count','trace_promotion_count','oracle_promotion_count','context_promotion_count')))
        self.assertFalse(s['static_core_compilation_performed']);self.assertFalse(s['v09_ppu_payload_semantics'])

    def test_all_eight_source_profiles_have_named_tests(self):
        with (ROOT/'docs/V08C-source-dma-configurations.csv').open(newline='',encoding='utf-8') as f:rows=list(csv.DictReader(f))
        self.assertEqual(len(rows),8);text=(ROOT/'tests/unit/test_v08c_dma_controller.py').read_text()
        for r in rows:self.assertIn('def '+r['Named_Test']+'(',text)

    def test_no_v08_context_or_byte_promotion(self):
        s=json.loads((ROOT/'docs/V08C-dma-summary.json').read_text())
        v7=json.loads((ROOT/'docs/V07C-scheduler-summary.json').read_text())
        self.assertEqual(s['production_contexts'],v7['production_contexts'])
        self.assertEqual(s['scheduler_executable_contexts'],v7['scheduler_executable_contexts'])
        self.assertEqual(s['source_proved_rom_bytes'],4803)

if __name__=='__main__':unittest.main()
