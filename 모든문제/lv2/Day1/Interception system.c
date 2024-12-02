#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void* a, const void* b) {
	int* A = *(int**)a;
	int* B = *(int**)b;

	if (A[1] == B[1]) {
		return A[0] - B[0];
	}
	return A[1] - B[1];
}

int solution(int** targets, size_t targets_rows, size_t targets_cols) {
	if (targets_rows == 0) return 0;

	qsort(targets, targets_rows, sizeof(int*), compare);
	
	int answer = 1;
	int end = targets[0][1];

	for (size_t i = 1; i < targets_rows; i++) {
		if (end <= targets[i][0]) {
			end = targets[i][1];
			answer++;
		}
	}
	return answer;
}