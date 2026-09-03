#include "v05c_static_cpu.h"

JSExecResult js_v05c_shard_206D(JSCPU *cpu, const JSBus *bus, JSStop *stop) {
    (void)bus;
    (void)stop;
    switch (js_cpu_context_key(cpu)) {
        case 0x040DB34Bu: {
            const uint32_t source_key = 0x040DB34Bu;
            cpu->pc = 0xB66Au;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 8u), 8u);
            static const uint32_t allowed[] = { 0x040DB353u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DB353u: {
            const uint32_t source_key = 0x040DB353u;
            cpu->pc = 0xB66Bu;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 8u), 8u);
            static const uint32_t allowed[] = { 0x040DB35Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DB35Bu: {
            const uint32_t source_key = 0x040DB35Bu;
            cpu->pc = 0xB66Cu;
            js_op_transfer(cpu, 'B');
            static const uint32_t allowed[] = { 0x040DB363u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DB363u: {
            const uint32_t source_key = 0x040DB363u;
            cpu->pc = 0xB66Eu;
            js_op_rep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x040DB371u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DB371u: {
            const uint32_t source_key = 0x040DB371u;
            cpu->pc = 0xB671u;
            uint32_t ea = js_addr_abs_y(cpu, 0x0E06u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040DB389u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DB389u: {
            const uint32_t source_key = 0x040DB389u;
            cpu->pc = 0xB674u;
            uint32_t ea = js_addr_abs(cpu, 0x13BBu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040DB3A1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DB3A1u: {
            const uint32_t source_key = 0x040DB3A1u;
            cpu->pc = 0xB677u;
            uint32_t ea = js_addr_abs_y(cpu, 0x0E08u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040DB3B9u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DB3B9u: {
            const uint32_t source_key = 0x040DB3B9u;
            cpu->pc = 0xB67Au;
            uint32_t ea = js_addr_abs(cpu, 0x13BDu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040DB3D1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DB3D1u: {
            const uint32_t source_key = 0x040DB3D1u;
            cpu->pc = 0xB67Cu;
            js_op_sep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x040DB3E3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DB3E3u: {
            const uint32_t source_key = 0x040DB3E3u;
            cpu->pc = 0xB67Du;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040D674Bu, 0x040D67DBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DB3EBu: {
            const uint32_t source_key = 0x040DB3EBu;
            cpu->pc = 0xB67Eu;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 8u), 8u);
            static const uint32_t allowed[] = { 0x040DB3F3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DB3F3u: {
            const uint32_t source_key = 0x040DB3F3u;
            cpu->pc = 0xB67Fu;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 8u), 8u);
            static const uint32_t allowed[] = { 0x040DB3FBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DB3FBu: {
            const uint32_t source_key = 0x040DB3FBu;
            cpu->pc = 0xB680u;
            js_op_transfer(cpu, 'A');
            static const uint32_t allowed[] = { 0x040DB403u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DB403u: {
            const uint32_t source_key = 0x040DB403u;
            cpu->pc = 0xB682u;
            js_op_rep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x040DB411u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DB411u: {
            const uint32_t source_key = 0x040DB411u;
            cpu->pc = 0xB685u;
            uint32_t ea = js_addr_abs(cpu, 0x13BBu);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040DB429u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DB429u: {
            const uint32_t source_key = 0x040DB429u;
            cpu->pc = 0xB688u;
            uint32_t ea = js_addr_abs_x(cpu, 0x0E06u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040DB441u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DB441u: {
            const uint32_t source_key = 0x040DB441u;
            cpu->pc = 0xB68Bu;
            uint32_t ea = js_addr_abs(cpu, 0x13BDu);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040DB459u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DB459u: {
            const uint32_t source_key = 0x040DB459u;
            cpu->pc = 0xB68Eu;
            uint32_t ea = js_addr_abs_x(cpu, 0x0E08u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040DB471u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DB471u: {
            const uint32_t source_key = 0x040DB471u;
            cpu->pc = 0xB690u;
            js_op_sep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x040DB483u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040DB483u: {
            const uint32_t source_key = 0x040DB483u;
            cpu->pc = 0xB691u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040D73ABu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        default: return JS_EXEC_NOT_MINE;
    }
}
