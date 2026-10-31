# Linux frontend (SDL3)

Native Linux port of the Rock n' Roll Racing SNES static recompilation.
The Windows launcher (`frontend/windows`, Win32/GDI/DirectSound) is untouched;
this frontend implements the same portable core API (`rnr_static_recomp.h`)
with SDL3 video/audio/gamepad.

## Files

* `main_sdl3.c` — SDL3 window/renderer/texture, audio stream, keyboard+gamepad
  input, snapshot, screenshot, NTSC frame limiter.
* `rnr_app_core_linux.c` / `rnr_app_core_linux.h` — portable core instance
  (ROM load, frame convert, audio FIFO, snapshots). Only Win32 dependency of
  the original was BCrypt SHA-256, replaced here by `rnr_sha256.*`.
* `rnr_sha256.*` — public-domain SHA-256 for the ROM identity check.
* `rnr_audio_resampler.*`, `../common/rnr_input_latch.c` — reused as-is
  (portable).

## Build

```sh
cmake -S . -B build -DRNR_BUILD_WINDOWS_FRONTEND=OFF -DRNR_BUILD_LINUX_FRONTEND=ON \
  -DSDL_GPU_VULKAN=OFF -DSDL_RENDER_VULKAN=OFF
cmake --build build -j
ctest --test-dir build --output-on-failure
# binary:
./build/linux/rock-n-roll-racing
```

Needs CMake 3.24+, GCC/Clang, pkg-config, X11/Wayland dev libs, ALSA/Pulse.
SDL 3.4.10 is fetched automatically (same revision as the Windows build).

## Run

```sh
./build/linux/rock-n-roll-racing "<path to Rock N' Roll Racing (USA).sfc>" [snapshot_dir]
# or the AppImage (see packaging/appimage/):
./Rock-n-Roll-Racing-x86_64.AppImage "<path to ROM>"
```

ROM requirements (never bundled): unheadered USA 1,048,576 bytes,
SHA-256 `9d721753301278325c851f1843d669a697aed757dcf6495a31fc31ddf664b182`.
A 512-byte SMC header is stripped automatically if present.

Keys: Arrows move, `D/F/A/S` = B/A/Y/X, `E/R` = L/R, `G` = Start, `T` = Select,
`Z/X` classic aliases, `Enter` = Start, `Space` = Select.
`F5`/`1` save snapshot, `F9`/`2` load, `F8` screenshot BMP,
`F11`/`Alt+Enter` fullscreen, `Esc` quit. Gamepad is positional
(SOUTH→B, EAST→A, WEST→Y, NORTH→X).
