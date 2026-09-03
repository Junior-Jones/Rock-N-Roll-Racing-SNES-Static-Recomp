#ifndef RNR_AUDIO_RESAMPLER_H
#define RNR_AUDIO_RESAMPLER_H

#include <stddef.h>
#include <stdint.h>

typedef enum RockNRollRacingAudioResamplerMode {
    RNR_AUDIO_RESAMPLER_HERMITE = 0,
    RNR_AUDIO_RESAMPLER_LINEAR = 1,
    RNR_AUDIO_RESAMPLER_NEAREST = 2
} RockNRollRacingAudioResamplerMode;

#define RNR_AUDIO_RESAMPLER_PENDING_FRAMES 16384u

typedef struct RockNRollRacingAudioHermiteResampler {
    double previous_left[4];
    double previous_right[4];
    double rate_ratio;
    double fraction;
    int16_t last_left;
    int16_t last_right;
    int mode;
    int16_t pending_samples[RNR_AUDIO_RESAMPLER_PENDING_FRAMES * 2u];
    size_t pending_frames;
} RockNRollRacingAudioHermiteResampler;

void rnr_audio_resampler_reset(RockNRollRacingAudioHermiteResampler *resampler);
void rnr_audio_resampler_set_rates(RockNRollRacingAudioHermiteResampler *resampler,
                                      double source_rate,
                                      double destination_rate);
void rnr_audio_resampler_set_mode(RockNRollRacingAudioHermiteResampler *resampler,
                                     int mode);

/* The caller must supply enough output storage.  For the static-recomp
   32,040 Hz to 48,000 Hz path, twice input_frames is always sufficient. */
size_t rnr_audio_resampler_process(RockNRollRacingAudioHermiteResampler *resampler,
                                      const int16_t *input,
                                      size_t input_frames,
                                      int16_t *output,
                                      size_t output_capacity_frames);

#endif
