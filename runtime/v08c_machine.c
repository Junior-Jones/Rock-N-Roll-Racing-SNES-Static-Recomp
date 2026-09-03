#include "v07c_machine.h"
#include "js_v05c_dispatch.h"
#include <string.h>

/* V08C extends the frozen V07C scheduler/timing authority with the general DMA/HDMA controller.
 * No alternate timing path is introduced; V06C remains predecessor evidence only. */

static int jsv08_system_bank(uint8_t bank) { return bank <= 0x3Fu || (bank >= 0x80u && bank <= 0xBFu); }
static uint16_t jsv08_vblank_start(const JSV08Scheduler *s) { return s->overscan ? 240u : 225u; }
static uint16_t jsv08_last_scanline(const JSV08Scheduler *s) { return (s->interlace && !s->field_odd) ? 262u : 261u; }
static int jsv08_in_vblank(const JSV08Scheduler *s) { return s->scanline >= jsv08_vblank_start(s); }
static int jsv08_in_hblank(const JSV08Scheduler *s) { return !(s->hclock >= 4u && s->hclock <= 1096u); }

static void jsv08_event(JSV08Scheduler *s, uint32_t code, uint32_t detail) {
    /* Deterministic compact event certificate; not execution authority. */
    uint64_t x = ((uint64_t)code << 48) ^ ((uint64_t)s->scanline << 32) ^
                 ((uint64_t)s->hclock << 16) ^ (uint64_t)detail ^ s->master_clock;
    s->event_digest ^= x + UINT64_C(0x9E3779B97F4A7C15) + (s->event_digest << 6) + (s->event_digest >> 2);
    s->event_count++;
}

void js_v08c_stop_clear(JSV08Stop *s) { if(s) memset(s,0,sizeof(*s)); }
static int jsv08_fail(JSV08Machine *m, JSV08Stop *s, JSV08StopReason r, uint32_t a, uint8_t v) {
    if(m){m->pending_bus_stop=r;m->pending_bus_address=a&0xFFFFFFu;m->pending_bus_value=v;}
    if(s){
        s->reason=r;s->address=a&0xFFFFFFu;s->value=v;s->source_key=js_cpu_context_key(m?&m->cpu:0);
        if(m){s->master_clock=m->scheduler.master_clock;s->scanline=m->scheduler.scanline;s->hclock=m->scheduler.hclock;}
    }
    return 0;
}

JSV08Region js_v08c_classify(uint32_t address) {
    uint8_t bank; uint16_t off; address &= 0xFFFFFFu; bank=(uint8_t)(address>>16); off=(uint16_t)address;
    if(bank==0x7Eu || bank==0x7Fu) return JSV08_REGION_WRAM;
    if(jsv08_system_bank(bank)) {
        if(off<=0x1FFFu) return JSV08_REGION_WRAM;
        if(off>=0x2100u && off<=0x213Fu) return JSV08_REGION_PPU;
        if(off>=0x2140u && off<=0x217Fu) return JSV08_REGION_APU;
        if(off>=0x2180u && off<=0x2183u) return JSV08_REGION_WRAM_PORT;
        if(off==0x4016u || off==0x4017u || (off>=0x4218u && off<=0x421Fu)) return JSV08_REGION_INPUT;
        if(off>=0x4200u && off<=0x4217u) return JSV08_REGION_CPU_IO;
        if(off>=0x4300u && off<=0x437Fu) return JSV08_REGION_DMA;
    }
    if(off>=0x8000u) return JSV08_REGION_ROM;
    return JSV08_REGION_OPEN_BUS;
}
int js_v08c_lorom_offset(uint32_t address, uint32_t *offset) {
    uint8_t bank; uint16_t off; address&=0xFFFFFFu;bank=(uint8_t)(address>>16);off=(uint16_t)address;
    if(!offset||bank==0x7Eu||bank==0x7Fu||off<0x8000u)return 0;
    *offset=(((uint32_t)bank&0x1Fu)<<15)|(off&0x7FFFu);return 1;
}
int js_v08c_wram_offset(uint32_t address,uint32_t *offset) {
    uint8_t bank;uint16_t off;address&=0xFFFFFFu;bank=(uint8_t)(address>>16);off=(uint16_t)address;if(!offset)return 0;
    if(bank==0x7Eu){*offset=off;return 1;}if(bank==0x7Fu){*offset=0x10000u|off;return 1;}
    if(jsv08_system_bank(bank)&&off<=0x1FFFu){*offset=off;return 1;}return 0;
}
uint8_t js_v08c_access_clocks(uint32_t address,uint8_t memsel) {
    uint8_t bg=(uint8_t)((address>>22)&3u),page=(uint8_t)(address>>8);memsel=memsel?1u:0u;
    if(bg==1u)return 8u;if(bg==3u)return memsel?6u:8u;if(page<=0x1Fu)return 8u;if(page<=0x3Fu)return 6u;
    if(page<=0x41u)return 12u;if(page<=0x5Fu)return 6u;if(page<=0x7Fu)return 8u;if(bg==0u)return 8u;return memsel?6u:8u;
}


/* V08C DMA/HDMA controller. V07C remains the frozen timing-plan authority; this
 * controller consumes the same monotonic scheduler and never creates a second clock. */
static const uint8_t jsv08_dma_count[8]={1u,2u,2u,4u,4u,4u,2u,4u};
static const uint8_t jsv08_dma_offset[8][4]={{0u,0u,0u,0u},{0u,1u,0u,1u},{0u,0u,0u,0u},{0u,0u,1u,1u},{0u,1u,2u,3u},{0u,1u,0u,1u},{0u,0u,0u,0u},{0u,0u,1u,1u}};
static int jsv08_read_effect(JSV08Machine*m,uint32_t a,uint8_t*out,JSV08Stop*s);
static int jsv08_write_effect(JSV08Machine*m,uint32_t a,uint8_t v,JSV08Stop*s);
static int jsv08_dma_process_kind(JSV08Machine*m,JSV08DmaRendezvous kind,uint8_t cpu_speed,JSV08Stop*s,int nested);
static void jsv08_queue_dma(JSV08Scheduler*s,JSV08DmaRendezvous kind);

static int jsv08_dma_a_hits_b(uint32_t a){uint8_t b=(uint8_t)(a>>16);uint16_t o=(uint16_t)a;return jsv08_system_bank(b)&&o>=0x2100u&&o<=0x21FFu;}
static int jsv08_dma_a_hits_controller(uint32_t a){uint8_t b=(uint8_t)(a>>16);uint16_t o=(uint16_t)a;return jsv08_system_bank(b)&&(o==0x420Bu||o==0x420Cu||(o>=0x4300u&&o<=0x437Fu));}
static void jsv08_dma_advance(JSV08Machine*m,uint32_t clocks){m->dma.dma_clock_counter+=clocks;js_v08c_scheduler_advance_wall(&m->scheduler,clocks);}
static int jsv08_dma_is_wram(uint32_t a){uint32_t o;return js_v08c_wram_offset(a,&o);}

void js_v08c_set_ppu_dma_seam(JSV08Machine*m,JSV08PpuDmaRead r,JSV08PpuDmaWrite w,void*opaque){if(!m)return;m->ppu_dma_read=r;m->ppu_dma_write=w;m->ppu_dma_opaque=opaque;}

static void jsv08_dma_channel_power_on(JSV08DmaChannel*c){memset(c,0,sizeof(*c));c->src_address=0xFFFFu;c->transfer_size=0xFFFFu;c->hdma_table_address=0xFFFFu;c->src_bank=0xFFu;c->dest_address=0xFFu;c->invert_direction=1u;c->decrement=1u;c->fixed_transfer=1u;c->hdma_indirect=1u;c->transfer_mode=7u;c->hdma_bank=0xFFu;c->line_counter_repeat=0xFFu;c->unused_control=1u;c->unused_register=0xFFu;}
static void jsv08_dma_power_on(JSV08Machine*m){unsigned i;memset(&m->dma,0,sizeof(m->dma));m->dma.active_channel=0xFFu;for(i=0;i<8u;i++)jsv08_dma_channel_power_on(&m->dma.channel[i]);}
static void jsv08_dma_reset(JSV08Machine*m){unsigned i;m->dma.hdma_channels=0u;m->dma.active_channel=0xFFu;for(i=0;i<8u;i++)m->dma.channel[i].dma_active=0u;}

