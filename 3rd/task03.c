#include <stdio.h>

int double_counter(int num) {
	if (num <= 0) return 0;
	return double_counter(num - 1) + num * num;
}

int main(void) {
	printf("%d\n", double_counter(100));
	return 0;
}

