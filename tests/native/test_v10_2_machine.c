#include "v10_2_machine.h"
#include "js_v10_2_scpu_dispatch.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned failures;
#define CHECK(expr) do { if (!(expr)) { \
    fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #expr); failures++; \
} } while (0)

static JSV10_2Machine *make_machine(uint8_t **rom_out) {
    JSV10_2Machine *machine = (JSV10_2Machine *)calloc(1u, sizeof(*machine));
    uint8_t *rom = (uint8_t *)calloc(JSV10_2_ROM_SIZE, 1u);
    if (!machine || !rom) exit(2);
    rom[0x7FFCu] = 0x00u;
    rom[0x7FFDu] = 0x80u;
    rom[0] = 0x5Cu; rom[1] = 0x0Cu; rom[2] = 0x80u; rom[3] = 0x80u;
    CHECK(js_v10_2_power_on(machine, rom, JSV10_2_ROM_SIZE, NULL));
    *rom_out = rom;
    return machine;
}

static void destroy_machine(JSV10_2Machine *machine, uint8_t *rom) {
    js_v10_2_shutdown(machine);
    free(rom);
    free(machine);
}

static void test_complete_lorom_mapping(void) {
    uint32_t offset = 0u;
    CHECK(js_v10_2_classify(0x008000u) == JSV10_2_REGION_ROM);
    CHECK(js_v10_2_classify(0x408000u) == JSV10_2_REGION_ROM);
    CHECK(js_v10_2_classify(0xC08000u) == JSV10_2_REGION_ROM);
    CHECK(js_v10_2_classify(0x400000u) == JSV10_2_REGION_OPEN_BUS);
    CHECK(js_v10_2_classify(0x700000u) == JSV10_2_REGION_OPEN_BUS);
    CHECK(js_v10_2_classify(0xF00000u) == JSV10_2_REGION_OPEN_BUS);
    CHECK(js_v10_2_classify(0x7E8000u) == JSV10_2_REGION_WRAM);
    CHECK(js_v10_2_lorom_offset(0x008000u, &offset) && offset == 0u);
    CHECK(js_v10_2_lorom_offset(0x808000u, &offset) && offset == 0u);
    CHECK(js_v10_2_lorom_offset(0x408000u, &offset) && offset == 0u);
    CHECK(js_v10_2_lorom_offset(0x418000u, &offset) && offset == 0x8000u);
    CHECK(js_v10_2_lorom_offset(0x608000u, &offset) && offset == 0u);
    CHECK(!js_v10_2_lorom_offset(0x400000u, &offset));
    CHECK(!js_v10_2_lorom_offset(0x700000u, &offset));
    CHECK(!js_v10_2_lorom_offset(0x000000u, &offset));
    CHECK(!js_v10_2_lorom_offset(0x7E8000u, &offset));
    CHECK(js_v10_2_access_clocks(0x808000u, 0u) == 8u);
    CHECK(js_v10_2_access_clocks(0x808000u, 1u) == 6u);
}

static void test_power_bus_and_first_static_step(void) {
    uint8_t *rom, value = 0u;
    JSV10_2Machine *m = make_machine(&rom);
    JSV10_2Stop stop;
    uint64_t before;
    CHECK(m->cpu.pc == 0x8000u && m->cpu.pbr == 0u && m->cpu.e == 1u);
    CHECK(m->scheduler.master_clock == JSV10_2_RESET_STARTUP_CLOCKS);
    CHECK(js_v10_2_write8(m, 0x7E1234u, 0x66u, &stop));
    CHECK(js_v10_2_read8(m, 0x001234u, &value, &stop) && value == 0x66u);
    CHECK(js_v10_2_write8(m, 0x002181u, 0x34u, &stop));
    CHECK(js_v10_2_write8(m, 0x002182u, 0x12u, &stop));
    CHECK(js_v10_2_write8(m, 0x002183u, 0x01u, &stop));
    CHECK(js_v10_2_write8(m, 0x002180u, 0xABu, &stop));
    CHECK(m->wram[0x11234u] == 0xABu && m->wram_position == 0x11235u);
    before = m->scheduler.master_clock;
    CHECK(js_v10_2_step(m, &stop) == JS_EXEC_OK);
    CHECK(m->cpu.pbr == 0x80u && m->cpu.pc == 0x800Cu);
    CHECK(m->scheduler.cpu_cycle_count >= 4u);
    CHECK(m->scheduler.master_clock > before);
    destroy_machine(m, rom);
}

