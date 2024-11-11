#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(const char* myString, const char* pat) {
	int answer = 0;
	for (int i = strlen(myString) - 1; i >= 0; i--)
		if (strncmp(myString + i, pat, strlen(pat)) == 0)
			answer++;
	return answer;
}