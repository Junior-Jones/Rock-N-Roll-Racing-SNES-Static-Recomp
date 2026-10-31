# Linux frontend (SDL3)

Native Linux port of the Rock n' Roll Racing SNES static recompilation.
The Windows launcher (`frontend/windows`, Win32/GDI/DirectSound) is untouched;
this frontend implements the same portable core API (`rnr_static_recomp.h`,
shared via `frontend/common/`) with SDL3 video/audio/gamepad.

## Files

* `main_sdl3.c` — SDL3 window/renderer/texture, audio stream with bounded
  queue (~200ms cap, drops instead of building latency), keyboard+gamepad
  input, 5 snapshot slots, screenshots, NTSC frame lock, FPS display,
  focus-loss pause, `settings.ini` persistence.
* `frontend/common/` — shared portable code: core instance (`rnr_app_core.*`),
  public-domain SHA-256 ROM check (`rnr_sha256.*`), canonical
  `rnr_static_recomp.h`, input latch.

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
Strict `-Wall -Wextra -Wpedantic -Werror` on all targets; `ctest` runs the
ROM-free core tests plus the SHA-256 vector test.

## Run

```sh
./build/linux/rock-n-roll-racing "<path to Rock N' Roll Racing (USA).sfc>" [snapshot_dir]
# or the AppImage (see packaging/appimage/):
./Rock-n-Roll-Racing-x86_64.AppImage "<path to ROM>"
```

ROM requirements (never bundled): unheadered USA 1,048,576 bytes,
SHA-256 `9d721753301278325c851f1843d669a697aed757dcf6495a31fc31ddf664b182`.
A 512-byte SMC header is stripped automatically if present.

Default keys: Arrows move, `D/F/A/S` = B/A/Y/X, `E/R` = L/R, `G` = Start,
`T` = Select, `Z/X` classic aliases, `Enter` = Start, `Space` = Select.
Gamepad is positional (SOUTH→B, EAST→A, WEST→Y, NORTH→X).

* `F5` save / `F9` load snapshot slot, `1`-`5` select slot (persisted)
* `F8` screenshot BMP, `F10` FPS display, `F11`/`Alt+Enter` fullscreen, `Esc` quit
* Window focus loss pauses (configurable); audio queue is bounded so latency
  cannot grow without bound when the output backs up.

`settings.ini` lives beside the executable (mirrors the Windows layout) and
stores video/emulation flags, the snapshot slot, keyboard scancodes and the
gamepad map — edit it to rebind. Section sample:

```ini
[Video]
Fullscreen=0
ShowFPS=0
[Emulation]
PauseOnFocusLoss=1
SnapshotSlot=0
[Keyboard]
Up=Up
B=D
Start=G
[Gamepad]
south=B
east=A
```

## Manual ROM-gated checks (not in `ctest`)

* `build/v10_2_real_boot` — upstream deep-boot tracer (portable `fopen`
  wrapper; needs ROM).
* `build/rnr-soak-check <rom> [frames]` — advances N frames with gameplay-like
  inputs, verifies snapshot save/load replay is framebuffer-identical and that
  audio keeps flowing. 3600 frames (~1 min) by default.
