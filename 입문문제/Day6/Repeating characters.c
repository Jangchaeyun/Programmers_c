#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* my_string, int n) {
	int len = strlen(my_string);
	char* answer = (char*)malloc(len * n);
	int k = 0;
	for (int j = 0; j < len; j++)
		for (int i = 0; i < n; i++) {
			answer[k] = my_string[j];
			k++;
		}
	answer[k] = NULL;
	return answer;
}