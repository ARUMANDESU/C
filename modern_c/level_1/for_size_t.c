#include <stddef.h>
#include <stdio.h>

int main() {
	size_t i;
	for (i = 9; i <= 9; --i) {
		printf("for: i: %zu\n", i);
	}
	printf("after for: i: %zu\n", i); // after for: i: 18446744073709551615
	return 0;
}
