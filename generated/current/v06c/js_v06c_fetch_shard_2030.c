#include "js_v06c_fetch.h"

int js_v06c_fetch_shard_2030(JSV06Machine *m, JSV06Stop *stop) {
    uint8_t got;
    switch(js_cpu_context_key(&m->cpu)) {
    case 0x04060333u:
        if(!js_v06c_read8(m,0x80C066u,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C066u;stop->value=got;}return -1;}
        return 1;
    case 0x0406033Bu:
        if(!js_v06c_read8(m,0x80C067u,&got,stop)) return -1;
        if(got!=0x4Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C067u;stop->value=got;}return -1;}
        return 1;
    case 0x04060343u:
        if(!js_v06c_read8(m,0x80C068u,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C068u;stop->value=got;}return -1;}
        return 1;
    case 0x0406034Bu:
        if(!js_v06c_read8(m,0x80C069u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C069u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80C06Au,&got,stop)) return -1;
        if(got!=0x6Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C06Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80C06Bu,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C06Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04060363u:
        if(!js_v06c_read8(m,0x80C06Cu,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C06Cu;stop->value=got;}return -1;}
        return 1;
    case 0x0406036Bu:
        if(!js_v06c_read8(m,0x80C06Du,&got,stop)) return -1;
        if(got!=0x6Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C06Du;stop->value=got;}return -1;}
        return 1;
    case 0x04060373u:
        if(!js_v06c_read8(m,0x80C06Eu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C06Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80C06Fu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C06Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80C070u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C070u;stop->value=got;}return -1;}
        return 1;
    case 0x0406038Bu:
        if(!js_v06c_read8(m,0x80C071u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C071u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80C072u,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C072u;stop->value=got;}return -1;}
        return 1;
    case 0x0406039Bu:
        if(!js_v06c_read8(m,0x80C073u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C073u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80C074u,&got,stop)) return -1;
        if(got!=0x0Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C074u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80C075u,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C075u;stop->value=got;}return -1;}
        return 1;
    case 0x040603B3u:
        if(!js_v06c_read8(m,0x80C076u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C076u;stop->value=got;}return -1;}
        return 1;
    case 0x040617A3u:
        if(!js_v06c_read8(m,0x80C2F4u,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C2F4u;stop->value=got;}return -1;}
        return 1;
    case 0x040617ABu:
        if(!js_v06c_read8(m,0x80C2F5u,&got,stop)) return -1;
        if(got!=0x4Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C2F5u;stop->value=got;}return -1;}
        return 1;
    case 0x040617B3u:
        if(!js_v06c_read8(m,0x80C2F6u,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C2F6u;stop->value=got;}return -1;}
        return 1;
    case 0x040617BBu:
        if(!js_v06c_read8(m,0x80C2F7u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C2F7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80C2F8u,&got,stop)) return -1;
        if(got!=0xFCu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C2F8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80C2F9u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C2F9u;stop->value=got;}return -1;}
        return 1;
    case 0x040617D3u:
        if(!js_v06c_read8(m,0x80C2FAu,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C2FAu;stop->value=got;}return -1;}
        return 1;
    case 0x040617DBu:
        if(!js_v06c_read8(m,0x80C2FBu,&got,stop)) return -1;
        if(got!=0x6Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C2FBu;stop->value=got;}return -1;}
        return 1;
    case 0x040617E3u:
        if(!js_v06c_read8(m,0x80C2FCu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C2FCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80C2FDu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C2FDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80C2FEu,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C2FEu;stop->value=got;}return -1;}
        return 1;
    case 0x040617FBu:
        if(!js_v06c_read8(m,0x80C2FFu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C2FFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80C300u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C300u;stop->value=got;}return -1;}
        return 1;
    case 0x0406180Bu:
        if(!js_v06c_read8(m,0x80C301u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C301u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80C302u,&got,stop)) return -1;
        if(got!=0x31u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C302u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80C303u,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C303u;stop->value=got;}return -1;}
        return 1;
    case 0x04061823u:
        if(!js_v06c_read8(m,0x80C304u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C304u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80C305u,&got,stop)) return -1;
        if(got!=0x7Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C305u;stop->value=got;}return -1;}
        return 1;
    case 0x04061833u:
        if(!js_v06c_read8(m,0x80C306u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C306u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80C307u,&got,stop)) return -1;
        if(got!=0x34u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C307u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80C308u,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C308u;stop->value=got;}return -1;}
        return 1;
    case 0x0406184Bu:
        if(!js_v06c_read8(m,0x80C309u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C309u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80C30Au,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C30Au;stop->value=got;}return -1;}
        return 1;
    case 0x04061858u:
        if(!js_v06c_read8(m,0x80C30Bu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C30Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80C30Cu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C30Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80C30Du,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C30Du;stop->value=got;}return -1;}
        return 1;
    case 0x04061870u:
        if(!js_v06c_read8(m,0x80C30Eu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C30Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80C30Fu,&got,stop)) return -1;
        if(got!=0x32u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C30Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80C310u,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C310u;stop->value=got;}return -1;}
        return 1;
    case 0x04061888u:
        if(!js_v06c_read8(m,0x80C311u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C311u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80C312u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C312u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80C313u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C313u;stop->value=got;}return -1;}
        return 1;
    case 0x040618A0u:
        if(!js_v06c_read8(m,0x80C314u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C314u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80C315u,&got,stop)) return -1;
        if(got!=0x35u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C315u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80C316u,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C316u;stop->value=got;}return -1;}
        return 1;
    case 0x040618B8u:
        if(!js_v06c_read8(m,0x80C317u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C317u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80C318u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C318u;stop->value=got;}return -1;}
        return 1;
    case 0x040618CBu:
        if(!js_v06c_read8(m,0x80C319u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80C319u;stop->value=got;}return -1;}
        return 1;
    default: return 0;
    }
}
