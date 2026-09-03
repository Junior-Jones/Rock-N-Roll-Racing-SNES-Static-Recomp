#include "js_v06c_fetch.h"

int js_v06c_fetch_shard_0020(JSV06Machine *m, JSV06Stop *stop) {
    uint8_t got;
    switch(js_cpu_context_key(&m->cpu)) {
    case 0x00040007u:
        if(!js_v06c_read8(m,0x008000u,&got,stop)) return -1;
        if(got!=0x5Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008000u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x008001u,&got,stop)) return -1;
        if(got!=0x0Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008001u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x008002u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008002u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x008003u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008003u;stop->value=got;}return -1;}
        return 1;
    case 0x00040B30u:
        if(!js_v06c_read8(m,0x008166u,&got,stop)) return -1;
        if(got!=0x5Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008166u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x008167u,&got,stop)) return -1;
        if(got!=0x6Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008167u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x008168u,&got,stop)) return -1;
        if(got!=0x81u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008168u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x008169u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008169u;stop->value=got;}return -1;}
        return 1;
    case 0x00040B31u:
        if(!js_v06c_read8(m,0x008166u,&got,stop)) return -1;
        if(got!=0x5Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008166u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x008167u,&got,stop)) return -1;
        if(got!=0x6Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008167u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x008168u,&got,stop)) return -1;
        if(got!=0x81u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008168u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x008169u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008169u;stop->value=got;}return -1;}
        return 1;
    case 0x00040B32u:
        if(!js_v06c_read8(m,0x008166u,&got,stop)) return -1;
        if(got!=0x5Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008166u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x008167u,&got,stop)) return -1;
        if(got!=0x6Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008167u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x008168u,&got,stop)) return -1;
        if(got!=0x81u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008168u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x008169u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008169u;stop->value=got;}return -1;}
        return 1;
    case 0x00040B33u:
        if(!js_v06c_read8(m,0x008166u,&got,stop)) return -1;
        if(got!=0x5Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008166u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x008167u,&got,stop)) return -1;
        if(got!=0x6Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008167u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x008168u,&got,stop)) return -1;
        if(got!=0x81u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008168u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x008169u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008169u;stop->value=got;}return -1;}
        return 1;
    case 0x00040B37u:
        if(!js_v06c_read8(m,0x008166u,&got,stop)) return -1;
        if(got!=0x5Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008166u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x008167u,&got,stop)) return -1;
        if(got!=0x6Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008167u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x008168u,&got,stop)) return -1;
        if(got!=0x81u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008168u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x008169u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008169u;stop->value=got;}return -1;}
        return 1;
    case 0x00040DD8u:
        if(!js_v06c_read8(m,0x0081BBu,&got,stop)) return -1;
        if(got!=0x5Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081BBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x0081BCu,&got,stop)) return -1;
        if(got!=0xBFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081BCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x0081BDu,&got,stop)) return -1;
        if(got!=0x81u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081BDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x0081BEu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081BEu;stop->value=got;}return -1;}
        return 1;
    case 0x00040DD9u:
        if(!js_v06c_read8(m,0x0081BBu,&got,stop)) return -1;
        if(got!=0x5Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081BBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x0081BCu,&got,stop)) return -1;
        if(got!=0xBFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081BCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x0081BDu,&got,stop)) return -1;
        if(got!=0x81u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081BDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x0081BEu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081BEu;stop->value=got;}return -1;}
        return 1;
    case 0x00040DDAu:
        if(!js_v06c_read8(m,0x0081BBu,&got,stop)) return -1;
        if(got!=0x5Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081BBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x0081BCu,&got,stop)) return -1;
        if(got!=0xBFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081BCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x0081BDu,&got,stop)) return -1;
        if(got!=0x81u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081BDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x0081BEu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081BEu;stop->value=got;}return -1;}
        return 1;
    case 0x00040DDBu:
        if(!js_v06c_read8(m,0x0081BBu,&got,stop)) return -1;
        if(got!=0x5Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081BBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x0081BCu,&got,stop)) return -1;
        if(got!=0xBFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081BCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x0081BDu,&got,stop)) return -1;
        if(got!=0x81u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081BDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x0081BEu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081BEu;stop->value=got;}return -1;}
        return 1;
    case 0x00040DDFu:
        if(!js_v06c_read8(m,0x0081BBu,&got,stop)) return -1;
        if(got!=0x5Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081BBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x0081BCu,&got,stop)) return -1;
        if(got!=0xBFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081BCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x0081BDu,&got,stop)) return -1;
        if(got!=0x81u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081BDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x0081BEu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081BEu;stop->value=got;}return -1;}
        return 1;
    case 0x00040FE8u:
        if(!js_v06c_read8(m,0x0081FDu,&got,stop)) return -1;
        if(got!=0x5Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081FDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x0081FEu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081FEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x0081FFu,&got,stop)) return -1;
        if(got!=0x82u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081FFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x008200u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008200u;stop->value=got;}return -1;}
        return 1;
    case 0x00040FE9u:
        if(!js_v06c_read8(m,0x0081FDu,&got,stop)) return -1;
        if(got!=0x5Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081FDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x0081FEu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081FEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x0081FFu,&got,stop)) return -1;
        if(got!=0x82u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081FFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x008200u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008200u;stop->value=got;}return -1;}
        return 1;
    case 0x00040FEAu:
        if(!js_v06c_read8(m,0x0081FDu,&got,stop)) return -1;
        if(got!=0x5Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081FDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x0081FEu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081FEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x0081FFu,&got,stop)) return -1;
        if(got!=0x82u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081FFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x008200u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008200u;stop->value=got;}return -1;}
        return 1;
    case 0x00040FEBu:
        if(!js_v06c_read8(m,0x0081FDu,&got,stop)) return -1;
        if(got!=0x5Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081FDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x0081FEu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081FEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x0081FFu,&got,stop)) return -1;
        if(got!=0x82u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081FFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x008200u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008200u;stop->value=got;}return -1;}
        return 1;
    case 0x00040FEFu:
        if(!js_v06c_read8(m,0x0081FDu,&got,stop)) return -1;
        if(got!=0x5Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081FDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x0081FEu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081FEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x0081FFu,&got,stop)) return -1;
        if(got!=0x82u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x0081FFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x008200u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x008200u;stop->value=got;}return -1;}
        return 1;
    default: return 0;
    }
}
