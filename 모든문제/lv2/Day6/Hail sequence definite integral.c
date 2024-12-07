#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

double area[1000];
int len;

void func(int k) {
	if (k == 1) return;
	if (k % 2 == 0) {
		area[len++] = (double)(k + k / 2) / 2;
		func(k / 2);
	}
	else {
		area[len++] = (double)(k + 3 * k + 1) / 2;
		func(k * 3 + 1);
	}
}

double* solution(int k, int** ranges, size_t ranges_rows, size_t ranges_cols) {
	double* answer = (double*)malloc(sizeof(double) * ranges_rows);
	int cnt = 0;
	func(k);

	int left, right;
	double sum;
	for (int i = 0; i < ranges_rows; i++) {
		left = ranges[i][0];
		right = len + ranges[i][1];
		sum = 0.0;
		if (left > right) answer[cnt++] = -1.0;
		else {
			for (int j = left; j < right; j++) sum += area[j];
			answer[cnt++] = sum;
		}
	}
	return answer;
}