#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int numbers[], size_t numbers_len, int k) {
	int answer = 0;
	for (int i = 1; i < k; i++) {
		answer += 2;
		if (answer >= numbers_len) {
			answer -= numbers_len;
		}
	}
	return numbers[answer];
}