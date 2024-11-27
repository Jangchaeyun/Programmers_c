#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(int x)
{
	int sum = 0, temp = x;
	while (temp != 0)
	{
		sum += temp % 10;
		temp /= 10;
	}
	return (x % sum == 0) ? true : false;
}