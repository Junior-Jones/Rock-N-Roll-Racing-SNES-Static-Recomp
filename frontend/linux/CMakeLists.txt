if(NOT LINUX)
  return()
endif()

set(RNR_SOURCE_ROOT "${CMAKE_CURRENT_LIST_DIR}/../..")

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

# Core instance + SHA-256 + input latch live in frontend/common and are
# shared by every non-Windows frontend. The Windows launcher keeps its own
# copies under frontend/windows and is untouched by this target.
add_executable(rnr-linux
  main_sdl3.c
  ../common/rnr_app_core.c
  ../common/rnr_sha256.c
  ../common/rnr_input_latch.c
)
target_include_directories(rnr-linux PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}"
  "${CMAKE_CURRENT_LIST_DIR}/../common"
  "${RNR_SOURCE_ROOT}/runtime"
  "${RNR_SOURCE_ROOT}/generated/current/v10_2/smp"
  "${RNR_SOURCE_ROOT}/generated/current/v10_2/scpu"
  "${RNR_SOURCE_ROOT}/generated/current/v10_2/timing"
)
target_link_libraries(rnr-linux PRIVATE rnr_v10_2_scpu SDL3::SDL3-static)
target_compile_options(rnr-linux PRIVATE -Wall -Wextra -Wpedantic)
set_target_properties(rnr-linux PROPERTIES
  OUTPUT_NAME "rock-n-roll-racing"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/linux"
)
