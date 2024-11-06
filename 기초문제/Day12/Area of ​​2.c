#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int arr[], size_t arr_len) {
	int* answer = (int*)malloc(arr_len * sizeof(int));
	int start, end;
	start = -1;
	int i, j;
	for (int i = 0; i < arr_len; i++)
		if (arr[i] == 2) {
			start = i;
			break;
		}
	for (int j = arr_len - 1; j >= 0; j--)
		if (arr[j] == 2) {
			end = j;
			break;
		}
	printf("%d %d", start, end);
	for (i = start; i <= end; i++)
		answer[i - start] = arr[i];

	if (start == -1)
		*answer = -1;
	return answer;
}