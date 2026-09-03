#include "rnr_app_core.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct InputEvent {
    uint32_t first_frame;
    uint32_t last_frame;
    uint16_t mask;
    const char *name;
} InputEvent;

static const InputEvent k_events[] = {
    {1200u, 1201u, RNR_INPUT_START, "Start"},
    {1350u, 1351u, RNR_INPUT_B, "B - choose New Game"},
    {1500u, 1501u, RNR_INPUT_B, "B - choose one player"},
    {1650u, 1651u, RNR_INPUT_B, "B - choose Rookie"},
    {2040u, 2041u, RNR_INPUT_B, "B - choose Snake Sanders"},
    {2310u, 2311u, RNR_INPUT_B, "B - buy default Marauder"},
    {3090u, 3091u, RNR_INPUT_B, "B - Start Race"},
    {3500u, 4560u, RNR_INPUT_B, "B - hold throttle"},
    {3800u, 3899u, RNR_INPUT_RIGHT, "Right - steer during race"},
    {4100u, 4199u, RNR_INPUT_LEFT, "Left - steer during race"},
    {4500u, 4501u, RNR_INPUT_Y, "Y - fire primary weapon"},
};

static const struct { uint32_t frame; const char *name; } k_shots[] = {
    {1140u, "01-one-second-before-Start.bmp"},
    {1260u, "02-one-second-after-Start.bmp"},
    {1290u, "03-one-second-before-New-Game.bmp"},
    {1410u, "04-one-second-after-New-Game.bmp"},
    {1440u, "05-one-second-before-One-Player.bmp"},
    {1560u, "06-one-second-after-One-Player.bmp"},
    {1590u, "07-one-second-before-Rookie.bmp"},
    {1710u, "08-one-second-after-Rookie.bmp"},
    {1980u, "09-one-second-before-Hero.bmp"},
    {2100u, "10-one-second-after-Hero.bmp"},
    {2250u, "11-one-second-before-Car.bmp"},
    {2370u, "12-one-second-after-Car.bmp"},
    {3030u, "13-one-second-before-Start-Race.bmp"},
    {3150u, "14-one-second-after-Start-Race.bmp"},
    {3450u, "15-cars-on-starting-grid.bmp"},
    {3740u, "16-before-steering-right.bmp"},
    {3960u, "17-after-steering-right.bmp"},
    {4040u, "18-before-steering-left.bmp"},
    {4260u, "19-after-steering-left.bmp"},
    {4440u, "20-before-primary-weapon.bmp"},
    {4560u, "21-after-primary-weapon.bmp"},
};

static uint8_t *load_file(const char *path, size_t *size) {
    FILE *file = fopen(path, "rb");
    uint8_t *data;
    long length;
    *size = 0u;
    if (!file) return NULL;
    if (fseek(file, 0, SEEK_END) != 0 || (length = ftell(file)) < 0 ||
        fseek(file, 0, SEEK_SET) != 0) {
        fclose(file);
        return NULL;
    }
    data = (uint8_t *)malloc((size_t)length);
    if (!data || fread(data, 1u, (size_t)length, file) != (size_t)length) {
        free(data);
        fclose(file);
        return NULL;
    }
    fclose(file);
    *size = (size_t)length;
    return data;
}

static int write_u16(FILE *file, uint16_t value) {
    uint8_t bytes[2] = {(uint8_t)value, (uint8_t)(value >> 8)};
    return fwrite(bytes, 1u, sizeof(bytes), file) == sizeof(bytes);
}

static int write_u32(FILE *file, uint32_t value) {
    uint8_t bytes[4] = {(uint8_t)value, (uint8_t)(value >> 8),
                        (uint8_t)(value >> 16), (uint8_t)(value >> 24)};
    return fwrite(bytes, 1u, sizeof(bytes), file) == sizeof(bytes);
}

static int save_bmp(const char *path, const uint32_t *pixels) {
    const uint32_t width = RNR_RECOMP_FRAME_WIDTH;
    const uint32_t height = RNR_RECOMP_FRAME_HEIGHT;
    const uint32_t row_bytes = (width * 3u + 3u) & ~3u;
    const uint32_t pixel_bytes = row_bytes * height;
    FILE *file = fopen(path, "wb");
    int y;
    if (!file) return 0;
    if (fwrite("BM", 1u, 2u, file) != 2u ||
        !write_u32(file, 54u + pixel_bytes) ||
        !write_u16(file, 0u) || !write_u16(file, 0u) ||
        !write_u32(file, 54u) || !write_u32(file, 40u) ||
        !write_u32(file, width) || !write_u32(file, height) ||
        !write_u16(file, 1u) || !write_u16(file, 24u) ||
        !write_u32(file, 0u) || !write_u32(file, pixel_bytes) ||
        !write_u32(file, 2835u) || !write_u32(file, 2835u) ||
        !write_u32(file, 0u) || !write_u32(file, 0u)) {
        fclose(file);
        return 0;
    }
    for (y = (int)height - 1; y >= 0; --y) {
        uint32_t x;
        for (x = 0u; x < width; ++x) {
            uint32_t pixel = pixels[(size_t)y * width + x];
            uint8_t bgr[3] = {(uint8_t)pixel, (uint8_t)(pixel >> 8),
                              (uint8_t)(pixel >> 16)};
            if (fwrite(bgr, 1u, 3u, file) != 3u) {
                fclose(file);
                return 0;
            }
        }
    }
    return fclose(file) == 0;
}

