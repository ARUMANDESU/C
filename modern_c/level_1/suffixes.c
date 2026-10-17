

#include <limits.h>
#include <stdio.h>
int main() {

    unsigned a = -1U;
    unsigned long b = -1UL;
    unsigned long long c = -1ULL;

    printf("Limits:\nUINT_MAX: %u\nULONG_MAX: %lu\nULLONG_MAX: %llu\n",
           UINT_MAX, ULONG_MAX, ULLONG_MAX);
    printf("a: %u\nb: %lu\nc: %llu\n", a, b, c);

    printf("-1U == UINT_MAX: %s\n", a == UINT_MAX ? "true" : "false");
    printf("-1UL == ULONG_MAX: %s\n", b == ULONG_MAX ? "true" : "false");
    printf("-1ULL == ULLONG_MAX: %s\n",
           c == ULLONG_MAX ? "true" : "false");

    return 0;
}