uint8_t js_v08c_dma_register_read(const JSV08Machine*m,uint16_t a){const JSV08DmaChannel*c;uint8_t r;if(!m||a<0x4300u||a>0x437Fu)return m?m->open_bus:0u;c=&m->dma.channel[(a&0x70u)>>4];r=(uint8_t)(a&0x0Fu);switch(r){case 0:return(uint8_t)((c->invert_direction?0x80u:0u)|(c->hdma_indirect?0x40u:0u)|(c->unused_control?0x20u:0u)|(c->decrement?0x10u:0u)|(c->fixed_transfer?0x08u:0u)|(c->transfer_mode&7u));case 1:return c->dest_address;case 2:return(uint8_t)c->src_address;case 3:return(uint8_t)(c->src_address>>8);case 4:return c->src_bank;case 5:return(uint8_t)c->transfer_size;case 6:return(uint8_t)(c->transfer_size>>8);case 7:return c->hdma_bank;case 8:return(uint8_t)c->hdma_table_address;case 9:return(uint8_t)(c->hdma_table_address>>8);case 10:return c->line_counter_repeat;case 11:case 15:return c->unused_register;default:return m->open_bus;}}
int js_v08c_dma_register_write(JSV08Machine*m,uint16_t a,uint8_t v){JSV08DmaChannel*c;uint8_t r;unsigned i;if(!m)return 0;if(a==0x420Bu){m->scheduler.manual_dma_mask=v;for(i=0;i<8u;i++)if(v&(1u<<i))m->dma.channel[i].dma_active=1u;if(v)jsv08_queue_dma(&m->scheduler,JSV08_DMA_MANUAL);return 1;}if(a==0x420Cu){m->dma.hdma_channels=v;m->scheduler.hdma_enable_mask=v;return 1;}if(a<0x4300u||a>0x437Fu)return 0;c=&m->dma.channel[(a&0x70u)>>4];r=(uint8_t)(a&0x0Fu);switch(r){case 0:c->invert_direction=!!(v&0x80u);c->hdma_indirect=!!(v&0x40u);c->unused_control=!!(v&0x20u);c->decrement=!!(v&0x10u);c->fixed_transfer=!!(v&0x08u);c->transfer_mode=v&7u;break;case 1:c->dest_address=v;break;case 2:c->src_address=(uint16_t)((c->src_address&0xFF00u)|v);break;case 3:c->src_address=(uint16_t)((c->src_address&0x00FFu)|((uint16_t)v<<8));break;case 4:c->src_bank=v;break;case 5:c->transfer_size=(uint16_t)((c->transfer_size&0xFF00u)|v);break;case 6:c->transfer_size=(uint16_t)((c->transfer_size&0x00FFu)|((uint16_t)v<<8));break;case 7:c->hdma_bank=v;break;case 8:c->hdma_table_address=(uint16_t)((c->hdma_table_address&0xFF00u)|v);break;case 9:c->hdma_table_address=(uint16_t)((c->hdma_table_address&0x00FFu)|((uint16_t)v<<8));break;case 10:c->line_counter_repeat=v;break;case 11:case 15:c->unused_register=v;break;default:break;}return 1;}

static int jsv08_dma_read_a(JSV08Machine*m,uint32_t a,uint8_t*out,JSV08Stop*s){jsv08_dma_advance(m,4u);m->dma.bus_cycles++;a&=0xFFFFFFu;if(jsv08_dma_a_hits_b(a)||jsv08_dma_a_hits_controller(a)){*out=m->open_bus;return 1;}if(!jsv08_read_effect(m,a,out,s))return 0;m->open_bus=*out;return 1;}
static int jsv08_dma_write_a(JSV08Machine*m,uint32_t a,uint8_t v,JSV08Stop*s){jsv08_dma_advance(m,4u);m->dma.bus_cycles++;a&=0xFFFFFFu;if(jsv08_dma_a_hits_b(a)||jsv08_dma_a_hits_controller(a)){m->open_bus=v;return 1;}if(!jsv08_write_effect(m,a,v,s))return 0;m->open_bus=v;return 1;}
static int jsv08_dma_read_b(JSV08Machine*m,uint16_t a,uint8_t*out,JSV08Stop*s){jsv08_dma_advance(m,4u);m->dma.bus_cycles++;if(a>=0x2100u&&a<=0x213Fu){if(!m->ppu_dma_read)return jsv08_fail(m,s,JSV08_STOP_PPU_UNAVAILABLE,a,0u);if(!m->ppu_dma_read(m->ppu_dma_opaque,a,out))return jsv08_fail(m,s,JSV08_STOP_PPU_UNAVAILABLE,a,0u);m->open_bus=*out;return 1;}if(a>=0x2140u&&a<=0x217Fu)return jsv08_fail(m,s,JSV08_STOP_APU_UNAVAILABLE,a,0u);if(a>=0x2180u&&a<=0x2183u){if(!jsv08_read_effect(m,a,out,s))return 0;m->open_bus=*out;return 1;}*out=m->open_bus;return 1;}
static int jsv08_dma_write_b(JSV08Machine*m,uint16_t a,uint8_t v,JSV08Stop*s){jsv08_dma_advance(m,4u);m->dma.bus_cycles++;if(a>=0x2100u&&a<=0x213Fu){if(!m->ppu_dma_write)return jsv08_fail(m,s,JSV08_STOP_PPU_UNAVAILABLE,a,v);if(!m->ppu_dma_write(m->ppu_dma_opaque,a,v))return jsv08_fail(m,s,JSV08_STOP_PPU_UNAVAILABLE,a,v);m->open_bus=v;return 1;}if(a>=0x2140u&&a<=0x217Fu)return jsv08_fail(m,s,JSV08_STOP_APU_UNAVAILABLE,a,v);if(a>=0x2180u&&a<=0x2183u){if(!jsv08_write_effect(m,a,v,s))return 0;m->open_bus=v;return 1;}m->open_bus=v;return 1;}
static int jsv08_dma_copy(JSV08Machine*m,uint32_t aa,uint16_t ab,uint8_t btoa,JSV08Stop*s){uint8_t v;if(btoa){if(ab==0x2180u&&jsv08_dma_is_wram(aa)){jsv08_dma_advance(m,4u);m->dma.bus_cycles++;if(!jsv08_dma_write_a(m,aa,0xFFu,s))return 0;m->dma.wram_restrictions++;}else{if(!jsv08_dma_read_b(m,ab,&v,s)||!jsv08_dma_write_a(m,aa,v,s))return 0;}}else{if(ab==0x2180u&&jsv08_dma_is_wram(aa)){jsv08_dma_advance(m,8u);m->dma.bus_cycles+=2u;m->dma.wram_restrictions++;}else{if(!jsv08_dma_read_a(m,aa,&v,s)||!jsv08_dma_write_b(m,ab,v,s))return 0;}}m->dma.transfer_bytes++;return 1;}
static void jsv08_dma_sync_start(JSV08Machine*m){uint32_t n=(uint32_t)(8u-(m->scheduler.master_clock&7u));m->dma.dma_clock_counter=0u;jsv08_dma_advance(m,n);}
static void jsv08_dma_sync_end(JSV08Machine*m,uint8_t cpu_speed){uint32_t n=(uint32_t)(cpu_speed-(m->dma.dma_clock_counter%cpu_speed));js_v08c_scheduler_advance_wall(&m->scheduler,n);}
static int jsv08_dma_table_read(JSV08Machine*m,uint32_t a,uint8_t*out,JSV08Stop*s){if(!jsv08_dma_read_a(m,a,out,s))return 0;jsv08_dma_advance(m,4u);return 1;}

