#include "v05c_static_cpu.h"

JSExecResult js_v05c_shard_2020(JSCPU *cpu, const JSBus *bus, JSStop *stop) {
    (void)bus;
    (void)stop;
    switch (js_cpu_context_key(cpu)) {
        case 0x04040067u: {
            const uint32_t source_key = 0x04040067u;
            cpu->pc = 0x800Du;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_C);
            static const uint32_t allowed[] = { 0x0404006Fu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404006Fu: {
            const uint32_t source_key = 0x0404006Fu;
            cpu->pc = 0x800Eu;
            js_op_xce(cpu);
            static const uint32_t allowed[] = { 0x04040073u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040073u: {
            const uint32_t source_key = 0x04040073u;
            cpu->pc = 0x800Fu;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0404007Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404007Bu: {
            const uint32_t source_key = 0x0404007Bu;
            cpu->pc = 0x8010u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04040083u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040083u: {
            const uint32_t source_key = 0x04040083u;
            cpu->pc = 0x8012u;
            js_op_rep(cpu, 0x10u);
            static const uint32_t allowed[] = { 0x04040092u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040092u: {
            const uint32_t source_key = 0x04040092u;
            cpu->pc = 0x8014u;
            uint16_t value = 0x0000u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040400A2u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040400A2u: {
            const uint32_t source_key = 0x040400A2u;
            cpu->pc = 0x8017u;
            uint16_t value = 0x0000u;
            js_op_load_y(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040400BAu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040400BAu: {
            const uint32_t source_key = 0x040400BAu;
            cpu->pc = 0x801Au;
            uint32_t ea = js_addr_abs_y(cpu, 0x0000u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040400D2u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040400D2u: {
            const uint32_t source_key = 0x040400D2u;
            cpu->pc = 0x801Bu;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040400DAu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040400DAu: {
            const uint32_t source_key = 0x040400DAu;
            cpu->pc = 0x801Eu;
            uint16_t value = 0x0331u;
            js_op_compare(cpu, cpu->y, value, 16u);
            static const uint32_t allowed[] = { 0x040400F2u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040400F2u: {
            const uint32_t source_key = 0x040400F2u;
            cpu->pc = 0x8020u;
            if (js_branch_condition(cpu, 'C')) cpu->pc = (uint16_t)(cpu->pc + (-9));
            static const uint32_t allowed[] = { 0x040400BAu, 0x04040102u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040102u: {
            const uint32_t source_key = 0x04040102u;
            cpu->pc = 0x8023u;
            uint16_t value = 0x0339u;
            js_op_load_y(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x0404011Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404011Au: {
            const uint32_t source_key = 0x0404011Au;
            cpu->pc = 0x8026u;
            uint32_t ea = js_addr_abs_y(cpu, 0x0000u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040132u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040132u: {
            const uint32_t source_key = 0x04040132u;
            cpu->pc = 0x8027u;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x0404013Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404013Au: {
            const uint32_t source_key = 0x0404013Au;
            cpu->pc = 0x802Au;
            uint16_t value = 0x2000u;
            js_op_compare(cpu, cpu->y, value, 16u);
            static const uint32_t allowed[] = { 0x04040152u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040152u: {
            const uint32_t source_key = 0x04040152u;
            cpu->pc = 0x802Cu;
            if (js_branch_condition(cpu, 'C')) cpu->pc = (uint16_t)(cpu->pc + (-9));
            static const uint32_t allowed[] = { 0x0404011Au, 0x04040162u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040162u: {
            const uint32_t source_key = 0x04040162u;
            cpu->pc = 0x802Eu;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x04040170u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040170u: {
            const uint32_t source_key = 0x04040170u;
            cpu->pc = 0x8031u;
            uint16_t value = 0x0000u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04040188u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040188u: {
            const uint32_t source_key = 0x04040188u;
            cpu->pc = 0x8032u;
            js_op_transfer(cpu, 'C');
            static const uint32_t allowed[] = { 0x04040190u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040190u: {
            const uint32_t source_key = 0x04040190u;
            cpu->pc = 0x8035u;
            uint16_t value = 0x01FFu;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040401A8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040401A8u: {
            const uint32_t source_key = 0x040401A8u;
            cpu->pc = 0x8036u;
            js_op_transfer(cpu, 'D');
            static const uint32_t allowed[] = { 0x040401B0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040401B0u: {
            const uint32_t source_key = 0x040401B0u;
            cpu->pc = 0x8038u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040401C3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040401C3u: {
            const uint32_t source_key = 0x040401C3u;
            cpu->pc = 0x803Cu;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x92u;
            cpu->pc = 0xEF72u;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x04977B93u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040401E3u: {
            const uint32_t source_key = 0x040401E3u;
            cpu->pc = 0x8040u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x92u;
            cpu->pc = 0xEFF1u;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x04977F8Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040203u: {
            const uint32_t source_key = 0x04040203u;
            cpu->pc = 0x8043u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x8138u;
            static const uint32_t allowed[] = { 0x040409C3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404021Bu: {
            const uint32_t source_key = 0x0404021Bu;
            cpu->pc = 0x8047u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x92u;
            cpu->pc = 0xF04Du;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x0497826Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404023Bu: {
            const uint32_t source_key = 0x0404023Bu;
            cpu->pc = 0x804Au;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF8DBu;
            static const uint32_t allowed[] = { 0x0407C6DBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040253u: {
            const uint32_t source_key = 0x04040253u;
            cpu->pc = 0x804Du;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x8114u;
            static const uint32_t allowed[] = { 0x040408A3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404026Bu: {
            const uint32_t source_key = 0x0404026Bu;
            cpu->pc = 0x804Fu;
            uint16_t value = 0x0001u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0404027Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404027Bu: {
            const uint32_t source_key = 0x0404027Bu;
            cpu->pc = 0x8052u;
            uint32_t ea = js_addr_abs(cpu, 0x0F0Eu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040293u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040293u: {
            const uint32_t source_key = 0x04040293u;
            cpu->pc = 0x8054u;
            uint16_t value = 0x0000u;
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040402A3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040402A3u: {
            const uint32_t source_key = 0x040402A3u;
            cpu->pc = 0x8058u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x81u;
            cpu->pc = 0xAC40u;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x040D6203u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040408A3u: {
            const uint32_t source_key = 0x040408A3u;
            cpu->pc = 0x8116u;
            uint16_t value = 0x0080u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040408B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040408B3u: {
            const uint32_t source_key = 0x040408B3u;
            cpu->pc = 0x8119u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF97Bu;
            static const uint32_t allowed[] = { 0x0407CBDBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040408CBu: {
            const uint32_t source_key = 0x040408CBu;
            cpu->pc = 0x811Cu;
            uint32_t ea = js_addr_abs(cpu, 0x1AECu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_y(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040408E3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040408E3u: {
            const uint32_t source_key = 0x040408E3u;
            cpu->pc = 0x811Du;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 8u), 8u);
            static const uint32_t allowed[] = { 0x040408EBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040408EBu: {
            const uint32_t source_key = 0x040408EBu;
            cpu->pc = 0x811Fu;
            uint16_t value = 0x0005u;
            js_op_compare(cpu, cpu->y, value, 8u);
            static const uint32_t allowed[] = { 0x040408FBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040408FBu: {
            const uint32_t source_key = 0x040408FBu;
            cpu->pc = 0x8121u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (2));
            static const uint32_t allowed[] = { 0x0404090Bu, 0x0404091Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404090Bu: {
            const uint32_t source_key = 0x0404090Bu;
            cpu->pc = 0x8123u;
            uint16_t value = 0x0000u;
            js_op_load_y(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0404091Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404091Bu: {
            const uint32_t source_key = 0x0404091Bu;
            cpu->pc = 0x8126u;
            uint32_t ea = js_addr_abs(cpu, 0x1AECu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_y(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040933u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040933u: {
            const uint32_t source_key = 0x04040933u;
            cpu->pc = 0x8129u;
            uint32_t ea = js_addr_abs_y(cpu, 0x82F2u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0404094Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404094Bu: {
            const uint32_t source_key = 0x0404094Bu;
            cpu->pc = 0x812Cu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF904u;
            static const uint32_t allowed[] = { 0x0407C823u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040963u: {
            const uint32_t source_key = 0x04040963u;
            cpu->pc = 0x812Fu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF986u;
            static const uint32_t allowed[] = { 0x0407CC33u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404097Bu: {
            const uint32_t source_key = 0x0404097Bu;
            cpu->pc = 0x8130u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x0404026Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040409C3u: {
            const uint32_t source_key = 0x040409C3u;
            cpu->pc = 0x8139u;
            cpu->p = (uint8_t)(cpu->p | JS_P_I);
            static const uint32_t allowed[] = { 0x040409CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040409CBu: {
            const uint32_t source_key = 0x040409CBu;
            cpu->pc = 0x813Bu;
            uint16_t value = 0x0009u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040409DBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040409DBu: {
            const uint32_t source_key = 0x040409DBu;
            cpu->pc = 0x813Eu;
            uint32_t ea = js_addr_abs(cpu, 0x2105u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040409F3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040409F3u: {
            const uint32_t source_key = 0x040409F3u;
            cpu->pc = 0x8140u;
            uint16_t value = 0x0061u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04040A03u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040A03u: {
            const uint32_t source_key = 0x04040A03u;
            cpu->pc = 0x8143u;
            uint32_t ea = js_addr_abs(cpu, 0x2101u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040A1Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040A1Bu: {
            const uint32_t source_key = 0x04040A1Bu;
            cpu->pc = 0x8145u;
            uint16_t value = 0x0001u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04040A2Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040A2Bu: {
            const uint32_t source_key = 0x04040A2Bu;
            cpu->pc = 0x8148u;
            uint32_t ea = js_addr_abs(cpu, 0x2107u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040A43u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040A43u: {
            const uint32_t source_key = 0x04040A43u;
            cpu->pc = 0x814Au;
            uint16_t value = 0x0011u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04040A53u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040A53u: {
            const uint32_t source_key = 0x04040A53u;
            cpu->pc = 0x814Du;
            uint32_t ea = js_addr_abs(cpu, 0x2108u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040A6Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040A6Bu: {
            const uint32_t source_key = 0x04040A6Bu;
            cpu->pc = 0x814Fu;
            uint16_t value = 0x003Du;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04040A7Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040A7Bu: {
            const uint32_t source_key = 0x04040A7Bu;
            cpu->pc = 0x8152u;
            uint32_t ea = js_addr_abs(cpu, 0x2109u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040A93u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040A93u: {
            const uint32_t source_key = 0x04040A93u;
            cpu->pc = 0x8154u;
            uint16_t value = 0x0044u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04040AA3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040AA3u: {
            const uint32_t source_key = 0x04040AA3u;
            cpu->pc = 0x8157u;
            uint32_t ea = js_addr_abs(cpu, 0x210Bu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040ABBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040ABBu: {
            const uint32_t source_key = 0x04040ABBu;
            cpu->pc = 0x8159u;
            uint16_t value = 0x0003u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04040ACBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040ACBu: {
            const uint32_t source_key = 0x04040ACBu;
            cpu->pc = 0x815Cu;
            uint32_t ea = js_addr_abs(cpu, 0x210Cu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040AE3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040AE3u: {
            const uint32_t source_key = 0x04040AE3u;
            cpu->pc = 0x815Eu;
            uint16_t value = 0x0017u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04040AF3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040AF3u: {
            const uint32_t source_key = 0x04040AF3u;
            cpu->pc = 0x8161u;
            uint32_t ea = js_addr_abs(cpu, 0x212Cu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040B0Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B0Bu: {
            const uint32_t source_key = 0x04040B0Bu;
            cpu->pc = 0x8164u;
            uint32_t ea = js_addr_abs(cpu, 0x212Du);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040B23u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B23u: {
            const uint32_t source_key = 0x04040B23u;
            cpu->pc = 0x8165u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_I);
            static const uint32_t allowed[] = { 0x04040B2Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B2Bu: {
            const uint32_t source_key = 0x04040B2Bu;
            cpu->pc = 0x8166u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x0404021Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B50u: {
            const uint32_t source_key = 0x04040B50u;
            cpu->pc = 0x816Bu;
            if (!js_stack_push8(cpu, bus, cpu->dbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040B58u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B51u: {
            const uint32_t source_key = 0x04040B51u;
            cpu->pc = 0x816Bu;
            if (!js_stack_push8(cpu, bus, cpu->dbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040B59u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B52u: {
            const uint32_t source_key = 0x04040B52u;
            cpu->pc = 0x816Bu;
            if (!js_stack_push8(cpu, bus, cpu->dbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040B5Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B53u: {
            const uint32_t source_key = 0x04040B53u;
            cpu->pc = 0x816Bu;
            if (!js_stack_push8(cpu, bus, cpu->dbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040B5Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B57u: {
            const uint32_t source_key = 0x04040B57u;
            cpu->pc = 0x816Bu;
            if (!js_stack_push8(cpu, bus, cpu->dbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040B5Fu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B58u: {
            const uint32_t source_key = 0x04040B58u;
            cpu->pc = 0x816Cu;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040B60u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B59u: {
            const uint32_t source_key = 0x04040B59u;
            cpu->pc = 0x816Cu;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040B61u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B5Au: {
            const uint32_t source_key = 0x04040B5Au;
            cpu->pc = 0x816Cu;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040B62u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B5Bu: {
            const uint32_t source_key = 0x04040B5Bu;
            cpu->pc = 0x816Cu;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040B63u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B5Fu: {
            const uint32_t source_key = 0x04040B5Fu;
            cpu->pc = 0x816Cu;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040B67u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B60u: {
            const uint32_t source_key = 0x04040B60u;
            cpu->pc = 0x816Du;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04040B68u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B61u: {
            const uint32_t source_key = 0x04040B61u;
            cpu->pc = 0x816Du;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04040B69u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B62u: {
            const uint32_t source_key = 0x04040B62u;
            cpu->pc = 0x816Du;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04040B6Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B63u: {
            const uint32_t source_key = 0x04040B63u;
            cpu->pc = 0x816Du;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04040B6Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B67u: {
            const uint32_t source_key = 0x04040B67u;
            cpu->pc = 0x816Du;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04040B6Fu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B68u: {
            const uint32_t source_key = 0x04040B68u;
            cpu->pc = 0x816Fu;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x04040B78u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B69u: {
            const uint32_t source_key = 0x04040B69u;
            cpu->pc = 0x816Fu;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x04040B78u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B6Au: {
            const uint32_t source_key = 0x04040B6Au;
            cpu->pc = 0x816Fu;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x04040B78u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B6Bu: {
            const uint32_t source_key = 0x04040B6Bu;
            cpu->pc = 0x816Fu;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x04040B78u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B6Fu: {
            const uint32_t source_key = 0x04040B6Fu;
            cpu->pc = 0x816Fu;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x04040B7Fu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B78u: {
            const uint32_t source_key = 0x04040B78u;
            cpu->pc = 0x8171u;
            uint32_t ea = js_addr_dp(cpu, 0x2Au);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040B88u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B7Fu: {
            const uint32_t source_key = 0x04040B7Fu;
            cpu->pc = 0x8171u;
            uint32_t ea = js_addr_dp(cpu, 0x2Au);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040B8Fu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B88u: {
            const uint32_t source_key = 0x04040B88u;
            cpu->pc = 0x8173u;
            uint32_t ea = js_addr_dp(cpu, 0x2Cu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_x(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040B98u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B8Fu: {
            const uint32_t source_key = 0x04040B8Fu;
            cpu->pc = 0x8173u;
            uint32_t ea = js_addr_dp(cpu, 0x2Cu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_x(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040B9Fu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B98u: {
            const uint32_t source_key = 0x04040B98u;
            cpu->pc = 0x8175u;
            uint32_t ea = js_addr_dp(cpu, 0x2Eu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_y(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040BA8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040B9Fu: {
            const uint32_t source_key = 0x04040B9Fu;
            cpu->pc = 0x8175u;
            uint32_t ea = js_addr_dp(cpu, 0x2Eu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_y(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040BAFu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040BA8u: {
            const uint32_t source_key = 0x04040BA8u;
            cpu->pc = 0x8177u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x04040BBBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040BAFu: {
            const uint32_t source_key = 0x04040BAFu;
            cpu->pc = 0x8177u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x04040BBFu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040BBBu: {
            const uint32_t source_key = 0x04040BBBu;
            cpu->pc = 0x817Au;
            uint32_t ea = js_addr_abs(cpu, 0x4210u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04040BD3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040BBFu: {
            const uint32_t source_key = 0x04040BBFu;
            cpu->pc = 0x817Au;
            uint32_t ea = js_addr_abs(cpu, 0x4210u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04040BD7u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040BD3u: {
            const uint32_t source_key = 0x04040BD3u;
            cpu->pc = 0x817Cu;
            uint16_t value = 0x0080u;
            js_op_and(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04040BE3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040BD7u: {
            const uint32_t source_key = 0x04040BD7u;
            cpu->pc = 0x817Cu;
            uint16_t value = 0x0080u;
            js_op_and(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04040BE7u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040BE3u: {
            const uint32_t source_key = 0x04040BE3u;
            cpu->pc = 0x817Eu;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (12));
            static const uint32_t allowed[] = { 0x04040BF3u, 0x04040C53u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040BE7u: {
            const uint32_t source_key = 0x04040BE7u;
            cpu->pc = 0x817Eu;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (12));
            static const uint32_t allowed[] = { 0x04040BF7u, 0x04040C57u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040BF3u: {
            const uint32_t source_key = 0x04040BF3u;
            cpu->pc = 0x8181u;
            uint32_t ea = js_addr_abs(cpu, 0x0355u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04040C0Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040BF7u: {
            const uint32_t source_key = 0x04040BF7u;
            cpu->pc = 0x8181u;
            uint32_t ea = js_addr_abs(cpu, 0x0355u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04040C0Fu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040C0Bu: {
            const uint32_t source_key = 0x04040C0Bu;
            return js_stop_now(stop, JS_STOP_UNPROVED_DYNAMIC_TARGET, source_key, source_key);
        }
        case 0x04040C0Fu: {
            const uint32_t source_key = 0x04040C0Fu;
            return js_stop_now(stop, JS_STOP_UNPROVED_DYNAMIC_TARGET, source_key, source_key);
        }
        case 0x04040C53u: {
            const uint32_t source_key = 0x04040C53u;
            cpu->pc = 0x818Cu;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x04040C60u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040C57u: {
            const uint32_t source_key = 0x04040C57u;
            cpu->pc = 0x818Cu;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x04040C67u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040C60u: {
            const uint32_t source_key = 0x04040C60u;
            cpu->pc = 0x818Fu;
            uint32_t ea = js_addr_abs(cpu, 0x127Eu);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040C78u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040C67u: {
            const uint32_t source_key = 0x04040C67u;
            cpu->pc = 0x818Fu;
            uint32_t ea = js_addr_abs(cpu, 0x127Eu);
            uint16_t original = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
            uint16_t result = js_op_incdec(cpu, original, 1, 8u);
            if (!js_bus_rmw_write(bus, ea, 0, 8u, 1u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04040C7Fu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040C78u: {
            const uint32_t source_key = 0x04040C78u;
            cpu->pc = 0x8191u;
            uint32_t ea = js_addr_dp(cpu, 0x2Au);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04040C88u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040C7Fu: {
            const uint32_t source_key = 0x04040C7Fu;
            cpu->pc = 0x8191u;
            uint32_t ea = js_addr_dp(cpu, 0x2Au);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04040C8Fu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040C88u: {
            const uint32_t source_key = 0x04040C88u;
            cpu->pc = 0x8193u;
            uint32_t ea = js_addr_dp(cpu, 0x2Cu);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_x(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04040C98u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040C8Fu: {
            const uint32_t source_key = 0x04040C8Fu;
            cpu->pc = 0x8193u;
            uint32_t ea = js_addr_dp(cpu, 0x2Cu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04040C9Fu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040C98u: {
            const uint32_t source_key = 0x04040C98u;
            cpu->pc = 0x8195u;
            uint32_t ea = js_addr_dp(cpu, 0x2Eu);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_y(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04040CA8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040C9Fu: {
            const uint32_t source_key = 0x04040C9Fu;
            cpu->pc = 0x8195u;
            uint32_t ea = js_addr_dp(cpu, 0x2Eu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_y(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04040CAFu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040CA8u: {
            const uint32_t source_key = 0x04040CA8u;
            cpu->pc = 0x8196u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04040CB0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040CAFu: {
            const uint32_t source_key = 0x04040CAFu;
            cpu->pc = 0x8196u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04040CB7u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04040CB0u: {
            const uint32_t source_key = 0x04040CB0u;
            return js_stop_now(stop, JS_STOP_UNPROVED_INTERRUPT_REENTRY, source_key, source_key);
        }
        case 0x04040CB7u: {
            const uint32_t source_key = 0x04040CB7u;
            return js_stop_now(stop, JS_STOP_UNPROVED_INTERRUPT_REENTRY, source_key, source_key);
        }
        case 0x04040DF8u: {
            const uint32_t source_key = 0x04040DF8u;
            return js_stop_now(stop, JS_STOP_UNPROVED_INTERRUPT_REENTRY, source_key, source_key);
        }
        case 0x04040DF9u: {
            const uint32_t source_key = 0x04040DF9u;
            return js_stop_now(stop, JS_STOP_UNPROVED_INTERRUPT_REENTRY, source_key, source_key);
        }
        case 0x04040DFAu: {
            const uint32_t source_key = 0x04040DFAu;
            return js_stop_now(stop, JS_STOP_UNPROVED_INTERRUPT_REENTRY, source_key, source_key);
        }
        case 0x04040DFBu: {
            const uint32_t source_key = 0x04040DFBu;
            return js_stop_now(stop, JS_STOP_UNPROVED_INTERRUPT_REENTRY, source_key, source_key);
        }
        case 0x04040DFFu: {
            const uint32_t source_key = 0x04040DFFu;
            return js_stop_now(stop, JS_STOP_UNPROVED_INTERRUPT_REENTRY, source_key, source_key);
        }
        case 0x04041008u: {
            const uint32_t source_key = 0x04041008u;
            cpu->pc = 0x8202u;
            if (!js_stack_push8(cpu, bus, cpu->p, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041010u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041009u: {
            const uint32_t source_key = 0x04041009u;
            cpu->pc = 0x8202u;
            if (!js_stack_push8(cpu, bus, cpu->p, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041011u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404100Au: {
            const uint32_t source_key = 0x0404100Au;
            cpu->pc = 0x8202u;
            if (!js_stack_push8(cpu, bus, cpu->p, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041012u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404100Bu: {
            const uint32_t source_key = 0x0404100Bu;
            cpu->pc = 0x8202u;
            if (!js_stack_push8(cpu, bus, cpu->p, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041013u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404100Fu: {
            const uint32_t source_key = 0x0404100Fu;
            cpu->pc = 0x8202u;
            if (!js_stack_push8(cpu, bus, cpu->p, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041017u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041010u: {
            const uint32_t source_key = 0x04041010u;
            cpu->pc = 0x8203u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_D);
            static const uint32_t allowed[] = { 0x04041018u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041011u: {
            const uint32_t source_key = 0x04041011u;
            cpu->pc = 0x8203u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_D);
            static const uint32_t allowed[] = { 0x04041019u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041012u: {
            const uint32_t source_key = 0x04041012u;
            cpu->pc = 0x8203u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_D);
            static const uint32_t allowed[] = { 0x0404101Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041013u: {
            const uint32_t source_key = 0x04041013u;
            cpu->pc = 0x8203u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_D);
            static const uint32_t allowed[] = { 0x0404101Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041017u: {
            const uint32_t source_key = 0x04041017u;
            cpu->pc = 0x8203u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_D);
            static const uint32_t allowed[] = { 0x0404101Fu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041018u: {
            const uint32_t source_key = 0x04041018u;
            cpu->pc = 0x8204u;
            if (!js_stack_push8(cpu, bus, cpu->dbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041020u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041019u: {
            const uint32_t source_key = 0x04041019u;
            cpu->pc = 0x8204u;
            if (!js_stack_push8(cpu, bus, cpu->dbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041021u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404101Au: {
            const uint32_t source_key = 0x0404101Au;
            cpu->pc = 0x8204u;
            if (!js_stack_push8(cpu, bus, cpu->dbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041022u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404101Bu: {
            const uint32_t source_key = 0x0404101Bu;
            cpu->pc = 0x8204u;
            if (!js_stack_push8(cpu, bus, cpu->dbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041023u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404101Fu: {
            const uint32_t source_key = 0x0404101Fu;
            cpu->pc = 0x8204u;
            if (!js_stack_push8(cpu, bus, cpu->dbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041027u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041020u: {
            const uint32_t source_key = 0x04041020u;
            cpu->pc = 0x8205u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041028u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041021u: {
            const uint32_t source_key = 0x04041021u;
            cpu->pc = 0x8205u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041029u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041022u: {
            const uint32_t source_key = 0x04041022u;
            cpu->pc = 0x8205u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0404102Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041023u: {
            const uint32_t source_key = 0x04041023u;
            cpu->pc = 0x8205u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0404102Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041027u: {
            const uint32_t source_key = 0x04041027u;
            cpu->pc = 0x8205u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0404102Fu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041028u: {
            const uint32_t source_key = 0x04041028u;
            cpu->pc = 0x8206u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04041030u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041029u: {
            const uint32_t source_key = 0x04041029u;
            cpu->pc = 0x8206u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04041031u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404102Au: {
            const uint32_t source_key = 0x0404102Au;
            cpu->pc = 0x8206u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04041032u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404102Bu: {
            const uint32_t source_key = 0x0404102Bu;
            cpu->pc = 0x8206u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04041033u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404102Fu: {
            const uint32_t source_key = 0x0404102Fu;
            cpu->pc = 0x8206u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04041037u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041030u: {
            const uint32_t source_key = 0x04041030u;
            cpu->pc = 0x8208u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x04041040u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041031u: {
            const uint32_t source_key = 0x04041031u;
            cpu->pc = 0x8208u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x04041040u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041032u: {
            const uint32_t source_key = 0x04041032u;
            cpu->pc = 0x8208u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x04041040u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041033u: {
            const uint32_t source_key = 0x04041033u;
            cpu->pc = 0x8208u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x04041040u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041037u: {
            const uint32_t source_key = 0x04041037u;
            cpu->pc = 0x8208u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x04041047u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041040u: {
            const uint32_t source_key = 0x04041040u;
            cpu->pc = 0x820Au;
            uint32_t ea = js_addr_dp(cpu, 0x2Au);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041050u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041047u: {
            const uint32_t source_key = 0x04041047u;
            cpu->pc = 0x820Au;
            uint32_t ea = js_addr_dp(cpu, 0x2Au);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041057u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041050u: {
            const uint32_t source_key = 0x04041050u;
            cpu->pc = 0x820Cu;
            uint32_t ea = js_addr_dp(cpu, 0x2Cu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_x(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041060u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041057u: {
            const uint32_t source_key = 0x04041057u;
            cpu->pc = 0x820Cu;
            uint32_t ea = js_addr_dp(cpu, 0x2Cu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_x(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041067u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041060u: {
            const uint32_t source_key = 0x04041060u;
            cpu->pc = 0x820Eu;
            uint32_t ea = js_addr_dp(cpu, 0x2Eu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_y(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041070u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041067u: {
            const uint32_t source_key = 0x04041067u;
            cpu->pc = 0x820Eu;
            uint32_t ea = js_addr_dp(cpu, 0x2Eu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_y(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041077u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041070u: {
            const uint32_t source_key = 0x04041070u;
            cpu->pc = 0x8210u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x04041083u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041077u: {
            const uint32_t source_key = 0x04041077u;
            cpu->pc = 0x8210u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x04041087u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041083u: {
            const uint32_t source_key = 0x04041083u;
            cpu->pc = 0x8213u;
            uint32_t ea = js_addr_abs(cpu, 0x4211u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0404109Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041087u: {
            const uint32_t source_key = 0x04041087u;
            cpu->pc = 0x8213u;
            uint32_t ea = js_addr_abs(cpu, 0x4211u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0404109Fu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404109Bu: {
            const uint32_t source_key = 0x0404109Bu;
            cpu->pc = 0x8215u;
            uint16_t value = 0x0080u;
            js_op_and(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040410ABu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404109Fu: {
            const uint32_t source_key = 0x0404109Fu;
            cpu->pc = 0x8215u;
            uint16_t value = 0x0080u;
            js_op_and(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040410AFu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040410ABu: {
            const uint32_t source_key = 0x040410ABu;
            cpu->pc = 0x8217u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (6));
            static const uint32_t allowed[] = { 0x040410BBu, 0x040410EBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040410AFu: {
            const uint32_t source_key = 0x040410AFu;
            cpu->pc = 0x8217u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (6));
            static const uint32_t allowed[] = { 0x040410BFu, 0x040410EFu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040410BBu: {
            const uint32_t source_key = 0x040410BBu;
            cpu->pc = 0x821Au;
            uint32_t ea = js_addr_abs(cpu, 0x0356u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040410D3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040410BFu: {
            const uint32_t source_key = 0x040410BFu;
            cpu->pc = 0x821Au;
            uint32_t ea = js_addr_abs(cpu, 0x0356u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040410D7u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040410D3u: {
            const uint32_t source_key = 0x040410D3u;
            return js_stop_now(stop, JS_STOP_UNPROVED_DYNAMIC_TARGET, source_key, source_key);
        }
        case 0x040410D7u: {
            const uint32_t source_key = 0x040410D7u;
            return js_stop_now(stop, JS_STOP_UNPROVED_DYNAMIC_TARGET, source_key, source_key);
        }
        case 0x040410EBu: {
            const uint32_t source_key = 0x040410EBu;
            cpu->pc = 0x821Fu;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040410F8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040410EFu: {
            const uint32_t source_key = 0x040410EFu;
            cpu->pc = 0x821Fu;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040410FFu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040410F8u: {
            const uint32_t source_key = 0x040410F8u;
            cpu->pc = 0x8221u;
            uint32_t ea = js_addr_dp(cpu, 0x2Au);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04041108u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040410FFu: {
            const uint32_t source_key = 0x040410FFu;
            cpu->pc = 0x8221u;
            uint32_t ea = js_addr_dp(cpu, 0x2Au);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0404110Fu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041108u: {
            const uint32_t source_key = 0x04041108u;
            cpu->pc = 0x8223u;
            uint32_t ea = js_addr_dp(cpu, 0x2Cu);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_x(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04041118u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404110Fu: {
            const uint32_t source_key = 0x0404110Fu;
            cpu->pc = 0x8223u;
            uint32_t ea = js_addr_dp(cpu, 0x2Cu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0404111Fu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041118u: {
            const uint32_t source_key = 0x04041118u;
            cpu->pc = 0x8225u;
            uint32_t ea = js_addr_dp(cpu, 0x2Eu);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_y(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04041128u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404111Fu: {
            const uint32_t source_key = 0x0404111Fu;
            cpu->pc = 0x8225u;
            uint32_t ea = js_addr_dp(cpu, 0x2Eu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_y(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0404112Fu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041128u: {
            const uint32_t source_key = 0x04041128u;
            cpu->pc = 0x8226u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04041130u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0404112Fu: {
            const uint32_t source_key = 0x0404112Fu;
            cpu->pc = 0x8226u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04041137u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041130u: {
            const uint32_t source_key = 0x04041130u;
            cpu->pc = 0x8227u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; cpu->p = (uint8_t)(v | (cpu->e ? (JS_P_M|JS_P_X) : 0u)); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04041138u, 0x04041139u, 0x0404113Au, 0x0404113Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041137u: {
            const uint32_t source_key = 0x04041137u;
            cpu->pc = 0x8227u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; cpu->p = (uint8_t)(v | (cpu->e ? (JS_P_M|JS_P_X) : 0u)); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x0404113Fu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041138u: {
            const uint32_t source_key = 0x04041138u;
            return js_stop_now(stop, JS_STOP_UNPROVED_INTERRUPT_REENTRY, source_key, source_key);
        }
        case 0x04041139u: {
            const uint32_t source_key = 0x04041139u;
            return js_stop_now(stop, JS_STOP_UNPROVED_INTERRUPT_REENTRY, source_key, source_key);
        }
        case 0x0404113Au: {
            const uint32_t source_key = 0x0404113Au;
            return js_stop_now(stop, JS_STOP_UNPROVED_INTERRUPT_REENTRY, source_key, source_key);
        }
        case 0x0404113Bu: {
            const uint32_t source_key = 0x0404113Bu;
            return js_stop_now(stop, JS_STOP_UNPROVED_INTERRUPT_REENTRY, source_key, source_key);
        }
        case 0x0404113Fu: {
            const uint32_t source_key = 0x0404113Fu;
            return js_stop_now(stop, JS_STOP_UNPROVED_INTERRUPT_REENTRY, source_key, source_key);
        }
        case 0x040417B8u: {
            const uint32_t source_key = 0x040417B8u;
            cpu->pc = 0x82F8u;
            if (!js_stack_push8(cpu, bus, cpu->dbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040417C0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040417C0u: {
            const uint32_t source_key = 0x040417C0u;
            cpu->pc = 0x82F9u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040417C8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040417C8u: {
            const uint32_t source_key = 0x040417C8u;
            cpu->pc = 0x82FAu;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x040417D0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040417D0u: {
            const uint32_t source_key = 0x040417D0u;
            cpu->pc = 0x82FDu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x82FFu;
            static const uint32_t allowed[] = { 0x040417F8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040417E8u: {
            const uint32_t source_key = 0x040417E8u;
            cpu->pc = 0x82FEu;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x040417F0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040417F0u: {
            const uint32_t source_key = 0x040417F0u;
            cpu->pc = 0x82FFu;
            { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x040CEC28u, 0x040CF4E8u, 0x040D2B98u, 0x040D7C20u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040417F8u: {
            const uint32_t source_key = 0x040417F8u;
            cpu->pc = 0x8301u;
            uint32_t ea = js_addr_dp(cpu, 0x88u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_x(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041808u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041808u: {
            const uint32_t source_key = 0x04041808u;
            cpu->pc = 0x8304u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x8320u;
            static const uint32_t allowed[] = { 0x04041900u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041820u: {
            const uint32_t source_key = 0x04041820u;
            cpu->pc = 0x8305u;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->a, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041828u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041828u: {
            const uint32_t source_key = 0x04041828u;
            cpu->pc = 0x8306u;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->x, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041830u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041830u: {
            const uint32_t source_key = 0x04041830u;
            cpu->pc = 0x8308u;
            uint32_t ea = js_addr_dp(cpu, 0x88u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04041840u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041840u: {
            const uint32_t source_key = 0x04041840u;
            cpu->pc = 0x8309u;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->a, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041848u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041848u: {
            const uint32_t source_key = 0x04041848u;
            cpu->pc = 0x830Cu;
            if (!js_stack_push16(cpu, bus, 0xCB00u, 0, stop, source_key)) return JS_EXEC_STOP;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x04041860u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041860u: {
            const uint32_t source_key = 0x04041860u;
            cpu->pc = 0x830Fu;
            if (!js_stack_push16(cpu, bus, 0x1000u, 0, stop, source_key)) return JS_EXEC_STOP;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x04041878u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041878u: {
            const uint32_t source_key = 0x04041878u;
            cpu->pc = 0x8312u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x852Cu;
            static const uint32_t allowed[] = { 0x04042960u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041890u: {
            const uint32_t source_key = 0x04041890u;
            cpu->pc = 0x8313u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x04041898u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041898u: {
            const uint32_t source_key = 0x04041898u;
            cpu->pc = 0x8314u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x040418A0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040418A0u: {
            const uint32_t source_key = 0x040418A0u;
            cpu->pc = 0x8315u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x040418A8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040418A8u: {
            const uint32_t source_key = 0x040418A8u;
            cpu->pc = 0x8316u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x040418B0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040418B0u: {
            const uint32_t source_key = 0x040418B0u;
            cpu->pc = 0x8317u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x040418B8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040418B8u: {
            const uint32_t source_key = 0x040418B8u;
            cpu->pc = 0x8318u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040417E8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041900u: {
            const uint32_t source_key = 0x04041900u;
            cpu->pc = 0x8321u;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04041908u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041908u: {
            const uint32_t source_key = 0x04041908u;
            cpu->pc = 0x8322u;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04041910u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041910u: {
            const uint32_t source_key = 0x04041910u;
            cpu->pc = 0x8323u;
            js_op_transfer(cpu, 'B');
            static const uint32_t allowed[] = { 0x04041918u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041918u: {
            const uint32_t source_key = 0x04041918u;
            cpu->pc = 0x8326u;
            uint16_t value = 0x8000u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04041930u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041930u: {
            const uint32_t source_key = 0x04041930u;
            cpu->pc = 0x8328u;
            uint32_t ea = js_addr_dp(cpu, 0x04u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041940u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041940u: {
            const uint32_t source_key = 0x04041940u;
            cpu->pc = 0x832Bu;
            uint16_t value = 0x0093u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04041958u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041958u: {
            const uint32_t source_key = 0x04041958u;
            cpu->pc = 0x832Du;
            uint32_t ea = js_addr_dp(cpu, 0x06u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041968u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041968u: {
            const uint32_t source_key = 0x04041968u;
            cpu->pc = 0x832Fu;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long_y(cpu, bus, 0x04u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 1, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04041978u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041978u: {
            const uint32_t source_key = 0x04041978u;
            cpu->pc = 0x8330u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_C);
            static const uint32_t allowed[] = { 0x04041980u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041980u: {
            const uint32_t source_key = 0x04041980u;
            cpu->pc = 0x8333u;
            uint16_t value = 0x8000u;
            js_op_adc(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04041998u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041998u: {
            const uint32_t source_key = 0x04041998u;
            cpu->pc = 0x8334u;
            js_op_transfer(cpu, 'A');
            static const uint32_t allowed[] = { 0x040419A0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040419A0u: {
            const uint32_t source_key = 0x040419A0u;
            cpu->pc = 0x8335u;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040419A8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040419A8u: {
            const uint32_t source_key = 0x040419A8u;
            cpu->pc = 0x8336u;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, 1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040419B0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040419B0u: {
            const uint32_t source_key = 0x040419B0u;
            cpu->pc = 0x8338u;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long_y(cpu, bus, 0x04u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 1, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040419C0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040419C0u: {
            const uint32_t source_key = 0x040419C0u;
            cpu->pc = 0x833Bu;
            uint16_t value = 0x0093u;
            js_op_adc(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040419D8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040419D8u: {
            const uint32_t source_key = 0x040419D8u;
            cpu->pc = 0x833Cu;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x04041820u, 0x04041B38u, 0x04041D38u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041AD8u: {
            const uint32_t source_key = 0x04041AD8u;
            cpu->pc = 0x835Cu;
            if (!js_stack_push8(cpu, bus, cpu->dbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041AE0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041AE0u: {
            const uint32_t source_key = 0x04041AE0u;
            cpu->pc = 0x835Du;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041AE8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041AE8u: {
            const uint32_t source_key = 0x04041AE8u;
            cpu->pc = 0x835Eu;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04041AF0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041AF0u: {
            const uint32_t source_key = 0x04041AF0u;
            cpu->pc = 0x8361u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x8363u;
            static const uint32_t allowed[] = { 0x04041B18u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041B08u: {
            const uint32_t source_key = 0x04041B08u;
            cpu->pc = 0x8362u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04041B10u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041B10u: {
            const uint32_t source_key = 0x04041B10u;
            return js_stop_now(stop, JS_STOP_UNPROVED_RETURN, source_key, source_key);
        }
        case 0x04041B18u: {
            const uint32_t source_key = 0x04041B18u;
            cpu->pc = 0x8364u;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->y, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041B20u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041B20u: {
            const uint32_t source_key = 0x04041B20u;
            cpu->pc = 0x8367u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x8320u;
            static const uint32_t allowed[] = { 0x04041900u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041B38u: {
            const uint32_t source_key = 0x04041B38u;
            cpu->pc = 0x8368u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_y(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x04041B40u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041B40u: {
            const uint32_t source_key = 0x04041B40u;
            cpu->pc = 0x8369u;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->a, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041B48u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041B48u: {
            const uint32_t source_key = 0x04041B48u;
            cpu->pc = 0x836Au;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->x, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041B50u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041B50u: {
            const uint32_t source_key = 0x04041B50u;
            cpu->pc = 0x836Bu;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->y, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041B58u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041B58u: {
            const uint32_t source_key = 0x04041B58u;
            cpu->pc = 0x836Eu;
            if (!js_stack_push16(cpu, bus, 0xCB00u, 0, stop, source_key)) return JS_EXEC_STOP;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x04041B70u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041B70u: {
            const uint32_t source_key = 0x04041B70u;
            cpu->pc = 0x8371u;
            if (!js_stack_push16(cpu, bus, 0x1000u, 0, stop, source_key)) return JS_EXEC_STOP;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x04041B88u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041B88u: {
            const uint32_t source_key = 0x04041B88u;
            cpu->pc = 0x8374u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x83CEu;
            static const uint32_t allowed[] = { 0x04041E70u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041BA0u: {
            const uint32_t source_key = 0x04041BA0u;
            cpu->pc = 0x8375u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x04041BA8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041BA8u: {
            const uint32_t source_key = 0x04041BA8u;
            cpu->pc = 0x8376u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x04041BB0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041BB0u: {
            const uint32_t source_key = 0x04041BB0u;
            cpu->pc = 0x8377u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x04041BB8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041BB8u: {
            const uint32_t source_key = 0x04041BB8u;
            cpu->pc = 0x8378u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x04041BC0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041BC0u: {
            const uint32_t source_key = 0x04041BC0u;
            cpu->pc = 0x8379u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x04041BC8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041BC8u: {
            const uint32_t source_key = 0x04041BC8u;
            cpu->pc = 0x837Au;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x04041B08u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041CD8u: {
            const uint32_t source_key = 0x04041CD8u;
            cpu->pc = 0x839Cu;
            if (!js_stack_push8(cpu, bus, cpu->dbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041CE0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041CE0u: {
            const uint32_t source_key = 0x04041CE0u;
            cpu->pc = 0x839Du;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041CE8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041CE8u: {
            const uint32_t source_key = 0x04041CE8u;
            cpu->pc = 0x839Eu;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04041CF0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041CF0u: {
            const uint32_t source_key = 0x04041CF0u;
            cpu->pc = 0x83A1u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x83A3u;
            static const uint32_t allowed[] = { 0x04041D18u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041D08u: {
            const uint32_t source_key = 0x04041D08u;
            cpu->pc = 0x83A2u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04041D10u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041D10u: {
            const uint32_t source_key = 0x04041D10u;
            cpu->pc = 0x83A3u;
            { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x040CEB08u, 0x040CEBC0u, 0x040CEBE8u, 0x040CF458u, 0x040D2B48u, 0x040D7BD0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_RETURN);
        }
        case 0x04041D18u: {
            const uint32_t source_key = 0x04041D18u;
            cpu->pc = 0x83A4u;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->a, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041D20u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041D20u: {
            const uint32_t source_key = 0x04041D20u;
            cpu->pc = 0x83A7u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x8320u;
            static const uint32_t allowed[] = { 0x04041900u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041D38u: {
            const uint32_t source_key = 0x04041D38u;
            cpu->pc = 0x83A8u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_y(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x04041D40u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041D40u: {
            const uint32_t source_key = 0x04041D40u;
            cpu->pc = 0x83A9u;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->a, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041D48u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041D48u: {
            const uint32_t source_key = 0x04041D48u;
            cpu->pc = 0x83AAu;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->x, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041D50u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041D50u: {
            const uint32_t source_key = 0x04041D50u;
            cpu->pc = 0x83ABu;
            js_op_transfer(cpu, 'H');
            static const uint32_t allowed[] = { 0x04041D58u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041D58u: {
            const uint32_t source_key = 0x04041D58u;
            cpu->pc = 0x83ACu;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04041D60u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041D60u: {
            const uint32_t source_key = 0x04041D60u;
            cpu->pc = 0x83ADu;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04041D68u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041D68u: {
            const uint32_t source_key = 0x04041D68u;
            cpu->pc = 0x83AEu;
            js_op_transfer(cpu, 'B');
            static const uint32_t allowed[] = { 0x04041D70u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041D70u: {
            const uint32_t source_key = 0x04041D70u;
            cpu->pc = 0x83B1u;
            uint32_t ea = js_addr_abs_y(cpu, 0x8639u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04041D88u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041D88u: {
            const uint32_t source_key = 0x04041D88u;
            cpu->pc = 0x83B2u;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->a, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041D90u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041D90u: {
            const uint32_t source_key = 0x04041D90u;
            cpu->pc = 0x83B5u;
            if (!js_stack_push16(cpu, bus, 0xCB00u, 0, stop, source_key)) return JS_EXEC_STOP;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x04041DA8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041DA8u: {
            const uint32_t source_key = 0x04041DA8u;
            cpu->pc = 0x83B8u;
            if (!js_stack_push16(cpu, bus, 0x1000u, 0, stop, source_key)) return JS_EXEC_STOP;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x04041DC0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041DC0u: {
            const uint32_t source_key = 0x04041DC0u;
            cpu->pc = 0x83BBu;
            uint32_t ea = js_addr_abs_y(cpu, 0x863Bu);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04041DD8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041DD8u: {
            const uint32_t source_key = 0x04041DD8u;
            cpu->pc = 0x83BDu;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (5));
            static const uint32_t allowed[] = { 0x04041DE8u, 0x04041E10u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041DE8u: {
            const uint32_t source_key = 0x04041DE8u;
            cpu->pc = 0x83C0u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x852Cu;
            static const uint32_t allowed[] = { 0x04042960u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041E00u: {
            const uint32_t source_key = 0x04041E00u;
            cpu->pc = 0x83C2u;
            if (js_branch_condition(cpu, 'A')) cpu->pc = (uint16_t)(cpu->pc + (3));
            static const uint32_t allowed[] = { 0x04041E28u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041E10u: {
            const uint32_t source_key = 0x04041E10u;
            cpu->pc = 0x83C5u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x83CEu;
            static const uint32_t allowed[] = { 0x04041E70u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041E28u: {
            const uint32_t source_key = 0x04041E28u;
            cpu->pc = 0x83C6u;
            js_op_transfer(cpu, 'E');
            static const uint32_t allowed[] = { 0x04041E30u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041E30u: {
            const uint32_t source_key = 0x04041E30u;
            cpu->pc = 0x83C7u;
            js_op_transfer(cpu, 'F');
            static const uint32_t allowed[] = { 0x04041E38u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041E38u: {
            const uint32_t source_key = 0x04041E38u;
            cpu->pc = 0x83C8u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_C);
            static const uint32_t allowed[] = { 0x04041E40u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041E40u: {
            const uint32_t source_key = 0x04041E40u;
            cpu->pc = 0x83CBu;
            uint16_t value = 0x000Au;
            js_op_adc(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04041E58u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041E58u: {
            const uint32_t source_key = 0x04041E58u;
            cpu->pc = 0x83CCu;
            js_op_transfer(cpu, 'A');
            static const uint32_t allowed[] = { 0x04041E60u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041E60u: {
            const uint32_t source_key = 0x04041E60u;
            cpu->pc = 0x83CDu;
            js_op_transfer(cpu, 'G');
            static const uint32_t allowed[] = { 0x04041E68u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041E68u: {
            const uint32_t source_key = 0x04041E68u;
            cpu->pc = 0x83CEu;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x04041D08u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041E70u: {
            const uint32_t source_key = 0x04041E70u;
            cpu->pc = 0x83D1u;
            uint16_t value = 0x0080u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04041E88u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041E88u: {
            const uint32_t source_key = 0x04041E88u;
            cpu->pc = 0x83D4u;
            uint32_t ea = js_addr_abs(cpu, 0x2115u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041EA0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041EA0u: {
            const uint32_t source_key = 0x04041EA0u;
            cpu->pc = 0x83D6u;
            uint32_t ea = js_addr_stack_rel(cpu, 0x07u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04041EB0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041EB0u: {
            const uint32_t source_key = 0x04041EB0u;
            cpu->pc = 0x83D9u;
            uint32_t ea = js_addr_abs(cpu, 0x2116u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041EC8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041EC8u: {
            const uint32_t source_key = 0x04041EC8u;
            cpu->pc = 0x83DBu;
            uint32_t ea = js_addr_stack_rel(cpu, 0x09u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04041ED8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041ED8u: {
            const uint32_t source_key = 0x04041ED8u;
            cpu->pc = 0x83DDu;
            uint32_t ea = js_addr_dp(cpu, 0x30u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041EE8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041EE8u: {
            const uint32_t source_key = 0x04041EE8u;
            cpu->pc = 0x83DFu;
            uint32_t ea = js_addr_stack_rel(cpu, 0x0Bu);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04041EF8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041EF8u: {
            const uint32_t source_key = 0x04041EF8u;
            cpu->pc = 0x83E1u;
            uint32_t ea = js_addr_dp(cpu, 0x32u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041F08u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041F08u: {
            const uint32_t source_key = 0x04041F08u;
            cpu->pc = 0x83E3u;
            uint32_t ea = js_addr_stack_rel(cpu, 0x05u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04041F18u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041F18u: {
            const uint32_t source_key = 0x04041F18u;
            cpu->pc = 0x83E5u;
            uint32_t ea = js_addr_dp(cpu, 0x40u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041F28u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041F28u: {
            const uint32_t source_key = 0x04041F28u;
            cpu->pc = 0x83E7u;
            uint32_t ea = js_addr_dp(cpu, 0x3Cu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041F38u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041F38u: {
            const uint32_t source_key = 0x04041F38u;
            cpu->pc = 0x83EAu;
            uint16_t value = 0x007Eu;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04041F50u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041F50u: {
            const uint32_t source_key = 0x04041F50u;
            cpu->pc = 0x83ECu;
            uint32_t ea = js_addr_dp(cpu, 0x42u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041F60u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041F60u: {
            const uint32_t source_key = 0x04041F60u;
            cpu->pc = 0x83EEu;
            uint32_t ea = js_addr_dp(cpu, 0x3Eu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041F70u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041F70u: {
            const uint32_t source_key = 0x04041F70u;
            cpu->pc = 0x83F0u;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long(cpu, bus, 0x30u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 1, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04041F80u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041F80u: {
            const uint32_t source_key = 0x04041F80u;
            cpu->pc = 0x83F2u;
            uint32_t ea = js_addr_dp(cpu, 0x34u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041F90u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041F90u: {
            const uint32_t source_key = 0x04041F90u;
            cpu->pc = 0x83F4u;
            uint32_t ea = js_addr_dp(cpu, 0x30u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041FA0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041FA0u: {
            const uint32_t source_key = 0x04041FA0u;
            cpu->pc = 0x83F6u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (7));
            static const uint32_t allowed[] = { 0x04041FB0u, 0x04041FE8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041FB0u: {
            const uint32_t source_key = 0x04041FB0u;
            cpu->pc = 0x83F9u;
            uint16_t value = 0x8000u;
            js_op_load_y(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04041FC8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041FC8u: {
            const uint32_t source_key = 0x04041FC8u;
            cpu->pc = 0x83FBu;
            uint32_t ea = js_addr_dp(cpu, 0x30u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_y(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041FD8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041FD8u: {
            const uint32_t source_key = 0x04041FD8u;
            cpu->pc = 0x83FDu;
            uint32_t ea = js_addr_dp(cpu, 0x32u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04041FE8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041FE8u: {
            const uint32_t source_key = 0x04041FE8u;
            cpu->pc = 0x83FFu;
            js_op_sep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x04041FFAu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04041FFAu: {
            const uint32_t source_key = 0x04041FFAu;
            cpu->pc = 0x8401u;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long(cpu, bus, 0x30u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0404200Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        default: return JS_EXEC_NOT_MINE;
    }
}
