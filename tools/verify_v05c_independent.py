#!/usr/bin/env python3
"""Independent V05C projection reviewer.

Does not import the V05 generator. Reconstructs the admitted production key set
from frozen V04 CSV authority, validates instruction definitions against the raw
ROM and frozen V02 opcode/E/M/X matrix, then reconciles V05 manifests/generated
sources/build inputs. Gameplay traces and oracle output are not inputs.
"""
from __future__ import annotations
import argparse,csv,hashlib,json,re
from collections import Counter,defaultdict
from pathlib import Path
ROM_SHA256='9d721753301278325c851f1843d669a697aed757dcf6495a31fc31ddf664b182'
TARGET_RE=re.compile(r'^([0-9A-F]{2}):([0-9A-F]{4}):E([01])M([01])X([01])')
CASE_RE=re.compile(r'^\s*case\s+(0x[0-9A-Fa-f]+)u:\s*\{')

def sha(p): return hashlib.sha256(p.read_bytes()).hexdigest()
def rows(p):
 with p.open(encoding='utf-8',newline='') as f:return list(csv.DictReader(f))
def kt(r):return (int(r['PBR'],16),int(r['PC'],16),int(r['E']),int(r['M']),int(r['X']))
def ki(k):return ((((k[0]<<16)|k[1])<<3)|(k[2]<<2)|(k[3]<<1)|k[4])
def tx(k):return f'{k[0]:02X}:{k[1]:04X}:E{k[2]}M{k[3]}X{k[4]}'
def parse(s):
 m=TARGET_RE.match(s); assert m,s; return tuple(int(m.group(i),16) for i in range(1,6))

