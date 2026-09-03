#include "js_v10_2_scpu_dispatch.h"
#include "js_v10_2_timing.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_SIZE (1u << 24)

typedef struct TestBus {
    uint8_t *memory;
    unsigned reads;
    unsigned writes;
} TestBus;

static int failures;

#define CHECK(condition) do { \
    if (!(condition)) { \
        fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #condition); \
        ++failures; \
    } \
} while (0)

static uint8_t read8(void *opaque, uint32_t address, int *ok) {
    TestBus *bus = (TestBus *)opaque;
    ++bus->reads;
    *ok = 1;
    return bus->memory[address & 0xFFFFFFu];
}

static void write8(void *opaque, uint32_t address, uint8_t value, int *ok) {
    TestBus *bus = (TestBus *)opaque;
    ++bus->writes;
    bus->memory[address & 0xFFFFFFu] = value;
    *ok = 1;
}

static JSCPU make_cpu(uint8_t bank, uint16_t pc, uint8_t e, uint8_t m, uint8_t x) {
    JSCPU cpu;
    memset(&cpu, 0, sizeof cpu);
    cpu.pbr = bank;
    cpu.pc = pc;
    cpu.e = e;
    cpu.s = 0x01FFu;
    if (m) cpu.p |= JS_P_M;
    if (x) cpu.p |= JS_P_X;
    return cpu;
}

static void test_membership_and_index(void) {
    JSCPU cpu = make_cpu(0x00u, 0x8000u, 1u, 1u, 1u);
    static const uint16_t allowed[] = {0u, 2u, 4u};
    CHECK(js_v10_2_scpu_has_context(&cpu));
    cpu = make_cpu(0x00u, 0x8166u, 0u, 0u, 0u);
    CHECK(js_v10_2_scpu_has_context(&cpu));
    cpu = make_cpu(0x7Fu, 0x1234u, 0u, 0u, 0u);
    CHECK(!js_v10_2_scpu_has_context(&cpu));
    CHECK(js_v10_2_scpu_index_allowed(2u, allowed, 3u));
    CHECK(!js_v10_2_scpu_index_allowed(3u, allowed, 3u));
}

static void test_reset_entry(void) {
    JSCPU cpu = make_cpu(0x00u, 0x8000u, 1u, 1u, 1u);
    JSStop stop;
    JSExecResult result = js_v10_2_scpu_step(&cpu, NULL, &stop);
    CHECK(result == JS_EXEC_OK);
    CHECK(cpu.pbr == 0x80u && cpu.pc == 0x800Cu);
}

static void test_native_rti(JSBus *bus, TestBus *memory) {
    JSCPU cpu = make_cpu(0x80u, 0x8196u, 0u, 0u, 0u);
    JSStop stop;
    JSExecResult result;
    memset(memory->memory, 0, MEMORY_SIZE);
    cpu.s = 0x01FBu;
    memory->memory[0x01FCu] = 0u;
    memory->memory[0x01FDu] = 0x2Eu;
    memory->memory[0x01FEu] = 0x80u;
    memory->memory[0x01FFu] = 0x80u;
    result = js_v10_2_scpu_step(&cpu, bus, &stop);
    CHECK(result == JS_EXEC_OK);
    CHECK(cpu.pbr == 0x80u && cpu.pc == 0x802Eu && cpu.s == 0x01FFu);

    cpu = make_cpu(0x80u, 0x8196u, 0u, 0u, 0u);
    cpu.s = 0x01FBu;
    memory->memory[0x01FCu] = 0u;
    memory->memory[0x01FDu] = 0x34u;
    memory->memory[0x01FEu] = 0x12u;
    memory->memory[0x01FFu] = 0x7Fu;
    result = js_v10_2_scpu_step(&cpu, bus, &stop);
    CHECK(result == JS_EXEC_STOP);
    CHECK(stop.reason == JS_STOP_UNPROVED_INTERRUPT_REENTRY);
}

static void test_dynamic_index_guard(JSBus *bus, TestBus *memory) {
    JSCPU cpu = make_cpu(0x80u, 0x8181u, 0u, 1u, 1u);
    JSStop stop;
    JSExecResult result;
    cpu.x = 1u;
    result = js_v10_2_scpu_step(&cpu, NULL, &stop);
    CHECK(result == JS_EXEC_STOP);
    CHECK(stop.reason == JS_STOP_UNPROVED_DYNAMIC_TARGET);

    memset(memory->memory, 0, MEMORY_SIZE);
    memory->reads = memory->writes = 0u;
    cpu = make_cpu(0x80u, 0x8181u, 0u, 1u, 1u);
    cpu.x = 0u;
    memory->memory[0x808197u] = 0xC0u;
    memory->memory[0x808198u] = 0x81u;
    result = js_v10_2_scpu_step(&cpu, bus, &stop);
    CHECK(result == JS_EXEC_OK);
    CHECK(cpu.pc == 0x81C0u && cpu.s == 0x01FDu);
    CHECK(memory->reads == 2u && memory->writes == 2u);
}

