#include "rnr_app_core.h"
#include "v10_2_machine.h"

#include <windows.h>
#include <bcrypt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RNR_FRONTEND_AUDIO_FIFO_FRAMES 8192u
#define RNR_AUDIO_PROGRESS_INSTRUCTIONS 16384u

struct RockNRollRacingRecomp {
    JSV10_2Machine machine;
    uint8_t *rom;
    uint32_t *frame_pixels;
    int16_t audio_samples[RNR_FRONTEND_AUDIO_FIFO_FRAMES *
                          RNR_RECOMP_AUDIO_CHANNELS];
    size_t audio_read_index;
    size_t audio_write_index;
    size_t audio_frames;
    uint64_t instruction_count;
    int failed;
    int audio_overflowed;
    uint64_t audio_frames_dropped;
    JSV10_2Stop stop;
    char last_error[512];
};

static const uint8_t k_expected_sha256[32] = {
    0x9d,0x72,0x17,0x53,0x30,0x12,0x78,0x32,
    0x5c,0x85,0x1f,0x18,0x43,0xd6,0x69,0xa6,
    0x97,0xae,0xd7,0x57,0xdc,0xf6,0x49,0x5a,
    0x31,0xfc,0x31,0xdd,0xf6,0x64,0xb1,0x82
};

#pragma pack(push, 1)
typedef struct RnrSnapshotHeader {
    char magic[8];
    uint32_t version;
    uint32_t header_size;
    uint32_t machine_size;
    uint32_t apu_size;
    uint8_t rom_sha256[32];
    uint64_t instruction_count;
    uint64_t payload_hash;
} RnrSnapshotHeader;
#pragma pack(pop)

#define RNR_SNAPSHOT_VERSION 1u

static uint64_t snapshot_hash_bytes(uint64_t hash, const void *data,
                                    size_t size) {
    const uint8_t *bytes = (const uint8_t *)data;
    size_t index;
    for (index = 0u; index < size; ++index) {
        hash ^= bytes[index];
        hash *= UINT64_C(1099511628211);
    }
    return hash;
}

static void set_error(char *destination, size_t capacity,
                      const char *message) {
    if (!destination || !capacity) return;
    (void)snprintf(destination, capacity, "%s", message ? message : "");
    destination[capacity - 1u] = '\0';
}

static void set_instance_error(RockNRollRacingRecomp *instance,
                               const char *message) {
    if (instance)
        set_error(instance->last_error, sizeof(instance->last_error), message);
}

static int supported_rom(const uint8_t *rom, size_t rom_size) {
    BCRYPT_ALG_HANDLE algorithm = NULL;
    BCRYPT_HASH_HANDLE hash = NULL;
    DWORD object_size = 0u;
    DWORD result_size = 0u;
    uint8_t *object = NULL;
    uint8_t digest[32];
    NTSTATUS status;
    int matched = 0;
    if (!rom || rom_size != RNR_RECOMP_ROM_SIZE) return 0;
    status = BCryptOpenAlgorithmProvider(
        &algorithm, BCRYPT_SHA256_ALGORITHM, NULL, 0u);
    if (status < 0) goto done;
    status = BCryptGetProperty(algorithm, BCRYPT_OBJECT_LENGTH,
                               (PUCHAR)&object_size, sizeof(object_size),
                               &result_size, 0u);
    if (status < 0 || !object_size) goto done;
    object = (uint8_t *)malloc(object_size);
    if (!object) goto done;
    status = BCryptCreateHash(algorithm, &hash, object, object_size,
                              NULL, 0u, 0u);
    if (status < 0) goto done;
    status = BCryptHashData(hash, (PUCHAR)rom, (ULONG)rom_size, 0u);
    if (status < 0) goto done;
    status = BCryptFinishHash(hash, digest, sizeof(digest), 0u);
    if (status >= 0 &&
        memcmp(digest, k_expected_sha256, sizeof(digest)) == 0)
        matched = 1;
done:
    if (hash) BCryptDestroyHash(hash);
    if (algorithm) BCryptCloseAlgorithmProvider(algorithm, 0u);
    free(object);
    return matched;
}

