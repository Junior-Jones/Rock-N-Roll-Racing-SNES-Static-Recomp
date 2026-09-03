#ifndef ROCKNROLL_V10_1_MACHINE_H
#define ROCKNROLL_V10_1_MACHINE_H

#include <stddef.h>
#include <stdint.h>
#include "v05c_static_cpu.h"
#include "js_v07c_timing.h"
#include "v09c_ppu.h"
#include "v10_1_apu.h"

#ifdef __cplusplus
extern "C" {
#endif

#define JSV10_1_ROM_SIZE 0x100000u
#define JSV10_1_WRAM_SIZE 0x20000u
#define JSV10_1_NTSC_MASTER_CLOCK 21477270u
#define JSV10_1_SMP_RATIO_NUM 2048000u
#define JSV10_1_SMP_RATIO_DEN 21477270u
#define JSV10_1_NORMAL_SCANLINE_CLOCKS 1364u
#define JSV10_1_SHORT_SCANLINE_CLOCKS 1360u
#define JSV10_1_DRAM_REFRESH_CLOCKS 40u
#define JSV10_1_HDMA_LINE_HCLOCK 1104u
#define JSV10_1_RESET_STARTUP_CLOCKS 186u

typedef enum JSV10_1Region {
    JSV10_1_REGION_OPEN_BUS=0, JSV10_1_REGION_ROM=1, JSV10_1_REGION_WRAM=2,
    JSV10_1_REGION_PPU=3, JSV10_1_REGION_APU=4, JSV10_1_REGION_WRAM_PORT=5,
    JSV10_1_REGION_CPU_IO=6, JSV10_1_REGION_INPUT=7, JSV10_1_REGION_DMA=8
} JSV10_1Region;

typedef enum JSV10_1PrimaryEvent {
    JSV10_1_EVENT_HDMA_INIT=0, JSV10_1_EVENT_DRAM_REFRESH=1,
    JSV10_1_EVENT_HDMA_LINE=2, JSV10_1_EVENT_END_SCANLINE=3
} JSV10_1PrimaryEvent;

typedef enum JSV10_1CpuStop {
    JSV10_1_CPU_RUNNING=0, JSV10_1_CPU_WAI=1, JSV10_1_CPU_STP=2
} JSV10_1CpuStop;

typedef enum JSV10_1DmaRendezvous {
    JSV10_1_DMA_NONE=0, JSV10_1_DMA_MANUAL=1,
    JSV10_1_DMA_HDMA_INIT=2, JSV10_1_DMA_HDMA_LINE=3
} JSV10_1DmaRendezvous;

typedef enum JSV10_1StopReason {
    JSV10_1_STOP_NONE=0,
    JSV10_1_STOP_PPU_RENDERER_V10=1, JSV10_1_STOP_SMP_AOT_REQUIRED=2,
    JSV10_1_STOP_PPU_UNKNOWN_STATE=3, JSV10_1_STOP_INPUT_V11=4,
    JSV10_1_STOP_ROM_WRITE=5, JSV10_1_STOP_STATIC_CODE_MISMATCH=6,
    JSV10_1_STOP_UNKNOWN_CONTEXT=7, JSV10_1_STOP_V05=8,
    JSV10_1_STOP_INVALID_MACHINE=9, JSV10_1_STOP_UNPROVED_DYNAMIC_TARGET=10,
    JSV10_1_STOP_UNPROVED_RETURN=11, JSV10_1_STOP_UNADMITTED_INTERRUPT_TARGET=12,
    JSV10_1_STOP_TIMING_PLAN_MISMATCH=13, JSV10_1_STOP_APU_PROTOCOL=14
} JSV10_1StopReason;

typedef struct JSV10_1Alu {
    uint8_t mult_operand1, mult_operand2, divisor;
    uint16_t mult_or_remainder, dividend, div_result;
    uint32_t shift;
    uint8_t mult_counter, div_counter;
    uint64_t prev_cpu_cycle;
} JSV10_1Alu;

typedef struct JSV10_1Scheduler {
    uint64_t master_clock;
    uint16_t hclock, scanline;
    uint8_t field_odd;
    uint64_t frame_number;
    uint8_t overscan, interlace, forced_blank;
    uint16_t dram_refresh_position, next_primary_clock;
    JSV10_1PrimaryEvent next_primary_event;

    uint8_t enable_nmi, enable_hirq, enable_virq, enable_autojoy;
    uint16_t htimer, vtimer, hcounter, vcounter;
    uint8_t nmi_flag, nmi_signal, nmi_pending;
    uint8_t irq_level, need_irq, irq_flag, irq_source;

    uint64_t autojoy_clock_start, autojoy_next_clock;
    uint8_t autojoy_active, autojoy_disabled, autojoy_strobe;
    int8_t autojoy_step;
    uint16_t controller_data[4];
    uint8_t autojoy_sample_bits[2];

    uint64_t cpu_cycle_count;
    JSV10_1CpuStop cpu_stop;
    JSV10_1DmaRendezvous dma_request, dma_rendezvous_ready;
    uint8_t dma_start_delay, dma_pending_mask, hdma_enable_mask, manual_dma_mask;

    uint64_t smp_target_cycle;
    uint32_t smp_target_remainder;
    uint64_t event_digest;
    uint64_t event_count;
} JSV10_1Scheduler;

typedef struct JSV10_1Stop {
    JSV10_1StopReason reason;
    uint32_t address, source_key, observed_key;
    uint8_t value;
    uint64_t master_clock;
    uint16_t scanline, hclock, smp_pc;
    JSStop v05;
} JSV10_1Stop;

typedef struct JSV10_1ExecTiming {
    const JSV07TimingPlan *plan;
    JSCPU before;
    uint64_t start_cpu_cycles;
    uint8_t read_count, write_count;
    uint8_t pointer_lo, pointer_hi, pointer_bytes_seen;
    uint8_t pre_access_idle_done, index_idle_done, rmw_idle_done;
    uint8_t pre_stack_idle_done, jsl_deferred_done;
} JSV10_1ExecTiming;

typedef struct JSV10_1DmaChannel {
    uint16_t src_address, transfer_size, hdma_table_address;
    uint8_t src_bank, dest_address, dma_active;
    uint8_t invert_direction, decrement, fixed_transfer, hdma_indirect;
    uint8_t transfer_mode, hdma_bank, line_counter_repeat;
    uint8_t do_transfer, hdma_finished, unused_control, unused_register;
} JSV10_1DmaChannel;

typedef struct JSV10_1DmaController {
    JSV10_1DmaChannel channel[8];
    uint8_t hdma_channels, active_channel;
    uint64_t dma_clock_counter, transfer_bytes, bus_cycles, wram_restrictions;
} JSV10_1DmaController;

typedef struct JSV10_1Machine {
    JSCPU cpu;
    const uint8_t *rom;
    size_t rom_size;
    uint8_t wram[JSV10_1_WRAM_SIZE];
    uint32_t wram_position;
    uint8_t open_bus, memsel, io_port_output;
    JSV10_1Alu alu;
    JSV10_1Scheduler scheduler;
    JSV10_1ExecTiming timing;
    JSV10_1DmaController dma;
    JSV09Ppu ppu;
    JSV10_1Apu apu;
    JSV10_1StopReason pending_bus_stop;
    uint32_t pending_bus_address;
    uint8_t pending_bus_value;
} JSV10_1Machine;

JSV10_1Region js_v10_1_classify(uint32_t address);
int js_v10_1_lorom_offset(uint32_t address, uint32_t *offset);
int js_v10_1_wram_offset(uint32_t address, uint32_t *offset);
uint8_t js_v10_1_access_clocks(uint32_t address, uint8_t memsel);
uint8_t js_v10_1_peek8(const JSV10_1Machine *m, uint32_t address);
uint16_t js_v10_1_reset_vector(const JSV10_1Machine *m);

void js_v10_1_scheduler_init(JSV10_1Scheduler *s);
void js_v10_1_scheduler_reset_cpu_side(JSV10_1Scheduler *s);
void js_v10_1_scheduler_advance_wall(JSV10_1Scheduler *s, uint32_t clocks);
void js_v10_1_scheduler_internal_cycle(JSV10_1Machine *m);
void js_v10_1_scheduler_set_display(JSV10_1Scheduler *s, int overscan, int interlace);
void js_v10_1_wai(JSV10_1Machine *m);
void js_v10_1_stp(JSV10_1Machine *m);
void js_v10_1_halted_quantum(JSV10_1Machine *m);

uint8_t js_v10_1_dma_register_read(const JSV10_1Machine *m, uint16_t address);
int js_v10_1_dma_register_write(JSV10_1Machine *m, uint16_t address, uint8_t value);
int js_v10_1_power_on(JSV10_1Machine *m, const uint8_t *rom, size_t rom_size, const uint8_t *initial_wram);
int js_v10_1_reset(JSV10_1Machine *m);
int js_v10_1_read8(JSV10_1Machine *m, uint32_t address, uint8_t *out, JSV10_1Stop *stop);
int js_v10_1_write8(JSV10_1Machine *m, uint32_t address, uint8_t value, JSV10_1Stop *stop);
JSExecResult js_v10_1_step(JSV10_1Machine *m, JSV10_1Stop *stop);
void js_v10_1_stop_clear(JSV10_1Stop *stop);

#ifdef __cplusplus
}
#endif
#endif
