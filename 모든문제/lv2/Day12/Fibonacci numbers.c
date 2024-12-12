#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int memo[100000];

int fibo(n)
{
	if (n == 0) return 0;
	if (memo[n] != 0) return memo[n];
	else return memo[n] = (fibo(n - 1) + fibo(n - 2)) % 1234567;
}

int solution(int n)
{
	memo[1] = 1;
	return fibo(n) % 1234567;
}