static void audio_sink(void *context, int16_t left, int16_t right) {
    RockNRollRacingRecomp *instance = (RockNRollRacingRecomp *)context;
    size_t index;
    if (!instance || instance->failed) return;
    if (instance->audio_frames == RNR_FRONTEND_AUDIO_FIFO_FRAMES) {
        instance->audio_read_index =
            (instance->audio_read_index + 1u) %
            RNR_FRONTEND_AUDIO_FIFO_FRAMES;
        instance->audio_frames--;
        instance->audio_frames_dropped++;
        instance->audio_overflowed = 1;
    }
    index = instance->audio_write_index * RNR_RECOMP_AUDIO_CHANNELS;
    instance->audio_samples[index] = left;
    instance->audio_samples[index + 1u] = right;
    instance->audio_write_index =
        (instance->audio_write_index + 1u) %
        RNR_FRONTEND_AUDIO_FIFO_FRAMES;
    instance->audio_frames++;
}

static void format_stop(RockNRollRacingRecomp *instance) {
    const JSV10_2Stop *stop = &instance->stop;
    (void)snprintf(
        instance->last_error, sizeof(instance->last_error),
        "Static core stopped fail-closed: reason %u at %02X:%04X, "
        "frame %llu, scanline %u, hclock %u, master clock %llu; "
        "source context %08X, observed context %08X, SMP PC %04X.",
        (unsigned)stop->reason,
        (unsigned)((stop->address >> 16) & 0xffu),
        (unsigned)(stop->address & 0xffffu),
        (unsigned long long)instance->machine.scheduler.frame_number,
        (unsigned)stop->scanline, (unsigned)stop->hclock,
        (unsigned long long)stop->master_clock,
        (unsigned)stop->source_key, (unsigned)stop->observed_key,
        (unsigned)stop->smp_pc);
    instance->last_error[sizeof(instance->last_error) - 1u] = '\0';
}

static void convert_frame(RockNRollRacingRecomp *instance) {
    size_t index;
    for (index = 0u;
         index < RNR_RECOMP_FRAME_WIDTH * RNR_RECOMP_FRAME_HEIGHT;
         ++index) {
        uint16_t color = (uint16_t)(
            instance->machine.published_framebuffer[index * 2u] |
            ((uint16_t)instance->machine.published_framebuffer[index * 2u + 1u]
             << 8));
        uint32_t red5 = color & 31u;
        uint32_t green5 = (color >> 5) & 31u;
        uint32_t blue5 = (color >> 10) & 31u;
        uint32_t red = (red5 << 3) | (red5 >> 2);
        uint32_t green = (green5 << 3) | (green5 >> 2);
        uint32_t blue = (blue5 << 3) | (blue5 >> 2);
        instance->frame_pixels[index] =
            UINT32_C(0xff000000) | (red << 16) | (green << 8) | blue;
    }
}

static int cold_power_on(RockNRollRacingRecomp *instance) {
    js_v10_2_stop_clear(&instance->stop);
    if (!js_v10_2_power_on(&instance->machine, instance->rom,
                           RNR_RECOMP_ROM_SIZE, NULL)) {
        set_instance_error(instance,
            "The Rock n' Roll Racing static core could not power on.");
        return 0;
    }
    js_v10_2_apu_set_sink(audio_sink, instance);
    return 1;
}

int rnr_recomp_create(RockNRollRacingRecomp **out_instance,
                         const uint8_t *rom, size_t rom_size,
                         char *error, size_t error_capacity) {
    RockNRollRacingRecomp *instance;
    if (out_instance) *out_instance = NULL;
    if (!out_instance || !rom || rom_size != RNR_RECOMP_ROM_SIZE) {
        set_error(error, error_capacity,
            "Select the exact supported 1 MiB Rock n' Roll Racing USA ROM.");
        return 0;
    }
    if (!supported_rom(rom, rom_size)) {
        set_error(error, error_capacity,
            "The selected ROM is not the supported Rock n' Roll Racing "
            "(USA) revision (SHA-256 mismatch).");
        return 0;
    }
    instance = (RockNRollRacingRecomp *)calloc(1u, sizeof(*instance));
    if (!instance) {
        set_error(error, error_capacity, "Out of memory creating the static core.");
        return 0;
    }
    instance->rom = (uint8_t *)malloc(rom_size);
    instance->frame_pixels = (uint32_t *)calloc(
        RNR_RECOMP_FRAME_WIDTH * RNR_RECOMP_FRAME_HEIGHT,
        sizeof(uint32_t));
    if (!instance->rom || !instance->frame_pixels) {
        set_error(error, error_capacity, "Out of memory creating the static core.");
        rnr_recomp_destroy(instance);
        return 0;
    }
    memcpy(instance->rom, rom, rom_size);
    if (!cold_power_on(instance)) {
        set_error(error, error_capacity, instance->last_error);
        rnr_recomp_destroy(instance);
        return 0;
    }
    set_instance_error(instance, "");
    *out_instance = instance;
    return 1;
}

