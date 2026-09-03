#ifndef ROCKNROLL_V08C_MACHINE_H
#define ROCKNROLL_V08C_MACHINE_H

#include <stddef.h>
#include <stdint.h>
#include "v05c_static_cpu.h"
#include "js_v07c_timing.h"

#ifdef __cplusplus
extern "C" {
#endif

#define JSV08_ROM_SIZE 0x100000u
#define JSV08_WRAM_SIZE 0x20000u
#define JSV08_NTSC_MASTER_CLOCK 21477270u
#define JSV08_SMP_RATIO_NUM 2048000u
#define JSV08_SMP_RATIO_DEN 21477270u
#define JSV08_NORMAL_SCANLINE_CLOCKS 1364u
#define JSV08_SHORT_SCANLINE_CLOCKS 1360u
#define JSV08_DRAM_REFRESH_CLOCKS 40u
#define JSV08_HDMA_LINE_HCLOCK 1104u
#define JSV08_RESET_STARTUP_CLOCKS 186u

typedef enum JSV08Region {
    JSV08_REGION_OPEN_BUS=0, JSV08_REGION_ROM=1, JSV08_REGION_WRAM=2,
    JSV08_REGION_PPU=3, JSV08_REGION_APU=4, JSV08_REGION_WRAM_PORT=5,
    JSV08_REGION_CPU_IO=6, JSV08_REGION_INPUT=7, JSV08_REGION_DMA=8
} JSV08Region;

typedef enum JSV08PrimaryEvent {
    JSV08_EVENT_HDMA_INIT=0, JSV08_EVENT_DRAM_REFRESH=1,
    JSV08_EVENT_HDMA_LINE=2, JSV08_EVENT_END_SCANLINE=3
} JSV08PrimaryEvent;

typedef enum JSV08CpuStop {
    JSV08_CPU_RUNNING=0, JSV08_CPU_WAI=1, JSV08_CPU_STP=2
} JSV08CpuStop;

typedef enum JSV08DmaRendezvous {
    JSV08_DMA_NONE=0, JSV08_DMA_MANUAL=1,
    JSV08_DMA_HDMA_INIT=2, JSV08_DMA_HDMA_LINE=3
} JSV08DmaRendezvous;

typedef enum JSV08StopReason {
    JSV08_STOP_NONE=0,
    JSV08_STOP_PPU_UNAVAILABLE=1, JSV08_STOP_APU_UNAVAILABLE=2,
    JSV08_STOP_DMA_BBUS_UNAVAILABLE=3, JSV08_STOP_INPUT_V11=4,
    JSV08_STOP_ROM_WRITE=5, JSV08_STOP_STATIC_CODE_MISMATCH=6,
    JSV08_STOP_UNKNOWN_CONTEXT=7, JSV08_STOP_V05=8,
    JSV08_STOP_INVALID_MACHINE=9, JSV08_STOP_UNPROVED_DYNAMIC_TARGET=10,
    JSV08_STOP_UNPROVED_RETURN=11, JSV08_STOP_UNADMITTED_INTERRUPT_TARGET=12,
    JSV08_STOP_TIMING_PLAN_MISMATCH=13
} JSV08StopReason;

typedef struct JSV08Alu {
    uint8_t mult_operand1, mult_operand2, divisor;
    uint16_t mult_or_remainder, dividend, div_result;
    uint32_t shift;
    uint8_t mult_counter, div_counter;
    uint64_t prev_cpu_cycle;
} JSV08Alu;

typedef struct JSV08Scheduler {
    uint64_t master_clock;
    uint16_t hclock, scanline;
    uint8_t field_odd;
    uint64_t frame_number;
    uint8_t overscan, interlace, forced_blank;
    uint16_t dram_refresh_position, next_primary_clock;
    JSV08PrimaryEvent next_primary_event;

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
    JSV08CpuStop cpu_stop;
    JSV08DmaRendezvous dma_request, dma_rendezvous_ready;
    uint8_t dma_start_delay, dma_pending_mask, hdma_enable_mask, manual_dma_mask;

    uint64_t smp_target_cycle;
    uint32_t smp_target_remainder;
    uint64_t event_digest;
    uint64_t event_count;
} JSV08Scheduler;

typedef struct JSV08Stop {
    JSV08StopReason reason;
    uint32_t address, source_key, observed_key;
    uint8_t value;
    uint64_t master_clock;
    uint16_t scanline, hclock;
    JSStop v05;
} JSV08Stop;

typedef struct JSV08ExecTiming {
    const JSV07TimingPlan *plan;
    JSCPU before;
    uint64_t start_cpu_cycles;
    uint8_t read_count, write_count;
    uint8_t pointer_lo, pointer_hi, pointer_bytes_seen;
    uint8_t pre_access_idle_done, index_idle_done, rmw_idle_done;
    uint8_t pre_stack_idle_done, jsl_deferred_done;
} JSV08ExecTiming;

typedef struct JSV08DmaChannel {
    uint16_t src_address, transfer_size, hdma_table_address;
    uint8_t src_bank, dest_address, dma_active;
    uint8_t invert_direction, decrement, fixed_transfer, hdma_indirect;
    uint8_t transfer_mode, hdma_bank, line_counter_repeat;
    uint8_t do_transfer, hdma_finished, unused_control, unused_register;
} JSV08DmaChannel;

typedef struct JSV08DmaController {
    JSV08DmaChannel channel[8];
    uint8_t hdma_channels, active_channel;
    uint64_t dma_clock_counter, transfer_bytes, bus_cycles, wram_restrictions;
} JSV08DmaController;

typedef int (*JSV08PpuDmaRead)(void *opaque, uint16_t address, uint8_t *value);
typedef int (*JSV08PpuDmaWrite)(void *opaque, uint16_t address, uint8_t value);

typedef struct JSV08Machine {
    JSCPU cpu;
    const uint8_t *rom;
    size_t rom_size;
    uint8_t wram[JSV08_WRAM_SIZE];
    uint32_t wram_position;
    uint8_t open_bus, memsel, io_port_output;
    JSV08Alu alu;
    JSV08Scheduler scheduler;
    JSV08ExecTiming timing;
    JSV08DmaController dma;
    JSV08PpuDmaRead ppu_dma_read;
    JSV08PpuDmaWrite ppu_dma_write;
    void *ppu_dma_opaque;
    JSV08StopReason pending_bus_stop;
    uint32_t pending_bus_address;
    uint8_t pending_bus_value;
} JSV08Machine;

JSV08Region js_v08c_classify(uint32_t address);
int js_v08c_lorom_offset(uint32_t address, uint32_t *offset);
int js_v08c_wram_offset(uint32_t address, uint32_t *offset);
uint8_t js_v08c_access_clocks(uint32_t address, uint8_t memsel);
uint8_t js_v08c_peek8(const JSV08Machine *m, uint32_t address);
uint16_t js_v08c_reset_vector(const JSV08Machine *m);

void js_v08c_scheduler_init(JSV08Scheduler *s);
void js_v08c_scheduler_reset_cpu_side(JSV08Scheduler *s);
void js_v08c_scheduler_advance_wall(JSV08Scheduler *s, uint32_t clocks);
void js_v08c_scheduler_internal_cycle(JSV08Machine *m);
void js_v08c_scheduler_set_display(JSV08Scheduler *s, int overscan, int interlace);
void js_v08c_wai(JSV08Machine *m);
void js_v08c_stp(JSV08Machine *m);
void js_v08c_halted_quantum(JSV08Machine *m);

void js_v08c_set_ppu_dma_seam(JSV08Machine *m, JSV08PpuDmaRead read_cb, JSV08PpuDmaWrite write_cb, void *opaque);
uint8_t js_v08c_dma_register_read(const JSV08Machine *m, uint16_t address);
int js_v08c_dma_register_write(JSV08Machine *m, uint16_t address, uint8_t value);
int js_v08c_power_on(JSV08Machine *m, const uint8_t *rom, size_t rom_size, const uint8_t *initial_wram);
int js_v08c_reset(JSV08Machine *m);
int js_v08c_read8(JSV08Machine *m, uint32_t address, uint8_t *out, JSV08Stop *stop);
int js_v08c_write8(JSV08Machine *m, uint32_t address, uint8_t value, JSV08Stop *stop);
JSExecResult js_v08c_step(JSV08Machine *m, JSV08Stop *stop);
void js_v08c_stop_clear(JSV08Stop *stop);

#ifdef __cplusplus
}
#endif
#endif
