#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long* solution(long long numbers[], size_t numbers_len) {
	long long* answer = (long long*)malloc(numbers_len * sizeof(long long));
	if (answer == NULL) {
		return NULL;
	}

	for (size_t i = 0; i < numbers_len; i++) {
		if (numbers[i] % 2 == 0) {
			answer[i] = numbers[i] + 1;
		}
		else {
			long long bit = 2;
			while (true) {
				if ((numbers[i] & bit) == 0) {
					break;
				}
				bit *= 2;
			}
			bit = bit / 2;
			answer[i] = numbers[i] + bit;
		}
	}
	
	return answer;
}