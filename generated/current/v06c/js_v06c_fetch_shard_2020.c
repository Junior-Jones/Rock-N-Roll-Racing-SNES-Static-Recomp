#include "js_v06c_fetch.h"

int js_v06c_fetch_shard_2020(JSV06Machine *m, JSV06Stop *stop) {
    uint8_t got;
    switch(js_cpu_context_key(&m->cpu)) {
    case 0x04040067u:
        if(!js_v06c_read8(m,0x80800Cu,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80800Cu;stop->value=got;}return -1;}
        return 1;
    case 0x0404006Fu:
        if(!js_v06c_read8(m,0x80800Du,&got,stop)) return -1;
        if(got!=0xFBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80800Du;stop->value=got;}return -1;}
        return 1;
    case 0x04040073u:
        if(!js_v06c_read8(m,0x80800Eu,&got,stop)) return -1;
        if(got!=0x4Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80800Eu;stop->value=got;}return -1;}
        return 1;
    case 0x0404007Bu:
        if(!js_v06c_read8(m,0x80800Fu,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80800Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04040083u:
        if(!js_v06c_read8(m,0x808010u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808010u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808011u,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808011u;stop->value=got;}return -1;}
        return 1;
    case 0x04040092u:
        if(!js_v06c_read8(m,0x808012u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808012u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808013u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808013u;stop->value=got;}return -1;}
        return 1;
    case 0x040400A2u:
        if(!js_v06c_read8(m,0x808014u,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808014u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808015u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808015u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808016u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808016u;stop->value=got;}return -1;}
        return 1;
    case 0x040400BAu:
        if(!js_v06c_read8(m,0x808017u,&got,stop)) return -1;
        if(got!=0x99u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808017u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808018u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808018u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808019u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808019u;stop->value=got;}return -1;}
        return 1;
    case 0x040400D2u:
        if(!js_v06c_read8(m,0x80801Au,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80801Au;stop->value=got;}return -1;}
        return 1;
    case 0x040400DAu:
        if(!js_v06c_read8(m,0x80801Bu,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80801Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80801Cu,&got,stop)) return -1;
        if(got!=0x31u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80801Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80801Du,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80801Du;stop->value=got;}return -1;}
        return 1;
    case 0x040400F2u:
        if(!js_v06c_read8(m,0x80801Eu,&got,stop)) return -1;
        if(got!=0x90u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80801Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80801Fu,&got,stop)) return -1;
        if(got!=0xF7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80801Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04040102u:
        if(!js_v06c_read8(m,0x808020u,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808020u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808021u,&got,stop)) return -1;
        if(got!=0x39u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808021u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808022u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808022u;stop->value=got;}return -1;}
        return 1;
    case 0x0404011Au:
        if(!js_v06c_read8(m,0x808023u,&got,stop)) return -1;
        if(got!=0x99u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808023u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808024u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808024u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808025u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808025u;stop->value=got;}return -1;}
        return 1;
    case 0x04040132u:
        if(!js_v06c_read8(m,0x808026u,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808026u;stop->value=got;}return -1;}
        return 1;
    case 0x0404013Au:
        if(!js_v06c_read8(m,0x808027u,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808027u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808028u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808028u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808029u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808029u;stop->value=got;}return -1;}
        return 1;
    case 0x04040152u:
        if(!js_v06c_read8(m,0x80802Au,&got,stop)) return -1;
        if(got!=0x90u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80802Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80802Bu,&got,stop)) return -1;
        if(got!=0xF7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80802Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04040162u:
        if(!js_v06c_read8(m,0x80802Cu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80802Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80802Du,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80802Du;stop->value=got;}return -1;}
        return 1;
    case 0x04040170u:
        if(!js_v06c_read8(m,0x80802Eu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80802Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80802Fu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80802Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808030u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808030u;stop->value=got;}return -1;}
        return 1;
    case 0x04040188u:
        if(!js_v06c_read8(m,0x808031u,&got,stop)) return -1;
        if(got!=0x5Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808031u;stop->value=got;}return -1;}
        return 1;
    case 0x04040190u:
        if(!js_v06c_read8(m,0x808032u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808032u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808033u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808033u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808034u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808034u;stop->value=got;}return -1;}
        return 1;
    case 0x040401A8u:
        if(!js_v06c_read8(m,0x808035u,&got,stop)) return -1;
        if(got!=0x1Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808035u;stop->value=got;}return -1;}
        return 1;
    case 0x040401B0u:
        if(!js_v06c_read8(m,0x808036u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808036u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808037u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808037u;stop->value=got;}return -1;}
        return 1;
    case 0x040401C3u:
        if(!js_v06c_read8(m,0x808038u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808038u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808039u,&got,stop)) return -1;
        if(got!=0x72u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808039u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80803Au,&got,stop)) return -1;
        if(got!=0xEFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80803Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80803Bu,&got,stop)) return -1;
        if(got!=0x92u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80803Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040401E3u:
        if(!js_v06c_read8(m,0x80803Cu,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80803Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80803Du,&got,stop)) return -1;
        if(got!=0xF1u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80803Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80803Eu,&got,stop)) return -1;
        if(got!=0xEFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80803Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80803Fu,&got,stop)) return -1;
        if(got!=0x92u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80803Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04040203u:
        if(!js_v06c_read8(m,0x808040u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808040u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808041u,&got,stop)) return -1;
        if(got!=0x38u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808041u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808042u,&got,stop)) return -1;
        if(got!=0x81u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808042u;stop->value=got;}return -1;}
        return 1;
    case 0x0404021Bu:
        if(!js_v06c_read8(m,0x808043u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808043u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808044u,&got,stop)) return -1;
        if(got!=0x4Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808044u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808045u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808045u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808046u,&got,stop)) return -1;
        if(got!=0x92u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808046u;stop->value=got;}return -1;}
        return 1;
    case 0x0404023Bu:
        if(!js_v06c_read8(m,0x808047u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808047u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808048u,&got,stop)) return -1;
        if(got!=0xDBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808048u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808049u,&got,stop)) return -1;
        if(got!=0xF8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808049u;stop->value=got;}return -1;}
        return 1;
    case 0x04040253u:
        if(!js_v06c_read8(m,0x80804Au,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80804Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80804Bu,&got,stop)) return -1;
        if(got!=0x14u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80804Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80804Cu,&got,stop)) return -1;
        if(got!=0x81u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80804Cu;stop->value=got;}return -1;}
        return 1;
    case 0x0404026Bu:
        if(!js_v06c_read8(m,0x80804Du,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80804Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80804Eu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80804Eu;stop->value=got;}return -1;}
        return 1;
    case 0x0404027Bu:
        if(!js_v06c_read8(m,0x80804Fu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80804Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808050u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808050u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808051u,&got,stop)) return -1;
        if(got!=0x0Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808051u;stop->value=got;}return -1;}
        return 1;
    case 0x04040293u:
        if(!js_v06c_read8(m,0x808052u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808052u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808053u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808053u;stop->value=got;}return -1;}
        return 1;
    case 0x040402A3u:
        if(!js_v06c_read8(m,0x808054u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808054u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808055u,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808055u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808056u,&got,stop)) return -1;
        if(got!=0xACu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808056u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808057u,&got,stop)) return -1;
        if(got!=0x81u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808057u;stop->value=got;}return -1;}
        return 1;
    case 0x040408A3u:
        if(!js_v06c_read8(m,0x808114u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808114u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808115u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808115u;stop->value=got;}return -1;}
        return 1;
    case 0x040408B3u:
        if(!js_v06c_read8(m,0x808116u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808116u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808117u,&got,stop)) return -1;
        if(got!=0x7Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808117u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808118u,&got,stop)) return -1;
        if(got!=0xF9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808118u;stop->value=got;}return -1;}
        return 1;
    case 0x040408CBu:
        if(!js_v06c_read8(m,0x808119u,&got,stop)) return -1;
        if(got!=0xACu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808119u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80811Au,&got,stop)) return -1;
        if(got!=0xECu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80811Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80811Bu,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80811Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040408E3u:
        if(!js_v06c_read8(m,0x80811Cu,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80811Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040408EBu:
        if(!js_v06c_read8(m,0x80811Du,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80811Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80811Eu,&got,stop)) return -1;
        if(got!=0x05u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80811Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040408FBu:
        if(!js_v06c_read8(m,0x80811Fu,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80811Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808120u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808120u;stop->value=got;}return -1;}
        return 1;
    case 0x0404090Bu:
        if(!js_v06c_read8(m,0x808121u,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808121u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808122u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808122u;stop->value=got;}return -1;}
        return 1;
    case 0x0404091Bu:
        if(!js_v06c_read8(m,0x808123u,&got,stop)) return -1;
        if(got!=0x8Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808123u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808124u,&got,stop)) return -1;
        if(got!=0xECu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808124u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808125u,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808125u;stop->value=got;}return -1;}
        return 1;
    case 0x04040933u:
        if(!js_v06c_read8(m,0x808126u,&got,stop)) return -1;
        if(got!=0xBEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808126u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808127u,&got,stop)) return -1;
        if(got!=0xF2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808127u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808128u,&got,stop)) return -1;
        if(got!=0x82u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808128u;stop->value=got;}return -1;}
        return 1;
    case 0x0404094Bu:
        if(!js_v06c_read8(m,0x808129u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808129u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80812Au,&got,stop)) return -1;
        if(got!=0x04u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80812Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80812Bu,&got,stop)) return -1;
        if(got!=0xF9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80812Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04040963u:
        if(!js_v06c_read8(m,0x80812Cu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80812Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80812Du,&got,stop)) return -1;
        if(got!=0x86u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80812Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80812Eu,&got,stop)) return -1;
        if(got!=0xF9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80812Eu;stop->value=got;}return -1;}
        return 1;
    case 0x0404097Bu:
        if(!js_v06c_read8(m,0x80812Fu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80812Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040409C3u:
        if(!js_v06c_read8(m,0x808138u,&got,stop)) return -1;
        if(got!=0x78u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808138u;stop->value=got;}return -1;}
        return 1;
    case 0x040409CBu:
        if(!js_v06c_read8(m,0x808139u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808139u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80813Au,&got,stop)) return -1;
        if(got!=0x09u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80813Au;stop->value=got;}return -1;}
        return 1;
    case 0x040409DBu:
        if(!js_v06c_read8(m,0x80813Bu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80813Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80813Cu,&got,stop)) return -1;
        if(got!=0x05u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80813Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80813Du,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80813Du;stop->value=got;}return -1;}
        return 1;
    case 0x040409F3u:
        if(!js_v06c_read8(m,0x80813Eu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80813Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80813Fu,&got,stop)) return -1;
        if(got!=0x61u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80813Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04040A03u:
        if(!js_v06c_read8(m,0x808140u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808140u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808141u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808141u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808142u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808142u;stop->value=got;}return -1;}
        return 1;
    case 0x04040A1Bu:
        if(!js_v06c_read8(m,0x808143u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808143u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808144u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808144u;stop->value=got;}return -1;}
        return 1;
    case 0x04040A2Bu:
        if(!js_v06c_read8(m,0x808145u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808145u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808146u,&got,stop)) return -1;
        if(got!=0x07u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808146u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808147u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808147u;stop->value=got;}return -1;}
        return 1;
    case 0x04040A43u:
        if(!js_v06c_read8(m,0x808148u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808148u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808149u,&got,stop)) return -1;
        if(got!=0x11u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808149u;stop->value=got;}return -1;}
        return 1;
    case 0x04040A53u:
        if(!js_v06c_read8(m,0x80814Au,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80814Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80814Bu,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80814Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80814Cu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80814Cu;stop->value=got;}return -1;}
        return 1;
    case 0x04040A6Bu:
        if(!js_v06c_read8(m,0x80814Du,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80814Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80814Eu,&got,stop)) return -1;
        if(got!=0x3Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80814Eu;stop->value=got;}return -1;}
        return 1;
    case 0x04040A7Bu:
        if(!js_v06c_read8(m,0x80814Fu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80814Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808150u,&got,stop)) return -1;
        if(got!=0x09u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808150u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808151u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808151u;stop->value=got;}return -1;}
        return 1;
    case 0x04040A93u:
        if(!js_v06c_read8(m,0x808152u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808152u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808153u,&got,stop)) return -1;
        if(got!=0x44u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808153u;stop->value=got;}return -1;}
        return 1;
    case 0x04040AA3u:
        if(!js_v06c_read8(m,0x808154u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808154u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808155u,&got,stop)) return -1;
        if(got!=0x0Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808155u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808156u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808156u;stop->value=got;}return -1;}
        return 1;
    case 0x04040ABBu:
        if(!js_v06c_read8(m,0x808157u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808157u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808158u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808158u;stop->value=got;}return -1;}
        return 1;
    case 0x04040ACBu:
        if(!js_v06c_read8(m,0x808159u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808159u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80815Au,&got,stop)) return -1;
        if(got!=0x0Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80815Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80815Bu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80815Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04040AE3u:
        if(!js_v06c_read8(m,0x80815Cu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80815Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80815Du,&got,stop)) return -1;
        if(got!=0x17u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80815Du;stop->value=got;}return -1;}
        return 1;
    case 0x04040AF3u:
        if(!js_v06c_read8(m,0x80815Eu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80815Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80815Fu,&got,stop)) return -1;
        if(got!=0x2Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80815Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808160u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808160u;stop->value=got;}return -1;}
        return 1;
    case 0x04040B0Bu:
        if(!js_v06c_read8(m,0x808161u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808161u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808162u,&got,stop)) return -1;
        if(got!=0x2Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808162u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808163u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808163u;stop->value=got;}return -1;}
        return 1;
    case 0x04040B23u:
        if(!js_v06c_read8(m,0x808164u,&got,stop)) return -1;
        if(got!=0x58u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808164u;stop->value=got;}return -1;}
        return 1;
    case 0x04040B2Bu:
        if(!js_v06c_read8(m,0x808165u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808165u;stop->value=got;}return -1;}
        return 1;
    case 0x04040B50u:
        if(!js_v06c_read8(m,0x80816Au,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80816Au;stop->value=got;}return -1;}
        return 1;
    case 0x04040B51u:
        if(!js_v06c_read8(m,0x80816Au,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80816Au;stop->value=got;}return -1;}
        return 1;
    case 0x04040B52u:
        if(!js_v06c_read8(m,0x80816Au,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80816Au;stop->value=got;}return -1;}
        return 1;
    case 0x04040B53u:
        if(!js_v06c_read8(m,0x80816Au,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80816Au;stop->value=got;}return -1;}
        return 1;
    case 0x04040B57u:
        if(!js_v06c_read8(m,0x80816Au,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80816Au;stop->value=got;}return -1;}
        return 1;
    case 0x04040B58u:
        if(!js_v06c_read8(m,0x80816Bu,&got,stop)) return -1;
        if(got!=0x4Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80816Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04040B59u:
        if(!js_v06c_read8(m,0x80816Bu,&got,stop)) return -1;
        if(got!=0x4Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80816Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04040B5Au:
        if(!js_v06c_read8(m,0x80816Bu,&got,stop)) return -1;
        if(got!=0x4Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80816Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04040B5Bu:
        if(!js_v06c_read8(m,0x80816Bu,&got,stop)) return -1;
        if(got!=0x4Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80816Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04040B5Fu:
        if(!js_v06c_read8(m,0x80816Bu,&got,stop)) return -1;
        if(got!=0x4Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80816Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04040B60u:
        if(!js_v06c_read8(m,0x80816Cu,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80816Cu;stop->value=got;}return -1;}
        return 1;
    case 0x04040B61u:
        if(!js_v06c_read8(m,0x80816Cu,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80816Cu;stop->value=got;}return -1;}
        return 1;
    case 0x04040B62u:
        if(!js_v06c_read8(m,0x80816Cu,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80816Cu;stop->value=got;}return -1;}
        return 1;
    case 0x04040B63u:
        if(!js_v06c_read8(m,0x80816Cu,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80816Cu;stop->value=got;}return -1;}
        return 1;
    case 0x04040B67u:
        if(!js_v06c_read8(m,0x80816Cu,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80816Cu;stop->value=got;}return -1;}
        return 1;
    case 0x04040B68u:
        if(!js_v06c_read8(m,0x80816Du,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80816Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80816Eu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80816Eu;stop->value=got;}return -1;}
        return 1;
    case 0x04040B69u:
        if(!js_v06c_read8(m,0x80816Du,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80816Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80816Eu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80816Eu;stop->value=got;}return -1;}
        return 1;
    case 0x04040B6Au:
        if(!js_v06c_read8(m,0x80816Du,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80816Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80816Eu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80816Eu;stop->value=got;}return -1;}
        return 1;
    case 0x04040B6Bu:
        if(!js_v06c_read8(m,0x80816Du,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80816Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80816Eu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80816Eu;stop->value=got;}return -1;}
        return 1;
    case 0x04040B6Fu:
        if(!js_v06c_read8(m,0x80816Du,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80816Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80816Eu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80816Eu;stop->value=got;}return -1;}
        return 1;
    case 0x04040B78u:
        if(!js_v06c_read8(m,0x80816Fu,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80816Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808170u,&got,stop)) return -1;
        if(got!=0x2Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808170u;stop->value=got;}return -1;}
        return 1;
    case 0x04040B7Fu:
        if(!js_v06c_read8(m,0x80816Fu,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80816Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808170u,&got,stop)) return -1;
        if(got!=0x2Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808170u;stop->value=got;}return -1;}
        return 1;
    case 0x04040B88u:
        if(!js_v06c_read8(m,0x808171u,&got,stop)) return -1;
        if(got!=0x86u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808171u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808172u,&got,stop)) return -1;
        if(got!=0x2Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808172u;stop->value=got;}return -1;}
        return 1;
    case 0x04040B8Fu:
        if(!js_v06c_read8(m,0x808171u,&got,stop)) return -1;
        if(got!=0x86u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808171u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808172u,&got,stop)) return -1;
        if(got!=0x2Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808172u;stop->value=got;}return -1;}
        return 1;
    case 0x04040B98u:
        if(!js_v06c_read8(m,0x808173u,&got,stop)) return -1;
        if(got!=0x84u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808173u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808174u,&got,stop)) return -1;
        if(got!=0x2Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808174u;stop->value=got;}return -1;}
        return 1;
    case 0x04040B9Fu:
        if(!js_v06c_read8(m,0x808173u,&got,stop)) return -1;
        if(got!=0x84u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808173u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808174u,&got,stop)) return -1;
        if(got!=0x2Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808174u;stop->value=got;}return -1;}
        return 1;
    case 0x04040BA8u:
        if(!js_v06c_read8(m,0x808175u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808175u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808176u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808176u;stop->value=got;}return -1;}
        return 1;
    case 0x04040BAFu:
        if(!js_v06c_read8(m,0x808175u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808175u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808176u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808176u;stop->value=got;}return -1;}
        return 1;
    case 0x04040BBBu:
        if(!js_v06c_read8(m,0x808177u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808177u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808178u,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808178u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808179u,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808179u;stop->value=got;}return -1;}
        return 1;
    case 0x04040BBFu:
        if(!js_v06c_read8(m,0x808177u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808177u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808178u,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808178u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808179u,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808179u;stop->value=got;}return -1;}
        return 1;
    case 0x04040BD3u:
        if(!js_v06c_read8(m,0x80817Au,&got,stop)) return -1;
        if(got!=0x29u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80817Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80817Bu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80817Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04040BD7u:
        if(!js_v06c_read8(m,0x80817Au,&got,stop)) return -1;
        if(got!=0x29u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80817Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80817Bu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80817Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04040BE3u:
        if(!js_v06c_read8(m,0x80817Cu,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80817Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80817Du,&got,stop)) return -1;
        if(got!=0x0Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80817Du;stop->value=got;}return -1;}
        return 1;
    case 0x04040BE7u:
        if(!js_v06c_read8(m,0x80817Cu,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80817Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80817Du,&got,stop)) return -1;
        if(got!=0x0Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80817Du;stop->value=got;}return -1;}
        return 1;
    case 0x04040BF3u:
        if(!js_v06c_read8(m,0x80817Eu,&got,stop)) return -1;
        if(got!=0xAEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80817Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80817Fu,&got,stop)) return -1;
        if(got!=0x55u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80817Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808180u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808180u;stop->value=got;}return -1;}
        return 1;
    case 0x04040BF7u:
        if(!js_v06c_read8(m,0x80817Eu,&got,stop)) return -1;
        if(got!=0xAEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80817Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80817Fu,&got,stop)) return -1;
        if(got!=0x55u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80817Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808180u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808180u;stop->value=got;}return -1;}
        return 1;
    case 0x04040C0Bu:
        if(!js_v06c_read8(m,0x808181u,&got,stop)) return -1;
        if(got!=0xFCu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808181u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808182u,&got,stop)) return -1;
        if(got!=0x97u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808182u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808183u,&got,stop)) return -1;
        if(got!=0x81u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808183u;stop->value=got;}return -1;}
        return 1;
    case 0x04040C0Fu:
        if(!js_v06c_read8(m,0x808181u,&got,stop)) return -1;
        if(got!=0xFCu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808181u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808182u,&got,stop)) return -1;
        if(got!=0x97u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808182u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808183u,&got,stop)) return -1;
        if(got!=0x81u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808183u;stop->value=got;}return -1;}
        return 1;
    case 0x04040C53u:
        if(!js_v06c_read8(m,0x80818Au,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80818Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80818Bu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80818Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04040C57u:
        if(!js_v06c_read8(m,0x80818Au,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80818Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80818Bu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80818Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04040C60u:
        if(!js_v06c_read8(m,0x80818Cu,&got,stop)) return -1;
        if(got!=0xEEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80818Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80818Du,&got,stop)) return -1;
        if(got!=0x7Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80818Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80818Eu,&got,stop)) return -1;
        if(got!=0x12u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80818Eu;stop->value=got;}return -1;}
        return 1;
    case 0x04040C67u:
        if(!js_v06c_read8(m,0x80818Cu,&got,stop)) return -1;
        if(got!=0xEEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80818Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80818Du,&got,stop)) return -1;
        if(got!=0x7Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80818Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80818Eu,&got,stop)) return -1;
        if(got!=0x12u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80818Eu;stop->value=got;}return -1;}
        return 1;
    case 0x04040C78u:
        if(!js_v06c_read8(m,0x80818Fu,&got,stop)) return -1;
        if(got!=0xA5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80818Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808190u,&got,stop)) return -1;
        if(got!=0x2Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808190u;stop->value=got;}return -1;}
        return 1;
    case 0x04040C7Fu:
        if(!js_v06c_read8(m,0x80818Fu,&got,stop)) return -1;
        if(got!=0xA5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80818Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808190u,&got,stop)) return -1;
        if(got!=0x2Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808190u;stop->value=got;}return -1;}
        return 1;
    case 0x04040C88u:
        if(!js_v06c_read8(m,0x808191u,&got,stop)) return -1;
        if(got!=0xA6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808191u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808192u,&got,stop)) return -1;
        if(got!=0x2Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808192u;stop->value=got;}return -1;}
        return 1;
    case 0x04040C8Fu:
        if(!js_v06c_read8(m,0x808191u,&got,stop)) return -1;
        if(got!=0xA6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808191u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808192u,&got,stop)) return -1;
        if(got!=0x2Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808192u;stop->value=got;}return -1;}
        return 1;
    case 0x04040C98u:
        if(!js_v06c_read8(m,0x808193u,&got,stop)) return -1;
        if(got!=0xA4u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808193u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808194u,&got,stop)) return -1;
        if(got!=0x2Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808194u;stop->value=got;}return -1;}
        return 1;
    case 0x04040C9Fu:
        if(!js_v06c_read8(m,0x808193u,&got,stop)) return -1;
        if(got!=0xA4u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808193u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808194u,&got,stop)) return -1;
        if(got!=0x2Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808194u;stop->value=got;}return -1;}
        return 1;
    case 0x04040CA8u:
        if(!js_v06c_read8(m,0x808195u,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808195u;stop->value=got;}return -1;}
        return 1;
    case 0x04040CAFu:
        if(!js_v06c_read8(m,0x808195u,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808195u;stop->value=got;}return -1;}
        return 1;
    case 0x04040CB0u:
        if(!js_v06c_read8(m,0x808196u,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808196u;stop->value=got;}return -1;}
        return 1;
    case 0x04040CB7u:
        if(!js_v06c_read8(m,0x808196u,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808196u;stop->value=got;}return -1;}
        return 1;
    case 0x04040DF8u:
        if(!js_v06c_read8(m,0x8081BFu,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8081BFu;stop->value=got;}return -1;}
        return 1;
    case 0x04040DF9u:
        if(!js_v06c_read8(m,0x8081BFu,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8081BFu;stop->value=got;}return -1;}
        return 1;
    case 0x04040DFAu:
        if(!js_v06c_read8(m,0x8081BFu,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8081BFu;stop->value=got;}return -1;}
        return 1;
    case 0x04040DFBu:
        if(!js_v06c_read8(m,0x8081BFu,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8081BFu;stop->value=got;}return -1;}
        return 1;
    case 0x04040DFFu:
        if(!js_v06c_read8(m,0x8081BFu,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8081BFu;stop->value=got;}return -1;}
        return 1;
    case 0x04041008u:
        if(!js_v06c_read8(m,0x808201u,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808201u;stop->value=got;}return -1;}
        return 1;
    case 0x04041009u:
        if(!js_v06c_read8(m,0x808201u,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808201u;stop->value=got;}return -1;}
        return 1;
    case 0x0404100Au:
        if(!js_v06c_read8(m,0x808201u,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808201u;stop->value=got;}return -1;}
        return 1;
    case 0x0404100Bu:
        if(!js_v06c_read8(m,0x808201u,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808201u;stop->value=got;}return -1;}
        return 1;
    case 0x0404100Fu:
        if(!js_v06c_read8(m,0x808201u,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808201u;stop->value=got;}return -1;}
        return 1;
    case 0x04041010u:
        if(!js_v06c_read8(m,0x808202u,&got,stop)) return -1;
        if(got!=0xD8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808202u;stop->value=got;}return -1;}
        return 1;
    case 0x04041011u:
        if(!js_v06c_read8(m,0x808202u,&got,stop)) return -1;
        if(got!=0xD8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808202u;stop->value=got;}return -1;}
        return 1;
    case 0x04041012u:
        if(!js_v06c_read8(m,0x808202u,&got,stop)) return -1;
        if(got!=0xD8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808202u;stop->value=got;}return -1;}
        return 1;
    case 0x04041013u:
        if(!js_v06c_read8(m,0x808202u,&got,stop)) return -1;
        if(got!=0xD8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808202u;stop->value=got;}return -1;}
        return 1;
    case 0x04041017u:
        if(!js_v06c_read8(m,0x808202u,&got,stop)) return -1;
        if(got!=0xD8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808202u;stop->value=got;}return -1;}
        return 1;
    case 0x04041018u:
        if(!js_v06c_read8(m,0x808203u,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808203u;stop->value=got;}return -1;}
        return 1;
    case 0x04041019u:
        if(!js_v06c_read8(m,0x808203u,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808203u;stop->value=got;}return -1;}
        return 1;
    case 0x0404101Au:
        if(!js_v06c_read8(m,0x808203u,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808203u;stop->value=got;}return -1;}
        return 1;
    case 0x0404101Bu:
        if(!js_v06c_read8(m,0x808203u,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808203u;stop->value=got;}return -1;}
        return 1;
    case 0x0404101Fu:
        if(!js_v06c_read8(m,0x808203u,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808203u;stop->value=got;}return -1;}
        return 1;
    case 0x04041020u:
        if(!js_v06c_read8(m,0x808204u,&got,stop)) return -1;
        if(got!=0x4Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808204u;stop->value=got;}return -1;}
        return 1;
    case 0x04041021u:
        if(!js_v06c_read8(m,0x808204u,&got,stop)) return -1;
        if(got!=0x4Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808204u;stop->value=got;}return -1;}
        return 1;
    case 0x04041022u:
        if(!js_v06c_read8(m,0x808204u,&got,stop)) return -1;
        if(got!=0x4Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808204u;stop->value=got;}return -1;}
        return 1;
    case 0x04041023u:
        if(!js_v06c_read8(m,0x808204u,&got,stop)) return -1;
        if(got!=0x4Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808204u;stop->value=got;}return -1;}
        return 1;
    case 0x04041027u:
        if(!js_v06c_read8(m,0x808204u,&got,stop)) return -1;
        if(got!=0x4Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808204u;stop->value=got;}return -1;}
        return 1;
    case 0x04041028u:
        if(!js_v06c_read8(m,0x808205u,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808205u;stop->value=got;}return -1;}
        return 1;
    case 0x04041029u:
        if(!js_v06c_read8(m,0x808205u,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808205u;stop->value=got;}return -1;}
        return 1;
    case 0x0404102Au:
        if(!js_v06c_read8(m,0x808205u,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808205u;stop->value=got;}return -1;}
        return 1;
    case 0x0404102Bu:
        if(!js_v06c_read8(m,0x808205u,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808205u;stop->value=got;}return -1;}
        return 1;
    case 0x0404102Fu:
        if(!js_v06c_read8(m,0x808205u,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808205u;stop->value=got;}return -1;}
        return 1;
    case 0x04041030u:
        if(!js_v06c_read8(m,0x808206u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808206u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808207u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808207u;stop->value=got;}return -1;}
        return 1;
    case 0x04041031u:
        if(!js_v06c_read8(m,0x808206u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808206u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808207u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808207u;stop->value=got;}return -1;}
        return 1;
    case 0x04041032u:
        if(!js_v06c_read8(m,0x808206u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808206u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808207u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808207u;stop->value=got;}return -1;}
        return 1;
    case 0x04041033u:
        if(!js_v06c_read8(m,0x808206u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808206u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808207u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808207u;stop->value=got;}return -1;}
        return 1;
    case 0x04041037u:
        if(!js_v06c_read8(m,0x808206u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808206u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808207u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808207u;stop->value=got;}return -1;}
        return 1;
    case 0x04041040u:
        if(!js_v06c_read8(m,0x808208u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808208u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808209u,&got,stop)) return -1;
        if(got!=0x2Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808209u;stop->value=got;}return -1;}
        return 1;
    case 0x04041047u:
        if(!js_v06c_read8(m,0x808208u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808208u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808209u,&got,stop)) return -1;
        if(got!=0x2Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808209u;stop->value=got;}return -1;}
        return 1;
    case 0x04041050u:
        if(!js_v06c_read8(m,0x80820Au,&got,stop)) return -1;
        if(got!=0x86u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80820Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80820Bu,&got,stop)) return -1;
        if(got!=0x2Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80820Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04041057u:
        if(!js_v06c_read8(m,0x80820Au,&got,stop)) return -1;
        if(got!=0x86u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80820Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80820Bu,&got,stop)) return -1;
        if(got!=0x2Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80820Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04041060u:
        if(!js_v06c_read8(m,0x80820Cu,&got,stop)) return -1;
        if(got!=0x84u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80820Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80820Du,&got,stop)) return -1;
        if(got!=0x2Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80820Du;stop->value=got;}return -1;}
        return 1;
    case 0x04041067u:
        if(!js_v06c_read8(m,0x80820Cu,&got,stop)) return -1;
        if(got!=0x84u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80820Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80820Du,&got,stop)) return -1;
        if(got!=0x2Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80820Du;stop->value=got;}return -1;}
        return 1;
    case 0x04041070u:
        if(!js_v06c_read8(m,0x80820Eu,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80820Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80820Fu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80820Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04041077u:
        if(!js_v06c_read8(m,0x80820Eu,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80820Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80820Fu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80820Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04041083u:
        if(!js_v06c_read8(m,0x808210u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808210u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808211u,&got,stop)) return -1;
        if(got!=0x11u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808211u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808212u,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808212u;stop->value=got;}return -1;}
        return 1;
    case 0x04041087u:
        if(!js_v06c_read8(m,0x808210u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808210u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808211u,&got,stop)) return -1;
        if(got!=0x11u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808211u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808212u,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808212u;stop->value=got;}return -1;}
        return 1;
    case 0x0404109Bu:
        if(!js_v06c_read8(m,0x808213u,&got,stop)) return -1;
        if(got!=0x29u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808213u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808214u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808214u;stop->value=got;}return -1;}
        return 1;
    case 0x0404109Fu:
        if(!js_v06c_read8(m,0x808213u,&got,stop)) return -1;
        if(got!=0x29u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808213u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808214u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808214u;stop->value=got;}return -1;}
        return 1;
    case 0x040410ABu:
        if(!js_v06c_read8(m,0x808215u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808215u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808216u,&got,stop)) return -1;
        if(got!=0x06u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808216u;stop->value=got;}return -1;}
        return 1;
    case 0x040410AFu:
        if(!js_v06c_read8(m,0x808215u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808215u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808216u,&got,stop)) return -1;
        if(got!=0x06u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808216u;stop->value=got;}return -1;}
        return 1;
    case 0x040410BBu:
        if(!js_v06c_read8(m,0x808217u,&got,stop)) return -1;
        if(got!=0xAEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808217u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808218u,&got,stop)) return -1;
        if(got!=0x56u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808218u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808219u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808219u;stop->value=got;}return -1;}
        return 1;
    case 0x040410BFu:
        if(!js_v06c_read8(m,0x808217u,&got,stop)) return -1;
        if(got!=0xAEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808217u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808218u,&got,stop)) return -1;
        if(got!=0x56u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808218u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808219u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808219u;stop->value=got;}return -1;}
        return 1;
    case 0x040410D3u:
        if(!js_v06c_read8(m,0x80821Au,&got,stop)) return -1;
        if(got!=0xFCu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80821Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80821Bu,&got,stop)) return -1;
        if(got!=0x28u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80821Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80821Cu,&got,stop)) return -1;
        if(got!=0x82u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80821Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040410D7u:
        if(!js_v06c_read8(m,0x80821Au,&got,stop)) return -1;
        if(got!=0xFCu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80821Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80821Bu,&got,stop)) return -1;
        if(got!=0x28u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80821Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80821Cu,&got,stop)) return -1;
        if(got!=0x82u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80821Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040410EBu:
        if(!js_v06c_read8(m,0x80821Du,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80821Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80821Eu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80821Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040410EFu:
        if(!js_v06c_read8(m,0x80821Du,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80821Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80821Eu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80821Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040410F8u:
        if(!js_v06c_read8(m,0x80821Fu,&got,stop)) return -1;
        if(got!=0xA5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80821Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808220u,&got,stop)) return -1;
        if(got!=0x2Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808220u;stop->value=got;}return -1;}
        return 1;
    case 0x040410FFu:
        if(!js_v06c_read8(m,0x80821Fu,&got,stop)) return -1;
        if(got!=0xA5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80821Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808220u,&got,stop)) return -1;
        if(got!=0x2Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808220u;stop->value=got;}return -1;}
        return 1;
    case 0x04041108u:
        if(!js_v06c_read8(m,0x808221u,&got,stop)) return -1;
        if(got!=0xA6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808221u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808222u,&got,stop)) return -1;
        if(got!=0x2Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808222u;stop->value=got;}return -1;}
        return 1;
    case 0x0404110Fu:
        if(!js_v06c_read8(m,0x808221u,&got,stop)) return -1;
        if(got!=0xA6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808221u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808222u,&got,stop)) return -1;
        if(got!=0x2Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808222u;stop->value=got;}return -1;}
        return 1;
    case 0x04041118u:
        if(!js_v06c_read8(m,0x808223u,&got,stop)) return -1;
        if(got!=0xA4u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808223u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808224u,&got,stop)) return -1;
        if(got!=0x2Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808224u;stop->value=got;}return -1;}
        return 1;
    case 0x0404111Fu:
        if(!js_v06c_read8(m,0x808223u,&got,stop)) return -1;
        if(got!=0xA4u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808223u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808224u,&got,stop)) return -1;
        if(got!=0x2Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808224u;stop->value=got;}return -1;}
        return 1;
    case 0x04041128u:
        if(!js_v06c_read8(m,0x808225u,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808225u;stop->value=got;}return -1;}
        return 1;
    case 0x0404112Fu:
        if(!js_v06c_read8(m,0x808225u,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808225u;stop->value=got;}return -1;}
        return 1;
    case 0x04041130u:
        if(!js_v06c_read8(m,0x808226u,&got,stop)) return -1;
        if(got!=0x28u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808226u;stop->value=got;}return -1;}
        return 1;
    case 0x04041137u:
        if(!js_v06c_read8(m,0x808226u,&got,stop)) return -1;
        if(got!=0x28u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808226u;stop->value=got;}return -1;}
        return 1;
    case 0x04041138u:
        if(!js_v06c_read8(m,0x808227u,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808227u;stop->value=got;}return -1;}
        return 1;
    case 0x04041139u:
        if(!js_v06c_read8(m,0x808227u,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808227u;stop->value=got;}return -1;}
        return 1;
    case 0x0404113Au:
        if(!js_v06c_read8(m,0x808227u,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808227u;stop->value=got;}return -1;}
        return 1;
    case 0x0404113Bu:
        if(!js_v06c_read8(m,0x808227u,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808227u;stop->value=got;}return -1;}
        return 1;
    case 0x0404113Fu:
        if(!js_v06c_read8(m,0x808227u,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808227u;stop->value=got;}return -1;}
        return 1;
    case 0x040417B8u:
        if(!js_v06c_read8(m,0x8082F7u,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8082F7u;stop->value=got;}return -1;}
        return 1;
    case 0x040417C0u:
        if(!js_v06c_read8(m,0x8082F8u,&got,stop)) return -1;
        if(got!=0x4Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8082F8u;stop->value=got;}return -1;}
        return 1;
    case 0x040417C8u:
        if(!js_v06c_read8(m,0x8082F9u,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8082F9u;stop->value=got;}return -1;}
        return 1;
    case 0x040417D0u:
        if(!js_v06c_read8(m,0x8082FAu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8082FAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8082FBu,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8082FBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8082FCu,&got,stop)) return -1;
        if(got!=0x82u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8082FCu;stop->value=got;}return -1;}
        return 1;
    case 0x040417E8u:
        if(!js_v06c_read8(m,0x8082FDu,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8082FDu;stop->value=got;}return -1;}
        return 1;
    case 0x040417F0u:
        if(!js_v06c_read8(m,0x8082FEu,&got,stop)) return -1;
        if(got!=0x6Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8082FEu;stop->value=got;}return -1;}
        return 1;
    case 0x040417F8u:
        if(!js_v06c_read8(m,0x8082FFu,&got,stop)) return -1;
        if(got!=0x86u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8082FFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808300u,&got,stop)) return -1;
        if(got!=0x88u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808300u;stop->value=got;}return -1;}
        return 1;
    case 0x04041808u:
        if(!js_v06c_read8(m,0x808301u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808301u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808302u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808302u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808303u,&got,stop)) return -1;
        if(got!=0x83u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808303u;stop->value=got;}return -1;}
        return 1;
    case 0x04041820u:
        if(!js_v06c_read8(m,0x808304u,&got,stop)) return -1;
        if(got!=0x48u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808304u;stop->value=got;}return -1;}
        return 1;
    case 0x04041828u:
        if(!js_v06c_read8(m,0x808305u,&got,stop)) return -1;
        if(got!=0xDAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808305u;stop->value=got;}return -1;}
        return 1;
    case 0x04041830u:
        if(!js_v06c_read8(m,0x808306u,&got,stop)) return -1;
        if(got!=0xA5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808306u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808307u,&got,stop)) return -1;
        if(got!=0x88u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808307u;stop->value=got;}return -1;}
        return 1;
    case 0x04041840u:
        if(!js_v06c_read8(m,0x808308u,&got,stop)) return -1;
        if(got!=0x48u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808308u;stop->value=got;}return -1;}
        return 1;
    case 0x04041848u:
        if(!js_v06c_read8(m,0x808309u,&got,stop)) return -1;
        if(got!=0xF4u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808309u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80830Au,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80830Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80830Bu,&got,stop)) return -1;
        if(got!=0xCBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80830Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04041860u:
        if(!js_v06c_read8(m,0x80830Cu,&got,stop)) return -1;
        if(got!=0xF4u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80830Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80830Du,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80830Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80830Eu,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80830Eu;stop->value=got;}return -1;}
        return 1;
    case 0x04041878u:
        if(!js_v06c_read8(m,0x80830Fu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80830Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808310u,&got,stop)) return -1;
        if(got!=0x2Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808310u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808311u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808311u;stop->value=got;}return -1;}
        return 1;
    case 0x04041890u:
        if(!js_v06c_read8(m,0x808312u,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808312u;stop->value=got;}return -1;}
        return 1;
    case 0x04041898u:
        if(!js_v06c_read8(m,0x808313u,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808313u;stop->value=got;}return -1;}
        return 1;
    case 0x040418A0u:
        if(!js_v06c_read8(m,0x808314u,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808314u;stop->value=got;}return -1;}
        return 1;
    case 0x040418A8u:
        if(!js_v06c_read8(m,0x808315u,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808315u;stop->value=got;}return -1;}
        return 1;
    case 0x040418B0u:
        if(!js_v06c_read8(m,0x808316u,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808316u;stop->value=got;}return -1;}
        return 1;
    case 0x040418B8u:
        if(!js_v06c_read8(m,0x808317u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808317u;stop->value=got;}return -1;}
        return 1;
    case 0x04041900u:
        if(!js_v06c_read8(m,0x808320u,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808320u;stop->value=got;}return -1;}
        return 1;
    case 0x04041908u:
        if(!js_v06c_read8(m,0x808321u,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808321u;stop->value=got;}return -1;}
        return 1;
    case 0x04041910u:
        if(!js_v06c_read8(m,0x808322u,&got,stop)) return -1;
        if(got!=0xA8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808322u;stop->value=got;}return -1;}
        return 1;
    case 0x04041918u:
        if(!js_v06c_read8(m,0x808323u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808323u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808324u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808324u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808325u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808325u;stop->value=got;}return -1;}
        return 1;
    case 0x04041930u:
        if(!js_v06c_read8(m,0x808326u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808326u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808327u,&got,stop)) return -1;
        if(got!=0x04u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808327u;stop->value=got;}return -1;}
        return 1;
    case 0x04041940u:
        if(!js_v06c_read8(m,0x808328u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808328u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808329u,&got,stop)) return -1;
        if(got!=0x93u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808329u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80832Au,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80832Au;stop->value=got;}return -1;}
        return 1;
    case 0x04041958u:
        if(!js_v06c_read8(m,0x80832Bu,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80832Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80832Cu,&got,stop)) return -1;
        if(got!=0x06u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80832Cu;stop->value=got;}return -1;}
        return 1;
    case 0x04041968u:
        if(!js_v06c_read8(m,0x80832Du,&got,stop)) return -1;
        if(got!=0xB7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80832Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80832Eu,&got,stop)) return -1;
        if(got!=0x04u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80832Eu;stop->value=got;}return -1;}
        return 1;
    case 0x04041978u:
        if(!js_v06c_read8(m,0x80832Fu,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80832Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04041980u:
        if(!js_v06c_read8(m,0x808330u,&got,stop)) return -1;
        if(got!=0x69u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808330u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808331u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808331u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808332u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808332u;stop->value=got;}return -1;}
        return 1;
    case 0x04041998u:
        if(!js_v06c_read8(m,0x808333u,&got,stop)) return -1;
        if(got!=0xAAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808333u;stop->value=got;}return -1;}
        return 1;
    case 0x040419A0u:
        if(!js_v06c_read8(m,0x808334u,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808334u;stop->value=got;}return -1;}
        return 1;
    case 0x040419A8u:
        if(!js_v06c_read8(m,0x808335u,&got,stop)) return -1;
        if(got!=0xC8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808335u;stop->value=got;}return -1;}
        return 1;
    case 0x040419B0u:
        if(!js_v06c_read8(m,0x808336u,&got,stop)) return -1;
        if(got!=0xB7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808336u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808337u,&got,stop)) return -1;
        if(got!=0x04u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808337u;stop->value=got;}return -1;}
        return 1;
    case 0x040419C0u:
        if(!js_v06c_read8(m,0x808338u,&got,stop)) return -1;
        if(got!=0x69u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808338u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808339u,&got,stop)) return -1;
        if(got!=0x93u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808339u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80833Au,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80833Au;stop->value=got;}return -1;}
        return 1;
    case 0x040419D8u:
        if(!js_v06c_read8(m,0x80833Bu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80833Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04041AD8u:
        if(!js_v06c_read8(m,0x80835Bu,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80835Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04041AE0u:
        if(!js_v06c_read8(m,0x80835Cu,&got,stop)) return -1;
        if(got!=0x4Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80835Cu;stop->value=got;}return -1;}
        return 1;
    case 0x04041AE8u:
        if(!js_v06c_read8(m,0x80835Du,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80835Du;stop->value=got;}return -1;}
        return 1;
    case 0x04041AF0u:
        if(!js_v06c_read8(m,0x80835Eu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80835Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80835Fu,&got,stop)) return -1;
        if(got!=0x63u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80835Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808360u,&got,stop)) return -1;
        if(got!=0x83u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808360u;stop->value=got;}return -1;}
        return 1;
    case 0x04041B08u:
        if(!js_v06c_read8(m,0x808361u,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808361u;stop->value=got;}return -1;}
        return 1;
    case 0x04041B10u:
        if(!js_v06c_read8(m,0x808362u,&got,stop)) return -1;
        if(got!=0x6Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808362u;stop->value=got;}return -1;}
        return 1;
    case 0x04041B18u:
        if(!js_v06c_read8(m,0x808363u,&got,stop)) return -1;
        if(got!=0x5Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808363u;stop->value=got;}return -1;}
        return 1;
    case 0x04041B20u:
        if(!js_v06c_read8(m,0x808364u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808364u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808365u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808365u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808366u,&got,stop)) return -1;
        if(got!=0x83u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808366u;stop->value=got;}return -1;}
        return 1;
    case 0x04041B38u:
        if(!js_v06c_read8(m,0x808367u,&got,stop)) return -1;
        if(got!=0x7Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808367u;stop->value=got;}return -1;}
        return 1;
    case 0x04041B40u:
        if(!js_v06c_read8(m,0x808368u,&got,stop)) return -1;
        if(got!=0x48u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808368u;stop->value=got;}return -1;}
        return 1;
    case 0x04041B48u:
        if(!js_v06c_read8(m,0x808369u,&got,stop)) return -1;
        if(got!=0xDAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808369u;stop->value=got;}return -1;}
        return 1;
    case 0x04041B50u:
        if(!js_v06c_read8(m,0x80836Au,&got,stop)) return -1;
        if(got!=0x5Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80836Au;stop->value=got;}return -1;}
        return 1;
    case 0x04041B58u:
        if(!js_v06c_read8(m,0x80836Bu,&got,stop)) return -1;
        if(got!=0xF4u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80836Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80836Cu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80836Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80836Du,&got,stop)) return -1;
        if(got!=0xCBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80836Du;stop->value=got;}return -1;}
        return 1;
    case 0x04041B70u:
        if(!js_v06c_read8(m,0x80836Eu,&got,stop)) return -1;
        if(got!=0xF4u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80836Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80836Fu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80836Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808370u,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808370u;stop->value=got;}return -1;}
        return 1;
    case 0x04041B88u:
        if(!js_v06c_read8(m,0x808371u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808371u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808372u,&got,stop)) return -1;
        if(got!=0xCEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808372u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808373u,&got,stop)) return -1;
        if(got!=0x83u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808373u;stop->value=got;}return -1;}
        return 1;
    case 0x04041BA0u:
        if(!js_v06c_read8(m,0x808374u,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808374u;stop->value=got;}return -1;}
        return 1;
    case 0x04041BA8u:
        if(!js_v06c_read8(m,0x808375u,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808375u;stop->value=got;}return -1;}
        return 1;
    case 0x04041BB0u:
        if(!js_v06c_read8(m,0x808376u,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808376u;stop->value=got;}return -1;}
        return 1;
    case 0x04041BB8u:
        if(!js_v06c_read8(m,0x808377u,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808377u;stop->value=got;}return -1;}
        return 1;
    case 0x04041BC0u:
        if(!js_v06c_read8(m,0x808378u,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808378u;stop->value=got;}return -1;}
        return 1;
    case 0x04041BC8u:
        if(!js_v06c_read8(m,0x808379u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808379u;stop->value=got;}return -1;}
        return 1;
    case 0x04041CD8u:
        if(!js_v06c_read8(m,0x80839Bu,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80839Bu;stop->value=got;}return -1;}
        return 1;
    case 0x04041CE0u:
        if(!js_v06c_read8(m,0x80839Cu,&got,stop)) return -1;
        if(got!=0x4Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80839Cu;stop->value=got;}return -1;}
        return 1;
    case 0x04041CE8u:
        if(!js_v06c_read8(m,0x80839Du,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80839Du;stop->value=got;}return -1;}
        return 1;
    case 0x04041CF0u:
        if(!js_v06c_read8(m,0x80839Eu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80839Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80839Fu,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80839Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083A0u,&got,stop)) return -1;
        if(got!=0x83u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083A0u;stop->value=got;}return -1;}
        return 1;
    case 0x04041D08u:
        if(!js_v06c_read8(m,0x8083A1u,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083A1u;stop->value=got;}return -1;}
        return 1;
    case 0x04041D10u:
        if(!js_v06c_read8(m,0x8083A2u,&got,stop)) return -1;
        if(got!=0x6Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083A2u;stop->value=got;}return -1;}
        return 1;
    case 0x04041D18u:
        if(!js_v06c_read8(m,0x8083A3u,&got,stop)) return -1;
        if(got!=0x48u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083A3u;stop->value=got;}return -1;}
        return 1;
    case 0x04041D20u:
        if(!js_v06c_read8(m,0x8083A4u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083A4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083A5u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083A5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083A6u,&got,stop)) return -1;
        if(got!=0x83u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083A6u;stop->value=got;}return -1;}
        return 1;
    case 0x04041D38u:
        if(!js_v06c_read8(m,0x8083A7u,&got,stop)) return -1;
        if(got!=0x7Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083A7u;stop->value=got;}return -1;}
        return 1;
    case 0x04041D40u:
        if(!js_v06c_read8(m,0x8083A8u,&got,stop)) return -1;
        if(got!=0x48u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083A8u;stop->value=got;}return -1;}
        return 1;
    case 0x04041D48u:
        if(!js_v06c_read8(m,0x8083A9u,&got,stop)) return -1;
        if(got!=0xDAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083A9u;stop->value=got;}return -1;}
        return 1;
    case 0x04041D50u:
        if(!js_v06c_read8(m,0x8083AAu,&got,stop)) return -1;
        if(got!=0x98u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083AAu;stop->value=got;}return -1;}
        return 1;
    case 0x04041D58u:
        if(!js_v06c_read8(m,0x8083ABu,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083ABu;stop->value=got;}return -1;}
        return 1;
    case 0x04041D60u:
        if(!js_v06c_read8(m,0x8083ACu,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083ACu;stop->value=got;}return -1;}
        return 1;
    case 0x04041D68u:
        if(!js_v06c_read8(m,0x8083ADu,&got,stop)) return -1;
        if(got!=0xA8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083ADu;stop->value=got;}return -1;}
        return 1;
    case 0x04041D70u:
        if(!js_v06c_read8(m,0x8083AEu,&got,stop)) return -1;
        if(got!=0xB9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083AEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083AFu,&got,stop)) return -1;
        if(got!=0x39u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083AFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083B0u,&got,stop)) return -1;
        if(got!=0x86u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083B0u;stop->value=got;}return -1;}
        return 1;
    case 0x04041D88u:
        if(!js_v06c_read8(m,0x8083B1u,&got,stop)) return -1;
        if(got!=0x48u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083B1u;stop->value=got;}return -1;}
        return 1;
    case 0x04041D90u:
        if(!js_v06c_read8(m,0x8083B2u,&got,stop)) return -1;
        if(got!=0xF4u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083B2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083B3u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083B3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083B4u,&got,stop)) return -1;
        if(got!=0xCBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083B4u;stop->value=got;}return -1;}
        return 1;
    case 0x04041DA8u:
        if(!js_v06c_read8(m,0x8083B5u,&got,stop)) return -1;
        if(got!=0xF4u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083B5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083B6u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083B6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083B7u,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083B7u;stop->value=got;}return -1;}
        return 1;
    case 0x04041DC0u:
        if(!js_v06c_read8(m,0x8083B8u,&got,stop)) return -1;
        if(got!=0xB9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083B8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083B9u,&got,stop)) return -1;
        if(got!=0x3Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083B9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083BAu,&got,stop)) return -1;
        if(got!=0x86u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083BAu;stop->value=got;}return -1;}
        return 1;
    case 0x04041DD8u:
        if(!js_v06c_read8(m,0x8083BBu,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083BBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083BCu,&got,stop)) return -1;
        if(got!=0x05u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083BCu;stop->value=got;}return -1;}
        return 1;
    case 0x04041DE8u:
        if(!js_v06c_read8(m,0x8083BDu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083BDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083BEu,&got,stop)) return -1;
        if(got!=0x2Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083BEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083BFu,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083BFu;stop->value=got;}return -1;}
        return 1;
    case 0x04041E00u:
        if(!js_v06c_read8(m,0x8083C0u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083C0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083C1u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083C1u;stop->value=got;}return -1;}
        return 1;
    case 0x04041E10u:
        if(!js_v06c_read8(m,0x8083C2u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083C2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083C3u,&got,stop)) return -1;
        if(got!=0xCEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083C3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083C4u,&got,stop)) return -1;
        if(got!=0x83u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083C4u;stop->value=got;}return -1;}
        return 1;
    case 0x04041E28u:
        if(!js_v06c_read8(m,0x8083C5u,&got,stop)) return -1;
        if(got!=0xBAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083C5u;stop->value=got;}return -1;}
        return 1;
    case 0x04041E30u:
        if(!js_v06c_read8(m,0x8083C6u,&got,stop)) return -1;
        if(got!=0x8Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083C6u;stop->value=got;}return -1;}
        return 1;
    case 0x04041E38u:
        if(!js_v06c_read8(m,0x8083C7u,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083C7u;stop->value=got;}return -1;}
        return 1;
    case 0x04041E40u:
        if(!js_v06c_read8(m,0x8083C8u,&got,stop)) return -1;
        if(got!=0x69u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083C8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083C9u,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083C9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083CAu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083CAu;stop->value=got;}return -1;}
        return 1;
    case 0x04041E58u:
        if(!js_v06c_read8(m,0x8083CBu,&got,stop)) return -1;
        if(got!=0xAAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083CBu;stop->value=got;}return -1;}
        return 1;
    case 0x04041E60u:
        if(!js_v06c_read8(m,0x8083CCu,&got,stop)) return -1;
        if(got!=0x9Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083CCu;stop->value=got;}return -1;}
        return 1;
    case 0x04041E68u:
        if(!js_v06c_read8(m,0x8083CDu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083CDu;stop->value=got;}return -1;}
        return 1;
    case 0x04041E70u:
        if(!js_v06c_read8(m,0x8083CEu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083CEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083CFu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083CFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083D0u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083D0u;stop->value=got;}return -1;}
        return 1;
    case 0x04041E88u:
        if(!js_v06c_read8(m,0x8083D1u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083D1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083D2u,&got,stop)) return -1;
        if(got!=0x15u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083D2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083D3u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083D3u;stop->value=got;}return -1;}
        return 1;
    case 0x04041EA0u:
        if(!js_v06c_read8(m,0x8083D4u,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083D4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083D5u,&got,stop)) return -1;
        if(got!=0x07u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083D5u;stop->value=got;}return -1;}
        return 1;
    case 0x04041EB0u:
        if(!js_v06c_read8(m,0x8083D6u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083D6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083D7u,&got,stop)) return -1;
        if(got!=0x16u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083D7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083D8u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083D8u;stop->value=got;}return -1;}
        return 1;
    case 0x04041EC8u:
        if(!js_v06c_read8(m,0x8083D9u,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083D9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083DAu,&got,stop)) return -1;
        if(got!=0x09u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083DAu;stop->value=got;}return -1;}
        return 1;
    case 0x04041ED8u:
        if(!js_v06c_read8(m,0x8083DBu,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083DBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083DCu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083DCu;stop->value=got;}return -1;}
        return 1;
    case 0x04041EE8u:
        if(!js_v06c_read8(m,0x8083DDu,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083DDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083DEu,&got,stop)) return -1;
        if(got!=0x0Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083DEu;stop->value=got;}return -1;}
        return 1;
    case 0x04041EF8u:
        if(!js_v06c_read8(m,0x8083DFu,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083DFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083E0u,&got,stop)) return -1;
        if(got!=0x32u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083E0u;stop->value=got;}return -1;}
        return 1;
    case 0x04041F08u:
        if(!js_v06c_read8(m,0x8083E1u,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083E1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083E2u,&got,stop)) return -1;
        if(got!=0x05u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083E2u;stop->value=got;}return -1;}
        return 1;
    case 0x04041F18u:
        if(!js_v06c_read8(m,0x8083E3u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083E3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083E4u,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083E4u;stop->value=got;}return -1;}
        return 1;
    case 0x04041F28u:
        if(!js_v06c_read8(m,0x8083E5u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083E5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083E6u,&got,stop)) return -1;
        if(got!=0x3Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083E6u;stop->value=got;}return -1;}
        return 1;
    case 0x04041F38u:
        if(!js_v06c_read8(m,0x8083E7u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083E7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083E8u,&got,stop)) return -1;
        if(got!=0x7Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083E8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083E9u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083E9u;stop->value=got;}return -1;}
        return 1;
    case 0x04041F50u:
        if(!js_v06c_read8(m,0x8083EAu,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083EAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083EBu,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083EBu;stop->value=got;}return -1;}
        return 1;
    case 0x04041F60u:
        if(!js_v06c_read8(m,0x8083ECu,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083ECu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083EDu,&got,stop)) return -1;
        if(got!=0x3Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083EDu;stop->value=got;}return -1;}
        return 1;
    case 0x04041F70u:
        if(!js_v06c_read8(m,0x8083EEu,&got,stop)) return -1;
        if(got!=0xA7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083EEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083EFu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083EFu;stop->value=got;}return -1;}
        return 1;
    case 0x04041F80u:
        if(!js_v06c_read8(m,0x8083F0u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083F0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083F1u,&got,stop)) return -1;
        if(got!=0x34u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083F1u;stop->value=got;}return -1;}
        return 1;
    case 0x04041F90u:
        if(!js_v06c_read8(m,0x8083F2u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083F2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083F3u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083F3u;stop->value=got;}return -1;}
        return 1;
    case 0x04041FA0u:
        if(!js_v06c_read8(m,0x8083F4u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083F4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083F5u,&got,stop)) return -1;
        if(got!=0x07u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083F5u;stop->value=got;}return -1;}
        return 1;
    case 0x04041FB0u:
        if(!js_v06c_read8(m,0x8083F6u,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083F6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083F7u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083F7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083F8u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083F8u;stop->value=got;}return -1;}
        return 1;
    case 0x04041FC8u:
        if(!js_v06c_read8(m,0x8083F9u,&got,stop)) return -1;
        if(got!=0x84u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083F9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083FAu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083FAu;stop->value=got;}return -1;}
        return 1;
    case 0x04041FD8u:
        if(!js_v06c_read8(m,0x8083FBu,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083FBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083FCu,&got,stop)) return -1;
        if(got!=0x32u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083FCu;stop->value=got;}return -1;}
        return 1;
    case 0x04041FE8u:
        if(!js_v06c_read8(m,0x8083FDu,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083FDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x8083FEu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083FEu;stop->value=got;}return -1;}
        return 1;
    case 0x04041FFAu:
        if(!js_v06c_read8(m,0x8083FFu,&got,stop)) return -1;
        if(got!=0xA7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x8083FFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x808400u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x808400u;stop->value=got;}return -1;}
        return 1;
    default: return 0;
    }
}
