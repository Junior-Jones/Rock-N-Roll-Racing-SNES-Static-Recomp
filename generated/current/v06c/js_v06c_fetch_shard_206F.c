#include "js_v06c_fetch.h"

int js_v06c_fetch_shard_206F(JSV06Machine *m, JSV06Stop *stop) {
    uint8_t got;
    switch(js_cpu_context_key(&m->cpu)) {
    case 0x040DED48u:
        if(!js_v06c_read8(m,0x81BDA9u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDA9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BDAAu,&got,stop)) return -1;
        if(got!=0xD8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDAAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BDABu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDABu;stop->value=got;}return -1;}
        return 1;
    case 0x040DED60u:
        if(!js_v06c_read8(m,0x81BDACu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDACu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BDADu,&got,stop)) return -1;
        if(got!=0xCDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDADu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BDAEu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDAEu;stop->value=got;}return -1;}
        return 1;
    case 0x040DED78u:
        if(!js_v06c_read8(m,0x81BDAFu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDAFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BDB0u,&got,stop)) return -1;
        if(got!=0xCFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDB0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BDB1u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDB1u;stop->value=got;}return -1;}
        return 1;
    case 0x040DED90u:
        if(!js_v06c_read8(m,0x81BDB2u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDB2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BDB3u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDB3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BDB4u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDB4u;stop->value=got;}return -1;}
        return 1;
    case 0x040DEDA8u:
        if(!js_v06c_read8(m,0x81BDB5u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDB5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BDB6u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDB6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BDB7u,&got,stop)) return -1;
        if(got!=0x0Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDB7u;stop->value=got;}return -1;}
        return 1;
    case 0x040DEDC0u:
        if(!js_v06c_read8(m,0x81BDB8u,&got,stop)) return -1;
        if(got!=0x29u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDB8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BDB9u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDB9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BDBAu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDBAu;stop->value=got;}return -1;}
        return 1;
    case 0x040DEDD8u:
        if(!js_v06c_read8(m,0x81BDBBu,&got,stop)) return -1;
        if(got!=0xC9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDBBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BDBCu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDBCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BDBDu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDBDu;stop->value=got;}return -1;}
        return 1;
    case 0x040DEDF0u:
        if(!js_v06c_read8(m,0x81BDBEu,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDBEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BDBFu,&got,stop)) return -1;
        if(got!=0x07u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDBFu;stop->value=got;}return -1;}
        return 1;
    case 0x040DEE00u:
        if(!js_v06c_read8(m,0x81BDC0u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDC0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BDC1u,&got,stop)) return -1;
        if(got!=0xD4u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDC1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BDC2u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDC2u;stop->value=got;}return -1;}
        return 1;
    case 0x040DEE18u:
        if(!js_v06c_read8(m,0x81BDC3u,&got,stop)) return -1;
        if(got!=0x8Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDC3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BDC4u,&got,stop)) return -1;
        if(got!=0xDCu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDC4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BDC5u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDC5u;stop->value=got;}return -1;}
        return 1;
    case 0x040DEE30u:
        if(!js_v06c_read8(m,0x81BDC6u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDC6u;stop->value=got;}return -1;}
        return 1;
    case 0x040DEE38u:
        if(!js_v06c_read8(m,0x81BDC7u,&got,stop)) return -1;
        if(got!=0x8Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDC7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BDC8u,&got,stop)) return -1;
        if(got!=0xD4u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDC8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BDC9u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDC9u;stop->value=got;}return -1;}
        return 1;
    case 0x040DEE50u:
        if(!js_v06c_read8(m,0x81BDCAu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDCAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BDCBu,&got,stop)) return -1;
        if(got!=0xDCu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDCBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BDCCu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDCCu;stop->value=got;}return -1;}
        return 1;
    case 0x040DEE68u:
        if(!js_v06c_read8(m,0x81BDCDu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BDCDu;stop->value=got;}return -1;}
        return 1;
    default: return 0;
    }
}
