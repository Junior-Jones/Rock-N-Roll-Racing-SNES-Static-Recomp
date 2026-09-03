#ifndef RNR_FRONTEND_SETTINGS_WIN32_H
#define RNR_FRONTEND_SETTINGS_WIN32_H

#include <windows.h>
#include <stdint.h>

#include "rnr_gamepad_input_win32.h"

#define RNR_WIN_BINDING_COUNT 12
#define RNR_INPUT_SOURCE_KEYBOARD 0
#define RNR_INPUT_SOURCE_GAMEPAD 1

typedef enum RockNRollRacingWinBindingAction {
    RNR_WIN_BIND_UP = 0, RNR_WIN_BIND_DOWN, RNR_WIN_BIND_LEFT, RNR_WIN_BIND_RIGHT,
    RNR_WIN_BIND_SNES_B, RNR_WIN_BIND_SNES_A, RNR_WIN_BIND_SNES_Y,
    RNR_WIN_BIND_SNES_X, RNR_WIN_BIND_SNES_L, RNR_WIN_BIND_SNES_R,
    RNR_WIN_BIND_START, RNR_WIN_BIND_SELECT
} RockNRollRacingWinBindingAction;

typedef struct RockNRollRacingFrontendSettingsWin32 {
    int integer_scale;
    int pause_on_focus_loss;
    int auto_run_on_load;
    int fullscreen_on_play;
    int show_fps_counter;
    int ntsc_frame_lock;
    int widescreen;
    int snapshot_slot;
    int input_source;
    int input_source_saved;
    int welcome_shown;
    UINT bindings[RNR_WIN_BINDING_COUNT];
    int gamepad_bindings[RNR_WIN_BINDING_COUNT];
} RockNRollRacingFrontendSettingsWin32;

void rnr_frontend_settings_win32_defaults(RockNRollRacingFrontendSettingsWin32 *s);
void rnr_frontend_settings_win32_classic(RockNRollRacingFrontendSettingsWin32 *s);
void rnr_frontend_settings_win32_load(RockNRollRacingFrontendSettingsWin32 *s,
                                          const wchar_t *path);
int rnr_frontend_settings_win32_save(const RockNRollRacingFrontendSettingsWin32 *s,
                                         const wchar_t *path);
uint16_t rnr_frontend_settings_win32_input(
    const RockNRollRacingFrontendSettingsWin32 *s, UINT virtual_key);
const wchar_t *rnr_frontend_settings_win32_action_name(int action);
void rnr_frontend_settings_win32_key_name(UINT virtual_key,
                                               wchar_t *text, size_t capacity);
int rnr_frontend_settings_win32_dialog(HWND parent, HINSTANCE instance,
                                           RockNRollRacingFrontendSettingsWin32 *s);
int rnr_frontend_controls_win32_dialog(HWND parent, HINSTANCE instance,
                                           RockNRollRacingFrontendSettingsWin32 *s,
                                           RockNRollRacingGamepadInputWin32 *gamepad);

#endif
