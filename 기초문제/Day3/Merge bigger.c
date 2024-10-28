#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int getMax(int a, int b) {
	return (a > b) ? a : b;
}

int concatenate(int a, int b) {
	int power = 1;
	while (power <= b)
		power *= 10;
	return (a * power) + b;
}

int solution(int a, int b) {
	int ab = concatenate(a, b);
	int ba = concatenate(b, a);

	return getMax(ab, ba);
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	int result = solution(a, b);

	printf("%d", result);

	return 0;
}