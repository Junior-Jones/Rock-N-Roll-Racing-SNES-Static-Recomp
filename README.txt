Rock n' Roll Racing (SNES) Static Recompilation - Source
Version 1.0.0

This package contains the Rock n' Roll Racing-specific static core and its
native Windows Launcher frontend. The original game ROM is not included.

Running the application
-----------------------

Place the verified Rock n' Roll Racing ROM in the Rom folder beside
Launcher.exe, then run Launcher.exe. Browse ROM can select the verified file
elsewhere. The complete ROM identity is checked before play is enabled.

Escape switches between gameplay and the launcher without resetting the
machine. Press 1 or 2 to save or load the current snapshot slot. F1 opens the
Welcome guide, F2/F3 open the Save/Load Snapshot windows, F4 opens Settings,
F5 opens Controller Bindings, F6 opens Audio Settings, F7 runs the selected
ROM and F8 captures a screenshot. Accepted settings and bindings are stored
in settings.ini beside Launcher.exe.

What fully static recompilation means
-------------------------------------

Rock n' Roll Racing executes through ahead-of-time native code generated from
the supported cartridge. Its W65C816/S-CPU instructions were analysed before
building and lowered into fixed C source. Production authority contains
24,835 exact PBR:PC:E:M:X contexts: 24,827 native bodies, five
scheduler-owned interrupt returns and three deliberate source terminals.
There are 28,911 guarded successor relations and an exact timing row for every
production context.

The generated S-CPU authority is losslessly compacted into 309 shared semantic
templates across 81 address shards. Every one of the 24,835 exact context
records remains present and selects frozen parameters for its original native
instruction body. Offline generation reconstructs and byte-compares all
normalized bodies before accepting the compact output. Generated C/header
source fell from 11,977,948 to 3,034,271 bytes, the Release static library from
8,693,312 to 3,280,010 bytes, and Launcher.exe from 7,635,968 to 5,480,448
bytes. This changes representation only: exact context identity, source-byte
guards, successor sets, interrupt/return ownership and fail-closed behavior are
preserved, with no runtime decoder or fallback added.

There is no general-purpose S-CPU interpreter, opcode decoder, JIT, dynamic
recompiler, runtime learning system or emulator fallback. Finite indirect
control-flow domains, interrupts and returns are source-proved and fail
closed. An unknown route stops and records the exact missing state.

Graphics, sound, races and player actions are computed live. Nothing is
prerecorded; executable game and audio-driver instructions are compiled ahead
of time.

Static machine coverage
-----------------------

The production core includes:

- Ahead-of-time W65C816/S-CPU game-code execution.
- LoROM mapping, 128 KiB WRAM, open bus and cartridge/machine bus behavior.
- CPU I/O, timers, NMI, IRQ, auto-joypad and controller serial ports.
- Native DMA and HDMA with scanline scheduling.
- NTSC master-clock, scanline, H-clock, refresh and frame scheduling.
- PPU register state, VRAM, CGRAM, OAM, backgrounds, objects, Mode 1,
  Mode 7, windows, color math, forced blank and completed framebuffers.
- Exact-PC ahead-of-time SPC700/S-SMP audio-driver execution.
- Exact 32-phase S-DSP execution and deterministic stereo PCM.
- Five integrity-checked full-machine snapshot slots.
- Fail-closed diagnostics containing CPU, SMP, DSP, scheduler, PPU, input,
  timing and machine-state evidence.

Static audio core
-----------------

Audio is fully generated inside the static core. The game's own SPC700 program
runs as 1,629 ahead-of-time exact-PC instruction bodies against project-owned
64 KiB audio RAM, timers, CPU/APU ports and DSP registers. There is no SPC700
interpreter and no emulator audio library linked into the application.

The project-owned S-DSP advances the authentic 32 internal phases and eight
voices. It covers BRR decoding and filters, Gaussian interpolation, pitch and
pitch modulation, ADSR/GAIN envelopes, key timing, noise, voice/master volume,
ENDX, echo addressing, eight-tap FIR echo, feedback, echo writes, clamping,
mute and reset behavior. The NTSC scheduler produces native 32,040 Hz signed
16-bit stereo PCM. A 180-second verification run produced 5,767,199 known PCM
frames, zero unknown frames and no static-core stop.

