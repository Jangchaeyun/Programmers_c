#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n, long long left, long long right)
{
	int* answer = (int*)malloc(sizeof(int) * (right - left + 1));

	for (long long i = left; i <= right; i++)
	{
		if (i % n > i / n) {
			answer[i - left] = i % n + 1;
		}
		else {
			answer[i - left] = i / n + 1;
		}
	}
	return answer;
}