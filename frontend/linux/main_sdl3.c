// Rock n' Roll Racing (SNES) static-recomp Linux frontend (SDL3).
// Uses the portable core API in rnr_static_recomp.h.
// ROM is user-supplied, never bundled.
#include "rnr_static_recomp.h"
#include "rnr_app_core_linux.h"
#include "../common/rnr_input_latch.h"

#include <SDL3/SDL.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIN_W 1024
#define WIN_H 896

static uint16_t snes_mask_for_scancode(SDL_Scancode sc) {
  switch (sc) {
    case SDL_SCANCODE_UP: return RNR_INPUT_UP;
    case SDL_SCANCODE_DOWN: return RNR_INPUT_DOWN;
    case SDL_SCANCODE_LEFT: return RNR_INPUT_LEFT;
    case SDL_SCANCODE_RIGHT: return RNR_INPUT_RIGHT;
    // Accessible defaults: D=B F=A A=Y S=X E=L R=R G=Start T=Select
    case SDL_SCANCODE_D: return RNR_INPUT_B;
    case SDL_SCANCODE_F: return RNR_INPUT_A;
    case SDL_SCANCODE_A: return RNR_INPUT_Y;
    case SDL_SCANCODE_S: return RNR_INPUT_X;
    case SDL_SCANCODE_E: return RNR_INPUT_L;
    case SDL_SCANCODE_R: return RNR_INPUT_R;
    case SDL_SCANCODE_G: return RNR_INPUT_START;
    case SDL_SCANCODE_T: return RNR_INPUT_SELECT;
    // Classic aliases: Z=B X=A Enter=Start Space=Select
    case SDL_SCANCODE_Z: return RNR_INPUT_B;
    case SDL_SCANCODE_X: return RNR_INPUT_A;
    case SDL_SCANCODE_RETURN: case SDL_SCANCODE_KP_ENTER: return RNR_INPUT_START;
    case SDL_SCANCODE_SPACE: return RNR_INPUT_SELECT;
    default: return 0;
  }
}

static uint16_t opposite_of(uint16_t m) {
  if (m == RNR_INPUT_UP) return RNR_INPUT_DOWN;
  if (m == RNR_INPUT_DOWN) return RNR_INPUT_UP;
  if (m == RNR_INPUT_LEFT) return RNR_INPUT_RIGHT;
  if (m == RNR_INPUT_RIGHT) return RNR_INPUT_LEFT;
  return 0;
}

static uint8_t *load_file(const char *path, size_t *out_size) {
  FILE *f = fopen(path, "rb");
  uint8_t *buf;
  size_t n;
  long sz;
  if (!f) return NULL;
  if (fseek(f, 0, SEEK_END) != 0) { fclose(f); return NULL; }
  sz = ftell(f);
  if (sz <= 0) { fclose(f); return NULL; }
  rewind(f);
  buf = (uint8_t *)malloc((size_t)sz);
  if (!buf) { fclose(f); return NULL; }
  n = fread(buf, 1, (size_t)sz, f);
  fclose(f);
  if (n != (size_t)sz) { free(buf); return NULL; }
  *out_size = n;
  return buf;
}

static void print_usage(const char *prog) {
  fprintf(stderr,
    "Usage: %s <rom.sfc> [snapshot_dir]\n"
    "  ROM: unheadered USA 1MiB, SHA-256 9d721753...b182\n"
    "Keys: Arrows move, D/F/A/S = B/A/Y/X, E/R = L/R, G=Start T=Select\n"
    "  Z/X classic aliases, Enter=Start Space=Select\n"
    "  F5 save snapshot, F9 load, F8 screenshot BMP, F11/Alt+Enter fullscreen, Esc quit\n",
    prog);
}

