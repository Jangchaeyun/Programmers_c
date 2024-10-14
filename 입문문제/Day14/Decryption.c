#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* cipher, int code) {
	int len = strlen(cipher);
	char* answer = (char*)malloc(len * sizeof(int));
	int a = 0;
	for (int i = 1; i <= len; i++)
	{
		if ((i % code) == 0) {
			answer[a++] = cipher[i - 1];
		}
	}
	answer[a] = NULL;
	return answer;
}