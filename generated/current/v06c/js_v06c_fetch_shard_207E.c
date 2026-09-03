#include "js_v06c_fetch.h"

int js_v06c_fetch_shard_207E(JSV06Machine *m, JSV06Stop *stop) {
    uint8_t got;
    switch(js_cpu_context_key(&m->cpu)) {
    case 0x040FC013u:
        if(!js_v06c_read8(m,0x81F802u,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F802u;stop->value=got;}return -1;}
        return 1;
    case 0x040FC01Bu:
        if(!js_v06c_read8(m,0x81F803u,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F803u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F804u,&got,stop)) return -1;
        if(got!=0x11u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F804u;stop->value=got;}return -1;}
        return 1;
    case 0x040FC02Bu:
        if(!js_v06c_read8(m,0x81F805u,&got,stop)) return -1;
        if(got!=0x90u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F805u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F806u,&got,stop)) return -1;
        if(got!=0xF2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F806u;stop->value=got;}return -1;}
        return 1;
    case 0x040FC03Bu:
        if(!js_v06c_read8(m,0x81F807u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F807u;stop->value=got;}return -1;}
        return 1;
    case 0x040FC043u:
        if(!js_v06c_read8(m,0x81F808u,&got,stop)) return -1;
        if(got!=0x5Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F808u;stop->value=got;}return -1;}
        return 1;
    case 0x040FC04Bu:
        if(!js_v06c_read8(m,0x81F809u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F809u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F80Au,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F80Au;stop->value=got;}return -1;}
        return 1;
    case 0x040FC058u:
        if(!js_v06c_read8(m,0x81F80Bu,&got,stop)) return -1;
        if(got!=0x29u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F80Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F80Cu,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F80Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F80Du,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F80Du;stop->value=got;}return -1;}
        return 1;
    case 0x040FC070u:
        if(!js_v06c_read8(m,0x81F80Eu,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F80Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040FC078u:
        if(!js_v06c_read8(m,0x81F80Fu,&got,stop)) return -1;
        if(got!=0x6Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F80Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F810u,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F810u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F811u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F811u;stop->value=got;}return -1;}
        return 1;
    case 0x040FC090u:
        if(!js_v06c_read8(m,0x81F812u,&got,stop)) return -1;
        if(got!=0xC9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F812u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F813u,&got,stop)) return -1;
        if(got!=0xE0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F813u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F814u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F814u;stop->value=got;}return -1;}
        return 1;
    case 0x040FC0A8u:
        if(!js_v06c_read8(m,0x81F815u,&got,stop)) return -1;
        if(got!=0x90u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F815u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F816u,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F816u;stop->value=got;}return -1;}
        return 1;
    case 0x040FC0B8u:
        if(!js_v06c_read8(m,0x81F817u,&got,stop)) return -1;
        if(got!=0xC9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F817u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F818u,&got,stop)) return -1;
        if(got!=0xE1u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F818u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F819u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F819u;stop->value=got;}return -1;}
        return 1;
    case 0x040FC0D0u:
        if(!js_v06c_read8(m,0x81F81Au,&got,stop)) return -1;
        if(got!=0xB0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F81Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F81Bu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F81Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040FC0E0u:
        if(!js_v06c_read8(m,0x81F81Cu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F81Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F81Du,&got,stop)) return -1;
        if(got!=0xE0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F81Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F81Eu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F81Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040FC0F8u:
        if(!js_v06c_read8(m,0x81F81Fu,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F81Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F820u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F820u;stop->value=got;}return -1;}
        return 1;
    case 0x040FC10Bu:
        if(!js_v06c_read8(m,0x81F821u,&got,stop)) return -1;
        if(got!=0x48u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F821u;stop->value=got;}return -1;}
        return 1;
    case 0x040FC113u:
        if(!js_v06c_read8(m,0x81F822u,&got,stop)) return -1;
        if(got!=0x98u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F822u;stop->value=got;}return -1;}
        return 1;
    case 0x040FC11Bu:
        if(!js_v06c_read8(m,0x81F823u,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F823u;stop->value=got;}return -1;}
        return 1;
    case 0x040FC123u:
        if(!js_v06c_read8(m,0x81F824u,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F824u;stop->value=got;}return -1;}
        return 1;
    case 0x040FC12Bu:
        if(!js_v06c_read8(m,0x81F825u,&got,stop)) return -1;
        if(got!=0xA8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F825u;stop->value=got;}return -1;}
        return 1;
    case 0x040FC133u:
        if(!js_v06c_read8(m,0x81F826u,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F826u;stop->value=got;}return -1;}
        return 1;
    case 0x040FC13Bu:
        if(!js_v06c_read8(m,0x81F827u,&got,stop)) return -1;
        if(got!=0x99u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F827u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F828u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F828u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F829u,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F829u;stop->value=got;}return -1;}
        return 1;
    case 0x040FC153u:
        if(!js_v06c_read8(m,0x81F82Au,&got,stop)) return -1;
        if(got!=0x8Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F82Au;stop->value=got;}return -1;}
        return 1;
    case 0x040FC15Bu:
        if(!js_v06c_read8(m,0x81F82Bu,&got,stop)) return -1;
        if(got!=0x99u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F82Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F82Cu,&got,stop)) return -1;
        if(got!=0xFEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F82Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F82Du,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F82Du;stop->value=got;}return -1;}
        return 1;
    case 0x040FC173u:
        if(!js_v06c_read8(m,0x81F82Eu,&got,stop)) return -1;
        if(got!=0x7Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F82Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040FC17Bu:
        if(!js_v06c_read8(m,0x81F82Fu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F82Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040FC183u:
        if(!js_v06c_read8(m,0x81F830u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F830u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F831u,&got,stop)) return -1;
        if(got!=0xE0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F831u;stop->value=got;}return -1;}
        return 1;
    case 0x040FC193u:
        if(!js_v06c_read8(m,0x81F832u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F832u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F833u,&got,stop)) return -1;
        if(got!=0xFBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F833u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F834u,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F834u;stop->value=got;}return -1;}
        return 1;
    case 0x040FC1ABu:
        if(!js_v06c_read8(m,0x81F835u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F835u;stop->value=got;}return -1;}
        return 1;
    case 0x040FC1B3u:
        if(!js_v06c_read8(m,0x81F836u,&got,stop)) return -1;
        if(got!=0xC9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F836u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F837u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F837u;stop->value=got;}return -1;}
        return 1;
    case 0x040FC1C3u:
        if(!js_v06c_read8(m,0x81F838u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F838u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F839u,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F839u;stop->value=got;}return -1;}
        return 1;
    case 0x040FC1D3u:
        if(!js_v06c_read8(m,0x81F83Au,&got,stop)) return -1;
        if(got!=0xC9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F83Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F83Bu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F83Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040FC1E3u:
        if(!js_v06c_read8(m,0x81F83Cu,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F83Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F83Du,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F83Du;stop->value=got;}return -1;}
        return 1;
    case 0x040FC243u:
        if(!js_v06c_read8(m,0x81F848u,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F848u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F849u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F849u;stop->value=got;}return -1;}
        return 1;
    case 0x040FC253u:
        if(!js_v06c_read8(m,0x81F84Au,&got,stop)) return -1;
        if(got!=0xAEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F84Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F84Bu,&got,stop)) return -1;
        if(got!=0xB8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F84Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F84Cu,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F84Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040FC26Bu:
        if(!js_v06c_read8(m,0x81F84Du,&got,stop)) return -1;
        if(got!=0xBDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F84Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F84Eu,&got,stop)) return -1;
        if(got!=0x61u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F84Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F84Fu,&got,stop)) return -1;
        if(got!=0xF8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F84Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040FC283u:
        if(!js_v06c_read8(m,0x81F850u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F850u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F851u,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F851u;stop->value=got;}return -1;}
        return 1;
    case 0x040FC293u:
        if(!js_v06c_read8(m,0x81F852u,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F852u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F853u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F853u;stop->value=got;}return -1;}
        return 1;
    case 0x040FC2A3u:
        if(!js_v06c_read8(m,0x81F854u,&got,stop)) return -1;
        if(got!=0xAEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F854u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F855u,&got,stop)) return -1;
        if(got!=0xB8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F855u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F856u,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F856u;stop->value=got;}return -1;}
        return 1;
    case 0x040FC2BBu:
        if(!js_v06c_read8(m,0x81F857u,&got,stop)) return -1;
        if(got!=0xBDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F857u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F858u,&got,stop)) return -1;
        if(got!=0x63u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F858u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F859u,&got,stop)) return -1;
        if(got!=0xF8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F859u;stop->value=got;}return -1;}
        return 1;
    case 0x040FC2D3u:
        if(!js_v06c_read8(m,0x81F85Au,&got,stop)) return -1;
        if(got!=0x8Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F85Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F85Bu,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F85Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F85Cu,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F85Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040FC2EBu:
        if(!js_v06c_read8(m,0x81F85Du,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F85Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F85Eu,&got,stop)) return -1;
        if(got!=0xFBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F85Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F85Fu,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F85Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040FC303u:
        if(!js_v06c_read8(m,0x81F860u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F860u;stop->value=got;}return -1;}
        return 1;
    default: return 0;
    }
}
