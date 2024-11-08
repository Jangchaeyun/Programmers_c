#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char** solution(const char* names[], size_t names_len) {
	char** answer = (char**)malloc(300);
	int n = 0;
	for (int i = 0; i < names_len; i += 5)
		answer[n++] = names[i];
	return answer;
}