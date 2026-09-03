#include "v05c_static_cpu.h"

JSExecResult js_v05c_shard_203E(JSCPU *cpu, const JSBus *bus, JSStop *stop) {
    (void)bus;
    (void)stop;
    switch (js_cpu_context_key(cpu)) {
        case 0x0407C6DBu: {
            const uint32_t source_key = 0x0407C6DBu;
            cpu->pc = 0xF8DEu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xFB2Fu;
            static const uint32_t allowed[] = { 0x0407D97Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C6F3u: {
            const uint32_t source_key = 0x0407C6F3u;
            cpu->pc = 0xF8E0u;
            uint16_t value = 0x0000u;
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407C703u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C703u: {
            const uint32_t source_key = 0x0407C703u;
            cpu->pc = 0xF8E3u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xFA38u;
            static const uint32_t allowed[] = { 0x0407D1C3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C71Bu: {
            const uint32_t source_key = 0x0407C71Bu;
            cpu->pc = 0xF8E5u;
            uint16_t value = 0x0001u;
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407C72Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C72Bu: {
            const uint32_t source_key = 0x0407C72Bu;
            cpu->pc = 0xF8E8u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xFA38u;
            static const uint32_t allowed[] = { 0x0407D1C3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C743u: {
            const uint32_t source_key = 0x0407C743u;
            cpu->pc = 0xF8EAu;
            uint16_t value = 0x0002u;
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407C753u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C753u: {
            const uint32_t source_key = 0x0407C753u;
            cpu->pc = 0xF8EDu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xFA38u;
            static const uint32_t allowed[] = { 0x0407D1C3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C76Bu: {
            const uint32_t source_key = 0x0407C76Bu;
            cpu->pc = 0xF8EFu;
            uint16_t value = 0x0003u;
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407C77Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C77Bu: {
            const uint32_t source_key = 0x0407C77Bu;
            cpu->pc = 0xF8F2u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xFA38u;
            static const uint32_t allowed[] = { 0x0407D1C3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C793u: {
            const uint32_t source_key = 0x0407C793u;
            cpu->pc = 0xF8F4u;
            uint16_t value = 0x0002u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407C7A3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C7A3u: {
            const uint32_t source_key = 0x0407C7A3u;
            cpu->pc = 0xF8F7u;
            uint32_t ea = js_addr_abs(cpu, 0x1AECu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407C7BBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C7BBu: {
            const uint32_t source_key = 0x0407C7BBu;
            cpu->pc = 0xF8F9u;
            uint16_t value = 0x0001u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407C7CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C7CBu: {
            const uint32_t source_key = 0x0407C7CBu;
            cpu->pc = 0xF8FCu;
            uint32_t ea = js_addr_abs(cpu, 0x1AEDu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407C7E3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C7E3u: {
            const uint32_t source_key = 0x0407C7E3u;
            cpu->pc = 0xF8FFu;
            uint32_t ea = js_addr_abs(cpu, 0x1AEEu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407C7FBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C7FBu: {
            const uint32_t source_key = 0x0407C7FBu;
            cpu->pc = 0xF900u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x04040253u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C823u: {
            const uint32_t source_key = 0x0407C823u;
            cpu->pc = 0xF907u;
            uint32_t ea = js_addr_abs(cpu, 0x0334u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407C83Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C83Bu: {
            const uint32_t source_key = 0x0407C83Bu;
            cpu->pc = 0xF909u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (15));
            static const uint32_t allowed[] = { 0x0407C84Bu, 0x0407C8C3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C84Bu: {
            const uint32_t source_key = 0x0407C84Bu;
            cpu->pc = 0xF90Bu;
            uint16_t value = 0x0000u;
            js_op_compare(cpu, cpu->x, value, 8u);
            static const uint32_t allowed[] = { 0x0407C85Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C85Bu: {
            const uint32_t source_key = 0x0407C85Bu;
            cpu->pc = 0xF90Du;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (3));
            static const uint32_t allowed[] = { 0x0407C86Bu, 0x0407C883u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C86Bu: {
            const uint32_t source_key = 0x0407C86Bu;
            cpu->pc = 0xF910u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xFA38u;
            static const uint32_t allowed[] = { 0x0407D1C3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C883u: {
            const uint32_t source_key = 0x0407C883u;
            cpu->pc = 0xF912u;
            uint16_t value = 0x0002u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407C893u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C893u: {
            const uint32_t source_key = 0x0407C893u;
            cpu->pc = 0xF913u;
            js_op_xba(cpu);
            static const uint32_t allowed[] = { 0x0407C89Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C89Bu: {
            const uint32_t source_key = 0x0407C89Bu;
            cpu->pc = 0xF915u;
            uint16_t value = 0x0001u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407C8ABu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C8ABu: {
            const uint32_t source_key = 0x0407C8ABu;
            cpu->pc = 0xF918u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF9C2u;
            static const uint32_t allowed[] = { 0x0407CE13u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C8C3u: {
            const uint32_t source_key = 0x0407C8C3u;
            cpu->pc = 0xF919u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x04040963u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C933u: {
            const uint32_t source_key = 0x0407C933u;
            cpu->pc = 0xF929u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF92Au;
            static const uint32_t allowed[] = { 0x0407C953u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C94Bu: {
            const uint32_t source_key = 0x0407C94Bu;
            cpu->pc = 0xF92Au;
            { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x040FAC0Bu, 0x040FADC3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C953u: {
            const uint32_t source_key = 0x0407C953u;
            cpu->pc = 0xF92Bu;
            if (!js_stack_push8(cpu, bus, (uint8_t)cpu->x, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407C95Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C95Bu: {
            const uint32_t source_key = 0x0407C95Bu;
            cpu->pc = 0xF92Cu;
            if (!js_stack_push8(cpu, bus, cpu->p, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407C963u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C963u: {
            const uint32_t source_key = 0x0407C963u;
            cpu->pc = 0xF92Eu;
            js_op_sep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x0407C973u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C973u: {
            const uint32_t source_key = 0x0407C973u;
            cpu->pc = 0xF931u;
            uint32_t ea = js_addr_abs(cpu, 0x0333u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407C98Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C98Bu: {
            const uint32_t source_key = 0x0407C98Bu;
            cpu->pc = 0xF933u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (10));
            static const uint32_t allowed[] = { 0x0407C99Bu, 0x0407C9EBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C99Bu: {
            const uint32_t source_key = 0x0407C99Bu;
            cpu->pc = 0xF935u;
            uint16_t value = 0x0032u;
            js_op_compare(cpu, cpu->a, value, 8u);
            static const uint32_t allowed[] = { 0x0407C9ABu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C9ABu: {
            const uint32_t source_key = 0x0407C9ABu;
            cpu->pc = 0xF937u;
            if (js_branch_condition(cpu, 'D')) cpu->pc = (uint16_t)(cpu->pc + (9));
            static const uint32_t allowed[] = { 0x0407C9BBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C9BBu: {
            const uint32_t source_key = 0x0407C9BBu;
            cpu->pc = 0xF938u;
            js_op_xba(cpu);
            static const uint32_t allowed[] = { 0x0407C9C3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C9C3u: {
            const uint32_t source_key = 0x0407C9C3u;
            cpu->pc = 0xF93Au;
            uint16_t value = 0x0002u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407C9D3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C9D3u: {
            const uint32_t source_key = 0x0407C9D3u;
            cpu->pc = 0xF93Du;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF9C2u;
            static const uint32_t allowed[] = { 0x0407CE13u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C9EBu: {
            const uint32_t source_key = 0x0407C9EBu;
            cpu->pc = 0xF93Eu;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; cpu->p = (uint8_t)(v | (cpu->e ? (JS_P_M|JS_P_X) : 0u)); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x0407C9F3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C9F3u: {
            const uint32_t source_key = 0x0407C9F3u;
            cpu->pc = 0xF93Fu;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_x(cpu, v, 8u); }
            static const uint32_t allowed[] = { 0x0407C9FBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407C9FBu: {
            const uint32_t source_key = 0x0407C9FBu;
            cpu->pc = 0xF940u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x0407C94Bu, 0x0407DA3Bu, 0x0407DADBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CBDBu: {
            const uint32_t source_key = 0x0407CBDBu;
            cpu->pc = 0xF97Cu;
            js_op_xba(cpu);
            static const uint32_t allowed[] = { 0x0407CBE3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CBE3u: {
            const uint32_t source_key = 0x0407CBE3u;
            cpu->pc = 0xF97Eu;
            uint16_t value = 0x0007u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407CBF3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CBF3u: {
            const uint32_t source_key = 0x0407CBF3u;
            cpu->pc = 0xF981u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF9C2u;
            static const uint32_t allowed[] = { 0x0407CE13u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CC0Bu: {
            const uint32_t source_key = 0x0407CC0Bu;
            cpu->pc = 0xF982u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x040408CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CC13u: {
            const uint32_t source_key = 0x0407CC13u;
            cpu->pc = 0xF985u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF986u;
            static const uint32_t allowed[] = { 0x0407CC33u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CC2Bu: {
            const uint32_t source_key = 0x0407CC2Bu;
            cpu->pc = 0xF986u;
            { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x040CFD53u, 0x040FAC2Bu, 0x040FADE3u, 0x040FB11Bu, 0x040FBBCBu, 0x040FBF1Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CC33u: {
            const uint32_t source_key = 0x0407CC33u;
            cpu->pc = 0xF987u;
            if (!js_stack_push8(cpu, bus, cpu->p, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407CC3Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CC3Bu: {
            const uint32_t source_key = 0x0407CC3Bu;
            cpu->pc = 0xF989u;
            js_op_rep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x0407CC49u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CC49u: {
            const uint32_t source_key = 0x0407CC49u;
            cpu->pc = 0xF98Cu;
            uint32_t ea = js_addr_abs(cpu, 0x1A5Cu);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x0407CC61u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CC61u: {
            const uint32_t source_key = 0x0407CC61u;
            cpu->pc = 0xF98Fu;
            uint32_t ea = js_addr_abs(cpu, 0x1A5Eu);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_compare(cpu, cpu->a, value, 16u);
            static const uint32_t allowed[] = { 0x0407CC79u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CC79u: {
            const uint32_t source_key = 0x0407CC79u;
            cpu->pc = 0xF991u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (5));
            static const uint32_t allowed[] = { 0x0407CC89u, 0x0407CCB1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CC89u: {
            const uint32_t source_key = 0x0407CC89u;
            cpu->pc = 0xF994u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF9F6u;
            static const uint32_t allowed[] = { 0x0407CFB1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CCA1u: {
            const uint32_t source_key = 0x0407CCA1u;
            cpu->pc = 0xF996u;
            if (js_branch_condition(cpu, 'A')) cpu->pc = (uint16_t)(cpu->pc + (-13));
            static const uint32_t allowed[] = { 0x0407CC49u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CCB1u: {
            const uint32_t source_key = 0x0407CCB1u;
            cpu->pc = 0xF997u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; cpu->p = (uint8_t)(v | (cpu->e ? (JS_P_M|JS_P_X) : 0u)); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x0407CCBBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CCBBu: {
            const uint32_t source_key = 0x0407CCBBu;
            cpu->pc = 0xF998u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x0404097Bu, 0x0407CC2Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CE13u: {
            const uint32_t source_key = 0x0407CE13u;
            cpu->pc = 0xF9C3u;
            if (!js_stack_push8(cpu, bus, cpu->p, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407CE1Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CE1Bu: {
            const uint32_t source_key = 0x0407CE1Bu;
            cpu->pc = 0xF9C5u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x0407CE28u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CE28u: {
            const uint32_t source_key = 0x0407CE28u;
            cpu->pc = 0xF9C6u;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->x, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407CE30u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CE30u: {
            const uint32_t source_key = 0x0407CE30u;
            cpu->pc = 0xF9C7u;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->y, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407CE38u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CE38u: {
            const uint32_t source_key = 0x0407CE38u;
            cpu->pc = 0xF9C8u;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->a, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407CE40u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CE40u: {
            const uint32_t source_key = 0x0407CE40u;
            cpu->pc = 0xF9CAu;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x0407CE53u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CE53u: {
            const uint32_t source_key = 0x0407CE53u;
            cpu->pc = 0xF9CDu;
            uint32_t ea = js_addr_abs(cpu, 0x1A5Eu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407CE6Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CE6Bu: {
            const uint32_t source_key = 0x0407CE6Bu;
            cpu->pc = 0xF9CEu;
            js_op_transfer(cpu, 'A');
            static const uint32_t allowed[] = { 0x0407CE73u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CE73u: {
            const uint32_t source_key = 0x0407CE73u;
            cpu->pc = 0xF9CFu;
            js_op_load_a(cpu, js_op_incdec(cpu, cpu->a, 1, 8u), 8u);
            static const uint32_t allowed[] = { 0x0407CE7Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CE7Bu: {
            const uint32_t source_key = 0x0407CE7Bu;
            cpu->pc = 0xF9D1u;
            uint16_t value = 0x003Fu;
            js_op_and(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407CE8Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CE8Bu: {
            const uint32_t source_key = 0x0407CE8Bu;
            cpu->pc = 0xF9D4u;
            uint32_t ea = js_addr_abs(cpu, 0x1A5Cu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_compare(cpu, cpu->a, value, 8u);
            static const uint32_t allowed[] = { 0x0407CEA3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CEA3u: {
            const uint32_t source_key = 0x0407CEA3u;
            cpu->pc = 0xF9D6u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (21));
            static const uint32_t allowed[] = { 0x0407CEB3u, 0x0407CF5Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CEB3u: {
            const uint32_t source_key = 0x0407CEB3u;
            cpu->pc = 0xF9D7u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 8u); }
            static const uint32_t allowed[] = { 0x0407CEBBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CEBBu: {
            const uint32_t source_key = 0x0407CEBBu;
            cpu->pc = 0xF9DAu;
            uint32_t ea = js_addr_abs_x(cpu, 0x1AA2u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407CED3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CED3u: {
            const uint32_t source_key = 0x0407CED3u;
            cpu->pc = 0xF9DBu;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 8u); }
            static const uint32_t allowed[] = { 0x0407CEDBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CEDBu: {
            const uint32_t source_key = 0x0407CEDBu;
            cpu->pc = 0xF9DEu;
            uint32_t ea = js_addr_abs_x(cpu, 0x1A62u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407CEF3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CEF3u: {
            const uint32_t source_key = 0x0407CEF3u;
            cpu->pc = 0xF9DFu;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, 1, 8u), 8u);
            static const uint32_t allowed[] = { 0x0407CEFBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CEFBu: {
            const uint32_t source_key = 0x0407CEFBu;
            cpu->pc = 0xF9E0u;
            js_op_transfer(cpu, 'F');
            static const uint32_t allowed[] = { 0x0407CF03u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CF03u: {
            const uint32_t source_key = 0x0407CF03u;
            cpu->pc = 0xF9E2u;
            uint16_t value = 0x003Fu;
            js_op_and(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407CF13u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CF13u: {
            const uint32_t source_key = 0x0407CF13u;
            cpu->pc = 0xF9E5u;
            uint32_t ea = js_addr_abs(cpu, 0x1A5Eu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407CF2Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CF2Bu: {
            const uint32_t source_key = 0x0407CF2Bu;
            cpu->pc = 0xF9E7u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x0407CF38u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CF38u: {
            const uint32_t source_key = 0x0407CF38u;
            cpu->pc = 0xF9E8u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_y(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x0407CF40u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CF40u: {
            const uint32_t source_key = 0x0407CF40u;
            cpu->pc = 0xF9E9u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_x(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x0407CF48u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CF48u: {
            const uint32_t source_key = 0x0407CF48u;
            cpu->pc = 0xF9EAu;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; cpu->p = (uint8_t)(v | (cpu->e ? (JS_P_M|JS_P_X) : 0u)); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x0407CF53u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CF53u: {
            const uint32_t source_key = 0x0407CF53u;
            cpu->pc = 0xF9EBu;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x0407C8C3u, 0x0407C9EBu, 0x0407CC0Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CF5Bu: {
            const uint32_t source_key = 0x0407CF5Bu;
            cpu->pc = 0xF9EDu;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x0407CF68u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CF68u: {
            const uint32_t source_key = 0x0407CF68u;
            cpu->pc = 0xF9EEu;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x0407CF70u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CF70u: {
            const uint32_t source_key = 0x0407CF70u;
            cpu->pc = 0xF9EFu;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_y(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x0407CF78u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CF78u: {
            const uint32_t source_key = 0x0407CF78u;
            cpu->pc = 0xF9F0u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_x(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x0407CF80u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CF80u: {
            const uint32_t source_key = 0x0407CF80u;
            cpu->pc = 0xF9F1u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; cpu->p = (uint8_t)(v | (cpu->e ? (JS_P_M|JS_P_X) : 0u)); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x0407CF8Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CF8Bu: {
            const uint32_t source_key = 0x0407CF8Bu;
            cpu->pc = 0xF9F2u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x0407C8C3u, 0x0407C9EBu, 0x0407CC0Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CFB1u: {
            const uint32_t source_key = 0x0407CFB1u;
            cpu->pc = 0xF9F7u;
            if (!js_stack_push8(cpu, bus, cpu->p, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407CFB9u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CFB9u: {
            const uint32_t source_key = 0x0407CFB9u;
            cpu->pc = 0xF9F9u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x0407CFC8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CFC8u: {
            const uint32_t source_key = 0x0407CFC8u;
            cpu->pc = 0xF9FAu;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->x, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407CFD0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CFD0u: {
            const uint32_t source_key = 0x0407CFD0u;
            cpu->pc = 0xF9FBu;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->y, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407CFD8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CFD8u: {
            const uint32_t source_key = 0x0407CFD8u;
            cpu->pc = 0xF9FDu;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x0407CFEBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407CFEBu: {
            const uint32_t source_key = 0x0407CFEBu;
            cpu->pc = 0xFA00u;
            uint32_t ea = js_addr_abs(cpu, 0x2142u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407D003u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D003u: {
            const uint32_t source_key = 0x0407D003u;
            cpu->pc = 0xFA03u;
            uint32_t ea = js_addr_abs(cpu, 0x1A60u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_compare(cpu, cpu->a, value, 8u);
            static const uint32_t allowed[] = { 0x0407D01Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D01Bu: {
            const uint32_t source_key = 0x0407D01Bu;
            cpu->pc = 0xFA05u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (44));
            static const uint32_t allowed[] = { 0x0407D02Bu, 0x0407D18Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D02Bu: {
            const uint32_t source_key = 0x0407D02Bu;
            cpu->pc = 0xFA06u;
            js_op_xba(cpu);
            static const uint32_t allowed[] = { 0x0407D033u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D033u: {
            const uint32_t source_key = 0x0407D033u;
            cpu->pc = 0xFA09u;
            uint32_t ea = js_addr_abs(cpu, 0x1A5Cu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407D04Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D04Bu: {
            const uint32_t source_key = 0x0407D04Bu;
            cpu->pc = 0xFA0Cu;
            uint32_t ea = js_addr_abs(cpu, 0x1A5Eu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_compare(cpu, cpu->a, value, 8u);
            static const uint32_t allowed[] = { 0x0407D063u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D063u: {
            const uint32_t source_key = 0x0407D063u;
            cpu->pc = 0xFA0Eu;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (35));
            static const uint32_t allowed[] = { 0x0407D073u, 0x0407D18Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D073u: {
            const uint32_t source_key = 0x0407D073u;
            cpu->pc = 0xFA0Fu;
            js_op_transfer(cpu, 'A');
            static const uint32_t allowed[] = { 0x0407D07Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D07Bu: {
            const uint32_t source_key = 0x0407D07Bu;
            cpu->pc = 0xFA12u;
            uint32_t ea = js_addr_abs_x(cpu, 0x1A62u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407D093u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D093u: {
            const uint32_t source_key = 0x0407D093u;
            cpu->pc = 0xFA13u;
            if (!js_stack_push8(cpu, bus, (uint8_t)cpu->a, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D09Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D09Bu: {
            const uint32_t source_key = 0x0407D09Bu;
            cpu->pc = 0xFA14u;
            js_op_xba(cpu);
            static const uint32_t allowed[] = { 0x0407D0A3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D0A3u: {
            const uint32_t source_key = 0x0407D0A3u;
            cpu->pc = 0xFA16u;
            uint16_t value = 0x00C0u;
            js_op_eor(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407D0B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D0B3u: {
            const uint32_t source_key = 0x0407D0B3u;
            cpu->pc = 0xFA19u;
            uint32_t ea = js_addr_abs(cpu, 0x1A60u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D0CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D0CBu: {
            const uint32_t source_key = 0x0407D0CBu;
            cpu->pc = 0xFA1Cu;
            uint32_t ea = js_addr_abs_x(cpu, 0x1AA2u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_ora(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407D0E3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D0E3u: {
            const uint32_t source_key = 0x0407D0E3u;
            cpu->pc = 0xFA1Du;
            if (!js_stack_push8(cpu, bus, (uint8_t)cpu->a, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D0EBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D0EBu: {
            const uint32_t source_key = 0x0407D0EBu;
            cpu->pc = 0xFA1Eu;
            js_op_transfer(cpu, 'F');
            static const uint32_t allowed[] = { 0x0407D0F3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D0F3u: {
            const uint32_t source_key = 0x0407D0F3u;
            cpu->pc = 0xFA1Fu;
            js_op_load_a(cpu, js_op_incdec(cpu, cpu->a, 1, 8u), 8u);
            static const uint32_t allowed[] = { 0x0407D0FBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D0FBu: {
            const uint32_t source_key = 0x0407D0FBu;
            cpu->pc = 0xFA21u;
            uint16_t value = 0x003Fu;
            js_op_and(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407D10Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D10Bu: {
            const uint32_t source_key = 0x0407D10Bu;
            cpu->pc = 0xFA24u;
            uint32_t ea = js_addr_abs(cpu, 0x1A5Cu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D123u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D123u: {
            const uint32_t source_key = 0x0407D123u;
            cpu->pc = 0xFA26u;
            js_op_rep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x0407D131u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D131u: {
            const uint32_t source_key = 0x0407D131u;
            cpu->pc = 0xFA27u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x0407D139u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D139u: {
            const uint32_t source_key = 0x0407D139u;
            cpu->pc = 0xFA2Au;
            uint32_t ea = js_addr_abs(cpu, 0x2142u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D151u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D151u: {
            const uint32_t source_key = 0x0407D151u;
            cpu->pc = 0xFA2Cu;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x0407D160u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D160u: {
            const uint32_t source_key = 0x0407D160u;
            cpu->pc = 0xFA2Du;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_y(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x0407D168u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D168u: {
            const uint32_t source_key = 0x0407D168u;
            cpu->pc = 0xFA2Eu;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_x(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x0407D170u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D170u: {
            const uint32_t source_key = 0x0407D170u;
            cpu->pc = 0xFA2Fu;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; cpu->p = (uint8_t)(v | (cpu->e ? (JS_P_M|JS_P_X) : 0u)); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x0407D179u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D179u: {
            const uint32_t source_key = 0x0407D179u;
            cpu->pc = 0xFA30u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_C);
            static const uint32_t allowed[] = { 0x0407D181u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D181u: {
            const uint32_t source_key = 0x0407D181u;
            cpu->pc = 0xFA31u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x0407CCA1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D18Bu: {
            const uint32_t source_key = 0x0407D18Bu;
            cpu->pc = 0xFA33u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x0407D198u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D198u: {
            const uint32_t source_key = 0x0407D198u;
            cpu->pc = 0xFA34u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_y(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x0407D1A0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D1A0u: {
            const uint32_t source_key = 0x0407D1A0u;
            cpu->pc = 0xFA35u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_x(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x0407D1A8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D1A8u: {
            const uint32_t source_key = 0x0407D1A8u;
            cpu->pc = 0xFA36u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; cpu->p = (uint8_t)(v | (cpu->e ? (JS_P_M|JS_P_X) : 0u)); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x0407D1B1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D1B1u: {
            const uint32_t source_key = 0x0407D1B1u;
            cpu->pc = 0xFA37u;
            cpu->p = (uint8_t)(cpu->p | JS_P_C);
            static const uint32_t allowed[] = { 0x0407D1B9u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D1B9u: {
            const uint32_t source_key = 0x0407D1B9u;
            cpu->pc = 0xFA38u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x0407CCA1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D1C3u: {
            const uint32_t source_key = 0x0407D1C3u;
            cpu->pc = 0xFA39u;
            if (!js_stack_push8(cpu, bus, cpu->p, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D1CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D1CBu: {
            const uint32_t source_key = 0x0407D1CBu;
            cpu->pc = 0xFA3Bu;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x0407D1D8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D1D8u: {
            const uint32_t source_key = 0x0407D1D8u;
            cpu->pc = 0xFA3Cu;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->a, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D1E0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D1E0u: {
            const uint32_t source_key = 0x0407D1E0u;
            cpu->pc = 0xFA3Du;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->x, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D1E8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D1E8u: {
            const uint32_t source_key = 0x0407D1E8u;
            cpu->pc = 0xFA3Eu;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->y, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D1F0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D1F0u: {
            const uint32_t source_key = 0x0407D1F0u;
            cpu->pc = 0xFA40u;
            js_op_sep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x0407D202u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D202u: {
            const uint32_t source_key = 0x0407D202u;
            cpu->pc = 0xFA42u;
            uint16_t value = 0x00FFu;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407D212u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D212u: {
            const uint32_t source_key = 0x0407D212u;
            cpu->pc = 0xFA45u;
            uint32_t ea = js_addr_abs(cpu, 0x2140u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D22Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D22Au: {
            const uint32_t source_key = 0x0407D22Au;
            cpu->pc = 0xFA48u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xFAEAu;
            static const uint32_t allowed[] = { 0x0407D752u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D242u: {
            const uint32_t source_key = 0x0407D242u;
            cpu->pc = 0xFA4Au;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x0407D250u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D250u: {
            const uint32_t source_key = 0x0407D250u;
            cpu->pc = 0xFA4Du;
            uint16_t value = 0xBBAAu;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x0407D268u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D268u: {
            const uint32_t source_key = 0x0407D268u;
            cpu->pc = 0xFA50u;
            uint32_t ea = js_addr_abs(cpu, 0x2140u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_compare(cpu, cpu->a, value, 16u);
            static const uint32_t allowed[] = { 0x0407D280u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D280u: {
            const uint32_t source_key = 0x0407D280u;
            cpu->pc = 0xFA52u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-5));
            static const uint32_t allowed[] = { 0x0407D268u, 0x0407D290u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D290u: {
            const uint32_t source_key = 0x0407D290u;
            cpu->pc = 0xFA54u;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long(cpu, bus, 0x91u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 1, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x0407D2A0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D2A0u: {
            const uint32_t source_key = 0x0407D2A0u;
            cpu->pc = 0xFA55u;
            js_op_transfer(cpu, 'A');
            static const uint32_t allowed[] = { 0x0407D2A8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D2A8u: {
            const uint32_t source_key = 0x0407D2A8u;
            cpu->pc = 0xFA58u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xFB1Du;
            static const uint32_t allowed[] = { 0x0407D8E8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D2C0u: {
            const uint32_t source_key = 0x0407D2C0u;
            cpu->pc = 0xFA5Bu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xFB1Du;
            static const uint32_t allowed[] = { 0x0407D8E8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D2D8u: {
            const uint32_t source_key = 0x0407D2D8u;
            cpu->pc = 0xFA5Du;
            js_op_sep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x0407D2EAu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D2EAu: {
            const uint32_t source_key = 0x0407D2EAu;
            cpu->pc = 0xFA5Fu;
            uint32_t ea = js_addr_dp(cpu, 0x90u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D2FAu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D2FAu: {
            const uint32_t source_key = 0x0407D2FAu;
            cpu->pc = 0xFA61u;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long(cpu, bus, 0x91u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407D30Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D30Au: {
            const uint32_t source_key = 0x0407D30Au;
            cpu->pc = 0xFA64u;
            uint32_t ea = js_addr_abs(cpu, 0x2142u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D322u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D322u: {
            const uint32_t source_key = 0x0407D322u;
            cpu->pc = 0xFA67u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xFB1Du;
            static const uint32_t allowed[] = { 0x0407D8EAu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D33Au: {
            const uint32_t source_key = 0x0407D33Au;
            cpu->pc = 0xFA69u;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long(cpu, bus, 0x91u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407D34Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D34Au: {
            const uint32_t source_key = 0x0407D34Au;
            cpu->pc = 0xFA6Cu;
            uint32_t ea = js_addr_abs(cpu, 0x2143u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D362u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D362u: {
            const uint32_t source_key = 0x0407D362u;
            cpu->pc = 0xFA6Fu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xFB1Du;
            static const uint32_t allowed[] = { 0x0407D8EAu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D37Au: {
            const uint32_t source_key = 0x0407D37Au;
            cpu->pc = 0xFA71u;
            js_op_rep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x0407D388u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D388u: {
            const uint32_t source_key = 0x0407D388u;
            cpu->pc = 0xFA73u;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long(cpu, bus, 0x91u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 1, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x0407D398u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D398u: {
            const uint32_t source_key = 0x0407D398u;
            cpu->pc = 0xFA74u;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->a, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D3A0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D3A0u: {
            const uint32_t source_key = 0x0407D3A0u;
            cpu->pc = 0xFA76u;
            js_op_sep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x0407D3B2u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D3B2u: {
            const uint32_t source_key = 0x0407D3B2u;
            cpu->pc = 0xFA79u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xFB1Du;
            static const uint32_t allowed[] = { 0x0407D8EAu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D3CAu: {
            const uint32_t source_key = 0x0407D3CAu;
            cpu->pc = 0xFA7Bu;
            uint16_t value = 0x0001u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407D3DAu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D3DAu: {
            const uint32_t source_key = 0x0407D3DAu;
            cpu->pc = 0xFA7Eu;
            uint32_t ea = js_addr_abs(cpu, 0x2141u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D3F2u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D3F2u: {
            const uint32_t source_key = 0x0407D3F2u;
            cpu->pc = 0xFA80u;
            uint16_t value = 0x00CCu;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407D402u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D402u: {
            const uint32_t source_key = 0x0407D402u;
            cpu->pc = 0xFA83u;
            uint32_t ea = js_addr_abs(cpu, 0x2140u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D41Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D41Au: {
            const uint32_t source_key = 0x0407D41Au;
            cpu->pc = 0xFA86u;
            uint32_t ea = js_addr_abs(cpu, 0x2140u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_compare(cpu, cpu->a, value, 8u);
            static const uint32_t allowed[] = { 0x0407D432u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D432u: {
            const uint32_t source_key = 0x0407D432u;
            cpu->pc = 0xFA88u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-10));
            static const uint32_t allowed[] = { 0x0407D3F2u, 0x0407D442u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D442u: {
            const uint32_t source_key = 0x0407D442u;
            cpu->pc = 0xFA8Bu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xFB1Du;
            static const uint32_t allowed[] = { 0x0407D8EAu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D45Au: {
            const uint32_t source_key = 0x0407D45Au;
            cpu->pc = 0xFA8Du;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long(cpu, bus, 0x91u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407D46Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D46Au: {
            const uint32_t source_key = 0x0407D46Au;
            cpu->pc = 0xFA90u;
            uint32_t ea = js_addr_abs(cpu, 0x2141u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D482u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D482u: {
            const uint32_t source_key = 0x0407D482u;
            cpu->pc = 0xFA92u;
            uint32_t ea = js_addr_dp(cpu, 0x90u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407D492u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D492u: {
            const uint32_t source_key = 0x0407D492u;
            cpu->pc = 0xFA95u;
            uint32_t ea = js_addr_abs(cpu, 0x2140u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D4AAu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D4AAu: {
            const uint32_t source_key = 0x0407D4AAu;
            cpu->pc = 0xFA98u;
            uint32_t ea = js_addr_abs(cpu, 0x2140u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_compare(cpu, cpu->a, value, 8u);
            static const uint32_t allowed[] = { 0x0407D4C2u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D4C2u: {
            const uint32_t source_key = 0x0407D4C2u;
            cpu->pc = 0xFA9Au;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-5));
            static const uint32_t allowed[] = { 0x0407D4AAu, 0x0407D4D2u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D4D2u: {
            const uint32_t source_key = 0x0407D4D2u;
            cpu->pc = 0xFA9Cu;
            uint32_t ea = js_addr_dp(cpu, 0x90u);
            uint16_t original = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
            uint16_t result = js_op_incdec(cpu, original, 1, 8u);
            if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D4E2u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D4E2u: {
            const uint32_t source_key = 0x0407D4E2u;
            cpu->pc = 0xFA9Du;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, -1, 16u), 16u);
            static const uint32_t allowed[] = { 0x0407D4EAu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D4EAu: {
            const uint32_t source_key = 0x0407D4EAu;
            cpu->pc = 0xFA9Fu;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-23));
            static const uint32_t allowed[] = { 0x0407D442u, 0x0407D4FAu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D4FAu: {
            const uint32_t source_key = 0x0407D4FAu;
            cpu->pc = 0xFAA1u;
            js_op_rep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x0407D508u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D508u: {
            const uint32_t source_key = 0x0407D508u;
            cpu->pc = 0xFAA2u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x0407D510u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D510u: {
            const uint32_t source_key = 0x0407D510u;
            cpu->pc = 0xFAA4u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (3));
            static const uint32_t allowed[] = { 0x0407D520u, 0x0407D538u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D520u: {
            const uint32_t source_key = 0x0407D520u;
            cpu->pc = 0xFAA7u;
            uint16_t value = 0xFFC0u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x0407D538u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D538u: {
            const uint32_t source_key = 0x0407D538u;
            cpu->pc = 0xFAA8u;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->a, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D540u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D540u: {
            const uint32_t source_key = 0x0407D540u;
            cpu->pc = 0xFAABu;
            uint32_t ea = js_addr_abs(cpu, 0x2142u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D558u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D558u: {
            const uint32_t source_key = 0x0407D558u;
            cpu->pc = 0xFAADu;
            js_op_sep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x0407D56Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D56Au: {
            const uint32_t source_key = 0x0407D56Au;
            cpu->pc = 0xFAB0u;
            uint32_t ea = js_addr_abs(cpu, 0x2141u);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D582u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D582u: {
            const uint32_t source_key = 0x0407D582u;
            cpu->pc = 0xFAB2u;
            uint32_t ea = js_addr_dp(cpu, 0x90u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407D592u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D592u: {
            const uint32_t source_key = 0x0407D592u;
            cpu->pc = 0xFAB3u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_C);
            static const uint32_t allowed[] = { 0x0407D59Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D59Au: {
            const uint32_t source_key = 0x0407D59Au;
            cpu->pc = 0xFAB5u;
            uint16_t value = 0x0003u;
            js_op_adc(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407D5AAu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D5AAu: {
            const uint32_t source_key = 0x0407D5AAu;
            cpu->pc = 0xFAB8u;
            uint32_t ea = js_addr_abs(cpu, 0x2140u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D5C2u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D5C2u: {
            const uint32_t source_key = 0x0407D5C2u;
            cpu->pc = 0xFABAu;
            js_op_rep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x0407D5D0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D5D0u: {
            const uint32_t source_key = 0x0407D5D0u;
            cpu->pc = 0xFABBu;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_x(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x0407D5D8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D5D8u: {
            const uint32_t source_key = 0x0407D5D8u;
            cpu->pc = 0xFABEu;
            uint16_t value = 0xFFC0u;
            js_op_compare(cpu, cpu->x, value, 16u);
            static const uint32_t allowed[] = { 0x0407D5F0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D5F0u: {
            const uint32_t source_key = 0x0407D5F0u;
            cpu->pc = 0xFAC0u;
            if (js_branch_condition(cpu, 'E')) cpu->pc = (uint16_t)(cpu->pc + (28));
            static const uint32_t allowed[] = { 0x0407D600u, 0x0407D6E0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D600u: {
            const uint32_t source_key = 0x0407D600u;
            cpu->pc = 0xFAC2u;
            js_op_sep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x0407D612u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D612u: {
            const uint32_t source_key = 0x0407D612u;
            cpu->pc = 0xFAC4u;
            uint16_t value = 0x0080u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407D622u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D622u: {
            const uint32_t source_key = 0x0407D622u;
            cpu->pc = 0xFAC7u;
            uint32_t ea = js_addr_abs(cpu, 0x2142u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_compare(cpu, cpu->a, value, 8u);
            static const uint32_t allowed[] = { 0x0407D63Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D63Au: {
            const uint32_t source_key = 0x0407D63Au;
            cpu->pc = 0xFAC9u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-5));
            static const uint32_t allowed[] = { 0x0407D622u, 0x0407D64Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D64Au: {
            const uint32_t source_key = 0x0407D64Au;
            cpu->pc = 0xFACCu;
            uint32_t ea = js_addr_abs(cpu, 0x1A60u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D662u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D662u: {
            const uint32_t source_key = 0x0407D662u;
            cpu->pc = 0xFACFu;
            uint32_t ea = js_addr_abs(cpu, 0x2142u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D67Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D67Au: {
            const uint32_t source_key = 0x0407D67Au;
            cpu->pc = 0xFAD1u;
            js_op_rep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x0407D688u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D688u: {
            const uint32_t source_key = 0x0407D688u;
            cpu->pc = 0xFAD4u;
            uint16_t value = 0x0001u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x0407D6A0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D6A0u: {
            const uint32_t source_key = 0x0407D6A0u;
            cpu->pc = 0xFAD7u;
            uint32_t ea = js_addr_abs(cpu, 0x1A5Cu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D6B8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D6B8u: {
            const uint32_t source_key = 0x0407D6B8u;
            cpu->pc = 0xFADAu;
            uint32_t ea = js_addr_abs(cpu, 0x1A5Eu);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D6D0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D6D0u: {
            const uint32_t source_key = 0x0407D6D0u;
            cpu->pc = 0xFADCu;
            if (js_branch_condition(cpu, 'A')) cpu->pc = (uint16_t)(cpu->pc + (7));
            static const uint32_t allowed[] = { 0x0407D718u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D6E0u: {
            const uint32_t source_key = 0x0407D6E0u;
            cpu->pc = 0xFADEu;
            js_op_sep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x0407D6F2u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D6F2u: {
            const uint32_t source_key = 0x0407D6F2u;
            cpu->pc = 0xFAE1u;
            uint32_t ea = js_addr_abs(cpu, 0x2140u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_compare(cpu, cpu->a, value, 8u);
            static const uint32_t allowed[] = { 0x0407D70Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D70Au: {
            const uint32_t source_key = 0x0407D70Au;
            cpu->pc = 0xFAE3u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-5));
            static const uint32_t allowed[] = { 0x0407D6F2u, 0x0407D71Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D718u: {
            const uint32_t source_key = 0x0407D718u;
            cpu->pc = 0xFAE5u;
            js_op_rep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x0407D728u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D71Au: {
            const uint32_t source_key = 0x0407D71Au;
            cpu->pc = 0xFAE5u;
            js_op_rep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x0407D728u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D728u: {
            const uint32_t source_key = 0x0407D728u;
            cpu->pc = 0xFAE6u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_y(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x0407D730u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D730u: {
            const uint32_t source_key = 0x0407D730u;
            cpu->pc = 0xFAE7u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_x(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x0407D738u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D738u: {
            const uint32_t source_key = 0x0407D738u;
            cpu->pc = 0xFAE8u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x0407D740u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D740u: {
            const uint32_t source_key = 0x0407D740u;
            cpu->pc = 0xFAE9u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; cpu->p = (uint8_t)(v | (cpu->e ? (JS_P_M|JS_P_X) : 0u)); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x0407D74Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D74Bu: {
            const uint32_t source_key = 0x0407D74Bu;
            cpu->pc = 0xFAEAu;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x0407C71Bu, 0x0407C743u, 0x0407C76Bu, 0x0407C793u, 0x0407C883u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D752u: {
            const uint32_t source_key = 0x0407D752u;
            cpu->pc = 0xFAEBu;
            if (!js_stack_push8(cpu, bus, cpu->p, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D75Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D75Au: {
            const uint32_t source_key = 0x0407D75Au;
            cpu->pc = 0xFAEDu;
            js_op_sep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x0407D76Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D76Au: {
            const uint32_t source_key = 0x0407D76Au;
            cpu->pc = 0xFAEFu;
            uint16_t value = 0x0082u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407D77Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D77Au: {
            const uint32_t source_key = 0x0407D77Au;
            cpu->pc = 0xFAF1u;
            uint32_t ea = js_addr_dp(cpu, 0x93u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D78Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D78Au: {
            const uint32_t source_key = 0x0407D78Au;
            cpu->pc = 0xFAF3u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x0407D798u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D798u: {
            const uint32_t source_key = 0x0407D798u;
            cpu->pc = 0xFAF4u;
            js_op_transfer(cpu, 'F');
            static const uint32_t allowed[] = { 0x0407D7A0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D7A0u: {
            const uint32_t source_key = 0x0407D7A0u;
            cpu->pc = 0xFAF7u;
            uint16_t value = 0x00FFu;
            js_op_and(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x0407D7B8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D7B8u: {
            const uint32_t source_key = 0x0407D7B8u;
            cpu->pc = 0xFAF8u;
            js_op_transfer(cpu, 'A');
            static const uint32_t allowed[] = { 0x0407D7C0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D7C0u: {
            const uint32_t source_key = 0x0407D7C0u;
            cpu->pc = 0xFAFBu;
            uint16_t value = 0x8000u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x0407D7D8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D7D8u: {
            const uint32_t source_key = 0x0407D7D8u;
            cpu->pc = 0xFAFDu;
            uint32_t ea = js_addr_dp(cpu, 0x91u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D7E8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D7E8u: {
            const uint32_t source_key = 0x0407D7E8u;
            cpu->pc = 0xFAFEu;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, -1, 16u), 16u);
            static const uint32_t allowed[] = { 0x0407D7F0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D7F0u: {
            const uint32_t source_key = 0x0407D7F0u;
            cpu->pc = 0xFB00u;
            if (js_branch_condition(cpu, 'M')) cpu->pc = (uint16_t)(cpu->pc + (27));
            static const uint32_t allowed[] = { 0x0407D800u, 0x0407D8D8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D800u: {
            const uint32_t source_key = 0x0407D800u;
            cpu->pc = 0xFB01u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_C);
            static const uint32_t allowed[] = { 0x0407D808u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D808u: {
            const uint32_t source_key = 0x0407D808u;
            cpu->pc = 0xFB03u;
            uint32_t ea = 0u;
            if (!js_addr_dp_ind_long(cpu, bus, 0x91u, &ea, stop, source_key)) return JS_EXEC_STOP;
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 1, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_adc(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x0407D818u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D818u: {
            const uint32_t source_key = 0x0407D818u;
            cpu->pc = 0xFB05u;
            if (js_branch_condition(cpu, 'C')) cpu->pc = (uint16_t)(cpu->pc + (6));
            static const uint32_t allowed[] = { 0x0407D828u, 0x0407D858u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D828u: {
            const uint32_t source_key = 0x0407D828u;
            cpu->pc = 0xFB07u;
            uint32_t ea = js_addr_dp(cpu, 0x93u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D838u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D838u: {
            const uint32_t source_key = 0x0407D838u;
            cpu->pc = 0xFB08u;
            cpu->p = (uint8_t)(cpu->p | JS_P_C);
            static const uint32_t allowed[] = { 0x0407D840u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D840u: {
            const uint32_t source_key = 0x0407D840u;
            cpu->pc = 0xFB0Bu;
            uint16_t value = 0x8000u;
            js_op_sbc(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x0407D858u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D858u: {
            const uint32_t source_key = 0x0407D858u;
            cpu->pc = 0xFB0Cu;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_C);
            static const uint32_t allowed[] = { 0x0407D860u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D860u: {
            const uint32_t source_key = 0x0407D860u;
            cpu->pc = 0xFB0Fu;
            uint16_t value = 0x0006u;
            js_op_adc(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x0407D878u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D878u: {
            const uint32_t source_key = 0x0407D878u;
            cpu->pc = 0xFB11u;
            if (js_branch_condition(cpu, 'C')) cpu->pc = (uint16_t)(cpu->pc + (6));
            static const uint32_t allowed[] = { 0x0407D888u, 0x0407D8B8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D888u: {
            const uint32_t source_key = 0x0407D888u;
            cpu->pc = 0xFB13u;
            uint32_t ea = js_addr_dp(cpu, 0x93u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D898u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D898u: {
            const uint32_t source_key = 0x0407D898u;
            cpu->pc = 0xFB14u;
            cpu->p = (uint8_t)(cpu->p | JS_P_C);
            static const uint32_t allowed[] = { 0x0407D8A0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D8A0u: {
            const uint32_t source_key = 0x0407D8A0u;
            cpu->pc = 0xFB17u;
            uint16_t value = 0x8000u;
            js_op_sbc(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x0407D8B8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D8B8u: {
            const uint32_t source_key = 0x0407D8B8u;
            cpu->pc = 0xFB19u;
            uint32_t ea = js_addr_dp(cpu, 0x91u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D8C8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D8C8u: {
            const uint32_t source_key = 0x0407D8C8u;
            cpu->pc = 0xFB1Bu;
            if (js_branch_condition(cpu, 'A')) cpu->pc = (uint16_t)(cpu->pc + (-30));
            static const uint32_t allowed[] = { 0x0407D7E8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D8D8u: {
            const uint32_t source_key = 0x0407D8D8u;
            cpu->pc = 0xFB1Cu;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; cpu->p = (uint8_t)(v | (cpu->e ? (JS_P_M|JS_P_X) : 0u)); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x0407D8E2u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D8E2u: {
            const uint32_t source_key = 0x0407D8E2u;
            cpu->pc = 0xFB1Du;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x0407D242u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D8E8u: {
            const uint32_t source_key = 0x0407D8E8u;
            cpu->pc = 0xFB1Eu;
            if (!js_stack_push8(cpu, bus, cpu->p, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D8F0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D8EAu: {
            const uint32_t source_key = 0x0407D8EAu;
            cpu->pc = 0xFB1Eu;
            if (!js_stack_push8(cpu, bus, cpu->p, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D8F2u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D8F0u: {
            const uint32_t source_key = 0x0407D8F0u;
            cpu->pc = 0xFB20u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x0407D900u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D8F2u: {
            const uint32_t source_key = 0x0407D8F2u;
            cpu->pc = 0xFB20u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x0407D900u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D900u: {
            const uint32_t source_key = 0x0407D900u;
            cpu->pc = 0xFB22u;
            uint32_t ea = js_addr_dp(cpu, 0x91u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D910u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D910u: {
            const uint32_t source_key = 0x0407D910u;
            cpu->pc = 0xFB24u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (9));
            static const uint32_t allowed[] = { 0x0407D920u, 0x0407D968u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D920u: {
            const uint32_t source_key = 0x0407D920u;
            cpu->pc = 0xFB27u;
            uint16_t value = 0x8000u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x0407D938u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D938u: {
            const uint32_t source_key = 0x0407D938u;
            cpu->pc = 0xFB29u;
            uint32_t ea = js_addr_dp(cpu, 0x91u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D948u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D948u: {
            const uint32_t source_key = 0x0407D948u;
            cpu->pc = 0xFB2Bu;
            js_op_sep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x0407D95Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D95Au: {
            const uint32_t source_key = 0x0407D95Au;
            cpu->pc = 0xFB2Du;
            uint32_t ea = js_addr_dp(cpu, 0x93u);
            uint16_t original = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
            uint16_t result = js_op_incdec(cpu, original, 1, 8u);
            if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D96Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D968u: {
            const uint32_t source_key = 0x0407D968u;
            cpu->pc = 0xFB2Eu;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; cpu->p = (uint8_t)(v | (cpu->e ? (JS_P_M|JS_P_X) : 0u)); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x0407D970u, 0x0407D972u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D96Au: {
            const uint32_t source_key = 0x0407D96Au;
            cpu->pc = 0xFB2Eu;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; cpu->p = (uint8_t)(v | (cpu->e ? (JS_P_M|JS_P_X) : 0u)); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x0407D970u, 0x0407D972u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D970u: {
            const uint32_t source_key = 0x0407D970u;
            cpu->pc = 0xFB2Fu;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x0407D2C0u, 0x0407D2D8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D972u: {
            const uint32_t source_key = 0x0407D972u;
            cpu->pc = 0xFB2Fu;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x0407D33Au, 0x0407D37Au, 0x0407D3CAu, 0x0407D45Au };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D97Bu: {
            const uint32_t source_key = 0x0407D97Bu;
            cpu->pc = 0xFB30u;
            if (!js_stack_push8(cpu, bus, cpu->p, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D983u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D983u: {
            const uint32_t source_key = 0x0407D983u;
            cpu->pc = 0xFB32u;
            js_op_sep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x0407D993u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D993u: {
            const uint32_t source_key = 0x0407D993u;
            cpu->pc = 0xFB34u;
            uint32_t ea = js_addr_dp(cpu, 0xDBu);
            if (!js_bus_write8(bus, ea, (uint8_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D9A3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D9A3u: {
            const uint32_t source_key = 0x0407D9A3u;
            cpu->pc = 0xFB36u;
            js_op_rep(cpu, 0x20u);
            static const uint32_t allowed[] = { 0x0407D9B1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D9B1u: {
            const uint32_t source_key = 0x0407D9B1u;
            cpu->pc = 0xFB39u;
            uint32_t ea = js_addr_abs(cpu, 0x1AE6u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D9C9u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D9C9u: {
            const uint32_t source_key = 0x0407D9C9u;
            cpu->pc = 0xFB3Cu;
            uint32_t ea = js_addr_abs(cpu, 0x1AE4u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(0u), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0407D9E1u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D9E1u: {
            const uint32_t source_key = 0x0407D9E1u;
            cpu->pc = 0xFB3Du;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; cpu->p = (uint8_t)(v | (cpu->e ? (JS_P_M|JS_P_X) : 0u)); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x0407D9EBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D9EBu: {
            const uint32_t source_key = 0x0407D9EBu;
            cpu->pc = 0xFB3Eu;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x0407C6F3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407D9F3u: {
            const uint32_t source_key = 0x0407D9F3u;
            cpu->pc = 0xFB41u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xFB42u;
            static const uint32_t allowed[] = { 0x0407DA13u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407DA0Bu: {
            const uint32_t source_key = 0x0407DA0Bu;
            cpu->pc = 0xFB42u;
            { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x040FB0FBu, 0x040FBBABu, 0x040FBEFBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407DA13u: {
            const uint32_t source_key = 0x0407DA13u;
            cpu->pc = 0xFB44u;
            uint16_t value = 0x0002u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407DA23u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407DA23u: {
            const uint32_t source_key = 0x0407DA23u;
            cpu->pc = 0xFB47u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF92Au;
            static const uint32_t allowed[] = { 0x0407C953u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407DA3Bu: {
            const uint32_t source_key = 0x0407DA3Bu;
            cpu->pc = 0xFB48u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x0407DA0Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407DA93u: {
            const uint32_t source_key = 0x0407DA93u;
            cpu->pc = 0xFB55u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xFB56u;
            static const uint32_t allowed[] = { 0x0407DAB3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407DAABu: {
            const uint32_t source_key = 0x0407DAABu;
            cpu->pc = 0xFB56u;
            { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x040CFD33u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407DAB3u: {
            const uint32_t source_key = 0x0407DAB3u;
            cpu->pc = 0xFB58u;
            uint16_t value = 0x0001u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0407DAC3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407DAC3u: {
            const uint32_t source_key = 0x0407DAC3u;
            cpu->pc = 0xFB5Bu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xF92Au;
            static const uint32_t allowed[] = { 0x0407C953u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0407DADBu: {
            const uint32_t source_key = 0x0407DADBu;
            cpu->pc = 0xFB5Cu;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x0407DAABu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        default: return JS_EXEC_NOT_MINE;
    }
}