void rnr_recomp_destroy(RockNRollRacingRecomp *instance) {
    if (!instance) return;
    js_v10_2_apu_set_sink(NULL, NULL);
    js_v10_2_shutdown(&instance->machine);
    free(instance->frame_pixels);
    free(instance->rom);
    free(instance);
}

int rnr_recomp_reset(RockNRollRacingRecomp *instance,
                        char *error, size_t error_capacity) {
    if (!instance || !instance->rom) {
        set_error(error, error_capacity,
                  "A loaded Rock n' Roll Racing core is required.");
        return 0;
    }
    js_v10_2_apu_set_sink(NULL, NULL);
    js_v10_2_shutdown(&instance->machine);
    memset(&instance->machine, 0, sizeof(instance->machine));
    instance->audio_read_index = 0u;
    instance->audio_write_index = 0u;
    instance->audio_frames = 0u;
    instance->instruction_count = 0u;
    instance->failed = 0;
    instance->audio_overflowed = 0;
    instance->audio_frames_dropped = 0u;
    memset(instance->frame_pixels, 0,
           RNR_RECOMP_FRAME_WIDTH * RNR_RECOMP_FRAME_HEIGHT *
           sizeof(*instance->frame_pixels));
    set_instance_error(instance, "");
    if (!cold_power_on(instance)) {
        set_error(error, error_capacity, instance->last_error);
        return 0;
    }
    return 1;
}

static int advance_frames(RockNRollRacingRecomp *instance, uint16_t input_mask,
                          uint32_t frame_count, int render_output,
                          RockNRollRacingRecompAudioProgressCallback audio_progress,
                          void *audio_progress_opaque,
                          RockNRollRacingRecompFrameResult *result) {
    uint32_t start;
    uint32_t frame;
    if (!instance || instance->failed) return 0;
    /* Authentic pads cannot assert opposing directions. Mesen and bsnes both
       neutralize these pairs at the controller boundary, so do the same here
       while leaving the frontend's physical-key latch truthful. */
    if ((input_mask & (RNR_INPUT_UP | RNR_INPUT_DOWN)) ==
        (RNR_INPUT_UP | RNR_INPUT_DOWN))
        input_mask &= (uint16_t)~(RNR_INPUT_UP | RNR_INPUT_DOWN);
    if ((input_mask & (RNR_INPUT_LEFT | RNR_INPUT_RIGHT)) ==
        (RNR_INPUT_LEFT | RNR_INPUT_RIGHT))
        input_mask &= (uint16_t)~(RNR_INPUT_LEFT | RNR_INPUT_RIGHT);
    start = (uint32_t)js_v10_2_frame_sequence(&instance->machine);
    if (result) memset(result, 0, sizeof(*result));
    for (frame = 0u; frame < frame_count; ++frame) {
        uint64_t sequence = js_v10_2_frame_sequence(&instance->machine);
        uint32_t watchdog = 0u;
        js_v10_2_set_controller_state(&instance->machine, 0u, input_mask);
        js_v10_2_set_controller_state(&instance->machine, 1u, 0u);
        while (js_v10_2_frame_sequence(&instance->machine) == sequence) {
            JSExecResult execution =
                js_v10_2_step(&instance->machine, &instance->stop);
            if (execution == JS_EXEC_STOP) {
                instance->failed = 1;
                format_stop(instance);
                return 0;
            }
            instance->instruction_count++;
            if (render_output && audio_progress &&
                (watchdog % RNR_AUDIO_PROGRESS_INSTRUCTIONS) == 0u)
                audio_progress(instance, audio_progress_opaque);
            if (++watchdog >= 5000000u) {
                instance->failed = 1;
                set_instance_error(instance,
                    "Static core did not reach the next video frame before "
                    "the fail-closed watchdog limit.");
                return 0;
            }
        }
        if (render_output) convert_frame(instance);
        js_v10_2_frame_acknowledge(&instance->machine);
    }
    if (result) {
        result->route_continued = 1u;
        result->frame_rendered = render_output ? 1u : 0u;
        result->input_mask = input_mask;
        result->start_frame = start;
        result->end_frame =
            (uint32_t)js_v10_2_frame_sequence(&instance->machine);
    }
    return 1;
}

