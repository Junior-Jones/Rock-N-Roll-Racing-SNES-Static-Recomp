#include "v05c_static_cpu.h"

JSExecResult js_v05c_shard_206E(JSCPU *cpu, const JSBus *bus, JSStop *stop) {
    (void)bus;
    (void)stop;
    switch (js_cpu_context_key(cpu)) {
        case 0x040DD0CBu: {
            const uint32_t source_key = 0x040DD0CBu;
            cpu->pc = 0xBA1Bu;
            js_op_rep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x040DD0D9u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DD0D9u: {
            const uint32_t source_key = 0x040DD0D9u;
            cpu->pc = 0xBA1Eu;
            uint16_t value = 0x0203u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040DD0F1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DD0F1u: {
            const uint32_t source_key = 0x040DD0F1u;
            cpu->pc = 0xBA21u;
            uint32_t ea = js_addr_abs(cpu, 0x02A0u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040DD109u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DD109u: {
            const uint32_t source_key = 0x040DD109u;
            cpu->pc = 0xBA24u;
            uint16_t value = 0x0004u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040DD121u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DD121u: {
            const uint32_t source_key = 0x040DD121u;
            cpu->pc = 0xBA27u;
            uint32_t ea = js_addr_abs(cpu, 0x02A2u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040DD139u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DD139u: {
            const uint32_t source_key = 0x040DD139u;
            cpu->pc = 0xBA2Au;
            uint16_t value = 0x2000u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040DD151u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DD151u: {
            const uint32_t source_key = 0x040DD151u;
            cpu->pc = 0xBA2Du;
            uint32_t ea = js_addr_abs(cpu, 0x0E06u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040DD169u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DD169u: {
            const uint32_t source_key = 0x040DD169u;
            cpu->pc = 0xBA30u;
            uint32_t ea = js_addr_abs(cpu, 0x0E0Au);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040DD181u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DD181u: {
            const uint32_t source_key = 0x040DD181u;
            cpu->pc = 0xBA33u;
            uint32_t ea = js_addr_abs(cpu, 0x0E08u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040DD199u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DD199u: {
            const uint32_t source_key = 0x040DD199u;
            cpu->pc = 0xBA36u;
            uint32_t ea = js_addr_abs(cpu, 0x0E0Cu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040DD1B1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DD1B1u: {
            const uint32_t source_key = 0x040DD1B1u;
            cpu->pc = 0xBA38u;
            js_op_sep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x040DD1C3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DD1C3u: {
            const uint32_t source_key = 0x040DD1C3u;
            cpu->pc = 0xBA3Bu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9C46u;
            static const uint32_t allowed[] = { 0x040CE233u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DD1DBu: {
            const uint32_t source_key = 0x040DD1DBu;
            cpu->pc = 0xBA3Du;
            uint16_t value = 0x0000u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040DD1EBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DD1EBu: {
            const uint32_t source_key = 0x040DD1EBu;
            cpu->pc = 0xBA40u;
            uint32_t ea = js_addr_abs(cpu, 0x035Bu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040DD203u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DD203u: {
            const uint32_t source_key = 0x040DD203u;
            cpu->pc = 0xBA42u;
            uint16_t value = 0x0008u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040DD213u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DD213u: {
            const uint32_t source_key = 0x040DD213u;
            cpu->pc = 0xBA45u;
            uint32_t ea = js_addr_abs(cpu, 0x035Cu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040DD22Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DD22Bu: {
            const uint32_t source_key = 0x040DD22Bu;
            cpu->pc = 0xBA47u;
            uint16_t value = 0x0009u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040DD23Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DD23Bu: {
            const uint32_t source_key = 0x040DD23Bu;
            cpu->pc = 0xBA4Au;
            uint32_t ea = js_addr_abs(cpu, 0x2109u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040DD253u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DD253u: {
            const uint32_t source_key = 0x040DD253u;
            cpu->pc = 0xBA4Cu;
            uint16_t value = 0x0081u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040DD263u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DD263u: {
            const uint32_t source_key = 0x040DD263u;
            cpu->pc = 0xBA4Fu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9DB1u;
            static const uint32_t allowed[] = { 0x040CED8Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DD27Bu: {
            const uint32_t source_key = 0x040DD27Bu;
            cpu->pc = 0xBA51u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040DD288u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DD288u: {
            const uint32_t source_key = 0x040DD288u;
            cpu->pc = 0xBA54u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xBDA9u;
            static const uint32_t allowed[] = { 0x040DED48u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DD2A0u: {
            const uint32_t source_key = 0x040DD2A0u;
            cpu->pc = 0xBA57u;
            uint16_t value = 0x0064u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040DD2B8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DD2B8u: {
            const uint32_t source_key = 0x040DD2B8u;
            cpu->pc = 0xBA5Au;
            uint16_t value = 0x0018u;
            js_op_load_x(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040DD2D0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DD2D0u: {
            const uint32_t source_key = 0x040DD2D0u;
            cpu->pc = 0xBA5Du;
            uint16_t value = 0x0019u;
            js_op_load_y(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040DD2E8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DD2E8u: {
            const uint32_t source_key = 0x040DD2E8u;
            cpu->pc = 0xBA60u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9D72u;
            static const uint32_t allowed[] = { 0x040CEB90u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        default: return JS_EXEC_NOT_MINE;
    }
}
