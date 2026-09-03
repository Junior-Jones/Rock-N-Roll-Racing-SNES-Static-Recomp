#include "js_v06c_fetch.h"

int js_v06c_fetch_shard_2029(JSV06Machine *m, JSV06Stop *stop) {
    uint8_t got;
    switch(js_cpu_context_key(&m->cpu)) {
    case 0x04052003u:
        if(!js_v06c_read8(m,0x80A400u,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A400u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A401u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A401u;stop->value=got;}return -1;}
        return 1;
    case 0x04052013u:
        if(!js_v06c_read8(m,0x80A402u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A402u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A403u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A403u;stop->value=got;}return -1;}
        return 1;
    case 0x04052023u:
        if(!js_v06c_read8(m,0x80A404u,&got,stop)) return -1;
        if(got!=0xCAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A404u;stop->value=got;}return -1;}
        return 1;
    case 0x0405202Bu:
        if(!js_v06c_read8(m,0x80A405u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A405u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A406u,&got,stop)) return -1;
        if(got!=0xFDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A406u;stop->value=got;}return -1;}
        return 1;
    case 0x0405203Bu:
        if(!js_v06c_read8(m,0x80A407u,&got,stop)) return -1;
        if(got!=0x88u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A407u;stop->value=got;}return -1;}
        return 1;
    case 0x04052043u:
        if(!js_v06c_read8(m,0x80A408u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A408u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A409u,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A409u;stop->value=got;}return -1;}
        return 1;
    case 0x04052053u:
        if(!js_v06c_read8(m,0x80A40Au,&got,stop)) return -1;
        if(got!=0xCEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A40Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A40Bu,&got,stop)) return -1;
        if(got!=0x5Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A40Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A40Cu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A40Cu;stop->value=got;}return -1;}
        return 1;
    case 0x0405206Bu:
        if(!js_v06c_read8(m,0x80A40Du,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A40Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A40Eu,&got,stop)) return -1;
        if(got!=0xE8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A40Eu;stop->value=got;}return -1;}
        return 1;
    case 0x0405207Bu:
        if(!js_v06c_read8(m,0x80A40Fu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A40Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A410u,&got,stop)) return -1;
        if(got!=0x8Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A410u;stop->value=got;}return -1;}
        return 1;
    case 0x0405208Bu:
        if(!js_v06c_read8(m,0x80A411u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A411u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A412u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A412u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A413u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A413u;stop->value=got;}return -1;}
        return 1;
    case 0x040520A3u:
        if(!js_v06c_read8(m,0x80A414u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A414u;stop->value=got;}return -1;}
        return 1;
    case 0x040520ABu:
        if(!js_v06c_read8(m,0x80A415u,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A415u;stop->value=got;}return -1;}
        return 1;
    case 0x040520B3u:
        if(!js_v06c_read8(m,0x80A416u,&got,stop)) return -1;
        if(got!=0x4Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A416u;stop->value=got;}return -1;}
        return 1;
    case 0x040520BBu:
        if(!js_v06c_read8(m,0x80A417u,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A417u;stop->value=got;}return -1;}
        return 1;
    case 0x040520C3u:
        if(!js_v06c_read8(m,0x80A418u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A418u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A419u,&got,stop)) return -1;
        if(got!=0x1Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A419u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A41Au,&got,stop)) return -1;
        if(got!=0xA4u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A41Au;stop->value=got;}return -1;}
        return 1;
    case 0x040520DBu:
        if(!js_v06c_read8(m,0x80A41Bu,&got,stop)) return -1;
        if(got!=0xABu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A41Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040520E3u:
        if(!js_v06c_read8(m,0x80A41Cu,&got,stop)) return -1;
        if(got!=0x6Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A41Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040520EBu:
        if(!js_v06c_read8(m,0x80A41Du,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A41Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A41Eu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A41Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040520F8u:
        if(!js_v06c_read8(m,0x80A41Fu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A41Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A420u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A420u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A421u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A421u;stop->value=got;}return -1;}
        return 1;
    case 0x04052110u:
        if(!js_v06c_read8(m,0x80A422u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A422u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A423u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A423u;stop->value=got;}return -1;}
        return 1;
    case 0x04052123u:
        if(!js_v06c_read8(m,0x80A424u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A424u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A425u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A425u;stop->value=got;}return -1;}
        return 1;
    case 0x04052133u:
        if(!js_v06c_read8(m,0x80A426u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A426u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A427u,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A427u;stop->value=got;}return -1;}
        return 1;
    case 0x04052143u:
        if(!js_v06c_read8(m,0x80A428u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A428u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A429u,&got,stop)) return -1;
        if(got!=0x04u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A429u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A42Au,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A42Au;stop->value=got;}return -1;}
        return 1;
    case 0x0405215Bu:
        if(!js_v06c_read8(m,0x80A42Bu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A42Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A42Cu,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A42Cu;stop->value=got;}return -1;}
        return 1;
    case 0x0405216Bu:
        if(!js_v06c_read8(m,0x80A42Du,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A42Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A42Eu,&got,stop)) return -1;
        if(got!=0x04u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A42Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A42Fu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A42Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04052183u:
        if(!js_v06c_read8(m,0x80A430u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A430u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A431u,&got,stop)) return -1;
        if(got!=0x04u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A431u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A432u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A432u;stop->value=got;}return -1;}
        return 1;
    case 0x0405219Bu:
        if(!js_v06c_read8(m,0x80A433u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A433u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A434u,&got,stop)) return -1;
        if(got!=0x04u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A434u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A435u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A435u;stop->value=got;}return -1;}
        return 1;
    case 0x040521B3u:
        if(!js_v06c_read8(m,0x80A436u,&got,stop)) return -1;
        if(got!=0xCAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A436u;stop->value=got;}return -1;}
        return 1;
    case 0x040521BBu:
        if(!js_v06c_read8(m,0x80A437u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A437u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A438u,&got,stop)) return -1;
        if(got!=0xEDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A438u;stop->value=got;}return -1;}
        return 1;
    case 0x040521CBu:
        if(!js_v06c_read8(m,0x80A439u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A439u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A43Au,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A43Au;stop->value=got;}return -1;}
        return 1;
    case 0x040521DBu:
        if(!js_v06c_read8(m,0x80A43Bu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A43Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A43Cu,&got,stop)) return -1;
        if(got!=0x55u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A43Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040521EBu:
        if(!js_v06c_read8(m,0x80A43Du,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A43Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A43Eu,&got,stop)) return -1;
        if(got!=0x04u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A43Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A43Fu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A43Fu;stop->value=got;}return -1;}
        return 1;
    case 0x04052203u:
        if(!js_v06c_read8(m,0x80A440u,&got,stop)) return -1;
        if(got!=0xCAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A440u;stop->value=got;}return -1;}
        return 1;
    case 0x0405220Bu:
        if(!js_v06c_read8(m,0x80A441u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A441u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A442u,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A442u;stop->value=got;}return -1;}
        return 1;
    case 0x0405221Bu:
        if(!js_v06c_read8(m,0x80A443u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A443u;stop->value=got;}return -1;}
        return 1;
    case 0x04052223u:
        if(!js_v06c_read8(m,0x80A444u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A444u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A445u,&got,stop)) return -1;
        if(got!=0x12u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A445u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A446u,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A446u;stop->value=got;}return -1;}
        return 1;
    case 0x0405223Bu:
        if(!js_v06c_read8(m,0x80A447u,&got,stop)) return -1;
        if(got!=0x29u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A447u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A448u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A448u;stop->value=got;}return -1;}
        return 1;
    case 0x0405224Bu:
        if(!js_v06c_read8(m,0x80A449u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A449u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80A44Au,&got,stop)) return -1;
        if(got!=0xF9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A44Au;stop->value=got;}return -1;}
        return 1;
    case 0x0405225Bu:
        if(!js_v06c_read8(m,0x80A44Bu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80A44Bu;stop->value=got;}return -1;}
        return 1;
    default: return 0;
    }
}
