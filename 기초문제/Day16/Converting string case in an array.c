#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char** solution(const char* strArr[], size_t strArr_len) {
	char** answer = (char**)malloc(sizeof(char*) * 20);

	for (int i = 0; i < strArr_len; i++)
	{
		answer[i] = (char*)malloc(sizeof(char) * 20);
	}
	int j;
	for (int i = 0; i < strArr_len; i++) {
		for (j = 0; j < strlen(strArr[i]); j++)
		{
			if (i % 2 == 0)
				answer[i][j] = tolower(strArr[i][j]);
			else
				answer[i][j] = toupper(strArr[i][j]);
		}
		answer[i][j] = '\0';
	}
	return answer;
}
