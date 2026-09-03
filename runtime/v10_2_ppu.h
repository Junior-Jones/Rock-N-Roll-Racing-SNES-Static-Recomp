#ifndef ROCKNROLL_V10_2_PPU_H
#define ROCKNROLL_V10_2_PPU_H
#include <stddef.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
#define JSV10_2_VRAM_BYTES 0x10000u
#define JSV10_2_OAM_BYTES 544u
#define JSV10_2_CGRAM_WORDS 256u
#define JSV10_2_FRAME_WIDTH 256u
#define JSV10_2_FRAME_MAX_HEIGHT 240u
#define JSV10_2_FRAME_BYTES (JSV10_2_FRAME_WIDTH*JSV10_2_FRAME_MAX_HEIGHT*2u)

typedef enum JSV10_2PpuResult {
    JSV10_2_PPU_OK=1,
    JSV10_2_PPU_RENDERER_REQUIRED=-1,
    JSV10_2_PPU_UNKNOWN_DATA=-2
} JSV10_2PpuResult;

typedef struct JSV10_2PpuLayer {
    uint16_t tilemap_address, chr_address, hscroll, vscroll;
    uint8_t double_width, double_height, large_tiles;
} JSV10_2PpuLayer;

typedef struct JSV10_2PpuWindow {
    uint8_t active[6], inverted[6], left, right;
} JSV10_2PpuWindow;

typedef struct JSV10_2PpuAccess {
    uint16_t scanline, hclock, vblank_start, nmi_scanline;
    uint8_t odd_frame, io_port_output, external_open_bus;
} JSV10_2PpuAccess;

typedef struct JSV10_2PpuFrameInfo {
    uint16_t width, height;
    uint8_t mode, brightness, forced_blank, main_screen_mask, sub_screen_mask;
    uint32_t non_backdrop_pixels, unique_colors;
    uint8_t tiled_modes_0_to_6, mode7, objects, windows;
    uint8_t main_sub_screen, color_math, brightness_and_forced_blank;
    uint8_t current_state_not_natural_frame, passed;
    uint64_t bgr555_digest;
} JSV10_2PpuFrameInfo;

typedef struct JSV10_2Ppu {
    uint8_t vram[JSV10_2_VRAM_BYTES], vram_known[JSV10_2_VRAM_BYTES];
    uint8_t oam[JSV10_2_OAM_BYTES], oam_known[JSV10_2_OAM_BYTES];
    uint16_t cgram[JSV10_2_CGRAM_WORDS];
    uint8_t cgram_known_lo[JSV10_2_CGRAM_WORDS], cgram_known_hi[JSV10_2_CGRAM_WORDS];
    uint8_t register_written[64], registers[64];

    uint8_t forced_blank, brightness, bg_mode, mode1_bg3_priority, mosaic_size, mosaic_enabled;
    uint8_t oam_mode, enable_oam_priority, oam_write_buffer, oam_write_buffer_known;
    uint16_t oam_base_address, oam_address_offset, oam_ram_address, internal_oam_address;
    JSV10_2PpuLayer layer[4];
    uint16_t bg_scroll[8];
    uint8_t hv_scroll_latch, h_scroll_latch;

    uint16_t vram_address, vram_increment, vram_read_buffer;
    uint8_t vram_remap, vram_inc_on_high, vram_read_buffer_known;

    uint8_t mode7_large_map, mode7_fill_tile0, mode7_hmirror, mode7_vmirror, mode7_latch;
    int16_t mode7_matrix[4], mode7_center_x, mode7_center_y;
    uint16_t mode7_hscroll, mode7_vscroll;

    uint8_t cgram_address, cgram_latch, cgram_write_buffer, cgram_write_buffer_known;
    JSV10_2PpuWindow window[2];
    uint8_t mask_logic[6], window_mask_main[5], window_mask_sub[5];
    uint8_t main_screen_layers, sub_screen_layers;
    uint8_t color_clip_mode, color_prevent_mode, color_add_subscreen, direct_color;
    uint8_t color_math_enabled, color_subtract, color_halve;
    uint16_t fixed_color;
    uint8_t extbg, hires, overscan, obj_interlace, screen_interlace;

    uint8_t ppu1_open_bus, ppu2_open_bus;
    uint16_t latched_h, latched_v;
    uint8_t location_latched, hloc_toggle, vloc_toggle;
    uint8_t range_over, time_over;
    uint8_t framebuffer[JSV10_2_FRAME_BYTES];
    uint64_t frame_count;
    uint32_t non_backdrop_pixels;
    uint64_t read_count, write_count, renderer_stops, unknown_stops;
} JSV10_2Ppu;

void js_v10_2_ppu_power_on(JSV10_2Ppu *p);
void js_v10_2_ppu_reset(JSV10_2Ppu *p);
JSV10_2PpuResult js_v10_2_ppu_read(JSV10_2Ppu *p, uint16_t addr, const JSV10_2PpuAccess *a, uint8_t *out);
JSV10_2PpuResult js_v10_2_ppu_write(JSV10_2Ppu *p, uint16_t addr, uint8_t value, const JSV10_2PpuAccess *a);
uint16_t js_v10_2_ppu_vram_word_address(const JSV10_2Ppu *p);
int js_v10_2_ppu_render_scanline(JSV10_2Ppu *p, unsigned raster_y, unsigned output_y);
int js_v10_2_ppu_render_frame(JSV10_2Ppu *p, JSV10_2PpuFrameInfo *info);
int js_v10_2_ppu_read_frame_bgr555(const JSV10_2Ppu *p, uint32_t offset, void *out, size_t size);
#ifdef __cplusplus
}
#endif
#endif
