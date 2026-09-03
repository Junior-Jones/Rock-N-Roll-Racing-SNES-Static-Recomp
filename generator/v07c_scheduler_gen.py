#!/usr/bin/env python3
"""Version 07C scheduler/timing projection for Rock n' Roll Racing.

Authority: frozen V05C static contexts, frozen V02C cycle/access contract, the exact
V06C target bus mapping, and pinned MesenCE source ordering used only as an
independent specification oracle. Gameplay, traces and oracle PC lists are not
inputs and cannot add contexts.
"""
from __future__ import annotations
from pathlib import Path
import argparse,csv,hashlib,json

PROJECT_MARK='ROCKNROLL_V07C_SCHEDULER_GEN_2'
ACCESS_FIELDS=['Fetch_Bytes','Pointer_Read_Bytes','Data_Read_Bytes','Data_Write_Bytes','Dummy_Write_Bytes','Stack_Read_Bytes','Stack_Write_Bytes','Vector_Read_Bytes']
PUSH={'PHA','PHB','PHK','PHP','PHX','PHY'}
PULL={'PLA','PLB','PLP','PLX','PLY'}
RMW={'INC','DEC','ASL','LSR','ROL','ROR'}
MODES=['ABS','ABSL_JUMP','ABS_JUMP','ABS_LONG','ABS_X','ABS_X_IND','ABS_Y','ACC','DP','DP_IND_LONG','DP_IND_LONG_Y','DP_IND_Y','IMM16','IMM8','IMM_M','IMM_X','IMP','REL16','REL8','STACK_REL']
MODE_ID={m:i for i,m in enumerate(MODES)}
RULE_BITS={
 'DYN_DIRECT_LOW_PRE_IDLE':1<<0,'DYN_INDEX_PRE_DATA_IDLE':1<<1,
 'DYN_BRANCH_TAKEN_POST_IDLE':1<<2,'DYN_BRANCH_PAGE_POST_IDLE':1<<3,
 'JSL_AFTER_PBR_PUSH_IDLE':1<<4,'JSR_PRE_STACK_IDLE':1<<5,'JSR_XIND_MID_IDLE':1<<6,
 'RETURN_PRE_IDLE':1<<7,'RTS_POST_POP_IDLE':1<<8,'PUSH_PRE_IDLE':1<<9,
 'PULL_PRE_IDLE':1<<10,'IMPLIED_PRE_IDLE':1<<11,'XBA_EXTRA_IDLE':1<<12,
 'STATUS_PRE_IDLE':1<<13,'BRANCH_ALWAYS_POST_IDLE':1<<14,'RELLONG_PRE_IDLE':1<<15,
 'RMW_INTERMEDIATE_IDLE':1<<16,'STACK_REL_PRE_DATA_IDLE':1<<17,'INDEX_FIXED_PRE_DATA_IDLE':1<<18,
}

def sha(p:Path)->str:
 h=hashlib.sha256(); h.update(p.read_bytes()); return h.hexdigest()
def rows(p:Path):
 with p.open(newline='',encoding='utf-8') as f:return list(csv.DictReader(f))
def write_csv(p:Path,fields,rr):
 p.parent.mkdir(parents=True,exist_ok=True)
 with p.open('w',newline='',encoding='utf-8') as f:
  w=csv.DictWriter(f,fieldnames=fields,lineterminator='\n');w.writeheader();w.writerows(rr)
def operand(raw:bytes)->int:
 v=0
 for i,b in enumerate(raw[1:]):v|=b<<(8*i)
 return v

def v07_executable(v5:dict)->bool:
 if v5['Disposition']=='NATIVE_BODY':return True
 # V07 owns asynchronous interrupt re-entry. RTI remains the same already-admitted
 # exact context key, but is promoted from a V05 named boundary to a scheduler-owned
 # fixed return body whose live target must still be another admitted V07 key.
 return v5['Mnemonic']=='RTI' and 'INTERRUPT_REENTRY' in v5.get('Boundary_Classes','')

