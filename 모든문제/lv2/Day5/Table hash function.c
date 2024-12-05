#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int gCol = 0;

int compare(const void* a, const void* b) {
	const int* rowA = *(const int**)a;
	const int* rowB = *(const int**)b;

	if (rowA[gCol - 1] == rowB[gCol - 1]) {
		return rowB[0] - rowA[0];
	}
	return rowA[gCol - 1] - rowB[gCol - 1];
}

int solution(int** data, size_t data_rows, size_t data_cols, int col, int row_begin, int row_end) {
	int answer = 0;
	gCol = col;

	qsort(data, data_rows, sizeof(int*), compare);

	for (int i = row_begin - 1; i < row_end; i++) {
		int temp = 0;
		for (size_t j = 0; j < data_cols; j++) {
			temp += data[i][j] % (i + 1);
		}
		answer ^= temp;
	}
	return answer;
}