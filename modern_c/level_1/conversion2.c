#include <limits.h>
#include <stdio.h>
int main() {

	printf("%u\n", -1U);
	printf("%u\n", UINT_MAX);

	printf("%d\n", -1 < 0U);

	return 0;
}
