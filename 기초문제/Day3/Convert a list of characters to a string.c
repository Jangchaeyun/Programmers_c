#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* arr[], size_t arr_len) {
	char* answer = (char*)malloc((arr_len + 1) * sizeof(char));

	for (int i = 0; i < arr_len; i++)
	{
		answer[i] = *arr[i];
	}

	answer[arr_len] = '\0';
	return answer;
}