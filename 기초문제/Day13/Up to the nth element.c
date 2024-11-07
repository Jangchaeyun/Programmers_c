#include <stdio.h>
#include <stdlib.h>

int* solution(int num_list[], size_t num_list_len, int n) {
	int* answer = (int*)malloc(n * sizeof(int));
	if (answer == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		return NULL;
	}

	for (int i = 0; i < n; i++) {
		answer[i] = num_list[i];
	}

	return answer;
}