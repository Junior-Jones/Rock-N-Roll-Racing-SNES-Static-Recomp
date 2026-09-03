#include "v07c_machine.h"
#include "js_v05c_dispatch.h"
#include <string.h>

/* V07C is the one active timing path. V06C remains immutable predecessor evidence;
 * its approximate pre-scheduler timing wrapper is deliberately not linked by the V07 build authority. */

static int jsv07_system_bank(uint8_t bank) { return bank <= 0x3Fu || (bank >= 0x80u && bank <= 0xBFu); }
static uint16_t jsv07_vblank_start(const JSV07Scheduler *s) { return s->overscan ? 240u : 225u; }
static uint16_t jsv07_last_scanline(const JSV07Scheduler *s) { return (s->interlace && !s->field_odd) ? 262u : 261u; }
static int jsv07_in_vblank(const JSV07Scheduler *s) { return s->scanline >= jsv07_vblank_start(s); }
static int jsv07_in_hblank(const JSV07Scheduler *s) { return !(s->hclock >= 4u && s->hclock <= 1096u); }

static void jsv07_event(JSV07Scheduler *s, uint32_t code, uint32_t detail) {
    /* Deterministic compact event certificate; not execution authority. */
    uint64_t x = ((uint64_t)code << 48) ^ ((uint64_t)s->scanline << 32) ^
                 ((uint64_t)s->hclock << 16) ^ (uint64_t)detail ^ s->master_clock;
    s->event_digest ^= x + UINT64_C(0x9E3779B97F4A7C15) + (s->event_digest << 6) + (s->event_digest >> 2);
    s->event_count++;
}

void js_v07c_stop_clear(JSV07Stop *s) { if(s) memset(s,0,sizeof(*s)); }
static int jsv07_fail(JSV07Machine *m, JSV07Stop *s, JSV07StopReason r, uint32_t a, uint8_t v) {
    if(m){m->pending_bus_stop=r;m->pending_bus_address=a&0xFFFFFFu;m->pending_bus_value=v;}
    if(s){
        s->reason=r;s->address=a&0xFFFFFFu;s->value=v;s->source_key=js_cpu_context_key(m?&m->cpu:0);
        if(m){s->master_clock=m->scheduler.master_clock;s->scanline=m->scheduler.scanline;s->hclock=m->scheduler.hclock;}
    }
    return 0;
}

JSV07Region js_v07c_classify(uint32_t address) {
    uint8_t bank; uint16_t off; address &= 0xFFFFFFu; bank=(uint8_t)(address>>16); off=(uint16_t)address;
    if(bank==0x7Eu || bank==0x7Fu) return JSV07_REGION_WRAM;
    if(jsv07_system_bank(bank)) {
        if(off<=0x1FFFu) return JSV07_REGION_WRAM;
        if(off>=0x2100u && off<=0x213Fu) return JSV07_REGION_PPU;
        if(off>=0x2140u && off<=0x217Fu) return JSV07_REGION_APU;
        if(off>=0x2180u && off<=0x2183u) return JSV07_REGION_WRAM_PORT;
        if(off==0x4016u || off==0x4017u || (off>=0x4218u && off<=0x421Fu)) return JSV07_REGION_INPUT;
        if(off>=0x4200u && off<=0x4217u) return JSV07_REGION_CPU_IO;
        if(off>=0x4300u && off<=0x437Fu) return JSV07_REGION_DMA;
    }
    if(off>=0x8000u) return JSV07_REGION_ROM;
    return JSV07_REGION_OPEN_BUS;
}
int js_v07c_lorom_offset(uint32_t address, uint32_t *offset) {
    uint8_t bank; uint16_t off; address&=0xFFFFFFu;bank=(uint8_t)(address>>16);off=(uint16_t)address;
    if(!offset||bank==0x7Eu||bank==0x7Fu||off<0x8000u)return 0;
    *offset=(((uint32_t)bank&0x1Fu)<<15)|(off&0x7FFFu);return 1;
}
int js_v07c_wram_offset(uint32_t address,uint32_t *offset) {
    uint8_t bank;uint16_t off;address&=0xFFFFFFu;bank=(uint8_t)(address>>16);off=(uint16_t)address;if(!offset)return 0;
    if(bank==0x7Eu){*offset=off;return 1;}if(bank==0x7Fu){*offset=0x10000u|off;return 1;}
    if(jsv07_system_bank(bank)&&off<=0x1FFFu){*offset=off;return 1;}return 0;
}
uint8_t js_v07c_access_clocks(uint32_t address,uint8_t memsel) {
    uint8_t bg=(uint8_t)((address>>22)&3u),page=(uint8_t)(address>>8);memsel=memsel?1u:0u;
    if(bg==1u)return 8u;if(bg==3u)return memsel?6u:8u;if(page<=0x1Fu)return 8u;if(page<=0x3Fu)return 6u;
    if(page<=0x41u)return 12u;if(page<=0x5Fu)return 6u;if(page<=0x7Fu)return 8u;if(bg==0u)return 8u;return memsel?6u:8u;
}

