#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int check[200] = { 0 };

int solution(int** lines, size_t lines_rows, size_t lines_cols) {
	int answer = 0;
	for (size_t i = 0; i < lines_rows; ++i) {
		for (int j = lines[i][0]; j < lines[i][1]; ++j) {
			check[j + 100]++;
		}
	}

	for (int i = 0; i < 200; ++i) {
		if (check[i] > 1) {
			answer++;
		}
	}
	return answer;
}