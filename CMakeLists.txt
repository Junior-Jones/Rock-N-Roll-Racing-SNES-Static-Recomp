cmake_minimum_required(VERSION 3.24)
project(RockNRollRacingV10_2CoreValidation C CXX)

if(POLICY CMP0091)
    cmake_policy(SET CMP0091 NEW)
endif()
if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB V10_2_SCPU_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/generated/current/v10_2/scpu/*.c")
file(GLOB V10_2_SMP_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/generated/current/v10_2/smp/*.cpp")

add_library(rnr_v10_2_scpu STATIC
    runtime/v05c_static_cpu.c
    runtime/v10_2_ppu.c
    runtime/v10_2_renderer.c
    runtime/v10_2_apu.cpp
    runtime/v10_2_audio/smp/smp.cpp
    runtime/v10_2_audio/dsp/project_static_dsp.c
    runtime/v10_2_audio/sc_static_apu.cpp
    runtime/v10_2_machine.c
    generated/current/v10_2/timing/js_v10_2_timing.c
    ${V10_2_SMP_SOURCES}
    ${V10_2_SCPU_SOURCES})

target_include_directories(rnr_v10_2_scpu PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/runtime"
    "${CMAKE_CURRENT_SOURCE_DIR}/runtime/v10_2_audio"
    "${CMAKE_CURRENT_SOURCE_DIR}/runtime/v10_2_audio/smp"
    "${CMAKE_CURRENT_SOURCE_DIR}/runtime/v10_2_audio/dsp"
    "${CMAKE_CURRENT_SOURCE_DIR}/generated/current/v10_2/smp"
    "${CMAKE_CURRENT_SOURCE_DIR}/generated/current/v10_2/scpu"
    "${CMAKE_CURRENT_SOURCE_DIR}/generated/current/v10_2/timing")

target_compile_definitions(rnr_v10_2_scpu PRIVATE SC_SMP_AOT=1)
if(MSVC)
    target_compile_options(rnr_v10_2_scpu PRIVATE /W4 /WX /permissive- /MP)
    set_source_files_properties(
        runtime/v10_2_audio/smp/smp.cpp
        ${V10_2_SMP_SOURCES}
        PROPERTIES COMPILE_OPTIONS "/W0;/O1")
else()
    target_compile_options(rnr_v10_2_scpu PRIVATE -Wall -Wextra -Wpedantic -Werror)
    set_source_files_properties(
        runtime/v10_2_audio/smp/smp.cpp
        ${V10_2_SMP_SOURCES}
        runtime/v10_2_audio/dsp/project_static_dsp.c
        PROPERTIES COMPILE_OPTIONS "-w")
endif()

enable_testing()
add_executable(test_v10_2_native tests/native/test_v10_2_native.c)
target_link_libraries(test_v10_2_native PRIVATE rnr_v10_2_scpu)
if(MSVC)
    target_compile_options(test_v10_2_native PRIVATE /W4 /WX /permissive-)
else()
    target_compile_options(test_v10_2_native PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
add_test(NAME v10_2_native COMMAND test_v10_2_native)

add_executable(test_v10_2_machine tests/native/test_v10_2_machine.c)
target_link_libraries(test_v10_2_machine PRIVATE rnr_v10_2_scpu)
if(MSVC)
    target_compile_options(test_v10_2_machine PRIVATE /W4 /WX /permissive-)
else()
    target_compile_options(test_v10_2_machine PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
add_test(NAME v10_2_machine COMMAND test_v10_2_machine)

add_executable(test_v10_2_ppu tests/native/test_v10_2_ppu.c)
target_link_libraries(test_v10_2_ppu PRIVATE rnr_v10_2_scpu)
if(MSVC)
    target_compile_options(test_v10_2_ppu PRIVATE /W4 /WX /permissive-)
else()
    target_compile_options(test_v10_2_ppu PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
add_test(NAME v10_2_ppu COMMAND test_v10_2_ppu)

add_executable(test_v10_2_audio tests/native/test_v10_2_audio.c)
target_link_libraries(test_v10_2_audio PRIVATE rnr_v10_2_scpu)
if(MSVC)
    target_compile_options(test_v10_2_audio PRIVATE /W4 /WX /permissive-)
else()
    target_compile_options(test_v10_2_audio PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
add_test(NAME v10_2_audio COMMAND test_v10_2_audio)

add_executable(test_v10_2_static_dsp
    tests/native/test_v10_2_static_dsp.c
    runtime/v10_2_audio/dsp/project_static_dsp.c)
target_include_directories(test_v10_2_static_dsp PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/runtime/v10_2_audio/dsp")
if(MSVC)
    target_compile_options(test_v10_2_static_dsp PRIVATE /W4 /WX /permissive-)
else()
    target_compile_options(test_v10_2_static_dsp PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
add_test(NAME v10_2_static_dsp COMMAND test_v10_2_static_dsp)

# Developer-only real-ROM gate. It is intentionally not registered with CTest:
# copyrighted ROM data is host supplied and never enters source or build output.
add_executable(v10_2_real_boot tests/native/v10_2_real_boot.c)
target_link_libraries(v10_2_real_boot PRIVATE rnr_v10_2_scpu)
if(MSVC)
    target_compile_options(v10_2_real_boot PRIVATE /W4 /WX /permissive-)
else()
    target_compile_options(v10_2_real_boot PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

option(RNR_BUILD_WINDOWS_FRONTEND "Build the complete Windows launcher" ON)
if(RNR_BUILD_WINDOWS_FRONTEND AND WIN32)
    add_subdirectory(frontend/windows)
endif()
