#include "v06c_machine.h"
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
