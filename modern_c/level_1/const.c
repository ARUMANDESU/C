#include <stdio.h>
int main() {

    // this is const-qualified object and it can be changed
    const int limit = 10;

    int *p = (int *)&limit;
    *p = 20;

    printf("%d\n", limit);
    // The compiler may have put limit in read-only memory, so the write crashes
    // the program. The compiler may have replaced every use of limit with the
    // number 10, so the write seems to do nothing. It may also appear to work,
    // until a different compiler or optimization level makes it fail.
	//
	//
	// just I should remember that const means “I may not modify this through this name”. It doesn’t mean “this value never changes”.e:w

    return 0;
}
