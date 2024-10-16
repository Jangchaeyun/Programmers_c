#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int array[], size_t array_len) {
	int* answer = (int*)malloc(sizeof(int) * 2);
	int i, idx, max = 0;
	for (i = 0; i < array_len; i++) {
		if (max < array[i]) {
			max = array[i];
			idx = i;
		}
	}
	answer[0] = max;
	answer[1] = idx;
	return answer;
}