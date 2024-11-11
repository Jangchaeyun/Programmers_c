#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char** solution(const char* strArr[], size_t strArr_len) {
	char** answer = (char**)malloc(20 * sizeof(char*));
	int tag = 0;
	int n = 0;
	for (int i = 0; i < strArr_len; i++)
		answer[i] = (char*)malloc(20 * sizeof(char));
	for (int i = 0; i < strArr_len; i++) {
		for (int j = 0; j < strlen(strArr[i]); j++) {
			if (strncmp(strArr[i] + j, "ad", 2) == 0)
				tag = 1;
		}
		if (tag == 1)
			tag = 0;
		else
			answer[n++] = strArr[i];
	}
	return answer;
}