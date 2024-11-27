#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int func(int num)
{
	for (int i = 2; i <= num / 2; i++)
	{
		if (num % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int  solution(int nums[], size_t nums_len)
{
	int answer = 0;
	int i, j, l;
	int m;
	for (int i = 0; i < nums_len - 2; i++)
	{
		if (nums[i] % 2 == 0) m = 1;
		else m = 0;
		for (j = i + 1; j < nums_len - 1; j++)
		{
			if (nums[j] % 2 == 0) m++;
			for (l = j + 1; l < nums_len; l++) {
				if (nums[l] % 2 == 0) m++;
				if (m == 0 || m == 2)
				{
					if (func(nums[i] + nums[j] + nums[l]) == 1)
					{
						answer++;
					}
				}
				if (nums[l] % 2 == 0) m--;
			}
			if (nums[j] % 2 == 0) m--;
		}
	}
	return answer;
}