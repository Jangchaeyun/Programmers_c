#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int* solution(int arr[], size_t arr_len, bool flag[], size_t flag_len) {
	int* answer = (int*)malloc(100 * 100 * sizeof(int));
	int n = 0;
	for (int i = 0; i < arr_len; i++) {
		if (flag[i])
		{
			for (int j = 0; j < arr[i] * 2; j++)
				answer[n++] = arr[i];
		}
		else {
			for (int j = 0; j < arr[i]; j++) {
				n--;
			}
		}
	}
	return answer;
}