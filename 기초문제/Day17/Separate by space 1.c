#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char** solution(char* my_string) {
	char** answer = (char**)malloc(sizeof(char*) * 500);
	char* temp;
	temp = strtok(my_string, " ");
	int i = 0;
	while (temp != NULL) {
		answer[i++] = temp;
		temp = strtok(NULL, " ");
	}
	return answer;
}