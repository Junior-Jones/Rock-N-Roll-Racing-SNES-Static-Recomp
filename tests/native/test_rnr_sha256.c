// ROM-free regression test for the portable SHA-256 used by the
// Linux frontend's ROM identity check (NIST FIPS 180-4 vectors).
#include "rnr_sha256.h"

#include <stdio.h>
#include <string.h>

static int check(const char *input, const char *expected_hex) {
    uint8_t digest[32];
    char hex[65];
    size_t i;
    rnr_sha256((const uint8_t *)input, strlen(input), digest);
    for (i = 0; i < 32; i++)
        sprintf(hex + i * 2, "%02x", digest[i]);
    if (strcmp(hex, expected_hex) != 0) {
        printf("FAIL input=\"%s\"\n  got      %s\n  expected %s\n",
               input, hex, expected_hex);
        return 0;
    }
    return 1;
}

int main(void) {
    int ok = 1;
    ok &= check("", "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855");
    ok &= check("abc", "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad");
    ok &= check("abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq",
               "248d6a61d20638b8e5c026930c3e6039a33ce45964ff2167f6ecedd419db06c1");
    if (ok) printf("rnr_sha256: all vectors pass\n");
    return ok ? 0 : 1;
}
