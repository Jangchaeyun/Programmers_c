#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

long long div_recursive(long long n, long long l, long long r) {
	if (l > r) return 0;
	if (n == 1) {
		return 1;
	}
	long long ret = 0;
	long long s = n / 5;
	for (int i = 0; i < 5; i++) {
		if (i == 2)continue;
		long long new_l = (l > s * i) ? l - (s * i) : 0;
		long long new_r = (r < s * (i + 1) - 1) ? r - (s * i) : s - 1;
		ret += div_recursive(s, new_l, new_r);
	}
	return ret;
}

int solution(int n, long long l, long long r) {
	return div_recursive(pow(5, n), l - 1, r - 1);
}