int rnr_recomp_advance(RockNRollRacingRecomp *instance, uint16_t input_mask,
                          uint32_t frame_count,
                          RockNRollRacingRecompFrameResult *result) {
    return advance_frames(instance, input_mask, frame_count, 1,
                          NULL, NULL, result);
}

int rnr_recomp_advance_streamed(
    RockNRollRacingRecomp *instance, uint16_t input_mask, uint32_t frame_count,
    RockNRollRacingRecompAudioProgressCallback audio_progress, void *opaque,
    RockNRollRacingRecompFrameResult *result) {
    return advance_frames(instance, input_mask, frame_count, 1,
                          audio_progress, opaque, result);
}

int rnr_recomp_advance_headless(RockNRollRacingRecomp *instance,
                                   uint16_t input_mask,
                                   uint32_t frame_count,
                                   RockNRollRacingRecompFrameResult *result) {
    return advance_frames(instance, input_mask, frame_count, 0,
                          NULL, NULL, result);
}

const uint32_t *rnr_recomp_frame_bgra(const RockNRollRacingRecomp *instance) {
    return instance ? instance->frame_pixels : NULL;
}

uint32_t rnr_recomp_frame_width(const RockNRollRacingRecomp *instance) {
    (void)instance;
    return RNR_RECOMP_FRAME_WIDTH;
}

uint32_t rnr_recomp_current_frame(const RockNRollRacingRecomp *instance) {
    return instance ?
        (uint32_t)js_v10_2_frame_sequence(&instance->machine) : 0u;
}

uint64_t rnr_recomp_instruction_count(const RockNRollRacingRecomp *instance) {
    return instance ? instance->instruction_count : 0u;
}

int rnr_recomp_failed(const RockNRollRacingRecomp *instance) {
    return instance ? instance->failed : 1;
}

const char *rnr_recomp_last_error(const RockNRollRacingRecomp *instance) {
    return instance ? instance->last_error : "No static core is loaded.";
}

size_t rnr_recomp_audio_available(const RockNRollRacingRecomp *instance) {
    return instance ? instance->audio_frames : 0u;
}

size_t rnr_recomp_audio_read(RockNRollRacingRecomp *instance,
                                int16_t *interleaved_stereo,
                                size_t frame_capacity) {
    size_t frames;
    size_t first;
    if (!instance || !interleaved_stereo || !frame_capacity) return 0u;
    frames = instance->audio_frames < frame_capacity ?
             instance->audio_frames : frame_capacity;
    first = RNR_FRONTEND_AUDIO_FIFO_FRAMES - instance->audio_read_index;
    if (first > frames) first = frames;
    memcpy(interleaved_stereo,
           instance->audio_samples +
               instance->audio_read_index * RNR_RECOMP_AUDIO_CHANNELS,
           first * RNR_RECOMP_AUDIO_CHANNELS * sizeof(int16_t));
    if (first < frames)
        memcpy(interleaved_stereo + first * RNR_RECOMP_AUDIO_CHANNELS,
               instance->audio_samples,
               (frames - first) * RNR_RECOMP_AUDIO_CHANNELS *
                   sizeof(int16_t));
    instance->audio_read_index =
        (instance->audio_read_index + frames) %
        RNR_FRONTEND_AUDIO_FIFO_FRAMES;
    instance->audio_frames -= frames;
    if (!instance->audio_frames)
        instance->audio_write_index = instance->audio_read_index;
    return frames;
}

