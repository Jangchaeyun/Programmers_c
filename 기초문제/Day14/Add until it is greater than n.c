#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int numbers[], size_t numbers_len, int n) {
	int answer = 0;
	for (int i = 0; i < numbers_len; i++) {
		if (answer > n) return answer;
		answer += numbers[i];
	}
}