def timing_rules(v5,v2):
 if not v07_executable(v5):
  return ['BOUNDARY_NO_EXECUTION'],0,0
 bus=sum(int(v2[k]) for k in ACCESS_FIELDS)
 imin=int(v2['Cycle_Min'])-bus; imax=int(v2['Cycle_Max'])-bus
 mn,mo=v5['Mnemonic'],v5['Mode']; dyn=v2['Dynamic_Cycle_Tags']; fixed=[]; dr=[]
 if imin:
  if mn=='JSL': fixed=['JSL_AFTER_PBR_PUSH_IDLE']
  elif mn=='JSR' and mo=='ABS_JUMP': fixed=['JSR_PRE_STACK_IDLE']
  elif mn=='JSR' and mo=='ABS_X_IND': fixed=['JSR_XIND_MID_IDLE']
  elif mn=='RTS': fixed=['RETURN_PRE_IDLE','RETURN_PRE_IDLE','RTS_POST_POP_IDLE']
  elif mn in ('RTL','RTI'): fixed=['RETURN_PRE_IDLE','RETURN_PRE_IDLE']
  elif mn in PUSH: fixed=['PUSH_PRE_IDLE']
  elif mn in PULL: fixed=['PULL_PRE_IDLE','PULL_PRE_IDLE']
  elif mn=='XBA': fixed=['IMPLIED_PRE_IDLE','XBA_EXTRA_IDLE']
  elif mn in ('REP','SEP'): fixed=['STATUS_PRE_IDLE']
  elif mn=='BRA': fixed=['BRANCH_ALWAYS_POST_IDLE']
  elif mn=='BRL': fixed=['RELLONG_PRE_IDLE']
  elif mo in ('IMP','ACC'): fixed=['IMPLIED_PRE_IDLE']*imin
  elif mn in RMW and mo!='ACC': fixed=['RMW_INTERMEDIATE_IDLE']*imin
  elif mo=='STACK_REL': fixed=['STACK_REL_PRE_DATA_IDLE']*imin
  elif mo in ('ABS_X','ABS_Y','DP_IND_Y'): fixed=['INDEX_FIXED_PRE_DATA_IDLE']*imin
  else: raise AssertionError(f'unclassified fixed idle {v5["Key"]} {mn} {mo} {imin}')
 if 'DIRECT_LOW_NONZERO' in dyn: dr.append('DYN_DIRECT_LOW_PRE_IDLE')
 if 'INDEX_PAGE_CROSS' in dyn: dr.append('DYN_INDEX_PRE_DATA_IDLE')
 if 'BRANCH_TAKEN' in dyn: dr.append('DYN_BRANCH_TAKEN_POST_IDLE')
 if 'BRANCH_PAGE_CROSS_EMULATION' in dyn: dr.append('DYN_BRANCH_PAGE_POST_IDLE')
 if len(fixed)!=imin or imax!=imin+len(dr):
  raise AssertionError(f'idle accounting {v5["Key"]}: {imin}/{imax} fixed={fixed} dyn={dr}')
 return fixed+dr,imin,imax

def plan_class(rules):
 if rules==['BOUNDARY_NO_EXECUTION']:return 'BOUNDARY_NO_EXECUTION'
 tags=set(rules)
 if any(x.startswith('JSL_') for x in tags):return 'JSL_DEFERRED_BANK_FETCH'
 if any(x.startswith('RETURN_') or x.startswith('RTS_') for x in tags):return 'RETURN_SEQUENCE'
 if any(x.startswith('DYN_BRANCH') or x.startswith('BRANCH_') for x in tags):return 'BRANCH_SEQUENCE'
 if any(x.startswith('RMW_') for x in tags):return 'RMW_SEQUENCE'
 if any(x.startswith('DYN_DIRECT') for x in tags) and any('INDEX' in x for x in tags):return 'DIRECT_INDEX_SEQUENCE'
 if any('INDEX' in x for x in tags):return 'INDEX_SEQUENCE'
 if any(x.startswith('DYN_DIRECT') for x in tags):return 'DIRECT_SEQUENCE'
 if rules:return 'FIXED_IDLE_SEQUENCE'
 return 'LINEAR_BUS_SEQUENCE'

