#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int arr[], size_t arr_len, int k) {
	int* answer = (int*)malloc(sizeof(int) * arr_len);
	for (int i = 0; i < arr_len; i++) {
		if (k % 2) answer[i] = arr[i] * k;
		else answer[i] = arr[i] + k;
	}
	return answer;
}