static void jsv07_update_smp(JSV07Scheduler *s) {
    /* Exact rational target; no floating point and no independent audio clock. */
    uint64_t q=s->master_clock/JSV07_SMP_RATIO_DEN, r=s->master_clock%JSV07_SMP_RATIO_DEN;
    uint64_t product=r*(uint64_t)JSV07_SMP_RATIO_NUM;
    s->smp_target_cycle=q*(uint64_t)JSV07_SMP_RATIO_NUM + product/JSV07_SMP_RATIO_DEN;
    s->smp_target_remainder=(uint32_t)(product%JSV07_SMP_RATIO_DEN);
}
static void jsv07_update_irq_level(JSV07Scheduler *s) {
    int enabled=s->enable_hirq||s->enable_virq, level;
    if(!enabled){s->irq_level=0;return;}
    level=(!s->enable_hirq||s->htimer==s->hcounter)&&(!s->enable_virq||s->vtimer==s->vcounter);
    if(!s->irq_level&&level){s->need_irq=(uint8_t)((s->enable_hirq&&s->hclock==6u)?3u:2u);jsv07_event(s,8u,s->need_irq);}
    s->irq_level=(uint8_t)level;
}
static void jsv07_process_irq(JSV07Scheduler *s) {
    if(s->need_irq>0u){s->need_irq--;if(s->need_irq==1u){s->irq_flag=1u;jsv07_event(s,9u,0u);}else if(s->need_irq==0u){s->irq_source=s->irq_flag;jsv07_event(s,10u,s->irq_source);}}
    if(s->hclock>10u)s->hcounter=(uint16_t)((s->hcounter+1u)&0x1FFu);
    else if(s->hclock==10u)s->hcounter=0u;
    else if(s->hclock==6u){s->hcounter=0u;if(s->scanline>0u)s->vcounter=(uint16_t)((s->vcounter+1u)&0x1FFu);if(s->enable_nmi&&s->scanline==jsv07_vblank_start(s)){s->nmi_signal=1u;jsv07_event(s,6u,0u);}}
    else if(s->hclock==2u){s->hcounter=(uint16_t)((s->hcounter+1u)&0x1FFu);if(s->scanline==jsv07_vblank_start(s)){s->nmi_flag=1u;jsv07_event(s,5u,0u);}else if(s->scanline==0u){s->nmi_flag=0u;s->vcounter=0u;}}
    jsv07_update_irq_level(s);
}
static void jsv07_process_autojoy(JSV07Scheduler *s) {
    if(s->autojoy_disabled)return;
    while(s->autojoy_next_clock<=s->master_clock){
        uint64_t clock=s->autojoy_next_clock;int step;s->autojoy_next_clock+=128u;step=(int)((clock-s->autojoy_clock_start)/128u);s->autojoy_step=(int8_t)step;
        if(step==0)s->autojoy_strobe=s->enable_autojoy;
        else if(step==1){if(!s->enable_autojoy){s->autojoy_disabled=1u;s->autojoy_active=0u;}else{s->autojoy_active=1u;memset(s->controller_data,0,sizeof(s->controller_data));}}
        else if(step==2)s->autojoy_strobe=0u;
        else {if(!s->enable_autojoy)step=34;else if(!(step&1)){uint8_t p1=s->autojoy_sample_bits[0],p2=s->autojoy_sample_bits[1];s->controller_data[0]=(uint16_t)((s->controller_data[0]<<1)|(p1&1u));s->controller_data[1]=(uint16_t)((s->controller_data[1]<<1)|(p2&1u));s->controller_data[2]=(uint16_t)((s->controller_data[2]<<1)|((p1>>1)&1u));s->controller_data[3]=(uint16_t)((s->controller_data[3]<<1)|((p2>>1)&1u));}}
        jsv07_event(s,11u,(uint32_t)step);if(step>=34){s->autojoy_disabled=1u;s->autojoy_active=0u;s->autojoy_strobe=0u;return;}
    }
}
static void jsv07_arm_autojoy(JSV07Scheduler *s) {
    uint64_t r=s->master_clock+130u;s->autojoy_clock_start=r+((r&0xFFu)?(256u-(r&0xFFu)):0u)-128u;s->autojoy_next_clock=s->autojoy_clock_start;s->autojoy_disabled=0u;s->autojoy_step=-1;jsv07_event(s,12u,(uint32_t)s->autojoy_clock_start);
}
static void jsv07_queue_dma(JSV07Scheduler *s,JSV07DmaRendezvous kind) {
    if(kind==JSV07_DMA_NONE)return;if(s->dma_request==JSV07_DMA_NONE||kind>s->dma_request)s->dma_request=kind;s->dma_start_delay=1u;jsv07_event(s,13u,(uint32_t)kind);
}
static int jsv07_line_ends(const JSV07Scheduler *s) {
    if(s->hclock>=JSV07_NORMAL_SCANLINE_CLOCKS)return 1;
    return s->hclock==JSV07_SHORT_SCANLINE_CLOCKS&&s->scanline==240u&&s->field_odd&&!s->interlace;
}
static void jsv07_tick2(JSV07Scheduler *s);
void js_v07c_scheduler_advance_wall(JSV07Scheduler *s,uint32_t clocks) { while(clocks>=2u){jsv07_tick2(s);clocks-=2u;} }
static void jsv07_primary(JSV07Scheduler *s) {
    if(s->next_primary_event==JSV07_EVENT_HDMA_INIT){jsv07_event(s,1u,0u);if(s->hdma_enable_mask)jsv07_queue_dma(s,JSV07_DMA_HDMA_INIT);s->next_primary_event=JSV07_EVENT_DRAM_REFRESH;s->next_primary_clock=s->dram_refresh_position;return;}
    if(s->next_primary_event==JSV07_EVENT_DRAM_REFRESH){jsv07_event(s,2u,0u);js_v07c_scheduler_advance_wall(s,JSV07_DRAM_REFRESH_CLOCKS);jsv07_event(s,3u,0u);if(s->scanline<jsv07_vblank_start(s)){s->next_primary_event=JSV07_EVENT_HDMA_LINE;s->next_primary_clock=JSV07_HDMA_LINE_HCLOCK;}else{s->next_primary_event=JSV07_EVENT_END_SCANLINE;s->next_primary_clock=1360u;}return;}
    if(s->next_primary_event==JSV07_EVENT_HDMA_LINE){jsv07_event(s,4u,0u);if(s->hdma_enable_mask)jsv07_queue_dma(s,JSV07_DMA_HDMA_LINE);s->next_primary_event=JSV07_EVENT_END_SCANLINE;s->next_primary_clock=1360u;return;}
    if(!jsv07_line_ends(s)){s->next_primary_clock=(uint16_t)(s->next_primary_clock+2u);return;}
    {uint16_t ended=s->scanline;s->scanline++;s->hclock=0u;jsv07_event(s,14u,ended);if(s->scanline==jsv07_vblank_start(s)){jsv07_event(s,15u,0u);jsv07_arm_autojoy(s);}if(s->scanline>jsv07_last_scanline(s)){s->field_odd^=1u;s->scanline=0u;s->frame_number++;jsv07_event(s,16u,s->field_odd);}s->dram_refresh_position=(uint16_t)(538u-(s->master_clock&7u));if(s->scanline==0u){s->next_primary_event=JSV07_EVENT_HDMA_INIT;s->next_primary_clock=(uint16_t)(12u+(s->master_clock&7u));}else{s->next_primary_event=JSV07_EVENT_DRAM_REFRESH;s->next_primary_clock=s->dram_refresh_position;}}
}
static void jsv07_tick2(JSV07Scheduler *s) {
    s->master_clock+=2u;s->hclock=(uint16_t)(s->hclock+2u);if(s->hclock==s->next_primary_clock)jsv07_primary(s);
    if((s->hclock&3u)==0u){/* V09 PPU phase seam; timeline already authoritative. */}
    else if(s->hclock&2u)jsv07_process_irq(s);
    jsv07_process_autojoy(s);jsv07_update_smp(s);
}
void js_v07c_scheduler_init(JSV07Scheduler *s) {
    if(!s)return;memset(s,0,sizeof(*s));s->forced_blank=1u;s->htimer=0x1FFu;s->vtimer=0x1FFu;s->autojoy_disabled=1u;s->autojoy_step=-1;s->dram_refresh_position=538u;s->next_primary_clock=538u;s->next_primary_event=JSV07_EVENT_DRAM_REFRESH;s->event_digest=UINT64_C(0xCBF29CE484222325);jsv07_update_smp(s);
}
void js_v07c_scheduler_reset_cpu_side(JSV07Scheduler *s) {
    if(!s)return;s->enable_autojoy=s->enable_nmi=s->enable_hirq=s->enable_virq=0u;s->nmi_flag=s->nmi_signal=s->nmi_pending=0u;s->irq_level=s->need_irq=s->irq_flag=s->irq_source=0u;s->autojoy_clock_start=s->autojoy_next_clock=0u;s->autojoy_active=0u;s->autojoy_disabled=1u;s->autojoy_strobe=0u;s->autojoy_step=-1;s->dma_request=s->dma_rendezvous_ready=JSV07_DMA_NONE;s->dma_start_delay=0u;s->manual_dma_mask=s->hdma_enable_mask=0u;s->cpu_stop=JSV07_CPU_RUNNING;jsv07_event(s,17u,0u);
}
void js_v07c_scheduler_set_display(JSV07Scheduler *s,int overscan,int interlace){if(s){s->overscan=(uint8_t)!!overscan;s->interlace=(uint8_t)!!interlace;}}
static JSV07DmaRendezvous jsv07_cpu_boundary(JSV07Scheduler *s) {
    s->cpu_cycle_count++;if(s->nmi_signal){s->nmi_signal=0u;s->nmi_pending=1u;jsv07_event(s,7u,0u);}if(s->dma_request!=JSV07_DMA_NONE){if(s->dma_start_delay)s->dma_start_delay--;if(!s->dma_start_delay){s->dma_rendezvous_ready=s->dma_request;s->dma_request=JSV07_DMA_NONE;jsv07_event(s,18u,s->dma_rendezvous_ready);}}return s->dma_rendezvous_ready;
}
void js_v07c_scheduler_internal_cycle(JSV07Machine *m){if(m){if(m->pending_bus_stop!=JSV07_STOP_NONE)return;if(jsv07_cpu_boundary(&m->scheduler)!=JSV07_DMA_NONE){m->pending_bus_stop=JSV07_STOP_DMA_TRANSFER_V08;m->pending_bus_address=0x00420Bu;return;}js_v07c_scheduler_advance_wall(&m->scheduler,6u);}}
void js_v07c_wai(JSV07Machine *m){if(m){m->scheduler.cpu_stop=JSV07_CPU_WAI;jsv07_event(&m->scheduler,19u,0u);}}
void js_v07c_stp(JSV07Machine *m){if(m){m->scheduler.cpu_stop=JSV07_CPU_STP;jsv07_event(&m->scheduler,20u,0u);}}
void js_v07c_halted_quantum(JSV07Machine *m){if(!m)return;if(m->scheduler.cpu_stop==JSV07_CPU_STP){js_v07c_scheduler_advance_wall(&m->scheduler,4u);return;}if(m->scheduler.cpu_stop==JSV07_CPU_WAI){js_v07c_scheduler_internal_cycle(m);if(m->scheduler.nmi_pending||m->scheduler.irq_source){m->scheduler.cpu_stop=JSV07_CPU_RUNNING;jsv07_event(&m->scheduler,21u,0u);}}}

