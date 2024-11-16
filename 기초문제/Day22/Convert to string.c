#include <stdio.h>
#include <stdlib.h>

char* solution(int n) {
	int length = snprintf(NULL, 0, "%d", n);
	char* answer = (char*)malloc(length + 1);
	if (answer == NULL) {
		return NULL;
	}

	sprintf(answer, "%d", n);
	return answer;
}