static JSV08DmaRendezvous jsv08_dma_highest(uint8_t mask){if(mask&4u)return JSV08_DMA_HDMA_LINE;if(mask&2u)return JSV08_DMA_HDMA_INIT;if(mask&1u)return JSV08_DMA_MANUAL;return JSV08_DMA_NONE;}
static void jsv08_dma_refresh_request(JSV08Scheduler*s){s->dma_request=jsv08_dma_highest(s->dma_pending_mask);}
static int jsv08_dma_service_pending(JSV08Machine*m,uint8_t cpu_speed,JSV08Stop*s){JSV08DmaRendezvous k;uint8_t bit;if(!m->scheduler.dma_pending_mask)return 1;if(m->scheduler.dma_start_delay){m->scheduler.dma_start_delay--;return 1;}k=jsv08_dma_highest(m->scheduler.dma_pending_mask);bit=(uint8_t)(1u<<((unsigned)k-1u));m->scheduler.dma_pending_mask=(uint8_t)(m->scheduler.dma_pending_mask&~bit);jsv08_dma_refresh_request(&m->scheduler);if(k==JSV08_DMA_HDMA_LINE||k==JSV08_DMA_HDMA_INIT)return jsv08_dma_process_kind(m,k,cpu_speed,s,1);return 1;}
static int jsv08_dma_run_channel(JSV08Machine*m,unsigned i,uint8_t cpu_speed,JSV08Stop*s){JSV08DmaChannel*c=&m->dma.channel[i];uint32_t n=0;if(!c->dma_active)return 1;m->dma.active_channel=(uint8_t)i;jsv08_dma_advance(m,8u);if(!jsv08_dma_service_pending(m,cpu_speed,s))return 0;do{uint32_t aa=((uint32_t)c->src_bank<<16)|c->src_address;uint16_t ab=(uint16_t)(0x2100u|((c->dest_address+jsv08_dma_offset[c->transfer_mode][n&3u])&0xFFu));if(!jsv08_dma_copy(m,aa,ab,c->invert_direction,s))return 0;if(!c->fixed_transfer)c->src_address=(uint16_t)(c->src_address+(c->decrement?-1:1));c->transfer_size=(uint16_t)(c->transfer_size-1u);n++;if(!jsv08_dma_service_pending(m,cpu_speed,s))return 0;}while(c->transfer_size&&c->dma_active);c->dma_active=0u;return 1;}
static int jsv08_dma_run_manual(JSV08Machine*m,uint8_t cpu_speed,JSV08Stop*s){unsigned i;jsv08_dma_sync_start(m);jsv08_dma_advance(m,8u);if(!jsv08_dma_service_pending(m,cpu_speed,s))return 0;for(i=0;i<8u;i++)if(!jsv08_dma_run_channel(m,i,cpu_speed,s))return 0;jsv08_dma_sync_end(m,cpu_speed);m->dma.active_channel=0xFFu;return 1;}

static int jsv08_hdma_init(JSV08Machine*m,uint8_t cpu_speed,JSV08Stop*s,int nested){unsigned i;int need_sync;uint8_t lo,hi;for(i=0;i<8u;i++){m->dma.channel[i].hdma_finished=0u;m->dma.channel[i].do_transfer=0u;}if(!m->dma.hdma_channels)return 1;need_sync=1;for(i=0;i<8u;i++)if(m->dma.channel[i].dma_active)need_sync=0;if(need_sync&&!nested)jsv08_dma_sync_start(m);jsv08_dma_advance(m,8u);for(i=0;i<8u;i++){JSV08DmaChannel*c=&m->dma.channel[i];c->do_transfer=1u;if(!(m->dma.hdma_channels&(1u<<i)))continue;c->hdma_table_address=c->src_address;c->dma_active=0u;if(!jsv08_dma_table_read(m,((uint32_t)c->src_bank<<16)|c->hdma_table_address,&c->line_counter_repeat,s))return 0;c->hdma_table_address++;if(!c->line_counter_repeat)c->hdma_finished=1u;if(c->hdma_indirect){if(!jsv08_dma_table_read(m,((uint32_t)c->src_bank<<16)|c->hdma_table_address,&lo,s))return 0;c->hdma_table_address++;if(!c->hdma_finished){if(!jsv08_dma_table_read(m,((uint32_t)c->src_bank<<16)|c->hdma_table_address,&hi,s))return 0;c->hdma_table_address++;c->transfer_size=(uint16_t)(lo|((uint16_t)hi<<8));}else c->transfer_size=(uint16_t)((uint16_t)lo<<8);}}if(need_sync&&!nested)jsv08_dma_sync_end(m,cpu_speed);return 1;}
static int jsv08_hdma_transfer(JSV08Machine*m,unsigned i,JSV08Stop*s){JSV08DmaChannel*c=&m->dma.channel[i];uint8_t n,count=jsv08_dma_count[c->transfer_mode];m->dma.active_channel=(uint8_t)(0x80u|i);c->dma_active=0u;for(n=0;n<count;n++){uint32_t aa;if(c->hdma_indirect){aa=((uint32_t)c->hdma_bank<<16)|c->transfer_size;c->transfer_size++;}else{aa=((uint32_t)c->src_bank<<16)|c->hdma_table_address;c->hdma_table_address++;}if(!jsv08_dma_copy(m,aa,(uint16_t)(0x2100u|((c->dest_address+jsv08_dma_offset[c->transfer_mode][n])&0xFFu)),c->invert_direction,s))return 0;}return 1;}
static int jsv08_hdma_last_active(JSV08Machine*m,unsigned ch){unsigned i;for(i=ch+1u;i<8u;i++)if((m->dma.hdma_channels&(1u<<i))&&!m->dma.channel[i].hdma_finished)return 0;return 1;}
static int jsv08_hdma_line(JSV08Machine*m,uint8_t cpu_speed,JSV08Stop*s,int nested){unsigned i;int need_sync;uint8_t nc,lo,hi,old=m->dma.active_channel;if(!m->dma.hdma_channels)return 1;need_sync=1;for(i=0;i<8u;i++)if(m->dma.channel[i].dma_active)need_sync=0;if(need_sync&&!nested)jsv08_dma_sync_start(m);jsv08_dma_advance(m,8u);for(i=0;i<8u;i++){JSV08DmaChannel*c=&m->dma.channel[i];if(!(m->dma.hdma_channels&(1u<<i))||c->hdma_finished)continue;c->dma_active=0u;if(c->do_transfer&&!jsv08_hdma_transfer(m,i,s))return 0;}for(i=0;i<8u;i++){JSV08DmaChannel*c=&m->dma.channel[i];if(!(m->dma.hdma_channels&(1u<<i))||c->hdma_finished)continue;c->line_counter_repeat--;c->do_transfer=!!(c->line_counter_repeat&0x80u);if(!jsv08_dma_table_read(m,((uint32_t)c->src_bank<<16)|c->hdma_table_address,&nc,s))return 0;if(!(c->line_counter_repeat&0x7Fu)){c->line_counter_repeat=nc;c->hdma_table_address++;if(c->hdma_indirect){if(!c->line_counter_repeat&&jsv08_hdma_last_active(m,i)){if(!jsv08_dma_table_read(m,((uint32_t)c->src_bank<<16)|c->hdma_table_address,&hi,s))return 0;c->hdma_table_address++;c->transfer_size=(uint16_t)((uint16_t)hi<<8);}else{if(!jsv08_dma_table_read(m,((uint32_t)c->src_bank<<16)|c->hdma_table_address,&lo,s))return 0;c->hdma_table_address++;if(!jsv08_dma_table_read(m,((uint32_t)c->src_bank<<16)|c->hdma_table_address,&hi,s))return 0;c->hdma_table_address++;c->transfer_size=(uint16_t)(lo|((uint16_t)hi<<8));}}if(!c->line_counter_repeat)c->hdma_finished=1u;c->do_transfer=1u;}}if(need_sync&&!nested)jsv08_dma_sync_end(m,cpu_speed);m->dma.active_channel=old;return 1;}
static int jsv08_dma_process_kind(JSV08Machine*m,JSV08DmaRendezvous kind,uint8_t cpu_speed,JSV08Stop*s,int nested){if(kind==JSV08_DMA_MANUAL)return jsv08_dma_run_manual(m,cpu_speed,s);if(kind==JSV08_DMA_HDMA_INIT)return jsv08_hdma_init(m,cpu_speed,s,nested);if(kind==JSV08_DMA_HDMA_LINE)return jsv08_hdma_line(m,cpu_speed,s,nested);return 1;}
static int jsv08_dma_process_ready(JSV08Machine*m,uint8_t cpu_speed,JSV08Stop*s){JSV08DmaRendezvous k=m->scheduler.dma_rendezvous_ready;m->scheduler.dma_rendezvous_ready=JSV08_DMA_NONE;return jsv08_dma_process_kind(m,k,cpu_speed,s,0);}

