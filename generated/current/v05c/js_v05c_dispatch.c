#include "js_v05c_dispatch.h"

JSExecResult js_v05c_shard_0020(JSCPU *cpu, const JSBus *bus, JSStop *stop);
JSExecResult js_v05c_shard_2020(JSCPU *cpu, const JSBus *bus, JSStop *stop);
JSExecResult js_v05c_shard_2021(JSCPU *cpu, const JSBus *bus, JSStop *stop);
JSExecResult js_v05c_shard_2028(JSCPU *cpu, const JSBus *bus, JSStop *stop);
JSExecResult js_v05c_shard_2029(JSCPU *cpu, const JSBus *bus, JSStop *stop);
JSExecResult js_v05c_shard_2030(JSCPU *cpu, const JSBus *bus, JSStop *stop);
JSExecResult js_v05c_shard_203E(JSCPU *cpu, const JSBus *bus, JSStop *stop);
JSExecResult js_v05c_shard_2067(JSCPU *cpu, const JSBus *bus, JSStop *stop);
JSExecResult js_v05c_shard_2068(JSCPU *cpu, const JSBus *bus, JSStop *stop);
JSExecResult js_v05c_shard_2069(JSCPU *cpu, const JSBus *bus, JSStop *stop);
JSExecResult js_v05c_shard_206B(JSCPU *cpu, const JSBus *bus, JSStop *stop);
JSExecResult js_v05c_shard_206D(JSCPU *cpu, const JSBus *bus, JSStop *stop);
JSExecResult js_v05c_shard_206E(JSCPU *cpu, const JSBus *bus, JSStop *stop);
JSExecResult js_v05c_shard_206F(JSCPU *cpu, const JSBus *bus, JSStop *stop);
JSExecResult js_v05c_shard_207D(JSCPU *cpu, const JSBus *bus, JSStop *stop);
JSExecResult js_v05c_shard_207E(JSCPU *cpu, const JSBus *bus, JSStop *stop);
JSExecResult js_v05c_shard_24BB(JSCPU *cpu, const JSBus *bus, JSStop *stop);
JSExecResult js_v05c_shard_24BC(JSCPU *cpu, const JSBus *bus, JSStop *stop);

JSExecResult js_v05c_step(JSCPU *cpu, const JSBus *bus, JSStop *stop) {
    JSExecResult r;
    uint32_t group;
    if (!cpu) return js_stop_now(stop, JS_STOP_INVALID_CPU_STATE, 0u, 0u);
    js_stop_clear(stop);
    if (cpu->e > 1u || (cpu->e && ((cpu->p & (JS_P_M|JS_P_X)) != (JS_P_M|JS_P_X))))
        return js_stop_now(stop, JS_STOP_INVALID_CPU_STATE, js_cpu_context_key(cpu), js_cpu_context_key(cpu));
    if ((cpu->p & JS_P_X) && ((cpu->x & 0xFF00u) || (cpu->y & 0xFF00u)))
        return js_stop_now(stop, JS_STOP_INVALID_CPU_STATE, js_cpu_context_key(cpu), js_cpu_context_key(cpu));
    group = ((((uint32_t)cpu->pbr << 16) | cpu->pc) >> 10);
    switch (group) {
        case 0x0020u: r = js_v05c_shard_0020(cpu, bus, stop); break;
        case 0x2020u: r = js_v05c_shard_2020(cpu, bus, stop); break;
        case 0x2021u: r = js_v05c_shard_2021(cpu, bus, stop); break;
        case 0x2028u: r = js_v05c_shard_2028(cpu, bus, stop); break;
        case 0x2029u: r = js_v05c_shard_2029(cpu, bus, stop); break;
        case 0x2030u: r = js_v05c_shard_2030(cpu, bus, stop); break;
        case 0x203Eu: r = js_v05c_shard_203E(cpu, bus, stop); break;
        case 0x2067u: r = js_v05c_shard_2067(cpu, bus, stop); break;
        case 0x2068u: r = js_v05c_shard_2068(cpu, bus, stop); break;
        case 0x2069u: r = js_v05c_shard_2069(cpu, bus, stop); break;
        case 0x206Bu: r = js_v05c_shard_206B(cpu, bus, stop); break;
        case 0x206Du: r = js_v05c_shard_206D(cpu, bus, stop); break;
        case 0x206Eu: r = js_v05c_shard_206E(cpu, bus, stop); break;
        case 0x206Fu: r = js_v05c_shard_206F(cpu, bus, stop); break;
        case 0x207Du: r = js_v05c_shard_207D(cpu, bus, stop); break;
        case 0x207Eu: r = js_v05c_shard_207E(cpu, bus, stop); break;
        case 0x24BBu: r = js_v05c_shard_24BB(cpu, bus, stop); break;
        case 0x24BCu: r = js_v05c_shard_24BC(cpu, bus, stop); break;
        default: r = JS_EXEC_NOT_MINE; break;
    }
    if (r == JS_EXEC_NOT_MINE) return js_stop_now(stop, JS_STOP_UNKNOWN_CONTEXT, js_cpu_context_key(cpu), js_cpu_context_key(cpu));
    return r;
}
