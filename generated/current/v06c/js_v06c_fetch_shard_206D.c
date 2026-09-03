#include "js_v06c_fetch.h"

int js_v06c_fetch_shard_206D(JSV06Machine *m, JSV06Stop *stop) {
    uint8_t got;
    switch(js_cpu_context_key(&m->cpu)) {
    case 0x040DB34Bu:
        if(!js_v06c_read8(m,0x81B669u,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B669u;stop->value=got;}return -1;}
        return 1;
    case 0x040DB353u:
        if(!js_v06c_read8(m,0x81B66Au,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B66Au;stop->value=got;}return -1;}
        return 1;
    case 0x040DB35Bu:
        if(!js_v06c_read8(m,0x81B66Bu,&got,stop)) return -1;
        if(got!=0xA8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B66Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040DB363u:
        if(!js_v06c_read8(m,0x81B66Cu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B66Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81B66Du,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B66Du;stop->value=got;}return -1;}
        return 1;
    case 0x040DB371u:
        if(!js_v06c_read8(m,0x81B66Eu,&got,stop)) return -1;
        if(got!=0xB9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B66Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81B66Fu,&got,stop)) return -1;
        if(got!=0x06u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B66Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81B670u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B670u;stop->value=got;}return -1;}
        return 1;
    case 0x040DB389u:
        if(!js_v06c_read8(m,0x81B671u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B671u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81B672u,&got,stop)) return -1;
        if(got!=0xBBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B672u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81B673u,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B673u;stop->value=got;}return -1;}
        return 1;
    case 0x040DB3A1u:
        if(!js_v06c_read8(m,0x81B674u,&got,stop)) return -1;
        if(got!=0xB9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B674u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81B675u,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B675u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81B676u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B676u;stop->value=got;}return -1;}
        return 1;
    case 0x040DB3B9u:
        if(!js_v06c_read8(m,0x81B677u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B677u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81B678u,&got,stop)) return -1;
        if(got!=0xBDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B678u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81B679u,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B679u;stop->value=got;}return -1;}
        return 1;
    case 0x040DB3D1u:
        if(!js_v06c_read8(m,0x81B67Au,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B67Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81B67Bu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B67Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040DB3E3u:
        if(!js_v06c_read8(m,0x81B67Cu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B67Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040DB3EBu:
        if(!js_v06c_read8(m,0x81B67Du,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B67Du;stop->value=got;}return -1;}
        return 1;
    case 0x040DB3F3u:
        if(!js_v06c_read8(m,0x81B67Eu,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B67Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040DB3FBu:
        if(!js_v06c_read8(m,0x81B67Fu,&got,stop)) return -1;
        if(got!=0xAAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B67Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040DB403u:
        if(!js_v06c_read8(m,0x81B680u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B680u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81B681u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B681u;stop->value=got;}return -1;}
        return 1;
    case 0x040DB411u:
        if(!js_v06c_read8(m,0x81B682u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B682u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81B683u,&got,stop)) return -1;
        if(got!=0xBBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B683u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81B684u,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B684u;stop->value=got;}return -1;}
        return 1;
    case 0x040DB429u:
        if(!js_v06c_read8(m,0x81B685u,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B685u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81B686u,&got,stop)) return -1;
        if(got!=0x06u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B686u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81B687u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B687u;stop->value=got;}return -1;}
        return 1;
    case 0x040DB441u:
        if(!js_v06c_read8(m,0x81B688u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B688u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81B689u,&got,stop)) return -1;
        if(got!=0xBDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B689u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81B68Au,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B68Au;stop->value=got;}return -1;}
        return 1;
    case 0x040DB459u:
        if(!js_v06c_read8(m,0x81B68Bu,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B68Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81B68Cu,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B68Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81B68Du,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B68Du;stop->value=got;}return -1;}
        return 1;
    case 0x040DB471u:
        if(!js_v06c_read8(m,0x81B68Eu,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B68Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81B68Fu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B68Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040DB483u:
        if(!js_v06c_read8(m,0x81B690u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81B690u;stop->value=got;}return -1;}
        return 1;
    default: return 0;
    }
}
