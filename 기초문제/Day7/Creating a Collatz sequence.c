#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n) {
	int* answer = (int*)malloc(n * sizeof(int));
	int i = 0;
	while (1) {
		answer[i++] = n;
		if (n % 2 == 0)
			n /= 2;
		else
			n = 3 * n + 1;
		if (n == 1) {
			answer[i] = n;
			break;
		}
	}
	return answer;
}