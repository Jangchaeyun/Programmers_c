#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

char num[1000];
int len;

int primeNum(long long n) {
	if (n == 0 || n == 1) return 0;
	for (long long i = 2; i <= (long long)sqrt(n); i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int solution(int n, int k) {
	int answer = 0;

	while (n > 0) {
		num[len++] = n % k + '0';
		n /= k;
	}

	long long digit = 0;
	for (int i = len - 1; i >= 0; i--) {
		if (num[i] == '0') {
			if (primeNum(digit)) answer++;
			digit = 0;
		}
		else {
			digit *= 10;
			digit += num[i] - '0';
		}
	}
	if (primeNum(digit)) answer++;
	return answer;
}