static uint16_t input_for_frame(uint32_t frame) {
    size_t index;
    uint16_t input = 0u;
    for (index = 0u; index < sizeof(k_events) / sizeof(k_events[0]); ++index)
        if (frame >= k_events[index].first_frame &&
            frame <= k_events[index].last_frame)
            input |= k_events[index].mask;
    return input;
}

static uint32_t frame_digest(const uint32_t *pixels) {
    uint32_t hash = 2166136261u;
    size_t index;
    for (index = 0u;
         index < (size_t)RNR_RECOMP_FRAME_WIDTH * RNR_RECOMP_FRAME_HEIGHT;
         ++index) {
        uint32_t value = pixels[index];
        int byte_index;
        for (byte_index = 0; byte_index < 4; ++byte_index) {
            hash ^= (uint8_t)(value >> (byte_index * 8));
            hash *= 16777619u;
        }
    }
    return hash;
}

static size_t drain_audio(RockNRollRacingRecomp *game, uint64_t *hash) {
    int16_t samples[2048u * RNR_RECOMP_AUDIO_CHANNELS];
    size_t total = 0u;
    size_t frames;
    do {
        size_t index;
        frames = rnr_recomp_audio_read(game, samples, 2048u);
        total += frames;
        if (hash) {
            for (index = 0u;
                 index < frames * RNR_RECOMP_AUDIO_CHANNELS; ++index) {
                uint16_t value = (uint16_t)samples[index];
                *hash ^= (uint8_t)value;
                *hash *= UINT64_C(1099511628211);
                *hash ^= (uint8_t)(value >> 8);
                *hash *= UINT64_C(1099511628211);
            }
        }
    } while (frames == 2048u);
    return total;
}