static void test_invalid_cpu_state(void) {
    JSCPU cpu = make_cpu(0x00u, 0x8000u, 1u, 1u, 1u);
    JSStop stop;
    JSExecResult result;
    cpu.p = 0u;
    result = js_v10_2_scpu_step(&cpu, NULL, &stop);
    CHECK(result == JS_EXEC_STOP && stop.reason == JS_STOP_INVALID_CPU_STATE);
}

static void test_unknown_context_fails_closed(void) {
    JSCPU cpu = make_cpu(0x7Fu, 0x1234u, 0u, 0u, 0u);
    JSStop stop;
    JSExecResult result = js_v10_2_scpu_step(&cpu, NULL, &stop);
    CHECK(result == JS_EXEC_STOP);
    CHECK(stop.reason == JS_STOP_UNKNOWN_CONTEXT);
    CHECK(stop.source_key == js_cpu_context_key(&cpu));
    CHECK(stop.observed_key == js_cpu_context_key(&cpu));
}

static void test_timing_manifest(void) {
    const JSV10_2TimingPlan *plan;
    const uint32_t indexed_rmw = JSV10_2_RULE_INDEX_FIXED_PRE_DATA_IDLE |
                                 JSV10_2_RULE_RMW_INTERMEDIATE_IDLE;
    CHECK(js_v10_2_timing_plan_count() == 24835u);
    plan = js_v10_2_timing_plan(0x00040007u); /* 00:8000:E1M1X1 */
    CHECK(plan != NULL && plan->opcode == 0x5Cu && plan->cycle_min == 4u);
    plan = js_v10_2_timing_plan(0x04040CB0u); /* 80:8196:E0M0X0 RTI */
    CHECK(plan != NULL && plan->opcode == 0x40u && plan->executable == 1u);
    plan = js_v10_2_timing_plan(0x040C5478u); /* 81:8A8F:E0M0X0 INC abs,X */
    CHECK(plan != NULL && plan->opcode == 0xFEu && plan->cycle_min == 9u);
    CHECK(plan != NULL && plan->rule_flags == indexed_rmw);
    CHECK(plan != NULL && strcmp(plan->rules,
          "INDEX_FIXED_PRE_DATA_IDLE;RMW_INTERMEDIATE_IDLE") == 0);
    plan = js_v10_2_timing_plan(0x0406F8FBu); /* 80:DF1F:E0M1X1 DEC dp,X */
    CHECK(plan != NULL && plan->opcode == 0xD6u && plan->cycle_min == 6u && plan->cycle_max == 7u);
    CHECK(plan != NULL && plan->rule_flags ==
          (indexed_rmw | JSV10_2_RULE_DYN_DIRECT_LOW_PRE_IDLE));
    plan = js_v10_2_timing_plan(0x04040C60u); /* 80:818C:E0M0X0 INC abs */
    CHECK(plan != NULL && plan->opcode == 0xEEu && plan->cycle_min == 8u);
    CHECK(plan != NULL && plan->rule_flags == JSV10_2_RULE_RMW_INTERMEDIATE_IDLE);
    plan = js_v10_2_timing_plan(0xFFFFFFFFu); /* outside the encoded context-key domain */
    CHECK(plan == NULL);
}

int main(void) {
    TestBus memory;
    JSBus bus;
    memory.memory = (uint8_t *)calloc(MEMORY_SIZE, 1u);
    if (!memory.memory) return 2;
    memory.reads = memory.writes = 0u;
    bus.opaque = &memory;
    bus.read8 = read8;
    bus.write8 = write8;
    test_membership_and_index();
    test_reset_entry();
    test_native_rti(&bus, &memory);
    test_dynamic_index_guard(&bus, &memory);
    test_invalid_cpu_state();
    test_unknown_context_fails_closed();
    test_timing_manifest();
    free(memory.memory);
    if (failures) {
        fprintf(stderr, "V10.2 native failures: %d\n", failures);
        return 1;
    }
    puts("V10.2 full S-CPU production/RTI/index-guard tests: PASS");
    return 0;
}
