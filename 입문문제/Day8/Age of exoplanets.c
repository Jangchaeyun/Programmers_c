#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int age) {
	char* answer = (char*)malloc(sizeof(char*) * 4);
	sprintf(answer, "%d", age);
	for (int i = 0; i < strlen(answer); i++) {
		answer[i] += 49;
	}
	return answer;
}