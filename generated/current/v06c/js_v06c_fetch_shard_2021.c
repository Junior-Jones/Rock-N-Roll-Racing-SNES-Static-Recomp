#include "js_v06c_fetch.h"

int js_v06c_fetch_shard_2021(JSV06Machine *m, JSV06Stop *stop) {
    uint8_t got;
    switch(js_cpu_context_key(&m->cpu)) {
    case 0x0404200Au:
        if(!js_v06c_read8(m,0x808401u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808401u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808402u,&got,stop)) return -1;
        if(got!=0x35u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808402u;stop->value=got;}return -1;}
        return 1;
    case 0x0404201Au:
        if(!js_v06c_read8(m,0x808403u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808403u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808404u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808404u;stop->value=got;}return -1;}
        return 1;
    case 0x04042028u:
        if(!js_v06c_read8(m,0x808405u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808405u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808406u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808406u;stop->value=got;}return -1;}
        return 1;
    case 0x04042038u:
        if(!js_v06c_read8(m,0x808407u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808407u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808408u,&got,stop)) return -1;
        if(got!=0x07u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808408u;stop->value=got;}return -1;}
        return 1;
    case 0x04042048u:
        if(!js_v06c_read8(m,0x808409u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808409u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80840Au,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80840Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80840Bu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80840Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04042060u:
        if(!js_v06c_read8(m,0x80840Cu,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80840Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80840Du,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80840Du;stop->value=got;}return -1;}
        return 1;
    case 0x04042070u:
        if(!js_v06c_read8(m,0x80840Eu,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80840Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80840Fu,&got,stop)) return -1;
        if(got!=0x32u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80840Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04042080u:
        if(!js_v06c_read8(m,0x808410u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808410u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808411u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808411u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808412u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808412u;stop->value=got;}return -1;}
        return 1;
    case 0x04042098u:
        if(!js_v06c_read8(m,0x808413u,&got,stop)) return -1;
        if(got!=0x38u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808413u;stop->value=got;}return -1;}
        return 1;
    case 0x040420A0u:
        if(!js_v06c_read8(m,0x808414u,&got,stop)) return -1;
        if(got!=0xE5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808414u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808415u,&got,stop)) return -1;
        if(got!=0x34u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808415u;stop->value=got;}return -1;}
        return 1;
    case 0x040420B0u:
        if(!js_v06c_read8(m,0x808416u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808416u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808417u,&got,stop)) return -1;
        if(got!=0x34u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808417u;stop->value=got;}return -1;}
        return 1;
    case 0x040420C0u:
        if(!js_v06c_read8(m,0x808418u,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808418u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808419u,&got,stop)) return -1;
        if(got!=0xFEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808419u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80841Au,&got,stop)) return -1;
        if(got!=0x0Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80841Au;stop->value=got;}return -1;}
        return 1;
    case 0x040420D8u:
        if(!js_v06c_read8(m,0x80841Bu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80841Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80841Cu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80841Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80841Du,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80841Du;stop->value=got;}return -1;}
        return 1;
    case 0x040420F0u:
        if(!js_v06c_read8(m,0x80841Eu,&got,stop)) return -1;
        if(got!=0x97u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80841Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80841Fu,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80841Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04042100u:
        if(!js_v06c_read8(m,0x808420u,&got,stop)) return -1;
        if(got!=0x88u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808420u;stop->value=got;}return -1;}
        return 1;
    case 0x04042108u:
        if(!js_v06c_read8(m,0x808421u,&got,stop)) return -1;
        if(got!=0x88u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808421u;stop->value=got;}return -1;}
        return 1;
    case 0x04042110u:
        if(!js_v06c_read8(m,0x808422u,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808422u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808423u,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808423u;stop->value=got;}return -1;}
        return 1;
    case 0x04042120u:
        if(!js_v06c_read8(m,0x808424u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808424u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808425u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808425u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808426u,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808426u;stop->value=got;}return -1;}
        return 1;
    case 0x04042138u:
        if(!js_v06c_read8(m,0x808427u,&got,stop)) return -1;
        if(got!=0x64u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808427u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808428u,&got,stop)) return -1;
        if(got!=0x44u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808428u;stop->value=got;}return -1;}
        return 1;
    case 0x04042148u:
        if(!js_v06c_read8(m,0x808429u,&got,stop)) return -1;
        if(got!=0x46u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808429u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80842Au,&got,stop)) return -1;
        if(got!=0x44u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80842Au;stop->value=got;}return -1;}
        return 1;
    case 0x04042158u:
        if(!js_v06c_read8(m,0x80842Bu,&got,stop)) return -1;
        if(got!=0xA5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80842Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80842Cu,&got,stop)) return -1;
        if(got!=0x44u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80842Cu;stop->value=got;}return -1;}
        return 1;
    case 0x04042168u:
        if(!js_v06c_read8(m,0x80842Du,&got,stop)) return -1;
        if(got!=0x89u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80842Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80842Eu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80842Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80842Fu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80842Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04042180u:
        if(!js_v06c_read8(m,0x808430u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808430u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808431u,&got,stop)) return -1;
        if(got!=0x14u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808431u;stop->value=got;}return -1;}
        return 1;
    case 0x04042190u:
        if(!js_v06c_read8(m,0x808432u,&got,stop)) return -1;
        if(got!=0xA7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808432u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808433u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808433u;stop->value=got;}return -1;}
        return 1;
    case 0x040421A0u:
        if(!js_v06c_read8(m,0x808434u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808434u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808435u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808435u;stop->value=got;}return -1;}
        return 1;
    case 0x040421B0u:
        if(!js_v06c_read8(m,0x808436u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808436u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808437u,&got,stop)) return -1;
        if(got!=0x09u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808437u;stop->value=got;}return -1;}
        return 1;
    case 0x040421C0u:
        if(!js_v06c_read8(m,0x808438u,&got,stop)) return -1;
        if(got!=0x48u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808438u;stop->value=got;}return -1;}
        return 1;
    case 0x040421C8u:
        if(!js_v06c_read8(m,0x808439u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808439u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80843Au,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80843Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80843Bu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80843Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040421E0u:
        if(!js_v06c_read8(m,0x80843Cu,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80843Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80843Du,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80843Du;stop->value=got;}return -1;}
        return 1;
    case 0x040421F0u:
        if(!js_v06c_read8(m,0x80843Eu,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80843Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040421F8u:
        if(!js_v06c_read8(m,0x80843Fu,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80843Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808440u,&got,stop)) return -1;
        if(got!=0x32u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808440u;stop->value=got;}return -1;}
        return 1;
    case 0x04042208u:
        if(!js_v06c_read8(m,0x808441u,&got,stop)) return -1;
        if(got!=0x09u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808441u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808442u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808442u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808443u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808443u;stop->value=got;}return -1;}
        return 1;
    case 0x04042220u:
        if(!js_v06c_read8(m,0x808444u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808444u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808445u,&got,stop)) return -1;
        if(got!=0x44u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808445u;stop->value=got;}return -1;}
        return 1;
    case 0x04042230u:
        if(!js_v06c_read8(m,0x808446u,&got,stop)) return -1;
        if(got!=0x4Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808446u;stop->value=got;}return -1;}
        return 1;
    case 0x04042238u:
        if(!js_v06c_read8(m,0x808447u,&got,stop)) return -1;
        if(got!=0x90u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808447u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808448u,&got,stop)) return -1;
        if(got!=0x31u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808448u;stop->value=got;}return -1;}
        return 1;
    case 0x04042248u:
        if(!js_v06c_read8(m,0x808449u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808449u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80844Au,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80844Au;stop->value=got;}return -1;}
        return 1;
    case 0x0404225Au:
        if(!js_v06c_read8(m,0x80844Bu,&got,stop)) return -1;
        if(got!=0xA7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80844Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80844Cu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80844Cu;stop->value=got;}return -1;}
        return 1;
    case 0x0404226Au:
        if(!js_v06c_read8(m,0x80844Du,&got,stop)) return -1;
        if(got!=0x87u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80844Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80844Eu,&got,stop)) return -1;
        if(got!=0x3Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80844Eu;stop->value=got;}return -1;}
        return 1;
    case 0x0404227Au:
        if(!js_v06c_read8(m,0x80844Fu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80844Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808450u,&got,stop)) return -1;
        if(got!=0xE0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808450u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808451u,&got,stop)) return -1;
        if(got!=0x84u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808451u;stop->value=got;}return -1;}
        return 1;
    case 0x04042292u:
        if(!js_v06c_read8(m,0x808452u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808452u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808453u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808453u;stop->value=got;}return -1;}
        return 1;
    case 0x040422A0u:
        if(!js_v06c_read8(m,0x808454u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808454u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808455u,&got,stop)) return -1;
        if(got!=0x34u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808455u;stop->value=got;}return -1;}
        return 1;
    case 0x040422B0u:
        if(!js_v06c_read8(m,0x808456u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808456u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808457u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808457u;stop->value=got;}return -1;}
        return 1;
    case 0x040422C0u:
        if(!js_v06c_read8(m,0x808458u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808458u;stop->value=got;}return -1;}
        return 1;
    case 0x040422C8u:
        if(!js_v06c_read8(m,0x808459u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808459u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80845Au,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80845Au;stop->value=got;}return -1;}
        return 1;
    case 0x040422D8u:
        if(!js_v06c_read8(m,0x80845Bu,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80845Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80845Cu,&got,stop)) return -1;
        if(got!=0x0Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80845Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040422E8u:
        if(!js_v06c_read8(m,0x80845Du,&got,stop)) return -1;
        if(got!=0x48u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80845Du;stop->value=got;}return -1;}
        return 1;
    case 0x040422F0u:
        if(!js_v06c_read8(m,0x80845Eu,&got,stop)) return -1;
        if(got!=0xA5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80845Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80845Fu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80845Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04042300u:
        if(!js_v06c_read8(m,0x808460u,&got,stop)) return -1;
        if(got!=0x09u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808460u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808461u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808461u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808462u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808462u;stop->value=got;}return -1;}
        return 1;
    case 0x04042318u:
        if(!js_v06c_read8(m,0x808463u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808463u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808464u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808464u;stop->value=got;}return -1;}
        return 1;
    case 0x04042328u:
        if(!js_v06c_read8(m,0x808465u,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808465u;stop->value=got;}return -1;}
        return 1;
    case 0x04042330u:
        if(!js_v06c_read8(m,0x808466u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808466u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808467u,&got,stop)) return -1;
        if(got!=0x32u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808467u;stop->value=got;}return -1;}
        return 1;
    case 0x04042340u:
        if(!js_v06c_read8(m,0x808468u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808468u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808469u,&got,stop)) return -1;
        if(got!=0x3Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808469u;stop->value=got;}return -1;}
        return 1;
    case 0x04042350u:
        if(!js_v06c_read8(m,0x80846Au,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80846Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80846Bu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80846Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04042360u:
        if(!js_v06c_read8(m,0x80846Cu,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80846Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80846Du,&got,stop)) return -1;
        if(got!=0x3Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80846Du;stop->value=got;}return -1;}
        return 1;
    case 0x04042370u:
        if(!js_v06c_read8(m,0x80846Eu,&got,stop)) return -1;
        if(got!=0xCAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80846Eu;stop->value=got;}return -1;}
        return 1;
    case 0x04042378u:
        if(!js_v06c_read8(m,0x80846Fu,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80846Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808470u,&got,stop)) return -1;
        if(got!=0xB8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808470u;stop->value=got;}return -1;}
        return 1;
    case 0x04042388u:
        if(!js_v06c_read8(m,0x808471u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808471u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808472u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808472u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808473u,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808473u;stop->value=got;}return -1;}
        return 1;
    case 0x040423A0u:
        if(!js_v06c_read8(m,0x808474u,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808474u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808475u,&got,stop)) return -1;
        if(got!=0x05u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808475u;stop->value=got;}return -1;}
        return 1;
    case 0x040423B0u:
        if(!js_v06c_read8(m,0x808476u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808476u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808477u,&got,stop)) return -1;
        if(got!=0x3Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808477u;stop->value=got;}return -1;}
        return 1;
    case 0x040423C0u:
        if(!js_v06c_read8(m,0x808478u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808478u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808479u,&got,stop)) return -1;
        if(got!=0xAFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808479u;stop->value=got;}return -1;}
        return 1;
    case 0x040423D0u:
        if(!js_v06c_read8(m,0x80847Au,&got,stop)) return -1;
        if(got!=0xA7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80847Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80847Bu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80847Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040423E0u:
        if(!js_v06c_read8(m,0x80847Cu,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80847Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80847Du,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80847Du;stop->value=got;}return -1;}
        return 1;
    case 0x040423F0u:
        if(!js_v06c_read8(m,0x80847Eu,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80847Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80847Fu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80847Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04042400u:
        if(!js_v06c_read8(m,0x808480u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808480u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808481u,&got,stop)) return -1;
        if(got!=0x07u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808481u;stop->value=got;}return -1;}
        return 1;
    case 0x04042410u:
        if(!js_v06c_read8(m,0x808482u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808482u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808483u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808483u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808484u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808484u;stop->value=got;}return -1;}
        return 1;
    case 0x04042428u:
        if(!js_v06c_read8(m,0x808485u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808485u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808486u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808486u;stop->value=got;}return -1;}
        return 1;
    case 0x04042438u:
        if(!js_v06c_read8(m,0x808487u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808487u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808488u,&got,stop)) return -1;
        if(got!=0x32u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808488u;stop->value=got;}return -1;}
        return 1;
    case 0x04042448u:
        if(!js_v06c_read8(m,0x808489u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808489u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80848Au,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80848Au;stop->value=got;}return -1;}
        return 1;
    case 0x0404245Au:
        if(!js_v06c_read8(m,0x80848Bu,&got,stop)) return -1;
        if(got!=0xA7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80848Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80848Cu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80848Cu;stop->value=got;}return -1;}
        return 1;
    case 0x0404246Au:
        if(!js_v06c_read8(m,0x80848Du,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80848Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80848Eu,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80848Eu;stop->value=got;}return -1;}
        return 1;
    case 0x0404247Au:
        if(!js_v06c_read8(m,0x80848Fu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80848Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808490u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808490u;stop->value=got;}return -1;}
        return 1;
    case 0x04042488u:
        if(!js_v06c_read8(m,0x808491u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808491u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808492u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808492u;stop->value=got;}return -1;}
        return 1;
    case 0x04042498u:
        if(!js_v06c_read8(m,0x808493u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808493u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808494u,&got,stop)) return -1;
        if(got!=0x07u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808494u;stop->value=got;}return -1;}
        return 1;
    case 0x040424A8u:
        if(!js_v06c_read8(m,0x808495u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808495u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808496u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808496u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808497u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808497u;stop->value=got;}return -1;}
        return 1;
    case 0x040424C0u:
        if(!js_v06c_read8(m,0x808498u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808498u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808499u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808499u;stop->value=got;}return -1;}
        return 1;
    case 0x040424D0u:
        if(!js_v06c_read8(m,0x80849Au,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80849Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80849Bu,&got,stop)) return -1;
        if(got!=0x32u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80849Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040424E0u:
        if(!js_v06c_read8(m,0x80849Cu,&got,stop)) return -1;
        if(got!=0xA5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80849Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80849Du,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80849Du;stop->value=got;}return -1;}
        return 1;
    case 0x040424F0u:
        if(!js_v06c_read8(m,0x80849Eu,&got,stop)) return -1;
        if(got!=0x29u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80849Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80849Fu,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80849Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084A0u,&got,stop)) return -1;
        if(got!=0x0Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084A0u;stop->value=got;}return -1;}
        return 1;
    case 0x04042508u:
        if(!js_v06c_read8(m,0x8084A1u,&got,stop)) return -1;
        if(got!=0xA8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084A1u;stop->value=got;}return -1;}
        return 1;
    case 0x04042510u:
        if(!js_v06c_read8(m,0x8084A2u,&got,stop)) return -1;
        if(got!=0xA5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084A2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084A3u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084A3u;stop->value=got;}return -1;}
        return 1;
    case 0x04042520u:
        if(!js_v06c_read8(m,0x8084A4u,&got,stop)) return -1;
        if(got!=0x29u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084A4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084A5u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084A5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084A6u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084A6u;stop->value=got;}return -1;}
        return 1;
    case 0x04042538u:
        if(!js_v06c_read8(m,0x8084A7u,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084A7u;stop->value=got;}return -1;}
        return 1;
    case 0x04042540u:
        if(!js_v06c_read8(m,0x8084A8u,&got,stop)) return -1;
        if(got!=0x2Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084A8u;stop->value=got;}return -1;}
        return 1;
    case 0x04042548u:
        if(!js_v06c_read8(m,0x8084A9u,&got,stop)) return -1;
        if(got!=0x2Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084A9u;stop->value=got;}return -1;}
        return 1;
    case 0x04042550u:
        if(!js_v06c_read8(m,0x8084AAu,&got,stop)) return -1;
        if(got!=0x2Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084AAu;stop->value=got;}return -1;}
        return 1;
    case 0x04042558u:
        if(!js_v06c_read8(m,0x8084ABu,&got,stop)) return -1;
        if(got!=0x2Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084ABu;stop->value=got;}return -1;}
        return 1;
    case 0x04042560u:
        if(!js_v06c_read8(m,0x8084ACu,&got,stop)) return -1;
        if(got!=0x69u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084ACu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084ADu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084ADu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084AEu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084AEu;stop->value=got;}return -1;}
        return 1;
    case 0x04042578u:
        if(!js_v06c_read8(m,0x8084AFu,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084AFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084B0u,&got,stop)) return -1;
        if(got!=0x8Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084B0u;stop->value=got;}return -1;}
        return 1;
    case 0x04042588u:
        if(!js_v06c_read8(m,0x8084B1u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084B1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084B2u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084B2u;stop->value=got;}return -1;}
        return 1;
    case 0x0404259Au:
        if(!js_v06c_read8(m,0x8084B3u,&got,stop)) return -1;
        if(got!=0xB7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084B3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084B4u,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084B4u;stop->value=got;}return -1;}
        return 1;
    case 0x040425AAu:
        if(!js_v06c_read8(m,0x8084B5u,&got,stop)) return -1;
        if(got!=0x87u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084B5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084B6u,&got,stop)) return -1;
        if(got!=0x3Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084B6u;stop->value=got;}return -1;}
        return 1;
    case 0x040425BAu:
        if(!js_v06c_read8(m,0x8084B7u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084B7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084B8u,&got,stop)) return -1;
        if(got!=0xE0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084B8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084B9u,&got,stop)) return -1;
        if(got!=0x84u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084B9u;stop->value=got;}return -1;}
        return 1;
    case 0x040425D2u:
        if(!js_v06c_read8(m,0x8084BAu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084BAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084BBu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084BBu;stop->value=got;}return -1;}
        return 1;
    case 0x040425E0u:
        if(!js_v06c_read8(m,0x8084BCu,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084BCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084BDu,&got,stop)) return -1;
        if(got!=0x34u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084BDu;stop->value=got;}return -1;}
        return 1;
    case 0x040425F0u:
        if(!js_v06c_read8(m,0x8084BEu,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084BEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084BFu,&got,stop)) return -1;
        if(got!=0x98u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084BFu;stop->value=got;}return -1;}
        return 1;
    case 0x04042600u:
        if(!js_v06c_read8(m,0x8084C0u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084C0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084C1u,&got,stop)) return -1;
        if(got!=0x3Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084C1u;stop->value=got;}return -1;}
        return 1;
    case 0x04042610u:
        if(!js_v06c_read8(m,0x8084C2u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084C2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084C3u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084C3u;stop->value=got;}return -1;}
        return 1;
    case 0x04042620u:
        if(!js_v06c_read8(m,0x8084C4u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084C4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084C5u,&got,stop)) return -1;
        if(got!=0x3Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084C5u;stop->value=got;}return -1;}
        return 1;
    case 0x04042630u:
        if(!js_v06c_read8(m,0x8084C6u,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084C6u;stop->value=got;}return -1;}
        return 1;
    case 0x04042638u:
        if(!js_v06c_read8(m,0x8084C7u,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084C7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084C8u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084C8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084C9u,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084C9u;stop->value=got;}return -1;}
        return 1;
    case 0x04042650u:
        if(!js_v06c_read8(m,0x8084CAu,&got,stop)) return -1;
        if(got!=0x90u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084CAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084CBu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084CBu;stop->value=got;}return -1;}
        return 1;
    case 0x04042660u:
        if(!js_v06c_read8(m,0x8084CCu,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084CCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084CDu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084CDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084CEu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084CEu;stop->value=got;}return -1;}
        return 1;
    case 0x04042678u:
        if(!js_v06c_read8(m,0x8084CFu,&got,stop)) return -1;
        if(got!=0xCAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084CFu;stop->value=got;}return -1;}
        return 1;
    case 0x04042680u:
        if(!js_v06c_read8(m,0x8084D0u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084D0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084D1u,&got,stop)) return -1;
        if(got!=0x07u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084D1u;stop->value=got;}return -1;}
        return 1;
    case 0x04042690u:
        if(!js_v06c_read8(m,0x8084D2u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084D2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084D3u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084D3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084D4u,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084D4u;stop->value=got;}return -1;}
        return 1;
    case 0x040426A8u:
        if(!js_v06c_read8(m,0x8084D5u,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084D5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084D6u,&got,stop)) return -1;
        if(got!=0x05u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084D6u;stop->value=got;}return -1;}
        return 1;
    case 0x040426B8u:
        if(!js_v06c_read8(m,0x8084D7u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084D7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084D8u,&got,stop)) return -1;
        if(got!=0x3Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084D8u;stop->value=got;}return -1;}
        return 1;
    case 0x040426C8u:
        if(!js_v06c_read8(m,0x8084D9u,&got,stop)) return -1;
        if(got!=0xC6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084D9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084DAu,&got,stop)) return -1;
        if(got!=0x8Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084DAu;stop->value=got;}return -1;}
        return 1;
    case 0x040426D8u:
        if(!js_v06c_read8(m,0x8084DBu,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084DBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084DCu,&got,stop)) return -1;
        if(got!=0xD4u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084DCu;stop->value=got;}return -1;}
        return 1;
    case 0x040426E8u:
        if(!js_v06c_read8(m,0x8084DDu,&got,stop)) return -1;
        if(got!=0x4Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084DDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084DEu,&got,stop)) return -1;
        if(got!=0x29u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084DEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084DFu,&got,stop)) return -1;
        if(got!=0x84u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084DFu;stop->value=got;}return -1;}
        return 1;
    case 0x04042702u:
        if(!js_v06c_read8(m,0x8084E0u,&got,stop)) return -1;
        if(got!=0x48u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084E0u;stop->value=got;}return -1;}
        return 1;
    case 0x0404270Au:
        if(!js_v06c_read8(m,0x8084E1u,&got,stop)) return -1;
        if(got!=0xA5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084E1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084E2u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084E2u;stop->value=got;}return -1;}
        return 1;
    case 0x0404271Au:
        if(!js_v06c_read8(m,0x8084E3u,&got,stop)) return -1;
        if(got!=0x49u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084E3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084E4u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084E4u;stop->value=got;}return -1;}
        return 1;
    case 0x0404272Au:
        if(!js_v06c_read8(m,0x8084E5u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084E5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084E6u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084E6u;stop->value=got;}return -1;}
        return 1;
    case 0x0404273Au:
        if(!js_v06c_read8(m,0x8084E7u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084E7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084E8u,&got,stop)) return -1;
        if(got!=0x04u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084E8u;stop->value=got;}return -1;}
        return 1;
    case 0x0404274Au:
        if(!js_v06c_read8(m,0x8084E9u,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084E9u;stop->value=got;}return -1;}
        return 1;
    case 0x04042752u:
        if(!js_v06c_read8(m,0x8084EAu,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084EAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084EBu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084EBu;stop->value=got;}return -1;}
        return 1;
    case 0x04042762u:
        if(!js_v06c_read8(m,0x8084ECu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084ECu;stop->value=got;}return -1;}
        return 1;
    case 0x0404276Au:
        if(!js_v06c_read8(m,0x8084EDu,&got,stop)) return -1;
        if(got!=0xA5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084EDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084EEu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084EEu;stop->value=got;}return -1;}
        return 1;
    case 0x0404277Au:
        if(!js_v06c_read8(m,0x8084EFu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084EFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084F0u,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084F0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084F1u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084F1u;stop->value=got;}return -1;}
        return 1;
    case 0x04042792u:
        if(!js_v06c_read8(m,0x8084F2u,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084F2u;stop->value=got;}return -1;}
        return 1;
    case 0x0404279Au:
        if(!js_v06c_read8(m,0x8084F3u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084F3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084F4u,&got,stop)) return -1;
        if(got!=0x19u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084F4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8084F5u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084F5u;stop->value=got;}return -1;}
        return 1;
    case 0x040427B2u:
        if(!js_v06c_read8(m,0x8084F6u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8084F6u;stop->value=got;}return -1;}
        return 1;
    case 0x04042960u:
        if(!js_v06c_read8(m,0x80852Cu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80852Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80852Du,&got,stop)) return -1;
        if(got!=0x7Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80852Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80852Eu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80852Eu;stop->value=got;}return -1;}
        return 1;
    case 0x04042978u:
        if(!js_v06c_read8(m,0x80852Fu,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80852Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808530u,&got,stop)) return -1;
        if(got!=0x3Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808530u;stop->value=got;}return -1;}
        return 1;
    case 0x04042988u:
        if(!js_v06c_read8(m,0x808531u,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808531u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808532u,&got,stop)) return -1;
        if(got!=0x07u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808532u;stop->value=got;}return -1;}
        return 1;
    case 0x04042998u:
        if(!js_v06c_read8(m,0x808533u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808533u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808534u,&got,stop)) return -1;
        if(got!=0x38u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808534u;stop->value=got;}return -1;}
        return 1;
    case 0x040429A8u:
        if(!js_v06c_read8(m,0x808535u,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808535u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808536u,&got,stop)) return -1;
        if(got!=0x09u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808536u;stop->value=got;}return -1;}
        return 1;
    case 0x040429B8u:
        if(!js_v06c_read8(m,0x808537u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808537u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808538u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808538u;stop->value=got;}return -1;}
        return 1;
    case 0x040429C8u:
        if(!js_v06c_read8(m,0x808539u,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808539u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80853Au,&got,stop)) return -1;
        if(got!=0x0Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80853Au;stop->value=got;}return -1;}
        return 1;
    case 0x040429D8u:
        if(!js_v06c_read8(m,0x80853Bu,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80853Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80853Cu,&got,stop)) return -1;
        if(got!=0x32u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80853Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040429E8u:
        if(!js_v06c_read8(m,0x80853Du,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80853Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80853Eu,&got,stop)) return -1;
        if(got!=0x05u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80853Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040429F8u:
        if(!js_v06c_read8(m,0x80853Fu,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80853Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808540u,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808540u;stop->value=got;}return -1;}
        return 1;
    case 0x04042A08u:
        if(!js_v06c_read8(m,0x808541u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808541u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808542u,&got,stop)) return -1;
        if(got!=0x3Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808542u;stop->value=got;}return -1;}
        return 1;
    case 0x04042A18u:
        if(!js_v06c_read8(m,0x808543u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808543u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808544u,&got,stop)) return -1;
        if(got!=0x7Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808544u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808545u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808545u;stop->value=got;}return -1;}
        return 1;
    case 0x04042A30u:
        if(!js_v06c_read8(m,0x808546u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808546u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808547u,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808547u;stop->value=got;}return -1;}
        return 1;
    case 0x04042A40u:
        if(!js_v06c_read8(m,0x808548u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808548u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808549u,&got,stop)) return -1;
        if(got!=0x3Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808549u;stop->value=got;}return -1;}
        return 1;
    case 0x04042A50u:
        if(!js_v06c_read8(m,0x80854Au,&got,stop)) return -1;
        if(got!=0xA7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80854Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80854Bu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80854Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04042A60u:
        if(!js_v06c_read8(m,0x80854Cu,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80854Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80854Du,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80854Du;stop->value=got;}return -1;}
        return 1;
    case 0x04042A70u:
        if(!js_v06c_read8(m,0x80854Eu,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80854Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80854Fu,&got,stop)) return -1;
        if(got!=0x07u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80854Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04042A80u:
        if(!js_v06c_read8(m,0x808550u,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808550u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808551u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808551u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808552u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808552u;stop->value=got;}return -1;}
        return 1;
    case 0x04042A98u:
        if(!js_v06c_read8(m,0x808553u,&got,stop)) return -1;
        if(got!=0x84u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808553u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808554u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808554u;stop->value=got;}return -1;}
        return 1;
    case 0x04042AA8u:
        if(!js_v06c_read8(m,0x808555u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808555u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808556u,&got,stop)) return -1;
        if(got!=0x32u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808556u;stop->value=got;}return -1;}
        return 1;
    case 0x04042AB8u:
        if(!js_v06c_read8(m,0x808557u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808557u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808558u,&got,stop)) return -1;
        if(got!=0x34u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808558u;stop->value=got;}return -1;}
        return 1;
    case 0x04042AC8u:
        if(!js_v06c_read8(m,0x808559u,&got,stop)) return -1;
        if(got!=0xA7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808559u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80855Au,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80855Au;stop->value=got;}return -1;}
        return 1;
    case 0x04042AD8u:
        if(!js_v06c_read8(m,0x80855Bu,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80855Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80855Cu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80855Cu;stop->value=got;}return -1;}
        return 1;
    case 0x04042AE8u:
        if(!js_v06c_read8(m,0x80855Du,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80855Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80855Eu,&got,stop)) return -1;
        if(got!=0x07u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80855Eu;stop->value=got;}return -1;}
        return 1;
    case 0x04042AF8u:
        if(!js_v06c_read8(m,0x80855Fu,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80855Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808560u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808560u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808561u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808561u;stop->value=got;}return -1;}
        return 1;
    case 0x04042B10u:
        if(!js_v06c_read8(m,0x808562u,&got,stop)) return -1;
        if(got!=0x84u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808562u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808563u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808563u;stop->value=got;}return -1;}
        return 1;
    case 0x04042B20u:
        if(!js_v06c_read8(m,0x808564u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808564u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808565u,&got,stop)) return -1;
        if(got!=0x32u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808565u;stop->value=got;}return -1;}
        return 1;
    case 0x04042B30u:
        if(!js_v06c_read8(m,0x808566u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808566u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808567u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808567u;stop->value=got;}return -1;}
        return 1;
    case 0x04042B42u:
        if(!js_v06c_read8(m,0x808568u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808568u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808569u,&got,stop)) return -1;
        if(got!=0x35u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808569u;stop->value=got;}return -1;}
        return 1;
    case 0x04042B52u:
        if(!js_v06c_read8(m,0x80856Au,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80856Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80856Bu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80856Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04042B60u:
        if(!js_v06c_read8(m,0x80856Cu,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80856Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80856Du,&got,stop)) return -1;
        if(got!=0xFEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80856Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80856Eu,&got,stop)) return -1;
        if(got!=0x0Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80856Eu;stop->value=got;}return -1;}
        return 1;
    case 0x04042B78u:
        if(!js_v06c_read8(m,0x80856Fu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80856Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808570u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808570u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808571u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808571u;stop->value=got;}return -1;}
        return 1;
    case 0x04042B90u:
        if(!js_v06c_read8(m,0x808572u,&got,stop)) return -1;
        if(got!=0x97u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808572u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808573u,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808573u;stop->value=got;}return -1;}
        return 1;
    case 0x04042BA0u:
        if(!js_v06c_read8(m,0x808574u,&got,stop)) return -1;
        if(got!=0x88u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808574u;stop->value=got;}return -1;}
        return 1;
    case 0x04042BA8u:
        if(!js_v06c_read8(m,0x808575u,&got,stop)) return -1;
        if(got!=0x88u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808575u;stop->value=got;}return -1;}
        return 1;
    case 0x04042BB0u:
        if(!js_v06c_read8(m,0x808576u,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808576u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808577u,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808577u;stop->value=got;}return -1;}
        return 1;
    case 0x04042BC0u:
        if(!js_v06c_read8(m,0x808578u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808578u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808579u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808579u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80857Au,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80857Au;stop->value=got;}return -1;}
        return 1;
    case 0x04042BD8u:
        if(!js_v06c_read8(m,0x80857Bu,&got,stop)) return -1;
        if(got!=0x64u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80857Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80857Cu,&got,stop)) return -1;
        if(got!=0x44u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80857Cu;stop->value=got;}return -1;}
        return 1;
    case 0x04042BE8u:
        if(!js_v06c_read8(m,0x80857Du,&got,stop)) return -1;
        if(got!=0xA5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80857Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80857Eu,&got,stop)) return -1;
        if(got!=0x44u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80857Eu;stop->value=got;}return -1;}
        return 1;
    case 0x04042BF8u:
        if(!js_v06c_read8(m,0x80857Fu,&got,stop)) return -1;
        if(got!=0x4Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80857Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04042C00u:
        if(!js_v06c_read8(m,0x808580u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808580u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808581u,&got,stop)) return -1;
        if(got!=0x44u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808581u;stop->value=got;}return -1;}
        return 1;
    case 0x04042C10u:
        if(!js_v06c_read8(m,0x808582u,&got,stop)) return -1;
        if(got!=0x89u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808582u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808583u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808583u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808584u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808584u;stop->value=got;}return -1;}
        return 1;
    case 0x04042C28u:
        if(!js_v06c_read8(m,0x808585u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808585u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808586u,&got,stop)) return -1;
        if(got!=0x12u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808586u;stop->value=got;}return -1;}
        return 1;
    case 0x04042C38u:
        if(!js_v06c_read8(m,0x808587u,&got,stop)) return -1;
        if(got!=0xA7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808587u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808588u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808588u;stop->value=got;}return -1;}
        return 1;
    case 0x04042C48u:
        if(!js_v06c_read8(m,0x808589u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808589u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80858Au,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80858Au;stop->value=got;}return -1;}
        return 1;
    case 0x04042C58u:
        if(!js_v06c_read8(m,0x80858Bu,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80858Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80858Cu,&got,stop)) return -1;
        if(got!=0x07u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80858Cu;stop->value=got;}return -1;}
        return 1;
    case 0x04042C68u:
        if(!js_v06c_read8(m,0x80858Du,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80858Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80858Eu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80858Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80858Fu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80858Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04042C80u:
        if(!js_v06c_read8(m,0x808590u,&got,stop)) return -1;
        if(got!=0x84u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808590u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808591u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808591u;stop->value=got;}return -1;}
        return 1;
    case 0x04042C90u:
        if(!js_v06c_read8(m,0x808592u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808592u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808593u,&got,stop)) return -1;
        if(got!=0x32u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808593u;stop->value=got;}return -1;}
        return 1;
    case 0x04042CA0u:
        if(!js_v06c_read8(m,0x808594u,&got,stop)) return -1;
        if(got!=0x09u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808594u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808595u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808595u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808596u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808596u;stop->value=got;}return -1;}
        return 1;
    case 0x04042CB8u:
        if(!js_v06c_read8(m,0x808597u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808597u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808598u,&got,stop)) return -1;
        if(got!=0x44u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808598u;stop->value=got;}return -1;}
        return 1;
    case 0x04042CC8u:
        if(!js_v06c_read8(m,0x808599u,&got,stop)) return -1;
        if(got!=0x4Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808599u;stop->value=got;}return -1;}
        return 1;
    case 0x04042CD0u:
        if(!js_v06c_read8(m,0x80859Au,&got,stop)) return -1;
        if(got!=0x90u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80859Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80859Bu,&got,stop)) return -1;
        if(got!=0x32u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80859Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04042CE0u:
        if(!js_v06c_read8(m,0x80859Cu,&got,stop)) return -1;
        if(got!=0xA7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80859Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80859Du,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80859Du;stop->value=got;}return -1;}
        return 1;
    case 0x04042CF0u:
        if(!js_v06c_read8(m,0x80859Eu,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80859Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80859Fu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80859Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04042D00u:
        if(!js_v06c_read8(m,0x8085A0u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085A0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085A1u,&got,stop)) return -1;
        if(got!=0x07u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085A1u;stop->value=got;}return -1;}
        return 1;
    case 0x04042D10u:
        if(!js_v06c_read8(m,0x8085A2u,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085A2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085A3u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085A3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085A4u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085A4u;stop->value=got;}return -1;}
        return 1;
    case 0x04042D28u:
        if(!js_v06c_read8(m,0x8085A5u,&got,stop)) return -1;
        if(got!=0x84u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085A5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085A6u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085A6u;stop->value=got;}return -1;}
        return 1;
    case 0x04042D38u:
        if(!js_v06c_read8(m,0x8085A7u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085A7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085A8u,&got,stop)) return -1;
        if(got!=0x32u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085A8u;stop->value=got;}return -1;}
        return 1;
    case 0x04042D48u:
        if(!js_v06c_read8(m,0x8085A9u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085A9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085AAu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085AAu;stop->value=got;}return -1;}
        return 1;
    case 0x04042D5Au:
        if(!js_v06c_read8(m,0x8085ABu,&got,stop)) return -1;
        if(got!=0x87u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085ABu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085ACu,&got,stop)) return -1;
        if(got!=0x38u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085ACu;stop->value=got;}return -1;}
        return 1;
    case 0x04042D6Au:
        if(!js_v06c_read8(m,0x8085ADu,&got,stop)) return -1;
        if(got!=0x87u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085ADu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085AEu,&got,stop)) return -1;
        if(got!=0x3Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085AEu;stop->value=got;}return -1;}
        return 1;
    case 0x04042D7Au:
        if(!js_v06c_read8(m,0x8085AFu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085AFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085B0u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085B0u;stop->value=got;}return -1;}
        return 1;
    case 0x04042D88u:
        if(!js_v06c_read8(m,0x8085B1u,&got,stop)) return -1;
        if(got!=0xC6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085B1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085B2u,&got,stop)) return -1;
        if(got!=0x34u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085B2u;stop->value=got;}return -1;}
        return 1;
    case 0x04042D98u:
        if(!js_v06c_read8(m,0x8085B3u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085B3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085B4u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085B4u;stop->value=got;}return -1;}
        return 1;
    case 0x04042DA8u:
        if(!js_v06c_read8(m,0x8085B5u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085B5u;stop->value=got;}return -1;}
        return 1;
    case 0x04042DB0u:
        if(!js_v06c_read8(m,0x8085B6u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085B6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085B7u,&got,stop)) return -1;
        if(got!=0x38u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085B7u;stop->value=got;}return -1;}
        return 1;
    case 0x04042DC0u:
        if(!js_v06c_read8(m,0x8085B8u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085B8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085B9u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085B9u;stop->value=got;}return -1;}
        return 1;
    case 0x04042DD0u:
        if(!js_v06c_read8(m,0x8085BAu,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085BAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085BBu,&got,stop)) return -1;
        if(got!=0x3Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085BBu;stop->value=got;}return -1;}
        return 1;
    case 0x04042DE0u:
        if(!js_v06c_read8(m,0x8085BCu,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085BCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085BDu,&got,stop)) return -1;
        if(got!=0x3Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085BDu;stop->value=got;}return -1;}
        return 1;
    case 0x04042DF0u:
        if(!js_v06c_read8(m,0x8085BEu,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085BEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085BFu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085BFu;stop->value=got;}return -1;}
        return 1;
    case 0x04042E00u:
        if(!js_v06c_read8(m,0x8085C0u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085C0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085C1u,&got,stop)) return -1;
        if(got!=0x3Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085C1u;stop->value=got;}return -1;}
        return 1;
    case 0x04042E10u:
        if(!js_v06c_read8(m,0x8085C2u,&got,stop)) return -1;
        if(got!=0xCAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085C2u;stop->value=got;}return -1;}
        return 1;
    case 0x04042E18u:
        if(!js_v06c_read8(m,0x8085C3u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085C3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085C4u,&got,stop)) return -1;
        if(got!=0xB8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085C4u;stop->value=got;}return -1;}
        return 1;
    case 0x04042E28u:
        if(!js_v06c_read8(m,0x8085C5u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085C5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085C6u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085C6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085C7u,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085C7u;stop->value=got;}return -1;}
        return 1;
    case 0x04042E40u:
        if(!js_v06c_read8(m,0x8085C8u,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085C8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085C9u,&got,stop)) return -1;
        if(got!=0x05u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085C9u;stop->value=got;}return -1;}
        return 1;
    case 0x04042E50u:
        if(!js_v06c_read8(m,0x8085CAu,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085CAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085CBu,&got,stop)) return -1;
        if(got!=0x3Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085CBu;stop->value=got;}return -1;}
        return 1;
    case 0x04042E60u:
        if(!js_v06c_read8(m,0x8085CCu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085CCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085CDu,&got,stop)) return -1;
        if(got!=0xAFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085CDu;stop->value=got;}return -1;}
        return 1;
    case 0x04042E70u:
        if(!js_v06c_read8(m,0x8085CEu,&got,stop)) return -1;
        if(got!=0xA7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085CEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085CFu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085CFu;stop->value=got;}return -1;}
        return 1;
    case 0x04042E80u:
        if(!js_v06c_read8(m,0x8085D0u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085D0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085D1u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085D1u;stop->value=got;}return -1;}
        return 1;
    case 0x04042E90u:
        if(!js_v06c_read8(m,0x8085D2u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085D2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085D3u,&got,stop)) return -1;
        if(got!=0x07u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085D3u;stop->value=got;}return -1;}
        return 1;
    case 0x04042EA0u:
        if(!js_v06c_read8(m,0x8085D4u,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085D4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085D5u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085D5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085D6u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085D6u;stop->value=got;}return -1;}
        return 1;
    case 0x04042EB8u:
        if(!js_v06c_read8(m,0x8085D7u,&got,stop)) return -1;
        if(got!=0x84u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085D7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085D8u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085D8u;stop->value=got;}return -1;}
        return 1;
    case 0x04042EC8u:
        if(!js_v06c_read8(m,0x8085D9u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085D9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085DAu,&got,stop)) return -1;
        if(got!=0x32u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085DAu;stop->value=got;}return -1;}
        return 1;
    case 0x04042ED8u:
        if(!js_v06c_read8(m,0x8085DBu,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085DBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085DCu,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085DCu;stop->value=got;}return -1;}
        return 1;
    case 0x04042EE8u:
        if(!js_v06c_read8(m,0x8085DDu,&got,stop)) return -1;
        if(got!=0xA7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085DDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085DEu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085DEu;stop->value=got;}return -1;}
        return 1;
    case 0x04042EF8u:
        if(!js_v06c_read8(m,0x8085DFu,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085DFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085E0u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085E0u;stop->value=got;}return -1;}
        return 1;
    case 0x04042F08u:
        if(!js_v06c_read8(m,0x8085E1u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085E1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085E2u,&got,stop)) return -1;
        if(got!=0x07u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085E2u;stop->value=got;}return -1;}
        return 1;
    case 0x04042F18u:
        if(!js_v06c_read8(m,0x8085E3u,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085E3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085E4u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085E4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085E5u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085E5u;stop->value=got;}return -1;}
        return 1;
    case 0x04042F30u:
        if(!js_v06c_read8(m,0x8085E6u,&got,stop)) return -1;
        if(got!=0x84u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085E6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085E7u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085E7u;stop->value=got;}return -1;}
        return 1;
    case 0x04042F40u:
        if(!js_v06c_read8(m,0x8085E8u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085E8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085E9u,&got,stop)) return -1;
        if(got!=0x32u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085E9u;stop->value=got;}return -1;}
        return 1;
    case 0x04042F50u:
        if(!js_v06c_read8(m,0x8085EAu,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085EAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085EBu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085EBu;stop->value=got;}return -1;}
        return 1;
    case 0x04042F62u:
        if(!js_v06c_read8(m,0x8085ECu,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085ECu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085EDu,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085EDu;stop->value=got;}return -1;}
        return 1;
    case 0x04042F72u:
        if(!js_v06c_read8(m,0x8085EEu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085EEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085EFu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085EFu;stop->value=got;}return -1;}
        return 1;
    case 0x04042F80u:
        if(!js_v06c_read8(m,0x8085F0u,&got,stop)) return -1;
        if(got!=0xA5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085F0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085F1u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085F1u;stop->value=got;}return -1;}
        return 1;
    case 0x04042F90u:
        if(!js_v06c_read8(m,0x8085F2u,&got,stop)) return -1;
        if(got!=0x29u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085F2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085F3u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085F3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085F4u,&got,stop)) return -1;
        if(got!=0x0Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085F4u;stop->value=got;}return -1;}
        return 1;
    case 0x04042FA8u:
        if(!js_v06c_read8(m,0x8085F5u,&got,stop)) return -1;
        if(got!=0xA8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085F5u;stop->value=got;}return -1;}
        return 1;
    case 0x04042FB0u:
        if(!js_v06c_read8(m,0x8085F6u,&got,stop)) return -1;
        if(got!=0xA5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085F6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085F7u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085F7u;stop->value=got;}return -1;}
        return 1;
    case 0x04042FC0u:
        if(!js_v06c_read8(m,0x8085F8u,&got,stop)) return -1;
        if(got!=0x29u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085F8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085F9u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085F9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8085FAu,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085FAu;stop->value=got;}return -1;}
        return 1;
    case 0x04042FD8u:
        if(!js_v06c_read8(m,0x8085FBu,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085FBu;stop->value=got;}return -1;}
        return 1;
    case 0x04042FE0u:
        if(!js_v06c_read8(m,0x8085FCu,&got,stop)) return -1;
        if(got!=0x2Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085FCu;stop->value=got;}return -1;}
        return 1;
    case 0x04042FE8u:
        if(!js_v06c_read8(m,0x8085FDu,&got,stop)) return -1;
        if(got!=0x2Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085FDu;stop->value=got;}return -1;}
        return 1;
    case 0x04042FF0u:
        if(!js_v06c_read8(m,0x8085FEu,&got,stop)) return -1;
        if(got!=0x2Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085FEu;stop->value=got;}return -1;}
        return 1;
    case 0x04042FF8u:
        if(!js_v06c_read8(m,0x8085FFu,&got,stop)) return -1;
        if(got!=0x2Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8085FFu;stop->value=got;}return -1;}
        return 1;
    case 0x04043000u:
        if(!js_v06c_read8(m,0x808600u,&got,stop)) return -1;
        if(got!=0x69u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808600u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808601u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808601u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808602u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808602u;stop->value=got;}return -1;}
        return 1;
    case 0x04043018u:
        if(!js_v06c_read8(m,0x808603u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808603u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808604u,&got,stop)) return -1;
        if(got!=0x8Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808604u;stop->value=got;}return -1;}
        return 1;
    case 0x04043028u:
        if(!js_v06c_read8(m,0x808605u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808605u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808606u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808606u;stop->value=got;}return -1;}
        return 1;
    case 0x0404303Au:
        if(!js_v06c_read8(m,0x808607u,&got,stop)) return -1;
        if(got!=0xB7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808607u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808608u,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808608u;stop->value=got;}return -1;}
        return 1;
    case 0x0404304Au:
        if(!js_v06c_read8(m,0x808609u,&got,stop)) return -1;
        if(got!=0x87u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808609u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80860Au,&got,stop)) return -1;
        if(got!=0x38u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80860Au;stop->value=got;}return -1;}
        return 1;
    case 0x0404305Au:
        if(!js_v06c_read8(m,0x80860Bu,&got,stop)) return -1;
        if(got!=0x87u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80860Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80860Cu,&got,stop)) return -1;
        if(got!=0x3Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80860Cu;stop->value=got;}return -1;}
        return 1;
    case 0x0404306Au:
        if(!js_v06c_read8(m,0x80860Du,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80860Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80860Eu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80860Eu;stop->value=got;}return -1;}
        return 1;
    case 0x04043078u:
        if(!js_v06c_read8(m,0x80860Fu,&got,stop)) return -1;
        if(got!=0xC6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80860Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808610u,&got,stop)) return -1;
        if(got!=0x34u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808610u;stop->value=got;}return -1;}
        return 1;
    case 0x04043088u:
        if(!js_v06c_read8(m,0x808611u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808611u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808612u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808612u;stop->value=got;}return -1;}
        return 1;
    case 0x04043098u:
        if(!js_v06c_read8(m,0x808613u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808613u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808614u,&got,stop)) return -1;
        if(got!=0x38u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808614u;stop->value=got;}return -1;}
        return 1;
    case 0x040430A8u:
        if(!js_v06c_read8(m,0x808615u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808615u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808616u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808616u;stop->value=got;}return -1;}
        return 1;
    case 0x040430B8u:
        if(!js_v06c_read8(m,0x808617u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808617u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808618u,&got,stop)) return -1;
        if(got!=0x3Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808618u;stop->value=got;}return -1;}
        return 1;
    case 0x040430C8u:
        if(!js_v06c_read8(m,0x808619u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808619u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80861Au,&got,stop)) return -1;
        if(got!=0x3Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80861Au;stop->value=got;}return -1;}
        return 1;
    case 0x040430D8u:
        if(!js_v06c_read8(m,0x80861Bu,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80861Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80861Cu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80861Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040430E8u:
        if(!js_v06c_read8(m,0x80861Du,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80861Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80861Eu,&got,stop)) return -1;
        if(got!=0x3Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80861Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040430F8u:
        if(!js_v06c_read8(m,0x80861Fu,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80861Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04043100u:
        if(!js_v06c_read8(m,0x808620u,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808620u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808621u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808621u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808622u,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808622u;stop->value=got;}return -1;}
        return 1;
    case 0x04043118u:
        if(!js_v06c_read8(m,0x808623u,&got,stop)) return -1;
        if(got!=0x90u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808623u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808624u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808624u;stop->value=got;}return -1;}
        return 1;
    case 0x04043128u:
        if(!js_v06c_read8(m,0x808625u,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808625u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808626u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808626u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808627u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808627u;stop->value=got;}return -1;}
        return 1;
    case 0x04043140u:
        if(!js_v06c_read8(m,0x808628u,&got,stop)) return -1;
        if(got!=0xCAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808628u;stop->value=got;}return -1;}
        return 1;
    case 0x04043148u:
        if(!js_v06c_read8(m,0x808629u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808629u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80862Au,&got,stop)) return -1;
        if(got!=0x07u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80862Au;stop->value=got;}return -1;}
        return 1;
    case 0x04043158u:
        if(!js_v06c_read8(m,0x80862Bu,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80862Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80862Cu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80862Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80862Du,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80862Du;stop->value=got;}return -1;}
        return 1;
    case 0x04043170u:
        if(!js_v06c_read8(m,0x80862Eu,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80862Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80862Fu,&got,stop)) return -1;
        if(got!=0x05u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80862Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04043180u:
        if(!js_v06c_read8(m,0x808630u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808630u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808631u,&got,stop)) return -1;
        if(got!=0x3Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808631u;stop->value=got;}return -1;}
        return 1;
    case 0x04043190u:
        if(!js_v06c_read8(m,0x808632u,&got,stop)) return -1;
        if(got!=0xC6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808632u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808633u,&got,stop)) return -1;
        if(got!=0x8Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808633u;stop->value=got;}return -1;}
        return 1;
    case 0x040431A0u:
        if(!js_v06c_read8(m,0x808634u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808634u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808635u,&got,stop)) return -1;
        if(got!=0xCFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808635u;stop->value=got;}return -1;}
        return 1;
    case 0x040431B0u:
        if(!js_v06c_read8(m,0x808636u,&got,stop)) return -1;
        if(got!=0x82u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808636u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808637u,&got,stop)) return -1;
        if(got!=0x44u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808637u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808638u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808638u;stop->value=got;}return -1;}
        return 1;
    default: return 0;
    }
}
