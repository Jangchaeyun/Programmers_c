#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* my_string, const char* letter) {
	int len = strlen(my_string);
	char* answer = (char*)malloc(len - 1);
	int x = 0;
	for (int i = 0; i < len; i++) {
		if (my_string[i] != letter[0]) {
			answer[x++] = my_string[i];
		}
	}
	answer[x] = NULL;
	return answer;
}