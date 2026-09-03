#include "v05c_static_cpu.h"

JSExecResult js_v05c_shard_2030(JSCPU *cpu, const JSBus *bus, JSStop *stop) {
    (void)bus;
    (void)stop;
    switch (js_cpu_context_key(cpu)) {
        case 0x04060333u: {
            const uint32_t source_key = 0x04060333u;
            cpu->pc = 0xC067u;
            if (!js_stack_push8(cpu, bus, cpu->dbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0406033Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0406033Bu: {
            const uint32_t source_key = 0x0406033Bu;
            cpu->pc = 0xC068u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04060343u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04060343u: {
            const uint32_t source_key = 0x04060343u;
            cpu->pc = 0xC069u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x0406034Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0406034Bu: {
            const uint32_t source_key = 0x0406034Bu;
            cpu->pc = 0xC06Cu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xC06Eu;
            static const uint32_t allowed[] = { 0x04060373u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04060363u: {
            const uint32_t source_key = 0x04060363u;
            cpu->pc = 0xC06Du;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x0406036Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0406036Bu: {
            const uint32_t source_key = 0x0406036Bu;
            cpu->pc = 0xC06Eu;
            { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x040CECB3u, 0x040CF3C3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04060373u: {
            const uint32_t source_key = 0x04060373u;
            cpu->pc = 0xC071u;
            uint32_t ea = js_addr_abs(cpu, 0x2121u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0406038Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0406038Bu: {
            const uint32_t source_key = 0x0406038Bu;
            cpu->pc = 0xC073u;
            uint16_t value = 0x0008u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0406039Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0406039Bu: {
            const uint32_t source_key = 0x0406039Bu;
            cpu->pc = 0xC076u;
            uint32_t ea = js_addr_abs(cpu, 0x420Bu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040603B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040603B3u: {
            const uint32_t source_key = 0x040603B3u;
            cpu->pc = 0xC077u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x04060363u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040617A3u: {
            const uint32_t source_key = 0x040617A3u;
            cpu->pc = 0xC2F5u;
            if (!js_stack_push8(cpu, bus, cpu->dbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040617ABu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040617ABu: {
            const uint32_t source_key = 0x040617ABu;
            cpu->pc = 0xC2F6u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040617B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040617B3u: {
            const uint32_t source_key = 0x040617B3u;
            cpu->pc = 0xC2F7u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x040617BBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040617BBu: {
            const uint32_t source_key = 0x040617BBu;
            cpu->pc = 0xC2FAu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xC2FCu;
            static const uint32_t allowed[] = { 0x040617E3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040617D3u: {
            const uint32_t source_key = 0x040617D3u;
            cpu->pc = 0xC2FBu;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x040617DBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040617DBu: {
            const uint32_t source_key = 0x040617DBu;
            cpu->pc = 0xC2FCu;
            { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x040CEC93u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040617E3u: {
            const uint32_t source_key = 0x040617E3u;
            cpu->pc = 0xC2FFu;
            uint32_t ea = js_addr_abs(cpu, 0x4330u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040617FBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040617FBu: {
            const uint32_t source_key = 0x040617FBu;
            cpu->pc = 0xC301u;
            uint16_t value = 0x0022u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0406180Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0406180Bu: {
            const uint32_t source_key = 0x0406180Bu;
            cpu->pc = 0xC304u;
            uint32_t ea = js_addr_abs(cpu, 0x4331u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04061823u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04061823u: {
            const uint32_t source_key = 0x04061823u;
            cpu->pc = 0xC306u;
            uint16_t value = 0x007Eu;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04061833u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04061833u: {
            const uint32_t source_key = 0x04061833u;
            cpu->pc = 0xC309u;
            uint32_t ea = js_addr_abs(cpu, 0x4334u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0406184Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0406184Bu: {
            const uint32_t source_key = 0x0406184Bu;
            cpu->pc = 0xC30Bu;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x04061858u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04061858u: {
            const uint32_t source_key = 0x04061858u;
            cpu->pc = 0xC30Eu;
            uint16_t value = 0x2000u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04061870u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04061870u: {
            const uint32_t source_key = 0x04061870u;
            cpu->pc = 0xC311u;
            uint32_t ea = js_addr_abs(cpu, 0x4332u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04061888u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04061888u: {
            const uint32_t source_key = 0x04061888u;
            cpu->pc = 0xC314u;
            uint16_t value = 0x0200u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040618A0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040618A0u: {
            const uint32_t source_key = 0x040618A0u;
            cpu->pc = 0xC317u;
            uint32_t ea = js_addr_abs(cpu, 0x4335u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040618B8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040618B8u: {
            const uint32_t source_key = 0x040618B8u;
            cpu->pc = 0xC319u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040618CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040618CBu: {
            const uint32_t source_key = 0x040618CBu;
            cpu->pc = 0xC31Au;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040617D3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        default: return JS_EXEC_NOT_MINE;
    }
}
