#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n) {
	int* answer = (int*)malloc(n * sizeof(int));
	int j = 0;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
			answer[j++] = i;
	}
	return answer;
}