#include "v05c_static_cpu.h"

JSExecResult js_v05c_shard_2028(JSCPU *cpu, const JSBus *bus, JSStop *stop) {
    (void)bus;
    (void)stop;
    switch (js_cpu_context_key(cpu)) {
        case 0x04050F93u: {
            const uint32_t source_key = 0x04050F93u;
            cpu->pc = 0xA1F3u;
            if (!js_stack_push8(cpu, bus, cpu->dbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04050F9Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04050F9Bu: {
            const uint32_t source_key = 0x04050F9Bu;
            cpu->pc = 0xA1F4u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04050FA3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04050FA3u: {
            const uint32_t source_key = 0x04050FA3u;
            cpu->pc = 0xA1F5u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04050FABu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04050FABu: {
            const uint32_t source_key = 0x04050FABu;
            cpu->pc = 0xA1F8u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xA1FAu;
            static const uint32_t allowed[] = { 0x04050FD3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04050FC3u: {
            const uint32_t source_key = 0x04050FC3u;
            cpu->pc = 0xA1F9u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04050FCBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04050FCBu: {
            const uint32_t source_key = 0x04050FCBu;
            cpu->pc = 0xA1FAu;
            { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x040CF08Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04050FD3u: {
            const uint32_t source_key = 0x04050FD3u;
            cpu->pc = 0xA1FCu;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x04050FE0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04050FE0u: {
            const uint32_t source_key = 0x04050FE0u;
            cpu->pc = 0xA1FFu;
            uint16_t value = 0x0080u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04050FF8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04050FF8u: {
            const uint32_t source_key = 0x04050FF8u;
            cpu->pc = 0xA202u;
            uint32_t ea = js_addr_abs(cpu, 0x2115u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051010u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051010u: {
            const uint32_t source_key = 0x04051010u;
            cpu->pc = 0xA205u;
            uint32_t ea = js_addr_abs(cpu, 0x035Bu);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04051028u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051028u: {
            const uint32_t source_key = 0x04051028u;
            cpu->pc = 0xA208u;
            uint32_t ea = js_addr_abs(cpu, 0x2116u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051040u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051040u: {
            const uint32_t source_key = 0x04051040u;
            cpu->pc = 0xA20Bu;
            uint16_t value = 0x1000u;
            js_op_load_y(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04051058u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051058u: {
            const uint32_t source_key = 0x04051058u;
            cpu->pc = 0xA20Eu;
            uint16_t value = 0x2000u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04051070u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051070u: {
            const uint32_t source_key = 0x04051070u;
            cpu->pc = 0xA211u;
            uint16_t value = 0x0000u;
            js_op_ora(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04051088u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051088u: {
            const uint32_t source_key = 0x04051088u;
            cpu->pc = 0xA214u;
            uint32_t ea = js_addr_abs(cpu, 0x2118u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040510A0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040510A0u: {
            const uint32_t source_key = 0x040510A0u;
            cpu->pc = 0xA215u;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, -1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040510A8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040510A8u: {
            const uint32_t source_key = 0x040510A8u;
            cpu->pc = 0xA217u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-6));
            static const uint32_t allowed[] = { 0x04051088u, 0x040510B8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040510B8u: {
            const uint32_t source_key = 0x040510B8u;
            cpu->pc = 0xA219u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040510CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040510CBu: {
            const uint32_t source_key = 0x040510CBu;
            cpu->pc = 0xA21Au;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x04050FC3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040510D0u: {
            const uint32_t source_key = 0x040510D0u;
            cpu->pc = 0xA21Bu;
            if (!js_stack_push8(cpu, bus, cpu->dbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040510D8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040510D8u: {
            const uint32_t source_key = 0x040510D8u;
            cpu->pc = 0xA21Cu;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040510E0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040510E0u: {
            const uint32_t source_key = 0x040510E0u;
            cpu->pc = 0xA21Du;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x040510E8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040510E8u: {
            const uint32_t source_key = 0x040510E8u;
            cpu->pc = 0xA21Eu;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->a, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040510F0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040510F0u: {
            const uint32_t source_key = 0x040510F0u;
            cpu->pc = 0xA21Fu;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->x, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040510F8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040510F8u: {
            const uint32_t source_key = 0x040510F8u;
            cpu->pc = 0xA222u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xA226u;
            static const uint32_t allowed[] = { 0x04051130u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051110u: {
            const uint32_t source_key = 0x04051110u;
            cpu->pc = 0xA223u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_x(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x04051118u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051118u: {
            const uint32_t source_key = 0x04051118u;
            cpu->pc = 0xA224u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x04051120u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051120u: {
            const uint32_t source_key = 0x04051120u;
            cpu->pc = 0xA225u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04051128u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051128u: {
            const uint32_t source_key = 0x04051128u;
            cpu->pc = 0xA226u;
            { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x040CF5F8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051130u: {
            const uint32_t source_key = 0x04051130u;
            cpu->pc = 0xA229u;
            uint16_t value = 0x0080u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04051148u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051148u: {
            const uint32_t source_key = 0x04051148u;
            cpu->pc = 0xA22Cu;
            uint32_t ea = js_addr_abs(cpu, 0x2115u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051160u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051160u: {
            const uint32_t source_key = 0x04051160u;
            cpu->pc = 0xA22Eu;
            uint32_t ea = js_addr_stack_rel(cpu, 0x03u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04051170u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051170u: {
            const uint32_t source_key = 0x04051170u;
            cpu->pc = 0xA22Fu;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04051178u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051178u: {
            const uint32_t source_key = 0x04051178u;
            cpu->pc = 0xA230u;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04051180u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051180u: {
            const uint32_t source_key = 0x04051180u;
            cpu->pc = 0xA231u;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04051188u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051188u: {
            const uint32_t source_key = 0x04051188u;
            cpu->pc = 0xA232u;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04051190u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051190u: {
            const uint32_t source_key = 0x04051190u;
            cpu->pc = 0xA233u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_C);
            static const uint32_t allowed[] = { 0x04051198u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051198u: {
            const uint32_t source_key = 0x04051198u;
            cpu->pc = 0xA236u;
            uint16_t value = 0x2000u;
            js_op_adc(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040511B0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040511B0u: {
            const uint32_t source_key = 0x040511B0u;
            cpu->pc = 0xA238u;
            uint32_t ea = js_addr_dp(cpu, 0x68u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040511C0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040511C0u: {
            const uint32_t source_key = 0x040511C0u;
            cpu->pc = 0xA23Au;
            uint32_t ea = js_addr_stack_rel(cpu, 0x05u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040511D0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040511D0u: {
            const uint32_t source_key = 0x040511D0u;
            cpu->pc = 0xA23Cu;
            uint32_t ea = js_addr_dp(cpu, 0x6Au);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040511E0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040511E0u: {
            const uint32_t source_key = 0x040511E0u;
            cpu->pc = 0xA23Eu;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040511F3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040511F3u: {
            const uint32_t source_key = 0x040511F3u;
            cpu->pc = 0xA240u;
            uint16_t value = 0x0000u;
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04051203u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051203u: {
            const uint32_t source_key = 0x04051203u;
            cpu->pc = 0xA242u;
            uint32_t ea = js_addr_dp(cpu, 0x68u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04051213u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051213u: {
            const uint32_t source_key = 0x04051213u;
            cpu->pc = 0xA245u;
            uint32_t ea = js_addr_abs(cpu, 0x2116u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0405122Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0405122Bu: {
            const uint32_t source_key = 0x0405122Bu;
            cpu->pc = 0xA247u;
            uint32_t ea = js_addr_dp(cpu, 0x69u);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0405123Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0405123Bu: {
            const uint32_t source_key = 0x0405123Bu;
            cpu->pc = 0xA24Au;
            uint32_t ea = js_addr_abs(cpu, 0x2117u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051253u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051253u: {
            const uint32_t source_key = 0x04051253u;
            cpu->pc = 0xA24Cu;
            uint16_t value = 0x0001u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04051263u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051263u: {
            const uint32_t source_key = 0x04051263u;
            cpu->pc = 0xA24Fu;
            uint32_t ea = js_addr_abs(cpu, 0x4300u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0405127Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0405127Bu: {
            const uint32_t source_key = 0x0405127Bu;
            cpu->pc = 0xA251u;
            uint16_t value = 0x0018u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0405128Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0405128Bu: {
            const uint32_t source_key = 0x0405128Bu;
            cpu->pc = 0xA254u;
            uint32_t ea = js_addr_abs(cpu, 0x4301u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040512A3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040512A3u: {
            const uint32_t source_key = 0x040512A3u;
            cpu->pc = 0xA256u;
            uint32_t ea = js_addr_dp(cpu, 0x6Au);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040512B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040512B3u: {
            const uint32_t source_key = 0x040512B3u;
            cpu->pc = 0xA259u;
            uint32_t ea = js_addr_abs(cpu, 0x4302u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040512CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040512CBu: {
            const uint32_t source_key = 0x040512CBu;
            cpu->pc = 0xA25Bu;
            uint32_t ea = js_addr_dp(cpu, 0x6Bu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040512DBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040512DBu: {
            const uint32_t source_key = 0x040512DBu;
            cpu->pc = 0xA25Eu;
            uint32_t ea = js_addr_abs(cpu, 0x4303u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040512F3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040512F3u: {
            const uint32_t source_key = 0x040512F3u;
            cpu->pc = 0xA260u;
            uint16_t value = 0x007Eu;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04051303u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051303u: {
            const uint32_t source_key = 0x04051303u;
            cpu->pc = 0xA263u;
            uint32_t ea = js_addr_abs(cpu, 0x4304u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0405131Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0405131Bu: {
            const uint32_t source_key = 0x0405131Bu;
            cpu->pc = 0xA265u;
            uint16_t value = 0x0000u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0405132Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0405132Bu: {
            const uint32_t source_key = 0x0405132Bu;
            cpu->pc = 0xA268u;
            uint32_t ea = js_addr_abs(cpu, 0x4305u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051343u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051343u: {
            const uint32_t source_key = 0x04051343u;
            cpu->pc = 0xA26Au;
            uint16_t value = 0x0001u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04051353u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051353u: {
            const uint32_t source_key = 0x04051353u;
            cpu->pc = 0xA26Du;
            uint32_t ea = js_addr_abs(cpu, 0x4306u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0405136Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0405136Bu: {
            const uint32_t source_key = 0x0405136Bu;
            cpu->pc = 0xA26Fu;
            uint16_t value = 0x0001u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0405137Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0405137Bu: {
            const uint32_t source_key = 0x0405137Bu;
            cpu->pc = 0xA272u;
            uint32_t ea = js_addr_abs(cpu, 0x420Bu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051393u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051393u: {
            const uint32_t source_key = 0x04051393u;
            cpu->pc = 0xA274u;
            uint32_t ea = js_addr_dp(cpu, 0x69u);
            uint16_t original = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
            uint16_t result = js_op_incdec(cpu, original, 1, 8u);
            if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040513A3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040513A3u: {
            const uint32_t source_key = 0x040513A3u;
            cpu->pc = 0xA276u;
            uint32_t ea = js_addr_dp(cpu, 0x6Bu);
            uint16_t original = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; original = v8; }
            uint16_t result = js_op_incdec(cpu, original, 1, 8u);
            if (!js_bus_rmw_write(bus, ea, 0, 8u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040513B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040513B3u: {
            const uint32_t source_key = 0x040513B3u;
            cpu->pc = 0xA277u;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, 1, 8u), 8u);
            static const uint32_t allowed[] = { 0x040513BBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040513BBu: {
            const uint32_t source_key = 0x040513BBu;
            cpu->pc = 0xA279u;
            uint16_t value = 0x0008u;
            js_op_compare(cpu, cpu->x, value, 8u);
            static const uint32_t allowed[] = { 0x040513CBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040513CBu: {
            const uint32_t source_key = 0x040513CBu;
            cpu->pc = 0xA27Bu;
            if (js_branch_condition(cpu, 'C')) cpu->pc = (uint16_t)(cpu->pc + (-59));
            static const uint32_t allowed[] = { 0x04051203u, 0x040513DBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040513DBu: {
            const uint32_t source_key = 0x040513DBu;
            cpu->pc = 0xA27Du;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040513E8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040513E8u: {
            const uint32_t source_key = 0x040513E8u;
            cpu->pc = 0xA27Eu;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x04051110u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040516D8u: {
            const uint32_t source_key = 0x040516D8u;
            cpu->pc = 0xA2DCu;
            if (!js_stack_push8(cpu, bus, cpu->dbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040516E0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040516E0u: {
            const uint32_t source_key = 0x040516E0u;
            cpu->pc = 0xA2DDu;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040516E8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040516E8u: {
            const uint32_t source_key = 0x040516E8u;
            cpu->pc = 0xA2DEu;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x040516F0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040516F0u: {
            const uint32_t source_key = 0x040516F0u;
            cpu->pc = 0xA2DFu;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->a, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040516F8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040516F8u: {
            const uint32_t source_key = 0x040516F8u;
            cpu->pc = 0xA2E0u;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->x, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051700u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051700u: {
            const uint32_t source_key = 0x04051700u;
            cpu->pc = 0xA2E3u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xA2E7u;
            static const uint32_t allowed[] = { 0x04051738u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051718u: {
            const uint32_t source_key = 0x04051718u;
            cpu->pc = 0xA2E4u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_x(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x04051720u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051720u: {
            const uint32_t source_key = 0x04051720u;
            cpu->pc = 0xA2E5u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x04051728u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051728u: {
            const uint32_t source_key = 0x04051728u;
            cpu->pc = 0xA2E6u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04051730u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051730u: {
            const uint32_t source_key = 0x04051730u;
            cpu->pc = 0xA2E7u;
            { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x040CF698u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051738u: {
            const uint32_t source_key = 0x04051738u;
            cpu->pc = 0xA2E9u;
            uint32_t ea = js_addr_stack_rel(cpu, 0x03u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04051748u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051748u: {
            const uint32_t source_key = 0x04051748u;
            cpu->pc = 0xA2EAu;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04051750u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051750u: {
            const uint32_t source_key = 0x04051750u;
            cpu->pc = 0xA2EBu;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04051758u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051758u: {
            const uint32_t source_key = 0x04051758u;
            cpu->pc = 0xA2ECu;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04051760u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051760u: {
            const uint32_t source_key = 0x04051760u;
            cpu->pc = 0xA2EDu;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04051768u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051768u: {
            const uint32_t source_key = 0x04051768u;
            cpu->pc = 0xA2F0u;
            uint16_t value = 0x2000u;
            js_op_adc(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04051780u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051780u: {
            const uint32_t source_key = 0x04051780u;
            cpu->pc = 0xA2F2u;
            uint32_t ea = js_addr_dp(cpu, 0x68u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051790u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051790u: {
            const uint32_t source_key = 0x04051790u;
            cpu->pc = 0xA2F4u;
            uint32_t ea = js_addr_stack_rel(cpu, 0x05u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040517A0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040517A0u: {
            const uint32_t source_key = 0x040517A0u;
            cpu->pc = 0xA2F6u;
            uint32_t ea = js_addr_dp(cpu, 0x6Au);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040517B0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040517B0u: {
            const uint32_t source_key = 0x040517B0u;
            cpu->pc = 0xA2F8u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x040517C3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040517C3u: {
            const uint32_t source_key = 0x040517C3u;
            cpu->pc = 0xA2FAu;
            uint16_t value = 0x0080u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040517D3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040517D3u: {
            const uint32_t source_key = 0x040517D3u;
            cpu->pc = 0xA2FDu;
            uint32_t ea = js_addr_abs(cpu, 0x2115u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040517EBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040517EBu: {
            const uint32_t source_key = 0x040517EBu;
            cpu->pc = 0xA2FFu;
            uint16_t value = 0x0001u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x040517FBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040517FBu: {
            const uint32_t source_key = 0x040517FBu;
            cpu->pc = 0xA302u;
            uint32_t ea = js_addr_abs(cpu, 0x4300u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051813u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051813u: {
            const uint32_t source_key = 0x04051813u;
            cpu->pc = 0xA304u;
            uint16_t value = 0x0018u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04051823u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051823u: {
            const uint32_t source_key = 0x04051823u;
            cpu->pc = 0xA307u;
            uint32_t ea = js_addr_abs(cpu, 0x4301u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x0405183Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0405183Bu: {
            const uint32_t source_key = 0x0405183Bu;
            cpu->pc = 0xA309u;
            uint16_t value = 0x007Eu;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0405184Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0405184Bu: {
            const uint32_t source_key = 0x0405184Bu;
            cpu->pc = 0xA30Cu;
            uint32_t ea = js_addr_abs(cpu, 0x4304u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051863u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051863u: {
            const uint32_t source_key = 0x04051863u;
            cpu->pc = 0xA30Eu;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x04051870u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051870u: {
            const uint32_t source_key = 0x04051870u;
            cpu->pc = 0xA311u;
            uint16_t value = 0x0004u;
            js_op_load_x(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04051888u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051888u: {
            const uint32_t source_key = 0x04051888u;
            cpu->pc = 0xA313u;
            uint32_t ea = js_addr_dp(cpu, 0x68u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04051898u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051898u: {
            const uint32_t source_key = 0x04051898u;
            cpu->pc = 0xA316u;
            uint32_t ea = js_addr_abs(cpu, 0x2116u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040518B0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040518B0u: {
            const uint32_t source_key = 0x040518B0u;
            cpu->pc = 0xA318u;
            uint32_t ea = js_addr_dp(cpu, 0x6Au);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040518C0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040518C0u: {
            const uint32_t source_key = 0x040518C0u;
            cpu->pc = 0xA31Bu;
            uint32_t ea = js_addr_abs(cpu, 0x4302u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040518D8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040518D8u: {
            const uint32_t source_key = 0x040518D8u;
            cpu->pc = 0xA31Eu;
            uint16_t value = 0x0080u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x040518F0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040518F0u: {
            const uint32_t source_key = 0x040518F0u;
            cpu->pc = 0xA321u;
            uint32_t ea = js_addr_abs(cpu, 0x4305u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051908u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051908u: {
            const uint32_t source_key = 0x04051908u;
            cpu->pc = 0xA323u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x0405191Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0405191Bu: {
            const uint32_t source_key = 0x0405191Bu;
            cpu->pc = 0xA325u;
            uint16_t value = 0x0001u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x0405192Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x0405192Bu: {
            const uint32_t source_key = 0x0405192Bu;
            cpu->pc = 0xA328u;
            uint32_t ea = js_addr_abs(cpu, 0x420Bu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051943u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051943u: {
            const uint32_t source_key = 0x04051943u;
            cpu->pc = 0xA32Au;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x04051950u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051950u: {
            const uint32_t source_key = 0x04051950u;
            cpu->pc = 0xA32Cu;
            uint32_t ea = js_addr_dp(cpu, 0x6Au);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04051960u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051960u: {
            const uint32_t source_key = 0x04051960u;
            cpu->pc = 0xA32Du;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_C);
            static const uint32_t allowed[] = { 0x04051968u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051968u: {
            const uint32_t source_key = 0x04051968u;
            cpu->pc = 0xA330u;
            uint16_t value = 0x0080u;
            js_op_adc(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04051980u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051980u: {
            const uint32_t source_key = 0x04051980u;
            cpu->pc = 0xA332u;
            uint32_t ea = js_addr_dp(cpu, 0x6Au);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051990u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051990u: {
            const uint32_t source_key = 0x04051990u;
            cpu->pc = 0xA334u;
            uint32_t ea = js_addr_dp(cpu, 0x69u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040519A0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040519A0u: {
            const uint32_t source_key = 0x040519A0u;
            cpu->pc = 0xA335u;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, -1, 16u), 16u);
            static const uint32_t allowed[] = { 0x040519A8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040519A8u: {
            const uint32_t source_key = 0x040519A8u;
            cpu->pc = 0xA337u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-38));
            static const uint32_t allowed[] = { 0x04051888u, 0x040519B8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040519B8u: {
            const uint32_t source_key = 0x040519B8u;
            cpu->pc = 0xA338u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x04051718u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040519C0u: {
            const uint32_t source_key = 0x040519C0u;
            cpu->pc = 0xA339u;
            if (!js_stack_push8(cpu, bus, cpu->dbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040519C8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040519C8u: {
            const uint32_t source_key = 0x040519C8u;
            cpu->pc = 0xA33Au;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040519D0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040519D0u: {
            const uint32_t source_key = 0x040519D0u;
            cpu->pc = 0xA33Bu;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x040519D8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040519D8u: {
            const uint32_t source_key = 0x040519D8u;
            cpu->pc = 0xA33Cu;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->a, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040519E0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040519E0u: {
            const uint32_t source_key = 0x040519E0u;
            cpu->pc = 0xA33Du;
            if (!js_stack_push16(cpu, bus, (uint16_t)cpu->x, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x040519E8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x040519E8u: {
            const uint32_t source_key = 0x040519E8u;
            cpu->pc = 0xA340u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xA344u;
            static const uint32_t allowed[] = { 0x04051A20u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051A00u: {
            const uint32_t source_key = 0x04051A00u;
            cpu->pc = 0xA341u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_x(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x04051A08u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051A08u: {
            const uint32_t source_key = 0x04051A08u;
            cpu->pc = 0xA342u;
            { uint16_t v = 0u; if (!js_stack_pop16(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 16u); }
            static const uint32_t allowed[] = { 0x04051A10u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051A10u: {
            const uint32_t source_key = 0x04051A10u;
            cpu->pc = 0xA343u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04051A18u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051A18u: {
            const uint32_t source_key = 0x04051A18u;
            cpu->pc = 0xA344u;
            { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x040CF648u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051A20u: {
            const uint32_t source_key = 0x04051A20u;
            cpu->pc = 0xA346u;
            uint32_t ea = js_addr_stack_rel(cpu, 0x03u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04051A30u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051A30u: {
            const uint32_t source_key = 0x04051A30u;
            cpu->pc = 0xA347u;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04051A38u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051A38u: {
            const uint32_t source_key = 0x04051A38u;
            cpu->pc = 0xA348u;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04051A40u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051A40u: {
            const uint32_t source_key = 0x04051A40u;
            cpu->pc = 0xA349u;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04051A48u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051A48u: {
            const uint32_t source_key = 0x04051A48u;
            cpu->pc = 0xA34Au;
            js_op_load_a(cpu, js_op_asl(cpu, cpu->a, 16u), 16u);
            static const uint32_t allowed[] = { 0x04051A50u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051A50u: {
            const uint32_t source_key = 0x04051A50u;
            cpu->pc = 0xA34Du;
            uint16_t value = 0x2000u;
            js_op_adc(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04051A68u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051A68u: {
            const uint32_t source_key = 0x04051A68u;
            cpu->pc = 0xA34Fu;
            uint32_t ea = js_addr_dp(cpu, 0x68u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051A78u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051A78u: {
            const uint32_t source_key = 0x04051A78u;
            cpu->pc = 0xA351u;
            uint32_t ea = js_addr_stack_rel(cpu, 0x05u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04051A88u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051A88u: {
            const uint32_t source_key = 0x04051A88u;
            cpu->pc = 0xA353u;
            uint32_t ea = js_addr_dp(cpu, 0x6Au);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051A98u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051A98u: {
            const uint32_t source_key = 0x04051A98u;
            cpu->pc = 0xA355u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x04051AABu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051AABu: {
            const uint32_t source_key = 0x04051AABu;
            cpu->pc = 0xA357u;
            uint16_t value = 0x0080u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04051ABBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051ABBu: {
            const uint32_t source_key = 0x04051ABBu;
            cpu->pc = 0xA35Au;
            uint32_t ea = js_addr_abs(cpu, 0x2115u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051AD3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051AD3u: {
            const uint32_t source_key = 0x04051AD3u;
            cpu->pc = 0xA35Cu;
            uint16_t value = 0x0001u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04051AE3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051AE3u: {
            const uint32_t source_key = 0x04051AE3u;
            cpu->pc = 0xA35Fu;
            uint32_t ea = js_addr_abs(cpu, 0x4300u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051AFBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051AFBu: {
            const uint32_t source_key = 0x04051AFBu;
            cpu->pc = 0xA361u;
            uint16_t value = 0x0018u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04051B0Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051B0Bu: {
            const uint32_t source_key = 0x04051B0Bu;
            cpu->pc = 0xA364u;
            uint32_t ea = js_addr_abs(cpu, 0x4301u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051B23u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051B23u: {
            const uint32_t source_key = 0x04051B23u;
            cpu->pc = 0xA366u;
            uint16_t value = 0x007Eu;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04051B33u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051B33u: {
            const uint32_t source_key = 0x04051B33u;
            cpu->pc = 0xA369u;
            uint32_t ea = js_addr_abs(cpu, 0x4304u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051B4Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051B4Bu: {
            const uint32_t source_key = 0x04051B4Bu;
            cpu->pc = 0xA36Bu;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x04051B58u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051B58u: {
            const uint32_t source_key = 0x04051B58u;
            cpu->pc = 0xA36Eu;
            uint16_t value = 0x0002u;
            js_op_load_x(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04051B70u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051B70u: {
            const uint32_t source_key = 0x04051B70u;
            cpu->pc = 0xA370u;
            uint32_t ea = js_addr_dp(cpu, 0x68u);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04051B80u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051B80u: {
            const uint32_t source_key = 0x04051B80u;
            cpu->pc = 0xA373u;
            uint32_t ea = js_addr_abs(cpu, 0x2116u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051B98u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051B98u: {
            const uint32_t source_key = 0x04051B98u;
            cpu->pc = 0xA375u;
            uint32_t ea = js_addr_dp(cpu, 0x6Au);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04051BA8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051BA8u: {
            const uint32_t source_key = 0x04051BA8u;
            cpu->pc = 0xA378u;
            uint32_t ea = js_addr_abs(cpu, 0x4302u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051BC0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051BC0u: {
            const uint32_t source_key = 0x04051BC0u;
            cpu->pc = 0xA37Bu;
            uint16_t value = 0x0040u;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04051BD8u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051BD8u: {
            const uint32_t source_key = 0x04051BD8u;
            cpu->pc = 0xA37Eu;
            uint32_t ea = js_addr_abs(cpu, 0x4305u);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051BF0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051BF0u: {
            const uint32_t source_key = 0x04051BF0u;
            cpu->pc = 0xA380u;
            js_op_sep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x04051C03u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051C03u: {
            const uint32_t source_key = 0x04051C03u;
            cpu->pc = 0xA382u;
            uint16_t value = 0x0001u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04051C13u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051C13u: {
            const uint32_t source_key = 0x04051C13u;
            cpu->pc = 0xA385u;
            uint32_t ea = js_addr_abs(cpu, 0x420Bu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051C2Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051C2Bu: {
            const uint32_t source_key = 0x04051C2Bu;
            cpu->pc = 0xA387u;
            js_op_rep(cpu, 0x30u);
            static const uint32_t allowed[] = { 0x04051C38u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051C38u: {
            const uint32_t source_key = 0x04051C38u;
            cpu->pc = 0xA389u;
            uint32_t ea = js_addr_dp(cpu, 0x6Au);
            uint16_t value = 0u;
            if (!js_bus_read16(bus, ea, 0, &value, stop, source_key)) return JS_EXEC_STOP;
            js_op_load_a(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04051C48u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051C48u: {
            const uint32_t source_key = 0x04051C48u;
            cpu->pc = 0xA38Au;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~ JS_P_C);
            static const uint32_t allowed[] = { 0x04051C50u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051C50u: {
            const uint32_t source_key = 0x04051C50u;
            cpu->pc = 0xA38Du;
            uint16_t value = 0x0040u;
            js_op_adc(cpu, value, 16u);
            static const uint32_t allowed[] = { 0x04051C68u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051C68u: {
            const uint32_t source_key = 0x04051C68u;
            cpu->pc = 0xA38Fu;
            uint32_t ea = js_addr_dp(cpu, 0x6Au);
            if (!js_bus_write16(bus, ea, 0, (uint16_t)(js_op_store_a(cpu, 16u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051C78u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051C78u: {
            const uint32_t source_key = 0x04051C78u;
            cpu->pc = 0xA391u;
            uint32_t ea = js_addr_dp(cpu, 0x69u);
            uint16_t original = 0u;
            if (!js_bus_read16(bus, ea, 0, &original, stop, source_key)) return JS_EXEC_STOP;
            uint16_t result = js_op_incdec(cpu, original, 1, 16u);
            if (!js_bus_rmw_write(bus, ea, 0, 16u, 0u, original, result, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051C88u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051C88u: {
            const uint32_t source_key = 0x04051C88u;
            cpu->pc = 0xA392u;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, -1, 16u), 16u);
            static const uint32_t allowed[] = { 0x04051C90u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051C90u: {
            const uint32_t source_key = 0x04051C90u;
            cpu->pc = 0xA394u;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-38));
            static const uint32_t allowed[] = { 0x04051B70u, 0x04051CA0u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051CA0u: {
            const uint32_t source_key = 0x04051CA0u;
            cpu->pc = 0xA395u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x04051A00u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051D03u: {
            const uint32_t source_key = 0x04051D03u;
            cpu->pc = 0xA3A1u;
            if (!js_stack_push8(cpu, bus, cpu->dbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051D0Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051D0Bu: {
            const uint32_t source_key = 0x04051D0Bu;
            cpu->pc = 0xA3A2u;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051D13u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051D13u: {
            const uint32_t source_key = 0x04051D13u;
            cpu->pc = 0xA3A3u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04051D1Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051D1Bu: {
            const uint32_t source_key = 0x04051D1Bu;
            cpu->pc = 0xA3A6u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xA3A8u;
            static const uint32_t allowed[] = { 0x04051D43u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051D33u: {
            const uint32_t source_key = 0x04051D33u;
            cpu->pc = 0xA3A7u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04051D3Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051D3Bu: {
            const uint32_t source_key = 0x04051D3Bu;
            cpu->pc = 0xA3A8u;
            { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x040FA613u, 0x040FA7B3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051D43u: {
            const uint32_t source_key = 0x04051D43u;
            cpu->pc = 0xA3AAu;
            uint16_t value = 0x0000u;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04051D53u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051D53u: {
            const uint32_t source_key = 0x04051D53u;
            cpu->pc = 0xA3ABu;
            if (!js_stack_push8(cpu, bus, (uint8_t)cpu->a, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051D5Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051D5Bu: {
            const uint32_t source_key = 0x04051D5Bu;
            cpu->pc = 0xA3AEu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xA444u;
            static const uint32_t allowed[] = { 0x04052223u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051D73u: {
            const uint32_t source_key = 0x04051D73u;
            cpu->pc = 0xA3AFu;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 1, stop, source_key)) return JS_EXEC_STOP; js_op_load_a(cpu, v, 8u); }
            static const uint32_t allowed[] = { 0x04051D7Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051D7Bu: {
            const uint32_t source_key = 0x04051D7Bu;
            cpu->pc = 0xA3B2u;
            uint32_t ea = js_addr_abs(cpu, 0x035Fu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051D93u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051D93u: {
            const uint32_t source_key = 0x04051D93u;
            cpu->pc = 0xA3B5u;
            uint32_t ea = js_addr_abs(cpu, 0x2100u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051DABu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051DABu: {
            const uint32_t source_key = 0x04051DABu;
            cpu->pc = 0xA3B7u;
            uint16_t value = 0x0020u;
            js_op_load_y(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04051DBBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051DBBu: {
            const uint32_t source_key = 0x04051DBBu;
            cpu->pc = 0xA3B9u;
            uint16_t value = 0x0000u;
            js_op_load_x(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04051DCBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051DCBu: {
            const uint32_t source_key = 0x04051DCBu;
            cpu->pc = 0xA3BAu;
            js_op_load_x(cpu, js_op_incdec(cpu, cpu->x, -1, 8u), 8u);
            static const uint32_t allowed[] = { 0x04051DD3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051DD3u: {
            const uint32_t source_key = 0x04051DD3u;
            cpu->pc = 0xA3BCu;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-3));
            static const uint32_t allowed[] = { 0x04051DCBu, 0x04051DE3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051DE3u: {
            const uint32_t source_key = 0x04051DE3u;
            cpu->pc = 0xA3BDu;
            js_op_load_y(cpu, js_op_incdec(cpu, cpu->y, -1, 8u), 8u);
            static const uint32_t allowed[] = { 0x04051DEBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051DEBu: {
            const uint32_t source_key = 0x04051DEBu;
            cpu->pc = 0xA3BFu;
            if (js_branch_condition(cpu, 'N')) cpu->pc = (uint16_t)(cpu->pc + (-6));
            static const uint32_t allowed[] = { 0x04051DCBu, 0x04051DFBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051DFBu: {
            const uint32_t source_key = 0x04051DFBu;
            cpu->pc = 0xA3C2u;
            uint32_t ea = js_addr_abs(cpu, 0x035Fu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04051E13u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051E13u: {
            const uint32_t source_key = 0x04051E13u;
            cpu->pc = 0xA3C3u;
            js_op_load_a(cpu, js_op_incdec(cpu, cpu->a, 1, 8u), 8u);
            static const uint32_t allowed[] = { 0x04051E1Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051E1Bu: {
            const uint32_t source_key = 0x04051E1Bu;
            cpu->pc = 0xA3C5u;
            uint16_t value = 0x0010u;
            js_op_compare(cpu, cpu->a, value, 8u);
            static const uint32_t allowed[] = { 0x04051E2Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051E2Bu: {
            const uint32_t source_key = 0x04051E2Bu;
            cpu->pc = 0xA3C7u;
            if (js_branch_condition(cpu, 'C')) cpu->pc = (uint16_t)(cpu->pc + (-29));
            static const uint32_t allowed[] = { 0x04051D53u, 0x04051E3Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051E3Bu: {
            const uint32_t source_key = 0x04051E3Bu;
            cpu->pc = 0xA3C8u;
            { uint16_t ret = 0u; if (!js_stack_pop16(cpu, bus, &ret, 1, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); }
            static const uint32_t allowed[] = { 0x04051D33u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051F53u: {
            const uint32_t source_key = 0x04051F53u;
            cpu->pc = 0xA3EBu;
            if (!js_stack_push8(cpu, bus, cpu->dbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051F5Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051F5Bu: {
            const uint32_t source_key = 0x04051F5Bu;
            cpu->pc = 0xA3ECu;
            if (!js_stack_push8(cpu, bus, cpu->pbr, 1, stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051F63u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051F63u: {
            const uint32_t source_key = 0x04051F63u;
            cpu->pc = 0xA3EDu;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04051F6Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051F6Bu: {
            const uint32_t source_key = 0x04051F6Bu;
            cpu->pc = 0xA3F0u;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xA3F2u;
            static const uint32_t allowed[] = { 0x04051F93u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051F83u: {
            const uint32_t source_key = 0x04051F83u;
            cpu->pc = 0xA3F1u;
            { uint8_t v = 0u; if (!js_stack_pop8(cpu, bus, &v, 0, stop, source_key)) return JS_EXEC_STOP; cpu->dbr = v; js_op_set_nz(cpu, v, 8u); js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x04051F8Bu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051F8Bu: {
            const uint32_t source_key = 0x04051F8Bu;
            cpu->pc = 0xA3F2u;
            { uint16_t ret = 0u; uint8_t bank = 0u; if (!js_stack_pop16(cpu, bus, &ret, 0, stop, source_key)) return JS_EXEC_STOP; if (!js_stack_pop8(cpu, bus, &bank, 0, stop, source_key)) return JS_EXEC_STOP; cpu->pc = (uint16_t)(ret + 1u); cpu->pbr = bank; js_cpu_normalize(cpu); }
            static const uint32_t allowed[] = { 0x040FA8DBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051F93u: {
            const uint32_t source_key = 0x04051F93u;
            cpu->pc = 0xA3F4u;
            uint16_t value = 0x000Fu;
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04051FA3u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051FA3u: {
            const uint32_t source_key = 0x04051FA3u;
            cpu->pc = 0xA3F7u;
            uint32_t ea = js_addr_abs(cpu, 0x035Fu);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04051FBBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051FBBu: {
            const uint32_t source_key = 0x04051FBBu;
            cpu->pc = 0xA3FAu;
            if (!js_stack_push16(cpu, bus, (uint16_t)(cpu->pc - 1u), 1, stop, source_key)) return JS_EXEC_STOP;
            cpu->pc = 0xA444u;
            static const uint32_t allowed[] = { 0x04052223u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051FD3u: {
            const uint32_t source_key = 0x04051FD3u;
            cpu->pc = 0xA3FDu;
            uint32_t ea = js_addr_abs(cpu, 0x035Fu);
            uint16_t value = 0u;
            { uint8_t v8 = 0u; if (!js_bus_read8(bus, ea, &v8, stop, source_key)) return JS_EXEC_STOP; value = v8; }
            js_op_load_a(cpu, value, 8u);
            static const uint32_t allowed[] = { 0x04051FEBu };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        case 0x04051FEBu: {
            const uint32_t source_key = 0x04051FEBu;
            cpu->pc = 0xA400u;
            uint32_t ea = js_addr_abs(cpu, 0x2100u);
            if (!js_bus_write8(bus, ea, (uint8_t)(js_op_store_a(cpu, 8u)), stop, source_key)) return JS_EXEC_STOP;
            static const uint32_t allowed[] = { 0x04052003u };
            return js_v05c_guard_successor(cpu, stop, source_key, allowed, sizeof allowed / sizeof allowed[0], JS_STOP_UNPROVED_SUCCESSOR);
        }
        default: return JS_EXEC_NOT_MINE;
    }
}
