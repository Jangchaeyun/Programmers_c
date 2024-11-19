#include <stdio.h>
#include <stdlib.h>

int** solution(int** arr, size_t arr_rows, size_t arr_cols) {
	size_t new_size = arr_rows > arr_cols ? arr_rows : arr_cols;

	int** answer = (int**)malloc(new_size * sizeof(int*));
	for (size_t i = 0; i < new_size; ++i) {
		answer[i] = (int*)malloc(new_size * sizeof(int));

		for (size_t j = 0; j < new_size; ++j) {
			if (i < arr_rows && j < arr_cols) {
				answer[i][j] = arr[i][j];
			}
			else {
				answer[i][j] = 0;
			}
		}
	}

	return answer;
}