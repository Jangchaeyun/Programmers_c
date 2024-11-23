#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int food[], size_t food_len) {
	int cnt = 0;
	for (int i = 1; i < food_len; i++) {
		food[i] /= 2;
		if (food[i] > 0) {
			cnt += (food[i] * 2);
		}
	}
	char* answer = (char*)malloc(sizeof(char) * (cnt + 2));

	int k = 0;
	for (int i = 1; i < food_len; i++) {
		if (food[i] != 0) {
			for (int j = 0; j < food[i]; j++) {
				answer[k] = i + '0';
				k++;
			}
		}
	}
	answer[k++] = '0';
	for (int i = food_len - 1; i >= 1; i--) {
		if (food[i] != 0) {
			for (int j = 0; j < food[i]; j++) {
				answer[k] = i + '0';
				k++;
			}
		}
	}
	answer[k] = '\0';
	return answer;
}