from __future__ import annotations
import argparse,csv,hashlib,json,re,zipfile
from pathlib import Path
ROM_SHA='9d721753301278325c851f1843d669a697aed757dcf6495a31fc31ddf664b182'
IPL_SHA='c95f88b299030d5afa55b1031e2b5ef2dff650c4b4e6bb6f8b1359436521278f'
def main():
 p=argparse.ArgumentParser();p.add_argument('--project',type=Path,required=True);p.add_argument('--rom',type=Path,required=True);p.add_argument('--mesen-source-zip',type=Path,required=True);a=p.parse_args();root=a.project;rom=a.rom.read_bytes();assert hashlib.sha256(rom).hexdigest()==ROM_SHA and len(rom)==0x100000
 # Reconstruct four source-proved call selectors independently from frozen V04 facts.
 ctx=list(csv.DictReader((root/'docs/V04C-contexts.csv').open(newline='',encoding='utf-8')));edges=list(csv.DictReader((root/'docs/V04C-edges.csv').open(newline='',encoding='utf-8')))
 expected=[('80:F8E0','0078E0','0000'),('80:F8E5','0078E5','0001'),('80:F8EA','0078EA','0002'),('80:F8EF','0078EF','0003')]
 for cpu,phys,x in expected:
  q=[r for r in ctx if r['PBR']+':'+r['PC']==cpu and r['Physical']==phys];assert len(q)==1;row=q[0];assert row['Mnemonic']=='JSR' and row['Bytes'].upper()=='2038FA' and row['XR']==x and row['Root']=='emulation_reset';assert any(e['From']==row['Context_ID'] and e['Edge_Kind']=='SOURCE_PROVED_CALL' and e['To'].startswith('80:FA38:') for e in edges)
 # Parse chain directly from ROM without importing V10 model.
 p0=0x10000;records=[];known=bytearray(0x10000);aram=bytearray(0x10000)
 for x in range(1,0xF0):known[x]=1
 for sel in range(4):
  size=int.from_bytes(rom[p0:p0+2],'little');dest=int.from_bytes(rom[p0+2:p0+4],'little');entry=int.from_bytes(rom[p0+4:p0+6],'little') or 0xFFC0;payload=rom[p0+6:p0+6+size];assert size>0 and dest+size<=0x10000
  for i,b in enumerate(payload):addr=dest+i;assert not (known[addr] and not (1<=addr<0xF0));aram[addr]=b;known[addr]=1
  records.append((p0,size,dest,entry,hashlib.sha256(payload).hexdigest()));p0+=6+size
 assert [(x[0],x[1],x[2],x[3]) for x in records]==[(0x10000,4032,0x0400,0xFFC0),(0x10FC6,49936,0x3800,0xFFC0),(0x1D2DC,1105,0x1400,0xFFC0),(0x1D733,3295,0x2000,0x0400)]
 assert sum(x[1] for x in records)==58368 and sum(known)==58607
 h=hashlib.sha256();h.update(b'RNR-V10.1-ARAM\0');h.update(aram);h.update(known);assert h.hexdigest()=='54e09724cf5839203d4a5515ef7e1fa70fdbf3b61c905e6cf222bb1d052f4a34'
 # Independent pinned Mesen source check: immutable 64-byte IPL and APUIO/ROM-overlay anchors.
 with zipfile.ZipFile(a.mesen_source_zip) as z:
  names=z.namelist();hn=next(n for n in names if n.endswith('Core\\SNES\\Spc.h') or n.endswith('Core/SNES/Spc.h'));cn=next(n for n in names if n.endswith('Core\\SNES\\Spc.cpp') or n.endswith('Core/SNES/Spc.cpp'));hs=z.read(hn).decode('utf-8',errors='replace');cs=z.read(cn).decode('utf-8',errors='replace')
 m=re.search(r'_spcBios\[64\]\s*\{(.*?)\};',hs,re.S);assert m;ipl=bytes(int(x,16) for x in re.findall(r'0x([0-9A-Fa-f]{2})',m.group(1)));assert len(ipl)==64 and hashlib.sha256(ipl).hexdigest()==IPL_SHA
 for needle in ('_state.OutputReg[0]','_state.NewCpuRegs[0] = _state.CpuRegs[0] = 0','_state.RomEnabled = true','addr >= 0xFFC0 && _state.RomEnabled','_spcBios[addr & 0x3F]'):assert needle in cs
 # Generated reports must agree, but are not used to derive facts above.
 s=json.loads((root/'docs/V10.1-aram-summary.json').read_text());assert s['uploaded_aram_bytes']==58368 and s['known_aram_bytes_at_frontier']==58607 and s['final_uploaded_entry']=='0400';assert all(s[k]==0 for k in ('gameplay_promotion_count','trace_promotion_count','oracle_pc_promotion_count'))
 wr=json.loads((root/'docs/V10.1-wram-epoch-summary.json').read_text());assert wr['admitted_executable_wram_epochs']==0
 rt=(root/'runtime/v10_1_apu.c').read_text()+(root/'runtime/v10_1_machine.c').read_text();assert 'switch(opcode' not in rt and 'RunOp' not in rt;assert 'JSV10_1_STOP_SMP_AOT_REQUIRED' in rt and 'm->scheduler.smp_target_cycle' in rt
 print('V10.1 independent review: PASS (4 upload records, 58368 uploaded bytes, 58607 known ARAM bytes, fixed IPL pinned, $0400 AOT frontier)')
if __name__=='__main__':main()
