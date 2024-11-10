#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* solution(const char* myString) {
	int length = strlen(myString);
	char* answer = (char*)malloc((length + 1) * sizeof(char));

	for (int i = 0; i < length; i++) {
		if (myString[i] == 'a' || myString[i] == 'A') {
			answer[i] = toupper(myString[i]);
		}
		else {
			answer[i] = tolower(myString[i]);
		}
	}
	answer[length] = '\0';
	return answer;
}