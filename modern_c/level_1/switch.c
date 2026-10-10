#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[argc + 1]) {
	if (argc < 2) {
		printf("input some integers: %s <int>...\n", argv[0]);
		return 0;
	}
    for (int i = 1; i < argc; i++) {
		char *end;
		long input = strtol(argv[i], &end, 10);

		if (end == argv[i]) {
			fprintf(stderr, "not a number: %s\n", argv[i]);
			return 1;
		}
		if (*end != '\0') {
			fprintf(stderr, "trailing garbage: %s\n", end);
			return 1;
		}

        switch (input) {
        case 1: // prints lol\nkek\n
            printf("lol\n");
		case 2: // prints kek\n
            printf("kek\n");
			break;
		case 3: // prints lol kek\n
			printf("lol kek\n");
			break;
		case 4: // prints lel\ndefault\n
			printf("lel\n");
        default: // yep prints default\n
            printf("default\n");
        }
    }

    return 0;
}
