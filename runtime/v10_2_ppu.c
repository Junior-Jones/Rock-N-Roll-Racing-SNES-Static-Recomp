#include "v10_2_ppu.h"
#include <string.h>

static uint16_t dot_from_hclock(uint16_t h){if(h<=1292u)return h>>2;if(h<=1310u)return (uint16_t)((h-2u)>>2);return (uint16_t)((h-4u)>>2);}
static int can_vram(const JSV10_2Ppu*p,const JSV10_2PpuAccess*a){return p->forced_blank||a->scanline>=a->nmi_scanline;}
static int can_cgram(const JSV10_2Ppu*p,const JSV10_2PpuAccess*a){return p->forced_blank||a->scanline>=a->nmi_scanline||a->scanline==0u||a->hclock<88u||a->hclock>=1096u;}
static int can_oam(const JSV10_2Ppu*p,const JSV10_2PpuAccess*a){return p->forced_blank||a->scanline>=a->vblank_start;}
static uint16_t oam_phys(uint16_t a){return a<512u?a:(uint16_t)(0x200u|(a&0x1Fu));}
static void mark_reg(JSV10_2Ppu*p,uint16_t a,uint8_t v){if(a>=0x2100u&&a<=0x213Fu){p->register_written[a-0x2100u]=1u;p->registers[a-0x2100u]=v;}}
static JSV10_2PpuResult renderer(JSV10_2Ppu*p){p->renderer_stops++;return JSV10_2_PPU_RENDERER_REQUIRED;}
static JSV10_2PpuResult unknown(JSV10_2Ppu*p){p->unknown_stops++;return JSV10_2_PPU_UNKNOWN_DATA;}

void js_v10_2_ppu_power_on(JSV10_2Ppu*p){if(!p)return;memset(p,0,sizeof(*p));p->forced_blank=1u;p->vram_increment=1u;p->mosaic_size=1u;}
void js_v10_2_ppu_reset(JSV10_2Ppu*p){if(!p)return;p->forced_blank=1u;p->hloc_toggle=0u;p->vloc_toggle=0u;p->location_latched=0u;}

uint16_t js_v10_2_ppu_vram_word_address(const JSV10_2Ppu*p){uint16_t a=p->vram_address;switch(p->vram_remap&3u){default:case 0:return a;case 1:return(uint16_t)((a&0xFF00u)|((a&0x00E0u)>>5)|((a&0x001Fu)<<3));case 2:return(uint16_t)((a&0xFE00u)|((a&0x01C0u)>>6)|((a&0x003Fu)<<3));case 3:return(uint16_t)((a&0xFC00u)|((a&0x0380u)>>7)|((a&0x007Fu)<<3));}}
static JSV10_2PpuResult update_vram_buffer(JSV10_2Ppu*p,const JSV10_2PpuAccess*a){uint32_t b;/* Mesen's SNES PPU returns a known zero read buffer when VMADD is loaded during active display. */if(!can_vram(p,a)){p->vram_read_buffer=0u;p->vram_read_buffer_known=1u;return JSV10_2_PPU_OK;}b=(uint32_t)js_v10_2_ppu_vram_word_address(p)<<1;p->vram_read_buffer=(uint16_t)(p->vram[b]|((uint16_t)p->vram[b+1u]<<8));p->vram_read_buffer_known=(uint8_t)(p->vram_known[b]&&p->vram_known[b+1u]);return JSV10_2_PPU_OK;}
static void latch_location(JSV10_2Ppu*p,const JSV10_2PpuAccess*a){p->latched_h=dot_from_hclock(a->hclock);p->latched_v=a->scanline;p->location_latched=1u;}
static void process_window(JSV10_2Ppu*p,uint8_t v,unsigned off){p->window[0].active[off]=(v&0x02u)!=0;p->window[0].active[off+1u]=(v&0x20u)!=0;p->window[0].inverted[off]=(v&0x01u)!=0;p->window[0].inverted[off+1u]=(v&0x10u)!=0;p->window[1].active[off]=(v&0x08u)!=0;p->window[1].active[off+1u]=(v&0x80u)!=0;p->window[1].inverted[off]=(v&0x04u)!=0;p->window[1].inverted[off+1u]=(v&0x40u)!=0;}

