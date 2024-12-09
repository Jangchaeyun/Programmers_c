#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int arr[100][100];

int minNumber(int top, int bottom, int left, int right) {
	int point = arr[top][left];
	int min = point;

	for (int i = top + 1; i <= bottom; i++) {
		arr[i - 1][left] = arr[i][left];
		if (min > arr[i][left]) min = arr[i][left];
	}

	for (int i = left + 1; i <= right; i++) {
		arr[bottom][i - 1] = arr[bottom][i];
		if (min > arr[bottom][i]) min = arr[bottom][i];
	}

	for (int i = bottom - 1; i >= top; i--) {
		arr[i + 1][right] = arr[i][right];
		if (min > arr[i][right]) min = arr[i][right];
 	}

	for (int i = right - 1; i >= left; i--) {
		arr[top][i + 1] = arr[top][i];
		if (min > arr[top][i]) min = arr[top][i];
	}

	arr[top][left + 1] = point;
	return min;
}

int* solution(int rows, int columns, int** queries, size_t queries_row_len, size_t queries_col_len) {
	int* answer = (int*)malloc(queries_row_len * sizeof(int));

	int n = 1;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			arr[i][j] = n++;
		}
	}

	for (int i = 0; i < queries_row_len; i++) {
		answer[i] = minNumber(queries[i][0] - 1, queries[i][2] - 1, queries[i][1] - 1, queries[i][3] - 1);
	}
	return answer;
}