size_t rnr_recomp_audio_discard(RockNRollRacingRecomp *instance) {
    size_t frames = instance ? instance->audio_frames : 0u;
    if (instance) {
        instance->audio_frames = 0u;
        instance->audio_read_index = 0u;
        instance->audio_write_index = 0u;
    }
    return frames;
}

int rnr_recomp_audio_overflowed(const RockNRollRacingRecomp *instance) {
    return instance ? instance->audio_overflowed : 0;
}

uint64_t rnr_recomp_audio_dropped_frames(
    const RockNRollRacingRecomp *instance) {
    return instance ? instance->audio_frames_dropped : 0u;
}

void rnr_recomp_audio_clear_overflow(RockNRollRacingRecomp *instance) {
    if (instance) instance->audio_overflowed = 0;
}

int rnr_recomp_widescreen_enabled(const RockNRollRacingRecomp *instance) {
    (void)instance;
    return 0;
}

int rnr_recomp_set_widescreen(RockNRollRacingRecomp *instance, int enabled,
                                 char *error, size_t error_capacity) {
    (void)instance;
    if (!enabled) return 1;
    set_error(error, error_capacity,
              "This Rock n' Roll Racing core does not expose widescreen rendering.");
    return 0;
}

static int unsupported(char *error, size_t error_capacity) {
    set_error(error, error_capacity,
              "This operation is not exposed by the Rock n' Roll Racing static core.");
    return 0;
}

int rnr_recomp_snapshot_save(const RockNRollRacingRecomp *instance,
                                const char *path,
                                char *error, size_t error_capacity) {
    RnrSnapshotHeader header;
    JSV10_2Machine machine;
    uint8_t *apu_snapshot = NULL;
    size_t apu_size;
    FILE *file = NULL;
    int ok = 0;
    if (!instance || instance->failed || !path || !path[0]) {
        set_error(error, error_capacity,
                  "A running Rock n' Roll Racing core and snapshot path are required.");
        return 0;
    }
    apu_size = js_v10_2_apu_snapshot_size();
    if (!apu_size || apu_size > UINT32_MAX) {
        set_error(error, error_capacity, "Static APU snapshot size is invalid.");
        return 0;
    }
    apu_snapshot = (uint8_t *)malloc(apu_size);
    if (!apu_snapshot ||
        !js_v10_2_apu_snapshot_save(&instance->machine.apu,
                                    apu_snapshot, apu_size)) {
        set_error(error, error_capacity, "Unable to capture static APU state.");
        goto done;
    }
    machine = instance->machine;
    machine.rom = NULL;
    machine.scheduler.owner = NULL;
    machine.timing.plan = NULL;
    memset(&header, 0, sizeof(header));
    memcpy(header.magic, "RNRSNAP1", 8u);
    header.version = RNR_SNAPSHOT_VERSION;
    header.header_size = (uint32_t)sizeof(header);
    header.machine_size = (uint32_t)sizeof(machine);
    header.apu_size = (uint32_t)apu_size;
    memcpy(header.rom_sha256, k_expected_sha256, sizeof(k_expected_sha256));
    header.instruction_count = instance->instruction_count;
    header.payload_hash = snapshot_hash_bytes(
        UINT64_C(1469598103934665603), &machine, sizeof(machine));
    header.payload_hash = snapshot_hash_bytes(
        header.payload_hash, apu_snapshot, apu_size);
    file = fopen(path, "wb");
    if (!file) {
        set_error(error, error_capacity, "Unable to create the snapshot file.");
        goto done;
    }
    if (fwrite(&header, 1u, sizeof(header), file) != sizeof(header) ||
        fwrite(&machine, 1u, sizeof(machine), file) != sizeof(machine) ||
        fwrite(apu_snapshot, 1u, apu_size, file) != apu_size) {
        set_error(error, error_capacity, "Unable to write the complete snapshot file.");
        goto done;
    }
    if (fclose(file) != 0) {
        file = NULL;
        set_error(error, error_capacity, "Unable to finish the snapshot file.");
        goto done;
    }
    file = NULL;
    set_error(error, error_capacity, "");
    ok = 1;
done:
    if (file) fclose(file);
    free(apu_snapshot);
    return ok;
}

