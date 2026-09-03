#include "v05c_static_cpu.h"

JSExecResult js_v05c_shard_24BC(JSCPU *cpu, const JSBus *bus, JSStop *stop) {
    (void)bus;
    (void)stop;
    switch (js_cpu_context_key(cpu)) {
        case 0x0497800Bu: {
            const uint32_t source_key = 0x0497800Bu;
            cpu->pc = 0xF003u;
            uint16_t value = 0x0001u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0497801Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0497801Bu: {
            const uint32_t source_key = 0x0497801Bu;
            cpu->pc = 0xF006u;
            uint32_t ea = js_addr_abs(cpu, 0x0B4Bu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04978033u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04978033u: {
            const uint32_t source_key = 0x04978033u;
            cpu->pc = 0xF009u;
            uint32_t ea = js_addr_abs(cpu, 0x0355u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0497804Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0497804Bu: {
            const uint32_t source_key = 0x0497804Bu;
            cpu->pc = 0xF00Cu;
            uint32_t ea = js_addr_abs(cpu, 0x0356u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04978063u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04978063u: {
            const uint32_t source_key = 0x04978063u;
            cpu->pc = 0xF00Eu;
            uint32_t ea = js_addr_dp(cpu, 0x02u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04978073u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04978073u: {
            const uint32_t source_key = 0x04978073u;
            cpu->pc = 0xF011u;
            uint32_t ea = js_addr_abs(cpu, 0x0330u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0497808Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0497808Bu: {
            const uint32_t source_key = 0x0497808Bu;
            cpu->pc = 0xF014u;
            uint32_t ea = js_addr_abs(cpu, 0x0247u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x049780A3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x049780A3u: {
            const uint32_t source_key = 0x049780A3u;
            cpu->pc = 0xF016u;
            uint16_t value = 0x00FFu;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x049780B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x049780B3u: {
            const uint32_t source_key = 0x049780B3u;
            cpu->pc = 0xF019u;
            uint32_t ea = js_addr_abs(cpu, 0x026Fu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x049780CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x049780CBu: {
            const uint32_t source_key = 0x049780CBu;
            cpu->pc = 0xF01Bu;
            js_op_rep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x049780D9u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x049780D9u: {
            const uint32_t source_key = 0x049780D9u;
            cpu->pc = 0xF01Eu;
            uint32_t ea = js_addr_abs(cpu, 0x0255u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x049780F1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x049780F1u: {
            const uint32_t source_key = 0x049780F1u;
            cpu->pc = 0xF021u;
            uint32_t ea = js_addr_abs(cpu, 0x0331u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04978109u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04978109u: {
            const uint32_t source_key = 0x04978109u;
            cpu->pc = 0xF024u;
            uint16_t value = 0x1234u;
            js_op_compare(cpu, cpu->a, value, 16u);
            static const uint32_t allowed[] = { 0x04978121u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04978121u: {
            const uint32_t source_key = 0x04978121u;
            cpu->pc = 0xF026u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (8));
            static const uint32_t allowed[] = { 0x04978131u, 0x04978171u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04978131u: {
            const uint32_t source_key = 0x04978131u;
            cpu->pc = 0xF029u;
            uint32_t ea = js_addr_abs(cpu, 0x0337u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04978149u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04978149u: {
            const uint32_t source_key = 0x04978149u;
            cpu->pc = 0xF02Cu;
            uint16_t value = 0x5678u;
            js_op_compare(cpu, cpu->a, value, 16u);
            static const uint32_t allowed[] = { 0x04978161u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04978161u: {
            const uint32_t source_key = 0x04978161u;
            cpu->pc = 0xF02Eu;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (21));
            static const uint32_t allowed[] = { 0x04978171u, 0x04978219u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04978171u: {
            const uint32_t source_key = 0x04978171u;
            cpu->pc = 0xF031u;
            uint32_t ea = js_addr_abs(cpu, 0x0330u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04978189u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04978189u: {
            const uint32_t source_key = 0x04978189u;
            cpu->pc = 0xF034u;
            uint16_t value = 0x1234u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x049781A1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x049781A1u: {
            const uint32_t source_key = 0x049781A1u;
            cpu->pc = 0xF037u;
            uint32_t ea = js_addr_abs(cpu, 0x0331u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x049781B9u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x049781B9u: {
            const uint32_t source_key = 0x049781B9u;
            cpu->pc = 0xF03Au;
            uint32_t ea = js_addr_abs(cpu, 0x0333u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x049781D1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x049781D1u: {
            const uint32_t source_key = 0x049781D1u;
            cpu->pc = 0xF03Du;
            uint32_t ea = js_addr_abs(cpu, 0x0335u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x049781E9u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x049781E9u: {
            const uint32_t source_key = 0x049781E9u;
            cpu->pc = 0xF040u;
            uint16_t value = 0x5678u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04978201u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04978201u: {
            const uint32_t source_key = 0x04978201u;
            cpu->pc = 0xF043u;
            uint32_t ea = js_addr_abs(cpu, 0x0337u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04978219u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04978219u: {
            const uint32_t source_key = 0x04978219u;
            cpu->pc = 0xF045u;
            js_op_sep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x0497822Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0497822Bu: {
            const uint32_t source_key = 0x0497822Bu;
            cpu->pc = 0xF048u;
            uint32_t ea = js_addr_abs(cpu, 0x033Bu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04978243u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04978243u: {
            const uint32_t source_key = 0x04978243u;
            cpu->pc = 0xF04Bu;
            uint32_t ea = js_addr_abs(cpu, 0x031Cu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0497825Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0497825Bu: {
            const uint32_t source_key = 0x0497825Bu;
            cpu->pc = 0xF04Cu;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04978263u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04978263u: {
            const uint32_t source_key = 0x04978263u;
            cpu->pc = 0xF04Du;
            { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04040203u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0497826Bu: {
            const uint32_t source_key = 0x0497826Bu;
            cpu->pc = 0xF04Fu;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x04978278u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04978278u: {
            const uint32_t source_key = 0x04978278u;
            cpu->pc = 0xF052u;
            uint16_t value = 0x1234u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04978290u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04978290u: {
            const uint32_t source_key = 0x04978290u;
            cpu->pc = 0xF056u;
            uint32_t ea = js_addr_abs_long(0x700000u);
            if (!js_bus_write16(bus, ea, 1, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x049782B0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x049782B0u: {
            const uint32_t source_key = 0x049782B0u;
            cpu->pc = 0xF05Au;
            uint32_t ea = js_addr_abs_long(0x700000u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 1, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x049782D0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x049782D0u: {
            const uint32_t source_key = 0x049782D0u;
            cpu->pc = 0xF05Du;
            uint16_t value = 0x1234u;
            js_op_compare(cpu, cpu->a, value, 16u);
            static const uint32_t allowed[] = { 0x049782E8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x049782E8u: {
            const uint32_t source_key = 0x049782E8u;
            cpu->pc = 0xF05Fu;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (18));
            static const uint32_t allowed[] = { 0x049782F8u, 0x04978388u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x049782F8u: {
            const uint32_t source_key = 0x049782F8u;
            cpu->pc = 0xF062u;
            uint16_t value = 0x5678u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04978310u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04978310u: {
            const uint32_t source_key = 0x04978310u;
            cpu->pc = 0xF066u;
            uint32_t ea = js_addr_abs_long(0x700000u);
            if (!js_bus_write16(bus, ea, 1, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04978330u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04978330u: {
            const uint32_t source_key = 0x04978330u;
            cpu->pc = 0xF06Au;
            uint32_t ea = js_addr_abs_long(0x700000u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 1, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04978350u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04978350u: {
            const uint32_t source_key = 0x04978350u;
            cpu->pc = 0xF06Du;
            uint16_t value = 0x5678u;
            js_op_compare(cpu, cpu->a, value, 16u);
            static const uint32_t allowed[] = { 0x04978368u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04978368u: {
            const uint32_t source_key = 0x04978368u;
            cpu->pc = 0xF06Fu;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (2));
            static const uint32_t allowed[] = { 0x04978378u, 0x04978388u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04978378u: {
            const uint32_t source_key = 0x04978378u;
            cpu->pc = 0xF071u;
            if (js_branch_condition(cpu, 'A')) cpu->pc = (uint16_t)(cpu->pc + (-2));
            static const uint32_t allowed[] = { 0x04978378u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04978388u: {
            const uint32_t source_key = 0x04978388u;
            cpu->pc = 0xF073u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x0497839Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0497839Bu: {
            const uint32_t source_key = 0x0497839Bu;
            cpu->pc = 0xF076u;
            uint32_t ea = js_addr_abs(cpu, 0x0280u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x049783B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x049783B3u: {
            const uint32_t source_key = 0x049783B3u;
            cpu->pc = 0xF079u;
            uint32_t ea = js_addr_abs(cpu, 0x0281u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x049783CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x049783CBu: {
            const uint32_t source_key = 0x049783CBu;
            cpu->pc = 0xF07Cu;
            uint32_t ea = js_addr_abs(cpu, 0x213Fu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x049783E3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x049783E3u: {
            const uint32_t source_key = 0x049783E3u;
            cpu->pc = 0xF07Eu;
            uint16_t value = 0x0010u;
            js_op_bit(cpu, value, 8u, 1);
            static const uint32_t allowed[] = { 0x049783F3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x049783F3u: {
            const uint32_t source_key = 0x049783F3u;
            cpu->pc = 0xF080u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (3));
            static const uint32_t allowed[] = { 0x04978403u, 0x0497841Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04978403u: {
            const uint32_t source_key = 0x04978403u;
            cpu->pc = 0xF083u;
            uint32_t ea = js_addr_abs(cpu, 0x0280u);
            uint16_t original = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
            uint16_t result = js_op_incdec(cpu, original, 1, 8u);
            if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0497841Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0497841Bu: {
            const uint32_t source_key = 0x0497841Bu;
            cpu->pc = 0xF084u;
            { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x0404023Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        default: return JS_EXEC_NOT_MINE;
    }
}
