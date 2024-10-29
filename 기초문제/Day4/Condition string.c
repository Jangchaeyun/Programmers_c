#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(const char* ineq, const char* eq, int n, int m) {
	int answer = 0;
	int re1 = strcmp(ineq, "<");
	int re2 = strcmp(eq, "=");

	if (re1 == 0 && re2 == 0) {
		answer = (n <= m) ? 1 : 0;
	}
	else if (re1 == 0 && re2 < 0) {
		answer = (n < m) ? 1 : 0;
	}
	else if (re1 > 0 && re2 == 0) {
		answer = (n >= m) ? 1 : 0;
	}
	else if (re1 > 0 && re2 < 0) {
		answer = (n > m) ? 1 : 0;
	}

	return answer;
}