int main(int argc, char **argv) {
    const char *rom_path;
    const char *output_dir;
    uint8_t *rom;
    size_t rom_size;
    RockNRollRacingRecomp *game = NULL;
    RockNRollRacingRecompFrameResult result;
    char error[512] = {0};
    uint32_t frame;
    size_t event_index;
    size_t shot_index = 0u;
    size_t audio_total = 0u;
    size_t audio_min = (size_t)-1;
    size_t audio_max = 0u;
    uint32_t audio_zero_frames = 0u;
    char snapshot_path[1024];
    uint64_t expected_audio_hash = UINT64_C(1469598103934665603);
    uint64_t replay_audio_hash = UINT64_C(1469598103934665603);
    uint64_t expected_instructions = 0u;
    uint32_t expected_frame_hash = 0u;
    size_t snapshot_audio_total = 0u;
    size_t expected_segment_audio = 0u;
    uint32_t snapshot_core_frame = 0u;
    if (argc != 3) {
        fprintf(stderr, "usage: %s ROM OUTPUT_DIRECTORY\n", argv[0]);
        return 2;
    }
    rom_path = argv[1];
    output_dir = argv[2];
    (void)snprintf(snapshot_path, sizeof(snapshot_path),
                   "%s\\race-ready.scsnap", output_dir);
    rom = load_file(rom_path, &rom_size);
    if (!rom || !rnr_recomp_create(&game, rom, rom_size,
                                      error, sizeof(error))) {
        fprintf(stderr, "FAIL create: %s\n", error);
        free(rom);
        return 1;
    }
    free(rom);
    for (frame = 1u; frame <= k_shots[sizeof(k_shots)/sizeof(k_shots[0])-1u].frame;
         ++frame) {
        uint16_t input = input_for_frame(frame);
        if (!rnr_recomp_advance(game, input, 1u, &result)) {
            fprintf(stderr, "FAIL frame %u: %s\n", frame,
                    rnr_recomp_last_error(game));
            rnr_recomp_destroy(game);
            return 1;
        }
        {
            uint64_t *audio_hash = frame > 3450u ?
                &expected_audio_hash : NULL;
            size_t audio_this_frame = drain_audio(game, audio_hash);
            audio_total += audio_this_frame;
            if (audio_this_frame < audio_min) audio_min = audio_this_frame;
            if (audio_this_frame > audio_max) audio_max = audio_this_frame;
            if (audio_this_frame == 0u) audio_zero_frames++;
        }
        for (event_index = 0u;
             event_index < sizeof(k_events) / sizeof(k_events[0]);
             ++event_index)
            if (frame == k_events[event_index].first_frame)
                printf("INPUT frame=%u button=%s mask=%04X\n", frame,
                       k_events[event_index].name, input);
        if (shot_index < sizeof(k_shots) / sizeof(k_shots[0]) &&
            frame == k_shots[shot_index].frame) {
            char path[1024];
            (void)snprintf(path, sizeof(path), "%s\\%s",
                           output_dir, k_shots[shot_index].name);
            if (!save_bmp(path, rnr_recomp_frame_bgra(game))) {
                fprintf(stderr, "FAIL screenshot: %s\n", path);
                rnr_recomp_destroy(game);
                return 1;
            }
            printf("SCREENSHOT frame=%u digest=%08X instructions=%llu "
                   "audio_total=%zu file=%s\n", frame,
                   frame_digest(rnr_recomp_frame_bgra(game)),
                   (unsigned long long)rnr_recomp_instruction_count(game),
                   audio_total, path);
            shot_index++;
        }
        if (frame == 3450u) {
            if (!rnr_recomp_snapshot_save(game, snapshot_path,
                                             error, sizeof(error))) {
                fprintf(stderr, "FAIL snapshot save: %s\n", error);
                rnr_recomp_destroy(game);
                return 1;
            }
            snapshot_audio_total = audio_total;
            snapshot_core_frame = rnr_recomp_current_frame(game);
            printf("SNAPSHOT saved route_frame=%u core_frame=%u file=%s\n",
                   frame, snapshot_core_frame, snapshot_path);
        }
    }
    expected_frame_hash = frame_digest(rnr_recomp_frame_bgra(game));
    expected_instructions = rnr_recomp_instruction_count(game);
    expected_segment_audio = audio_total - snapshot_audio_total;
    if (!rnr_recomp_snapshot_load(game, snapshot_path,
                                     error, sizeof(error)) ||
        rnr_recomp_current_frame(game) != snapshot_core_frame ||
        rnr_recomp_audio_available(game) != 0u) {
        fprintf(stderr,
                "FAIL snapshot load: %s frame=%u expected_frame=%u "
                "queued_audio=%zu\n", error,
                rnr_recomp_current_frame(game), snapshot_core_frame,
                rnr_recomp_audio_available(game));
        rnr_recomp_destroy(game);
        return 1;
    }
    {
        size_t replay_audio = 0u;
        uint32_t replay_frame;
        for (replay_frame = 3451u; replay_frame <= 4560u; ++replay_frame) {
            uint16_t input = input_for_frame(replay_frame);
            if (!rnr_recomp_advance(game, input, 1u, &result)) {
                fprintf(stderr, "FAIL snapshot replay frame %u: %s\n",
                        replay_frame, rnr_recomp_last_error(game));
                rnr_recomp_destroy(game);
                return 1;
            }
            replay_audio += drain_audio(game, &replay_audio_hash);
        }
        if (replay_audio != expected_segment_audio ||
            replay_audio_hash != expected_audio_hash ||
            frame_digest(rnr_recomp_frame_bgra(game)) !=
                expected_frame_hash ||
            rnr_recomp_instruction_count(game) != expected_instructions) {
            fprintf(stderr,
                    "FAIL snapshot determinism: audio=%zu/%zu "
                    "audio_hash=%016llX/%016llX frame_hash=%08X/%08X "
                    "instructions=%llu/%llu\n",
                    replay_audio, expected_segment_audio,
                    (unsigned long long)replay_audio_hash,
                    (unsigned long long)expected_audio_hash,
                    frame_digest(rnr_recomp_frame_bgra(game)),
                    expected_frame_hash,
                    (unsigned long long)rnr_recomp_instruction_count(game),
                    (unsigned long long)expected_instructions);
            rnr_recomp_destroy(game);
            return 1;
        }
        printf("SNAPSHOT PASS route_frame=3450 core_frame=%u "
               "replay_to_route_frame=4560 audio_frames=%zu "
               "audio_hash=%016llX frame_hash=%08X instructions=%llu\n",
               snapshot_core_frame, replay_audio,
               (unsigned long long)replay_audio_hash,
               expected_frame_hash,
               (unsigned long long)expected_instructions);
    }
    printf("PASS frames=%u instructions=%llu audio_frames=%zu "
           "audio_per_frame_min=%zu audio_per_frame_max=%zu "
           "audio_zero_frames=%u overflow=%d\n", frame - 1u,
           (unsigned long long)rnr_recomp_instruction_count(game),
           audio_total, audio_min, audio_max, audio_zero_frames,
           rnr_recomp_audio_overflowed(game));
    rnr_recomp_destroy(game);
    return 0;
}
