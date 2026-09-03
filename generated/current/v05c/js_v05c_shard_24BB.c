#include "v05c_static_cpu.h"

JSExecResult js_v05c_shard_24BB(JSCPU *cpu, const JSBus *bus, JSStop *stop) {
    (void)bus;
    (void)stop;
    switch (js_cpu_context_key(cpu)) {
        case 0x04977B93u: {
            const uint32_t source_key = 0x04977B93u;
            cpu->pc = 0xEF73u;
            if (!js_stack_push8(cpu, bus, cpu->dbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977B9Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977B9Bu: {
            const uint32_t source_key = 0x04977B9Bu;
            cpu->pc = 0xEF74u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977BA3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977BA3u: {
            const uint32_t source_key = 0x04977BA3u;
            cpu->pc = 0xEF75u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04977BABu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977BABu: {
            const uint32_t source_key = 0x04977BABu;
            cpu->pc = 0xEF77u;
            uint16_t value = 0x0001u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04977BBBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977BBBu: {
            const uint32_t source_key = 0x04977BBBu;
            cpu->pc = 0xEF7Au;
            uint32_t ea = js_addr_abs(cpu, 0x420Du);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977BD3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977BD3u: {
            const uint32_t source_key = 0x04977BD3u;
            cpu->pc = 0xEF7Cu;
            uint16_t value = 0x008Fu;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04977BE3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977BE3u: {
            const uint32_t source_key = 0x04977BE3u;
            cpu->pc = 0xEF7Fu;
            uint32_t ea = js_addr_abs(cpu, 0x2100u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977BFBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977BFBu: {
            const uint32_t source_key = 0x04977BFBu;
            cpu->pc = 0xEF81u;
            uint16_t value = 0x000Bu;
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04977C0Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977C0Bu: {
            const uint32_t source_key = 0x04977C0Bu;
            cpu->pc = 0xEF84u;
            uint32_t ea = js_addr_abs_x(cpu, 0x2101u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977C23u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977C23u: {
            const uint32_t source_key = 0x04977C23u;
            cpu->pc = 0xEF85u;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, -1, 8u), 8u);
            static const uint32_t allowed[] = { 0x04977C2Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977C2Bu: {
            const uint32_t source_key = 0x04977C2Bu;
            cpu->pc = 0xEF87u;
            if (js_branch_condition(cpu, 'P')) cpu->pc = (uint16_t)(cpu->pc + (-6));
            static const uint32_t allowed[] = { 0x04977C0Bu, 0x04977C3Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977C3Bu: {
            const uint32_t source_key = 0x04977C3Bu;
            cpu->pc = 0xEF89u;
            uint16_t value = 0x0007u;
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04977C4Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977C4Bu: {
            const uint32_t source_key = 0x04977C4Bu;
            cpu->pc = 0xEF8Cu;
            uint32_t ea = js_addr_abs_x(cpu, 0x210Du);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977C63u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977C63u: {
            const uint32_t source_key = 0x04977C63u;
            cpu->pc = 0xEF8Fu;
            uint32_t ea = js_addr_abs_x(cpu, 0x210Du);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977C7Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977C7Bu: {
            const uint32_t source_key = 0x04977C7Bu;
            cpu->pc = 0xEF90u;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, -1, 8u), 8u);
            static const uint32_t allowed[] = { 0x04977C83u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977C83u: {
            const uint32_t source_key = 0x04977C83u;
            cpu->pc = 0xEF92u;
            if (js_branch_condition(cpu, 'P')) cpu->pc = (uint16_t)(cpu->pc + (-9));
            static const uint32_t allowed[] = { 0x04977C4Bu, 0x04977C93u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977C93u: {
            const uint32_t source_key = 0x04977C93u;
            cpu->pc = 0xEF94u;
            uint16_t value = 0x0080u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04977CA3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977CA3u: {
            const uint32_t source_key = 0x04977CA3u;
            cpu->pc = 0xEF97u;
            uint32_t ea = js_addr_abs(cpu, 0x2115u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977CBBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977CBBu: {
            const uint32_t source_key = 0x04977CBBu;
            cpu->pc = 0xEF99u;
            uint16_t value = 0x0004u;
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04977CCBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977CCBu: {
            const uint32_t source_key = 0x04977CCBu;
            cpu->pc = 0xEF9Cu;
            uint32_t ea = js_addr_abs_x(cpu, 0x2116u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977CE3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977CE3u: {
            const uint32_t source_key = 0x04977CE3u;
            cpu->pc = 0xEF9Du;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, -1, 8u), 8u);
            static const uint32_t allowed[] = { 0x04977CEBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977CEBu: {
            const uint32_t source_key = 0x04977CEBu;
            cpu->pc = 0xEF9Fu;
            if (js_branch_condition(cpu, 'P')) cpu->pc = (uint16_t)(cpu->pc + (-6));
            static const uint32_t allowed[] = { 0x04977CCBu, 0x04977CFBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977CFBu: {
            const uint32_t source_key = 0x04977CFBu;
            cpu->pc = 0xEFA2u;
            uint32_t ea = js_addr_abs(cpu, 0x211Bu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977D13u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977D13u: {
            const uint32_t source_key = 0x04977D13u;
            cpu->pc = 0xEFA4u;
            uint16_t value = 0x0001u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04977D23u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977D23u: {
            const uint32_t source_key = 0x04977D23u;
            cpu->pc = 0xEFA7u;
            uint32_t ea = js_addr_abs(cpu, 0x211Bu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977D3Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977D3Bu: {
            const uint32_t source_key = 0x04977D3Bu;
            cpu->pc = 0xEFAAu;
            uint32_t ea = js_addr_abs(cpu, 0x211Cu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977D53u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977D53u: {
            const uint32_t source_key = 0x04977D53u;
            cpu->pc = 0xEFADu;
            uint32_t ea = js_addr_abs(cpu, 0x211Cu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977D6Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977D6Bu: {
            const uint32_t source_key = 0x04977D6Bu;
            cpu->pc = 0xEFB0u;
            uint32_t ea = js_addr_abs(cpu, 0x211Du);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977D83u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977D83u: {
            const uint32_t source_key = 0x04977D83u;
            cpu->pc = 0xEFB3u;
            uint32_t ea = js_addr_abs(cpu, 0x211Du);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977D9Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977D9Bu: {
            const uint32_t source_key = 0x04977D9Bu;
            cpu->pc = 0xEFB6u;
            uint32_t ea = js_addr_abs(cpu, 0x211Eu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977DB3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977DB3u: {
            const uint32_t source_key = 0x04977DB3u;
            cpu->pc = 0xEFB8u;
            uint16_t value = 0x0001u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04977DC3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977DC3u: {
            const uint32_t source_key = 0x04977DC3u;
            cpu->pc = 0xEFBBu;
            uint32_t ea = js_addr_abs(cpu, 0x211Eu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977DDBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977DDBu: {
            const uint32_t source_key = 0x04977DDBu;
            cpu->pc = 0xEFBEu;
            uint32_t ea = js_addr_abs(cpu, 0x211Fu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977DF3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977DF3u: {
            const uint32_t source_key = 0x04977DF3u;
            cpu->pc = 0xEFC1u;
            uint32_t ea = js_addr_abs(cpu, 0x211Fu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977E0Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977E0Bu: {
            const uint32_t source_key = 0x04977E0Bu;
            cpu->pc = 0xEFC4u;
            uint32_t ea = js_addr_abs(cpu, 0x2120u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977E23u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977E23u: {
            const uint32_t source_key = 0x04977E23u;
            cpu->pc = 0xEFC7u;
            uint32_t ea = js_addr_abs(cpu, 0x2120u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977E3Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977E3Bu: {
            const uint32_t source_key = 0x04977E3Bu;
            cpu->pc = 0xEFC9u;
            uint16_t value = 0x000Eu;
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04977E4Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977E4Bu: {
            const uint32_t source_key = 0x04977E4Bu;
            cpu->pc = 0xEFCCu;
            uint32_t ea = js_addr_abs_x(cpu, 0x2121u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977E63u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977E63u: {
            const uint32_t source_key = 0x04977E63u;
            cpu->pc = 0xEFCDu;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, -1, 8u), 8u);
            static const uint32_t allowed[] = { 0x04977E6Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977E6Bu: {
            const uint32_t source_key = 0x04977E6Bu;
            cpu->pc = 0xEFCFu;
            if (js_branch_condition(cpu, 'P')) cpu->pc = (uint16_t)(cpu->pc + (-6));
            static const uint32_t allowed[] = { 0x04977E4Bu, 0x04977E7Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977E7Bu: {
            const uint32_t source_key = 0x04977E7Bu;
            cpu->pc = 0xEFD1u;
            uint16_t value = 0x0030u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04977E8Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977E8Bu: {
            const uint32_t source_key = 0x04977E8Bu;
            cpu->pc = 0xEFD4u;
            uint32_t ea = js_addr_abs(cpu, 0x2130u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977EA3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977EA3u: {
            const uint32_t source_key = 0x04977EA3u;
            cpu->pc = 0xEFD7u;
            uint32_t ea = js_addr_abs(cpu, 0x2131u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977EBBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977EBBu: {
            const uint32_t source_key = 0x04977EBBu;
            cpu->pc = 0xEFD9u;
            uint16_t value = 0x00E0u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04977ECBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977ECBu: {
            const uint32_t source_key = 0x04977ECBu;
            cpu->pc = 0xEFDCu;
            uint32_t ea = js_addr_abs(cpu, 0x2132u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977EE3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977EE3u: {
            const uint32_t source_key = 0x04977EE3u;
            cpu->pc = 0xEFDFu;
            uint32_t ea = js_addr_abs(cpu, 0x2133u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977EFBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977EFBu: {
            const uint32_t source_key = 0x04977EFBu;
            cpu->pc = 0xEFE2u;
            uint32_t ea = js_addr_abs(cpu, 0x4200u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977F13u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977F13u: {
            const uint32_t source_key = 0x04977F13u;
            cpu->pc = 0xEFE4u;
            uint16_t value = 0x00FFu;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04977F23u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977F23u: {
            const uint32_t source_key = 0x04977F23u;
            cpu->pc = 0xEFE7u;
            uint32_t ea = js_addr_abs(cpu, 0x4201u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977F3Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977F3Bu: {
            const uint32_t source_key = 0x04977F3Bu;
            cpu->pc = 0xEFE9u;
            uint16_t value = 0x000Bu;
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04977F4Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977F4Bu: {
            const uint32_t source_key = 0x04977F4Bu;
            cpu->pc = 0xEFECu;
            uint32_t ea = js_addr_abs_x(cpu, 0x4202u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977F63u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977F63u: {
            const uint32_t source_key = 0x04977F63u;
            cpu->pc = 0xEFEDu;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, -1, 8u), 8u);
            static const uint32_t allowed[] = { 0x04977F6Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977F6Bu: {
            const uint32_t source_key = 0x04977F6Bu;
            cpu->pc = 0xEFEFu;
            if (js_branch_condition(cpu, 'P')) cpu->pc = (uint16_t)(cpu->pc + (-6));
            static const uint32_t allowed[] = { 0x04977F4Bu, 0x04977F7Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977F7Bu: {
            const uint32_t source_key = 0x04977F7Bu;
            cpu->pc = 0xEFF0u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04977F83u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977F83u: {
            const uint32_t source_key = 0x04977F83u;
            cpu->pc = 0xEFF1u;
            { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x040401E3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977F8Bu: {
            const uint32_t source_key = 0x04977F8Bu;
            cpu->pc = 0xEFF2u;
            if (!js_stack_push8(cpu, bus, cpu->dbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977F93u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977F93u: {
            const uint32_t source_key = 0x04977F93u;
            cpu->pc = 0xEFF3u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977F9Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977F9Bu: {
            const uint32_t source_key = 0x04977F9Bu;
            cpu->pc = 0xEFF4u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04977FA3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977FA3u: {
            const uint32_t source_key = 0x04977FA3u;
            cpu->pc = 0xEFF6u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x04977FB0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977FB0u: {
            const uint32_t source_key = 0x04977FB0u;
            cpu->pc = 0xEFF9u;
            uint32_t ea = js_addr_abs(cpu, 0x033Du);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977FC8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977FC8u: {
            const uint32_t source_key = 0x04977FC8u;
            cpu->pc = 0xEFFCu;
            uint32_t ea = js_addr_abs(cpu, 0x033Fu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977FE0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977FE0u: {
            const uint32_t source_key = 0x04977FE0u;
            cpu->pc = 0xEFFFu;
            uint32_t ea = js_addr_abs(cpu, 0x023Eu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04977FF8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04977FF8u: {
            const uint32_t source_key = 0x04977FF8u;
            cpu->pc = 0xF001u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x0497800Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        default: return JS_EXEC_NOT_MINE;
    }
}
