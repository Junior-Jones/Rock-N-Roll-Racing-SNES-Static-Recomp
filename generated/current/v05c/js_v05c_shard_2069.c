#include "v05c_static_cpu.h"

JSExecResult js_v05c_shard_2069(JSCPU *cpu, const JSBus *bus, JSStop *stop) {
    (void)bus;
    (void)stop;
    switch (js_cpu_context_key(cpu)) {
        case 0x040D2ABBu: {
            const uint32_t source_key = 0x040D2ABBu;
            cpu->pc = 0xA55Au;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9C46u;
            static const uint32_t allowed[] = { 0x040CE233u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D2AD3u: {
            const uint32_t source_key = 0x040D2AD3u;
            cpu->pc = 0xA55Du;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xA750u;
            static const uint32_t allowed[] = { 0x040D3A83u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D2AEBu: {
            const uint32_t source_key = 0x040D2AEBu;
            cpu->pc = 0xA55Fu;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040D2AF8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D2AF8u: {
            const uint32_t source_key = 0x040D2AF8u;
            cpu->pc = 0xA562u;
            uint32_t ea = js_addr_abs(cpu, 0x02D4u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D2B10u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D2B10u: {
            const uint32_t source_key = 0x040D2B10u;
            cpu->pc = 0xA565u;
            uint16_t value = 0x0032u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D2B28u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D2B28u: {
            const uint32_t source_key = 0x040D2B28u;
            cpu->pc = 0xA569u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0x839Bu;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x04041CD8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D2B48u: {
            const uint32_t source_key = 0x040D2B48u;
            cpu->pc = 0xA56Cu;
            uint16_t value = 0x0034u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D2B60u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D2B60u: {
            const uint32_t source_key = 0x040D2B60u;
            cpu->pc = 0xA56Fu;
            uint16_t value = 0x2000u;
            js_op_load_x(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D2B78u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D2B78u: {
            const uint32_t source_key = 0x040D2B78u;
            cpu->pc = 0xA573u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0x82F7u;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x040417B8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D2B98u: {
            const uint32_t source_key = 0x040D2B98u;
            cpu->pc = 0xA576u;
            uint16_t value = 0x0000u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D2BB0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D2BB0u: {
            const uint32_t source_key = 0x040D2BB0u;
            cpu->pc = 0xA57Au;
            uint32_t ea = js_addr_abs_long(0x7E2000u);
            if (!js_bus_write16(bus, ea, 1, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D2BD0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D2BD0u: {
            const uint32_t source_key = 0x040D2BD0u;
            cpu->pc = 0xA57Du;
            uint16_t value = 0x6000u;
            js_op_load_y(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D2BE8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D2BE8u: {
            const uint32_t source_key = 0x040D2BE8u;
            cpu->pc = 0xA580u;
            uint16_t value = 0x0018u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D2C00u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D2C00u: {
            const uint32_t source_key = 0x040D2C00u;
            cpu->pc = 0xA584u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0x835Bu;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x04041AD8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D3A83u: {
            const uint32_t source_key = 0x040D3A83u;
            cpu->pc = 0xA752u;
            js_op_rep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x040D3A91u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D3A91u: {
            const uint32_t source_key = 0x040D3A91u;
            cpu->pc = 0xA755u;
            uint32_t ea = js_addr_abs(cpu, 0x5C00u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D3AA9u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D3AA9u: {
            const uint32_t source_key = 0x040D3AA9u;
            cpu->pc = 0xA758u;
            uint32_t ea = js_addr_abs(cpu, 0x035Bu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D3AC1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D3AC1u: {
            const uint32_t source_key = 0x040D3AC1u;
            cpu->pc = 0xA75Bu;
            uint16_t value = 0x3000u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D3AD9u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D3AD9u: {
            const uint32_t source_key = 0x040D3AD9u;
            cpu->pc = 0xA75Eu;
            uint32_t ea = js_addr_abs(cpu, 0x0359u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D3AF1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D3AF1u: {
            const uint32_t source_key = 0x040D3AF1u;
            cpu->pc = 0xA760u;
            js_op_sep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x040D3B03u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D3B03u: {
            const uint32_t source_key = 0x040D3B03u;
            cpu->pc = 0xA762u;
            uint16_t value = 0x0022u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D3B13u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D3B13u: {
            const uint32_t source_key = 0x040D3B13u;
            cpu->pc = 0xA765u;
            cpu->pc = 0x9DB1u;
            static const uint32_t allowed[] = { 0x040CED8Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        default: return JS_EXEC_NOT_MINE;
    }
}
