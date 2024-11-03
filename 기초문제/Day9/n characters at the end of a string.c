#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* my_string, int n) {
	char* answer = (char*)malloc(1000 * sizeof(int));
	int i;
	int j = 0;
	for (i = strlen(my_string) - n; i <= strlen(my_string); i++)
		answer[j++] = my_string[i];
	answer[j] = "\0";
	return answer;
}