static void jsv07_alu_run(JSV07Machine *m,int is_read){uint64_t target=m->scheduler.cpu_cycle_count-(is_read&&m->scheduler.cpu_cycle_count?1u:0u),cycles;if(target<m->alu.prev_cpu_cycle)target=m->alu.prev_cpu_cycle;cycles=target-m->alu.prev_cpu_cycle;while(cycles--){if(!m->alu.mult_counter&&!m->alu.div_counter)break;if(m->alu.mult_counter){m->alu.mult_counter--;if(m->alu.div_result&1u)m->alu.mult_or_remainder=(uint16_t)(m->alu.mult_or_remainder+m->alu.shift);m->alu.shift<<=1;m->alu.div_result>>=1;}if(m->alu.div_counter){m->alu.div_counter--;m->alu.shift>>=1;m->alu.div_result<<=1;if(m->alu.mult_or_remainder>=m->alu.shift){m->alu.mult_or_remainder=(uint16_t)(m->alu.mult_or_remainder-m->alu.shift);m->alu.div_result|=1u;}}}m->alu.prev_cpu_cycle=target;}
static uint8_t jsv07_alu_read(JSV07Machine *m,uint16_t off){jsv07_alu_run(m,1);switch(off){case 0x4214:return(uint8_t)m->alu.div_result;case 0x4215:return(uint8_t)(m->alu.div_result>>8);case 0x4216:return(uint8_t)m->alu.mult_or_remainder;default:return(uint8_t)(m->alu.mult_or_remainder>>8);}}
static void jsv07_alu_write(JSV07Machine *m,uint16_t off,uint8_t v){int block;jsv07_alu_run(m,1);block=m->alu.div_counter||m->alu.mult_counter;jsv07_alu_run(m,0);switch(off){case 0x4202:m->alu.mult_operand1=v;break;case 0x4203:m->alu.mult_or_remainder=0;if(!block){m->alu.mult_counter=8;m->alu.mult_operand2=v;m->alu.div_result=(uint16_t)(((uint16_t)v<<8)|m->alu.mult_operand1);m->alu.shift=v;}break;case 0x4204:m->alu.dividend=(uint16_t)((m->alu.dividend&0xFF00u)|v);break;case 0x4205:m->alu.dividend=(uint16_t)((m->alu.dividend&0x00FFu)|((uint16_t)v<<8));break;case 0x4206:m->alu.mult_or_remainder=m->alu.dividend;if(!block){m->alu.div_counter=16;m->alu.divisor=v;m->alu.shift=(uint32_t)v<<16;}break;default:break;}}