static void jsv08_update_smp(JSV08Scheduler *s) {
    /* Exact rational target; no floating point and no independent audio clock. */
    uint64_t q=s->master_clock/JSV08_SMP_RATIO_DEN, r=s->master_clock%JSV08_SMP_RATIO_DEN;
    uint64_t product=r*(uint64_t)JSV08_SMP_RATIO_NUM;
    s->smp_target_cycle=q*(uint64_t)JSV08_SMP_RATIO_NUM + product/JSV08_SMP_RATIO_DEN;
    s->smp_target_remainder=(uint32_t)(product%JSV08_SMP_RATIO_DEN);
}
static void jsv08_update_irq_level(JSV08Scheduler *s) {
    int enabled=s->enable_hirq||s->enable_virq, level;
    if(!enabled){s->irq_level=0;return;}
    level=(!s->enable_hirq||s->htimer==s->hcounter)&&(!s->enable_virq||s->vtimer==s->vcounter);
    if(!s->irq_level&&level){s->need_irq=(uint8_t)((s->enable_hirq&&s->hclock==6u)?3u:2u);jsv08_event(s,8u,s->need_irq);}
    s->irq_level=(uint8_t)level;
}
static void jsv08_process_irq(JSV08Scheduler *s) {
    if(s->need_irq>0u){s->need_irq--;if(s->need_irq==1u){s->irq_flag=1u;jsv08_event(s,9u,0u);}else if(s->need_irq==0u){s->irq_source=s->irq_flag;jsv08_event(s,10u,s->irq_source);}}
    if(s->hclock>10u)s->hcounter=(uint16_t)((s->hcounter+1u)&0x1FFu);
    else if(s->hclock==10u)s->hcounter=0u;
    else if(s->hclock==6u){s->hcounter=0u;if(s->scanline>0u)s->vcounter=(uint16_t)((s->vcounter+1u)&0x1FFu);if(s->enable_nmi&&s->scanline==jsv08_vblank_start(s)){s->nmi_signal=1u;jsv08_event(s,6u,0u);}}
    else if(s->hclock==2u){s->hcounter=(uint16_t)((s->hcounter+1u)&0x1FFu);if(s->scanline==jsv08_vblank_start(s)){s->nmi_flag=1u;jsv08_event(s,5u,0u);}else if(s->scanline==0u){s->nmi_flag=0u;s->vcounter=0u;}}
    jsv08_update_irq_level(s);
}
static void jsv08_process_autojoy(JSV08Scheduler *s) {
    if(s->autojoy_disabled)return;
    while(s->autojoy_next_clock<=s->master_clock){
        uint64_t clock=s->autojoy_next_clock;int step;s->autojoy_next_clock+=128u;step=(int)((clock-s->autojoy_clock_start)/128u);s->autojoy_step=(int8_t)step;
        if(step==0)s->autojoy_strobe=s->enable_autojoy;
        else if(step==1){if(!s->enable_autojoy){s->autojoy_disabled=1u;s->autojoy_active=0u;}else{s->autojoy_active=1u;memset(s->controller_data,0,sizeof(s->controller_data));}}
        else if(step==2)s->autojoy_strobe=0u;
        else {if(!s->enable_autojoy)step=34;else if(!(step&1)){uint8_t p1=s->autojoy_sample_bits[0],p2=s->autojoy_sample_bits[1];s->controller_data[0]=(uint16_t)((s->controller_data[0]<<1)|(p1&1u));s->controller_data[1]=(uint16_t)((s->controller_data[1]<<1)|(p2&1u));s->controller_data[2]=(uint16_t)((s->controller_data[2]<<1)|((p1>>1)&1u));s->controller_data[3]=(uint16_t)((s->controller_data[3]<<1)|((p2>>1)&1u));}}
        jsv08_event(s,11u,(uint32_t)step);if(step>=34){s->autojoy_disabled=1u;s->autojoy_active=0u;s->autojoy_strobe=0u;return;}
    }
}
static void jsv08_arm_autojoy(JSV08Scheduler *s) {
    uint64_t r=s->master_clock+130u;s->autojoy_clock_start=r+((r&0xFFu)?(256u-(r&0xFFu)):0u)-128u;s->autojoy_next_clock=s->autojoy_clock_start;s->autojoy_disabled=0u;s->autojoy_step=-1;jsv08_event(s,12u,(uint32_t)s->autojoy_clock_start);
}
static void jsv08_queue_dma(JSV08Scheduler *s,JSV08DmaRendezvous kind) {
    if(kind==JSV08_DMA_NONE)return;s->dma_pending_mask=(uint8_t)(s->dma_pending_mask|(1u<<((unsigned)kind-1u)));jsv08_dma_refresh_request(s);s->dma_start_delay=1u;jsv08_event(s,13u,(uint32_t)kind);
}
static int jsv08_line_ends(const JSV08Scheduler *s) {
    if(s->hclock>=JSV08_NORMAL_SCANLINE_CLOCKS)return 1;
    return s->hclock==JSV08_SHORT_SCANLINE_CLOCKS&&s->scanline==240u&&s->field_odd&&!s->interlace;
}
static void jsv08_tick2(JSV08Scheduler *s);
void js_v08c_scheduler_advance_wall(JSV08Scheduler *s,uint32_t clocks) { while(clocks>=2u){jsv08_tick2(s);clocks-=2u;} }
static void jsv08_primary(JSV08Scheduler *s) {
    if(s->next_primary_event==JSV08_EVENT_HDMA_INIT){jsv08_event(s,1u,0u);if(s->hdma_enable_mask)jsv08_queue_dma(s,JSV08_DMA_HDMA_INIT);s->next_primary_event=JSV08_EVENT_DRAM_REFRESH;s->next_primary_clock=s->dram_refresh_position;return;}
    if(s->next_primary_event==JSV08_EVENT_DRAM_REFRESH){jsv08_event(s,2u,0u);js_v08c_scheduler_advance_wall(s,JSV08_DRAM_REFRESH_CLOCKS);jsv08_event(s,3u,0u);if(s->scanline<jsv08_vblank_start(s)){s->next_primary_event=JSV08_EVENT_HDMA_LINE;s->next_primary_clock=JSV08_HDMA_LINE_HCLOCK;}else{s->next_primary_event=JSV08_EVENT_END_SCANLINE;s->next_primary_clock=1360u;}return;}
    if(s->next_primary_event==JSV08_EVENT_HDMA_LINE){jsv08_event(s,4u,0u);if(s->hdma_enable_mask)jsv08_queue_dma(s,JSV08_DMA_HDMA_LINE);s->next_primary_event=JSV08_EVENT_END_SCANLINE;s->next_primary_clock=1360u;return;}
    if(!jsv08_line_ends(s)){s->next_primary_clock=(uint16_t)(s->next_primary_clock+2u);return;}
    {uint16_t ended=s->scanline;s->scanline++;s->hclock=0u;jsv08_event(s,14u,ended);if(s->scanline==jsv08_vblank_start(s)){jsv08_event(s,15u,0u);jsv08_arm_autojoy(s);}if(s->scanline>jsv08_last_scanline(s)){s->field_odd^=1u;s->scanline=0u;s->frame_number++;jsv08_event(s,16u,s->field_odd);}s->dram_refresh_position=(uint16_t)(538u-(s->master_clock&7u));if(s->scanline==0u){s->next_primary_event=JSV08_EVENT_HDMA_INIT;s->next_primary_clock=(uint16_t)(12u+(s->master_clock&7u));}else{s->next_primary_event=JSV08_EVENT_DRAM_REFRESH;s->next_primary_clock=s->dram_refresh_position;}}
}
static void jsv08_tick2(JSV08Scheduler *s) {
    s->master_clock+=2u;s->hclock=(uint16_t)(s->hclock+2u);if(s->hclock==s->next_primary_clock)jsv08_primary(s);
    if((s->hclock&3u)==0u){/* V09 PPU phase seam; timeline already authoritative. */}
    else if(s->hclock&2u)jsv08_process_irq(s);
    jsv08_process_autojoy(s);jsv08_update_smp(s);
}
void js_v08c_scheduler_init(JSV08Scheduler *s) {
    if(!s)return;memset(s,0,sizeof(*s));s->forced_blank=1u;s->htimer=0x1FFu;s->vtimer=0x1FFu;s->autojoy_disabled=1u;s->autojoy_step=-1;s->dram_refresh_position=538u;s->next_primary_clock=538u;s->next_primary_event=JSV08_EVENT_DRAM_REFRESH;s->event_digest=UINT64_C(0xCBF29CE484222325);jsv08_update_smp(s);
}
void js_v08c_scheduler_reset_cpu_side(JSV08Scheduler *s) {
    if(!s)return;s->enable_autojoy=s->enable_nmi=s->enable_hirq=s->enable_virq=0u;s->nmi_flag=s->nmi_signal=s->nmi_pending=0u;s->irq_level=s->need_irq=s->irq_flag=s->irq_source=0u;s->autojoy_clock_start=s->autojoy_next_clock=0u;s->autojoy_active=0u;s->autojoy_disabled=1u;s->autojoy_strobe=0u;s->autojoy_step=-1;s->dma_request=s->dma_rendezvous_ready=JSV08_DMA_NONE;s->dma_start_delay=s->dma_pending_mask=0u;s->manual_dma_mask=s->hdma_enable_mask=0u;s->cpu_stop=JSV08_CPU_RUNNING;jsv08_event(s,17u,0u);
}
void js_v08c_scheduler_set_display(JSV08Scheduler *s,int overscan,int interlace){if(s){s->overscan=(uint8_t)!!overscan;s->interlace=(uint8_t)!!interlace;}}
static JSV08DmaRendezvous jsv08_cpu_boundary(JSV08Scheduler *s) {
    s->cpu_cycle_count++;if(s->nmi_signal){s->nmi_signal=0u;s->nmi_pending=1u;jsv08_event(s,7u,0u);}if(s->dma_pending_mask){if(s->dma_start_delay)s->dma_start_delay--;if(!s->dma_start_delay){JSV08DmaRendezvous k=jsv08_dma_highest(s->dma_pending_mask);s->dma_pending_mask=(uint8_t)(s->dma_pending_mask&~(1u<<((unsigned)k-1u)));s->dma_rendezvous_ready=k;jsv08_dma_refresh_request(s);jsv08_event(s,18u,s->dma_rendezvous_ready);}}return s->dma_rendezvous_ready;
}
void js_v08c_scheduler_internal_cycle(JSV08Machine *m){if(m){if(m->pending_bus_stop!=JSV08_STOP_NONE)return;if(jsv08_cpu_boundary(&m->scheduler)!=JSV08_DMA_NONE){if(!jsv08_dma_process_ready(m,6u,0)){if(m->pending_bus_stop==JSV08_STOP_NONE)m->pending_bus_stop=JSV08_STOP_DMA_BBUS_UNAVAILABLE;return;}}js_v08c_scheduler_advance_wall(&m->scheduler,6u);}}
void js_v08c_wai(JSV08Machine *m){if(m){m->scheduler.cpu_stop=JSV08_CPU_WAI;jsv08_event(&m->scheduler,19u,0u);}}
void js_v08c_stp(JSV08Machine *m){if(m){m->scheduler.cpu_stop=JSV08_CPU_STP;jsv08_event(&m->scheduler,20u,0u);}}
void js_v08c_halted_quantum(JSV08Machine *m){if(!m)return;if(m->scheduler.cpu_stop==JSV08_CPU_STP){js_v08c_scheduler_advance_wall(&m->scheduler,4u);return;}if(m->scheduler.cpu_stop==JSV08_CPU_WAI){js_v08c_scheduler_internal_cycle(m);if(m->scheduler.nmi_pending||m->scheduler.irq_source){m->scheduler.cpu_stop=JSV08_CPU_RUNNING;jsv08_event(&m->scheduler,21u,0u);}}}

