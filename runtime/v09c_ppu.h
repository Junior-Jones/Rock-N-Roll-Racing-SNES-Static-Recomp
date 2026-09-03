#ifndef ROCKNROLL_V09C_PPU_H
#define ROCKNROLL_V09C_PPU_H
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
#define JSV09_VRAM_BYTES 0x10000u
#define JSV09_OAM_BYTES 544u
#define JSV09_CGRAM_WORDS 256u

typedef enum JSV09PpuResult {
    JSV09_PPU_OK=1,
    JSV09_PPU_RENDERER_REQUIRED=-1,
    JSV09_PPU_UNKNOWN_DATA=-2
} JSV09PpuResult;

typedef struct JSV09PpuLayer {
    uint16_t tilemap_address, chr_address, hscroll, vscroll;
    uint8_t double_width, double_height, large_tiles;
} JSV09PpuLayer;

typedef struct JSV09PpuWindow {
    uint8_t active[6], inverted[6], left, right;
} JSV09PpuWindow;

typedef struct JSV09PpuAccess {
    uint16_t scanline, hclock, vblank_start, nmi_scanline;
    uint8_t odd_frame, io_port_output, external_open_bus;
} JSV09PpuAccess;

typedef struct JSV09Ppu {
    uint8_t vram[JSV09_VRAM_BYTES], vram_known[JSV09_VRAM_BYTES];
    uint8_t oam[JSV09_OAM_BYTES], oam_known[JSV09_OAM_BYTES];
    uint16_t cgram[JSV09_CGRAM_WORDS];
    uint8_t cgram_known_lo[JSV09_CGRAM_WORDS], cgram_known_hi[JSV09_CGRAM_WORDS];
    uint8_t register_written[64];

    uint8_t forced_blank, brightness, bg_mode, mode1_bg3_priority, mosaic_size, mosaic_enabled;
    uint8_t oam_mode, enable_oam_priority, oam_write_buffer, oam_write_buffer_known;
    uint16_t oam_base_address, oam_address_offset, oam_ram_address, internal_oam_address;
    JSV09PpuLayer layer[4];
    uint8_t hv_scroll_latch, h_scroll_latch;

    uint16_t vram_address, vram_increment, vram_read_buffer;
    uint8_t vram_remap, vram_inc_on_high, vram_read_buffer_known;

    uint8_t mode7_large_map, mode7_fill_tile0, mode7_hmirror, mode7_vmirror, mode7_latch;
    int16_t mode7_matrix[4], mode7_center_x, mode7_center_y;
    uint16_t mode7_hscroll, mode7_vscroll;

    uint8_t cgram_address, cgram_latch, cgram_write_buffer, cgram_write_buffer_known;
    JSV09PpuWindow window[2];
    uint8_t mask_logic[6], window_mask_main[5], window_mask_sub[5];
    uint8_t main_screen_layers, sub_screen_layers;
    uint8_t color_clip_mode, color_prevent_mode, color_add_subscreen, direct_color;
    uint8_t color_math_enabled, color_subtract, color_halve;
    uint16_t fixed_color;
    uint8_t extbg, hires, overscan, obj_interlace, screen_interlace;

    uint8_t ppu1_open_bus, ppu2_open_bus;
    uint16_t latched_h, latched_v;
    uint8_t location_latched, hloc_toggle, vloc_toggle;
    uint64_t read_count, write_count, renderer_stops, unknown_stops;
} JSV09Ppu;

void js_v09c_ppu_power_on(JSV09Ppu *p);
void js_v09c_ppu_reset(JSV09Ppu *p);
JSV09PpuResult js_v09c_ppu_read(JSV09Ppu *p, uint16_t addr, const JSV09PpuAccess *a, uint8_t *out);
JSV09PpuResult js_v09c_ppu_write(JSV09Ppu *p, uint16_t addr, uint8_t value, const JSV09PpuAccess *a);
uint16_t js_v09c_ppu_vram_word_address(const JSV09Ppu *p);
#ifdef __cplusplus
}
#endif
#endif
