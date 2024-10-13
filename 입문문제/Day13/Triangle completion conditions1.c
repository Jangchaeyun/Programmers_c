#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int sides[], size_t sides_len) {
	int answer = 0, flag = 0;
	for (int i = 0; i < sides_len; i++)
	{
		for (int x = 0; x < sides_len; x++)
		{
			if (sides[i] < sides[x])
			{
				flag = sides[i];
				sides[i] = sides[x];
				sides[x] = flag;
			}
			if (sides[2] >= sides[0] + sides[1])
			{
				answer = 2;
			}
			else {
				answer = 1;
			}
		}
	}
	return answer;
}