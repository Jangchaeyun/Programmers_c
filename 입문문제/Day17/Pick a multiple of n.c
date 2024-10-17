#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n, int numlist[], size_t numlist_len) {
	int* answer = (int*)malloc(numlist_len);
	int x = 0;
	for (int i = 0; i < numlist_len; i++)
	{
		if ((numlist[i] % n) == 0)
		{
			answer[x++] = numlist[i];
		}
	}
	return answer;
}