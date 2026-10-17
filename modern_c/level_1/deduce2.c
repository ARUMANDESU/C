#include <stdint.h>
#include <stdio.h>

int main(void) {
    unsigned long modulus = 1ul << 16;

    // simulate 16-bit unsigned negation by hand
    unsigned long neg = (modulus - 0x8000) % modulus;

    // or let a real 16-bit unsigned type do the wrapping
    uint16_t y = -0x8000;

    printf("max 16-bit unsigned: %lu\n", modulus - 1);
    printf("by hand:  %lu\n", neg);
    printf("uint16_t: %u\n", (unsigned)y);
    return 0;
}
