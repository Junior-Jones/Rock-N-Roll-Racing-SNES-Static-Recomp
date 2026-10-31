// Rock n' Roll Racing (SNES) static-recomp Linux frontend (SDL3).
// Uses the portable core API in frontend/common (rnr_app_core.h).
// ROM is user-supplied, never bundled.
#include "rnr_static_recomp.h"
#include "rnr_app_core.h"
#include "rnr_input_latch.h"

#include <SDL3/SDL.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIN_W 1024
#define WIN_H 896
#define SNAP_SLOTS 5

// Action order matches the Windows frontend binding table:
// Up Down Left Right B A Y X L R Start Select.
static const uint16_t kActionMask[12] = {
  RNR_INPUT_UP, RNR_INPUT_DOWN, RNR_INPUT_LEFT, RNR_INPUT_RIGHT,
  RNR_INPUT_B, RNR_INPUT_A, RNR_INPUT_Y, RNR_INPUT_X,
  RNR_INPUT_L, RNR_INPUT_R, RNR_INPUT_START, RNR_INPUT_SELECT
};
static const char *kActionName[12] = {
  "Up", "Down", "Left", "Right",
  "B", "A", "Y", "X",
  "L", "R", "Start", "Select"
};

typedef struct Settings {
  int fullscreen;
  int show_fps;
  int pause_on_focus_loss;
  int snapshot_slot; // 0..SNAP_SLOTS-1
  SDL_Scancode kb[12];
  uint16_t gp[SDL_GAMEPAD_BUTTON_COUNT];
} Settings;

static void settings_defaults(Settings *s) {
  int i;
  memset(s, 0, sizeof(*s));
  s->pause_on_focus_loss = 1;
  s->kb[0] = SDL_SCANCODE_UP; s->kb[1] = SDL_SCANCODE_DOWN;
  s->kb[2] = SDL_SCANCODE_LEFT; s->kb[3] = SDL_SCANCODE_RIGHT;
  s->kb[4] = SDL_SCANCODE_D; s->kb[5] = SDL_SCANCODE_F;
  s->kb[6] = SDL_SCANCODE_A; s->kb[7] = SDL_SCANCODE_S;
  s->kb[8] = SDL_SCANCODE_E; s->kb[9] = SDL_SCANCODE_R;
  s->kb[10] = SDL_SCANCODE_G; s->kb[11] = SDL_SCANCODE_T;
  for (i = 0; i < SDL_GAMEPAD_BUTTON_COUNT; i++) s->gp[i] = 0;
  // Positional mapping: SOUTH(bottom)->B EAST(right)->A
  // WEST(left)->Y NORTH(top)->X (matches the SNES diamond).
  s->gp[SDL_GAMEPAD_BUTTON_SOUTH] = RNR_INPUT_B;
  s->gp[SDL_GAMEPAD_BUTTON_EAST] = RNR_INPUT_A;
  s->gp[SDL_GAMEPAD_BUTTON_WEST] = RNR_INPUT_Y;
  s->gp[SDL_GAMEPAD_BUTTON_NORTH] = RNR_INPUT_X;
  s->gp[SDL_GAMEPAD_BUTTON_LEFT_SHOULDER] = RNR_INPUT_L;
  s->gp[SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER] = RNR_INPUT_R;
  s->gp[SDL_GAMEPAD_BUTTON_START] = RNR_INPUT_START;
  s->gp[SDL_GAMEPAD_BUTTON_BACK] = RNR_INPUT_SELECT;
  s->gp[SDL_GAMEPAD_BUTTON_DPAD_UP] = RNR_INPUT_UP;
  s->gp[SDL_GAMEPAD_BUTTON_DPAD_DOWN] = RNR_INPUT_DOWN;
  s->gp[SDL_GAMEPAD_BUTTON_DPAD_LEFT] = RNR_INPUT_LEFT;
  s->gp[SDL_GAMEPAD_BUTTON_DPAD_RIGHT] = RNR_INPUT_RIGHT;
}

static int mask_for_action_name(const char *name, uint16_t *out) {
  int i;
  for (i = 0; i < 12; i++) {
    if (strcmp(name, kActionName[i]) == 0) { *out = kActionMask[i]; return 1; }
  }
  return 0;
}

