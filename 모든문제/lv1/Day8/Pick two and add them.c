#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int numbers[], size_t numbers_len)
{
	int* answer;
	int num[10001];
	int len = 0, temp;

	for (int i = 0; i < numbers_len - 1; i++) {
		for (int j = i + 1; j < numbers_len; j++) {
			num[len++] = numbers[i] + numbers[j];
		}
	}

	for (int i = 0; i < len - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < len; j++)
		{
			if (num[j] < num[min])
			{
				min = j;
			}
		}
		if (i != min)
		{
			temp = num[i];
			num[i] = num[min];
			num[min] = temp;
		}
	}

	answer = (int*)malloc(sizeof(int) * len);

	for (int i = 0, n = 0; i < len; i++)
	{
		answer[n++] = num[i];
		while (num[i] == num[i + 1]) i++;
	}
	return answer;
}