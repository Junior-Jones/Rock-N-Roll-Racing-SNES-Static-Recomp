#include "v05c_static_cpu.h"

JSExecResult js_v05c_shard_2021(JSCPU *cpu, const JSBus *bus, JSStop *stop) {
    (void)bus;
    (void)stop;
    switch (js_cpu_context_key(cpu)) {
        case 0x0404200Au: {
            const uint32_t source_key = 0x0404200Au;
            cpu->pc = 0x8403u;
            uint32_t ea = js_addr_dp(cpu, 0x35u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0404201Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404201Au: {
            const uint32_t source_key = 0x0404201Au;
            cpu->pc = 0x8405u;
            js_op_rep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x04042028u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042028u: {
            const uint32_t source_key = 0x04042028u;
            cpu->pc = 0x8407u;
            uint32_t ea = js_addr_dp(cpu, 0x30u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042038u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042038u: {
            const uint32_t source_key = 0x04042038u;
            cpu->pc = 0x8409u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (7));
            static const uint32_t allowed[] = { 0x04042048u, 0x04042080u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042048u: {
            const uint32_t source_key = 0x04042048u;
            cpu->pc = 0x840Cu;
            uint16_t value = 0x8000u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042060u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042060u: {
            const uint32_t source_key = 0x04042060u;
            cpu->pc = 0x840Eu;
            uint32_t ea = js_addr_dp(cpu, 0x30u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042070u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042070u: {
            const uint32_t source_key = 0x04042070u;
            cpu->pc = 0x8410u;
            uint32_t ea = js_addr_dp(cpu, 0x32u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042080u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042080u: {
            const uint32_t source_key = 0x04042080u;
            cpu->pc = 0x8413u;
            uint16_t value = 0x0000u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042098u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042098u: {
            const uint32_t source_key = 0x04042098u;
            cpu->pc = 0x8414u;
            cpu->p = (uint8_t)(cpu->p | JS_P_C);
            static const uint32_t allowed[] = { 0x040420A0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040420A0u: {
            const uint32_t source_key = 0x040420A0u;
            cpu->pc = 0x8416u;
            uint32_t ea = js_addr_dp(cpu, 0x34u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_sbc(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040420B0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040420B0u: {
            const uint32_t source_key = 0x040420B0u;
            cpu->pc = 0x8418u;
            uint32_t ea = js_addr_dp(cpu, 0x34u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040420C0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040420C0u: {
            const uint32_t source_key = 0x040420C0u;
            cpu->pc = 0x841Bu;
            uint16_t value = 0x0FFEu;
            js_op_load_y(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040420D8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040420D8u: {
            const uint32_t source_key = 0x040420D8u;
            cpu->pc = 0x841Eu;
            uint16_t value = 0x0000u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040420F0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040420F0u: {
            const uint32_t source_key = 0x040420F0u;
            cpu->pc = 0x8420u;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long_y(cpu, bus, 0x40u, &ea, stop, source_key)) return JS_EXEC_STOP;
            if (!js_bus_write16(bus, ea, 1, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042100u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042100u: {
            const uint32_t source_key = 0x04042100u;
            cpu->pc = 0x8421u;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, -1, 16u), 16u);
            static const uint32_t allowed[] = { 0x04042108u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042108u: {
            const uint32_t source_key = 0x04042108u;
            cpu->pc = 0x8422u;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, -1, 16u), 16u);
            static const uint32_t allowed[] = { 0x04042110u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042110u: {
            const uint32_t source_key = 0x04042110u;
            cpu->pc = 0x8424u;
            if (js_branch_condition(cpu, 'P')) cpu->pc = (uint16_t)(cpu->pc + (-6));
            static const uint32_t allowed[] = { 0x040420F0u, 0x04042120u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042120u: {
            const uint32_t source_key = 0x04042120u;
            cpu->pc = 0x8427u;
            uint16_t value = 0x1000u;
            js_op_load_x(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042138u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042138u: {
            const uint32_t source_key = 0x04042138u;
            cpu->pc = 0x8429u;
            uint32_t ea = js_addr_dp(cpu, 0x44u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042148u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042148u: {
            const uint32_t source_key = 0x04042148u;
            cpu->pc = 0x842Bu;
            uint32_t ea = js_addr_dp(cpu, 0x44u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_lsr(cpu, original, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042158u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042158u: {
            const uint32_t source_key = 0x04042158u;
            cpu->pc = 0x842Du;
            uint32_t ea = js_addr_dp(cpu, 0x44u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042168u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042168u: {
            const uint32_t source_key = 0x04042168u;
            cpu->pc = 0x8430u;
            uint16_t value = 0x0100u;
            js_op_bit(cpu, value, 16u, 1);
            static const uint32_t allowed[] = { 0x04042180u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042180u: {
            const uint32_t source_key = 0x04042180u;
            cpu->pc = 0x8432u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (20));
            static const uint32_t allowed[] = { 0x04042190u, 0x04042230u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042190u: {
            const uint32_t source_key = 0x04042190u;
            cpu->pc = 0x8434u;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long(cpu, bus, 0x30u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 1, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040421A0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040421A0u: {
            const uint32_t source_key = 0x040421A0u;
            cpu->pc = 0x8436u;
            uint32_t ea = js_addr_dp(cpu, 0x30u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040421B0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040421B0u: {
            const uint32_t source_key = 0x040421B0u;
            cpu->pc = 0x8438u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (9));
            static const uint32_t allowed[] = { 0x040421C0u, 0x04042208u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040421C0u: {
            const uint32_t source_key = 0x040421C0u;
            cpu->pc = 0x8439u;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->a, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040421C8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040421C8u: {
            const uint32_t source_key = 0x040421C8u;
            cpu->pc = 0x843Cu;
            uint16_t value = 0x8000u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040421E0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040421E0u: {
            const uint32_t source_key = 0x040421E0u;
            cpu->pc = 0x843Eu;
            uint32_t ea = js_addr_dp(cpu, 0x30u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040421F0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040421F0u: {
            const uint32_t source_key = 0x040421F0u;
            cpu->pc = 0x843Fu;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x040421F8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040421F8u: {
            const uint32_t source_key = 0x040421F8u;
            cpu->pc = 0x8441u;
            uint32_t ea = js_addr_dp(cpu, 0x32u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042208u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042208u: {
            const uint32_t source_key = 0x04042208u;
            cpu->pc = 0x8444u;
            uint16_t value = 0xFF00u;
            js_op_ora(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042220u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042220u: {
            const uint32_t source_key = 0x04042220u;
            cpu->pc = 0x8446u;
            uint32_t ea = js_addr_dp(cpu, 0x44u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042230u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042230u: {
            const uint32_t source_key = 0x04042230u;
            cpu->pc = 0x8447u;
            js_op_load_a(cpu, js_op_lsr(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04042238u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042238u: {
            const uint32_t source_key = 0x04042238u;
            cpu->pc = 0x8449u;
            if (js_branch_condition(cpu, 'C')) cpu->pc = (uint16_t)(cpu->pc + (49));
            static const uint32_t allowed[] = { 0x04042248u, 0x040423D0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042248u: {
            const uint32_t source_key = 0x04042248u;
            cpu->pc = 0x844Bu;
            js_op_sep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x0404225Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404225Au: {
            const uint32_t source_key = 0x0404225Au;
            cpu->pc = 0x844Du;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long(cpu, bus, 0x30u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0404226Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404226Au: {
            const uint32_t source_key = 0x0404226Au;
            cpu->pc = 0x844Fu;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long(cpu, bus, 0x3Cu, &ea, stop, source_key)) return JS_EXEC_STOP;
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0404227Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404227Au: {
            const uint32_t source_key = 0x0404227Au;
            cpu->pc = 0x8452u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x84E0u;
            static const uint32_t allowed[] = { 0x04042702u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042292u: {
            const uint32_t source_key = 0x04042292u;
            cpu->pc = 0x8454u;
            js_op_rep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x040422A0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040422A0u: {
            const uint32_t source_key = 0x040422A0u;
            cpu->pc = 0x8456u;
            uint32_t ea = js_addr_dp(cpu, 0x34u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040422B0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040422B0u: {
            const uint32_t source_key = 0x040422B0u;
            cpu->pc = 0x8458u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (1));
            static const uint32_t allowed[] = { 0x040422C0u, 0x040422C8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040422C0u: {
            const uint32_t source_key = 0x040422C0u;
            cpu->pc = 0x8459u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x04041BA0u, 0x04041E28u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040422C8u: {
            const uint32_t source_key = 0x040422C8u;
            cpu->pc = 0x845Bu;
            uint32_t ea = js_addr_dp(cpu, 0x30u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040422D8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040422D8u: {
            const uint32_t source_key = 0x040422D8u;
            cpu->pc = 0x845Du;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (11));
            static const uint32_t allowed[] = { 0x040422E8u, 0x04042340u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040422E8u: {
            const uint32_t source_key = 0x040422E8u;
            cpu->pc = 0x845Eu;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->a, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040422F0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040422F0u: {
            const uint32_t source_key = 0x040422F0u;
            cpu->pc = 0x8460u;
            uint32_t ea = js_addr_dp(cpu, 0x30u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042300u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042300u: {
            const uint32_t source_key = 0x04042300u;
            cpu->pc = 0x8463u;
            uint16_t value = 0x8000u;
            js_op_ora(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042318u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042318u: {
            const uint32_t source_key = 0x04042318u;
            cpu->pc = 0x8465u;
            uint32_t ea = js_addr_dp(cpu, 0x30u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042328u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042328u: {
            const uint32_t source_key = 0x04042328u;
            cpu->pc = 0x8466u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x04042330u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042330u: {
            const uint32_t source_key = 0x04042330u;
            cpu->pc = 0x8468u;
            uint32_t ea = js_addr_dp(cpu, 0x32u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042340u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042340u: {
            const uint32_t source_key = 0x04042340u;
            cpu->pc = 0x846Au;
            uint32_t ea = js_addr_dp(cpu, 0x3Cu);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042350u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042350u: {
            const uint32_t source_key = 0x04042350u;
            cpu->pc = 0x846Cu;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (2));
            static const uint32_t allowed[] = { 0x04042360u, 0x04042370u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042360u: {
            const uint32_t source_key = 0x04042360u;
            cpu->pc = 0x846Eu;
            uint32_t ea = js_addr_dp(cpu, 0x3Eu);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042370u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042370u: {
            const uint32_t source_key = 0x04042370u;
            cpu->pc = 0x846Fu;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, -1, 16u), 16u);
            static const uint32_t allowed[] = { 0x04042378u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042378u: {
            const uint32_t source_key = 0x04042378u;
            cpu->pc = 0x8471u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-72));
            static const uint32_t allowed[] = { 0x04042148u, 0x04042388u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042388u: {
            const uint32_t source_key = 0x04042388u;
            cpu->pc = 0x8474u;
            uint16_t value = 0x1000u;
            js_op_load_x(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040423A0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040423A0u: {
            const uint32_t source_key = 0x040423A0u;
            cpu->pc = 0x8476u;
            uint32_t ea = js_addr_stack_rel(cpu, 0x05u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040423B0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040423B0u: {
            const uint32_t source_key = 0x040423B0u;
            cpu->pc = 0x8478u;
            uint32_t ea = js_addr_dp(cpu, 0x3Cu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040423C0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040423C0u: {
            const uint32_t source_key = 0x040423C0u;
            cpu->pc = 0x847Au;
            if (js_branch_condition(cpu, 'A')) cpu->pc = (uint16_t)(cpu->pc + (-81));
            static const uint32_t allowed[] = { 0x04042148u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040423D0u: {
            const uint32_t source_key = 0x040423D0u;
            cpu->pc = 0x847Cu;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long(cpu, bus, 0x30u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 1, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040423E0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040423E0u: {
            const uint32_t source_key = 0x040423E0u;
            cpu->pc = 0x847Eu;
            uint32_t ea = js_addr_dp(cpu, 0xA2u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040423F0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040423F0u: {
            const uint32_t source_key = 0x040423F0u;
            cpu->pc = 0x8480u;
            uint32_t ea = js_addr_dp(cpu, 0x30u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042400u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042400u: {
            const uint32_t source_key = 0x04042400u;
            cpu->pc = 0x8482u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (7));
            static const uint32_t allowed[] = { 0x04042410u, 0x04042448u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042410u: {
            const uint32_t source_key = 0x04042410u;
            cpu->pc = 0x8485u;
            uint16_t value = 0x8000u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042428u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042428u: {
            const uint32_t source_key = 0x04042428u;
            cpu->pc = 0x8487u;
            uint32_t ea = js_addr_dp(cpu, 0x30u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042438u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042438u: {
            const uint32_t source_key = 0x04042438u;
            cpu->pc = 0x8489u;
            uint32_t ea = js_addr_dp(cpu, 0x32u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042448u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042448u: {
            const uint32_t source_key = 0x04042448u;
            cpu->pc = 0x848Bu;
            js_op_sep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x0404245Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404245Au: {
            const uint32_t source_key = 0x0404245Au;
            cpu->pc = 0x848Du;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long(cpu, bus, 0x30u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0404246Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404246Au: {
            const uint32_t source_key = 0x0404246Au;
            cpu->pc = 0x848Fu;
            uint32_t ea = js_addr_dp(cpu, 0xA3u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0404247Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404247Au: {
            const uint32_t source_key = 0x0404247Au;
            cpu->pc = 0x8491u;
            js_op_rep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x04042488u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042488u: {
            const uint32_t source_key = 0x04042488u;
            cpu->pc = 0x8493u;
            uint32_t ea = js_addr_dp(cpu, 0x30u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042498u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042498u: {
            const uint32_t source_key = 0x04042498u;
            cpu->pc = 0x8495u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (7));
            static const uint32_t allowed[] = { 0x040424A8u, 0x040424E0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040424A8u: {
            const uint32_t source_key = 0x040424A8u;
            cpu->pc = 0x8498u;
            uint16_t value = 0x8000u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040424C0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040424C0u: {
            const uint32_t source_key = 0x040424C0u;
            cpu->pc = 0x849Au;
            uint32_t ea = js_addr_dp(cpu, 0x30u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040424D0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040424D0u: {
            const uint32_t source_key = 0x040424D0u;
            cpu->pc = 0x849Cu;
            uint32_t ea = js_addr_dp(cpu, 0x32u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040424E0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040424E0u: {
            const uint32_t source_key = 0x040424E0u;
            cpu->pc = 0x849Eu;
            uint32_t ea = js_addr_dp(cpu, 0xA2u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040424F0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040424F0u: {
            const uint32_t source_key = 0x040424F0u;
            cpu->pc = 0x84A1u;
            uint16_t value = 0x0FFFu;
            js_op_and(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042508u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042508u: {
            const uint32_t source_key = 0x04042508u;
            cpu->pc = 0x84A2u;
            js_op_transfer(cpu, 'B');
            static const uint32_t allowed[] = { 0x04042510u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042510u: {
            const uint32_t source_key = 0x04042510u;
            cpu->pc = 0x84A4u;
            uint32_t ea = js_addr_dp(cpu, 0xA2u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042520u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042520u: {
            const uint32_t source_key = 0x04042520u;
            cpu->pc = 0x84A7u;
            uint16_t value = 0xF000u;
            js_op_and(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042538u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042538u: {
            const uint32_t source_key = 0x04042538u;
            cpu->pc = 0x84A8u;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04042540u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042540u: {
            const uint32_t source_key = 0x04042540u;
            cpu->pc = 0x84A9u;
            js_op_load_a(cpu, js_op_rol(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04042548u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042548u: {
            const uint32_t source_key = 0x04042548u;
            cpu->pc = 0x84AAu;
            js_op_load_a(cpu, js_op_rol(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04042550u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042550u: {
            const uint32_t source_key = 0x04042550u;
            cpu->pc = 0x84ABu;
            js_op_load_a(cpu, js_op_rol(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04042558u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042558u: {
            const uint32_t source_key = 0x04042558u;
            cpu->pc = 0x84ACu;
            js_op_load_a(cpu, js_op_rol(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04042560u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042560u: {
            const uint32_t source_key = 0x04042560u;
            cpu->pc = 0x84AFu;
            uint16_t value = 0x0003u;
            js_op_adc(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042578u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042578u: {
            const uint32_t source_key = 0x04042578u;
            cpu->pc = 0x84B1u;
            uint32_t ea = js_addr_dp(cpu, 0x8Eu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042588u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042588u: {
            const uint32_t source_key = 0x04042588u;
            cpu->pc = 0x84B3u;
            js_op_sep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x0404259Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404259Au: {
            const uint32_t source_key = 0x0404259Au;
            cpu->pc = 0x84B5u;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long_y(cpu, bus, 0x40u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040425AAu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040425AAu: {
            const uint32_t source_key = 0x040425AAu;
            cpu->pc = 0x84B7u;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long(cpu, bus, 0x3Cu, &ea, stop, source_key)) return JS_EXEC_STOP;
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040425BAu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040425BAu: {
            const uint32_t source_key = 0x040425BAu;
            cpu->pc = 0x84BAu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x84E0u;
            static const uint32_t allowed[] = { 0x04042702u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040425D2u: {
            const uint32_t source_key = 0x040425D2u;
            cpu->pc = 0x84BCu;
            js_op_rep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x040425E0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040425E0u: {
            const uint32_t source_key = 0x040425E0u;
            cpu->pc = 0x84BEu;
            uint32_t ea = js_addr_dp(cpu, 0x34u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040425F0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040425F0u: {
            const uint32_t source_key = 0x040425F0u;
            cpu->pc = 0x84C0u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (-104));
            static const uint32_t allowed[] = { 0x040422C0u, 0x04042600u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042600u: {
            const uint32_t source_key = 0x04042600u;
            cpu->pc = 0x84C2u;
            uint32_t ea = js_addr_dp(cpu, 0x3Cu);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042610u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042610u: {
            const uint32_t source_key = 0x04042610u;
            cpu->pc = 0x84C4u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (2));
            static const uint32_t allowed[] = { 0x04042620u, 0x04042630u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042620u: {
            const uint32_t source_key = 0x04042620u;
            cpu->pc = 0x84C6u;
            uint32_t ea = js_addr_dp(cpu, 0x3Eu);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042630u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042630u: {
            const uint32_t source_key = 0x04042630u;
            cpu->pc = 0x84C7u;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x04042638u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042638u: {
            const uint32_t source_key = 0x04042638u;
            cpu->pc = 0x84CAu;
            uint16_t value = 0x1000u;
            js_op_compare(cpu, cpu->y, value, 16u);
            static const uint32_t allowed[] = { 0x04042650u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042650u: {
            const uint32_t source_key = 0x04042650u;
            cpu->pc = 0x84CCu;
            if (js_branch_condition(cpu, 'C')) cpu->pc = (uint16_t)(cpu->pc + (3));
            static const uint32_t allowed[] = { 0x04042660u, 0x04042678u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042660u: {
            const uint32_t source_key = 0x04042660u;
            cpu->pc = 0x84CFu;
            uint16_t value = 0x0000u;
            js_op_load_y(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042678u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042678u: {
            const uint32_t source_key = 0x04042678u;
            cpu->pc = 0x84D0u;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, -1, 16u), 16u);
            static const uint32_t allowed[] = { 0x04042680u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042680u: {
            const uint32_t source_key = 0x04042680u;
            cpu->pc = 0x84D2u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (7));
            static const uint32_t allowed[] = { 0x04042690u, 0x040426C8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042690u: {
            const uint32_t source_key = 0x04042690u;
            cpu->pc = 0x84D5u;
            uint16_t value = 0x1000u;
            js_op_load_x(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040426A8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040426A8u: {
            const uint32_t source_key = 0x040426A8u;
            cpu->pc = 0x84D7u;
            uint32_t ea = js_addr_stack_rel(cpu, 0x05u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040426B8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040426B8u: {
            const uint32_t source_key = 0x040426B8u;
            cpu->pc = 0x84D9u;
            uint32_t ea = js_addr_dp(cpu, 0x3Cu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040426C8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040426C8u: {
            const uint32_t source_key = 0x040426C8u;
            cpu->pc = 0x84DBu;
            uint32_t ea = js_addr_dp(cpu, 0x8Eu);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, -1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040426D8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040426D8u: {
            const uint32_t source_key = 0x040426D8u;
            cpu->pc = 0x84DDu;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-44));
            static const uint32_t allowed[] = { 0x04042588u, 0x040426E8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040426E8u: {
            const uint32_t source_key = 0x040426E8u;
            cpu->pc = 0x84E0u;
            cpu->pc = 0x8429u;
            static const uint32_t allowed[] = { 0x04042148u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042702u: {
            const uint32_t source_key = 0x04042702u;
            cpu->pc = 0x84E1u;
            if (!js_stack_push8(cpu, bus, (uint8_t)cpu->a, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0404270Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404270Au: {
            const uint32_t source_key = 0x0404270Au;
            cpu->pc = 0x84E3u;
            uint32_t ea = js_addr_dp(cpu, 0x02u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0404271Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404271Au: {
            const uint32_t source_key = 0x0404271Au;
            cpu->pc = 0x84E5u;
            uint16_t value = 0x0001u;
            js_op_eor(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0404272Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404272Au: {
            const uint32_t source_key = 0x0404272Au;
            cpu->pc = 0x84E7u;
            uint32_t ea = js_addr_dp(cpu, 0x02u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0404273Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404273Au: {
            const uint32_t source_key = 0x0404273Au;
            cpu->pc = 0x84E9u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (4));
            static const uint32_t allowed[] = { 0x0404274Au, 0x0404276Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404274Au: {
            const uint32_t source_key = 0x0404274Au;
            cpu->pc = 0x84EAu;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 8u); }
            static const uint32_t allowed[] = { 0x04042752u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042752u: {
            const uint32_t source_key = 0x04042752u;
            cpu->pc = 0x84ECu;
            uint32_t ea = js_addr_dp(cpu, 0x03u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042762u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042762u: {
            const uint32_t source_key = 0x04042762u;
            cpu->pc = 0x84EDu;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x04042292u, 0x040425D2u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404276Au: {
            const uint32_t source_key = 0x0404276Au;
            cpu->pc = 0x84EFu;
            uint32_t ea = js_addr_dp(cpu, 0x03u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0404277Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404277Au: {
            const uint32_t source_key = 0x0404277Au;
            cpu->pc = 0x84F2u;
            uint32_t ea = js_addr_abs(cpu, 0x2118u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042792u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042792u: {
            const uint32_t source_key = 0x04042792u;
            cpu->pc = 0x84F3u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 8u); }
            static const uint32_t allowed[] = { 0x0404279Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404279Au: {
            const uint32_t source_key = 0x0404279Au;
            cpu->pc = 0x84F6u;
            uint32_t ea = js_addr_abs(cpu, 0x2119u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040427B2u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040427B2u: {
            const uint32_t source_key = 0x040427B2u;
            cpu->pc = 0x84F7u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x04042292u, 0x040425D2u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042960u: {
            const uint32_t source_key = 0x04042960u;
            cpu->pc = 0x852Fu;
            uint16_t value = 0x007Eu;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042978u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042978u: {
            const uint32_t source_key = 0x04042978u;
            cpu->pc = 0x8531u;
            uint32_t ea = js_addr_dp(cpu, 0x3Au);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042988u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042988u: {
            const uint32_t source_key = 0x04042988u;
            cpu->pc = 0x8533u;
            uint32_t ea = js_addr_stack_rel(cpu, 0x07u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042998u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042998u: {
            const uint32_t source_key = 0x04042998u;
            cpu->pc = 0x8535u;
            uint32_t ea = js_addr_dp(cpu, 0x38u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040429A8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040429A8u: {
            const uint32_t source_key = 0x040429A8u;
            cpu->pc = 0x8537u;
            uint32_t ea = js_addr_stack_rel(cpu, 0x09u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040429B8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040429B8u: {
            const uint32_t source_key = 0x040429B8u;
            cpu->pc = 0x8539u;
            uint32_t ea = js_addr_dp(cpu, 0x30u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040429C8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040429C8u: {
            const uint32_t source_key = 0x040429C8u;
            cpu->pc = 0x853Bu;
            uint32_t ea = js_addr_stack_rel(cpu, 0x0Bu);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040429D8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040429D8u: {
            const uint32_t source_key = 0x040429D8u;
            cpu->pc = 0x853Du;
            uint32_t ea = js_addr_dp(cpu, 0x32u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040429E8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040429E8u: {
            const uint32_t source_key = 0x040429E8u;
            cpu->pc = 0x853Fu;
            uint32_t ea = js_addr_stack_rel(cpu, 0x05u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040429F8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040429F8u: {
            const uint32_t source_key = 0x040429F8u;
            cpu->pc = 0x8541u;
            uint32_t ea = js_addr_dp(cpu, 0x40u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042A08u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042A08u: {
            const uint32_t source_key = 0x04042A08u;
            cpu->pc = 0x8543u;
            uint32_t ea = js_addr_dp(cpu, 0x3Cu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042A18u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042A18u: {
            const uint32_t source_key = 0x04042A18u;
            cpu->pc = 0x8546u;
            uint16_t value = 0x007Eu;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042A30u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042A30u: {
            const uint32_t source_key = 0x04042A30u;
            cpu->pc = 0x8548u;
            uint32_t ea = js_addr_dp(cpu, 0x42u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042A40u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042A40u: {
            const uint32_t source_key = 0x04042A40u;
            cpu->pc = 0x854Au;
            uint32_t ea = js_addr_dp(cpu, 0x3Eu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042A50u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042A50u: {
            const uint32_t source_key = 0x04042A50u;
            cpu->pc = 0x854Cu;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long(cpu, bus, 0x30u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 1, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042A60u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042A60u: {
            const uint32_t source_key = 0x04042A60u;
            cpu->pc = 0x854Eu;
            uint32_t ea = js_addr_dp(cpu, 0x30u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042A70u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042A70u: {
            const uint32_t source_key = 0x04042A70u;
            cpu->pc = 0x8550u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (7));
            static const uint32_t allowed[] = { 0x04042A80u, 0x04042AB8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042A80u: {
            const uint32_t source_key = 0x04042A80u;
            cpu->pc = 0x8553u;
            uint16_t value = 0x8000u;
            js_op_load_y(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042A98u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042A98u: {
            const uint32_t source_key = 0x04042A98u;
            cpu->pc = 0x8555u;
            uint32_t ea = js_addr_dp(cpu, 0x30u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_y(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042AA8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042AA8u: {
            const uint32_t source_key = 0x04042AA8u;
            cpu->pc = 0x8557u;
            uint32_t ea = js_addr_dp(cpu, 0x32u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042AB8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042AB8u: {
            const uint32_t source_key = 0x04042AB8u;
            cpu->pc = 0x8559u;
            uint32_t ea = js_addr_dp(cpu, 0x34u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042AC8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042AC8u: {
            const uint32_t source_key = 0x04042AC8u;
            cpu->pc = 0x855Bu;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long(cpu, bus, 0x30u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 1, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042AD8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042AD8u: {
            const uint32_t source_key = 0x04042AD8u;
            cpu->pc = 0x855Du;
            uint32_t ea = js_addr_dp(cpu, 0x30u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042AE8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042AE8u: {
            const uint32_t source_key = 0x04042AE8u;
            cpu->pc = 0x855Fu;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (7));
            static const uint32_t allowed[] = { 0x04042AF8u, 0x04042B30u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042AF8u: {
            const uint32_t source_key = 0x04042AF8u;
            cpu->pc = 0x8562u;
            uint16_t value = 0x8000u;
            js_op_load_y(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042B10u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042B10u: {
            const uint32_t source_key = 0x04042B10u;
            cpu->pc = 0x8564u;
            uint32_t ea = js_addr_dp(cpu, 0x30u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_y(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042B20u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042B20u: {
            const uint32_t source_key = 0x04042B20u;
            cpu->pc = 0x8566u;
            uint32_t ea = js_addr_dp(cpu, 0x32u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042B30u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042B30u: {
            const uint32_t source_key = 0x04042B30u;
            cpu->pc = 0x8568u;
            js_op_sep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x04042B42u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042B42u: {
            const uint32_t source_key = 0x04042B42u;
            cpu->pc = 0x856Au;
            uint32_t ea = js_addr_dp(cpu, 0x35u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042B52u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042B52u: {
            const uint32_t source_key = 0x04042B52u;
            cpu->pc = 0x856Cu;
            js_op_rep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x04042B60u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042B60u: {
            const uint32_t source_key = 0x04042B60u;
            cpu->pc = 0x856Fu;
            uint16_t value = 0x0FFEu;
            js_op_load_y(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042B78u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042B78u: {
            const uint32_t source_key = 0x04042B78u;
            cpu->pc = 0x8572u;
            uint16_t value = 0x0000u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042B90u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042B90u: {
            const uint32_t source_key = 0x04042B90u;
            cpu->pc = 0x8574u;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long_y(cpu, bus, 0x40u, &ea, stop, source_key)) return JS_EXEC_STOP;
            if (!js_bus_write16(bus, ea, 1, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042BA0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042BA0u: {
            const uint32_t source_key = 0x04042BA0u;
            cpu->pc = 0x8575u;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, -1, 16u), 16u);
            static const uint32_t allowed[] = { 0x04042BA8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042BA8u: {
            const uint32_t source_key = 0x04042BA8u;
            cpu->pc = 0x8576u;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, -1, 16u), 16u);
            static const uint32_t allowed[] = { 0x04042BB0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042BB0u: {
            const uint32_t source_key = 0x04042BB0u;
            cpu->pc = 0x8578u;
            if (js_branch_condition(cpu, 'P')) cpu->pc = (uint16_t)(cpu->pc + (-6));
            static const uint32_t allowed[] = { 0x04042B90u, 0x04042BC0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042BC0u: {
            const uint32_t source_key = 0x04042BC0u;
            cpu->pc = 0x857Bu;
            uint16_t value = 0x1000u;
            js_op_load_x(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042BD8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042BD8u: {
            const uint32_t source_key = 0x04042BD8u;
            cpu->pc = 0x857Du;
            uint32_t ea = js_addr_dp(cpu, 0x44u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042BE8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042BE8u: {
            const uint32_t source_key = 0x04042BE8u;
            cpu->pc = 0x857Fu;
            uint32_t ea = js_addr_dp(cpu, 0x44u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042BF8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042BF8u: {
            const uint32_t source_key = 0x04042BF8u;
            cpu->pc = 0x8580u;
            js_op_load_a(cpu, js_op_lsr(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04042C00u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042C00u: {
            const uint32_t source_key = 0x04042C00u;
            cpu->pc = 0x8582u;
            uint32_t ea = js_addr_dp(cpu, 0x44u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042C10u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042C10u: {
            const uint32_t source_key = 0x04042C10u;
            cpu->pc = 0x8585u;
            uint16_t value = 0x0100u;
            js_op_bit(cpu, value, 16u, 1);
            static const uint32_t allowed[] = { 0x04042C28u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042C28u: {
            const uint32_t source_key = 0x04042C28u;
            cpu->pc = 0x8587u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (18));
            static const uint32_t allowed[] = { 0x04042C38u, 0x04042CC8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042C38u: {
            const uint32_t source_key = 0x04042C38u;
            cpu->pc = 0x8589u;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long(cpu, bus, 0x30u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 1, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042C48u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042C48u: {
            const uint32_t source_key = 0x04042C48u;
            cpu->pc = 0x858Bu;
            uint32_t ea = js_addr_dp(cpu, 0x30u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042C58u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042C58u: {
            const uint32_t source_key = 0x04042C58u;
            cpu->pc = 0x858Du;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (7));
            static const uint32_t allowed[] = { 0x04042C68u, 0x04042CA0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042C68u: {
            const uint32_t source_key = 0x04042C68u;
            cpu->pc = 0x8590u;
            uint16_t value = 0x8000u;
            js_op_load_y(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042C80u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042C80u: {
            const uint32_t source_key = 0x04042C80u;
            cpu->pc = 0x8592u;
            uint32_t ea = js_addr_dp(cpu, 0x30u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_y(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042C90u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042C90u: {
            const uint32_t source_key = 0x04042C90u;
            cpu->pc = 0x8594u;
            uint32_t ea = js_addr_dp(cpu, 0x32u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042CA0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042CA0u: {
            const uint32_t source_key = 0x04042CA0u;
            cpu->pc = 0x8597u;
            uint16_t value = 0xFF00u;
            js_op_ora(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042CB8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042CB8u: {
            const uint32_t source_key = 0x04042CB8u;
            cpu->pc = 0x8599u;
            uint32_t ea = js_addr_dp(cpu, 0x44u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042CC8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042CC8u: {
            const uint32_t source_key = 0x04042CC8u;
            cpu->pc = 0x859Au;
            js_op_load_a(cpu, js_op_lsr(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04042CD0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042CD0u: {
            const uint32_t source_key = 0x04042CD0u;
            cpu->pc = 0x859Cu;
            if (js_branch_condition(cpu, 'C')) cpu->pc = (uint16_t)(cpu->pc + (50));
            static const uint32_t allowed[] = { 0x04042CE0u, 0x04042E70u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042CE0u: {
            const uint32_t source_key = 0x04042CE0u;
            cpu->pc = 0x859Eu;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long(cpu, bus, 0x30u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 1, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042CF0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042CF0u: {
            const uint32_t source_key = 0x04042CF0u;
            cpu->pc = 0x85A0u;
            uint32_t ea = js_addr_dp(cpu, 0x30u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042D00u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042D00u: {
            const uint32_t source_key = 0x04042D00u;
            cpu->pc = 0x85A2u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (7));
            static const uint32_t allowed[] = { 0x04042D10u, 0x04042D48u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042D10u: {
            const uint32_t source_key = 0x04042D10u;
            cpu->pc = 0x85A5u;
            uint16_t value = 0x8000u;
            js_op_load_y(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042D28u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042D28u: {
            const uint32_t source_key = 0x04042D28u;
            cpu->pc = 0x85A7u;
            uint32_t ea = js_addr_dp(cpu, 0x30u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_y(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042D38u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042D38u: {
            const uint32_t source_key = 0x04042D38u;
            cpu->pc = 0x85A9u;
            uint32_t ea = js_addr_dp(cpu, 0x32u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042D48u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042D48u: {
            const uint32_t source_key = 0x04042D48u;
            cpu->pc = 0x85ABu;
            js_op_sep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x04042D5Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042D5Au: {
            const uint32_t source_key = 0x04042D5Au;
            cpu->pc = 0x85ADu;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long(cpu, bus, 0x38u, &ea, stop, source_key)) return JS_EXEC_STOP;
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042D6Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042D6Au: {
            const uint32_t source_key = 0x04042D6Au;
            cpu->pc = 0x85AFu;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long(cpu, bus, 0x3Cu, &ea, stop, source_key)) return JS_EXEC_STOP;
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042D7Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042D7Au: {
            const uint32_t source_key = 0x04042D7Au;
            cpu->pc = 0x85B1u;
            js_op_rep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x04042D88u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042D88u: {
            const uint32_t source_key = 0x04042D88u;
            cpu->pc = 0x85B3u;
            uint32_t ea = js_addr_dp(cpu, 0x34u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, -1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042D98u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042D98u: {
            const uint32_t source_key = 0x04042D98u;
            cpu->pc = 0x85B5u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (1));
            static const uint32_t allowed[] = { 0x04042DA8u, 0x04042DB0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042DA8u: {
            const uint32_t source_key = 0x04042DA8u;
            cpu->pc = 0x85B6u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x04041890u, 0x04041E00u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042DB0u: {
            const uint32_t source_key = 0x04042DB0u;
            cpu->pc = 0x85B8u;
            uint32_t ea = js_addr_dp(cpu, 0x38u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042DC0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042DC0u: {
            const uint32_t source_key = 0x04042DC0u;
            cpu->pc = 0x85BAu;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (2));
            static const uint32_t allowed[] = { 0x04042DD0u, 0x04042DE0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042DD0u: {
            const uint32_t source_key = 0x04042DD0u;
            cpu->pc = 0x85BCu;
            uint32_t ea = js_addr_dp(cpu, 0x3Au);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042DE0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042DE0u: {
            const uint32_t source_key = 0x04042DE0u;
            cpu->pc = 0x85BEu;
            uint32_t ea = js_addr_dp(cpu, 0x3Cu);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042DF0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042DF0u: {
            const uint32_t source_key = 0x04042DF0u;
            cpu->pc = 0x85C0u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (2));
            static const uint32_t allowed[] = { 0x04042E00u, 0x04042E10u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042E00u: {
            const uint32_t source_key = 0x04042E00u;
            cpu->pc = 0x85C2u;
            uint32_t ea = js_addr_dp(cpu, 0x3Eu);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042E10u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042E10u: {
            const uint32_t source_key = 0x04042E10u;
            cpu->pc = 0x85C3u;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, -1, 16u), 16u);
            static const uint32_t allowed[] = { 0x04042E18u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042E18u: {
            const uint32_t source_key = 0x04042E18u;
            cpu->pc = 0x85C5u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-72));
            static const uint32_t allowed[] = { 0x04042BE8u, 0x04042E28u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042E28u: {
            const uint32_t source_key = 0x04042E28u;
            cpu->pc = 0x85C8u;
            uint16_t value = 0x1000u;
            js_op_load_x(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042E40u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042E40u: {
            const uint32_t source_key = 0x04042E40u;
            cpu->pc = 0x85CAu;
            uint32_t ea = js_addr_stack_rel(cpu, 0x05u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042E50u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042E50u: {
            const uint32_t source_key = 0x04042E50u;
            cpu->pc = 0x85CCu;
            uint32_t ea = js_addr_dp(cpu, 0x3Cu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042E60u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042E60u: {
            const uint32_t source_key = 0x04042E60u;
            cpu->pc = 0x85CEu;
            if (js_branch_condition(cpu, 'A')) cpu->pc = (uint16_t)(cpu->pc + (-81));
            static const uint32_t allowed[] = { 0x04042BE8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042E70u: {
            const uint32_t source_key = 0x04042E70u;
            cpu->pc = 0x85D0u;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long(cpu, bus, 0x30u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 1, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042E80u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042E80u: {
            const uint32_t source_key = 0x04042E80u;
            cpu->pc = 0x85D2u;
            uint32_t ea = js_addr_dp(cpu, 0x30u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042E90u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042E90u: {
            const uint32_t source_key = 0x04042E90u;
            cpu->pc = 0x85D4u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (7));
            static const uint32_t allowed[] = { 0x04042EA0u, 0x04042ED8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042EA0u: {
            const uint32_t source_key = 0x04042EA0u;
            cpu->pc = 0x85D7u;
            uint16_t value = 0x8000u;
            js_op_load_y(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042EB8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042EB8u: {
            const uint32_t source_key = 0x04042EB8u;
            cpu->pc = 0x85D9u;
            uint32_t ea = js_addr_dp(cpu, 0x30u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_y(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042EC8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042EC8u: {
            const uint32_t source_key = 0x04042EC8u;
            cpu->pc = 0x85DBu;
            uint32_t ea = js_addr_dp(cpu, 0x32u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042ED8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042ED8u: {
            const uint32_t source_key = 0x04042ED8u;
            cpu->pc = 0x85DDu;
            uint32_t ea = js_addr_dp(cpu, 0xA2u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042EE8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042EE8u: {
            const uint32_t source_key = 0x04042EE8u;
            cpu->pc = 0x85DFu;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long(cpu, bus, 0x30u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 1, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042EF8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042EF8u: {
            const uint32_t source_key = 0x04042EF8u;
            cpu->pc = 0x85E1u;
            uint32_t ea = js_addr_dp(cpu, 0x30u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042F08u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042F08u: {
            const uint32_t source_key = 0x04042F08u;
            cpu->pc = 0x85E3u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (7));
            static const uint32_t allowed[] = { 0x04042F18u, 0x04042F50u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042F18u: {
            const uint32_t source_key = 0x04042F18u;
            cpu->pc = 0x85E6u;
            uint16_t value = 0x8000u;
            js_op_load_y(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042F30u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042F30u: {
            const uint32_t source_key = 0x04042F30u;
            cpu->pc = 0x85E8u;
            uint32_t ea = js_addr_dp(cpu, 0x30u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_y(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042F40u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042F40u: {
            const uint32_t source_key = 0x04042F40u;
            cpu->pc = 0x85EAu;
            uint32_t ea = js_addr_dp(cpu, 0x32u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042F50u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042F50u: {
            const uint32_t source_key = 0x04042F50u;
            cpu->pc = 0x85ECu;
            js_op_sep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x04042F62u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042F62u: {
            const uint32_t source_key = 0x04042F62u;
            cpu->pc = 0x85EEu;
            uint32_t ea = js_addr_dp(cpu, 0xA3u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04042F72u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042F72u: {
            const uint32_t source_key = 0x04042F72u;
            cpu->pc = 0x85F0u;
            js_op_rep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x04042F80u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042F80u: {
            const uint32_t source_key = 0x04042F80u;
            cpu->pc = 0x85F2u;
            uint32_t ea = js_addr_dp(cpu, 0xA2u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042F90u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042F90u: {
            const uint32_t source_key = 0x04042F90u;
            cpu->pc = 0x85F5u;
            uint16_t value = 0x0FFFu;
            js_op_and(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042FA8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042FA8u: {
            const uint32_t source_key = 0x04042FA8u;
            cpu->pc = 0x85F6u;
            js_op_transfer(cpu, 'B');
            static const uint32_t allowed[] = { 0x04042FB0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042FB0u: {
            const uint32_t source_key = 0x04042FB0u;
            cpu->pc = 0x85F8u;
            uint32_t ea = js_addr_dp(cpu, 0xA2u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042FC0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042FC0u: {
            const uint32_t source_key = 0x04042FC0u;
            cpu->pc = 0x85FBu;
            uint16_t value = 0xF000u;
            js_op_and(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04042FD8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042FD8u: {
            const uint32_t source_key = 0x04042FD8u;
            cpu->pc = 0x85FCu;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04042FE0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042FE0u: {
            const uint32_t source_key = 0x04042FE0u;
            cpu->pc = 0x85FDu;
            js_op_load_a(cpu, js_op_rol(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04042FE8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042FE8u: {
            const uint32_t source_key = 0x04042FE8u;
            cpu->pc = 0x85FEu;
            js_op_load_a(cpu, js_op_rol(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04042FF0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042FF0u: {
            const uint32_t source_key = 0x04042FF0u;
            cpu->pc = 0x85FFu;
            js_op_load_a(cpu, js_op_rol(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04042FF8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04042FF8u: {
            const uint32_t source_key = 0x04042FF8u;
            cpu->pc = 0x8600u;
            js_op_load_a(cpu, js_op_rol(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04043000u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04043000u: {
            const uint32_t source_key = 0x04043000u;
            cpu->pc = 0x8603u;
            uint16_t value = 0x0003u;
            js_op_adc(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04043018u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04043018u: {
            const uint32_t source_key = 0x04043018u;
            cpu->pc = 0x8605u;
            uint32_t ea = js_addr_dp(cpu, 0x8Eu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04043028u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04043028u: {
            const uint32_t source_key = 0x04043028u;
            cpu->pc = 0x8607u;
            js_op_sep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x0404303Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404303Au: {
            const uint32_t source_key = 0x0404303Au;
            cpu->pc = 0x8609u;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long_y(cpu, bus, 0x40u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0404304Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404304Au: {
            const uint32_t source_key = 0x0404304Au;
            cpu->pc = 0x860Bu;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long(cpu, bus, 0x38u, &ea, stop, source_key)) return JS_EXEC_STOP;
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0404305Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404305Au: {
            const uint32_t source_key = 0x0404305Au;
            cpu->pc = 0x860Du;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long(cpu, bus, 0x3Cu, &ea, stop, source_key)) return JS_EXEC_STOP;
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0404306Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404306Au: {
            const uint32_t source_key = 0x0404306Au;
            cpu->pc = 0x860Fu;
            js_op_rep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x04043078u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04043078u: {
            const uint32_t source_key = 0x04043078u;
            cpu->pc = 0x8611u;
            uint32_t ea = js_addr_dp(cpu, 0x34u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, -1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04043088u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04043088u: {
            const uint32_t source_key = 0x04043088u;
            cpu->pc = 0x8613u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (-94));
            static const uint32_t allowed[] = { 0x04042DA8u, 0x04043098u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04043098u: {
            const uint32_t source_key = 0x04043098u;
            cpu->pc = 0x8615u;
            uint32_t ea = js_addr_dp(cpu, 0x38u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040430A8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040430A8u: {
            const uint32_t source_key = 0x040430A8u;
            cpu->pc = 0x8617u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (2));
            static const uint32_t allowed[] = { 0x040430B8u, 0x040430C8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040430B8u: {
            const uint32_t source_key = 0x040430B8u;
            cpu->pc = 0x8619u;
            uint32_t ea = js_addr_dp(cpu, 0x3Au);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040430C8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040430C8u: {
            const uint32_t source_key = 0x040430C8u;
            cpu->pc = 0x861Bu;
            uint32_t ea = js_addr_dp(cpu, 0x3Cu);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040430D8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040430D8u: {
            const uint32_t source_key = 0x040430D8u;
            cpu->pc = 0x861Du;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (2));
            static const uint32_t allowed[] = { 0x040430E8u, 0x040430F8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040430E8u: {
            const uint32_t source_key = 0x040430E8u;
            cpu->pc = 0x861Fu;
            uint32_t ea = js_addr_dp(cpu, 0x3Eu);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040430F8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040430F8u: {
            const uint32_t source_key = 0x040430F8u;
            cpu->pc = 0x8620u;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x04043100u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04043100u: {
            const uint32_t source_key = 0x04043100u;
            cpu->pc = 0x8623u;
            uint16_t value = 0x1000u;
            js_op_compare(cpu, cpu->y, value, 16u);
            static const uint32_t allowed[] = { 0x04043118u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04043118u: {
            const uint32_t source_key = 0x04043118u;
            cpu->pc = 0x8625u;
            if (js_branch_condition(cpu, 'C')) cpu->pc = (uint16_t)(cpu->pc + (3));
            static const uint32_t allowed[] = { 0x04043128u, 0x04043140u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04043128u: {
            const uint32_t source_key = 0x04043128u;
            cpu->pc = 0x8628u;
            uint16_t value = 0x0000u;
            js_op_load_y(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04043140u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04043140u: {
            const uint32_t source_key = 0x04043140u;
            cpu->pc = 0x8629u;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, -1, 16u), 16u);
            static const uint32_t allowed[] = { 0x04043148u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04043148u: {
            const uint32_t source_key = 0x04043148u;
            cpu->pc = 0x862Bu;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (7));
            static const uint32_t allowed[] = { 0x04043158u, 0x04043190u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04043158u: {
            const uint32_t source_key = 0x04043158u;
            cpu->pc = 0x862Eu;
            uint16_t value = 0x1000u;
            js_op_load_x(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04043170u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04043170u: {
            const uint32_t source_key = 0x04043170u;
            cpu->pc = 0x8630u;
            uint32_t ea = js_addr_stack_rel(cpu, 0x05u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04043180u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04043180u: {
            const uint32_t source_key = 0x04043180u;
            cpu->pc = 0x8632u;
            uint32_t ea = js_addr_dp(cpu, 0x3Cu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04043190u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04043190u: {
            const uint32_t source_key = 0x04043190u;
            cpu->pc = 0x8634u;
            uint32_t ea = js_addr_dp(cpu, 0x8Eu);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, -1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040431A0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040431A0u: {
            const uint32_t source_key = 0x040431A0u;
            cpu->pc = 0x8636u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-49));
            static const uint32_t allowed[] = { 0x04043028u, 0x040431B0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040431B0u: {
            const uint32_t source_key = 0x040431B0u;
            cpu->pc = 0x8639u;
            cpu->pc = (uint16_t)(cpu->pc + (-188));
            static const uint32_t allowed[] = { 0x04042BE8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        default: return JS_EXEC_NOT_MINE;
    }
}