JSV10_2PpuResult js_v10_2_ppu_read(JSV10_2Ppu*p,uint16_t addr,const JSV10_2PpuAccess*a,uint8_t*out){uint8_t v=0;int32_t prod;uint16_t oa,ca;uint32_t vb;if(!p||!a||!out||addr<0x2100u||addr>0x213Fu)return JSV10_2_PPU_UNKNOWN_DATA;p->read_count++;
 switch(addr){
 case 0x2134u:case 0x2135u:case 0x2136u:prod=(int32_t)p->mode7_matrix[0]*(int32_t)(int8_t)(((uint16_t)p->mode7_matrix[1])>>8);v=(uint8_t)((uint32_t)prod>>(8u*(addr-0x2134u)));p->ppu1_open_bus=v;*out=v;return JSV10_2_PPU_OK;
 case 0x2137u:if(a->io_port_output&0x80u)latch_location(p,a);*out=a->external_open_bus;return JSV10_2_PPU_OK;
 case 0x2138u:if(!can_oam(p,a))return renderer(p);oa=oam_phys(p->internal_oam_address);if(!p->oam_known[oa])return unknown(p);v=p->oam[oa];p->internal_oam_address=(uint16_t)((p->internal_oam_address+1u)&0x3FFu);p->ppu1_open_bus=v;*out=v;return JSV10_2_PPU_OK;
 case 0x2139u:case 0x213Au:if(!p->vram_read_buffer_known)return unknown(p);v=(uint8_t)(p->vram_read_buffer>>(addr==0x213Au?8u:0u));if((addr==0x2139u&&!p->vram_inc_on_high)||(addr==0x213Au&&p->vram_inc_on_high)){JSV10_2PpuResult r=update_vram_buffer(p,a);if(r!=JSV10_2_PPU_OK)return r;p->vram_address=(uint16_t)((p->vram_address+p->vram_increment)&0x7FFFu);}p->ppu1_open_bus=v;*out=v;return JSV10_2_PPU_OK;
 case 0x213Bu:if(!can_cgram(p,a))return renderer(p);ca=p->cgram_address;if(p->cgram_latch){if(!p->cgram_known_hi[ca])return unknown(p);v=(uint8_t)(((p->cgram[ca]>>8)&0x7Fu)|(p->ppu2_open_bus&0x80u));p->cgram_address=(uint8_t)(p->cgram_address+1u);}else{if(!p->cgram_known_lo[ca])return unknown(p);v=(uint8_t)p->cgram[ca];}p->cgram_latch^=1u;p->ppu2_open_bus=v;*out=v;return JSV10_2_PPU_OK;
 case 0x213Cu:if(!p->location_latched)latch_location(p,a);v=p->hloc_toggle?(uint8_t)(((p->latched_h>>8)&1u)|(p->ppu2_open_bus&0xFEu)):(uint8_t)p->latched_h;p->hloc_toggle^=1u;p->ppu2_open_bus=v;*out=v;return JSV10_2_PPU_OK;
 case 0x213Du:if(!p->location_latched)latch_location(p,a);v=p->vloc_toggle?(uint8_t)(((p->latched_v>>8)&1u)|(p->ppu2_open_bus&0xFEu)):(uint8_t)p->latched_v;p->vloc_toggle^=1u;p->ppu2_open_bus=v;*out=v;return JSV10_2_PPU_OK;
 case 0x213Eu:v=(uint8_t)((p->time_over?0x80u:0u)|(p->range_over?0x40u:0u)|(p->ppu1_open_bus&0x10u)|0x01u);p->ppu1_open_bus=v;*out=v;return JSV10_2_PPU_OK;
 case 0x213Fu:v=(uint8_t)((a->odd_frame?0x80u:0u)|(p->location_latched?0x40u:0u)|(p->ppu2_open_bus&0x20u)|0x03u);if(a->io_port_output&0x80u)p->location_latched=0u;p->hloc_toggle=0u;p->vloc_toggle=0u;p->ppu2_open_bus=v;*out=v;return JSV10_2_PPU_OK;
 default:vb=(uint32_t)(addr&0x210Fu);if((vb>=0x2104u&&vb<=0x2106u)||(vb>=0x2108u&&vb<=0x210Au))*out=p->ppu1_open_bus;else*out=a->external_open_bus;return JSV10_2_PPU_OK;
 }
}

