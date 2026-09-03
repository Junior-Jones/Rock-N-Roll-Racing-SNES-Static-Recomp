#ifndef ROCKNROLL_V10_2_MACHINE_H
#define ROCKNROLL_V10_2_MACHINE_H

#include <stddef.h>
#include <stdint.h>
#include "v05c_static_cpu.h"
#include "js_v10_2_timing.h"
#include "v10_2_ppu.h"
#include "v10_2_apu.h"

#ifdef __cplusplus
extern "C" {
#endif

#define JSV10_2_ROM_SIZE 0x100000u
#define JSV10_2_WRAM_SIZE 0x20000u
#define JSV10_2_NTSC_MASTER_CLOCK 21477270u
#define JSV10_2_SMP_RATIO_NUM 15664u
#define JSV10_2_SMP_RATIO_DEN 328125u
#define JSV10_2_NORMAL_SCANLINE_CLOCKS 1364u
#define JSV10_2_SHORT_SCANLINE_CLOCKS 1360u
#define JSV10_2_DRAM_REFRESH_CLOCKS 40u
#define JSV10_2_RENDER_HCLOCK 1080u
#define JSV10_2_HDMA_LINE_HCLOCK 1104u
#define JSV10_2_RESET_STARTUP_CLOCKS 186u

typedef enum JSV10_2Region {
    JSV10_2_REGION_OPEN_BUS=0, JSV10_2_REGION_ROM=1, JSV10_2_REGION_WRAM=2,
    JSV10_2_REGION_PPU=3, JSV10_2_REGION_APU=4, JSV10_2_REGION_WRAM_PORT=5,
    JSV10_2_REGION_CPU_IO=6, JSV10_2_REGION_INPUT=7, JSV10_2_REGION_DMA=8
} JSV10_2Region;

typedef enum JSV10_2PrimaryEvent {
    JSV10_2_EVENT_HDMA_INIT=0, JSV10_2_EVENT_DRAM_REFRESH=1,
    JSV10_2_EVENT_HDMA_LINE=2, JSV10_2_EVENT_END_SCANLINE=3
} JSV10_2PrimaryEvent;

typedef enum JSV10_2CpuStop {
    JSV10_2_CPU_RUNNING=0, JSV10_2_CPU_WAI=1, JSV10_2_CPU_STP=2
} JSV10_2CpuStop;

typedef enum JSV10_2DmaRendezvous {
    JSV10_2_DMA_NONE=0, JSV10_2_DMA_MANUAL=1,
    JSV10_2_DMA_HDMA_INIT=2, JSV10_2_DMA_HDMA_LINE=3
} JSV10_2DmaRendezvous;

typedef enum JSV10_2StopReason {
    JSV10_2_STOP_NONE=0,
    JSV10_2_STOP_PPU_RENDERER_V10=1, JSV10_2_STOP_SMP_AOT_REQUIRED=2,
    JSV10_2_STOP_PPU_UNKNOWN_STATE=3, JSV10_2_STOP_INPUT_V11=4,
    JSV10_2_STOP_ROM_WRITE=5, JSV10_2_STOP_STATIC_CODE_MISMATCH=6,
    JSV10_2_STOP_UNKNOWN_CONTEXT=7, JSV10_2_STOP_V05=8,
    JSV10_2_STOP_INVALID_MACHINE=9, JSV10_2_STOP_UNPROVED_DYNAMIC_TARGET=10,
    JSV10_2_STOP_UNPROVED_RETURN=11, JSV10_2_STOP_UNADMITTED_INTERRUPT_TARGET=12,
    JSV10_2_STOP_TIMING_PLAN_MISMATCH=13, JSV10_2_STOP_APU_PROTOCOL=14,
    JSV10_2_STOP_DMA_BBUS_UNAVAILABLE=15
} JSV10_2StopReason;

typedef struct JSV10_2Alu {
    uint8_t mult_operand1, mult_operand2, divisor;
    uint16_t mult_or_remainder, dividend, div_result;
    uint32_t shift;
    uint8_t mult_counter, div_counter;
    uint64_t prev_cpu_cycle;
} JSV10_2Alu;

typedef struct JSV10_2Scheduler {
    void *owner;
    uint64_t master_clock;
    uint16_t hclock, scanline;
    uint8_t field_odd;
    uint64_t frame_number;
    uint8_t overscan, interlace, forced_blank;
    uint16_t dram_refresh_position, next_primary_clock;
    JSV10_2PrimaryEvent next_primary_event;

    uint8_t enable_nmi, enable_hirq, enable_virq, enable_autojoy;
    uint16_t htimer, vtimer, hcounter, vcounter;
    uint8_t nmi_flag, nmi_signal, nmi_pending;
    uint8_t irq_level, need_irq, irq_flag, irq_source;

    uint64_t autojoy_clock_start, autojoy_next_clock;
    uint8_t autojoy_active, autojoy_disabled, autojoy_strobe;
    int8_t autojoy_step;
    uint16_t controller_data[4];
    uint16_t controller_state[2], controller_shift[2], autojoy_shift[2];
    uint8_t controller_strobe;

    uint64_t cpu_cycle_count;
    JSV10_2CpuStop cpu_stop;
    JSV10_2DmaRendezvous dma_request, dma_rendezvous_ready;
    uint8_t dma_start_delay, dma_pending_mask, hdma_enable_mask, manual_dma_mask;

    uint64_t event_digest;
    uint64_t event_count;
} JSV10_2Scheduler;

typedef struct JSV10_2Stop {
    JSV10_2StopReason reason;
    uint32_t address, source_key, observed_key;
    uint8_t value;
    uint64_t master_clock;
    uint16_t scanline, hclock, smp_pc;
    JSStop v05;
} JSV10_2Stop;

typedef struct JSV10_2ExecTiming {
    const JSV10_2TimingPlan *plan;
    JSCPU before;
    uint64_t start_cpu_cycles;
    uint8_t read_count, write_count;
    uint8_t pointer_lo, pointer_hi, pointer_bytes_seen;
    uint8_t pre_access_idle_done, index_idle_done, rmw_idle_done;
    uint8_t pre_stack_idle_done, jsl_deferred_done, block_post_idle_done;
} JSV10_2ExecTiming;

typedef struct JSV10_2DmaChannel {
    uint16_t src_address, transfer_size, hdma_table_address;
    uint8_t src_bank, dest_address, dma_active;
    uint8_t invert_direction, decrement, fixed_transfer, hdma_indirect;
    uint8_t transfer_mode, hdma_bank, line_counter_repeat;
    uint8_t do_transfer, hdma_finished, unused_control, unused_register;
} JSV10_2DmaChannel;

typedef struct JSV10_2DmaController {
    JSV10_2DmaChannel channel[8];
    uint8_t hdma_channels, active_channel;
    uint64_t dma_clock_counter, transfer_bytes, bus_cycles, wram_restrictions;
} JSV10_2DmaController;

typedef struct JSV10_2Machine {
    JSCPU cpu;
    const uint8_t *rom;
    size_t rom_size;
    uint8_t wram[JSV10_2_WRAM_SIZE];
    uint32_t wram_position;
    uint8_t open_bus, memsel, io_port_output;
    JSV10_2Alu alu;
    JSV10_2Scheduler scheduler;
    JSV10_2ExecTiming timing;
    JSV10_2DmaController dma;
    JSV10_2Ppu ppu;
    JSV10_2Apu apu;
    uint8_t published_framebuffer[JSV10_2_FRAME_BYTES];
    uint64_t frame_sequence;
    uint16_t scanlines_rendered;
    uint8_t frame_ready;
    JSV10_2StopReason pending_bus_stop;
    uint32_t pending_bus_address;
    uint8_t pending_bus_value;
} JSV10_2Machine;

JSV10_2Region js_v10_2_classify(uint32_t address);
int js_v10_2_lorom_offset(uint32_t address, uint32_t *offset);
int js_v10_2_wram_offset(uint32_t address, uint32_t *offset);
uint8_t js_v10_2_access_clocks(uint32_t address, uint8_t memsel);
uint8_t js_v10_2_peek8(const JSV10_2Machine *m, uint32_t address);
uint16_t js_v10_2_reset_vector(const JSV10_2Machine *m);

void js_v10_2_scheduler_init(JSV10_2Scheduler *s);
void js_v10_2_scheduler_reset_cpu_side(JSV10_2Scheduler *s);
void js_v10_2_scheduler_advance_wall(JSV10_2Scheduler *s, uint32_t clocks);
void js_v10_2_scheduler_internal_cycle(JSV10_2Machine *m);
void js_v10_2_scheduler_set_display(JSV10_2Scheduler *s, int overscan, int interlace);
void js_v10_2_wai(JSV10_2Machine *m);
void js_v10_2_stp(JSV10_2Machine *m);
void js_v10_2_halted_quantum(JSV10_2Machine *m);
void js_v10_2_set_controller_state(JSV10_2Machine *m, unsigned port, uint16_t state);
int js_v10_2_frame_ready(const JSV10_2Machine *m);
uint64_t js_v10_2_frame_sequence(const JSV10_2Machine *m);
void js_v10_2_frame_acknowledge(JSV10_2Machine *m);
int js_v10_2_read_frame_bgr555(const JSV10_2Machine *m, uint32_t offset, void *out, size_t size);

uint8_t js_v10_2_dma_register_read(const JSV10_2Machine *m, uint16_t address);
int js_v10_2_dma_register_write(JSV10_2Machine *m, uint16_t address, uint8_t value);
int js_v10_2_power_on(JSV10_2Machine *m, const uint8_t *rom, size_t rom_size, const uint8_t *initial_wram);
int js_v10_2_reset(JSV10_2Machine *m);
void js_v10_2_shutdown(JSV10_2Machine *m);
int js_v10_2_read8(JSV10_2Machine *m, uint32_t address, uint8_t *out, JSV10_2Stop *stop);
int js_v10_2_write8(JSV10_2Machine *m, uint32_t address, uint8_t value, JSV10_2Stop *stop);
JSExecResult js_v10_2_step(JSV10_2Machine *m, JSV10_2Stop *stop);
void js_v10_2_stop_clear(JSV10_2Stop *stop);

#ifdef __cplusplus
}
#endif
#endif
