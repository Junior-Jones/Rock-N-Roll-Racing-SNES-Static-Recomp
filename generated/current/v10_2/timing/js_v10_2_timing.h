#ifndef ROCKNROLL_V10_2_TIMING_H
#define ROCKNROLL_V10_2_TIMING_H
#include <stddef.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
typedef enum JSV10_2Mode {
    JSV10_2_MODE_ABS=0,
    JSV10_2_MODE_ABS_IND=1,
    JSV10_2_MODE_ABS_JUMP=2,
    JSV10_2_MODE_ABS_LONG=3,
    JSV10_2_MODE_ABS_LONG_X=4,
    JSV10_2_MODE_ABS_X=5,
    JSV10_2_MODE_ABS_X_IND=6,
    JSV10_2_MODE_ABS_Y=7,
    JSV10_2_MODE_ABSL_JUMP=8,
    JSV10_2_MODE_ACC=9,
    JSV10_2_MODE_BLOCK=10,
    JSV10_2_MODE_DP=11,
    JSV10_2_MODE_DP_IND=12,
    JSV10_2_MODE_DP_IND_LONG=13,
    JSV10_2_MODE_DP_IND_LONG_Y=14,
    JSV10_2_MODE_DP_IND_Y=15,
    JSV10_2_MODE_DP_X=16,
    JSV10_2_MODE_IMM_M=17,
    JSV10_2_MODE_IMM_X=18,
    JSV10_2_MODE_IMM16=19,
    JSV10_2_MODE_IMM8=20,
    JSV10_2_MODE_IMP=21,
    JSV10_2_MODE_REL16=22,
    JSV10_2_MODE_REL8=23,
    JSV10_2_MODE_STACK_REL=24
} JSV10_2Mode;
#define JSV10_2_RULE_DYN_DIRECT_LOW_PRE_IDLE 0x00000001u
#define JSV10_2_RULE_DYN_INDEX_PRE_DATA_IDLE 0x00000002u
#define JSV10_2_RULE_DYN_BRANCH_TAKEN_POST_IDLE 0x00000004u
#define JSV10_2_RULE_DYN_BRANCH_PAGE_POST_IDLE 0x00000008u
#define JSV10_2_RULE_JSL_AFTER_PBR_PUSH_IDLE 0x00000010u
#define JSV10_2_RULE_JSR_PRE_STACK_IDLE 0x00000020u
#define JSV10_2_RULE_JSR_XIND_MID_IDLE 0x00000040u
#define JSV10_2_RULE_RETURN_PRE_IDLE 0x00000080u
#define JSV10_2_RULE_RTS_POST_POP_IDLE 0x00000100u
#define JSV10_2_RULE_PUSH_PRE_IDLE 0x00000200u
#define JSV10_2_RULE_PULL_PRE_IDLE 0x00000400u
#define JSV10_2_RULE_IMPLIED_PRE_IDLE 0x00000800u
#define JSV10_2_RULE_XBA_EXTRA_IDLE 0x00001000u
#define JSV10_2_RULE_STATUS_PRE_IDLE 0x00002000u
#define JSV10_2_RULE_BRANCH_ALWAYS_POST_IDLE 0x00004000u
#define JSV10_2_RULE_RELLONG_PRE_IDLE 0x00008000u
#define JSV10_2_RULE_RMW_INTERMEDIATE_IDLE 0x00010000u
#define JSV10_2_RULE_STACK_REL_PRE_DATA_IDLE 0x00020000u
#define JSV10_2_RULE_INDEX_FIXED_PRE_DATA_IDLE 0x00040000u
#define JSV10_2_RULE_JUMP_XIND_PRE_POINTER_IDLE 0x00080000u
#define JSV10_2_RULE_BLOCK_MOVE_PRE_READ_IDLE 0x00100000u
#define JSV10_2_RULE_BLOCK_MOVE_POST_WRITE_IDLE 0x00200000u
typedef struct JSV10_2TimingPlan {
    uint32_t key, address, operand, rule_flags;
    uint8_t opcode, length, e, m, x, mode, cycle_min, cycle_max;
    uint8_t fetch_bytes, pointer_reads, data_reads, data_writes, dummy_writes;
    uint8_t stack_reads, stack_writes, vector_reads, fixed_idles, dynamic_idle_max;
    uint8_t executable;
    uint8_t bytes[4];
    const char *timing_class;
    const char *rules;
} JSV10_2TimingPlan;
const JSV10_2TimingPlan *js_v10_2_timing_plan(uint32_t key);
size_t js_v10_2_timing_plan_count(void);
#ifdef __cplusplus
}
#endif
#endif
