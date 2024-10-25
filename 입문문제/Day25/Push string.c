#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int solution(const char* A, const char* B) {
	int lenA = strlen(A);
	int lenB = strlen(B);

	char* doubleB = (char*)malloc(2 * lenB + 1);
	strcpy(doubleB, B);
	strcat(doubleB, B);

	char* pos = strstr(doubleB, A);
	int answer = -1;

	if (pos != NULL) {
		answer = pos - doubleB;
	}

	free(doubleB);

	return answer;
}