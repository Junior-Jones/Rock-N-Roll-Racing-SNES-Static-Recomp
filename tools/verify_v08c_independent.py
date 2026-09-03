#!/usr/bin/env python3
"""Independent Version 08C DMA/HDMA review.

This verifier deliberately does not import the V08 model or generator.  It
reconstructs the target-source census from frozen V04 evidence, checks target
ROM signatures, parses the pinned MesenCE source archive, and reviews emitted
V08 authority/runtime text independently.
"""
from __future__ import annotations
from pathlib import Path
import argparse,csv,hashlib,json,re,zipfile

ROM_SHA='9d721753301278325c851f1843d669a697aed757dcf6495a31fc31ddf664b182'
COUNT=[1,2,2,4,4,4,2,4]
OFF=[[0,0,0,0],[0,1,0,1],[0,0,0,0],[0,0,1,1],[0,1,2,3],[0,1,0,1],[0,0,0,0],[0,0,1,1]]
EXPECTED_420B={'096FE9','004073','002382','002325','00226F','009CD3','009CEE'}
EXPECTED_420C={'096FE9'}
EXPECTED_PROFILES={
 'SRC-80A24C-CH0-VRAM-0100':(0,'01','18','7E','DYNAMIC_DP_6A_6B','0100','01','00224C','00226F','test_source_80a24c_channel0_vram_mode1_0100',0x224C,38),
 'SRC-80A2FF-CH0-VRAM-0080':(0,'01','18','7E','DYNAMIC_DP_6A','0080','01','0022FF','002325','test_source_80a2ff_channel0_vram_mode1_0080',0x22FF,42),
 'SRC-80A35C-CH0-VRAM-0040':(0,'01','18','7E','DYNAMIC_DP_6A','0040','01','00235C','002382','test_source_80a35c_channel0_vram_mode1_0040',0x235C,42),
 'SRC-81F678-CH0-VRAM-1000':(0,'01','18','7E','3500','1000','SOURCE_CONFIG_ONLY','00F681;00F68E','','test_source_81f68e_channel0_vram_mode1_1000',0xF678,36),
 'SRC-80C2FC-CH3-CGRAM-0200':(3,'00','22','7E','2000','0200','08','0042FC','004073','test_source_80c2fc_channel3_cgram_mode0_0200',0x42FC,31),
 'SRC-819CC6-CH4-OAM-0100':(4,'00','04','7E','13FA','0100','10','009C6F;009CC6','009CD3','test_source_819cc6_channel4_oam_mode0_0100',0x9C6F,105),
 'SRC-819CE1-CH4-OAM-0010':(4,'00','04','7E','14FA','0010','10','009C6F;009CE1','009CEE','test_source_819ce1_channel4_oam_mode0_0010',0x9CE1,18),
 'SRC-926FE9-CLEAR-DMA-HDMA':(-1,'','','','','','00','096FE9','096FE9','test_source_926fe9_clears_mdmaen_and_hdmaen',0x96FE7,8),
}

def rows(path:Path):
 with path.open(newline='',encoding='utf-8') as f:return list(csv.DictReader(f))
def sha(b:bytes):return hashlib.sha256(b).hexdigest()
def member(z:zipfile.ZipFile,suffix:str)->str:
 names=[n for n in z.namelist() if n.endswith(suffix)]
 if len(names)!=1: raise RuntimeError(f'expected one {suffix}, got {len(names)}')
 return z.read(names[0]).decode('utf-8','replace')
def norm(s:str)->str:return re.sub(r'\s+','',s)

