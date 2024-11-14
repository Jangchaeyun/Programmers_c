#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(const char* strArr[], size_t strArr_len) {
	int lengthCounts[1001] = { 0 };
	int maxCount = 0;

	for (size_t i = 0; i < strArr_len; i++) {
		int length = strlen(strArr[i]);
		lengthCounts[length]++;
	}

	for (size_t i = 0; i < 1001; i++) {
		if (lengthCounts[i] > maxCount) {
			maxCount = lengthCounts[i];
		}
	}
	return maxCount;
}