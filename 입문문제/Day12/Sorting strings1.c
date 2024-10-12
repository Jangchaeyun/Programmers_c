#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(const char* my_string) {
	int len = strlen(my_string);
	int* answer = (int*)malloc(len * sizeof(int) + 1);
	int tmp = 0, count = 0;

	for (int i = 0; i < len; i++)
	{
		if (my_string[i] >= '0' && my_string[i] <= '9')
		{
			answer[count++] = my_string[i] - '0';
		}
	}
	for (int i = 0; i < count; i++)
	{
		for (int j = i; j < count; j++)
		{
			if (answer[i] > answer[j])
			{
				tmp = answer[i];
				answer[i] = answer[j];
				answer[j] = tmp;
			}
		}
	}
	return answer;
}