uint8_t js_v07c_peek8(const JSV07Machine *m,uint32_t a){uint32_t o;uint16_t off=(uint16_t)a;JSV07Region r;if(!m)return 0;a&=0xFFFFFFu;r=js_v07c_classify(a);if(r==JSV07_REGION_ROM&&js_v07c_lorom_offset(a,&o)&&o<m->rom_size)return m->rom[o];if(r==JSV07_REGION_WRAM&&js_v07c_wram_offset(a,&o))return m->wram[o];if(r==JSV07_REGION_WRAM_PORT&&off==0x2180u)return m->wram[m->wram_position];if(r==JSV07_REGION_CPU_IO){if(off==0x4213u)return m->io_port_output;if(off==0x4214u)return(uint8_t)m->alu.div_result;if(off==0x4215u)return(uint8_t)(m->alu.div_result>>8);if(off==0x4216u)return(uint8_t)m->alu.mult_or_remainder;if(off==0x4217u)return(uint8_t)(m->alu.mult_or_remainder>>8);}return m->open_bus;}
uint16_t js_v07c_reset_vector(const JSV07Machine *m){return(uint16_t)(js_v07c_peek8(m,0x00FFFCu)|((uint16_t)js_v07c_peek8(m,0x00FFFDu)<<8));}

static void jsv07_write_nmitimen(JSV07Machine *m,uint8_t v){JSV07Scheduler*s=&m->scheduler;uint8_t old=s->enable_nmi;jsv07_process_autojoy(s);s->enable_virq=!!(v&0x20u);s->enable_hirq=!!(v&0x10u);s->enable_autojoy=!!(v&1u);if(s->nmi_flag&&(v&0x80u)&&!old){s->nmi_signal=1u;jsv07_event(s,22u,0u);}s->enable_nmi=!!(v&0x80u);if(!(s->enable_hirq||s->enable_virq)){s->irq_flag=0u;s->irq_source=0u;}jsv07_update_irq_level(s);}
static uint8_t jsv07_read4210(JSV07Machine*m){JSV07Scheduler*s=&m->scheduler;uint8_t v=(uint8_t)((s->nmi_flag?0x80u:0u)|0x02u|(m->open_bus&0x70u));if(s->nmi_flag&&(s->hclock>=6u||s->scanline!=jsv07_vblank_start(s)))s->nmi_flag=0u;return v;}
static uint8_t jsv07_read4211(JSV07Machine*m){JSV07Scheduler*s=&m->scheduler;uint8_t v=(uint8_t)((s->irq_flag?0x80u:0u)|(m->open_bus&0x7Fu));if(s->irq_flag&&!s->need_irq){s->irq_flag=0u;s->irq_source=0u;}return v;}
static uint8_t jsv07_read4212(JSV07Machine*m){JSV07Scheduler*s=&m->scheduler;jsv07_process_autojoy(s);return(uint8_t)((jsv07_in_vblank(s)?0x80u:0u)|(jsv07_in_hblank(s)?0x40u:0u)|(s->autojoy_active?1u:0u)|(m->open_bus&0x3Eu));}