static void jsv08_alu_run(JSV08Machine *m,int is_read){uint64_t target=m->scheduler.cpu_cycle_count-(is_read&&m->scheduler.cpu_cycle_count?1u:0u),cycles;if(target<m->alu.prev_cpu_cycle)target=m->alu.prev_cpu_cycle;cycles=target-m->alu.prev_cpu_cycle;while(cycles--){if(!m->alu.mult_counter&&!m->alu.div_counter)break;if(m->alu.mult_counter){m->alu.mult_counter--;if(m->alu.div_result&1u)m->alu.mult_or_remainder=(uint16_t)(m->alu.mult_or_remainder+m->alu.shift);m->alu.shift<<=1;m->alu.div_result>>=1;}if(m->alu.div_counter){m->alu.div_counter--;m->alu.shift>>=1;m->alu.div_result<<=1;if(m->alu.mult_or_remainder>=m->alu.shift){m->alu.mult_or_remainder=(uint16_t)(m->alu.mult_or_remainder-m->alu.shift);m->alu.div_result|=1u;}}}m->alu.prev_cpu_cycle=target;}
static uint8_t jsv08_alu_read(JSV08Machine *m,uint16_t off){jsv08_alu_run(m,1);switch(off){case 0x4214:return(uint8_t)m->alu.div_result;case 0x4215:return(uint8_t)(m->alu.div_result>>8);case 0x4216:return(uint8_t)m->alu.mult_or_remainder;default:return(uint8_t)(m->alu.mult_or_remainder>>8);}}
static void jsv08_alu_write(JSV08Machine *m,uint16_t off,uint8_t v){int block;jsv08_alu_run(m,1);block=m->alu.div_counter||m->alu.mult_counter;jsv08_alu_run(m,0);switch(off){case 0x4202:m->alu.mult_operand1=v;break;case 0x4203:m->alu.mult_or_remainder=0;if(!block){m->alu.mult_counter=8;m->alu.mult_operand2=v;m->alu.div_result=(uint16_t)(((uint16_t)v<<8)|m->alu.mult_operand1);m->alu.shift=v;}break;case 0x4204:m->alu.dividend=(uint16_t)((m->alu.dividend&0xFF00u)|v);break;case 0x4205:m->alu.dividend=(uint16_t)((m->alu.dividend&0x00FFu)|((uint16_t)v<<8));break;case 0x4206:m->alu.mult_or_remainder=m->alu.dividend;if(!block){m->alu.div_counter=16;m->alu.divisor=v;m->alu.shift=(uint32_t)v<<16;}break;default:break;}}

uint8_t js_v08c_peek8(const JSV08Machine *m,uint32_t a){uint32_t o;uint16_t off=(uint16_t)a;JSV08Region r;if(!m)return 0;a&=0xFFFFFFu;r=js_v08c_classify(a);if(r==JSV08_REGION_ROM&&js_v08c_lorom_offset(a,&o)&&o<m->rom_size)return m->rom[o];if(r==JSV08_REGION_WRAM&&js_v08c_wram_offset(a,&o))return m->wram[o];if(r==JSV08_REGION_WRAM_PORT&&off==0x2180u)return m->wram[m->wram_position];if(r==JSV08_REGION_DMA)return js_v08c_dma_register_read(m,off);if(r==JSV08_REGION_CPU_IO){if(off==0x4213u)return m->io_port_output;if(off==0x4214u)return(uint8_t)m->alu.div_result;if(off==0x4215u)return(uint8_t)(m->alu.div_result>>8);if(off==0x4216u)return(uint8_t)m->alu.mult_or_remainder;if(off==0x4217u)return(uint8_t)(m->alu.mult_or_remainder>>8);}return m->open_bus;}
uint16_t js_v08c_reset_vector(const JSV08Machine *m){return(uint16_t)(js_v08c_peek8(m,0x00FFFCu)|((uint16_t)js_v08c_peek8(m,0x00FFFDu)<<8));}

