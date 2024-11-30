#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a, int b)
{
	int num1, num2, temp;
	if (a > b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	num1 = b - a + 1;
	num2 = a + b;
	return (long long)num1 * num2 / 2;
}