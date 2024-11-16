#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* n_str) {
	char* answer = (char*)malloc(strlen(n_str));
	int j = 0;
	for (int i = 0; i < strlen(n_str); i++) {
		if (n_str[i] != '0')
		{
			for (int k = i; k < strlen(n_str); k++)
				answer[j++] = n_str[k];
			break;
		}
	}
	answer[j] = '\0';
	return answer;
}