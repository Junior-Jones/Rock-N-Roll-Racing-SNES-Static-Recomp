#ifndef RNR_STATIC_RECOMP_FRONTEND_H
#define RNR_STATIC_RECOMP_FRONTEND_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define RNR_RECOMP_ROM_SIZE 1048576u
#define RNR_RECOMP_FRAME_WIDTH 256u
#define RNR_RECOMP_FRAME_HEIGHT 224u
#define RNR_RECOMP_AUDIO_SAMPLE_RATE 32040u
#define RNR_RECOMP_HOST_AUDIO_SAMPLE_RATE 32040u
#define RNR_RECOMP_AUDIO_CHANNELS 2u
#define RNR_RECOMP_PRESENTATION_FPS_NUMERATOR 39375000u
#define RNR_RECOMP_PRESENTATION_FPS_DENOMINATOR 655171u

enum RockNRollRacingRecompInput {
    RNR_INPUT_B = 0x8000u, RNR_INPUT_Y = 0x4000u,
    RNR_INPUT_SELECT = 0x2000u, RNR_INPUT_START = 0x1000u,
    RNR_INPUT_UP = 0x0800u, RNR_INPUT_DOWN = 0x0400u,
    RNR_INPUT_LEFT = 0x0200u, RNR_INPUT_RIGHT = 0x0100u,
    RNR_INPUT_A = 0x0080u, RNR_INPUT_X = 0x0040u,
    RNR_INPUT_L = 0x0020u, RNR_INPUT_R = 0x0010u
};

typedef struct RockNRollRacingRecomp RockNRollRacingRecomp;
typedef void (*RockNRollRacingRecompAudioProgressCallback)(
    RockNRollRacingRecomp *instance, void *opaque);
typedef struct RockNRollRacingRecompFrameResult {
    uint8_t route_continued;
    uint8_t frame_rendered;
    uint16_t input_mask;
    uint32_t start_frame;
    uint32_t end_frame;
    char renderer_error[192];
} RockNRollRacingRecompFrameResult;

int rnr_recomp_create(RockNRollRacingRecomp **out_instance,
                         const uint8_t *rom, size_t rom_size,
                         char *error, size_t error_capacity);
void rnr_recomp_destroy(RockNRollRacingRecomp *instance);
int rnr_recomp_reset(RockNRollRacingRecomp *instance,
                        char *error, size_t error_capacity);
int rnr_recomp_advance(RockNRollRacingRecomp *instance, uint16_t input_mask,
                          uint32_t frame_count,
                          RockNRollRacingRecompFrameResult *result);
int rnr_recomp_advance_streamed(
    RockNRollRacingRecomp *instance, uint16_t input_mask, uint32_t frame_count,
    RockNRollRacingRecompAudioProgressCallback audio_progress, void *opaque,
    RockNRollRacingRecompFrameResult *result);
int rnr_recomp_advance_headless(RockNRollRacingRecomp *instance,
                                   uint16_t input_mask,
                                   uint32_t frame_count,
                                   RockNRollRacingRecompFrameResult *result);
const uint32_t *rnr_recomp_frame_bgra(const RockNRollRacingRecomp *instance);
uint32_t rnr_recomp_frame_width(const RockNRollRacingRecomp *instance);
uint32_t rnr_recomp_current_frame(const RockNRollRacingRecomp *instance);
uint64_t rnr_recomp_instruction_count(const RockNRollRacingRecomp *instance);
int rnr_recomp_failed(const RockNRollRacingRecomp *instance);
const char *rnr_recomp_last_error(const RockNRollRacingRecomp *instance);
size_t rnr_recomp_audio_available(const RockNRollRacingRecomp *instance);
size_t rnr_recomp_audio_read(RockNRollRacingRecomp *instance,
                                int16_t *interleaved_stereo,
                                size_t frame_capacity);
size_t rnr_recomp_audio_discard(RockNRollRacingRecomp *instance);
int rnr_recomp_audio_overflowed(const RockNRollRacingRecomp *instance);
uint64_t rnr_recomp_audio_dropped_frames(
    const RockNRollRacingRecomp *instance);
void rnr_recomp_audio_clear_overflow(RockNRollRacingRecomp *instance);

int rnr_recomp_widescreen_enabled(const RockNRollRacingRecomp *instance);
int rnr_recomp_set_widescreen(RockNRollRacingRecomp *instance, int enabled,
                                 char *error, size_t error_capacity);
int rnr_recomp_snapshot_save(const RockNRollRacingRecomp *instance,
                                const char *path,
                                char *error, size_t error_capacity);
int rnr_recomp_snapshot_load(RockNRollRacingRecomp *instance,
                                const char *path,
                                char *error, size_t error_capacity);
int rnr_recomp_sram_copy(const RockNRollRacingRecomp *instance,
                            void *destination, size_t capacity);
int rnr_recomp_sram_load(RockNRollRacingRecomp *instance,
                            const void *source, size_t size,
                            char *error, size_t error_capacity);
int rnr_recomp_sram_dirty(const RockNRollRacingRecomp *instance);
void rnr_recomp_sram_mark_clean(RockNRollRacingRecomp *instance);

#ifdef __cplusplus
}
#endif
#endif
