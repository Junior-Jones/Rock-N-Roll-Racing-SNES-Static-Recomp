#include "v05c_static_cpu.h"

JSExecResult js_v05c_shard_2068(JSCPU *cpu, const JSBus *bus, JSStop *stop) {
    (void)bus;
    (void)stop;
    switch (js_cpu_context_key(cpu)) {
        case 0x040D0003u: {
            const uint32_t source_key = 0x040D0003u;
            cpu->pc = 0xA001u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FBA0Bu, 0x040FBD5Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D000Bu: {
            const uint32_t source_key = 0x040D000Bu;
            cpu->pc = 0xA004u;
            uint32_t ea = js_addr_abs(cpu, 0x13B6u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D0023u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D0023u: {
            const uint32_t source_key = 0x040D0023u;
            cpu->pc = 0xA006u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (7));
            static const uint32_t allowed[] = { 0x040D0033u, 0x040D006Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D0033u: {
            const uint32_t source_key = 0x040D0033u;
            cpu->pc = 0xA007u;
            js_op_load_a(cpu, js_op_incdec(cpu, cpu->a, 1, 8u), 8u);
            static const uint32_t allowed[] = { 0x040D003Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D003Bu: {
            const uint32_t source_key = 0x040D003Bu;
            cpu->pc = 0xA00Au;
            uint32_t ea = js_addr_abs(cpu, 0x13B6u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D0053u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D0053u: {
            const uint32_t source_key = 0x040D0053u;
            cpu->pc = 0xA00Cu;
            uint16_t value = 0x0001u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D0063u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D0063u: {
            const uint32_t source_key = 0x040D0063u;
            cpu->pc = 0xA00Du;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FBA4Bu, 0x040FBD9Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D006Bu: {
            const uint32_t source_key = 0x040D006Bu;
            cpu->pc = 0xA00Fu;
            uint16_t value = 0x0014u;
            js_op_compare(cpu, cpu->a, value, 8u);
            static const uint32_t allowed[] = { 0x040D007Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D007Bu: {
            const uint32_t source_key = 0x040D007Bu;
            cpu->pc = 0xA011u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (7));
            static const uint32_t allowed[] = { 0x040D008Bu, 0x040D00C3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D008Bu: {
            const uint32_t source_key = 0x040D008Bu;
            cpu->pc = 0xA012u;
            js_op_load_a(cpu, js_op_incdec(cpu, cpu->a, 1, 8u), 8u);
            static const uint32_t allowed[] = { 0x040D0093u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D0093u: {
            const uint32_t source_key = 0x040D0093u;
            cpu->pc = 0xA015u;
            uint32_t ea = js_addr_abs(cpu, 0x13B6u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D00ABu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D00ABu: {
            const uint32_t source_key = 0x040D00ABu;
            cpu->pc = 0xA017u;
            uint16_t value = 0x0002u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D00BBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D00BBu: {
            const uint32_t source_key = 0x040D00BBu;
            cpu->pc = 0xA018u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FBA4Bu, 0x040FBD9Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D00C3u: {
            const uint32_t source_key = 0x040D00C3u;
            cpu->pc = 0xA019u;
            js_op_load_a(cpu, js_op_incdec(cpu, cpu->a, 1, 8u), 8u);
            static const uint32_t allowed[] = { 0x040D00CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D00CBu: {
            const uint32_t source_key = 0x040D00CBu;
            cpu->pc = 0xA01Bu;
            uint16_t value = 0x001Eu;
            js_op_compare(cpu, cpu->a, value, 8u);
            static const uint32_t allowed[] = { 0x040D00DBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D00DBu: {
            const uint32_t source_key = 0x040D00DBu;
            cpu->pc = 0xA01Du;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (2));
            static const uint32_t allowed[] = { 0x040D00EBu, 0x040D00FBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D00EBu: {
            const uint32_t source_key = 0x040D00EBu;
            cpu->pc = 0xA01Fu;
            uint16_t value = 0x0000u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D00FBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D00FBu: {
            const uint32_t source_key = 0x040D00FBu;
            cpu->pc = 0xA022u;
            uint32_t ea = js_addr_abs(cpu, 0x13B6u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D0113u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D0113u: {
            const uint32_t source_key = 0x040D0113u;
            cpu->pc = 0xA024u;
            uint16_t value = 0x0000u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D0123u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D0123u: {
            const uint32_t source_key = 0x040D0123u;
            cpu->pc = 0xA025u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FBA4Bu, 0x040FBD9Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D02BBu: {
            const uint32_t source_key = 0x040D02BBu;
            cpu->pc = 0xA059u;
            uint16_t value = 0x000Fu;
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D02CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D02CBu: {
            const uint32_t source_key = 0x040D02CBu;
            cpu->pc = 0xA05Bu;
            uint16_t value = 0x00FFu;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D02DBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D02DBu: {
            const uint32_t source_key = 0x040D02DBu;
            cpu->pc = 0xA05Eu;
            uint32_t ea = js_addr_abs_x(cpu, 0x02E7u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D02F3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D02F3u: {
            const uint32_t source_key = 0x040D02F3u;
            cpu->pc = 0xA05Fu;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, -1, 8u), 8u);
            static const uint32_t allowed[] = { 0x040D02FBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D02FBu: {
            const uint32_t source_key = 0x040D02FBu;
            cpu->pc = 0xA061u;
            if (js_branch_condition(cpu, 'P')) cpu->pc = (uint16_t)(cpu->pc + (-6));
            static const uint32_t allowed[] = { 0x040D02DBu, 0x040D030Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D030Bu: {
            const uint32_t source_key = 0x040D030Bu;
            cpu->pc = 0xA062u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040CF033u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        default: return JS_EXEC_NOT_MINE;
    }
}
