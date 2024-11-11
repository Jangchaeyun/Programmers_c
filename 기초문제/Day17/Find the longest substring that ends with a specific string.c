#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* myString, const char* pat) {
	char* answer = (char*)malloc(strlen(myString));
	int i, j;
	for (i = strlen(myString) - 1; i >= 0; i--) {
		if (strncmp(myString + i, pat, strlen(pat)) == 0)
			break;
	}

	for (j = 0; j < (i + strlen(pat)); j++) {
		answer[j] = myString[j];
	}
	answer[j++] = '\0';
	return answer;
}