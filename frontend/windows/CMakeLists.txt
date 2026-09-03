if(NOT WIN32)
  return()
endif()

set(RNR_SOURCE_ROOT "${CMAKE_CURRENT_LIST_DIR}/../..")
set(RNR_GAMEPAD_ADAPTER_DIR "${RNR_SOURCE_ROOT}/third_party/rnr-gamepad")

include(FetchContent)
set(SDL_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_STATIC ON CACHE BOOL "" FORCE)
set(SDL_TEST_LIBRARY OFF CACHE BOOL "" FORCE)
set(SDL_TESTS OFF CACHE BOOL "" FORCE)
set(SDL_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SDL_INSTALL OFF CACHE BOOL "" FORCE)
FetchContent_Declare(rnr_sdl
  URL "https://github.com/libsdl-org/SDL/archive/refs/tags/release-3.4.10.zip"
  URL_HASH "SHA256=30DCE54890B17544A35E4521274762016AF6ED59C2183B896EF5E6693E97FB6C"
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(rnr_sdl)

set(RNR_FRONTEND_INCLUDE_DIRS
  "${CMAKE_CURRENT_LIST_DIR}"
  "${CMAKE_CURRENT_LIST_DIR}/../common"
  "${RNR_SOURCE_ROOT}/runtime"
  "${RNR_SOURCE_ROOT}/generated/current/v10_2/scpu"
  "${RNR_SOURCE_ROOT}/generated/current/v10_2/timing"
  "${RNR_GAMEPAD_ADAPTER_DIR}"
)

add_executable(rnr-launcher WIN32
  rnr_launcher_win32.c
  rnr_app_core.c
  launcher_version.rc
  rnr_audio_output_dsound_win32.c
  rnr_audio_resampler.c
  rnr_frontend_settings_win32.c
  ../common/rnr_input_latch.c
  "${RNR_GAMEPAD_ADAPTER_DIR}/rnr_gamepad_input_win32.c"
)
target_include_directories(rnr-launcher PRIVATE ${RNR_FRONTEND_INCLUDE_DIRS})
target_link_libraries(rnr-launcher PRIVATE
  rnr_v10_2_scpu SDL3::SDL3-static
  user32 gdi32 comdlg32 comctl32 shell32 bcrypt dsound dxguid winmm
)
target_compile_definitions(rnr-launcher PRIVATE
  UNICODE _UNICODE WIN32_LEAN_AND_MEAN NOMINMAX _CRT_SECURE_NO_WARNINGS
)
if(MSVC)
  target_compile_options(rnr-launcher PRIVATE /W4 /WX /experimental:deterministic)
  target_link_options(rnr-launcher PRIVATE $<$<CONFIG:Release>:/Brepro>)
else()
  target_compile_options(rnr-launcher PRIVATE -Wall -Wextra -Wpedantic)
endif()
set_target_properties(rnr-launcher PROPERTIES
  OUTPUT_NAME "Launcher"
  RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/release"
)
add_custom_command(TARGET rnr-launcher POST_BUILD
  COMMAND "${CMAKE_COMMAND}" -E make_directory
    "$<TARGET_FILE_DIR:rnr-launcher>/Rom"
  COMMAND "${CMAKE_COMMAND}" -E make_directory
    "$<TARGET_FILE_DIR:rnr-launcher>/Screenshots"
  COMMAND "${CMAKE_COMMAND}" -E copy_if_different
    "${RNR_SOURCE_ROOT}/Rom/Readme.txt"
    "$<TARGET_FILE_DIR:rnr-launcher>/Rom/Readme.txt"
  COMMAND "${CMAKE_COMMAND}" -E copy_if_different
    "${RNR_SOURCE_ROOT}/Screenshots/Readme.txt"
    "$<TARGET_FILE_DIR:rnr-launcher>/Screenshots/Readme.txt"
  COMMAND "${CMAKE_COMMAND}" -E copy_if_different
    "${RNR_SOURCE_ROOT}/README.txt"
    "$<TARGET_FILE_DIR:rnr-launcher>/README.txt"
  COMMAND "${CMAKE_COMMAND}" -E copy_if_different
    "${RNR_SOURCE_ROOT}/VERSION.txt"
    "$<TARGET_FILE_DIR:rnr-launcher>/VERSION.txt"
  COMMAND "${CMAKE_COMMAND}" -E copy_if_different
    "${RNR_SOURCE_ROOT}/THIRD-PARTY-NOTICES.txt"
    "$<TARGET_FILE_DIR:rnr-launcher>/THIRD-PARTY-NOTICES.txt"
  COMMAND "${CMAKE_COMMAND}" -E copy_if_different
    "${RNR_SOURCE_ROOT}/SDL-LICENSE.txt"
    "$<TARGET_FILE_DIR:rnr-launcher>/SDL-LICENSE.txt"
  COMMAND "${CMAKE_COMMAND}" -E copy_if_different
    "${RNR_SOURCE_ROOT}/SNES9X-LICENSE.txt"
    "$<TARGET_FILE_DIR:rnr-launcher>/SNES9X-LICENSE.txt"
  VERBATIM
)

add_executable(rnr-frontend-core-test
  rnr_frontend_core_test.c
  rnr_app_core.c
)
target_include_directories(rnr-frontend-core-test PRIVATE ${RNR_FRONTEND_INCLUDE_DIRS})
target_link_libraries(rnr-frontend-core-test PRIVATE rnr_v10_2_scpu bcrypt)
target_compile_definitions(rnr-frontend-core-test PRIVATE _CRT_SECURE_NO_WARNINGS)

add_executable(rnr-input-contract-test
  ../common/rnr_input_contract_test.c
  ../common/rnr_input_latch.c
)
target_include_directories(rnr-input-contract-test PRIVATE ${RNR_FRONTEND_INCLUDE_DIRS})

add_executable(rnr-settings-input-contract-test
  rnr_settings_input_contract_test.c
  rnr_frontend_settings_win32.c
  "${RNR_GAMEPAD_ADAPTER_DIR}/rnr_gamepad_input_win32.c"
)
target_include_directories(rnr-settings-input-contract-test PRIVATE ${RNR_FRONTEND_INCLUDE_DIRS})
target_link_libraries(rnr-settings-input-contract-test PRIVATE
  SDL3::SDL3-static user32 comctl32
)
target_compile_definitions(rnr-settings-input-contract-test PRIVATE
  UNICODE _UNICODE WIN32_LEAN_AND_MEAN NOMINMAX _CRT_SECURE_NO_WARNINGS
)

add_executable(rnr-audio-resampler-test
  rnr_audio_resampler_test.c
  rnr_audio_resampler.c
)

add_executable(rnr-audio-settings-contract-test
  rnr_audio_settings_contract_test.c
  rnr_audio_output_dsound_win32.c
  rnr_audio_resampler.c
  rnr_app_core.c
)
target_include_directories(rnr-audio-settings-contract-test PRIVATE
  ${RNR_FRONTEND_INCLUDE_DIRS})
target_link_libraries(rnr-audio-settings-contract-test PRIVATE
  rnr_v10_2_scpu user32 dsound dxguid winmm bcrypt)
target_compile_definitions(rnr-audio-settings-contract-test PRIVATE
  UNICODE _UNICODE WIN32_LEAN_AND_MEAN NOMINMAX _CRT_SECURE_NO_WARNINGS)

add_executable(rnr-natural-route
  ../../tests/native/v10_2_natural_route.c
  rnr_app_core.c
)
target_include_directories(rnr-natural-route PRIVATE ${RNR_FRONTEND_INCLUDE_DIRS})
target_link_libraries(rnr-natural-route PRIVATE rnr_v10_2_scpu bcrypt)
target_compile_definitions(rnr-natural-route PRIVATE _CRT_SECURE_NO_WARNINGS)
target_include_directories(rnr-audio-resampler-test PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}"
)

foreach(test_target IN ITEMS
    rnr-frontend-core-test rnr-input-contract-test
    rnr-settings-input-contract-test rnr-audio-resampler-test
    rnr-audio-settings-contract-test rnr-natural-route)
  if(MSVC)
    target_compile_options(${test_target} PRIVATE /W4 /WX)
  else()
    target_compile_options(${test_target} PRIVATE -Wall -Wextra -Wpedantic)
  endif()
endforeach()

add_test(NAME rnr_frontend_core_reset COMMAND rnr-frontend-core-test)
add_test(NAME rnr_input_contract COMMAND rnr-input-contract-test)
add_test(NAME rnr_settings_input_contract COMMAND rnr-settings-input-contract-test)
add_test(NAME rnr_audio_resampler COMMAND rnr-audio-resampler-test)
add_test(NAME rnr_audio_settings_contract
  COMMAND rnr-audio-settings-contract-test)
