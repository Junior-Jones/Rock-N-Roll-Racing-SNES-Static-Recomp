#include "v05c_static_cpu.h"

JSExecResult js_v05c_shard_0020(JSCPU *cpu, const JSBus *bus, JSStop *stop) {
    (void)bus;
    (void)stop;
    switch (js_cpu_context_key(cpu)) {
        case 0x00040007u: {
            const uint32_t source_key = 0x00040007u;
            cpu->pc = 0x8004u;
            cpu->pbr = 0x80u;
            cpu->pc = 0x800Cu;
            static const uint32_t allowed[] = { 0x04040067u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x00040B30u: {
            const uint32_t source_key = 0x00040B30u;
            cpu->pc = 0x816Au;
            cpu->pbr = 0x80u;
            cpu->pc = 0x816Au;
            static const uint32_t allowed[] = { 0x04040B50u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x00040B31u: {
            const uint32_t source_key = 0x00040B31u;
            cpu->pc = 0x816Au;
            cpu->pbr = 0x80u;
            cpu->pc = 0x816Au;
            static const uint32_t allowed[] = { 0x04040B51u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x00040B32u: {
            const uint32_t source_key = 0x00040B32u;
            cpu->pc = 0x816Au;
            cpu->pbr = 0x80u;
            cpu->pc = 0x816Au;
            static const uint32_t allowed[] = { 0x04040B52u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x00040B33u: {
            const uint32_t source_key = 0x00040B33u;
            cpu->pc = 0x816Au;
            cpu->pbr = 0x80u;
            cpu->pc = 0x816Au;
            static const uint32_t allowed[] = { 0x04040B53u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x00040B37u: {
            const uint32_t source_key = 0x00040B37u;
            cpu->pc = 0x816Au;
            cpu->pbr = 0x80u;
            cpu->pc = 0x816Au;
            static const uint32_t allowed[] = { 0x04040B57u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x00040DD8u: {
            const uint32_t source_key = 0x00040DD8u;
            cpu->pc = 0x81BFu;
            cpu->pbr = 0x80u;
            cpu->pc = 0x81BFu;
            static const uint32_t allowed[] = { 0x04040DF8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x00040DD9u: {
            const uint32_t source_key = 0x00040DD9u;
            cpu->pc = 0x81BFu;
            cpu->pbr = 0x80u;
            cpu->pc = 0x81BFu;
            static const uint32_t allowed[] = { 0x04040DF9u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x00040DDAu: {
            const uint32_t source_key = 0x00040DDAu;
            cpu->pc = 0x81BFu;
            cpu->pbr = 0x80u;
            cpu->pc = 0x81BFu;
            static const uint32_t allowed[] = { 0x04040DFAu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x00040DDBu: {
            const uint32_t source_key = 0x00040DDBu;
            cpu->pc = 0x81BFu;
            cpu->pbr = 0x80u;
            cpu->pc = 0x81BFu;
            static const uint32_t allowed[] = { 0x04040DFBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x00040DDFu: {
            const uint32_t source_key = 0x00040DDFu;
            cpu->pc = 0x81BFu;
            cpu->pbr = 0x80u;
            cpu->pc = 0x81BFu;
            static const uint32_t allowed[] = { 0x04040DFFu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x00040FE8u: {
            const uint32_t source_key = 0x00040FE8u;
            cpu->pc = 0x8201u;
            cpu->pbr = 0x80u;
            cpu->pc = 0x8201u;
            static const uint32_t allowed[] = { 0x04041008u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x00040FE9u: {
            const uint32_t source_key = 0x00040FE9u;
            cpu->pc = 0x8201u;
            cpu->pbr = 0x80u;
            cpu->pc = 0x8201u;
            static const uint32_t allowed[] = { 0x04041009u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x00040FEAu: {
            const uint32_t source_key = 0x00040FEAu;
            cpu->pc = 0x8201u;
            cpu->pbr = 0x80u;
            cpu->pc = 0x8201u;
            static const uint32_t allowed[] = { 0x0404100Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x00040FEBu: {
            const uint32_t source_key = 0x00040FEBu;
            cpu->pc = 0x8201u;
            cpu->pbr = 0x80u;
            cpu->pc = 0x8201u;
            static const uint32_t allowed[] = { 0x0404100Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x00040FEFu: {
            const uint32_t source_key = 0x00040FEFu;
            cpu->pc = 0x8201u;
            cpu->pbr = 0x80u;
            cpu->pc = 0x8201u;
            static const uint32_t allowed[] = { 0x0404100Fu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        default: return JS_EXEC_NOT_MINE;
    }
}
