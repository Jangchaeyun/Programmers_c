#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int numbers[], size_t numbers_len) {
	int answer = 0;
	for (int i = 0; i < numbers_len; i++)
		for (int j = i + 1; j < numbers_len; j++)
			if (numbers[i] * numbers[j] > answer)
				answer = numbers[i] * numbers[j];
	return answer;
}