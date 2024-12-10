#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int** ary;
int count[2];

void func(int left, int right, int top, int bottom) {
	int zero = 0, one = 0;
	for (int i = top; i <= bottom; i++) {
		for (int j = left; j <= right; j++) {
			if (ary[i][j]) one++;
			else zero++;
		}
	}

	if (zero == 0) count[1] = count[1] - one + 1;
	else if (one == 0) count[0] = count[0] - zero + 1;
	else {
		if (right - left == 1) return;
		int midW = left + (right - left) / 2;
		int midH = top + (bottom - top) / 2;
		func(left, midW, top, midH);
		func(left, midW, midH + 1, bottom);
		func(midW + 1, right, top, midH);
		func(midW + 1, right, midH + 1, bottom);
	}
}

int* solution(int** arr, size_t arr_rows, size_t arr_cols) {
	int* answer = (int*)malloc(sizeof(int) * 2);
	ary = arr;

	for (int i = 0; i < arr_rows; i++) {
		for (int j = 0; j < arr_cols; j++) {
			if (arr[i][j]) count[1]++;
			else count[0]++;
		}
	}

	func(0, arr_rows - 1, 0, arr_cols - 1);
	answer[0] = count[0];
	answer[1] = count[1];

	return answer;
}