static int jsv07_read_effect(JSV07Machine*m,uint32_t a,uint8_t*out,JSV07Stop*s){uint32_t o;uint16_t off=(uint16_t)a;JSV07Region r=js_v07c_classify(a);if(r==JSV07_REGION_ROM){js_v07c_lorom_offset(a,&o);*out=m->rom[o];m->open_bus=*out;return 1;}if(r==JSV07_REGION_WRAM){js_v07c_wram_offset(a,&o);*out=m->wram[o];m->open_bus=*out;return 1;}if(r==JSV07_REGION_OPEN_BUS){*out=m->open_bus;return 1;}if(r==JSV07_REGION_PPU)return jsv07_fail(m,s,JSV07_STOP_PPU_UNAVAILABLE,a,0);if(r==JSV07_REGION_APU)return jsv07_fail(m,s,JSV07_STOP_APU_UNAVAILABLE,a,0);if(r==JSV07_REGION_DMA)return jsv07_fail(m,s,JSV07_STOP_DMA_TRANSFER_V08,a,0);if(r==JSV07_REGION_INPUT&&!(off>=0x4218u&&off<=0x421Fu))return jsv07_fail(m,s,JSV07_STOP_INPUT_V11,a,0);
 if(r==JSV07_REGION_WRAM_PORT){if(off==0x2180u){*out=m->wram[m->wram_position];m->wram_position=(m->wram_position+1u)&0x1FFFFu;m->open_bus=*out;}else *out=m->open_bus;return 1;}
 if(r==JSV07_REGION_INPUT&&off>=0x4218u&&off<=0x421Fu){unsigned i=(unsigned)(off-0x4218u);*out=(uint8_t)(m->scheduler.controller_data[i>>1]>>((i&1u)?8:0));m->open_bus=*out;return 1;}
 if(r==JSV07_REGION_CPU_IO){if(off==0x4210u)*out=jsv07_read4210(m);else if(off==0x4211u)*out=jsv07_read4211(m);else if(off==0x4212u)*out=jsv07_read4212(m);else if(off==0x4213u)*out=m->io_port_output;else if(off>=0x4214u&&off<=0x4217u)*out=jsv07_alu_read(m,off);else *out=m->open_bus;m->open_bus=*out;return 1;}return jsv07_fail(m,s,JSV07_STOP_INVALID_MACHINE,a,0);}
static int jsv07_write_effect(JSV07Machine*m,uint32_t a,uint8_t v,JSV07Stop*s){uint32_t o;uint16_t off=(uint16_t)a;JSV07Region r=js_v07c_classify(a);if(r==JSV07_REGION_ROM)return jsv07_fail(m,s,JSV07_STOP_ROM_WRITE,a,v);if(r==JSV07_REGION_WRAM){js_v07c_wram_offset(a,&o);m->wram[o]=v;return 1;}if(r==JSV07_REGION_OPEN_BUS)return 1;if(r==JSV07_REGION_PPU)return jsv07_fail(m,s,JSV07_STOP_PPU_UNAVAILABLE,a,v);if(r==JSV07_REGION_APU)return jsv07_fail(m,s,JSV07_STOP_APU_UNAVAILABLE,a,v);if(r==JSV07_REGION_DMA)return jsv07_fail(m,s,JSV07_STOP_DMA_TRANSFER_V08,a,v);if(r==JSV07_REGION_INPUT)return jsv07_fail(m,s,JSV07_STOP_INPUT_V11,a,v);
 if(r==JSV07_REGION_WRAM_PORT){if(off==0x2180u){m->wram[m->wram_position]=v;m->wram_position=(m->wram_position+1u)&0x1FFFFu;}else if(off==0x2181u)m->wram_position=(m->wram_position&0x1FF00u)|v;else if(off==0x2182u)m->wram_position=(m->wram_position&0x100FFu)|((uint32_t)v<<8);else if(off==0x2183u)m->wram_position=(m->wram_position&0x0FFFFu)|((uint32_t)(v&1u)<<16);return 1;}
 if(r==JSV07_REGION_CPU_IO){JSV07Scheduler*sc=&m->scheduler;if(off==0x4200u){jsv07_write_nmitimen(m,v);return 1;}if(off==0x4201u){m->io_port_output=v;return 1;}if(off>=0x4202u&&off<=0x4206u){jsv07_alu_write(m,off,v);return 1;}if(off==0x4207u){sc->htimer=(uint16_t)((sc->htimer&0x100u)|v);jsv07_update_irq_level(sc);return 1;}if(off==0x4208u){sc->htimer=(uint16_t)((sc->htimer&0xFFu)|((uint16_t)(v&1u)<<8));jsv07_update_irq_level(sc);return 1;}if(off==0x4209u){sc->vtimer=(uint16_t)((sc->vtimer&0x100u)|v);jsv07_update_irq_level(sc);return 1;}if(off==0x420Au){sc->vtimer=(uint16_t)((sc->vtimer&0xFFu)|((uint16_t)(v&1u)<<8));jsv07_update_irq_level(sc);return 1;}if(off==0x420Bu){sc->manual_dma_mask=v;if(v)jsv07_queue_dma(sc,JSV07_DMA_MANUAL);return 1;}if(off==0x420Cu){sc->hdma_enable_mask=v;return 1;}if(off==0x420Du){m->memsel=v&1u;return 1;}return 1;}return jsv07_fail(m,s,JSV07_STOP_INVALID_MACHINE,a,v);}

int js_v07c_read8(JSV07Machine*m,uint32_t a,uint8_t*out,JSV07Stop*s){uint8_t clocks;if(!m||!out)return jsv07_fail(m,s,JSV07_STOP_INVALID_MACHINE,a,0);a&=0xFFFFFFu;clocks=js_v07c_access_clocks(a,m->memsel);if(jsv07_cpu_boundary(&m->scheduler)!=JSV07_DMA_NONE)return jsv07_fail(m,s,JSV07_STOP_DMA_TRANSFER_V08,a,0);js_v07c_scheduler_advance_wall(&m->scheduler,(uint32_t)(clocks-4u));jsv07_event(&m->scheduler,23u,a);if(!jsv07_read_effect(m,a,out,s))return 0;js_v07c_scheduler_advance_wall(&m->scheduler,4u);return 1;}
int js_v07c_write8(JSV07Machine*m,uint32_t a,uint8_t v,JSV07Stop*s){uint8_t clocks;if(!m)return jsv07_fail(m,s,JSV07_STOP_INVALID_MACHINE,a,v);a&=0xFFFFFFu;clocks=js_v07c_access_clocks(a,m->memsel);if(jsv07_cpu_boundary(&m->scheduler)!=JSV07_DMA_NONE)return jsv07_fail(m,s,JSV07_STOP_DMA_TRANSFER_V08,a,v);js_v07c_scheduler_advance_wall(&m->scheduler,clocks);jsv07_event(&m->scheduler,24u,a);return jsv07_write_effect(m,a,v,s);}