int main(int argc, char **argv) {
  const char *rom_path = NULL;
  const char *snap_dir = ".";
  uint8_t *rom = NULL;
  size_t rom_size = 0;
  RockNRollRacingRecomp *core = NULL;
  char err[512] = {0};
  SDL_Window *win = NULL;
  SDL_Renderer *ren = NULL;
  SDL_Texture *tex = NULL;
  SDL_AudioDeviceID adevice = 0;
  SDL_AudioStream *astream = NULL;
  SDL_AudioSpec want;
  SDL_Gamepad *pad = NULL;
  RockNRollRacingInputLatch latch = {0};
  int running = 1, fullscreen = 0;
  Uint64 freq, next;
  double frame_ns;
  int frame_count = 0;

  if (argc < 2) { print_usage(argv[0]); return 1; }
  rom_path = argv[1];
  if (argc >= 3) snap_dir = argv[2];

  rom = load_file(rom_path, &rom_size);
  if (!rom) { fprintf(stderr, "Cannot read ROM: %s\n", rom_path); return 1; }
  // Strip SMC header if present (512 bytes -> 1MiB+512)
  if (rom_size == RNR_RECOMP_ROM_SIZE + 512) {
    memmove(rom, rom + 512, RNR_RECOMP_ROM_SIZE);
    rom_size = RNR_RECOMP_ROM_SIZE;
  }
  if (rom_size != RNR_RECOMP_ROM_SIZE) {
    fprintf(stderr, "ROM must be %u bytes, got %zu\n", RNR_RECOMP_ROM_SIZE, rom_size);
    free(rom); return 1;
  }

  if (!rnr_recomp_create(&core, rom, rom_size, err, sizeof(err))) {
    fprintf(stderr, "Core create failed: %s\n", err[0] ? err : "unknown");
    free(rom); return 1;
  }
  free(rom); rom = NULL;

  if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMEPAD)) {
    fprintf(stderr, "SDL_Init: %s\n", SDL_GetError());
    rnr_recomp_destroy(core); return 1;
  }

  win = SDL_CreateWindow("Rock n' Roll Racing (static recomp, Linux)",
                         WIN_W, WIN_H, SDL_WINDOW_RESIZABLE);
  if (!win) { fprintf(stderr, "Window: %s\n", SDL_GetError()); goto fail; }
  ren = SDL_CreateRenderer(win, NULL);
  if (!ren) { fprintf(stderr, "Renderer: %s\n", SDL_GetError()); goto fail; }
  tex = SDL_CreateTexture(ren, SDL_PIXELFORMAT_XRGB8888,
                          SDL_TEXTUREACCESS_STREAMING,
                          RNR_RECOMP_FRAME_WIDTH, RNR_RECOMP_FRAME_HEIGHT);
  if (!tex) { fprintf(stderr, "Texture: %s\n", SDL_GetError()); goto fail; }
  SDL_SetTextureScaleMode(tex, SDL_SCALEMODE_NEAREST);

  want.format = SDL_AUDIO_S16LE;
  want.channels = 2;
  want.freq = 48000;
  adevice = SDL_OpenAudioDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &want);
  if (!adevice) {
    fprintf(stderr, "Audio device: %s (continuing silent)\n", SDL_GetError());
  } else {
    SDL_AudioSpec src;
    src.format = SDL_AUDIO_S16LE;
    src.channels = 2;
    src.freq = RNR_RECOMP_AUDIO_SAMPLE_RATE;
    astream = SDL_CreateAudioStream(&src, &want);
    if (!astream) {
      fprintf(stderr, "AudioStream: %s (continuing silent)\n", SDL_GetError());
    } else {
      SDL_BindAudioStream(adevice, astream);
      SDL_ResumeAudioDevice(adevice);
    }
  }

  freq = SDL_GetPerformanceFrequency();
  frame_ns = 1e9 * (double)RNR_RECOMP_PRESENTATION_FPS_DENOMINATOR /
                   (double)RNR_RECOMP_PRESENTATION_FPS_NUMERATOR;
  next = SDL_GetPerformanceCounter();

  rnr_input_latch_reset(&latch);

  while (running) {
    SDL_Event ev;
    uint16_t held_extra = 0;
    // gamepad poll
    if (!pad) {
      int count = 0;
      SDL_JoystickID *ids = SDL_GetGamepads(&count);
      if (ids) {
        if (count > 0) pad = SDL_OpenGamepad(ids[0]);
        SDL_free(ids);
      }
    }
    if (pad) {
      if (!SDL_GamepadConnected(pad)) { SDL_CloseGamepad(pad); pad = NULL; }
      else {
        SDL_UpdateGamepads();
        if (SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_DPAD_UP)) held_extra |= RNR_INPUT_UP;
        if (SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_DPAD_DOWN)) held_extra |= RNR_INPUT_DOWN;
        if (SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_DPAD_LEFT)) held_extra |= RNR_INPUT_LEFT;
        if (SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_DPAD_RIGHT)) held_extra |= RNR_INPUT_RIGHT;
        // Positional: SOUTH(bottom/Xbox A)->SNES B, EAST(right/Xbox B)->SNES A
        // WEST(left/Xbox X)->SNES Y, NORTH(top/Xbox Y)->SNES X
        if (SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_SOUTH)) held_extra |= RNR_INPUT_B;
        if (SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_EAST)) held_extra |= RNR_INPUT_A;
        if (SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_WEST)) held_extra |= RNR_INPUT_Y;
        if (SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_NORTH)) held_extra |= RNR_INPUT_X;
        if (SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_LEFT_SHOULDER)) held_extra |= RNR_INPUT_L;
        if (SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER)) held_extra |= RNR_INPUT_R;
        if (SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_START)) held_extra |= RNR_INPUT_START;
        if (SDL_GetGamepadButton(pad, SDL_GAMEPAD_BUTTON_BACK)) held_extra |= RNR_INPUT_SELECT;
      }
    }

    while (SDL_PollEvent(&ev)) {
      if (ev.type == SDL_EVENT_QUIT) running = 0;
      else if (ev.type == SDL_EVENT_KEY_DOWN && !ev.key.repeat) {
        uint16_t m = snes_mask_for_scancode(ev.key.scancode);
        if (m) rnr_input_latch_press(&latch, m, opposite_of(m), 0);
        if (ev.key.scancode == SDL_SCANCODE_ESCAPE) running = 0;
        if (ev.key.scancode == SDL_SCANCODE_F11 ||
            ((ev.key.mod & SDL_KMOD_ALT) && ev.key.scancode == SDL_SCANCODE_RETURN)) {
          fullscreen = !fullscreen;
          SDL_SetWindowFullscreen(win, fullscreen);
        }
        if (ev.key.scancode == SDL_SCANCODE_F5) {
          char path[1024];
          snprintf(path, sizeof(path), "%s/rnr_snapshot1.bin", snap_dir);
          if (rnr_recomp_snapshot_save(core, path, err, sizeof(err)))
            SDL_SetWindowTitle(win, "Rock n' Roll Racing - snapshot saved");
          else
            fprintf(stderr, "Snapshot save failed: %s\n", err);
        }
        if (ev.key.scancode == SDL_SCANCODE_F9) {
          char path[1024];
          snprintf(path, sizeof(path), "%s/rnr_snapshot1.bin", snap_dir);
          if (rnr_recomp_snapshot_load(core, path, err, sizeof(err)))
            SDL_SetWindowTitle(win, "Rock n' Roll Racing (static recomp, Linux)");
          else
            fprintf(stderr, "Snapshot load failed: %s\n", err);
        }
        if (ev.key.scancode == SDL_SCANCODE_F8) {
          const uint32_t *px = rnr_recomp_frame_bgra(core);
          SDL_Surface *surf = SDL_CreateSurfaceFrom(
              RNR_RECOMP_FRAME_WIDTH, RNR_RECOMP_FRAME_HEIGHT,
              SDL_PIXELFORMAT_XRGB8888, (void *)px,
              RNR_RECOMP_FRAME_WIDTH * 4);
          if (surf) {
            char path[1024];
            snprintf(path, sizeof(path), "%s/rnr_shot_%d.bmp", snap_dir, frame_count);
            SDL_SaveBMP(surf, path);
            SDL_DestroySurface(surf);
            fprintf(stderr, "Screenshot: %s\n", path);
          }
        }
        if (ev.key.scancode == SDL_SCANCODE_1) { // alias save like Windows
          char path[1024];
          snprintf(path, sizeof(path), "%s/rnr_snapshot1.bin", snap_dir);
          rnr_recomp_snapshot_save(core, path, err, sizeof(err));
        }
        if (ev.key.scancode == SDL_SCANCODE_2) {
          char path[1024];
          snprintf(path, sizeof(path), "%s/rnr_snapshot1.bin", snap_dir);
          rnr_recomp_snapshot_load(core, path, err, sizeof(err));
        }
      } else if (ev.type == SDL_EVENT_KEY_UP) {
        uint16_t m = snes_mask_for_scancode(ev.key.scancode);
        if (m) rnr_input_latch_release(&latch, m);
      }
    }

    {
      uint16_t mask = (uint16_t)(rnr_input_latch_sample(&latch) | held_extra);
      RockNRollRacingRecompFrameResult res;
      if (!rnr_recomp_advance(core, mask, 1, &res)) {
        fprintf(stderr, "Core stopped: %s\n", rnr_recomp_last_error(core));
        {
          char log[1024];
          snprintf(log, sizeof(log), "%s/static-core-failure.log", snap_dir);
          rnr_recomp_write_diagnostic_log(core, log, "", err, sizeof(err));
        }
        running = 0;
        break;
      }
      rnr_input_latch_consume(&latch, mask);
    }

    {
      const uint32_t *px = rnr_recomp_frame_bgra(core);
      void *dst;
      int pitch;
      if (SDL_LockTexture(tex, NULL, &dst, &pitch)) {
        memcpy(dst, px, RNR_RECOMP_FRAME_WIDTH * RNR_RECOMP_FRAME_HEIGHT * 4);
        SDL_UnlockTexture(tex);
      }
      SDL_RenderTexture(ren, tex, NULL, NULL);
      SDL_RenderPresent(ren);
    }

    {
      size_t avail = rnr_recomp_audio_available(core);
      if (avail && astream) {
        static int16_t tmp[8192 * 2];
        while (avail > 0) {
          size_t chunk = avail > 8192 ? 8192 : avail;
          size_t got = rnr_recomp_audio_read(core, tmp, chunk);
          if (!got) break;
          SDL_PutAudioStreamData(astream, tmp, (int)(got * 2 * sizeof(int16_t)));
          avail -= got;
        }
        SDL_FlushAudioStream(astream);
      } else if (avail) {
        rnr_recomp_audio_read(core, NULL, 0); // keep FIFO bounded
        // drain silently to avoid unbounded growth
        static int16_t dump[8192 * 2];
        while (avail > 0) {
          size_t chunk = avail > 8192 ? 8192 : avail;
          size_t got = rnr_recomp_audio_read(core, dump, chunk);
          if (!got) break;
          avail -= got;
        }
      }
    }

    frame_count++;
    // NTSC frame lock ~60.0988fps
    {
      Uint64 target = next + (Uint64)(frame_ns * (double)freq / 1e9);
      Uint64 now = SDL_GetPerformanceCounter();
      if (target > now) {
        Uint64 ticks = target - now;
        double ms = 1000.0 * (double)ticks / (double)freq;
        if (ms >= 1.0) SDL_Delay((Uint32)(ms - 0.5));
        while (SDL_GetPerformanceCounter() < target) { /* spin */ }
      }
      next = target;
    }
  }

  if (pad) SDL_CloseGamepad(pad);
  if (astream) SDL_DestroyAudioStream(astream);
  if (adevice) SDL_CloseAudioDevice(adevice);
  if (tex) SDL_DestroyTexture(tex);
  if (ren) SDL_DestroyRenderer(ren);
  if (win) SDL_DestroyWindow(win);
  SDL_Quit();
  rnr_recomp_destroy(core);
  return 0;

fail:
  if (pad) SDL_CloseGamepad(pad);
  if (tex) SDL_DestroyTexture(tex);
  if (ren) SDL_DestroyRenderer(ren);
  if (win) SDL_DestroyWindow(win);
  SDL_Quit();
  rnr_recomp_destroy(core);
  return 1;
}
