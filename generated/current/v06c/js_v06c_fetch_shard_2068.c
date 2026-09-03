#include "js_v06c_fetch.h"

int js_v06c_fetch_shard_2068(JSV06Machine *m, JSV06Stop *stop) {
    uint8_t got;
    switch(js_cpu_context_key(&m->cpu)) {
    case 0x040D0003u:
        if(!js_v06c_read8(m,0x81A000u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A000u;stop->value=got;}return -1;}
        return 1;
    case 0x040D000Bu:
        if(!js_v06c_read8(m,0x81A001u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A001u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A002u,&got,stop)) return -1;
        if(got!=0xB6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A002u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A003u,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A003u;stop->value=got;}return -1;}
        return 1;
    case 0x040D0023u:
        if(!js_v06c_read8(m,0x81A004u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A004u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A005u,&got,stop)) return -1;
        if(got!=0x07u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A005u;stop->value=got;}return -1;}
        return 1;
    case 0x040D0033u:
        if(!js_v06c_read8(m,0x81A006u,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A006u;stop->value=got;}return -1;}
        return 1;
    case 0x040D003Bu:
        if(!js_v06c_read8(m,0x81A007u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A007u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A008u,&got,stop)) return -1;
        if(got!=0xB6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A008u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A009u,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A009u;stop->value=got;}return -1;}
        return 1;
    case 0x040D0053u:
        if(!js_v06c_read8(m,0x81A00Au,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A00Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A00Bu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A00Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040D0063u:
        if(!js_v06c_read8(m,0x81A00Cu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A00Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040D006Bu:
        if(!js_v06c_read8(m,0x81A00Du,&got,stop)) return -1;
        if(got!=0xC9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A00Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A00Eu,&got,stop)) return -1;
        if(got!=0x14u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A00Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040D007Bu:
        if(!js_v06c_read8(m,0x81A00Fu,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A00Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A010u,&got,stop)) return -1;
        if(got!=0x07u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A010u;stop->value=got;}return -1;}
        return 1;
    case 0x040D008Bu:
        if(!js_v06c_read8(m,0x81A011u,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A011u;stop->value=got;}return -1;}
        return 1;
    case 0x040D0093u:
        if(!js_v06c_read8(m,0x81A012u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A012u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A013u,&got,stop)) return -1;
        if(got!=0xB6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A013u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A014u,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A014u;stop->value=got;}return -1;}
        return 1;
    case 0x040D00ABu:
        if(!js_v06c_read8(m,0x81A015u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A015u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A016u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A016u;stop->value=got;}return -1;}
        return 1;
    case 0x040D00BBu:
        if(!js_v06c_read8(m,0x81A017u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A017u;stop->value=got;}return -1;}
        return 1;
    case 0x040D00C3u:
        if(!js_v06c_read8(m,0x81A018u,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A018u;stop->value=got;}return -1;}
        return 1;
    case 0x040D00CBu:
        if(!js_v06c_read8(m,0x81A019u,&got,stop)) return -1;
        if(got!=0xC9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A019u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A01Au,&got,stop)) return -1;
        if(got!=0x1Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A01Au;stop->value=got;}return -1;}
        return 1;
    case 0x040D00DBu:
        if(!js_v06c_read8(m,0x81A01Bu,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A01Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A01Cu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A01Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040D00EBu:
        if(!js_v06c_read8(m,0x81A01Du,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A01Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A01Eu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A01Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040D00FBu:
        if(!js_v06c_read8(m,0x81A01Fu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A01Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A020u,&got,stop)) return -1;
        if(got!=0xB6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A020u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A021u,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A021u;stop->value=got;}return -1;}
        return 1;
    case 0x040D0113u:
        if(!js_v06c_read8(m,0x81A022u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A022u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A023u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A023u;stop->value=got;}return -1;}
        return 1;
    case 0x040D0123u:
        if(!js_v06c_read8(m,0x81A024u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A024u;stop->value=got;}return -1;}
        return 1;
    case 0x040D02BBu:
        if(!js_v06c_read8(m,0x81A057u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A057u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A058u,&got,stop)) return -1;
        if(got!=0x0Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A058u;stop->value=got;}return -1;}
        return 1;
    case 0x040D02CBu:
        if(!js_v06c_read8(m,0x81A059u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A059u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A05Au,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A05Au;stop->value=got;}return -1;}
        return 1;
    case 0x040D02DBu:
        if(!js_v06c_read8(m,0x81A05Bu,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A05Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A05Cu,&got,stop)) return -1;
        if(got!=0xE7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A05Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A05Du,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A05Du;stop->value=got;}return -1;}
        return 1;
    case 0x040D02F3u:
        if(!js_v06c_read8(m,0x81A05Eu,&got,stop)) return -1;
        if(got!=0xCAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A05Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040D02FBu:
        if(!js_v06c_read8(m,0x81A05Fu,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A05Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81A060u,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A060u;stop->value=got;}return -1;}
        return 1;
    case 0x040D030Bu:
        if(!js_v06c_read8(m,0x81A061u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81A061u;stop->value=got;}return -1;}
        return 1;
    default: return 0;
    }
}
