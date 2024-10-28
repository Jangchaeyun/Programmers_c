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

int concatenate2(int a, int b) {
	return (2 * a * b);
}

int solution(int a, int b) {
	int ab = concatenate(a, b);
	int ab2 = concatenate2(a, b);

	return getMax(ab, ab2);
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	int result = solution(a, b);
	
	printf("%d", result);

	return 0;
}