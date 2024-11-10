#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* myString) {
	char* answer = (char*)malloc(sizeof(char) * (strlen(myString) + 1));
	for (int i = 0; i < strlen(myString); i++) {
		if ('a' <= myString[i] && myString[i] <= 'z') {
			answer[i] = myString[i] - ('a' - 'A');
		}
		else answer[i] = myString[i];
	}
	answer[strlen(myString)] = '\0';
	return answer;
}