static void test_controller_serial_and_autojoy(void) {
    uint8_t *rom, value = 0u;
    JSV10_2Machine *m = make_machine(&rom);
    JSV10_2Stop stop;
    unsigned bit;
    const uint16_t state = 0xA501u;
    js_v10_2_set_controller_state(m, 0u, state);
    CHECK(js_v10_2_write8(m, 0x004016u, 1u, &stop));
    CHECK(js_v10_2_write8(m, 0x004016u, 0u, &stop));
    for (bit = 0u; bit < 16u; ++bit) {
        CHECK(js_v10_2_read8(m, 0x004016u, &value, &stop));
        CHECK((value & 1u) == ((state >> (15u - bit)) & 1u));
    }

    m->scheduler.enable_autojoy = 1u;
    m->scheduler.scanline = 224u;
    m->scheduler.hclock = 1358u;
    m->scheduler.next_primary_event = JSV10_2_EVENT_END_SCANLINE;
    m->scheduler.next_primary_clock = 1360u;
    js_v10_2_scheduler_advance_wall(&m->scheduler, 6u);
    js_v10_2_scheduler_advance_wall(&m->scheduler, 5000u);
    CHECK(m->scheduler.autojoy_active == 0u);
    CHECK(m->scheduler.controller_data[0] == state);
    CHECK(m->scheduler.controller_data[1] == 0u);
    destroy_machine(m, rom);
}

static void test_dma_register_file_and_ppu_storage(void) {
    uint8_t *rom;
    JSV10_2Machine *m = make_machine(&rom);
    JSV10_2Stop stop;
    unsigned channel;
    for (channel = 0u; channel < 8u; ++channel) {
        uint16_t base = (uint16_t)(0x4300u + channel * 0x10u);
        CHECK(js_v10_2_dma_register_write(m, base, (uint8_t)(0x81u | channel)));
        CHECK(js_v10_2_dma_register_write(m, (uint16_t)(base + 1u), (uint8_t)(0x18u + channel)));
        CHECK(js_v10_2_dma_register_write(m, (uint16_t)(base + 2u), 0x34u));
        CHECK(js_v10_2_dma_register_write(m, (uint16_t)(base + 3u), 0x12u));
        CHECK(js_v10_2_dma_register_read(m, base) == (uint8_t)(0x81u | channel));
        CHECK(js_v10_2_dma_register_read(m, (uint16_t)(base + 1u)) == (uint8_t)(0x18u + channel));
        CHECK(js_v10_2_dma_register_read(m, (uint16_t)(base + 2u)) == 0x34u);
        CHECK(js_v10_2_dma_register_read(m, (uint16_t)(base + 3u)) == 0x12u);
    }
    CHECK(js_v10_2_write8(m, 0x002105u, 0x07u, &stop));
    CHECK(m->ppu.bg_mode == 7u);
    CHECK(js_v10_2_write8(m, 0x002100u, 0x8Fu, &stop));
    CHECK(m->ppu.forced_blank == 1u && m->ppu.brightness == 15u);
    destroy_machine(m, rom);
}

static void test_native_interrupt_entry_is_admitted(void) {
    uint8_t *rom;
    JSV10_2Machine *m = make_machine(&rom);
    JSV10_2Stop stop;
    rom[0x7FEAu] = 0x66u;
    rom[0x7FEBu] = 0x81u;
    m->cpu.pbr = 0x80u; m->cpu.pc = 0x800Cu; m->cpu.e = 0u;
    m->cpu.p = (uint8_t)(JS_P_I | JS_P_M | JS_P_X);
    m->cpu.s = 0x01FFu;
    m->scheduler.nmi_pending = 1u;
    CHECK(js_v10_2_step(m, &stop) == JS_EXEC_OK);
    CHECK(m->cpu.pbr == 0u && m->cpu.pc == 0x8166u);
    CHECK(m->cpu.s == 0x01FBu);
    CHECK(js_v10_2_scpu_has_context(&m->cpu));
    destroy_machine(m, rom);
}