The Windows frontend drains completed DSP work into a bounded FIFO and sends
it to a DirectSound circular buffer. Native PCM is resampled to the selected
device rate with Hermite interpolation by default. Real play-cursor queue
measurement, bounded drift correction and underrun recovery keep host output
synchronized while machine time remains owned by the static core.

How Mesen and Snes9x were used
------------------------------

Mesen/MesenCE was used as an independent development oracle for selected boot,
framebuffer, input and timing comparisons. Mesen's mature frontend behavior
also informed pacing and device-queue checks. It is not included, linked or
called by the release and never provides a fallback.

Snes9x/byuu S-SMP sources supplied semantic-development reference material for
the offline SPC700 generator. Production contains only Rock n' Roll Racing's
finite exact-PC bodies, not Snes9x's interpreter or audio backend. The
applicable notice is included in SNES9X-LICENSE.txt.

ROM requirements
----------------

Title: Rock n' Roll Racing
Region: USA NTSC
Format: unheadered .sfc
Size: 1,048,576 bytes
SHA-256: 9d721753301278325c851f1843d669a697aed757dcf6495a31fc31ddf664b182

The ROM and original game assets are never included in source or release
archives.

Windows build
-------------

Requirements:

- CMake 3.24 or newer
- Visual Studio 2022 with the x64 C/C++ toolchain
- Internet access during first configuration so CMake can obtain SDL 3.4.10

From the source root:

  cmake -S . -B build -G "Visual Studio 17 2022" -A x64
  cmake --build build --config Release --parallel
  ctest --test-dir build -C Release --output-on-failure

The application is build\Release\Launcher.exe. Release builds statically link
the Visual C++ runtime and SDL3 gamepad support. Video/dialogs use Win32/GDI;
speaker output uses DirectSound.

The repository's Windows CI workflow performs the same Visual Studio 2022 x64
configuration, complete Release build and ROM-free CTest suite on every push
to main and every pull request. Its GitHub token permission is limited to
read-only repository contents.

Verification
------------

ROM-free tests cover static CPU semantics, machine reset, PPU behavior, the
static DSP, frontend/core reset, input latching, settings persistence, audio
resampling and audio settings. The source-only production verifier reconciles
the S-CPU graph, timing table, dynamic calls, interrupt graph, executable-WRAM
policy, S-SMP set and S-DSP phases without promoting trace or oracle results.

The corrected title/demo route was verified for 180 emulated seconds after a
second full source-discovery pass. Live racing, steering, weapons, boost,
snapshot continuation, screenshots, windowed/full-screen presentation and
audio output have also been exercised during development.

Frontend and release behavior
-----------------------------

See VERSION.txt for launcher, display, input, snapshot and audio features.
The first-run Welcome state is saved in settings.ini. Reopening it with F1 is
modal, scales to the monitor work area, supports keyboard navigation, and
returns keyboard focus to the previous valid launcher/game control when it
closes.

Failure logging
---------------

If the static core reaches an uncompiled execution or hardware state, the app
pauses and creates Logs\Static-Core-Failure-YYYYMMDD-HHMMSS-mmm.txt. A large
read-only error window shows the repair evidence and provides a Close button.
The logging path does not enable a fallback emulator.

Package contents
----------------

The Windows release contains Launcher.exe, README.txt, VERSION.txt,
THIRD-PARTY-NOTICES.txt, SDL-LICENSE.txt and SNES9X-LICENSE.txt, plus Rom and
Screenshots folders with short instruction files. Saves and Logs are created
only when needed. The archive excludes the ROM, settings.ini, snapshots,
captured screenshots, logs, test evidence and external controller databases.

Licensing and original game
---------------------------

SDL 3.4.10 is statically linked under its zlib license. The ahead-of-time
S-SMP semantic library carries the Snes9x/byuu notice and license. See
THIRD-PARTY-NOTICES.txt, SDL-LICENSE.txt and SNES9X-LICENSE.txt for the exact
notices and terms distributed with this project.

Rock n' Roll Racing, its ROM, music, graphics and other original assets are
not distributed. The user must provide the exact legally obtained ROM listed
under ROM requirements.
