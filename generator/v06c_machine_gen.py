#!/usr/bin/env python3
from __future__ import annotations
from pathlib import Path
import argparse,csv,hashlib,json,sys

PROJECT_MARK='ROCKNROLL_V06C_MACHINE_GEN_1'

def sha(p:Path)->str:
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1<<20),b''):h.update(b)
 return h.hexdigest()

def load_model(project:Path):
 sys.path.insert(0,str(project))
 from analysis import v06c_machine_model as m
 return m

def read_rows(path:Path):
 with path.open(newline='',encoding='utf-8') as f:return list(csv.DictReader(f))

def write_csv(path:Path,fields,rows):
 path.parent.mkdir(parents=True,exist_ok=True)
 with path.open('w',newline='',encoding='utf-8') as f:
  w=csv.DictWriter(f,fieldnames=fields,lineterminator='\n');w.writeheader();w.writerows(rows)

def c_header()->str:
 return r'''#ifndef ROCKNROLL_V06C_MACHINE_H
#define ROCKNROLL_V06C_MACHINE_H

#include <stddef.h>
#include <stdint.h>
#include "v05c_static_cpu.h"

#ifdef __cplusplus
extern "C" {
#endif

#define JSV06_ROM_SIZE 0x100000u
#define JSV06_WRAM_SIZE 0x20000u

typedef enum JSV06Region {
    JSV06_REGION_OPEN_BUS=0, JSV06_REGION_ROM=1, JSV06_REGION_WRAM=2,
    JSV06_REGION_PPU=3, JSV06_REGION_APU=4, JSV06_REGION_WRAM_PORT=5,
    JSV06_REGION_CPU_IO=6, JSV06_REGION_INPUT=7, JSV06_REGION_DMA=8
} JSV06Region;

typedef enum JSV06StopReason {
    JSV06_STOP_NONE=0, JSV06_STOP_PPU_UNAVAILABLE=1, JSV06_STOP_APU_UNAVAILABLE=2,
    JSV06_STOP_DMA_UNAVAILABLE=3, JSV06_STOP_INPUT_UNAVAILABLE=4,
    JSV06_STOP_TIMING_UNAVAILABLE=5, JSV06_STOP_ROM_WRITE=6,
    JSV06_STOP_STATIC_CODE_MISMATCH=7, JSV06_STOP_UNKNOWN_CONTEXT=8,
    JSV06_STOP_V05=9, JSV06_STOP_INVALID_MACHINE=10
} JSV06StopReason;

typedef struct JSV06Alu {
    uint8_t mult_operand1, mult_operand2, divisor;
    uint16_t mult_or_remainder, dividend, div_result;
    uint32_t shift;
    uint8_t mult_counter, div_counter;
    uint64_t prev_cpu_cycle;
} JSV06Alu;

typedef struct JSV06Stop {
    JSV06StopReason reason;
    uint32_t address, source_key, observed_key;
    uint8_t value;
    JSStop v05;
} JSV06Stop;

typedef struct JSV06Machine {
    JSCPU cpu;
    const uint8_t *rom;
    size_t rom_size;
    uint8_t wram[JSV06_WRAM_SIZE];
    uint32_t wram_position;
    uint8_t open_bus, memsel, nmitimen, io_port_output;
    uint16_t htimer, vtimer;
    uint64_t access_clock_sum;
    uint64_t cpu_cycle_count;
    JSV06Alu alu;
    JSV06StopReason pending_bus_stop;
    uint32_t pending_bus_address;
    uint8_t pending_bus_value;
} JSV06Machine;

JSV06Region js_v06c_classify(uint32_t address);
int js_v06c_lorom_offset(uint32_t address, uint32_t *offset);
int js_v06c_wram_offset(uint32_t address, uint32_t *offset);
uint8_t js_v06c_access_clocks(uint32_t address, uint8_t memsel);
uint8_t js_v06c_peek8(const JSV06Machine *m, uint32_t address);
uint16_t js_v06c_reset_vector(const JSV06Machine *m);
int js_v06c_power_on(JSV06Machine *m, const uint8_t *rom, size_t rom_size, const uint8_t *initial_wram);
int js_v06c_reset(JSV06Machine *m);
void js_v06c_cpu_internal_cycle(JSV06Machine *m);
int js_v06c_read8(JSV06Machine *m, uint32_t address, uint8_t *out, JSV06Stop *stop);
int js_v06c_write8(JSV06Machine *m, uint32_t address, uint8_t value, JSV06Stop *stop);
JSExecResult js_v06c_step(JSV06Machine *m, JSV06Stop *stop);
void js_v06c_stop_clear(JSV06Stop *stop);

#ifdef __cplusplus
}
#endif
#endif
'''

