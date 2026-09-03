#if !defined(_WIN32)
#error This test requires Windows.
#endif

#include <windows.h>

#include <stdio.h>
#include <string.h>

#include "rnr_frontend_settings_win32.h"
#include "rnr_static_recomp.h"

#define CHECK(expression) do { \
    if (!(expression)) { \
        fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #expression); \
        return 1; \
    } \
} while (0)

int main(void)
{
    static const UINT accessible_keys[RNR_WIN_BINDING_COUNT] = {
        VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT,
        'D', 'F', 'A', 'S', 'E', 'R', 'G', 'T'
    };
    static const uint16_t masks[RNR_WIN_BINDING_COUNT] = {
        RNR_INPUT_UP, RNR_INPUT_DOWN, RNR_INPUT_LEFT,
        RNR_INPUT_RIGHT, RNR_INPUT_B, RNR_INPUT_A,
        RNR_INPUT_Y, RNR_INPUT_X, RNR_INPUT_L,
        RNR_INPUT_R, RNR_INPUT_START, RNR_INPUT_SELECT
    };
    static const int gamepad[RNR_WIN_BINDING_COUNT] = {
        RNR_GAMEPAD_DPAD_UP, RNR_GAMEPAD_DPAD_DOWN,
        RNR_GAMEPAD_DPAD_LEFT, RNR_GAMEPAD_DPAD_RIGHT,
        RNR_GAMEPAD_FACE_SOUTH, RNR_GAMEPAD_FACE_EAST,
        RNR_GAMEPAD_FACE_WEST, RNR_GAMEPAD_FACE_NORTH,
        RNR_GAMEPAD_LEFT_SHOULDER, RNR_GAMEPAD_RIGHT_SHOULDER,
        RNR_GAMEPAD_START, RNR_GAMEPAD_BACK
    };
    RockNRollRacingFrontendSettingsWin32 settings;
    RockNRollRacingFrontendSettingsWin32 loaded;
    wchar_t path[MAX_PATH];
    int index;

    CHECK(GetFullPathNameW(L"rnr-input-settings-contract.ini", MAX_PATH,
                           path, NULL) > 0u);
    (void)DeleteFileW(path);

    rnr_frontend_settings_win32_defaults(&settings);
    for (index = 0; index < RNR_WIN_BINDING_COUNT; ++index) {
        CHECK(settings.bindings[index] == accessible_keys[index]);
        CHECK(settings.gamepad_bindings[index] == gamepad[index]);
        CHECK(rnr_frontend_settings_win32_input(
                  &settings, settings.bindings[index]) == masks[index]);
    }
    CHECK(settings.bindings[10] == 'G');
    CHECK(settings.bindings[11] == 'T');

    settings.input_source = RNR_INPUT_SOURCE_GAMEPAD;
    settings.welcome_shown = 1;
    settings.snapshot_slot = 4;
    CHECK(rnr_frontend_settings_win32_save(&settings, path));
    memset(&loaded, 0, sizeof(loaded));
    rnr_frontend_settings_win32_load(&loaded, path);
    CHECK(loaded.input_source == RNR_INPUT_SOURCE_GAMEPAD);
    CHECK(loaded.input_source_saved == 1);
    CHECK(loaded.welcome_shown == 1);
    CHECK(loaded.snapshot_slot == 4);
    for (index = 0; index < RNR_WIN_BINDING_COUNT; ++index) {
        CHECK(loaded.bindings[index] == accessible_keys[index]);
        CHECK(loaded.gamepad_bindings[index] == gamepad[index]);
        CHECK(rnr_frontend_settings_win32_input(
                  &loaded, loaded.bindings[index]) == masks[index]);
    }

    CHECK(WritePrivateProfileStringW(L"Input", L"Action10", L"84", path));
    CHECK(WritePrivateProfileStringW(L"Input", L"Action11", L"71", path));
    rnr_frontend_settings_win32_load(&loaded, path);
    CHECK(loaded.bindings[10] == 'T');
    CHECK(loaded.bindings[11] == 'G');
    CHECK(rnr_frontend_settings_win32_input(&loaded, 'T') ==
          RNR_INPUT_START);
    CHECK(rnr_frontend_settings_win32_input(&loaded, 'G') ==
          RNR_INPUT_SELECT);

    CHECK(WritePrivateProfileStringW(L"Input", L"Action11", L"84", path));
    rnr_frontend_settings_win32_load(&loaded, path);
    CHECK(loaded.bindings[10] == 'G');
    CHECK(loaded.bindings[11] == 'T');
    CHECK(rnr_frontend_settings_win32_input(&loaded, 'G') ==
          RNR_INPUT_START);
    CHECK(rnr_frontend_settings_win32_input(&loaded, 'T') ==
          RNR_INPUT_SELECT);

    CHECK(DeleteFileW(path));
    puts("PASS keyboard/gamepad action order, settings round-trip, and invalid-binding recovery");
    return 0;
}
