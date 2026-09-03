#include "rnr_app_core.h"

#include <stdio.h>
#include <stdlib.h>

static uint8_t *load_file(const char *path, size_t *size) {
    FILE *file;
    long length;
    uint8_t *data;
    *size = 0u;
    file = fopen(path, "rb");
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

static uint64_t hash_frame(const uint32_t *pixels) {
    uint64_t hash = UINT64_C(1469598103934665603);
    size_t index;
    for (index = 0u;
         index < RNR_RECOMP_FRAME_WIDTH * RNR_RECOMP_FRAME_HEIGHT;
         ++index) {
        hash ^= pixels[index];
        hash *= UINT64_C(1099511628211);
    }
    return hash;
}

static uint16_t logged_test_input(uint32_t frame) {
    static const struct { uint32_t frame; uint16_t mask; } events[] = {
        {772u,0x1000u},{1019u,0x0080u},{1137u,0x8000u},
        {1341u,0x0020u},{1364u,0x0010u},{1398u,0x4000u},
        {1414u,0x0040u},{1482u,0x2000u},{1921u,0x2000u},
        {2158u,0x1000u},{2580u,0x1000u},{2750u,0x1000u},
        {3053u,0x8000u},{3158u,0x0080u},{3338u,0x0040u},
        {3475u,0x4000u},{3634u,0x1000u},{4418u,0x1000u},
        {4535u,0x0080u},{4605u,0x8000u},{4725u,0x0040u},
        {4803u,0x4000u},{5138u,0x2000u},
    };
    size_t index;
    for (index = 0u; index < sizeof(events) / sizeof(events[0]); ++index)
        if (events[index].frame == frame) return events[index].mask;
    return 0u;
}

static int run_logged_timeline(RockNRollRacingRecomp *game, uint32_t frame_limit) {
    RockNRollRacingRecompFrameResult result;
    uint32_t frame;
    for (frame = 0u; frame < frame_limit; ++frame) {
        uint16_t input = logged_test_input(frame);
        if (!rnr_recomp_advance(game, input, 1u, &result)) {
            fprintf(stderr, "FAIL: logged render timeline stopped at frame %u: %s\n",
                    frame, rnr_recomp_last_error(game));
            return 0;
        }
        (void)rnr_recomp_audio_discard(game);
    }
    return 1;
}

static int run_mixed_render_timeline(RockNRollRacingRecomp *game,
                                     uint32_t frame_limit) {
    RockNRollRacingRecompFrameResult result;
    while (rnr_recomp_current_frame(game) < frame_limit) {
        uint32_t frame = rnr_recomp_current_frame(game);
        uint16_t input = logged_test_input(frame);
        int advanced = (frame & 1u) ?
            rnr_recomp_advance(game, input, 1u, &result) :
            rnr_recomp_advance_headless(game, input, 1u, &result);
        if (!advanced) {
            fprintf(stderr, "FAIL: mixed render timeline stopped at frame %u: %s\n",
                    frame, rnr_recomp_last_error(game));
            return 0;
        }
        (void)rnr_recomp_audio_discard(game);
    }
    return 1;
}

static int run_segment(RockNRollRacingRecomp *game, int discard_video,
                       uint32_t frame_limit,
                       uint64_t *frame_hash, size_t *audio_total) {
    RockNRollRacingRecompFrameResult result;
    uint32_t frame;
    *audio_total = 0u;
    for (frame = 0u; frame < frame_limit; ++frame) {
        int advanced = discard_video && frame + 1u < frame_limit ?
            rnr_recomp_advance_headless(game, 0u, 1u, &result) :
            rnr_recomp_advance(game, 0u, 1u, &result);
        if (!advanced) return 0;
        *audio_total += rnr_recomp_audio_discard(game);
    }
    if (!rnr_recomp_frame_bgra(game)) return 0;
    *frame_hash = hash_frame(rnr_recomp_frame_bgra(game));
    return !rnr_recomp_failed(game);
}

int main(void) {
    const char *path = getenv("RNR_ROM");
    uint8_t *rom;
    size_t rom_size;
    RockNRollRacingRecomp *game = NULL;
    uint64_t first_hash = 0u;
    uint64_t reset_hash = 0u;
    size_t first_audio = 0u;
    size_t reset_audio = 0u;
    char error[256];
    uint32_t frame_limit = 180u;
    const char *frame_limit_text = getenv("RNR_FRONTEND_TEST_FRAMES");
    const char *logged_timeline = getenv("RNR_FRONTEND_TEST_LOGGED_TIMELINE");
    const char *mixed_timeline = getenv("RNR_FRONTEND_TEST_MIXED_RENDER");
    int passed;
    if (!path || !path[0]) {
        puts("SKIP rnr_frontend_core_test: RNR_ROM not set");
        return 0;
    }
    rom = load_file(path, &rom_size);
    if (!rom) {
        fputs("FAIL: unable to read ROM\n", stderr);
        return 1;
    }
    passed = rnr_recomp_create(&game, rom, rom_size, error, sizeof(error));
    free(rom);
    if (!passed) {
        fprintf(stderr, "FAIL: create: %s\n", error);
        return 1;
    }
    if (frame_limit_text && frame_limit_text[0]) {
        unsigned long parsed = strtoul(frame_limit_text, NULL, 10);
        if (parsed > 0u && parsed <= UINT32_MAX)
            frame_limit = (uint32_t)parsed;
    }
    if (logged_timeline && logged_timeline[0]) {
        passed = run_logged_timeline(game, frame_limit);
        rnr_recomp_destroy(game);
        if (!passed) return 1;
        printf("PASS: logged input/render timeline reproduced %u frames\n",
               frame_limit);
        return 0;
    }
    if (mixed_timeline && mixed_timeline[0]) {
        passed = run_mixed_render_timeline(game, frame_limit);
        rnr_recomp_destroy(game);
        if (!passed) return 1;
        printf("PASS: mixed headless/render timeline reached %u frames\n",
               frame_limit);
        return 0;
    }
    /* Compare like-for-like headless catch-up routes on both sides of reset.
     * A first rendered frame may intentionally consume one extra emulated
     * frame to resynchronise from the power-on mid-raster position. */
    passed = run_segment(game, 1, frame_limit, &first_hash, &first_audio);
    if (passed)
        passed = rnr_recomp_reset(game, error, sizeof(error));
    if (passed)
        passed = rnr_recomp_current_frame(game) == 0u &&
                 rnr_recomp_audio_available(game) == 0u;
    if (passed)
        passed = run_segment(game, 1, frame_limit, &reset_hash, &reset_audio);
    if (passed)
        passed = first_hash == reset_hash && first_audio == reset_audio &&
                 first_audio > 0u;
    rnr_recomp_destroy(game);
    if (!passed) {
        fprintf(stderr,
                "FAIL: cold reset did not reproduce clean video/audio state "
                "(first_hash=%016llx reset_hash=%016llx first_audio=%zu "
                "reset_audio=%zu)\n",
                (unsigned long long)first_hash,
                (unsigned long long)reset_hash,
                first_audio, reset_audio);
        return 1;
    }
    printf("PASS: cold reset and headless catch-up reproduced %u frames "
           "(%zu audio frames)\n", frame_limit, reset_audio);
    return 0;
}
