#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int arr[], size_t arr_len, int** intervals, size_t intervals_rows, size_t intervals_cols) {
	int* answer = (int*)malloc(arr_len * sizeof(int));
	int n = 0;
	for (int i = intervals[0][0]; i <= intervals[0][1]; i++)
		answer[n++] = arr[i];
	for (int j = intervals[1][0]; j <= intervals[1][1]; j++)
		answer[n++] = arr[j];
	answer[n] = '\0';
	return answer;
}