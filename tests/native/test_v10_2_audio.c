#include "v10_2_apu.h"

#include <stdio.h>
#include <string.h>

static unsigned failures;
static uint64_t sink_frames;

#define CHECK(expr) do { if (!(expr)) { \
    fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #expr); failures++; \
} } while (0)

static void count_sample(void *context, int16_t left, int16_t right) {
    uint64_t *count = (uint64_t *)context;
    (void)left;
    (void)right;
    (*count)++;
}

static void test_ipl_clock_and_pcm(void) {
    JSV10_2Apu apu;
    uint8_t port0 = 0u, port1 = 0u;
    const uint64_t master = UINT64_C(1000000);
    const uint64_t expected_cycles = (master * UINT64_C(15664)) / UINT64_C(328125);

    memset(&apu, 0, sizeof(apu));
    sink_frames = 0u;
    js_v10_2_apu_set_sink(count_sample, &sink_frames);
    CHECK(js_v10_2_apu_power_on(&apu));
    CHECK(apu.clock_ratio_numerator == 15664u);
    CHECK(apu.clock_ratio_denominator == 328125u);
    CHECK(js_v10_2_apu_sync(&apu, master) == JSV10_2_APU_OK);
    CHECK(apu.last_master_clock == master);
    CHECK(apu.smp_cycles == expected_cycles);
    CHECK(apu.clock_remainder == (uint32_t)((master * UINT64_C(15664)) % UINT64_C(328125)));
    CHECK(apu.smp_instructions > 0u);
    CHECK(apu.validated_instructions == apu.smp_instructions);
    CHECK(apu.pcm_frames > 0u);
    CHECK(apu.pcm_known_frames + apu.pcm_unknown_frames == apu.pcm_frames);
    CHECK(apu.pcm_unknown_frames == 0u);
    CHECK(sink_frames == apu.pcm_frames);
    CHECK(apu.sdsp_primitive_steps > 0u);
    CHECK(apu.code_write_barriers == 0u);
    CHECK(!apu.failed);

    CHECK(js_v10_2_apu_cpu_read(&apu, 0u, &port0) == JSV10_2_APU_OK);
    CHECK(js_v10_2_apu_cpu_read(&apu, 1u, &port1) == JSV10_2_APU_OK);
    CHECK(port0 == 0xAAu);
    CHECK(port1 == 0xBBu);
    js_v10_2_apu_shutdown(&apu);
}

static void test_monotonicity_ports_and_reset(void) {
    JSV10_2Apu apu;
    uint8_t value = 0u;
    memset(&apu, 0, sizeof(apu));
    CHECK(js_v10_2_apu_power_on(&apu));
    CHECK(js_v10_2_apu_sync(&apu, 200000u) == JSV10_2_APU_OK);
    CHECK(js_v10_2_apu_cpu_write(&apu, 0u, 0xCCu) == JSV10_2_APU_OK);
    CHECK(js_v10_2_apu_cpu_read(&apu, 0u, &value) == JSV10_2_APU_OK);
    CHECK(js_v10_2_apu_sync(&apu, 199998u) == JSV10_2_APU_PROTOCOL_ERROR);
    CHECK(js_v10_2_apu_reset(&apu));
    CHECK(apu.last_master_clock == 0u);
    CHECK(apu.smp_cycles == 0u);
    CHECK(apu.smp_instructions == 0u);
    CHECK(apu.pcm_frames == 0u);
    CHECK(apu.pcm_known_frames == 0u);
    CHECK(apu.pcm_unknown_frames == 0u);
    CHECK(apu.entry_pc == 0xFFC0u);
    CHECK(!apu.failed);
    js_v10_2_apu_shutdown(&apu);
}

static void test_single_owner_is_fail_closed_and_recoverable(void) {
    JSV10_2Apu first, second;
    memset(&first, 0, sizeof(first));
    memset(&second, 0, sizeof(second));
    CHECK(js_v10_2_apu_power_on(&first));
    CHECK(!js_v10_2_apu_power_on(&second));
    CHECK(second.failed);
    CHECK(strstr(second.last_error, "one V10.2 static APU owner") != NULL);
    CHECK(js_v10_2_apu_sync(&first, 100000u) == JSV10_2_APU_OK);
    js_v10_2_apu_shutdown(&first);
    CHECK(js_v10_2_apu_power_on(&second));
    js_v10_2_apu_shutdown(&second);
}

int main(void) {
    test_ipl_clock_and_pcm();
    test_monotonicity_ports_and_reset();
    test_single_owner_is_fail_closed_and_recoverable();
    if (failures) fprintf(stderr, "V10.2 audio failures: %u\n", failures);
    return failures ? 1 : 0;
}
