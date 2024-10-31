#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define INF 0x7fffffff

int* solution(int arr[], size_t arr_len, int** queries, size_t queries_rows, size_t queries_cols) {
	int* answer = (int*)malloc(queries_rows * sizeof(int));
	for (int i = 0; i < queries_rows; i++) {
		int s = queries[i][0], e = queries[i][1], k = queries[i][2];
		int min = INF;
		for (; s <= e; s++) {
			if (arr[s] <= k) continue;
			if (arr[s] < min) min = arr[s];
		}
		if (min == INF) min = -1;
		answer[i] = min;
	}
	return answer;
}