#include <stdio.h>

int main(void) {
	int a;
	int b;
	scanf("%d %d", &a, &b);
	if ((-100000 > a) || (100000 < a)) {
		printf("value a is out of range. %d", a);
		return -1;
	}
	if ((-100000 > b) || (100000 < b)) {
		printf("value a is out of range. %d", b);
		return -1;
	}
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	return 0;
}