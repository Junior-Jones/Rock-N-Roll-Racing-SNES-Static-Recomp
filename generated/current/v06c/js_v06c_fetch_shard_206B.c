#include "js_v06c_fetch.h"

int js_v06c_fetch_shard_206B(JSV06Machine *m, JSV06Stop *stop) {
    uint8_t got;
    switch(js_cpu_context_key(&m->cpu)) {
    case 0x040D6203u:
        if(!js_v06c_read8(m,0x81AC40u,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC40u;stop->value=got;}return -1;}
        return 1;
    case 0x040D620Bu:
        if(!js_v06c_read8(m,0x81AC41u,&got,stop)) return -1;
        if(got!=0x4Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC41u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6213u:
        if(!js_v06c_read8(m,0x81AC42u,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC42u;stop->value=got;}return -1;}
        return 1;
    case 0x040D621Bu:
        if(!js_v06c_read8(m,0x81AC43u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC43u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC44u,&got,stop)) return -1;
        if(got!=0x48u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC44u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC45u,&got,stop)) return -1;
        if(got!=0xACu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC45u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6243u:
        if(!js_v06c_read8(m,0x81AC48u,&got,stop)) return -1;
        if(got!=0xDAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC48u;stop->value=got;}return -1;}
        return 1;
    case 0x040D624Bu:
        if(!js_v06c_read8(m,0x81AC49u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC49u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC4Au,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC4Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC4Bu,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC4Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040D6263u:
        if(!js_v06c_read8(m,0x81AC4Cu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC4Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC4Du,&got,stop)) return -1;
        if(got!=0xB1u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC4Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC4Eu,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC4Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040D627Bu:
        if(!js_v06c_read8(m,0x81AC4Fu,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC4Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040D6283u:
        if(!js_v06c_read8(m,0x81AC50u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC50u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC51u,&got,stop)) return -1;
        if(got!=0x06u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC51u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6293u:
        if(!js_v06c_read8(m,0x81AC52u,&got,stop)) return -1;
        if(got!=0xCAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC52u;stop->value=got;}return -1;}
        return 1;
    case 0x040D629Bu:
        if(!js_v06c_read8(m,0x81AC53u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC53u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC54u,&got,stop)) return -1;
        if(got!=0x36u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC54u;stop->value=got;}return -1;}
        return 1;
    case 0x040D62ABu:
        if(!js_v06c_read8(m,0x81AC55u,&got,stop)) return -1;
        if(got!=0x82u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC55u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC56u,&got,stop)) return -1;
        if(got!=0x8Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC56u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC57u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC57u;stop->value=got;}return -1;}
        return 1;
    case 0x040D62C3u:
        if(!js_v06c_read8(m,0x81AC58u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC58u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC59u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC59u;stop->value=got;}return -1;}
        return 1;
    case 0x040D62D0u:
        if(!js_v06c_read8(m,0x81AC5Au,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC5Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC5Bu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC5Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC5Cu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC5Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040D62E8u:
        if(!js_v06c_read8(m,0x81AC5Du,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC5Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC5Eu,&got,stop)) return -1;
        if(got!=0x0Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC5Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040D62F8u:
        if(!js_v06c_read8(m,0x81AC5Fu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC5Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC60u,&got,stop)) return -1;
        if(got!=0x76u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC60u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC61u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC61u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6310u:
        if(!js_v06c_read8(m,0x81AC62u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC62u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC63u,&got,stop)) return -1;
        if(got!=0x75u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC63u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC64u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC64u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6328u:
        if(!js_v06c_read8(m,0x81AC65u,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC65u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC66u,&got,stop)) return -1;
        if(got!=0x3Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC66u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC67u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC67u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6340u:
        if(!js_v06c_read8(m,0x81AC68u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC68u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC69u,&got,stop)) return -1;
        if(got!=0x29u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC69u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC6Au,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC6Au;stop->value=got;}return -1;}
        return 1;
    case 0x040D6358u:
        if(!js_v06c_read8(m,0x81AC6Bu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC6Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC6Cu,&got,stop)) return -1;
        if(got!=0x39u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC6Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC6Du,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC6Du;stop->value=got;}return -1;}
        return 1;
    case 0x040D6370u:
        if(!js_v06c_read8(m,0x81AC6Eu,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC6Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC6Fu,&got,stop)) return -1;
        if(got!=0x38u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC6Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC70u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC70u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6388u:
        if(!js_v06c_read8(m,0x81AC71u,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC71u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC72u,&got,stop)) return -1;
        if(got!=0x3Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC72u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC73u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC73u;stop->value=got;}return -1;}
        return 1;
    case 0x040D63A0u:
        if(!js_v06c_read8(m,0x81AC74u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC74u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC75u,&got,stop)) return -1;
        if(got!=0x29u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC75u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC76u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC76u;stop->value=got;}return -1;}
        return 1;
    case 0x040D63B8u:
        if(!js_v06c_read8(m,0x81AC77u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC77u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC78u,&got,stop)) return -1;
        if(got!=0x76u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC78u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC79u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC79u;stop->value=got;}return -1;}
        return 1;
    case 0x040D63D0u:
        if(!js_v06c_read8(m,0x81AC7Au,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC7Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC7Bu,&got,stop)) return -1;
        if(got!=0x75u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC7Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC7Cu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC7Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040D63E8u:
        if(!js_v06c_read8(m,0x81AC7Du,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC7Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC7Eu,&got,stop)) return -1;
        if(got!=0x77u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC7Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC7Fu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC7Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040D6400u:
        if(!js_v06c_read8(m,0x81AC80u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC80u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC81u,&got,stop)) return -1;
        if(got!=0x29u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC81u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC82u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC82u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6418u:
        if(!js_v06c_read8(m,0x81AC83u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC83u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC84u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC84u;stop->value=got;}return -1;}
        return 1;
    case 0x040D642Bu:
        if(!js_v06c_read8(m,0x81AC85u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC85u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC86u,&got,stop)) return -1;
        if(got!=0xA6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC86u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC87u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC87u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6443u:
        if(!js_v06c_read8(m,0x81AC88u,&got,stop)) return -1;
        if(got!=0x4Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC88u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC89u,&got,stop)) return -1;
        if(got!=0x54u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC89u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC8Au,&got,stop)) return -1;
        if(got!=0xF4u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC8Au;stop->value=got;}return -1;}
        return 1;
    case 0x040D645Bu:
        if(!js_v06c_read8(m,0x81AC8Bu,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC8Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC8Cu,&got,stop)) return -1;
        if(got!=0x1Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC8Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC8Du,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC8Du;stop->value=got;}return -1;}
        return 1;
    case 0x040D6473u:
        if(!js_v06c_read8(m,0x81AC8Eu,&got,stop)) return -1;
        if(got!=0x0Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC8Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC8Fu,&got,stop)) return -1;
        if(got!=0x1Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC8Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC90u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC90u;stop->value=got;}return -1;}
        return 1;
    case 0x040D648Bu:
        if(!js_v06c_read8(m,0x81AC91u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC91u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC92u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC92u;stop->value=got;}return -1;}
        return 1;
    case 0x040D649Bu:
        if(!js_v06c_read8(m,0x81AC93u,&got,stop)) return -1;
        if(got!=0x4Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC93u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC94u,&got,stop)) return -1;
        if(got!=0x19u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC94u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC95u,&got,stop)) return -1;
        if(got!=0xBAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC95u;stop->value=got;}return -1;}
        return 1;
    case 0x040D64B3u:
        if(!js_v06c_read8(m,0x81AC96u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC96u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC97u,&got,stop)) return -1;
        if(got!=0x1Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC97u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC98u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC98u;stop->value=got;}return -1;}
        return 1;
    case 0x040D64CBu:
        if(!js_v06c_read8(m,0x81AC99u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC99u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC9Au,&got,stop)) return -1;
        if(got!=0x3Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC9Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC9Bu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC9Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040D64E3u:
        if(!js_v06c_read8(m,0x81AC9Cu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC9Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC9Du,&got,stop)) return -1;
        if(got!=0x57u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC9Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AC9Eu,&got,stop)) return -1;
        if(got!=0xA5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AC9Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040D6723u:
        if(!js_v06c_read8(m,0x81ACE4u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ACE4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ACE5u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ACE5u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6733u:
        if(!js_v06c_read8(m,0x81ACE6u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ACE6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ACE7u,&got,stop)) return -1;
        if(got!=0x76u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ACE7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ACE8u,&got,stop)) return -1;
        if(got!=0xAEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ACE8u;stop->value=got;}return -1;}
        return 1;
    case 0x040D674Bu:
        if(!js_v06c_read8(m,0x81ACE9u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ACE9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ACEAu,&got,stop)) return -1;
        if(got!=0x2Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ACEAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ACEBu,&got,stop)) return -1;
        if(got!=0xAFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ACEBu;stop->value=got;}return -1;}
        return 1;
    case 0x040D6763u:
        if(!js_v06c_read8(m,0x81ACECu,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ACECu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ACEDu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ACEDu;stop->value=got;}return -1;}
        return 1;
    case 0x040D6773u:
        if(!js_v06c_read8(m,0x81ACEEu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ACEEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ACEFu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ACEFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ACF0u,&got,stop)) return -1;
        if(got!=0xAEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ACF0u;stop->value=got;}return -1;}
        return 1;
    case 0x040D678Bu:
        if(!js_v06c_read8(m,0x81ACF1u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ACF1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ACF2u,&got,stop)) return -1;
        if(got!=0x99u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ACF2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ACF3u,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ACF3u;stop->value=got;}return -1;}
        return 1;
    case 0x040D67A3u:
        if(!js_v06c_read8(m,0x81ACF4u,&got,stop)) return -1;
        if(got!=0x90u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ACF4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ACF5u,&got,stop)) return -1;
        if(got!=0x0Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ACF5u;stop->value=got;}return -1;}
        return 1;
    case 0x040D67B3u:
        if(!js_v06c_read8(m,0x81ACF6u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ACF6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ACF7u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ACF7u;stop->value=got;}return -1;}
        return 1;
    case 0x040D67C3u:
        if(!js_v06c_read8(m,0x81ACF8u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ACF8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ACF9u,&got,stop)) return -1;
        if(got!=0x76u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ACF9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ACFAu,&got,stop)) return -1;
        if(got!=0xAEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ACFAu;stop->value=got;}return -1;}
        return 1;
    case 0x040D67DBu:
        if(!js_v06c_read8(m,0x81ACFBu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ACFBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ACFCu,&got,stop)) return -1;
        if(got!=0x2Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ACFCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ACFDu,&got,stop)) return -1;
        if(got!=0xAFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ACFDu;stop->value=got;}return -1;}
        return 1;
    case 0x040D67F3u:
        if(!js_v06c_read8(m,0x81ACFEu,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ACFEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ACFFu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ACFFu;stop->value=got;}return -1;}
        return 1;
    case 0x040D6803u:
        if(!js_v06c_read8(m,0x81AD00u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD00u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD01u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD01u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD02u,&got,stop)) return -1;
        if(got!=0xAEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD02u;stop->value=got;}return -1;}
        return 1;
    case 0x040D681Bu:
        if(!js_v06c_read8(m,0x81AD03u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD03u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD04u,&got,stop)) return -1;
        if(got!=0x61u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD04u;stop->value=got;}return -1;}
        return 1;
    case 0x040D682Bu:
        if(!js_v06c_read8(m,0x81AD05u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD05u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD06u,&got,stop)) return -1;
        if(got!=0xB1u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD06u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD07u,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD07u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6843u:
        if(!js_v06c_read8(m,0x81AD08u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD08u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD09u,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD09u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD0Au,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD0Au;stop->value=got;}return -1;}
        return 1;
    case 0x040D685Bu:
        if(!js_v06c_read8(m,0x81AD0Bu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD0Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD0Cu,&got,stop)) return -1;
        if(got!=0xF2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD0Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD0Du,&got,stop)) return -1;
        if(got!=0x0Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD0Du;stop->value=got;}return -1;}
        return 1;
    case 0x040D6873u:
        if(!js_v06c_read8(m,0x81AD0Eu,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD0Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD0Fu,&got,stop)) return -1;
        if(got!=0xA1u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD0Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD10u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD10u;stop->value=got;}return -1;}
        return 1;
    case 0x040D688Bu:
        if(!js_v06c_read8(m,0x81AD11u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD11u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD12u,&got,stop)) return -1;
        if(got!=0xF3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD12u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD13u,&got,stop)) return -1;
        if(got!=0x0Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD13u;stop->value=got;}return -1;}
        return 1;
    case 0x040D68A3u:
        if(!js_v06c_read8(m,0x81AD14u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD14u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD15u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD15u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD16u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD16u;stop->value=got;}return -1;}
        return 1;
    case 0x040D68BBu:
        if(!js_v06c_read8(m,0x81AD17u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD17u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD18u,&got,stop)) return -1;
        if(got!=0x2Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD18u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD19u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD19u;stop->value=got;}return -1;}
        return 1;
    case 0x040D68D3u:
        if(!js_v06c_read8(m,0x81AD1Au,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD1Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD1Bu,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD1Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD1Cu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD1Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040D68EBu:
        if(!js_v06c_read8(m,0x81AD1Du,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD1Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD1Eu,&got,stop)) return -1;
        if(got!=0x2Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD1Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD1Fu,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD1Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040D6903u:
        if(!js_v06c_read8(m,0x81AD20u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD20u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6948u:
        if(!js_v06c_read8(m,0x81AD29u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD29u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD2Au,&got,stop)) return -1;
        if(got!=0x88u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD2Au;stop->value=got;}return -1;}
        return 1;
    case 0x040D6958u:
        if(!js_v06c_read8(m,0x81AD2Bu,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD2Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD2Cu,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD2Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD2Du,&got,stop)) return -1;
        if(got!=0x0Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD2Du;stop->value=got;}return -1;}
        return 1;
    case 0x040D6970u:
        if(!js_v06c_read8(m,0x81AD2Eu,&got,stop)) return -1;
        if(got!=0x29u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD2Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD2Fu,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD2Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD30u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD30u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6988u:
        if(!js_v06c_read8(m,0x81AD31u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD31u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD32u,&got,stop)) return -1;
        if(got!=0x41u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD32u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6998u:
        if(!js_v06c_read8(m,0x81AD33u,&got,stop)) return -1;
        if(got!=0xA5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD33u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD34u,&got,stop)) return -1;
        if(got!=0x88u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD34u;stop->value=got;}return -1;}
        return 1;
    case 0x040D69A8u:
        if(!js_v06c_read8(m,0x81AD35u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD35u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD36u,&got,stop)) return -1;
        if(got!=0x72u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD36u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AD37u,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD37u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6BA0u:
        if(!js_v06c_read8(m,0x81AD74u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AD74u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6D33u:
        if(!js_v06c_read8(m,0x81ADA6u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADA6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADA7u,&got,stop)) return -1;
        if(got!=0x99u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADA7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADA8u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADA8u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6D4Bu:
        if(!js_v06c_read8(m,0x81ADA9u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADA9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADAAu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADAAu;stop->value=got;}return -1;}
        return 1;
    case 0x040D6D5Bu:
        if(!js_v06c_read8(m,0x81ADABu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADABu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADACu,&got,stop)) return -1;
        if(got!=0x9Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADACu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADADu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADADu;stop->value=got;}return -1;}
        return 1;
    case 0x040D6D73u:
        if(!js_v06c_read8(m,0x81ADAEu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADAEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADAFu,&got,stop)) return -1;
        if(got!=0x9Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADAFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADB0u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADB0u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6D8Bu:
        if(!js_v06c_read8(m,0x81ADB1u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADB1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADB2u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADB2u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6D9Bu:
        if(!js_v06c_read8(m,0x81ADB3u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADB3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADB4u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADB4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADB5u,&got,stop)) return -1;
        if(got!=0x0Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADB5u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6DB3u:
        if(!js_v06c_read8(m,0x81ADB6u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADB6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADB7u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADB7u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6DC1u:
        if(!js_v06c_read8(m,0x81ADB8u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADB8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADB9u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADB9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADBAu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADBAu;stop->value=got;}return -1;}
        return 1;
    case 0x040D6DD9u:
        if(!js_v06c_read8(m,0x81ADBBu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADBBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADBCu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADBCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADBDu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADBDu;stop->value=got;}return -1;}
        return 1;
    case 0x040D6DF1u:
        if(!js_v06c_read8(m,0x81ADBEu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADBEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADBFu,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADBFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADC0u,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADC0u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6E09u:
        if(!js_v06c_read8(m,0x81ADC1u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADC1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADC2u,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADC2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADC3u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADC3u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6E21u:
        if(!js_v06c_read8(m,0x81ADC4u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADC4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADC5u,&got,stop)) return -1;
        if(got!=0x04u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADC5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADC6u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADC6u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6E39u:
        if(!js_v06c_read8(m,0x81ADC7u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADC7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADC8u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADC8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADC9u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADC9u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6E51u:
        if(!js_v06c_read8(m,0x81ADCAu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADCAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADCBu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADCBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADCCu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADCCu;stop->value=got;}return -1;}
        return 1;
    case 0x040D6E69u:
        if(!js_v06c_read8(m,0x81ADCDu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADCDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADCEu,&got,stop)) return -1;
        if(got!=0x33u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADCEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADCFu,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADCFu;stop->value=got;}return -1;}
        return 1;
    case 0x040D6E81u:
        if(!js_v06c_read8(m,0x81ADD0u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADD0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADD1u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADD1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADD2u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADD2u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6E99u:
        if(!js_v06c_read8(m,0x81ADD3u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADD3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADD4u,&got,stop)) return -1;
        if(got!=0x37u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADD4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADD5u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADD5u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6EB1u:
        if(!js_v06c_read8(m,0x81ADD6u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADD6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADD7u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADD7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADD8u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADD8u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6EC9u:
        if(!js_v06c_read8(m,0x81ADD9u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADD9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADDAu,&got,stop)) return -1;
        if(got!=0x3Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADDAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADDBu,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADDBu;stop->value=got;}return -1;}
        return 1;
    case 0x040D6EE1u:
        if(!js_v06c_read8(m,0x81ADDCu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADDCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADDDu,&got,stop)) return -1;
        if(got!=0xF6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADDDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADDEu,&got,stop)) return -1;
        if(got!=0x0Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADDEu;stop->value=got;}return -1;}
        return 1;
    case 0x040D6EF9u:
        if(!js_v06c_read8(m,0x81ADDFu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADDFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADE0u,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADE0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADE1u,&got,stop)) return -1;
        if(got!=0x0Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADE1u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6F11u:
        if(!js_v06c_read8(m,0x81ADE2u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADE2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADE3u,&got,stop)) return -1;
        if(got!=0xFEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADE3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADE4u,&got,stop)) return -1;
        if(got!=0x0Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADE4u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6F29u:
        if(!js_v06c_read8(m,0x81ADE5u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADE5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADE6u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADE6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADE7u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADE7u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6F41u:
        if(!js_v06c_read8(m,0x81ADE8u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADE8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADE9u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADE9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADEAu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADEAu;stop->value=got;}return -1;}
        return 1;
    case 0x040D6F59u:
        if(!js_v06c_read8(m,0x81ADEBu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADEBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADECu,&got,stop)) return -1;
        if(got!=0x6Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADECu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADEDu,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADEDu;stop->value=got;}return -1;}
        return 1;
    case 0x040D6F71u:
        if(!js_v06c_read8(m,0x81ADEEu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADEEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADEFu,&got,stop)) return -1;
        if(got!=0x73u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADEFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADF0u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADF0u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6F89u:
        if(!js_v06c_read8(m,0x81ADF1u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADF1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADF2u,&got,stop)) return -1;
        if(got!=0x77u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADF2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADF3u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADF3u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6FA1u:
        if(!js_v06c_read8(m,0x81ADF4u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADF4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADF5u,&got,stop)) return -1;
        if(got!=0x7Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADF5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADF6u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADF6u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6FB9u:
        if(!js_v06c_read8(m,0x81ADF7u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADF7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADF8u,&got,stop)) return -1;
        if(got!=0x7Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADF8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADF9u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADF9u;stop->value=got;}return -1;}
        return 1;
    case 0x040D6FD1u:
        if(!js_v06c_read8(m,0x81ADFAu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADFAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADFBu,&got,stop)) return -1;
        if(got!=0x83u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADFBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADFCu,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADFCu;stop->value=got;}return -1;}
        return 1;
    case 0x040D6FE9u:
        if(!js_v06c_read8(m,0x81ADFDu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADFDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADFEu,&got,stop)) return -1;
        if(got!=0x87u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADFEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81ADFFu,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81ADFFu;stop->value=got;}return -1;}
        return 1;
    case 0x040D7001u:
        if(!js_v06c_read8(m,0x81AE00u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE00u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE01u,&got,stop)) return -1;
        if(got!=0x87u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE01u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE02u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE02u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7019u:
        if(!js_v06c_read8(m,0x81AE03u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE03u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE04u,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE04u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE05u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE05u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7031u:
        if(!js_v06c_read8(m,0x81AE06u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE06u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE07u,&got,stop)) return -1;
        if(got!=0xA8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE07u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE08u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE08u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7049u:
        if(!js_v06c_read8(m,0x81AE09u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE09u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE0Au,&got,stop)) return -1;
        if(got!=0xACu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE0Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE0Bu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE0Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040D7061u:
        if(!js_v06c_read8(m,0x81AE0Cu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE0Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE0Du,&got,stop)) return -1;
        if(got!=0xAEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE0Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE0Eu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE0Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040D7079u:
        if(!js_v06c_read8(m,0x81AE0Fu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE0Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE10u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE10u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE11u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE11u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7091u:
        if(!js_v06c_read8(m,0x81AE12u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE12u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE13u,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE13u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE14u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE14u;stop->value=got;}return -1;}
        return 1;
    case 0x040D70A9u:
        if(!js_v06c_read8(m,0x81AE15u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE15u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE16u,&got,stop)) return -1;
        if(got!=0x0Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE16u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE17u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE17u;stop->value=got;}return -1;}
        return 1;
    case 0x040D70C1u:
        if(!js_v06c_read8(m,0x81AE18u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE18u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE19u,&got,stop)) return -1;
        if(got!=0x06u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE19u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE1Au,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE1Au;stop->value=got;}return -1;}
        return 1;
    case 0x040D70D9u:
        if(!js_v06c_read8(m,0x81AE1Bu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE1Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE1Cu,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE1Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE1Du,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE1Du;stop->value=got;}return -1;}
        return 1;
    case 0x040D70F1u:
        if(!js_v06c_read8(m,0x81AE1Eu,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE1Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE1Fu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE1Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040D7103u:
        if(!js_v06c_read8(m,0x81AE20u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE20u;stop->value=got;}return -1;}
        return 1;
    case 0x040D710Bu:
        if(!js_v06c_read8(m,0x81AE21u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE21u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE22u,&got,stop)) return -1;
        if(got!=0x1Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE22u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE23u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE23u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7123u:
        if(!js_v06c_read8(m,0x81AE24u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE24u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE25u,&got,stop)) return -1;
        if(got!=0x4Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE25u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7133u:
        if(!js_v06c_read8(m,0x81AE26u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE26u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE27u,&got,stop)) return -1;
        if(got!=0xB5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE27u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE28u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE28u;stop->value=got;}return -1;}
        return 1;
    case 0x040D714Bu:
        if(!js_v06c_read8(m,0x81AE29u,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE29u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE2Au,&got,stop)) return -1;
        if(got!=0x83u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE2Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE2Bu,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE2Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040D7163u:
        if(!js_v06c_read8(m,0x81AE2Cu,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE2Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE2Du,&got,stop)) return -1;
        if(got!=0xB6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE2Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE2Eu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE2Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040D717Bu:
        if(!js_v06c_read8(m,0x81AE2Fu,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE2Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE30u,&got,stop)) return -1;
        if(got!=0x7Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE30u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE31u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE31u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7193u:
        if(!js_v06c_read8(m,0x81AE32u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE32u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE33u,&got,stop)) return -1;
        if(got!=0xB7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE33u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE34u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE34u;stop->value=got;}return -1;}
        return 1;
    case 0x040D71ABu:
        if(!js_v06c_read8(m,0x81AE35u,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE35u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE36u,&got,stop)) return -1;
        if(got!=0x7Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE36u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE37u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE37u;stop->value=got;}return -1;}
        return 1;
    case 0x040D71C3u:
        if(!js_v06c_read8(m,0x81AE38u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE38u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE39u,&got,stop)) return -1;
        if(got!=0xB8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE39u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE3Au,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE3Au;stop->value=got;}return -1;}
        return 1;
    case 0x040D71DBu:
        if(!js_v06c_read8(m,0x81AE3Bu,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE3Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE3Cu,&got,stop)) return -1;
        if(got!=0x73u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE3Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE3Du,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE3Du;stop->value=got;}return -1;}
        return 1;
    case 0x040D71F3u:
        if(!js_v06c_read8(m,0x81AE3Eu,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE3Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE3Fu,&got,stop)) return -1;
        if(got!=0xB9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE3Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE40u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE40u;stop->value=got;}return -1;}
        return 1;
    case 0x040D720Bu:
        if(!js_v06c_read8(m,0x81AE41u,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE41u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE42u,&got,stop)) return -1;
        if(got!=0x77u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE42u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE43u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE43u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7223u:
        if(!js_v06c_read8(m,0x81AE44u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE44u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE45u,&got,stop)) return -1;
        if(got!=0xBAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE45u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE46u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE46u;stop->value=got;}return -1;}
        return 1;
    case 0x040D723Bu:
        if(!js_v06c_read8(m,0x81AE47u,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE47u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE48u,&got,stop)) return -1;
        if(got!=0x6Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE48u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE49u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE49u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7253u:
        if(!js_v06c_read8(m,0x81AE4Au,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE4Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE4Bu,&got,stop)) return -1;
        if(got!=0xBBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE4Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE4Cu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE4Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040D726Bu:
        if(!js_v06c_read8(m,0x81AE4Du,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE4Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE4Eu,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE4Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE4Fu,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE4Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040D7283u:
        if(!js_v06c_read8(m,0x81AE50u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE50u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE51u,&got,stop)) return -1;
        if(got!=0xBCu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE51u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE52u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE52u;stop->value=got;}return -1;}
        return 1;
    case 0x040D729Bu:
        if(!js_v06c_read8(m,0x81AE53u,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE53u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE54u,&got,stop)) return -1;
        if(got!=0x87u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE54u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE55u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE55u;stop->value=got;}return -1;}
        return 1;
    case 0x040D72B3u:
        if(!js_v06c_read8(m,0x81AE56u,&got,stop)) return -1;
        if(got!=0xACu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE56u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE57u,&got,stop)) return -1;
        if(got!=0xBDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE57u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE58u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE58u;stop->value=got;}return -1;}
        return 1;
    case 0x040D72CBu:
        if(!js_v06c_read8(m,0x81AE59u,&got,stop)) return -1;
        if(got!=0xB9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE59u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE5Au,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE5Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE5Bu,&got,stop)) return -1;
        if(got!=0xAFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE5Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040D72E3u:
        if(!js_v06c_read8(m,0x81AE5Cu,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE5Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE5Du,&got,stop)) return -1;
        if(got!=0x33u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE5Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE5Eu,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE5Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040D72FBu:
        if(!js_v06c_read8(m,0x81AE5Fu,&got,stop)) return -1;
        if(got!=0xACu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE5Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE60u,&got,stop)) return -1;
        if(got!=0xBEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE60u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE61u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE61u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7313u:
        if(!js_v06c_read8(m,0x81AE62u,&got,stop)) return -1;
        if(got!=0xB9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE62u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE63u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE63u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE64u,&got,stop)) return -1;
        if(got!=0xAFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE64u;stop->value=got;}return -1;}
        return 1;
    case 0x040D732Bu:
        if(!js_v06c_read8(m,0x81AE65u,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE65u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE66u,&got,stop)) return -1;
        if(got!=0x37u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE66u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE67u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE67u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7343u:
        if(!js_v06c_read8(m,0x81AE68u,&got,stop)) return -1;
        if(got!=0xACu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE68u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE69u,&got,stop)) return -1;
        if(got!=0xBFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE69u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE6Au,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE6Au;stop->value=got;}return -1;}
        return 1;
    case 0x040D735Bu:
        if(!js_v06c_read8(m,0x81AE6Bu,&got,stop)) return -1;
        if(got!=0xB9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE6Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE6Cu,&got,stop)) return -1;
        if(got!=0x26u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE6Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE6Du,&got,stop)) return -1;
        if(got!=0xAFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE6Du;stop->value=got;}return -1;}
        return 1;
    case 0x040D7373u:
        if(!js_v06c_read8(m,0x81AE6Eu,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE6Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE6Fu,&got,stop)) return -1;
        if(got!=0x3Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE6Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE70u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE70u;stop->value=got;}return -1;}
        return 1;
    case 0x040D738Bu:
        if(!js_v06c_read8(m,0x81AE71u,&got,stop)) return -1;
        if(got!=0x8Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE71u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7393u:
        if(!js_v06c_read8(m,0x81AE72u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE72u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE73u,&got,stop)) return -1;
        if(got!=0x7Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE73u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE74u,&got,stop)) return -1;
        if(got!=0xB6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE74u;stop->value=got;}return -1;}
        return 1;
    case 0x040D73ABu:
        if(!js_v06c_read8(m,0x81AE75u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE75u;stop->value=got;}return -1;}
        return 1;
    case 0x040D73B3u:
        if(!js_v06c_read8(m,0x81AE76u,&got,stop)) return -1;
        if(got!=0x8Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE76u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE77u,&got,stop)) return -1;
        if(got!=0x3Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE77u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE78u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE78u;stop->value=got;}return -1;}
        return 1;
    case 0x040D73CBu:
        if(!js_v06c_read8(m,0x81AE79u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE79u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE7Au,&got,stop)) return -1;
        if(got!=0xB7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE7Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE7Bu,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE7Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040D73E3u:
        if(!js_v06c_read8(m,0x81AE7Cu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE7Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE7Du,&got,stop)) return -1;
        if(got!=0xB9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE7Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE7Eu,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE7Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040D73FBu:
        if(!js_v06c_read8(m,0x81AE7Fu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE7Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE80u,&got,stop)) return -1;
        if(got!=0xBAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE80u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE81u,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE81u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7413u:
        if(!js_v06c_read8(m,0x81AE82u,&got,stop)) return -1;
        if(got!=0xBDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE82u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE83u,&got,stop)) return -1;
        if(got!=0xA8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE83u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE84u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE84u;stop->value=got;}return -1;}
        return 1;
    case 0x040D742Bu:
        if(!js_v06c_read8(m,0x81AE85u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE85u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE86u,&got,stop)) return -1;
        if(got!=0xAAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE86u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE87u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE87u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7443u:
        if(!js_v06c_read8(m,0x81AE88u,&got,stop)) return -1;
        if(got!=0xACu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE88u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE89u,&got,stop)) return -1;
        if(got!=0x99u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE89u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE8Au,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE8Au;stop->value=got;}return -1;}
        return 1;
    case 0x040D745Bu:
        if(!js_v06c_read8(m,0x81AE8Bu,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE8Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE8Cu,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE8Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE8Du,&got,stop)) return -1;
        if(got!=0x0Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE8Du;stop->value=got;}return -1;}
        return 1;
    case 0x040D7473u:
        if(!js_v06c_read8(m,0x81AE8Eu,&got,stop)) return -1;
        if(got!=0xC9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE8Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE8Fu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE8Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040D7483u:
        if(!js_v06c_read8(m,0x81AE90u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE90u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE91u,&got,stop)) return -1;
        if(got!=0x05u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE91u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7493u:
        if(!js_v06c_read8(m,0x81AE92u,&got,stop)) return -1;
        if(got!=0xB9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE92u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE93u,&got,stop)) return -1;
        if(got!=0x0Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE93u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE94u,&got,stop)) return -1;
        if(got!=0xAFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE94u;stop->value=got;}return -1;}
        return 1;
    case 0x040D74ABu:
        if(!js_v06c_read8(m,0x81AE95u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE95u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE96u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE96u;stop->value=got;}return -1;}
        return 1;
    case 0x040D74BBu:
        if(!js_v06c_read8(m,0x81AE97u,&got,stop)) return -1;
        if(got!=0xB9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE97u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE98u,&got,stop)) return -1;
        if(got!=0x12u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE98u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE99u,&got,stop)) return -1;
        if(got!=0xAFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE99u;stop->value=got;}return -1;}
        return 1;
    case 0x040D74D3u:
        if(!js_v06c_read8(m,0x81AE9Au,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE9Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE9Bu,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE9Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE9Cu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE9Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040D74EBu:
        if(!js_v06c_read8(m,0x81AE9Du,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE9Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE9Eu,&got,stop)) return -1;
        if(got!=0xA7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE9Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AE9Fu,&got,stop)) return -1;
        if(got!=0xAEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AE9Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040D7503u:
        if(!js_v06c_read8(m,0x81AEA0u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEA0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEA1u,&got,stop)) return -1;
        if(got!=0xF3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEA1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEA2u,&got,stop)) return -1;
        if(got!=0xAEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEA2u;stop->value=got;}return -1;}
        return 1;
    case 0x040D751Bu:
        if(!js_v06c_read8(m,0x81AEA3u,&got,stop)) return -1;
        if(got!=0x8Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEA3u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7523u:
        if(!js_v06c_read8(m,0x81AEA4u,&got,stop)) return -1;
        if(got!=0x4Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEA4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEA5u,&got,stop)) return -1;
        if(got!=0x69u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEA5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEA6u,&got,stop)) return -1;
        if(got!=0xB6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEA6u;stop->value=got;}return -1;}
        return 1;
    case 0x040D753Bu:
        if(!js_v06c_read8(m,0x81AEA7u,&got,stop)) return -1;
        if(got!=0xBDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEA7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEA8u,&got,stop)) return -1;
        if(got!=0x83u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEA8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEA9u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEA9u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7553u:
        if(!js_v06c_read8(m,0x81AEAAu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEAAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEABu,&got,stop)) return -1;
        if(got!=0xB5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEABu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEACu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEACu;stop->value=got;}return -1;}
        return 1;
    case 0x040D756Bu:
        if(!js_v06c_read8(m,0x81AEADu,&got,stop)) return -1;
        if(got!=0xBDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEADu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEAEu,&got,stop)) return -1;
        if(got!=0x7Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEAEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEAFu,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEAFu;stop->value=got;}return -1;}
        return 1;
    case 0x040D7583u:
        if(!js_v06c_read8(m,0x81AEB0u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEB0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEB1u,&got,stop)) return -1;
        if(got!=0xB6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEB1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEB2u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEB2u;stop->value=got;}return -1;}
        return 1;
    case 0x040D759Bu:
        if(!js_v06c_read8(m,0x81AEB3u,&got,stop)) return -1;
        if(got!=0xBDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEB3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEB4u,&got,stop)) return -1;
        if(got!=0x7Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEB4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEB5u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEB5u;stop->value=got;}return -1;}
        return 1;
    case 0x040D75B3u:
        if(!js_v06c_read8(m,0x81AEB6u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEB6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEB7u,&got,stop)) return -1;
        if(got!=0xB7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEB7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEB8u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEB8u;stop->value=got;}return -1;}
        return 1;
    case 0x040D75CBu:
        if(!js_v06c_read8(m,0x81AEB9u,&got,stop)) return -1;
        if(got!=0xBDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEB9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEBAu,&got,stop)) return -1;
        if(got!=0x73u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEBAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEBBu,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEBBu;stop->value=got;}return -1;}
        return 1;
    case 0x040D75E3u:
        if(!js_v06c_read8(m,0x81AEBCu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEBCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEBDu,&got,stop)) return -1;
        if(got!=0xB8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEBDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEBEu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEBEu;stop->value=got;}return -1;}
        return 1;
    case 0x040D75FBu:
        if(!js_v06c_read8(m,0x81AEBFu,&got,stop)) return -1;
        if(got!=0xBDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEBFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEC0u,&got,stop)) return -1;
        if(got!=0x77u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEC0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEC1u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEC1u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7613u:
        if(!js_v06c_read8(m,0x81AEC2u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEC2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEC3u,&got,stop)) return -1;
        if(got!=0xB9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEC3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEC4u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEC4u;stop->value=got;}return -1;}
        return 1;
    case 0x040D762Bu:
        if(!js_v06c_read8(m,0x81AEC5u,&got,stop)) return -1;
        if(got!=0xBDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEC5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEC6u,&got,stop)) return -1;
        if(got!=0x6Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEC6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEC7u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEC7u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7643u:
        if(!js_v06c_read8(m,0x81AEC8u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEC8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEC9u,&got,stop)) return -1;
        if(got!=0xBAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEC9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AECAu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AECAu;stop->value=got;}return -1;}
        return 1;
    case 0x040D765Bu:
        if(!js_v06c_read8(m,0x81AECBu,&got,stop)) return -1;
        if(got!=0xBDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AECBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AECCu,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AECCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AECDu,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AECDu;stop->value=got;}return -1;}
        return 1;
    case 0x040D7673u:
        if(!js_v06c_read8(m,0x81AECEu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AECEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AECFu,&got,stop)) return -1;
        if(got!=0xBBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AECFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AED0u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AED0u;stop->value=got;}return -1;}
        return 1;
    case 0x040D768Bu:
        if(!js_v06c_read8(m,0x81AED1u,&got,stop)) return -1;
        if(got!=0xBDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AED1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AED2u,&got,stop)) return -1;
        if(got!=0x87u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AED2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AED3u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AED3u;stop->value=got;}return -1;}
        return 1;
    case 0x040D76A3u:
        if(!js_v06c_read8(m,0x81AED4u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AED4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AED5u,&got,stop)) return -1;
        if(got!=0xBCu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AED5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AED6u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AED6u;stop->value=got;}return -1;}
        return 1;
    case 0x040D76BBu:
        if(!js_v06c_read8(m,0x81AED7u,&got,stop)) return -1;
        if(got!=0xBCu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AED7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AED8u,&got,stop)) return -1;
        if(got!=0x33u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AED8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AED9u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AED9u;stop->value=got;}return -1;}
        return 1;
    case 0x040D76D3u:
        if(!js_v06c_read8(m,0x81AEDAu,&got,stop)) return -1;
        if(got!=0xB9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEDAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEDBu,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEDBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEDCu,&got,stop)) return -1;
        if(got!=0xAFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEDCu;stop->value=got;}return -1;}
        return 1;
    case 0x040D76EBu:
        if(!js_v06c_read8(m,0x81AEDDu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEDDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEDEu,&got,stop)) return -1;
        if(got!=0xBDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEDEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEDFu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEDFu;stop->value=got;}return -1;}
        return 1;
    case 0x040D7703u:
        if(!js_v06c_read8(m,0x81AEE0u,&got,stop)) return -1;
        if(got!=0xBCu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEE0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEE1u,&got,stop)) return -1;
        if(got!=0x37u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEE1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEE2u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEE2u;stop->value=got;}return -1;}
        return 1;
    case 0x040D771Bu:
        if(!js_v06c_read8(m,0x81AEE3u,&got,stop)) return -1;
        if(got!=0xB9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEE3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEE4u,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEE4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEE5u,&got,stop)) return -1;
        if(got!=0xAFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEE5u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7733u:
        if(!js_v06c_read8(m,0x81AEE6u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEE6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEE7u,&got,stop)) return -1;
        if(got!=0xBEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEE7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEE8u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEE8u;stop->value=got;}return -1;}
        return 1;
    case 0x040D774Bu:
        if(!js_v06c_read8(m,0x81AEE9u,&got,stop)) return -1;
        if(got!=0xBCu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEE9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEEAu,&got,stop)) return -1;
        if(got!=0x3Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEEAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEEBu,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEEBu;stop->value=got;}return -1;}
        return 1;
    case 0x040D7763u:
        if(!js_v06c_read8(m,0x81AEECu,&got,stop)) return -1;
        if(got!=0xB9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEECu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEEDu,&got,stop)) return -1;
        if(got!=0x1Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEEDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEEEu,&got,stop)) return -1;
        if(got!=0xAFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEEEu;stop->value=got;}return -1;}
        return 1;
    case 0x040D777Bu:
        if(!js_v06c_read8(m,0x81AEEFu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEEFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEF0u,&got,stop)) return -1;
        if(got!=0xBFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEF0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEF1u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEF1u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7793u:
        if(!js_v06c_read8(m,0x81AEF2u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEF2u;stop->value=got;}return -1;}
        return 1;
    case 0x040D779Bu:
        if(!js_v06c_read8(m,0x81AEF3u,&got,stop)) return -1;
        if(got!=0xBDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEF3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEF4u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEF4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEF5u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEF5u;stop->value=got;}return -1;}
        return 1;
    case 0x040D77B3u:
        if(!js_v06c_read8(m,0x81AEF6u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEF6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEF7u,&got,stop)) return -1;
        if(got!=0xB0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEF7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEF8u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEF8u;stop->value=got;}return -1;}
        return 1;
    case 0x040D77CBu:
        if(!js_v06c_read8(m,0x81AEF9u,&got,stop)) return -1;
        if(got!=0xBDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEF9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEFAu,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEFAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEFBu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEFBu;stop->value=got;}return -1;}
        return 1;
    case 0x040D77E3u:
        if(!js_v06c_read8(m,0x81AEFCu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEFCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEFDu,&got,stop)) return -1;
        if(got!=0xF2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEFDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AEFEu,&got,stop)) return -1;
        if(got!=0x0Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEFEu;stop->value=got;}return -1;}
        return 1;
    case 0x040D77FBu:
        if(!js_v06c_read8(m,0x81AEFFu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AEFFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF00u,&got,stop)) return -1;
        if(got!=0xF5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF00u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF01u,&got,stop)) return -1;
        if(got!=0x0Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF01u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7813u:
        if(!js_v06c_read8(m,0x81AF02u,&got,stop)) return -1;
        if(got!=0xBDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF02u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF03u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF03u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF04u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF04u;stop->value=got;}return -1;}
        return 1;
    case 0x040D782Bu:
        if(!js_v06c_read8(m,0x81AF05u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF05u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF06u,&got,stop)) return -1;
        if(got!=0x2Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF06u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF07u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF07u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7843u:
        if(!js_v06c_read8(m,0x81AF08u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF08u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF09u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF09u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF0Au,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF0Au;stop->value=got;}return -1;}
        return 1;
    case 0x040D785Bu:
        if(!js_v06c_read8(m,0x81AF0Bu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF0Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040D797Bu:
        if(!js_v06c_read8(m,0x81AF2Fu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF2Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF30u,&got,stop)) return -1;
        if(got!=0x41u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF30u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF31u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF31u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7993u:
        if(!js_v06c_read8(m,0x81AF32u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF32u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF33u,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF33u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF34u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF34u;stop->value=got;}return -1;}
        return 1;
    case 0x040D79ABu:
        if(!js_v06c_read8(m,0x81AF35u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF35u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF36u,&got,stop)) return -1;
        if(got!=0x1Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF36u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF37u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF37u;stop->value=got;}return -1;}
        return 1;
    case 0x040D79C3u:
        if(!js_v06c_read8(m,0x81AF38u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF38u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF39u,&got,stop)) return -1;
        if(got!=0x06u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF39u;stop->value=got;}return -1;}
        return 1;
    case 0x040D79D3u:
        if(!js_v06c_read8(m,0x81AF3Au,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF3Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF3Bu,&got,stop)) return -1;
        if(got!=0x3Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF3Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF3Cu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF3Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040D79EBu:
        if(!js_v06c_read8(m,0x81AF3Du,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF3Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF3Eu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF3Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040D79FBu:
        if(!js_v06c_read8(m,0x81AF3Fu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF3Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040D7A03u:
        if(!js_v06c_read8(m,0x81AF40u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF40u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF41u,&got,stop)) return -1;
        if(got!=0x46u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF41u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF42u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF42u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7A1Bu:
        if(!js_v06c_read8(m,0x81AF43u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF43u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF44u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF44u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7A2Bu:
        if(!js_v06c_read8(m,0x81AF45u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF45u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF46u,&got,stop)) return -1;
        if(got!=0x5Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF46u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF47u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF47u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7A43u:
        if(!js_v06c_read8(m,0x81AF48u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF48u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF49u,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF49u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7A53u:
        if(!js_v06c_read8(m,0x81AF4Au,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF4Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF4Bu,&got,stop)) return -1;
        if(got!=0x5Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF4Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF4Cu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF4Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040D7A6Bu:
        if(!js_v06c_read8(m,0x81AF4Du,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF4Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF4Eu,&got,stop)) return -1;
        if(got!=0x09u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF4Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040D7A7Bu:
        if(!js_v06c_read8(m,0x81AF4Fu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF4Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF50u,&got,stop)) return -1;
        if(got!=0x09u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF50u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF51u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF51u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7A93u:
        if(!js_v06c_read8(m,0x81AF52u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF52u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF53u,&got,stop)) return -1;
        if(got!=0x81u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF53u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7AA3u:
        if(!js_v06c_read8(m,0x81AF54u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF54u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF55u,&got,stop)) return -1;
        if(got!=0xB1u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF55u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF56u,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF56u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7ABBu:
        if(!js_v06c_read8(m,0x81AF57u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF57u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF58u,&got,stop)) return -1;
        if(got!=0xCDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF58u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF59u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF59u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7AD3u:
        if(!js_v06c_read8(m,0x81AF5Au,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF5Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF5Bu,&got,stop)) return -1;
        if(got!=0xB7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF5Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF5Cu,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF5Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040D7AEBu:
        if(!js_v06c_read8(m,0x81AF5Du,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF5Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF5Eu,&got,stop)) return -1;
        if(got!=0xB8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF5Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF5Fu,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF5Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040D7B03u:
        if(!js_v06c_read8(m,0x81AF60u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF60u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF61u,&got,stop)) return -1;
        if(got!=0x0Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF61u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7B13u:
        if(!js_v06c_read8(m,0x81AF62u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF62u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF63u,&got,stop)) return -1;
        if(got!=0x1Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF63u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF64u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF64u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7B2Bu:
        if(!js_v06c_read8(m,0x81AF65u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF65u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF66u,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF66u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7B3Bu:
        if(!js_v06c_read8(m,0x81AF67u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF67u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF68u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF68u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF69u,&got,stop)) return -1;
        if(got!=0x0Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF69u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7B53u:
        if(!js_v06c_read8(m,0x81AF6Au,&got,stop)) return -1;
        if(got!=0xC9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF6Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF6Bu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF6Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040D7B63u:
        if(!js_v06c_read8(m,0x81AF6Cu,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF6Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF6Du,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF6Du;stop->value=got;}return -1;}
        return 1;
    case 0x040D7B73u:
        if(!js_v06c_read8(m,0x81AF6Eu,&got,stop)) return -1;
        if(got!=0xEEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF6Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF6Fu,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF6Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF70u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF70u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7B8Bu:
        if(!js_v06c_read8(m,0x81AF71u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF71u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF72u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF72u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7B98u:
        if(!js_v06c_read8(m,0x81AF73u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF73u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF74u,&got,stop)) return -1;
        if(got!=0x3Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF74u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF75u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF75u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7BB0u:
        if(!js_v06c_read8(m,0x81AF76u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF76u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF77u,&got,stop)) return -1;
        if(got!=0x9Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF77u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF78u,&got,stop)) return -1;
        if(got!=0x83u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF78u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF79u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF79u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7BD0u:
        if(!js_v06c_read8(m,0x81AF7Au,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF7Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF7Bu,&got,stop)) return -1;
        if(got!=0x3Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF7Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF7Cu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF7Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040D7BE8u:
        if(!js_v06c_read8(m,0x81AF7Du,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF7Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF7Eu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF7Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF7Fu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF7Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040D7C00u:
        if(!js_v06c_read8(m,0x81AF80u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF80u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF81u,&got,stop)) return -1;
        if(got!=0xF7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF81u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF82u,&got,stop)) return -1;
        if(got!=0x82u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF82u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF83u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF83u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7C20u:
        if(!js_v06c_read8(m,0x81AF84u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF84u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF85u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF85u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF86u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF86u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7C38u:
        if(!js_v06c_read8(m,0x81AF87u,&got,stop)) return -1;
        if(got!=0x8Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF87u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF88u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF88u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF89u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF89u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF8Au,&got,stop)) return -1;
        if(got!=0x7Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF8Au;stop->value=got;}return -1;}
        return 1;
    case 0x040D7C58u:
        if(!js_v06c_read8(m,0x81AF8Bu,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF8Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF8Cu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF8Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF8Du,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF8Du;stop->value=got;}return -1;}
        return 1;
    case 0x040D7C70u:
        if(!js_v06c_read8(m,0x81AF8Eu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF8Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF8Fu,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF8Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF90u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF90u;stop->value=got;}return -1;}
        return 1;
    case 0x040D7C88u:
        if(!js_v06c_read8(m,0x81AF91u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF91u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF92u,&got,stop)) return -1;
        if(got!=0x5Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF92u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF93u,&got,stop)) return -1;
        if(got!=0x83u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF93u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81AF94u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81AF94u;stop->value=got;}return -1;}
        return 1;
    default: return 0;
    }
}