def main():
 ap=argparse.ArgumentParser();ap.add_argument('rom',type=Path);ap.add_argument('--artifact-root',type=Path,required=True);a=ap.parse_args();root=a.artifact_root.resolve();rom=a.rom.resolve();data=rom.read_bytes();assert len(data)==1048576 and sha(rom)==ROM_SHA256
 v04=rows(root/'docs/V04C-contexts.csv'); ed=rows(root/'docs/V04C-edges.csv'); bd=rows(root/'docs/V04C-fail-closed-boundaries.csv')
 idkey={r['Context_ID']:kt(r) for r in v04}; grouped=defaultdict(list)
 for r in v04:grouped[kt(r)].append(r)
 canonical={}
 for k,rs in grouped.items():
  sig={(r['Physical'],r['Opcode'],r['Mnemonic'],r['Mode'],r['Length'],r['Bytes']) for r in rs};assert len(sig)==1,(k,sig);canonical[k]=rs[0]
 assert len(canonical)==2258
 succ=defaultdict(set)
 for r in ed:succ[idkey[r['From']]].add(parse(r['To']))
 assert all(t in canonical for ts in succ.values() for t in ts)
 bclasses=defaultdict(Counter)
 for r in bd:bclasses[parse(r['Context'])][r['Class']]+=1
 assert len([k for k in canonical if not succ.get(k)])==20
 assert len([k for k in bclasses if succ.get(k)])==12

 # Frozen V02 matrix is an independent instruction/context definition source.
 matrix={(int(r['Opcode'],16),int(r['E']),int(r['M']),int(r['X'])):r for r in rows(root/'docs/V02C-opcode-context-matrix.csv') if r['Status']=='LEGAL'}
 assert len(matrix)==1280
 phys=set()
 for k,r in canonical.items():
  raw=bytes.fromhex(r['Bytes']);off=int(r['Physical'],16); assert data[off:off+len(raw)]==raw,(tx(k),off)
  m=matrix[(int(r['Opcode'],16),k[2],k[3],k[4])]
  assert (m['Mnemonic'],m['Mode'],int(m['Instruction_Bytes']))==(r['Mnemonic'],r['Mode'],int(r['Length'])),(tx(k),m,r)
  phys.update(range(off,off+len(raw)))
 assert len(phys)==4803

 pm=rows(root/'docs/V05C-production-manifest.csv'); assert len(pm)==2258
 pby={r['Key']:r for r in pm}; assert len(pby)==2258
 for k,r in canonical.items():
  q=pby[tx(k)]; assert int(q['Key_Hex'],16)==ki(k); assert q['Physical']==r['Physical'];assert q['Bytes']==r['Bytes'];assert q['Mnemonic']==r['Mnemonic'];assert q['Mode']==r['Mode'];assert int(q['Length'])==int(r['Length']);assert int(q['Shard'],16)==(((k[0]<<16)|k[1])>>10);assert int(q['Successor_Count'])==len(succ.get(k,set()));assert q['Disposition']==('NATIVE_BODY' if succ.get(k) else 'NAMED_BOUNDARY')
 assert len({r['Shard'] for r in pm})==18

 v5s={(parse(r['From_Key']),parse(r['To_Key'])) for r in rows(root/'docs/V05C-successors.csv')}
 v4s={(s,t) for s,ts in succ.items() for t in ts}; assert v5s==v4s and len(v5s)==2488

 bproj=rows(root/'docs/V05C-boundary-projection.csv'); expected=[]
 for k in sorted(bclasses,key=ki):
  for cls,count in sorted(bclasses[k].items()):expected.append((tx(k),cls,count,bool(succ.get(k))))
 got=[(r['Key'],r['Class'],int(r['Boundary_Row_Count']),r['Has_Proved_Successor']=='YES') for r in bproj]; assert got==expected

 summary=json.loads((root/'docs/V05C-lowering-summary.json').read_text()); assert summary['production_context_keys']==2258 and summary['unique_pbr_pc']==2158 and summary['source_proved_rom_bytes']==4803 and summary['native_body_keys']==2238 and summary['named_boundary_keys']==20 and summary['mixed_fail_closed_keys']==12 and summary['successor_relations']==2488 and summary['shard_count']==18; assert summary['runtime_opcode_decoder'] is False and summary['gameplay_promotions']==summary['trace_promotions']==summary['oracle_promotions']==0

 gen=root/'generated/current/v05c'; h=json.loads((gen/'V05C-GENERATED-SHA256.json').read_text());assert len(h['files'])==20
 for f in h['files']:
  p=root/f['path'];assert p.stat().st_size==f['size'];assert sha(p)==f['sha256']
 cfiles=sorted(gen.glob('*.c'));hfiles=sorted(gen.glob('*.h'));assert len(cfiles)==19 and len(hfiles)==1
 casekeys=[]
 for p in gen.glob('js_v05c_shard_*.c'):
  for line in p.read_text().splitlines():
   m=CASE_RE.match(line)
   if m:casekeys.append(int(m.group(1),16))
 assert len(casekeys)==2258 and set(casekeys)=={ki(k) for k in canonical}
 allsrc='\n'.join(p.read_text() for p in cfiles+hfiles+[root/'runtime/v05c_static_cpu.c',root/'runtime/v05c_static_cpu.h'])
 forbidden=['RunOp','Mesen','OPCODES[','decode_context','runtime opcode','gameplay trace','oracle trace']
 for s in forbidden: assert s not in allsrc,s
 assert 'JS_STOP_UNKNOWN_CONTEXT' in (gen/'js_v05c_dispatch.c').read_text()
 assert allsrc.count('JS_STOP_UNPROVED_DYNAMIC_TARGET')>=1 and allsrc.count('JS_STOP_UNPROVED_INTERRUPT_REENTRY')>=1 and allsrc.count('JS_STOP_UNPROVED_RETURN')>=1

 allow=[x.strip() for x in (root/'config/build-source-allowlist.txt').read_text().splitlines() if x.strip() and not x.lstrip().startswith('#')]
 expected_build=['runtime/v05c_static_cpu.c','runtime/v05c_static_cpu.h','generated/current/v05c/js_v05c_dispatch.c','generated/current/v05c/js_v05c_dispatch.h']+[f'generated/current/v05c/{p.name}' for p in sorted(gen.glob('js_v05c_shard_*.c'))]
 assert allow==expected_build,(allow,expected_build);assert len([x for x in allow if x.endswith('.c')])==20 and len([x for x in allow if x.endswith('.h')])==2
 print(f'V05C independent projection review: PASS; keys={len(canonical)} bytes={len(phys)} successors={len(v5s)} boundaries=20 mixed=12 shards=18')
if __name__=='__main__':main()
