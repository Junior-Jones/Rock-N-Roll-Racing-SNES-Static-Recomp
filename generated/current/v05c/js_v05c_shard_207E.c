#include "v05c_static_cpu.h"

JSExecResult js_v05c_shard_207E(JSCPU *cpu, const JSBus *bus, JSStop *stop) {
    (void)bus;
    (void)stop;
    switch (js_cpu_context_key(cpu)) {
        case 0x040FC013u: {
            const uint32_t source_key = 0x040FC013u;
            cpu->pc = 0xF803u;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 8u), 8u);
            static const uint32_t allowed[] = { 0x040FC01Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC01Bu: {
            const uint32_t source_key = 0x040FC01Bu;
            cpu->pc = 0xF805u;
            uint16_t value = 0x0011u;
            js_op_compare(cpu, cpu->y, value, 8u);
            static const uint32_t allowed[] = { 0x040FC02Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC02Bu: {
            const uint32_t source_key = 0x040FC02Bu;
            cpu->pc = 0xF807u;
            if (js_branch_condition(cpu, 'C')) cpu->pc = (uint16_t)(cpu->pc + (-14));
            static const uint32_t allowed[] = { 0x040FBFCBu, 0x040FC03Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC03Bu: {
            const uint32_t source_key = 0x040FC03Bu;
            cpu->pc = 0xF808u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FA763u, 0x040FAB2Bu, 0x040FAC63u, 0x040FAD53u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC043u: {
            const uint32_t source_key = 0x040FC043u;
            cpu->pc = 0xF809u;
            if (!js_stack_push8(cpu, bus, (uint8_t)cpu->y, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FC04Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC04Bu: {
            const uint32_t source_key = 0x040FC04Bu;
            cpu->pc = 0xF80Bu;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FC058u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC058u: {
            const uint32_t source_key = 0x040FC058u;
            cpu->pc = 0xF80Eu;
            uint16_t value = 0x00FFu;
            js_op_and(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040FC070u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC070u: {
            const uint32_t source_key = 0x040FC070u;
            cpu->pc = 0xF80Fu;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_C);
            static const uint32_t allowed[] = { 0x040FC078u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC078u: {
            const uint32_t source_key = 0x040FC078u;
            cpu->pc = 0xF812u;
            uint32_t ea = js_addr_abs(cpu, 0x02C0u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_adc(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040FC090u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC090u: {
            const uint32_t source_key = 0x040FC090u;
            cpu->pc = 0xF815u;
            uint16_t value = 0x00E0u;
            js_op_compare(cpu, cpu->a, value, 16u);
            static const uint32_t allowed[] = { 0x040FC0A8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC0A8u: {
            const uint32_t source_key = 0x040FC0A8u;
            cpu->pc = 0xF817u;
            if (js_branch_condition(cpu, 'C')) cpu->pc = (uint16_t)(cpu->pc + (8));
            static const uint32_t allowed[] = { 0x040FC0B8u, 0x040FC0F8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC0B8u: {
            const uint32_t source_key = 0x040FC0B8u;
            cpu->pc = 0xF81Au;
            uint16_t value = 0xFFE1u;
            js_op_compare(cpu, cpu->a, value, 16u);
            static const uint32_t allowed[] = { 0x040FC0D0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC0D0u: {
            const uint32_t source_key = 0x040FC0D0u;
            cpu->pc = 0xF81Cu;
            if (js_branch_condition(cpu, 'D')) cpu->pc = (uint16_t)(cpu->pc + (3));
            static const uint32_t allowed[] = { 0x040FC0E0u, 0x040FC0F8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC0E0u: {
            const uint32_t source_key = 0x040FC0E0u;
            cpu->pc = 0xF81Fu;
            uint16_t value = 0x00E0u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040FC0F8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC0F8u: {
            const uint32_t source_key = 0x040FC0F8u;
            cpu->pc = 0xF821u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FC10Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC10Bu: {
            const uint32_t source_key = 0x040FC10Bu;
            cpu->pc = 0xF822u;
            if (!js_stack_push8(cpu, bus, (uint8_t)cpu->a, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FC113u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC113u: {
            const uint32_t source_key = 0x040FC113u;
            cpu->pc = 0xF823u;
            js_op_transfer(cpu, 'H');
            static const uint32_t allowed[] = { 0x040FC11Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC11Bu: {
            const uint32_t source_key = 0x040FC11Bu;
            cpu->pc = 0xF824u;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 8u), 8u);
            static const uint32_t allowed[] = { 0x040FC123u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC123u: {
            const uint32_t source_key = 0x040FC123u;
            cpu->pc = 0xF825u;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 8u), 8u);
            static const uint32_t allowed[] = { 0x040FC12Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC12Bu: {
            const uint32_t source_key = 0x040FC12Bu;
            cpu->pc = 0xF826u;
            js_op_transfer(cpu, 'B');
            static const uint32_t allowed[] = { 0x040FC133u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC133u: {
            const uint32_t source_key = 0x040FC133u;
            cpu->pc = 0xF827u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 8u); }
            static const uint32_t allowed[] = { 0x040FC13Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC13Bu: {
            const uint32_t source_key = 0x040FC13Bu;
            cpu->pc = 0xF82Au;
            uint32_t ea = js_addr_abs_y(cpu, 0x13FFu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FC153u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC153u: {
            const uint32_t source_key = 0x040FC153u;
            cpu->pc = 0xF82Bu;
            js_op_transfer(cpu, 'F');
            static const uint32_t allowed[] = { 0x040FC15Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC15Bu: {
            const uint32_t source_key = 0x040FC15Bu;
            cpu->pc = 0xF82Eu;
            uint32_t ea = js_addr_abs_y(cpu, 0x13FEu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FC173u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC173u: {
            const uint32_t source_key = 0x040FC173u;
            cpu->pc = 0xF82Fu;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_y(cpu, v, 8u); }
            static const uint32_t allowed[] = { 0x040FC17Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC17Bu: {
            const uint32_t source_key = 0x040FC17Bu;
            cpu->pc = 0xF830u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FC013u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC183u: {
            const uint32_t source_key = 0x040FC183u;
            cpu->pc = 0xF832u;
            uint16_t value = 0x00E0u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FC193u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC193u: {
            const uint32_t source_key = 0x040FC193u;
            cpu->pc = 0xF835u;
            uint32_t ea = js_addr_abs(cpu, 0x13FBu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FC1ABu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC1ABu: {
            const uint32_t source_key = 0x040FC1ABu;
            cpu->pc = 0xF836u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FBA8Bu, 0x040FBDDBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC1B3u: {
            const uint32_t source_key = 0x040FC1B3u;
            cpu->pc = 0xF838u;
            uint16_t value = 0x0000u;
            js_op_compare(cpu, cpu->a, value, 8u);
            static const uint32_t allowed[] = { 0x040FC1C3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC1C3u: {
            const uint32_t source_key = 0x040FC1C3u;
            cpu->pc = 0xF83Au;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (24));
            static const uint32_t allowed[] = { 0x040FC1D3u, 0x040FC293u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC1D3u: {
            const uint32_t source_key = 0x040FC1D3u;
            cpu->pc = 0xF83Cu;
            uint16_t value = 0x0001u;
            js_op_compare(cpu, cpu->a, value, 8u);
            static const uint32_t allowed[] = { 0x040FC1E3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC1E3u: {
            const uint32_t source_key = 0x040FC1E3u;
            cpu->pc = 0xF83Eu;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (10));
            static const uint32_t allowed[] = { 0x040FC243u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC243u: {
            const uint32_t source_key = 0x040FC243u;
            cpu->pc = 0xF84Au;
            uint16_t value = 0x0020u;
            js_op_load_y(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FC253u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC253u: {
            const uint32_t source_key = 0x040FC253u;
            cpu->pc = 0xF84Du;
            uint32_t ea = js_addr_abs(cpu, 0x13B8u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FC26Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC26Bu: {
            const uint32_t source_key = 0x040FC26Bu;
            cpu->pc = 0xF850u;
            uint32_t ea = js_addr_abs_x(cpu, 0xF861u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FC283u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC283u: {
            const uint32_t source_key = 0x040FC283u;
            cpu->pc = 0xF852u;
            if (js_branch_condition(cpu, 'A')) cpu->pc = (uint16_t)(cpu->pc + (8));
            static const uint32_t allowed[] = { 0x040FC2D3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC293u: {
            const uint32_t source_key = 0x040FC293u;
            cpu->pc = 0xF854u;
            uint16_t value = 0x0030u;
            js_op_load_y(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FC2A3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC2A3u: {
            const uint32_t source_key = 0x040FC2A3u;
            cpu->pc = 0xF857u;
            uint32_t ea = js_addr_abs(cpu, 0x13B8u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FC2BBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC2BBu: {
            const uint32_t source_key = 0x040FC2BBu;
            cpu->pc = 0xF85Au;
            uint32_t ea = js_addr_abs_x(cpu, 0xF863u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FC2D3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC2D3u: {
            const uint32_t source_key = 0x040FC2D3u;
            cpu->pc = 0xF85Du;
            uint32_t ea = js_addr_abs(cpu, 0x13FAu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_y(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FC2EBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC2EBu: {
            const uint32_t source_key = 0x040FC2EBu;
            cpu->pc = 0xF860u;
            uint32_t ea = js_addr_abs(cpu, 0x13FBu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FC303u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FC303u: {
            const uint32_t source_key = 0x040FC303u;
            cpu->pc = 0xF861u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FBAC3u, 0x040FBE13u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        default: return JS_EXEC_NOT_MINE;
    }
}
