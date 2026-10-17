#include <limits.h>
#include <stdio.h>

int main() {

    unsigned x = 1u << 16;
    unsigned y = -0x8000;

    printf("UINT_MAX: %u\nx: %u\ny: %u\n", UINT_MAX, x, y);

    return 0;
}
