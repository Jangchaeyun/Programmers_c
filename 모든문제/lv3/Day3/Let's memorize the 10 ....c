#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* solution(int e, int starts[], size_t starts_len) {
	int* countArray = (int*)calloc(e + 1, sizeof(int));
	int* dp = (int*)malloc((e + 1) * sizeof(int));
	int* answer = (int*)malloc(starts_len * sizeof(int));

	for (int i = 1; i <= e; i++) {
		for (int j = 1; j * i <= e; j++) {
			countArray[i * j]++;
		}
	}

	int maxCount = -1;
	int index = -1;
	for (int i = e; i >= 0; i--) {
		if (countArray[i] >= maxCount) {
			maxCount = countArray[i];
			index = i;
		}
		dp[i] = index;
	}

	for (size_t i = 0; i < starts_len; i++) {
		answer[i] = dp[starts[i]];
	}

	free(countArray);
	free(dp);

	return answer;
}