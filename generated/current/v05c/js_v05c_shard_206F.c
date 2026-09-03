#include "v05c_static_cpu.h"

JSExecResult js_v05c_shard_206F(JSCPU *cpu, const JSBus *bus, JSStop *stop) {
    (void)bus;
    (void)stop;
    switch (js_cpu_context_key(cpu)) {
        case 0x040DED48u: {
            const uint32_t source_key = 0x040DED48u;
            cpu->pc = 0xBDACu;
            uint32_t ea = js_addr_abs(cpu, 0x02D8u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040DED60u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DED60u: {
            const uint32_t source_key = 0x040DED60u;
            cpu->pc = 0xBDAFu;
            uint32_t ea = js_addr_abs(cpu, 0x02CDu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040DED78u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DED78u: {
            const uint32_t source_key = 0x040DED78u;
            cpu->pc = 0xBDB2u;
            uint32_t ea = js_addr_abs(cpu, 0x02CFu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040DED90u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DED90u: {
            const uint32_t source_key = 0x040DED90u;
            cpu->pc = 0xBDB5u;
            uint16_t value = 0x0001u;
            js_op_load_x(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040DEDA8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DEDA8u: {
            const uint32_t source_key = 0x040DEDA8u;
            cpu->pc = 0xBDB8u;
            uint32_t ea = js_addr_abs(cpu, 0x0BFFu);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040DEDC0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DEDC0u: {
            const uint32_t source_key = 0x040DEDC0u;
            cpu->pc = 0xBDBBu;
            uint16_t value = 0x00FFu;
            js_op_and(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040DEDD8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DEDD8u: {
            const uint32_t source_key = 0x040DEDD8u;
            cpu->pc = 0xBDBEu;
            uint16_t value = 0x0002u;
            js_op_compare(cpu, cpu->a, value, 16u);
            static const uint32_t allowed[] = { 0x040DEDF0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DEDF0u: {
            const uint32_t source_key = 0x040DEDF0u;
            cpu->pc = 0xBDC0u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (7));
            static const uint32_t allowed[] = { 0x040DEE00u, 0x040DEE38u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DEE00u: {
            const uint32_t source_key = 0x040DEE00u;
            cpu->pc = 0xBDC3u;
            uint32_t ea = js_addr_abs(cpu, 0x02D4u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040DEE18u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DEE18u: {
            const uint32_t source_key = 0x040DEE18u;
            cpu->pc = 0xBDC6u;
            uint32_t ea = js_addr_abs(cpu, 0x02DCu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_x(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040DEE30u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DEE30u: {
            const uint32_t source_key = 0x040DEE30u;
            cpu->pc = 0xBDC7u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040DD2A0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DEE38u: {
            const uint32_t source_key = 0x040DEE38u;
            cpu->pc = 0xBDCAu;
            uint32_t ea = js_addr_abs(cpu, 0x02D4u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_x(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040DEE50u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DEE50u: {
            const uint32_t source_key = 0x040DEE50u;
            cpu->pc = 0xBDCDu;
            uint32_t ea = js_addr_abs(cpu, 0x02DCu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040DEE68u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DEE68u: {
            const uint32_t source_key = 0x040DEE68u;
            cpu->pc = 0xBDCEu;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040DD2A0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        default: return JS_EXEC_NOT_MINE;
    }
}
