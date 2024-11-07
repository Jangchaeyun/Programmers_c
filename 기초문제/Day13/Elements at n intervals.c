#include <stdio.h>
#include <stdlib.h>

int* solution(int num_list[], size_t num_list_len, int n) {
	size_t answer_len = (num_list_len % n == 0) ? (num_list_len / n) : (num_list_len / n + 1);

	int* answer = (int*)malloc(answer_len * sizeof(int));
	if (answer == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		return NULL;
	}

	size_t index = 0;
	for (size_t i = 0; i < num_list_len; i += n) {
		answer[index++] = num_list[i];
	}

	return answer;
}