def rule_mask(rules):
 m=0
 for r in rules:
  if r=='BOUNDARY_NO_EXECUTION':continue
  m|=RULE_BITS[r]
 return m

def c_header()->str:
 mode_lines=',\n '.join(f'JSV07_MODE_{m}={i}' for i,m in enumerate(MODES))
 bit_lines='\n'.join(f'#define JSV07_RULE_{n} 0x{v:08X}u' for n,v in RULE_BITS.items())
 return f'''#ifndef ROCKNROLL_V07C_TIMING_H
#define ROCKNROLL_V07C_TIMING_H
#include <stddef.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {{
#endif
typedef enum JSV07TimingClass {{
 JSV07_TIMING_LINEAR_BUS_SEQUENCE=0, JSV07_TIMING_FIXED_IDLE_SEQUENCE=1,
 JSV07_TIMING_DIRECT_SEQUENCE=2, JSV07_TIMING_INDEX_SEQUENCE=3,
 JSV07_TIMING_DIRECT_INDEX_SEQUENCE=4, JSV07_TIMING_RMW_SEQUENCE=5,
 JSV07_TIMING_BRANCH_SEQUENCE=6, JSV07_TIMING_RETURN_SEQUENCE=7,
 JSV07_TIMING_JSL_DEFERRED_BANK_FETCH=8, JSV07_TIMING_BOUNDARY_NO_EXECUTION=9
}} JSV07TimingClass;
typedef enum JSV07Mode {{
 {mode_lines}
}} JSV07Mode;
{bit_lines}
typedef struct JSV07TimingPlan {{
 uint32_t key,address,operand,rule_flags;
 uint8_t opcode,length,e,m,x,mode,cycle_min,cycle_max;
 uint8_t fetch_bytes,pointer_reads,data_reads,data_writes,dummy_writes,stack_reads,stack_writes,vector_reads;
 uint8_t fixed_idles,dynamic_idle_max,timing_class,v07_executable;
 uint8_t bytes[4];
 const char *rules;
}} JSV07TimingPlan;
const JSV07TimingPlan *js_v07c_timing_plan(uint32_t key);
size_t js_v07c_timing_plan_count(void);
#ifdef __cplusplus
}}
#endif
#endif
'''

