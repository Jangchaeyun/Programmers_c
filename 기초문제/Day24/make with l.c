#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* myString) {
	char* answer = (char*)malloc(strlen(myString));
	for (int i = 0; i < strlen(myString); i++) {
		if (myString[i] < 'l') answer[i] = 'l';
		else answer[i] = myString[i];
	}
	answer[strlen(myString)] = '\0';
	return answer;
} 