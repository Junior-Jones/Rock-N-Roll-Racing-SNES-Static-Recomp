#include "js_v06c_fetch.h"

int js_v06c_fetch_shard_24BC(JSV06Machine *m, JSV06Stop *stop) {
    uint8_t got;
    switch(js_cpu_context_key(&m->cpu)) {
    case 0x0497800Bu:
        if(!js_v06c_read8(m,0x92F001u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F001u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F002u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F002u;stop->value=got;}return -1;}
        return 1;
    case 0x0497801Bu:
        if(!js_v06c_read8(m,0x92F003u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F003u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F004u,&got,stop)) return -1;
        if(got!=0x4Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F004u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F005u,&got,stop)) return -1;
        if(got!=0x0Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F005u;stop->value=got;}return -1;}
        return 1;
    case 0x04978033u:
        if(!js_v06c_read8(m,0x92F006u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F006u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F007u,&got,stop)) return -1;
        if(got!=0x55u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F007u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F008u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F008u;stop->value=got;}return -1;}
        return 1;
    case 0x0497804Bu:
        if(!js_v06c_read8(m,0x92F009u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F009u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F00Au,&got,stop)) return -1;
        if(got!=0x56u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F00Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F00Bu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F00Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04978063u:
        if(!js_v06c_read8(m,0x92F00Cu,&got,stop)) return -1;
        if(got!=0x64u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F00Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F00Du,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F00Du;stop->value=got;}return -1;}
        return 1;
    case 0x04978073u:
        if(!js_v06c_read8(m,0x92F00Eu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F00Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F00Fu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F00Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F010u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F010u;stop->value=got;}return -1;}
        return 1;
    case 0x0497808Bu:
        if(!js_v06c_read8(m,0x92F011u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F011u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F012u,&got,stop)) return -1;
        if(got!=0x47u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F012u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F013u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F013u;stop->value=got;}return -1;}
        return 1;
    case 0x049780A3u:
        if(!js_v06c_read8(m,0x92F014u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F014u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F015u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F015u;stop->value=got;}return -1;}
        return 1;
    case 0x049780B3u:
        if(!js_v06c_read8(m,0x92F016u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F016u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F017u,&got,stop)) return -1;
        if(got!=0x6Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F017u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F018u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F018u;stop->value=got;}return -1;}
        return 1;
    case 0x049780CBu:
        if(!js_v06c_read8(m,0x92F019u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F019u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F01Au,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F01Au;stop->value=got;}return -1;}
        return 1;
    case 0x049780D9u:
        if(!js_v06c_read8(m,0x92F01Bu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F01Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F01Cu,&got,stop)) return -1;
        if(got!=0x55u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F01Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F01Du,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F01Du;stop->value=got;}return -1;}
        return 1;
    case 0x049780F1u:
        if(!js_v06c_read8(m,0x92F01Eu,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F01Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F01Fu,&got,stop)) return -1;
        if(got!=0x31u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F01Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F020u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F020u;stop->value=got;}return -1;}
        return 1;
    case 0x04978109u:
        if(!js_v06c_read8(m,0x92F021u,&got,stop)) return -1;
        if(got!=0xC9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F021u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F022u,&got,stop)) return -1;
        if(got!=0x34u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F022u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F023u,&got,stop)) return -1;
        if(got!=0x12u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F023u;stop->value=got;}return -1;}
        return 1;
    case 0x04978121u:
        if(!js_v06c_read8(m,0x92F024u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F024u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F025u,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F025u;stop->value=got;}return -1;}
        return 1;
    case 0x04978131u:
        if(!js_v06c_read8(m,0x92F026u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F026u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F027u,&got,stop)) return -1;
        if(got!=0x37u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F027u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F028u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F028u;stop->value=got;}return -1;}
        return 1;
    case 0x04978149u:
        if(!js_v06c_read8(m,0x92F029u,&got,stop)) return -1;
        if(got!=0xC9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F029u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F02Au,&got,stop)) return -1;
        if(got!=0x78u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F02Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F02Bu,&got,stop)) return -1;
        if(got!=0x56u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F02Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04978161u:
        if(!js_v06c_read8(m,0x92F02Cu,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F02Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F02Du,&got,stop)) return -1;
        if(got!=0x15u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F02Du;stop->value=got;}return -1;}
        return 1;
    case 0x04978171u:
        if(!js_v06c_read8(m,0x92F02Eu,&got,stop)) return -1;
        if(got!=0xEEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F02Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F02Fu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F02Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F030u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F030u;stop->value=got;}return -1;}
        return 1;
    case 0x04978189u:
        if(!js_v06c_read8(m,0x92F031u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F031u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F032u,&got,stop)) return -1;
        if(got!=0x34u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F032u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F033u,&got,stop)) return -1;
        if(got!=0x12u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F033u;stop->value=got;}return -1;}
        return 1;
    case 0x049781A1u:
        if(!js_v06c_read8(m,0x92F034u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F034u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F035u,&got,stop)) return -1;
        if(got!=0x31u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F035u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F036u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F036u;stop->value=got;}return -1;}
        return 1;
    case 0x049781B9u:
        if(!js_v06c_read8(m,0x92F037u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F037u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F038u,&got,stop)) return -1;
        if(got!=0x33u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F038u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F039u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F039u;stop->value=got;}return -1;}
        return 1;
    case 0x049781D1u:
        if(!js_v06c_read8(m,0x92F03Au,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F03Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F03Bu,&got,stop)) return -1;
        if(got!=0x35u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F03Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F03Cu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F03Cu;stop->value=got;}return -1;}
        return 1;
    case 0x049781E9u:
        if(!js_v06c_read8(m,0x92F03Du,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F03Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F03Eu,&got,stop)) return -1;
        if(got!=0x78u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F03Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F03Fu,&got,stop)) return -1;
        if(got!=0x56u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F03Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04978201u:
        if(!js_v06c_read8(m,0x92F040u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F040u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F041u,&got,stop)) return -1;
        if(got!=0x37u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F041u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F042u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F042u;stop->value=got;}return -1;}
        return 1;
    case 0x04978219u:
        if(!js_v06c_read8(m,0x92F043u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F043u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F044u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F044u;stop->value=got;}return -1;}
        return 1;
    case 0x0497822Bu:
        if(!js_v06c_read8(m,0x92F045u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F045u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F046u,&got,stop)) return -1;
        if(got!=0x3Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F046u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F047u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F047u;stop->value=got;}return -1;}
        return 1;
    case 0x04978243u:
        if(!js_v06c_read8(m,0x92F048u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F048u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F049u,&got,stop)) return -1;
        if(got!=0x1Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F049u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F04Au,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F04Au;stop->value=got;}return -1;}
        return 1;
    case 0x0497825Bu:
        if(!js_v06c_read8(m,0x92F04Bu,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F04Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04978263u:
        if(!js_v06c_read8(m,0x92F04Cu,&got,stop)) return -1;
        if(got!=0x6Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F04Cu;stop->value=got;}return -1;}
        return 1;
    case 0x0497826Bu:
        if(!js_v06c_read8(m,0x92F04Du,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F04Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F04Eu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F04Eu;stop->value=got;}return -1;}
        return 1;
    case 0x04978278u:
        if(!js_v06c_read8(m,0x92F04Fu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F04Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F050u,&got,stop)) return -1;
        if(got!=0x34u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F050u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F051u,&got,stop)) return -1;
        if(got!=0x12u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F051u;stop->value=got;}return -1;}
        return 1;
    case 0x04978290u:
        if(!js_v06c_read8(m,0x92F052u,&got,stop)) return -1;
        if(got!=0x8Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F052u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F053u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F053u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F054u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F054u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F055u,&got,stop)) return -1;
        if(got!=0x70u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F055u;stop->value=got;}return -1;}
        return 1;
    case 0x049782B0u:
        if(!js_v06c_read8(m,0x92F056u,&got,stop)) return -1;
        if(got!=0xAFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F056u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F057u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F057u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F058u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F058u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F059u,&got,stop)) return -1;
        if(got!=0x70u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F059u;stop->value=got;}return -1;}
        return 1;
    case 0x049782D0u:
        if(!js_v06c_read8(m,0x92F05Au,&got,stop)) return -1;
        if(got!=0xC9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F05Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F05Bu,&got,stop)) return -1;
        if(got!=0x34u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F05Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F05Cu,&got,stop)) return -1;
        if(got!=0x12u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F05Cu;stop->value=got;}return -1;}
        return 1;
    case 0x049782E8u:
        if(!js_v06c_read8(m,0x92F05Du,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F05Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F05Eu,&got,stop)) return -1;
        if(got!=0x12u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F05Eu;stop->value=got;}return -1;}
        return 1;
    case 0x049782F8u:
        if(!js_v06c_read8(m,0x92F05Fu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F05Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F060u,&got,stop)) return -1;
        if(got!=0x78u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F060u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F061u,&got,stop)) return -1;
        if(got!=0x56u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F061u;stop->value=got;}return -1;}
        return 1;
    case 0x04978310u:
        if(!js_v06c_read8(m,0x92F062u,&got,stop)) return -1;
        if(got!=0x8Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F062u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F063u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F063u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F064u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F064u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F065u,&got,stop)) return -1;
        if(got!=0x70u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F065u;stop->value=got;}return -1;}
        return 1;
    case 0x04978330u:
        if(!js_v06c_read8(m,0x92F066u,&got,stop)) return -1;
        if(got!=0xAFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F066u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F067u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F067u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F068u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F068u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F069u,&got,stop)) return -1;
        if(got!=0x70u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F069u;stop->value=got;}return -1;}
        return 1;
    case 0x04978350u:
        if(!js_v06c_read8(m,0x92F06Au,&got,stop)) return -1;
        if(got!=0xC9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F06Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F06Bu,&got,stop)) return -1;
        if(got!=0x78u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F06Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F06Cu,&got,stop)) return -1;
        if(got!=0x56u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F06Cu;stop->value=got;}return -1;}
        return 1;
    case 0x04978368u:
        if(!js_v06c_read8(m,0x92F06Du,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F06Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F06Eu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F06Eu;stop->value=got;}return -1;}
        return 1;
    case 0x04978378u:
        if(!js_v06c_read8(m,0x92F06Fu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F06Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F070u,&got,stop)) return -1;
        if(got!=0xFEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F070u;stop->value=got;}return -1;}
        return 1;
    case 0x04978388u:
        if(!js_v06c_read8(m,0x92F071u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F071u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F072u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F072u;stop->value=got;}return -1;}
        return 1;
    case 0x0497839Bu:
        if(!js_v06c_read8(m,0x92F073u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F073u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F074u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F074u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F075u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F075u;stop->value=got;}return -1;}
        return 1;
    case 0x049783B3u:
        if(!js_v06c_read8(m,0x92F076u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F076u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F077u,&got,stop)) return -1;
        if(got!=0x81u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F077u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F078u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F078u;stop->value=got;}return -1;}
        return 1;
    case 0x049783CBu:
        if(!js_v06c_read8(m,0x92F079u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F079u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F07Au,&got,stop)) return -1;
        if(got!=0x3Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F07Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F07Bu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F07Bu;stop->value=got;}return -1;}
        return 1;
    case 0x049783E3u:
        if(!js_v06c_read8(m,0x92F07Cu,&got,stop)) return -1;
        if(got!=0x89u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F07Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F07Du,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F07Du;stop->value=got;}return -1;}
        return 1;
    case 0x049783F3u:
        if(!js_v06c_read8(m,0x92F07Eu,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F07Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F07Fu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F07Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04978403u:
        if(!js_v06c_read8(m,0x92F080u,&got,stop)) return -1;
        if(got!=0xEEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F080u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F081u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F081u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F082u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F082u;stop->value=got;}return -1;}
        return 1;
    case 0x0497841Bu:
        if(!js_v06c_read8(m,0x92F083u,&got,stop)) return -1;
        if(got!=0x6Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F083u;stop->value=got;}return -1;}
        return 1;
    default: return 0;
    }
}
