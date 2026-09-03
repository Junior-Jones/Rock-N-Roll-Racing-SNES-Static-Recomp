from __future__ import annotations
import argparse,csv,hashlib,json,re,zipfile
from pathlib import Path
ROM='9d721753301278325c851f1843d669a697aed757dcf6495a31fc31ddf664b182'
def sha(b):return hashlib.sha256(b).hexdigest()
def eff(s):
 for t in re.split(r'[;,| ]+',s):
  if t:
   try:yield int(t,16)&0xffff
   except ValueError:pass

def main():
 p=argparse.ArgumentParser();p.add_argument('--project',type=Path,required=True);p.add_argument('--rom',type=Path,required=True);p.add_argument('--mesen-source-zip',type=Path,required=True);a=p.parse_args();r=a.project
 assert sha(a.rom.read_bytes())==ROM
 # independently reconstruct admitted direct PPU register set
 hit=set()
 with (r/'docs/V04C-memory-accesses.csv').open(newline='',encoding='utf-8') as f:
  for row in csv.DictReader(f):
   for x in eff(row['Effective_Addresses']):
    if 0x2100<=x<=0x213f: hit.add(x)
 rows=list(csv.DictReader((r/'docs/V09C-source-ppu-registers.csv').open(newline='',encoding='utf-8')))
 declared={int(x['Register'],16) for x in rows if x['Reached']=='YES'}
 assert hit <= declared and len(hit)==46 and len(rows)==64
 assert all(x['Implemented']=='YES' for x in rows)
 assert all(x['Certified']=='YES' for x in rows if x['Reached']=='YES')
 sites=list(csv.DictReader((r/'docs/V09C-source-ppu-access-sites.csv').open(newline='',encoding='utf-8')))
 assert len(sites)>0 and {int(x['Register'],16) for x in sites}==declared
 assert all(x['Path'] in ('CPU_DIRECT','DMA_BBUS') for x in sites)
 s=json.loads((r/'docs/V09C-ppu-summary.json').read_text());assert s['source_reached_register_count']==47 and s['ppu_registers_implemented']==64
 assert s['shared_cpu_dma_ppu_state'] and s['renderer_dependent_fail_closed'] and not s['renderer_implemented']
 assert (s['production_contexts'],s['scheduler_executable_contexts'],s['source_proved_rom_bytes'])==(2258,2250,4803)
 assert all(s[k]==0 for k in ('gameplay_promotion_count','trace_promotion_count','oracle_promotion_count','context_promotion_count'))
 c=(r/'runtime/v09c_machine.c').read_text();h=(r/'runtime/v09c_machine.h').read_text();ppu=(r/'runtime/v09c_ppu.c').read_text()
 assert 'JSV09Ppu ppu;' in h and 'ppu_dma_opaque' not in h
 assert 'return jsv09_ppu_read(m,a,out,s)' in c and 'return jsv09_ppu_write(m,a,v,s)' in c
 assert 'if(r==JSV09_REGION_PPU)return jsv09_ppu_read' in c and 'if(r==JSV09_REGION_PPU)return jsv09_ppu_write' in c
 assert 'JSV09_STOP_PPU_RENDERER_V10' in c+h and 'JSV09_STOP_PPU_UNKNOWN_STATE' in c+h
 assert 'vram_known' in (r/'runtime/v09c_ppu.h').read_text() and 'cgram_known_hi' in (r/'runtime/v09c_ppu.h').read_text()
 for x in range(0x2100,0x2134): assert f'case 0x{x:04X}u:' in ppu,hex(x)
 for x in range(0x2134,0x2140): assert f'case 0x{x:04X}u:' in ppu,hex(x)
 assert 'return renderer(p); /* OBJ range/time-over require V10 sprite evaluation. */' in ppu
 # Pinned Mesen source anchors, without importing V09 generator/model.
 with zipfile.ZipFile(a.mesen_source_zip) as z:
  names=z.namelist();name=next(n for n in names if n.endswith('\\Core\\SNES\\SnesPpu.cpp'));raw=z.read(name);text=raw.decode('utf-8',errors='replace')
 assert 'case 0x2139:' in text and 'VramReadBuffer' in text and 'case 0x2122:' in text and 'CgramAddressLatch' in text
 assert 'case 0x2104:' in text and 'InternalOamAddress' in text and 'case 0x213F:' in text
 assert 'VramAddrIncrementOnSecondReg' in text and 'VramAddressRemapping' in text
 print(f'V09C INDEPENDENT: PASS direct_reached={len(hit)} declared={len(declared)} implemented=64 mesen_ppu_sha256={sha(raw)[:16]}')
if __name__=='__main__':main()
