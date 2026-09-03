#ifndef ROCKNROLL_V07C_MACHINE_H
#define ROCKNROLL_V07C_MACHINE_H

#include <stddef.h>
#include <stdint.h>
#include "v05c_static_cpu.h"
#include "js_v07c_timing.h"

#ifdef __cplusplus
extern "C" {
#endif

#define JSV07_ROM_SIZE 0x100000u
#define JSV07_WRAM_SIZE 0x20000u
#define JSV07_NTSC_MASTER_CLOCK 21477270u
#define JSV07_SMP_RATIO_NUM 2048000u
#define JSV07_SMP_RATIO_DEN 21477270u
#define JSV07_NORMAL_SCANLINE_CLOCKS 1364u
#define JSV07_SHORT_SCANLINE_CLOCKS 1360u
#define JSV07_DRAM_REFRESH_CLOCKS 40u
#define JSV07_HDMA_LINE_HCLOCK 1104u
#define JSV07_RESET_STARTUP_CLOCKS 186u

typedef enum JSV07Region {
    JSV07_REGION_OPEN_BUS=0, JSV07_REGION_ROM=1, JSV07_REGION_WRAM=2,
    JSV07_REGION_PPU=3, JSV07_REGION_APU=4, JSV07_REGION_WRAM_PORT=5,
    JSV07_REGION_CPU_IO=6, JSV07_REGION_INPUT=7, JSV07_REGION_DMA=8
} JSV07Region;

typedef enum JSV07PrimaryEvent {
    JSV07_EVENT_HDMA_INIT=0, JSV07_EVENT_DRAM_REFRESH=1,
    JSV07_EVENT_HDMA_LINE=2, JSV07_EVENT_END_SCANLINE=3
} JSV07PrimaryEvent;

typedef enum JSV07CpuStop {
    JSV07_CPU_RUNNING=0, JSV07_CPU_WAI=1, JSV07_CPU_STP=2
} JSV07CpuStop;

typedef enum JSV07DmaRendezvous {
    JSV07_DMA_NONE=0, JSV07_DMA_MANUAL=1,
    JSV07_DMA_HDMA_INIT=2, JSV07_DMA_HDMA_LINE=3
} JSV07DmaRendezvous;

typedef enum JSV07StopReason {
    JSV07_STOP_NONE=0,
    JSV07_STOP_PPU_UNAVAILABLE=1, JSV07_STOP_APU_UNAVAILABLE=2,
    JSV07_STOP_DMA_TRANSFER_V08=3, JSV07_STOP_INPUT_V11=4,
    JSV07_STOP_ROM_WRITE=5, JSV07_STOP_STATIC_CODE_MISMATCH=6,
    JSV07_STOP_UNKNOWN_CONTEXT=7, JSV07_STOP_V05=8,
    JSV07_STOP_INVALID_MACHINE=9, JSV07_STOP_UNPROVED_DYNAMIC_TARGET=10,
    JSV07_STOP_UNPROVED_RETURN=11, JSV07_STOP_UNADMITTED_INTERRUPT_TARGET=12,
    JSV07_STOP_TIMING_PLAN_MISMATCH=13
} JSV07StopReason;

typedef struct JSV07Alu {
    uint8_t mult_operand1, mult_operand2, divisor;
    uint16_t mult_or_remainder, dividend, div_result;
    uint32_t shift;
    uint8_t mult_counter, div_counter;
    uint64_t prev_cpu_cycle;
} JSV07Alu;

typedef struct JSV07Scheduler {
    uint64_t master_clock;
    uint16_t hclock, scanline;
    uint8_t field_odd;
    uint64_t frame_number;
    uint8_t overscan, interlace, forced_blank;
    uint16_t dram_refresh_position, next_primary_clock;
    JSV07PrimaryEvent next_primary_event;

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
    JSV07CpuStop cpu_stop;
    JSV07DmaRendezvous dma_request, dma_rendezvous_ready;
    uint8_t dma_start_delay, hdma_enable_mask, manual_dma_mask;

    uint64_t smp_target_cycle;
    uint32_t smp_target_remainder;
    uint64_t event_digest;
    uint64_t event_count;
} JSV07Scheduler;

typedef struct JSV07Stop {
    JSV07StopReason reason;
    uint32_t address, source_key, observed_key;
    uint8_t value;
    uint64_t master_clock;
    uint16_t scanline, hclock;
    JSStop v05;
} JSV07Stop;

typedef struct JSV07ExecTiming {
    const JSV07TimingPlan *plan;
    JSCPU before;
    uint64_t start_cpu_cycles;
    uint8_t read_count, write_count;
    uint8_t pointer_lo, pointer_hi, pointer_bytes_seen;
    uint8_t pre_access_idle_done, index_idle_done, rmw_idle_done;
    uint8_t pre_stack_idle_done, jsl_deferred_done;
} JSV07ExecTiming;

typedef struct JSV07Machine {
    JSCPU cpu;
    const uint8_t *rom;
    size_t rom_size;
    uint8_t wram[JSV07_WRAM_SIZE];
    uint32_t wram_position;
    uint8_t open_bus, memsel, io_port_output;
    JSV07Alu alu;
    JSV07Scheduler scheduler;
    JSV07ExecTiming timing;
    JSV07StopReason pending_bus_stop;
    uint32_t pending_bus_address;
    uint8_t pending_bus_value;
} JSV07Machine;

JSV07Region js_v07c_classify(uint32_t address);
int js_v07c_lorom_offset(uint32_t address, uint32_t *offset);
int js_v07c_wram_offset(uint32_t address, uint32_t *offset);
uint8_t js_v07c_access_clocks(uint32_t address, uint8_t memsel);
uint8_t js_v07c_peek8(const JSV07Machine *m, uint32_t address);
uint16_t js_v07c_reset_vector(const JSV07Machine *m);

void js_v07c_scheduler_init(JSV07Scheduler *s);
void js_v07c_scheduler_reset_cpu_side(JSV07Scheduler *s);
void js_v07c_scheduler_advance_wall(JSV07Scheduler *s, uint32_t clocks);
void js_v07c_scheduler_internal_cycle(JSV07Machine *m);
void js_v07c_scheduler_set_display(JSV07Scheduler *s, int overscan, int interlace);
void js_v07c_wai(JSV07Machine *m);
void js_v07c_stp(JSV07Machine *m);
void js_v07c_halted_quantum(JSV07Machine *m);

int js_v07c_power_on(JSV07Machine *m, const uint8_t *rom, size_t rom_size, const uint8_t *initial_wram);
int js_v07c_reset(JSV07Machine *m);
int js_v07c_read8(JSV07Machine *m, uint32_t address, uint8_t *out, JSV07Stop *stop);
int js_v07c_write8(JSV07Machine *m, uint32_t address, uint8_t value, JSV07Stop *stop);
JSExecResult js_v07c_step(JSV07Machine *m, JSV07Stop *stop);
void js_v07c_stop_clear(JSV07Stop *stop);

#ifdef __cplusplus
}
#endif
#endif
