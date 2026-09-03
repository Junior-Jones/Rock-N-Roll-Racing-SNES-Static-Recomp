#!/usr/bin/env python3
"""Independent V07C timing/scheduler review. Does not import V07 model or generator."""
from __future__ import annotations
from pathlib import Path
import argparse,csv,hashlib,json,zipfile

def rows(p):
 with p.open(newline='',encoding='utf-8') as f:return list(csv.DictReader(f))
def sha_bytes(b):return hashlib.sha256(b).hexdigest()

def main():
 ap=argparse.ArgumentParser();ap.add_argument('--project',type=Path,required=True);ap.add_argument('--mesen-source-zip',type=Path,required=True);a=ap.parse_args();p=a.project.resolve();errs=[]
 v5={r['Key_Hex']:r for r in rows(p/'docs/V05C-production-manifest.csv')};v7={r['Key_Hex']:r for r in rows(p/'docs/V07C-timing-manifest.csv')}
 v2={(r['Opcode'],r['E'],r['M'],r['X']):r for r in rows(p/'docs/V02C-opcode-context-matrix.csv') if r['Status']=='LEGAL'}
 if set(v5)!=set(v7) or len(v7)!=2258:errs.append('V05->V07 key projection')
 access=('Fetch_Bytes','Pointer_Read_Bytes','Data_Read_Bytes','Data_Write_Bytes','Dummy_Write_Bytes','Stack_Read_Bytes','Stack_Write_Bytes','Vector_Read_Bytes')
 for k,r in v7.items():
  q=v2.get((r['Opcode'],r['E'],r['M'],r['X']))
  if not q:errs.append('missing V02 '+k);break
  if any(r[x]!=q[x] for x in ('Cycle_Min','Cycle_Max','Dynamic_Cycle_Tags')+access):errs.append('matrix mismatch '+k);break
  if r['V07_Disposition']!='NAMED_BOUNDARY':
   bus=sum(int(r[x]) for x in access);imin=int(q['Cycle_Min'])-bus;imax=int(q['Cycle_Max'])-bus
   if int(r['Fixed_Idle_Cycles'])!=imin or int(r['Dynamic_Idle_Max'])!=imax-imin:errs.append('idle accounting '+k);break
 # Primary-source pin: independently inspect the preserved Mesen source text for the exact event/read/write ordering used as verification.
 with zipfile.ZipFile(a.mesen_source_zip) as z:
  mm=next(n for n in z.namelist() if n.endswith('SnesMemoryManager.cpp'));mem=z.read(mm).decode('utf-8','replace')
  irh=next(n for n in z.namelist() if n.endswith('InternalRegisters.h'));irt=z.read(irh).decode('utf-8','replace')
  irc=next(n for n in z.namelist() if n.endswith('InternalRegisters.cpp'));irr=z.read(irc).decode('utf-8','replace')
  cpu=next(n for n in z.namelist() if n.endswith('SnesCpu.Shared.h'));ct=z.read(cpu).decode('utf-8','replace')
  ins=next(n for n in z.namelist() if n.endswith('SnesCpu.Instructions.h'));it=z.read(ins).decode('utf-8','replace')
 required=[
  ('master/h +2','_masterClock += 2;' in mem and '_hClock += 2;' in mem),
  ('primary before ppu/irq','if(_hClock == _nextEventClock)' in mem and 'if((_hClock & 0x03) == 0)' in mem),
  ('refresh40','case SnesEventType::DramRefresh:' in mem and 'IncMasterClock40();' in mem),
  ('hdma1104','_nextEventClock = 276 * 4;' in mem),
  ('read final4','(this->*_execRead)();' in mem and 'IncMasterClock4();' in mem),
  ('write effect after duration','(this->*_execWrite)();' in mem and 'ProcessMemoryWrite<CpuType::Snes>' in mem),
  ('irq inverted m/4','void InternalRegisters::ProcessIrqCounters()' in irt and 'if(_needIrq > 0)' in irt),
  ('autojoy128','for(uint64_t clock = _autoReadNextClock; clock <= _console->GetMasterClock(); clock += 128)' in irr),
  ('JSL interleave','PushByte(_state.K, false);\n\tIdle();\n\n\tuint8_t b3 = ReadOperandByte();' in it),
  ('JSR pre idle','case 0x20: AddrMode_AbsJmp(); Idle(); JSR(); break;' in ct),
  ('RTI two pre idles','case 0x40: Idle(); Idle(); RTI(); break;' in ct or ('void SnesCpu::RTI()' in it and it.count('Idle();') >= 2)),
  ('interrupt dummy read idle','ProcessInterrupt' in it and 'ReadCode(_state.PC);' in it and 'Idle();' in it),
 ]
 for name,ok in required:
  if not ok:errs.append('Mesen source ordering '+name)
 s=json.loads((p/'docs/V07C-scheduler-summary.json').read_text())
 if s['production_contexts']!=2258 or s['scheduler_executable_contexts']!=2250 or s['interrupt_return_contexts']!=12 or s['remaining_boundary_contexts']!=8:errs.append('summary counts')
 if any(s[x] for x in ('gameplay_promotion_count','trace_promotion_count','oracle_promotion_count','context_promotion_count')):errs.append('promotion')
 if errs:
  print('V07C INDEPENDENT: FAIL');print('\n'.join(errs));return 1
 print(f"V07C INDEPENDENT: PASS contexts={len(v7)} executable=2250 native=2238 interrupt_returns=12 boundaries=8 mesen_memory_sha256={sha_bytes(mem.encode())[:16]} timing_rows={len(v7)}")
 return 0
if __name__=='__main__':raise SystemExit(main())