def c_source()->str:
 return r'''#include "v06c_machine.h"
#include "js_v05c_dispatch.h"
#include "js_v06c_fetch.h"
#include <string.h>

static int js_v06c_system_bank(uint8_t bank) { return bank <= 0x3Fu || (bank >= 0x80u && bank <= 0xBFu); }
void js_v06c_stop_clear(JSV06Stop *s) { if(s) memset(s,0,sizeof(*s)); }
static int js_v06c_fail(JSV06Machine *m, JSV06Stop *s, JSV06StopReason r, uint32_t a, uint8_t v) {
    if(m){m->pending_bus_stop=r;m->pending_bus_address=a&0xFFFFFFu;m->pending_bus_value=v;}
    if(s){s->reason=r;s->address=a&0xFFFFFFu;s->value=v;s->source_key=js_cpu_context_key(m?&m->cpu:0);}
    return 0;
}
JSV06Region js_v06c_classify(uint32_t address) {
    uint8_t bank; uint16_t off; address &= 0xFFFFFFu; bank=(uint8_t)(address>>16); off=(uint16_t)address;
    if(bank==0x7Eu || bank==0x7Fu) return JSV06_REGION_WRAM;
    if(js_v06c_system_bank(bank)) {
        if(off<=0x1FFFu) return JSV06_REGION_WRAM;
        if(off>=0x2100u && off<=0x213Fu) return JSV06_REGION_PPU;
        if(off>=0x2140u && off<=0x217Fu) return JSV06_REGION_APU;
        if(off>=0x2180u && off<=0x2183u) return JSV06_REGION_WRAM_PORT;
        if(off==0x4016u || off==0x4017u || (off>=0x4218u && off<=0x421Fu)) return JSV06_REGION_INPUT;
        if(off>=0x4200u && off<=0x4217u) return JSV06_REGION_CPU_IO;
        if(off>=0x4300u && off<=0x437Fu) return JSV06_REGION_DMA;
    }
    if(off>=0x8000u) return JSV06_REGION_ROM;
    return JSV06_REGION_OPEN_BUS;
}
int js_v06c_lorom_offset(uint32_t address, uint32_t *offset) {
    uint8_t bank; uint16_t off; address&=0xFFFFFFu; bank=(uint8_t)(address>>16); off=(uint16_t)address;
    if(!offset || bank==0x7Eu || bank==0x7Fu || off<0x8000u) return 0;
    *offset=(((uint32_t)bank & 0x1Fu)<<15)|(off&0x7FFFu); return 1;
}
int js_v06c_wram_offset(uint32_t address, uint32_t *offset) {
    uint8_t bank; uint16_t off; address&=0xFFFFFFu; bank=(uint8_t)(address>>16); off=(uint16_t)address;
    if(!offset) return 0;
    if(bank==0x7Eu){*offset=off;return 1;} if(bank==0x7Fu){*offset=0x10000u|off;return 1;}
    if(js_v06c_system_bank(bank)&&off<=0x1FFFu){*offset=off;return 1;} return 0;
}
uint8_t js_v06c_access_clocks(uint32_t address, uint8_t memsel) {
    uint8_t bank_group=(uint8_t)((address>>22)&3u), page=(uint8_t)(address>>8); memsel=memsel?1u:0u;
    if(bank_group==1u) return 8u; if(bank_group==3u) return memsel?6u:8u;
    if(page<=0x1Fu) return 8u; if(page<=0x3Fu) return 6u; if(page<=0x41u) return 12u;
    if(page<=0x5Fu) return 6u; if(page<=0x7Fu) return 8u; if(bank_group==0u) return 8u; return memsel?6u:8u;
}
static void js_v06c_alu_run(JSV06Machine *m, int is_read) {
    uint64_t target=m->cpu_cycle_count-(is_read && m->cpu_cycle_count?1u:0u), cycles;
    if(target<m->alu.prev_cpu_cycle) target=m->alu.prev_cpu_cycle; cycles=target-m->alu.prev_cpu_cycle;
    while(cycles--){ if(!m->alu.mult_counter&&!m->alu.div_counter) break;
        if(m->alu.mult_counter){m->alu.mult_counter--;if(m->alu.div_result&1u)m->alu.mult_or_remainder=(uint16_t)(m->alu.mult_or_remainder+m->alu.shift);m->alu.shift<<=1;m->alu.div_result>>=1;}
        if(m->alu.div_counter){m->alu.div_counter--;m->alu.shift>>=1;m->alu.div_result<<=1;if(m->alu.mult_or_remainder>=m->alu.shift){m->alu.mult_or_remainder=(uint16_t)(m->alu.mult_or_remainder-m->alu.shift);m->alu.div_result|=1u;}}
    } m->alu.prev_cpu_cycle=target;
}
static uint8_t js_v06c_alu_read(JSV06Machine *m,uint16_t off){js_v06c_alu_run(m,1);switch(off){case 0x4214:return(uint8_t)m->alu.div_result;case 0x4215:return(uint8_t)(m->alu.div_result>>8);case 0x4216:return(uint8_t)m->alu.mult_or_remainder;default:return(uint8_t)(m->alu.mult_or_remainder>>8);}}
static void js_v06c_alu_write(JSV06Machine *m,uint16_t off,uint8_t v){int block;js_v06c_alu_run(m,1);block=m->alu.div_counter||m->alu.mult_counter;js_v06c_alu_run(m,0);switch(off){
 case 0x4202:m->alu.mult_operand1=v;break;case 0x4203:m->alu.mult_or_remainder=0;if(!block){m->alu.mult_counter=8;m->alu.mult_operand2=v;m->alu.div_result=(uint16_t)(((uint16_t)v<<8)|m->alu.mult_operand1);m->alu.shift=v;}else if(!m->alu.div_counter&&!m->alu.mult_counter)m->alu.div_result=(uint16_t)(((uint16_t)v<<8)|m->alu.mult_operand1);break;
 case 0x4204:m->alu.dividend=(uint16_t)((m->alu.dividend&0xFF00u)|v);break;case 0x4205:m->alu.dividend=(uint16_t)((m->alu.dividend&0x00FFu)|((uint16_t)v<<8));break;case 0x4206:m->alu.mult_or_remainder=m->alu.dividend;if(!block){m->alu.div_counter=16;m->alu.divisor=v;m->alu.shift=(uint32_t)v<<16;}break;default:break;}}
uint8_t js_v06c_peek8(const JSV06Machine *m,uint32_t a){uint32_t o;uint16_t off=(uint16_t)a;JSV06Region r;if(!m)return 0;a&=0xFFFFFFu;r=js_v06c_classify(a);if(r==JSV06_REGION_ROM&&js_v06c_lorom_offset(a,&o)&&o<m->rom_size)return m->rom[o];if(r==JSV06_REGION_WRAM&&js_v06c_wram_offset(a,&o))return m->wram[o];if(r==JSV06_REGION_WRAM_PORT&&off==0x2180u)return m->wram[m->wram_position];if(r==JSV06_REGION_CPU_IO){if(off==0x4213u)return m->io_port_output;if(off==0x4214u)return(uint8_t)m->alu.div_result;if(off==0x4215u)return(uint8_t)(m->alu.div_result>>8);if(off==0x4216u)return(uint8_t)m->alu.mult_or_remainder;if(off==0x4217u)return(uint8_t)(m->alu.mult_or_remainder>>8);}return m->open_bus;}
uint16_t js_v06c_reset_vector(const JSV06Machine *m){return(uint16_t)(js_v06c_peek8(m,0x00FFFCu)|((uint16_t)js_v06c_peek8(m,0x00FFFDu)<<8));}
int js_v06c_power_on(JSV06Machine *m,const uint8_t *rom,size_t size,const uint8_t *initial_wram){if(!m||!rom||size!=JSV06_ROM_SIZE)return 0;memset(m,0,sizeof(*m));m->rom=rom;m->rom_size=size;if(initial_wram)memcpy(m->wram,initial_wram,JSV06_WRAM_SIZE);m->io_port_output=0xFFu;m->htimer=0x1FFu;m->vtimer=0x1FFu;m->alu.mult_operand1=0xFFu;m->alu.dividend=0xFFFFu;m->cpu.s=0x01FFu;m->cpu.p=JS_P_I|JS_P_M|JS_P_X;m->cpu.e=1u;m->cpu.pc=js_v06c_reset_vector(m);return 1;}
int js_v06c_reset(JSV06Machine *m){if(!m||!m->rom||m->rom_size!=JSV06_ROM_SIZE)return 0;m->cpu.p=(uint8_t)((m->cpu.p|JS_P_I|JS_P_M|JS_P_X)&(uint8_t)~JS_P_D);m->cpu.e=1u;m->cpu.dbr=0;m->cpu.d=0;m->cpu.pbr=0;m->cpu.x&=0xFFu;m->cpu.y&=0xFFu;m->cpu.s=(uint16_t)(0x0100u|(m->cpu.s&0xFFu));m->cpu.pc=js_v06c_reset_vector(m);m->nmitimen=0;m->access_clock_sum=0;m->cpu_cycle_count=0;m->pending_bus_stop=JSV06_STOP_NONE;return 1;}
void js_v06c_cpu_internal_cycle(JSV06Machine *m){if(m)m->cpu_cycle_count++;}
static void js_v06c_begin_access(JSV06Machine *m,uint32_t a){m->cpu_cycle_count++;m->access_clock_sum+=js_v06c_access_clocks(a,m->memsel);}
int js_v06c_read8(JSV06Machine *m,uint32_t a,uint8_t *out,JSV06Stop *s){uint32_t o;uint16_t off;JSV06Region r;if(!m||!out)return js_v06c_fail(m,s,JSV06_STOP_INVALID_MACHINE,a,0);a&=0xFFFFFFu;off=(uint16_t)a;js_v06c_begin_access(m,a);r=js_v06c_classify(a);
 if(r==JSV06_REGION_ROM){js_v06c_lorom_offset(a,&o);*out=m->rom[o];m->open_bus=*out;return 1;}if(r==JSV06_REGION_WRAM){js_v06c_wram_offset(a,&o);*out=m->wram[o];m->open_bus=*out;return 1;}if(r==JSV06_REGION_OPEN_BUS){*out=m->open_bus;return 1;}if(r==JSV06_REGION_PPU)return js_v06c_fail(m,s,JSV06_STOP_PPU_UNAVAILABLE,a,0);if(r==JSV06_REGION_APU)return js_v06c_fail(m,s,JSV06_STOP_APU_UNAVAILABLE,a,0);if(r==JSV06_REGION_DMA)return js_v06c_fail(m,s,JSV06_STOP_DMA_UNAVAILABLE,a,0);if(r==JSV06_REGION_INPUT)return js_v06c_fail(m,s,JSV06_STOP_INPUT_UNAVAILABLE,a,0);
 if(r==JSV06_REGION_WRAM_PORT){if(off==0x2180u){*out=m->wram[m->wram_position];m->wram_position=(m->wram_position+1u)&0x1FFFFu;m->open_bus=*out;}else *out=m->open_bus;return 1;}
 if(r==JSV06_REGION_CPU_IO){if(off>=0x4210u&&off<=0x4212u)return js_v06c_fail(m,s,JSV06_STOP_TIMING_UNAVAILABLE,a,0);if(off==0x4213u){*out=m->io_port_output;return 1;}if(off>=0x4214u&&off<=0x4217u){*out=js_v06c_alu_read(m,off);return 1;}*out=m->open_bus;return 1;}return js_v06c_fail(m,s,JSV06_STOP_INVALID_MACHINE,a,0);}
int js_v06c_write8(JSV06Machine *m,uint32_t a,uint8_t v,JSV06Stop *s){uint32_t o;uint16_t off;JSV06Region r;if(!m)return js_v06c_fail(m,s,JSV06_STOP_INVALID_MACHINE,a,v);a&=0xFFFFFFu;off=(uint16_t)a;js_v06c_begin_access(m,a);r=js_v06c_classify(a);
 if(r==JSV06_REGION_ROM)return js_v06c_fail(m,s,JSV06_STOP_ROM_WRITE,a,v);if(r==JSV06_REGION_WRAM){js_v06c_wram_offset(a,&o);m->wram[o]=v;return 1;}if(r==JSV06_REGION_OPEN_BUS)return 1;if(r==JSV06_REGION_PPU)return js_v06c_fail(m,s,JSV06_STOP_PPU_UNAVAILABLE,a,v);if(r==JSV06_REGION_APU)return js_v06c_fail(m,s,JSV06_STOP_APU_UNAVAILABLE,a,v);if(r==JSV06_REGION_DMA)return js_v06c_fail(m,s,JSV06_STOP_DMA_UNAVAILABLE,a,v);if(r==JSV06_REGION_INPUT)return js_v06c_fail(m,s,JSV06_STOP_INPUT_UNAVAILABLE,a,v);
 if(r==JSV06_REGION_WRAM_PORT){if(off==0x2180u){m->wram[m->wram_position]=v;m->wram_position=(m->wram_position+1u)&0x1FFFFu;}else if(off==0x2181u)m->wram_position=(m->wram_position&0x1FF00u)|v;else if(off==0x2182u)m->wram_position=(m->wram_position&0x100FFu)|((uint32_t)v<<8);else if(off==0x2183u)m->wram_position=(m->wram_position&0x0FFFFu)|((uint32_t)(v&1u)<<16);return 1;}
 if(r==JSV06_REGION_CPU_IO){if(off==0x4200u){m->nmitimen=v;return 1;}if(off==0x4201u){m->io_port_output=v;return 1;}if(off>=0x4202u&&off<=0x4206u){js_v06c_alu_write(m,off,v);return 1;}if(off==0x4207u){m->htimer=(uint16_t)((m->htimer&0x100u)|v);return 1;}if(off==0x4208u){m->htimer=(uint16_t)((m->htimer&0xFFu)|((uint16_t)(v&1u)<<8));return 1;}if(off==0x4209u){m->vtimer=(uint16_t)((m->vtimer&0x100u)|v);return 1;}if(off==0x420Au){m->vtimer=(uint16_t)((m->vtimer&0xFFu)|((uint16_t)(v&1u)<<8));return 1;}if(off==0x420Bu||off==0x420Cu)return js_v06c_fail(m,s,JSV06_STOP_DMA_UNAVAILABLE,a,v);if(off==0x420Du){m->memsel=v&1u;return 1;}return 1;}return js_v06c_fail(m,s,JSV06_STOP_INVALID_MACHINE,a,v);}
static uint8_t js_v06c_v05_read(void *opaque,uint32_t a,int *ok){JSV06Machine*m=(JSV06Machine*)opaque;uint8_t v=0;*ok=js_v06c_read8(m,a,&v,0);return v;}
static void js_v06c_v05_write(void *opaque,uint32_t a,uint8_t v,int *ok){*ok=js_v06c_write8((JSV06Machine*)opaque,a,v,0);}
JSExecResult js_v06c_step(JSV06Machine *m,JSV06Stop *s){JSBus bus;JSStop v05;int fg;JSExecResult r;if(!m)return JS_EXEC_STOP;js_v06c_stop_clear(s);m->pending_bus_stop=JSV06_STOP_NONE;fg=js_v06c_fetch_guard(m,s);if(fg<0)return JS_EXEC_STOP;if(fg==0){js_v06c_fail(m,s,JSV06_STOP_UNKNOWN_CONTEXT,((uint32_t)m->cpu.pbr<<16)|m->cpu.pc,0);return JS_EXEC_STOP;}bus.opaque=m;bus.read8=js_v06c_v05_read;bus.write8=js_v06c_v05_write;js_stop_clear(&v05);r=js_v05c_step(&m->cpu,&bus,&v05);if(r==JS_EXEC_STOP){if(s)s->v05=v05;if(v05.reason==JS_STOP_BUS_UNAVAILABLE&&m->pending_bus_stop!=JSV06_STOP_NONE){if(s){s->reason=m->pending_bus_stop;s->address=m->pending_bus_address;s->value=m->pending_bus_value;}return r;}if(s){s->reason=JSV06_STOP_V05;s->source_key=v05.source_key;s->observed_key=v05.observed_key;s->address=v05.address;s->value=v05.value;}}return r;}
'''

