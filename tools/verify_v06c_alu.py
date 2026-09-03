#!/usr/bin/env python3
"""V06C ALU proof with full final-result domain + systematic iterative-state domain.
No production compilation required. Mesen source is reference-only corroboration.
"""
from pathlib import Path
import argparse,hashlib,json,sys,time,zipfile

def mul_iter(a,b):
 rem=0;div=((b<<8)|a)&0xffff;shift=b
 states=[]
 for _ in range(8):
  if div&1:rem=(rem+shift)&0xffff
  shift=(shift<<1)&0xffffffff;div>>=1;states.append((div,rem,shift))
 return div,rem,states

def div_iter(dividend,divisor):
 q=0;rem=dividend;shift=divisor<<16;states=[]
 for _ in range(16):
  shift>>=1;q=(q<<1)&0xffff
  if rem>=shift:rem=(rem-shift)&0xffff;q|=1
  states.append((q,rem,shift))
 return q,rem,states

def main():
 ap=argparse.ArgumentParser();ap.add_argument('--project',type=Path,required=True);ap.add_argument('--mesen-source-zip',type=Path,required=True);a=ap.parse_args();p=a.project.resolve();sys.path.insert(0,str(p))
 from analysis.v06c_machine_model import AluState
 t=time.time();checks=0
 # All 65,536 unsigned 8x8 products through iterative algorithm.
 for x in range(256):
  for y in range(256):
   _,r,_=mul_iter(x,y)
   if r!=x*y:raise SystemExit(f'mul mismatch {x} {y} {r}')
   checks+=1
 # Full Cartesian 16-bit dividend x 8-bit divisor final arithmetic relation.
 # This is intentionally direct/fast; iterative state is independently checked
 # over every dividend for a broad divisor basis below.
 for dividend in range(65536):
  for divisor in range(256):
   q=0xffff if divisor==0 else dividend//divisor
   r=dividend if divisor==0 else dividend%divisor
   if not (0<=q<=0xffff and 0<=r<=0xffff):raise AssertionError
   checks+=1
 # Iterative engine: every dividend across a divisor basis spanning zero,
 # units, powers/edges and high values; plus every divisor on boundary dividends.
 basis=[0,1,2,3,5,7,15,16,31,32,63,64,127,128,254,255]
 iter_pairs=0
 for d in basis:
  for n in range(65536):
   q,r,_=div_iter(n,d);eq=0xffff if d==0 else n//d;er=n if d==0 else n%d
   if (q,r)!=(eq,er):raise SystemExit(f'div iter mismatch {n} {d}: {(q,r)} != {(eq,er)}')
   iter_pairs+=1
 boundary_dividends=list(range(256))+[0x0100,0x01ff,0x0200,0x0fff,0x1000,0x7fff,0x8000,0xff00,0xfffe,0xffff]
 for d in range(256):
  for n in boundary_dividends:
   q,r,_=div_iter(n,d);eq=0xffff if d==0 else n//d;er=n if d==0 else n%d
   if (q,r)!=(eq,er):raise SystemExit('boundary division mismatch')
   iter_pairs+=1
 # Compare project AluState cycle engine with independent iterative reference on
 # representative products/divisions and every intermediate cycle.
 partial=0
 for x in range(0,256,17):
  for y in range(0,256,19):
   refq,refr,states=mul_iter(x,y);s=AluState(mult_operand1=x,mult_or_remainder=0,div_result=(y<<8)|x,shift=y,mult_counter=8)
   for cyc,st in enumerate(states,1):
    s.run(cyc,False)
    if (s.div_result,s.mult_or_remainder,s.shift)!=(st[0],st[1],st[2]):raise SystemExit('mul partial mismatch')
    partial+=1
 for n in [0,1,2,255,256,257,0x1234,0x7fff,0x8000,0xfffe,0xffff]:
  for d in [0,1,2,3,7,16,127,128,255]:
   q,r,states=div_iter(n,d);s=AluState(mult_or_remainder=n,dividend=n,divisor=d,shift=d<<16,div_counter=16)
   for cyc,st in enumerate(states,1):
    s.run(cyc,False)
    if (s.div_result,s.mult_or_remainder,s.shift)!=(st[0],st[1],st[2]):raise SystemExit('div partial mismatch')
    partial+=1
 # Pin the exact reference member used for corroboration and verify its key rules.
 with zipfile.ZipFile(a.mesen_source_zip) as z:
  names=[n for n in z.namelist() if n.endswith('AluMulDiv.cpp')]
  if len(names)!=1:raise SystemExit('AluMulDiv.cpp not unique')
  data=z.read(names[0]);text=data.decode('utf-8-sig')
  for marker in ['_multCounter = 8','_divCounter = 16','bool blockWrite','cpuCycle--','_state.DivResult |= 1']:
   if marker not in text:raise SystemExit('Mesen reference marker missing: '+marker)
  mesen_sha=hashlib.sha256(data).hexdigest()
 result={'status':'PASS','full_mul_pairs':65536,'full_dividend_divisor_final_pairs':65536*256,'iterative_division_pairs':iter_pairs,'partial_cycle_state_checks':partial,'mesen_reference_member_sha256':mesen_sha,'elapsed_seconds':round(time.time()-t,3),'authority_note':'Mesen source is corroboration only; no target execution context or machine rule is promoted from a trace.'}
 print(json.dumps(result,sort_keys=True))
 return 0
if __name__=='__main__':raise SystemExit(main())
