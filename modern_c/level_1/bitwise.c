#include <stdio.h>
int main() {
    unsigned A = 240;
    unsigned B = 287;

    printf("A\\B = A - (A&B): %s\n",
           (A & ~B) == (A - (A & B)) ? "true" : "false");

    return 0;
}
