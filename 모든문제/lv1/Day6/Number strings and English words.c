#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(const char* s)
{
	char str[10][6] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
	char number[50] = { 0 }, temp;
	int i, j, m, leng = 0;
	int answer = 0;

	for (i = 0; i < strlen(s); i++)
	{
		temp = s[i];
		if (temp >= '0' && temp <= '9')
		{
			number[leng++] = temp;
		}
		else {
			for (j = 0; j < 10; j++)
			{
				if (strncmp(s + i, str + j, 3) == 0)
				{
					temp = j + '0';
					number[leng++] = temp;
					i += strlen(str[j]) - 1;
					break;
				}
			}
		}
	}

	m = 1; 
	for (i = strlen(number) - 1; i >= 0; i--, m *= 10)
	{
		answer += (number[i] - '0') * m;
	}

	return answer;
}