#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* my_string, int n) {
	char* answer = (char*)malloc((n + 1) * sizeof(char));

	strncpy(answer, my_string, n);

	answer[n] = '\0';

	return answer;
}