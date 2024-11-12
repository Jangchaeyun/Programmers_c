#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* rny_string) {
	int length = strlen(rny_string);
	int newLength = 0;

	for (int i = 0; i < length; ++i) {
		if (rny_string[i] == 'm') {
			newLength += 2;
		}
		else {
			newLength += 1;
		}
	}
	
	char* answer = (char**)malloc(newLength + 1);
	if (!answer) return NULL;

	int index = 0;
	for (int i = 0; i < length; ++i) {
		if (rny_string[i] == 'm') {
			answer[index++] = 'r';
			answer[index++] = 'n';
		}
		else {
			answer[index++] = rny_string[i];
		}
	}
	answer[index] = '\0';

	return answer;
}