int js_v07c_power_on(JSV07Machine*m,const uint8_t*rom,size_t size,const uint8_t*initial_wram){if(!m||!rom||size!=JSV07_ROM_SIZE)return 0;memset(m,0,sizeof(*m));m->rom=rom;m->rom_size=size;if(initial_wram)memcpy(m->wram,initial_wram,JSV07_WRAM_SIZE);m->io_port_output=0xFFu;m->alu.mult_operand1=0xFFu;m->alu.dividend=0xFFFFu;js_v07c_scheduler_init(&m->scheduler);m->cpu.s=0x01FFu;m->cpu.p=JS_P_I|JS_P_M|JS_P_X;m->cpu.e=1u;m->cpu.pc=js_v07c_reset_vector(m);js_v07c_scheduler_advance_wall(&m->scheduler,JSV07_RESET_STARTUP_CLOCKS);return 1;}
int js_v07c_reset(JSV07Machine*m){if(!m||!m->rom||m->rom_size!=JSV07_ROM_SIZE)return 0;m->cpu.p=(uint8_t)((m->cpu.p|JS_P_I|JS_P_M|JS_P_X)&(uint8_t)~JS_P_D);m->cpu.e=1u;m->cpu.dbr=0u;m->cpu.d=0u;m->cpu.pbr=0u;m->cpu.x&=0xFFu;m->cpu.y&=0xFFu;m->cpu.s=(uint16_t)(0x0100u|(m->cpu.s&0xFFu));m->cpu.pc=js_v07c_reset_vector(m);js_v07c_scheduler_reset_cpu_side(&m->scheduler);m->pending_bus_stop=JSV07_STOP_NONE;js_v07c_scheduler_advance_wall(&m->scheduler,JSV07_RESET_STARTUP_CLOCKS);return 1;}

/* Instruction timing choreography around frozen V05C native bodies. */
static void jsv07_idle_n(JSV07Machine*m,unsigned n){while(n--)js_v07c_scheduler_internal_cycle(m);}
static int jsv07_fetch_byte(JSV07Machine*m,const JSV07TimingPlan*p,unsigned i,JSV07Stop*s){uint8_t v=0;uint32_t a=((uint32_t)m->cpu.pbr<<16)|(uint16_t)(m->cpu.pc+i);if(!js_v07c_read8(m,a,&v,s))return 0;if(v!=p->bytes[i])return jsv07_fail(m,s,JSV07_STOP_STATIC_CODE_MISMATCH,a,v);return 1;}
static int jsv07_branch_taken(const JSV07ExecTiming*t){uint8_t op=t->plan->opcode,p=t->before.p;switch(op){case 0x10:return !(p&JS_P_N);case 0x30:return !!(p&JS_P_N);case 0x50:return !(p&JS_P_V);case 0x70:return !!(p&JS_P_V);case 0x90:return !(p&JS_P_C);case 0xB0:return !!(p&JS_P_C);case 0xD0:return !(p&JS_P_Z);case 0xF0:return !!(p&JS_P_Z);default:return 0;}}
static int jsv07_index_cross(const JSV07ExecTiming*t){uint16_t base,index;if(t->plan->mode==JSV07_MODE_ABS_X){base=(uint16_t)t->plan->operand;index=t->before.x;}else if(t->plan->mode==JSV07_MODE_ABS_Y){base=(uint16_t)t->plan->operand;index=t->before.y;}else if(t->plan->mode==JSV07_MODE_DP_IND_Y&&t->pointer_bytes_seen>=2u){base=(uint16_t)(t->pointer_lo|((uint16_t)t->pointer_hi<<8));index=t->before.y;}else return 0;return ((base&0xFF00u)!=((uint16_t)(base+index)&0xFF00u));}
static void jsv07_before_body_access(JSV07Machine*m,int is_write){JSV07ExecTiming*t=&m->timing;uint32_t f=t->plan->rule_flags;unsigned i=0;
 if(!t->pre_access_idle_done){if((f&JSV07_RULE_DYN_DIRECT_LOW_PRE_IDLE)&&(t->before.d&0xFFu))jsv07_idle_n(m,1u);if(f&JSV07_RULE_STACK_REL_PRE_DATA_IDLE)jsv07_idle_n(m,1u);t->pre_access_idle_done=1u;}
 if(!t->pre_stack_idle_done&&is_write&&(f&(JSV07_RULE_JSR_PRE_STACK_IDLE|JSV07_RULE_PUSH_PRE_IDLE))){jsv07_idle_n(m,1u);t->pre_stack_idle_done=1u;}
 if(!t->pre_stack_idle_done&&!is_write&&(f&(JSV07_RULE_RETURN_PRE_IDLE|JSV07_RULE_PULL_PRE_IDLE))){if(f&JSV07_RULE_RETURN_PRE_IDLE)i=2u;else i=2u;jsv07_idle_n(m,i);t->pre_stack_idle_done=1u;}
 if(!t->index_idle_done){int at_data=(!is_write&&t->read_count>=t->plan->pointer_reads)||(is_write&&t->read_count>=t->plan->pointer_reads);if(at_data){if(f&JSV07_RULE_INDEX_FIXED_PRE_DATA_IDLE)jsv07_idle_n(m,1u);if((f&JSV07_RULE_DYN_INDEX_PRE_DATA_IDLE)&&jsv07_index_cross(t))jsv07_idle_n(m,1u);t->index_idle_done=1u;}}
 if(is_write&&!t->rmw_idle_done&&(f&JSV07_RULE_RMW_INTERMEDIATE_IDLE)){jsv07_idle_n(m,1u);t->rmw_idle_done=1u;}
}
static uint8_t jsv07_v05_read(void*opaque,uint32_t a,int*ok){JSV07Machine*m=(JSV07Machine*)opaque;uint8_t v=0;jsv07_before_body_access(m,0);*ok=js_v07c_read8(m,a,&v,0);if(*ok&&m->timing.read_count<m->timing.plan->pointer_reads){if(m->timing.pointer_bytes_seen==0u)m->timing.pointer_lo=v;else if(m->timing.pointer_bytes_seen==1u)m->timing.pointer_hi=v;m->timing.pointer_bytes_seen++;}m->timing.read_count++;return v;}
static void jsv07_v05_write(void*opaque,uint32_t a,uint8_t v,int*ok){JSV07Machine*m=(JSV07Machine*)opaque;jsv07_before_body_access(m,1);*ok=js_v07c_write8(m,a,v,0);m->timing.write_count++;if(*ok&&!m->timing.jsl_deferred_done&&(m->timing.plan->rule_flags&JSV07_RULE_JSL_AFTER_PBR_PUSH_IDLE)&&m->timing.write_count==1u){js_v07c_scheduler_internal_cycle(m);*ok=jsv07_fetch_byte(m,m->timing.plan,3u,0);m->timing.jsl_deferred_done=1u;}}
static int jsv07_prefetch(JSV07Machine*m,const JSV07TimingPlan*p,JSV07Stop*s){unsigned n=(p->rule_flags&JSV07_RULE_JSL_AFTER_PBR_PUSH_IDLE)?3u:p->length,i;for(i=0;i<n;i++)if(!jsv07_fetch_byte(m,p,i,s))return 0;return 1;}
static void jsv07_pre_body_fixed(JSV07Machine*m,const JSV07TimingPlan*p){uint32_t f=p->rule_flags;if(f&JSV07_RULE_IMPLIED_PRE_IDLE)jsv07_idle_n(m,1u);if(f&JSV07_RULE_XBA_EXTRA_IDLE)jsv07_idle_n(m,1u);if(f&JSV07_RULE_STATUS_PRE_IDLE)jsv07_idle_n(m,1u);if(f&JSV07_RULE_RELLONG_PRE_IDLE)jsv07_idle_n(m,1u);}
static void jsv07_post_body(JSV07Machine*m,const JSV07TimingPlan*p){uint32_t f=p->rule_flags;if(f&JSV07_RULE_RTS_POST_POP_IDLE)jsv07_idle_n(m,1u);if(f&JSV07_RULE_BRANCH_ALWAYS_POST_IDLE)jsv07_idle_n(m,1u);if((f&JSV07_RULE_DYN_BRANCH_TAKEN_POST_IDLE)&&jsv07_branch_taken(&m->timing)){int8_t d=(int8_t)p->bytes[1];uint16_t seq=(uint16_t)(m->timing.before.pc+p->length),target=(uint16_t)(seq+d);jsv07_idle_n(m,1u);if((f&JSV07_RULE_DYN_BRANCH_PAGE_POST_IDLE)&&m->timing.before.e&&((seq&0xFF00u)!=(target&0xFF00u)))jsv07_idle_n(m,1u);}}

