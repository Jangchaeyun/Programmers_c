#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* s) {
	char* answer = (char*)malloc(strlen(s) + 1);

	strcpy(answer, s);

	for (int i = 0; i < strlen(s); i++) {
		for (int j = i + 1; j < strlen(s); j++) {
			if (answer[i] < answer[j]) {
				char temp = answer[i];
				answer[i] = answer[j];
				answer[j] = temp;
			}
		}
	}
	return answer;
}