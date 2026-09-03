#include "v05c_static_cpu.h"

JSExecResult js_v05c_shard_207D(JSCPU *cpu, const JSBus *bus, JSStop *stop) {
    (void)bus;
    (void)stop;
    switch (js_cpu_context_key(cpu)) {
        case 0x040FA2A3u: {
            const uint32_t source_key = 0x040FA2A3u;
            cpu->pc = 0xF458u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0xA415u;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x040520ABu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA2C3u: {
            const uint32_t source_key = 0x040FA2C3u;
            cpu->pc = 0xF45Bu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9C46u;
            static const uint32_t allowed[] = { 0x040CE233u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA2DBu: {
            const uint32_t source_key = 0x040FA2DBu;
            cpu->pc = 0xF45Du;
            uint16_t value = 0x00A0u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FA2EBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA2EBu: {
            const uint32_t source_key = 0x040FA2EBu;
            cpu->pc = 0xF460u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9DB1u;
            static const uint32_t allowed[] = { 0x040CED8Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA303u: {
            const uint32_t source_key = 0x040FA303u;
            cpu->pc = 0xF462u;
            uint16_t value = 0x0000u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FA313u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA313u: {
            const uint32_t source_key = 0x040FA313u;
            cpu->pc = 0xF466u;
            uint32_t ea = js_addr_abs_long(0x7E2000u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FA333u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA333u: {
            const uint32_t source_key = 0x040FA333u;
            cpu->pc = 0xF46Au;
            uint32_t ea = js_addr_abs_long(0x7E2001u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FA353u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA353u: {
            const uint32_t source_key = 0x040FA353u;
            cpu->pc = 0xF46Cu;
            uint16_t value = 0x000Bu;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FA363u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA363u: {
            const uint32_t source_key = 0x040FA363u;
            cpu->pc = 0xF46Fu;
            uint32_t ea = js_addr_abs(cpu, 0x2105u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FA37Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA37Bu: {
            const uint32_t source_key = 0x040FA37Bu;
            cpu->pc = 0xF471u;
            uint16_t value = 0x0078u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FA38Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA38Bu: {
            const uint32_t source_key = 0x040FA38Bu;
            cpu->pc = 0xF474u;
            uint32_t ea = js_addr_abs(cpu, 0x2107u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FA3A3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA3A3u: {
            const uint32_t source_key = 0x040FA3A3u;
            cpu->pc = 0xF476u;
            uint16_t value = 0x0002u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FA3B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA3B3u: {
            const uint32_t source_key = 0x040FA3B3u;
            cpu->pc = 0xF479u;
            uint32_t ea = js_addr_abs(cpu, 0x210Bu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FA3CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA3CBu: {
            const uint32_t source_key = 0x040FA3CBu;
            cpu->pc = 0xF47Bu;
            uint16_t value = 0x0011u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FA3DBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA3DBu: {
            const uint32_t source_key = 0x040FA3DBu;
            cpu->pc = 0xF47Eu;
            uint32_t ea = js_addr_abs(cpu, 0x212Cu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FA3F3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA3F3u: {
            const uint32_t source_key = 0x040FA3F3u;
            cpu->pc = 0xF481u;
            uint32_t ea = js_addr_abs(cpu, 0x0F0Eu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FA40Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA40Bu: {
            const uint32_t source_key = 0x040FA40Bu;
            cpu->pc = 0xF483u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (16));
            static const uint32_t allowed[] = { 0x040FA41Bu, 0x040FA49Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA41Bu: {
            const uint32_t source_key = 0x040FA41Bu;
            cpu->pc = 0xF485u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FA428u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA428u: {
            const uint32_t source_key = 0x040FA428u;
            cpu->pc = 0xF488u;
            uint16_t value = 0x007Bu;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040FA440u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA440u: {
            const uint32_t source_key = 0x040FA440u;
            cpu->pc = 0xF48Bu;
            uint16_t value = 0x007Au;
            js_op_load_x(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040FA458u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA458u: {
            const uint32_t source_key = 0x040FA458u;
            cpu->pc = 0xF48Eu;
            uint16_t value = 0x007Cu;
            js_op_load_y(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040FA470u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA470u: {
            const uint32_t source_key = 0x040FA470u;
            cpu->pc = 0xF491u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9D72u;
            static const uint32_t allowed[] = { 0x040CEB90u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA49Bu: {
            const uint32_t source_key = 0x040FA49Bu;
            cpu->pc = 0xF495u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FA4A8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA4A8u: {
            const uint32_t source_key = 0x040FA4A8u;
            cpu->pc = 0xF498u;
            uint16_t value = 0x0001u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040FA4C0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA4C0u: {
            const uint32_t source_key = 0x040FA4C0u;
            cpu->pc = 0xF49Bu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9E50u;
            static const uint32_t allowed[] = { 0x040CF280u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA4D8u: {
            const uint32_t source_key = 0x040FA4D8u;
            cpu->pc = 0xF49Eu;
            uint16_t value = 0x0001u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040FA4F0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA4F0u: {
            const uint32_t source_key = 0x040FA4F0u;
            cpu->pc = 0xF4A1u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9E12u;
            static const uint32_t allowed[] = { 0x040CF090u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA508u: {
            const uint32_t source_key = 0x040FA508u;
            cpu->pc = 0xF4A3u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FA51Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA51Bu: {
            const uint32_t source_key = 0x040FA51Bu;
            cpu->pc = 0xF4A6u;
            uint32_t ea = js_addr_abs(cpu, 0x0BFFu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FA533u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA533u: {
            const uint32_t source_key = 0x040FA533u;
            cpu->pc = 0xF4A9u;
            uint32_t ea = js_addr_abs(cpu, 0x033Cu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FA54Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA54Bu: {
            const uint32_t source_key = 0x040FA54Bu;
            cpu->pc = 0xF4ABu;
            uint16_t value = 0x000Cu;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FA55Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA55Bu: {
            const uint32_t source_key = 0x040FA55Bu;
            cpu->pc = 0xF4AEu;
            uint32_t ea = js_addr_abs(cpu, 0x0355u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FA573u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA573u: {
            const uint32_t source_key = 0x040FA573u;
            cpu->pc = 0xF4B0u;
            uint16_t value = 0x0081u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FA583u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA583u: {
            const uint32_t source_key = 0x040FA583u;
            cpu->pc = 0xF4B3u;
            uint32_t ea = js_addr_abs(cpu, 0x4200u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FA59Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA59Bu: {
            const uint32_t source_key = 0x040FA59Bu;
            cpu->pc = 0xF4B6u;
            uint32_t ea = js_addr_abs(cpu, 0x0F0Eu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FA5B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA5B3u: {
            const uint32_t source_key = 0x040FA5B3u;
            cpu->pc = 0xF4B8u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (36));
            static const uint32_t allowed[] = { 0x040FA5C3u, 0x040FA6E3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA5C3u: {
            const uint32_t source_key = 0x040FA5C3u;
            cpu->pc = 0xF4BBu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9C8Cu;
            static const uint32_t allowed[] = { 0x040CE463u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA5DBu: {
            const uint32_t source_key = 0x040FA5DBu;
            cpu->pc = 0xF4BEu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9CB6u;
            static const uint32_t allowed[] = { 0x040CE5B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA5F3u: {
            const uint32_t source_key = 0x040FA5F3u;
            cpu->pc = 0xF4C2u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0xA3A0u;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x04051D03u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA613u: {
            const uint32_t source_key = 0x040FA613u;
            cpu->pc = 0xF4C5u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9F5Cu;
            static const uint32_t allowed[] = { 0x040CFAE3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA62Bu: {
            const uint32_t source_key = 0x040FA62Bu;
            cpu->pc = 0xF4C7u;
            uint16_t value = 0x0003u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FA63Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA63Bu: {
            const uint32_t source_key = 0x040FA63Bu;
            cpu->pc = 0xF4CAu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF5EDu;
            static const uint32_t allowed[] = { 0x040FAF6Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA653u: {
            const uint32_t source_key = 0x040FA653u;
            cpu->pc = 0xF4CDu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF538u;
            static const uint32_t allowed[] = { 0x040FA9C3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA66Bu: {
            const uint32_t source_key = 0x040FA66Bu;
            cpu->pc = 0xF4D0u;
            uint32_t ea = js_addr_abs(cpu, 0x0330u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FA683u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA683u: {
            const uint32_t source_key = 0x040FA683u;
            cpu->pc = 0xF4D2u;
            uint16_t value = 0x000Au;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FA693u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA693u: {
            const uint32_t source_key = 0x040FA693u;
            cpu->pc = 0xF4D5u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF5EDu;
            static const uint32_t allowed[] = { 0x040FAF6Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA6ABu: {
            const uint32_t source_key = 0x040FA6ABu;
            cpu->pc = 0xF4D7u;
            if (js_branch_condition(cpu, 'C')) cpu->pc = (uint16_t)(cpu->pc + (51));
            static const uint32_t allowed[] = { 0x040FA6BBu, 0x040FA853u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA6BBu: {
            const uint32_t source_key = 0x040FA6BBu;
            cpu->pc = 0xF4DAu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF650u;
            static const uint32_t allowed[] = { 0x040FB283u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA6D3u: {
            const uint32_t source_key = 0x040FA6D3u;
            cpu->pc = 0xF4DCu;
            if (js_branch_condition(cpu, 'A')) cpu->pc = (uint16_t)(cpu->pc + (26));
            static const uint32_t allowed[] = { 0x040FA7B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA6E3u: {
            const uint32_t source_key = 0x040FA6E3u;
            cpu->pc = 0xF4DEu;
            uint16_t value = 0x0010u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FA6F3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA6F3u: {
            const uint32_t source_key = 0x040FA6F3u;
            cpu->pc = 0xF4E1u;
            uint32_t ea = js_addr_abs(cpu, 0x212Cu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FA70Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA70Bu: {
            const uint32_t source_key = 0x040FA70Bu;
            cpu->pc = 0xF4E3u;
            uint16_t value = 0x0006u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FA71Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA71Bu: {
            const uint32_t source_key = 0x040FA71Bu;
            cpu->pc = 0xF4E6u;
            uint32_t ea = js_addr_abs(cpu, 0x02C0u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FA733u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA733u: {
            const uint32_t source_key = 0x040FA733u;
            cpu->pc = 0xF4E9u;
            uint32_t ea = js_addr_abs(cpu, 0x02C1u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FA74Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA74Bu: {
            const uint32_t source_key = 0x040FA74Bu;
            cpu->pc = 0xF4ECu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF7F7u;
            static const uint32_t allowed[] = { 0x040FBFBBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA763u: {
            const uint32_t source_key = 0x040FA763u;
            cpu->pc = 0xF4EFu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9C8Cu;
            static const uint32_t allowed[] = { 0x040CE463u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA77Bu: {
            const uint32_t source_key = 0x040FA77Bu;
            cpu->pc = 0xF4F2u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9CB6u;
            static const uint32_t allowed[] = { 0x040CE5B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA793u: {
            const uint32_t source_key = 0x040FA793u;
            cpu->pc = 0xF4F6u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0xA3A0u;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x04051D03u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA7B3u: {
            const uint32_t source_key = 0x040FA7B3u;
            cpu->pc = 0xF4F9u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF6A4u;
            static const uint32_t allowed[] = { 0x040FB523u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA7CBu: {
            const uint32_t source_key = 0x040FA7CBu;
            cpu->pc = 0xF4FBu;
            if (js_branch_condition(cpu, 'D')) cpu->pc = (uint16_t)(cpu->pc + (15));
            static const uint32_t allowed[] = { 0x040FA7DBu, 0x040FA853u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA7DBu: {
            const uint32_t source_key = 0x040FA7DBu;
            cpu->pc = 0xF4FEu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF786u;
            static const uint32_t allowed[] = { 0x040FBC33u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA7F3u: {
            const uint32_t source_key = 0x040FA7F3u;
            cpu->pc = 0xF500u;
            if (js_branch_condition(cpu, 'D')) cpu->pc = (uint16_t)(cpu->pc + (10));
            static const uint32_t allowed[] = { 0x040FA803u, 0x040FA853u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA803u: {
            const uint32_t source_key = 0x040FA803u;
            cpu->pc = 0xF503u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF701u;
            static const uint32_t allowed[] = { 0x040FB80Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA81Bu: {
            const uint32_t source_key = 0x040FA81Bu;
            cpu->pc = 0xF505u;
            if (js_branch_condition(cpu, 'D')) cpu->pc = (uint16_t)(cpu->pc + (5));
            static const uint32_t allowed[] = { 0x040FA82Bu, 0x040FA853u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA82Bu: {
            const uint32_t source_key = 0x040FA82Bu;
            cpu->pc = 0xF508u;
            uint32_t ea = js_addr_abs(cpu, 0x0F0Eu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FA843u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA843u: {
            const uint32_t source_key = 0x040FA843u;
            cpu->pc = 0xF50Au;
            if (js_branch_condition(cpu, 'A')) cpu->pc = (uint16_t)(cpu->pc + (8));
            static const uint32_t allowed[] = { 0x040FA893u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA853u: {
            const uint32_t source_key = 0x040FA853u;
            cpu->pc = 0xF50Du;
            uint32_t ea = js_addr_abs(cpu, 0x0F0Eu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FA86Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA86Bu: {
            const uint32_t source_key = 0x040FA86Bu;
            cpu->pc = 0xF50Fu;
            uint16_t value = 0x0001u;
            js_op_ora(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FA87Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA87Bu: {
            const uint32_t source_key = 0x040FA87Bu;
            cpu->pc = 0xF512u;
            uint32_t ea = js_addr_abs(cpu, 0x0F0Eu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FA893u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA893u: {
            const uint32_t source_key = 0x040FA893u;
            cpu->pc = 0xF514u;
            uint16_t value = 0x0000u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FA8A3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA8A3u: {
            const uint32_t source_key = 0x040FA8A3u;
            cpu->pc = 0xF517u;
            uint32_t ea = js_addr_abs(cpu, 0x0355u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FA8BBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA8BBu: {
            const uint32_t source_key = 0x040FA8BBu;
            cpu->pc = 0xF51Bu;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0xA3EAu;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x04051F53u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA8DBu: {
            const uint32_t source_key = 0x040FA8DBu;
            cpu->pc = 0xF51Du;
            uint16_t value = 0x0001u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FA8EBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA8EBu: {
            const uint32_t source_key = 0x040FA8EBu;
            cpu->pc = 0xF520u;
            uint32_t ea = js_addr_abs(cpu, 0x2107u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FA903u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA903u: {
            const uint32_t source_key = 0x040FA903u;
            cpu->pc = 0xF522u;
            uint16_t value = 0x0011u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FA913u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA913u: {
            const uint32_t source_key = 0x040FA913u;
            cpu->pc = 0xF525u;
            uint32_t ea = js_addr_abs(cpu, 0x2108u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FA92Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA92Bu: {
            const uint32_t source_key = 0x040FA92Bu;
            cpu->pc = 0xF527u;
            uint16_t value = 0x0044u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FA93Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA93Bu: {
            const uint32_t source_key = 0x040FA93Bu;
            cpu->pc = 0xF52Au;
            uint32_t ea = js_addr_abs(cpu, 0x210Bu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FA953u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA953u: {
            const uint32_t source_key = 0x040FA953u;
            cpu->pc = 0xF52Cu;
            uint16_t value = 0x0009u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FA963u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA963u: {
            const uint32_t source_key = 0x040FA963u;
            cpu->pc = 0xF52Fu;
            uint32_t ea = js_addr_abs(cpu, 0x2105u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FA97Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA97Bu: {
            const uint32_t source_key = 0x040FA97Bu;
            cpu->pc = 0xF531u;
            uint16_t value = 0x0015u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FA98Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA98Bu: {
            const uint32_t source_key = 0x040FA98Bu;
            cpu->pc = 0xF534u;
            uint32_t ea = js_addr_abs(cpu, 0x212Cu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FA9A3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA9A3u: {
            const uint32_t source_key = 0x040FA9A3u;
            cpu->pc = 0xF537u;
            uint32_t ea = js_addr_abs(cpu, 0x2131u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FA9BBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA9BBu: {
            const uint32_t source_key = 0x040FA9BBu;
            return js_stop_now(stop, JS_STOP_UNPROVED_RETURN, source_key, source_key);
        }
        case 0x040FA9C3u: {
            const uint32_t source_key = 0x040FA9C3u;
            cpu->pc = 0xF53Au;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FA9D0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA9D0u: {
            const uint32_t source_key = 0x040FA9D0u;
            cpu->pc = 0xF53Du;
            uint16_t value = 0xFF9Cu;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040FA9E8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FA9E8u: {
            const uint32_t source_key = 0x040FA9E8u;
            cpu->pc = 0xF540u;
            uint32_t ea = js_addr_abs(cpu, 0x02C0u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FAA00u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAA00u: {
            const uint32_t source_key = 0x040FAA00u;
            cpu->pc = 0xF543u;
            uint16_t value = 0x0004u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040FAA18u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAA18u: {
            const uint32_t source_key = 0x040FAA18u;
            cpu->pc = 0xF546u;
            uint32_t ea = js_addr_abs(cpu, 0x02C3u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FAA30u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAA30u: {
            const uint32_t source_key = 0x040FAA30u;
            cpu->pc = 0xF548u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FAA43u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAA43u: {
            const uint32_t source_key = 0x040FAA43u;
            cpu->pc = 0xF54Bu;
            uint32_t ea = js_addr_abs(cpu, 0x02C2u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FAA5Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAA5Bu: {
            const uint32_t source_key = 0x040FAA5Bu;
            cpu->pc = 0xF54Eu;
            uint32_t ea = js_addr_abs(cpu, 0x02C5u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FAA73u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAA73u: {
            const uint32_t source_key = 0x040FAA73u;
            cpu->pc = 0xF551u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF55Fu;
            static const uint32_t allowed[] = { 0x040FAAFBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAA8Bu: {
            const uint32_t source_key = 0x040FAA8Bu;
            cpu->pc = 0xF553u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FAA98u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAA98u: {
            const uint32_t source_key = 0x040FAA98u;
            cpu->pc = 0xF556u;
            uint16_t value = 0xFFF8u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040FAAB0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAAB0u: {
            const uint32_t source_key = 0x040FAAB0u;
            cpu->pc = 0xF559u;
            uint32_t ea = js_addr_abs(cpu, 0x02C3u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FAAC8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAAC8u: {
            const uint32_t source_key = 0x040FAAC8u;
            cpu->pc = 0xF55Bu;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FAADBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAADBu: {
            const uint32_t source_key = 0x040FAADBu;
            cpu->pc = 0xF55Eu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF586u;
            static const uint32_t allowed[] = { 0x040FAC33u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAAF3u: {
            const uint32_t source_key = 0x040FAAF3u;
            cpu->pc = 0xF55Fu;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FA66Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAAF8u: {
            const uint32_t source_key = 0x040FAAF8u;
            cpu->pc = 0xF562u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF5BDu;
            static const uint32_t allowed[] = { 0x040FADE8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAAFBu: {
            const uint32_t source_key = 0x040FAAFBu;
            cpu->pc = 0xF562u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF5BDu;
            static const uint32_t allowed[] = { 0x040FADEBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAB13u: {
            const uint32_t source_key = 0x040FAB13u;
            cpu->pc = 0xF565u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF7F7u;
            static const uint32_t allowed[] = { 0x040FBFBBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAB2Bu: {
            const uint32_t source_key = 0x040FAB2Bu;
            cpu->pc = 0xF568u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9C8Cu;
            static const uint32_t allowed[] = { 0x040CE463u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAB43u: {
            const uint32_t source_key = 0x040FAB43u;
            cpu->pc = 0xF56Bu;
            uint32_t ea = js_addr_abs(cpu, 0x0240u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FAB5Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAB5Bu: {
            const uint32_t source_key = 0x040FAB5Bu;
            cpu->pc = 0xF56Du;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-5));
            static const uint32_t allowed[] = { 0x040FAB43u, 0x040FAB6Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAB6Bu: {
            const uint32_t source_key = 0x040FAB6Bu;
            cpu->pc = 0xF56Fu;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FAB78u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAB78u: {
            const uint32_t source_key = 0x040FAB78u;
            cpu->pc = 0xF572u;
            uint32_t ea = js_addr_abs(cpu, 0x02C0u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040FAB90u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAB90u: {
            const uint32_t source_key = 0x040FAB90u;
            cpu->pc = 0xF574u;
            if (js_branch_condition(cpu, 'M')) cpu->pc = (uint16_t)(cpu->pc + (-21));
            static const uint32_t allowed[] = { 0x040FAAF8u, 0x040FABA0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FABA0u: {
            const uint32_t source_key = 0x040FABA0u;
            cpu->pc = 0xF577u;
            uint16_t value = 0x007Eu;
            js_op_compare(cpu, cpu->a, value, 16u);
            static const uint32_t allowed[] = { 0x040FABB8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FABB8u: {
            const uint32_t source_key = 0x040FABB8u;
            cpu->pc = 0xF579u;
            if (js_branch_condition(cpu, 'C')) cpu->pc = (uint16_t)(cpu->pc + (-26));
            static const uint32_t allowed[] = { 0x040FAAF8u, 0x040FABC8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FABC8u: {
            const uint32_t source_key = 0x040FABC8u;
            cpu->pc = 0xF57Bu;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FABDBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FABDBu: {
            const uint32_t source_key = 0x040FABDBu;
            cpu->pc = 0xF57Du;
            uint16_t value = 0x000Bu;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FABEBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FABEBu: {
            const uint32_t source_key = 0x040FABEBu;
            cpu->pc = 0xF581u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0xF926u;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x0407C933u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAC0Bu: {
            const uint32_t source_key = 0x040FAC0Bu;
            cpu->pc = 0xF585u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0xF982u;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x0407CC13u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAC2Bu: {
            const uint32_t source_key = 0x040FAC2Bu;
            cpu->pc = 0xF586u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FAA8Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAC30u: {
            const uint32_t source_key = 0x040FAC30u;
            cpu->pc = 0xF589u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF5BDu;
            static const uint32_t allowed[] = { 0x040FADE8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAC33u: {
            const uint32_t source_key = 0x040FAC33u;
            cpu->pc = 0xF589u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF5BDu;
            static const uint32_t allowed[] = { 0x040FADEBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAC4Bu: {
            const uint32_t source_key = 0x040FAC4Bu;
            cpu->pc = 0xF58Cu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF7F7u;
            static const uint32_t allowed[] = { 0x040FBFBBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAC63u: {
            const uint32_t source_key = 0x040FAC63u;
            cpu->pc = 0xF58Fu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9C8Cu;
            static const uint32_t allowed[] = { 0x040CE463u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAC7Bu: {
            const uint32_t source_key = 0x040FAC7Bu;
            cpu->pc = 0xF592u;
            uint32_t ea = js_addr_abs(cpu, 0x0240u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FAC93u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAC93u: {
            const uint32_t source_key = 0x040FAC93u;
            cpu->pc = 0xF594u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-5));
            static const uint32_t allowed[] = { 0x040FAC7Bu, 0x040FACA3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FACA3u: {
            const uint32_t source_key = 0x040FACA3u;
            cpu->pc = 0xF596u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FACB0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FACB0u: {
            const uint32_t source_key = 0x040FACB0u;
            cpu->pc = 0xF599u;
            uint32_t ea = js_addr_abs(cpu, 0x02C3u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040FACC8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FACC8u: {
            const uint32_t source_key = 0x040FACC8u;
            cpu->pc = 0xF59Bu;
            if (js_branch_condition(cpu, 'M')) cpu->pc = (uint16_t)(cpu->pc + (-21));
            static const uint32_t allowed[] = { 0x040FAC30u, 0x040FACD8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FACD8u: {
            const uint32_t source_key = 0x040FACD8u;
            cpu->pc = 0xF59Eu;
            uint32_t ea = js_addr_abs(cpu, 0x02C0u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040FACF0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FACF0u: {
            const uint32_t source_key = 0x040FACF0u;
            cpu->pc = 0xF59Fu;
            cpu->p = (uint8_t)(cpu->p | JS_P_C);
            static const uint32_t allowed[] = { 0x040FACF8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FACF8u: {
            const uint32_t source_key = 0x040FACF8u;
            cpu->pc = 0xF5A2u;
            uint16_t value = 0x0004u;
            js_op_sbc(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040FAD10u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAD10u: {
            const uint32_t source_key = 0x040FAD10u;
            cpu->pc = 0xF5A5u;
            uint32_t ea = js_addr_abs(cpu, 0x02C0u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FAD28u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAD28u: {
            const uint32_t source_key = 0x040FAD28u;
            cpu->pc = 0xF5A7u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FAD3Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAD3Bu: {
            const uint32_t source_key = 0x040FAD3Bu;
            cpu->pc = 0xF5AAu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF7F7u;
            static const uint32_t allowed[] = { 0x040FBFBBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAD53u: {
            const uint32_t source_key = 0x040FAD53u;
            cpu->pc = 0xF5ADu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9C8Cu;
            static const uint32_t allowed[] = { 0x040CE463u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAD6Bu: {
            const uint32_t source_key = 0x040FAD6Bu;
            cpu->pc = 0xF5B0u;
            uint32_t ea = js_addr_abs(cpu, 0x0240u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FAD83u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAD83u: {
            const uint32_t source_key = 0x040FAD83u;
            cpu->pc = 0xF5B2u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-5));
            static const uint32_t allowed[] = { 0x040FAD6Bu, 0x040FAD93u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAD93u: {
            const uint32_t source_key = 0x040FAD93u;
            cpu->pc = 0xF5B4u;
            uint16_t value = 0x0007u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FADA3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FADA3u: {
            const uint32_t source_key = 0x040FADA3u;
            cpu->pc = 0xF5B8u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0xF926u;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x0407C933u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FADC3u: {
            const uint32_t source_key = 0x040FADC3u;
            cpu->pc = 0xF5BCu;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0xF982u;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x0407CC13u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FADE3u: {
            const uint32_t source_key = 0x040FADE3u;
            cpu->pc = 0xF5BDu;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FAAF3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FADE8u: {
            const uint32_t source_key = 0x040FADE8u;
            cpu->pc = 0xF5BFu;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FADFBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FADEBu: {
            const uint32_t source_key = 0x040FADEBu;
            cpu->pc = 0xF5BFu;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FADFBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FADFBu: {
            const uint32_t source_key = 0x040FADFBu;
            cpu->pc = 0xF5C2u;
            uint32_t ea = js_addr_abs(cpu, 0x02C2u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FAE13u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAE13u: {
            const uint32_t source_key = 0x040FAE13u;
            cpu->pc = 0xF5C3u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_C);
            static const uint32_t allowed[] = { 0x040FAE1Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAE1Bu: {
            const uint32_t source_key = 0x040FAE1Bu;
            cpu->pc = 0xF5C6u;
            uint32_t ea = js_addr_abs(cpu, 0x02C5u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_adc(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FAE33u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAE33u: {
            const uint32_t source_key = 0x040FAE33u;
            cpu->pc = 0xF5C9u;
            uint32_t ea = js_addr_abs(cpu, 0x02C2u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FAE4Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAE4Bu: {
            const uint32_t source_key = 0x040FAE4Bu;
            cpu->pc = 0xF5CBu;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FAE58u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAE58u: {
            const uint32_t source_key = 0x040FAE58u;
            cpu->pc = 0xF5CEu;
            uint32_t ea = js_addr_abs(cpu, 0x02C0u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040FAE70u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAE70u: {
            const uint32_t source_key = 0x040FAE70u;
            cpu->pc = 0xF5D1u;
            uint32_t ea = js_addr_abs(cpu, 0x02C3u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_adc(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040FAE88u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAE88u: {
            const uint32_t source_key = 0x040FAE88u;
            cpu->pc = 0xF5D4u;
            uint32_t ea = js_addr_abs(cpu, 0x02C0u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FAEA0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAEA0u: {
            const uint32_t source_key = 0x040FAEA0u;
            cpu->pc = 0xF5D6u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FAEB3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAEB3u: {
            const uint32_t source_key = 0x040FAEB3u;
            cpu->pc = 0xF5D9u;
            uint32_t ea = js_addr_abs(cpu, 0x02C5u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FAECBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAECBu: {
            const uint32_t source_key = 0x040FAECBu;
            cpu->pc = 0xF5DAu;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_C);
            static const uint32_t allowed[] = { 0x040FAED3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAED3u: {
            const uint32_t source_key = 0x040FAED3u;
            cpu->pc = 0xF5DCu;
            uint16_t value = 0x0040u;
            js_op_adc(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FAEE3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAEE3u: {
            const uint32_t source_key = 0x040FAEE3u;
            cpu->pc = 0xF5DFu;
            uint32_t ea = js_addr_abs(cpu, 0x02C5u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FAEFBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAEFBu: {
            const uint32_t source_key = 0x040FAEFBu;
            cpu->pc = 0xF5E1u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FAF08u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAF08u: {
            const uint32_t source_key = 0x040FAF08u;
            cpu->pc = 0xF5E4u;
            uint32_t ea = js_addr_abs(cpu, 0x02C3u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040FAF20u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAF20u: {
            const uint32_t source_key = 0x040FAF20u;
            cpu->pc = 0xF5E7u;
            uint16_t value = 0x0000u;
            js_op_adc(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040FAF38u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAF38u: {
            const uint32_t source_key = 0x040FAF38u;
            cpu->pc = 0xF5EAu;
            uint32_t ea = js_addr_abs(cpu, 0x02C3u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FAF50u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAF50u: {
            const uint32_t source_key = 0x040FAF50u;
            cpu->pc = 0xF5ECu;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FAF63u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAF63u: {
            const uint32_t source_key = 0x040FAF63u;
            cpu->pc = 0xF5EDu;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FAB13u, 0x040FAC4Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAF6Bu: {
            const uint32_t source_key = 0x040FAF6Bu;
            cpu->pc = 0xF5F0u;
            uint32_t ea = js_addr_abs(cpu, 0x0289u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FAF83u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAF83u: {
            const uint32_t source_key = 0x040FAF83u;
            cpu->pc = 0xF5F2u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FAF90u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAF90u: {
            const uint32_t source_key = 0x040FAF90u;
            cpu->pc = 0xF5F5u;
            uint16_t value = 0x00FFu;
            js_op_and(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040FAFA8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAFA8u: {
            const uint32_t source_key = 0x040FAFA8u;
            cpu->pc = 0xF5F6u;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x040FAFB0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAFB0u: {
            const uint32_t source_key = 0x040FAFB0u;
            cpu->pc = 0xF5F7u;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x040FAFB8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAFB8u: {
            const uint32_t source_key = 0x040FAFB8u;
            cpu->pc = 0xF5F8u;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x040FAFC0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAFC0u: {
            const uint32_t source_key = 0x040FAFC0u;
            cpu->pc = 0xF5F9u;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x040FAFC8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAFC8u: {
            const uint32_t source_key = 0x040FAFC8u;
            cpu->pc = 0xF5FAu;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x040FAFD0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAFD0u: {
            const uint32_t source_key = 0x040FAFD0u;
            cpu->pc = 0xF5FBu;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x040FAFD8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAFD8u: {
            const uint32_t source_key = 0x040FAFD8u;
            cpu->pc = 0xF5FEu;
            uint32_t ea = js_addr_abs(cpu, 0x02C0u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FAFF0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAFF0u: {
            const uint32_t source_key = 0x040FAFF0u;
            cpu->pc = 0xF600u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FB000u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FAFF3u: {
            const uint32_t source_key = 0x040FAFF3u;
            cpu->pc = 0xF600u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FB000u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB000u: {
            const uint32_t source_key = 0x040FB000u;
            cpu->pc = 0xF603u;
            uint32_t ea = js_addr_abs(cpu, 0x02C0u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, -1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB018u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB018u: {
            const uint32_t source_key = 0x040FB018u;
            cpu->pc = 0xF605u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FB02Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB02Bu: {
            const uint32_t source_key = 0x040FB02Bu;
            cpu->pc = 0xF607u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (30));
            static const uint32_t allowed[] = { 0x040FB03Bu, 0x040FB12Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB03Bu: {
            const uint32_t source_key = 0x040FB03Bu;
            cpu->pc = 0xF60Au;
            uint32_t ea = js_addr_abs(cpu, 0x0330u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FB053u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB053u: {
            const uint32_t source_key = 0x040FB053u;
            cpu->pc = 0xF60Cu;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (5));
            static const uint32_t allowed[] = { 0x040FB063u, 0x040FB08Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB063u: {
            const uint32_t source_key = 0x040FB063u;
            cpu->pc = 0xF60Fu;
            uint32_t ea = js_addr_abs(cpu, 0x0289u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FB07Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB07Bu: {
            const uint32_t source_key = 0x040FB07Bu;
            cpu->pc = 0xF611u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (10));
            static const uint32_t allowed[] = { 0x040FB08Bu, 0x040FB0DBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB08Bu: {
            const uint32_t source_key = 0x040FB08Bu;
            cpu->pc = 0xF614u;
            uint32_t ea = js_addr_abs(cpu, 0x127Eu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FB0A3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB0A3u: {
            const uint32_t source_key = 0x040FB0A3u;
            cpu->pc = 0xF617u;
            uint32_t ea = js_addr_abs(cpu, 0x127Eu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_compare(cpu, cpu->a, value, 8u);
            static const uint32_t allowed[] = { 0x040FB0BBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB0BBu: {
            const uint32_t source_key = 0x040FB0BBu;
            cpu->pc = 0xF619u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (-5));
            static const uint32_t allowed[] = { 0x040FB0A3u, 0x040FB0CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB0CBu: {
            const uint32_t source_key = 0x040FB0CBu;
            cpu->pc = 0xF61Bu;
            if (js_branch_condition(cpu, 'A')) cpu->pc = (uint16_t)(cpu->pc + (-29));
            static const uint32_t allowed[] = { 0x040FAFF3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB0DBu: {
            const uint32_t source_key = 0x040FB0DBu;
            cpu->pc = 0xF61Fu;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0xFB3Eu;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x0407D9F3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB0FBu: {
            const uint32_t source_key = 0x040FB0FBu;
            cpu->pc = 0xF623u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0xF982u;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x0407CC13u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB11Bu: {
            const uint32_t source_key = 0x040FB11Bu;
            cpu->pc = 0xF624u;
            cpu->p = (uint8_t)(cpu->p | JS_P_C);
            static const uint32_t allowed[] = { 0x040FB123u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB123u: {
            const uint32_t source_key = 0x040FB123u;
            cpu->pc = 0xF625u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FA653u, 0x040FA6ABu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB12Bu: {
            const uint32_t source_key = 0x040FB12Bu;
            cpu->pc = 0xF626u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_C);
            static const uint32_t allowed[] = { 0x040FB133u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB133u: {
            const uint32_t source_key = 0x040FB133u;
            cpu->pc = 0xF627u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FA653u, 0x040FA6ABu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB283u: {
            const uint32_t source_key = 0x040FB283u;
            cpu->pc = 0xF653u;
            uint32_t ea = js_addr_abs(cpu, 0x2130u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB29Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB29Bu: {
            const uint32_t source_key = 0x040FB29Bu;
            cpu->pc = 0xF655u;
            uint16_t value = 0x00E0u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FB2ABu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB2ABu: {
            const uint32_t source_key = 0x040FB2ABu;
            cpu->pc = 0xF658u;
            uint32_t ea = js_addr_abs(cpu, 0x02C0u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB2C3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB2C3u: {
            const uint32_t source_key = 0x040FB2C3u;
            cpu->pc = 0xF65Bu;
            uint32_t ea = js_addr_abs(cpu, 0x2132u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB2DBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB2DBu: {
            const uint32_t source_key = 0x040FB2DBu;
            cpu->pc = 0xF65Du;
            uint16_t value = 0x00AFu;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FB2EBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB2EBu: {
            const uint32_t source_key = 0x040FB2EBu;
            cpu->pc = 0xF660u;
            uint32_t ea = js_addr_abs(cpu, 0x2131u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB303u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB303u: {
            const uint32_t source_key = 0x040FB303u;
            cpu->pc = 0xF663u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9C8Cu;
            static const uint32_t allowed[] = { 0x040CE463u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB31Bu: {
            const uint32_t source_key = 0x040FB31Bu;
            cpu->pc = 0xF666u;
            uint32_t ea = js_addr_abs(cpu, 0x0240u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FB333u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB333u: {
            const uint32_t source_key = 0x040FB333u;
            cpu->pc = 0xF668u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-5));
            static const uint32_t allowed[] = { 0x040FB31Bu, 0x040FB343u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB343u: {
            const uint32_t source_key = 0x040FB343u;
            cpu->pc = 0xF66Bu;
            uint32_t ea = js_addr_abs(cpu, 0x02C0u);
            uint16_t original = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
            uint16_t result = js_op_incdec(cpu, original, 1, 8u);
            if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB35Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB35Bu: {
            const uint32_t source_key = 0x040FB35Bu;
            cpu->pc = 0xF66Eu;
            uint32_t ea = js_addr_abs(cpu, 0x02C0u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FB373u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB373u: {
            const uint32_t source_key = 0x040FB373u;
            cpu->pc = 0xF671u;
            uint32_t ea = js_addr_abs(cpu, 0x2132u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB38Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB38Bu: {
            const uint32_t source_key = 0x040FB38Bu;
            cpu->pc = 0xF673u;
            uint16_t value = 0x00FFu;
            js_op_compare(cpu, cpu->a, value, 8u);
            static const uint32_t allowed[] = { 0x040FB39Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB39Bu: {
            const uint32_t source_key = 0x040FB39Bu;
            cpu->pc = 0xF675u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-21));
            static const uint32_t allowed[] = { 0x040FB303u, 0x040FB3ABu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB3ABu: {
            const uint32_t source_key = 0x040FB3ABu;
            cpu->pc = 0xF676u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FA6D3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB3B3u: {
            const uint32_t source_key = 0x040FB3B3u;
            cpu->pc = 0xF678u;
            js_op_rep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x040FB3C1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB3C1u: {
            const uint32_t source_key = 0x040FB3C1u;
            cpu->pc = 0xF67Bu;
            uint16_t value = 0x0800u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040FB3D9u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB3D9u: {
            const uint32_t source_key = 0x040FB3D9u;
            cpu->pc = 0xF67Eu;
            uint32_t ea = js_addr_abs(cpu, 0x2116u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB3F1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB3F1u: {
            const uint32_t source_key = 0x040FB3F1u;
            cpu->pc = 0xF681u;
            uint16_t value = 0x3500u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040FB409u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB409u: {
            const uint32_t source_key = 0x040FB409u;
            cpu->pc = 0xF684u;
            uint32_t ea = js_addr_abs(cpu, 0x4302u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB421u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB421u: {
            const uint32_t source_key = 0x040FB421u;
            cpu->pc = 0xF687u;
            uint16_t value = 0x1000u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040FB439u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB439u: {
            const uint32_t source_key = 0x040FB439u;
            cpu->pc = 0xF68Au;
            uint32_t ea = js_addr_abs(cpu, 0x4305u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB451u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB451u: {
            const uint32_t source_key = 0x040FB451u;
            cpu->pc = 0xF68Cu;
            js_op_sep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x040FB463u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB463u: {
            const uint32_t source_key = 0x040FB463u;
            cpu->pc = 0xF68Eu;
            uint16_t value = 0x0001u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FB473u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB473u: {
            const uint32_t source_key = 0x040FB473u;
            cpu->pc = 0xF691u;
            uint32_t ea = js_addr_abs(cpu, 0x4300u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB48Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB48Bu: {
            const uint32_t source_key = 0x040FB48Bu;
            cpu->pc = 0xF693u;
            uint16_t value = 0x0018u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FB49Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB49Bu: {
            const uint32_t source_key = 0x040FB49Bu;
            cpu->pc = 0xF696u;
            uint32_t ea = js_addr_abs(cpu, 0x4301u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB4B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB4B3u: {
            const uint32_t source_key = 0x040FB4B3u;
            cpu->pc = 0xF698u;
            uint16_t value = 0x007Eu;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FB4C3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB4C3u: {
            const uint32_t source_key = 0x040FB4C3u;
            cpu->pc = 0xF69Bu;
            uint32_t ea = js_addr_abs(cpu, 0x4304u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB4DBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB4DBu: {
            const uint32_t source_key = 0x040FB4DBu;
            cpu->pc = 0xF69Eu;
            uint32_t ea = js_addr_abs(cpu, 0x0297u);
            uint16_t original = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
            uint16_t result = js_op_incdec(cpu, original, 1, 8u);
            if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB4F3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB4F3u: {
            const uint32_t source_key = 0x040FB4F3u;
            cpu->pc = 0xF6A1u;
            uint32_t ea = js_addr_abs(cpu, 0x0297u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FB50Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB50Bu: {
            const uint32_t source_key = 0x040FB50Bu;
            cpu->pc = 0xF6A3u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-5));
            static const uint32_t allowed[] = { 0x040FB4F3u, 0x040FB51Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB51Bu: {
            const uint32_t source_key = 0x040FB51Bu;
            cpu->pc = 0xF6A4u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FB863u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB523u: {
            const uint32_t source_key = 0x040FB523u;
            cpu->pc = 0xF6A6u;
            uint16_t value = 0x0000u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FB533u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB533u: {
            const uint32_t source_key = 0x040FB533u;
            cpu->pc = 0xF6A9u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF71Cu;
            static const uint32_t allowed[] = { 0x040FB8E3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB54Bu: {
            const uint32_t source_key = 0x040FB54Bu;
            cpu->pc = 0xF6ABu;
            if (js_branch_condition(cpu, 'C')) cpu->pc = (uint16_t)(cpu->pc + (1));
            static const uint32_t allowed[] = { 0x040FB55Bu, 0x040FB563u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB55Bu: {
            const uint32_t source_key = 0x040FB55Bu;
            cpu->pc = 0xF6ACu;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FA7CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_RETURN);
        }
        case 0x040FB563u: {
            const uint32_t source_key = 0x040FB563u;
            cpu->pc = 0xF6AFu;
            uint32_t ea = js_addr_abs(cpu, 0x13B8u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FB57Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB57Bu: {
            const uint32_t source_key = 0x040FB57Bu;
            cpu->pc = 0xF6B1u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (70));
            static const uint32_t allowed[] = { 0x040FB58Bu, 0x040FB7BBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB58Bu: {
            const uint32_t source_key = 0x040FB58Bu;
            cpu->pc = 0xF6B2u;
            js_op_load_a(cpu, js_op_incdec(cpu, cpu->a, -1, 8u), 8u);
            static const uint32_t allowed[] = { 0x040FB593u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB593u: {
            const uint32_t source_key = 0x040FB593u;
            cpu->pc = 0xF6B4u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (59));
            static const uint32_t allowed[] = { 0x040FB5A3u, 0x040FB77Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB5A3u: {
            const uint32_t source_key = 0x040FB5A3u;
            cpu->pc = 0xF6B7u;
            uint32_t ea = js_addr_abs(cpu, 0x031Bu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB5BBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB5BBu: {
            const uint32_t source_key = 0x040FB5BBu;
            cpu->pc = 0xF6B9u;
            uint16_t value = 0x0001u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FB5CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB5CBu: {
            const uint32_t source_key = 0x040FB5CBu;
            cpu->pc = 0xF6BCu;
            uint32_t ea = js_addr_abs(cpu, 0x031Cu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB5E3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB5E3u: {
            const uint32_t source_key = 0x040FB5E3u;
            cpu->pc = 0xF6BEu;
            js_op_rep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x040FB5F1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB5F1u: {
            const uint32_t source_key = 0x040FB5F1u;
            cpu->pc = 0xF6C1u;
            uint16_t value = 0x0303u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040FB609u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB609u: {
            const uint32_t source_key = 0x040FB609u;
            cpu->pc = 0xF6C4u;
            uint32_t ea = js_addr_abs(cpu, 0x0DF6u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB621u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB621u: {
            const uint32_t source_key = 0x040FB621u;
            cpu->pc = 0xF6C7u;
            uint32_t ea = js_addr_abs(cpu, 0x0DFAu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB639u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB639u: {
            const uint32_t source_key = 0x040FB639u;
            cpu->pc = 0xF6CAu;
            uint32_t ea = js_addr_abs(cpu, 0x0E02u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB651u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB651u: {
            const uint32_t source_key = 0x040FB651u;
            cpu->pc = 0xF6CDu;
            uint32_t ea = js_addr_abs(cpu, 0x0DFEu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB669u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB669u: {
            const uint32_t source_key = 0x040FB669u;
            cpu->pc = 0xF6D0u;
            uint16_t value = 0x0707u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040FB681u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB681u: {
            const uint32_t source_key = 0x040FB681u;
            cpu->pc = 0xF6D3u;
            uint32_t ea = js_addr_abs(cpu, 0x0E6Fu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB699u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB699u: {
            const uint32_t source_key = 0x040FB699u;
            cpu->pc = 0xF6D6u;
            uint32_t ea = js_addr_abs(cpu, 0x0E73u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB6B1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB6B1u: {
            const uint32_t source_key = 0x040FB6B1u;
            cpu->pc = 0xF6D9u;
            uint32_t ea = js_addr_abs(cpu, 0x0E77u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB6C9u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB6C9u: {
            const uint32_t source_key = 0x040FB6C9u;
            cpu->pc = 0xF6DCu;
            uint32_t ea = js_addr_abs(cpu, 0x0E7Bu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB6E1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB6E1u: {
            const uint32_t source_key = 0x040FB6E1u;
            cpu->pc = 0xF6DFu;
            uint32_t ea = js_addr_abs(cpu, 0x0E7Fu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB6F9u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB6F9u: {
            const uint32_t source_key = 0x040FB6F9u;
            cpu->pc = 0xF6E2u;
            uint32_t ea = js_addr_abs(cpu, 0x0E83u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB711u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB711u: {
            const uint32_t source_key = 0x040FB711u;
            cpu->pc = 0xF6E5u;
            uint32_t ea = js_addr_abs(cpu, 0x0E87u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB729u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB729u: {
            const uint32_t source_key = 0x040FB729u;
            cpu->pc = 0xF6E8u;
            uint32_t ea = js_addr_abs(cpu, 0x0E87u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB741u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB741u: {
            const uint32_t source_key = 0x040FB741u;
            cpu->pc = 0xF6EBu;
            uint32_t ea = js_addr_abs(cpu, 0x0E8Bu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB759u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB759u: {
            const uint32_t source_key = 0x040FB759u;
            cpu->pc = 0xF6EDu;
            js_op_sep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x040FB76Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB76Bu: {
            const uint32_t source_key = 0x040FB76Bu;
            cpu->pc = 0xF6EEu;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_C);
            static const uint32_t allowed[] = { 0x040FB773u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB773u: {
            const uint32_t source_key = 0x040FB773u;
            cpu->pc = 0xF6EFu;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FA7CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_RETURN);
        }
        case 0x040FB77Bu: {
            const uint32_t source_key = 0x040FB77Bu;
            cpu->pc = 0xF6F2u;
            uint32_t ea = js_addr_abs(cpu, 0x031Bu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB793u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB793u: {
            const uint32_t source_key = 0x040FB793u;
            cpu->pc = 0xF6F5u;
            uint32_t ea = js_addr_abs(cpu, 0x031Cu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB7ABu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB7ABu: {
            const uint32_t source_key = 0x040FB7ABu;
            cpu->pc = 0xF6F6u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_C);
            static const uint32_t allowed[] = { 0x040FB7B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB7B3u: {
            const uint32_t source_key = 0x040FB7B3u;
            cpu->pc = 0xF6F7u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FA7CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_RETURN);
        }
        case 0x040FB7BBu: {
            const uint32_t source_key = 0x040FB7BBu;
            cpu->pc = 0xF6F9u;
            uint16_t value = 0x0001u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FB7CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB7CBu: {
            const uint32_t source_key = 0x040FB7CBu;
            cpu->pc = 0xF6FCu;
            uint32_t ea = js_addr_abs(cpu, 0x031Bu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB7E3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB7E3u: {
            const uint32_t source_key = 0x040FB7E3u;
            cpu->pc = 0xF6FFu;
            uint32_t ea = js_addr_abs(cpu, 0x031Cu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB7FBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB7FBu: {
            const uint32_t source_key = 0x040FB7FBu;
            cpu->pc = 0xF700u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_C);
            static const uint32_t allowed[] = { 0x040FB803u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB803u: {
            const uint32_t source_key = 0x040FB803u;
            cpu->pc = 0xF701u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FA7CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_RETURN);
        }
        case 0x040FB80Bu: {
            const uint32_t source_key = 0x040FB80Bu;
            cpu->pc = 0xF704u;
            uint32_t ea = js_addr_abs(cpu, 0x031Bu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FB823u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB823u: {
            const uint32_t source_key = 0x040FB823u;
            cpu->pc = 0xF707u;
            uint32_t ea = js_addr_abs(cpu, 0x031Cu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_ora(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FB83Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB83Bu: {
            const uint32_t source_key = 0x040FB83Bu;
            cpu->pc = 0xF709u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (17));
            static const uint32_t allowed[] = { 0x040FB84Bu, 0x040FB8D3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB84Bu: {
            const uint32_t source_key = 0x040FB84Bu;
            cpu->pc = 0xF70Cu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF676u;
            static const uint32_t allowed[] = { 0x040FB3B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB863u: {
            const uint32_t source_key = 0x040FB863u;
            cpu->pc = 0xF70Eu;
            uint16_t value = 0x0000u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FB873u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB873u: {
            const uint32_t source_key = 0x040FB873u;
            cpu->pc = 0xF711u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF71Cu;
            static const uint32_t allowed[] = { 0x040FB8E3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB88Bu: {
            const uint32_t source_key = 0x040FB88Bu;
            cpu->pc = 0xF713u;
            if (js_branch_condition(cpu, 'C')) cpu->pc = (uint16_t)(cpu->pc + (1));
            static const uint32_t allowed[] = { 0x040FB89Bu, 0x040FB8A3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB89Bu: {
            const uint32_t source_key = 0x040FB89Bu;
            cpu->pc = 0xF714u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FA81Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_RETURN);
        }
        case 0x040FB8A3u: {
            const uint32_t source_key = 0x040FB8A3u;
            cpu->pc = 0xF717u;
            uint32_t ea = js_addr_abs(cpu, 0x13B8u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FB8BBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB8BBu: {
            const uint32_t source_key = 0x040FB8BBu;
            cpu->pc = 0xF71Au;
            uint32_t ea = js_addr_abs(cpu, 0x0336u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB8D3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB8D3u: {
            const uint32_t source_key = 0x040FB8D3u;
            cpu->pc = 0xF71Bu;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_C);
            static const uint32_t allowed[] = { 0x040FB8DBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB8DBu: {
            const uint32_t source_key = 0x040FB8DBu;
            cpu->pc = 0xF71Cu;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FA81Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_RETURN);
        }
        case 0x040FB8E3u: {
            const uint32_t source_key = 0x040FB8E3u;
            cpu->pc = 0xF71Fu;
            uint32_t ea = js_addr_abs(cpu, 0x13B8u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB8FBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB8FBu: {
            const uint32_t source_key = 0x040FB8FBu;
            cpu->pc = 0xF721u;
            uint16_t value = 0x0000u;
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FB90Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB90Bu: {
            const uint32_t source_key = 0x040FB90Bu;
            cpu->pc = 0xF724u;
            uint32_t ea = js_addr_abs_x(cpu, 0xF77Du);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FB923u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB923u: {
            const uint32_t source_key = 0x040FB923u;
            cpu->pc = 0xF727u;
            uint32_t ea = js_addr_abs_x(cpu, 0x14FAu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB93Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB93Bu: {
            const uint32_t source_key = 0x040FB93Bu;
            cpu->pc = 0xF728u;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, 1, 8u), 8u);
            static const uint32_t allowed[] = { 0x040FB943u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB943u: {
            const uint32_t source_key = 0x040FB943u;
            cpu->pc = 0xF72Au;
            uint16_t value = 0x0009u;
            js_op_compare(cpu, cpu->x, value, 8u);
            static const uint32_t allowed[] = { 0x040FB953u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB953u: {
            const uint32_t source_key = 0x040FB953u;
            cpu->pc = 0xF72Cu;
            if (js_branch_condition(cpu, 'C')) cpu->pc = (uint16_t)(cpu->pc + (-11));
            static const uint32_t allowed[] = { 0x040FB90Bu, 0x040FB963u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB963u: {
            const uint32_t source_key = 0x040FB963u;
            cpu->pc = 0xF72Eu;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FB970u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB970u: {
            const uint32_t source_key = 0x040FB970u;
            cpu->pc = 0xF731u;
            uint16_t value = 0x0384u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040FB988u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB988u: {
            const uint32_t source_key = 0x040FB988u;
            cpu->pc = 0xF734u;
            uint32_t ea = js_addr_abs(cpu, 0x02C0u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB9A0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB9A0u: {
            const uint32_t source_key = 0x040FB9A0u;
            cpu->pc = 0xF736u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FB9B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB9B3u: {
            const uint32_t source_key = 0x040FB9B3u;
            cpu->pc = 0xF739u;
            uint32_t ea = js_addr_abs(cpu, 0x13B6u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB9CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB9CBu: {
            const uint32_t source_key = 0x040FB9CBu;
            cpu->pc = 0xF73Cu;
            uint32_t ea = js_addr_abs(cpu, 0x0289u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FB9E3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB9E3u: {
            const uint32_t source_key = 0x040FB9E3u;
            cpu->pc = 0xF73Eu;
            uint16_t value = 0x0002u;
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FB9F3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FB9F3u: {
            const uint32_t source_key = 0x040FB9F3u;
            cpu->pc = 0xF741u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9FF8u;
            static const uint32_t allowed[] = { 0x040CFFC3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBA0Bu: {
            const uint32_t source_key = 0x040FBA0Bu;
            cpu->pc = 0xF743u;
            uint16_t value = 0x0003u;
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FBA1Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBA1Bu: {
            const uint32_t source_key = 0x040FBA1Bu;
            cpu->pc = 0xF746u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9FE6u;
            static const uint32_t allowed[] = { 0x040CFF33u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBA33u: {
            const uint32_t source_key = 0x040FBA33u;
            cpu->pc = 0xF749u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xA001u;
            static const uint32_t allowed[] = { 0x040D000Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBA4Bu: {
            const uint32_t source_key = 0x040FBA4Bu;
            cpu->pc = 0xF74Bu;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (13));
            static const uint32_t allowed[] = { 0x040FBA5Bu, 0x040FBAC3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBA5Bu: {
            const uint32_t source_key = 0x040FBA5Bu;
            cpu->pc = 0xF74Cu;
            js_op_load_a(cpu, js_op_incdec(cpu, cpu->a, -1, 8u), 8u);
            static const uint32_t allowed[] = { 0x040FBA63u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBA63u: {
            const uint32_t source_key = 0x040FBA63u;
            cpu->pc = 0xF74Eu;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (5));
            static const uint32_t allowed[] = { 0x040FBA73u, 0x040FBA9Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBA73u: {
            const uint32_t source_key = 0x040FBA73u;
            cpu->pc = 0xF751u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF830u;
            static const uint32_t allowed[] = { 0x040FC183u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBA8Bu: {
            const uint32_t source_key = 0x040FBA8Bu;
            cpu->pc = 0xF753u;
            if (js_branch_condition(cpu, 'A')) cpu->pc = (uint16_t)(cpu->pc + (5));
            static const uint32_t allowed[] = { 0x040FBAC3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBA9Bu: {
            const uint32_t source_key = 0x040FBA9Bu;
            cpu->pc = 0xF755u;
            uint16_t value = 0x0000u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FBAABu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBAABu: {
            const uint32_t source_key = 0x040FBAABu;
            cpu->pc = 0xF758u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF836u;
            static const uint32_t allowed[] = { 0x040FC1B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBAC3u: {
            const uint32_t source_key = 0x040FBAC3u;
            cpu->pc = 0xF75Bu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9C8Cu;
            static const uint32_t allowed[] = { 0x040CE463u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBADBu: {
            const uint32_t source_key = 0x040FBADBu;
            cpu->pc = 0xF75Eu;
            uint32_t ea = js_addr_abs(cpu, 0x0240u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FBAF3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBAF3u: {
            const uint32_t source_key = 0x040FBAF3u;
            cpu->pc = 0xF760u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-5));
            static const uint32_t allowed[] = { 0x040FBADBu, 0x040FBB03u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBB03u: {
            const uint32_t source_key = 0x040FBB03u;
            cpu->pc = 0xF762u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FBB10u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBB10u: {
            const uint32_t source_key = 0x040FBB10u;
            cpu->pc = 0xF765u;
            uint32_t ea = js_addr_abs(cpu, 0x02C0u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, -1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FBB28u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBB28u: {
            const uint32_t source_key = 0x040FBB28u;
            cpu->pc = 0xF767u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FBB3Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBB3Bu: {
            const uint32_t source_key = 0x040FBB3Bu;
            cpu->pc = 0xF769u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (18));
            static const uint32_t allowed[] = { 0x040FBB4Bu, 0x040FBBDBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBB4Bu: {
            const uint32_t source_key = 0x040FBB4Bu;
            cpu->pc = 0xF76Cu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9F9Du;
            static const uint32_t allowed[] = { 0x040CFCEBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBB63u: {
            const uint32_t source_key = 0x040FBB63u;
            cpu->pc = 0xF76Fu;
            uint32_t ea = js_addr_abs(cpu, 0x0289u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FBB7Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBB7Bu: {
            const uint32_t source_key = 0x040FBB7Bu;
            cpu->pc = 0xF771u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (-53));
            static const uint32_t allowed[] = { 0x040FB9E3u, 0x040FBB8Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBB8Bu: {
            const uint32_t source_key = 0x040FBB8Bu;
            cpu->pc = 0xF775u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0xFB3Eu;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x0407D9F3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBBABu: {
            const uint32_t source_key = 0x040FBBABu;
            cpu->pc = 0xF779u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0xF982u;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x0407CC13u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBBCBu: {
            const uint32_t source_key = 0x040FBBCBu;
            cpu->pc = 0xF77Au;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_C);
            static const uint32_t allowed[] = { 0x040FBBD3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBBD3u: {
            const uint32_t source_key = 0x040FBBD3u;
            cpu->pc = 0xF77Bu;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FB54Bu, 0x040FB88Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_RETURN);
        }
        case 0x040FBBDBu: {
            const uint32_t source_key = 0x040FBBDBu;
            cpu->pc = 0xF77Cu;
            cpu->p = (uint8_t)(cpu->p | JS_P_C);
            static const uint32_t allowed[] = { 0x040FBBE3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBBE3u: {
            const uint32_t source_key = 0x040FBBE3u;
            cpu->pc = 0xF77Du;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FB54Bu, 0x040FB88Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_RETURN);
        }
        case 0x040FBC33u: {
            const uint32_t source_key = 0x040FBC33u;
            cpu->pc = 0xF788u;
            uint16_t value = 0x0000u;
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FBC43u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBC43u: {
            const uint32_t source_key = 0x040FBC43u;
            cpu->pc = 0xF78Bu;
            uint32_t ea = js_addr_abs_x(cpu, 0xF7EEu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FBC5Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBC5Bu: {
            const uint32_t source_key = 0x040FBC5Bu;
            cpu->pc = 0xF78Eu;
            uint32_t ea = js_addr_abs_x(cpu, 0x14FAu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FBC73u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBC73u: {
            const uint32_t source_key = 0x040FBC73u;
            cpu->pc = 0xF78Fu;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, 1, 8u), 8u);
            static const uint32_t allowed[] = { 0x040FBC7Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBC7Bu: {
            const uint32_t source_key = 0x040FBC7Bu;
            cpu->pc = 0xF791u;
            uint16_t value = 0x0009u;
            js_op_compare(cpu, cpu->x, value, 8u);
            static const uint32_t allowed[] = { 0x040FBC8Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBC8Bu: {
            const uint32_t source_key = 0x040FBC8Bu;
            cpu->pc = 0xF793u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-11));
            static const uint32_t allowed[] = { 0x040FBC43u, 0x040FBC9Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBC9Bu: {
            const uint32_t source_key = 0x040FBC9Bu;
            cpu->pc = 0xF795u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FBCA8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBCA8u: {
            const uint32_t source_key = 0x040FBCA8u;
            cpu->pc = 0xF798u;
            uint16_t value = 0x0384u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040FBCC0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBCC0u: {
            const uint32_t source_key = 0x040FBCC0u;
            cpu->pc = 0xF79Bu;
            uint32_t ea = js_addr_abs(cpu, 0x02C0u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FBCD8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBCD8u: {
            const uint32_t source_key = 0x040FBCD8u;
            cpu->pc = 0xF79Du;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FBCEBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBCEBu: {
            const uint32_t source_key = 0x040FBCEBu;
            cpu->pc = 0xF7A0u;
            uint32_t ea = js_addr_abs(cpu, 0x13B8u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FBD03u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBD03u: {
            const uint32_t source_key = 0x040FBD03u;
            cpu->pc = 0xF7A3u;
            uint32_t ea = js_addr_abs(cpu, 0x13B6u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FBD1Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBD1Bu: {
            const uint32_t source_key = 0x040FBD1Bu;
            cpu->pc = 0xF7A6u;
            uint32_t ea = js_addr_abs(cpu, 0x0289u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FBD33u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBD33u: {
            const uint32_t source_key = 0x040FBD33u;
            cpu->pc = 0xF7A8u;
            uint16_t value = 0x0001u;
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FBD43u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBD43u: {
            const uint32_t source_key = 0x040FBD43u;
            cpu->pc = 0xF7ABu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9FF8u;
            static const uint32_t allowed[] = { 0x040CFFC3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBD5Bu: {
            const uint32_t source_key = 0x040FBD5Bu;
            cpu->pc = 0xF7ADu;
            uint16_t value = 0x0002u;
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FBD6Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBD6Bu: {
            const uint32_t source_key = 0x040FBD6Bu;
            cpu->pc = 0xF7B0u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9FE6u;
            static const uint32_t allowed[] = { 0x040CFF33u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBD83u: {
            const uint32_t source_key = 0x040FBD83u;
            cpu->pc = 0xF7B3u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xA001u;
            static const uint32_t allowed[] = { 0x040D000Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBD9Bu: {
            const uint32_t source_key = 0x040FBD9Bu;
            cpu->pc = 0xF7B5u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (13));
            static const uint32_t allowed[] = { 0x040FBDABu, 0x040FBE13u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBDABu: {
            const uint32_t source_key = 0x040FBDABu;
            cpu->pc = 0xF7B6u;
            js_op_load_a(cpu, js_op_incdec(cpu, cpu->a, -1, 8u), 8u);
            static const uint32_t allowed[] = { 0x040FBDB3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBDB3u: {
            const uint32_t source_key = 0x040FBDB3u;
            cpu->pc = 0xF7B8u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (5));
            static const uint32_t allowed[] = { 0x040FBDC3u, 0x040FBDEBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBDC3u: {
            const uint32_t source_key = 0x040FBDC3u;
            cpu->pc = 0xF7BBu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF830u;
            static const uint32_t allowed[] = { 0x040FC183u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBDDBu: {
            const uint32_t source_key = 0x040FBDDBu;
            cpu->pc = 0xF7BDu;
            if (js_branch_condition(cpu, 'A')) cpu->pc = (uint16_t)(cpu->pc + (5));
            static const uint32_t allowed[] = { 0x040FBE13u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBDEBu: {
            const uint32_t source_key = 0x040FBDEBu;
            cpu->pc = 0xF7BFu;
            uint16_t value = 0x0001u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FBDFBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBDFBu: {
            const uint32_t source_key = 0x040FBDFBu;
            cpu->pc = 0xF7C2u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF836u;
            static const uint32_t allowed[] = { 0x040FC1B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBE13u: {
            const uint32_t source_key = 0x040FBE13u;
            cpu->pc = 0xF7C5u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9C8Cu;
            static const uint32_t allowed[] = { 0x040CE463u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBE2Bu: {
            const uint32_t source_key = 0x040FBE2Bu;
            cpu->pc = 0xF7C8u;
            uint32_t ea = js_addr_abs(cpu, 0x0240u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FBE43u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBE43u: {
            const uint32_t source_key = 0x040FBE43u;
            cpu->pc = 0xF7CAu;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-5));
            static const uint32_t allowed[] = { 0x040FBE2Bu, 0x040FBE53u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBE53u: {
            const uint32_t source_key = 0x040FBE53u;
            cpu->pc = 0xF7CCu;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FBE60u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBE60u: {
            const uint32_t source_key = 0x040FBE60u;
            cpu->pc = 0xF7CFu;
            uint32_t ea = js_addr_abs(cpu, 0x02C0u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, -1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FBE78u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBE78u: {
            const uint32_t source_key = 0x040FBE78u;
            cpu->pc = 0xF7D1u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040FBE8Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBE8Bu: {
            const uint32_t source_key = 0x040FBE8Bu;
            cpu->pc = 0xF7D3u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (25));
            static const uint32_t allowed[] = { 0x040FBE9Bu, 0x040FBF63u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBE9Bu: {
            const uint32_t source_key = 0x040FBE9Bu;
            cpu->pc = 0xF7D6u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0x9F9Du;
            static const uint32_t allowed[] = { 0x040CFCEBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBEB3u: {
            const uint32_t source_key = 0x040FBEB3u;
            cpu->pc = 0xF7D9u;
            uint32_t ea = js_addr_abs(cpu, 0x0289u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FBECBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBECBu: {
            const uint32_t source_key = 0x040FBECBu;
            cpu->pc = 0xF7DBu;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (-53));
            static const uint32_t allowed[] = { 0x040FBD33u, 0x040FBEDBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBEDBu: {
            const uint32_t source_key = 0x040FBEDBu;
            cpu->pc = 0xF7DFu;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0xFB3Eu;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x0407D9F3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBEFBu: {
            const uint32_t source_key = 0x040FBEFBu;
            cpu->pc = 0xF7E3u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 0, stop, source_key)) return JS_EXEC_STOP;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 0, stop, source_key)) return JS_EXEC_STOP;
            cpu->pbr = 0x80u;
            cpu->pc = 0xF982u;
            js_cpu_normalize(cpu);
            static const uint32_t allowed[] = { 0x0407CC13u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBF1Bu: {
            const uint32_t source_key = 0x040FBF1Bu;
            cpu->pc = 0xF7E6u;
            uint32_t ea = js_addr_abs(cpu, 0x13B8u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FBF33u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBF33u: {
            const uint32_t source_key = 0x040FBF33u;
            cpu->pc = 0xF7E7u;
            js_op_load_a(cpu, js_op_incdec(cpu, cpu->a, 1, 8u), 8u);
            static const uint32_t allowed[] = { 0x040FBF3Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBF3Bu: {
            const uint32_t source_key = 0x040FBF3Bu;
            cpu->pc = 0xF7EAu;
            uint32_t ea = js_addr_abs(cpu, 0x0BFFu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040FBF53u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBF53u: {
            const uint32_t source_key = 0x040FBF53u;
            cpu->pc = 0xF7EBu;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_C);
            static const uint32_t allowed[] = { 0x040FBF5Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBF5Bu: {
            const uint32_t source_key = 0x040FBF5Bu;
            cpu->pc = 0xF7ECu;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FA7F3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_RETURN);
        }
        case 0x040FBF63u: {
            const uint32_t source_key = 0x040FBF63u;
            cpu->pc = 0xF7EDu;
            cpu->p = (uint8_t)(cpu->p | JS_P_C);
            static const uint32_t allowed[] = { 0x040FBF6Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBF6Bu: {
            const uint32_t source_key = 0x040FBF6Bu;
            cpu->pc = 0xF7EEu;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040FA7F3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_RETURN);
        }
        case 0x040FBFBBu: {
            const uint32_t source_key = 0x040FBFBBu;
            cpu->pc = 0xF7F9u;
            uint16_t value = 0x0000u;
            js_op_load_y(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FBFCBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBFCBu: {
            const uint32_t source_key = 0x040FBFCBu;
            cpu->pc = 0xF7FCu;
            uint32_t ea = js_addr_abs_y(cpu, 0xF885u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FBFE3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBFE3u: {
            const uint32_t source_key = 0x040FBFE3u;
            cpu->pc = 0xF7FFu;
            uint32_t ea = js_addr_abs_y(cpu, 0xF896u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040FBFFBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040FBFFBu: {
            const uint32_t source_key = 0x040FBFFBu;
            cpu->pc = 0xF802u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF808u;
            static const uint32_t allowed[] = { 0x040FC043u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        default: return JS_EXEC_NOT_MINE;
    }
}