int rnr_recomp_snapshot_load(RockNRollRacingRecomp *instance,
                                const char *path,
                                char *error, size_t error_capacity) {
    RnrSnapshotHeader header;
    JSV10_2Machine *loaded_machine = NULL;
    JSV10_2Machine *old_machine = NULL;
    uint8_t *loaded_apu = NULL;
    uint8_t *old_apu = NULL;
    size_t apu_size;
    uint64_t payload_hash;
    FILE *file = NULL;
    int trailing;
    int ok = 0;
    if (!instance || !path || !path[0]) {
        set_error(error, error_capacity,
                  "A loaded Rock n' Roll Racing core and snapshot path are required.");
        return 0;
    }
    apu_size = js_v10_2_apu_snapshot_size();
    loaded_machine = (JSV10_2Machine *)malloc(sizeof(*loaded_machine));
    old_machine = (JSV10_2Machine *)malloc(sizeof(*old_machine));
    loaded_apu = (uint8_t *)malloc(apu_size);
    old_apu = (uint8_t *)malloc(apu_size);
    if (!loaded_machine || !old_machine || !loaded_apu || !old_apu) {
        set_error(error, error_capacity, "Out of memory loading the snapshot.");
        goto done;
    }
    file = fopen(path, "rb");
    if (!file || fread(&header, 1u, sizeof(header), file) != sizeof(header) ||
        memcmp(header.magic, "RNRSNAP1", 8u) != 0 ||
        header.version != RNR_SNAPSHOT_VERSION ||
        header.header_size != sizeof(header) ||
        header.machine_size != sizeof(*loaded_machine) ||
        header.apu_size != apu_size ||
        memcmp(header.rom_sha256, k_expected_sha256,
               sizeof(k_expected_sha256)) != 0) {
        set_error(error, error_capacity,
                  "The snapshot is invalid or belongs to another static-core build.");
        goto done;
    }
    if (fread(loaded_machine, 1u, sizeof(*loaded_machine), file) !=
            sizeof(*loaded_machine) ||
        fread(loaded_apu, 1u, apu_size, file) != apu_size ||
        (trailing = fgetc(file)) != EOF) {
        set_error(error, error_capacity, "The snapshot file is incomplete or has trailing data.");
        goto done;
    }
    fclose(file);
    file = NULL;
    payload_hash = snapshot_hash_bytes(
        UINT64_C(1469598103934665603), loaded_machine,
        sizeof(*loaded_machine));
    payload_hash = snapshot_hash_bytes(payload_hash, loaded_apu, apu_size);
    if (payload_hash != header.payload_hash ||
        loaded_machine->rom != NULL ||
        loaded_machine->rom_size != RNR_RECOMP_ROM_SIZE ||
        loaded_machine->scheduler.owner != NULL ||
        loaded_machine->timing.plan != NULL ||
        !loaded_machine->apu.acquired) {
        set_error(error, error_capacity, "The snapshot payload failed validation.");
        goto done;
    }
    *old_machine = instance->machine;
    if (!js_v10_2_apu_snapshot_save(&instance->machine.apu,
                                    old_apu, apu_size)) {
        set_error(error, error_capacity,
                  "Unable to preserve the current APU state before loading.");
        goto done;
    }
    instance->machine = *loaded_machine;
    instance->machine.rom = instance->rom;
    instance->machine.scheduler.owner = &instance->machine;
    if (!js_v10_2_apu_snapshot_load(&instance->machine.apu,
                                    loaded_apu, apu_size,
                                    error, error_capacity)) {
        instance->machine = *old_machine;
        instance->machine.rom = instance->rom;
        instance->machine.scheduler.owner = &instance->machine;
        (void)js_v10_2_apu_snapshot_load(&instance->machine.apu,
                                         old_apu, apu_size, NULL, 0u);
        goto done;
    }
    js_v10_2_apu_set_sink(audio_sink, instance);
    instance->instruction_count = header.instruction_count;
    instance->audio_read_index = 0u;
    instance->audio_write_index = 0u;
    instance->audio_frames = 0u;
    instance->audio_overflowed = 0;
    instance->audio_frames_dropped = 0u;
    instance->failed = 0;
    js_v10_2_stop_clear(&instance->stop);
    set_instance_error(instance, "");
    convert_frame(instance);
    set_error(error, error_capacity, "");
    ok = 1;
done:
    if (file) fclose(file);
    free(old_apu);
    free(loaded_apu);
    free(old_machine);
    free(loaded_machine);
    return ok;
}