static void settings_load(Settings *s, const char *path) {
  FILE *f = fopen(path, "r");
  char line[256], section[32] = "";
  if (!f) return;
  while (fgets(line, sizeof(line), f)) {
    char *eq, *key, *val;
    size_t n = strlen(line);
    while (n && (line[n-1] == '\n' || line[n-1] == '\r')) line[--n] = 0;
    if (!n || line[0] == '#' || line[0] == ';') continue;
    if (line[0] == '[') {
      size_t m = strlen(line);
      if (m > 2 && line[m-1] == ']') {
        memcpy(section, line + 1, m - 2 < sizeof(section)-1 ? m - 2 : sizeof(section)-1);
        section[m - 2 < sizeof(section)-1 ? m - 2 : sizeof(section)-1] = 0;
      }
      continue;
    }
    eq = strchr(line, '=');
    if (!eq) continue;
    *eq = 0; key = line; val = eq + 1;
    if (strcmp(section, "Video") == 0) {
      if (strcmp(key, "Fullscreen") == 0) s->fullscreen = atoi(val) != 0;
      if (strcmp(key, "ShowFPS") == 0) s->show_fps = atoi(val) != 0;
    } else if (strcmp(section, "Emulation") == 0) {
      if (strcmp(key, "PauseOnFocusLoss") == 0) s->pause_on_focus_loss = atoi(val) != 0;
      if (strcmp(key, "SnapshotSlot") == 0) {
        int slot = atoi(val);
        if (slot >= 0 && slot < SNAP_SLOTS) s->snapshot_slot = slot;
      }
    } else if (strcmp(section, "Keyboard") == 0) {
      int i;
      for (i = 0; i < 12; i++) {
        if (strcmp(key, kActionName[i]) == 0) {
          SDL_Scancode sc = SDL_GetScancodeFromName(val);
          if (sc != SDL_SCANCODE_UNKNOWN) s->kb[i] = sc;
        }
      }
    } else if (strcmp(section, "Gamepad") == 0) {
      // Key is an SDL gamepad button name (south/east/.../dpadup/...),
      // value is a SNES action name (Up/Down/.../B/A/...).
      static const struct { const char *name; int btn; } kBtn[] = {
        {"south", SDL_GAMEPAD_BUTTON_SOUTH}, {"east", SDL_GAMEPAD_BUTTON_EAST},
        {"west", SDL_GAMEPAD_BUTTON_WEST}, {"north", SDL_GAMEPAD_BUTTON_NORTH},
        {"back", SDL_GAMEPAD_BUTTON_BACK}, {"start", SDL_GAMEPAD_BUTTON_START},
        {"leftshoulder", SDL_GAMEPAD_BUTTON_LEFT_SHOULDER},
        {"rightshoulder", SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER},
        {"dpadup", SDL_GAMEPAD_BUTTON_DPAD_UP}, {"dpaddown", SDL_GAMEPAD_BUTTON_DPAD_DOWN},
        {"dpadleft", SDL_GAMEPAD_BUTTON_DPAD_LEFT}, {"dpadright", SDL_GAMEPAD_BUTTON_DPAD_RIGHT},
        {NULL, -1}
      };
      int b;
      uint16_t mask;
      char lower[32];
      size_t k;
      for (k = 0; k < sizeof(lower)-1 && key[k]; k++)
        lower[k] = (char)(key[k] >= 'A' && key[k] <= 'Z' ? key[k] + 32 : key[k]);
      lower[k] = 0;
      if (!mask_for_action_name(val, &mask)) continue;
      for (b = 0; kBtn[b].name; b++) {
        if (strcmp(lower, kBtn[b].name) == 0) { s->gp[kBtn[b].btn] = mask; break; }
      }
    }
  }
  fclose(f);
}

