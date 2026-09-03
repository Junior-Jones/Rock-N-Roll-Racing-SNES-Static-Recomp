#ifndef RNR_GAMEPAD_INPUT_WIN32_H
#define RNR_GAMEPAD_INPUT_WIN32_H

#include <stddef.h>
#include <stdint.h>
#include <windows.h>

#include <SDL3/SDL_gamepad.h>

#define RNR_GAMEPAD_BINDING_COUNT 12

typedef enum RockNRollRacingGamepadControl {
    RNR_GAMEPAD_DPAD_UP = 1,
    RNR_GAMEPAD_DPAD_DOWN,
    RNR_GAMEPAD_DPAD_LEFT,
    RNR_GAMEPAD_DPAD_RIGHT,
    RNR_GAMEPAD_LEFT_STICK_UP,
    RNR_GAMEPAD_LEFT_STICK_DOWN,
    RNR_GAMEPAD_LEFT_STICK_LEFT,
    RNR_GAMEPAD_LEFT_STICK_RIGHT,
    RNR_GAMEPAD_FACE_SOUTH,
    RNR_GAMEPAD_FACE_EAST,
    RNR_GAMEPAD_FACE_WEST,
    RNR_GAMEPAD_FACE_NORTH,
    RNR_GAMEPAD_LEFT_SHOULDER,
    RNR_GAMEPAD_RIGHT_SHOULDER,
    RNR_GAMEPAD_LEFT_TRIGGER,
    RNR_GAMEPAD_RIGHT_TRIGGER,
    RNR_GAMEPAD_START,
    RNR_GAMEPAD_BACK,
    RNR_GAMEPAD_LEFT_STICK_BUTTON,
    RNR_GAMEPAD_RIGHT_STICK_BUTTON,
    RNR_GAMEPAD_CONTROL_LAST = RNR_GAMEPAD_RIGHT_STICK_BUTTON
} RockNRollRacingGamepadControl;

typedef struct RockNRollRacingGamepadInputWin32 {
    SDL_Gamepad *handle;
    int initialized;
    int startup_gamepad_found;
    unsigned refresh_countdown;
    wchar_t name[160];
} RockNRollRacingGamepadInputWin32;

int rnr_gamepad_win32_initialize(RockNRollRacingGamepadInputWin32 *input,
                                     const wchar_t *mapping_path);
void rnr_gamepad_win32_shutdown(RockNRollRacingGamepadInputWin32 *input);
uint16_t rnr_gamepad_win32_poll(
    RockNRollRacingGamepadInputWin32 *input,
    const int bindings[RNR_GAMEPAD_BINDING_COUNT]);
int rnr_gamepad_win32_connected(const RockNRollRacingGamepadInputWin32 *input);
const wchar_t *rnr_gamepad_win32_name(const RockNRollRacingGamepadInputWin32 *input);
void rnr_gamepad_win32_default_bindings(
    int bindings[RNR_GAMEPAD_BINDING_COUNT]);
const wchar_t *rnr_gamepad_win32_control_name(int control);
int rnr_gamepad_win32_capture_control(RockNRollRacingGamepadInputWin32 *input);
void rnr_gamepad_win32_control_display_name(
    const RockNRollRacingGamepadInputWin32 *input, int control,
    wchar_t *text, size_t capacity);

#endif
