/* generated compact exact-context S-CPU shard - do not edit */
#include "js_v10_2_scpu_dispatch.h"
typedef struct js_v10_2_compact_record {
    uint32_t key;
    uint32_t parameter_offset;
    uint16_t template_id;
    uint16_t reserved;
} js_v10_2_compact_record;
static const js_v10_2_compact_record records[14] = {
    {0x0495D9A8u,0x00000000u,0x000Cu,0u},
    {0x0495D9C0u,0x00000005u,0x0001u,0u},
    {0x0495D9D8u,0x00000009u,0x0001u,0u},
    {0x0495D9F0u,0x0000000Du,0x000Cu,0u},
    {0x0495DA08u,0x00000012u,0x0001u,0u},
    {0x0495DA20u,0x00000016u,0x0000u,0u},
    {0x0495DA38u,0x0000001Bu,0x0012u,0u},
    {0x0495DA48u,0x0000001Fu,0x0000u,0u},
    {0x0495DA60u,0x00000024u,0x0012u,0u},
    {0x0495DA70u,0x00000028u,0x000Cu,0u},
    {0x0495DA88u,0x0000002Du,0x0001u,0u},
    {0x0495DAA0u,0x00000031u,0x000Cu,0u},
    {0x0495DAB8u,0x00000036u,0x0001u,0u},
    {0x0495DAD0u,0x0000003Au,0x000Eu,0u},
};
static const uint32_t parameters[61] = {
    0x0495D9A8u,0x0000BB38u,0x0000BAD5u,0x00000010u,0x0495D9C0u,0x0495D9C0u,0x0000BB3Bu,0x0000A596u,
    0x04952CB0u,0x0495D9D8u,0x0000BB3Eu,0x0000A278u,0x049513C0u,0x0495D9F0u,0x0000BB41u,0x0000BB5Bu,
    0x00000010u,0x0495DA08u,0x0495DA08u,0x0000BB44u,0x0000BC2Fu,0x0495E178u,0x0495DA20u,0x0000BB47u,
    0x00000000u,0x00000010u,0x0495DA38u,0x0495DA38u,0x0000BB49u,0x00000023u,0x0495DA48u,0x0495DA48u,
    0x0000BB4Cu,0x00000000u,0x00000010u,0x0495DA60u,0x0495DA60u,0x0000BB4Eu,0x00000025u,0x0495DA70u,
    0x0495DA70u,0x0000BB51u,0x0000BB07u,0x00000010u,0x0495DA88u,0x0495DA88u,0x0000BB54u,0x0000A296u,
    0x049514B0u,0x0495DAA0u,0x0000BB57u,0x0000BCA7u,0x00000010u,0x0495DAB8u,0x0495DAB8u,0x0000BB5Au,
    0x0000A547u,0x04952A38u,0x0495DAD0u,0x0000BB5Bu,0x04945E08u,
};
JSExecResult js_v10_2_compact_group_24AE(JSCPU *cpu,
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
