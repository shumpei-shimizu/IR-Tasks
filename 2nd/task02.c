#include <stdio.h>

int main(void) {
	int i;
	int sum = 0;
	for (i = 1; i <= 100; i++) {
		sum += i*i;
	}
	printf("%d\n", sum);
	return 0;
}