JSV10_2PpuResult js_v10_2_ppu_write(JSV10_2Ppu*p,uint16_t addr,uint8_t v,const JSV10_2PpuAccess*a){unsigned i;uint16_t oa,ca;uint32_t b;JSV10_2PpuResult r;if(!p||!a||addr<0x2100u||addr>0x213Fu)return JSV10_2_PPU_UNKNOWN_DATA;p->write_count++;mark_reg(p,addr,v);
 switch(addr){
 case 0x2100u:if(p->forced_blank&&a->scanline==a->nmi_scanline)p->internal_oam_address=(uint16_t)(p->oam_ram_address<<1);p->forced_blank=(v&0x80u)!=0;p->brightness=v&0x0Fu;break;
 case 0x2101u:p->oam_mode=(v>>5)&7u;p->oam_base_address=(uint16_t)((v&7u)<<13);p->oam_address_offset=(uint16_t)((((v&0x18u)>>3)+1u)<<12);break;
 case 0x2102u:p->oam_ram_address=(uint16_t)((p->oam_ram_address&0x100u)|v);p->internal_oam_address=(uint16_t)(p->oam_ram_address<<1);break;
 case 0x2103u:p->oam_ram_address=(uint16_t)((p->oam_ram_address&0xFFu)|((uint16_t)(v&1u)<<8));p->internal_oam_address=(uint16_t)(p->oam_ram_address<<1);p->enable_oam_priority=(v&0x80u)!=0;break;
 case 0x2104u:if(!can_oam(p,a))return renderer(p);oa=p->internal_oam_address;if(oa<512u){if(oa&1u){if(!p->oam_write_buffer_known)return unknown(p);p->oam[oa-1u]=p->oam_write_buffer;p->oam_known[oa-1u]=1u;p->oam[oa]=v;p->oam_known[oa]=1u;}else{p->oam_write_buffer=v;p->oam_write_buffer_known=1u;}}else{oa=oam_phys(oa);if((p->internal_oam_address&1u)==0u){p->oam_write_buffer=v;p->oam_write_buffer_known=1u;}p->oam[oa]=v;p->oam_known[oa]=1u;}p->internal_oam_address=(uint16_t)((p->internal_oam_address+1u)&0x3FFu);break;
 case 0x2105u:p->bg_mode=v&7u;p->mode1_bg3_priority=(v&8u)!=0;for(i=0;i<4;i++)p->layer[i].large_tiles=(v>>(4u+i))&1u;break;
 case 0x2106u:p->mosaic_size=(uint8_t)(((v>>4)&0x0Fu)+1u);p->mosaic_enabled=v&0x0Fu;break;
 case 0x2107u:case 0x2108u:case 0x2109u:case 0x210Au:i=addr-0x2107u;p->layer[i].tilemap_address=(uint16_t)((v&0x7Cu)<<8);p->layer[i].double_width=v&1u;p->layer[i].double_height=(v>>1)&1u;break;
 case 0x210Bu:case 0x210Cu:i=(addr-0x210Bu)*2u;p->layer[i].chr_address=(uint16_t)((v&7u)<<12);p->layer[i+1u].chr_address=(uint16_t)((v&0x70u)<<8);break;
 case 0x210Du:p->mode7_hscroll=(uint16_t)(((uint16_t)v<<8)|p->mode7_latch)&0x1FFFu;p->mode7_latch=v;/* fallthrough */
 case 0x210Fu:case 0x2111u:case 0x2113u:i=(addr-0x210Du)>>1;p->layer[i].hscroll=(uint16_t)(((uint16_t)v<<8)|(p->hv_scroll_latch&0xF8u)|(p->h_scroll_latch&7u))&0x3FFu;p->bg_scroll[i*2u]=p->layer[i].hscroll;p->hv_scroll_latch=v;p->h_scroll_latch=v;break;
 case 0x210Eu:p->mode7_vscroll=(uint16_t)(((uint16_t)v<<8)|p->mode7_latch)&0x1FFFu;p->mode7_latch=v;/* fallthrough */
 case 0x2110u:case 0x2112u:case 0x2114u:i=(addr-0x210Eu)>>1;p->layer[i].vscroll=(uint16_t)(((uint16_t)v<<8)|p->hv_scroll_latch)&0x3FFu;p->bg_scroll[i*2u+1u]=p->layer[i].vscroll;p->hv_scroll_latch=v;break;
 case 0x2115u:p->vram_increment=(v&3u)==0u?1u:(v&3u)==1u?32u:128u;p->vram_remap=(v>>2)&3u;p->vram_inc_on_high=(v&0x80u)!=0;break;
 case 0x2116u:p->vram_address=(uint16_t)((p->vram_address&0x7F00u)|v);r=update_vram_buffer(p,a);if(r!=JSV10_2_PPU_OK)return r;break;
 case 0x2117u:p->vram_address=(uint16_t)((p->vram_address&0x00FFu)|((uint16_t)(v&0x7Fu)<<8));r=update_vram_buffer(p,a);if(r!=JSV10_2_PPU_OK)return r;break;
 case 0x2118u:case 0x2119u:b=(uint32_t)js_v10_2_ppu_vram_word_address(p)<<1;b+=(addr==0x2119u);if(can_vram(p,a)){p->vram[b]=v;p->vram_known[b]=1u;}if((addr==0x2118u&&!p->vram_inc_on_high)||(addr==0x2119u&&p->vram_inc_on_high))p->vram_address=(uint16_t)((p->vram_address+p->vram_increment)&0x7FFFu);break;
 case 0x211Au:p->mode7_large_map=(v&0x80u)!=0;p->mode7_fill_tile0=(v&0x40u)!=0;p->mode7_hmirror=v&1u;p->mode7_vmirror=(v>>1)&1u;break;
 case 0x211Bu:case 0x211Cu:case 0x211Du:case 0x211Eu:i=addr-0x211Bu;p->mode7_matrix[i]=(int16_t)(((uint16_t)v<<8)|p->mode7_latch);p->mode7_latch=v;break;
 case 0x211Fu:p->mode7_center_x=(int16_t)(((uint16_t)v<<8)|p->mode7_latch);p->mode7_latch=v;break;
 case 0x2120u:p->mode7_center_y=(int16_t)(((uint16_t)v<<8)|p->mode7_latch);p->mode7_latch=v;break;
 case 0x2121u:p->cgram_address=v;p->cgram_latch=0u;break;
 case 0x2122u:if(!can_cgram(p,a))return renderer(p);ca=p->cgram_address;if(p->cgram_latch){v&=0x7Fu;if(!p->cgram_write_buffer_known)return unknown(p);p->cgram[ca]=(uint16_t)(p->cgram_write_buffer|((uint16_t)v<<8));p->cgram_known_lo[ca]=1u;p->cgram_known_hi[ca]=1u;p->cgram_address=(uint8_t)(p->cgram_address+1u);}else{p->cgram_write_buffer=v;p->cgram_write_buffer_known=1u;}p->cgram_latch^=1u;break;
 case 0x2123u:process_window(p,v,0u);break;case 0x2124u:process_window(p,v,2u);break;case 0x2125u:process_window(p,v,4u);break;
 case 0x2126u:p->window[0].left=v;break;case 0x2127u:p->window[0].right=v;break;case 0x2128u:p->window[1].left=v;break;case 0x2129u:p->window[1].right=v;break;
 case 0x212Au:for(i=0;i<4;i++)p->mask_logic[i]=(v>>(2u*i))&3u;break;case 0x212Bu:p->mask_logic[4]=v&3u;p->mask_logic[5]=(v>>2)&3u;break;
 case 0x212Cu:p->main_screen_layers=v&0x1Fu;break;case 0x212Du:p->sub_screen_layers=v&0x1Fu;break;
 case 0x212Eu:for(i=0;i<5;i++)p->window_mask_main[i]=(v>>i)&1u;break;case 0x212Fu:for(i=0;i<5;i++)p->window_mask_sub[i]=(v>>i)&1u;break;
 case 0x2130u:p->color_clip_mode=(v>>6)&3u;p->color_prevent_mode=(v>>4)&3u;p->color_add_subscreen=(v>>1)&1u;p->direct_color=v&1u;break;
 case 0x2131u:p->color_math_enabled=v&0x3Fu;p->color_subtract=(v>>7)&1u;p->color_halve=(v>>6)&1u;break;
 case 0x2132u:if(v&0x80u)p->fixed_color=(uint16_t)((p->fixed_color&~0x7C00u)|((uint16_t)(v&0x1Fu)<<10));if(v&0x40u)p->fixed_color=(uint16_t)((p->fixed_color&~0x03E0u)|((uint16_t)(v&0x1Fu)<<5));if(v&0x20u)p->fixed_color=(uint16_t)((p->fixed_color&~0x001Fu)|(v&0x1Fu));break;
 case 0x2133u:p->extbg=(v>>6)&1u;p->hires=(v>>3)&1u;p->overscan=(v>>2)&1u;p->obj_interlace=(v>>1)&1u;p->screen_interlace=v&1u;break;
 default:break; /* writes to read-only/unused PPU addresses are ignored after bus timing */
 }
 return JSV10_2_PPU_OK;
}
