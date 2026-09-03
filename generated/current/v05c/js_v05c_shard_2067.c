#include "v05c_static_cpu.h"

JSExecResult js_v05c_shard_2067(JSCPU *cpu, const JSBus *bus, JSStop *stop) {
    (void)bus;
    (void)stop;
    switch (js_cpu_context_key(cpu)) {
        case 0x040CE233u: {
            const uint32_t source_key = 0x040CE233u;
            cpu->pc = 0x9C48u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040CE240u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE240u: {
            const uint32_t source_key = 0x040CE240u;
            cpu->pc = 0x9C4Bu;
            uint16_t value = 0x0000u;
            js_op_load_x(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CE258u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE258u: {
            const uint32_t source_key = 0x040CE258u;
            cpu->pc = 0x9C4Eu;
            uint16_t value = 0x0080u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CE270u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE270u: {
            const uint32_t source_key = 0x040CE270u;
            cpu->pc = 0x9C51u;
            uint32_t ea = js_addr_abs_x(cpu, 0x13FAu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CE288u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE288u: {
            const uint32_t source_key = 0x040CE288u;
            cpu->pc = 0x9C52u;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CE290u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE290u: {
            const uint32_t source_key = 0x040CE290u;
            cpu->pc = 0x9C53u;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CE298u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE298u: {
            const uint32_t source_key = 0x040CE298u;
            cpu->pc = 0x9C56u;
            uint32_t ea = js_addr_abs_x(cpu, 0x13FAu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CE2B0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE2B0u: {
            const uint32_t source_key = 0x040CE2B0u;
            cpu->pc = 0x9C57u;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CE2B8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE2B8u: {
            const uint32_t source_key = 0x040CE2B8u;
            cpu->pc = 0x9C58u;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CE2C0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE2C0u: {
            const uint32_t source_key = 0x040CE2C0u;
            cpu->pc = 0x9C5Bu;
            uint16_t value = 0x0100u;
            js_op_compare(cpu, cpu->x, value, 16u);
            static const uint32_t allowed[] = { 0x040CE2D8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE2D8u: {
            const uint32_t source_key = 0x040CE2D8u;
            cpu->pc = 0x9C5Du;
            if (js_branch_condition(cpu, 'C')) cpu->pc = (uint16_t)(cpu->pc + (-15));
            static const uint32_t allowed[] = { 0x040CE270u, 0x040CE2E8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE2E8u: {
            const uint32_t source_key = 0x040CE2E8u;
            cpu->pc = 0x9C60u;
            uint16_t value = 0x0000u;
            js_op_load_x(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CE300u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE300u: {
            const uint32_t source_key = 0x040CE300u;
            cpu->pc = 0x9C63u;
            uint16_t value = 0xFFFFu;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CE318u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE318u: {
            const uint32_t source_key = 0x040CE318u;
            cpu->pc = 0x9C66u;
            uint32_t ea = js_addr_abs_x(cpu, 0x14FAu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CE330u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE330u: {
            const uint32_t source_key = 0x040CE330u;
            cpu->pc = 0x9C67u;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CE338u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE338u: {
            const uint32_t source_key = 0x040CE338u;
            cpu->pc = 0x9C68u;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CE340u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE340u: {
            const uint32_t source_key = 0x040CE340u;
            cpu->pc = 0x9C6Bu;
            uint16_t value = 0x0010u;
            js_op_compare(cpu, cpu->x, value, 16u);
            static const uint32_t allowed[] = { 0x040CE358u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE358u: {
            const uint32_t source_key = 0x040CE358u;
            cpu->pc = 0x9C6Du;
            if (js_branch_condition(cpu, 'C')) cpu->pc = (uint16_t)(cpu->pc + (-10));
            static const uint32_t allowed[] = { 0x040CE318u, 0x040CE368u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE368u: {
            const uint32_t source_key = 0x040CE368u;
            cpu->pc = 0x9C6Fu;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040CE37Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE37Bu: {
            const uint32_t source_key = 0x040CE37Bu;
            cpu->pc = 0x9C72u;
            uint32_t ea = js_addr_abs(cpu, 0x4340u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CE393u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE393u: {
            const uint32_t source_key = 0x040CE393u;
            cpu->pc = 0x9C74u;
            uint16_t value = 0x0004u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040CE3A3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE3A3u: {
            const uint32_t source_key = 0x040CE3A3u;
            cpu->pc = 0x9C77u;
            uint32_t ea = js_addr_abs(cpu, 0x4341u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CE3BBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE3BBu: {
            const uint32_t source_key = 0x040CE3BBu;
            cpu->pc = 0x9C79u;
            uint16_t value = 0x007Eu;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040CE3CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE3CBu: {
            const uint32_t source_key = 0x040CE3CBu;
            cpu->pc = 0x9C7Cu;
            uint32_t ea = js_addr_abs(cpu, 0x4344u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CE3E3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE3E3u: {
            const uint32_t source_key = 0x040CE3E3u;
            cpu->pc = 0x9C7Fu;
            uint32_t ea = js_addr_abs(cpu, 0x0240u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CE3FBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE3FBu: {
            const uint32_t source_key = 0x040CE3FBu;
            cpu->pc = 0x9C80u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040D2AD3u, 0x040D7A1Bu, 0x040DD1DBu, 0x040FA2DBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE463u: {
            const uint32_t source_key = 0x040CE463u;
            cpu->pc = 0x9C8Eu;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040CE470u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE470u: {
            const uint32_t source_key = 0x040CE470u;
            cpu->pc = 0x9C91u;
            uint16_t value = 0x00FEu;
            js_op_load_y(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CE488u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE488u: {
            const uint32_t source_key = 0x040CE488u;
            cpu->pc = 0x9C94u;
            uint32_t ea = js_addr_abs_y(cpu, 0x13FAu);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CE4A0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE4A0u: {
            const uint32_t source_key = 0x040CE4A0u;
            cpu->pc = 0x9C97u;
            uint32_t ea = js_addr_abs_y(cpu, 0x161Au);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CE4B8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE4B8u: {
            const uint32_t source_key = 0x040CE4B8u;
            cpu->pc = 0x9C98u;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, -1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CE4C0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE4C0u: {
            const uint32_t source_key = 0x040CE4C0u;
            cpu->pc = 0x9C99u;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, -1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CE4C8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE4C8u: {
            const uint32_t source_key = 0x040CE4C8u;
            cpu->pc = 0x9C9Bu;
            if (js_branch_condition(cpu, 'P')) cpu->pc = (uint16_t)(cpu->pc + (-10));
            static const uint32_t allowed[] = { 0x040CE488u, 0x040CE4D8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE4D8u: {
            const uint32_t source_key = 0x040CE4D8u;
            cpu->pc = 0x9C9Eu;
            uint16_t value = 0x000Eu;
            js_op_load_y(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CE4F0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE4F0u: {
            const uint32_t source_key = 0x040CE4F0u;
            cpu->pc = 0x9CA1u;
            uint32_t ea = js_addr_abs_y(cpu, 0x14FAu);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CE508u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE508u: {
            const uint32_t source_key = 0x040CE508u;
            cpu->pc = 0x9CA4u;
            uint32_t ea = js_addr_abs_y(cpu, 0x171Au);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CE520u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE520u: {
            const uint32_t source_key = 0x040CE520u;
            cpu->pc = 0x9CA5u;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, -1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CE528u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE528u: {
            const uint32_t source_key = 0x040CE528u;
            cpu->pc = 0x9CA6u;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, -1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CE530u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE530u: {
            const uint32_t source_key = 0x040CE530u;
            cpu->pc = 0x9CA8u;
            if (js_branch_condition(cpu, 'P')) cpu->pc = (uint16_t)(cpu->pc + (-10));
            static const uint32_t allowed[] = { 0x040CE4F0u, 0x040CE540u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE540u: {
            const uint32_t source_key = 0x040CE540u;
            cpu->pc = 0x9CAAu;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040CE553u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE553u: {
            const uint32_t source_key = 0x040CE553u;
            cpu->pc = 0x9CADu;
            uint32_t ea = js_addr_abs(cpu, 0x0240u);
            uint16_t original = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
            uint16_t result = js_op_incdec(cpu, original, 1, 8u);
            if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CE56Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE56Bu: {
            const uint32_t source_key = 0x040CE56Bu;
            cpu->pc = 0x9CAEu;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FA5DBu, 0x040FA77Bu, 0x040FAB43u, 0x040FAC7Bu, 0x040FAD6Bu, 0x040FB31Bu, 0x040FBADBu, 0x040FBE2Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE5B3u: {
            const uint32_t source_key = 0x040CE5B3u;
            cpu->pc = 0x9CB9u;
            uint32_t ea = js_addr_abs(cpu, 0x0240u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040CE5CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE5CBu: {
            const uint32_t source_key = 0x040CE5CBu;
            cpu->pc = 0x9CBBu;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (54));
            static const uint32_t allowed[] = { 0x040CE5DBu, 0x040CE78Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE5DBu: {
            const uint32_t source_key = 0x040CE5DBu;
            cpu->pc = 0x9CBEu;
            uint32_t ea = js_addr_abs(cpu, 0x0240u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CE5F3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE5F3u: {
            const uint32_t source_key = 0x040CE5F3u;
            cpu->pc = 0x9CC0u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040CE600u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE600u: {
            const uint32_t source_key = 0x040CE600u;
            cpu->pc = 0x9CC3u;
            uint32_t ea = js_addr_abs(cpu, 0x2102u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CE618u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE618u: {
            const uint32_t source_key = 0x040CE618u;
            cpu->pc = 0x9CC6u;
            uint16_t value = 0x13FAu;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CE630u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE630u: {
            const uint32_t source_key = 0x040CE630u;
            cpu->pc = 0x9CC9u;
            uint32_t ea = js_addr_abs(cpu, 0x4342u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CE648u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE648u: {
            const uint32_t source_key = 0x040CE648u;
            cpu->pc = 0x9CCCu;
            uint16_t value = 0x0100u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CE660u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE660u: {
            const uint32_t source_key = 0x040CE660u;
            cpu->pc = 0x9CCFu;
            uint32_t ea = js_addr_abs(cpu, 0x4345u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CE678u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE678u: {
            const uint32_t source_key = 0x040CE678u;
            cpu->pc = 0x9CD1u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040CE68Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE68Bu: {
            const uint32_t source_key = 0x040CE68Bu;
            cpu->pc = 0x9CD3u;
            uint16_t value = 0x0010u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040CE69Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE69Bu: {
            const uint32_t source_key = 0x040CE69Bu;
            cpu->pc = 0x9CD6u;
            uint32_t ea = js_addr_abs(cpu, 0x420Bu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CE6B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE6B3u: {
            const uint32_t source_key = 0x040CE6B3u;
            cpu->pc = 0x9CD8u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040CE6C0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE6C0u: {
            const uint32_t source_key = 0x040CE6C0u;
            cpu->pc = 0x9CDBu;
            uint16_t value = 0x0100u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CE6D8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE6D8u: {
            const uint32_t source_key = 0x040CE6D8u;
            cpu->pc = 0x9CDEu;
            uint32_t ea = js_addr_abs(cpu, 0x2102u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CE6F0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE6F0u: {
            const uint32_t source_key = 0x040CE6F0u;
            cpu->pc = 0x9CE1u;
            uint16_t value = 0x14FAu;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CE708u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE708u: {
            const uint32_t source_key = 0x040CE708u;
            cpu->pc = 0x9CE4u;
            uint32_t ea = js_addr_abs(cpu, 0x4342u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CE720u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE720u: {
            const uint32_t source_key = 0x040CE720u;
            cpu->pc = 0x9CE7u;
            uint16_t value = 0x0010u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CE738u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE738u: {
            const uint32_t source_key = 0x040CE738u;
            cpu->pc = 0x9CEAu;
            uint32_t ea = js_addr_abs(cpu, 0x4345u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CE750u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE750u: {
            const uint32_t source_key = 0x040CE750u;
            cpu->pc = 0x9CECu;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040CE763u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE763u: {
            const uint32_t source_key = 0x040CE763u;
            cpu->pc = 0x9CEEu;
            uint16_t value = 0x0010u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040CE773u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE773u: {
            const uint32_t source_key = 0x040CE773u;
            cpu->pc = 0x9CF1u;
            uint32_t ea = js_addr_abs(cpu, 0x420Bu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CE78Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CE78Bu: {
            const uint32_t source_key = 0x040CE78Bu;
            cpu->pc = 0x9CF2u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FA5F3u, 0x040FA793u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEA03u: {
            const uint32_t source_key = 0x040CEA03u;
            cpu->pc = 0x9D42u;
            uint16_t value = 0x0015u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040CEA13u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEA13u: {
            const uint32_t source_key = 0x040CEA13u;
            cpu->pc = 0x9D45u;
            uint32_t ea = js_addr_abs(cpu, 0x212Cu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEA2Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEA2Bu: {
            const uint32_t source_key = 0x040CEA2Bu;
            cpu->pc = 0x9D47u;
            uint16_t value = 0x0080u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040CEA3Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEA3Bu: {
            const uint32_t source_key = 0x040CEA3Bu;
            cpu->pc = 0x9D4Au;
            uint32_t ea = js_addr_abs(cpu, 0x2115u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEA53u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEA53u: {
            const uint32_t source_key = 0x040CEA53u;
            cpu->pc = 0x9D4Du;
            uint32_t ea = js_addr_abs(cpu, 0x0355u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEA6Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEA6Bu: {
            const uint32_t source_key = 0x040CEA6Bu;
            cpu->pc = 0x9D4Fu;
            uint16_t value = 0x0081u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040CEA7Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEA7Bu: {
            const uint32_t source_key = 0x040CEA7Bu;
            cpu->pc = 0x9D52u;
            uint32_t ea = js_addr_abs(cpu, 0x4200u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEA93u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEA93u: {
            const uint32_t source_key = 0x040CEA93u;
            cpu->pc = 0x9D54u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040CEAA0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEAA0u: {
            const uint32_t source_key = 0x040CEAA0u;
            cpu->pc = 0x9D57u;
            uint16_t value = 0x3C00u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CEAB8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEAB8u: {
            const uint32_t source_key = 0x040CEAB8u;
            cpu->pc = 0x9D5Au;
            uint32_t ea = js_addr_abs(cpu, 0x035Bu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEAD0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEAD0u: {
            const uint32_t source_key = 0x040CEAD0u;
            cpu->pc = 0x9D5Du;
            uint16_t value = 0x0030u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CEAE8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEAE8u: {
            const uint32_t source_key = 0x040CEAE8u;
            cpu->pc = 0x9D61u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0x839Bu;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x04041CD8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEB08u: {
            const uint32_t source_key = 0x040CEB08u;
            cpu->pc = 0x9D64u;
            uint16_t value = 0x2000u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CEB20u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEB20u: {
            const uint32_t source_key = 0x040CEB20u;
            cpu->pc = 0x9D67u;
            uint32_t ea = js_addr_abs(cpu, 0x0359u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEB38u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEB38u: {
            const uint32_t source_key = 0x040CEB38u;
            cpu->pc = 0x9D69u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040CEB4Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEB4Bu: {
            const uint32_t source_key = 0x040CEB4Bu;
            cpu->pc = 0x9D6Au;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040D6263u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEB90u: {
            const uint32_t source_key = 0x040CEB90u;
            cpu->pc = 0x9D73u;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->y, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEB98u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEB98u: {
            const uint32_t source_key = 0x040CEB98u;
            cpu->pc = 0x9D74u;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->x, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEBA0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEBA0u: {
            const uint32_t source_key = 0x040CEBA0u;
            cpu->pc = 0x9D78u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0x839Bu;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x04041CD8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEBC0u: {
            const uint32_t source_key = 0x040CEBC0u;
            cpu->pc = 0x9D79u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x040CEBC8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEBC8u: {
            const uint32_t source_key = 0x040CEBC8u;
            cpu->pc = 0x9D7Du;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0x839Bu;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x04041CD8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEBE8u: {
            const uint32_t source_key = 0x040CEBE8u;
            cpu->pc = 0x9D7Eu;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x040CEBF0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEBF0u: {
            const uint32_t source_key = 0x040CEBF0u;
            cpu->pc = 0x9D81u;
            uint16_t value = 0x2000u;
            js_op_load_x(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CEC08u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEC08u: {
            const uint32_t source_key = 0x040CEC08u;
            cpu->pc = 0x9D85u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0x82F7u;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x040417B8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEC28u: {
            const uint32_t source_key = 0x040CEC28u;
            cpu->pc = 0x9D88u;
            uint16_t value = 0x0000u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CEC40u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEC40u: {
            const uint32_t source_key = 0x040CEC40u;
            cpu->pc = 0x9D8Cu;
            uint32_t ea = js_addr_abs_long(0x7E2000u);
            if (!js_bus_write16(bus, ea, 1, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEC60u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEC60u: {
            const uint32_t source_key = 0x040CEC60u;
            cpu->pc = 0x9D8Eu;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040CEC73u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEC73u: {
            const uint32_t source_key = 0x040CEC73u;
            cpu->pc = 0x9D92u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0xC2F4u;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x040617A3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEC93u: {
            const uint32_t source_key = 0x040CEC93u;
            cpu->pc = 0x9D96u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0xC066u;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x04060333u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CECB3u: {
            const uint32_t source_key = 0x040CECB3u;
            cpu->pc = 0x9D98u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040CECC0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CECC0u: {
            const uint32_t source_key = 0x040CECC0u;
            return js_stop_now(stop, JS_STOP_UNPROVED_RETURN, source_key, source_key);
        }
        case 0x040CECCBu: {
            const uint32_t source_key = 0x040CECCBu;
            cpu->pc = 0x9D9Au;
            if (!js_stack_push8(cpu, bus, cpu->p, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CECD3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CECD3u: {
            const uint32_t source_key = 0x040CECD3u;
            cpu->pc = 0x9D9Cu;
            js_op_sep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x040CECE3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CECE3u: {
            const uint32_t source_key = 0x040CECE3u;
            cpu->pc = 0x9D9Fu;
            uint32_t ea = js_addr_abs(cpu, 0x0BFFu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040CECFBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CECFBu: {
            const uint32_t source_key = 0x040CECFBu;
            cpu->pc = 0x9DA1u;
            uint16_t value = 0x0002u;
            js_op_compare(cpu, cpu->a, value, 8u);
            static const uint32_t allowed[] = { 0x040CED0Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CED0Bu: {
            const uint32_t source_key = 0x040CED0Bu;
            cpu->pc = 0x9DA3u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (3));
            static const uint32_t allowed[] = { 0x040CED1Bu, 0x040CED33u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CED1Bu: {
            const uint32_t source_key = 0x040CED1Bu;
            cpu->pc = 0x9DA4u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; cpu->p = (uint8_t)(v | (cpu->e ? (JS_P_M|JS_P_X) : 0u)); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x040CED23u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CED23u: {
            const uint32_t source_key = 0x040CED23u;
            cpu->pc = 0x9DA5u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_C);
            static const uint32_t allowed[] = { 0x040CED2Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CED2Bu: {
            const uint32_t source_key = 0x040CED2Bu;
            cpu->pc = 0x9DA6u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040D67A3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CED33u: {
            const uint32_t source_key = 0x040CED33u;
            cpu->pc = 0x9DA7u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; cpu->p = (uint8_t)(v | (cpu->e ? (JS_P_M|JS_P_X) : 0u)); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x040CED3Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CED3Bu: {
            const uint32_t source_key = 0x040CED3Bu;
            cpu->pc = 0x9DA8u;
            cpu->p = (uint8_t)(cpu->p | JS_P_C);
            static const uint32_t allowed[] = { 0x040CED43u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CED43u: {
            const uint32_t source_key = 0x040CED43u;
            cpu->pc = 0x9DA9u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040D67A3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CED8Bu: {
            const uint32_t source_key = 0x040CED8Bu;
            cpu->pc = 0x9DB4u;
            uint32_t ea = js_addr_abs(cpu, 0x2101u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEDA3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEDA3u: {
            const uint32_t source_key = 0x040CEDA3u;
            cpu->pc = 0x9DB7u;
            uint32_t ea = js_addr_abs(cpu, 0x210Du);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEDBBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEDBBu: {
            const uint32_t source_key = 0x040CEDBBu;
            cpu->pc = 0x9DBAu;
            uint32_t ea = js_addr_abs(cpu, 0x210Du);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEDD3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEDD3u: {
            const uint32_t source_key = 0x040CEDD3u;
            cpu->pc = 0x9DBDu;
            uint32_t ea = js_addr_abs(cpu, 0x210Fu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEDEBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEDEBu: {
            const uint32_t source_key = 0x040CEDEBu;
            cpu->pc = 0x9DC0u;
            uint32_t ea = js_addr_abs(cpu, 0x210Fu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEE03u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEE03u: {
            const uint32_t source_key = 0x040CEE03u;
            cpu->pc = 0x9DC3u;
            uint32_t ea = js_addr_abs(cpu, 0x2111u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEE1Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEE1Bu: {
            const uint32_t source_key = 0x040CEE1Bu;
            cpu->pc = 0x9DC6u;
            uint32_t ea = js_addr_abs(cpu, 0x2111u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEE33u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEE33u: {
            const uint32_t source_key = 0x040CEE33u;
            cpu->pc = 0x9DC8u;
            uint16_t value = 0x00FFu;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040CEE43u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEE43u: {
            const uint32_t source_key = 0x040CEE43u;
            cpu->pc = 0x9DCBu;
            uint32_t ea = js_addr_abs(cpu, 0x210Eu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEE5Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEE5Bu: {
            const uint32_t source_key = 0x040CEE5Bu;
            cpu->pc = 0x9DCEu;
            uint32_t ea = js_addr_abs(cpu, 0x210Eu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEE73u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEE73u: {
            const uint32_t source_key = 0x040CEE73u;
            cpu->pc = 0x9DD1u;
            uint32_t ea = js_addr_abs(cpu, 0x2110u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEE8Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEE8Bu: {
            const uint32_t source_key = 0x040CEE8Bu;
            cpu->pc = 0x9DD4u;
            uint32_t ea = js_addr_abs(cpu, 0x2110u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEEA3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEEA3u: {
            const uint32_t source_key = 0x040CEEA3u;
            cpu->pc = 0x9DD7u;
            uint32_t ea = js_addr_abs(cpu, 0x2112u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEEBBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEEBBu: {
            const uint32_t source_key = 0x040CEEBBu;
            cpu->pc = 0x9DDAu;
            uint32_t ea = js_addr_abs(cpu, 0x2112u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEED3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEED3u: {
            const uint32_t source_key = 0x040CEED3u;
            cpu->pc = 0x9DDDu;
            uint32_t ea = js_addr_abs(cpu, 0x0297u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEEEBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEEEBu: {
            const uint32_t source_key = 0x040CEEEBu;
            cpu->pc = 0x9DE0u;
            uint32_t ea = js_addr_abs(cpu, 0x0298u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEF03u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEF03u: {
            const uint32_t source_key = 0x040CEF03u;
            cpu->pc = 0x9DE3u;
            uint32_t ea = js_addr_abs(cpu, 0x13B6u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEF1Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEF1Bu: {
            const uint32_t source_key = 0x040CEF1Bu;
            cpu->pc = 0x9DE6u;
            uint32_t ea = js_addr_abs(cpu, 0x13B8u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEF33u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEF33u: {
            const uint32_t source_key = 0x040CEF33u;
            cpu->pc = 0x9DE9u;
            uint32_t ea = js_addr_abs(cpu, 0x031Du);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEF4Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEF4Bu: {
            const uint32_t source_key = 0x040CEF4Bu;
            cpu->pc = 0x9DECu;
            uint32_t ea = js_addr_abs(cpu, 0x02D0u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEF63u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEF63u: {
            const uint32_t source_key = 0x040CEF63u;
            cpu->pc = 0x9DEFu;
            uint32_t ea = js_addr_abs(cpu, 0x02D1u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEF7Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEF7Bu: {
            const uint32_t source_key = 0x040CEF7Bu;
            cpu->pc = 0x9DF1u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040CEF88u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEF88u: {
            const uint32_t source_key = 0x040CEF88u;
            cpu->pc = 0x9DF4u;
            uint16_t value = 0xFFFFu;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CEFA0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEFA0u: {
            const uint32_t source_key = 0x040CEFA0u;
            cpu->pc = 0x9DF7u;
            uint32_t ea = js_addr_abs(cpu, 0x1AE2u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEFB8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEFB8u: {
            const uint32_t source_key = 0x040CEFB8u;
            cpu->pc = 0x9DF9u;
            uint32_t ea = js_addr_dp(cpu, 0xC0u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEFC8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEFC8u: {
            const uint32_t source_key = 0x040CEFC8u;
            cpu->pc = 0x9DFBu;
            uint32_t ea = js_addr_dp(cpu, 0xC2u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEFD8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEFD8u: {
            const uint32_t source_key = 0x040CEFD8u;
            cpu->pc = 0x9DFEu;
            uint32_t ea = js_addr_abs(cpu, 0x0243u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CEFF0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CEFF0u: {
            const uint32_t source_key = 0x040CEFF0u;
            cpu->pc = 0x9E01u;
            uint32_t ea = js_addr_abs(cpu, 0x0245u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CF008u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF008u: {
            const uint32_t source_key = 0x040CF008u;
            cpu->pc = 0x9E03u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040CF01Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF01Bu: {
            const uint32_t source_key = 0x040CF01Bu;
            cpu->pc = 0x9E06u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xA057u;
            static const uint32_t allowed[] = { 0x040D02BBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF033u: {
            const uint32_t source_key = 0x040CF033u;
            cpu->pc = 0x9E09u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9F5Cu;
            static const uint32_t allowed[] = { 0x040CFAE3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF04Bu: {
            const uint32_t source_key = 0x040CF04Bu;
            cpu->pc = 0x9E0Du;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0xA415u;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x040520ABu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF06Bu: {
            const uint32_t source_key = 0x040CF06Bu;
            cpu->pc = 0x9E11u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0xA1F2u;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x04050F93u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF08Bu: {
            const uint32_t source_key = 0x040CF08Bu;
            cpu->pc = 0x9E12u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040D2AEBu, 0x040D627Bu, 0x040D6843u, 0x040D7ABBu, 0x040DD27Bu, 0x040FA303u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF090u: {
            const uint32_t source_key = 0x040CF090u;
            cpu->pc = 0x9E13u;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CF098u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF098u: {
            const uint32_t source_key = 0x040CF098u;
            cpu->pc = 0x9E14u;
            js_op_transfer(cpu, 'A');
            static const uint32_t allowed[] = { 0x040CF0A0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF0A0u: {
            const uint32_t source_key = 0x040CF0A0u;
            cpu->pc = 0x9E17u;
            uint32_t ea = js_addr_abs_x(cpu, 0xA154u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CF0B8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF0B8u: {
            const uint32_t source_key = 0x040CF0B8u;
            cpu->pc = 0x9E19u;
            uint32_t ea = js_addr_dp(cpu, 0x58u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CF0C8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF0C8u: {
            const uint32_t source_key = 0x040CF0C8u;
            cpu->pc = 0x9E1Cu;
            uint16_t value = 0x0000u;
            js_op_load_y(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CF0E0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF0E0u: {
            const uint32_t source_key = 0x040CF0E0u;
            cpu->pc = 0x9E1Eu;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_y(cpu, bus, 0x58u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CF0F0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF0F0u: {
            const uint32_t source_key = 0x040CF0F0u;
            cpu->pc = 0x9E20u;
            uint32_t ea = js_addr_dp(cpu, 0x58u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CF100u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF100u: {
            const uint32_t source_key = 0x040CF100u;
            cpu->pc = 0x9E23u;
            uint16_t value = 0x00FFu;
            js_op_and(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CF118u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF118u: {
            const uint32_t source_key = 0x040CF118u;
            cpu->pc = 0x9E24u;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CF120u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF120u: {
            const uint32_t source_key = 0x040CF120u;
            cpu->pc = 0x9E25u;
            js_op_transfer(cpu, 'A');
            static const uint32_t allowed[] = { 0x040CF128u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF128u: {
            const uint32_t source_key = 0x040CF128u;
            cpu->pc = 0x9E27u;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_y(cpu, bus, 0x58u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CF138u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF138u: {
            const uint32_t source_key = 0x040CF138u;
            cpu->pc = 0x9E2Au;
            uint32_t ea = js_addr_abs_y(cpu, 0x13FAu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CF150u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF150u: {
            const uint32_t source_key = 0x040CF150u;
            cpu->pc = 0x9E2Bu;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CF158u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF158u: {
            const uint32_t source_key = 0x040CF158u;
            cpu->pc = 0x9E2Cu;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CF160u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF160u: {
            const uint32_t source_key = 0x040CF160u;
            cpu->pc = 0x9E2Du;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, -1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CF168u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF168u: {
            const uint32_t source_key = 0x040CF168u;
            cpu->pc = 0x9E2Fu;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-10));
            static const uint32_t allowed[] = { 0x040CF128u, 0x040CF178u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF178u: {
            const uint32_t source_key = 0x040CF178u;
            cpu->pc = 0x9E30u;
            js_op_transfer(cpu, 'H');
            static const uint32_t allowed[] = { 0x040CF180u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF180u: {
            const uint32_t source_key = 0x040CF180u;
            cpu->pc = 0x9E31u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_C);
            static const uint32_t allowed[] = { 0x040CF188u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF188u: {
            const uint32_t source_key = 0x040CF188u;
            cpu->pc = 0x9E33u;
            uint32_t ea = js_addr_dp(cpu, 0x58u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_adc(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CF198u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF198u: {
            const uint32_t source_key = 0x040CF198u;
            cpu->pc = 0x9E35u;
            uint32_t ea = js_addr_dp(cpu, 0x58u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CF1A8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF1A8u: {
            const uint32_t source_key = 0x040CF1A8u;
            cpu->pc = 0x9E38u;
            uint16_t value = 0x0000u;
            js_op_load_y(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CF1C0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF1C0u: {
            const uint32_t source_key = 0x040CF1C0u;
            cpu->pc = 0x9E3Au;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_y(cpu, bus, 0x58u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CF1D0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF1D0u: {
            const uint32_t source_key = 0x040CF1D0u;
            cpu->pc = 0x9E3Cu;
            uint32_t ea = js_addr_dp(cpu, 0x58u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CF1E0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF1E0u: {
            const uint32_t source_key = 0x040CF1E0u;
            cpu->pc = 0x9E3Fu;
            uint16_t value = 0x00FFu;
            js_op_and(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CF1F8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF1F8u: {
            const uint32_t source_key = 0x040CF1F8u;
            cpu->pc = 0x9E41u;
            uint32_t ea = js_addr_dp(cpu, 0x88u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CF208u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF208u: {
            const uint32_t source_key = 0x040CF208u;
            cpu->pc = 0x9E43u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040CF21Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF21Bu: {
            const uint32_t source_key = 0x040CF21Bu;
            cpu->pc = 0x9E45u;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_y(cpu, bus, 0x58u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040CF22Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF22Bu: {
            const uint32_t source_key = 0x040CF22Bu;
            cpu->pc = 0x9E48u;
            uint32_t ea = js_addr_abs_y(cpu, 0x14FAu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CF243u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF243u: {
            const uint32_t source_key = 0x040CF243u;
            cpu->pc = 0x9E49u;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 8u), 8u);
            static const uint32_t allowed[] = { 0x040CF24Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF24Bu: {
            const uint32_t source_key = 0x040CF24Bu;
            cpu->pc = 0x9E4Bu;
            uint32_t ea = js_addr_dp(cpu, 0x88u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_compare(cpu, cpu->y, value, 8u);
            static const uint32_t allowed[] = { 0x040CF25Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF25Bu: {
            const uint32_t source_key = 0x040CF25Bu;
            cpu->pc = 0x9E4Du;
            if (js_branch_condition(cpu, 'C')) cpu->pc = (uint16_t)(cpu->pc + (-10));
            static const uint32_t allowed[] = { 0x040CF21Bu, 0x040CF26Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF26Bu: {
            const uint32_t source_key = 0x040CF26Bu;
            cpu->pc = 0x9E4Fu;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040CF278u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF278u: {
            const uint32_t source_key = 0x040CF278u;
            cpu->pc = 0x9E50u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FA508u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF280u: {
            const uint32_t source_key = 0x040CF280u;
            cpu->pc = 0x9E51u;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CF288u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF288u: {
            const uint32_t source_key = 0x040CF288u;
            cpu->pc = 0x9E52u;
            js_op_transfer(cpu, 'A');
            static const uint32_t allowed[] = { 0x040CF290u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF290u: {
            const uint32_t source_key = 0x040CF290u;
            cpu->pc = 0x9E55u;
            uint32_t ea = js_addr_abs_x(cpu, 0xA13Eu);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CF2A8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF2A8u: {
            const uint32_t source_key = 0x040CF2A8u;
            cpu->pc = 0x9E57u;
            uint32_t ea = js_addr_dp(cpu, 0x58u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CF2B8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF2B8u: {
            const uint32_t source_key = 0x040CF2B8u;
            cpu->pc = 0x9E5Au;
            uint16_t value = 0x0000u;
            js_op_load_y(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CF2D0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF2D0u: {
            const uint32_t source_key = 0x040CF2D0u;
            cpu->pc = 0x9E5Cu;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_y(cpu, bus, 0x58u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CF2E0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF2E0u: {
            const uint32_t source_key = 0x040CF2E0u;
            cpu->pc = 0x9E5Du;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CF2E8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF2E8u: {
            const uint32_t source_key = 0x040CF2E8u;
            cpu->pc = 0x9E5Eu;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CF2F0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF2F0u: {
            const uint32_t source_key = 0x040CF2F0u;
            cpu->pc = 0x9E61u;
            uint16_t value = 0x0001u;
            js_op_compare(cpu, cpu->a, value, 16u);
            static const uint32_t allowed[] = { 0x040CF308u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF308u: {
            const uint32_t source_key = 0x040CF308u;
            cpu->pc = 0x9E63u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (24));
            static const uint32_t allowed[] = { 0x040CF318u, 0x040CF3D8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF318u: {
            const uint32_t source_key = 0x040CF318u;
            cpu->pc = 0x9E66u;
            uint16_t value = 0x0000u;
            js_op_compare(cpu, cpu->a, value, 16u);
            static const uint32_t allowed[] = { 0x040CF330u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF330u: {
            const uint32_t source_key = 0x040CF330u;
            cpu->pc = 0x9E68u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (26));
            static const uint32_t allowed[] = { 0x040CF340u, 0x040CF410u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF340u: {
            const uint32_t source_key = 0x040CF340u;
            cpu->pc = 0x9E6Bu;
            uint16_t value = 0x0003u;
            js_op_compare(cpu, cpu->a, value, 16u);
            static const uint32_t allowed[] = { 0x040CF358u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF358u: {
            const uint32_t source_key = 0x040CF358u;
            cpu->pc = 0x9E6Du;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (52));
            static const uint32_t allowed[] = { 0x040CF368u, 0x040CF508u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF368u: {
            const uint32_t source_key = 0x040CF368u;
            cpu->pc = 0x9E70u;
            uint16_t value = 0x0004u;
            js_op_compare(cpu, cpu->a, value, 16u);
            static const uint32_t allowed[] = { 0x040CF380u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF380u: {
            const uint32_t source_key = 0x040CF380u;
            cpu->pc = 0x9E72u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (29));
            static const uint32_t allowed[] = { 0x040CF390u, 0x040CF478u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF390u: {
            const uint32_t source_key = 0x040CF390u;
            cpu->pc = 0x9E74u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040CF3A3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF3A3u: {
            const uint32_t source_key = 0x040CF3A3u;
            cpu->pc = 0x9E78u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0xC066u;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x04060333u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF3C3u: {
            const uint32_t source_key = 0x040CF3C3u;
            cpu->pc = 0x9E7Au;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040CF3D0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF3D0u: {
            const uint32_t source_key = 0x040CF3D0u;
            cpu->pc = 0x9E7Bu;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FA4D8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_RETURN);
        }
        case 0x040CF3D8u: {
            const uint32_t source_key = 0x040CF3D8u;
            cpu->pc = 0x9E7Cu;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CF3E0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF3E0u: {
            const uint32_t source_key = 0x040CF3E0u;
            cpu->pc = 0x9E7Du;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CF3E8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF3E8u: {
            const uint32_t source_key = 0x040CF3E8u;
            cpu->pc = 0x9E7Eu;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CF3F0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF3F0u: {
            const uint32_t source_key = 0x040CF3F0u;
            cpu->pc = 0x9E7Fu;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CF3F8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF3F8u: {
            const uint32_t source_key = 0x040CF3F8u;
            cpu->pc = 0x9E82u;
            cpu->pc = (uint16_t)(cpu->pc + (-40));
            static const uint32_t allowed[] = { 0x040CF2D0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF410u: {
            const uint32_t source_key = 0x040CF410u;
            cpu->pc = 0x9E84u;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_y(cpu, bus, 0x58u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CF420u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF420u: {
            const uint32_t source_key = 0x040CF420u;
            cpu->pc = 0x9E85u;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CF428u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF428u: {
            const uint32_t source_key = 0x040CF428u;
            cpu->pc = 0x9E86u;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CF430u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF430u: {
            const uint32_t source_key = 0x040CF430u;
            cpu->pc = 0x9E87u;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->y, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CF438u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF438u: {
            const uint32_t source_key = 0x040CF438u;
            cpu->pc = 0x9E8Bu;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0x839Bu;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x04041CD8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF458u: {
            const uint32_t source_key = 0x040CF458u;
            cpu->pc = 0x9E8Cu;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_y(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x040CF460u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF460u: {
            const uint32_t source_key = 0x040CF460u;
            cpu->pc = 0x9E8Fu;
            cpu->pc = (uint16_t)(cpu->pc + (-53));
            static const uint32_t allowed[] = { 0x040CF2D0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF478u: {
            const uint32_t source_key = 0x040CF478u;
            cpu->pc = 0x9E91u;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_y(cpu, bus, 0x58u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CF488u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF488u: {
            const uint32_t source_key = 0x040CF488u;
            cpu->pc = 0x9E92u;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CF490u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF490u: {
            const uint32_t source_key = 0x040CF490u;
            cpu->pc = 0x9E93u;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CF498u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF498u: {
            const uint32_t source_key = 0x040CF498u;
            cpu->pc = 0x9E94u;
            js_op_transfer(cpu, 'A');
            static const uint32_t allowed[] = { 0x040CF4A0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF4A0u: {
            const uint32_t source_key = 0x040CF4A0u;
            cpu->pc = 0x9E96u;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_y(cpu, bus, 0x58u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CF4B0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF4B0u: {
            const uint32_t source_key = 0x040CF4B0u;
            cpu->pc = 0x9E97u;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CF4B8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF4B8u: {
            const uint32_t source_key = 0x040CF4B8u;
            cpu->pc = 0x9E98u;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CF4C0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF4C0u: {
            const uint32_t source_key = 0x040CF4C0u;
            cpu->pc = 0x9E99u;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->y, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CF4C8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF4C8u: {
            const uint32_t source_key = 0x040CF4C8u;
            cpu->pc = 0x9E9Du;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0x82F7u;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x040417B8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF4E8u: {
            const uint32_t source_key = 0x040CF4E8u;
            cpu->pc = 0x9E9Eu;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_y(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x040CF4F0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF4F0u: {
            const uint32_t source_key = 0x040CF4F0u;
            cpu->pc = 0x9EA1u;
            cpu->pc = (uint16_t)(cpu->pc + (-71));
            static const uint32_t allowed[] = { 0x040CF2D0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF508u: {
            const uint32_t source_key = 0x040CF508u;
            cpu->pc = 0x9EA3u;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_y(cpu, bus, 0x58u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CF518u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF518u: {
            const uint32_t source_key = 0x040CF518u;
            cpu->pc = 0x9EA4u;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CF520u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF520u: {
            const uint32_t source_key = 0x040CF520u;
            cpu->pc = 0x9EA5u;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CF528u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF528u: {
            const uint32_t source_key = 0x040CF528u;
            cpu->pc = 0x9EA6u;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->a, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CF530u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF530u: {
            const uint32_t source_key = 0x040CF530u;
            cpu->pc = 0x9EA8u;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_y(cpu, bus, 0x58u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CF540u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF540u: {
            const uint32_t source_key = 0x040CF540u;
            cpu->pc = 0x9EA9u;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CF548u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF548u: {
            const uint32_t source_key = 0x040CF548u;
            cpu->pc = 0x9EAAu;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CF550u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF550u: {
            const uint32_t source_key = 0x040CF550u;
            cpu->pc = 0x9EABu;
            js_op_transfer(cpu, 'A');
            static const uint32_t allowed[] = { 0x040CF558u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF558u: {
            const uint32_t source_key = 0x040CF558u;
            cpu->pc = 0x9EADu;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_y(cpu, bus, 0x58u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CF568u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF568u: {
            const uint32_t source_key = 0x040CF568u;
            cpu->pc = 0x9EAEu;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CF570u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF570u: {
            const uint32_t source_key = 0x040CF570u;
            cpu->pc = 0x9EAFu;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040CF578u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF578u: {
            const uint32_t source_key = 0x040CF578u;
            cpu->pc = 0x9EB2u;
            uint16_t value = 0x0010u;
            js_op_compare(cpu, cpu->a, value, 16u);
            static const uint32_t allowed[] = { 0x040CF590u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF590u: {
            const uint32_t source_key = 0x040CF590u;
            cpu->pc = 0x9EB4u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (15));
            static const uint32_t allowed[] = { 0x040CF5A0u, 0x040CF618u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF5A0u: {
            const uint32_t source_key = 0x040CF5A0u;
            cpu->pc = 0x9EB7u;
            uint16_t value = 0x0020u;
            js_op_compare(cpu, cpu->a, value, 16u);
            static const uint32_t allowed[] = { 0x040CF5B8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF5B8u: {
            const uint32_t source_key = 0x040CF5B8u;
            cpu->pc = 0x9EB9u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (20));
            static const uint32_t allowed[] = { 0x040CF5C8u, 0x040CF668u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF5C8u: {
            const uint32_t source_key = 0x040CF5C8u;
            cpu->pc = 0x9EBAu;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x040CF5D0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF5D0u: {
            const uint32_t source_key = 0x040CF5D0u;
            cpu->pc = 0x9EBBu;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->y, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CF5D8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF5D8u: {
            const uint32_t source_key = 0x040CF5D8u;
            cpu->pc = 0x9EBFu;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0xA21Au;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x040510D0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF5F8u: {
            const uint32_t source_key = 0x040CF5F8u;
            cpu->pc = 0x9EC0u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_y(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x040CF600u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF600u: {
            const uint32_t source_key = 0x040CF600u;
            cpu->pc = 0x9EC3u;
            cpu->pc = (uint16_t)(cpu->pc + (-105));
            static const uint32_t allowed[] = { 0x040CF2D0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF618u: {
            const uint32_t source_key = 0x040CF618u;
            cpu->pc = 0x9EC4u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x040CF620u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF620u: {
            const uint32_t source_key = 0x040CF620u;
            cpu->pc = 0x9EC5u;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->y, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CF628u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF628u: {
            const uint32_t source_key = 0x040CF628u;
            cpu->pc = 0x9EC9u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0xA338u;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x040519C0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF648u: {
            const uint32_t source_key = 0x040CF648u;
            cpu->pc = 0x9ECAu;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_y(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x040CF650u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF650u: {
            const uint32_t source_key = 0x040CF650u;
            cpu->pc = 0x9ECDu;
            cpu->pc = (uint16_t)(cpu->pc + (-115));
            static const uint32_t allowed[] = { 0x040CF2D0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF668u: {
            const uint32_t source_key = 0x040CF668u;
            cpu->pc = 0x9ECEu;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x040CF670u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF670u: {
            const uint32_t source_key = 0x040CF670u;
            cpu->pc = 0x9ECFu;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->y, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CF678u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF678u: {
            const uint32_t source_key = 0x040CF678u;
            cpu->pc = 0x9ED3u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0xA2DBu;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x040516D8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF698u: {
            const uint32_t source_key = 0x040CF698u;
            cpu->pc = 0x9ED4u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_y(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x040CF6A0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CF6A0u: {
            const uint32_t source_key = 0x040CF6A0u;
            cpu->pc = 0x9ED7u;
            cpu->pc = (uint16_t)(cpu->pc + (-125));
            static const uint32_t allowed[] = { 0x040CF2D0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFAE3u: {
            const uint32_t source_key = 0x040CFAE3u;
            cpu->pc = 0x9F5Eu;
            js_op_rep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x040CFAF1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFAF1u: {
            const uint32_t source_key = 0x040CFAF1u;
            cpu->pc = 0x9F61u;
            uint32_t ea = js_addr_abs(cpu, 0x033Du);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CFB09u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFB09u: {
            const uint32_t source_key = 0x040CFB09u;
            cpu->pc = 0x9F64u;
            uint32_t ea = js_addr_abs(cpu, 0x0345u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFB21u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFB21u: {
            const uint32_t source_key = 0x040CFB21u;
            cpu->pc = 0x9F67u;
            uint32_t ea = js_addr_abs(cpu, 0x033Fu);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040CFB39u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFB39u: {
            const uint32_t source_key = 0x040CFB39u;
            cpu->pc = 0x9F6Au;
            uint32_t ea = js_addr_abs(cpu, 0x0347u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFB51u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFB51u: {
            const uint32_t source_key = 0x040CFB51u;
            cpu->pc = 0x9F6Du;
            uint32_t ea = js_addr_abs(cpu, 0x034Du);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFB69u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFB69u: {
            const uint32_t source_key = 0x040CFB69u;
            cpu->pc = 0x9F70u;
            uint32_t ea = js_addr_abs(cpu, 0x034Fu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFB81u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFB81u: {
            const uint32_t source_key = 0x040CFB81u;
            cpu->pc = 0x9F72u;
            js_op_sep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x040CFB93u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFB93u: {
            const uint32_t source_key = 0x040CFB93u;
            cpu->pc = 0x9F75u;
            uint32_t ea = js_addr_abs(cpu, 0x028Eu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFBABu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFBABu: {
            const uint32_t source_key = 0x040CFBABu;
            cpu->pc = 0x9F78u;
            uint32_t ea = js_addr_abs(cpu, 0x028Fu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFBC3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFBC3u: {
            const uint32_t source_key = 0x040CFBC3u;
            cpu->pc = 0x9F7Bu;
            uint32_t ea = js_addr_abs(cpu, 0x028Du);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFBDBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFBDBu: {
            const uint32_t source_key = 0x040CFBDBu;
            cpu->pc = 0x9F7Eu;
            uint32_t ea = js_addr_abs(cpu, 0x028Cu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFBF3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFBF3u: {
            const uint32_t source_key = 0x040CFBF3u;
            cpu->pc = 0x9F81u;
            uint32_t ea = js_addr_abs(cpu, 0x028Bu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFC0Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFC0Bu: {
            const uint32_t source_key = 0x040CFC0Bu;
            cpu->pc = 0x9F84u;
            uint32_t ea = js_addr_abs(cpu, 0x028Au);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFC23u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFC23u: {
            const uint32_t source_key = 0x040CFC23u;
            cpu->pc = 0x9F87u;
            uint32_t ea = js_addr_abs(cpu, 0x0290u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFC3Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFC3Bu: {
            const uint32_t source_key = 0x040CFC3Bu;
            cpu->pc = 0x9F8Au;
            uint32_t ea = js_addr_abs(cpu, 0x0291u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFC53u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFC53u: {
            const uint32_t source_key = 0x040CFC53u;
            cpu->pc = 0x9F8Du;
            uint32_t ea = js_addr_abs(cpu, 0x0293u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFC6Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFC6Bu: {
            const uint32_t source_key = 0x040CFC6Bu;
            cpu->pc = 0x9F90u;
            uint32_t ea = js_addr_abs(cpu, 0x0292u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFC83u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFC83u: {
            const uint32_t source_key = 0x040CFC83u;
            cpu->pc = 0x9F93u;
            uint32_t ea = js_addr_abs(cpu, 0x0296u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFC9Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFC9Bu: {
            const uint32_t source_key = 0x040CFC9Bu;
            cpu->pc = 0x9F96u;
            uint32_t ea = js_addr_abs(cpu, 0x0294u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFCB3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFCB3u: {
            const uint32_t source_key = 0x040CFCB3u;
            cpu->pc = 0x9F99u;
            uint32_t ea = js_addr_abs(cpu, 0x0295u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFCCBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFCCBu: {
            const uint32_t source_key = 0x040CFCCBu;
            cpu->pc = 0x9F9Cu;
            uint32_t ea = js_addr_abs(cpu, 0x0289u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFCE3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFCE3u: {
            const uint32_t source_key = 0x040CFCE3u;
            cpu->pc = 0x9F9Du;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040CF04Bu, 0x040FA62Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFCEBu: {
            const uint32_t source_key = 0x040CFCEBu;
            cpu->pc = 0x9FA0u;
            uint32_t ea = js_addr_abs(cpu, 0x0296u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040CFD03u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFD03u: {
            const uint32_t source_key = 0x040CFD03u;
            cpu->pc = 0x9FA2u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (11));
            static const uint32_t allowed[] = { 0x040CFD13u, 0x040CFD6Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFD13u: {
            const uint32_t source_key = 0x040CFD13u;
            cpu->pc = 0x9FA6u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0xFB52u;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x0407DA93u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFD33u: {
            const uint32_t source_key = 0x040CFD33u;
            cpu->pc = 0x9FAAu;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0xF982u;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x0407CC13u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFD53u: {
            const uint32_t source_key = 0x040CFD53u;
            cpu->pc = 0x9FADu;
            uint32_t ea = js_addr_abs(cpu, 0x0296u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFD6Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFD6Bu: {
            const uint32_t source_key = 0x040CFD6Bu;
            cpu->pc = 0x9FAEu;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FBB63u, 0x040FBEB3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFD73u: {
            const uint32_t source_key = 0x040CFD73u;
            cpu->pc = 0x9FB1u;
            uint32_t ea = js_addr_abs(cpu, 0x13B8u);
            uint16_t original = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
            uint16_t result = js_op_incdec(cpu, original, 1, 8u);
            if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFD8Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFD8Bu: {
            const uint32_t source_key = 0x040CFD8Bu;
            cpu->pc = 0x9FB4u;
            uint32_t ea = js_addr_abs(cpu, 0x13B8u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_compare(cpu, cpu->x, value, 8u);
            static const uint32_t allowed[] = { 0x040CFDA3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFDA3u: {
            const uint32_t source_key = 0x040CFDA3u;
            cpu->pc = 0x9FB6u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (3));
            static const uint32_t allowed[] = { 0x040CFDB3u, 0x040CFDCBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFDB3u: {
            const uint32_t source_key = 0x040CFDB3u;
            cpu->pc = 0x9FB9u;
            uint32_t ea = js_addr_abs(cpu, 0x13B8u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFDCBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFDCBu: {
            const uint32_t source_key = 0x040CFDCBu;
            cpu->pc = 0x9FBCu;
            uint32_t ea = js_addr_abs(cpu, 0x028Du);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFDE3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFDE3u: {
            const uint32_t source_key = 0x040CFDE3u;
            cpu->pc = 0x9FBFu;
            uint32_t ea = js_addr_abs(cpu, 0x028Fu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFDFBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFDFBu: {
            const uint32_t source_key = 0x040CFDFBu;
            cpu->pc = 0x9FC2u;
            uint32_t ea = js_addr_abs(cpu, 0x0296u);
            uint16_t original = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
            uint16_t result = js_op_incdec(cpu, original, 1, 8u);
            if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFE13u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFE13u: {
            const uint32_t source_key = 0x040CFE13u;
            cpu->pc = 0x9FC5u;
            uint32_t ea = js_addr_abs(cpu, 0x13B6u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFE2Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFE2Bu: {
            const uint32_t source_key = 0x040CFE2Bu;
            cpu->pc = 0x9FC6u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FBA33u, 0x040FBD83u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFE33u: {
            const uint32_t source_key = 0x040CFE33u;
            cpu->pc = 0x9FC9u;
            uint32_t ea = js_addr_abs(cpu, 0x13B8u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040CFE4Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFE4Bu: {
            const uint32_t source_key = 0x040CFE4Bu;
            cpu->pc = 0x9FCAu;
            js_op_load_a(cpu, js_op_incdec(cpu, cpu->a, -1, 8u), 8u);
            static const uint32_t allowed[] = { 0x040CFE53u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFE53u: {
            const uint32_t source_key = 0x040CFE53u;
            cpu->pc = 0x9FCCu;
            if (js_branch_condition(cpu, 'P')) cpu->pc = (uint16_t)(cpu->pc + (1));
            static const uint32_t allowed[] = { 0x040CFE63u, 0x040CFE6Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFE63u: {
            const uint32_t source_key = 0x040CFE63u;
            cpu->pc = 0x9FCDu;
            js_op_transfer(cpu, 'F');
            static const uint32_t allowed[] = { 0x040CFE6Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFE6Bu: {
            const uint32_t source_key = 0x040CFE6Bu;
            cpu->pc = 0x9FD0u;
            uint32_t ea = js_addr_abs(cpu, 0x13B8u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFE83u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFE83u: {
            const uint32_t source_key = 0x040CFE83u;
            cpu->pc = 0x9FD3u;
            uint32_t ea = js_addr_abs(cpu, 0x028Cu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFE9Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFE9Bu: {
            const uint32_t source_key = 0x040CFE9Bu;
            cpu->pc = 0x9FD6u;
            uint32_t ea = js_addr_abs(cpu, 0x028Eu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFEB3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFEB3u: {
            const uint32_t source_key = 0x040CFEB3u;
            cpu->pc = 0x9FD9u;
            uint32_t ea = js_addr_abs(cpu, 0x0296u);
            uint16_t original = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
            uint16_t result = js_op_incdec(cpu, original, 1, 8u);
            if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFECBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFECBu: {
            const uint32_t source_key = 0x040CFECBu;
            cpu->pc = 0x9FDCu;
            uint32_t ea = js_addr_abs(cpu, 0x13B6u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040CFEE3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFEE3u: {
            const uint32_t source_key = 0x040CFEE3u;
            cpu->pc = 0x9FDDu;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FBA0Bu, 0x040FBD5Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFF33u: {
            const uint32_t source_key = 0x040CFF33u;
            cpu->pc = 0x9FE9u;
            uint32_t ea = js_addr_abs(cpu, 0x028Fu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040CFF4Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFF4Bu: {
            const uint32_t source_key = 0x040CFF4Bu;
            cpu->pc = 0x9FEBu;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (3));
            static const uint32_t allowed[] = { 0x040CFF5Bu, 0x040CFF73u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFF5Bu: {
            const uint32_t source_key = 0x040CFF5Bu;
            cpu->pc = 0x9FEEu;
            cpu->pc = 0x9FAEu;
            static const uint32_t allowed[] = { 0x040CFD73u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFF73u: {
            const uint32_t source_key = 0x040CFF73u;
            cpu->pc = 0x9FEFu;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FBA33u, 0x040FBD83u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFFC3u: {
            const uint32_t source_key = 0x040CFFC3u;
            cpu->pc = 0x9FFBu;
            uint32_t ea = js_addr_abs(cpu, 0x028Eu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040CFFDBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFFDBu: {
            const uint32_t source_key = 0x040CFFDBu;
            cpu->pc = 0x9FFDu;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (3));
            static const uint32_t allowed[] = { 0x040CFFEBu, 0x040D0003u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040CFFEBu: {
            const uint32_t source_key = 0x040CFFEBu;
            cpu->pc = 0xA000u;
            cpu->pc = 0x9FC6u;
            static const uint32_t allowed[] = { 0x040CFE33u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        default: return JS_EXEC_NOT_MINE;
    }
}