def generate(project:Path,rom_path:Path):
 m=load_model(project); rom=rom_path.read_bytes()
 if len(rom)!=m.ROM_SIZE:raise SystemExit('ROM size mismatch')
 rows=read_rows(project/'docs/V05C-production-manifest.csv')
 if len(rows)!=2258: raise SystemExit(f'expected 2258 V05 rows, got {len(rows)}')
 out=project/'generated/current/v06c'; out.mkdir(parents=True,exist_ok=True)
 for old in out.glob('*'): old.unlink()
 (project/'runtime/v06c_machine.h').write_text(c_header(),encoding='utf-8',newline='\n')
 (project/'runtime/v06c_machine.c').write_text(c_source(),encoding='utf-8',newline='\n')
 groups={}
 fetch_rows=[]
 for r in rows:
  pbr=int(r['PBR'],16);pc=int(r['PC'],16);key=int(r['Key_Hex'],16); b=bytes.fromhex(r['Bytes']); group=((pbr<<16)|pc)>>10
  groups.setdefault(group,[]).append((key,pbr,pc,b,r))
  for i,v in enumerate(b):
   a=(pbr<<16)|((pc+i)&0xFFFF);o=m.lorom_offset(a)
   if o is None or rom[o]!=v:raise SystemExit(f'fetch authority mismatch {r["Key"]} +{i}')
  fetch_rows.append({'Key':r['Key'],'Key_Hex':r['Key_Hex'],'PBR':r['PBR'],'PC':r['PC'],'Length':len(b),'Bytes':b.hex().upper(),'Shard':f'{group:04X}'})
 if len(groups)!=18:raise SystemExit(f'expected 18 shards got {len(groups)}')
 header='''#ifndef ROCKNROLL_V06C_FETCH_H\n#define ROCKNROLL_V06C_FETCH_H\n#include "v06c_machine.h"\nint js_v06c_fetch_guard(JSV06Machine *m, JSV06Stop *stop);\n#endif\n'''
 (out/'js_v06c_fetch.h').write_text(header,encoding='utf-8',newline='\n')
 shard_meta=[]
 for group,items in sorted(groups.items()):
  name=f'js_v06c_fetch_shard_{group:04X}'; shard_meta.append((group,name))
  lines=['#include "js_v06c_fetch.h"','',f'int {name}(JSV06Machine *m, JSV06Stop *stop) {{','    uint8_t got;','    switch(js_cpu_context_key(&m->cpu)) {']
  for key,pbr,pc,b,r in sorted(items):
   lines.append(f'    case 0x{key:08X}u:')
   for i,v in enumerate(b):
    a=(pbr<<16)|((pc+i)&0xFFFF)
    lines.append(f'        if(!js_v06c_read8(m,0x{a:06X}u,&got,stop)) return -1;')
    lines.append(f'        if(got!=0x{v:02X}u){{if(stop){{stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x{a:06X}u;stop->value=got;}}return -1;}}')
   lines.append('        return 1;')
  lines += ['    default: return 0;','    }','}','']
  (out/f'{name}.c').write_text('\n'.join(lines),encoding='utf-8',newline='\n')
 disp=['#include "js_v06c_fetch.h"','']+[f'int {n}(JSV06Machine *m, JSV06Stop *stop);' for _,n in shard_meta]
 disp += ['','int js_v06c_fetch_guard(JSV06Machine *m, JSV06Stop *stop) {','    int r; uint32_t group;','    if(!m) return -1;','    group=((((uint32_t)m->cpu.pbr<<16)|m->cpu.pc)>>10);','    switch(group) {']
 for g,n in shard_meta:disp.append(f'    case 0x{g:04X}u: r={n}(m,stop); break;')
 disp += ['    default: r=0; break;','    }','    return r;','}','']
 (out/'js_v06c_fetch.c').write_text('\n'.join(disp),encoding='utf-8',newline='\n')
 write_csv(project/'docs/V06C-fetch-manifest.csv',['Key','Key_Hex','PBR','PC','Length','Bytes','Shard'],fetch_rows)
 # Exhaustive mapping census: one pass over every physical S-CPU address.
 counts={x.name:0 for x in m.Region}
 aliases=[0]*(m.ROM_SIZE//0x8000)
 for a in range(1<<24):
  r=m.classify_address(a);counts[r.name]+=1
  if r==m.Region.ROM:
   o=m.lorom_offset(a);aliases[o>>15]+=1
 if sum(counts.values())!=(1<<24):raise AssertionError(counts)
 bus_rows=[{'Region':k,'Address_Count':v} for k,v in sorted(counts.items())]
 write_csv(project/'docs/V06C-bus-census.csv',['Region','Address_Count'],bus_rows)
 # 2 MEMSEL x 256 banks x 256 pages = 131072 timing cells.
 speed={0:{6:0,8:0,12:0},1:{6:0,8:0,12:0}}
 for ms in (0,1):
  for bank in range(256):
   for page in range(256): speed[ms][m.access_clocks((bank<<16)|(page<<8),ms)]+=1
 speed_rows=[{'MEMSEL':ms,'Master_Clocks':cl,'Cell_Count':speed[ms][cl]} for ms in (0,1) for cl in (6,8,12)]
 write_csv(project/'docs/V06C-speed-census.csv',['MEMSEL','Master_Clocks','Cell_Count'],speed_rows)
 summary={
  'schema':1,'milestone':'V06C','status':(project/'config/v06c-release-state.txt').read_text().strip(),'generator':PROJECT_MARK,
  'rom_sha256':m.ROM_SHA256,'rom_size':len(rom),'mapping':'strict 1 MiB FastROM LoROM; upper 32 KiB ROM windows only; no modulo',
  'address_space_count':1<<24,'region_counts':counts,'sram_address_count':0,
  'rom_physical_32k_alias_counts':{'min':min(aliases),'max':max(aliases),'distribution':{str(n):aliases.count(n) for n in sorted(set(aliases))}},
  'timing_cell_count':2*256*256,'timing_counts':{str(ms):{str(k):v for k,v in speed[ms].items()} for ms in (0,1)},
  'fetch_contexts':len(fetch_rows),'fetch_shards':len(groups),'v05_context_promotion_count':0,'gameplay_promotion_count':0,'trace_promotion_count':0,'oracle_promotion_count':0,
  'reset_vector':'00:8000','reset_vector_sampling':'side-effect-free untimed peek','pre_scheduler_counter_name':'access_clock_sum',
  'power_on_reset_distinction':'power-on initializes WRAM host image/open-bus/base latches/ALU; reset preserves WRAM, WRAM port, open bus, MEMSEL, timer/output latches and ALU while resetting CPU/reset-owned state',
  'deferred_components':['V07 scheduler/interrupt timing','V08 DMA/HDMA execution','V09 PPU','V10 input','later S-SMP/audio'],
  'compile_build_gate':'DEFERRED_BY_USER_POLICY_NOT_RUN_AT_VERSION_END'
 }
 (project/'docs/V06C-machine-summary.json').write_text(json.dumps(summary,indent=2,sort_keys=True)+'\n',encoding='utf-8',newline='\n')
 genfiles=sorted([project/'runtime/v06c_machine.c',project/'runtime/v06c_machine.h']+list(out.glob('*'))+[project/'docs/V06C-fetch-manifest.csv',project/'docs/V06C-bus-census.csv',project/'docs/V06C-speed-census.csv',project/'docs/V06C-machine-summary.json'])
 hashes={str(p.relative_to(project)):sha(p) for p in genfiles}
 (out/'V06C-GENERATED-SHA256.json').write_text(json.dumps(hashes,indent=2,sort_keys=True)+'\n',encoding='utf-8',newline='\n')
 print(json.dumps({'contexts':len(fetch_rows),'shards':len(groups),'counts':counts,'alias_distribution':summary['rom_physical_32k_alias_counts'],'timing':summary['timing_counts'],'generated_files':len(hashes)+1},sort_keys=True))

def main():
 ap=argparse.ArgumentParser();ap.add_argument('--project',type=Path,required=True);ap.add_argument('--rom',type=Path,required=True);a=ap.parse_args();generate(a.project.resolve(),a.rom.resolve())
if __name__=='__main__':main()
