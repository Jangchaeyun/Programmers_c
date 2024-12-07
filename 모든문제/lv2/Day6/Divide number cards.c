#include <stdio.h>

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int solution(int arrayA[], size_t arrayA_len, int arrayB[], size_t arrayB_len) {
	int answer = 0;
	int cur = arrayA[0];

	for (size_t i = 1; i < arrayA_len; i++) {
		cur = gcd(cur, arrayA[i]);
		if (cur == 1) break;
	}

	if (cur != 1) {
		size_t i;
		for (i = 0; i < arrayB_len; i++) {
			if (arrayB[i] % cur == 0) break;
		}
		if (i == arrayB_len) answer = cur;
	}

	cur = arrayB[0];

	for (size_t i = 1; i < arrayB_len; i++) {
		cur = gcd(cur, arrayB[i]);
		if (cur == 1) break;
	}

	if (cur != 1) {
		size_t i;
		for (i = 0; i < arrayA_len; i++) {
			if (arrayA[i] % cur == 0) break;
		}
		if (i == arrayA_len) {
			if (cur > answer) answer = cur;
		}
	}

	return answer;
}