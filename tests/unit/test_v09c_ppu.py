from __future__ import annotations
import csv,hashlib,json,re,subprocess,unittest
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
def sha(p:Path):return hashlib.sha256(p.read_bytes()).hexdigest()
class V09CPpuTests(unittest.TestCase):
 def test_inventory_is_complete_and_reached_separated(self):

  with (ROOT/'docs/V09C-source-ppu-registers.csv').open(newline='',encoding='utf-8') as f: rows=list(csv.DictReader(f))
  self.assertEqual(len(rows),64);self.assertTrue(all(r['Implemented']=='YES' for r in rows))
  reached=[r for r in rows if r['Reached']=='YES'];self.assertEqual(len(reached),47);self.assertTrue(all(r['Certified']=='YES' for r in reached))
 def test_direct_source_reach_is_46_and_dma_adds_cgram_data(self):

  with (ROOT/'docs/V09C-source-ppu-registers.csv').open(newline='',encoding='utf-8') as f: rows={r['Register']:r for r in csv.DictReader(f)}
  direct=[r for r in rows.values() if int(r['Direct_Read_Count'])+int(r['Direct_Write_Count'])]
  self.assertEqual(len(direct),46);self.assertEqual(rows['2122']['Direct_Write_Count'],'0');self.assertGreater(int(rows['2122']['DMA_Delivery_Count']),0)
 def test_all_write_register_cases_present(self):
  s=(ROOT/'runtime/v09c_ppu.c').read_text()
  for a in range(0x2100,0x2134):self.assertIn(f'case 0x{a:04X}u:',s,hex(a))
 def test_all_read_register_cases_present(self):
  s=(ROOT/'runtime/v09c_ppu.c').read_text()
  for a in range(0x2134,0x2140):self.assertIn(f'case 0x{a:04X}u:',s,hex(a))
 def test_single_ppu_object_shared_by_cpu_and_dma(self):
  h=(ROOT/'runtime/v09c_machine.h').read_text();c=(ROOT/'runtime/v09c_machine.c').read_text()
  self.assertIn('JSV09Ppu ppu;',h);self.assertNotIn('ppu_dma_opaque',h)
  self.assertIn('return jsv09_ppu_read(m,a,out,s)',c);self.assertIn('return jsv09_ppu_write(m,a,v,s)',c)
  self.assertIn('if(r==JSV09_REGION_PPU)return jsv09_ppu_read',c);self.assertIn('if(r==JSV09_REGION_PPU)return jsv09_ppu_write',c)
 def test_renderer_dependent_cases_fail_closed(self):
  c=(ROOT/'runtime/v09c_ppu.c').read_text();m=(ROOT/'runtime/v09c_machine.c').read_text()
  self.assertIn('if(!can_oam(p,a))return renderer(p);',c);self.assertIn('if(!can_cgram(p,a))return renderer(p);',c)
  self.assertIn('if(!can_vram(p,a))return renderer(p);',c);self.assertIn('JSV09_STOP_PPU_RENDERER_V10',m)
 def test_unknown_memory_is_tracked_and_fails_closed(self):
  h=(ROOT/'runtime/v09c_ppu.h').read_text();c=(ROOT/'runtime/v09c_ppu.c').read_text();m=(ROOT/'runtime/v09c_machine.c').read_text()
  for x in ('vram_known','oam_known','cgram_known_lo','cgram_known_hi','vram_read_buffer_known'):self.assertIn(x,h)
  self.assertIn('return unknown(p);',c);self.assertIn('JSV09_STOP_PPU_UNKNOWN_STATE',m)
 def test_vram_remap_modes_match_pinned_formulas(self):
  c=(ROOT/'runtime/v09c_ppu.c').read_text()
  for x in ('(a&0xFF00u)|((a&0x00E0u)>>5)|((a&0x001Fu)<<3)','(a&0xFE00u)|((a&0x01C0u)>>6)|((a&0x003Fu)<<3)','(a&0xFC00u)|((a&0x0380u)>>7)|((a&0x007Fu)<<3)'):self.assertIn(x,c)
 def test_vram_read_buffer_is_delayed_and_access_gated(self):
  c=(ROOT/'runtime/v09c_ppu.c').read_text()
  self.assertIn('p->vram_read_buffer',c);self.assertIn('update_vram_buffer(p,a)',c);self.assertIn('p->vram_address=(uint16_t)((p->vram_address+p->vram_increment)&0x7FFFu)',c)
 def test_cgram_high_read_uses_ppu2_open_bus_bit7(self):
  c=(ROOT/'runtime/v09c_ppu.c').read_text();self.assertIn('(p->ppu2_open_bus&0x80u)',c);self.assertIn('p->ppu2_open_bus=v',c)
 def test_oam_pair_buffer_and_high_table_owned(self):
  c=(ROOT/'runtime/v09c_ppu.c').read_text();self.assertIn('p->oam_write_buffer',c);self.assertIn('0x200u|(a&0x1Fu)',c);self.assertIn('internal_oam_address',c)
 def test_inidisp_forced_blank_oam_reset_side_effect(self):
  c=(ROOT/'runtime/v09c_ppu.c').read_text();self.assertIn('if(p->forced_blank&&a->scanline==a->nmi_scanline)',c)
 def test_stat78_resets_hv_toggles(self):
  c=(ROOT/'runtime/v09c_ppu.c').read_text();frag=re.search(r'case 0x213Fu:.*?return JSV09_PPU_OK;',c,re.S).group(0);self.assertIn('p->hloc_toggle=0u',frag);self.assertIn('p->vloc_toggle=0u',frag)
 def test_stat77_is_renderer_owned_until_v10(self):
  c=(ROOT/'runtime/v09c_ppu.c').read_text();self.assertIn('case 0x213Eu:return renderer(p);',c)
 def test_summary_preserves_static_authority_counts(self):
  s=json.loads((ROOT/'docs/V09C-ppu-summary.json').read_text());self.assertEqual((s['production_contexts'],s['scheduler_executable_contexts'],s['source_proved_rom_bytes']),(2258,2250,4803));self.assertFalse(s['renderer_implemented']);self.assertTrue(s['knownness_tracking'])
 def test_no_gameplay_trace_or_oracle_promotions(self):
  s=json.loads((ROOT/'docs/V09C-ppu-summary.json').read_text());self.assertTrue(all(s[k]==0 for k in ('gameplay_promotion_count','trace_promotion_count','oracle_promotion_count','context_promotion_count')))
 def test_runtime_delimiters_balanced_without_compilation(self):
  for rel in ('runtime/v09c_machine.c','runtime/v09c_machine.h','runtime/v09c_ppu.c','runtime/v09c_ppu.h'):
   s=(ROOT/rel).read_text();t=re.sub(r'/\*.*?\*/','',s,flags=re.S);t=re.sub(r'//.*','',t);t=re.sub(r'"(?:\\.|[^"\\])*"','""',t)
   for a,b in [('(',')'),('{','}'),('[',']')]:self.assertEqual(t.count(a),t.count(b),(rel,a,b))

 def test_access_site_provenance_covers_every_reached_register(self):
  with (ROOT/'docs/V09C-source-ppu-registers.csv').open(newline='',encoding='utf-8') as f: rows=list(csv.DictReader(f))
  with (ROOT/'docs/V09C-source-ppu-access-sites.csv').open(newline='',encoding='utf-8') as f: sites=list(csv.DictReader(f))
  self.assertEqual({r['Register'] for r in rows if r['Reached']=='YES'},{x['Register'] for x in sites})
  self.assertTrue(all(x['Path'] in ('CPU_DIRECT','DMA_BBUS') for x in sites))
  self.assertTrue(all(r['Observed_Value_Domain']=='NOT_USED_AS_STATIC_AUTHORITY' for r in rows))

 def test_generated_manifest_self_consistent(self):
  m=json.loads((ROOT/'generated/current/v09c/V09C-GENERATED-SHA256.json').read_text())
  for rel,h in m['files'].items():self.assertEqual(sha(ROOT/rel),h,rel)
 def test_v08_predecessor_files_match_tag(self):
  cert=json.loads((ROOT/'config/v09c-accepted-predecessor-certificate.json').read_text())
  self.assertEqual(cert['git_commit'],'268c7d3fa9ee18c9dc88e87e88a96adf7562d5b9')
  for rel,h in cert['files'].items():
   self.assertEqual(sha(ROOT/rel),h,rel)
   if (ROOT/'.git').exists():self.assertEqual(hashlib.sha256(subprocess.check_output(['git','-C',str(ROOT),'show',f'V08C:{rel}'])).hexdigest(),h,rel)
if __name__=='__main__':unittest.main()
