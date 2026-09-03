#include "js_v06c_fetch.h"

int js_v06c_fetch_shard_24BB(JSV06Machine *m, JSV06Stop *stop) {
    uint8_t got;
    switch(js_cpu_context_key(&m->cpu)) {
    case 0x04977B93u:
        if(!js_v06c_read8(m,0x92EF72u,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF72u;stop->value=got;}return -1;}
        return 1;
    case 0x04977B9Bu:
        if(!js_v06c_read8(m,0x92EF73u,&got,stop)) return -1;
        if(got!=0x4Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF73u;stop->value=got;}return -1;}
        return 1;
    case 0x04977BA3u:
        if(!js_v06c_read8(m,0x92EF74u,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF74u;stop->value=got;}return -1;}
        return 1;
    case 0x04977BABu:
        if(!js_v06c_read8(m,0x92EF75u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF75u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EF76u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF76u;stop->value=got;}return -1;}
        return 1;
    case 0x04977BBBu:
        if(!js_v06c_read8(m,0x92EF77u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF77u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EF78u,&got,stop)) return -1;
        if(got!=0x0Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF78u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EF79u,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF79u;stop->value=got;}return -1;}
        return 1;
    case 0x04977BD3u:
        if(!js_v06c_read8(m,0x92EF7Au,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF7Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EF7Bu,&got,stop)) return -1;
        if(got!=0x8Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF7Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04977BE3u:
        if(!js_v06c_read8(m,0x92EF7Cu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF7Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EF7Du,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF7Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EF7Eu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF7Eu;stop->value=got;}return -1;}
        return 1;
    case 0x04977BFBu:
        if(!js_v06c_read8(m,0x92EF7Fu,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF7Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EF80u,&got,stop)) return -1;
        if(got!=0x0Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF80u;stop->value=got;}return -1;}
        return 1;
    case 0x04977C0Bu:
        if(!js_v06c_read8(m,0x92EF81u,&got,stop)) return -1;
        if(got!=0x9Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF81u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EF82u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF82u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EF83u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF83u;stop->value=got;}return -1;}
        return 1;
    case 0x04977C23u:
        if(!js_v06c_read8(m,0x92EF84u,&got,stop)) return -1;
        if(got!=0xCAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF84u;stop->value=got;}return -1;}
        return 1;
    case 0x04977C2Bu:
        if(!js_v06c_read8(m,0x92EF85u,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF85u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EF86u,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF86u;stop->value=got;}return -1;}
        return 1;
    case 0x04977C3Bu:
        if(!js_v06c_read8(m,0x92EF87u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF87u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EF88u,&got,stop)) return -1;
        if(got!=0x07u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF88u;stop->value=got;}return -1;}
        return 1;
    case 0x04977C4Bu:
        if(!js_v06c_read8(m,0x92EF89u,&got,stop)) return -1;
        if(got!=0x9Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF89u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EF8Au,&got,stop)) return -1;
        if(got!=0x0Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF8Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EF8Bu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF8Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04977C63u:
        if(!js_v06c_read8(m,0x92EF8Cu,&got,stop)) return -1;
        if(got!=0x9Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF8Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EF8Du,&got,stop)) return -1;
        if(got!=0x0Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF8Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EF8Eu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF8Eu;stop->value=got;}return -1;}
        return 1;
    case 0x04977C7Bu:
        if(!js_v06c_read8(m,0x92EF8Fu,&got,stop)) return -1;
        if(got!=0xCAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF8Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04977C83u:
        if(!js_v06c_read8(m,0x92EF90u,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF90u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EF91u,&got,stop)) return -1;
        if(got!=0xF7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF91u;stop->value=got;}return -1;}
        return 1;
    case 0x04977C93u:
        if(!js_v06c_read8(m,0x92EF92u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF92u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EF93u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF93u;stop->value=got;}return -1;}
        return 1;
    case 0x04977CA3u:
        if(!js_v06c_read8(m,0x92EF94u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF94u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EF95u,&got,stop)) return -1;
        if(got!=0x15u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF95u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EF96u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF96u;stop->value=got;}return -1;}
        return 1;
    case 0x04977CBBu:
        if(!js_v06c_read8(m,0x92EF97u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF97u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EF98u,&got,stop)) return -1;
        if(got!=0x04u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF98u;stop->value=got;}return -1;}
        return 1;
    case 0x04977CCBu:
        if(!js_v06c_read8(m,0x92EF99u,&got,stop)) return -1;
        if(got!=0x9Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF99u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EF9Au,&got,stop)) return -1;
        if(got!=0x16u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF9Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EF9Bu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF9Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04977CE3u:
        if(!js_v06c_read8(m,0x92EF9Cu,&got,stop)) return -1;
        if(got!=0xCAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF9Cu;stop->value=got;}return -1;}
        return 1;
    case 0x04977CEBu:
        if(!js_v06c_read8(m,0x92EF9Du,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF9Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EF9Eu,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF9Eu;stop->value=got;}return -1;}
        return 1;
    case 0x04977CFBu:
        if(!js_v06c_read8(m,0x92EF9Fu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EF9Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFA0u,&got,stop)) return -1;
        if(got!=0x1Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFA0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFA1u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFA1u;stop->value=got;}return -1;}
        return 1;
    case 0x04977D13u:
        if(!js_v06c_read8(m,0x92EFA2u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFA2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFA3u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFA3u;stop->value=got;}return -1;}
        return 1;
    case 0x04977D23u:
        if(!js_v06c_read8(m,0x92EFA4u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFA4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFA5u,&got,stop)) return -1;
        if(got!=0x1Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFA5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFA6u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFA6u;stop->value=got;}return -1;}
        return 1;
    case 0x04977D3Bu:
        if(!js_v06c_read8(m,0x92EFA7u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFA7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFA8u,&got,stop)) return -1;
        if(got!=0x1Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFA8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFA9u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFA9u;stop->value=got;}return -1;}
        return 1;
    case 0x04977D53u:
        if(!js_v06c_read8(m,0x92EFAAu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFAAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFABu,&got,stop)) return -1;
        if(got!=0x1Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFABu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFACu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFACu;stop->value=got;}return -1;}
        return 1;
    case 0x04977D6Bu:
        if(!js_v06c_read8(m,0x92EFADu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFADu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFAEu,&got,stop)) return -1;
        if(got!=0x1Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFAEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFAFu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFAFu;stop->value=got;}return -1;}
        return 1;
    case 0x04977D83u:
        if(!js_v06c_read8(m,0x92EFB0u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFB0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFB1u,&got,stop)) return -1;
        if(got!=0x1Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFB1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFB2u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFB2u;stop->value=got;}return -1;}
        return 1;
    case 0x04977D9Bu:
        if(!js_v06c_read8(m,0x92EFB3u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFB3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFB4u,&got,stop)) return -1;
        if(got!=0x1Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFB4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFB5u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFB5u;stop->value=got;}return -1;}
        return 1;
    case 0x04977DB3u:
        if(!js_v06c_read8(m,0x92EFB6u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFB6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFB7u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFB7u;stop->value=got;}return -1;}
        return 1;
    case 0x04977DC3u:
        if(!js_v06c_read8(m,0x92EFB8u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFB8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFB9u,&got,stop)) return -1;
        if(got!=0x1Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFB9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFBAu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFBAu;stop->value=got;}return -1;}
        return 1;
    case 0x04977DDBu:
        if(!js_v06c_read8(m,0x92EFBBu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFBBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFBCu,&got,stop)) return -1;
        if(got!=0x1Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFBCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFBDu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFBDu;stop->value=got;}return -1;}
        return 1;
    case 0x04977DF3u:
        if(!js_v06c_read8(m,0x92EFBEu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFBEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFBFu,&got,stop)) return -1;
        if(got!=0x1Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFBFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFC0u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFC0u;stop->value=got;}return -1;}
        return 1;
    case 0x04977E0Bu:
        if(!js_v06c_read8(m,0x92EFC1u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFC1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFC2u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFC2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFC3u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFC3u;stop->value=got;}return -1;}
        return 1;
    case 0x04977E23u:
        if(!js_v06c_read8(m,0x92EFC4u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFC4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFC5u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFC5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFC6u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFC6u;stop->value=got;}return -1;}
        return 1;
    case 0x04977E3Bu:
        if(!js_v06c_read8(m,0x92EFC7u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFC7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFC8u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFC8u;stop->value=got;}return -1;}
        return 1;
    case 0x04977E4Bu:
        if(!js_v06c_read8(m,0x92EFC9u,&got,stop)) return -1;
        if(got!=0x9Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFC9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFCAu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFCAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFCBu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFCBu;stop->value=got;}return -1;}
        return 1;
    case 0x04977E63u:
        if(!js_v06c_read8(m,0x92EFCCu,&got,stop)) return -1;
        if(got!=0xCAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFCCu;stop->value=got;}return -1;}
        return 1;
    case 0x04977E6Bu:
        if(!js_v06c_read8(m,0x92EFCDu,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFCDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFCEu,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFCEu;stop->value=got;}return -1;}
        return 1;
    case 0x04977E7Bu:
        if(!js_v06c_read8(m,0x92EFCFu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFCFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFD0u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFD0u;stop->value=got;}return -1;}
        return 1;
    case 0x04977E8Bu:
        if(!js_v06c_read8(m,0x92EFD1u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFD1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFD2u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFD2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFD3u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFD3u;stop->value=got;}return -1;}
        return 1;
    case 0x04977EA3u:
        if(!js_v06c_read8(m,0x92EFD4u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFD4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFD5u,&got,stop)) return -1;
        if(got!=0x31u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFD5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFD6u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFD6u;stop->value=got;}return -1;}
        return 1;
    case 0x04977EBBu:
        if(!js_v06c_read8(m,0x92EFD7u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFD7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFD8u,&got,stop)) return -1;
        if(got!=0xE0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFD8u;stop->value=got;}return -1;}
        return 1;
    case 0x04977ECBu:
        if(!js_v06c_read8(m,0x92EFD9u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFD9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFDAu,&got,stop)) return -1;
        if(got!=0x32u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFDAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFDBu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFDBu;stop->value=got;}return -1;}
        return 1;
    case 0x04977EE3u:
        if(!js_v06c_read8(m,0x92EFDCu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFDCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFDDu,&got,stop)) return -1;
        if(got!=0x33u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFDDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFDEu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFDEu;stop->value=got;}return -1;}
        return 1;
    case 0x04977EFBu:
        if(!js_v06c_read8(m,0x92EFDFu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFDFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFE0u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFE0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFE1u,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFE1u;stop->value=got;}return -1;}
        return 1;
    case 0x04977F13u:
        if(!js_v06c_read8(m,0x92EFE2u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFE2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFE3u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFE3u;stop->value=got;}return -1;}
        return 1;
    case 0x04977F23u:
        if(!js_v06c_read8(m,0x92EFE4u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFE4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFE5u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFE5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFE6u,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFE6u;stop->value=got;}return -1;}
        return 1;
    case 0x04977F3Bu:
        if(!js_v06c_read8(m,0x92EFE7u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFE7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFE8u,&got,stop)) return -1;
        if(got!=0x0Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFE8u;stop->value=got;}return -1;}
        return 1;
    case 0x04977F4Bu:
        if(!js_v06c_read8(m,0x92EFE9u,&got,stop)) return -1;
        if(got!=0x9Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFE9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFEAu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFEAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFEBu,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFEBu;stop->value=got;}return -1;}
        return 1;
    case 0x04977F63u:
        if(!js_v06c_read8(m,0x92EFECu,&got,stop)) return -1;
        if(got!=0xCAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFECu;stop->value=got;}return -1;}
        return 1;
    case 0x04977F6Bu:
        if(!js_v06c_read8(m,0x92EFEDu,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFEDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFEEu,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFEEu;stop->value=got;}return -1;}
        return 1;
    case 0x04977F7Bu:
        if(!js_v06c_read8(m,0x92EFEFu,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFEFu;stop->value=got;}return -1;}
        return 1;
    case 0x04977F83u:
        if(!js_v06c_read8(m,0x92EFF0u,&got,stop)) return -1;
        if(got!=0x6Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFF0u;stop->value=got;}return -1;}
        return 1;
    case 0x04977F8Bu:
        if(!js_v06c_read8(m,0x92EFF1u,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFF1u;stop->value=got;}return -1;}
        return 1;
    case 0x04977F93u:
        if(!js_v06c_read8(m,0x92EFF2u,&got,stop)) return -1;
        if(got!=0x4Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFF2u;stop->value=got;}return -1;}
        return 1;
    case 0x04977F9Bu:
        if(!js_v06c_read8(m,0x92EFF3u,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFF3u;stop->value=got;}return -1;}
        return 1;
    case 0x04977FA3u:
        if(!js_v06c_read8(m,0x92EFF4u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFF4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFF5u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFF5u;stop->value=got;}return -1;}
        return 1;
    case 0x04977FB0u:
        if(!js_v06c_read8(m,0x92EFF6u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFF6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFF7u,&got,stop)) return -1;
        if(got!=0x3Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFF7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFF8u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFF8u;stop->value=got;}return -1;}
        return 1;
    case 0x04977FC8u:
        if(!js_v06c_read8(m,0x92EFF9u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFF9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFFAu,&got,stop)) return -1;
        if(got!=0x3Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFFAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFFBu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFFBu;stop->value=got;}return -1;}
        return 1;
    case 0x04977FE0u:
        if(!js_v06c_read8(m,0x92EFFCu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFFCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFFDu,&got,stop)) return -1;
        if(got!=0x3Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFFDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92EFFEu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFFEu;stop->value=got;}return -1;}
        return 1;
    case 0x04977FF8u:
        if(!js_v06c_read8(m,0x92EFFFu,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92EFFFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x92F000u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x92F000u;stop->value=got;}return -1;}
        return 1;
    default: return 0;
    }
}