static void settings_save(const Settings *s, const char *path) {
  FILE *f = fopen(path, "w");
  int i;
  if (!f) return;
  fprintf(f, "# Rock n' Roll Racing Linux frontend settings.\n"
             "# Keyboard values are SDL scancode names; Gamepad values are SNES actions.\n"
             "[Video]\nFullscreen=%d\nShowFPS=%d\n"
             "[Emulation]\nPauseOnFocusLoss=%d\nSnapshotSlot=%d\n",
          !!s->fullscreen, !!s->show_fps,
          !!s->pause_on_focus_loss, s->snapshot_slot);
  fprintf(f, "[Keyboard]\n");
  for (i = 0; i < 12; i++)
    fprintf(f, "%s=%s\n", kActionName[i], SDL_GetScancodeName(s->kb[i]));
  fprintf(f, "[Gamepad]\n");
  {
    static const struct { const char *name; int btn; } kBtn[] = {
      {"south", SDL_GAMEPAD_BUTTON_SOUTH}, {"east", SDL_GAMEPAD_BUTTON_EAST},
      {"west", SDL_GAMEPAD_BUTTON_WEST}, {"north", SDL_GAMEPAD_BUTTON_NORTH},
      {"back", SDL_GAMEPAD_BUTTON_BACK}, {"start", SDL_GAMEPAD_BUTTON_START},
      {"leftshoulder", SDL_GAMEPAD_BUTTON_LEFT_SHOULDER},
      {"rightshoulder", SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER},
      {"dpadup", SDL_GAMEPAD_BUTTON_DPAD_UP}, {"dpaddown", SDL_GAMEPAD_BUTTON_DPAD_DOWN},
      {"dpadleft", SDL_GAMEPAD_BUTTON_DPAD_LEFT}, {"dpadright", SDL_GAMEPAD_BUTTON_DPAD_RIGHT},
      {NULL, -1}
    };
    for (i = 0; kBtn[i].name; i++) {
      int a;
      const char *aname = "";
      for (a = 0; a < 12; a++) {
        if (s->gp[kBtn[i].btn] == kActionMask[a]) { aname = kActionName[a]; break; }
      }
      if (aname[0]) fprintf(f, "%s=%s\n", kBtn[i].name, aname);
    }
  }
  fclose(f);
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
    "  ROM: unheadered USA 1MiB, SHA-256 9d721753...b182 (never bundled)\n"
    "  settings.ini lives beside the executable; edit it to rebind keys/gamepad.\n"
    "Keys: Arrows move, D/F/A/S = B/A/Y/X, E/R = L/R, G=Start T=Select\n"
    "  F5 save / F9 load snapshot slot, 1-5 select slot, F8 screenshot BMP\n"
    "  F10 FPS display, F11/Alt+Enter fullscreen, Esc quit\n",
    prog);
}

