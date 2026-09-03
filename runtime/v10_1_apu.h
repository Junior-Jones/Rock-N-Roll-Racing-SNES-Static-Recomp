#ifndef ROCKNROLL_V10_1_APU_H
#define ROCKNROLL_V10_1_APU_H
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
#define JSV10_1_ARAM_SIZE 0x10000u
typedef enum JSV10_1ApuResult {
    JSV10_1_APU_OK=0,
    JSV10_1_APU_AOT_REQUIRED=1,
    JSV10_1_APU_PROTOCOL_ERROR=2
} JSV10_1ApuResult;
typedef enum JSV10_1IplPhase {
    JSV10_1_IPL_WAIT_CC=0,
    JSV10_1_IPL_TRANSFER=1,
    JSV10_1_IPL_RESTART_ACK=2,
    JSV10_1_IPL_AOT_REQUIRED=3
} JSV10_1IplPhase;
typedef struct JSV10_1Apu {
    uint8_t aram[JSV10_1_ARAM_SIZE];
    uint8_t known[JSV10_1_ARAM_SIZE];
    uint8_t cpu_to_smp[4], smp_to_cpu[4];
    JSV10_1IplPhase phase;
    uint16_t destination, entry_pc;
    uint8_t expected_counter;
    uint32_t bytes_written;
    uint64_t last_smp_target_cycle;
} JSV10_1Apu;
void js_v10_1_apu_power_on(JSV10_1Apu *a);
void js_v10_1_apu_reset(JSV10_1Apu *a);
JSV10_1ApuResult js_v10_1_apu_sync(JSV10_1Apu *a, uint64_t smp_target_cycle);
JSV10_1ApuResult js_v10_1_apu_cpu_read(JSV10_1Apu *a, uint8_t port, uint8_t *value);
JSV10_1ApuResult js_v10_1_apu_cpu_write(JSV10_1Apu *a, uint8_t port, uint8_t value);
#ifdef __cplusplus
}
#endif
#endif
