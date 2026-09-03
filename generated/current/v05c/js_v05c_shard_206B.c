#include "v05c_static_cpu.h"

JSExecResult js_v05c_shard_206B(JSCPU *cpu, const JSBus *bus, JSStop *stop) {
    (void)bus;
    (void)stop;
    switch (js_cpu_context_key(cpu)) {
        case 0x040D6203u: {
            const uint32_t source_key = 0x040D6203u;
            cpu->pc = 0xAC41u;
            if (!js_stack_push8(cpu, bus, cpu->dbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D620Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D620Bu: {
            const uint32_t source_key = 0x040D620Bu;
            cpu->pc = 0xAC42u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D6213u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6213u: {
            const uint32_t source_key = 0x040D6213u;
            cpu->pc = 0xAC43u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x040D621Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D621Bu: {
            const uint32_t source_key = 0x040D621Bu;
            cpu->pc = 0xAC46u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xAC48u;
            static const uint32_t allowed[] = { 0x040D6243u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6243u: {
            const uint32_t source_key = 0x040D6243u;
            cpu->pc = 0xAC49u;
            if (!js_stack_push8(cpu, bus, (uint8_t)cpu->x, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D624Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D624Bu: {
            const uint32_t source_key = 0x040D624Bu;
            cpu->pc = 0xAC4Cu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9D40u;
            static const uint32_t allowed[] = { 0x040CEA03u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6263u: {
            const uint32_t source_key = 0x040D6263u;
            cpu->pc = 0xAC4Fu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9DB1u;
            static const uint32_t allowed[] = { 0x040CED8Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D627Bu: {
            const uint32_t source_key = 0x040D627Bu;
            cpu->pc = 0xAC50u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_x(cpu, v, 8u); }
            static const uint32_t allowed[] = { 0x040D6283u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6283u: {
            const uint32_t source_key = 0x040D6283u;
            cpu->pc = 0xAC52u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (6));
            static const uint32_t allowed[] = { 0x040D6293u, 0x040D62C3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6293u: {
            const uint32_t source_key = 0x040D6293u;
            cpu->pc = 0xAC53u;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, -1, 8u), 8u);
            static const uint32_t allowed[] = { 0x040D629Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D629Bu: {
            const uint32_t source_key = 0x040D629Bu;
            cpu->pc = 0xAC55u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (54));
            static const uint32_t allowed[] = { 0x040D62ABu, 0x040D645Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D62ABu: {
            const uint32_t source_key = 0x040D62ABu;
            cpu->pc = 0xAC58u;
            cpu->pc = (uint16_t)(cpu->pc + (140));
            static const uint32_t allowed[] = { 0x040D6723u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D62C3u: {
            const uint32_t source_key = 0x040D62C3u;
            cpu->pc = 0xAC5Au;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040D62D0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D62D0u: {
            const uint32_t source_key = 0x040D62D0u;
            cpu->pc = 0xAC5Du;
            uint32_t ea = js_addr_abs(cpu, 0x0280u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D62E8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D62E8u: {
            const uint32_t source_key = 0x040D62E8u;
            cpu->pc = 0xAC5Fu;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (12));
            static const uint32_t allowed[] = { 0x040D62F8u, 0x040D6358u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D62F8u: {
            const uint32_t source_key = 0x040D62F8u;
            cpu->pc = 0xAC62u;
            uint16_t value = 0x0076u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D6310u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6310u: {
            const uint32_t source_key = 0x040D6310u;
            cpu->pc = 0xAC65u;
            uint16_t value = 0x0075u;
            js_op_load_x(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D6328u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6328u: {
            const uint32_t source_key = 0x040D6328u;
            cpu->pc = 0xAC68u;
            uint16_t value = 0x003Cu;
            js_op_load_y(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D6340u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6340u: {
            const uint32_t source_key = 0x040D6340u;
            cpu->pc = 0xAC6Bu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xAD29u;
            static const uint32_t allowed[] = { 0x040D6948u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6358u: {
            const uint32_t source_key = 0x040D6358u;
            cpu->pc = 0xAC6Eu;
            uint16_t value = 0x0039u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D6370u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6370u: {
            const uint32_t source_key = 0x040D6370u;
            cpu->pc = 0xAC71u;
            uint16_t value = 0x0038u;
            js_op_load_x(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D6388u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6388u: {
            const uint32_t source_key = 0x040D6388u;
            cpu->pc = 0xAC74u;
            uint16_t value = 0x003Au;
            js_op_load_y(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D63A0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D63A0u: {
            const uint32_t source_key = 0x040D63A0u;
            cpu->pc = 0xAC77u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xAD29u;
            static const uint32_t allowed[] = { 0x040D6948u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D63B8u: {
            const uint32_t source_key = 0x040D63B8u;
            cpu->pc = 0xAC7Au;
            uint16_t value = 0x0076u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D63D0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D63D0u: {
            const uint32_t source_key = 0x040D63D0u;
            cpu->pc = 0xAC7Du;
            uint16_t value = 0x0075u;
            js_op_load_x(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D63E8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D63E8u: {
            const uint32_t source_key = 0x040D63E8u;
            cpu->pc = 0xAC80u;
            uint16_t value = 0x0077u;
            js_op_load_y(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D6400u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6400u: {
            const uint32_t source_key = 0x040D6400u;
            cpu->pc = 0xAC83u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xAD29u;
            static const uint32_t allowed[] = { 0x040D6948u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6418u: {
            const uint32_t source_key = 0x040D6418u;
            cpu->pc = 0xAC85u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040D642Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D642Bu: {
            const uint32_t source_key = 0x040D642Bu;
            cpu->pc = 0xAC88u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xADA6u;
            static const uint32_t allowed[] = { 0x040D6D33u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6443u: {
            const uint32_t source_key = 0x040D6443u;
            cpu->pc = 0xAC8Bu;
            cpu->pc = 0xF454u;
            static const uint32_t allowed[] = { 0x040FA2A3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D645Bu: {
            const uint32_t source_key = 0x040D645Bu;
            cpu->pc = 0xAC8Eu;
            uint32_t ea = js_addr_abs(cpu, 0x031Bu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D6473u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6473u: {
            const uint32_t source_key = 0x040D6473u;
            cpu->pc = 0xAC91u;
            uint32_t ea = js_addr_abs(cpu, 0x031Cu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_ora(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D648Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D648Bu: {
            const uint32_t source_key = 0x040D648Bu;
            cpu->pc = 0xAC93u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (3));
            static const uint32_t allowed[] = { 0x040D649Bu, 0x040D64B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D649Bu: {
            const uint32_t source_key = 0x040D649Bu;
            cpu->pc = 0xAC96u;
            cpu->pc = 0xBA19u;
            static const uint32_t allowed[] = { 0x040DD0CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D64B3u: {
            const uint32_t source_key = 0x040D64B3u;
            cpu->pc = 0xAC99u;
            uint32_t ea = js_addr_abs(cpu, 0x031Eu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D64CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D64CBu: {
            const uint32_t source_key = 0x040D64CBu;
            cpu->pc = 0xAC9Cu;
            uint32_t ea = js_addr_abs(cpu, 0x033Cu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D64E3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D64E3u: {
            const uint32_t source_key = 0x040D64E3u;
            cpu->pc = 0xAC9Fu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xA557u;
            static const uint32_t allowed[] = { 0x040D2ABBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6723u: {
            const uint32_t source_key = 0x040D6723u;
            cpu->pc = 0xACE6u;
            uint16_t value = 0x0000u;
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D6733u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6733u: {
            const uint32_t source_key = 0x040D6733u;
            cpu->pc = 0xACE9u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xAE76u;
            static const uint32_t allowed[] = { 0x040D73B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D674Bu: {
            const uint32_t source_key = 0x040D674Bu;
            cpu->pc = 0xACECu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xAF2Fu;
            static const uint32_t allowed[] = { 0x040D797Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6763u: {
            const uint32_t source_key = 0x040D6763u;
            cpu->pc = 0xACEEu;
            uint16_t value = 0x0000u;
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D6773u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6773u: {
            const uint32_t source_key = 0x040D6773u;
            cpu->pc = 0xACF1u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xAE21u;
            static const uint32_t allowed[] = { 0x040D710Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D678Bu: {
            const uint32_t source_key = 0x040D678Bu;
            cpu->pc = 0xACF4u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9D99u;
            static const uint32_t allowed[] = { 0x040CECCBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D67A3u: {
            const uint32_t source_key = 0x040D67A3u;
            cpu->pc = 0xACF6u;
            if (js_branch_condition(cpu, 'C')) cpu->pc = (uint16_t)(cpu->pc + (13));
            static const uint32_t allowed[] = { 0x040D67B3u, 0x040D681Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D67B3u: {
            const uint32_t source_key = 0x040D67B3u;
            cpu->pc = 0xACF8u;
            uint16_t value = 0x0001u;
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D67C3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D67C3u: {
            const uint32_t source_key = 0x040D67C3u;
            cpu->pc = 0xACFBu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xAE76u;
            static const uint32_t allowed[] = { 0x040D73B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D67DBu: {
            const uint32_t source_key = 0x040D67DBu;
            cpu->pc = 0xACFEu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xAF2Fu;
            static const uint32_t allowed[] = { 0x040D797Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D67F3u: {
            const uint32_t source_key = 0x040D67F3u;
            cpu->pc = 0xAD00u;
            uint16_t value = 0x0001u;
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D6803u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6803u: {
            const uint32_t source_key = 0x040D6803u;
            cpu->pc = 0xAD03u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xAE21u;
            static const uint32_t allowed[] = { 0x040D710Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D681Bu: {
            const uint32_t source_key = 0x040D681Bu;
            cpu->pc = 0xAD05u;
            uint16_t value = 0x0061u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D682Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D682Bu: {
            const uint32_t source_key = 0x040D682Bu;
            cpu->pc = 0xAD08u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9DB1u;
            static const uint32_t allowed[] = { 0x040CED8Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6843u: {
            const uint32_t source_key = 0x040D6843u;
            cpu->pc = 0xAD0Bu;
            uint32_t ea = js_addr_abs(cpu, 0x02A0u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D685Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D685Bu: {
            const uint32_t source_key = 0x040D685Bu;
            cpu->pc = 0xAD0Eu;
            uint32_t ea = js_addr_abs(cpu, 0x0DF2u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D6873u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6873u: {
            const uint32_t source_key = 0x040D6873u;
            cpu->pc = 0xAD11u;
            uint32_t ea = js_addr_abs(cpu, 0x02A1u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D688Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D688Bu: {
            const uint32_t source_key = 0x040D688Bu;
            cpu->pc = 0xAD14u;
            uint32_t ea = js_addr_abs(cpu, 0x0DF3u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D68A3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D68A3u: {
            const uint32_t source_key = 0x040D68A3u;
            cpu->pc = 0xAD17u;
            uint32_t ea = js_addr_abs(cpu, 0x02A2u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D68BBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D68BBu: {
            const uint32_t source_key = 0x040D68BBu;
            cpu->pc = 0xAD1Au;
            uint32_t ea = js_addr_abs(cpu, 0x0E2Du);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D68D3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D68D3u: {
            const uint32_t source_key = 0x040D68D3u;
            cpu->pc = 0xAD1Du;
            uint32_t ea = js_addr_abs(cpu, 0x02A3u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D68EBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D68EBu: {
            const uint32_t source_key = 0x040D68EBu;
            cpu->pc = 0xAD20u;
            uint32_t ea = js_addr_abs(cpu, 0x0E2Eu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D6903u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6903u: {
            const uint32_t source_key = 0x040D6903u;
            return js_stop_now(stop, JS_STOP_UNPROVED_RETURN, source_key, source_key);
        }
        case 0x040D6948u: {
            const uint32_t source_key = 0x040D6948u;
            cpu->pc = 0xAD2Bu;
            uint32_t ea = js_addr_dp(cpu, 0x88u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D6958u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6958u: {
            const uint32_t source_key = 0x040D6958u;
            cpu->pc = 0xAD2Eu;
            uint32_t ea = js_addr_abs(cpu, 0x0F0Eu);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D6970u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6970u: {
            const uint32_t source_key = 0x040D6970u;
            cpu->pc = 0xAD31u;
            uint16_t value = 0x00FFu;
            js_op_and(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D6988u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6988u: {
            const uint32_t source_key = 0x040D6988u;
            cpu->pc = 0xAD33u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (65));
            static const uint32_t allowed[] = { 0x040D6998u, 0x040D6BA0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6998u: {
            const uint32_t source_key = 0x040D6998u;
            cpu->pc = 0xAD35u;
            uint32_t ea = js_addr_dp(cpu, 0x88u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D69A8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D69A8u: {
            const uint32_t source_key = 0x040D69A8u;
            cpu->pc = 0xAD38u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9D72u;
            static const uint32_t allowed[] = { 0x040CEB90u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6BA0u: {
            const uint32_t source_key = 0x040D6BA0u;
            cpu->pc = 0xAD75u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040D6358u, 0x040D63B8u, 0x040D6418u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6D33u: {
            const uint32_t source_key = 0x040D6D33u;
            cpu->pc = 0xADA9u;
            uint32_t ea = js_addr_abs(cpu, 0x0299u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D6D4Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6D4Bu: {
            const uint32_t source_key = 0x040D6D4Bu;
            cpu->pc = 0xADABu;
            uint16_t value = 0x0001u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D6D5Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6D5Bu: {
            const uint32_t source_key = 0x040D6D5Bu;
            cpu->pc = 0xADAEu;
            uint32_t ea = js_addr_abs(cpu, 0x029Au);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D6D73u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6D73u: {
            const uint32_t source_key = 0x040D6D73u;
            cpu->pc = 0xADB1u;
            uint32_t ea = js_addr_abs(cpu, 0x029Bu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D6D8Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6D8Bu: {
            const uint32_t source_key = 0x040D6D8Bu;
            cpu->pc = 0xADB3u;
            uint16_t value = 0x0000u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D6D9Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6D9Bu: {
            const uint32_t source_key = 0x040D6D9Bu;
            cpu->pc = 0xADB6u;
            uint32_t ea = js_addr_abs(cpu, 0x0C00u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D6DB3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6DB3u: {
            const uint32_t source_key = 0x040D6DB3u;
            cpu->pc = 0xADB8u;
            js_op_rep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x040D6DC1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6DC1u: {
            const uint32_t source_key = 0x040D6DC1u;
            cpu->pc = 0xADBBu;
            uint16_t value = 0x0100u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D6DD9u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6DD9u: {
            const uint32_t source_key = 0x040D6DD9u;
            cpu->pc = 0xADBEu;
            uint32_t ea = js_addr_abs(cpu, 0x029Cu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D6DF1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6DF1u: {
            const uint32_t source_key = 0x040D6DF1u;
            cpu->pc = 0xADC1u;
            uint16_t value = 0x0808u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D6E09u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6E09u: {
            const uint32_t source_key = 0x040D6E09u;
            cpu->pc = 0xADC4u;
            uint32_t ea = js_addr_abs(cpu, 0x02A0u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D6E21u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6E21u: {
            const uint32_t source_key = 0x040D6E21u;
            cpu->pc = 0xADC7u;
            uint16_t value = 0x0004u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D6E39u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6E39u: {
            const uint32_t source_key = 0x040D6E39u;
            cpu->pc = 0xADCAu;
            uint32_t ea = js_addr_abs(cpu, 0x02A2u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D6E51u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6E51u: {
            const uint32_t source_key = 0x040D6E51u;
            cpu->pc = 0xADCDu;
            uint16_t value = 0x0101u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D6E69u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6E69u: {
            const uint32_t source_key = 0x040D6E69u;
            cpu->pc = 0xADD0u;
            uint32_t ea = js_addr_abs(cpu, 0x0E33u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D6E81u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6E81u: {
            const uint32_t source_key = 0x040D6E81u;
            cpu->pc = 0xADD3u;
            uint16_t value = 0x0202u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D6E99u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6E99u: {
            const uint32_t source_key = 0x040D6E99u;
            cpu->pc = 0xADD6u;
            uint32_t ea = js_addr_abs(cpu, 0x0E37u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D6EB1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6EB1u: {
            const uint32_t source_key = 0x040D6EB1u;
            cpu->pc = 0xADD9u;
            uint16_t value = 0x0101u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D6EC9u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6EC9u: {
            const uint32_t source_key = 0x040D6EC9u;
            cpu->pc = 0xADDCu;
            uint32_t ea = js_addr_abs(cpu, 0x0E3Bu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D6EE1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6EE1u: {
            const uint32_t source_key = 0x040D6EE1u;
            cpu->pc = 0xADDFu;
            uint32_t ea = js_addr_abs(cpu, 0x0DF6u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D6EF9u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6EF9u: {
            const uint32_t source_key = 0x040D6EF9u;
            cpu->pc = 0xADE2u;
            uint32_t ea = js_addr_abs(cpu, 0x0DFAu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D6F11u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6F11u: {
            const uint32_t source_key = 0x040D6F11u;
            cpu->pc = 0xADE5u;
            uint32_t ea = js_addr_abs(cpu, 0x0DFEu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D6F29u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6F29u: {
            const uint32_t source_key = 0x040D6F29u;
            cpu->pc = 0xADE8u;
            uint32_t ea = js_addr_abs(cpu, 0x0E02u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D6F41u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6F41u: {
            const uint32_t source_key = 0x040D6F41u;
            cpu->pc = 0xADEBu;
            uint16_t value = 0x0101u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D6F59u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6F59u: {
            const uint32_t source_key = 0x040D6F59u;
            cpu->pc = 0xADEEu;
            uint32_t ea = js_addr_abs(cpu, 0x0E6Fu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D6F71u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6F71u: {
            const uint32_t source_key = 0x040D6F71u;
            cpu->pc = 0xADF1u;
            uint32_t ea = js_addr_abs(cpu, 0x0E73u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D6F89u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6F89u: {
            const uint32_t source_key = 0x040D6F89u;
            cpu->pc = 0xADF4u;
            uint32_t ea = js_addr_abs(cpu, 0x0E77u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D6FA1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6FA1u: {
            const uint32_t source_key = 0x040D6FA1u;
            cpu->pc = 0xADF7u;
            uint32_t ea = js_addr_abs(cpu, 0x0E7Bu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D6FB9u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6FB9u: {
            const uint32_t source_key = 0x040D6FB9u;
            cpu->pc = 0xADFAu;
            uint32_t ea = js_addr_abs(cpu, 0x0E7Fu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D6FD1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6FD1u: {
            const uint32_t source_key = 0x040D6FD1u;
            cpu->pc = 0xADFDu;
            uint32_t ea = js_addr_abs(cpu, 0x0E83u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D6FE9u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D6FE9u: {
            const uint32_t source_key = 0x040D6FE9u;
            cpu->pc = 0xAE00u;
            uint32_t ea = js_addr_abs(cpu, 0x0E87u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D7001u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7001u: {
            const uint32_t source_key = 0x040D7001u;
            cpu->pc = 0xAE03u;
            uint32_t ea = js_addr_abs(cpu, 0x0E87u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D7019u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7019u: {
            const uint32_t source_key = 0x040D7019u;
            cpu->pc = 0xAE06u;
            uint32_t ea = js_addr_abs(cpu, 0x0E8Bu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D7031u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7031u: {
            const uint32_t source_key = 0x040D7031u;
            cpu->pc = 0xAE09u;
            uint32_t ea = js_addr_abs(cpu, 0x02A8u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D7049u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7049u: {
            const uint32_t source_key = 0x040D7049u;
            cpu->pc = 0xAE0Cu;
            uint32_t ea = js_addr_abs(cpu, 0x02ACu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D7061u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7061u: {
            const uint32_t source_key = 0x040D7061u;
            cpu->pc = 0xAE0Fu;
            uint32_t ea = js_addr_abs(cpu, 0x02AEu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D7079u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7079u: {
            const uint32_t source_key = 0x040D7079u;
            cpu->pc = 0xAE12u;
            uint16_t value = 0x0002u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D7091u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7091u: {
            const uint32_t source_key = 0x040D7091u;
            cpu->pc = 0xAE15u;
            uint32_t ea = js_addr_abs(cpu, 0x0E08u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D70A9u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D70A9u: {
            const uint32_t source_key = 0x040D70A9u;
            cpu->pc = 0xAE18u;
            uint32_t ea = js_addr_abs(cpu, 0x0E0Cu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D70C1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D70C1u: {
            const uint32_t source_key = 0x040D70C1u;
            cpu->pc = 0xAE1Bu;
            uint32_t ea = js_addr_abs(cpu, 0x0E06u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D70D9u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D70D9u: {
            const uint32_t source_key = 0x040D70D9u;
            cpu->pc = 0xAE1Eu;
            uint32_t ea = js_addr_abs(cpu, 0x0E0Au);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D70F1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D70F1u: {
            const uint32_t source_key = 0x040D70F1u;
            cpu->pc = 0xAE20u;
            js_op_sep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x040D7103u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7103u: {
            const uint32_t source_key = 0x040D7103u;
            cpu->pc = 0xAE21u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040D6443u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D710Bu: {
            const uint32_t source_key = 0x040D710Bu;
            cpu->pc = 0xAE24u;
            uint32_t ea = js_addr_abs(cpu, 0x031Cu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D7123u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7123u: {
            const uint32_t source_key = 0x040D7123u;
            cpu->pc = 0xAE26u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (79));
            static const uint32_t allowed[] = { 0x040D7133u, 0x040D73ABu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7133u: {
            const uint32_t source_key = 0x040D7133u;
            cpu->pc = 0xAE29u;
            uint32_t ea = js_addr_abs(cpu, 0x02B5u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D714Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D714Bu: {
            const uint32_t source_key = 0x040D714Bu;
            cpu->pc = 0xAE2Cu;
            uint32_t ea = js_addr_abs_x(cpu, 0x0E83u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D7163u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7163u: {
            const uint32_t source_key = 0x040D7163u;
            cpu->pc = 0xAE2Fu;
            uint32_t ea = js_addr_abs(cpu, 0x02B6u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D717Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D717Bu: {
            const uint32_t source_key = 0x040D717Bu;
            cpu->pc = 0xAE32u;
            uint32_t ea = js_addr_abs_x(cpu, 0x0E7Fu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D7193u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7193u: {
            const uint32_t source_key = 0x040D7193u;
            cpu->pc = 0xAE35u;
            uint32_t ea = js_addr_abs(cpu, 0x02B7u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D71ABu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D71ABu: {
            const uint32_t source_key = 0x040D71ABu;
            cpu->pc = 0xAE38u;
            uint32_t ea = js_addr_abs_x(cpu, 0x0E7Bu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D71C3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D71C3u: {
            const uint32_t source_key = 0x040D71C3u;
            cpu->pc = 0xAE3Bu;
            uint32_t ea = js_addr_abs(cpu, 0x02B8u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D71DBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D71DBu: {
            const uint32_t source_key = 0x040D71DBu;
            cpu->pc = 0xAE3Eu;
            uint32_t ea = js_addr_abs_x(cpu, 0x0E73u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D71F3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D71F3u: {
            const uint32_t source_key = 0x040D71F3u;
            cpu->pc = 0xAE41u;
            uint32_t ea = js_addr_abs(cpu, 0x02B9u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D720Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D720Bu: {
            const uint32_t source_key = 0x040D720Bu;
            cpu->pc = 0xAE44u;
            uint32_t ea = js_addr_abs_x(cpu, 0x0E77u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D7223u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7223u: {
            const uint32_t source_key = 0x040D7223u;
            cpu->pc = 0xAE47u;
            uint32_t ea = js_addr_abs(cpu, 0x02BAu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D723Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D723Bu: {
            const uint32_t source_key = 0x040D723Bu;
            cpu->pc = 0xAE4Au;
            uint32_t ea = js_addr_abs_x(cpu, 0x0E6Fu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D7253u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7253u: {
            const uint32_t source_key = 0x040D7253u;
            cpu->pc = 0xAE4Du;
            uint32_t ea = js_addr_abs(cpu, 0x02BBu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D726Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D726Bu: {
            const uint32_t source_key = 0x040D726Bu;
            cpu->pc = 0xAE50u;
            uint32_t ea = js_addr_abs_x(cpu, 0x0E8Bu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D7283u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7283u: {
            const uint32_t source_key = 0x040D7283u;
            cpu->pc = 0xAE53u;
            uint32_t ea = js_addr_abs(cpu, 0x02BCu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D729Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D729Bu: {
            const uint32_t source_key = 0x040D729Bu;
            cpu->pc = 0xAE56u;
            uint32_t ea = js_addr_abs_x(cpu, 0x0E87u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D72B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D72B3u: {
            const uint32_t source_key = 0x040D72B3u;
            cpu->pc = 0xAE59u;
            uint32_t ea = js_addr_abs(cpu, 0x02BDu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_y(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D72CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D72CBu: {
            const uint32_t source_key = 0x040D72CBu;
            cpu->pc = 0xAE5Cu;
            uint32_t ea = js_addr_abs_y(cpu, 0xAF20u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D72E3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D72E3u: {
            const uint32_t source_key = 0x040D72E3u;
            cpu->pc = 0xAE5Fu;
            uint32_t ea = js_addr_abs_x(cpu, 0x0E33u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D72FBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D72FBu: {
            const uint32_t source_key = 0x040D72FBu;
            cpu->pc = 0xAE62u;
            uint32_t ea = js_addr_abs(cpu, 0x02BEu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_y(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D7313u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7313u: {
            const uint32_t source_key = 0x040D7313u;
            cpu->pc = 0xAE65u;
            uint32_t ea = js_addr_abs_y(cpu, 0xAF20u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D732Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D732Bu: {
            const uint32_t source_key = 0x040D732Bu;
            cpu->pc = 0xAE68u;
            uint32_t ea = js_addr_abs_x(cpu, 0x0E37u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D7343u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7343u: {
            const uint32_t source_key = 0x040D7343u;
            cpu->pc = 0xAE6Bu;
            uint32_t ea = js_addr_abs(cpu, 0x02BFu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_y(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D735Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D735Bu: {
            const uint32_t source_key = 0x040D735Bu;
            cpu->pc = 0xAE6Eu;
            uint32_t ea = js_addr_abs_y(cpu, 0xAF26u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D7373u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7373u: {
            const uint32_t source_key = 0x040D7373u;
            cpu->pc = 0xAE71u;
            uint32_t ea = js_addr_abs_x(cpu, 0x0E3Bu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D738Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D738Bu: {
            const uint32_t source_key = 0x040D738Bu;
            cpu->pc = 0xAE72u;
            js_op_transfer(cpu, 'F');
            static const uint32_t allowed[] = { 0x040D7393u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7393u: {
            const uint32_t source_key = 0x040D7393u;
            cpu->pc = 0xAE75u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xB67Du;
            static const uint32_t allowed[] = { 0x040DB3EBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D73ABu: {
            const uint32_t source_key = 0x040D73ABu;
            cpu->pc = 0xAE76u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040D678Bu, 0x040D681Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D73B3u: {
            const uint32_t source_key = 0x040D73B3u;
            cpu->pc = 0xAE79u;
            uint32_t ea = js_addr_abs(cpu, 0x033Cu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_x(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D73CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D73CBu: {
            const uint32_t source_key = 0x040D73CBu;
            cpu->pc = 0xAE7Cu;
            uint32_t ea = js_addr_abs(cpu, 0x13B7u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D73E3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D73E3u: {
            const uint32_t source_key = 0x040D73E3u;
            cpu->pc = 0xAE7Fu;
            uint32_t ea = js_addr_abs(cpu, 0x13B9u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D73FBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D73FBu: {
            const uint32_t source_key = 0x040D73FBu;
            cpu->pc = 0xAE82u;
            uint32_t ea = js_addr_abs(cpu, 0x13BAu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D7413u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7413u: {
            const uint32_t source_key = 0x040D7413u;
            cpu->pc = 0xAE85u;
            uint32_t ea = js_addr_abs_x(cpu, 0x02A8u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D742Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D742Bu: {
            const uint32_t source_key = 0x040D742Bu;
            cpu->pc = 0xAE88u;
            uint32_t ea = js_addr_abs(cpu, 0x02AAu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D7443u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7443u: {
            const uint32_t source_key = 0x040D7443u;
            cpu->pc = 0xAE8Bu;
            uint32_t ea = js_addr_abs(cpu, 0x0299u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_y(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D745Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D745Bu: {
            const uint32_t source_key = 0x040D745Bu;
            cpu->pc = 0xAE8Eu;
            uint32_t ea = js_addr_abs(cpu, 0x0BFFu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D7473u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7473u: {
            const uint32_t source_key = 0x040D7473u;
            cpu->pc = 0xAE90u;
            uint16_t value = 0x0002u;
            js_op_compare(cpu, cpu->a, value, 8u);
            static const uint32_t allowed[] = { 0x040D7483u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7483u: {
            const uint32_t source_key = 0x040D7483u;
            cpu->pc = 0xAE92u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (5));
            static const uint32_t allowed[] = { 0x040D7493u, 0x040D74BBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7493u: {
            const uint32_t source_key = 0x040D7493u;
            cpu->pc = 0xAE95u;
            uint32_t ea = js_addr_abs_y(cpu, 0xAF0Cu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D74ABu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D74ABu: {
            const uint32_t source_key = 0x040D74ABu;
            cpu->pc = 0xAE97u;
            if (js_branch_condition(cpu, 'A')) cpu->pc = (uint16_t)(cpu->pc + (3));
            static const uint32_t allowed[] = { 0x040D74D3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D74BBu: {
            const uint32_t source_key = 0x040D74BBu;
            cpu->pc = 0xAE9Au;
            uint32_t ea = js_addr_abs_y(cpu, 0xAF12u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D74D3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D74D3u: {
            const uint32_t source_key = 0x040D74D3u;
            cpu->pc = 0xAE9Du;
            uint32_t ea = js_addr_abs(cpu, 0x02ABu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D74EBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D74EBu: {
            const uint32_t source_key = 0x040D74EBu;
            cpu->pc = 0xAEA0u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xAEA7u;
            static const uint32_t allowed[] = { 0x040D753Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7503u: {
            const uint32_t source_key = 0x040D7503u;
            cpu->pc = 0xAEA3u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xAEF3u;
            static const uint32_t allowed[] = { 0x040D779Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D751Bu: {
            const uint32_t source_key = 0x040D751Bu;
            cpu->pc = 0xAEA4u;
            js_op_transfer(cpu, 'F');
            static const uint32_t allowed[] = { 0x040D7523u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7523u: {
            const uint32_t source_key = 0x040D7523u;
            cpu->pc = 0xAEA7u;
            cpu->pc = 0xB669u;
            static const uint32_t allowed[] = { 0x040DB34Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D753Bu: {
            const uint32_t source_key = 0x040D753Bu;
            cpu->pc = 0xAEAAu;
            uint32_t ea = js_addr_abs_x(cpu, 0x0E83u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D7553u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7553u: {
            const uint32_t source_key = 0x040D7553u;
            cpu->pc = 0xAEADu;
            uint32_t ea = js_addr_abs(cpu, 0x02B5u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D756Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D756Bu: {
            const uint32_t source_key = 0x040D756Bu;
            cpu->pc = 0xAEB0u;
            uint32_t ea = js_addr_abs_x(cpu, 0x0E7Fu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D7583u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7583u: {
            const uint32_t source_key = 0x040D7583u;
            cpu->pc = 0xAEB3u;
            uint32_t ea = js_addr_abs(cpu, 0x02B6u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D759Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D759Bu: {
            const uint32_t source_key = 0x040D759Bu;
            cpu->pc = 0xAEB6u;
            uint32_t ea = js_addr_abs_x(cpu, 0x0E7Bu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D75B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D75B3u: {
            const uint32_t source_key = 0x040D75B3u;
            cpu->pc = 0xAEB9u;
            uint32_t ea = js_addr_abs(cpu, 0x02B7u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D75CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D75CBu: {
            const uint32_t source_key = 0x040D75CBu;
            cpu->pc = 0xAEBCu;
            uint32_t ea = js_addr_abs_x(cpu, 0x0E73u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D75E3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D75E3u: {
            const uint32_t source_key = 0x040D75E3u;
            cpu->pc = 0xAEBFu;
            uint32_t ea = js_addr_abs(cpu, 0x02B8u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D75FBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D75FBu: {
            const uint32_t source_key = 0x040D75FBu;
            cpu->pc = 0xAEC2u;
            uint32_t ea = js_addr_abs_x(cpu, 0x0E77u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D7613u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7613u: {
            const uint32_t source_key = 0x040D7613u;
            cpu->pc = 0xAEC5u;
            uint32_t ea = js_addr_abs(cpu, 0x02B9u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D762Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D762Bu: {
            const uint32_t source_key = 0x040D762Bu;
            cpu->pc = 0xAEC8u;
            uint32_t ea = js_addr_abs_x(cpu, 0x0E6Fu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D7643u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7643u: {
            const uint32_t source_key = 0x040D7643u;
            cpu->pc = 0xAECBu;
            uint32_t ea = js_addr_abs(cpu, 0x02BAu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D765Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D765Bu: {
            const uint32_t source_key = 0x040D765Bu;
            cpu->pc = 0xAECEu;
            uint32_t ea = js_addr_abs_x(cpu, 0x0E8Bu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D7673u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7673u: {
            const uint32_t source_key = 0x040D7673u;
            cpu->pc = 0xAED1u;
            uint32_t ea = js_addr_abs(cpu, 0x02BBu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D768Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D768Bu: {
            const uint32_t source_key = 0x040D768Bu;
            cpu->pc = 0xAED4u;
            uint32_t ea = js_addr_abs_x(cpu, 0x0E87u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D76A3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D76A3u: {
            const uint32_t source_key = 0x040D76A3u;
            cpu->pc = 0xAED7u;
            uint32_t ea = js_addr_abs(cpu, 0x02BCu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D76BBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D76BBu: {
            const uint32_t source_key = 0x040D76BBu;
            cpu->pc = 0xAEDAu;
            uint32_t ea = js_addr_abs_x(cpu, 0x0E33u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_y(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D76D3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D76D3u: {
            const uint32_t source_key = 0x040D76D3u;
            cpu->pc = 0xAEDDu;
            uint32_t ea = js_addr_abs_y(cpu, 0xAF18u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D76EBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D76EBu: {
            const uint32_t source_key = 0x040D76EBu;
            cpu->pc = 0xAEE0u;
            uint32_t ea = js_addr_abs(cpu, 0x02BDu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D7703u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7703u: {
            const uint32_t source_key = 0x040D7703u;
            cpu->pc = 0xAEE3u;
            uint32_t ea = js_addr_abs_x(cpu, 0x0E37u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_y(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D771Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D771Bu: {
            const uint32_t source_key = 0x040D771Bu;
            cpu->pc = 0xAEE6u;
            uint32_t ea = js_addr_abs_y(cpu, 0xAF18u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D7733u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7733u: {
            const uint32_t source_key = 0x040D7733u;
            cpu->pc = 0xAEE9u;
            uint32_t ea = js_addr_abs(cpu, 0x02BEu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D774Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D774Bu: {
            const uint32_t source_key = 0x040D774Bu;
            cpu->pc = 0xAEECu;
            uint32_t ea = js_addr_abs_x(cpu, 0x0E3Bu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_y(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D7763u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7763u: {
            const uint32_t source_key = 0x040D7763u;
            cpu->pc = 0xAEEFu;
            uint32_t ea = js_addr_abs_y(cpu, 0xAF1Eu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D777Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D777Bu: {
            const uint32_t source_key = 0x040D777Bu;
            cpu->pc = 0xAEF2u;
            uint32_t ea = js_addr_abs(cpu, 0x02BFu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D7793u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7793u: {
            const uint32_t source_key = 0x040D7793u;
            cpu->pc = 0xAEF3u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040D7503u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D779Bu: {
            const uint32_t source_key = 0x040D779Bu;
            cpu->pc = 0xAEF6u;
            uint32_t ea = js_addr_abs_x(cpu, 0x029Cu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D77B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D77B3u: {
            const uint32_t source_key = 0x040D77B3u;
            cpu->pc = 0xAEF9u;
            uint32_t ea = js_addr_abs(cpu, 0x02B0u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D77CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D77CBu: {
            const uint32_t source_key = 0x040D77CBu;
            cpu->pc = 0xAEFCu;
            uint32_t ea = js_addr_abs_x(cpu, 0x02A0u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D77E3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D77E3u: {
            const uint32_t source_key = 0x040D77E3u;
            cpu->pc = 0xAEFFu;
            uint32_t ea = js_addr_abs(cpu, 0x0DF2u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D77FBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D77FBu: {
            const uint32_t source_key = 0x040D77FBu;
            cpu->pc = 0xAF02u;
            uint32_t ea = js_addr_abs(cpu, 0x0DF5u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D7813u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7813u: {
            const uint32_t source_key = 0x040D7813u;
            cpu->pc = 0xAF05u;
            uint32_t ea = js_addr_abs_x(cpu, 0x02A2u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D782Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D782Bu: {
            const uint32_t source_key = 0x040D782Bu;
            cpu->pc = 0xAF08u;
            uint32_t ea = js_addr_abs(cpu, 0x0E2Du);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D7843u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7843u: {
            const uint32_t source_key = 0x040D7843u;
            cpu->pc = 0xAF0Bu;
            uint32_t ea = js_addr_abs(cpu, 0x0E30u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D785Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D785Bu: {
            const uint32_t source_key = 0x040D785Bu;
            cpu->pc = 0xAF0Cu;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040D751Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D797Bu: {
            const uint32_t source_key = 0x040D797Bu;
            cpu->pc = 0xAF32u;
            uint32_t ea = js_addr_abs(cpu, 0x0241u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D7993u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7993u: {
            const uint32_t source_key = 0x040D7993u;
            cpu->pc = 0xAF35u;
            uint32_t ea = js_addr_abs(cpu, 0x0242u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D79ABu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D79ABu: {
            const uint32_t source_key = 0x040D79ABu;
            cpu->pc = 0xAF38u;
            uint32_t ea = js_addr_abs(cpu, 0x031Cu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D79C3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D79C3u: {
            const uint32_t source_key = 0x040D79C3u;
            cpu->pc = 0xAF3Au;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (6));
            static const uint32_t allowed[] = { 0x040D79D3u, 0x040D7A03u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D79D3u: {
            const uint32_t source_key = 0x040D79D3u;
            cpu->pc = 0xAF3Du;
            uint32_t ea = js_addr_abs(cpu, 0x033Cu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D79EBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D79EBu: {
            const uint32_t source_key = 0x040D79EBu;
            cpu->pc = 0xAF3Fu;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (1));
            static const uint32_t allowed[] = { 0x040D79FBu, 0x040D7A03u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D79FBu: {
            const uint32_t source_key = 0x040D79FBu;
            cpu->pc = 0xAF40u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040D6763u, 0x040D67F3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7A03u: {
            const uint32_t source_key = 0x040D7A03u;
            cpu->pc = 0xAF43u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9C46u;
            static const uint32_t allowed[] = { 0x040CE233u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7A1Bu: {
            const uint32_t source_key = 0x040D7A1Bu;
            cpu->pc = 0xAF45u;
            uint16_t value = 0x0000u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D7A2Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7A2Bu: {
            const uint32_t source_key = 0x040D7A2Bu;
            cpu->pc = 0xAF48u;
            uint32_t ea = js_addr_abs(cpu, 0x035Bu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D7A43u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7A43u: {
            const uint32_t source_key = 0x040D7A43u;
            cpu->pc = 0xAF4Au;
            uint16_t value = 0x0008u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D7A53u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7A53u: {
            const uint32_t source_key = 0x040D7A53u;
            cpu->pc = 0xAF4Du;
            uint32_t ea = js_addr_abs(cpu, 0x035Cu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D7A6Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7A6Bu: {
            const uint32_t source_key = 0x040D7A6Bu;
            cpu->pc = 0xAF4Fu;
            uint16_t value = 0x0009u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D7A7Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7A7Bu: {
            const uint32_t source_key = 0x040D7A7Bu;
            cpu->pc = 0xAF52u;
            uint32_t ea = js_addr_abs(cpu, 0x2109u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D7A93u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7A93u: {
            const uint32_t source_key = 0x040D7A93u;
            cpu->pc = 0xAF54u;
            uint16_t value = 0x0081u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D7AA3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7AA3u: {
            const uint32_t source_key = 0x040D7AA3u;
            cpu->pc = 0xAF57u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9DB1u;
            static const uint32_t allowed[] = { 0x040CED8Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7ABBu: {
            const uint32_t source_key = 0x040D7ABBu;
            cpu->pc = 0xAF5Au;
            uint32_t ea = js_addr_abs(cpu, 0x02CDu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D7AD3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7AD3u: {
            const uint32_t source_key = 0x040D7AD3u;
            cpu->pc = 0xAF5Du;
            uint32_t ea = js_addr_abs(cpu, 0x13B7u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D7AEBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7AEBu: {
            const uint32_t source_key = 0x040D7AEBu;
            cpu->pc = 0xAF60u;
            uint32_t ea = js_addr_abs(cpu, 0x13B8u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D7B03u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7B03u: {
            const uint32_t source_key = 0x040D7B03u;
            cpu->pc = 0xAF62u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (15));
            static const uint32_t allowed[] = { 0x040D7B13u, 0x040D7B8Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7B13u: {
            const uint32_t source_key = 0x040D7B13u;
            cpu->pc = 0xAF65u;
            uint32_t ea = js_addr_abs(cpu, 0x031Cu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D7B2Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7B2Bu: {
            const uint32_t source_key = 0x040D7B2Bu;
            cpu->pc = 0xAF67u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (10));
            static const uint32_t allowed[] = { 0x040D7B3Bu, 0x040D7B8Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7B3Bu: {
            const uint32_t source_key = 0x040D7B3Bu;
            cpu->pc = 0xAF6Au;
            uint32_t ea = js_addr_abs(cpu, 0x0BFFu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040D7B53u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7B53u: {
            const uint32_t source_key = 0x040D7B53u;
            cpu->pc = 0xAF6Cu;
            uint16_t value = 0x0002u;
            js_op_compare(cpu, cpu->a, value, 8u);
            static const uint32_t allowed[] = { 0x040D7B63u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7B63u: {
            const uint32_t source_key = 0x040D7B63u;
            cpu->pc = 0xAF6Eu;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (3));
            static const uint32_t allowed[] = { 0x040D7B73u, 0x040D7B8Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7B73u: {
            const uint32_t source_key = 0x040D7B73u;
            cpu->pc = 0xAF71u;
            uint32_t ea = js_addr_abs(cpu, 0x02D0u);
            uint16_t original = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
            uint16_t result = js_op_incdec(cpu, original, 1, 8u);
            if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D7B8Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7B8Bu: {
            const uint32_t source_key = 0x040D7B8Bu;
            cpu->pc = 0xAF73u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040D7B98u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7B98u: {
            const uint32_t source_key = 0x040D7B98u;
            cpu->pc = 0xAF76u;
            uint16_t value = 0x003Bu;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D7BB0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7BB0u: {
            const uint32_t source_key = 0x040D7BB0u;
            cpu->pc = 0xAF7Au;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0x839Bu;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x04041CD8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7BD0u: {
            const uint32_t source_key = 0x040D7BD0u;
            cpu->pc = 0xAF7Du;
            uint16_t value = 0x003Cu;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D7BE8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7BE8u: {
            const uint32_t source_key = 0x040D7BE8u;
            cpu->pc = 0xAF80u;
            uint16_t value = 0x2000u;
            js_op_load_x(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D7C00u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7C00u: {
            const uint32_t source_key = 0x040D7C00u;
            cpu->pc = 0xAF84u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0x82F7u;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x040417B8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7C20u: {
            const uint32_t source_key = 0x040D7C20u;
            cpu->pc = 0xAF87u;
            uint16_t value = 0x0000u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D7C38u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7C38u: {
            const uint32_t source_key = 0x040D7C38u;
            cpu->pc = 0xAF8Bu;
            uint32_t ea = js_addr_abs_long(0x7E2000u);
            if (!js_bus_write16(bus, ea, 1, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040D7C58u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7C58u: {
            const uint32_t source_key = 0x040D7C58u;
            cpu->pc = 0xAF8Eu;
            uint16_t value = 0x4000u;
            js_op_load_y(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D7C70u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7C70u: {
            const uint32_t source_key = 0x040D7C70u;
            cpu->pc = 0xAF91u;
            uint16_t value = 0x0018u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040D7C88u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040D7C88u: {
            const uint32_t source_key = 0x040D7C88u;
            cpu->pc = 0xAF95u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0x835Bu;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x04041AD8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        default: return JS_EXEC_NOT_MINE;
    }
}
