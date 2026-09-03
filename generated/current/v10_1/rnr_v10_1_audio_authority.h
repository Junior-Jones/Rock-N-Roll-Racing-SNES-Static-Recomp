#ifndef RNR_V10_1_AUDIO_AUTHORITY_H
#define RNR_V10_1_AUDIO_AUTHORITY_H
#include <stdint.h>
#define RNR_V10_1_UPLOAD_RECORD_COUNT 4u
#define RNR_V10_1_UPLOADED_ARAM_BYTES 58368u
#define RNR_V10_1_KNOWN_ARAM_BYTES 58607u
#define RNR_V10_1_FINAL_SMP_ENTRY 0x0400u
#define RNR_V10_1_IPL_CLEAR_START 0x0001u
#define RNR_V10_1_IPL_CLEAR_END 0x00EFu
typedef struct RnrV10_1UploadAuthority { uint8_t selector; uint16_t size,destination,entry; uint32_t header_physical; } RnrV10_1UploadAuthority;
static const RnrV10_1UploadAuthority rnr_v10_1_upload_authority[4] = {
  {0u,0x0FC0u,0x0400u,0xFFC0u,0x010000u},
  {1u,0xC310u,0x3800u,0xFFC0u,0x010FC6u},
  {2u,0x0451u,0x1400u,0xFFC0u,0x01D2DCu},
  {3u,0x0CDFu,0x2000u,0x0400u,0x01D733u},
};
#endif
