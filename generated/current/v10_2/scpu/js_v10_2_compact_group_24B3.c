/* generated compact exact-context S-CPU shard - do not edit */
#include "js_v10_2_scpu_dispatch.h"
typedef struct js_v10_2_compact_record {
    uint32_t key;
    uint32_t parameter_offset;
    uint16_t template_id;
    uint16_t reserved;
} js_v10_2_compact_record;
static const js_v10_2_compact_record records[18] = {
    {0x04967B18u,0x00000000u,0x0000u,0u},
    {0x04967B30u,0x00000005u,0x0012u,0u},
    {0x04967B40u,0x00000009u,0x0000u,0u},
    {0x04967B58u,0x0000000Eu,0x0012u,0u},
    {0x04967B68u,0x00000012u,0x000Cu,0u},
    {0x04967B80u,0x00000017u,0x0001u,0u},
    {0x04967B98u,0x0000001Bu,0x0001u,0u},
    {0x04967BB0u,0x0000001Fu,0x0000u,0u},
    {0x04967BC8u,0x00000024u,0x0012u,0u},
    {0x04967BD8u,0x00000028u,0x0000u,0u},
    {0x04967BF0u,0x0000002Du,0x0012u,0u},
    {0x04967C00u,0x00000031u,0x000Cu,0u},
    {0x04967C18u,0x00000036u,0x0001u,0u},
    {0x04967C30u,0x0000003Au,0x000Cu,0u},
    {0x04967C48u,0x0000003Fu,0x0001u,0u},
    {0x04967C60u,0x00000043u,0x000Cu,0u},
    {0x04967C78u,0x00000048u,0x0001u,0u},
    {0x04967C90u,0x0000004Cu,0x000Eu,0u},
};
static const uint32_t parameters[79] = {
    0x04967B18u,0x0000CF66u,0x00000002u,0x00000010u,0x04967B30u,0x04967B30u,0x0000CF68u,0x00000023u,
    0x04967B40u,0x04967B40u,0x0000CF6Bu,0x00000006u,0x00000010u,0x04967B58u,0x04967B58u,0x0000CF6Du,
    0x00000025u,0x04967B68u,0x04967B68u,0x0000CF70u,0x0000CF43u,0x00000010u,0x04967B80u,0x04967B80u,
    0x0000CF73u,0x0000A296u,0x049514B0u,0x04967B98u,0x0000CF76u,0x0000A278u,0x049513C0u,0x04967BB0u,
    0x0000CF79u,0x00000000u,0x00000010u,0x04967BC8u,0x04967BC8u,0x0000CF7Bu,0x00000023u,0x04967BD8u,
    0x04967BD8u,0x0000CF7Eu,0x00000000u,0x00000010u,0x04967BF0u,0x04967BF0u,0x0000CF80u,0x00000025u,
    0x04967C00u,0x04967C00u,0x0000CF83u,0x0000CF09u,0x00000010u,0x04967C18u,0x04967C18u,0x0000CF86u,
    0x0000A296u,0x049514B0u,0x04967C30u,0x0000CF89u,0x0000CF45u,0x00000010u,0x04967C48u,0x04967C48u,
    0x0000CF8Cu,0x0000A596u,0x04952CB0u,0x04967C60u,0x0000CF8Fu,0x0000CF55u,0x00000010u,0x04967C78u,
    0x04967C78u,0x0000CF92u,0x0000A547u,0x04952A38u,0x04967C90u,0x0000CF93u,0x04945E08u,
};
JSExecResult js_v10_2_compact_group_24B3(JSCPU *cpu,
                                              const JSBus *bus,
                                              JSStop *stop,
                                              uint32_t packed) {
    size_t lo = 0u, hi = 18u;
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
