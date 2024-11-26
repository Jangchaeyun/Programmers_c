#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
	int answer = 0;
	int len = 0;
	int exp;
	int num = n;

	while (num / 3 > 0) {
		num = num / 3;
		len++;
	}

	while (n > 0) {
		exp = 1;
		for (int i = 0; i < len; i++)
		{
			exp = exp * 3;
		}
		answer = answer + (n % 3) * exp;
		n = n / 3;
		len--;
	}
	return answer;
}