static int jsv07_stack_pop8(JSV07Machine*m,uint8_t*out,JSV07Stop*s){m->cpu.s=(uint16_t)(m->cpu.s+1u);if(m->cpu.e)m->cpu.s=(uint16_t)(0x0100u|(m->cpu.s&0xFFu));return js_v07c_read8(m,m->cpu.s,out,s);}
static int jsv07_stack_pop16(JSV07Machine*m,uint16_t*out,JSV07Stop*s){uint8_t lo,hi;if(!jsv07_stack_pop8(m,&lo,s)||!jsv07_stack_pop8(m,&hi,s))return 0;*out=(uint16_t)(lo|((uint16_t)hi<<8));return 1;}
static JSExecResult jsv07_rti(JSV07Machine*m,const JSV07TimingPlan*p,JSV07Stop*s){uint8_t ps,k=0;uint16_t pc;uint32_t observed;jsv07_idle_n(m,2u);if(!jsv07_stack_pop8(m,&ps,s)||!jsv07_stack_pop16(m,&pc,s))return JS_EXEC_STOP;if(!m->cpu.e&& !jsv07_stack_pop8(m,&k,s))return JS_EXEC_STOP;m->cpu.p=ps;if(m->cpu.e)m->cpu.p|=(JS_P_M|JS_P_X);m->cpu.pc=pc;if(!m->cpu.e)m->cpu.pbr=k;js_cpu_normalize(&m->cpu);observed=js_cpu_context_key(&m->cpu);if(!js_v07c_timing_plan(observed)){if(s){s->reason=JSV07_STOP_UNADMITTED_INTERRUPT_TARGET;s->source_key=p->key;s->observed_key=observed;s->address=((uint32_t)m->cpu.pbr<<16)|m->cpu.pc;}return JS_EXEC_STOP;}return JS_EXEC_OK;}
static int jsv07_push8(JSV07Machine*m,uint8_t v,JSV07Stop*s){uint32_t a=m->cpu.s;if(!js_v07c_write8(m,a,v,s))return 0;m->cpu.s=(uint16_t)(m->cpu.s-1u);if(m->cpu.e)m->cpu.s=(uint16_t)(0x0100u|(m->cpu.s&0xFFu));return 1;}
static int jsv07_push16(JSV07Machine*m,uint16_t v,JSV07Stop*s){return jsv07_push8(m,(uint8_t)(v>>8),s)&&jsv07_push8(m,(uint8_t)v,s);}
static int jsv07_interrupt(JSV07Machine*m,int nmi,JSV07Stop*s){uint8_t dummy=0,lo,hi;uint16_t vec;uint32_t key;if(!js_v07c_read8(m,((uint32_t)m->cpu.pbr<<16)|m->cpu.pc,&dummy,s))return 0;js_v07c_scheduler_internal_cycle(m);if(m->cpu.e){if(!jsv07_push16(m,m->cpu.pc,s)||!jsv07_push8(m,(uint8_t)(m->cpu.p|0x20u),s))return 0;vec=(uint16_t)(nmi?0xFFFAu:0xFFFEu);}else{if(!jsv07_push8(m,m->cpu.pbr,s)||!jsv07_push16(m,m->cpu.pc,s)||!jsv07_push8(m,m->cpu.p,s))return 0;vec=(uint16_t)(nmi?0xFFEAu:0xFFEEu);}m->cpu.p=(uint8_t)((m->cpu.p|JS_P_I)&(uint8_t)~JS_P_D);m->cpu.pbr=0u;if(!js_v07c_read8(m,vec,&lo,s)||!js_v07c_read8(m,(uint16_t)(vec+1u),&hi,s))return 0;m->cpu.pc=(uint16_t)(lo|((uint16_t)hi<<8));js_cpu_normalize(&m->cpu);key=js_cpu_context_key(&m->cpu);if(!js_v07c_timing_plan(key))return jsv07_fail(m,s,JSV07_STOP_UNADMITTED_INTERRUPT_TARGET,((uint32_t)m->cpu.pbr<<16)|m->cpu.pc,0);return 1;}

