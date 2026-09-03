#ifndef RNR_INPUT_LATCH_H
#define RNR_INPUT_LATCH_H

#include <stdint.h>

typedef struct RockNRollRacingInputLatch {
    uint16_t held;
    uint16_t pending_press;
} RockNRollRacingInputLatch;

void rnr_input_latch_reset(RockNRollRacingInputLatch *latch);
void rnr_input_latch_press(RockNRollRacingInputLatch *latch, uint16_t mask,
                           uint16_t unsampled_opposite_mask, int repeated);
void rnr_input_latch_release(RockNRollRacingInputLatch *latch, uint16_t mask);
uint16_t rnr_input_latch_sample(const RockNRollRacingInputLatch *latch);
void rnr_input_latch_consume(RockNRollRacingInputLatch *latch, uint16_t sampled_mask);

#endif
