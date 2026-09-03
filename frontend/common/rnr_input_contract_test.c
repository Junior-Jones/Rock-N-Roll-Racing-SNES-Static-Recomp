#include <stdio.h>

#include "rnr_input_latch.h"
#include "rnr_static_recomp.h"

#define CHECK(expression) do { \
    if (!(expression)) { \
        fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #expression); \
        return 1; \
    } \
} while (0)

int main(void)
{
    static const uint16_t frontend[] = {
        RNR_INPUT_B, RNR_INPUT_Y, RNR_INPUT_SELECT,
        RNR_INPUT_START, RNR_INPUT_UP, RNR_INPUT_DOWN,
        RNR_INPUT_LEFT, RNR_INPUT_RIGHT, RNR_INPUT_A,
        RNR_INPUT_X, RNR_INPUT_L, RNR_INPUT_R
    };
    static const uint16_t snes_serial_bits[] = {
        0x8000u, 0x4000u, 0x2000u, 0x1000u,
        0x0800u, 0x0400u, 0x0200u, 0x0100u,
        0x0080u, 0x0040u, 0x0020u, 0x0010u
    };
    RockNRollRacingInputLatch latch = { 0u, 0u };
    size_t index;

    for (index = 0u; index < sizeof(frontend) / sizeof(frontend[0]); ++index) {
        CHECK(frontend[index] == snes_serial_bits[index]);
        rnr_input_latch_reset(&latch);
        rnr_input_latch_press(&latch, frontend[index], 0u, 0);
        CHECK(rnr_input_latch_sample(&latch) == frontend[index]);
        rnr_input_latch_release(&latch, frontend[index]);
        CHECK(rnr_input_latch_sample(&latch) == frontend[index]);
        rnr_input_latch_consume(&latch, frontend[index]);
        CHECK(rnr_input_latch_sample(&latch) == 0u);
    }

    rnr_input_latch_press(&latch, RNR_INPUT_LEFT,
                             RNR_INPUT_RIGHT, 0);
    rnr_input_latch_press(&latch, RNR_INPUT_RIGHT,
                             RNR_INPUT_LEFT, 0);
    CHECK((latch.held & (RNR_INPUT_LEFT | RNR_INPUT_RIGHT)) ==
          (RNR_INPUT_LEFT | RNR_INPUT_RIGHT));
    CHECK(latch.pending_press == RNR_INPUT_RIGHT);
    rnr_input_latch_reset(&latch);
    CHECK(rnr_input_latch_sample(&latch) == 0u);

    puts("PASS all frontend/core button constants and keyboard press/release latch routes");
    return 0;
}
