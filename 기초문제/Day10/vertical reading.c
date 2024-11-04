#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* my_string, int m, int c) {
	int length = strlen(my_string);

	char* answer = (char*)malloc((length / m + 2) * sizeof(char));

	int index = 0;

	for (int i = c - 1; i < length; i += m) {
		answer[index++] = my_string[i];
	}

	answer[index] = '\0';

	return answer;
}