static void jsv08_write_nmitimen(JSV08Machine *m,uint8_t v){JSV08Scheduler*s=&m->scheduler;uint8_t old=s->enable_nmi;jsv08_process_autojoy(s);s->enable_virq=!!(v&0x20u);s->enable_hirq=!!(v&0x10u);s->enable_autojoy=!!(v&1u);if(s->nmi_flag&&(v&0x80u)&&!old){s->nmi_signal=1u;jsv08_event(s,22u,0u);}s->enable_nmi=!!(v&0x80u);if(!(s->enable_hirq||s->enable_virq)){s->irq_flag=0u;s->irq_source=0u;}jsv08_update_irq_level(s);}
static uint8_t jsv08_read4210(JSV08Machine*m){JSV08Scheduler*s=&m->scheduler;uint8_t v=(uint8_t)((s->nmi_flag?0x80u:0u)|0x02u|(m->open_bus&0x70u));if(s->nmi_flag&&(s->hclock>=6u||s->scanline!=jsv08_vblank_start(s)))s->nmi_flag=0u;return v;}
static uint8_t jsv08_read4211(JSV08Machine*m){JSV08Scheduler*s=&m->scheduler;uint8_t v=(uint8_t)((s->irq_flag?0x80u:0u)|(m->open_bus&0x7Fu));if(s->irq_flag&&!s->need_irq){s->irq_flag=0u;s->irq_source=0u;}return v;}
static uint8_t jsv08_read4212(JSV08Machine*m){JSV08Scheduler*s=&m->scheduler;jsv08_process_autojoy(s);return(uint8_t)((jsv08_in_vblank(s)?0x80u:0u)|(jsv08_in_hblank(s)?0x40u:0u)|(s->autojoy_active?1u:0u)|(m->open_bus&0x3Eu));}

static int jsv08_read_effect(JSV08Machine*m,uint32_t a,uint8_t*out,JSV08Stop*s){uint32_t o;uint16_t off=(uint16_t)a;JSV08Region r=js_v08c_classify(a);if(r==JSV08_REGION_ROM){js_v08c_lorom_offset(a,&o);*out=m->rom[o];m->open_bus=*out;return 1;}if(r==JSV08_REGION_WRAM){js_v08c_wram_offset(a,&o);*out=m->wram[o];m->open_bus=*out;return 1;}if(r==JSV08_REGION_OPEN_BUS){*out=m->open_bus;return 1;}if(r==JSV08_REGION_PPU)return jsv08_fail(m,s,JSV08_STOP_PPU_UNAVAILABLE,a,0);if(r==JSV08_REGION_APU)return jsv08_fail(m,s,JSV08_STOP_APU_UNAVAILABLE,a,0);if(r==JSV08_REGION_DMA){*out=js_v08c_dma_register_read(m,off);m->open_bus=*out;return 1;}if(r==JSV08_REGION_INPUT&&!(off>=0x4218u&&off<=0x421Fu))return jsv08_fail(m,s,JSV08_STOP_INPUT_V11,a,0);
 if(r==JSV08_REGION_WRAM_PORT){if(off==0x2180u){*out=m->wram[m->wram_position];m->wram_position=(m->wram_position+1u)&0x1FFFFu;m->open_bus=*out;}else *out=m->open_bus;return 1;}
 if(r==JSV08_REGION_INPUT&&off>=0x4218u&&off<=0x421Fu){unsigned i=(unsigned)(off-0x4218u);*out=(uint8_t)(m->scheduler.controller_data[i>>1]>>((i&1u)?8:0));m->open_bus=*out;return 1;}
 if(r==JSV08_REGION_CPU_IO){if(off==0x4210u)*out=jsv08_read4210(m);else if(off==0x4211u)*out=jsv08_read4211(m);else if(off==0x4212u)*out=jsv08_read4212(m);else if(off==0x4213u)*out=m->io_port_output;else if(off>=0x4214u&&off<=0x4217u)*out=jsv08_alu_read(m,off);else *out=m->open_bus;m->open_bus=*out;return 1;}return jsv08_fail(m,s,JSV08_STOP_INVALID_MACHINE,a,0);}
static int jsv08_write_effect(JSV08Machine*m,uint32_t a,uint8_t v,JSV08Stop*s){uint32_t o;uint16_t off=(uint16_t)a;JSV08Region r=js_v08c_classify(a);if(r==JSV08_REGION_ROM)return jsv08_fail(m,s,JSV08_STOP_ROM_WRITE,a,v);if(r==JSV08_REGION_WRAM){js_v08c_wram_offset(a,&o);m->wram[o]=v;return 1;}if(r==JSV08_REGION_OPEN_BUS)return 1;if(r==JSV08_REGION_PPU)return jsv08_fail(m,s,JSV08_STOP_PPU_UNAVAILABLE,a,v);if(r==JSV08_REGION_APU)return jsv08_fail(m,s,JSV08_STOP_APU_UNAVAILABLE,a,v);if(r==JSV08_REGION_DMA){js_v08c_dma_register_write(m,off,v);return 1;}if(r==JSV08_REGION_INPUT)return jsv08_fail(m,s,JSV08_STOP_INPUT_V11,a,v);
 if(r==JSV08_REGION_WRAM_PORT){if(off==0x2180u){m->wram[m->wram_position]=v;m->wram_position=(m->wram_position+1u)&0x1FFFFu;}else if(off==0x2181u)m->wram_position=(m->wram_position&0x1FF00u)|v;else if(off==0x2182u)m->wram_position=(m->wram_position&0x100FFu)|((uint32_t)v<<8);else if(off==0x2183u)m->wram_position=(m->wram_position&0x0FFFFu)|((uint32_t)(v&1u)<<16);return 1;}
 if(r==JSV08_REGION_CPU_IO){JSV08Scheduler*sc=&m->scheduler;if(off==0x4200u){jsv08_write_nmitimen(m,v);return 1;}if(off==0x4201u){m->io_port_output=v;return 1;}if(off>=0x4202u&&off<=0x4206u){jsv08_alu_write(m,off,v);return 1;}if(off==0x4207u){sc->htimer=(uint16_t)((sc->htimer&0x100u)|v);jsv08_update_irq_level(sc);return 1;}if(off==0x4208u){sc->htimer=(uint16_t)((sc->htimer&0xFFu)|((uint16_t)(v&1u)<<8));jsv08_update_irq_level(sc);return 1;}if(off==0x4209u){sc->vtimer=(uint16_t)((sc->vtimer&0x100u)|v);jsv08_update_irq_level(sc);return 1;}if(off==0x420Au){sc->vtimer=(uint16_t)((sc->vtimer&0xFFu)|((uint16_t)(v&1u)<<8));jsv08_update_irq_level(sc);return 1;}if(off==0x420Bu||off==0x420Cu){js_v08c_dma_register_write(m,off,v);return 1;}if(off==0x420Du){m->memsel=v&1u;return 1;}return 1;}return jsv08_fail(m,s,JSV08_STOP_INVALID_MACHINE,a,v);}

int js_v08c_read8(JSV08Machine*m,uint32_t a,uint8_t*out,JSV08Stop*s){uint8_t clocks;if(!m||!out)return jsv08_fail(m,s,JSV08_STOP_INVALID_MACHINE,a,0);a&=0xFFFFFFu;clocks=js_v08c_access_clocks(a,m->memsel);if(jsv08_cpu_boundary(&m->scheduler)!=JSV08_DMA_NONE)if(!jsv08_dma_process_ready(m,clocks,s))return 0;js_v08c_scheduler_advance_wall(&m->scheduler,(uint32_t)(clocks-4u));jsv08_event(&m->scheduler,23u,a);if(!jsv08_read_effect(m,a,out,s))return 0;js_v08c_scheduler_advance_wall(&m->scheduler,4u);return 1;}
int js_v08c_write8(JSV08Machine*m,uint32_t a,uint8_t v,JSV08Stop*s){uint8_t clocks;if(!m)return jsv08_fail(m,s,JSV08_STOP_INVALID_MACHINE,a,v);a&=0xFFFFFFu;clocks=js_v08c_access_clocks(a,m->memsel);if(jsv08_cpu_boundary(&m->scheduler)!=JSV08_DMA_NONE)if(!jsv08_dma_process_ready(m,clocks,s))return 0;js_v08c_scheduler_advance_wall(&m->scheduler,clocks);jsv08_event(&m->scheduler,24u,a);return jsv08_write_effect(m,a,v,s);}