int main(int argc, char **argv) {
  const char *rom_path = NULL;
  const char *snap_dir = ".";
  uint8_t *rom = NULL;
  size_t rom_size = 0;
  RockNRollRacingRecomp *core = NULL;
  char err[512] = {0};
  char settings_path[1024] = "settings.ini";
  SDL_Window *win = NULL;
  SDL_Renderer *ren = NULL;
  SDL_Texture *tex = NULL;
  SDL_AudioDeviceID adevice = 0;
  SDL_AudioStream *astream = NULL;
  SDL_AudioSpec want;
  SDL_Gamepad *pad = NULL;
  RockNRollRacingInputLatch latch = {0};
  Settings settings;
  int running = 1, paused = 0;
  Uint64 freq, next, fps_last;
  double frame_ns, fps_ema = 60.0;
  int frame_count = 0, fps_frames = 0;
  char title[128];

  if (argc < 2) { print_usage(argv[0]); return 1; }
  rom_path = argv[1];
  if (argc >= 3) snap_dir = argv[2];

  // settings.ini lives beside the executable (mirrors the Windows layout).
  {
    // NOTE: do not SDL_free() this pointer; SDL owns the cached base path
    // and frees it during SDL_Quit (freeing it here double-frees).
    const char *base = SDL_GetBasePath();
    if (base)
      snprintf(settings_path, sizeof(settings_path), "%ssettings.ini", base);
  }
  settings_defaults(&settings);
  settings_load(&settings, settings_path);

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
  if (settings.fullscreen) SDL_SetWindowFullscreen(win, true);

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
  fps_last = next;

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
        int b;
        SDL_UpdateGamepads();
        for (b = 0; b < SDL_GAMEPAD_BUTTON_COUNT; b++) {
          if (settings.gp[b] && SDL_GetGamepadButton(pad, b))
            held_extra |= settings.gp[b];
        }
      }
    }

    while (SDL_PollEvent(&ev)) {
      if (ev.type == SDL_EVENT_QUIT) running = 0;
      else if (ev.type == SDL_EVENT_WINDOW_FOCUS_LOST && settings.pause_on_focus_loss && !paused) {
        paused = 1;
        SDL_SetWindowTitle(win, "Rock n' Roll Racing - paused (focus lost)");
      }
      else if (ev.type == SDL_EVENT_WINDOW_FOCUS_GAINED && paused) {
        paused = 0;
        next = SDL_GetPerformanceCounter(); // avoid time-debt burst
      }
      else if (ev.type == SDL_EVENT_KEY_DOWN && !ev.key.repeat) {
        int a;
        uint16_t m = 0;
        for (a = 0; a < 12; a++) {
          if (ev.key.scancode == settings.kb[a]) { m = kActionMask[a]; break; }
        }
        if (m) rnr_input_latch_press(&latch, m, opposite_of(m), 0);
        if (ev.key.scancode == SDL_SCANCODE_ESCAPE) running = 0;
        if (ev.key.scancode == SDL_SCANCODE_F11 ||
            ((ev.key.mod & SDL_KMOD_ALT) && ev.key.scancode == SDL_SCANCODE_RETURN)) {
          settings.fullscreen = !settings.fullscreen;
          SDL_SetWindowFullscreen(win, settings.fullscreen);
          settings_save(&settings, settings_path);
        }
        if (ev.key.scancode == SDL_SCANCODE_F10) {
          settings.show_fps = !settings.show_fps;
          settings_save(&settings, settings_path);
          if (!settings.show_fps)
            SDL_SetWindowTitle(win, "Rock n' Roll Racing (static recomp, Linux)");
        }
        if (ev.key.scancode == SDL_SCANCODE_F5) {
          char path[1024];
          snprintf(path, sizeof(path), "%s/rnr_snapshot%d.bin", snap_dir, settings.snapshot_slot + 1);
          if (!rnr_recomp_snapshot_save(core, path, err, sizeof(err)))
            fprintf(stderr, "Snapshot save failed: %s\n", err);
        }
        if (ev.key.scancode == SDL_SCANCODE_F9) {
          char path[1024];
          snprintf(path, sizeof(path), "%s/rnr_snapshot%d.bin", snap_dir, settings.snapshot_slot + 1);
          if (!rnr_recomp_snapshot_load(core, path, err, sizeof(err)))
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
        if (ev.key.scancode >= SDL_SCANCODE_1 && ev.key.scancode <= SDL_SCANCODE_5) {
          settings.snapshot_slot = ev.key.scancode - SDL_SCANCODE_1;
          settings_save(&settings, settings_path);
        }
        if (paused && ev.key.scancode != SDL_SCANCODE_ESCAPE) {
          paused = 0;
          next = SDL_GetPerformanceCounter();
        }
      } else if (ev.type == SDL_EVENT_KEY_UP) {
        int a;
        for (a = 0; a < 12; a++) {
          if (ev.key.scancode == settings.kb[a]) {
            rnr_input_latch_release(&latch, kActionMask[a]);
            break;
          }
        }
      }
    }

    if (!paused) {
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
        // Bounded queue: never hold more than ~200ms or latency grows forever.
        const int queued = SDL_GetAudioStreamQueued(astream);
        static int16_t tmp[8192 * 2];
        size_t budget = (size_t)(48000 / 5); // 200ms in frames
        size_t queued_frames = queued >= 0 ? (size_t)queued / 4 : 0;
        while (avail > 0 && queued_frames < budget) {
          size_t chunk = avail > 8192 ? 8192 : avail;
          if (chunk > budget - queued_frames) chunk = budget - queued_frames;
          size_t got = rnr_recomp_audio_read(core, tmp, chunk);
          if (!got) break;
          SDL_PutAudioStreamData(astream, tmp, (int)(got * 2 * sizeof(int16_t)));
          avail -= got;
          queued_frames += got;
          // 32040Hz core -> 48000Hz device expands ~1.5x; account roughly.
          queued_frames += got / 2;
        }
        if (avail > 0) {
          // Output is backed up: drop instead of building latency.
          static int16_t drop[4096 * 2];
          while (avail > 0) {
            size_t chunk = avail > 4096 ? 4096 : avail;
            size_t got = rnr_recomp_audio_read(core, drop, chunk);
            if (!got) break;
            avail -= got;
          }
        }
        SDL_FlushAudioStream(astream);
      } else if (avail) {
        // No audio device: drain the FIFO so it cannot grow unbounded.
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
    fps_frames++;
    {
      Uint64 now = SDL_GetPerformanceCounter();
      double dt = (double)(now - fps_last) / (double)freq;
      if (dt > 0) {
        double inst = 1.0 / dt;
        fps_ema += (inst - fps_ema) * 0.05;
      }
      fps_last = now;
      if (settings.show_fps && fps_frames >= 30) {
        snprintf(title, sizeof(title),
                 "Rock n' Roll Racing - %.1f fps (slot %d)%s",
                 fps_ema, settings.snapshot_slot + 1, paused ? " [paused]" : "");
        SDL_SetWindowTitle(win, title);
        fps_frames = 0;
      }
    }
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

  settings_save(&settings, settings_path);
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
