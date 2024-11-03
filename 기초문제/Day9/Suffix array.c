#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char** solution(const char* my_string) {
	char** answer = (char**)malloc(strlen(my_string) * sizeof(char*));
	for (int i = 0; i < strlen(my_string); i++)
		answer[i] = (char*)malloc(strlen(my_string) * sizeof(char));
	int n = 0;
	int m = 0;
	for (int i = 0; i < strlen(my_string); i++)
	{
		for (int j = i; j < strlen(my_string); j++)
			answer[n][m++] = my_string[j];
		answer[n][m] = '\0';
		n++;
		m = 0;
	}

	char* tmp;
	for (int i = 0; i < strlen(my_string) - 1; i++)
		for (int j = i + 1; j < strlen(my_string); j++) {
			if (strcmp(answer[i], answer[j]) > 0)
			{
				tmp = answer[i];
				answer[i] = answer[j];
				answer[j] = tmp;
			}
		}
	return answer;
}