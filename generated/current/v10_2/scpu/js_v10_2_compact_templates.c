/* generated compact exact-context semantic templates - do not edit */
/* Exact key records select these templates; no ROM opcode is decoded. */
#include "js_v10_2_scpu_dispatch.h"

static JSExecResult js_v10_2_template_000(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint16_t value = ((uint16_t)p[2]);
    js_op_load_a(cpu, value, ((uint8_t)p[3]));
    const uint32_t allowed[] = { ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_001(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
    cpu->pc = ((uint16_t)p[2]);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_002(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_003(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_load_a(cpu, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_004(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_005(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (((uint8_t)p[2])));
    const uint32_t allowed[] = { ((uint32_t)p[3]), ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_006(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    js_op_sep(cpu, ((uint8_t)p[2]));
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_007(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_C);
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_008(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    js_op_rep(cpu, ((uint8_t)p[2]));
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_009(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_x(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_load_a(cpu, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_00A(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint16_t value = ((uint16_t)p[2]);
    js_op_compare(cpu, cpu->a, value, ((uint8_t)p[3]));
    const uint32_t allowed[] = { ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_00B(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint16_t value = ((uint16_t)p[2]);
    js_op_load_x(cpu, value, ((uint8_t)p[3]));
    const uint32_t allowed[] = { ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_00C(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint16_t value = ((uint16_t)p[2]);
    js_op_load_y(cpu, value, ((uint8_t)p[3]));
    const uint32_t allowed[] = { ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_00D(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_load_a(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_00E(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_00F(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    js_op_load_a(cpu, js_op_asl(cpu, cpu->a, ((uint8_t)p[2])), ((uint8_t)p[2]));
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_010(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint16_t value = ((uint16_t)p[2]);
    js_op_and(cpu, value, ((uint8_t)p[3]));
    const uint32_t allowed[] = { ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_011(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (((uint8_t)p[2])));
    const uint32_t allowed[] = { ((uint32_t)p[3]), ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_012(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_013(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
    if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
    cpu->pbr = ((uint8_t)p[2]);
    cpu->pc = ((uint16_t)p[3]);
    js_cpu_normalize(cpu);
    const uint32_t allowed[] = { ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_014(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_015(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint16_t value = ((uint16_t)p[2]);
    js_op_adc(cpu, value, ((uint8_t)p[3]));
    const uint32_t allowed[] = { ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_016(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_x(cpu, ((uint16_t)p[2]));
    if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_017(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_y(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_load_a(cpu, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_018(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    cpu->p = (uint8_t)(cpu->p | JS_P_C);
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_019(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    js_op_transfer(cpu, 'A');
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_01A(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    if (js_branch_condition(cpu, 'A')) cpu->pc = (uint16_t)(cpu->pc + (((uint8_t)p[2])));
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_01B(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    if (js_branch_condition(cpu, 'C')) cpu->pc = (uint16_t)(cpu->pc + (((uint8_t)p[2])));
    const uint32_t allowed[] = { ((uint32_t)p[3]), ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_01C(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_load_a(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_01D(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_load_x(cpu, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_01E(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_y(cpu, ((uint16_t)p[2]));
    if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_01F(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, ((uint8_t)p[2])), ((uint8_t)p[2]));
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_020(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    js_op_load_a(cpu, js_op_incdec(cpu, cpu->a, 1, ((uint8_t)p[2])), ((uint8_t)p[2]));
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_021(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_022(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    if (js_branch_condition(cpu, 'D')) cpu->pc = (uint16_t)(cpu->pc + (((uint8_t)p[2])));
    const uint32_t allowed[] = { ((uint32_t)p[3]), ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_023(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_x(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_load_a(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_024(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_x(cpu, ((uint16_t)p[2]));
    if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_025(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    if (!js_stack_push16(cpu, bus, (uint16_t)cpu->a, 1, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_026(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_y(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_load_a(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_027(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    js_op_transfer(cpu, 'B');
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_028(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_029(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-((uint8_t)p[2])));
    const uint32_t allowed[] = { ((uint32_t)p[3]), ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_02A(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, 1, ((uint8_t)p[2])), ((uint8_t)p[2]));
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_02B(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_load_y(cpu, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_02C(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    cpu->pc = ((uint16_t)p[2]);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_02D(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    js_op_load_a(cpu, js_op_lsr(cpu, cpu->a, ((uint8_t)p[2])), ((uint8_t)p[2]));
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_02E(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 16u); }
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_02F(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_load_a(cpu, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_030(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_x(cpu, ((uint16_t)p[2]));
    if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_031(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_032(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_033(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t original = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
    uint16_t result = js_op_incdec(cpu, original, 1, 8u);
    if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_034(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    js_op_transfer(cpu, 'F');
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_035(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    if (!js_stack_push8(cpu, bus, cpu->dbr, 1, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_036(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_y(cpu, ((uint16_t)p[2]));
    if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_037(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    if (!js_stack_push8(cpu, bus, cpu->pbr, 1, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_038(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_long_x(cpu, ((uint32_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 1, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_load_a(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_039(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, -1, ((uint8_t)p[2])), ((uint8_t)p[2]));
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_03A(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint16_t value = ((uint16_t)p[2]);
    js_op_sbc(cpu, value, ((uint8_t)p[3]));
    const uint32_t allowed[] = { ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_03B(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_load_x(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_03C(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_adc(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_03D(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    js_op_load_a(cpu, js_op_incdec(cpu, cpu->a, -1, ((uint8_t)p[2])), ((uint8_t)p[2]));
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_03E(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint16_t value = ((uint16_t)p[2]);
    js_op_compare(cpu, cpu->x, value, ((uint8_t)p[3]));
    const uint32_t allowed[] = { ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_03F(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    if (js_branch_condition(cpu, 'A')) cpu->pc = (uint16_t)(cpu->pc + (-((uint8_t)p[2])));
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_040(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    if (js_branch_condition(cpu, 'M')) cpu->pc = (uint16_t)(cpu->pc + (((uint8_t)p[2])));
    const uint32_t allowed[] = { ((uint32_t)p[3]), ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_041(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    uint16_t original = 0u;
    if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
    uint16_t result = js_op_incdec(cpu, original, 1, 16u);
    if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_042(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint16_t value = ((uint16_t)p[2]);
    js_op_compare(cpu, cpu->y, value, ((uint8_t)p[3]));
    const uint32_t allowed[] = { ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_043(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint16_t value = ((uint16_t)p[2]);
    js_op_eor(cpu, value, ((uint8_t)p[3]));
    const uint32_t allowed[] = { ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_044(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (-((uint8_t)p[2])));
    const uint32_t allowed[] = { ((uint32_t)p[3]), ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_045(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]), ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_046(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    js_op_transfer(cpu, 'H');
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_047(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_adc(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_048(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]), ((uint32_t)p[4]), ((uint32_t)p[5]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_049(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    if (js_branch_condition(cpu, 'P')) cpu->pc = (uint16_t)(cpu->pc + (((uint8_t)p[2])));
    const uint32_t allowed[] = { ((uint32_t)p[3]), ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_04A(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_04B(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    if (!js_stack_push16(cpu, bus, (uint16_t)cpu->x, 1, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_04C(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, -1, ((uint8_t)p[2])), ((uint8_t)p[2]));
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_04D(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_load_y(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_04E(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_load_x(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_04F(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 8u); }
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_050(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    cpu->pc = (uint16_t)(cpu->pc + (-((uint16_t)p[2])));
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_051(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = 0u;
    if (!js_addr_dp_ind_y(cpu, bus, ((uint8_t)p[2]), &ea, stop, source_key)) return JS_EXEC_STOP;
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_load_a(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_052(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_adc(cpu, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_053(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_y(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_load_x(cpu, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_054(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_x(cpu, v, 8u); }
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_055(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint16_t value = ((uint16_t)p[2]);
    js_op_bit(cpu, value, ((uint8_t)p[3]), 1);
    const uint32_t allowed[] = { ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_056(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_x(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_057(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_x(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_load_y(cpu, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_058(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_x(cpu, v, 16u); }
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_059(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    if (!js_stack_push16(cpu, bus, (uint16_t)cpu->y, 1, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_05A(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    if (!js_stack_push8(cpu, bus, cpu->p, 1, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_05B(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    if (js_branch_condition(cpu, 'P')) cpu->pc = (uint16_t)(cpu->pc + (-((uint8_t)p[2])));
    const uint32_t allowed[] = { ((uint32_t)p[3]), ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_05C(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    uint16_t original = 0u;
    if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
    uint16_t result = js_op_incdec(cpu, original, -1, 16u);
    if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_05D(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_y(cpu, v, 16u); }
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_05E(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_05F(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_sbc(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_060(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    if (js_branch_condition(cpu, 'C')) cpu->pc = (uint16_t)(cpu->pc + (-((uint8_t)p[2])));
    const uint32_t allowed[] = { ((uint32_t)p[3]), ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_061(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_x(cpu, ((uint16_t)p[2]));
    if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_062(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_stack_rel(cpu, ((uint8_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_load_a(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_063(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_x(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_064(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_sbc(cpu, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_065(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; cpu->p = (uint8_t)(v | (cpu->e ? (JS_P_M|JS_P_X) : 0u)); js_cpu_normalize(cpu); }
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_066(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    js_op_xba(cpu);
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_067(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint16_t value = ((uint16_t)p[2]);
    js_op_ora(cpu, value, ((uint8_t)p[3]));
    const uint32_t allowed[] = { ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_068(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_compare(cpu, cpu->a, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_069(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_y(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_06A(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_load_y(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_06B(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    if (!js_stack_push16(cpu, bus, ((uint16_t)p[2]), 0, stop, source_key)) return JS_EXEC_STOP;
    js_cpu_normalize(cpu);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_06C(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_x(cpu, ((uint16_t)p[2]));
    uint16_t original = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
    uint16_t result = js_op_incdec(cpu, original, 1, 8u);
    if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_06D(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_x(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_06E(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    if (!js_stack_push8(cpu, bus, (uint8_t)cpu->a, 1, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_06F(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_070(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_y(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_071(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]), ((uint32_t)p[4]), ((uint32_t)p[5]), ((uint32_t)p[6]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_072(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_long_x(cpu, ((uint32_t)p[2]));
    if (!js_bus_write16(bus, ea, 1, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_073(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_compare(cpu, cpu->a, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_074(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    cpu->pc = (uint16_t)(cpu->pc + (((uint16_t)p[2])));
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_075(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t original = 0u;
    if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
    uint16_t result = js_op_incdec(cpu, original, 1, 16u);
    if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_076(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t original = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
    uint16_t result = js_op_incdec(cpu, original, -1, 8u);
    if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_077(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_x(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_adc(cpu, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_078(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    uint16_t original = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
    uint16_t result = js_op_incdec(cpu, original, 1, 8u);
    if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_079(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp_x(cpu, ((uint8_t)p[2]));
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_load_a(cpu, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_07A(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_sbc(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_07B(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_x(cpu, ((uint16_t)p[2]));
    uint16_t original = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
    uint16_t result = js_op_incdec(cpu, original, -1, 8u);
    if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_07C(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    js_op_load_a(cpu, js_op_rol(cpu, cpu->a, ((uint8_t)p[2])), ((uint8_t)p[2]));
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_07D(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_x(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_sbc(cpu, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_07E(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    if (!js_stack_push8(cpu, bus, (uint8_t)cpu->y, 1, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_07F(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    js_op_load_a(cpu, js_op_ror(cpu, cpu->a, 16u), 16u);
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_080(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t original = 0u;
    if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
    uint16_t result = js_op_incdec(cpu, original, -1, 16u);
    if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_081(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    if (!js_stack_push8(cpu, bus, (uint8_t)cpu->x, 1, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_082(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    if (js_branch_condition(cpu, 'D')) cpu->pc = (uint16_t)(cpu->pc + (-((uint8_t)p[2])));
    const uint32_t allowed[] = { ((uint32_t)p[3]), ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_083(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_y(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_sbc(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_084(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_adc(cpu, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_085(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]), ((uint32_t)p[4]), ((uint32_t)p[5]), ((uint32_t)p[6]), ((uint32_t)p[7]), ((uint32_t)p[8]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_086(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_y(cpu, v, 8u); }
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_087(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = 0u;
    if (!js_addr_dp_ind_y(cpu, bus, ((uint8_t)p[2]), &ea, stop, source_key)) return JS_EXEC_STOP;
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_load_a(cpu, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_088(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_y(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_adc(cpu, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_089(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_stack_rel(cpu, ((uint8_t)p[2]));
    if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_08A(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp_x(cpu, ((uint8_t)p[2]));
    if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_08B(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = 0u;
    if (!js_addr_dp_ind(cpu, bus, ((uint8_t)p[2]), &ea, stop, source_key)) return JS_EXEC_STOP;
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_load_a(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_08C(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_y(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_08D(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]), ((uint32_t)p[4]), ((uint32_t)p[5]), ((uint32_t)p[6]), ((uint32_t)p[7]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_08E(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]), ((uint32_t)p[4]), ((uint32_t)p[5]), ((uint32_t)p[6]), ((uint32_t)p[7]), ((uint32_t)p[8]), ((uint32_t)p[9]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_08F(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_long(((uint32_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 1, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_load_a(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_090(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_x(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_load_y(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_091(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_y(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_adc(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_092(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_x(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_093(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_094(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_D);
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_095(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    cpu->pbr = ((uint8_t)p[2]);
    cpu->pc = ((uint16_t)p[3]);
    const uint32_t allowed[] = { ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_096(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = 0u;
    if (!js_addr_dp_ind_long_y(cpu, bus, ((uint8_t)p[2]), &ea, stop, source_key)) return JS_EXEC_STOP;
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 1, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_load_a(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_097(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = 0u;
    if (!js_addr_dp_ind_long_y(cpu, bus, ((uint8_t)p[2]), &ea, stop, source_key)) return JS_EXEC_STOP;
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_load_a(cpu, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_098(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp_x(cpu, ((uint8_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_load_a(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_099(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = 0u;
    if (!js_addr_dp_ind_long(cpu, bus, ((uint8_t)p[2]), &ea, stop, source_key)) return JS_EXEC_STOP;
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 1, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_load_a(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_09A(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_ora(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_09B(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_y(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_load_x(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_09C(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_y(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_compare(cpu, cpu->a, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_09D(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]), ((uint32_t)p[4]), ((uint32_t)p[5]), ((uint32_t)p[6]), ((uint32_t)p[7]), ((uint32_t)p[8]), ((uint32_t)p[9]), ((uint32_t)p[10]), ((uint32_t)p[11]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_09E(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_ora(cpu, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_09F(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_sbc(cpu, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0A0(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp_x(cpu, ((uint8_t)p[2]));
    if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0A1(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]), ((uint32_t)p[4]), ((uint32_t)p[5]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0A2(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    cpu->p = (uint8_t)(cpu->p | JS_P_I);
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0A3(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_x(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_adc(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0A4(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_x(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_ora(cpu, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0A5(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    uint16_t original = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
    uint16_t result = js_op_incdec(cpu, original, -1, 8u);
    if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0A6(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_compare(cpu, cpu->a, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0A7(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_load_x(cpu, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0A8(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]), ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0A9(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    cpu->p = (uint8_t)(cpu->p | JS_P_D);
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0AA(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_long(((uint32_t)p[2]));
    if (!js_bus_write16(bus, ea, 1, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0AB(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_x(cpu, ((uint16_t)p[2]));
    uint16_t original = 0u;
    if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
    uint16_t result = js_op_incdec(cpu, original, -1, 16u);
    if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0AC(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_x(cpu, ((uint16_t)p[2]));
    uint16_t original = 0u;
    if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
    uint16_t result = js_op_incdec(cpu, original, 1, 16u);
    if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0AD(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    uint16_t original = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
    uint16_t result = js_op_rol(cpu, original, 8u);
    if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0AE(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]), ((uint32_t)p[4]), ((uint32_t)p[5]), ((uint32_t)p[6]), ((uint32_t)p[7]), ((uint32_t)p[8]), ((uint32_t)p[9]), ((uint32_t)p[10]), ((uint32_t)p[11]), ((uint32_t)p[12]), ((uint32_t)p[13]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0AF(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0B0(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; cpu->p = (uint8_t)(v | (cpu->e ? (JS_P_M|JS_P_X) : 0u)); js_cpu_normalize(cpu); }
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0B1(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    js_op_transfer(cpu, 'D');
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0B2(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = 0u;
    if (!js_addr_dp_ind_long(cpu, bus, ((uint8_t)p[2]), &ea, stop, source_key)) return JS_EXEC_STOP;
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_load_a(cpu, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0B3(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t original = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
    uint16_t result = js_op_asl(cpu, original, 8u);
    if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0B4(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_x(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_sbc(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0B5(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_x(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_compare(cpu, cpu->a, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0B6(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    uint16_t original = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
    uint16_t result = js_op_asl(cpu, original, 8u);
    if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0B7(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_load_y(cpu, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0B8(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_I);
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0B9(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    js_op_transfer(cpu, 'K');
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0BA(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = 0u;
    if (!js_addr_dp_ind_long(cpu, bus, ((uint8_t)p[2]), &ea, stop, source_key)) return JS_EXEC_STOP;
    if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0BB(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = 0u;
    if (!js_addr_dp_ind_long_y(cpu, bus, ((uint8_t)p[2]), &ea, stop, source_key)) return JS_EXEC_STOP;
    if (!js_bus_write16(bus, ea, 1, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0BC(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t original = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
    uint16_t result = js_op_rol(cpu, original, 8u);
    if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0BD(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    uint16_t original = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
    uint16_t result = js_op_ror(cpu, original, 8u);
    if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0BE(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    cpu->dbr = 0x7Eu;
    uint32_t source_address = ((uint32_t)((uint8_t)p[2]) << 16) | (cpu->x & 0xFFFFu);
    uint32_t destination_address = ((uint32_t)0x7Eu << 16) | (cpu->y & 0xFFFFu);
    uint8_t moved = 0u;
    if (!js_bus_read8(bus, source_address, &moved, stop, source_key)) return JS_EXEC_STOP;
    if (!js_bus_write8(bus, destination_address, moved, stop, source_key)) return JS_EXEC_STOP;
    cpu->x = (uint16_t)((cpu->x + 1u) & 0xFFFFu);
    cpu->y = (uint16_t)((cpu->y + 1u) & 0xFFFFu);
    { uint16_t before = cpu->a; cpu->a = (uint16_t)(cpu->a - 1u);
      cpu->pc = before != 0u ? ((uint16_t)p[3]) : ((uint16_t)p[1]); }
    const uint32_t allowed[] = { ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0BF(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_eor(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0C0(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_y(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0C1(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]), ((uint32_t)p[4]), ((uint32_t)p[5]), ((uint32_t)p[6]), ((uint32_t)p[7]), ((uint32_t)p[8]), ((uint32_t)p[9]), ((uint32_t)p[10]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0C2(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]), ((uint32_t)p[4]), ((uint32_t)p[5]), ((uint32_t)p[6]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0C3(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t v = 0u;
      if (!js_read_dp16(cpu, bus, ((uint8_t)p[2]), &v, stop, source_key)) return JS_EXEC_STOP;
      if (!js_stack_push16(cpu, bus, v, 1, stop, source_key)) return JS_EXEC_STOP; }
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0C4(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    { uint8_t status = 0u, bank = 0u; uint16_t return_pc = 0u;
      if (!js_stack_pop8(cpu, bus, &status, 1, stop, source_key)) return JS_EXEC_STOP;
      if (!js_stack_pop16(cpu, bus, &return_pc, 1, stop, source_key)) return JS_EXEC_STOP;
      cpu->p = status; cpu->pc = return_pc;
      if (!cpu->e) {
          if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP;
          cpu->pbr = bank;
      } else { cpu->pbr = 0u; }
      js_cpu_normalize(cpu);
      if (!js_v10_2_scpu_has_context(cpu))
          return js_stop_now(stop, JS_STOP_UNPROVED_INTERRUPT_REENTRY, source_key, js_cpu_context_key(cpu));
      return JS_EXEC_OK; }
}

static JSExecResult js_v10_2_template_0C5(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    const uint16_t allowed_x[] = { 0x0000u, 0x0002u, 0x0004u, 0x0006u, 0x0008u };
    if (!js_v10_2_scpu_index_allowed(cpu->x, allowed_x, sizeof allowed_x / sizeof allowed_x[0]))
        return js_stop_now(stop, JS_STOP_UNPROVED_DYNAMIC_TARGET, source_key, js_cpu_context_key(cpu));
    cpu->pc = ((uint16_t)p[1]);
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(((uint16_t)p[1]) + cpu->x);
    uint16_t target = 0u;
    if (!js_bus_read16(bus, pointer, 0, &target, stop, source_key)) return JS_EXEC_STOP;
    cpu->pc = target;
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]), ((uint32_t)p[4]), ((uint32_t)p[5]), ((uint32_t)p[6]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0C6(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = 0u;
    if (!js_addr_dp_ind(cpu, bus, ((uint8_t)p[2]), &ea, stop, source_key)) return JS_EXEC_STOP;
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_adc(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0C7(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, 0x0BA7u);
    uint16_t original = 0u;
    if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
    uint16_t result = js_op_lsr(cpu, original, 16u);
    if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0C8(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t original = 0u;
    if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
    uint16_t result = js_op_ror(cpu, original, 16u);
    if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0C9(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_compare(cpu, cpu->a, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0CA(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, 0x027Du);
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_bit(cpu, value, 8u, 0);
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0CB(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_y(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_compare(cpu, cpu->a, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0CC(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_eor(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0CD(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp_x(cpu, ((uint8_t)p[2]));
    uint16_t original = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
    uint16_t result = js_op_incdec(cpu, original, -1, 8u);
    if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0CE(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]), ((uint32_t)p[4]), ((uint32_t)p[5]), ((uint32_t)p[6]), ((uint32_t)p[7]), ((uint32_t)p[8]), ((uint32_t)p[9]), ((uint32_t)p[10]), ((uint32_t)p[11]), ((uint32_t)p[12]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0CF(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]), ((uint32_t)p[4]), ((uint32_t)p[5]), ((uint32_t)p[6]), ((uint32_t)p[7]), ((uint32_t)p[8]), ((uint32_t)p[9]), ((uint32_t)p[10]), ((uint32_t)p[11]), ((uint32_t)p[12]), ((uint32_t)p[13]), ((uint32_t)p[14]), ((uint32_t)p[15]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0D0(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    const uint16_t allowed_x[] = { 0x0000u, 0x0002u, 0x0004u };
    if (!js_v10_2_scpu_index_allowed(cpu->x, allowed_x, sizeof allowed_x / sizeof allowed_x[0]))
        return js_stop_now(stop, JS_STOP_UNPROVED_DYNAMIC_TARGET, source_key, js_cpu_context_key(cpu));
    cpu->pc = ((uint16_t)p[1]);
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(((uint16_t)p[2]) + cpu->x);
    uint16_t target = 0u;
    if (!js_bus_read16(bus, pointer, 0, &target, stop, source_key)) return JS_EXEC_STOP;
    if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
    cpu->pc = target;
    const uint32_t allowed[] = { ((uint32_t)p[3]), ((uint32_t)p[4]), ((uint32_t)p[5]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0D1(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    const uint16_t allowed_x[] = { 0x0000u, 0x0002u, 0x0004u, 0x0006u, 0x0008u, 0x000Au };
    if (!js_v10_2_scpu_index_allowed(cpu->x, allowed_x, sizeof allowed_x / sizeof allowed_x[0]))
        return js_stop_now(stop, JS_STOP_UNPROVED_DYNAMIC_TARGET, source_key, js_cpu_context_key(cpu));
    cpu->pc = ((uint16_t)p[1]);
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(((uint16_t)p[1]) + cpu->x);
    uint16_t target = 0u;
    if (!js_bus_read16(bus, pointer, 0, &target, stop, source_key)) return JS_EXEC_STOP;
    cpu->pc = target;
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]), ((uint32_t)p[4]), ((uint32_t)p[5]), ((uint32_t)p[6]), ((uint32_t)p[7]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0D2(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    if (js_branch_condition(cpu, 'M')) cpu->pc = (uint16_t)(cpu->pc + (-((uint8_t)p[2])));
    const uint32_t allowed[] = { ((uint32_t)p[3]), ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0D3(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    js_op_transfer(cpu, 'E');
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0D4(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    js_op_transfer(cpu, 'G');
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0D5(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    js_op_transfer(cpu, 'I');
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0D6(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = 0u;
    if (!js_addr_dp_ind(cpu, bus, 0x5Au, &ea, stop, source_key)) return JS_EXEC_STOP;
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_load_a(cpu, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0D7(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = 0u;
    if (!js_addr_dp_ind_long_y(cpu, bus, 0x08u, &ea, stop, source_key)) return JS_EXEC_STOP;
    if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0D8(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = 0u;
    if (!js_addr_dp_ind_y(cpu, bus, ((uint8_t)p[2]), &ea, stop, source_key)) return JS_EXEC_STOP;
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_adc(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0D9(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t original = 0u;
    if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
    uint16_t result = js_op_rol(cpu, original, 16u);
    if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0DA(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_compare(cpu, cpu->x, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0DB(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_y(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_sbc(cpu, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0DC(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    uint16_t original = 0u;
    if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
    uint16_t result = js_op_lsr(cpu, original, 16u);
    if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0DD(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_compare(cpu, cpu->x, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0DE(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_stack_rel(cpu, ((uint8_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_compare(cpu, cpu->a, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0DF(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    return js_stop_now(stop, JS_STOP_STATIC_TERMINAL, source_key, source_key);
}

static JSExecResult js_v10_2_template_0E0(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    const uint16_t allowed_x[] = { ((uint8_t)p[1]) };
    if (!js_v10_2_scpu_index_allowed(cpu->x, allowed_x, sizeof allowed_x / sizeof allowed_x[0]))
        return js_stop_now(stop, JS_STOP_UNPROVED_DYNAMIC_TARGET, source_key, js_cpu_context_key(cpu));
    cpu->pc = ((uint16_t)p[2]);
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(((uint16_t)p[3]) + cpu->x);
    uint16_t target = 0u;
    if (!js_bus_read16(bus, pointer, 0, &target, stop, source_key)) return JS_EXEC_STOP;
    if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
    cpu->pc = target;
    const uint32_t allowed[] = { ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0E1(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    const uint16_t allowed_x[] = { ((uint8_t)p[1]), ((uint8_t)p[2]), ((uint8_t)p[3]), ((uint8_t)p[4]) };
    if (!js_v10_2_scpu_index_allowed(cpu->x, allowed_x, sizeof allowed_x / sizeof allowed_x[0]))
        return js_stop_now(stop, JS_STOP_UNPROVED_DYNAMIC_TARGET, source_key, js_cpu_context_key(cpu));
    cpu->pc = ((uint16_t)p[5]);
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(((uint16_t)p[6]) + cpu->x);
    uint16_t target = 0u;
    if (!js_bus_read16(bus, pointer, 0, &target, stop, source_key)) return JS_EXEC_STOP;
    if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
    cpu->pc = target;
    const uint32_t allowed[] = { ((uint32_t)p[7]), ((uint32_t)p[8]), ((uint32_t)p[9]), ((uint32_t)p[10]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0E2(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    const uint16_t allowed_x[] = { ((uint8_t)p[1]), ((uint8_t)p[2]), ((uint8_t)p[3]), ((uint8_t)p[4]), ((uint8_t)p[5]) };
    if (!js_v10_2_scpu_index_allowed(cpu->x, allowed_x, sizeof allowed_x / sizeof allowed_x[0]))
        return js_stop_now(stop, JS_STOP_UNPROVED_DYNAMIC_TARGET, source_key, js_cpu_context_key(cpu));
    cpu->pc = ((uint16_t)p[6]);
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(((uint16_t)p[7]) + cpu->x);
    uint16_t target = 0u;
    if (!js_bus_read16(bus, pointer, 0, &target, stop, source_key)) return JS_EXEC_STOP;
    if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
    cpu->pc = target;
    const uint32_t allowed[] = { ((uint32_t)p[8]), ((uint32_t)p[9]), ((uint32_t)p[10]), ((uint32_t)p[11]), ((uint32_t)p[12]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0E3(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    const uint16_t allowed_x[] = { 0x0000u, 0x0002u, 0x0004u, 0x0006u, 0x0008u, 0x000Au, 0x000Cu };
    if (!js_v10_2_scpu_index_allowed(cpu->x, allowed_x, sizeof allowed_x / sizeof allowed_x[0]))
        return js_stop_now(stop, JS_STOP_UNPROVED_DYNAMIC_TARGET, source_key, js_cpu_context_key(cpu));
    cpu->pc = ((uint16_t)p[1]);
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(((uint16_t)p[1]) + cpu->x);
    uint16_t target = 0u;
    if (!js_bus_read16(bus, pointer, 0, &target, stop, source_key)) return JS_EXEC_STOP;
    cpu->pc = target;
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]), ((uint32_t)p[4]), ((uint32_t)p[5]), ((uint32_t)p[6]), ((uint32_t)p[7]), ((uint32_t)p[8]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0E4(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    const uint16_t allowed_x[] = { 0x0000u, 0x0002u, 0x0004u, 0x0006u, 0x0008u, 0x000Au, 0x000Cu };
    if (!js_v10_2_scpu_index_allowed(cpu->x, allowed_x, sizeof allowed_x / sizeof allowed_x[0]))
        return js_stop_now(stop, JS_STOP_UNPROVED_DYNAMIC_TARGET, source_key, js_cpu_context_key(cpu));
    cpu->pc = ((uint16_t)p[1]);
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(((uint16_t)p[2]) + cpu->x);
    uint16_t target = 0u;
    if (!js_bus_read16(bus, pointer, 0, &target, stop, source_key)) return JS_EXEC_STOP;
    if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
    cpu->pc = target;
    const uint32_t allowed[] = { ((uint32_t)p[3]), ((uint32_t)p[4]), ((uint32_t)p[5]), ((uint32_t)p[6]), ((uint32_t)p[7]), ((uint32_t)p[8]), ((uint32_t)p[9]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0E5(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    js_op_transfer(cpu, 'C');
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0E6(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    js_op_transfer(cpu, 'J');
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0E7(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = 0x800Eu;
    js_op_xce(cpu);
    const uint32_t allowed[] = { 0x04040073u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0E8(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = 0u;
    if (!js_addr_dp_ind_y(cpu, bus, 0x13u, &ea, stop, source_key)) return JS_EXEC_STOP;
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_compare(cpu, cpu->a, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0E9(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t original = 0u;
    if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
    uint16_t result = js_op_asl(cpu, original, 16u);
    if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0EA(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t original = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
    uint16_t result = js_op_lsr(cpu, original, 8u);
    if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0EB(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t original = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
    uint16_t result = js_op_ror(cpu, original, 8u);
    if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0EC(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_and(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0ED(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_compare(cpu, cpu->x, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0EE(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_long(((uint32_t)p[2]));
    if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0EF(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_long_x(cpu, 0x7E3500u);
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 1, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_adc(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0F0(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_x(cpu, 0xDC00u);
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_and(cpu, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0F1(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_abs_y(cpu, ((uint16_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_ora(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0F2(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, 0xD7u);
    uint16_t original = 0u;
    if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
    uint16_t result = js_op_rol(cpu, original, 16u);
    if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0F3(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    uint16_t original = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
    uint16_t result = js_op_lsr(cpu, original, 8u);
    if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0F4(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_compare(cpu, cpu->y, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0F5(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, ((uint8_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_ora(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0F6(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, 0x88u);
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_compare(cpu, cpu->y, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0F7(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp(cpu, 0xA4u);
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_ora(cpu, value, 8u);
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0F8(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp_x(cpu, ((uint8_t)p[2]));
    if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0F9(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp_x(cpu, ((uint8_t)p[2]));
    if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_y(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0FA(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp_x(cpu, 0x84u);
    uint16_t original = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
    uint16_t result = js_op_incdec(cpu, original, 1, 8u);
    if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { ((uint32_t)p[2]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0FB(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    uint32_t ea = js_addr_dp_x(cpu, ((uint8_t)p[2]));
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_load_y(cpu, value, 16u);
    const uint32_t allowed[] = { ((uint32_t)p[3]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0FC(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]), ((uint32_t)p[4]), ((uint32_t)p[5]), ((uint32_t)p[6]), ((uint32_t)p[7]), ((uint32_t)p[8]), ((uint32_t)p[9]), ((uint32_t)p[10]), ((uint32_t)p[11]), ((uint32_t)p[12]), ((uint32_t)p[13]), ((uint32_t)p[14]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0FD(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]), ((uint32_t)p[4]), ((uint32_t)p[5]), ((uint32_t)p[6]), ((uint32_t)p[7]), ((uint32_t)p[8]), ((uint32_t)p[9]), ((uint32_t)p[10]), ((uint32_t)p[11]), ((uint32_t)p[12]), ((uint32_t)p[13]), ((uint32_t)p[14]), ((uint32_t)p[15]), ((uint32_t)p[16]), ((uint32_t)p[17]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0FE(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]), ((uint32_t)p[4]), ((uint32_t)p[5]), ((uint32_t)p[6]), ((uint32_t)p[7]), ((uint32_t)p[8]), ((uint32_t)p[9]), ((uint32_t)p[10]), ((uint32_t)p[11]), ((uint32_t)p[12]), ((uint32_t)p[13]), ((uint32_t)p[14]), ((uint32_t)p[15]), ((uint32_t)p[16]), ((uint32_t)p[17]), ((uint32_t)p[18]), ((uint32_t)p[19]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_0FF(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
    const uint32_t allowed[] = { 0x040690EBu, 0x04069123u, 0x0406915Bu, 0x04069193u, 0x0406921Bu, 0x04069253u, 0x0406928Bu, 0x040692C3u, 0x0406934Bu, 0x04069383u, 0x040693BBu, 0x040693F3u, 0x0406947Bu, 0x040694B3u, 0x040694EBu, 0x04069523u, 0x040695ABu, 0x040695E3u, 0x0406961Bu, 0x04069653u, 0x040696DBu, 0x04069713u, 0x0406974Bu, 0x04069783u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_100(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]), ((uint32_t)p[4]), ((uint32_t)p[5]), ((uint32_t)p[6]), ((uint32_t)p[7]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_101(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]), ((uint32_t)p[4]), ((uint32_t)p[5]), ((uint32_t)p[6]), ((uint32_t)p[7]), ((uint32_t)p[8]), ((uint32_t)p[9]), ((uint32_t)p[10]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_102(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]), ((uint32_t)p[4]), ((uint32_t)p[5]), ((uint32_t)p[6]), ((uint32_t)p[7]), ((uint32_t)p[8]), ((uint32_t)p[9]), ((uint32_t)p[10]), ((uint32_t)p[11]), ((uint32_t)p[12]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_103(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
    const uint32_t allowed[] = { 0x04049E98u, 0x0404A2A0u, 0x0404A680u, 0x0404AA88u, 0x0404C870u, 0x0405B258u, 0x0405B758u, 0x0406EE00u, 0x0406FF98u, 0x040704B8u, 0x04070678u, 0x040709B8u, 0x040C07E8u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_104(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]), ((uint32_t)p[4]), ((uint32_t)p[5]), ((uint32_t)p[6]), ((uint32_t)p[7]), ((uint32_t)p[8]), ((uint32_t)p[9]), ((uint32_t)p[10]), ((uint32_t)p[11]), ((uint32_t)p[12]), ((uint32_t)p[13]), ((uint32_t)p[14]), ((uint32_t)p[15]), ((uint32_t)p[16]), ((uint32_t)p[17]), ((uint32_t)p[18]), ((uint32_t)p[19]), ((uint32_t)p[20]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_105(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]), ((uint32_t)p[4]), ((uint32_t)p[5]), ((uint32_t)p[6]), ((uint32_t)p[7]), ((uint32_t)p[8]), ((uint32_t)p[9]), ((uint32_t)p[10]), ((uint32_t)p[11]), ((uint32_t)p[12]), ((uint32_t)p[13]), ((uint32_t)p[14]), ((uint32_t)p[15]), ((uint32_t)p[16]), ((uint32_t)p[17]), ((uint32_t)p[18]), ((uint32_t)p[19]), ((uint32_t)p[20]), ((uint32_t)p[21]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_106(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = ((uint32_t)p[0]);
    cpu->pc = ((uint16_t)p[1]);
    { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; cpu->p = (uint8_t)(v | (cpu->e ? (JS_P_M|JS_P_X) : 0u)); js_cpu_normalize(cpu); }
    const uint32_t allowed[] = { ((uint32_t)p[2]), ((uint32_t)p[3]), ((uint32_t)p[4]) };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_107(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x049534F0u;
    const uint16_t allowed_x[] = { 0x0000u };
    if (!js_v10_2_scpu_index_allowed(cpu->x, allowed_x, sizeof allowed_x / sizeof allowed_x[0]))
        return js_stop_now(stop, JS_STOP_UNPROVED_DYNAMIC_TARGET, source_key, js_cpu_context_key(cpu));
    cpu->pc = 0xA6A1u;
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0x1F47u + cpu->x);
    uint16_t target = 0u;
    if (!js_bus_read16(bus, pointer, 0, &target, stop, source_key)) return JS_EXEC_STOP;
    if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
    cpu->pc = target;
    const uint32_t allowed[] = { 0x0496CD58u, 0x0496CE10u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_108(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x04959550u;
    const uint16_t allowed_x[] = { 0x0000u, 0x0002u };
    if (!js_v10_2_scpu_index_allowed(cpu->x, allowed_x, sizeof allowed_x / sizeof allowed_x[0]))
        return js_stop_now(stop, JS_STOP_UNPROVED_DYNAMIC_TARGET, source_key, js_cpu_context_key(cpu));
    cpu->pc = 0xB2ADu;
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0xB2F3u + cpu->x);
    uint16_t target = 0u;
    if (!js_bus_read16(bus, pointer, 0, &target, stop, source_key)) return JS_EXEC_STOP;
    if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
    cpu->pc = target;
    const uint32_t allowed[] = { 0x04951F20u, 0x04952078u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_109(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x040D8253u;
    const uint16_t allowed_x[] = { 0x0000u, 0x0002u, 0x0004u, 0x0006u, 0x0008u };
    if (!js_v10_2_scpu_index_allowed(cpu->x, allowed_x, sizeof allowed_x / sizeof allowed_x[0]))
        return js_stop_now(stop, JS_STOP_UNPROVED_DYNAMIC_TARGET, source_key, js_cpu_context_key(cpu));
    cpu->pc = 0xB04Du;
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0xB089u + cpu->x);
    uint16_t target = 0u;
    if (!js_bus_read16(bus, pointer, 0, &target, stop, source_key)) return JS_EXEC_STOP;
    if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
    cpu->pc = target;
    const uint32_t allowed[] = { 0x040C6363u, 0x040C9EFBu, 0x040D3353u, 0x040DB80Bu };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_10A(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x04FF80D8u;
    const uint16_t allowed_x[] = { 0x0000u, 0x0002u, 0x0004u, 0x0006u, 0x0008u, 0x000Au, 0x000Cu, 0x000Eu };
    if (!js_v10_2_scpu_index_allowed(cpu->x, allowed_x, sizeof allowed_x / sizeof allowed_x[0]))
        return js_stop_now(stop, JS_STOP_UNPROVED_DYNAMIC_TARGET, source_key, js_cpu_context_key(cpu));
    cpu->pc = 0xF01Eu;
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0xF031u + cpu->x);
    uint16_t target = 0u;
    if (!js_bus_read16(bus, pointer, 0, &target, stop, source_key)) return JS_EXEC_STOP;
    cpu->pc = target;
    const uint32_t allowed[] = { 0x04FF8208u, 0x04FF8260u, 0x04FF8270u, 0x04FF8278u, 0x04FF8840u, 0x04FF88D0u, 0x04FF8A48u, 0x04FF8AD0u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_10B(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x0407E123u;
    const uint16_t allowed_x[] = { 0x0000u, 0x0002u, 0x0004u, 0x0006u, 0x0008u, 0x000Au, 0x000Cu, 0x000Eu, 0x0010u };
    if (!js_v10_2_scpu_index_allowed(cpu->x, allowed_x, sizeof allowed_x / sizeof allowed_x[0]))
        return js_stop_now(stop, JS_STOP_UNPROVED_DYNAMIC_TARGET, source_key, js_cpu_context_key(cpu));
    cpu->pc = 0xFC27u;
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0xFC29u + cpu->x);
    uint16_t target = 0u;
    if (!js_bus_read16(bus, pointer, 0, &target, stop, source_key)) return JS_EXEC_STOP;
    if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
    cpu->pc = target;
    const uint32_t allowed[] = { 0x0407E143u, 0x0407E1DBu, 0x0407E233u, 0x0407E27Bu, 0x0407E4A3u, 0x0407E5E3u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_10C(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x049516D0u;
    const uint16_t allowed_x[] = { 0x0000u, 0x0002u, 0x0004u, 0x0006u, 0x0008u, 0x000Au, 0x000Cu, 0x000Eu, 0x0010u, 0x0012u };
    if (!js_v10_2_scpu_index_allowed(cpu->x, allowed_x, sizeof allowed_x / sizeof allowed_x[0]))
        return js_stop_now(stop, JS_STOP_UNPROVED_DYNAMIC_TARGET, source_key, js_cpu_context_key(cpu));
    cpu->pc = 0xA2DDu;
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0xA200u + cpu->x);
    uint16_t target = 0u;
    if (!js_bus_read16(bus, pointer, 0, &target, stop, source_key)) return JS_EXEC_STOP;
    if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
    cpu->pc = target;
    const uint32_t allowed[] = { 0x04951780u, 0x049518E8u, 0x04951918u, 0x04951AB0u, 0x04951B28u, 0x04951D60u, 0x049521E8u, 0x04952280u, 0x049523F0u, 0x049529D8u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_10D(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x040FEAD3u;
    const uint16_t allowed_x[] = { 0x0000u, 0x0002u, 0x0004u, 0x0006u, 0x0008u, 0x000Au, 0x000Cu, 0x000Eu, 0x0010u, 0x0012u, 0x0014u, 0x0016u, 0x0018u };
    if (!js_v10_2_scpu_index_allowed(cpu->x, allowed_x, sizeof allowed_x / sizeof allowed_x[0]))
        return js_stop_now(stop, JS_STOP_UNPROVED_DYNAMIC_TARGET, source_key, js_cpu_context_key(cpu));
    cpu->pc = 0xFD5Du;
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0xFD5Du + cpu->x);
    uint16_t target = 0u;
    if (!js_bus_read16(bus, pointer, 0, &target, stop, source_key)) return JS_EXEC_STOP;
    cpu->pc = target;
    const uint32_t allowed[] = { 0x040FEBBBu, 0x040FEBFBu, 0x040FEC03u, 0x040FEC8Bu, 0x040FECFBu, 0x040FED9Bu, 0x040FEE3Bu, 0x040FEEDBu };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_10E(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x040E5A33u;
    const uint16_t allowed_x[] = { 0x0000u, 0x0002u, 0x0004u, 0x0006u, 0x0008u, 0x000Au, 0x000Cu, 0x000Eu, 0x0010u, 0x0012u, 0x0014u, 0x0016u, 0x0018u };
    if (!js_v10_2_scpu_index_allowed(cpu->x, allowed_x, sizeof allowed_x / sizeof allowed_x[0]))
        return js_stop_now(stop, JS_STOP_UNPROVED_DYNAMIC_TARGET, source_key, js_cpu_context_key(cpu));
    cpu->pc = 0xCB49u;
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0xCB54u + cpu->x);
    uint16_t target = 0u;
    if (!js_bus_read16(bus, pointer, 0, &target, stop, source_key)) return JS_EXEC_STOP;
    if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
    cpu->pc = target;
    const uint32_t allowed[] = { 0x040E5A9Bu, 0x040E5B73u, 0x040E5BC3u, 0x040E5C63u, 0x040E5CE3u, 0x040E5D33u, 0x040E5D7Bu, 0x040E5DABu, 0x040E5DDBu, 0x040E5E0Bu, 0x040E620Bu, 0x040E69F3u, 0x040E6C4Bu };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_10F(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x04040C0Bu;
    const uint16_t allowed_x[] = { 0x0000u, 0x0002u, 0x0004u, 0x0006u, 0x0008u, 0x000Au, 0x000Cu, 0x000Eu, 0x0010u, 0x0012u, 0x0014u, 0x0016u, 0x0018u, 0x001Au, 0x001Cu, 0x001Eu, 0x0020u, 0x0022u };
    if (!js_v10_2_scpu_index_allowed(cpu->x, allowed_x, sizeof allowed_x / sizeof allowed_x[0]))
        return js_stop_now(stop, JS_STOP_UNPROVED_DYNAMIC_TARGET, source_key, js_cpu_context_key(cpu));
    cpu->pc = 0x8184u;
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0x8197u + cpu->x);
    uint16_t target = 0u;
    if (!js_bus_read16(bus, pointer, 0, &target, stop, source_key)) return JS_EXEC_STOP;
    if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
    cpu->pc = target;
    const uint32_t allowed[] = { 0x04040E03u, 0x04040E0Bu, 0x04040E33u, 0x04040E5Bu, 0x04040E83u, 0x04040EABu, 0x04040ED3u, 0x04040EFBu, 0x04040F23u, 0x04040F4Bu, 0x04040F73u, 0x04040F9Bu, 0x04040FC3u, 0x0405F0D3u, 0x0405F0FBu, 0x0405F18Bu, 0x0405F253u, 0x0405FA73u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_110(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x0405244Bu;
    const uint16_t allowed_x[] = { 0x0006u, 0x0008u, 0x000Au, 0x000Cu, 0x000Eu, 0x0010u, 0x0012u, 0x0014u, 0x0016u, 0x0018u, 0x001Au, 0x001Cu, 0x001Eu, 0x0020u, 0x0022u, 0x0024u, 0x0026u, 0x0028u, 0x002Au, 0x002Cu, 0x002Eu };
    if (!js_v10_2_scpu_index_allowed(cpu->x, allowed_x, sizeof allowed_x / sizeof allowed_x[0]))
        return js_stop_now(stop, JS_STOP_UNPROVED_DYNAMIC_TARGET, source_key, js_cpu_context_key(cpu));
    cpu->pc = 0xA48Cu;
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0xA484u + cpu->x);
    uint16_t target = 0u;
    if (!js_bus_read16(bus, pointer, 0, &target, stop, source_key)) return JS_EXEC_STOP;
    cpu->pc = target;
    const uint32_t allowed[] = { 0x04052423u, 0x040525A3u, 0x04053193u, 0x04053343u, 0x040534F3u, 0x040537C3u, 0x04053A8Bu, 0x04053D5Bu, 0x04054023u, 0x040543BBu, 0x0405498Bu, 0x04054F5Bu, 0x040554DBu };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_111(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x04947620u;
    const uint16_t allowed_x[] = { 0x0000u, 0x0002u, 0x0004u, 0x0006u, 0x0008u, 0x000Au, 0x000Cu, 0x000Eu, 0x0010u, 0x0012u, 0x0014u, 0x0016u, 0x0018u, 0x001Au, 0x001Cu, 0x001Eu, 0x0020u, 0x0022u, 0x0024u, 0x0026u, 0x0028u, 0x002Au, 0x002Cu, 0x002Eu, 0x0030u, 0x0032u, 0x0034u, 0x0036u, 0x0038u, 0x003Au, 0x003Cu, 0x003Eu };
    if (!js_v10_2_scpu_index_allowed(cpu->x, allowed_x, sizeof allowed_x / sizeof allowed_x[0]))
        return js_stop_now(stop, JS_STOP_UNPROVED_DYNAMIC_TARGET, source_key, js_cpu_context_key(cpu));
    cpu->pc = 0x8EC7u;
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0x8EC7u + cpu->x);
    uint16_t target = 0u;
    if (!js_bus_read16(bus, pointer, 0, &target, stop, source_key)) return JS_EXEC_STOP;
    cpu->pc = target;
    const uint32_t allowed[] = { 0x049475C0u, 0x04947838u, 0x04947B90u, 0x04947C30u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_112(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x04953F08u;
    const uint16_t allowed_x[] = { 0x0000u, 0x0002u, 0x0004u, 0x0006u, 0x0008u, 0x000Au, 0x000Cu, 0x000Eu, 0x0010u, 0x0012u, 0x0014u, 0x0016u, 0x0018u, 0x001Au, 0x001Cu, 0x001Eu, 0x0020u, 0x0022u, 0x0024u, 0x0026u, 0x0028u, 0x002Au, 0x002Cu, 0x002Eu, 0x0030u, 0x0032u, 0x0034u, 0x0036u, 0x0038u, 0x003Au, 0x003Cu, 0x003Eu };
    if (!js_v10_2_scpu_index_allowed(cpu->x, allowed_x, sizeof allowed_x / sizeof allowed_x[0]))
        return js_stop_now(stop, JS_STOP_UNPROVED_DYNAMIC_TARGET, source_key, js_cpu_context_key(cpu));
    cpu->pc = 0xA7E4u;
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0xA7E5u + cpu->x);
    uint16_t target = 0u;
    if (!js_bus_read16(bus, pointer, 0, &target, stop, source_key)) return JS_EXEC_STOP;
    if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
    cpu->pc = target;
    const uint32_t allowed[] = { 0x04953BB8u, 0x04953BE0u, 0x04953F20u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_113(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x04945D78u;
    const uint16_t allowed_x[] = { 0x0000u, 0x0002u, 0x0004u, 0x0006u, 0x0008u, 0x000Au, 0x000Cu, 0x000Eu, 0x0010u, 0x0012u, 0x0014u, 0x0016u, 0x0018u, 0x001Au, 0x001Cu, 0x001Eu, 0x0020u, 0x0022u, 0x0024u, 0x0026u, 0x0028u, 0x002Au, 0x002Cu, 0x002Eu, 0x0030u, 0x0032u, 0x0034u, 0x0036u, 0x0038u, 0x003Au, 0x003Cu, 0x003Eu };
    if (!js_v10_2_scpu_index_allowed(cpu->x, allowed_x, sizeof allowed_x / sizeof allowed_x[0]))
        return js_stop_now(stop, JS_STOP_UNPROVED_DYNAMIC_TARGET, source_key, js_cpu_context_key(cpu));
    cpu->pc = 0x8BB2u;
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0x8C0Bu + cpu->x);
    uint16_t target = 0u;
    if (!js_bus_read16(bus, pointer, 0, &target, stop, source_key)) return JS_EXEC_STOP;
    if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
    cpu->pc = target;
    const uint32_t allowed[] = { 0x04946258u, 0x04947E38u, 0x04947E78u, 0x04947EB8u, 0x04947EF8u, 0x04947F38u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_114(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x04945C48u;
    const uint16_t allowed_x[] = { 0x0000u, 0x0002u, 0x0004u, 0x0006u, 0x0008u, 0x000Au, 0x000Cu, 0x000Eu, 0x0010u, 0x0012u, 0x0014u, 0x0016u, 0x0018u, 0x001Au, 0x001Cu, 0x001Eu, 0x0020u, 0x0022u, 0x0024u, 0x0026u, 0x0028u, 0x002Au, 0x002Cu, 0x002Eu, 0x0030u, 0x0032u, 0x0034u, 0x0036u, 0x0038u, 0x003Au, 0x003Cu, 0x003Eu };
    if (!js_v10_2_scpu_index_allowed(cpu->x, allowed_x, sizeof allowed_x / sizeof allowed_x[0]))
        return js_stop_now(stop, JS_STOP_UNPROVED_DYNAMIC_TARGET, source_key, js_cpu_context_key(cpu));
    cpu->pc = 0x8B8Cu;
    uint32_t pointer = ((uint32_t)cpu->pbr << 16) | (uint16_t)(0x8BCBu + cpu->x);
    uint16_t target = 0u;
    if (!js_bus_read16(bus, pointer, 0, &target, stop, source_key)) return JS_EXEC_STOP;
    if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
    cpu->pc = target;
    const uint32_t allowed[] = { 0x04946258u, 0x04946260u, 0x04946778u, 0x04947000u, 0x04947068u, 0x049470D0u, 0x04947110u, 0x049471D8u, 0x04947200u, 0x04947228u, 0x04947250u, 0x04947278u, 0x049472D8u, 0x04947300u, 0x04947328u, 0x04947350u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_115(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x04945830u;
    cpu->pc = 0x8B07u;
    if (!js_stack_push16(cpu, bus, cpu->d, 1, stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { 0x04945838u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_116(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x0404D43Bu;
    cpu->pc = 0x9A89u;
    if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (0));
    const uint32_t allowed[] = { 0x0404D44Bu };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_117(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x04977658u;
    cpu->pc = 0xEECDu;
    uint32_t ea = 0u;
    if (!js_addr_dp_ind_long(cpu, bus, 0xBAu, &ea, stop, source_key)) return JS_EXEC_STOP;
    if (!js_bus_write16(bus, ea, 1, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
    const uint32_t allowed[] = { 0x04977668u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_118(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x0407D808u;
    cpu->pc = 0xFB03u;
    uint32_t ea = 0u;
    if (!js_addr_dp_ind_long(cpu, bus, 0x91u, &ea, stop, source_key)) return JS_EXEC_STOP;
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 1, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_adc(cpu, value, 16u);
    const uint32_t allowed[] = { 0x0407D818u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_119(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x0407E018u;
    cpu->pc = 0xFC05u;
    uint32_t ea = 0u;
    if (!js_addr_dp_ind_long_y(cpu, bus, 0x91u, &ea, stop, source_key)) return JS_EXEC_STOP;
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 1, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_sbc(cpu, value, 16u);
    const uint32_t allowed[] = { 0x0407E028u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_11A(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x04952258u;
    cpu->pc = 0xA44Du;
    uint32_t ea = 0u;
    if (!js_addr_dp_ind_y(cpu, bus, 0x0Bu, &ea, stop, source_key)) return JS_EXEC_STOP;
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_and(cpu, value, 16u);
    const uint32_t allowed[] = { 0x04952268u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_11B(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x0404E6CBu;
    cpu->pc = 0x9CDBu;
    uint32_t ea = 0u;
    if (!js_addr_dp_ind_y(cpu, bus, 0x5Au, &ea, stop, source_key)) return JS_EXEC_STOP;
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_sbc(cpu, value, 8u);
    const uint32_t allowed[] = { 0x0404E6DBu };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_11C(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x040C0A00u;
    cpu->pc = 0x8143u;
    uint32_t ea = js_addr_abs(cpu, 0x0B6Du);
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_compare(cpu, cpu->y, value, 16u);
    const uint32_t allowed[] = { 0x040C0A18u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_11D(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x040C48C0u;
    cpu->pc = 0x891Bu;
    uint32_t ea = js_addr_abs_x(cpu, 0x1031u);
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_compare(cpu, cpu->a, value, 16u);
    const uint32_t allowed[] = { 0x040C48D8u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_11E(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x04058528u;
    cpu->pc = 0xB0A8u;
    uint32_t ea = js_addr_abs_y(cpu, 0x033Du);
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_and(cpu, value, 16u);
    const uint32_t allowed[] = { 0x04058540u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_11F(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x04058510u;
    cpu->pc = 0xB0A5u;
    uint32_t ea = js_addr_abs_y(cpu, 0x0345u);
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_eor(cpu, value, 16u);
    const uint32_t allowed[] = { 0x04058528u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_120(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x0407E8FBu;
    cpu->pc = 0xFD22u;
    uint32_t ea = js_addr_abs_y(cpu, 0x0C8Fu);
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_ora(cpu, value, 8u);
    const uint32_t allowed[] = { 0x0407E913u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_121(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x04952EE0u;
    cpu->pc = 0xA5DEu;
    uint32_t ea = js_addr_dp(cpu, 0x15u);
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_and(cpu, value, 16u);
    const uint32_t allowed[] = { 0x04952EF0u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_122(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x0497361Bu;
    cpu->pc = 0xE6C5u;
    uint32_t ea = js_addr_dp(cpu, 0x88u);
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_compare(cpu, cpu->x, value, 8u);
    const uint32_t allowed[] = { 0x0497362Bu };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_123(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x040675B0u;
    cpu->pc = 0xCEB8u;
    uint32_t ea = js_addr_dp_x(cpu, 0x9Eu);
    uint16_t value = 0u;
    if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
    js_op_compare(cpu, cpu->a, value, 16u);
    const uint32_t allowed[] = { 0x040675C0u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_124(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x0405DAB3u;
    cpu->pc = 0xBB58u;
    uint32_t ea = js_addr_dp_x(cpu, 0x80u);
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_adc(cpu, value, 8u);
    const uint32_t allowed[] = { 0x0405DAC3u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_125(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x0407EE33u;
    cpu->pc = 0xFDC8u;
    uint32_t ea = js_addr_dp_x(cpu, 0x48u);
    uint16_t value = 0u;
    { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
    js_op_sbc(cpu, value, 8u);
    const uint32_t allowed[] = { 0x0407EE43u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_126(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x0407C9FBu;
    cpu->pc = 0xF940u;
    { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
    const uint32_t allowed[] = { 0x0404A0B3u, 0x0404A54Bu, 0x0404A89Bu, 0x0404AC73u, 0x0404C8BBu, 0x0404D363u, 0x0406EEA3u, 0x0406FBD3u, 0x0407089Bu, 0x04070BDBu, 0x0407C94Bu, 0x0407CBC3u, 0x0407DA3Bu, 0x0407DA8Bu, 0x0407DADBu };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_127(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x040CE78Bu;
    cpu->pc = 0x9CF2u;
    { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
    const uint32_t allowed[] = { 0x040C6DDBu, 0x040C8E2Bu, 0x040CA40Bu, 0x040CD2A3u, 0x040CE5A3u, 0x040D304Bu, 0x040D367Bu, 0x040D594Bu, 0x040D7EDBu, 0x040DAC9Bu, 0x040DBD3Bu, 0x040DCF83u, 0x040DD743u, 0x040E14E3u, 0x040E324Bu, 0x040E43E3u, 0x040E777Bu, 0x040E7863u, 0x040E8413u, 0x040EC6FBu, 0x040EC783u, 0x040FA5F3u, 0x040FA793u, 0x040FC41Bu, 0x040FC983u, 0x040FF3DBu };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_128(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x040CE56Bu;
    cpu->pc = 0x9CAEu;
    { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
    const uint32_t allowed[] = { 0x040C6DC3u, 0x040C6F0Bu, 0x040CA3F3u, 0x040CA563u, 0x040CE44Bu, 0x040D3033u, 0x040D317Bu, 0x040D3663u, 0x040D375Bu, 0x040D7EC3u, 0x040D8073u, 0x040DBD23u, 0x040DBE6Bu, 0x040DD72Bu, 0x040DD8BBu, 0x040E41E3u, 0x040E5A63u, 0x040E83FBu, 0x040E865Bu, 0x040FA5DBu, 0x040FA77Bu, 0x040FAB43u, 0x040FAC7Bu, 0x040FAD6Bu, 0x040FB31Bu, 0x040FBADBu, 0x040FBE2Bu, 0x040FC96Bu, 0x040FCB63u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_129(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x040EEFF8u;
    cpu->pc = 0xDE00u;
    { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
    const uint32_t allowed[] = { 0x040C6CA0u, 0x040D2D18u, 0x040D7CC0u, 0x040D8C98u, 0x040D8E28u, 0x040D9250u, 0x040D92B0u, 0x040D93F8u, 0x040DCA60u, 0x040DCB18u, 0x040DCC68u, 0x040DCD20u, 0x040DD480u, 0x040DD568u, 0x040DE8F8u, 0x040E3FD0u, 0x040E4030u, 0x040E4140u, 0x040E41A0u, 0x040EE868u, 0x040EE928u, 0x040EE980u, 0x040EEA18u, 0x040EEAF8u, 0x040EEC38u, 0x040EECA8u, 0x040EEDE0u, 0x040EEE38u, 0x040FDAB8u, 0x040FDE08u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_12A(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x040C04D8u;
    cpu->pc = 0x809Cu;
    { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
    const uint32_t allowed[] = { 0x040C0418u, 0x040C14D0u, 0x040C1538u, 0x040C1638u, 0x040C16F8u, 0x040C1760u, 0x040C1860u, 0x040C1AB0u, 0x040C2930u, 0x040C2998u, 0x040C2AB0u, 0x040C2F28u, 0x040C2F58u, 0x040C2F90u, 0x040C30A8u, 0x040C36A8u, 0x040C37A0u, 0x040C38E8u, 0x040C3920u, 0x040C3958u, 0x040C39C0u, 0x040C39F8u, 0x040C3A30u, 0x040C3A98u, 0x040C3AD0u, 0x040C3B08u, 0x040C3B40u, 0x040C3BA8u, 0x040C3BF8u, 0x040C3C48u, 0x040C3CC8u, 0x040C3D18u, 0x040C3D68u, 0x040C3DE8u, 0x040C3E38u, 0x040C3E88u, 0x040C3FA8u, 0x040C4070u, 0x040C40D8u, 0x040C4140u, 0x040C41A8u, 0x040C4210u, 0x040C43E0u, 0x040C4448u, 0x040C44B0u, 0x040C46E0u, 0x040C4740u, 0x040C4828u, 0x040C4890u, 0x040C55D0u, 0x040C58C0u, 0x040C5938u, 0x040C62D8u, 0x040C6328u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_12B(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x040EF588u;
    cpu->pc = 0xDEB2u;
    { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
    const uint32_t allowed[] = { 0x040C6C08u, 0x040C7290u, 0x040C72F0u, 0x040C7AA8u, 0x040C7B40u, 0x040C7C08u, 0x040C7DA0u, 0x040C7E00u, 0x040C7F88u, 0x040C7FE8u, 0x040C8120u, 0x040C8138u, 0x040C8150u, 0x040C81B0u, 0x040C8268u, 0x040C8340u, 0x040C84B0u, 0x040CA290u, 0x040CA338u, 0x040CAE58u, 0x040CAF00u, 0x040CB290u, 0x040CB410u, 0x040CB4F8u, 0x040CBCC8u, 0x040CBD28u, 0x040D2C98u, 0x040D4190u, 0x040D4250u, 0x040D6A48u, 0x040D7D38u, 0x040D8048u, 0x040D8928u, 0x040D89C0u, 0x040D8A20u, 0x040D8B38u, 0x040D8C00u, 0x040D8D30u, 0x040D8D90u, 0x040D8E88u, 0x040D8F30u, 0x040D9008u, 0x040D9118u, 0x040D9178u, 0x040D9310u, 0x040DBA00u, 0x040DBA18u, 0x040DC588u, 0x040DC6D0u, 0x040DC780u, 0x040DC918u, 0x040DC9A0u, 0x040DCA00u, 0x040DCC08u, 0x040DD3C0u, 0x040DD420u, 0x040DD508u, 0x040DD5C8u, 0x040DE2F8u, 0x040DE808u, 0x040E3760u, 0x040E3860u, 0x040E38D8u, 0x040E3960u, 0x040E39C0u, 0x040E3D88u, 0x040E3DE8u, 0x040E3E70u, 0x040E44C8u, 0x040E4528u, 0x040E4DD0u, 0x040E53B8u, 0x040E5418u, 0x040E55B0u, 0x040E5610u, 0x040E5680u, 0x040E56E0u, 0x040E5778u, 0x040E57D8u, 0x040EF3F0u, 0x040FD228u, 0x040FD288u, 0x040FD2E8u, 0x040FD450u, 0x040FD498u, 0x040FDAF8u, 0x040FDB78u, 0x040FDE48u, 0x040FDEC8u, 0x040FE150u, 0x040FE360u, 0x040FE550u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_12C(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x040CE458u;
    cpu->pc = 0x9C8Cu;
    { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
    const uint32_t allowed[] = { 0x04FFB600u, 0x04FFC378u, 0x04FFC678u, 0x04FFCC88u, 0x04FFCEC0u, 0x04FFD0A0u, 0x04FFD380u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_12D(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x040617DBu;
    cpu->pc = 0xC2FCu;
    { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
    const uint32_t allowed[] = { 0x040C8E4Bu, 0x040CEC93u, 0x040D306Bu, 0x040D369Bu, 0x040D5A8Bu, 0x040D5C2Bu, 0x040D5D53u, 0x040D7E73u, 0x040DBCEBu, 0x040DD763u, 0x040E8463u, 0x040EC853u, 0x04FFB43Bu, 0x04FFB833u, 0x04FFBFFBu, 0x04FFCA13u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_12E(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x0407DA0Bu;
    cpu->pc = 0xFB42u;
    { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
    const uint32_t allowed[] = { 0x040C733Bu, 0x040CA63Bu, 0x040CBDCBu, 0x040D31EBu, 0x040D37CBu, 0x040D6CBBu, 0x040D80FBu, 0x040DC323u, 0x040DE193u, 0x040DE223u, 0x040DE35Bu, 0x040E354Bu, 0x040E35C3u, 0x040FB0FBu, 0x040FBBABu, 0x040FBEFBu, 0x040FCBD3u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_12F(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x04051D3Bu;
    cpu->pc = 0xA3A8u;
    { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
    const uint32_t allowed[] = { 0x040C6E23u, 0x040CA453u, 0x040D30ABu, 0x040D36DBu, 0x040D6B33u, 0x040D7F23u, 0x040DBD83u, 0x040DD833u, 0x040E3293u, 0x040E4443u, 0x040E85BBu, 0x040FA613u, 0x040FA7B3u, 0x040FCA63u, 0x04FFB493u, 0x04FFB88Bu, 0x04FFC103u, 0x04FFCB1Bu };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_130(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x040417F0u;
    cpu->pc = 0x82FFu;
    { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
    const uint32_t allowed[] = { 0x040C6530u, 0x040CAA58u, 0x040CEC28u, 0x040CF4E8u, 0x040D2B98u, 0x040D3448u, 0x040D4350u, 0x040D4450u, 0x040D7C20u, 0x040D9A98u, 0x040D9BD8u, 0x040DA100u, 0x040E7D88u, 0x040FDD28u, 0x040FE078u, 0x040FE2D0u, 0x040FE4C0u, 0x040FE6B0u, 0x049787E0u, 0x04FFBB20u, 0x04FFD8B0u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_131(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x0407CC2Bu;
    cpu->pc = 0xF986u;
    { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
    const uint32_t allowed[] = { 0x040C6EABu, 0x040C738Bu, 0x040CA65Bu, 0x040CA8A3u, 0x040CFD53u, 0x040D320Bu, 0x040D37EBu, 0x040D6CDBu, 0x040D811Bu, 0x040DC3FBu, 0x040DC5D3u, 0x040DDA2Bu, 0x040E356Bu, 0x040E35E3u, 0x040E42ABu, 0x040E5C43u, 0x040E859Bu, 0x040E874Bu, 0x040EC4CBu, 0x040FAC2Bu, 0x040FADE3u, 0x040FB11Bu, 0x040FBBCBu, 0x040FBF1Bu, 0x040FCBF3u, 0x04FFC0E3u, 0x04FFC72Bu, 0x04FFCAFBu, 0x04FFD433u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_132(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x04951150u;
    cpu->pc = 0xA22Du;
    { uint16_t target = 0u;
      if (!js_bus_read16(bus, 0x1F47u, 0, &target, stop, source_key)) return JS_EXEC_STOP;
      cpu->pc = target; }
    const uint32_t allowed[] = { 0x04959098u, 0x0495D9A8u, 0x04963108u, 0x04967B18u, 0x0496CB88u, 0x04971A68u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_133(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x04945E38u;
    cpu->pc = 0x8BC8u;
    { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; cpu->d = v; js_op_set_nz(cpu, v, 16u); }
    const uint32_t allowed[] = { 0x04945E40u };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

static JSExecResult js_v10_2_template_134(
        JSCPU *cpu, const JSBus *bus, JSStop *stop, const uint32_t *p) {
    (void)cpu; (void)bus; (void)stop; (void)p;
    const uint32_t source_key = 0x04041130u;
    cpu->pc = 0x8227u;
    { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; cpu->p = (uint8_t)(v | (cpu->e ? (JS_P_M|JS_P_X) : 0u)); js_cpu_normalize(cpu); }
    const uint32_t allowed[] = { 0x04041138u, 0x04041139u, 0x0404113Au, 0x0404113Bu };
    return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
}

JSExecResult js_v10_2_compact_execute(JSCPU *cpu, const JSBus *bus, JSStop *stop,
                                        uint16_t template_id, const uint32_t *p) {
    switch (template_id) {
        case 0x000u: return js_v10_2_template_000(cpu, bus, stop, p);
        case 0x001u: return js_v10_2_template_001(cpu, bus, stop, p);
        case 0x002u: return js_v10_2_template_002(cpu, bus, stop, p);
        case 0x003u: return js_v10_2_template_003(cpu, bus, stop, p);
        case 0x004u: return js_v10_2_template_004(cpu, bus, stop, p);
        case 0x005u: return js_v10_2_template_005(cpu, bus, stop, p);
        case 0x006u: return js_v10_2_template_006(cpu, bus, stop, p);
        case 0x007u: return js_v10_2_template_007(cpu, bus, stop, p);
        case 0x008u: return js_v10_2_template_008(cpu, bus, stop, p);
        case 0x009u: return js_v10_2_template_009(cpu, bus, stop, p);
        case 0x00Au: return js_v10_2_template_00A(cpu, bus, stop, p);
        case 0x00Bu: return js_v10_2_template_00B(cpu, bus, stop, p);
        case 0x00Cu: return js_v10_2_template_00C(cpu, bus, stop, p);
        case 0x00Du: return js_v10_2_template_00D(cpu, bus, stop, p);
        case 0x00Eu: return js_v10_2_template_00E(cpu, bus, stop, p);
        case 0x00Fu: return js_v10_2_template_00F(cpu, bus, stop, p);
        case 0x010u: return js_v10_2_template_010(cpu, bus, stop, p);
        case 0x011u: return js_v10_2_template_011(cpu, bus, stop, p);
        case 0x012u: return js_v10_2_template_012(cpu, bus, stop, p);
        case 0x013u: return js_v10_2_template_013(cpu, bus, stop, p);
        case 0x014u: return js_v10_2_template_014(cpu, bus, stop, p);
        case 0x015u: return js_v10_2_template_015(cpu, bus, stop, p);
        case 0x016u: return js_v10_2_template_016(cpu, bus, stop, p);
        case 0x017u: return js_v10_2_template_017(cpu, bus, stop, p);
        case 0x018u: return js_v10_2_template_018(cpu, bus, stop, p);
        case 0x019u: return js_v10_2_template_019(cpu, bus, stop, p);
        case 0x01Au: return js_v10_2_template_01A(cpu, bus, stop, p);
        case 0x01Bu: return js_v10_2_template_01B(cpu, bus, stop, p);
        case 0x01Cu: return js_v10_2_template_01C(cpu, bus, stop, p);
        case 0x01Du: return js_v10_2_template_01D(cpu, bus, stop, p);
        case 0x01Eu: return js_v10_2_template_01E(cpu, bus, stop, p);
        case 0x01Fu: return js_v10_2_template_01F(cpu, bus, stop, p);
        case 0x020u: return js_v10_2_template_020(cpu, bus, stop, p);
        case 0x021u: return js_v10_2_template_021(cpu, bus, stop, p);
        case 0x022u: return js_v10_2_template_022(cpu, bus, stop, p);
        case 0x023u: return js_v10_2_template_023(cpu, bus, stop, p);
        case 0x024u: return js_v10_2_template_024(cpu, bus, stop, p);
        case 0x025u: return js_v10_2_template_025(cpu, bus, stop, p);
        case 0x026u: return js_v10_2_template_026(cpu, bus, stop, p);
        case 0x027u: return js_v10_2_template_027(cpu, bus, stop, p);
        case 0x028u: return js_v10_2_template_028(cpu, bus, stop, p);
        case 0x029u: return js_v10_2_template_029(cpu, bus, stop, p);
        case 0x02Au: return js_v10_2_template_02A(cpu, bus, stop, p);
        case 0x02Bu: return js_v10_2_template_02B(cpu, bus, stop, p);
        case 0x02Cu: return js_v10_2_template_02C(cpu, bus, stop, p);
        case 0x02Du: return js_v10_2_template_02D(cpu, bus, stop, p);
        case 0x02Eu: return js_v10_2_template_02E(cpu, bus, stop, p);
        case 0x02Fu: return js_v10_2_template_02F(cpu, bus, stop, p);
        case 0x030u: return js_v10_2_template_030(cpu, bus, stop, p);
        case 0x031u: return js_v10_2_template_031(cpu, bus, stop, p);
        case 0x032u: return js_v10_2_template_032(cpu, bus, stop, p);
        case 0x033u: return js_v10_2_template_033(cpu, bus, stop, p);
        case 0x034u: return js_v10_2_template_034(cpu, bus, stop, p);
        case 0x035u: return js_v10_2_template_035(cpu, bus, stop, p);
        case 0x036u: return js_v10_2_template_036(cpu, bus, stop, p);
        case 0x037u: return js_v10_2_template_037(cpu, bus, stop, p);
        case 0x038u: return js_v10_2_template_038(cpu, bus, stop, p);
        case 0x039u: return js_v10_2_template_039(cpu, bus, stop, p);
        case 0x03Au: return js_v10_2_template_03A(cpu, bus, stop, p);
        case 0x03Bu: return js_v10_2_template_03B(cpu, bus, stop, p);
        case 0x03Cu: return js_v10_2_template_03C(cpu, bus, stop, p);
        case 0x03Du: return js_v10_2_template_03D(cpu, bus, stop, p);
        case 0x03Eu: return js_v10_2_template_03E(cpu, bus, stop, p);
        case 0x03Fu: return js_v10_2_template_03F(cpu, bus, stop, p);
        case 0x040u: return js_v10_2_template_040(cpu, bus, stop, p);
        case 0x041u: return js_v10_2_template_041(cpu, bus, stop, p);
        case 0x042u: return js_v10_2_template_042(cpu, bus, stop, p);
        case 0x043u: return js_v10_2_template_043(cpu, bus, stop, p);
        case 0x044u: return js_v10_2_template_044(cpu, bus, stop, p);
        case 0x045u: return js_v10_2_template_045(cpu, bus, stop, p);
        case 0x046u: return js_v10_2_template_046(cpu, bus, stop, p);
        case 0x047u: return js_v10_2_template_047(cpu, bus, stop, p);
        case 0x048u: return js_v10_2_template_048(cpu, bus, stop, p);
        case 0x049u: return js_v10_2_template_049(cpu, bus, stop, p);
        case 0x04Au: return js_v10_2_template_04A(cpu, bus, stop, p);
        case 0x04Bu: return js_v10_2_template_04B(cpu, bus, stop, p);
        case 0x04Cu: return js_v10_2_template_04C(cpu, bus, stop, p);
        case 0x04Du: return js_v10_2_template_04D(cpu, bus, stop, p);
        case 0x04Eu: return js_v10_2_template_04E(cpu, bus, stop, p);
        case 0x04Fu: return js_v10_2_template_04F(cpu, bus, stop, p);
        case 0x050u: return js_v10_2_template_050(cpu, bus, stop, p);
        case 0x051u: return js_v10_2_template_051(cpu, bus, stop, p);
        case 0x052u: return js_v10_2_template_052(cpu, bus, stop, p);
        case 0x053u: return js_v10_2_template_053(cpu, bus, stop, p);
        case 0x054u: return js_v10_2_template_054(cpu, bus, stop, p);
        case 0x055u: return js_v10_2_template_055(cpu, bus, stop, p);
        case 0x056u: return js_v10_2_template_056(cpu, bus, stop, p);
        case 0x057u: return js_v10_2_template_057(cpu, bus, stop, p);
        case 0x058u: return js_v10_2_template_058(cpu, bus, stop, p);
        case 0x059u: return js_v10_2_template_059(cpu, bus, stop, p);
        case 0x05Au: return js_v10_2_template_05A(cpu, bus, stop, p);
        case 0x05Bu: return js_v10_2_template_05B(cpu, bus, stop, p);
        case 0x05Cu: return js_v10_2_template_05C(cpu, bus, stop, p);
        case 0x05Du: return js_v10_2_template_05D(cpu, bus, stop, p);
        case 0x05Eu: return js_v10_2_template_05E(cpu, bus, stop, p);
        case 0x05Fu: return js_v10_2_template_05F(cpu, bus, stop, p);
        case 0x060u: return js_v10_2_template_060(cpu, bus, stop, p);
        case 0x061u: return js_v10_2_template_061(cpu, bus, stop, p);
        case 0x062u: return js_v10_2_template_062(cpu, bus, stop, p);
        case 0x063u: return js_v10_2_template_063(cpu, bus, stop, p);
        case 0x064u: return js_v10_2_template_064(cpu, bus, stop, p);
        case 0x065u: return js_v10_2_template_065(cpu, bus, stop, p);
        case 0x066u: return js_v10_2_template_066(cpu, bus, stop, p);
        case 0x067u: return js_v10_2_template_067(cpu, bus, stop, p);
        case 0x068u: return js_v10_2_template_068(cpu, bus, stop, p);
        case 0x069u: return js_v10_2_template_069(cpu, bus, stop, p);
        case 0x06Au: return js_v10_2_template_06A(cpu, bus, stop, p);
        case 0x06Bu: return js_v10_2_template_06B(cpu, bus, stop, p);
        case 0x06Cu: return js_v10_2_template_06C(cpu, bus, stop, p);
        case 0x06Du: return js_v10_2_template_06D(cpu, bus, stop, p);
        case 0x06Eu: return js_v10_2_template_06E(cpu, bus, stop, p);
        case 0x06Fu: return js_v10_2_template_06F(cpu, bus, stop, p);
        case 0x070u: return js_v10_2_template_070(cpu, bus, stop, p);
        case 0x071u: return js_v10_2_template_071(cpu, bus, stop, p);
        case 0x072u: return js_v10_2_template_072(cpu, bus, stop, p);
        case 0x073u: return js_v10_2_template_073(cpu, bus, stop, p);
        case 0x074u: return js_v10_2_template_074(cpu, bus, stop, p);
        case 0x075u: return js_v10_2_template_075(cpu, bus, stop, p);
        case 0x076u: return js_v10_2_template_076(cpu, bus, stop, p);
        case 0x077u: return js_v10_2_template_077(cpu, bus, stop, p);
        case 0x078u: return js_v10_2_template_078(cpu, bus, stop, p);
        case 0x079u: return js_v10_2_template_079(cpu, bus, stop, p);
        case 0x07Au: return js_v10_2_template_07A(cpu, bus, stop, p);
        case 0x07Bu: return js_v10_2_template_07B(cpu, bus, stop, p);
        case 0x07Cu: return js_v10_2_template_07C(cpu, bus, stop, p);
        case 0x07Du: return js_v10_2_template_07D(cpu, bus, stop, p);
        case 0x07Eu: return js_v10_2_template_07E(cpu, bus, stop, p);
        case 0x07Fu: return js_v10_2_template_07F(cpu, bus, stop, p);
        case 0x080u: return js_v10_2_template_080(cpu, bus, stop, p);
        case 0x081u: return js_v10_2_template_081(cpu, bus, stop, p);
        case 0x082u: return js_v10_2_template_082(cpu, bus, stop, p);
        case 0x083u: return js_v10_2_template_083(cpu, bus, stop, p);
        case 0x084u: return js_v10_2_template_084(cpu, bus, stop, p);
        case 0x085u: return js_v10_2_template_085(cpu, bus, stop, p);
        case 0x086u: return js_v10_2_template_086(cpu, bus, stop, p);
        case 0x087u: return js_v10_2_template_087(cpu, bus, stop, p);
        case 0x088u: return js_v10_2_template_088(cpu, bus, stop, p);
        case 0x089u: return js_v10_2_template_089(cpu, bus, stop, p);
        case 0x08Au: return js_v10_2_template_08A(cpu, bus, stop, p);
        case 0x08Bu: return js_v10_2_template_08B(cpu, bus, stop, p);
        case 0x08Cu: return js_v10_2_template_08C(cpu, bus, stop, p);
        case 0x08Du: return js_v10_2_template_08D(cpu, bus, stop, p);
        case 0x08Eu: return js_v10_2_template_08E(cpu, bus, stop, p);
        case 0x08Fu: return js_v10_2_template_08F(cpu, bus, stop, p);
        case 0x090u: return js_v10_2_template_090(cpu, bus, stop, p);
        case 0x091u: return js_v10_2_template_091(cpu, bus, stop, p);
        case 0x092u: return js_v10_2_template_092(cpu, bus, stop, p);
        case 0x093u: return js_v10_2_template_093(cpu, bus, stop, p);
        case 0x094u: return js_v10_2_template_094(cpu, bus, stop, p);
        case 0x095u: return js_v10_2_template_095(cpu, bus, stop, p);
        case 0x096u: return js_v10_2_template_096(cpu, bus, stop, p);
        case 0x097u: return js_v10_2_template_097(cpu, bus, stop, p);
        case 0x098u: return js_v10_2_template_098(cpu, bus, stop, p);
        case 0x099u: return js_v10_2_template_099(cpu, bus, stop, p);
        case 0x09Au: return js_v10_2_template_09A(cpu, bus, stop, p);
        case 0x09Bu: return js_v10_2_template_09B(cpu, bus, stop, p);
        case 0x09Cu: return js_v10_2_template_09C(cpu, bus, stop, p);
        case 0x09Du: return js_v10_2_template_09D(cpu, bus, stop, p);
        case 0x09Eu: return js_v10_2_template_09E(cpu, bus, stop, p);
        case 0x09Fu: return js_v10_2_template_09F(cpu, bus, stop, p);
        case 0x0A0u: return js_v10_2_template_0A0(cpu, bus, stop, p);
        case 0x0A1u: return js_v10_2_template_0A1(cpu, bus, stop, p);
        case 0x0A2u: return js_v10_2_template_0A2(cpu, bus, stop, p);
        case 0x0A3u: return js_v10_2_template_0A3(cpu, bus, stop, p);
        case 0x0A4u: return js_v10_2_template_0A4(cpu, bus, stop, p);
        case 0x0A5u: return js_v10_2_template_0A5(cpu, bus, stop, p);
        case 0x0A6u: return js_v10_2_template_0A6(cpu, bus, stop, p);
        case 0x0A7u: return js_v10_2_template_0A7(cpu, bus, stop, p);
        case 0x0A8u: return js_v10_2_template_0A8(cpu, bus, stop, p);
        case 0x0A9u: return js_v10_2_template_0A9(cpu, bus, stop, p);
        case 0x0AAu: return js_v10_2_template_0AA(cpu, bus, stop, p);
        case 0x0ABu: return js_v10_2_template_0AB(cpu, bus, stop, p);
        case 0x0ACu: return js_v10_2_template_0AC(cpu, bus, stop, p);
        case 0x0ADu: return js_v10_2_template_0AD(cpu, bus, stop, p);
        case 0x0AEu: return js_v10_2_template_0AE(cpu, bus, stop, p);
        case 0x0AFu: return js_v10_2_template_0AF(cpu, bus, stop, p);
        case 0x0B0u: return js_v10_2_template_0B0(cpu, bus, stop, p);
        case 0x0B1u: return js_v10_2_template_0B1(cpu, bus, stop, p);
        case 0x0B2u: return js_v10_2_template_0B2(cpu, bus, stop, p);
        case 0x0B3u: return js_v10_2_template_0B3(cpu, bus, stop, p);
        case 0x0B4u: return js_v10_2_template_0B4(cpu, bus, stop, p);
        case 0x0B5u: return js_v10_2_template_0B5(cpu, bus, stop, p);
        case 0x0B6u: return js_v10_2_template_0B6(cpu, bus, stop, p);
        case 0x0B7u: return js_v10_2_template_0B7(cpu, bus, stop, p);
        case 0x0B8u: return js_v10_2_template_0B8(cpu, bus, stop, p);
        case 0x0B9u: return js_v10_2_template_0B9(cpu, bus, stop, p);
        case 0x0BAu: return js_v10_2_template_0BA(cpu, bus, stop, p);
        case 0x0BBu: return js_v10_2_template_0BB(cpu, bus, stop, p);
        case 0x0BCu: return js_v10_2_template_0BC(cpu, bus, stop, p);
        case 0x0BDu: return js_v10_2_template_0BD(cpu, bus, stop, p);
        case 0x0BEu: return js_v10_2_template_0BE(cpu, bus, stop, p);
        case 0x0BFu: return js_v10_2_template_0BF(cpu, bus, stop, p);
        case 0x0C0u: return js_v10_2_template_0C0(cpu, bus, stop, p);
        case 0x0C1u: return js_v10_2_template_0C1(cpu, bus, stop, p);
        case 0x0C2u: return js_v10_2_template_0C2(cpu, bus, stop, p);
        case 0x0C3u: return js_v10_2_template_0C3(cpu, bus, stop, p);
        case 0x0C4u: return js_v10_2_template_0C4(cpu, bus, stop, p);
        case 0x0C5u: return js_v10_2_template_0C5(cpu, bus, stop, p);
        case 0x0C6u: return js_v10_2_template_0C6(cpu, bus, stop, p);
        case 0x0C7u: return js_v10_2_template_0C7(cpu, bus, stop, p);
        case 0x0C8u: return js_v10_2_template_0C8(cpu, bus, stop, p);
        case 0x0C9u: return js_v10_2_template_0C9(cpu, bus, stop, p);
        case 0x0CAu: return js_v10_2_template_0CA(cpu, bus, stop, p);
        case 0x0CBu: return js_v10_2_template_0CB(cpu, bus, stop, p);
        case 0x0CCu: return js_v10_2_template_0CC(cpu, bus, stop, p);
        case 0x0CDu: return js_v10_2_template_0CD(cpu, bus, stop, p);
        case 0x0CEu: return js_v10_2_template_0CE(cpu, bus, stop, p);
        case 0x0CFu: return js_v10_2_template_0CF(cpu, bus, stop, p);
        case 0x0D0u: return js_v10_2_template_0D0(cpu, bus, stop, p);
        case 0x0D1u: return js_v10_2_template_0D1(cpu, bus, stop, p);
        case 0x0D2u: return js_v10_2_template_0D2(cpu, bus, stop, p);
        case 0x0D3u: return js_v10_2_template_0D3(cpu, bus, stop, p);
        case 0x0D4u: return js_v10_2_template_0D4(cpu, bus, stop, p);
        case 0x0D5u: return js_v10_2_template_0D5(cpu, bus, stop, p);
        case 0x0D6u: return js_v10_2_template_0D6(cpu, bus, stop, p);
        case 0x0D7u: return js_v10_2_template_0D7(cpu, bus, stop, p);
        case 0x0D8u: return js_v10_2_template_0D8(cpu, bus, stop, p);
        case 0x0D9u: return js_v10_2_template_0D9(cpu, bus, stop, p);
        case 0x0DAu: return js_v10_2_template_0DA(cpu, bus, stop, p);
        case 0x0DBu: return js_v10_2_template_0DB(cpu, bus, stop, p);
        case 0x0DCu: return js_v10_2_template_0DC(cpu, bus, stop, p);
        case 0x0DDu: return js_v10_2_template_0DD(cpu, bus, stop, p);
        case 0x0DEu: return js_v10_2_template_0DE(cpu, bus, stop, p);
        case 0x0DFu: return js_v10_2_template_0DF(cpu, bus, stop, p);
        case 0x0E0u: return js_v10_2_template_0E0(cpu, bus, stop, p);
        case 0x0E1u: return js_v10_2_template_0E1(cpu, bus, stop, p);
        case 0x0E2u: return js_v10_2_template_0E2(cpu, bus, stop, p);
        case 0x0E3u: return js_v10_2_template_0E3(cpu, bus, stop, p);
        case 0x0E4u: return js_v10_2_template_0E4(cpu, bus, stop, p);
        case 0x0E5u: return js_v10_2_template_0E5(cpu, bus, stop, p);
        case 0x0E6u: return js_v10_2_template_0E6(cpu, bus, stop, p);
        case 0x0E7u: return js_v10_2_template_0E7(cpu, bus, stop, p);
        case 0x0E8u: return js_v10_2_template_0E8(cpu, bus, stop, p);
        case 0x0E9u: return js_v10_2_template_0E9(cpu, bus, stop, p);
        case 0x0EAu: return js_v10_2_template_0EA(cpu, bus, stop, p);
        case 0x0EBu: return js_v10_2_template_0EB(cpu, bus, stop, p);
        case 0x0ECu: return js_v10_2_template_0EC(cpu, bus, stop, p);
        case 0x0EDu: return js_v10_2_template_0ED(cpu, bus, stop, p);
        case 0x0EEu: return js_v10_2_template_0EE(cpu, bus, stop, p);
        case 0x0EFu: return js_v10_2_template_0EF(cpu, bus, stop, p);
        case 0x0F0u: return js_v10_2_template_0F0(cpu, bus, stop, p);
        case 0x0F1u: return js_v10_2_template_0F1(cpu, bus, stop, p);
        case 0x0F2u: return js_v10_2_template_0F2(cpu, bus, stop, p);
        case 0x0F3u: return js_v10_2_template_0F3(cpu, bus, stop, p);
        case 0x0F4u: return js_v10_2_template_0F4(cpu, bus, stop, p);
        case 0x0F5u: return js_v10_2_template_0F5(cpu, bus, stop, p);
        case 0x0F6u: return js_v10_2_template_0F6(cpu, bus, stop, p);
        case 0x0F7u: return js_v10_2_template_0F7(cpu, bus, stop, p);
        case 0x0F8u: return js_v10_2_template_0F8(cpu, bus, stop, p);
        case 0x0F9u: return js_v10_2_template_0F9(cpu, bus, stop, p);
        case 0x0FAu: return js_v10_2_template_0FA(cpu, bus, stop, p);
        case 0x0FBu: return js_v10_2_template_0FB(cpu, bus, stop, p);
        case 0x0FCu: return js_v10_2_template_0FC(cpu, bus, stop, p);
        case 0x0FDu: return js_v10_2_template_0FD(cpu, bus, stop, p);
        case 0x0FEu: return js_v10_2_template_0FE(cpu, bus, stop, p);
        case 0x0FFu: return js_v10_2_template_0FF(cpu, bus, stop, p);
        case 0x100u: return js_v10_2_template_100(cpu, bus, stop, p);
        case 0x101u: return js_v10_2_template_101(cpu, bus, stop, p);
        case 0x102u: return js_v10_2_template_102(cpu, bus, stop, p);
        case 0x103u: return js_v10_2_template_103(cpu, bus, stop, p);
        case 0x104u: return js_v10_2_template_104(cpu, bus, stop, p);
        case 0x105u: return js_v10_2_template_105(cpu, bus, stop, p);
        case 0x106u: return js_v10_2_template_106(cpu, bus, stop, p);
        case 0x107u: return js_v10_2_template_107(cpu, bus, stop, p);
        case 0x108u: return js_v10_2_template_108(cpu, bus, stop, p);
        case 0x109u: return js_v10_2_template_109(cpu, bus, stop, p);
        case 0x10Au: return js_v10_2_template_10A(cpu, bus, stop, p);
        case 0x10Bu: return js_v10_2_template_10B(cpu, bus, stop, p);
        case 0x10Cu: return js_v10_2_template_10C(cpu, bus, stop, p);
        case 0x10Du: return js_v10_2_template_10D(cpu, bus, stop, p);
        case 0x10Eu: return js_v10_2_template_10E(cpu, bus, stop, p);
        case 0x10Fu: return js_v10_2_template_10F(cpu, bus, stop, p);
        case 0x110u: return js_v10_2_template_110(cpu, bus, stop, p);
        case 0x111u: return js_v10_2_template_111(cpu, bus, stop, p);
        case 0x112u: return js_v10_2_template_112(cpu, bus, stop, p);
        case 0x113u: return js_v10_2_template_113(cpu, bus, stop, p);
        case 0x114u: return js_v10_2_template_114(cpu, bus, stop, p);
        case 0x115u: return js_v10_2_template_115(cpu, bus, stop, p);
        case 0x116u: return js_v10_2_template_116(cpu, bus, stop, p);
        case 0x117u: return js_v10_2_template_117(cpu, bus, stop, p);
        case 0x118u: return js_v10_2_template_118(cpu, bus, stop, p);
        case 0x119u: return js_v10_2_template_119(cpu, bus, stop, p);
        case 0x11Au: return js_v10_2_template_11A(cpu, bus, stop, p);
        case 0x11Bu: return js_v10_2_template_11B(cpu, bus, stop, p);
        case 0x11Cu: return js_v10_2_template_11C(cpu, bus, stop, p);
        case 0x11Du: return js_v10_2_template_11D(cpu, bus, stop, p);
        case 0x11Eu: return js_v10_2_template_11E(cpu, bus, stop, p);
        case 0x11Fu: return js_v10_2_template_11F(cpu, bus, stop, p);
        case 0x120u: return js_v10_2_template_120(cpu, bus, stop, p);
        case 0x121u: return js_v10_2_template_121(cpu, bus, stop, p);
        case 0x122u: return js_v10_2_template_122(cpu, bus, stop, p);
        case 0x123u: return js_v10_2_template_123(cpu, bus, stop, p);
        case 0x124u: return js_v10_2_template_124(cpu, bus, stop, p);
        case 0x125u: return js_v10_2_template_125(cpu, bus, stop, p);
        case 0x126u: return js_v10_2_template_126(cpu, bus, stop, p);
        case 0x127u: return js_v10_2_template_127(cpu, bus, stop, p);
        case 0x128u: return js_v10_2_template_128(cpu, bus, stop, p);
        case 0x129u: return js_v10_2_template_129(cpu, bus, stop, p);
        case 0x12Au: return js_v10_2_template_12A(cpu, bus, stop, p);
        case 0x12Bu: return js_v10_2_template_12B(cpu, bus, stop, p);
        case 0x12Cu: return js_v10_2_template_12C(cpu, bus, stop, p);
        case 0x12Du: return js_v10_2_template_12D(cpu, bus, stop, p);
        case 0x12Eu: return js_v10_2_template_12E(cpu, bus, stop, p);
        case 0x12Fu: return js_v10_2_template_12F(cpu, bus, stop, p);
        case 0x130u: return js_v10_2_template_130(cpu, bus, stop, p);
        case 0x131u: return js_v10_2_template_131(cpu, bus, stop, p);
        case 0x132u: return js_v10_2_template_132(cpu, bus, stop, p);
        case 0x133u: return js_v10_2_template_133(cpu, bus, stop, p);
        case 0x134u: return js_v10_2_template_134(cpu, bus, stop, p);
        default: return js_stop_now(stop, JS_STOP_UNKNOWN_CONTEXT,
                                    js_cpu_context_key(cpu), js_cpu_context_key(cpu));
    }
}