def generate(project:Path):
 v5=rows(project/'docs/V05C-production-manifest.csv')
 v2={(r['Opcode'],r['E'],r['M'],r['X']):r for r in rows(project/'docs/V02C-opcode-context-matrix.csv') if r['Status']=='LEGAL'}
 outrows=[]
 for p in v5:
  q=v2[(p['Opcode'],p['E'],p['M'],p['X'])]
  rules,imin,imax=timing_rules(p,q); cls=plan_class(rules); raw=bytes.fromhex(p['Bytes']); op=operand(raw)
  exe=v07_executable(p)
  outrows.append({
   'Production_ID':p['Production_ID'],'Key':p['Key'],'Key_Hex':p['Key_Hex'],'PBR':p['PBR'],'PC':p['PC'],'E':p['E'],'M':p['M'],'X':p['X'],
   'Opcode':p['Opcode'],'Mnemonic':p['Mnemonic'],'Mode':p['Mode'],'Length':p['Length'],'Bytes':p['Bytes'],'V05_Disposition':p['Disposition'],
   'V07_Disposition':'SCHEDULER_INTERRUPT_RETURN_BODY' if p['Disposition']!='NATIVE_BODY' and exe else ('NATIVE_BODY' if exe else 'NAMED_BOUNDARY'),
   'Cycle_Min':q['Cycle_Min'],'Cycle_Max':q['Cycle_Max'],'Dynamic_Cycle_Tags':q['Dynamic_Cycle_Tags'],
   'Fetch_Bytes':q['Fetch_Bytes'],'Pointer_Read_Bytes':q['Pointer_Read_Bytes'],'Data_Read_Bytes':q['Data_Read_Bytes'],'Data_Write_Bytes':q['Data_Write_Bytes'],
   'Dummy_Write_Bytes':q['Dummy_Write_Bytes'],'Stack_Read_Bytes':q['Stack_Read_Bytes'],'Stack_Write_Bytes':q['Stack_Write_Bytes'],'Vector_Read_Bytes':q['Vector_Read_Bytes'],
   'Fixed_Idle_Cycles':str(imin),'Dynamic_Idle_Max':str(imax-imin),'Timing_Class':cls,'Timing_Rules':';'.join(rules),
   'Rule_Flags':f'{rule_mask(rules):08X}','Operand':f'{op:06X}','Address':f'{((int(p["PBR"],16)<<16)|int(p["PC"],16)):06X}',
   'Authority':'V02C_MATRIX_PLUS_PINNED_MESEN_CPU_SOURCE_ORDER_NO_GAMEPLAY'
  })
 fields=list(outrows[0]); write_csv(project/'docs/V07C-timing-manifest.csv',fields,outrows)
 cls_counts={}
 for r in outrows:cls_counts[r['Timing_Class']]=cls_counts.get(r['Timing_Class'],0)+1
 executable=[r for r in outrows if r['V07_Disposition']!='NAMED_BOUNDARY']; boundary=[r for r in outrows if r['V07_Disposition']=='NAMED_BOUNDARY']
 interrupt_returns=[r for r in outrows if r['V07_Disposition']=='SCHEDULER_INTERRUPT_RETURN_BODY']
 summary={
  'schema':2,'milestone':'V07C','status':(project/'config/v07c-release-state.txt').read_text().strip() if (project/'config/v07c-release-state.txt').exists() else 'TECHNICAL_CANDIDATE',
  'generator':PROJECT_MARK,'production_contexts':len(outrows),'scheduler_executable_contexts':len(executable),'v05_native_contexts':2238,
  'interrupt_return_contexts':len(interrupt_returns),'remaining_boundary_contexts':len(boundary),
  'timing_class_counts':dict(sorted(cls_counts.items())),'master_time_unit':'one SNES master clock','read_effect_phase':'duration-4 then effect then final 4','write_effect_phase':'full duration then effect',
  'event_tie_order':['PRIMARY_RASTER_EVENT','PPU_OR_IRQ_PHASE','AUTOJOY','S_SMP_RENDEZVOUS'],
  'dram_refresh_wall_clocks':40,'normal_scanline_clocks':1364,'short_scanline_clocks':1360,'hdma_line_hclock':1104,
  'reset_vector_sampling':'untimed side-effect-free peek','reset_startup_delay_master_clocks':186,
  'smp_ratio':{'numerator':2048000,'denominator':21477270},
  'historical_approximate_v06_timing_path_active':False,'v06_files_modified':False,
  'interrupt_reentry_policy':'RTI is scheduler-owned only for the 12 already-admitted V05 interrupt-vector RTI keys; live return key must exist in V07 timing table or execution stops',
  'gameplay_promotion_count':0,'trace_promotion_count':0,'oracle_promotion_count':0,'context_promotion_count':0,
  'compile_build_gate':'DEFERRED_BY_USER_POLICY_NOT_RUN_AT_VERSION_END',
  'later_subsystem_seams':['V08 DMA/HDMA transfer execution','V09 PPU rendering/register semantics','V11 input electrical devices','later S-SMP execution/audio']
 }
 (project/'docs/V07C-scheduler-summary.json').write_text(json.dumps(summary,indent=2,sort_keys=True)+'\n',encoding='utf-8',newline='\n')
 out=project/'generated/current/v07c';out.mkdir(parents=True,exist_ok=True)
 (out/'js_v07c_timing.h').write_text(c_header(),encoding='utf-8',newline='\n')
 enum={'LINEAR_BUS_SEQUENCE':0,'FIXED_IDLE_SEQUENCE':1,'DIRECT_SEQUENCE':2,'INDEX_SEQUENCE':3,'DIRECT_INDEX_SEQUENCE':4,'RMW_SEQUENCE':5,'BRANCH_SEQUENCE':6,'RETURN_SEQUENCE':7,'JSL_DEFERRED_BANK_FETCH':8,'BOUNDARY_NO_EXECUTION':9}
 lines=['#include "js_v07c_timing.h"','','static const JSV07TimingPlan PLANS[] = {']
 for r in outrows:
  raw=bytes.fromhex(r['Bytes'])+b'\x00'*4; b0,b1,b2,b3=raw[:4]
  nums=[int(r[k]) for k in ['Cycle_Min','Cycle_Max','Fetch_Bytes','Pointer_Read_Bytes','Data_Read_Bytes','Data_Write_Bytes','Dummy_Write_Bytes','Stack_Read_Bytes','Stack_Write_Bytes','Vector_Read_Bytes','Fixed_Idle_Cycles','Dynamic_Idle_Max']]
  rule=r['Timing_Rules'].replace('\\','\\\\').replace('"','\\"')
  exe=0 if r['V07_Disposition']=='NAMED_BOUNDARY' else 1
  scalar = [int(r['Length']), int(r['E']), int(r['M']), int(r['X']), MODE_ID[r['Mode']], *nums, enum[r['Timing_Class']], exe]
  scalar_text = ','.join(f'{v}u' for v in scalar)
  lines.append(
   f" {{0x{int(r['Key_Hex'],16):08X}u,0x{int(r['Address'],16):06X}u,0x{int(r['Operand'],16):06X}u,"
   f"0x{int(r['Rule_Flags'],16):08X}u,0x{int(r['Opcode'],16):02X}u,{scalar_text},"
   f"{{0x{b0:02X}u,0x{b1:02X}u,0x{b2:02X}u,0x{b3:02X}u}},\"{rule}\"}},"
  )
 lines+=['};','', 'size_t js_v07c_timing_plan_count(void) { return sizeof(PLANS)/sizeof(PLANS[0]); }',
 'const JSV07TimingPlan *js_v07c_timing_plan(uint32_t key) {',' size_t lo=0,hi=js_v07c_timing_plan_count();',' while(lo<hi){size_t m=lo+(hi-lo)/2;if(PLANS[m].key<key)lo=m+1;else hi=m;}',' return lo<js_v07c_timing_plan_count()&&PLANS[lo].key==key?&PLANS[lo]:0;','}','']
 (out/'js_v07c_timing.c').write_text('\n'.join(lines),encoding='utf-8',newline='\n')
 gen=[project/'docs/V07C-timing-manifest.csv',project/'docs/V07C-scheduler-summary.json',out/'js_v07c_timing.h',out/'js_v07c_timing.c']
 hashes={str(p.relative_to(project)):sha(p) for p in gen}
 hashes['aggregate_sha256']=hashlib.sha256(''.join(hashes[k] for k in sorted(hashes)).encode()).hexdigest()
 (out/'V07C-GENERATED-SHA256.json').write_text(json.dumps(hashes,indent=2,sort_keys=True)+'\n',encoding='utf-8',newline='\n')
 print(json.dumps({'contexts':len(outrows),'executable':len(executable),'interrupt_returns':len(interrupt_returns),'boundaries':len(boundary),'classes':summary['timing_class_counts']},sort_keys=True))

def main():
 ap=argparse.ArgumentParser();ap.add_argument('--project',type=Path,required=True);a=ap.parse_args();generate(a.project.resolve())
if __name__=='__main__':main()
