#include <stdio.h>

typedef struct {
	int key;
	char *str;
} my_class_t;

int main(void) {
	my_class_t my_object;
	my_object.key = 101;
	my_object.str = "C gengo tte kaki nikui yone w";

	printf("%d\n", my_object.key);
	printf("%s\n", my_object.str);

	my_class_t construct = {102, "Constructer wo tukau kannji nimo dekiru yo w"};

	printf("%d\n", construct.key);
	printf("%s\n", construct.str);

	return 0;
}


