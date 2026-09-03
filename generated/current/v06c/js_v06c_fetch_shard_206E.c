#include "js_v06c_fetch.h"

int js_v06c_fetch_shard_206E(JSV06Machine *m, JSV06Stop *stop) {
    uint8_t got;
    switch(js_cpu_context_key(&m->cpu)) {
    case 0x040DD0CBu:
        if(!js_v06c_read8(m,0x81BA19u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA19u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA1Au,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA1Au;stop->value=got;}return -1;}
        return 1;
    case 0x040DD0D9u:
        if(!js_v06c_read8(m,0x81BA1Bu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA1Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA1Cu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA1Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA1Du,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA1Du;stop->value=got;}return -1;}
        return 1;
    case 0x040DD0F1u:
        if(!js_v06c_read8(m,0x81BA1Eu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA1Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA1Fu,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA1Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA20u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA20u;stop->value=got;}return -1;}
        return 1;
    case 0x040DD109u:
        if(!js_v06c_read8(m,0x81BA21u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA21u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA22u,&got,stop)) return -1;
        if(got!=0x04u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA22u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA23u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA23u;stop->value=got;}return -1;}
        return 1;
    case 0x040DD121u:
        if(!js_v06c_read8(m,0x81BA24u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA24u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA25u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA25u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA26u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA26u;stop->value=got;}return -1;}
        return 1;
    case 0x040DD139u:
        if(!js_v06c_read8(m,0x81BA27u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA27u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA28u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA28u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA29u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA29u;stop->value=got;}return -1;}
        return 1;
    case 0x040DD151u:
        if(!js_v06c_read8(m,0x81BA2Au,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA2Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA2Bu,&got,stop)) return -1;
        if(got!=0x06u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA2Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA2Cu,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA2Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040DD169u:
        if(!js_v06c_read8(m,0x81BA2Du,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA2Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA2Eu,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA2Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA2Fu,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA2Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040DD181u:
        if(!js_v06c_read8(m,0x81BA30u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA30u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA31u,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA31u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA32u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA32u;stop->value=got;}return -1;}
        return 1;
    case 0x040DD199u:
        if(!js_v06c_read8(m,0x81BA33u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA33u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA34u,&got,stop)) return -1;
        if(got!=0x0Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA34u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA35u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA35u;stop->value=got;}return -1;}
        return 1;
    case 0x040DD1B1u:
        if(!js_v06c_read8(m,0x81BA36u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA36u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA37u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA37u;stop->value=got;}return -1;}
        return 1;
    case 0x040DD1C3u:
        if(!js_v06c_read8(m,0x81BA38u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA38u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA39u,&got,stop)) return -1;
        if(got!=0x46u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA39u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA3Au,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA3Au;stop->value=got;}return -1;}
        return 1;
    case 0x040DD1DBu:
        if(!js_v06c_read8(m,0x81BA3Bu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA3Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA3Cu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA3Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040DD1EBu:
        if(!js_v06c_read8(m,0x81BA3Du,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA3Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA3Eu,&got,stop)) return -1;
        if(got!=0x5Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA3Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA3Fu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA3Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040DD203u:
        if(!js_v06c_read8(m,0x81BA40u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA40u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA41u,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA41u;stop->value=got;}return -1;}
        return 1;
    case 0x040DD213u:
        if(!js_v06c_read8(m,0x81BA42u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA42u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA43u,&got,stop)) return -1;
        if(got!=0x5Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA43u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA44u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA44u;stop->value=got;}return -1;}
        return 1;
    case 0x040DD22Bu:
        if(!js_v06c_read8(m,0x81BA45u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA45u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA46u,&got,stop)) return -1;
        if(got!=0x09u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA46u;stop->value=got;}return -1;}
        return 1;
    case 0x040DD23Bu:
        if(!js_v06c_read8(m,0x81BA47u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA47u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA48u,&got,stop)) return -1;
        if(got!=0x09u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA48u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA49u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA49u;stop->value=got;}return -1;}
        return 1;
    case 0x040DD253u:
        if(!js_v06c_read8(m,0x81BA4Au,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA4Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA4Bu,&got,stop)) return -1;
        if(got!=0x81u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA4Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040DD263u:
        if(!js_v06c_read8(m,0x81BA4Cu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA4Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA4Du,&got,stop)) return -1;
        if(got!=0xB1u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA4Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA4Eu,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA4Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040DD27Bu:
        if(!js_v06c_read8(m,0x81BA4Fu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA4Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA50u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA50u;stop->value=got;}return -1;}
        return 1;
    case 0x040DD288u:
        if(!js_v06c_read8(m,0x81BA51u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA51u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA52u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA52u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA53u,&got,stop)) return -1;
        if(got!=0xBDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA53u;stop->value=got;}return -1;}
        return 1;
    case 0x040DD2A0u:
        if(!js_v06c_read8(m,0x81BA54u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA54u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA55u,&got,stop)) return -1;
        if(got!=0x64u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA55u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA56u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA56u;stop->value=got;}return -1;}
        return 1;
    case 0x040DD2B8u:
        if(!js_v06c_read8(m,0x81BA57u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA57u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA58u,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA58u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA59u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA59u;stop->value=got;}return -1;}
        return 1;
    case 0x040DD2D0u:
        if(!js_v06c_read8(m,0x81BA5Au,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA5Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA5Bu,&got,stop)) return -1;
        if(got!=0x19u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA5Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA5Cu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA5Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040DD2E8u:
        if(!js_v06c_read8(m,0x81BA5Du,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA5Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA5Eu,&got,stop)) return -1;
        if(got!=0x72u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA5Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81BA5Fu,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81BA5Fu;stop->value=got;}return -1;}
        return 1;
    default: return 0;
    }
}
