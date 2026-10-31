// Public-domain SHA-256 (Brad Conte style, self-contained).
// For ROM identity check only.
#ifndef RNR_SHA256_H
#define RNR_SHA256_H
#include <stddef.h>
#include <stdint.h>
void rnr_sha256(const uint8_t *data, size_t len, uint8_t out[32]);
#endif
