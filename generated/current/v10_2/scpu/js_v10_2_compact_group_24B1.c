/* generated compact exact-context S-CPU shard - do not edit */
#include "js_v10_2_scpu_dispatch.h"
typedef struct js_v10_2_compact_record {
    uint32_t key;
    uint32_t parameter_offset;
    uint16_t template_id;
    uint16_t reserved;
} js_v10_2_compact_record;
static const js_v10_2_compact_record records[14] = {
    {0x04963108u,0x00000000u,0x000Cu,0u},
    {0x04963120u,0x00000005u,0x0001u,0u},
    {0x04963138u,0x00000009u,0x000Cu,0u},
    {0x04963150u,0x0000000Eu,0x0001u,0u},
    {0x04963168u,0x00000012u,0x0001u,0u},
    {0x04963180u,0x00000016u,0x0000u,0u},
    {0x04963198u,0x0000001Bu,0x0012u,0u},
    {0x049631A8u,0x0000001Fu,0x0000u,0u},
    {0x049631C0u,0x00000024u,0x0012u,0u},
    {0x049631D0u,0x00000028u,0x000Cu,0u},
    {0x049631E8u,0x0000002Du,0x0001u,0u},
    {0x04963200u,0x00000031u,0x000Cu,0u},
    {0x04963218u,0x00000036u,0x0001u,0u},
    {0x04963230u,0x0000003Au,0x000Eu,0u},
};
static const uint32_t parameters[61] = {
    0x04963108u,0x0000C624u,0x0000C5BDu,0x00000010u,0x04963120u,0x04963120u,0x0000C627u,0x0000A596u,
    0x04952CB0u,0x04963138u,0x0000C62Au,0x0000C5D7u,0x00000010u,0x04963150u,0x04963150u,0x0000C62Du,
    0x0000A547u,0x04952A38u,0x04963168u,0x0000C630u,0x0000A278u,0x049513C0u,0x04963180u,0x0000C633u,
    0x00000000u,0x00000010u,0x04963198u,0x04963198u,0x0000C635u,0x00000023u,0x049631A8u,0x049631A8u,
    0x0000C638u,0x00000000u,0x00000010u,0x049631C0u,0x049631C0u,0x0000C63Au,0x00000025u,0x049631D0u,
    0x049631D0u,0x0000C63Du,0x0000C5E5u,0x00000010u,0x049631E8u,0x049631E8u,0x0000C640u,0x0000A296u,
    0x049514B0u,0x04963200u,0x0000C643u,0x0000C607u,0x00000010u,0x04963218u,0x04963218u,0x0000C646u,
    0x0000A596u,0x04952CB0u,0x04963230u,0x0000C647u,0x04945E08u,
};
JSExecResult js_v10_2_compact_group_24B1(JSCPU *cpu,
                                              const JSBus *bus,
                                              JSStop *stop,
                                              uint32_t packed) {
    size_t lo = 0u, hi = 14u;
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