JSExecResult js_v07c_step(JSV07Machine*m,JSV07Stop*s){const JSV07TimingPlan*p;JSBus bus;JSStop v05;JSExecResult r;uint32_t key;uint64_t cycles;unsigned expected;if(!m)return JS_EXEC_STOP;js_v07c_stop_clear(s);m->pending_bus_stop=JSV07_STOP_NONE;if(m->scheduler.cpu_stop!=JSV07_CPU_RUNNING){js_v07c_halted_quantum(m);return JS_EXEC_OK;}
 /* Interrupt ownership is scheduler-side and cannot promote a new context. */
 if(m->scheduler.nmi_pending||m->scheduler.nmi_signal){m->scheduler.nmi_pending=m->scheduler.nmi_signal=0u;if(!jsv07_interrupt(m,1,s))return JS_EXEC_STOP;return JS_EXEC_OK;}
 if(m->scheduler.irq_source&&!(m->cpu.p&JS_P_I)){if(!jsv07_interrupt(m,0,s))return JS_EXEC_STOP;return JS_EXEC_OK;}
 key=js_cpu_context_key(&m->cpu);p=js_v07c_timing_plan(key);if(!p){jsv07_fail(m,s,JSV07_STOP_UNKNOWN_CONTEXT,((uint32_t)m->cpu.pbr<<16)|m->cpu.pc,0);return JS_EXEC_STOP;}
 if(!p->v07_executable){JSV07StopReason q=(p->opcode==0xFCu)?JSV07_STOP_UNPROVED_DYNAMIC_TARGET:JSV07_STOP_UNPROVED_RETURN;jsv07_fail(m,s,q,p->address,0);return JS_EXEC_STOP;}
 memset(&m->timing,0,sizeof(m->timing));m->timing.plan=p;m->timing.before=m->cpu;m->timing.start_cpu_cycles=m->scheduler.cpu_cycle_count;
 if(!jsv07_prefetch(m,p,s))return JS_EXEC_STOP;
 if(p->opcode==0x40u&&p->v07_executable){r=jsv07_rti(m,p,s);}else{jsv07_pre_body_fixed(m,p);bus.opaque=m;bus.read8=jsv07_v05_read;bus.write8=jsv07_v05_write;js_stop_clear(&v05);r=js_v05c_step(&m->cpu,&bus,&v05);if(r==JS_EXEC_STOP){if(s)s->v05=v05;if(v05.reason==JS_STOP_BUS_UNAVAILABLE&&m->pending_bus_stop!=JSV07_STOP_NONE){if(s){s->reason=m->pending_bus_stop;s->address=m->pending_bus_address;s->value=m->pending_bus_value;}return r;}if(s){s->reason=JSV07_STOP_V05;s->source_key=v05.source_key;s->observed_key=v05.observed_key;s->address=v05.address;s->value=v05.value;}return r;}jsv07_post_body(m,p);}
 if(r!=JS_EXEC_OK)return r;if(m->pending_bus_stop==JSV07_STOP_DMA_TRANSFER_V08){if(s){s->reason=JSV07_STOP_DMA_TRANSFER_V08;s->master_clock=m->scheduler.master_clock;s->scanline=m->scheduler.scanline;s->hclock=m->scheduler.hclock;}return JS_EXEC_STOP;}cycles=m->scheduler.cpu_cycle_count-m->timing.start_cpu_cycles;expected=p->cycle_min;if((p->rule_flags&JSV07_RULE_DYN_DIRECT_LOW_PRE_IDLE)&&(m->timing.before.d&0xFFu))expected++;if((p->rule_flags&JSV07_RULE_DYN_INDEX_PRE_DATA_IDLE)&&jsv07_index_cross(&m->timing))expected++;if((p->rule_flags&JSV07_RULE_DYN_BRANCH_TAKEN_POST_IDLE)&&jsv07_branch_taken(&m->timing)){int8_t d=(int8_t)p->bytes[1];uint16_t seq=(uint16_t)(m->timing.before.pc+p->length),target=(uint16_t)(seq+d);expected++;if((p->rule_flags&JSV07_RULE_DYN_BRANCH_PAGE_POST_IDLE)&&m->timing.before.e&&((seq&0xFF00u)!=(target&0xFF00u)))expected++;}
 if(cycles!=expected){if(s){s->reason=JSV07_STOP_TIMING_PLAN_MISMATCH;s->source_key=p->key;s->observed_key=(uint32_t)cycles;s->address=p->address;s->value=(uint8_t)expected;}return JS_EXEC_STOP;}return JS_EXEC_OK;}
