#!/usr/bin/env python3
"""Independent V06C review. Deliberately does not import V06 model/generator."""
from pathlib import Path
import argparse,csv,hashlib,json,re
from collections import Counter

def sha(p):
 h=hashlib.sha256();h.update(p.read_bytes());return h.hexdigest()

def region(a):
 b=(a>>16)&255;o=a&65535;sysb=b<=0x3f or 0x80<=b<=0xbf
 if b in (0x7e,0x7f):return 'WRAM'
 if sysb:
  if o<=0x1fff:return 'WRAM'
  if 0x2100<=o<=0x213f:return 'PPU'
  if 0x2140<=o<=0x217f:return 'APU'
  if 0x2180<=o<=0x2183:return 'WRAM_PORT'
  if o in (0x4016,0x4017) or 0x4218<=o<=0x421f:return 'INPUT'
  if 0x4200<=o<=0x4217:return 'CPU_IO'
  if 0x4300<=o<=0x437f:return 'DMA'
 if o>=0x8000:return 'ROM'
 return 'OPEN_BUS'
def roff(a):
 b=(a>>16)&255;o=a&65535
 if b in (0x7e,0x7f) or o<0x8000:return None
 return ((b&31)<<15)|(o&0x7fff)
def clocks(a,ms):
 bg=(a>>22)&3;p=(a>>8)&255
 if bg==1:return 8
 if bg==3:return 6 if ms else 8
 if p<=0x1f:return 8
 if p<=0x3f:return 6
 if p<=0x41:return 12
 if p<=0x5f:return 6
 if p<=0x7f:return 8
 if bg==0:return 8
 return 6 if ms else 8

def main():
 ap=argparse.ArgumentParser();ap.add_argument('--project',type=Path,required=True);ap.add_argument('--rom',type=Path,required=True);a=ap.parse_args();p=a.project.resolve();rb=a.rom.read_bytes();errs=[]
 if hashlib.sha256(rb).hexdigest()!='9d721753301278325c851f1843d669a697aed757dcf6495a31fc31ddf664b182':errs.append('ROM hash')
 cnt=Counter(region(x) for x in range(1<<24));doc={r['Region']:int(r['Address_Count']) for r in csv.DictReader((p/'docs/V06C-bus-census.csv').open())}
 if dict(cnt)!=doc:errs.append(f'bus census mismatch {cnt} != {doc}')
 sp=Counter()
 for ms in (0,1):
  for b in range(256):
   for pg in range(256):sp[(ms,clocks((b<<16)|(pg<<8),ms))]+=1
 got={(int(r['MEMSEL']),int(r['Master_Clocks'])):int(r['Cell_Count']) for r in csv.DictReader((p/'docs/V06C-speed-census.csv').open())}
 if dict(sp)!=got:errs.append('speed census mismatch')
 v5={r['Key_Hex']:r for r in csv.DictReader((p/'docs/V05C-production-manifest.csv').open())};v6={r['Key_Hex']:r for r in csv.DictReader((p/'docs/V06C-fetch-manifest.csv').open())}
 if set(v5)!=set(v6) or len(v6)!=2258:errs.append('fetch key projection')
 for k,r in v6.items():
  if r['Bytes']!=v5[k]['Bytes']:errs.append('byte projection '+k);break
  b=int(r['PBR'],16);pc=int(r['PC'],16)
  for i,x in enumerate(bytes.fromhex(r['Bytes'])):
   o=roff((b<<16)|((pc+i)&65535))
   if o is None or rb[o]!=x:errs.append('ROM byte '+k);break
 src=(p/'runtime/v06c_machine.c').read_text()
 if 'master_clock' in src or '% JSV06_ROM_SIZE' in src or '& 0x1Fu' not in src:errs.append('C source mapper/timing policy')
 if src.count('JSV06_STOP_PPU_UNAVAILABLE')<2 or src.count('JSV06_STOP_APU_UNAVAILABLE')<2 or src.count('JSV06_STOP_DMA_UNAVAILABLE')<2 or src.count('JSV06_STOP_INPUT_UNAVAILABLE')<2:errs.append('component stops')
 build=[x.strip() for x in (p/'config/build-source-allowlist.txt').read_text().splitlines() if x.strip() and not x.startswith('#')]
 c=[x for x in build if x.endswith('.c')];h=[x for x in build if x.endswith('.h')]
 if len(c)!=40 or len(h)!=4:errs.append(f'build list {len(c)}C {len(h)}H')
 if any(x.startswith(('analysis/','generator/','tools/','tests/','oracle/','research/')) for x in build):errs.append('nonproduction build input')
 summary=json.loads((p/'docs/V06C-machine-summary.json').read_text())
 for k in ('gameplay_promotion_count','trace_promotion_count','oracle_promotion_count','v05_context_promotion_count'):
  if summary[k]!=0:errs.append(k)
 if errs:
  print('V06C INDEPENDENT: FAIL');print('\n'.join(errs));return 1
 print(f"V06C INDEPENDENT: PASS addresses={sum(cnt.values())} timing_cells={sum(sp.values())} contexts={len(v6)} regions={dict(cnt)}")
 return 0
if __name__=='__main__':raise SystemExit(main())
