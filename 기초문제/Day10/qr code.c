#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(int q, int r, const char* code) {
	int length = strlen(code);

	char* answer = (char*)malloc((length / q + 2) * sizeof(char));

	int index = 0;

	for (int i = 0; i < length; ++i) {
		if (i % q == r) {
			answer[index++] = code[i];
		}
	}
	
	answer[index] = '\0';

	return answer;
}