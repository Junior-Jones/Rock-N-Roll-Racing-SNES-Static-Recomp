#include "v10_2_ppu.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned failures;
#define CHECK(expr) do { if (!(expr)) { \
    fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #expr); failures++; \
} } while (0)

static JSV10_2Ppu *new_ppu(void) {
    JSV10_2Ppu *p = (JSV10_2Ppu *)calloc(1u, sizeof(*p));
    if (!p) exit(2);
    js_v10_2_ppu_power_on(p);
    return p;
}

static JSV10_2PpuAccess blank_access(void) {
    JSV10_2PpuAccess access;
    memset(&access, 0, sizeof(access));
    access.vblank_start = 225u;
    access.nmi_scanline = 225u;
    access.io_port_output = 0xFFu;
    return access;
}

static void write_reg(JSV10_2Ppu *p, JSV10_2PpuAccess *a, uint16_t reg, uint8_t value) {
    CHECK(js_v10_2_ppu_write(p, reg, value, a) == JSV10_2_PPU_OK);
}

static unsigned mode_bpp(unsigned mode) {
    static const uint8_t bpp[7] = {2u, 4u, 4u, 8u, 8u, 4u, 4u};
    return bpp[mode];
}

static void setup_tiled_mode(JSV10_2Ppu *p, unsigned mode) {
    JSV10_2PpuAccess access = blank_access();
    unsigned bpp = mode_bpp(mode), row, plane;
    uint32_t tile_base = bpp * 8u;
    p->vram[0] = 1u; p->vram[1] = 0u;
    for (row = 0u; row < 8u; ++row) {
        for (plane = 0u; plane < bpp; ++plane) {
            uint32_t address = tile_base + row * 2u + (plane >> 1u) * 16u + (plane & 1u);
            p->vram[address] = 0xFFu;
        }
    }
    for (row = 0u; row < JSV10_2_CGRAM_WORDS; ++row)
        p->cgram[row] = (uint16_t)((row & 31u) | (((row >> 1u) & 31u) << 5u) | (1u << 10u));
    write_reg(p, &access, 0x2100u, 0x0Fu);
    write_reg(p, &access, 0x2105u, (uint8_t)mode);
    write_reg(p, &access, 0x2107u, 0u);
    write_reg(p, &access, 0x210Bu, 0u);
    write_reg(p, &access, 0x212Cu, 1u);
}

static void test_all_tiled_modes(void) {
    unsigned mode;
    for (mode = 0u; mode <= 6u; ++mode) {
        JSV10_2Ppu *p = new_ppu();
        JSV10_2PpuFrameInfo info;
        setup_tiled_mode(p, mode);
        CHECK(js_v10_2_ppu_render_frame(p, &info));
        CHECK(info.passed && info.mode == mode);
        CHECK(info.width == 256u && info.height == 224u);
        CHECK(info.non_backdrop_pixels != 0u);
        CHECK(info.tiled_modes_0_to_6 && info.objects && info.windows && info.color_math);
        free(p);
    }
}

static void test_mode7(void) {
    JSV10_2Ppu *p = new_ppu();
    JSV10_2PpuAccess access = blank_access();
    JSV10_2PpuFrameInfo info;
    uint32_t address;
    for (address = 0u; address < JSV10_2_VRAM_BYTES; address += 2u) {
        p->vram[address] = 1u;
        p->vram[address + 1u] = 1u;
    }
    p->cgram[1] = 0x03E0u;
    write_reg(p, &access, 0x2100u, 0x0Fu);
    write_reg(p, &access, 0x2105u, 7u);
    write_reg(p, &access, 0x212Cu, 1u);
    p->mode7_matrix[0] = 0x0100;
    p->mode7_matrix[3] = 0x0100;
    CHECK(js_v10_2_ppu_render_frame(p, &info));
    CHECK(info.mode == 7u && info.mode7 && info.non_backdrop_pixels != 0u);
    free(p);
}

