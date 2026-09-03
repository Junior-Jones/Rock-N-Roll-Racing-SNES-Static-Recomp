#include "v10_2_apu.h"
#include "v10_2_audio/sc_static_apu.h"

#include <cstdio>
#include <cstring>

namespace {
JSV10_2Apu *g_owner = nullptr;

void set_error(JSV10_2Apu *apu, const char *text) {
    if (!apu) return;
    std::snprintf(apu->last_error, sizeof(apu->last_error), "%s", text ? text : "");
}

JSV10_2ApuResult update_status(JSV10_2Apu *apu, bool operation_ok) {
    SCStaticApuStatus status{};
    if (!apu || !sc_static_apu_status(&status)) {
        return JSV10_2_APU_PROTOCOL_ERROR;
    }
    apu->smp_cycles = status.smp_cycles;
    apu->smp_instructions = status.smp_instructions;
    apu->pcm_frames = status.pcm_frames;
    apu->pcm_known_frames = status.pcm_known_frames;
    apu->pcm_unknown_frames = status.pcm_unknown_frames;
    apu->entry_pc = status.smp_pc;
    apu->fail_pc = status.aot_fail_pc;
    apu->clock_ratio_numerator = status.clock_ratio_numerator;
    apu->clock_ratio_denominator = status.clock_ratio_denominator;
    apu->clock_remainder = status.clock_remainder;
    apu->smp_cycle_overshoot = status.smp_cycle_overshoot;
    apu->validated_instructions = status.aot_validated_instructions;
    apu->code_write_barriers = status.code_write_barriers;
    apu->sdsp_primitive_steps = status.sdsp_primitive_steps;
    apu->sdsp_brr_steps = status.sdsp_brr_steps;
    apu->failed = static_cast<uint8_t>(status.aot_failed || status.sdsp_static_failed || !operation_ok);
    apu->fail_reason = status.aot_failed ? status.aot_fail_reason : status.sdsp_fail_reason;
    if (status.aot_failed) {
        return JSV10_2_APU_AOT_REQUIRED;
    }
    return operation_ok && !status.sdsp_static_failed ? JSV10_2_APU_OK : JSV10_2_APU_PROTOCOL_ERROR;
}
}

extern "C" int js_v10_2_apu_power_on(JSV10_2Apu *apu) {
    if (!apu) return 0;
    if (g_owner && g_owner != apu) {
        std::memset(apu, 0, sizeof(*apu));
        apu->failed = 1u;
        set_error(apu, "Only one V10.2 static APU owner is supported at a time.");
        return 0;
    }
    std::memset(apu, 0, sizeof(*apu));
    if (!g_owner) {
        if (!sc_static_apu_acquire(apu->last_error, sizeof(apu->last_error))) {
            apu->failed = 1u;
            return 0;
        }
        g_owner = apu;
    } else {
        sc_static_apu_reset();
    }
    apu->acquired = 1u;
    return update_status(apu, true) == JSV10_2_APU_OK;
}

extern "C" int js_v10_2_apu_reset(JSV10_2Apu *apu) {
    if (!apu || g_owner != apu || !apu->acquired) return 0;
    sc_static_apu_reset();
    std::memset(apu, 0, sizeof(*apu));
    apu->acquired = 1u;
    return update_status(apu, true) == JSV10_2_APU_OK;
}

extern "C" void js_v10_2_apu_shutdown(JSV10_2Apu *apu) {
    if (!apu) return;
    if (g_owner == apu) {
        sc_static_apu_release();
        g_owner = nullptr;
    }
    std::memset(apu, 0, sizeof(*apu));
}

extern "C" JSV10_2ApuResult js_v10_2_apu_sync(JSV10_2Apu *apu, uint64_t master_clock) {
    if (!apu || g_owner != apu || !apu->acquired || master_clock < apu->last_master_clock)
        return JSV10_2_APU_PROTOCOL_ERROR;
    const int ok = sc_static_apu_sync_to_master(master_clock, apu->last_error, sizeof(apu->last_error));
    apu->last_master_clock = master_clock;
    return update_status(apu, ok != 0);
}

extern "C" JSV10_2ApuResult js_v10_2_apu_cpu_read(JSV10_2Apu *apu, uint8_t port, uint8_t *value) {
    int ok = 0;
    if (!apu || g_owner != apu || !value || !apu->acquired) return JSV10_2_APU_PROTOCOL_ERROR;
    *value = sc_static_apu_cpu_read_port(apu->last_master_clock, port & 3u, &ok,
                                         apu->last_error, sizeof(apu->last_error));
    return update_status(apu, ok != 0);
}

extern "C" JSV10_2ApuResult js_v10_2_apu_cpu_write(JSV10_2Apu *apu, uint8_t port, uint8_t value) {
    if (!apu || g_owner != apu || !apu->acquired) return JSV10_2_APU_PROTOCOL_ERROR;
    const int ok = sc_static_apu_cpu_write_port(apu->last_master_clock, port & 3u, value,
                                                apu->last_error, sizeof(apu->last_error));
    return update_status(apu, ok != 0);
}

extern "C" void js_v10_2_apu_set_sink(JSV10_2AudioSink sink, void *context) {
    sc_static_apu_set_sink(reinterpret_cast<SCStaticAudioSink>(sink), context);
}

extern "C" int js_v10_2_apu_read_aram(uint32_t offset, void *output, size_t bytes) {
    return sc_static_apu_read_aram(offset, output, bytes);
}

extern "C" int js_v10_2_apu_read_dsp_register(uint8_t address, uint8_t *value) {
    return sc_static_apu_read_dsp_register(address, value);
}

extern "C" size_t js_v10_2_apu_snapshot_size(void) {
    return sc_static_apu_snapshot_size();
}

extern "C" int js_v10_2_apu_snapshot_save(const JSV10_2Apu *apu,
                                            void *data, size_t capacity) {
    if (!apu || g_owner != apu || !apu->acquired) return 0;
    return sc_static_apu_snapshot_save(data, capacity);
}

extern "C" int js_v10_2_apu_snapshot_load(JSV10_2Apu *apu,
                                            const void *data, size_t size,
                                            char *error,
                                            size_t error_capacity) {
    if (!apu || g_owner != apu || !apu->acquired) {
        if (error && error_capacity)
            std::snprintf(error, error_capacity,
                          "Static APU snapshot owner is invalid.");
        return 0;
    }
    if (!sc_static_apu_snapshot_load(data, size, error, error_capacity))
        return 0;
    set_error(apu, "");
    return update_status(apu, true) == JSV10_2_APU_OK;
}
