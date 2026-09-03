#include "js_v06c_fetch.h"

int js_v06c_fetch_shard_2069(JSV06Machine *m, JSV06Stop *stop) {
    uint8_t got;
    switch(js_cpu_context_key(&m->cpu)) {
    case 0x040D2ABBu:
        if(!js_v06c_read8(m,0x81A557u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A557u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A558u,&got,stop)) return -1;
        if(got!=0x46u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A558u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A559u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A559u;stop->value=got;}return -1;}
        return 1;
    case 0x040D2AD3u:
        if(!js_v06c_read8(m,0x81A55Au,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A55Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A55Bu,&got,stop)) return -1;
        if(got!=0x50u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A55Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A55Cu,&got,stop)) return -1;
        if(got!=0xA7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A55Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040D2AEBu:
        if(!js_v06c_read8(m,0x81A55Du,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A55Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A55Eu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A55Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040D2AF8u:
        if(!js_v06c_read8(m,0x81A55Fu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A55Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A560u,&got,stop)) return -1;
        if(got!=0xD4u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A560u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A561u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A561u;stop->value=got;}return -1;}
        return 1;
    case 0x040D2B10u:
        if(!js_v06c_read8(m,0x81A562u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A562u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A563u,&got,stop)) return -1;
        if(got!=0x32u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A563u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A564u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A564u;stop->value=got;}return -1;}
        return 1;
    case 0x040D2B28u:
        if(!js_v06c_read8(m,0x81A565u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A565u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A566u,&got,stop)) return -1;
        if(got!=0x9Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A566u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A567u,&got,stop)) return -1;
        if(got!=0x83u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A567u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A568u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A568u;stop->value=got;}return -1;}
        return 1;
    case 0x040D2B48u:
        if(!js_v06c_read8(m,0x81A569u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A569u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A56Au,&got,stop)) return -1;
        if(got!=0x34u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A56Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A56Bu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A56Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040D2B60u:
        if(!js_v06c_read8(m,0x81A56Cu,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A56Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A56Du,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A56Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A56Eu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A56Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040D2B78u:
        if(!js_v06c_read8(m,0x81A56Fu,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A56Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A570u,&got,stop)) return -1;
        if(got!=0xF7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A570u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A571u,&got,stop)) return -1;
        if(got!=0x82u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A571u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A572u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A572u;stop->value=got;}return -1;}
        return 1;
    case 0x040D2B98u:
        if(!js_v06c_read8(m,0x81A573u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A573u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A574u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A574u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A575u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A575u;stop->value=got;}return -1;}
        return 1;
    case 0x040D2BB0u:
        if(!js_v06c_read8(m,0x81A576u,&got,stop)) return -1;
        if(got!=0x8Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A576u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A577u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A577u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A578u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A578u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A579u,&got,stop)) return -1;
        if(got!=0x7Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A579u;stop->value=got;}return -1;}
        return 1;
    case 0x040D2BD0u:
        if(!js_v06c_read8(m,0x81A57Au,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A57Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A57Bu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A57Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A57Cu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A57Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040D2BE8u:
        if(!js_v06c_read8(m,0x81A57Du,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A57Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A57Eu,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A57Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A57Fu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A57Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040D2C00u:
        if(!js_v06c_read8(m,0x81A580u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A580u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A581u,&got,stop)) return -1;
        if(got!=0x5Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A581u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A582u,&got,stop)) return -1;
        if(got!=0x83u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A582u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A583u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A583u;stop->value=got;}return -1;}
        return 1;
    case 0x040D3A83u:
        if(!js_v06c_read8(m,0x81A750u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A750u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A751u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A751u;stop->value=got;}return -1;}
        return 1;
    case 0x040D3A91u:
        if(!js_v06c_read8(m,0x81A752u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A752u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A753u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A753u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A754u,&got,stop)) return -1;
        if(got!=0x5Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A754u;stop->value=got;}return -1;}
        return 1;
    case 0x040D3AA9u:
        if(!js_v06c_read8(m,0x81A755u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A755u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A756u,&got,stop)) return -1;
        if(got!=0x5Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A756u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A757u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A757u;stop->value=got;}return -1;}
        return 1;
    case 0x040D3AC1u:
        if(!js_v06c_read8(m,0x81A758u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A758u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A759u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A759u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A75Au,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A75Au;stop->value=got;}return -1;}
        return 1;
    case 0x040D3AD9u:
        if(!js_v06c_read8(m,0x81A75Bu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A75Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A75Cu,&got,stop)) return -1;
        if(got!=0x59u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A75Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A75Du,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A75Du;stop->value=got;}return -1;}
        return 1;
    case 0x040D3AF1u:
        if(!js_v06c_read8(m,0x81A75Eu,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A75Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A75Fu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A75Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040D3B03u:
        if(!js_v06c_read8(m,0x81A760u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A760u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A761u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A761u;stop->value=got;}return -1;}
        return 1;
    case 0x040D3B13u:
        if(!js_v06c_read8(m,0x81A762u,&got,stop)) return -1;
        if(got!=0x4Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A762u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A763u,&got,stop)) return -1;
        if(got!=0xB1u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A763u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A764u,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A764u;stop->value=got;}return -1;}
        return 1;
    default: return 0;
    }
}
