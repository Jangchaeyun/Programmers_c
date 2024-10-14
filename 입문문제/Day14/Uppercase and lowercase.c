#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* my_string) {
	char* answer = (char*)malloc(strlen(my_string) + 1);
	int i;
	for (i = 0; i < strlen(my_string); i++) {
		if (my_string[i] >= 'a' && my_string[i] <= 'z')
			answer[i] = my_string[i] - 32;
		if (my_string[i] >= 'A' && my_string[i] <= 'Z')
			answer[i] = my_string[i] + 32;
	}
	answer[i] = '\0';
	return answer;
}