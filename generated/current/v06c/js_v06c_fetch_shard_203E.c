#include "js_v06c_fetch.h"

int js_v06c_fetch_shard_203E(JSV06Machine *m, JSV06Stop *stop) {
    uint8_t got;
    switch(js_cpu_context_key(&m->cpu)) {
    case 0x0407C6DBu:
        if(!js_v06c_read8(m,0x80F8DBu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8DBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F8DCu,&got,stop)) return -1;
        if(got!=0x2Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8DCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F8DDu,&got,stop)) return -1;
        if(got!=0xFBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8DDu;stop->value=got;}return -1;}
        return 1;
    case 0x0407C6F3u:
        if(!js_v06c_read8(m,0x80F8DEu,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8DEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F8DFu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8DFu;stop->value=got;}return -1;}
        return 1;
    case 0x0407C703u:
        if(!js_v06c_read8(m,0x80F8E0u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8E0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F8E1u,&got,stop)) return -1;
        if(got!=0x38u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8E1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F8E2u,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8E2u;stop->value=got;}return -1;}
        return 1;
    case 0x0407C71Bu:
        if(!js_v06c_read8(m,0x80F8E3u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8E3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F8E4u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8E4u;stop->value=got;}return -1;}
        return 1;
    case 0x0407C72Bu:
        if(!js_v06c_read8(m,0x80F8E5u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8E5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F8E6u,&got,stop)) return -1;
        if(got!=0x38u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8E6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F8E7u,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8E7u;stop->value=got;}return -1;}
        return 1;
    case 0x0407C743u:
        if(!js_v06c_read8(m,0x80F8E8u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8E8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F8E9u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8E9u;stop->value=got;}return -1;}
        return 1;
    case 0x0407C753u:
        if(!js_v06c_read8(m,0x80F8EAu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8EAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F8EBu,&got,stop)) return -1;
        if(got!=0x38u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8EBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F8ECu,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8ECu;stop->value=got;}return -1;}
        return 1;
    case 0x0407C76Bu:
        if(!js_v06c_read8(m,0x80F8EDu,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8EDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F8EEu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8EEu;stop->value=got;}return -1;}
        return 1;
    case 0x0407C77Bu:
        if(!js_v06c_read8(m,0x80F8EFu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8EFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F8F0u,&got,stop)) return -1;
        if(got!=0x38u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8F0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F8F1u,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8F1u;stop->value=got;}return -1;}
        return 1;
    case 0x0407C793u:
        if(!js_v06c_read8(m,0x80F8F2u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8F2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F8F3u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8F3u;stop->value=got;}return -1;}
        return 1;
    case 0x0407C7A3u:
        if(!js_v06c_read8(m,0x80F8F4u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8F4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F8F5u,&got,stop)) return -1;
        if(got!=0xECu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8F5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F8F6u,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8F6u;stop->value=got;}return -1;}
        return 1;
    case 0x0407C7BBu:
        if(!js_v06c_read8(m,0x80F8F7u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8F7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F8F8u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8F8u;stop->value=got;}return -1;}
        return 1;
    case 0x0407C7CBu:
        if(!js_v06c_read8(m,0x80F8F9u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8F9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F8FAu,&got,stop)) return -1;
        if(got!=0xEDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8FAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F8FBu,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8FBu;stop->value=got;}return -1;}
        return 1;
    case 0x0407C7E3u:
        if(!js_v06c_read8(m,0x80F8FCu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8FCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F8FDu,&got,stop)) return -1;
        if(got!=0xEEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8FDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F8FEu,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8FEu;stop->value=got;}return -1;}
        return 1;
    case 0x0407C7FBu:
        if(!js_v06c_read8(m,0x80F8FFu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F8FFu;stop->value=got;}return -1;}
        return 1;
    case 0x0407C823u:
        if(!js_v06c_read8(m,0x80F904u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F904u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F905u,&got,stop)) return -1;
        if(got!=0x34u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F905u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F906u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F906u;stop->value=got;}return -1;}
        return 1;
    case 0x0407C83Bu:
        if(!js_v06c_read8(m,0x80F907u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F907u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F908u,&got,stop)) return -1;
        if(got!=0x0Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F908u;stop->value=got;}return -1;}
        return 1;
    case 0x0407C84Bu:
        if(!js_v06c_read8(m,0x80F909u,&got,stop)) return -1;
        if(got!=0xE0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F909u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F90Au,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F90Au;stop->value=got;}return -1;}
        return 1;
    case 0x0407C85Bu:
        if(!js_v06c_read8(m,0x80F90Bu,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F90Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F90Cu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F90Cu;stop->value=got;}return -1;}
        return 1;
    case 0x0407C86Bu:
        if(!js_v06c_read8(m,0x80F90Du,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F90Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F90Eu,&got,stop)) return -1;
        if(got!=0x38u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F90Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F90Fu,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F90Fu;stop->value=got;}return -1;}
        return 1;
    case 0x0407C883u:
        if(!js_v06c_read8(m,0x80F910u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F910u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F911u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F911u;stop->value=got;}return -1;}
        return 1;
    case 0x0407C893u:
        if(!js_v06c_read8(m,0x80F912u,&got,stop)) return -1;
        if(got!=0xEBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F912u;stop->value=got;}return -1;}
        return 1;
    case 0x0407C89Bu:
        if(!js_v06c_read8(m,0x80F913u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F913u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F914u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F914u;stop->value=got;}return -1;}
        return 1;
    case 0x0407C8ABu:
        if(!js_v06c_read8(m,0x80F915u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F915u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F916u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F916u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F917u,&got,stop)) return -1;
        if(got!=0xF9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F917u;stop->value=got;}return -1;}
        return 1;
    case 0x0407C8C3u:
        if(!js_v06c_read8(m,0x80F918u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F918u;stop->value=got;}return -1;}
        return 1;
    case 0x0407C933u:
        if(!js_v06c_read8(m,0x80F926u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F926u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F927u,&got,stop)) return -1;
        if(got!=0x2Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F927u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F928u,&got,stop)) return -1;
        if(got!=0xF9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F928u;stop->value=got;}return -1;}
        return 1;
    case 0x0407C94Bu:
        if(!js_v06c_read8(m,0x80F929u,&got,stop)) return -1;
        if(got!=0x6Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F929u;stop->value=got;}return -1;}
        return 1;
    case 0x0407C953u:
        if(!js_v06c_read8(m,0x80F92Au,&got,stop)) return -1;
        if(got!=0xDAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F92Au;stop->value=got;}return -1;}
        return 1;
    case 0x0407C95Bu:
        if(!js_v06c_read8(m,0x80F92Bu,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F92Bu;stop->value=got;}return -1;}
        return 1;
    case 0x0407C963u:
        if(!js_v06c_read8(m,0x80F92Cu,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F92Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F92Du,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F92Du;stop->value=got;}return -1;}
        return 1;
    case 0x0407C973u:
        if(!js_v06c_read8(m,0x80F92Eu,&got,stop)) return -1;
        if(got!=0xAEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F92Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F92Fu,&got,stop)) return -1;
        if(got!=0x33u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F92Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F930u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F930u;stop->value=got;}return -1;}
        return 1;
    case 0x0407C98Bu:
        if(!js_v06c_read8(m,0x80F931u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F931u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F932u,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F932u;stop->value=got;}return -1;}
        return 1;
    case 0x0407C99Bu:
        if(!js_v06c_read8(m,0x80F933u,&got,stop)) return -1;
        if(got!=0xC9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F933u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F934u,&got,stop)) return -1;
        if(got!=0x32u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F934u;stop->value=got;}return -1;}
        return 1;
    case 0x0407C9ABu:
        if(!js_v06c_read8(m,0x80F935u,&got,stop)) return -1;
        if(got!=0xB0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F935u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F936u,&got,stop)) return -1;
        if(got!=0x09u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F936u;stop->value=got;}return -1;}
        return 1;
    case 0x0407C9BBu:
        if(!js_v06c_read8(m,0x80F937u,&got,stop)) return -1;
        if(got!=0xEBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F937u;stop->value=got;}return -1;}
        return 1;
    case 0x0407C9C3u:
        if(!js_v06c_read8(m,0x80F938u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F938u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F939u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F939u;stop->value=got;}return -1;}
        return 1;
    case 0x0407C9D3u:
        if(!js_v06c_read8(m,0x80F93Au,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F93Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F93Bu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F93Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F93Cu,&got,stop)) return -1;
        if(got!=0xF9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F93Cu;stop->value=got;}return -1;}
        return 1;
    case 0x0407C9EBu:
        if(!js_v06c_read8(m,0x80F93Du,&got,stop)) return -1;
        if(got!=0x28u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F93Du;stop->value=got;}return -1;}
        return 1;
    case 0x0407C9F3u:
        if(!js_v06c_read8(m,0x80F93Eu,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F93Eu;stop->value=got;}return -1;}
        return 1;
    case 0x0407C9FBu:
        if(!js_v06c_read8(m,0x80F93Fu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F93Fu;stop->value=got;}return -1;}
        return 1;
    case 0x0407CBDBu:
        if(!js_v06c_read8(m,0x80F97Bu,&got,stop)) return -1;
        if(got!=0xEBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F97Bu;stop->value=got;}return -1;}
        return 1;
    case 0x0407CBE3u:
        if(!js_v06c_read8(m,0x80F97Cu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F97Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F97Du,&got,stop)) return -1;
        if(got!=0x07u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F97Du;stop->value=got;}return -1;}
        return 1;
    case 0x0407CBF3u:
        if(!js_v06c_read8(m,0x80F97Eu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F97Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F97Fu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F97Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F980u,&got,stop)) return -1;
        if(got!=0xF9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F980u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CC0Bu:
        if(!js_v06c_read8(m,0x80F981u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F981u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CC13u:
        if(!js_v06c_read8(m,0x80F982u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F982u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F983u,&got,stop)) return -1;
        if(got!=0x86u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F983u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F984u,&got,stop)) return -1;
        if(got!=0xF9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F984u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CC2Bu:
        if(!js_v06c_read8(m,0x80F985u,&got,stop)) return -1;
        if(got!=0x6Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F985u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CC33u:
        if(!js_v06c_read8(m,0x80F986u,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F986u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CC3Bu:
        if(!js_v06c_read8(m,0x80F987u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F987u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F988u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F988u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CC49u:
        if(!js_v06c_read8(m,0x80F989u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F989u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F98Au,&got,stop)) return -1;
        if(got!=0x5Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F98Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F98Bu,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F98Bu;stop->value=got;}return -1;}
        return 1;
    case 0x0407CC61u:
        if(!js_v06c_read8(m,0x80F98Cu,&got,stop)) return -1;
        if(got!=0xCDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F98Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F98Du,&got,stop)) return -1;
        if(got!=0x5Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F98Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F98Eu,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F98Eu;stop->value=got;}return -1;}
        return 1;
    case 0x0407CC79u:
        if(!js_v06c_read8(m,0x80F98Fu,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F98Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F990u,&got,stop)) return -1;
        if(got!=0x05u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F990u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CC89u:
        if(!js_v06c_read8(m,0x80F991u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F991u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F992u,&got,stop)) return -1;
        if(got!=0xF6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F992u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F993u,&got,stop)) return -1;
        if(got!=0xF9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F993u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CCA1u:
        if(!js_v06c_read8(m,0x80F994u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F994u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F995u,&got,stop)) return -1;
        if(got!=0xF3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F995u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CCB1u:
        if(!js_v06c_read8(m,0x80F996u,&got,stop)) return -1;
        if(got!=0x28u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F996u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CCBBu:
        if(!js_v06c_read8(m,0x80F997u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F997u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CE13u:
        if(!js_v06c_read8(m,0x80F9C2u,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9C2u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CE1Bu:
        if(!js_v06c_read8(m,0x80F9C3u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9C3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F9C4u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9C4u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CE28u:
        if(!js_v06c_read8(m,0x80F9C5u,&got,stop)) return -1;
        if(got!=0xDAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9C5u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CE30u:
        if(!js_v06c_read8(m,0x80F9C6u,&got,stop)) return -1;
        if(got!=0x5Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9C6u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CE38u:
        if(!js_v06c_read8(m,0x80F9C7u,&got,stop)) return -1;
        if(got!=0x48u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9C7u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CE40u:
        if(!js_v06c_read8(m,0x80F9C8u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9C8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F9C9u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9C9u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CE53u:
        if(!js_v06c_read8(m,0x80F9CAu,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9CAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F9CBu,&got,stop)) return -1;
        if(got!=0x5Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9CBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F9CCu,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9CCu;stop->value=got;}return -1;}
        return 1;
    case 0x0407CE6Bu:
        if(!js_v06c_read8(m,0x80F9CDu,&got,stop)) return -1;
        if(got!=0xAAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9CDu;stop->value=got;}return -1;}
        return 1;
    case 0x0407CE73u:
        if(!js_v06c_read8(m,0x80F9CEu,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9CEu;stop->value=got;}return -1;}
        return 1;
    case 0x0407CE7Bu:
        if(!js_v06c_read8(m,0x80F9CFu,&got,stop)) return -1;
        if(got!=0x29u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9CFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F9D0u,&got,stop)) return -1;
        if(got!=0x3Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9D0u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CE8Bu:
        if(!js_v06c_read8(m,0x80F9D1u,&got,stop)) return -1;
        if(got!=0xCDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9D1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F9D2u,&got,stop)) return -1;
        if(got!=0x5Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9D2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F9D3u,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9D3u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CEA3u:
        if(!js_v06c_read8(m,0x80F9D4u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9D4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F9D5u,&got,stop)) return -1;
        if(got!=0x15u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9D5u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CEB3u:
        if(!js_v06c_read8(m,0x80F9D6u,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9D6u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CEBBu:
        if(!js_v06c_read8(m,0x80F9D7u,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9D7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F9D8u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9D8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F9D9u,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9D9u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CED3u:
        if(!js_v06c_read8(m,0x80F9DAu,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9DAu;stop->value=got;}return -1;}
        return 1;
    case 0x0407CEDBu:
        if(!js_v06c_read8(m,0x80F9DBu,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9DBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F9DCu,&got,stop)) return -1;
        if(got!=0x62u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9DCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F9DDu,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9DDu;stop->value=got;}return -1;}
        return 1;
    case 0x0407CEF3u:
        if(!js_v06c_read8(m,0x80F9DEu,&got,stop)) return -1;
        if(got!=0xE8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9DEu;stop->value=got;}return -1;}
        return 1;
    case 0x0407CEFBu:
        if(!js_v06c_read8(m,0x80F9DFu,&got,stop)) return -1;
        if(got!=0x8Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9DFu;stop->value=got;}return -1;}
        return 1;
    case 0x0407CF03u:
        if(!js_v06c_read8(m,0x80F9E0u,&got,stop)) return -1;
        if(got!=0x29u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9E0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F9E1u,&got,stop)) return -1;
        if(got!=0x3Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9E1u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CF13u:
        if(!js_v06c_read8(m,0x80F9E2u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9E2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F9E3u,&got,stop)) return -1;
        if(got!=0x5Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9E3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F9E4u,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9E4u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CF2Bu:
        if(!js_v06c_read8(m,0x80F9E5u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9E5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F9E6u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9E6u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CF38u:
        if(!js_v06c_read8(m,0x80F9E7u,&got,stop)) return -1;
        if(got!=0x7Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9E7u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CF40u:
        if(!js_v06c_read8(m,0x80F9E8u,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9E8u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CF48u:
        if(!js_v06c_read8(m,0x80F9E9u,&got,stop)) return -1;
        if(got!=0x28u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9E9u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CF53u:
        if(!js_v06c_read8(m,0x80F9EAu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9EAu;stop->value=got;}return -1;}
        return 1;
    case 0x0407CF5Bu:
        if(!js_v06c_read8(m,0x80F9EBu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9EBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F9ECu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9ECu;stop->value=got;}return -1;}
        return 1;
    case 0x0407CF68u:
        if(!js_v06c_read8(m,0x80F9EDu,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9EDu;stop->value=got;}return -1;}
        return 1;
    case 0x0407CF70u:
        if(!js_v06c_read8(m,0x80F9EEu,&got,stop)) return -1;
        if(got!=0x7Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9EEu;stop->value=got;}return -1;}
        return 1;
    case 0x0407CF78u:
        if(!js_v06c_read8(m,0x80F9EFu,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9EFu;stop->value=got;}return -1;}
        return 1;
    case 0x0407CF80u:
        if(!js_v06c_read8(m,0x80F9F0u,&got,stop)) return -1;
        if(got!=0x28u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9F0u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CF8Bu:
        if(!js_v06c_read8(m,0x80F9F1u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9F1u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CFB1u:
        if(!js_v06c_read8(m,0x80F9F6u,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9F6u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CFB9u:
        if(!js_v06c_read8(m,0x80F9F7u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9F7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F9F8u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9F8u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CFC8u:
        if(!js_v06c_read8(m,0x80F9F9u,&got,stop)) return -1;
        if(got!=0xDAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9F9u;stop->value=got;}return -1;}
        return 1;
    case 0x0407CFD0u:
        if(!js_v06c_read8(m,0x80F9FAu,&got,stop)) return -1;
        if(got!=0x5Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9FAu;stop->value=got;}return -1;}
        return 1;
    case 0x0407CFD8u:
        if(!js_v06c_read8(m,0x80F9FBu,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9FBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F9FCu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9FCu;stop->value=got;}return -1;}
        return 1;
    case 0x0407CFEBu:
        if(!js_v06c_read8(m,0x80F9FDu,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9FDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F9FEu,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9FEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80F9FFu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80F9FFu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D003u:
        if(!js_v06c_read8(m,0x80FA00u,&got,stop)) return -1;
        if(got!=0xCDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA00u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA01u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA01u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA02u,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA02u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D01Bu:
        if(!js_v06c_read8(m,0x80FA03u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA03u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA04u,&got,stop)) return -1;
        if(got!=0x2Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA04u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D02Bu:
        if(!js_v06c_read8(m,0x80FA05u,&got,stop)) return -1;
        if(got!=0xEBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA05u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D033u:
        if(!js_v06c_read8(m,0x80FA06u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA06u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA07u,&got,stop)) return -1;
        if(got!=0x5Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA07u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA08u,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA08u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D04Bu:
        if(!js_v06c_read8(m,0x80FA09u,&got,stop)) return -1;
        if(got!=0xCDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA09u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA0Au,&got,stop)) return -1;
        if(got!=0x5Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA0Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA0Bu,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA0Bu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D063u:
        if(!js_v06c_read8(m,0x80FA0Cu,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA0Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA0Du,&got,stop)) return -1;
        if(got!=0x23u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA0Du;stop->value=got;}return -1;}
        return 1;
    case 0x0407D073u:
        if(!js_v06c_read8(m,0x80FA0Eu,&got,stop)) return -1;
        if(got!=0xAAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA0Eu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D07Bu:
        if(!js_v06c_read8(m,0x80FA0Fu,&got,stop)) return -1;
        if(got!=0xBDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA0Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA10u,&got,stop)) return -1;
        if(got!=0x62u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA10u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA11u,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA11u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D093u:
        if(!js_v06c_read8(m,0x80FA12u,&got,stop)) return -1;
        if(got!=0x48u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA12u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D09Bu:
        if(!js_v06c_read8(m,0x80FA13u,&got,stop)) return -1;
        if(got!=0xEBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA13u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D0A3u:
        if(!js_v06c_read8(m,0x80FA14u,&got,stop)) return -1;
        if(got!=0x49u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA14u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA15u,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA15u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D0B3u:
        if(!js_v06c_read8(m,0x80FA16u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA16u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA17u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA17u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA18u,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA18u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D0CBu:
        if(!js_v06c_read8(m,0x80FA19u,&got,stop)) return -1;
        if(got!=0x1Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA19u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA1Au,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA1Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA1Bu,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA1Bu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D0E3u:
        if(!js_v06c_read8(m,0x80FA1Cu,&got,stop)) return -1;
        if(got!=0x48u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA1Cu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D0EBu:
        if(!js_v06c_read8(m,0x80FA1Du,&got,stop)) return -1;
        if(got!=0x8Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA1Du;stop->value=got;}return -1;}
        return 1;
    case 0x0407D0F3u:
        if(!js_v06c_read8(m,0x80FA1Eu,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA1Eu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D0FBu:
        if(!js_v06c_read8(m,0x80FA1Fu,&got,stop)) return -1;
        if(got!=0x29u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA1Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA20u,&got,stop)) return -1;
        if(got!=0x3Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA20u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D10Bu:
        if(!js_v06c_read8(m,0x80FA21u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA21u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA22u,&got,stop)) return -1;
        if(got!=0x5Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA22u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA23u,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA23u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D123u:
        if(!js_v06c_read8(m,0x80FA24u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA24u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA25u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA25u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D131u:
        if(!js_v06c_read8(m,0x80FA26u,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA26u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D139u:
        if(!js_v06c_read8(m,0x80FA27u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA27u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA28u,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA28u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA29u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA29u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D151u:
        if(!js_v06c_read8(m,0x80FA2Au,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA2Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA2Bu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA2Bu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D160u:
        if(!js_v06c_read8(m,0x80FA2Cu,&got,stop)) return -1;
        if(got!=0x7Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA2Cu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D168u:
        if(!js_v06c_read8(m,0x80FA2Du,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA2Du;stop->value=got;}return -1;}
        return 1;
    case 0x0407D170u:
        if(!js_v06c_read8(m,0x80FA2Eu,&got,stop)) return -1;
        if(got!=0x28u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA2Eu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D179u:
        if(!js_v06c_read8(m,0x80FA2Fu,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA2Fu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D181u:
        if(!js_v06c_read8(m,0x80FA30u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA30u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D18Bu:
        if(!js_v06c_read8(m,0x80FA31u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA31u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA32u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA32u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D198u:
        if(!js_v06c_read8(m,0x80FA33u,&got,stop)) return -1;
        if(got!=0x7Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA33u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D1A0u:
        if(!js_v06c_read8(m,0x80FA34u,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA34u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D1A8u:
        if(!js_v06c_read8(m,0x80FA35u,&got,stop)) return -1;
        if(got!=0x28u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA35u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D1B1u:
        if(!js_v06c_read8(m,0x80FA36u,&got,stop)) return -1;
        if(got!=0x38u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA36u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D1B9u:
        if(!js_v06c_read8(m,0x80FA37u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA37u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D1C3u:
        if(!js_v06c_read8(m,0x80FA38u,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA38u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D1CBu:
        if(!js_v06c_read8(m,0x80FA39u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA39u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA3Au,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA3Au;stop->value=got;}return -1;}
        return 1;
    case 0x0407D1D8u:
        if(!js_v06c_read8(m,0x80FA3Bu,&got,stop)) return -1;
        if(got!=0x48u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA3Bu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D1E0u:
        if(!js_v06c_read8(m,0x80FA3Cu,&got,stop)) return -1;
        if(got!=0xDAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA3Cu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D1E8u:
        if(!js_v06c_read8(m,0x80FA3Du,&got,stop)) return -1;
        if(got!=0x5Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA3Du;stop->value=got;}return -1;}
        return 1;
    case 0x0407D1F0u:
        if(!js_v06c_read8(m,0x80FA3Eu,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA3Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA3Fu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA3Fu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D202u:
        if(!js_v06c_read8(m,0x80FA40u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA40u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA41u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA41u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D212u:
        if(!js_v06c_read8(m,0x80FA42u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA42u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA43u,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA43u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA44u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA44u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D22Au:
        if(!js_v06c_read8(m,0x80FA45u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA45u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA46u,&got,stop)) return -1;
        if(got!=0xEAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA46u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA47u,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA47u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D242u:
        if(!js_v06c_read8(m,0x80FA48u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA48u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA49u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA49u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D250u:
        if(!js_v06c_read8(m,0x80FA4Au,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA4Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA4Bu,&got,stop)) return -1;
        if(got!=0xAAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA4Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA4Cu,&got,stop)) return -1;
        if(got!=0xBBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA4Cu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D268u:
        if(!js_v06c_read8(m,0x80FA4Du,&got,stop)) return -1;
        if(got!=0xCDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA4Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA4Eu,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA4Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA4Fu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA4Fu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D280u:
        if(!js_v06c_read8(m,0x80FA50u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA50u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA51u,&got,stop)) return -1;
        if(got!=0xFBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA51u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D290u:
        if(!js_v06c_read8(m,0x80FA52u,&got,stop)) return -1;
        if(got!=0xA7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA52u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA53u,&got,stop)) return -1;
        if(got!=0x91u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA53u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D2A0u:
        if(!js_v06c_read8(m,0x80FA54u,&got,stop)) return -1;
        if(got!=0xAAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA54u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D2A8u:
        if(!js_v06c_read8(m,0x80FA55u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA55u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA56u,&got,stop)) return -1;
        if(got!=0x1Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA56u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA57u,&got,stop)) return -1;
        if(got!=0xFBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA57u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D2C0u:
        if(!js_v06c_read8(m,0x80FA58u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA58u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA59u,&got,stop)) return -1;
        if(got!=0x1Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA59u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA5Au,&got,stop)) return -1;
        if(got!=0xFBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA5Au;stop->value=got;}return -1;}
        return 1;
    case 0x0407D2D8u:
        if(!js_v06c_read8(m,0x80FA5Bu,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA5Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA5Cu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA5Cu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D2EAu:
        if(!js_v06c_read8(m,0x80FA5Du,&got,stop)) return -1;
        if(got!=0x64u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA5Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA5Eu,&got,stop)) return -1;
        if(got!=0x90u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA5Eu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D2FAu:
        if(!js_v06c_read8(m,0x80FA5Fu,&got,stop)) return -1;
        if(got!=0xA7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA5Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA60u,&got,stop)) return -1;
        if(got!=0x91u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA60u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D30Au:
        if(!js_v06c_read8(m,0x80FA61u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA61u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA62u,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA62u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA63u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA63u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D322u:
        if(!js_v06c_read8(m,0x80FA64u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA64u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA65u,&got,stop)) return -1;
        if(got!=0x1Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA65u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA66u,&got,stop)) return -1;
        if(got!=0xFBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA66u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D33Au:
        if(!js_v06c_read8(m,0x80FA67u,&got,stop)) return -1;
        if(got!=0xA7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA67u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA68u,&got,stop)) return -1;
        if(got!=0x91u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA68u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D34Au:
        if(!js_v06c_read8(m,0x80FA69u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA69u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA6Au,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA6Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA6Bu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA6Bu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D362u:
        if(!js_v06c_read8(m,0x80FA6Cu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA6Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA6Du,&got,stop)) return -1;
        if(got!=0x1Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA6Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA6Eu,&got,stop)) return -1;
        if(got!=0xFBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA6Eu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D37Au:
        if(!js_v06c_read8(m,0x80FA6Fu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA6Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA70u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA70u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D388u:
        if(!js_v06c_read8(m,0x80FA71u,&got,stop)) return -1;
        if(got!=0xA7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA71u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA72u,&got,stop)) return -1;
        if(got!=0x91u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA72u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D398u:
        if(!js_v06c_read8(m,0x80FA73u,&got,stop)) return -1;
        if(got!=0x48u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA73u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D3A0u:
        if(!js_v06c_read8(m,0x80FA74u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA74u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA75u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA75u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D3B2u:
        if(!js_v06c_read8(m,0x80FA76u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA76u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA77u,&got,stop)) return -1;
        if(got!=0x1Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA77u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA78u,&got,stop)) return -1;
        if(got!=0xFBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA78u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D3CAu:
        if(!js_v06c_read8(m,0x80FA79u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA79u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA7Au,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA7Au;stop->value=got;}return -1;}
        return 1;
    case 0x0407D3DAu:
        if(!js_v06c_read8(m,0x80FA7Bu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA7Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA7Cu,&got,stop)) return -1;
        if(got!=0x41u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA7Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA7Du,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA7Du;stop->value=got;}return -1;}
        return 1;
    case 0x0407D3F2u:
        if(!js_v06c_read8(m,0x80FA7Eu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA7Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA7Fu,&got,stop)) return -1;
        if(got!=0xCCu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA7Fu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D402u:
        if(!js_v06c_read8(m,0x80FA80u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA80u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA81u,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA81u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA82u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA82u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D41Au:
        if(!js_v06c_read8(m,0x80FA83u,&got,stop)) return -1;
        if(got!=0xCDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA83u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA84u,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA84u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA85u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA85u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D432u:
        if(!js_v06c_read8(m,0x80FA86u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA86u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA87u,&got,stop)) return -1;
        if(got!=0xF6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA87u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D442u:
        if(!js_v06c_read8(m,0x80FA88u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA88u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA89u,&got,stop)) return -1;
        if(got!=0x1Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA89u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA8Au,&got,stop)) return -1;
        if(got!=0xFBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA8Au;stop->value=got;}return -1;}
        return 1;
    case 0x0407D45Au:
        if(!js_v06c_read8(m,0x80FA8Bu,&got,stop)) return -1;
        if(got!=0xA7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA8Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA8Cu,&got,stop)) return -1;
        if(got!=0x91u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA8Cu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D46Au:
        if(!js_v06c_read8(m,0x80FA8Du,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA8Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA8Eu,&got,stop)) return -1;
        if(got!=0x41u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA8Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA8Fu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA8Fu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D482u:
        if(!js_v06c_read8(m,0x80FA90u,&got,stop)) return -1;
        if(got!=0xA5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA90u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA91u,&got,stop)) return -1;
        if(got!=0x90u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA91u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D492u:
        if(!js_v06c_read8(m,0x80FA92u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA92u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA93u,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA93u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA94u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA94u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D4AAu:
        if(!js_v06c_read8(m,0x80FA95u,&got,stop)) return -1;
        if(got!=0xCDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA95u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA96u,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA96u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA97u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA97u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D4C2u:
        if(!js_v06c_read8(m,0x80FA98u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA98u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA99u,&got,stop)) return -1;
        if(got!=0xFBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA99u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D4D2u:
        if(!js_v06c_read8(m,0x80FA9Au,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA9Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA9Bu,&got,stop)) return -1;
        if(got!=0x90u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA9Bu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D4E2u:
        if(!js_v06c_read8(m,0x80FA9Cu,&got,stop)) return -1;
        if(got!=0xCAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA9Cu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D4EAu:
        if(!js_v06c_read8(m,0x80FA9Du,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA9Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FA9Eu,&got,stop)) return -1;
        if(got!=0xE9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA9Eu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D4FAu:
        if(!js_v06c_read8(m,0x80FA9Fu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FA9Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAA0u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAA0u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D508u:
        if(!js_v06c_read8(m,0x80FAA1u,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAA1u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D510u:
        if(!js_v06c_read8(m,0x80FAA2u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAA2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAA3u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAA3u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D520u:
        if(!js_v06c_read8(m,0x80FAA4u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAA4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAA5u,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAA5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAA6u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAA6u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D538u:
        if(!js_v06c_read8(m,0x80FAA7u,&got,stop)) return -1;
        if(got!=0x48u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAA7u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D540u:
        if(!js_v06c_read8(m,0x80FAA8u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAA8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAA9u,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAA9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAAAu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAAAu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D558u:
        if(!js_v06c_read8(m,0x80FAABu,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAABu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAACu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAACu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D56Au:
        if(!js_v06c_read8(m,0x80FAADu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAADu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAAEu,&got,stop)) return -1;
        if(got!=0x41u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAAEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAAFu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAAFu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D582u:
        if(!js_v06c_read8(m,0x80FAB0u,&got,stop)) return -1;
        if(got!=0xA5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAB0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAB1u,&got,stop)) return -1;
        if(got!=0x90u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAB1u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D592u:
        if(!js_v06c_read8(m,0x80FAB2u,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAB2u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D59Au:
        if(!js_v06c_read8(m,0x80FAB3u,&got,stop)) return -1;
        if(got!=0x69u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAB3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAB4u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAB4u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D5AAu:
        if(!js_v06c_read8(m,0x80FAB5u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAB5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAB6u,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAB6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAB7u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAB7u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D5C2u:
        if(!js_v06c_read8(m,0x80FAB8u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAB8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAB9u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAB9u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D5D0u:
        if(!js_v06c_read8(m,0x80FABAu,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FABAu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D5D8u:
        if(!js_v06c_read8(m,0x80FABBu,&got,stop)) return -1;
        if(got!=0xE0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FABBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FABCu,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FABCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FABDu,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FABDu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D5F0u:
        if(!js_v06c_read8(m,0x80FABEu,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FABEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FABFu,&got,stop)) return -1;
        if(got!=0x1Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FABFu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D600u:
        if(!js_v06c_read8(m,0x80FAC0u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAC0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAC1u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAC1u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D612u:
        if(!js_v06c_read8(m,0x80FAC2u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAC2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAC3u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAC3u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D622u:
        if(!js_v06c_read8(m,0x80FAC4u,&got,stop)) return -1;
        if(got!=0xCDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAC4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAC5u,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAC5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAC6u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAC6u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D63Au:
        if(!js_v06c_read8(m,0x80FAC7u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAC7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAC8u,&got,stop)) return -1;
        if(got!=0xFBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAC8u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D64Au:
        if(!js_v06c_read8(m,0x80FAC9u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAC9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FACAu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FACAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FACBu,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FACBu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D662u:
        if(!js_v06c_read8(m,0x80FACCu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FACCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FACDu,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FACDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FACEu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FACEu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D67Au:
        if(!js_v06c_read8(m,0x80FACFu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FACFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAD0u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAD0u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D688u:
        if(!js_v06c_read8(m,0x80FAD1u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAD1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAD2u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAD2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAD3u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAD3u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D6A0u:
        if(!js_v06c_read8(m,0x80FAD4u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAD4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAD5u,&got,stop)) return -1;
        if(got!=0x5Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAD5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAD6u,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAD6u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D6B8u:
        if(!js_v06c_read8(m,0x80FAD7u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAD7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAD8u,&got,stop)) return -1;
        if(got!=0x5Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAD8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAD9u,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAD9u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D6D0u:
        if(!js_v06c_read8(m,0x80FADAu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FADAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FADBu,&got,stop)) return -1;
        if(got!=0x07u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FADBu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D6E0u:
        if(!js_v06c_read8(m,0x80FADCu,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FADCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FADDu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FADDu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D6F2u:
        if(!js_v06c_read8(m,0x80FADEu,&got,stop)) return -1;
        if(got!=0xCDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FADEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FADFu,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FADFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAE0u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAE0u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D70Au:
        if(!js_v06c_read8(m,0x80FAE1u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAE1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAE2u,&got,stop)) return -1;
        if(got!=0xFBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAE2u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D718u:
        if(!js_v06c_read8(m,0x80FAE3u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAE3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAE4u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAE4u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D71Au:
        if(!js_v06c_read8(m,0x80FAE3u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAE3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAE4u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAE4u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D728u:
        if(!js_v06c_read8(m,0x80FAE5u,&got,stop)) return -1;
        if(got!=0x7Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAE5u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D730u:
        if(!js_v06c_read8(m,0x80FAE6u,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAE6u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D738u:
        if(!js_v06c_read8(m,0x80FAE7u,&got,stop)) return -1;
        if(got!=0x68u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAE7u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D740u:
        if(!js_v06c_read8(m,0x80FAE8u,&got,stop)) return -1;
        if(got!=0x28u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAE8u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D74Bu:
        if(!js_v06c_read8(m,0x80FAE9u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAE9u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D752u:
        if(!js_v06c_read8(m,0x80FAEAu,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAEAu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D75Au:
        if(!js_v06c_read8(m,0x80FAEBu,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAEBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAECu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAECu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D76Au:
        if(!js_v06c_read8(m,0x80FAEDu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAEDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAEEu,&got,stop)) return -1;
        if(got!=0x82u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAEEu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D77Au:
        if(!js_v06c_read8(m,0x80FAEFu,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAEFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAF0u,&got,stop)) return -1;
        if(got!=0x93u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAF0u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D78Au:
        if(!js_v06c_read8(m,0x80FAF1u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAF1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAF2u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAF2u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D798u:
        if(!js_v06c_read8(m,0x80FAF3u,&got,stop)) return -1;
        if(got!=0x8Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAF3u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D7A0u:
        if(!js_v06c_read8(m,0x80FAF4u,&got,stop)) return -1;
        if(got!=0x29u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAF4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAF5u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAF5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAF6u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAF6u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D7B8u:
        if(!js_v06c_read8(m,0x80FAF7u,&got,stop)) return -1;
        if(got!=0xAAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAF7u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D7C0u:
        if(!js_v06c_read8(m,0x80FAF8u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAF8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAF9u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAF9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAFAu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAFAu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D7D8u:
        if(!js_v06c_read8(m,0x80FAFBu,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAFBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAFCu,&got,stop)) return -1;
        if(got!=0x91u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAFCu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D7E8u:
        if(!js_v06c_read8(m,0x80FAFDu,&got,stop)) return -1;
        if(got!=0xCAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAFDu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D7F0u:
        if(!js_v06c_read8(m,0x80FAFEu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAFEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FAFFu,&got,stop)) return -1;
        if(got!=0x1Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FAFFu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D800u:
        if(!js_v06c_read8(m,0x80FB00u,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB00u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D808u:
        if(!js_v06c_read8(m,0x80FB01u,&got,stop)) return -1;
        if(got!=0x67u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB01u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB02u,&got,stop)) return -1;
        if(got!=0x91u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB02u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D818u:
        if(!js_v06c_read8(m,0x80FB03u,&got,stop)) return -1;
        if(got!=0x90u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB03u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB04u,&got,stop)) return -1;
        if(got!=0x06u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB04u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D828u:
        if(!js_v06c_read8(m,0x80FB05u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB05u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB06u,&got,stop)) return -1;
        if(got!=0x93u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB06u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D838u:
        if(!js_v06c_read8(m,0x80FB07u,&got,stop)) return -1;
        if(got!=0x38u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB07u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D840u:
        if(!js_v06c_read8(m,0x80FB08u,&got,stop)) return -1;
        if(got!=0xE9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB08u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB09u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB09u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB0Au,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB0Au;stop->value=got;}return -1;}
        return 1;
    case 0x0407D858u:
        if(!js_v06c_read8(m,0x80FB0Bu,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB0Bu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D860u:
        if(!js_v06c_read8(m,0x80FB0Cu,&got,stop)) return -1;
        if(got!=0x69u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB0Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB0Du,&got,stop)) return -1;
        if(got!=0x06u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB0Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB0Eu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB0Eu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D878u:
        if(!js_v06c_read8(m,0x80FB0Fu,&got,stop)) return -1;
        if(got!=0x90u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB0Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB10u,&got,stop)) return -1;
        if(got!=0x06u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB10u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D888u:
        if(!js_v06c_read8(m,0x80FB11u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB11u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB12u,&got,stop)) return -1;
        if(got!=0x93u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB12u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D898u:
        if(!js_v06c_read8(m,0x80FB13u,&got,stop)) return -1;
        if(got!=0x38u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB13u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D8A0u:
        if(!js_v06c_read8(m,0x80FB14u,&got,stop)) return -1;
        if(got!=0xE9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB14u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB15u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB15u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB16u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB16u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D8B8u:
        if(!js_v06c_read8(m,0x80FB17u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB17u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB18u,&got,stop)) return -1;
        if(got!=0x91u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB18u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D8C8u:
        if(!js_v06c_read8(m,0x80FB19u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB19u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB1Au,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB1Au;stop->value=got;}return -1;}
        return 1;
    case 0x0407D8D8u:
        if(!js_v06c_read8(m,0x80FB1Bu,&got,stop)) return -1;
        if(got!=0x28u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB1Bu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D8E2u:
        if(!js_v06c_read8(m,0x80FB1Cu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB1Cu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D8E8u:
        if(!js_v06c_read8(m,0x80FB1Du,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB1Du;stop->value=got;}return -1;}
        return 1;
    case 0x0407D8EAu:
        if(!js_v06c_read8(m,0x80FB1Du,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB1Du;stop->value=got;}return -1;}
        return 1;
    case 0x0407D8F0u:
        if(!js_v06c_read8(m,0x80FB1Eu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB1Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB1Fu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB1Fu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D8F2u:
        if(!js_v06c_read8(m,0x80FB1Eu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB1Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB1Fu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB1Fu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D900u:
        if(!js_v06c_read8(m,0x80FB20u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB20u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB21u,&got,stop)) return -1;
        if(got!=0x91u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB21u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D910u:
        if(!js_v06c_read8(m,0x80FB22u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB22u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB23u,&got,stop)) return -1;
        if(got!=0x09u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB23u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D920u:
        if(!js_v06c_read8(m,0x80FB24u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB24u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB25u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB25u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB26u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB26u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D938u:
        if(!js_v06c_read8(m,0x80FB27u,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB27u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB28u,&got,stop)) return -1;
        if(got!=0x91u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB28u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D948u:
        if(!js_v06c_read8(m,0x80FB29u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB29u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB2Au,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB2Au;stop->value=got;}return -1;}
        return 1;
    case 0x0407D95Au:
        if(!js_v06c_read8(m,0x80FB2Bu,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB2Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB2Cu,&got,stop)) return -1;
        if(got!=0x93u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB2Cu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D968u:
        if(!js_v06c_read8(m,0x80FB2Du,&got,stop)) return -1;
        if(got!=0x28u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB2Du;stop->value=got;}return -1;}
        return 1;
    case 0x0407D96Au:
        if(!js_v06c_read8(m,0x80FB2Du,&got,stop)) return -1;
        if(got!=0x28u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB2Du;stop->value=got;}return -1;}
        return 1;
    case 0x0407D970u:
        if(!js_v06c_read8(m,0x80FB2Eu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB2Eu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D972u:
        if(!js_v06c_read8(m,0x80FB2Eu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB2Eu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D97Bu:
        if(!js_v06c_read8(m,0x80FB2Fu,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB2Fu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D983u:
        if(!js_v06c_read8(m,0x80FB30u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB30u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB31u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB31u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D993u:
        if(!js_v06c_read8(m,0x80FB32u,&got,stop)) return -1;
        if(got!=0x64u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB32u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB33u,&got,stop)) return -1;
        if(got!=0xDBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB33u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D9A3u:
        if(!js_v06c_read8(m,0x80FB34u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB34u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB35u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB35u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D9B1u:
        if(!js_v06c_read8(m,0x80FB36u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB36u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB37u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB37u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB38u,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB38u;stop->value=got;}return -1;}
        return 1;
    case 0x0407D9C9u:
        if(!js_v06c_read8(m,0x80FB39u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB39u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB3Au,&got,stop)) return -1;
        if(got!=0xE4u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB3Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB3Bu,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB3Bu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D9E1u:
        if(!js_v06c_read8(m,0x80FB3Cu,&got,stop)) return -1;
        if(got!=0x28u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB3Cu;stop->value=got;}return -1;}
        return 1;
    case 0x0407D9EBu:
        if(!js_v06c_read8(m,0x80FB3Du,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB3Du;stop->value=got;}return -1;}
        return 1;
    case 0x0407D9F3u:
        if(!js_v06c_read8(m,0x80FB3Eu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB3Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB3Fu,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB3Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB40u,&got,stop)) return -1;
        if(got!=0xFBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB40u;stop->value=got;}return -1;}
        return 1;
    case 0x0407DA0Bu:
        if(!js_v06c_read8(m,0x80FB41u,&got,stop)) return -1;
        if(got!=0x6Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB41u;stop->value=got;}return -1;}
        return 1;
    case 0x0407DA13u:
        if(!js_v06c_read8(m,0x80FB42u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB42u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB43u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB43u;stop->value=got;}return -1;}
        return 1;
    case 0x0407DA23u:
        if(!js_v06c_read8(m,0x80FB44u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB44u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB45u,&got,stop)) return -1;
        if(got!=0x2Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB45u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB46u,&got,stop)) return -1;
        if(got!=0xF9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB46u;stop->value=got;}return -1;}
        return 1;
    case 0x0407DA3Bu:
        if(!js_v06c_read8(m,0x80FB47u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB47u;stop->value=got;}return -1;}
        return 1;
    case 0x0407DA93u:
        if(!js_v06c_read8(m,0x80FB52u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB52u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB53u,&got,stop)) return -1;
        if(got!=0x56u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB53u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB54u,&got,stop)) return -1;
        if(got!=0xFBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB54u;stop->value=got;}return -1;}
        return 1;
    case 0x0407DAABu:
        if(!js_v06c_read8(m,0x80FB55u,&got,stop)) return -1;
        if(got!=0x6Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB55u;stop->value=got;}return -1;}
        return 1;
    case 0x0407DAB3u:
        if(!js_v06c_read8(m,0x80FB56u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB56u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB57u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB57u;stop->value=got;}return -1;}
        return 1;
    case 0x0407DAC3u:
        if(!js_v06c_read8(m,0x80FB58u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB58u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB59u,&got,stop)) return -1;
        if(got!=0x2Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB59u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x80FB5Au,&got,stop)) return -1;
        if(got!=0xF9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB5Au;stop->value=got;}return -1;}
        return 1;
    case 0x0407DADBu:
        if(!js_v06c_read8(m,0x80FB5Bu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x80FB5Bu;stop->value=got;}return -1;}
        return 1;
    default: return 0;
    }
}
