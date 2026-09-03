#ifndef ROCKNROLL_V08C_DMA_TABLES_H
#define ROCKNROLL_V08C_DMA_TABLES_H
#include <stdint.h>
static const uint8_t JS_V08C_DMA_TRANSFER_COUNT[8]={1,2,2,4,4,4,2,4};
static const uint8_t JS_V08C_DMA_TRANSFER_OFFSET[8][4]={{0,0,0,0},{0,1,0,1},{0,0,0,0},{0,0,1,1},{0,1,2,3},{0,1,0,1},{0,0,0,0},{0,0,1,1}};
#endif
