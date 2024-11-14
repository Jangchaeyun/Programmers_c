#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int arr[], size_t arr_len, int n) {
	int* answer = (int*)malloc(arr_len * sizeof(int));
	for (int i = 0; i < arr_len; i++)
		answer[i] = arr[i];
	if (arr_len % 2 != 0)
		for (int i = 0; i <= arr_len / 2; i++)
			answer[i * 2] = arr[i * 2] + n;
	else
		for (int i = 0; i < arr_len / 2; i++)
			answer[i * 2 + 1] = arr[i * 2 + 1] + n;
	return answer;
}