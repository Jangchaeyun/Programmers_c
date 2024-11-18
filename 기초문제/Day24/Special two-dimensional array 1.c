#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int** solution(int n) {
	int** answer = (int**)malloc(n * n * sizeof(int));
	for (int i = 0; i < n; i++)
		answer[i] = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j)
				answer[i][j] = 1;
			else
				answer[i][j] = 0;
		}
	return answer;
}