#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(const char* intStrs[], size_t intStrs_len, int k, int s, int l) {
	int* answer = (int*)malloc(intStrs_len * sizeof(int));
	int n = 0;
	int tmp = 0;
	for (int i = 0; i < intStrs_len; i++)
	{
		for (int j = s; j < s + l; j++) {
			tmp = tmp * 10 + intStrs[i][j] - '0';
		}
		if (tmp > k)
			answer[n++] = tmp;
		tmp = 0;
	}
	return answer;
}