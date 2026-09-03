#include "js_v06c_fetch.h"

int js_v06c_fetch_shard_207D(JSV06Machine *m, JSV06Stop *stop) {
    uint8_t got;
    switch(js_cpu_context_key(&m->cpu)) {
    case 0x040FA2A3u:
        if(!js_v06c_read8(m,0x81F454u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F454u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F455u,&got,stop)) return -1;
        if(got!=0x15u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F455u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F456u,&got,stop)) return -1;
        if(got!=0xA4u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F456u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F457u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F457u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA2C3u:
        if(!js_v06c_read8(m,0x81F458u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F458u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F459u,&got,stop)) return -1;
        if(got!=0x46u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F459u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F45Au,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F45Au;stop->value=got;}return -1;}
        return 1;
    case 0x040FA2DBu:
        if(!js_v06c_read8(m,0x81F45Bu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F45Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F45Cu,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F45Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040FA2EBu:
        if(!js_v06c_read8(m,0x81F45Du,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F45Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F45Eu,&got,stop)) return -1;
        if(got!=0xB1u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F45Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F45Fu,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F45Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040FA303u:
        if(!js_v06c_read8(m,0x81F460u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F460u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F461u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F461u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA313u:
        if(!js_v06c_read8(m,0x81F462u,&got,stop)) return -1;
        if(got!=0x8Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F462u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F463u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F463u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F464u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F464u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F465u,&got,stop)) return -1;
        if(got!=0x7Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F465u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA333u:
        if(!js_v06c_read8(m,0x81F466u,&got,stop)) return -1;
        if(got!=0x8Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F466u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F467u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F467u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F468u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F468u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F469u,&got,stop)) return -1;
        if(got!=0x7Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F469u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA353u:
        if(!js_v06c_read8(m,0x81F46Au,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F46Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F46Bu,&got,stop)) return -1;
        if(got!=0x0Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F46Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040FA363u:
        if(!js_v06c_read8(m,0x81F46Cu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F46Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F46Du,&got,stop)) return -1;
        if(got!=0x05u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F46Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F46Eu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F46Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040FA37Bu:
        if(!js_v06c_read8(m,0x81F46Fu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F46Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F470u,&got,stop)) return -1;
        if(got!=0x78u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F470u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA38Bu:
        if(!js_v06c_read8(m,0x81F471u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F471u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F472u,&got,stop)) return -1;
        if(got!=0x07u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F472u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F473u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F473u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA3A3u:
        if(!js_v06c_read8(m,0x81F474u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F474u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F475u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F475u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA3B3u:
        if(!js_v06c_read8(m,0x81F476u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F476u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F477u,&got,stop)) return -1;
        if(got!=0x0Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F477u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F478u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F478u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA3CBu:
        if(!js_v06c_read8(m,0x81F479u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F479u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F47Au,&got,stop)) return -1;
        if(got!=0x11u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F47Au;stop->value=got;}return -1;}
        return 1;
    case 0x040FA3DBu:
        if(!js_v06c_read8(m,0x81F47Bu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F47Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F47Cu,&got,stop)) return -1;
        if(got!=0x2Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F47Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F47Du,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F47Du;stop->value=got;}return -1;}
        return 1;
    case 0x040FA3F3u:
        if(!js_v06c_read8(m,0x81F47Eu,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F47Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F47Fu,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F47Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F480u,&got,stop)) return -1;
        if(got!=0x0Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F480u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA40Bu:
        if(!js_v06c_read8(m,0x81F481u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F481u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F482u,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F482u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA41Bu:
        if(!js_v06c_read8(m,0x81F483u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F483u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F484u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F484u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA428u:
        if(!js_v06c_read8(m,0x81F485u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F485u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F486u,&got,stop)) return -1;
        if(got!=0x7Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F486u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F487u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F487u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA440u:
        if(!js_v06c_read8(m,0x81F488u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F488u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F489u,&got,stop)) return -1;
        if(got!=0x7Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F489u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F48Au,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F48Au;stop->value=got;}return -1;}
        return 1;
    case 0x040FA458u:
        if(!js_v06c_read8(m,0x81F48Bu,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F48Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F48Cu,&got,stop)) return -1;
        if(got!=0x7Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F48Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F48Du,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F48Du;stop->value=got;}return -1;}
        return 1;
    case 0x040FA470u:
        if(!js_v06c_read8(m,0x81F48Eu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F48Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F48Fu,&got,stop)) return -1;
        if(got!=0x72u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F48Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F490u,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F490u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA49Bu:
        if(!js_v06c_read8(m,0x81F493u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F493u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F494u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F494u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA4A8u:
        if(!js_v06c_read8(m,0x81F495u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F495u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F496u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F496u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F497u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F497u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA4C0u:
        if(!js_v06c_read8(m,0x81F498u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F498u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F499u,&got,stop)) return -1;
        if(got!=0x50u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F499u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F49Au,&got,stop)) return -1;
        if(got!=0x9Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F49Au;stop->value=got;}return -1;}
        return 1;
    case 0x040FA4D8u:
        if(!js_v06c_read8(m,0x81F49Bu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F49Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F49Cu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F49Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F49Du,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F49Du;stop->value=got;}return -1;}
        return 1;
    case 0x040FA4F0u:
        if(!js_v06c_read8(m,0x81F49Eu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F49Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F49Fu,&got,stop)) return -1;
        if(got!=0x12u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F49Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4A0u,&got,stop)) return -1;
        if(got!=0x9Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4A0u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA508u:
        if(!js_v06c_read8(m,0x81F4A1u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4A1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4A2u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4A2u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA51Bu:
        if(!js_v06c_read8(m,0x81F4A3u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4A3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4A4u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4A4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4A5u,&got,stop)) return -1;
        if(got!=0x0Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4A5u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA533u:
        if(!js_v06c_read8(m,0x81F4A6u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4A6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4A7u,&got,stop)) return -1;
        if(got!=0x3Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4A7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4A8u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4A8u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA54Bu:
        if(!js_v06c_read8(m,0x81F4A9u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4A9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4AAu,&got,stop)) return -1;
        if(got!=0x0Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4AAu;stop->value=got;}return -1;}
        return 1;
    case 0x040FA55Bu:
        if(!js_v06c_read8(m,0x81F4ABu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4ABu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4ACu,&got,stop)) return -1;
        if(got!=0x55u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4ACu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4ADu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4ADu;stop->value=got;}return -1;}
        return 1;
    case 0x040FA573u:
        if(!js_v06c_read8(m,0x81F4AEu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4AEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4AFu,&got,stop)) return -1;
        if(got!=0x81u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4AFu;stop->value=got;}return -1;}
        return 1;
    case 0x040FA583u:
        if(!js_v06c_read8(m,0x81F4B0u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4B0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4B1u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4B1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4B2u,&got,stop)) return -1;
        if(got!=0x42u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4B2u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA59Bu:
        if(!js_v06c_read8(m,0x81F4B3u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4B3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4B4u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4B4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4B5u,&got,stop)) return -1;
        if(got!=0x0Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4B5u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA5B3u:
        if(!js_v06c_read8(m,0x81F4B6u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4B6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4B7u,&got,stop)) return -1;
        if(got!=0x24u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4B7u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA5C3u:
        if(!js_v06c_read8(m,0x81F4B8u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4B8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4B9u,&got,stop)) return -1;
        if(got!=0x8Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4B9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4BAu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4BAu;stop->value=got;}return -1;}
        return 1;
    case 0x040FA5DBu:
        if(!js_v06c_read8(m,0x81F4BBu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4BBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4BCu,&got,stop)) return -1;
        if(got!=0xB6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4BCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4BDu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4BDu;stop->value=got;}return -1;}
        return 1;
    case 0x040FA5F3u:
        if(!js_v06c_read8(m,0x81F4BEu,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4BEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4BFu,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4BFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4C0u,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4C0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4C1u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4C1u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA613u:
        if(!js_v06c_read8(m,0x81F4C2u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4C2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4C3u,&got,stop)) return -1;
        if(got!=0x5Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4C3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4C4u,&got,stop)) return -1;
        if(got!=0x9Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4C4u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA62Bu:
        if(!js_v06c_read8(m,0x81F4C5u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4C5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4C6u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4C6u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA63Bu:
        if(!js_v06c_read8(m,0x81F4C7u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4C7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4C8u,&got,stop)) return -1;
        if(got!=0xEDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4C8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4C9u,&got,stop)) return -1;
        if(got!=0xF5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4C9u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA653u:
        if(!js_v06c_read8(m,0x81F4CAu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4CAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4CBu,&got,stop)) return -1;
        if(got!=0x38u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4CBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4CCu,&got,stop)) return -1;
        if(got!=0xF5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4CCu;stop->value=got;}return -1;}
        return 1;
    case 0x040FA66Bu:
        if(!js_v06c_read8(m,0x81F4CDu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4CDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4CEu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4CEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4CFu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4CFu;stop->value=got;}return -1;}
        return 1;
    case 0x040FA683u:
        if(!js_v06c_read8(m,0x81F4D0u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4D0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4D1u,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4D1u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA693u:
        if(!js_v06c_read8(m,0x81F4D2u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4D2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4D3u,&got,stop)) return -1;
        if(got!=0xEDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4D3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4D4u,&got,stop)) return -1;
        if(got!=0xF5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4D4u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA6ABu:
        if(!js_v06c_read8(m,0x81F4D5u,&got,stop)) return -1;
        if(got!=0x90u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4D5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4D6u,&got,stop)) return -1;
        if(got!=0x33u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4D6u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA6BBu:
        if(!js_v06c_read8(m,0x81F4D7u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4D7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4D8u,&got,stop)) return -1;
        if(got!=0x50u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4D8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4D9u,&got,stop)) return -1;
        if(got!=0xF6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4D9u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA6D3u:
        if(!js_v06c_read8(m,0x81F4DAu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4DAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4DBu,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4DBu;stop->value=got;}return -1;}
        return 1;
    case 0x040FA6E3u:
        if(!js_v06c_read8(m,0x81F4DCu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4DCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4DDu,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4DDu;stop->value=got;}return -1;}
        return 1;
    case 0x040FA6F3u:
        if(!js_v06c_read8(m,0x81F4DEu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4DEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4DFu,&got,stop)) return -1;
        if(got!=0x2Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4DFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4E0u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4E0u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA70Bu:
        if(!js_v06c_read8(m,0x81F4E1u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4E1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4E2u,&got,stop)) return -1;
        if(got!=0x06u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4E2u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA71Bu:
        if(!js_v06c_read8(m,0x81F4E3u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4E3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4E4u,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4E4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4E5u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4E5u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA733u:
        if(!js_v06c_read8(m,0x81F4E6u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4E6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4E7u,&got,stop)) return -1;
        if(got!=0xC1u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4E7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4E8u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4E8u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA74Bu:
        if(!js_v06c_read8(m,0x81F4E9u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4E9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4EAu,&got,stop)) return -1;
        if(got!=0xF7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4EAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4EBu,&got,stop)) return -1;
        if(got!=0xF7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4EBu;stop->value=got;}return -1;}
        return 1;
    case 0x040FA763u:
        if(!js_v06c_read8(m,0x81F4ECu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4ECu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4EDu,&got,stop)) return -1;
        if(got!=0x8Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4EDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4EEu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4EEu;stop->value=got;}return -1;}
        return 1;
    case 0x040FA77Bu:
        if(!js_v06c_read8(m,0x81F4EFu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4EFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4F0u,&got,stop)) return -1;
        if(got!=0xB6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4F0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4F1u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4F1u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA793u:
        if(!js_v06c_read8(m,0x81F4F2u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4F2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4F3u,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4F3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4F4u,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4F4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4F5u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4F5u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA7B3u:
        if(!js_v06c_read8(m,0x81F4F6u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4F6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4F7u,&got,stop)) return -1;
        if(got!=0xA4u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4F7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4F8u,&got,stop)) return -1;
        if(got!=0xF6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4F8u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA7CBu:
        if(!js_v06c_read8(m,0x81F4F9u,&got,stop)) return -1;
        if(got!=0xB0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4F9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4FAu,&got,stop)) return -1;
        if(got!=0x0Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4FAu;stop->value=got;}return -1;}
        return 1;
    case 0x040FA7DBu:
        if(!js_v06c_read8(m,0x81F4FBu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4FBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4FCu,&got,stop)) return -1;
        if(got!=0x86u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4FCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4FDu,&got,stop)) return -1;
        if(got!=0xF7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4FDu;stop->value=got;}return -1;}
        return 1;
    case 0x040FA7F3u:
        if(!js_v06c_read8(m,0x81F4FEu,&got,stop)) return -1;
        if(got!=0xB0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4FEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F4FFu,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F4FFu;stop->value=got;}return -1;}
        return 1;
    case 0x040FA803u:
        if(!js_v06c_read8(m,0x81F500u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F500u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F501u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F501u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F502u,&got,stop)) return -1;
        if(got!=0xF7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F502u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA81Bu:
        if(!js_v06c_read8(m,0x81F503u,&got,stop)) return -1;
        if(got!=0xB0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F503u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F504u,&got,stop)) return -1;
        if(got!=0x05u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F504u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA82Bu:
        if(!js_v06c_read8(m,0x81F505u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F505u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F506u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F506u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F507u,&got,stop)) return -1;
        if(got!=0x0Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F507u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA843u:
        if(!js_v06c_read8(m,0x81F508u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F508u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F509u,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F509u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA853u:
        if(!js_v06c_read8(m,0x81F50Au,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F50Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F50Bu,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F50Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F50Cu,&got,stop)) return -1;
        if(got!=0x0Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F50Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040FA86Bu:
        if(!js_v06c_read8(m,0x81F50Du,&got,stop)) return -1;
        if(got!=0x09u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F50Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F50Eu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F50Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040FA87Bu:
        if(!js_v06c_read8(m,0x81F50Fu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F50Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F510u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F510u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F511u,&got,stop)) return -1;
        if(got!=0x0Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F511u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA893u:
        if(!js_v06c_read8(m,0x81F512u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F512u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F513u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F513u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA8A3u:
        if(!js_v06c_read8(m,0x81F514u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F514u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F515u,&got,stop)) return -1;
        if(got!=0x55u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F515u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F516u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F516u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA8BBu:
        if(!js_v06c_read8(m,0x81F517u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F517u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F518u,&got,stop)) return -1;
        if(got!=0xEAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F518u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F519u,&got,stop)) return -1;
        if(got!=0xA3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F519u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F51Au,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F51Au;stop->value=got;}return -1;}
        return 1;
    case 0x040FA8DBu:
        if(!js_v06c_read8(m,0x81F51Bu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F51Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F51Cu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F51Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040FA8EBu:
        if(!js_v06c_read8(m,0x81F51Du,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F51Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F51Eu,&got,stop)) return -1;
        if(got!=0x07u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F51Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F51Fu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F51Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040FA903u:
        if(!js_v06c_read8(m,0x81F520u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F520u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F521u,&got,stop)) return -1;
        if(got!=0x11u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F521u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA913u:
        if(!js_v06c_read8(m,0x81F522u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F522u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F523u,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F523u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F524u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F524u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA92Bu:
        if(!js_v06c_read8(m,0x81F525u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F525u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F526u,&got,stop)) return -1;
        if(got!=0x44u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F526u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA93Bu:
        if(!js_v06c_read8(m,0x81F527u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F527u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F528u,&got,stop)) return -1;
        if(got!=0x0Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F528u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F529u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F529u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA953u:
        if(!js_v06c_read8(m,0x81F52Au,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F52Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F52Bu,&got,stop)) return -1;
        if(got!=0x09u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F52Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040FA963u:
        if(!js_v06c_read8(m,0x81F52Cu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F52Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F52Du,&got,stop)) return -1;
        if(got!=0x05u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F52Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F52Eu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F52Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040FA97Bu:
        if(!js_v06c_read8(m,0x81F52Fu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F52Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F530u,&got,stop)) return -1;
        if(got!=0x15u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F530u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA98Bu:
        if(!js_v06c_read8(m,0x81F531u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F531u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F532u,&got,stop)) return -1;
        if(got!=0x2Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F532u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F533u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F533u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA9A3u:
        if(!js_v06c_read8(m,0x81F534u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F534u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F535u,&got,stop)) return -1;
        if(got!=0x31u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F535u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F536u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F536u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA9BBu:
        if(!js_v06c_read8(m,0x81F537u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F537u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA9C3u:
        if(!js_v06c_read8(m,0x81F538u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F538u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F539u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F539u;stop->value=got;}return -1;}
        return 1;
    case 0x040FA9D0u:
        if(!js_v06c_read8(m,0x81F53Au,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F53Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F53Bu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F53Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F53Cu,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F53Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040FA9E8u:
        if(!js_v06c_read8(m,0x81F53Du,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F53Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F53Eu,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F53Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F53Fu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F53Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040FAA00u:
        if(!js_v06c_read8(m,0x81F540u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F540u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F541u,&got,stop)) return -1;
        if(got!=0x04u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F541u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F542u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F542u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAA18u:
        if(!js_v06c_read8(m,0x81F543u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F543u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F544u,&got,stop)) return -1;
        if(got!=0xC3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F544u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F545u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F545u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAA30u:
        if(!js_v06c_read8(m,0x81F546u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F546u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F547u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F547u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAA43u:
        if(!js_v06c_read8(m,0x81F548u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F548u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F549u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F549u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F54Au,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F54Au;stop->value=got;}return -1;}
        return 1;
    case 0x040FAA5Bu:
        if(!js_v06c_read8(m,0x81F54Bu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F54Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F54Cu,&got,stop)) return -1;
        if(got!=0xC5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F54Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F54Du,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F54Du;stop->value=got;}return -1;}
        return 1;
    case 0x040FAA73u:
        if(!js_v06c_read8(m,0x81F54Eu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F54Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F54Fu,&got,stop)) return -1;
        if(got!=0x5Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F54Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F550u,&got,stop)) return -1;
        if(got!=0xF5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F550u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAA8Bu:
        if(!js_v06c_read8(m,0x81F551u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F551u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F552u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F552u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAA98u:
        if(!js_v06c_read8(m,0x81F553u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F553u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F554u,&got,stop)) return -1;
        if(got!=0xF8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F554u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F555u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F555u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAAB0u:
        if(!js_v06c_read8(m,0x81F556u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F556u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F557u,&got,stop)) return -1;
        if(got!=0xC3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F557u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F558u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F558u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAAC8u:
        if(!js_v06c_read8(m,0x81F559u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F559u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F55Au,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F55Au;stop->value=got;}return -1;}
        return 1;
    case 0x040FAADBu:
        if(!js_v06c_read8(m,0x81F55Bu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F55Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F55Cu,&got,stop)) return -1;
        if(got!=0x86u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F55Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F55Du,&got,stop)) return -1;
        if(got!=0xF5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F55Du;stop->value=got;}return -1;}
        return 1;
    case 0x040FAAF3u:
        if(!js_v06c_read8(m,0x81F55Eu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F55Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040FAAF8u:
        if(!js_v06c_read8(m,0x81F55Fu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F55Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F560u,&got,stop)) return -1;
        if(got!=0xBDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F560u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F561u,&got,stop)) return -1;
        if(got!=0xF5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F561u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAAFBu:
        if(!js_v06c_read8(m,0x81F55Fu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F55Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F560u,&got,stop)) return -1;
        if(got!=0xBDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F560u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F561u,&got,stop)) return -1;
        if(got!=0xF5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F561u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAB13u:
        if(!js_v06c_read8(m,0x81F562u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F562u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F563u,&got,stop)) return -1;
        if(got!=0xF7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F563u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F564u,&got,stop)) return -1;
        if(got!=0xF7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F564u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAB2Bu:
        if(!js_v06c_read8(m,0x81F565u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F565u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F566u,&got,stop)) return -1;
        if(got!=0x8Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F566u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F567u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F567u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAB43u:
        if(!js_v06c_read8(m,0x81F568u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F568u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F569u,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F569u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F56Au,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F56Au;stop->value=got;}return -1;}
        return 1;
    case 0x040FAB5Bu:
        if(!js_v06c_read8(m,0x81F56Bu,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F56Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F56Cu,&got,stop)) return -1;
        if(got!=0xFBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F56Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040FAB6Bu:
        if(!js_v06c_read8(m,0x81F56Du,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F56Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F56Eu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F56Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040FAB78u:
        if(!js_v06c_read8(m,0x81F56Fu,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F56Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F570u,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F570u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F571u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F571u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAB90u:
        if(!js_v06c_read8(m,0x81F572u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F572u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F573u,&got,stop)) return -1;
        if(got!=0xEBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F573u;stop->value=got;}return -1;}
        return 1;
    case 0x040FABA0u:
        if(!js_v06c_read8(m,0x81F574u,&got,stop)) return -1;
        if(got!=0xC9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F574u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F575u,&got,stop)) return -1;
        if(got!=0x7Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F575u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F576u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F576u;stop->value=got;}return -1;}
        return 1;
    case 0x040FABB8u:
        if(!js_v06c_read8(m,0x81F577u,&got,stop)) return -1;
        if(got!=0x90u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F577u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F578u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F578u;stop->value=got;}return -1;}
        return 1;
    case 0x040FABC8u:
        if(!js_v06c_read8(m,0x81F579u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F579u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F57Au,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F57Au;stop->value=got;}return -1;}
        return 1;
    case 0x040FABDBu:
        if(!js_v06c_read8(m,0x81F57Bu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F57Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F57Cu,&got,stop)) return -1;
        if(got!=0x0Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F57Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040FABEBu:
        if(!js_v06c_read8(m,0x81F57Du,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F57Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F57Eu,&got,stop)) return -1;
        if(got!=0x26u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F57Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F57Fu,&got,stop)) return -1;
        if(got!=0xF9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F57Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F580u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F580u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAC0Bu:
        if(!js_v06c_read8(m,0x81F581u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F581u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F582u,&got,stop)) return -1;
        if(got!=0x82u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F582u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F583u,&got,stop)) return -1;
        if(got!=0xF9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F583u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F584u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F584u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAC2Bu:
        if(!js_v06c_read8(m,0x81F585u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F585u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAC30u:
        if(!js_v06c_read8(m,0x81F586u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F586u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F587u,&got,stop)) return -1;
        if(got!=0xBDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F587u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F588u,&got,stop)) return -1;
        if(got!=0xF5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F588u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAC33u:
        if(!js_v06c_read8(m,0x81F586u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F586u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F587u,&got,stop)) return -1;
        if(got!=0xBDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F587u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F588u,&got,stop)) return -1;
        if(got!=0xF5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F588u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAC4Bu:
        if(!js_v06c_read8(m,0x81F589u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F589u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F58Au,&got,stop)) return -1;
        if(got!=0xF7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F58Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F58Bu,&got,stop)) return -1;
        if(got!=0xF7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F58Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040FAC63u:
        if(!js_v06c_read8(m,0x81F58Cu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F58Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F58Du,&got,stop)) return -1;
        if(got!=0x8Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F58Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F58Eu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F58Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040FAC7Bu:
        if(!js_v06c_read8(m,0x81F58Fu,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F58Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F590u,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F590u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F591u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F591u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAC93u:
        if(!js_v06c_read8(m,0x81F592u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F592u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F593u,&got,stop)) return -1;
        if(got!=0xFBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F593u;stop->value=got;}return -1;}
        return 1;
    case 0x040FACA3u:
        if(!js_v06c_read8(m,0x81F594u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F594u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F595u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F595u;stop->value=got;}return -1;}
        return 1;
    case 0x040FACB0u:
        if(!js_v06c_read8(m,0x81F596u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F596u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F597u,&got,stop)) return -1;
        if(got!=0xC3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F597u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F598u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F598u;stop->value=got;}return -1;}
        return 1;
    case 0x040FACC8u:
        if(!js_v06c_read8(m,0x81F599u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F599u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F59Au,&got,stop)) return -1;
        if(got!=0xEBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F59Au;stop->value=got;}return -1;}
        return 1;
    case 0x040FACD8u:
        if(!js_v06c_read8(m,0x81F59Bu,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F59Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F59Cu,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F59Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F59Du,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F59Du;stop->value=got;}return -1;}
        return 1;
    case 0x040FACF0u:
        if(!js_v06c_read8(m,0x81F59Eu,&got,stop)) return -1;
        if(got!=0x38u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F59Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040FACF8u:
        if(!js_v06c_read8(m,0x81F59Fu,&got,stop)) return -1;
        if(got!=0xE9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F59Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5A0u,&got,stop)) return -1;
        if(got!=0x04u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5A0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5A1u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5A1u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAD10u:
        if(!js_v06c_read8(m,0x81F5A2u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5A2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5A3u,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5A3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5A4u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5A4u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAD28u:
        if(!js_v06c_read8(m,0x81F5A5u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5A5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5A6u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5A6u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAD3Bu:
        if(!js_v06c_read8(m,0x81F5A7u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5A7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5A8u,&got,stop)) return -1;
        if(got!=0xF7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5A8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5A9u,&got,stop)) return -1;
        if(got!=0xF7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5A9u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAD53u:
        if(!js_v06c_read8(m,0x81F5AAu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5AAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5ABu,&got,stop)) return -1;
        if(got!=0x8Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5ABu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5ACu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5ACu;stop->value=got;}return -1;}
        return 1;
    case 0x040FAD6Bu:
        if(!js_v06c_read8(m,0x81F5ADu,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5ADu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5AEu,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5AEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5AFu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5AFu;stop->value=got;}return -1;}
        return 1;
    case 0x040FAD83u:
        if(!js_v06c_read8(m,0x81F5B0u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5B0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5B1u,&got,stop)) return -1;
        if(got!=0xFBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5B1u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAD93u:
        if(!js_v06c_read8(m,0x81F5B2u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5B2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5B3u,&got,stop)) return -1;
        if(got!=0x07u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5B3u;stop->value=got;}return -1;}
        return 1;
    case 0x040FADA3u:
        if(!js_v06c_read8(m,0x81F5B4u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5B4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5B5u,&got,stop)) return -1;
        if(got!=0x26u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5B5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5B6u,&got,stop)) return -1;
        if(got!=0xF9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5B6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5B7u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5B7u;stop->value=got;}return -1;}
        return 1;
    case 0x040FADC3u:
        if(!js_v06c_read8(m,0x81F5B8u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5B8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5B9u,&got,stop)) return -1;
        if(got!=0x82u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5B9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5BAu,&got,stop)) return -1;
        if(got!=0xF9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5BAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5BBu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5BBu;stop->value=got;}return -1;}
        return 1;
    case 0x040FADE3u:
        if(!js_v06c_read8(m,0x81F5BCu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5BCu;stop->value=got;}return -1;}
        return 1;
    case 0x040FADE8u:
        if(!js_v06c_read8(m,0x81F5BDu,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5BDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5BEu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5BEu;stop->value=got;}return -1;}
        return 1;
    case 0x040FADEBu:
        if(!js_v06c_read8(m,0x81F5BDu,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5BDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5BEu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5BEu;stop->value=got;}return -1;}
        return 1;
    case 0x040FADFBu:
        if(!js_v06c_read8(m,0x81F5BFu,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5BFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5C0u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5C0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5C1u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5C1u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAE13u:
        if(!js_v06c_read8(m,0x81F5C2u,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5C2u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAE1Bu:
        if(!js_v06c_read8(m,0x81F5C3u,&got,stop)) return -1;
        if(got!=0x6Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5C3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5C4u,&got,stop)) return -1;
        if(got!=0xC5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5C4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5C5u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5C5u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAE33u:
        if(!js_v06c_read8(m,0x81F5C6u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5C6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5C7u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5C7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5C8u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5C8u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAE4Bu:
        if(!js_v06c_read8(m,0x81F5C9u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5C9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5CAu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5CAu;stop->value=got;}return -1;}
        return 1;
    case 0x040FAE58u:
        if(!js_v06c_read8(m,0x81F5CBu,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5CBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5CCu,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5CCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5CDu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5CDu;stop->value=got;}return -1;}
        return 1;
    case 0x040FAE70u:
        if(!js_v06c_read8(m,0x81F5CEu,&got,stop)) return -1;
        if(got!=0x6Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5CEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5CFu,&got,stop)) return -1;
        if(got!=0xC3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5CFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5D0u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5D0u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAE88u:
        if(!js_v06c_read8(m,0x81F5D1u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5D1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5D2u,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5D2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5D3u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5D3u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAEA0u:
        if(!js_v06c_read8(m,0x81F5D4u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5D4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5D5u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5D5u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAEB3u:
        if(!js_v06c_read8(m,0x81F5D6u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5D6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5D7u,&got,stop)) return -1;
        if(got!=0xC5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5D7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5D8u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5D8u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAECBu:
        if(!js_v06c_read8(m,0x81F5D9u,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5D9u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAED3u:
        if(!js_v06c_read8(m,0x81F5DAu,&got,stop)) return -1;
        if(got!=0x69u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5DAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5DBu,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5DBu;stop->value=got;}return -1;}
        return 1;
    case 0x040FAEE3u:
        if(!js_v06c_read8(m,0x81F5DCu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5DCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5DDu,&got,stop)) return -1;
        if(got!=0xC5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5DDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5DEu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5DEu;stop->value=got;}return -1;}
        return 1;
    case 0x040FAEFBu:
        if(!js_v06c_read8(m,0x81F5DFu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5DFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5E0u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5E0u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAF08u:
        if(!js_v06c_read8(m,0x81F5E1u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5E1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5E2u,&got,stop)) return -1;
        if(got!=0xC3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5E2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5E3u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5E3u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAF20u:
        if(!js_v06c_read8(m,0x81F5E4u,&got,stop)) return -1;
        if(got!=0x69u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5E4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5E5u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5E5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5E6u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5E6u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAF38u:
        if(!js_v06c_read8(m,0x81F5E7u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5E7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5E8u,&got,stop)) return -1;
        if(got!=0xC3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5E8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5E9u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5E9u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAF50u:
        if(!js_v06c_read8(m,0x81F5EAu,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5EAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5EBu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5EBu;stop->value=got;}return -1;}
        return 1;
    case 0x040FAF63u:
        if(!js_v06c_read8(m,0x81F5ECu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5ECu;stop->value=got;}return -1;}
        return 1;
    case 0x040FAF6Bu:
        if(!js_v06c_read8(m,0x81F5EDu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5EDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5EEu,&got,stop)) return -1;
        if(got!=0x89u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5EEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5EFu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5EFu;stop->value=got;}return -1;}
        return 1;
    case 0x040FAF83u:
        if(!js_v06c_read8(m,0x81F5F0u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5F0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5F1u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5F1u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAF90u:
        if(!js_v06c_read8(m,0x81F5F2u,&got,stop)) return -1;
        if(got!=0x29u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5F2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5F3u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5F3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5F4u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5F4u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAFA8u:
        if(!js_v06c_read8(m,0x81F5F5u,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5F5u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAFB0u:
        if(!js_v06c_read8(m,0x81F5F6u,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5F6u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAFB8u:
        if(!js_v06c_read8(m,0x81F5F7u,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5F7u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAFC0u:
        if(!js_v06c_read8(m,0x81F5F8u,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5F8u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAFC8u:
        if(!js_v06c_read8(m,0x81F5F9u,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5F9u;stop->value=got;}return -1;}
        return 1;
    case 0x040FAFD0u:
        if(!js_v06c_read8(m,0x81F5FAu,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5FAu;stop->value=got;}return -1;}
        return 1;
    case 0x040FAFD8u:
        if(!js_v06c_read8(m,0x81F5FBu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5FBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5FCu,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5FCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5FDu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5FDu;stop->value=got;}return -1;}
        return 1;
    case 0x040FAFF0u:
        if(!js_v06c_read8(m,0x81F5FEu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5FEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5FFu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5FFu;stop->value=got;}return -1;}
        return 1;
    case 0x040FAFF3u:
        if(!js_v06c_read8(m,0x81F5FEu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5FEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F5FFu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F5FFu;stop->value=got;}return -1;}
        return 1;
    case 0x040FB000u:
        if(!js_v06c_read8(m,0x81F600u,&got,stop)) return -1;
        if(got!=0xCEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F600u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F601u,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F601u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F602u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F602u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB018u:
        if(!js_v06c_read8(m,0x81F603u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F603u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F604u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F604u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB02Bu:
        if(!js_v06c_read8(m,0x81F605u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F605u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F606u,&got,stop)) return -1;
        if(got!=0x1Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F606u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB03Bu:
        if(!js_v06c_read8(m,0x81F607u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F607u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F608u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F608u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F609u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F609u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB053u:
        if(!js_v06c_read8(m,0x81F60Au,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F60Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F60Bu,&got,stop)) return -1;
        if(got!=0x05u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F60Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040FB063u:
        if(!js_v06c_read8(m,0x81F60Cu,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F60Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F60Du,&got,stop)) return -1;
        if(got!=0x89u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F60Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F60Eu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F60Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040FB07Bu:
        if(!js_v06c_read8(m,0x81F60Fu,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F60Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F610u,&got,stop)) return -1;
        if(got!=0x0Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F610u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB08Bu:
        if(!js_v06c_read8(m,0x81F611u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F611u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F612u,&got,stop)) return -1;
        if(got!=0x7Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F612u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F613u,&got,stop)) return -1;
        if(got!=0x12u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F613u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB0A3u:
        if(!js_v06c_read8(m,0x81F614u,&got,stop)) return -1;
        if(got!=0xCDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F614u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F615u,&got,stop)) return -1;
        if(got!=0x7Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F615u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F616u,&got,stop)) return -1;
        if(got!=0x12u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F616u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB0BBu:
        if(!js_v06c_read8(m,0x81F617u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F617u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F618u,&got,stop)) return -1;
        if(got!=0xFBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F618u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB0CBu:
        if(!js_v06c_read8(m,0x81F619u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F619u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F61Au,&got,stop)) return -1;
        if(got!=0xE3u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F61Au;stop->value=got;}return -1;}
        return 1;
    case 0x040FB0DBu:
        if(!js_v06c_read8(m,0x81F61Bu,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F61Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F61Cu,&got,stop)) return -1;
        if(got!=0x3Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F61Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F61Du,&got,stop)) return -1;
        if(got!=0xFBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F61Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F61Eu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F61Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040FB0FBu:
        if(!js_v06c_read8(m,0x81F61Fu,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F61Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F620u,&got,stop)) return -1;
        if(got!=0x82u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F620u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F621u,&got,stop)) return -1;
        if(got!=0xF9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F621u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F622u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F622u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB11Bu:
        if(!js_v06c_read8(m,0x81F623u,&got,stop)) return -1;
        if(got!=0x38u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F623u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB123u:
        if(!js_v06c_read8(m,0x81F624u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F624u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB12Bu:
        if(!js_v06c_read8(m,0x81F625u,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F625u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB133u:
        if(!js_v06c_read8(m,0x81F626u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F626u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB283u:
        if(!js_v06c_read8(m,0x81F650u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F650u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F651u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F651u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F652u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F652u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB29Bu:
        if(!js_v06c_read8(m,0x81F653u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F653u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F654u,&got,stop)) return -1;
        if(got!=0xE0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F654u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB2ABu:
        if(!js_v06c_read8(m,0x81F655u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F655u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F656u,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F656u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F657u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F657u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB2C3u:
        if(!js_v06c_read8(m,0x81F658u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F658u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F659u,&got,stop)) return -1;
        if(got!=0x32u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F659u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F65Au,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F65Au;stop->value=got;}return -1;}
        return 1;
    case 0x040FB2DBu:
        if(!js_v06c_read8(m,0x81F65Bu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F65Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F65Cu,&got,stop)) return -1;
        if(got!=0xAFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F65Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040FB2EBu:
        if(!js_v06c_read8(m,0x81F65Du,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F65Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F65Eu,&got,stop)) return -1;
        if(got!=0x31u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F65Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F65Fu,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F65Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040FB303u:
        if(!js_v06c_read8(m,0x81F660u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F660u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F661u,&got,stop)) return -1;
        if(got!=0x8Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F661u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F662u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F662u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB31Bu:
        if(!js_v06c_read8(m,0x81F663u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F663u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F664u,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F664u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F665u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F665u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB333u:
        if(!js_v06c_read8(m,0x81F666u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F666u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F667u,&got,stop)) return -1;
        if(got!=0xFBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F667u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB343u:
        if(!js_v06c_read8(m,0x81F668u,&got,stop)) return -1;
        if(got!=0xEEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F668u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F669u,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F669u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F66Au,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F66Au;stop->value=got;}return -1;}
        return 1;
    case 0x040FB35Bu:
        if(!js_v06c_read8(m,0x81F66Bu,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F66Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F66Cu,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F66Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F66Du,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F66Du;stop->value=got;}return -1;}
        return 1;
    case 0x040FB373u:
        if(!js_v06c_read8(m,0x81F66Eu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F66Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F66Fu,&got,stop)) return -1;
        if(got!=0x32u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F66Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F670u,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F670u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB38Bu:
        if(!js_v06c_read8(m,0x81F671u,&got,stop)) return -1;
        if(got!=0xC9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F671u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F672u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F672u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB39Bu:
        if(!js_v06c_read8(m,0x81F673u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F673u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F674u,&got,stop)) return -1;
        if(got!=0xEBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F674u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB3ABu:
        if(!js_v06c_read8(m,0x81F675u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F675u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB3B3u:
        if(!js_v06c_read8(m,0x81F676u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F676u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F677u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F677u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB3C1u:
        if(!js_v06c_read8(m,0x81F678u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F678u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F679u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F679u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F67Au,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F67Au;stop->value=got;}return -1;}
        return 1;
    case 0x040FB3D9u:
        if(!js_v06c_read8(m,0x81F67Bu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F67Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F67Cu,&got,stop)) return -1;
        if(got!=0x16u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F67Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F67Du,&got,stop)) return -1;
        if(got!=0x21u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F67Du;stop->value=got;}return -1;}
        return 1;
    case 0x040FB3F1u:
        if(!js_v06c_read8(m,0x81F67Eu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F67Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F67Fu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F67Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F680u,&got,stop)) return -1;
        if(got!=0x35u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F680u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB409u:
        if(!js_v06c_read8(m,0x81F681u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F681u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F682u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F682u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F683u,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F683u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB421u:
        if(!js_v06c_read8(m,0x81F684u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F684u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F685u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F685u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F686u,&got,stop)) return -1;
        if(got!=0x10u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F686u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB439u:
        if(!js_v06c_read8(m,0x81F687u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F687u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F688u,&got,stop)) return -1;
        if(got!=0x05u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F688u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F689u,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F689u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB451u:
        if(!js_v06c_read8(m,0x81F68Au,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F68Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F68Bu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F68Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040FB463u:
        if(!js_v06c_read8(m,0x81F68Cu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F68Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F68Du,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F68Du;stop->value=got;}return -1;}
        return 1;
    case 0x040FB473u:
        if(!js_v06c_read8(m,0x81F68Eu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F68Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F68Fu,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F68Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F690u,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F690u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB48Bu:
        if(!js_v06c_read8(m,0x81F691u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F691u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F692u,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F692u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB49Bu:
        if(!js_v06c_read8(m,0x81F693u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F693u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F694u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F694u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F695u,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F695u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB4B3u:
        if(!js_v06c_read8(m,0x81F696u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F696u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F697u,&got,stop)) return -1;
        if(got!=0x7Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F697u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB4C3u:
        if(!js_v06c_read8(m,0x81F698u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F698u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F699u,&got,stop)) return -1;
        if(got!=0x04u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F699u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F69Au,&got,stop)) return -1;
        if(got!=0x43u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F69Au;stop->value=got;}return -1;}
        return 1;
    case 0x040FB4DBu:
        if(!js_v06c_read8(m,0x81F69Bu,&got,stop)) return -1;
        if(got!=0xEEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F69Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F69Cu,&got,stop)) return -1;
        if(got!=0x97u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F69Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F69Du,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F69Du;stop->value=got;}return -1;}
        return 1;
    case 0x040FB4F3u:
        if(!js_v06c_read8(m,0x81F69Eu,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F69Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F69Fu,&got,stop)) return -1;
        if(got!=0x97u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F69Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6A0u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6A0u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB50Bu:
        if(!js_v06c_read8(m,0x81F6A1u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6A1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6A2u,&got,stop)) return -1;
        if(got!=0xFBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6A2u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB51Bu:
        if(!js_v06c_read8(m,0x81F6A3u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6A3u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB523u:
        if(!js_v06c_read8(m,0x81F6A4u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6A4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6A5u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6A5u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB533u:
        if(!js_v06c_read8(m,0x81F6A6u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6A6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6A7u,&got,stop)) return -1;
        if(got!=0x1Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6A7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6A8u,&got,stop)) return -1;
        if(got!=0xF7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6A8u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB54Bu:
        if(!js_v06c_read8(m,0x81F6A9u,&got,stop)) return -1;
        if(got!=0x90u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6A9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6AAu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6AAu;stop->value=got;}return -1;}
        return 1;
    case 0x040FB55Bu:
        if(!js_v06c_read8(m,0x81F6ABu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6ABu;stop->value=got;}return -1;}
        return 1;
    case 0x040FB563u:
        if(!js_v06c_read8(m,0x81F6ACu,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6ACu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6ADu,&got,stop)) return -1;
        if(got!=0xB8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6ADu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6AEu,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6AEu;stop->value=got;}return -1;}
        return 1;
    case 0x040FB57Bu:
        if(!js_v06c_read8(m,0x81F6AFu,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6AFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6B0u,&got,stop)) return -1;
        if(got!=0x46u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6B0u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB58Bu:
        if(!js_v06c_read8(m,0x81F6B1u,&got,stop)) return -1;
        if(got!=0x3Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6B1u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB593u:
        if(!js_v06c_read8(m,0x81F6B2u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6B2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6B3u,&got,stop)) return -1;
        if(got!=0x3Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6B3u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB5A3u:
        if(!js_v06c_read8(m,0x81F6B4u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6B4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6B5u,&got,stop)) return -1;
        if(got!=0x1Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6B5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6B6u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6B6u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB5BBu:
        if(!js_v06c_read8(m,0x81F6B7u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6B7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6B8u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6B8u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB5CBu:
        if(!js_v06c_read8(m,0x81F6B9u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6B9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6BAu,&got,stop)) return -1;
        if(got!=0x1Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6BAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6BBu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6BBu;stop->value=got;}return -1;}
        return 1;
    case 0x040FB5E3u:
        if(!js_v06c_read8(m,0x81F6BCu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6BCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6BDu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6BDu;stop->value=got;}return -1;}
        return 1;
    case 0x040FB5F1u:
        if(!js_v06c_read8(m,0x81F6BEu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6BEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6BFu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6BFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6C0u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6C0u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB609u:
        if(!js_v06c_read8(m,0x81F6C1u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6C1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6C2u,&got,stop)) return -1;
        if(got!=0xF6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6C2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6C3u,&got,stop)) return -1;
        if(got!=0x0Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6C3u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB621u:
        if(!js_v06c_read8(m,0x81F6C4u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6C4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6C5u,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6C5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6C6u,&got,stop)) return -1;
        if(got!=0x0Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6C6u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB639u:
        if(!js_v06c_read8(m,0x81F6C7u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6C7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6C8u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6C8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6C9u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6C9u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB651u:
        if(!js_v06c_read8(m,0x81F6CAu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6CAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6CBu,&got,stop)) return -1;
        if(got!=0xFEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6CBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6CCu,&got,stop)) return -1;
        if(got!=0x0Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6CCu;stop->value=got;}return -1;}
        return 1;
    case 0x040FB669u:
        if(!js_v06c_read8(m,0x81F6CDu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6CDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6CEu,&got,stop)) return -1;
        if(got!=0x07u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6CEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6CFu,&got,stop)) return -1;
        if(got!=0x07u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6CFu;stop->value=got;}return -1;}
        return 1;
    case 0x040FB681u:
        if(!js_v06c_read8(m,0x81F6D0u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6D0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6D1u,&got,stop)) return -1;
        if(got!=0x6Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6D1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6D2u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6D2u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB699u:
        if(!js_v06c_read8(m,0x81F6D3u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6D3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6D4u,&got,stop)) return -1;
        if(got!=0x73u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6D4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6D5u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6D5u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB6B1u:
        if(!js_v06c_read8(m,0x81F6D6u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6D6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6D7u,&got,stop)) return -1;
        if(got!=0x77u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6D7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6D8u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6D8u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB6C9u:
        if(!js_v06c_read8(m,0x81F6D9u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6D9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6DAu,&got,stop)) return -1;
        if(got!=0x7Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6DAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6DBu,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6DBu;stop->value=got;}return -1;}
        return 1;
    case 0x040FB6E1u:
        if(!js_v06c_read8(m,0x81F6DCu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6DCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6DDu,&got,stop)) return -1;
        if(got!=0x7Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6DDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6DEu,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6DEu;stop->value=got;}return -1;}
        return 1;
    case 0x040FB6F9u:
        if(!js_v06c_read8(m,0x81F6DFu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6DFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6E0u,&got,stop)) return -1;
        if(got!=0x83u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6E0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6E1u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6E1u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB711u:
        if(!js_v06c_read8(m,0x81F6E2u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6E2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6E3u,&got,stop)) return -1;
        if(got!=0x87u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6E3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6E4u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6E4u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB729u:
        if(!js_v06c_read8(m,0x81F6E5u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6E5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6E6u,&got,stop)) return -1;
        if(got!=0x87u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6E6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6E7u,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6E7u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB741u:
        if(!js_v06c_read8(m,0x81F6E8u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6E8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6E9u,&got,stop)) return -1;
        if(got!=0x8Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6E9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6EAu,&got,stop)) return -1;
        if(got!=0x0Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6EAu;stop->value=got;}return -1;}
        return 1;
    case 0x040FB759u:
        if(!js_v06c_read8(m,0x81F6EBu,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6EBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6ECu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6ECu;stop->value=got;}return -1;}
        return 1;
    case 0x040FB76Bu:
        if(!js_v06c_read8(m,0x81F6EDu,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6EDu;stop->value=got;}return -1;}
        return 1;
    case 0x040FB773u:
        if(!js_v06c_read8(m,0x81F6EEu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6EEu;stop->value=got;}return -1;}
        return 1;
    case 0x040FB77Bu:
        if(!js_v06c_read8(m,0x81F6EFu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6EFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6F0u,&got,stop)) return -1;
        if(got!=0x1Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6F0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6F1u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6F1u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB793u:
        if(!js_v06c_read8(m,0x81F6F2u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6F2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6F3u,&got,stop)) return -1;
        if(got!=0x1Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6F3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6F4u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6F4u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB7ABu:
        if(!js_v06c_read8(m,0x81F6F5u,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6F5u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB7B3u:
        if(!js_v06c_read8(m,0x81F6F6u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6F6u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB7BBu:
        if(!js_v06c_read8(m,0x81F6F7u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6F7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6F8u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6F8u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB7CBu:
        if(!js_v06c_read8(m,0x81F6F9u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6F9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6FAu,&got,stop)) return -1;
        if(got!=0x1Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6FAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6FBu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6FBu;stop->value=got;}return -1;}
        return 1;
    case 0x040FB7E3u:
        if(!js_v06c_read8(m,0x81F6FCu,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6FCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6FDu,&got,stop)) return -1;
        if(got!=0x1Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6FDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F6FEu,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6FEu;stop->value=got;}return -1;}
        return 1;
    case 0x040FB7FBu:
        if(!js_v06c_read8(m,0x81F6FFu,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F6FFu;stop->value=got;}return -1;}
        return 1;
    case 0x040FB803u:
        if(!js_v06c_read8(m,0x81F700u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F700u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB80Bu:
        if(!js_v06c_read8(m,0x81F701u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F701u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F702u,&got,stop)) return -1;
        if(got!=0x1Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F702u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F703u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F703u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB823u:
        if(!js_v06c_read8(m,0x81F704u,&got,stop)) return -1;
        if(got!=0x0Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F704u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F705u,&got,stop)) return -1;
        if(got!=0x1Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F705u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F706u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F706u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB83Bu:
        if(!js_v06c_read8(m,0x81F707u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F707u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F708u,&got,stop)) return -1;
        if(got!=0x11u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F708u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB84Bu:
        if(!js_v06c_read8(m,0x81F709u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F709u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F70Au,&got,stop)) return -1;
        if(got!=0x76u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F70Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F70Bu,&got,stop)) return -1;
        if(got!=0xF6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F70Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040FB863u:
        if(!js_v06c_read8(m,0x81F70Cu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F70Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F70Du,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F70Du;stop->value=got;}return -1;}
        return 1;
    case 0x040FB873u:
        if(!js_v06c_read8(m,0x81F70Eu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F70Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F70Fu,&got,stop)) return -1;
        if(got!=0x1Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F70Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F710u,&got,stop)) return -1;
        if(got!=0xF7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F710u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB88Bu:
        if(!js_v06c_read8(m,0x81F711u,&got,stop)) return -1;
        if(got!=0x90u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F711u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F712u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F712u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB89Bu:
        if(!js_v06c_read8(m,0x81F713u,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F713u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB8A3u:
        if(!js_v06c_read8(m,0x81F714u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F714u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F715u,&got,stop)) return -1;
        if(got!=0xB8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F715u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F716u,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F716u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB8BBu:
        if(!js_v06c_read8(m,0x81F717u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F717u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F718u,&got,stop)) return -1;
        if(got!=0x36u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F718u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F719u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F719u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB8D3u:
        if(!js_v06c_read8(m,0x81F71Au,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F71Au;stop->value=got;}return -1;}
        return 1;
    case 0x040FB8DBu:
        if(!js_v06c_read8(m,0x81F71Bu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F71Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040FB8E3u:
        if(!js_v06c_read8(m,0x81F71Cu,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F71Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F71Du,&got,stop)) return -1;
        if(got!=0xB8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F71Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F71Eu,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F71Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040FB8FBu:
        if(!js_v06c_read8(m,0x81F71Fu,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F71Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F720u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F720u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB90Bu:
        if(!js_v06c_read8(m,0x81F721u,&got,stop)) return -1;
        if(got!=0xBDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F721u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F722u,&got,stop)) return -1;
        if(got!=0x7Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F722u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F723u,&got,stop)) return -1;
        if(got!=0xF7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F723u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB923u:
        if(!js_v06c_read8(m,0x81F724u,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F724u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F725u,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F725u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F726u,&got,stop)) return -1;
        if(got!=0x14u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F726u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB93Bu:
        if(!js_v06c_read8(m,0x81F727u,&got,stop)) return -1;
        if(got!=0xE8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F727u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB943u:
        if(!js_v06c_read8(m,0x81F728u,&got,stop)) return -1;
        if(got!=0xE0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F728u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F729u,&got,stop)) return -1;
        if(got!=0x09u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F729u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB953u:
        if(!js_v06c_read8(m,0x81F72Au,&got,stop)) return -1;
        if(got!=0x90u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F72Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F72Bu,&got,stop)) return -1;
        if(got!=0xF5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F72Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040FB963u:
        if(!js_v06c_read8(m,0x81F72Cu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F72Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F72Du,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F72Du;stop->value=got;}return -1;}
        return 1;
    case 0x040FB970u:
        if(!js_v06c_read8(m,0x81F72Eu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F72Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F72Fu,&got,stop)) return -1;
        if(got!=0x84u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F72Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F730u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F730u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB988u:
        if(!js_v06c_read8(m,0x81F731u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F731u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F732u,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F732u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F733u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F733u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB9A0u:
        if(!js_v06c_read8(m,0x81F734u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F734u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F735u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F735u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB9B3u:
        if(!js_v06c_read8(m,0x81F736u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F736u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F737u,&got,stop)) return -1;
        if(got!=0xB6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F737u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F738u,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F738u;stop->value=got;}return -1;}
        return 1;
    case 0x040FB9CBu:
        if(!js_v06c_read8(m,0x81F739u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F739u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F73Au,&got,stop)) return -1;
        if(got!=0x89u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F73Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F73Bu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F73Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040FB9E3u:
        if(!js_v06c_read8(m,0x81F73Cu,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F73Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F73Du,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F73Du;stop->value=got;}return -1;}
        return 1;
    case 0x040FB9F3u:
        if(!js_v06c_read8(m,0x81F73Eu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F73Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F73Fu,&got,stop)) return -1;
        if(got!=0xF8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F73Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F740u,&got,stop)) return -1;
        if(got!=0x9Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F740u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBA0Bu:
        if(!js_v06c_read8(m,0x81F741u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F741u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F742u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F742u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBA1Bu:
        if(!js_v06c_read8(m,0x81F743u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F743u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F744u,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F744u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F745u,&got,stop)) return -1;
        if(got!=0x9Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F745u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBA33u:
        if(!js_v06c_read8(m,0x81F746u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F746u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F747u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F747u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F748u,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F748u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBA4Bu:
        if(!js_v06c_read8(m,0x81F749u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F749u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F74Au,&got,stop)) return -1;
        if(got!=0x0Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F74Au;stop->value=got;}return -1;}
        return 1;
    case 0x040FBA5Bu:
        if(!js_v06c_read8(m,0x81F74Bu,&got,stop)) return -1;
        if(got!=0x3Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F74Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040FBA63u:
        if(!js_v06c_read8(m,0x81F74Cu,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F74Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F74Du,&got,stop)) return -1;
        if(got!=0x05u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F74Du;stop->value=got;}return -1;}
        return 1;
    case 0x040FBA73u:
        if(!js_v06c_read8(m,0x81F74Eu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F74Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F74Fu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F74Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F750u,&got,stop)) return -1;
        if(got!=0xF8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F750u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBA8Bu:
        if(!js_v06c_read8(m,0x81F751u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F751u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F752u,&got,stop)) return -1;
        if(got!=0x05u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F752u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBA9Bu:
        if(!js_v06c_read8(m,0x81F753u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F753u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F754u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F754u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBAABu:
        if(!js_v06c_read8(m,0x81F755u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F755u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F756u,&got,stop)) return -1;
        if(got!=0x36u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F756u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F757u,&got,stop)) return -1;
        if(got!=0xF8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F757u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBAC3u:
        if(!js_v06c_read8(m,0x81F758u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F758u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F759u,&got,stop)) return -1;
        if(got!=0x8Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F759u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F75Au,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F75Au;stop->value=got;}return -1;}
        return 1;
    case 0x040FBADBu:
        if(!js_v06c_read8(m,0x81F75Bu,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F75Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F75Cu,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F75Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F75Du,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F75Du;stop->value=got;}return -1;}
        return 1;
    case 0x040FBAF3u:
        if(!js_v06c_read8(m,0x81F75Eu,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F75Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F75Fu,&got,stop)) return -1;
        if(got!=0xFBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F75Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040FBB03u:
        if(!js_v06c_read8(m,0x81F760u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F760u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F761u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F761u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBB10u:
        if(!js_v06c_read8(m,0x81F762u,&got,stop)) return -1;
        if(got!=0xCEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F762u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F763u,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F763u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F764u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F764u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBB28u:
        if(!js_v06c_read8(m,0x81F765u,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F765u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F766u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F766u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBB3Bu:
        if(!js_v06c_read8(m,0x81F767u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F767u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F768u,&got,stop)) return -1;
        if(got!=0x12u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F768u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBB4Bu:
        if(!js_v06c_read8(m,0x81F769u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F769u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F76Au,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F76Au;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F76Bu,&got,stop)) return -1;
        if(got!=0x9Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F76Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040FBB63u:
        if(!js_v06c_read8(m,0x81F76Cu,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F76Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F76Du,&got,stop)) return -1;
        if(got!=0x89u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F76Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F76Eu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F76Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040FBB7Bu:
        if(!js_v06c_read8(m,0x81F76Fu,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F76Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F770u,&got,stop)) return -1;
        if(got!=0xCBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F770u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBB8Bu:
        if(!js_v06c_read8(m,0x81F771u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F771u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F772u,&got,stop)) return -1;
        if(got!=0x3Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F772u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F773u,&got,stop)) return -1;
        if(got!=0xFBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F773u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F774u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F774u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBBABu:
        if(!js_v06c_read8(m,0x81F775u,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F775u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F776u,&got,stop)) return -1;
        if(got!=0x82u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F776u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F777u,&got,stop)) return -1;
        if(got!=0xF9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F777u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F778u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F778u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBBCBu:
        if(!js_v06c_read8(m,0x81F779u,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F779u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBBD3u:
        if(!js_v06c_read8(m,0x81F77Au,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F77Au;stop->value=got;}return -1;}
        return 1;
    case 0x040FBBDBu:
        if(!js_v06c_read8(m,0x81F77Bu,&got,stop)) return -1;
        if(got!=0x38u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F77Bu;stop->value=got;}return -1;}
        return 1;
    case 0x040FBBE3u:
        if(!js_v06c_read8(m,0x81F77Cu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F77Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040FBC33u:
        if(!js_v06c_read8(m,0x81F786u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F786u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F787u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F787u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBC43u:
        if(!js_v06c_read8(m,0x81F788u,&got,stop)) return -1;
        if(got!=0xBDu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F788u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F789u,&got,stop)) return -1;
        if(got!=0xEEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F789u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F78Au,&got,stop)) return -1;
        if(got!=0xF7u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F78Au;stop->value=got;}return -1;}
        return 1;
    case 0x040FBC5Bu:
        if(!js_v06c_read8(m,0x81F78Bu,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F78Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F78Cu,&got,stop)) return -1;
        if(got!=0xFAu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F78Cu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F78Du,&got,stop)) return -1;
        if(got!=0x14u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F78Du;stop->value=got;}return -1;}
        return 1;
    case 0x040FBC73u:
        if(!js_v06c_read8(m,0x81F78Eu,&got,stop)) return -1;
        if(got!=0xE8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F78Eu;stop->value=got;}return -1;}
        return 1;
    case 0x040FBC7Bu:
        if(!js_v06c_read8(m,0x81F78Fu,&got,stop)) return -1;
        if(got!=0xE0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F78Fu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F790u,&got,stop)) return -1;
        if(got!=0x09u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F790u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBC8Bu:
        if(!js_v06c_read8(m,0x81F791u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F791u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F792u,&got,stop)) return -1;
        if(got!=0xF5u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F792u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBC9Bu:
        if(!js_v06c_read8(m,0x81F793u,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F793u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F794u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F794u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBCA8u:
        if(!js_v06c_read8(m,0x81F795u,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F795u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F796u,&got,stop)) return -1;
        if(got!=0x84u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F796u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F797u,&got,stop)) return -1;
        if(got!=0x03u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F797u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBCC0u:
        if(!js_v06c_read8(m,0x81F798u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F798u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F799u,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F799u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F79Au,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F79Au;stop->value=got;}return -1;}
        return 1;
    case 0x040FBCD8u:
        if(!js_v06c_read8(m,0x81F79Bu,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F79Bu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F79Cu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F79Cu;stop->value=got;}return -1;}
        return 1;
    case 0x040FBCEBu:
        if(!js_v06c_read8(m,0x81F79Du,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F79Du;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F79Eu,&got,stop)) return -1;
        if(got!=0xB8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F79Eu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F79Fu,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F79Fu;stop->value=got;}return -1;}
        return 1;
    case 0x040FBD03u:
        if(!js_v06c_read8(m,0x81F7A0u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7A0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7A1u,&got,stop)) return -1;
        if(got!=0xB6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7A1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7A2u,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7A2u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBD1Bu:
        if(!js_v06c_read8(m,0x81F7A3u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7A3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7A4u,&got,stop)) return -1;
        if(got!=0x89u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7A4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7A5u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7A5u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBD33u:
        if(!js_v06c_read8(m,0x81F7A6u,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7A6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7A7u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7A7u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBD43u:
        if(!js_v06c_read8(m,0x81F7A8u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7A8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7A9u,&got,stop)) return -1;
        if(got!=0xF8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7A9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7AAu,&got,stop)) return -1;
        if(got!=0x9Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7AAu;stop->value=got;}return -1;}
        return 1;
    case 0x040FBD5Bu:
        if(!js_v06c_read8(m,0x81F7ABu,&got,stop)) return -1;
        if(got!=0xA2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7ABu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7ACu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7ACu;stop->value=got;}return -1;}
        return 1;
    case 0x040FBD6Bu:
        if(!js_v06c_read8(m,0x81F7ADu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7ADu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7AEu,&got,stop)) return -1;
        if(got!=0xE6u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7AEu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7AFu,&got,stop)) return -1;
        if(got!=0x9Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7AFu;stop->value=got;}return -1;}
        return 1;
    case 0x040FBD83u:
        if(!js_v06c_read8(m,0x81F7B0u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7B0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7B1u,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7B1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7B2u,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7B2u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBD9Bu:
        if(!js_v06c_read8(m,0x81F7B3u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7B3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7B4u,&got,stop)) return -1;
        if(got!=0x0Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7B4u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBDABu:
        if(!js_v06c_read8(m,0x81F7B5u,&got,stop)) return -1;
        if(got!=0x3Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7B5u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBDB3u:
        if(!js_v06c_read8(m,0x81F7B6u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7B6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7B7u,&got,stop)) return -1;
        if(got!=0x05u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7B7u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBDC3u:
        if(!js_v06c_read8(m,0x81F7B8u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7B8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7B9u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7B9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7BAu,&got,stop)) return -1;
        if(got!=0xF8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7BAu;stop->value=got;}return -1;}
        return 1;
    case 0x040FBDDBu:
        if(!js_v06c_read8(m,0x81F7BBu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7BBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7BCu,&got,stop)) return -1;
        if(got!=0x05u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7BCu;stop->value=got;}return -1;}
        return 1;
    case 0x040FBDEBu:
        if(!js_v06c_read8(m,0x81F7BDu,&got,stop)) return -1;
        if(got!=0xA9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7BDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7BEu,&got,stop)) return -1;
        if(got!=0x01u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7BEu;stop->value=got;}return -1;}
        return 1;
    case 0x040FBDFBu:
        if(!js_v06c_read8(m,0x81F7BFu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7BFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7C0u,&got,stop)) return -1;
        if(got!=0x36u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7C0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7C1u,&got,stop)) return -1;
        if(got!=0xF8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7C1u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBE13u:
        if(!js_v06c_read8(m,0x81F7C2u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7C2u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7C3u,&got,stop)) return -1;
        if(got!=0x8Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7C3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7C4u,&got,stop)) return -1;
        if(got!=0x9Cu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7C4u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBE2Bu:
        if(!js_v06c_read8(m,0x81F7C5u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7C5u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7C6u,&got,stop)) return -1;
        if(got!=0x40u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7C6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7C7u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7C7u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBE43u:
        if(!js_v06c_read8(m,0x81F7C8u,&got,stop)) return -1;
        if(got!=0xD0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7C8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7C9u,&got,stop)) return -1;
        if(got!=0xFBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7C9u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBE53u:
        if(!js_v06c_read8(m,0x81F7CAu,&got,stop)) return -1;
        if(got!=0xC2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7CAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7CBu,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7CBu;stop->value=got;}return -1;}
        return 1;
    case 0x040FBE60u:
        if(!js_v06c_read8(m,0x81F7CCu,&got,stop)) return -1;
        if(got!=0xCEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7CCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7CDu,&got,stop)) return -1;
        if(got!=0xC0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7CDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7CEu,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7CEu;stop->value=got;}return -1;}
        return 1;
    case 0x040FBE78u:
        if(!js_v06c_read8(m,0x81F7CFu,&got,stop)) return -1;
        if(got!=0xE2u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7CFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7D0u,&got,stop)) return -1;
        if(got!=0x30u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7D0u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBE8Bu:
        if(!js_v06c_read8(m,0x81F7D1u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7D1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7D2u,&got,stop)) return -1;
        if(got!=0x19u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7D2u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBE9Bu:
        if(!js_v06c_read8(m,0x81F7D3u,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7D3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7D4u,&got,stop)) return -1;
        if(got!=0x9Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7D4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7D5u,&got,stop)) return -1;
        if(got!=0x9Fu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7D5u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBEB3u:
        if(!js_v06c_read8(m,0x81F7D6u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7D6u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7D7u,&got,stop)) return -1;
        if(got!=0x89u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7D7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7D8u,&got,stop)) return -1;
        if(got!=0x02u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7D8u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBECBu:
        if(!js_v06c_read8(m,0x81F7D9u,&got,stop)) return -1;
        if(got!=0xF0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7D9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7DAu,&got,stop)) return -1;
        if(got!=0xCBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7DAu;stop->value=got;}return -1;}
        return 1;
    case 0x040FBEDBu:
        if(!js_v06c_read8(m,0x81F7DBu,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7DBu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7DCu,&got,stop)) return -1;
        if(got!=0x3Eu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7DCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7DDu,&got,stop)) return -1;
        if(got!=0xFBu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7DDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7DEu,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7DEu;stop->value=got;}return -1;}
        return 1;
    case 0x040FBEFBu:
        if(!js_v06c_read8(m,0x81F7DFu,&got,stop)) return -1;
        if(got!=0x22u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7DFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7E0u,&got,stop)) return -1;
        if(got!=0x82u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7E0u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7E1u,&got,stop)) return -1;
        if(got!=0xF9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7E1u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7E2u,&got,stop)) return -1;
        if(got!=0x80u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7E2u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBF1Bu:
        if(!js_v06c_read8(m,0x81F7E3u,&got,stop)) return -1;
        if(got!=0xADu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7E3u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7E4u,&got,stop)) return -1;
        if(got!=0xB8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7E4u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7E5u,&got,stop)) return -1;
        if(got!=0x13u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7E5u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBF33u:
        if(!js_v06c_read8(m,0x81F7E6u,&got,stop)) return -1;
        if(got!=0x1Au){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7E6u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBF3Bu:
        if(!js_v06c_read8(m,0x81F7E7u,&got,stop)) return -1;
        if(got!=0x8Du){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7E7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7E8u,&got,stop)) return -1;
        if(got!=0xFFu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7E8u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7E9u,&got,stop)) return -1;
        if(got!=0x0Bu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7E9u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBF53u:
        if(!js_v06c_read8(m,0x81F7EAu,&got,stop)) return -1;
        if(got!=0x18u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7EAu;stop->value=got;}return -1;}
        return 1;
    case 0x040FBF5Bu:
        if(!js_v06c_read8(m,0x81F7EBu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7EBu;stop->value=got;}return -1;}
        return 1;
    case 0x040FBF63u:
        if(!js_v06c_read8(m,0x81F7ECu,&got,stop)) return -1;
        if(got!=0x38u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7ECu;stop->value=got;}return -1;}
        return 1;
    case 0x040FBF6Bu:
        if(!js_v06c_read8(m,0x81F7EDu,&got,stop)) return -1;
        if(got!=0x60u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7EDu;stop->value=got;}return -1;}
        return 1;
    case 0x040FBFBBu:
        if(!js_v06c_read8(m,0x81F7F7u,&got,stop)) return -1;
        if(got!=0xA0u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7F7u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7F8u,&got,stop)) return -1;
        if(got!=0x00u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7F8u;stop->value=got;}return -1;}
        return 1;
    case 0x040FBFCBu:
        if(!js_v06c_read8(m,0x81F7F9u,&got,stop)) return -1;
        if(got!=0xBEu){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7F9u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7FAu,&got,stop)) return -1;
        if(got!=0x85u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7FAu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7FBu,&got,stop)) return -1;
        if(got!=0xF8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7FBu;stop->value=got;}return -1;}
        return 1;
    case 0x040FBFE3u:
        if(!js_v06c_read8(m,0x81F7FCu,&got,stop)) return -1;
        if(got!=0xB9u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7FCu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7FDu,&got,stop)) return -1;
        if(got!=0x96u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7FDu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F7FEu,&got,stop)) return -1;
        if(got!=0xF8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7FEu;stop->value=got;}return -1;}
        return 1;
    case 0x040FBFFBu:
        if(!js_v06c_read8(m,0x81F7FFu,&got,stop)) return -1;
        if(got!=0x20u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F7FFu;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F800u,&got,stop)) return -1;
        if(got!=0x08u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F800u;stop->value=got;}return -1;}
        if(!js_v06c_read8(m,0x81F801u,&got,stop)) return -1;
        if(got!=0xF8u){if(stop){stop->reason=JSV06_STOP_STATIC_CODE_MISMATCH;stop->address=0x81F801u;stop->value=got;}return -1;}
        return 1;
    default: return 0;
    }
}