def main()->int:
 ap=argparse.ArgumentParser();ap.add_argument('--project',type=Path,required=True);ap.add_argument('--rom',type=Path,required=True);ap.add_argument('--mesen-source-zip',type=Path,required=True);a=ap.parse_args();p=a.project.resolve();errs=[]
 rom=a.rom.read_bytes()
 if len(rom)!=0x100000 or sha(rom)!=ROM_SHA:errs.append('target ROM identity')
 # Independent frozen-source census.
 access=rows(p/'docs/V04C-memory-accesses.csv'); regs={}
 for r in access:
  for ea in r['Effective_Addresses'].split(';'):
   q=ea.strip().upper()[-4:]
   if q in ('420B','420C') or ('4300'<=q<='437F'):
    regs.setdefault(q,set()).add(r['Physical'].upper())
 chans=sorted({int(k[2],16) for k in regs if k.startswith('43')})
 if chans!=[0,3,4]:errs.append(f'frozen source channels {chans}')
 if regs.get('420B')!=EXPECTED_420B:errs.append('frozen $420B source set')
 if regs.get('420C')!=EXPECTED_420C:errs.append('frozen $420C source set')
 # Ledger/profile reconstruction and exact ROM byte signatures.
 led=rows(p/'docs/V08C-source-dma-configurations.csv')
 if len(led)!=8 or {r['Profile'] for r in led}!=set(EXPECTED_PROFILES):errs.append('source profile universe')
 tests=(p/'tests/unit/test_v08c_dma_controller.py').read_text()
 for r in led:
  e=EXPECTED_PROFILES.get(r['Profile'])
  if not e:continue
  fields=(int(r['Channel']),r['DMAP'],r['BBAD'],r['A1B'],r['A1T'],r['DAS'],r['MDMAEN'],r['Setup_Physical'],r['Start_Physical'],r['Named_Test'])
  if fields!=e[:10]:errs.append('profile fields '+r['Profile'])
  if r['Named_Test'] not in tests:errs.append('missing named test '+r['Named_Test'])
  off,n=e[10],e[11]
  if r['ROM_Signature_SHA256']!=sha(rom[off:off+n]):errs.append('ROM signature '+r['Profile'])
 # Emitted summary/generator manifest.
 s=json.loads((p/'docs/V08C-dma-summary.json').read_text())
 required_summary={'milestone':'V08C','construction_authority':'ROM_SOURCE_STATIC_PROOF_ONLY','production_contexts':2258,'scheduler_executable_contexts':2250,'source_proved_rom_bytes':4803,'general_dma_channels_implemented':8,'general_transfer_modes_implemented':8,'source_reached_named_profiles':8,'source_proved_nonzero_hdma_enable':False,'v09_ppu_payload_semantics':False,'static_core_compilation_performed':False}
 for k,v in required_summary.items():
  if s.get(k)!=v:errs.append('summary '+k)
 if s.get('source_reached_dma_channels')!=[0,3,4] or s.get('transfer_byte_count')!=COUNT or s.get('transfer_offsets')!=OFF:errs.append('summary tables/source channels')
 if any(s.get(k) for k in ('gameplay_promotion_count','trace_promotion_count','oracle_promotion_count','context_promotion_count')):errs.append('promotion count')
 man=json.loads((p/'generated/current/v08c/V08C-GENERATED-SHA256.json').read_text())
 for rel,h in man.get('files',{}).items():
  if sha((p/rel).read_bytes())!=h:errs.append('generated manifest '+rel)
 # Pinned MesenCE source review.
 try:
  with zipfile.ZipFile(a.mesen_source_zip) as z:
   dc=member(z,'SnesDmaController.cpp'); mm=member(z,'SnesMemoryManager.cpp')
 except Exception as e:
  errs.append('Mesen source archive '+str(e));dc=mm=''
 ndc=norm(dc);nmm=norm(mm)
 source_checks=[
  ('mode byte counts','_transferByteCount[8]={1,2,2,4,4,4,2,4}' in ndc),
  ('mode offset rows',all(norm('{'+','.join(map(str,row))+'}') in ndc for row in OFF)),
  ('DAS wrap decrement','channel.TransferSize--' in dc and 'do {' in dc),
  ('start alignment','8 - (_memoryManager->GetMasterClock() & 0x07)' in dc),
  ('end alignment','cpuSpeed - (_dmaClockCounter % cpuSpeed)' in dc),
  ('WRAM restriction','addressBusB != 0x2180 || !_memoryManager->IsWorkRam(addressBusA)' in dc),
  ('indirect HDMA','HdmaIndirectAddressing' in dc),
  ('last active HDMA oddity','IsLastActiveHdmaChannel' in dc),
  ('priority flags',all(x in dc for x in ('_hdmaPending','_hdmaInitPending','_dmaPending'))),
  ('DMA A-bus B-bus exclusion','forBusA && handler == _registerHandlerB.get() && (addr & 0xFF00) == 0x2100' in mm),
  ('DMA controller re-entry exclusion','0x420B' in mm and '0x420C' in mm and '0x4300' in mm),
 ]
 for n,ok in source_checks:
  if not ok:errs.append('Mesen source '+n)
 # Runtime structural authority. This is source review, not compilation.
 c=(p/'runtime/v08c_machine.c').read_text();h=(p/'runtime/v08c_machine.h').read_text();nc=norm(c)
 runtime_checks=[
  ('eight count table','jsv08_dma_count[8]={1u,2u,2u,4u,4u,4u,2u,4u}' in nc),
  ('eight offset table','jsv08_dma_offset[8][4]' in c and all(norm('{'+','.join(str(x)+'u' for x in row)+'}') in nc for row in OFF)),
  ('8 channels','channel[8]' in h),
  ('V07 timing retained','js_v07c_timing_plan' in c and '#include "js_v07c_timing.h"' in h),
  ('PPU ordered seam','js_v08c_set_ppu_dma_seam' in c and 'JSV08PpuDmaRead' in h and 'JSV08PpuDmaWrite' in h),
  ('pending priority state','dma_pending_mask' in c and 'dma_pending_mask' in h and 'JSV08_DMA_HDMA_LINE' in c and 'JSV08_DMA_HDMA_INIT' in c and 'JSV08_DMA_MANUAL' in c),
  ('old V07 transfer stop removed','STOP_DMA_TRANSFER_V08' not in c and 'STOP_DMA_TRANSFER_V08' not in h),
  ('no runtime opcode decoder','switch(opcode' not in c and 'RunOp' not in c),
  ('DAS do-while','do{' in nc and 'transfer_size=(uint16_t)(c->transfer_size-1u)' in nc),
  ('A-bus exclusions','jsv08_dma_a_hits_b' in c and 'jsv08_dma_a_hits_controller' in c),
  ('WRAM restriction','ab==0x2180u&&jsv08_dma_is_wram(aa)' in nc),
 ]
 for n,ok in runtime_checks:
  if not ok:errs.append('runtime '+n)
 # Bracket balance after deleting comments/quoted strings catches gross source damage without invoking a C compiler.
 for rel,text in [('runtime/v08c_machine.c',c),('runtime/v08c_machine.h',h)]:
  t=re.sub(r'/\*.*?\*/','',text,flags=re.S);t=re.sub(r'//.*','',t);t=re.sub(r'"(?:\\.|[^"\\])*"','""',t);t=re.sub(r"'(?:\\.|[^'\\])*'","''",t)
  for x,y in [('(',')'),('{','}'),('[',']')]:
   if t.count(x)!=t.count(y):errs.append(f'{rel} unbalanced {x}{y}')
 if errs:
  print('V08C INDEPENDENT: FAIL');print('\n'.join(errs));return 1
 print(f'V08C INDEPENDENT: PASS profiles={len(led)} source_channels=0,3,4 contexts=2258 executable=2250 modes=8 channels=8 mesen_dma_sha256={sha(dc.encode())[:16]}')
 return 0
if __name__=='__main__':raise SystemExit(main())