int js_v08c_power_on(JSV08Machine*m,const uint8_t*rom,size_t size,const uint8_t*initial_wram){if(!m||!rom||size!=JSV08_ROM_SIZE)return 0;memset(m,0,sizeof(*m));m->rom=rom;m->rom_size=size;if(initial_wram)memcpy(m->wram,initial_wram,JSV08_WRAM_SIZE);m->io_port_output=0xFFu;m->alu.mult_operand1=0xFFu;m->alu.dividend=0xFFFFu;js_v08c_scheduler_init(&m->scheduler);jsv08_dma_power_on(m);m->cpu.s=0x01FFu;m->cpu.p=JS_P_I|JS_P_M|JS_P_X;m->cpu.e=1u;m->cpu.pc=js_v08c_reset_vector(m);js_v08c_scheduler_advance_wall(&m->scheduler,JSV08_RESET_STARTUP_CLOCKS);return 1;}
int js_v08c_reset(JSV08Machine*m){if(!m||!m->rom||m->rom_size!=JSV08_ROM_SIZE)return 0;m->cpu.p=(uint8_t)((m->cpu.p|JS_P_I|JS_P_M|JS_P_X)&(uint8_t)~JS_P_D);m->cpu.e=1u;m->cpu.dbr=0u;m->cpu.d=0u;m->cpu.pbr=0u;m->cpu.x&=0xFFu;m->cpu.y&=0xFFu;m->cpu.s=(uint16_t)(0x0100u|(m->cpu.s&0xFFu));m->cpu.pc=js_v08c_reset_vector(m);js_v08c_scheduler_reset_cpu_side(&m->scheduler);jsv08_dma_reset(m);m->pending_bus_stop=JSV08_STOP_NONE;js_v08c_scheduler_advance_wall(&m->scheduler,JSV08_RESET_STARTUP_CLOCKS);return 1;}

/* Instruction timing choreography around frozen V05C native bodies. */
static void jsv08_idle_n(JSV08Machine*m,unsigned n){while(n--)js_v08c_scheduler_internal_cycle(m);}
static int jsv08_fetch_byte(JSV08Machine*m,const JSV07TimingPlan*p,unsigned i,JSV08Stop*s){uint8_t v=0;uint32_t a=((uint32_t)m->cpu.pbr<<16)|(uint16_t)(m->cpu.pc+i);if(!js_v08c_read8(m,a,&v,s))return 0;if(v!=p->bytes[i])return jsv08_fail(m,s,JSV08_STOP_STATIC_CODE_MISMATCH,a,v);return 1;}
static int jsv08_branch_taken(const JSV08ExecTiming*t){uint8_t op=t->plan->opcode,p=t->before.p;switch(op){case 0x10:return !(p&JS_P_N);case 0x30:return !!(p&JS_P_N);case 0x50:return !(p&JS_P_V);case 0x70:return !!(p&JS_P_V);case 0x90:return !(p&JS_P_C);case 0xB0:return !!(p&JS_P_C);case 0xD0:return !(p&JS_P_Z);case 0xF0:return !!(p&JS_P_Z);default:return 0;}}
static int jsv08_index_cross(const JSV08ExecTiming*t){uint16_t base,index;if(t->plan->mode==JSV07_MODE_ABS_X){base=(uint16_t)t->plan->operand;index=t->before.x;}else if(t->plan->mode==JSV07_MODE_ABS_Y){base=(uint16_t)t->plan->operand;index=t->before.y;}else if(t->plan->mode==JSV07_MODE_DP_IND_Y&&t->pointer_bytes_seen>=2u){base=(uint16_t)(t->pointer_lo|((uint16_t)t->pointer_hi<<8));index=t->before.y;}else return 0;return ((base&0xFF00u)!=((uint16_t)(base+index)&0xFF00u));}
static void jsv08_before_body_access(JSV08Machine*m,int is_write){JSV08ExecTiming*t=&m->timing;uint32_t f=t->plan->rule_flags;unsigned i=0;
 if(!t->pre_access_idle_done){if((f&JSV07_RULE_DYN_DIRECT_LOW_PRE_IDLE)&&(t->before.d&0xFFu))jsv08_idle_n(m,1u);if(f&JSV07_RULE_STACK_REL_PRE_DATA_IDLE)jsv08_idle_n(m,1u);t->pre_access_idle_done=1u;}
 if(!t->pre_stack_idle_done&&is_write&&(f&(JSV07_RULE_JSR_PRE_STACK_IDLE|JSV07_RULE_PUSH_PRE_IDLE))){jsv08_idle_n(m,1u);t->pre_stack_idle_done=1u;}
 if(!t->pre_stack_idle_done&&!is_write&&(f&(JSV07_RULE_RETURN_PRE_IDLE|JSV07_RULE_PULL_PRE_IDLE))){if(f&JSV07_RULE_RETURN_PRE_IDLE)i=2u;else i=2u;jsv08_idle_n(m,i);t->pre_stack_idle_done=1u;}
 if(!t->index_idle_done){int at_data=(!is_write&&t->read_count>=t->plan->pointer_reads)||(is_write&&t->read_count>=t->plan->pointer_reads);if(at_data){if(f&JSV07_RULE_INDEX_FIXED_PRE_DATA_IDLE)jsv08_idle_n(m,1u);if((f&JSV07_RULE_DYN_INDEX_PRE_DATA_IDLE)&&jsv08_index_cross(t))jsv08_idle_n(m,1u);t->index_idle_done=1u;}}
 if(is_write&&!t->rmw_idle_done&&(f&JSV07_RULE_RMW_INTERMEDIATE_IDLE)){jsv08_idle_n(m,1u);t->rmw_idle_done=1u;}
}
static uint8_t jsv08_v05_read(void*opaque,uint32_t a,int*ok){JSV08Machine*m=(JSV08Machine*)opaque;uint8_t v=0;jsv08_before_body_access(m,0);*ok=js_v08c_read8(m,a,&v,0);if(*ok&&m->timing.read_count<m->timing.plan->pointer_reads){if(m->timing.pointer_bytes_seen==0u)m->timing.pointer_lo=v;else if(m->timing.pointer_bytes_seen==1u)m->timing.pointer_hi=v;m->timing.pointer_bytes_seen++;}m->timing.read_count++;return v;}
static void jsv08_v05_write(void*opaque,uint32_t a,uint8_t v,int*ok){JSV08Machine*m=(JSV08Machine*)opaque;jsv08_before_body_access(m,1);*ok=js_v08c_write8(m,a,v,0);m->timing.write_count++;if(*ok&&!m->timing.jsl_deferred_done&&(m->timing.plan->rule_flags&JSV07_RULE_JSL_AFTER_PBR_PUSH_IDLE)&&m->timing.write_count==1u){js_v08c_scheduler_internal_cycle(m);*ok=jsv08_fetch_byte(m,m->timing.plan,3u,0);m->timing.jsl_deferred_done=1u;}}
static int jsv08_prefetch(JSV08Machine*m,const JSV07TimingPlan*p,JSV08Stop*s){unsigned n=(p->rule_flags&JSV07_RULE_JSL_AFTER_PBR_PUSH_IDLE)?3u:p->length,i;for(i=0;i<n;i++)if(!jsv08_fetch_byte(m,p,i,s))return 0;return 1;}
static void jsv08_pre_body_fixed(JSV08Machine*m,const JSV07TimingPlan*p){uint32_t f=p->rule_flags;if(f&JSV07_RULE_IMPLIED_PRE_IDLE)jsv08_idle_n(m,1u);if(f&JSV07_RULE_XBA_EXTRA_IDLE)jsv08_idle_n(m,1u);if(f&JSV07_RULE_STATUS_PRE_IDLE)jsv08_idle_n(m,1u);if(f&JSV07_RULE_RELLONG_PRE_IDLE)jsv08_idle_n(m,1u);}
static void jsv08_post_body(JSV08Machine*m,const JSV07TimingPlan*p){uint32_t f=p->rule_flags;if(f&JSV07_RULE_RTS_POST_POP_IDLE)jsv08_idle_n(m,1u);if(f&JSV07_RULE_BRANCH_ALWAYS_POST_IDLE)jsv08_idle_n(m,1u);if((f&JSV07_RULE_DYN_BRANCH_TAKEN_POST_IDLE)&&jsv08_branch_taken(&m->timing)){int8_t d=(int8_t)p->bytes[1];uint16_t seq=(uint16_t)(m->timing.before.pc+p->length),target=(uint16_t)(seq+d);jsv08_idle_n(m,1u);if((f&JSV07_RULE_DYN_BRANCH_PAGE_POST_IDLE)&&m->timing.before.e&&((seq&0xFF00u)!=(target&0xFF00u)))jsv08_idle_n(m,1u);}}

