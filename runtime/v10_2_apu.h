#ifndef ROCKNROLL_V10_2_APU_H
#define ROCKNROLL_V10_2_APU_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum JSV10_2ApuResult {
    JSV10_2_APU_OK = 0,
    JSV10_2_APU_AOT_REQUIRED = 1,
    JSV10_2_APU_PROTOCOL_ERROR = 2
} JSV10_2ApuResult;

typedef void (*JSV10_2AudioSink)(void *context, int16_t left, int16_t right);

typedef struct JSV10_2Apu {
    uint64_t last_master_clock;
    uint64_t smp_cycles;
    uint64_t smp_instructions;
    uint64_t pcm_frames;
    uint64_t pcm_known_frames;
    uint64_t pcm_unknown_frames;
    uint16_t entry_pc;
    uint16_t fail_pc;
    uint32_t clock_ratio_numerator;
    uint32_t clock_ratio_denominator;
    uint32_t clock_remainder;
    int32_t smp_cycle_overshoot;
    uint64_t validated_instructions;
    uint32_t code_write_barriers;
    uint64_t sdsp_primitive_steps;
    uint64_t sdsp_brr_steps;
    uint8_t acquired;
    uint8_t failed;
    uint32_t fail_reason;
    char last_error[224];
} JSV10_2Apu;

int js_v10_2_apu_power_on(JSV10_2Apu *a);
int js_v10_2_apu_reset(JSV10_2Apu *a);
void js_v10_2_apu_shutdown(JSV10_2Apu *a);
JSV10_2ApuResult js_v10_2_apu_sync(JSV10_2Apu *a, uint64_t master_clock);
JSV10_2ApuResult js_v10_2_apu_cpu_read(JSV10_2Apu *a, uint8_t port, uint8_t *value);
JSV10_2ApuResult js_v10_2_apu_cpu_write(JSV10_2Apu *a, uint8_t port, uint8_t value);
void js_v10_2_apu_set_sink(JSV10_2AudioSink sink, void *context);
int js_v10_2_apu_read_aram(uint32_t offset, void *output, size_t bytes);
int js_v10_2_apu_read_dsp_register(uint8_t address, uint8_t *value);
size_t js_v10_2_apu_snapshot_size(void);
int js_v10_2_apu_snapshot_save(const JSV10_2Apu *a, void *data,
                                size_t capacity);
int js_v10_2_apu_snapshot_load(JSV10_2Apu *a, const void *data, size_t size,
                                char *error, size_t error_capacity);

#ifdef __cplusplus
}
#endif
#endif
