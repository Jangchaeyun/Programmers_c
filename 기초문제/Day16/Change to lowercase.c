#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

char* solution(const char* myString) {
	char* answer = (char*)malloc(100000 * sizeof(char));
	for (int i = 0; i < strlen(myString); i++)
		answer[i] = tolower(myString[i]);
	return answer;
}