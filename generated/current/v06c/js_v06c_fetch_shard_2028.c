#include "js_v06c_fetch.h"

int js_v06c_fetch_shard_2028(JSV06Machine *m, JSV06Stop *stop) {
    uint8_t got;
    switch(js_cpu_context_key(&m->cpu)) {
    case 0x04050F93u:
        if(!js_v06c_read8(m,0x80A1F2u,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A1F2u;stop->value=got;}return -1;}
        return 1;
    case 0x04050F9Bu:
        if(!js_v06c_read8(m,0x80A1F3u,&got,stop)) return -1;
        if(got!=0x4Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A1F3u;stop->value=got;}return -1;}
        return 1;
    case 0x04050FA3u:
        if(!js_v06c_read8(m,0x80A1F4u,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A1F4u;stop->value=got;}return -1;}
        return 1;
    case 0x04050FABu:
        if(!js_v06c_read8(m,0x80A1F5u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A1F5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A1F6u,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A1F6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A1F7u,&got,stop)) return -1;
        if(got!=0xA1u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A1F7u;stop->value=got;}return -1;}
        return 1;
    case 0x04050FC3u:
        if(!js_v06c_read8(m,0x80A1F8u,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A1F8u;stop->value=got;}return -1;}
        return 1;
    case 0x04050FCBu:
        if(!js_v06c_read8(m,0x80A1F9u,&got,stop)) return -1;
        if(got!=0x6Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A1F9u;stop->value=got;}return -1;}
        return 1;
    case 0x04050FD3u:
        if(!js_v06c_read8(m,0x80A1FAu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A1FAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A1FBu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A1FBu;stop->value=got;}return -1;}
        return 1;
    case 0x04050FE0u:
        if(!js_v06c_read8(m,0x80A1FCu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A1FCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A1FDu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A1FDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A1FEu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A1FEu;stop->value=got;}return -1;}
        return 1;
    case 0x04050FF8u:
        if(!js_v06c_read8(m,0x80A1FFu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A1FFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A200u,&got,stop)) return -1;
        if(got!=0x15u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A200u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A201u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A201u;stop->value=got;}return -1;}
        return 1;
    case 0x04051010u:
        if(!js_v06c_read8(m,0x80A202u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A202u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A203u,&got,stop)) return -1;
        if(got!=0x5Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A203u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A204u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A204u;stop->value=got;}return -1;}
        return 1;
    case 0x04051028u:
        if(!js_v06c_read8(m,0x80A205u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A205u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A206u,&got,stop)) return -1;
        if(got!=0x16u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A206u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A207u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A207u;stop->value=got;}return -1;}
        return 1;
    case 0x04051040u:
        if(!js_v06c_read8(m,0x80A208u,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A208u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A209u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A209u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A20Au,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A20Au;stop->value=got;}return -1;}
        return 1;
    case 0x04051058u:
        if(!js_v06c_read8(m,0x80A20Bu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A20Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A20Cu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A20Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A20Du,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A20Du;stop->value=got;}return -1;}
        return 1;
    case 0x04051070u:
        if(!js_v06c_read8(m,0x80A20Eu,&got,stop)) return -1;
        if(got!=0x09u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A20Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A20Fu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A20Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A210u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A210u;stop->value=got;}return -1;}
        return 1;
    case 0x04051088u:
        if(!js_v06c_read8(m,0x80A211u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A211u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A212u,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A212u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A213u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A213u;stop->value=got;}return -1;}
        return 1;
    case 0x040510A0u:
        if(!js_v06c_read8(m,0x80A214u,&got,stop)) return -1;
        if(got!=0x88u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A214u;stop->value=got;}return -1;}
        return 1;
    case 0x040510A8u:
        if(!js_v06c_read8(m,0x80A215u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A215u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A216u,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A216u;stop->value=got;}return -1;}
        return 1;
    case 0x040510B8u:
        if(!js_v06c_read8(m,0x80A217u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A217u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A218u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A218u;stop->value=got;}return -1;}
        return 1;
    case 0x040510CBu:
        if(!js_v06c_read8(m,0x80A219u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A219u;stop->value=got;}return -1;}
        return 1;
    case 0x040510D0u:
        if(!js_v06c_read8(m,0x80A21Au,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A21Au;stop->value=got;}return -1;}
        return 1;
    case 0x040510D8u:
        if(!js_v06c_read8(m,0x80A21Bu,&got,stop)) return -1;
        if(got!=0x4Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A21Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040510E0u:
        if(!js_v06c_read8(m,0x80A21Cu,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A21Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040510E8u:
        if(!js_v06c_read8(m,0x80A21Du,&got,stop)) return -1;
        if(got!=0x48u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A21Du;stop->value=got;}return -1;}
        return 1;
    case 0x040510F0u:
        if(!js_v06c_read8(m,0x80A21Eu,&got,stop)) return -1;
        if(got!=0xDAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A21Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040510F8u:
        if(!js_v06c_read8(m,0x80A21Fu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A21Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A220u,&got,stop)) return -1;
        if(got!=0x26u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A220u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A221u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A221u;stop->value=got;}return -1;}
        return 1;
    case 0x04051110u:
        if(!js_v06c_read8(m,0x80A222u,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A222u;stop->value=got;}return -1;}
        return 1;
    case 0x04051118u:
        if(!js_v06c_read8(m,0x80A223u,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A223u;stop->value=got;}return -1;}
        return 1;
    case 0x04051120u:
        if(!js_v06c_read8(m,0x80A224u,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A224u;stop->value=got;}return -1;}
        return 1;
    case 0x04051128u:
        if(!js_v06c_read8(m,0x80A225u,&got,stop)) return -1;
        if(got!=0x6Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A225u;stop->value=got;}return -1;}
        return 1;
    case 0x04051130u:
        if(!js_v06c_read8(m,0x80A226u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A226u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A227u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A227u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A228u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A228u;stop->value=got;}return -1;}
        return 1;
    case 0x04051148u:
        if(!js_v06c_read8(m,0x80A229u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A229u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A22Au,&got,stop)) return -1;
        if(got!=0x15u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A22Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A22Bu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A22Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04051160u:
        if(!js_v06c_read8(m,0x80A22Cu,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A22Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A22Du,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A22Du;stop->value=got;}return -1;}
        return 1;
    case 0x04051170u:
        if(!js_v06c_read8(m,0x80A22Eu,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A22Eu;stop->value=got;}return -1;}
        return 1;
    case 0x04051178u:
        if(!js_v06c_read8(m,0x80A22Fu,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A22Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04051180u:
        if(!js_v06c_read8(m,0x80A230u,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A230u;stop->value=got;}return -1;}
        return 1;
    case 0x04051188u:
        if(!js_v06c_read8(m,0x80A231u,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A231u;stop->value=got;}return -1;}
        return 1;
    case 0x04051190u:
        if(!js_v06c_read8(m,0x80A232u,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A232u;stop->value=got;}return -1;}
        return 1;
    case 0x04051198u:
        if(!js_v06c_read8(m,0x80A233u,&got,stop)) return -1;
        if(got!=0x69u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A233u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A234u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A234u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A235u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A235u;stop->value=got;}return -1;}
        return 1;
    case 0x040511B0u:
        if(!js_v06c_read8(m,0x80A236u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A236u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A237u,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A237u;stop->value=got;}return -1;}
        return 1;
    case 0x040511C0u:
        if(!js_v06c_read8(m,0x80A238u,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A238u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A239u,&got,stop)) return -1;
        if(got!=0x05u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A239u;stop->value=got;}return -1;}
        return 1;
    case 0x040511D0u:
        if(!js_v06c_read8(m,0x80A23Au,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A23Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A23Bu,&got,stop)) return -1;
        if(got!=0x6Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A23Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040511E0u:
        if(!js_v06c_read8(m,0x80A23Cu,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A23Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A23Du,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A23Du;stop->value=got;}return -1;}
        return 1;
    case 0x040511F3u:
        if(!js_v06c_read8(m,0x80A23Eu,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A23Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A23Fu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A23Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04051203u:
        if(!js_v06c_read8(m,0x80A240u,&got,stop)) return -1;
        if(got!=0xA5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A240u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A241u,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A241u;stop->value=got;}return -1;}
        return 1;
    case 0x04051213u:
        if(!js_v06c_read8(m,0x80A242u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A242u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A243u,&got,stop)) return -1;
        if(got!=0x16u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A243u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A244u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A244u;stop->value=got;}return -1;}
        return 1;
    case 0x0405122Bu:
        if(!js_v06c_read8(m,0x80A245u,&got,stop)) return -1;
        if(got!=0xA5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A245u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A246u,&got,stop)) return -1;
        if(got!=0x69u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A246u;stop->value=got;}return -1;}
        return 1;
    case 0x0405123Bu:
        if(!js_v06c_read8(m,0x80A247u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A247u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A248u,&got,stop)) return -1;
        if(got!=0x17u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A248u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A249u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A249u;stop->value=got;}return -1;}
        return 1;
    case 0x04051253u:
        if(!js_v06c_read8(m,0x80A24Au,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A24Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A24Bu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A24Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04051263u:
        if(!js_v06c_read8(m,0x80A24Cu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A24Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A24Du,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A24Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A24Eu,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A24Eu;stop->value=got;}return -1;}
        return 1;
    case 0x0405127Bu:
        if(!js_v06c_read8(m,0x80A24Fu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A24Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A250u,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A250u;stop->value=got;}return -1;}
        return 1;
    case 0x0405128Bu:
        if(!js_v06c_read8(m,0x80A251u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A251u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A252u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A252u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A253u,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A253u;stop->value=got;}return -1;}
        return 1;
    case 0x040512A3u:
        if(!js_v06c_read8(m,0x80A254u,&got,stop)) return -1;
        if(got!=0xA5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A254u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A255u,&got,stop)) return -1;
        if(got!=0x6Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A255u;stop->value=got;}return -1;}
        return 1;
    case 0x040512B3u:
        if(!js_v06c_read8(m,0x80A256u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A256u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A257u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A257u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A258u,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A258u;stop->value=got;}return -1;}
        return 1;
    case 0x040512CBu:
        if(!js_v06c_read8(m,0x80A259u,&got,stop)) return -1;
        if(got!=0xA5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A259u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A25Au,&got,stop)) return -1;
        if(got!=0x6Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A25Au;stop->value=got;}return -1;}
        return 1;
    case 0x040512DBu:
        if(!js_v06c_read8(m,0x80A25Bu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A25Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A25Cu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A25Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A25Du,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A25Du;stop->value=got;}return -1;}
        return 1;
    case 0x040512F3u:
        if(!js_v06c_read8(m,0x80A25Eu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A25Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A25Fu,&got,stop)) return -1;
        if(got!=0x7Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A25Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04051303u:
        if(!js_v06c_read8(m,0x80A260u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A260u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A261u,&got,stop)) return -1;
        if(got!=0x04u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A261u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A262u,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A262u;stop->value=got;}return -1;}
        return 1;
    case 0x0405131Bu:
        if(!js_v06c_read8(m,0x80A263u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A263u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A264u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A264u;stop->value=got;}return -1;}
        return 1;
    case 0x0405132Bu:
        if(!js_v06c_read8(m,0x80A265u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A265u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A266u,&got,stop)) return -1;
        if(got!=0x05u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A266u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A267u,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A267u;stop->value=got;}return -1;}
        return 1;
    case 0x04051343u:
        if(!js_v06c_read8(m,0x80A268u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A268u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A269u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A269u;stop->value=got;}return -1;}
        return 1;
    case 0x04051353u:
        if(!js_v06c_read8(m,0x80A26Au,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A26Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A26Bu,&got,stop)) return -1;
        if(got!=0x06u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A26Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A26Cu,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A26Cu;stop->value=got;}return -1;}
        return 1;
    case 0x0405136Bu:
        if(!js_v06c_read8(m,0x80A26Du,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A26Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A26Eu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A26Eu;stop->value=got;}return -1;}
        return 1;
    case 0x0405137Bu:
        if(!js_v06c_read8(m,0x80A26Fu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A26Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A270u,&got,stop)) return -1;
        if(got!=0x0Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A270u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A271u,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A271u;stop->value=got;}return -1;}
        return 1;
    case 0x04051393u:
        if(!js_v06c_read8(m,0x80A272u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A272u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A273u,&got,stop)) return -1;
        if(got!=0x69u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A273u;stop->value=got;}return -1;}
        return 1;
    case 0x040513A3u:
        if(!js_v06c_read8(m,0x80A274u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A274u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A275u,&got,stop)) return -1;
        if(got!=0x6Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A275u;stop->value=got;}return -1;}
        return 1;
    case 0x040513B3u:
        if(!js_v06c_read8(m,0x80A276u,&got,stop)) return -1;
        if(got!=0xE8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A276u;stop->value=got;}return -1;}
        return 1;
    case 0x040513BBu:
        if(!js_v06c_read8(m,0x80A277u,&got,stop)) return -1;
        if(got!=0xE0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A277u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A278u,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A278u;stop->value=got;}return -1;}
        return 1;
    case 0x040513CBu:
        if(!js_v06c_read8(m,0x80A279u,&got,stop)) return -1;
        if(got!=0x90u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A279u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A27Au,&got,stop)) return -1;
        if(got!=0xC5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A27Au;stop->value=got;}return -1;}
        return 1;
    case 0x040513DBu:
        if(!js_v06c_read8(m,0x80A27Bu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A27Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A27Cu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A27Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040513E8u:
        if(!js_v06c_read8(m,0x80A27Du,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A27Du;stop->value=got;}return -1;}
        return 1;
    case 0x040516D8u:
        if(!js_v06c_read8(m,0x80A2DBu,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2DBu;stop->value=got;}return -1;}
        return 1;
    case 0x040516E0u:
        if(!js_v06c_read8(m,0x80A2DCu,&got,stop)) return -1;
        if(got!=0x4Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2DCu;stop->value=got;}return -1;}
        return 1;
    case 0x040516E8u:
        if(!js_v06c_read8(m,0x80A2DDu,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2DDu;stop->value=got;}return -1;}
        return 1;
    case 0x040516F0u:
        if(!js_v06c_read8(m,0x80A2DEu,&got,stop)) return -1;
        if(got!=0x48u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2DEu;stop->value=got;}return -1;}
        return 1;
    case 0x040516F8u:
        if(!js_v06c_read8(m,0x80A2DFu,&got,stop)) return -1;
        if(got!=0xDAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2DFu;stop->value=got;}return -1;}
        return 1;
    case 0x04051700u:
        if(!js_v06c_read8(m,0x80A2E0u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2E0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A2E1u,&got,stop)) return -1;
        if(got!=0xE7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2E1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A2E2u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2E2u;stop->value=got;}return -1;}
        return 1;
    case 0x04051718u:
        if(!js_v06c_read8(m,0x80A2E3u,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2E3u;stop->value=got;}return -1;}
        return 1;
    case 0x04051720u:
        if(!js_v06c_read8(m,0x80A2E4u,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2E4u;stop->value=got;}return -1;}
        return 1;
    case 0x04051728u:
        if(!js_v06c_read8(m,0x80A2E5u,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2E5u;stop->value=got;}return -1;}
        return 1;
    case 0x04051730u:
        if(!js_v06c_read8(m,0x80A2E6u,&got,stop)) return -1;
        if(got!=0x6Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2E6u;stop->value=got;}return -1;}
        return 1;
    case 0x04051738u:
        if(!js_v06c_read8(m,0x80A2E7u,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2E7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A2E8u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2E8u;stop->value=got;}return -1;}
        return 1;
    case 0x04051748u:
        if(!js_v06c_read8(m,0x80A2E9u,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2E9u;stop->value=got;}return -1;}
        return 1;
    case 0x04051750u:
        if(!js_v06c_read8(m,0x80A2EAu,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2EAu;stop->value=got;}return -1;}
        return 1;
    case 0x04051758u:
        if(!js_v06c_read8(m,0x80A2EBu,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2EBu;stop->value=got;}return -1;}
        return 1;
    case 0x04051760u:
        if(!js_v06c_read8(m,0x80A2ECu,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2ECu;stop->value=got;}return -1;}
        return 1;
    case 0x04051768u:
        if(!js_v06c_read8(m,0x80A2EDu,&got,stop)) return -1;
        if(got!=0x69u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2EDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A2EEu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2EEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A2EFu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2EFu;stop->value=got;}return -1;}
        return 1;
    case 0x04051780u:
        if(!js_v06c_read8(m,0x80A2F0u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2F0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A2F1u,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2F1u;stop->value=got;}return -1;}
        return 1;
    case 0x04051790u:
        if(!js_v06c_read8(m,0x80A2F2u,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2F2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A2F3u,&got,stop)) return -1;
        if(got!=0x05u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2F3u;stop->value=got;}return -1;}
        return 1;
    case 0x040517A0u:
        if(!js_v06c_read8(m,0x80A2F4u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2F4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A2F5u,&got,stop)) return -1;
        if(got!=0x6Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2F5u;stop->value=got;}return -1;}
        return 1;
    case 0x040517B0u:
        if(!js_v06c_read8(m,0x80A2F6u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2F6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A2F7u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2F7u;stop->value=got;}return -1;}
        return 1;
    case 0x040517C3u:
        if(!js_v06c_read8(m,0x80A2F8u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2F8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A2F9u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2F9u;stop->value=got;}return -1;}
        return 1;
    case 0x040517D3u:
        if(!js_v06c_read8(m,0x80A2FAu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2FAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A2FBu,&got,stop)) return -1;
        if(got!=0x15u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2FBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A2FCu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2FCu;stop->value=got;}return -1;}
        return 1;
    case 0x040517EBu:
        if(!js_v06c_read8(m,0x80A2FDu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2FDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A2FEu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2FEu;stop->value=got;}return -1;}
        return 1;
    case 0x040517FBu:
        if(!js_v06c_read8(m,0x80A2FFu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A2FFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A300u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A300u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A301u,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A301u;stop->value=got;}return -1;}
        return 1;
    case 0x04051813u:
        if(!js_v06c_read8(m,0x80A302u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A302u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A303u,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A303u;stop->value=got;}return -1;}
        return 1;
    case 0x04051823u:
        if(!js_v06c_read8(m,0x80A304u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A304u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A305u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A305u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A306u,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A306u;stop->value=got;}return -1;}
        return 1;
    case 0x0405183Bu:
        if(!js_v06c_read8(m,0x80A307u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A307u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A308u,&got,stop)) return -1;
        if(got!=0x7Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A308u;stop->value=got;}return -1;}
        return 1;
    case 0x0405184Bu:
        if(!js_v06c_read8(m,0x80A309u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A309u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A30Au,&got,stop)) return -1;
        if(got!=0x04u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A30Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A30Bu,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A30Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04051863u:
        if(!js_v06c_read8(m,0x80A30Cu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A30Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A30Du,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A30Du;stop->value=got;}return -1;}
        return 1;
    case 0x04051870u:
        if(!js_v06c_read8(m,0x80A30Eu,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A30Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A30Fu,&got,stop)) return -1;
        if(got!=0x04u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A30Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A310u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A310u;stop->value=got;}return -1;}
        return 1;
    case 0x04051888u:
        if(!js_v06c_read8(m,0x80A311u,&got,stop)) return -1;
        if(got!=0xA5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A311u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A312u,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A312u;stop->value=got;}return -1;}
        return 1;
    case 0x04051898u:
        if(!js_v06c_read8(m,0x80A313u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A313u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A314u,&got,stop)) return -1;
        if(got!=0x16u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A314u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A315u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A315u;stop->value=got;}return -1;}
        return 1;
    case 0x040518B0u:
        if(!js_v06c_read8(m,0x80A316u,&got,stop)) return -1;
        if(got!=0xA5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A316u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A317u,&got,stop)) return -1;
        if(got!=0x6Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A317u;stop->value=got;}return -1;}
        return 1;
    case 0x040518C0u:
        if(!js_v06c_read8(m,0x80A318u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A318u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A319u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A319u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A31Au,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A31Au;stop->value=got;}return -1;}
        return 1;
    case 0x040518D8u:
        if(!js_v06c_read8(m,0x80A31Bu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A31Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A31Cu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A31Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A31Du,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A31Du;stop->value=got;}return -1;}
        return 1;
    case 0x040518F0u:
        if(!js_v06c_read8(m,0x80A31Eu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A31Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A31Fu,&got,stop)) return -1;
        if(got!=0x05u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A31Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A320u,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A320u;stop->value=got;}return -1;}
        return 1;
    case 0x04051908u:
        if(!js_v06c_read8(m,0x80A321u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A321u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A322u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A322u;stop->value=got;}return -1;}
        return 1;
    case 0x0405191Bu:
        if(!js_v06c_read8(m,0x80A323u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A323u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A324u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A324u;stop->value=got;}return -1;}
        return 1;
    case 0x0405192Bu:
        if(!js_v06c_read8(m,0x80A325u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A325u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A326u,&got,stop)) return -1;
        if(got!=0x0Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A326u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A327u,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A327u;stop->value=got;}return -1;}
        return 1;
    case 0x04051943u:
        if(!js_v06c_read8(m,0x80A328u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A328u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A329u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A329u;stop->value=got;}return -1;}
        return 1;
    case 0x04051950u:
        if(!js_v06c_read8(m,0x80A32Au,&got,stop)) return -1;
        if(got!=0xA5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A32Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A32Bu,&got,stop)) return -1;
        if(got!=0x6Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A32Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04051960u:
        if(!js_v06c_read8(m,0x80A32Cu,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A32Cu;stop->value=got;}return -1;}
        return 1;
    case 0x04051968u:
        if(!js_v06c_read8(m,0x80A32Du,&got,stop)) return -1;
        if(got!=0x69u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A32Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A32Eu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A32Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A32Fu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A32Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04051980u:
        if(!js_v06c_read8(m,0x80A330u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A330u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A331u,&got,stop)) return -1;
        if(got!=0x6Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A331u;stop->value=got;}return -1;}
        return 1;
    case 0x04051990u:
        if(!js_v06c_read8(m,0x80A332u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A332u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A333u,&got,stop)) return -1;
        if(got!=0x69u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A333u;stop->value=got;}return -1;}
        return 1;
    case 0x040519A0u:
        if(!js_v06c_read8(m,0x80A334u,&got,stop)) return -1;
        if(got!=0xCAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A334u;stop->value=got;}return -1;}
        return 1;
    case 0x040519A8u:
        if(!js_v06c_read8(m,0x80A335u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A335u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A336u,&got,stop)) return -1;
        if(got!=0xDAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A336u;stop->value=got;}return -1;}
        return 1;
    case 0x040519B8u:
        if(!js_v06c_read8(m,0x80A337u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A337u;stop->value=got;}return -1;}
        return 1;
    case 0x040519C0u:
        if(!js_v06c_read8(m,0x80A338u,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A338u;stop->value=got;}return -1;}
        return 1;
    case 0x040519C8u:
        if(!js_v06c_read8(m,0x80A339u,&got,stop)) return -1;
        if(got!=0x4Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A339u;stop->value=got;}return -1;}
        return 1;
    case 0x040519D0u:
        if(!js_v06c_read8(m,0x80A33Au,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A33Au;stop->value=got;}return -1;}
        return 1;
    case 0x040519D8u:
        if(!js_v06c_read8(m,0x80A33Bu,&got,stop)) return -1;
        if(got!=0x48u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A33Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040519E0u:
        if(!js_v06c_read8(m,0x80A33Cu,&got,stop)) return -1;
        if(got!=0xDAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A33Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040519E8u:
        if(!js_v06c_read8(m,0x80A33Du,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A33Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A33Eu,&got,stop)) return -1;
        if(got!=0x44u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A33Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A33Fu,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A33Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04051A00u:
        if(!js_v06c_read8(m,0x80A340u,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A340u;stop->value=got;}return -1;}
        return 1;
    case 0x04051A08u:
        if(!js_v06c_read8(m,0x80A341u,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A341u;stop->value=got;}return -1;}
        return 1;
    case 0x04051A10u:
        if(!js_v06c_read8(m,0x80A342u,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A342u;stop->value=got;}return -1;}
        return 1;
    case 0x04051A18u:
        if(!js_v06c_read8(m,0x80A343u,&got,stop)) return -1;
        if(got!=0x6Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A343u;stop->value=got;}return -1;}
        return 1;
    case 0x04051A20u:
        if(!js_v06c_read8(m,0x80A344u,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A344u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A345u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A345u;stop->value=got;}return -1;}
        return 1;
    case 0x04051A30u:
        if(!js_v06c_read8(m,0x80A346u,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A346u;stop->value=got;}return -1;}
        return 1;
    case 0x04051A38u:
        if(!js_v06c_read8(m,0x80A347u,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A347u;stop->value=got;}return -1;}
        return 1;
    case 0x04051A40u:
        if(!js_v06c_read8(m,0x80A348u,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A348u;stop->value=got;}return -1;}
        return 1;
    case 0x04051A48u:
        if(!js_v06c_read8(m,0x80A349u,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A349u;stop->value=got;}return -1;}
        return 1;
    case 0x04051A50u:
        if(!js_v06c_read8(m,0x80A34Au,&got,stop)) return -1;
        if(got!=0x69u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A34Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A34Bu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A34Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A34Cu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A34Cu;stop->value=got;}return -1;}
        return 1;
    case 0x04051A68u:
        if(!js_v06c_read8(m,0x80A34Du,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A34Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A34Eu,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A34Eu;stop->value=got;}return -1;}
        return 1;
    case 0x04051A78u:
        if(!js_v06c_read8(m,0x80A34Fu,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A34Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A350u,&got,stop)) return -1;
        if(got!=0x05u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A350u;stop->value=got;}return -1;}
        return 1;
    case 0x04051A88u:
        if(!js_v06c_read8(m,0x80A351u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A351u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A352u,&got,stop)) return -1;
        if(got!=0x6Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A352u;stop->value=got;}return -1;}
        return 1;
    case 0x04051A98u:
        if(!js_v06c_read8(m,0x80A353u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A353u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A354u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A354u;stop->value=got;}return -1;}
        return 1;
    case 0x04051AABu:
        if(!js_v06c_read8(m,0x80A355u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A355u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A356u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A356u;stop->value=got;}return -1;}
        return 1;
    case 0x04051ABBu:
        if(!js_v06c_read8(m,0x80A357u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A357u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A358u,&got,stop)) return -1;
        if(got!=0x15u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A358u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A359u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A359u;stop->value=got;}return -1;}
        return 1;
    case 0x04051AD3u:
        if(!js_v06c_read8(m,0x80A35Au,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A35Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A35Bu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A35Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04051AE3u:
        if(!js_v06c_read8(m,0x80A35Cu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A35Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A35Du,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A35Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A35Eu,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A35Eu;stop->value=got;}return -1;}
        return 1;
    case 0x04051AFBu:
        if(!js_v06c_read8(m,0x80A35Fu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A35Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A360u,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A360u;stop->value=got;}return -1;}
        return 1;
    case 0x04051B0Bu:
        if(!js_v06c_read8(m,0x80A361u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A361u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A362u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A362u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A363u,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A363u;stop->value=got;}return -1;}
        return 1;
    case 0x04051B23u:
        if(!js_v06c_read8(m,0x80A364u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A364u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A365u,&got,stop)) return -1;
        if(got!=0x7Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A365u;stop->value=got;}return -1;}
        return 1;
    case 0x04051B33u:
        if(!js_v06c_read8(m,0x80A366u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A366u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A367u,&got,stop)) return -1;
        if(got!=0x04u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A367u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A368u,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A368u;stop->value=got;}return -1;}
        return 1;
    case 0x04051B4Bu:
        if(!js_v06c_read8(m,0x80A369u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A369u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A36Au,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A36Au;stop->value=got;}return -1;}
        return 1;
    case 0x04051B58u:
        if(!js_v06c_read8(m,0x80A36Bu,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A36Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A36Cu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A36Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A36Du,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A36Du;stop->value=got;}return -1;}
        return 1;
    case 0x04051B70u:
        if(!js_v06c_read8(m,0x80A36Eu,&got,stop)) return -1;
        if(got!=0xA5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A36Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A36Fu,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A36Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04051B80u:
        if(!js_v06c_read8(m,0x80A370u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A370u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A371u,&got,stop)) return -1;
        if(got!=0x16u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A371u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A372u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A372u;stop->value=got;}return -1;}
        return 1;
    case 0x04051B98u:
        if(!js_v06c_read8(m,0x80A373u,&got,stop)) return -1;
        if(got!=0xA5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A373u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A374u,&got,stop)) return -1;
        if(got!=0x6Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A374u;stop->value=got;}return -1;}
        return 1;
    case 0x04051BA8u:
        if(!js_v06c_read8(m,0x80A375u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A375u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A376u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A376u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A377u,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A377u;stop->value=got;}return -1;}
        return 1;
    case 0x04051BC0u:
        if(!js_v06c_read8(m,0x80A378u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A378u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A379u,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A379u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A37Au,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A37Au;stop->value=got;}return -1;}
        return 1;
    case 0x04051BD8u:
        if(!js_v06c_read8(m,0x80A37Bu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A37Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A37Cu,&got,stop)) return -1;
        if(got!=0x05u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A37Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A37Du,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A37Du;stop->value=got;}return -1;}
        return 1;
    case 0x04051BF0u:
        if(!js_v06c_read8(m,0x80A37Eu,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A37Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A37Fu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A37Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04051C03u:
        if(!js_v06c_read8(m,0x80A380u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A380u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A381u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A381u;stop->value=got;}return -1;}
        return 1;
    case 0x04051C13u:
        if(!js_v06c_read8(m,0x80A382u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A382u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A383u,&got,stop)) return -1;
        if(got!=0x0Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A383u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A384u,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A384u;stop->value=got;}return -1;}
        return 1;
    case 0x04051C2Bu:
        if(!js_v06c_read8(m,0x80A385u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A385u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A386u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A386u;stop->value=got;}return -1;}
        return 1;
    case 0x04051C38u:
        if(!js_v06c_read8(m,0x80A387u,&got,stop)) return -1;
        if(got!=0xA5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A387u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A388u,&got,stop)) return -1;
        if(got!=0x6Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A388u;stop->value=got;}return -1;}
        return 1;
    case 0x04051C48u:
        if(!js_v06c_read8(m,0x80A389u,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A389u;stop->value=got;}return -1;}
        return 1;
    case 0x04051C50u:
        if(!js_v06c_read8(m,0x80A38Au,&got,stop)) return -1;
        if(got!=0x69u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A38Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A38Bu,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A38Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A38Cu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A38Cu;stop->value=got;}return -1;}
        return 1;
    case 0x04051C68u:
        if(!js_v06c_read8(m,0x80A38Du,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A38Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A38Eu,&got,stop)) return -1;
        if(got!=0x6Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A38Eu;stop->value=got;}return -1;}
        return 1;
    case 0x04051C78u:
        if(!js_v06c_read8(m,0x80A38Fu,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A38Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A390u,&got,stop)) return -1;
        if(got!=0x69u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A390u;stop->value=got;}return -1;}
        return 1;
    case 0x04051C88u:
        if(!js_v06c_read8(m,0x80A391u,&got,stop)) return -1;
        if(got!=0xCAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A391u;stop->value=got;}return -1;}
        return 1;
    case 0x04051C90u:
        if(!js_v06c_read8(m,0x80A392u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A392u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A393u,&got,stop)) return -1;
        if(got!=0xDAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A393u;stop->value=got;}return -1;}
        return 1;
    case 0x04051CA0u:
        if(!js_v06c_read8(m,0x80A394u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A394u;stop->value=got;}return -1;}
        return 1;
    case 0x04051D03u:
        if(!js_v06c_read8(m,0x80A3A0u,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3A0u;stop->value=got;}return -1;}
        return 1;
    case 0x04051D0Bu:
        if(!js_v06c_read8(m,0x80A3A1u,&got,stop)) return -1;
        if(got!=0x4Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3A1u;stop->value=got;}return -1;}
        return 1;
    case 0x04051D13u:
        if(!js_v06c_read8(m,0x80A3A2u,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3A2u;stop->value=got;}return -1;}
        return 1;
    case 0x04051D1Bu:
        if(!js_v06c_read8(m,0x80A3A3u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3A3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A3A4u,&got,stop)) return -1;
        if(got!=0xA8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3A4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A3A5u,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3A5u;stop->value=got;}return -1;}
        return 1;
    case 0x04051D33u:
        if(!js_v06c_read8(m,0x80A3A6u,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3A6u;stop->value=got;}return -1;}
        return 1;
    case 0x04051D3Bu:
        if(!js_v06c_read8(m,0x80A3A7u,&got,stop)) return -1;
        if(got!=0x6Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3A7u;stop->value=got;}return -1;}
        return 1;
    case 0x04051D43u:
        if(!js_v06c_read8(m,0x80A3A8u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3A8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A3A9u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3A9u;stop->value=got;}return -1;}
        return 1;
    case 0x04051D53u:
        if(!js_v06c_read8(m,0x80A3AAu,&got,stop)) return -1;
        if(got!=0x48u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3AAu;stop->value=got;}return -1;}
        return 1;
    case 0x04051D5Bu:
        if(!js_v06c_read8(m,0x80A3ABu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3ABu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A3ACu,&got,stop)) return -1;
        if(got!=0x44u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3ACu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A3ADu,&got,stop)) return -1;
        if(got!=0xA4u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3ADu;stop->value=got;}return -1;}
        return 1;
    case 0x04051D73u:
        if(!js_v06c_read8(m,0x80A3AEu,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3AEu;stop->value=got;}return -1;}
        return 1;
    case 0x04051D7Bu:
        if(!js_v06c_read8(m,0x80A3AFu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3AFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A3B0u,&got,stop)) return -1;
        if(got!=0x5Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3B0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A3B1u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3B1u;stop->value=got;}return -1;}
        return 1;
    case 0x04051D93u:
        if(!js_v06c_read8(m,0x80A3B2u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3B2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A3B3u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3B3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A3B4u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3B4u;stop->value=got;}return -1;}
        return 1;
    case 0x04051DABu:
        if(!js_v06c_read8(m,0x80A3B5u,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3B5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A3B6u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3B6u;stop->value=got;}return -1;}
        return 1;
    case 0x04051DBBu:
        if(!js_v06c_read8(m,0x80A3B7u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3B7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A3B8u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3B8u;stop->value=got;}return -1;}
        return 1;
    case 0x04051DCBu:
        if(!js_v06c_read8(m,0x80A3B9u,&got,stop)) return -1;
        if(got!=0xCAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3B9u;stop->value=got;}return -1;}
        return 1;
    case 0x04051DD3u:
        if(!js_v06c_read8(m,0x80A3BAu,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3BAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A3BBu,&got,stop)) return -1;
        if(got!=0xFDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3BBu;stop->value=got;}return -1;}
        return 1;
    case 0x04051DE3u:
        if(!js_v06c_read8(m,0x80A3BCu,&got,stop)) return -1;
        if(got!=0x88u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3BCu;stop->value=got;}return -1;}
        return 1;
    case 0x04051DEBu:
        if(!js_v06c_read8(m,0x80A3BDu,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3BDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A3BEu,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3BEu;stop->value=got;}return -1;}
        return 1;
    case 0x04051DFBu:
        if(!js_v06c_read8(m,0x80A3BFu,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3BFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A3C0u,&got,stop)) return -1;
        if(got!=0x5Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3C0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A3C1u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3C1u;stop->value=got;}return -1;}
        return 1;
    case 0x04051E13u:
        if(!js_v06c_read8(m,0x80A3C2u,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3C2u;stop->value=got;}return -1;}
        return 1;
    case 0x04051E1Bu:
        if(!js_v06c_read8(m,0x80A3C3u,&got,stop)) return -1;
        if(got!=0xC9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3C3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A3C4u,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3C4u;stop->value=got;}return -1;}
        return 1;
    case 0x04051E2Bu:
        if(!js_v06c_read8(m,0x80A3C5u,&got,stop)) return -1;
        if(got!=0x90u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3C5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A3C6u,&got,stop)) return -1;
        if(got!=0xE3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3C6u;stop->value=got;}return -1;}
        return 1;
    case 0x04051E3Bu:
        if(!js_v06c_read8(m,0x80A3C7u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3C7u;stop->value=got;}return -1;}
        return 1;
    case 0x04051F53u:
        if(!js_v06c_read8(m,0x80A3EAu,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3EAu;stop->value=got;}return -1;}
        return 1;
    case 0x04051F5Bu:
        if(!js_v06c_read8(m,0x80A3EBu,&got,stop)) return -1;
        if(got!=0x4Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3EBu;stop->value=got;}return -1;}
        return 1;
    case 0x04051F63u:
        if(!js_v06c_read8(m,0x80A3ECu,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3ECu;stop->value=got;}return -1;}
        return 1;
    case 0x04051F6Bu:
        if(!js_v06c_read8(m,0x80A3EDu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3EDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A3EEu,&got,stop)) return -1;
        if(got!=0xF2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3EEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A3EFu,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3EFu;stop->value=got;}return -1;}
        return 1;
    case 0x04051F83u:
        if(!js_v06c_read8(m,0x80A3F0u,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3F0u;stop->value=got;}return -1;}
        return 1;
    case 0x04051F8Bu:
        if(!js_v06c_read8(m,0x80A3F1u,&got,stop)) return -1;
        if(got!=0x6Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3F1u;stop->value=got;}return -1;}
        return 1;
    case 0x04051F93u:
        if(!js_v06c_read8(m,0x80A3F2u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3F2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A3F3u,&got,stop)) return -1;
        if(got!=0x0Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3F3u;stop->value=got;}return -1;}
        return 1;
    case 0x04051FA3u:
        if(!js_v06c_read8(m,0x80A3F4u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3F4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A3F5u,&got,stop)) return -1;
        if(got!=0x5Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3F5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A3F6u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3F6u;stop->value=got;}return -1;}
        return 1;
    case 0x04051FBBu:
        if(!js_v06c_read8(m,0x80A3F7u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3F7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A3F8u,&got,stop)) return -1;
        if(got!=0x44u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3F8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A3F9u,&got,stop)) return -1;
        if(got!=0xA4u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3F9u;stop->value=got;}return -1;}
        return 1;
    case 0x04051FD3u:
        if(!js_v06c_read8(m,0x80A3FAu,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3FAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A3FBu,&got,stop)) return -1;
        if(got!=0x5Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3FBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A3FCu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3FCu;stop->value=got;}return -1;}
        return 1;
    case 0x04051FEBu:
        if(!js_v06c_read8(m,0x80A3FDu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3FDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A3FEu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3FEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A3FFu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A3FFu;stop->value=got;}return -1;}
        return 1;
    default: return 0;
    }
}
