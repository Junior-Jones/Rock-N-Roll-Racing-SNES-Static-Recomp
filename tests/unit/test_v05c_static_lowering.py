import csv,hashlib,json,re,unittest
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]

def rows(rel):
 with (ROOT/rel).open(encoding='utf-8',newline='') as f:return list(csv.DictReader(f))
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()

class V05CStaticLoweringTests(unittest.TestCase):
 def test_projection_counts_and_byte_coverage(self):
  s=json.loads((ROOT/'docs/V05C-lowering-summary.json').read_text())
  self.assertEqual(('05C',2258,2158,4803,2238,20,12,2488,18),(s['milestone'],s['production_context_keys'],s['unique_pbr_pc'],s['source_proved_rom_bytes'],s['native_body_keys'],s['named_boundary_keys'],s['mixed_fail_closed_keys'],s['successor_relations'],s['shard_count']))
  self.assertFalse(s['runtime_opcode_decoder']);self.assertEqual((0,0,0),(s['gameplay_promotions'],s['trace_promotions'],s['oracle_promotions']))
  m=rows('docs/V05C-production-manifest.csv');self.assertEqual(2258,len(m));self.assertEqual(4803,len({i for r in m for i in range(int(r['Physical'],16),int(r['Physical'],16)+int(r['Length']))}))
 def test_generated_hash_manifest_and_source_count(self):
  d=ROOT/'generated/current/v05c';h=json.loads((d/'V05C-GENERATED-SHA256.json').read_text());self.assertEqual(20,len(h['files']))
  for f in h['files']:
   p=ROOT/f['path'];self.assertEqual(f['size'],p.stat().st_size);self.assertEqual(f['sha256'],sha(p))
  self.assertEqual(19,len(list(d.glob('*.c'))));self.assertEqual(1,len(list(d.glob('*.h'))));self.assertEqual(18,len(list(d.glob('js_v05c_shard_*.c'))))
 def test_production_build_allowlist_is_exact(self):
  got=[x.strip() for x in (ROOT/'config/build-source-allowlist.txt').read_text().splitlines() if x.strip() and not x.lstrip().startswith('#')]
  shards=[f'generated/current/v05c/{p.name}' for p in sorted((ROOT/'generated/current/v05c').glob('js_v05c_shard_*.c'))]
  want=['runtime/v05c_static_cpu.c','runtime/v05c_static_cpu.h','generated/current/v05c/js_v05c_dispatch.c','generated/current/v05c/js_v05c_dispatch.h']+shards
  self.assertEqual(want,got);self.assertEqual((20,2),(sum(x.endswith('.c') for x in got),sum(x.endswith('.h') for x in got)))
  self.assertFalse(any(x.startswith(('analysis/','oracle/','tools/','tests/','research/','generator/')) for x in got))
 def test_static_dispatch_contract_and_no_decoder(self):
  d=ROOT/'generated/current/v05c';texts=[p.read_text() for p in list(d.glob('*.c'))+list(d.glob('*.h'))+[ROOT/'runtime/v05c_static_cpu.c',ROOT/'runtime/v05c_static_cpu.h']];alltext='\n'.join(texts)
  self.assertIn('JS_STOP_UNKNOWN_CONTEXT',(d/'js_v05c_dispatch.c').read_text());self.assertIn('JS_STOP_BUS_UNAVAILABLE',alltext)
  for bad in ('RunOp','Mesen','decode_context','OPCODES[','gameplay trace','oracle trace'):self.assertNotIn(bad,alltext)
  keys=[]
  for p in d.glob('js_v05c_shard_*.c'):
   keys += [int(x,16) for x in re.findall(r'case\s+(0x[0-9A-F]+)u:\s*\{',p.read_text())]
  self.assertEqual(2258,len(keys));self.assertEqual(2258,len(set(keys)))
 def test_boundary_and_successor_projection(self):
  m=rows('docs/V05C-production-manifest.csv');self.assertEqual(20,sum(r['Disposition']=='NAMED_BOUNDARY' for r in m));self.assertEqual(2238,sum(r['Disposition']=='NATIVE_BODY' for r in m));self.assertEqual(12,sum(bool(r['Boundary_Classes']) and r['Disposition']=='NATIVE_BODY' for r in m))
  self.assertEqual(2488,len(rows('docs/V05C-successors.csv')))
  b=rows('docs/V05C-boundary-projection.csv');self.assertEqual(57,sum(int(r['Boundary_Row_Count']) for r in b));self.assertEqual({'DYNAMIC_TARGET','INTERRUPT_REENTRY','RETURN'},{r['Class'] for r in b})
if __name__=='__main__':unittest.main()
