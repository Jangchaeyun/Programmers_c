#include <stdio.h>
#include <stdlib.h>

int* solution(int num_list[], size_t num_list_len, int n) {
	size_t result_len = num_list_len - (n - 1);
	int* answer = (int*)malloc(result_len * sizeof(int));

	for (size_t i = 0; i < result_len; i++) {
		answer[i] = num_list[n - 1 + i];
	}

	return answer;
}