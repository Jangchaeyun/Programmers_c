#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* my_string, int indices[], size_t indices_len) {
	char* answer = (char*)malloc(strlen(my_string) * sizeof(int));
	int i, j;
	int tmp;
	for (i = 0; i < indices_len - 1; i++)
		for (j = i + 1; j < indices_len; j++)
		{
			if (indices[i] > indices[j])
			{
				tmp = indices[i];
				indices[i] = indices[j];
				indices[j] = tmp;
			}
		}
	j = 0;
	int k = 0;

	for (i = 0; i < strlen(my_string); i++) {
		if (i != indices[j])
			answer[k++] = my_string[i];
		else
			j++;
	}
	answer[k] = '\0';
	return answer;
}