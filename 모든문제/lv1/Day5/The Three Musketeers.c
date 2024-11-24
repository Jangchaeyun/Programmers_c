#include <stdio.h>

int solution(int number[], size_t number_len) {
	int answer = 0;

	for (int i = 0; i < number_len; i++) {
		for (int j = i + 1; j < number_len; j++) {
			for (int k = j + 1; k < number_len; k++) {
				if (-1 * (number[i] + number[j]) == number[k]) {
					answer += 1;
				}
			}
		}
	}
	return answer;
}