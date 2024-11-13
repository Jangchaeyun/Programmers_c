#include <stdio.h>
#include <stdlib.h>

int* solution(int arr[], size_t arr_len) {
	size_t totalSize = 0;

	for (size_t i = 0; i < arr_len; ++i) {
		totalSize += arr[i];
	}

	int* answer = (int*)malloc(totalSize * sizeof(int));
	if (answer == NULL) {
		return NULL;
	}

	size_t idx = 0;
	for (size_t i = 0; i < arr_len; ++i) {
		for (int j = 0; j < arr[i]; ++j) {
			answer[idx++] = arr[i];
		}
	}
	return answer;
}