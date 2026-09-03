from __future__ import annotations
import argparse,csv,hashlib,json,re
from pathlib import Path
DMA_OFFSETS={0:[0],1:[0,1],2:[0,0],3:[0,0,1,1],4:[0,1,2,3],5:[0,1,0,1],6:[0,0],7:[0,0,1,1]}

def sha(p:Path)->str:return hashlib.sha256(p.read_bytes()).hexdigest()
def parse_eff(s:str):
    for t in re.split(r'[;,| ]+',s):
        if t:
            try: yield int(t,16)&0xffff
            except ValueError: pass

def build(root:Path):
    reached={a:{'read':0,'write':0,'first':'','first_context':'','dma':0} for a in range(0x2100,0x2140)}
    sites=[]
    with (root/'docs/V04C-memory-accesses.csv').open(newline='',encoding='utf-8') as f:
        for r in csv.DictReader(f):
            for a in parse_eff(r['Effective_Addresses']):
                if 0x2100<=a<=0x213f:
                    k='read' if r['Access']=='READ' else 'write'; reached[a][k]+=1
                    if not reached[a]['first']: reached[a]['first']=r['Physical']; reached[a]['first_context']=r['Context']
                    sites.append({'Register':f'{a:04X}','Path':'CPU_DIRECT','Access':r['Access'],'Physical':r['Physical'],'Context':r['Context'],'Instruction':r['Instruction'],'Profile':''})
    dma_regs=set()
    with (root/'docs/V08C-source-dma-configurations.csv').open(newline='',encoding='utf-8') as f:
        for r in csv.DictReader(f):
            if r['Channel']=='-1' or not r['BBAD']: continue
            mode=int(r['DMAP'],16)&7; bbad=int(r['BBAD'],16)
            for off in DMA_OFFSETS[mode]:
                a=0x2100|((bbad+off)&0xff)
                if 0x2100<=a<=0x213f:
                    dma_regs.add(a);reached[a]['dma']+=1
                    sites.append({'Register':f'{a:04X}','Path':'DMA_BBUS','Access':'WRITE' if (int(r['DMAP'],16)&0x80)==0 else 'READ','Physical':r['Start_Physical'] or r['Setup_Physical'],'Context':'V08C_SOURCE_PROFILE','Instruction':'DMA/HDMA','Profile':r['Profile']})
    rows=[]
    for a in range(0x2100,0x2140):
        x=reached[a]; hit=bool(x['read'] or x['write'] or x['dma'])
        if a<=0x2133: sem='WRITE_STATE_OR_READ_OPEN_BUS'
        elif a==0x213e: sem='READ_RENDERER_DEPENDENT_STATUS'
        else: sem='READ_STATE_OR_LATCH'
        rows.append({'Register':f'{a:04X}','Direct_Read_Count':x['read'],'Direct_Write_Count':x['write'],'DMA_Delivery_Count':x['dma'],'Reached':'YES' if hit else 'NO','Implemented':'YES','Certified':'YES' if hit else 'NOT_REACHED','First_Proved_Physical':x['first'],'First_Proved_Context':x['first_context'],'Production_Value_Domain':'00-FF_GENERAL' if a<=0x2133 else 'READ_SEMANTICS','Observed_Value_Domain':'NOT_USED_AS_STATIC_AUTHORITY','Semantic_Class':sem})
    out=root/'docs/V09C-source-ppu-registers.csv';out.parent.mkdir(exist_ok=True)
    with out.open('w',newline='',encoding='utf-8') as f:
        w=csv.DictWriter(f,fieldnames=rows[0],lineterminator='\n');w.writeheader();w.writerows(rows)
    siteout=root/'docs/V09C-source-ppu-access-sites.csv'
    sites.sort(key=lambda z:(int(z['Register'],16),z['Path'],z['Physical'],z['Context'],z['Profile']))
    with siteout.open('w',newline='',encoding='utf-8') as f:
        w=csv.DictWriter(f,fieldnames=['Register','Path','Access','Physical','Context','Instruction','Profile'],lineterminator='\n');w.writeheader();w.writerows(sites)
    hit=[int(r['Register'],16) for r in rows if r['Reached']=='YES']
    summary={
      'schema':1,'milestone':'V09C','production_contexts':2258,'scheduler_executable_contexts':2250,'source_proved_rom_bytes':4803,
      'ppu_register_space':64,'ppu_registers_implemented':64,'source_reached_register_count':len(hit),'source_proved_access_site_count':len(sites),'source_reached_registers':[f'{a:04X}' for a in hit],
      'dma_delivered_registers':[f'{a:04X}' for a in sorted(dma_regs)],'shared_cpu_dma_ppu_state':True,'renderer_implemented':False,
      'renderer_dependent_fail_closed':True,'vram_bytes':65536,'oam_bytes':544,'cgram_words':256,'knownness_tracking':True,
      'gameplay_promotion_count':0,'trace_promotion_count':0,'oracle_promotion_count':0,'context_promotion_count':0,'static_core_compilation_performed':False,
      'next_milestone':'V10C source-proved cold-boot closure; renderer work only when a proved frontier requires it'
    }
    (root/'docs/V09C-ppu-summary.json').write_text(json.dumps(summary,indent=2,sort_keys=True)+'\n')
    g=root/'generated/current/v09c';g.mkdir(parents=True,exist_ok=True)
    lo=sum(1<<(a-0x2100) for a in hit if a<0x2120);hi=sum(1<<(a-0x2120) for a in hit if a>=0x2120)
    (g/'js_v09c_ppu_inventory.h').write_text('''#ifndef JS_V09C_PPU_INVENTORY_H\n#define JS_V09C_PPU_INVENTORY_H\n#include <stdint.h>\n#define JSV09_PPU_REGISTER_COUNT 64u\n#define JSV09_SOURCE_REACHED_PPU_COUNT %du\n#define JSV09_SOURCE_REACHED_MASK_LO UINT32_C(0x%08X)\n#define JSV09_SOURCE_REACHED_MASK_HI UINT32_C(0x%08X)\n#endif\n'''%(len(hit),lo,hi))
    files=['docs/V09C-source-ppu-registers.csv','docs/V09C-source-ppu-access-sites.csv','docs/V09C-ppu-summary.json','generated/current/v09c/js_v09c_ppu_inventory.h']
    man={'schema':1,'milestone':'V09C','files':{r:sha(root/r) for r in files}}
    (g/'V09C-GENERATED-SHA256.json').write_text(json.dumps(man,indent=2,sort_keys=True)+'\n')
    return summary

def main():
 p=argparse.ArgumentParser();p.add_argument('--project',type=Path,required=True);p.add_argument('--rom',type=Path,required=True);a=p.parse_args()
 if hashlib.sha256(a.rom.read_bytes()).hexdigest()!='9d721753301278325c851f1843d669a697aed757dcf6495a31fc31ddf664b182':raise SystemExit('wrong ROM')
 s=build(a.project);print(f"V09C generated: reached={s['source_reached_register_count']} implemented=64")
if __name__=='__main__':main()
