#include <stdio.h>
#include <stdlib.h>

int** solution(int n) {
	int** answer = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		answer[i] = (int*)malloc(n * sizeof(int));
	}

	int num = 1;
	int row_idx = 0, col_idx = 0;
	int len = n - 1;

	while (num <= n * n) {
		if (row_idx == (n - 1) / 2 && col_idx == n / 2) {
			answer[row_idx][col_idx] = num++;
		}

		for (int i = 0; i < len; ++i) {
			answer[row_idx][col_idx++] = num++;
		}

		for (int i = 0; i < len; ++i) {
			answer[row_idx++][col_idx] = num++;
		}
		
		for (int i = 0; i < len; ++i) {
			answer[row_idx][col_idx--] = num++;
		}
		
		for (int i = 0; i < len; ++i) {
			answer[row_idx--][col_idx] = num++;
		}

		len -= 2;
		row_idx++;
		col_idx++;
	}
	return answer;
}