#ifndef RNR_AUDIO_OUTPUT_DSOUND_WIN32_H
#define RNR_AUDIO_OUTPUT_DSOUND_WIN32_H

#if !defined(_WIN32)
#error This audio backend is for Windows only.
#endif

#include <windows.h>
#include <mmsystem.h>
#include <dsound.h>
#include <stdint.h>

#include "rnr_app_core.h"
#include "rnr_audio_resampler.h"

#define RNR_AUDIO_DEVICE_NAME_CAPACITY 128u
#define RNR_AUDIO_QUEUE_HISTORY_CAPACITY 60u

#define RNR_AUDIO_MIN_LATENCY_MS 0
#define RNR_AUDIO_MAX_LATENCY_MS 40
#define RNR_AUDIO_MIN_SAFETY_BUFFER_MS 0
#define RNR_AUDIO_MAX_SAFETY_BUFFER_MS 100
#define RNR_AUDIO_MIN_RING_BUFFER_MS 50
#define RNR_AUDIO_MAX_RING_BUFFER_MS 1000
#define RNR_AUDIO_MIN_RECOVERY_MS 10
#define RNR_AUDIO_MAX_RECOVERY_MS 500
#define RNR_AUDIO_MIN_DRIFT_TOLERANCE_MS 0
#define RNR_AUDIO_MAX_DRIFT_TOLERANCE_MS 20
#define RNR_AUDIO_MIN_RATE_ADJUSTMENT_PPM 0
#define RNR_AUDIO_MAX_RATE_ADJUSTMENT_PPM 10000
#define RNR_AUDIO_MIN_AVERAGING_FRAMES 1
#define RNR_AUDIO_MAX_AVERAGING_FRAMES 60
#define RNR_AUDIO_MIN_FADE_MS 0
#define RNR_AUDIO_MAX_FADE_MS 100

typedef struct RockNRollRacingAudioSettings {
    int enabled;
    int volume_percent;
    int latency_enabled;
    int latency_ms;
    int output_sample_rate;
    int resampler_mode;
    int safety_buffer_ms;
    int ring_buffer_ms;
    int drift_correction_enabled;
    int drift_tolerance_ms;
    int max_rate_adjustment_ppm;
    int averaging_frames;
    int integral_correction_enabled;
    int recovery_enabled;
    int recovery_threshold_ms;
    int realign_on_underrun;
    int clear_on_pause;
    int resume_fade_ms;
    wchar_t device_name[RNR_AUDIO_DEVICE_NAME_CAPACITY];
} RockNRollRacingAudioSettings;

typedef struct RockNRollRacingAudioDiagnostics {
    uint64_t native_frames_queued;
    uint64_t underruns;
    uint64_t queue_failures;
    uint64_t queue_recoveries;
    uint64_t stale_frames_dropped;
    uint64_t device_reopens;
    uint32_t queue_depth_frames;
    uint32_t safe_queue_depth_frames;
    uint32_t peak_queue_depth_frames;
    uint32_t target_latency_frames;
    float playback_ratio;
    float average_latency_ms;
    int device_sample_rate;
} RockNRollRacingAudioDiagnostics;

typedef struct RockNRollRacingAudioOutput {
    LPDIRECTSOUND8 direct_sound;
    LPDIRECTSOUNDBUFFER primary_buffer;
    LPDIRECTSOUNDBUFFER8 secondary_buffer;
    RockNRollRacingAudioHermiteResampler resampler;
    DWORD buffer_size_bytes;
    DWORD write_offset;
    DWORD previous_play_cursor;
    uint64_t total_bytes_written;
    uint64_t total_bytes_played;
    uint32_t target_latency_frames;
    uint32_t queue_history[RNR_AUDIO_QUEUE_HISTORY_CAPACITY];
    uint32_t queue_history_index;
    uint32_t queue_history_count;
    int32_t under_target;
    int paused;
    int playing;
    int priming;
    int volume_percent;
    int latency_enabled;
    int device_sample_rate;
    int drift_correction_enabled;
    int drift_tolerance_ms;
    int max_rate_adjustment_ppm;
    int averaging_frames;
    int integral_correction_enabled;
    int recovery_enabled;
    int recovery_threshold_ms;
    int realign_on_underrun;
    int clear_on_pause;
    uint32_t fade_frames_remaining;
    uint32_t fade_frames_total;
    int starved_last_pump;
    double playback_ratio;
    wchar_t opened_device_name[RNR_AUDIO_DEVICE_NAME_CAPACITY];
    RockNRollRacingAudioDiagnostics diagnostics;
} RockNRollRacingAudioOutput;

void rnr_audio_settings_defaults(RockNRollRacingAudioSettings *settings);
void rnr_audio_settings_load(RockNRollRacingAudioSettings *settings,
                                 const wchar_t *ini_path);
void rnr_audio_settings_save(const RockNRollRacingAudioSettings *settings,
                                 const wchar_t *ini_path);

UINT rnr_audio_device_count(void);
int rnr_audio_device_name(UINT device_index, wchar_t *name,
                             size_t name_capacity);

void rnr_audio_output_initialize(RockNRollRacingAudioOutput *output);
int rnr_audio_output_open(RockNRollRacingAudioOutput *output,
                             const RockNRollRacingAudioSettings *settings,
                             HWND owner, wchar_t *error,
                             size_t error_capacity);
void rnr_audio_output_close(RockNRollRacingAudioOutput *output);
void rnr_audio_output_pause(RockNRollRacingAudioOutput *output);
void rnr_audio_output_resume(RockNRollRacingAudioOutput *output);
void rnr_audio_output_flush(RockNRollRacingAudioOutput *output);
int rnr_audio_output_is_open(const RockNRollRacingAudioOutput *output);
int32_t rnr_audio_output_pacing_ppm(
    const RockNRollRacingAudioOutput *output);
void rnr_audio_output_get_diagnostics(
    const RockNRollRacingAudioOutput *output,
    RockNRollRacingAudioDiagnostics *diagnostics);

/* Recording remains native 32,040 Hz PCM; only speaker output is resampled. */
void rnr_audio_output_pump(RockNRollRacingAudioOutput *output,
                              RockNRollRacingRecomp *game);
/* Drain a partial in-frame DSP batch without running end-of-frame latency
   control more than once per emulated frame. */
void rnr_audio_output_pump_progress(RockNRollRacingAudioOutput *output,
                                       RockNRollRacingRecomp *game);

#endif
