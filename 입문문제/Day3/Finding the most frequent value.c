#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int array[], size_t array_len) {
	int answer = 0;
	int freq = 1;
	int idx = 1;
	if (array_len == 1) {
		answer = array[0]; return answer;
	}
	for (int i = 0; i < array_len - 1; i++)
	{
		freq = 1;
		for (int j = i + 1; j < array_len; j++)
		{
			if (array[i] == array[j]) freq++;
			if (freq > idx)
			{
				idx = freq;
				answer = array[i];
			}
			else if (freq == idx && answer != array[i])
				answer = -1;
		}
	}
	return answer;
}