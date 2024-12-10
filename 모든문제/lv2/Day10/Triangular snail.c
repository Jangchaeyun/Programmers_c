#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n) {
	int* answer = (int*)calloc(n * (n + 1) / 2, sizeof(int));
	int tmp[n][n];
	int num = 1;
	int row, col;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tmp[i][j] = 0;

	row = -1;
	col = 0;
	for (int i = n; i > 0; i -= 3) {
		for (int j = 0; j < i; j++) {
			tmp[++row][col] = num++;
		}
		for (int j = 0; j < i - 1; j++) {
			tmp[row][++col] = num++;
		}
		for (int j = 0; j < i - 2; j++) {
			tmp[--row][--col] = num++;
		}
	}

	int p = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			answer[p++] = tmp[i][j];
		}
	}
	return answer;
}