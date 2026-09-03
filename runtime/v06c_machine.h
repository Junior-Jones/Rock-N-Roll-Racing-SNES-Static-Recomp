#ifndef ROCKNROLL_V06C_MACHINE_H
#define ROCKNROLL_V06C_MACHINE_H

#include <stddef.h>
#include <stdint.h>
#include "v05c_static_cpu.h"

#ifdef __cplusplus
extern "C" {
#endif

#define JSV06_ROM_SIZE 0x100000u
#define JSV06_WRAM_SIZE 0x20000u

typedef enum JSV06Region {
    JSV06_REGION_OPEN_BUS=0, JSV06_REGION_ROM=1, JSV06_REGION_WRAM=2,
    JSV06_REGION_PPU=3, JSV06_REGION_APU=4, JSV06_REGION_WRAM_PORT=5,
    JSV06_REGION_CPU_IO=6, JSV06_REGION_INPUT=7, JSV06_REGION_DMA=8
} JSV06Region;

typedef enum JSV06StopReason {
    JSV06_STOP_NONE=0, JSV06_STOP_PPU_UNAVAILABLE=1, JSV06_STOP_APU_UNAVAILABLE=2,
    JSV06_STOP_DMA_UNAVAILABLE=3, JSV06_STOP_INPUT_UNAVAILABLE=4,
    JSV06_STOP_TIMING_UNAVAILABLE=5, JSV06_STOP_ROM_WRITE=6,
    JSV06_STOP_STATIC_CODE_MISMATCH=7, JSV06_STOP_UNKNOWN_CONTEXT=8,
    JSV06_STOP_V05=9, JSV06_STOP_INVALID_MACHINE=10
} JSV06StopReason;

typedef struct JSV06Alu {
    uint8_t mult_operand1, mult_operand2, divisor;
    uint16_t mult_or_remainder, dividend, div_result;
    uint32_t shift;
    uint8_t mult_counter, div_counter;
    uint64_t prev_cpu_cycle;
} JSV06Alu;

typedef struct JSV06Stop {
    JSV06StopReason reason;
    uint32_t address, source_key, observed_key;
    uint8_t value;
    JSStop v05;
} JSV06Stop;

typedef struct JSV06Machine {
    JSCPU cpu;
    const uint8_t *rom;
    size_t rom_size;
    uint8_t wram[JSV06_WRAM_SIZE];
    uint32_t wram_position;
    uint8_t open_bus, memsel, nmitimen, io_port_output;
    uint16_t htimer, vtimer;
    uint64_t access_clock_sum;
    uint64_t cpu_cycle_count;
    JSV06Alu alu;
    JSV06StopReason pending_bus_stop;
    uint32_t pending_bus_address;
    uint8_t pending_bus_value;
} JSV06Machine;

JSV06Region js_v06c_classify(uint32_t address);
int js_v06c_lorom_offset(uint32_t address, uint32_t *offset);
int js_v06c_wram_offset(uint32_t address, uint32_t *offset);
uint8_t js_v06c_access_clocks(uint32_t address, uint8_t memsel);
uint8_t js_v06c_peek8(const JSV06Machine *m, uint32_t address);
uint16_t js_v06c_reset_vector(const JSV06Machine *m);
int js_v06c_power_on(JSV06Machine *m, const uint8_t *rom, size_t rom_size, const uint8_t *initial_wram);
int js_v06c_reset(JSV06Machine *m);
void js_v06c_cpu_internal_cycle(JSV06Machine *m);
int js_v06c_read8(JSV06Machine *m, uint32_t address, uint8_t *out, JSV06Stop *stop);
int js_v06c_write8(JSV06Machine *m, uint32_t address, uint8_t value, JSV06Stop *stop);
JSExecResult js_v06c_step(JSV06Machine *m, JSV06Stop *stop);
void js_v06c_stop_clear(JSV06Stop *stop);

#ifdef __cplusplus
}
#endif
#endif
