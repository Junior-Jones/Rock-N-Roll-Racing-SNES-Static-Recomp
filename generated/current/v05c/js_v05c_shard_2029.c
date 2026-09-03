#include "v05c_static_cpu.h"

JSExecResult js_v05c_shard_2029(JSCPU *cpu, const JSBus *bus, JSStop *stop) {
    (void)bus;
    (void)stop;
    switch (js_cpu_context_key(cpu)) {
        case 0x04052003u: {
            const uint32_t source_key = 0x04052003u;
            cpu->pc = 0xA402u;
            uint16_t value = 0x0020u;
            js_op_load_y(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04052013u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04052013u: {
            const uint32_t source_key = 0x04052013u;
            cpu->pc = 0xA404u;
            uint16_t value = 0x0000u;
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04052023u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04052023u: {
            const uint32_t source_key = 0x04052023u;
            cpu->pc = 0xA405u;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, -1, 8u), 8u);
            static const uint32_t allowed[] = { 0x0405202Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0405202Bu: {
            const uint32_t source_key = 0x0405202Bu;
            cpu->pc = 0xA407u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-3));
            static const uint32_t allowed[] = { 0x04052023u, 0x0405203Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0405203Bu: {
            const uint32_t source_key = 0x0405203Bu;
            cpu->pc = 0xA408u;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, -1, 8u), 8u);
            static const uint32_t allowed[] = { 0x04052043u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04052043u: {
            const uint32_t source_key = 0x04052043u;
            cpu->pc = 0xA40Au;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-6));
            static const uint32_t allowed[] = { 0x04052023u, 0x04052053u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04052053u: {
            const uint32_t source_key = 0x04052053u;
            cpu->pc = 0xA40Du;
            uint32_t ea = js_addr_abs(cpu, 0x035Fu);
            uint16_t original = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
            uint16_t result = js_op_incdec(cpu, original, -1, 8u);
            if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0405206Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0405206Bu: {
            const uint32_t source_key = 0x0405206Bu;
            cpu->pc = 0xA40Fu;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-24));
            static const uint32_t allowed[] = { 0x04051FBBu, 0x0405207Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0405207Bu: {
            const uint32_t source_key = 0x0405207Bu;
            cpu->pc = 0xA411u;
            uint16_t value = 0x008Fu;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0405208Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0405208Bu: {
            const uint32_t source_key = 0x0405208Bu;
            cpu->pc = 0xA414u;
            uint32_t ea = js_addr_abs(cpu, 0x2100u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040520A3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040520A3u: {
            const uint32_t source_key = 0x040520A3u;
            cpu->pc = 0xA415u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x04051F83u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040520ABu: {
            const uint32_t source_key = 0x040520ABu;
            cpu->pc = 0xA416u;
            if (!js_stack_push8(cpu, bus, cpu->dbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040520B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040520B3u: {
            const uint32_t source_key = 0x040520B3u;
            cpu->pc = 0xA417u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040520BBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040520BBu: {
            const uint32_t source_key = 0x040520BBu;
            cpu->pc = 0xA418u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x040520C3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040520C3u: {
            const uint32_t source_key = 0x040520C3u;
            cpu->pc = 0xA41Bu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xA41Du;
            static const uint32_t allowed[] = { 0x040520EBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040520DBu: {
            const uint32_t source_key = 0x040520DBu;
            cpu->pc = 0xA41Cu;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x040520E3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040520E3u: {
            const uint32_t source_key = 0x040520E3u;
            cpu->pc = 0xA41Du;
            { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x040CF06Bu, 0x040FA2C3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040520EBu: {
            const uint32_t source_key = 0x040520EBu;
            cpu->pc = 0xA41Fu;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040520F8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040520F8u: {
            const uint32_t source_key = 0x040520F8u;
            cpu->pc = 0xA422u;
            uint32_t ea = js_addr_abs(cpu, 0x2102u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04052110u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04052110u: {
            const uint32_t source_key = 0x04052110u;
            cpu->pc = 0xA424u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x04052123u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04052123u: {
            const uint32_t source_key = 0x04052123u;
            cpu->pc = 0xA426u;
            uint16_t value = 0x0080u;
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04052133u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04052133u: {
            const uint32_t source_key = 0x04052133u;
            cpu->pc = 0xA428u;
            uint16_t value = 0x000Au;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04052143u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04052143u: {
            const uint32_t source_key = 0x04052143u;
            cpu->pc = 0xA42Bu;
            uint32_t ea = js_addr_abs(cpu, 0x2104u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0405215Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0405215Bu: {
            const uint32_t source_key = 0x0405215Bu;
            cpu->pc = 0xA42Du;
            uint16_t value = 0x00F0u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0405216Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0405216Bu: {
            const uint32_t source_key = 0x0405216Bu;
            cpu->pc = 0xA430u;
            uint32_t ea = js_addr_abs(cpu, 0x2104u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04052183u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04052183u: {
            const uint32_t source_key = 0x04052183u;
            cpu->pc = 0xA433u;
            uint32_t ea = js_addr_abs(cpu, 0x2104u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0405219Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0405219Bu: {
            const uint32_t source_key = 0x0405219Bu;
            cpu->pc = 0xA436u;
            uint32_t ea = js_addr_abs(cpu, 0x2104u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040521B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040521B3u: {
            const uint32_t source_key = 0x040521B3u;
            cpu->pc = 0xA437u;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, -1, 8u), 8u);
            static const uint32_t allowed[] = { 0x040521BBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040521BBu: {
            const uint32_t source_key = 0x040521BBu;
            cpu->pc = 0xA439u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-19));
            static const uint32_t allowed[] = { 0x04052133u, 0x040521CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040521CBu: {
            const uint32_t source_key = 0x040521CBu;
            cpu->pc = 0xA43Bu;
            uint16_t value = 0x0020u;
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040521DBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040521DBu: {
            const uint32_t source_key = 0x040521DBu;
            cpu->pc = 0xA43Du;
            uint16_t value = 0x0055u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040521EBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040521EBu: {
            const uint32_t source_key = 0x040521EBu;
            cpu->pc = 0xA440u;
            uint32_t ea = js_addr_abs(cpu, 0x2104u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04052203u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04052203u: {
            const uint32_t source_key = 0x04052203u;
            cpu->pc = 0xA441u;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, -1, 8u), 8u);
            static const uint32_t allowed[] = { 0x0405220Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0405220Bu: {
            const uint32_t source_key = 0x0405220Bu;
            cpu->pc = 0xA443u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-6));
            static const uint32_t allowed[] = { 0x040521EBu, 0x0405221Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0405221Bu: {
            const uint32_t source_key = 0x0405221Bu;
            cpu->pc = 0xA444u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040520DBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04052223u: {
            const uint32_t source_key = 0x04052223u;
            cpu->pc = 0xA447u;
            uint32_t ea = js_addr_abs(cpu, 0x4212u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0405223Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0405223Bu: {
            const uint32_t source_key = 0x0405223Bu;
            cpu->pc = 0xA449u;
            uint16_t value = 0x0080u;
            js_op_and(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0405224Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0405224Bu: {
            const uint32_t source_key = 0x0405224Bu;
            cpu->pc = 0xA44Bu;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (-7));
            static const uint32_t allowed[] = { 0x04052223u, 0x0405225Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0405225Bu: {
            const uint32_t source_key = 0x0405225Bu;
            cpu->pc = 0xA44Cu;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x04051D73u, 0x04051FD3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        default: return JS_EXEC_NOT_MINE;
    }
}
