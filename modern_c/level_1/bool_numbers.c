#include <stdio.h>
int main() {
	int num = 2;
	int num2 = 20;
	int num3 = 0;
	
	// after `!!` num becomes 1(true)
	printf("%d\n", !!num); // this prints 1
	printf("%d\n", !!num2); // this prints 1
	printf("%d\n", !!num3); // this prints 0
}