static int jsv08_stack_pop8(JSV08Machine*m,uint8_t*out,JSV08Stop*s){m->cpu.s=(uint16_t)(m->cpu.s+1u);if(m->cpu.e)m->cpu.s=(uint16_t)(0x0100u|(m->cpu.s&0xFFu));return js_v08c_read8(m,m->cpu.s,out,s);}
static int jsv08_stack_pop16(JSV08Machine*m,uint16_t*out,JSV08Stop*s){uint8_t lo,hi;if(!jsv08_stack_pop8(m,&lo,s)||!jsv08_stack_pop8(m,&hi,s))return 0;*out=(uint16_t)(lo|((uint16_t)hi<<8));return 1;}
static JSExecResult jsv08_rti(JSV08Machine*m,const JSV07TimingPlan*p,JSV08Stop*s){uint8_t ps,k=0;uint16_t pc;uint32_t observed;jsv08_idle_n(m,2u);if(!jsv08_stack_pop8(m,&ps,s)||!jsv08_stack_pop16(m,&pc,s))return JS_EXEC_STOP;if(!m->cpu.e&& !jsv08_stack_pop8(m,&k,s))return JS_EXEC_STOP;m->cpu.p=ps;if(m->cpu.e)m->cpu.p|=(JS_P_M|JS_P_X);m->cpu.pc=pc;if(!m->cpu.e)m->cpu.pbr=k;js_cpu_normalize(&m->cpu);observed=js_cpu_context_key(&m->cpu);if(!js_v07c_timing_plan(observed)){if(s){s->reason=JSV08_STOP_UNADMITTED_INTERRUPT_TARGET;s->source_key=p->key;s->observed_key=observed;s->address=((uint32_t)m->cpu.pbr<<16)|m->cpu.pc;}return JS_EXEC_STOP;}return JS_EXEC_OK;}
static int jsv08_push8(JSV08Machine*m,uint8_t v,JSV08Stop*s){uint32_t a=m->cpu.s;if(!js_v08c_write8(m,a,v,s))return 0;m->cpu.s=(uint16_t)(m->cpu.s-1u);if(m->cpu.e)m->cpu.s=(uint16_t)(0x0100u|(m->cpu.s&0xFFu));return 1;}
static int jsv08_push16(JSV08Machine*m,uint16_t v,JSV08Stop*s){return jsv08_push8(m,(uint8_t)(v>>8),s)&&jsv08_push8(m,(uint8_t)v,s);}
static int jsv08_interrupt(JSV08Machine*m,int nmi,JSV08Stop*s){uint8_t dummy=0,lo,hi;uint16_t vec;uint32_t key;if(!js_v08c_read8(m,((uint32_t)m->cpu.pbr<<16)|m->cpu.pc,&dummy,s))return 0;js_v08c_scheduler_internal_cycle(m);if(m->cpu.e){if(!jsv08_push16(m,m->cpu.pc,s)||!jsv08_push8(m,(uint8_t)(m->cpu.p|0x20u),s))return 0;vec=(uint16_t)(nmi?0xFFFAu:0xFFFEu);}else{if(!jsv08_push8(m,m->cpu.pbr,s)||!jsv08_push16(m,m->cpu.pc,s)||!jsv08_push8(m,m->cpu.p,s))return 0;vec=(uint16_t)(nmi?0xFFEAu:0xFFEEu);}m->cpu.p=(uint8_t)((m->cpu.p|JS_P_I)&(uint8_t)~JS_P_D);m->cpu.pbr=0u;if(!js_v08c_read8(m,vec,&lo,s)||!js_v08c_read8(m,(uint16_t)(vec+1u),&hi,s))return 0;m->cpu.pc=(uint16_t)(lo|((uint16_t)hi<<8));js_cpu_normalize(&m->cpu);key=js_cpu_context_key(&m->cpu);if(!js_v07c_timing_plan(key))return jsv08_fail(m,s,JSV08_STOP_UNADMITTED_INTERRUPT_TARGET,((uint32_t)m->cpu.pbr<<16)|m->cpu.pc,0);return 1;}

JSExecResult js_v08c_step(JSV08Machine*m,JSV08Stop*s){const JSV07TimingPlan*p;JSBus bus;JSStop v05;JSExecResult r;uint32_t key;uint64_t cycles;unsigned expected;if(!m)return JS_EXEC_STOP;js_v08c_stop_clear(s);m->pending_bus_stop=JSV08_STOP_NONE;if(m->scheduler.cpu_stop!=JSV08_CPU_RUNNING){js_v08c_halted_quantum(m);return JS_EXEC_OK;}
 /* Interrupt ownership is scheduler-side and cannot promote a new context. */
 if(m->scheduler.nmi_pending||m->scheduler.nmi_signal){m->scheduler.nmi_pending=m->scheduler.nmi_signal=0u;if(!jsv08_interrupt(m,1,s))return JS_EXEC_STOP;return JS_EXEC_OK;}
 if(m->scheduler.irq_source&&!(m->cpu.p&JS_P_I)){if(!jsv08_interrupt(m,0,s))return JS_EXEC_STOP;return JS_EXEC_OK;}
 key=js_cpu_context_key(&m->cpu);p=js_v07c_timing_plan(key);if(!p){jsv08_fail(m,s,JSV08_STOP_UNKNOWN_CONTEXT,((uint32_t)m->cpu.pbr<<16)|m->cpu.pc,0);return JS_EXEC_STOP;}
 if(!p->v07_executable){JSV08StopReason q=(p->opcode==0xFCu)?JSV08_STOP_UNPROVED_DYNAMIC_TARGET:JSV08_STOP_UNPROVED_RETURN;jsv08_fail(m,s,q,p->address,0);return JS_EXEC_STOP;}
 memset(&m->timing,0,sizeof(m->timing));m->timing.plan=p;m->timing.before=m->cpu;m->timing.start_cpu_cycles=m->scheduler.cpu_cycle_count;
 if(!jsv08_prefetch(m,p,s))return JS_EXEC_STOP;
 if(p->opcode==0x40u&&p->v07_executable){r=jsv08_rti(m,p,s);}else{jsv08_pre_body_fixed(m,p);bus.opaque=m;bus.read8=jsv08_v05_read;bus.write8=jsv08_v05_write;js_stop_clear(&v05);r=js_v05c_step(&m->cpu,&bus,&v05);if(r==JS_EXEC_STOP){if(s)s->v05=v05;if(v05.reason==JS_STOP_BUS_UNAVAILABLE&&m->pending_bus_stop!=JSV08_STOP_NONE){if(s){s->reason=m->pending_bus_stop;s->address=m->pending_bus_address;s->value=m->pending_bus_value;}return r;}if(s){s->reason=JSV08_STOP_V05;s->source_key=v05.source_key;s->observed_key=v05.observed_key;s->address=v05.address;s->value=v05.value;}return r;}jsv08_post_body(m,p);}
 if(r!=JS_EXEC_OK)return r;cycles=m->scheduler.cpu_cycle_count-m->timing.start_cpu_cycles;expected=p->cycle_min;if((p->rule_flags&JSV07_RULE_DYN_DIRECT_LOW_PRE_IDLE)&&(m->timing.before.d&0xFFu))expected++;if((p->rule_flags&JSV07_RULE_DYN_INDEX_PRE_DATA_IDLE)&&jsv08_index_cross(&m->timing))expected++;if((p->rule_flags&JSV07_RULE_DYN_BRANCH_TAKEN_POST_IDLE)&&jsv08_branch_taken(&m->timing)){int8_t d=(int8_t)p->bytes[1];uint16_t seq=(uint16_t)(m->timing.before.pc+p->length),target=(uint16_t)(seq+d);expected++;if((p->rule_flags&JSV07_RULE_DYN_BRANCH_PAGE_POST_IDLE)&&m->timing.before.e&&((seq&0xFF00u)!=(target&0xFF00u)))expected++;}
 if(cycles!=expected){if(s){s->reason=JSV08_STOP_TIMING_PLAN_MISMATCH;s->source_key=p->key;s->observed_key=(uint32_t)cycles;s->address=p->address;s->value=(uint8_t)expected;}return JS_EXEC_STOP;}return JS_EXEC_OK;}
