#include <stdio.h>
int main() {

    double a = 0.2;
    float b = 0.2F;
    float c = 0.2L;

    printf("0.2 literal equal to: %.40f\n", a);
    printf("0.2F literal equal to: %.40f\n", b);
    printf("0.2L literal equal to: %.40f\n", c);

    printf("0.2F == 0x1.9999’9AP-3: %s\n", 0.2F == 0x1.99999AP-3 ? "true" : "false");
    printf("0.2L == 0xC.CCCC’CCCC’CCCC’CCDP-6: %s\n",
           0.2L == 0xC.CCCCCCCCCCCCCCDP-6 ? "true" : "false");

    return 0;
}