static void test_natural_scanline_and_frame_publication(void) {
    uint8_t *rom, pixel[2] = {0xFFu, 0xFFu};
    JSV10_2Machine *m = make_machine(&rom);
    m->ppu.forced_blank = 0u;
    m->ppu.brightness = 15u;
    m->ppu.registers[0] = 0x0Fu;
    m->ppu.cgram[0] = 0x1234u;
    m->scheduler.scanline = 1u;
    m->scheduler.hclock = (uint16_t)(JSV10_2_RENDER_HCLOCK - 2u);
    m->scheduler.next_primary_event = JSV10_2_EVENT_HDMA_LINE;
    m->scheduler.next_primary_clock = JSV10_2_HDMA_LINE_HCLOCK;
    js_v10_2_scheduler_advance_wall(&m->scheduler, 2u);
    CHECK(m->scanlines_rendered == 1u);
    CHECK(m->ppu.framebuffer[0] == 0x34u && m->ppu.framebuffer[1] == 0x12u);
    CHECK(js_v10_2_read_frame_bgr555(m, 0u, pixel, sizeof(pixel)));
    CHECK(pixel[0] == 0u && pixel[1] == 0u);

    m->scheduler.scanline = 224u;
    m->scheduler.hclock = (uint16_t)(JSV10_2_RENDER_HCLOCK - 2u);
    m->scheduler.next_primary_event = JSV10_2_EVENT_HDMA_LINE;
    m->scheduler.next_primary_clock = JSV10_2_HDMA_LINE_HCLOCK;
    pixel[0] = pixel[1] = 0u;
    js_v10_2_scheduler_advance_wall(&m->scheduler, 2u);
    CHECK(m->scanlines_rendered == 2u);
    CHECK(m->ppu.framebuffer[223u * JSV10_2_FRAME_WIDTH * 2u] == 0x34u);
    CHECK(m->ppu.framebuffer[223u * JSV10_2_FRAME_WIDTH * 2u + 1u] == 0x12u);

    m->scheduler.scanline = 224u;
    m->scheduler.hclock = 1358u;
    m->scheduler.next_primary_event = JSV10_2_EVENT_END_SCANLINE;
    m->scheduler.next_primary_clock = 1360u;
    js_v10_2_scheduler_advance_wall(&m->scheduler, 6u);
    CHECK(js_v10_2_frame_ready(m));
    CHECK(js_v10_2_frame_sequence(m) == 1u);
    pixel[0] = pixel[1] = 0u;
    CHECK(js_v10_2_read_frame_bgr555(m, 0u, pixel, sizeof(pixel)));
    CHECK(pixel[0] == 0x34u && pixel[1] == 0x12u);
    m->ppu.framebuffer[0] = 0xAAu;
    m->ppu.framebuffer[1] = 0x55u;
    pixel[0] = pixel[1] = 0u;
    CHECK(js_v10_2_read_frame_bgr555(m, 0u, pixel, sizeof(pixel)));
    CHECK(pixel[0] == 0x34u && pixel[1] == 0x12u);
    js_v10_2_frame_acknowledge(m);
    CHECK(!js_v10_2_frame_ready(m));
    destroy_machine(m, rom);
}

static void test_jsl_deferred_bank_fetch_uses_source_pc(void) {
    uint8_t *rom;
    JSV10_2Machine *m = make_machine(&rom);
    JSV10_2Stop stop;
    rom[0x003Cu] = 0x22u;
    rom[0x003Du] = 0xF1u;
    rom[0x003Eu] = 0xEFu;
    rom[0x003Fu] = 0x92u;
    rom[0x0043u] = 0x99u;
    m->cpu.pbr = 0x80u;
    m->cpu.pc = 0x803Cu;
    m->cpu.e = 0u;
    m->cpu.p = (uint8_t)(JS_P_I | JS_P_M | JS_P_X);
    m->cpu.s = 0x01FFu;
    CHECK(js_v10_2_step(m, &stop) == JS_EXEC_OK);
    CHECK(m->cpu.pbr == 0x92u && m->cpu.pc == 0xEFF1u);
    CHECK(m->cpu.s == 0x01FCu);
    destroy_machine(m, rom);
}

static void test_pending_device_stop_is_sticky_and_reported(void) {
    uint8_t *rom;
    JSV10_2Machine *m = make_machine(&rom);
    JSV10_2Stop stop;
    m->pending_bus_stop = JSV10_2_STOP_APU_PROTOCOL;
    m->pending_bus_address = 0x002140u;
    m->pending_bus_value = 0x5Au;
    CHECK(js_v10_2_step(m, &stop) == JS_EXEC_STOP);
    CHECK(stop.reason == JSV10_2_STOP_APU_PROTOCOL);
    CHECK(stop.address == 0x002140u && stop.value == 0x5Au);
    CHECK(m->pending_bus_stop == JSV10_2_STOP_APU_PROTOCOL);
    destroy_machine(m, rom);
}

int main(void) {
    test_complete_lorom_mapping();
    test_power_bus_and_first_static_step();
    test_controller_serial_and_autojoy();
    test_dma_register_file_and_ppu_storage();
    test_native_interrupt_entry_is_admitted();
    test_natural_scanline_and_frame_publication();
    test_jsl_deferred_bank_fetch_uses_source_pc();
    test_pending_device_stop_is_sticky_and_reported();
    if (failures) fprintf(stderr, "V10.2 machine failures: %u\n", failures);
    return failures ? 1 : 0;
}
