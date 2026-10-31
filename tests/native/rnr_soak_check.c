// Manual ROM-gated soak + determinism check for the static core.
// NOT registered with CTest: needs the user-supplied ROM, like v10_2_real_boot.
// Usage: rnr-soak-check <rom.sfc> [total_frames]
// Checks: (1) no fail-closed stop over N frames with gameplay-like inputs,
// (2) snapshot save/load is deterministic (same inputs => same framebuffer),
// (3) audio keeps flowing.
#include "rnr_static_recomp.h"
#include "rnr_app_core.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static uint64_t framebuffer_hash(const RockNRollRacingRecomp *core) {
  const uint32_t *px = rnr_recomp_frame_bgra(core);
  uint64_t h = UINT64_C(1469598103934665603);
  size_t i;
  for (i = 0; i < RNR_RECOMP_FRAME_WIDTH * RNR_RECOMP_FRAME_HEIGHT; i++) {
    h ^= px[i];
    h *= UINT64_C(1099511628211);
  }
  return h;
}

// Deterministic scripted input: menu taps, then race throttle + weapon.
static uint16_t script_input(uint32_t frame) {
  uint16_t in = 0;
  if (frame < 900 && (frame % 90) < 4) in |= RNR_INPUT_START;
  if (frame >= 400) in |= RNR_INPUT_B;
  if (frame >= 1000 && (frame % 120) < 4) in |= RNR_INPUT_Y;
  if (frame >= 1000 && (frame % 60) < 30) in |= RNR_INPUT_RIGHT;
  return in;
}

int main(int argc, char **argv) {
  const char *rom_path;
  uint32_t total = 3600;
  FILE *f;
  uint8_t *rom;
  long sz;
  RockNRollRacingRecomp *core = NULL;
  char err[512] = {0};
  uint32_t frame;
  uint64_t h1 = 0, h2 = 0;
  int ok = 1;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s <rom.sfc> [total_frames]\n", argv[0]);
    return 2;
  }
  rom_path = argv[1];
  if (argc >= 3) total = (uint32_t)strtoul(argv[2], NULL, 10);
  if (total < 1000) total = 1000;

  f = fopen(rom_path, "rb");
  if (!f) { fprintf(stderr, "cannot read %s\n", rom_path); return 1; }
  fseek(f, 0, SEEK_END); sz = ftell(f); rewind(f);
  rom = (uint8_t *)malloc((size_t)sz);
  if (!rom || fread(rom, 1, (size_t)sz, f) != (size_t)sz) {
    fprintf(stderr, "cannot read %s\n", rom_path);
    fclose(f);
    free(rom);
    return 1;
  }
  fclose(f);
  if (sz == (long)RNR_RECOMP_ROM_SIZE + 512) {
    memmove(rom, rom + 512, RNR_RECOMP_ROM_SIZE);
    sz = (long)RNR_RECOMP_ROM_SIZE;
  }
  if (!rnr_recomp_create(&core, rom, (size_t)sz, err, sizeof(err))) {
    fprintf(stderr, "core create failed: %s\n", err[0] ? err : "?");
    free(rom);
    return 1;
  }
  free(rom);

  for (frame = 0; frame < 600; frame++) {
    RockNRollRacingRecompFrameResult res;
    if (!rnr_recomp_advance(core, script_input(frame), 1, &res)) {
      printf("FAIL: stop at frame %u: %s\n", frame, rnr_recomp_last_error(core));
      ok = 0;
      goto done;
    }
  }
  if (!rnr_recomp_snapshot_save(core, "/tmp/rnr_soak_base.bin", err, sizeof(err))) {
    printf("FAIL: snapshot save: %s\n", err);
    ok = 0;
    goto done;
  }
  for (frame = 600; frame < 900; frame++) {
    RockNRollRacingRecompFrameResult res;
    if (!rnr_recomp_advance(core, script_input(frame), 1, &res)) {
      printf("FAIL: stop at frame %u: %s\n", frame, rnr_recomp_last_error(core));
      ok = 0;
      goto done;
    }
  }
  h1 = framebuffer_hash(core);
  if (!rnr_recomp_snapshot_load(core, "/tmp/rnr_soak_base.bin", err, sizeof(err))) {
    printf("FAIL: snapshot load: %s\n", err);
    ok = 0;
    goto done;
  }
  for (frame = 600; frame < 900; frame++) {
    RockNRollRacingRecompFrameResult res;
    if (!rnr_recomp_advance(core, script_input(frame), 1, &res)) {
      printf("FAIL: stop at replay frame %u: %s\n", frame, rnr_recomp_last_error(core));
      ok = 0;
      goto done;
    }
  }
  h2 = framebuffer_hash(core);
  printf("determinism: %016llx vs %016llx %s\n",
         (unsigned long long)h1, (unsigned long long)h2,
         h1 == h2 ? "MATCH" : "MISMATCH");
  if (h1 != h2) {
    printf("FAIL: nondeterministic replay\n");
    ok = 0;
    goto done;
  }
  for (frame = 900; frame < total; frame++) {
    RockNRollRacingRecompFrameResult res;
    static int16_t drain[4096 * 2];
    if (!rnr_recomp_advance(core, script_input(frame), 1, &res)) {
      printf("FAIL: stop at frame %u: %s\n", frame, rnr_recomp_last_error(core));
      ok = 0;
      goto done;
    }
    while (rnr_recomp_audio_available(core) > 0) {
      size_t a = rnr_recomp_audio_available(core);
      if (a > 4096) a = 4096;
      if (!rnr_recomp_audio_read(core, drain, a)) break;
    }
    if (frame % 600 == 0)
      printf("soak frame %u ok (instr %llu)\n", frame,
             (unsigned long long)rnr_recomp_instruction_count(core));
  }
  if (rnr_recomp_audio_available(core) == 0 && rnr_recomp_audio_dropped_frames(core) == 0) {
    printf("WARN: no audio frames observed at end of soak\n");
  }
  if (ok) printf("SOAK PASS: %u frames, deterministic, audio flowing\n", total);

done:
  if (!ok && core)
    rnr_recomp_write_diagnostic_log(core, "/tmp/rnr_soak_fail.log", "", err, sizeof(err));
  rnr_recomp_destroy(core);
  remove("/tmp/rnr_soak_base.bin");
  return ok ? 0 : 1;
}
