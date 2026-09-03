#include "js_v06c_fetch.h"

int js_v06c_fetch_shard_2067(JSV06Machine *m, JSV06Stop *stop) {
    uint8_t got;
    switch(js_cpu_context_key(&m->cpu)) {
    case 0x040CE233u:
        if(!js_v06c_read8(m,0x819C46u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C46u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C47u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C47u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE240u:
        if(!js_v06c_read8(m,0x819C48u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C48u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C49u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C49u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C4Au,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C4Au;stop->value=got;}return -1;}
        return 1;
    case 0x040CE258u:
        if(!js_v06c_read8(m,0x819C4Bu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C4Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C4Cu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C4Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C4Du,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C4Du;stop->value=got;}return -1;}
        return 1;
    case 0x040CE270u:
        if(!js_v06c_read8(m,0x819C4Eu,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C4Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C4Fu,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C4Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C50u,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C50u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE288u:
        if(!js_v06c_read8(m,0x819C51u,&got,stop)) return -1;
        if(got!=0xE8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C51u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE290u:
        if(!js_v06c_read8(m,0x819C52u,&got,stop)) return -1;
        if(got!=0xE8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C52u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE298u:
        if(!js_v06c_read8(m,0x819C53u,&got,stop)) return -1;
        if(got!=0x9Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C53u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C54u,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C54u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C55u,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C55u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE2B0u:
        if(!js_v06c_read8(m,0x819C56u,&got,stop)) return -1;
        if(got!=0xE8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C56u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE2B8u:
        if(!js_v06c_read8(m,0x819C57u,&got,stop)) return -1;
        if(got!=0xE8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C57u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE2C0u:
        if(!js_v06c_read8(m,0x819C58u,&got,stop)) return -1;
        if(got!=0xE0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C58u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C59u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C59u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C5Au,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C5Au;stop->value=got;}return -1;}
        return 1;
    case 0x040CE2D8u:
        if(!js_v06c_read8(m,0x819C5Bu,&got,stop)) return -1;
        if(got!=0x90u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C5Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C5Cu,&got,stop)) return -1;
        if(got!=0xF1u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C5Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040CE2E8u:
        if(!js_v06c_read8(m,0x819C5Du,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C5Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C5Eu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C5Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C5Fu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C5Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040CE300u:
        if(!js_v06c_read8(m,0x819C60u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C60u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C61u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C61u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C62u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C62u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE318u:
        if(!js_v06c_read8(m,0x819C63u,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C63u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C64u,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C64u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C65u,&got,stop)) return -1;
        if(got!=0x14u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C65u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE330u:
        if(!js_v06c_read8(m,0x819C66u,&got,stop)) return -1;
        if(got!=0xE8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C66u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE338u:
        if(!js_v06c_read8(m,0x819C67u,&got,stop)) return -1;
        if(got!=0xE8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C67u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE340u:
        if(!js_v06c_read8(m,0x819C68u,&got,stop)) return -1;
        if(got!=0xE0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C68u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C69u,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C69u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C6Au,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C6Au;stop->value=got;}return -1;}
        return 1;
    case 0x040CE358u:
        if(!js_v06c_read8(m,0x819C6Bu,&got,stop)) return -1;
        if(got!=0x90u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C6Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C6Cu,&got,stop)) return -1;
        if(got!=0xF6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C6Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040CE368u:
        if(!js_v06c_read8(m,0x819C6Du,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C6Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C6Eu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C6Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040CE37Bu:
        if(!js_v06c_read8(m,0x819C6Fu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C6Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C70u,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C70u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C71u,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C71u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE393u:
        if(!js_v06c_read8(m,0x819C72u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C72u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C73u,&got,stop)) return -1;
        if(got!=0x04u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C73u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE3A3u:
        if(!js_v06c_read8(m,0x819C74u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C74u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C75u,&got,stop)) return -1;
        if(got!=0x41u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C75u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C76u,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C76u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE3BBu:
        if(!js_v06c_read8(m,0x819C77u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C77u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C78u,&got,stop)) return -1;
        if(got!=0x7Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C78u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE3CBu:
        if(!js_v06c_read8(m,0x819C79u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C79u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C7Au,&got,stop)) return -1;
        if(got!=0x44u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C7Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C7Bu,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C7Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040CE3E3u:
        if(!js_v06c_read8(m,0x819C7Cu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C7Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C7Du,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C7Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C7Eu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C7Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040CE3FBu:
        if(!js_v06c_read8(m,0x819C7Fu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C7Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040CE463u:
        if(!js_v06c_read8(m,0x819C8Cu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C8Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C8Du,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C8Du;stop->value=got;}return -1;}
        return 1;
    case 0x040CE470u:
        if(!js_v06c_read8(m,0x819C8Eu,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C8Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C8Fu,&got,stop)) return -1;
        if(got!=0xFEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C8Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C90u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C90u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE488u:
        if(!js_v06c_read8(m,0x819C91u,&got,stop)) return -1;
        if(got!=0xB9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C91u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C92u,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C92u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C93u,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C93u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE4A0u:
        if(!js_v06c_read8(m,0x819C94u,&got,stop)) return -1;
        if(got!=0x99u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C94u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C95u,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C95u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C96u,&got,stop)) return -1;
        if(got!=0x16u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C96u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE4B8u:
        if(!js_v06c_read8(m,0x819C97u,&got,stop)) return -1;
        if(got!=0x88u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C97u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE4C0u:
        if(!js_v06c_read8(m,0x819C98u,&got,stop)) return -1;
        if(got!=0x88u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C98u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE4C8u:
        if(!js_v06c_read8(m,0x819C99u,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C99u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C9Au,&got,stop)) return -1;
        if(got!=0xF6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C9Au;stop->value=got;}return -1;}
        return 1;
    case 0x040CE4D8u:
        if(!js_v06c_read8(m,0x819C9Bu,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C9Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C9Cu,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C9Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C9Du,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C9Du;stop->value=got;}return -1;}
        return 1;
    case 0x040CE4F0u:
        if(!js_v06c_read8(m,0x819C9Eu,&got,stop)) return -1;
        if(got!=0xB9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C9Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819C9Fu,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819C9Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CA0u,&got,stop)) return -1;
        if(got!=0x14u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CA0u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE508u:
        if(!js_v06c_read8(m,0x819CA1u,&got,stop)) return -1;
        if(got!=0x99u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CA1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CA2u,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CA2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CA3u,&got,stop)) return -1;
        if(got!=0x17u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CA3u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE520u:
        if(!js_v06c_read8(m,0x819CA4u,&got,stop)) return -1;
        if(got!=0x88u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CA4u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE528u:
        if(!js_v06c_read8(m,0x819CA5u,&got,stop)) return -1;
        if(got!=0x88u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CA5u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE530u:
        if(!js_v06c_read8(m,0x819CA6u,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CA6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CA7u,&got,stop)) return -1;
        if(got!=0xF6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CA7u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE540u:
        if(!js_v06c_read8(m,0x819CA8u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CA8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CA9u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CA9u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE553u:
        if(!js_v06c_read8(m,0x819CAAu,&got,stop)) return -1;
        if(got!=0xEEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CAAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CABu,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CABu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CACu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CACu;stop->value=got;}return -1;}
        return 1;
    case 0x040CE56Bu:
        if(!js_v06c_read8(m,0x819CADu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CADu;stop->value=got;}return -1;}
        return 1;
    case 0x040CE5B3u:
        if(!js_v06c_read8(m,0x819CB6u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CB6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CB7u,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CB7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CB8u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CB8u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE5CBu:
        if(!js_v06c_read8(m,0x819CB9u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CB9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CBAu,&got,stop)) return -1;
        if(got!=0x36u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CBAu;stop->value=got;}return -1;}
        return 1;
    case 0x040CE5DBu:
        if(!js_v06c_read8(m,0x819CBBu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CBBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CBCu,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CBCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CBDu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CBDu;stop->value=got;}return -1;}
        return 1;
    case 0x040CE5F3u:
        if(!js_v06c_read8(m,0x819CBEu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CBEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CBFu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CBFu;stop->value=got;}return -1;}
        return 1;
    case 0x040CE600u:
        if(!js_v06c_read8(m,0x819CC0u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CC0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CC1u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CC1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CC2u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CC2u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE618u:
        if(!js_v06c_read8(m,0x819CC3u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CC3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CC4u,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CC4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CC5u,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CC5u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE630u:
        if(!js_v06c_read8(m,0x819CC6u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CC6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CC7u,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CC7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CC8u,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CC8u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE648u:
        if(!js_v06c_read8(m,0x819CC9u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CC9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CCAu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CCAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CCBu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CCBu;stop->value=got;}return -1;}
        return 1;
    case 0x040CE660u:
        if(!js_v06c_read8(m,0x819CCCu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CCCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CCDu,&got,stop)) return -1;
        if(got!=0x45u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CCDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CCEu,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CCEu;stop->value=got;}return -1;}
        return 1;
    case 0x040CE678u:
        if(!js_v06c_read8(m,0x819CCFu,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CCFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CD0u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CD0u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE68Bu:
        if(!js_v06c_read8(m,0x819CD1u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CD1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CD2u,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CD2u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE69Bu:
        if(!js_v06c_read8(m,0x819CD3u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CD3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CD4u,&got,stop)) return -1;
        if(got!=0x0Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CD4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CD5u,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CD5u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE6B3u:
        if(!js_v06c_read8(m,0x819CD6u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CD6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CD7u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CD7u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE6C0u:
        if(!js_v06c_read8(m,0x819CD8u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CD8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CD9u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CD9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CDAu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CDAu;stop->value=got;}return -1;}
        return 1;
    case 0x040CE6D8u:
        if(!js_v06c_read8(m,0x819CDBu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CDBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CDCu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CDCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CDDu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CDDu;stop->value=got;}return -1;}
        return 1;
    case 0x040CE6F0u:
        if(!js_v06c_read8(m,0x819CDEu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CDEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CDFu,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CDFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CE0u,&got,stop)) return -1;
        if(got!=0x14u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CE0u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE708u:
        if(!js_v06c_read8(m,0x819CE1u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CE1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CE2u,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CE2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CE3u,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CE3u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE720u:
        if(!js_v06c_read8(m,0x819CE4u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CE4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CE5u,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CE5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CE6u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CE6u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE738u:
        if(!js_v06c_read8(m,0x819CE7u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CE7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CE8u,&got,stop)) return -1;
        if(got!=0x45u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CE8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CE9u,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CE9u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE750u:
        if(!js_v06c_read8(m,0x819CEAu,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CEAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CEBu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CEBu;stop->value=got;}return -1;}
        return 1;
    case 0x040CE763u:
        if(!js_v06c_read8(m,0x819CECu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CECu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CEDu,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CEDu;stop->value=got;}return -1;}
        return 1;
    case 0x040CE773u:
        if(!js_v06c_read8(m,0x819CEEu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CEEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CEFu,&got,stop)) return -1;
        if(got!=0x0Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CEFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819CF0u,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CF0u;stop->value=got;}return -1;}
        return 1;
    case 0x040CE78Bu:
        if(!js_v06c_read8(m,0x819CF1u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819CF1u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEA03u:
        if(!js_v06c_read8(m,0x819D40u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D40u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D41u,&got,stop)) return -1;
        if(got!=0x15u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D41u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEA13u:
        if(!js_v06c_read8(m,0x819D42u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D42u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D43u,&got,stop)) return -1;
        if(got!=0x2Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D43u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D44u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D44u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEA2Bu:
        if(!js_v06c_read8(m,0x819D45u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D45u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D46u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D46u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEA3Bu:
        if(!js_v06c_read8(m,0x819D47u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D47u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D48u,&got,stop)) return -1;
        if(got!=0x15u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D48u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D49u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D49u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEA53u:
        if(!js_v06c_read8(m,0x819D4Au,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D4Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D4Bu,&got,stop)) return -1;
        if(got!=0x55u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D4Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D4Cu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D4Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040CEA6Bu:
        if(!js_v06c_read8(m,0x819D4Du,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D4Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D4Eu,&got,stop)) return -1;
        if(got!=0x81u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D4Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040CEA7Bu:
        if(!js_v06c_read8(m,0x819D4Fu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D4Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D50u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D50u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D51u,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D51u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEA93u:
        if(!js_v06c_read8(m,0x819D52u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D52u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D53u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D53u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEAA0u:
        if(!js_v06c_read8(m,0x819D54u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D54u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D55u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D55u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D56u,&got,stop)) return -1;
        if(got!=0x3Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D56u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEAB8u:
        if(!js_v06c_read8(m,0x819D57u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D57u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D58u,&got,stop)) return -1;
        if(got!=0x5Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D58u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D59u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D59u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEAD0u:
        if(!js_v06c_read8(m,0x819D5Au,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D5Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D5Bu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D5Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D5Cu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D5Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040CEAE8u:
        if(!js_v06c_read8(m,0x819D5Du,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D5Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D5Eu,&got,stop)) return -1;
        if(got!=0x9Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D5Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D5Fu,&got,stop)) return -1;
        if(got!=0x83u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D5Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D60u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D60u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEB08u:
        if(!js_v06c_read8(m,0x819D61u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D61u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D62u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D62u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D63u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D63u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEB20u:
        if(!js_v06c_read8(m,0x819D64u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D64u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D65u,&got,stop)) return -1;
        if(got!=0x59u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D65u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D66u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D66u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEB38u:
        if(!js_v06c_read8(m,0x819D67u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D67u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D68u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D68u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEB4Bu:
        if(!js_v06c_read8(m,0x819D69u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D69u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEB90u:
        if(!js_v06c_read8(m,0x819D72u,&got,stop)) return -1;
        if(got!=0x5Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D72u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEB98u:
        if(!js_v06c_read8(m,0x819D73u,&got,stop)) return -1;
        if(got!=0xDAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D73u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEBA0u:
        if(!js_v06c_read8(m,0x819D74u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D74u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D75u,&got,stop)) return -1;
        if(got!=0x9Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D75u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D76u,&got,stop)) return -1;
        if(got!=0x83u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D76u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D77u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D77u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEBC0u:
        if(!js_v06c_read8(m,0x819D78u,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D78u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEBC8u:
        if(!js_v06c_read8(m,0x819D79u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D79u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D7Au,&got,stop)) return -1;
        if(got!=0x9Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D7Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D7Bu,&got,stop)) return -1;
        if(got!=0x83u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D7Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D7Cu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D7Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040CEBE8u:
        if(!js_v06c_read8(m,0x819D7Du,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D7Du;stop->value=got;}return -1;}
        return 1;
    case 0x040CEBF0u:
        if(!js_v06c_read8(m,0x819D7Eu,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D7Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D7Fu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D7Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D80u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D80u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEC08u:
        if(!js_v06c_read8(m,0x819D81u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D81u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D82u,&got,stop)) return -1;
        if(got!=0xF7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D82u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D83u,&got,stop)) return -1;
        if(got!=0x82u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D83u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D84u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D84u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEC28u:
        if(!js_v06c_read8(m,0x819D85u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D85u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D86u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D86u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D87u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D87u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEC40u:
        if(!js_v06c_read8(m,0x819D88u,&got,stop)) return -1;
        if(got!=0x8Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D88u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D89u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D89u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D8Au,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D8Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D8Bu,&got,stop)) return -1;
        if(got!=0x7Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D8Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040CEC60u:
        if(!js_v06c_read8(m,0x819D8Cu,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D8Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D8Du,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D8Du;stop->value=got;}return -1;}
        return 1;
    case 0x040CEC73u:
        if(!js_v06c_read8(m,0x819D8Eu,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D8Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D8Fu,&got,stop)) return -1;
        if(got!=0xF4u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D8Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D90u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D90u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D91u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D91u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEC93u:
        if(!js_v06c_read8(m,0x819D92u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D92u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D93u,&got,stop)) return -1;
        if(got!=0x66u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D93u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D94u,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D94u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D95u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D95u;stop->value=got;}return -1;}
        return 1;
    case 0x040CECB3u:
        if(!js_v06c_read8(m,0x819D96u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D96u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D97u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D97u;stop->value=got;}return -1;}
        return 1;
    case 0x040CECC0u:
        if(!js_v06c_read8(m,0x819D98u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D98u;stop->value=got;}return -1;}
        return 1;
    case 0x040CECCBu:
        if(!js_v06c_read8(m,0x819D99u,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D99u;stop->value=got;}return -1;}
        return 1;
    case 0x040CECD3u:
        if(!js_v06c_read8(m,0x819D9Au,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D9Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D9Bu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D9Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040CECE3u:
        if(!js_v06c_read8(m,0x819D9Cu,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D9Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D9Du,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D9Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819D9Eu,&got,stop)) return -1;
        if(got!=0x0Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D9Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040CECFBu:
        if(!js_v06c_read8(m,0x819D9Fu,&got,stop)) return -1;
        if(got!=0xC9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819D9Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DA0u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DA0u;stop->value=got;}return -1;}
        return 1;
    case 0x040CED0Bu:
        if(!js_v06c_read8(m,0x819DA1u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DA1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DA2u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DA2u;stop->value=got;}return -1;}
        return 1;
    case 0x040CED1Bu:
        if(!js_v06c_read8(m,0x819DA3u,&got,stop)) return -1;
        if(got!=0x28u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DA3u;stop->value=got;}return -1;}
        return 1;
    case 0x040CED23u:
        if(!js_v06c_read8(m,0x819DA4u,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DA4u;stop->value=got;}return -1;}
        return 1;
    case 0x040CED2Bu:
        if(!js_v06c_read8(m,0x819DA5u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DA5u;stop->value=got;}return -1;}
        return 1;
    case 0x040CED33u:
        if(!js_v06c_read8(m,0x819DA6u,&got,stop)) return -1;
        if(got!=0x28u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DA6u;stop->value=got;}return -1;}
        return 1;
    case 0x040CED3Bu:
        if(!js_v06c_read8(m,0x819DA7u,&got,stop)) return -1;
        if(got!=0x38u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DA7u;stop->value=got;}return -1;}
        return 1;
    case 0x040CED43u:
        if(!js_v06c_read8(m,0x819DA8u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DA8u;stop->value=got;}return -1;}
        return 1;
    case 0x040CED8Bu:
        if(!js_v06c_read8(m,0x819DB1u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DB1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DB2u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DB2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DB3u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DB3u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEDA3u:
        if(!js_v06c_read8(m,0x819DB4u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DB4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DB5u,&got,stop)) return -1;
        if(got!=0x0Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DB5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DB6u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DB6u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEDBBu:
        if(!js_v06c_read8(m,0x819DB7u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DB7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DB8u,&got,stop)) return -1;
        if(got!=0x0Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DB8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DB9u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DB9u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEDD3u:
        if(!js_v06c_read8(m,0x819DBAu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DBAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DBBu,&got,stop)) return -1;
        if(got!=0x0Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DBBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DBCu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DBCu;stop->value=got;}return -1;}
        return 1;
    case 0x040CEDEBu:
        if(!js_v06c_read8(m,0x819DBDu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DBDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DBEu,&got,stop)) return -1;
        if(got!=0x0Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DBEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DBFu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DBFu;stop->value=got;}return -1;}
        return 1;
    case 0x040CEE03u:
        if(!js_v06c_read8(m,0x819DC0u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DC0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DC1u,&got,stop)) return -1;
        if(got!=0x11u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DC1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DC2u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DC2u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEE1Bu:
        if(!js_v06c_read8(m,0x819DC3u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DC3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DC4u,&got,stop)) return -1;
        if(got!=0x11u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DC4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DC5u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DC5u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEE33u:
        if(!js_v06c_read8(m,0x819DC6u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DC6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DC7u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DC7u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEE43u:
        if(!js_v06c_read8(m,0x819DC8u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DC8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DC9u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DC9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DCAu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DCAu;stop->value=got;}return -1;}
        return 1;
    case 0x040CEE5Bu:
        if(!js_v06c_read8(m,0x819DCBu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DCBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DCCu,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DCCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DCDu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DCDu;stop->value=got;}return -1;}
        return 1;
    case 0x040CEE73u:
        if(!js_v06c_read8(m,0x819DCEu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DCEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DCFu,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DCFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DD0u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DD0u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEE8Bu:
        if(!js_v06c_read8(m,0x819DD1u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DD1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DD2u,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DD2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DD3u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DD3u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEEA3u:
        if(!js_v06c_read8(m,0x819DD4u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DD4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DD5u,&got,stop)) return -1;
        if(got!=0x12u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DD5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DD6u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DD6u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEEBBu:
        if(!js_v06c_read8(m,0x819DD7u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DD7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DD8u,&got,stop)) return -1;
        if(got!=0x12u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DD8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DD9u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DD9u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEED3u:
        if(!js_v06c_read8(m,0x819DDAu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DDAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DDBu,&got,stop)) return -1;
        if(got!=0x97u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DDBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DDCu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DDCu;stop->value=got;}return -1;}
        return 1;
    case 0x040CEEEBu:
        if(!js_v06c_read8(m,0x819DDDu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DDDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DDEu,&got,stop)) return -1;
        if(got!=0x98u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DDEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DDFu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DDFu;stop->value=got;}return -1;}
        return 1;
    case 0x040CEF03u:
        if(!js_v06c_read8(m,0x819DE0u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DE0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DE1u,&got,stop)) return -1;
        if(got!=0xB6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DE1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DE2u,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DE2u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEF1Bu:
        if(!js_v06c_read8(m,0x819DE3u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DE3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DE4u,&got,stop)) return -1;
        if(got!=0xB8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DE4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DE5u,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DE5u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEF33u:
        if(!js_v06c_read8(m,0x819DE6u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DE6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DE7u,&got,stop)) return -1;
        if(got!=0x1Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DE7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DE8u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DE8u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEF4Bu:
        if(!js_v06c_read8(m,0x819DE9u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DE9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DEAu,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DEAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DEBu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DEBu;stop->value=got;}return -1;}
        return 1;
    case 0x040CEF63u:
        if(!js_v06c_read8(m,0x819DECu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DECu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DEDu,&got,stop)) return -1;
        if(got!=0xD1u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DEDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DEEu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DEEu;stop->value=got;}return -1;}
        return 1;
    case 0x040CEF7Bu:
        if(!js_v06c_read8(m,0x819DEFu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DEFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DF0u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DF0u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEF88u:
        if(!js_v06c_read8(m,0x819DF1u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DF1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DF2u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DF2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DF3u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DF3u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEFA0u:
        if(!js_v06c_read8(m,0x819DF4u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DF4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DF5u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DF5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DF6u,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DF6u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEFB8u:
        if(!js_v06c_read8(m,0x819DF7u,&got,stop)) return -1;
        if(got!=0x64u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DF7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DF8u,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DF8u;stop->value=got;}return -1;}
        return 1;
    case 0x040CEFC8u:
        if(!js_v06c_read8(m,0x819DF9u,&got,stop)) return -1;
        if(got!=0x64u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DF9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DFAu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DFAu;stop->value=got;}return -1;}
        return 1;
    case 0x040CEFD8u:
        if(!js_v06c_read8(m,0x819DFBu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DFBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DFCu,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DFCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DFDu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DFDu;stop->value=got;}return -1;}
        return 1;
    case 0x040CEFF0u:
        if(!js_v06c_read8(m,0x819DFEu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DFEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819DFFu,&got,stop)) return -1;
        if(got!=0x45u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819DFFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E00u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E00u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF008u:
        if(!js_v06c_read8(m,0x819E01u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E01u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E02u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E02u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF01Bu:
        if(!js_v06c_read8(m,0x819E03u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E03u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E04u,&got,stop)) return -1;
        if(got!=0x57u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E04u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E05u,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E05u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF033u:
        if(!js_v06c_read8(m,0x819E06u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E06u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E07u,&got,stop)) return -1;
        if(got!=0x5Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E07u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E08u,&got,stop)) return -1;
        if(got!=0x9Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E08u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF04Bu:
        if(!js_v06c_read8(m,0x819E09u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E09u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E0Au,&got,stop)) return -1;
        if(got!=0x15u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E0Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E0Bu,&got,stop)) return -1;
        if(got!=0xA4u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E0Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E0Cu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E0Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF06Bu:
        if(!js_v06c_read8(m,0x819E0Du,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E0Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E0Eu,&got,stop)) return -1;
        if(got!=0xF2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E0Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E0Fu,&got,stop)) return -1;
        if(got!=0xA1u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E0Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E10u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E10u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF08Bu:
        if(!js_v06c_read8(m,0x819E11u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E11u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF090u:
        if(!js_v06c_read8(m,0x819E12u,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E12u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF098u:
        if(!js_v06c_read8(m,0x819E13u,&got,stop)) return -1;
        if(got!=0xAAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E13u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF0A0u:
        if(!js_v06c_read8(m,0x819E14u,&got,stop)) return -1;
        if(got!=0xBDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E14u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E15u,&got,stop)) return -1;
        if(got!=0x54u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E15u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E16u,&got,stop)) return -1;
        if(got!=0xA1u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E16u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF0B8u:
        if(!js_v06c_read8(m,0x819E17u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E17u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E18u,&got,stop)) return -1;
        if(got!=0x58u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E18u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF0C8u:
        if(!js_v06c_read8(m,0x819E19u,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E19u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E1Au,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E1Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E1Bu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E1Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF0E0u:
        if(!js_v06c_read8(m,0x819E1Cu,&got,stop)) return -1;
        if(got!=0xB1u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E1Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E1Du,&got,stop)) return -1;
        if(got!=0x58u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E1Du;stop->value=got;}return -1;}
        return 1;
    case 0x040CF0F0u:
        if(!js_v06c_read8(m,0x819E1Eu,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E1Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E1Fu,&got,stop)) return -1;
        if(got!=0x58u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E1Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF100u:
        if(!js_v06c_read8(m,0x819E20u,&got,stop)) return -1;
        if(got!=0x29u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E20u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E21u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E21u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E22u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E22u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF118u:
        if(!js_v06c_read8(m,0x819E23u,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E23u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF120u:
        if(!js_v06c_read8(m,0x819E24u,&got,stop)) return -1;
        if(got!=0xAAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E24u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF128u:
        if(!js_v06c_read8(m,0x819E25u,&got,stop)) return -1;
        if(got!=0xB1u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E25u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E26u,&got,stop)) return -1;
        if(got!=0x58u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E26u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF138u:
        if(!js_v06c_read8(m,0x819E27u,&got,stop)) return -1;
        if(got!=0x99u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E27u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E28u,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E28u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E29u,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E29u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF150u:
        if(!js_v06c_read8(m,0x819E2Au,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E2Au;stop->value=got;}return -1;}
        return 1;
    case 0x040CF158u:
        if(!js_v06c_read8(m,0x819E2Bu,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E2Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF160u:
        if(!js_v06c_read8(m,0x819E2Cu,&got,stop)) return -1;
        if(got!=0xCAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E2Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF168u:
        if(!js_v06c_read8(m,0x819E2Du,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E2Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E2Eu,&got,stop)) return -1;
        if(got!=0xF6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E2Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF178u:
        if(!js_v06c_read8(m,0x819E2Fu,&got,stop)) return -1;
        if(got!=0x98u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E2Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF180u:
        if(!js_v06c_read8(m,0x819E30u,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E30u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF188u:
        if(!js_v06c_read8(m,0x819E31u,&got,stop)) return -1;
        if(got!=0x65u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E31u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E32u,&got,stop)) return -1;
        if(got!=0x58u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E32u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF198u:
        if(!js_v06c_read8(m,0x819E33u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E33u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E34u,&got,stop)) return -1;
        if(got!=0x58u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E34u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF1A8u:
        if(!js_v06c_read8(m,0x819E35u,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E35u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E36u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E36u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E37u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E37u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF1C0u:
        if(!js_v06c_read8(m,0x819E38u,&got,stop)) return -1;
        if(got!=0xB1u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E38u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E39u,&got,stop)) return -1;
        if(got!=0x58u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E39u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF1D0u:
        if(!js_v06c_read8(m,0x819E3Au,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E3Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E3Bu,&got,stop)) return -1;
        if(got!=0x58u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E3Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF1E0u:
        if(!js_v06c_read8(m,0x819E3Cu,&got,stop)) return -1;
        if(got!=0x29u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E3Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E3Du,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E3Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E3Eu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E3Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF1F8u:
        if(!js_v06c_read8(m,0x819E3Fu,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E3Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E40u,&got,stop)) return -1;
        if(got!=0x88u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E40u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF208u:
        if(!js_v06c_read8(m,0x819E41u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E41u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E42u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E42u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF21Bu:
        if(!js_v06c_read8(m,0x819E43u,&got,stop)) return -1;
        if(got!=0xB1u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E43u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E44u,&got,stop)) return -1;
        if(got!=0x58u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E44u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF22Bu:
        if(!js_v06c_read8(m,0x819E45u,&got,stop)) return -1;
        if(got!=0x99u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E45u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E46u,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E46u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E47u,&got,stop)) return -1;
        if(got!=0x14u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E47u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF243u:
        if(!js_v06c_read8(m,0x819E48u,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E48u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF24Bu:
        if(!js_v06c_read8(m,0x819E49u,&got,stop)) return -1;
        if(got!=0xC4u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E49u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E4Au,&got,stop)) return -1;
        if(got!=0x88u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E4Au;stop->value=got;}return -1;}
        return 1;
    case 0x040CF25Bu:
        if(!js_v06c_read8(m,0x819E4Bu,&got,stop)) return -1;
        if(got!=0x90u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E4Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E4Cu,&got,stop)) return -1;
        if(got!=0xF6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E4Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF26Bu:
        if(!js_v06c_read8(m,0x819E4Du,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E4Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E4Eu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E4Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF278u:
        if(!js_v06c_read8(m,0x819E4Fu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E4Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF280u:
        if(!js_v06c_read8(m,0x819E50u,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E50u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF288u:
        if(!js_v06c_read8(m,0x819E51u,&got,stop)) return -1;
        if(got!=0xAAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E51u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF290u:
        if(!js_v06c_read8(m,0x819E52u,&got,stop)) return -1;
        if(got!=0xBDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E52u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E53u,&got,stop)) return -1;
        if(got!=0x3Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E53u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E54u,&got,stop)) return -1;
        if(got!=0xA1u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E54u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF2A8u:
        if(!js_v06c_read8(m,0x819E55u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E55u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E56u,&got,stop)) return -1;
        if(got!=0x58u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E56u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF2B8u:
        if(!js_v06c_read8(m,0x819E57u,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E57u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E58u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E58u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E59u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E59u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF2D0u:
        if(!js_v06c_read8(m,0x819E5Au,&got,stop)) return -1;
        if(got!=0xB1u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E5Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E5Bu,&got,stop)) return -1;
        if(got!=0x58u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E5Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF2E0u:
        if(!js_v06c_read8(m,0x819E5Cu,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E5Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF2E8u:
        if(!js_v06c_read8(m,0x819E5Du,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E5Du;stop->value=got;}return -1;}
        return 1;
    case 0x040CF2F0u:
        if(!js_v06c_read8(m,0x819E5Eu,&got,stop)) return -1;
        if(got!=0xC9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E5Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E5Fu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E5Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E60u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E60u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF308u:
        if(!js_v06c_read8(m,0x819E61u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E61u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E62u,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E62u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF318u:
        if(!js_v06c_read8(m,0x819E63u,&got,stop)) return -1;
        if(got!=0xC9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E63u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E64u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E64u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E65u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E65u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF330u:
        if(!js_v06c_read8(m,0x819E66u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E66u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E67u,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E67u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF340u:
        if(!js_v06c_read8(m,0x819E68u,&got,stop)) return -1;
        if(got!=0xC9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E68u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E69u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E69u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E6Au,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E6Au;stop->value=got;}return -1;}
        return 1;
    case 0x040CF358u:
        if(!js_v06c_read8(m,0x819E6Bu,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E6Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E6Cu,&got,stop)) return -1;
        if(got!=0x34u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E6Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF368u:
        if(!js_v06c_read8(m,0x819E6Du,&got,stop)) return -1;
        if(got!=0xC9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E6Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E6Eu,&got,stop)) return -1;
        if(got!=0x04u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E6Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E6Fu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E6Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF380u:
        if(!js_v06c_read8(m,0x819E70u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E70u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E71u,&got,stop)) return -1;
        if(got!=0x1Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E71u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF390u:
        if(!js_v06c_read8(m,0x819E72u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E72u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E73u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E73u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF3A3u:
        if(!js_v06c_read8(m,0x819E74u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E74u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E75u,&got,stop)) return -1;
        if(got!=0x66u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E75u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E76u,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E76u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E77u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E77u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF3C3u:
        if(!js_v06c_read8(m,0x819E78u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E78u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E79u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E79u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF3D0u:
        if(!js_v06c_read8(m,0x819E7Au,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E7Au;stop->value=got;}return -1;}
        return 1;
    case 0x040CF3D8u:
        if(!js_v06c_read8(m,0x819E7Bu,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E7Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF3E0u:
        if(!js_v06c_read8(m,0x819E7Cu,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E7Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF3E8u:
        if(!js_v06c_read8(m,0x819E7Du,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E7Du;stop->value=got;}return -1;}
        return 1;
    case 0x040CF3F0u:
        if(!js_v06c_read8(m,0x819E7Eu,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E7Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF3F8u:
        if(!js_v06c_read8(m,0x819E7Fu,&got,stop)) return -1;
        if(got!=0x82u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E7Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E80u,&got,stop)) return -1;
        if(got!=0xD8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E80u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E81u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E81u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF410u:
        if(!js_v06c_read8(m,0x819E82u,&got,stop)) return -1;
        if(got!=0xB1u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E82u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E83u,&got,stop)) return -1;
        if(got!=0x58u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E83u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF420u:
        if(!js_v06c_read8(m,0x819E84u,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E84u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF428u:
        if(!js_v06c_read8(m,0x819E85u,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E85u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF430u:
        if(!js_v06c_read8(m,0x819E86u,&got,stop)) return -1;
        if(got!=0x5Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E86u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF438u:
        if(!js_v06c_read8(m,0x819E87u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E87u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E88u,&got,stop)) return -1;
        if(got!=0x9Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E88u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E89u,&got,stop)) return -1;
        if(got!=0x83u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E89u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E8Au,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E8Au;stop->value=got;}return -1;}
        return 1;
    case 0x040CF458u:
        if(!js_v06c_read8(m,0x819E8Bu,&got,stop)) return -1;
        if(got!=0x7Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E8Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF460u:
        if(!js_v06c_read8(m,0x819E8Cu,&got,stop)) return -1;
        if(got!=0x82u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E8Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E8Du,&got,stop)) return -1;
        if(got!=0xCBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E8Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E8Eu,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E8Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF478u:
        if(!js_v06c_read8(m,0x819E8Fu,&got,stop)) return -1;
        if(got!=0xB1u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E8Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E90u,&got,stop)) return -1;
        if(got!=0x58u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E90u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF488u:
        if(!js_v06c_read8(m,0x819E91u,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E91u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF490u:
        if(!js_v06c_read8(m,0x819E92u,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E92u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF498u:
        if(!js_v06c_read8(m,0x819E93u,&got,stop)) return -1;
        if(got!=0xAAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E93u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF4A0u:
        if(!js_v06c_read8(m,0x819E94u,&got,stop)) return -1;
        if(got!=0xB1u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E94u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E95u,&got,stop)) return -1;
        if(got!=0x58u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E95u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF4B0u:
        if(!js_v06c_read8(m,0x819E96u,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E96u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF4B8u:
        if(!js_v06c_read8(m,0x819E97u,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E97u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF4C0u:
        if(!js_v06c_read8(m,0x819E98u,&got,stop)) return -1;
        if(got!=0x5Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E98u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF4C8u:
        if(!js_v06c_read8(m,0x819E99u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E99u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E9Au,&got,stop)) return -1;
        if(got!=0xF7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E9Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E9Bu,&got,stop)) return -1;
        if(got!=0x82u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E9Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E9Cu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E9Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF4E8u:
        if(!js_v06c_read8(m,0x819E9Du,&got,stop)) return -1;
        if(got!=0x7Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E9Du;stop->value=got;}return -1;}
        return 1;
    case 0x040CF4F0u:
        if(!js_v06c_read8(m,0x819E9Eu,&got,stop)) return -1;
        if(got!=0x82u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E9Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819E9Fu,&got,stop)) return -1;
        if(got!=0xB9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819E9Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819EA0u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EA0u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF508u:
        if(!js_v06c_read8(m,0x819EA1u,&got,stop)) return -1;
        if(got!=0xB1u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EA1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819EA2u,&got,stop)) return -1;
        if(got!=0x58u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EA2u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF518u:
        if(!js_v06c_read8(m,0x819EA3u,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EA3u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF520u:
        if(!js_v06c_read8(m,0x819EA4u,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EA4u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF528u:
        if(!js_v06c_read8(m,0x819EA5u,&got,stop)) return -1;
        if(got!=0x48u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EA5u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF530u:
        if(!js_v06c_read8(m,0x819EA6u,&got,stop)) return -1;
        if(got!=0xB1u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EA6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819EA7u,&got,stop)) return -1;
        if(got!=0x58u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EA7u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF540u:
        if(!js_v06c_read8(m,0x819EA8u,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EA8u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF548u:
        if(!js_v06c_read8(m,0x819EA9u,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EA9u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF550u:
        if(!js_v06c_read8(m,0x819EAAu,&got,stop)) return -1;
        if(got!=0xAAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EAAu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF558u:
        if(!js_v06c_read8(m,0x819EABu,&got,stop)) return -1;
        if(got!=0xB1u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EABu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819EACu,&got,stop)) return -1;
        if(got!=0x58u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EACu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF568u:
        if(!js_v06c_read8(m,0x819EADu,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EADu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF570u:
        if(!js_v06c_read8(m,0x819EAEu,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EAEu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF578u:
        if(!js_v06c_read8(m,0x819EAFu,&got,stop)) return -1;
        if(got!=0xC9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EAFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819EB0u,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EB0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819EB1u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EB1u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF590u:
        if(!js_v06c_read8(m,0x819EB2u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EB2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819EB3u,&got,stop)) return -1;
        if(got!=0x0Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EB3u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF5A0u:
        if(!js_v06c_read8(m,0x819EB4u,&got,stop)) return -1;
        if(got!=0xC9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EB4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819EB5u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EB5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819EB6u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EB6u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF5B8u:
        if(!js_v06c_read8(m,0x819EB7u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EB7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819EB8u,&got,stop)) return -1;
        if(got!=0x14u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EB8u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF5C8u:
        if(!js_v06c_read8(m,0x819EB9u,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EB9u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF5D0u:
        if(!js_v06c_read8(m,0x819EBAu,&got,stop)) return -1;
        if(got!=0x5Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EBAu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF5D8u:
        if(!js_v06c_read8(m,0x819EBBu,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EBBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819EBCu,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EBCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819EBDu,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EBDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819EBEu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EBEu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF5F8u:
        if(!js_v06c_read8(m,0x819EBFu,&got,stop)) return -1;
        if(got!=0x7Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EBFu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF600u:
        if(!js_v06c_read8(m,0x819EC0u,&got,stop)) return -1;
        if(got!=0x82u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EC0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819EC1u,&got,stop)) return -1;
        if(got!=0x97u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EC1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819EC2u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EC2u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF618u:
        if(!js_v06c_read8(m,0x819EC3u,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EC3u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF620u:
        if(!js_v06c_read8(m,0x819EC4u,&got,stop)) return -1;
        if(got!=0x5Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EC4u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF628u:
        if(!js_v06c_read8(m,0x819EC5u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EC5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819EC6u,&got,stop)) return -1;
        if(got!=0x38u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EC6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819EC7u,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EC7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819EC8u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EC8u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF648u:
        if(!js_v06c_read8(m,0x819EC9u,&got,stop)) return -1;
        if(got!=0x7Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819EC9u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF650u:
        if(!js_v06c_read8(m,0x819ECAu,&got,stop)) return -1;
        if(got!=0x82u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819ECAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819ECBu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819ECBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819ECCu,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819ECCu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF668u:
        if(!js_v06c_read8(m,0x819ECDu,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819ECDu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF670u:
        if(!js_v06c_read8(m,0x819ECEu,&got,stop)) return -1;
        if(got!=0x5Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819ECEu;stop->value=got;}return -1;}
        return 1;
    case 0x040CF678u:
        if(!js_v06c_read8(m,0x819ECFu,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819ECFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819ED0u,&got,stop)) return -1;
        if(got!=0xDBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819ED0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819ED1u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819ED1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819ED2u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819ED2u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF698u:
        if(!js_v06c_read8(m,0x819ED3u,&got,stop)) return -1;
        if(got!=0x7Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819ED3u;stop->value=got;}return -1;}
        return 1;
    case 0x040CF6A0u:
        if(!js_v06c_read8(m,0x819ED4u,&got,stop)) return -1;
        if(got!=0x82u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819ED4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819ED5u,&got,stop)) return -1;
        if(got!=0x83u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819ED5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819ED6u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819ED6u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFAE3u:
        if(!js_v06c_read8(m,0x819F5Cu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F5Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F5Du,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F5Du;stop->value=got;}return -1;}
        return 1;
    case 0x040CFAF1u:
        if(!js_v06c_read8(m,0x819F5Eu,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F5Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F5Fu,&got,stop)) return -1;
        if(got!=0x3Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F5Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F60u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F60u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFB09u:
        if(!js_v06c_read8(m,0x819F61u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F61u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F62u,&got,stop)) return -1;
        if(got!=0x45u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F62u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F63u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F63u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFB21u:
        if(!js_v06c_read8(m,0x819F64u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F64u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F65u,&got,stop)) return -1;
        if(got!=0x3Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F65u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F66u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F66u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFB39u:
        if(!js_v06c_read8(m,0x819F67u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F67u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F68u,&got,stop)) return -1;
        if(got!=0x47u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F68u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F69u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F69u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFB51u:
        if(!js_v06c_read8(m,0x819F6Au,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F6Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F6Bu,&got,stop)) return -1;
        if(got!=0x4Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F6Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F6Cu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F6Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040CFB69u:
        if(!js_v06c_read8(m,0x819F6Du,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F6Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F6Eu,&got,stop)) return -1;
        if(got!=0x4Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F6Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F6Fu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F6Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040CFB81u:
        if(!js_v06c_read8(m,0x819F70u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F70u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F71u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F71u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFB93u:
        if(!js_v06c_read8(m,0x819F72u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F72u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F73u,&got,stop)) return -1;
        if(got!=0x8Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F73u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F74u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F74u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFBABu:
        if(!js_v06c_read8(m,0x819F75u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F75u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F76u,&got,stop)) return -1;
        if(got!=0x8Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F76u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F77u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F77u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFBC3u:
        if(!js_v06c_read8(m,0x819F78u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F78u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F79u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F79u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F7Au,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F7Au;stop->value=got;}return -1;}
        return 1;
    case 0x040CFBDBu:
        if(!js_v06c_read8(m,0x819F7Bu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F7Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F7Cu,&got,stop)) return -1;
        if(got!=0x8Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F7Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F7Du,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F7Du;stop->value=got;}return -1;}
        return 1;
    case 0x040CFBF3u:
        if(!js_v06c_read8(m,0x819F7Eu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F7Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F7Fu,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F7Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F80u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F80u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFC0Bu:
        if(!js_v06c_read8(m,0x819F81u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F81u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F82u,&got,stop)) return -1;
        if(got!=0x8Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F82u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F83u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F83u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFC23u:
        if(!js_v06c_read8(m,0x819F84u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F84u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F85u,&got,stop)) return -1;
        if(got!=0x90u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F85u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F86u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F86u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFC3Bu:
        if(!js_v06c_read8(m,0x819F87u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F87u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F88u,&got,stop)) return -1;
        if(got!=0x91u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F88u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F89u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F89u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFC53u:
        if(!js_v06c_read8(m,0x819F8Au,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F8Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F8Bu,&got,stop)) return -1;
        if(got!=0x93u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F8Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F8Cu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F8Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040CFC6Bu:
        if(!js_v06c_read8(m,0x819F8Du,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F8Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F8Eu,&got,stop)) return -1;
        if(got!=0x92u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F8Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F8Fu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F8Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040CFC83u:
        if(!js_v06c_read8(m,0x819F90u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F90u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F91u,&got,stop)) return -1;
        if(got!=0x96u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F91u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F92u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F92u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFC9Bu:
        if(!js_v06c_read8(m,0x819F93u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F93u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F94u,&got,stop)) return -1;
        if(got!=0x94u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F94u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F95u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F95u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFCB3u:
        if(!js_v06c_read8(m,0x819F96u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F96u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F97u,&got,stop)) return -1;
        if(got!=0x95u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F97u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F98u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F98u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFCCBu:
        if(!js_v06c_read8(m,0x819F99u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F99u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F9Au,&got,stop)) return -1;
        if(got!=0x89u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F9Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F9Bu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F9Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040CFCE3u:
        if(!js_v06c_read8(m,0x819F9Cu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F9Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040CFCEBu:
        if(!js_v06c_read8(m,0x819F9Du,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F9Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F9Eu,&got,stop)) return -1;
        if(got!=0x96u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F9Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819F9Fu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819F9Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040CFD03u:
        if(!js_v06c_read8(m,0x819FA0u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FA0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FA1u,&got,stop)) return -1;
        if(got!=0x0Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FA1u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFD13u:
        if(!js_v06c_read8(m,0x819FA2u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FA2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FA3u,&got,stop)) return -1;
        if(got!=0x52u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FA3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FA4u,&got,stop)) return -1;
        if(got!=0xFBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FA4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FA5u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FA5u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFD33u:
        if(!js_v06c_read8(m,0x819FA6u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FA6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FA7u,&got,stop)) return -1;
        if(got!=0x82u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FA7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FA8u,&got,stop)) return -1;
        if(got!=0xF9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FA8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FA9u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FA9u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFD53u:
        if(!js_v06c_read8(m,0x819FAAu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FAAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FABu,&got,stop)) return -1;
        if(got!=0x96u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FABu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FACu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FACu;stop->value=got;}return -1;}
        return 1;
    case 0x040CFD6Bu:
        if(!js_v06c_read8(m,0x819FADu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FADu;stop->value=got;}return -1;}
        return 1;
    case 0x040CFD73u:
        if(!js_v06c_read8(m,0x819FAEu,&got,stop)) return -1;
        if(got!=0xEEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FAEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FAFu,&got,stop)) return -1;
        if(got!=0xB8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FAFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FB0u,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FB0u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFD8Bu:
        if(!js_v06c_read8(m,0x819FB1u,&got,stop)) return -1;
        if(got!=0xECu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FB1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FB2u,&got,stop)) return -1;
        if(got!=0xB8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FB2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FB3u,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FB3u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFDA3u:
        if(!js_v06c_read8(m,0x819FB4u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FB4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FB5u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FB5u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFDB3u:
        if(!js_v06c_read8(m,0x819FB6u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FB6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FB7u,&got,stop)) return -1;
        if(got!=0xB8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FB7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FB8u,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FB8u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFDCBu:
        if(!js_v06c_read8(m,0x819FB9u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FB9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FBAu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FBAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FBBu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FBBu;stop->value=got;}return -1;}
        return 1;
    case 0x040CFDE3u:
        if(!js_v06c_read8(m,0x819FBCu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FBCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FBDu,&got,stop)) return -1;
        if(got!=0x8Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FBDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FBEu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FBEu;stop->value=got;}return -1;}
        return 1;
    case 0x040CFDFBu:
        if(!js_v06c_read8(m,0x819FBFu,&got,stop)) return -1;
        if(got!=0xEEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FBFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FC0u,&got,stop)) return -1;
        if(got!=0x96u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FC0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FC1u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FC1u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFE13u:
        if(!js_v06c_read8(m,0x819FC2u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FC2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FC3u,&got,stop)) return -1;
        if(got!=0xB6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FC3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FC4u,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FC4u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFE2Bu:
        if(!js_v06c_read8(m,0x819FC5u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FC5u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFE33u:
        if(!js_v06c_read8(m,0x819FC6u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FC6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FC7u,&got,stop)) return -1;
        if(got!=0xB8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FC7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FC8u,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FC8u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFE4Bu:
        if(!js_v06c_read8(m,0x819FC9u,&got,stop)) return -1;
        if(got!=0x3Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FC9u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFE53u:
        if(!js_v06c_read8(m,0x819FCAu,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FCAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FCBu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FCBu;stop->value=got;}return -1;}
        return 1;
    case 0x040CFE63u:
        if(!js_v06c_read8(m,0x819FCCu,&got,stop)) return -1;
        if(got!=0x8Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FCCu;stop->value=got;}return -1;}
        return 1;
    case 0x040CFE6Bu:
        if(!js_v06c_read8(m,0x819FCDu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FCDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FCEu,&got,stop)) return -1;
        if(got!=0xB8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FCEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FCFu,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FCFu;stop->value=got;}return -1;}
        return 1;
    case 0x040CFE83u:
        if(!js_v06c_read8(m,0x819FD0u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FD0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FD1u,&got,stop)) return -1;
        if(got!=0x8Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FD1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FD2u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FD2u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFE9Bu:
        if(!js_v06c_read8(m,0x819FD3u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FD3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FD4u,&got,stop)) return -1;
        if(got!=0x8Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FD4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FD5u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FD5u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFEB3u:
        if(!js_v06c_read8(m,0x819FD6u,&got,stop)) return -1;
        if(got!=0xEEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FD6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FD7u,&got,stop)) return -1;
        if(got!=0x96u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FD7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FD8u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FD8u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFECBu:
        if(!js_v06c_read8(m,0x819FD9u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FD9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FDAu,&got,stop)) return -1;
        if(got!=0xB6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FDAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FDBu,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FDBu;stop->value=got;}return -1;}
        return 1;
    case 0x040CFEE3u:
        if(!js_v06c_read8(m,0x819FDCu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FDCu;stop->value=got;}return -1;}
        return 1;
    case 0x040CFF33u:
        if(!js_v06c_read8(m,0x819FE6u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FE6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FE7u,&got,stop)) return -1;
        if(got!=0x8Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FE7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FE8u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FE8u;stop->value=got;}return -1;}
        return 1;
    case 0x040CFF4Bu:
        if(!js_v06c_read8(m,0x819FE9u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FE9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FEAu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FEAu;stop->value=got;}return -1;}
        return 1;
    case 0x040CFF5Bu:
        if(!js_v06c_read8(m,0x819FEBu,&got,stop)) return -1;
        if(got!=0x4Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FEBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FECu,&got,stop)) return -1;
        if(got!=0xAEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FECu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FEDu,&got,stop)) return -1;
        if(got!=0x9Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FEDu;stop->value=got;}return -1;}
        return 1;
    case 0x040CFF73u:
        if(!js_v06c_read8(m,0x819FEEu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FEEu;stop->value=got;}return -1;}
        return 1;
    case 0x040CFFC3u:
        if(!js_v06c_read8(m,0x819FF8u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FF8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FF9u,&got,stop)) return -1;
        if(got!=0x8Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FF9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FFAu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FFAu;stop->value=got;}return -1;}
        return 1;
    case 0x040CFFDBu:
        if(!js_v06c_read8(m,0x819FFBu,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FFBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FFCu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FFCu;stop->value=got;}return -1;}
        return 1;
    case 0x040CFFEBu:
        if(!js_v06c_read8(m,0x819FFDu,&got,stop)) return -1;
        if(got!=0x4Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FFDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FFEu,&got,stop)) return -1;
        if(got!=0xC6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FFEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x819FFFu,&got,stop)) return -1;
        if(got!=0x9Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x819FFFu;stop->value=got;}return -1;}
        return 1;
    default: return 0;
    }
}
