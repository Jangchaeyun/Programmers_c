#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* number, int k)
{
	char* answer = (char*)malloc(strlen(number));
	strcpy(answer, "");

	int i, cnt = 0, len = 0;
	char max, index;
	char* temp = number;
	while (k > cnt && strlen(number) - k > len)
	{
		max = '0';
		index = i = 0;
		while (1)
		{
			if (max < temp[i])
			{
				max = temp[i];
				index = i;
				if (max == '9') break;
			}
			if (i == k - cnt) break;
			i++;
		}
		cnt += index;
		answer[len++] = max;
		temp = temp + index + 1;
	}
	answer[len] = '\0';
	if (strlen(number) - k > len)
	{
		strcat(answer, temp);
		answer[strlen(number) - k] = '\0';
	}

	return answer;
}