static void test_obj_color_math_blank_and_stat77(void) {
    JSV10_2Ppu *p = new_ppu();
    JSV10_2PpuAccess access = blank_access();
    JSV10_2PpuFrameInfo info;
    unsigned object;
    uint16_t color;
    memset(p->oam, 0, sizeof(p->oam));
    for (object = 0u; object < 128u; ++object) p->oam[object * 4u + 1u] = 0xE0u;
    p->oam[1] = 0xFFu;
    p->oam[3] = 0x02u;
    memset(p->vram, 0xFF, 32u);
    for (object = 128u; object < 256u; ++object) p->cgram[object] = 0x7C00u;
    write_reg(p, &access, 0x2100u, 0x0Fu);
    write_reg(p, &access, 0x212Cu, 0x10u);
    CHECK(js_v10_2_ppu_render_frame(p, &info));
    CHECK(info.non_backdrop_pixels != 0u);

    memset(p->vram, 0, sizeof(p->vram));
    memset(p->oam, 0, sizeof(p->oam));
    p->cgram[0] = 0x001Fu;
    p->fixed_color = 0x7C00u;
    p->registers[0x00] = 0x0Fu;
    p->registers[0x2C] = 0u;
    p->registers[0x30] = 0u;
    p->registers[0x31] = 0x20u;
    CHECK(js_v10_2_ppu_render_frame(p, &info));
    color = (uint16_t)(p->framebuffer[0] | ((uint16_t)p->framebuffer[1] << 8u));
    CHECK(color == 0x7C1Fu);

    p->registers[0x00] = 0x8Fu;
    CHECK(js_v10_2_ppu_render_frame(p, &info));
    CHECK(info.forced_blank && info.non_backdrop_pixels == 0u);
    CHECK(p->framebuffer[0] == 0u && p->framebuffer[1] == 0u);

    p->range_over = 1u; p->time_over = 1u; p->ppu1_open_bus = 0x10u;
    CHECK(js_v10_2_ppu_read(p, 0x213Eu, &access, p->registers) == JSV10_2_PPU_OK);
    CHECK((p->registers[0] & 0xD0u) == 0xD0u);
    free(p);
}

static void test_register_latches_vram_remap_and_overscan(void) {
    JSV10_2Ppu *p = new_ppu();
    JSV10_2PpuAccess access = blank_access();
    JSV10_2PpuFrameInfo info;
    p->vram_address = 0x1234u;
    p->vram_remap = 0u; CHECK(js_v10_2_ppu_vram_word_address(p) == 0x1234u);
    p->vram_remap = 1u; CHECK(js_v10_2_ppu_vram_word_address(p) == (uint16_t)((0x1234u&0xFF00u)|((0x1234u&0x00E0u)>>5u)|((0x1234u&0x001Fu)<<3u)));
    p->vram_remap = 2u; CHECK(js_v10_2_ppu_vram_word_address(p) == (uint16_t)((0x1234u&0xFE00u)|((0x1234u&0x01C0u)>>6u)|((0x1234u&0x003Fu)<<3u)));
    p->vram_remap = 3u; CHECK(js_v10_2_ppu_vram_word_address(p) == (uint16_t)((0x1234u&0xFC00u)|((0x1234u&0x0380u)>>7u)|((0x1234u&0x007Fu)<<3u)));
    write_reg(p, &access, 0x210Du, 0x34u);
    write_reg(p, &access, 0x210Du, 0x12u);
    CHECK(p->bg_scroll[0] == p->layer[0].hscroll);
    write_reg(p, &access, 0x2133u, 0x04u);
    write_reg(p, &access, 0x2100u, 0x8Fu);
    CHECK(js_v10_2_ppu_render_frame(p, &info));
    CHECK(info.height == 239u);
    free(p);
}

static void test_active_display_vram_rules(void) {
    JSV10_2Ppu *p = new_ppu();
    JSV10_2PpuAccess access = blank_access();
    uint8_t value = 0xFFu;
    access.scanline = 100u;
    access.hclock = 500u;
    p->forced_blank = 0u;
    p->vram[0x2468u] = 0x5Au;
    p->vram_known[0x2468u] = 1u;
    p->vram_address = 0x1234u;
    CHECK(js_v10_2_ppu_write(p, 0x2116u, 0x34u, &access) == JSV10_2_PPU_OK);
    CHECK(p->vram_read_buffer_known && p->vram_read_buffer == 0u);
    CHECK(js_v10_2_ppu_read(p, 0x2139u, &access, &value) == JSV10_2_PPU_OK);
    CHECK(value == 0u && p->vram_address == 0x1235u);
    p->vram_address = 0x1234u;
    CHECK(js_v10_2_ppu_write(p, 0x2118u, 0xA5u, &access) == JSV10_2_PPU_OK);
    CHECK(p->vram[0x2468u] == 0x5Au && p->vram_address == 0x1235u);
    free(p);
}

int main(void) {
    test_all_tiled_modes();
    test_mode7();
    test_obj_color_math_blank_and_stat77();
    test_register_latches_vram_remap_and_overscan();
    test_active_display_vram_rules();
    if (failures) fprintf(stderr, "V10.2 PPU failures: %u\n", failures);
    return failures ? 1 : 0;
}
