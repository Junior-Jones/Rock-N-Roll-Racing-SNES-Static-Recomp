/* generated compact exact-context S-CPU shard - do not edit */
#include "js_v10_2_scpu_dispatch.h"
typedef struct js_v10_2_compact_record {
    uint32_t key;
    uint32_t parameter_offset;
    uint16_t template_id;
    uint16_t reserved;
} js_v10_2_compact_record;
static const js_v10_2_compact_record records[9] = {
    {0x00040007u,0x00000000u,0x0095u,0u},
    {0x00040B30u,0x00000005u,0x0095u,0u},
    {0x00040B31u,0x0000000Au,0x0095u,0u},
    {0x00040B32u,0x0000000Fu,0x0095u,0u},
    {0x00040B33u,0x00000014u,0x0095u,0u},
    {0x00040FE8u,0x00000019u,0x0095u,0u},
    {0x00040FE9u,0x0000001Eu,0x0095u,0u},
    {0x00040FEAu,0x00000023u,0x0095u,0u},
    {0x00040FEBu,0x00000028u,0x0095u,0u},
};
static const uint32_t parameters[45] = {
    0x00040007u,0x00008004u,0x00000080u,0x0000800Cu,0x04040067u,0x00040B30u,0x0000816Au,0x00000080u,
    0x0000816Au,0x04040B50u,0x00040B31u,0x0000816Au,0x00000080u,0x0000816Au,0x04040B51u,0x00040B32u,
    0x0000816Au,0x00000080u,0x0000816Au,0x04040B52u,0x00040B33u,0x0000816Au,0x00000080u,0x0000816Au,
    0x04040B53u,0x00040FE8u,0x00008201u,0x00000080u,0x00008201u,0x04041008u,0x00040FE9u,0x00008201u,
    0x00000080u,0x00008201u,0x04041009u,0x00040FEAu,0x00008201u,0x00000080u,0x00008201u,0x0404100Au,
    0x00040FEBu,0x00008201u,0x00000080u,0x00008201u,0x0404100Bu,
};
JSExecResult js_v10_2_compact_group_0020(JSCPU *cpu,
                                              const JSBus *bus,
                                              JSStop *stop,
                                              uint32_t packed) {
    size_t lo = 0u, hi = 9u;
    while (lo < hi) {
        size_t mid = lo + (hi - lo) / 2u;
        uint32_t found = records[mid].key;
        if (packed < found) hi = mid;
        else if (packed > found) lo = mid + 1u;
        else return js_v10_2_compact_execute(
            cpu, bus, stop, records[mid].template_id,
            parameters + records[mid].parameter_offset);
    }
    return JS_EXEC_NOT_MINE;
}