int rnr_recomp_sram_copy(const RockNRollRacingRecomp *instance,
                            void *destination, size_t capacity) {
    (void)instance; (void)destination; (void)capacity;
    return 0;
}

int rnr_recomp_sram_load(RockNRollRacingRecomp *instance,
                            const void *source, size_t size,
                            char *error, size_t error_capacity) {
    (void)instance; (void)source; (void)size;
    return unsupported(error, error_capacity);
}

int rnr_recomp_sram_dirty(const RockNRollRacingRecomp *instance) {
    (void)instance;
    return 0;
}

void rnr_recomp_sram_mark_clean(RockNRollRacingRecomp *instance) {
    (void)instance;
}

static int write_diagnostic(const RockNRollRacingRecomp *instance,
                            const char *path, const char *mode,
                            const char *section_title,
                            const char *screenshot_path,
                            char *error, size_t error_capacity) {
    FILE *file;
    if (!instance || !path || !path[0]) {
        set_error(error, error_capacity,
                  "A loaded static core and diagnostic path are required.");
        return 0;
    }
    file = fopen(path, mode);
    if (!file) {
        set_error(error, error_capacity, "Unable to write the diagnostic log.");
        return 0;
    }
    if (section_title && section_title[0])
        (void)fprintf(file, "\r\n--- %s ---\r\n", section_title);
    (void)fprintf(file,
        "Rock n' Roll Racing static-core diagnostic\r\n"
        "frame=%llu frame_sequence=%llu master_clock=%llu "
        "scanline=%u hclock=%u\r\n"
        "cpu=%02X:%04X A=%04X X=%04X Y=%04X S=%04X D=%04X "
        "P=%02X E=%u\r\n"
        "instructions=%llu smp_pc=%04X smp_cycles=%llu pcm_frames=%llu\r\n"
        "failed=%d stop_reason=%u stop_address=%06X last_error=%s\r\n"
        "screenshot=%s\r\n",
        (unsigned long long)instance->machine.frame_sequence,
        (unsigned long long)instance->machine.frame_sequence,
        (unsigned long long)instance->machine.scheduler.master_clock,
        (unsigned)instance->machine.scheduler.scanline,
        (unsigned)instance->machine.scheduler.hclock,
        (unsigned)instance->machine.cpu.pbr,
        (unsigned)instance->machine.cpu.pc,
        (unsigned)instance->machine.cpu.a,
        (unsigned)instance->machine.cpu.x,
        (unsigned)instance->machine.cpu.y,
        (unsigned)instance->machine.cpu.s,
        (unsigned)instance->machine.cpu.d,
        (unsigned)instance->machine.cpu.p,
        (unsigned)instance->machine.cpu.e,
        (unsigned long long)instance->instruction_count,
        (unsigned)instance->machine.apu.entry_pc,
        (unsigned long long)instance->machine.apu.smp_cycles,
        (unsigned long long)instance->machine.apu.pcm_frames,
        instance->failed, (unsigned)instance->stop.reason,
        (unsigned)instance->stop.address,
        instance->last_error[0] ? instance->last_error : "none",
        screenshot_path && screenshot_path[0] ? screenshot_path : "none");
    if (fclose(file) != 0) {
        set_error(error, error_capacity, "Unable to finish the diagnostic log.");
        return 0;
    }
    return 1;
}

int rnr_recomp_write_diagnostic_log(
    const RockNRollRacingRecomp *instance, const char *path,
    const char *screenshot_path, char *error, size_t error_capacity) {
    return write_diagnostic(instance, path, "wb", NULL, screenshot_path,
                            error, error_capacity);
}

int rnr_recomp_append_diagnostic_log(
    const RockNRollRacingRecomp *instance, const char *path,
    const char *section_title, char *error, size_t error_capacity) {
    return write_diagnostic(instance, path, "ab", section_title, NULL,
                            error, error_capacity);
}
