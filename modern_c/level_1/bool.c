#include <stdio.h>

int main() {
	// before c23 in order to use bool, true, and false we should include stdbool.h
	// and if you want your code to be compiled in older platforms then you should include stdbool.h
	bool is_true = true;
	if (is_true) {
		printf("lol kek\n");
	}

	return 0;
}
