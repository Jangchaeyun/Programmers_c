#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(const char* before, const char* after) {
	int answer = 1;
	int* alp[25] = { 0, };
	int* alp2[25] = { 0, };
	for (int i = 0; i < strlen(before); i++)
		alp[before[i] - 97]++;
	for (int i = 0; i < strlen(after); i++)
		alp2[after[i] - 97]++;
	for (int i = 0; i < 25; i++)
		if (alp[i] != alp2[i])
			return 0;
	return answer;
}