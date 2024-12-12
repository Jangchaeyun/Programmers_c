#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int n) {
	long long answer = 0;
	long long num[n];

	num[0] = 1;
	num[1] = 1;

	for (int i = 2; i <= n; i++) {
		num[i] = (num[i - 1] + num[i - 2]) % 1234567;
	}

	answer = num[n];

	return answer;
}