#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(const char* order[], size_t order_len) {
	int answer = 0;
	int i = 0;
	for (i = 0; i < order_len; i++) {
		if (strstr(order[i], "cafelatte") != 0) {
			answer += 5000;
		}
		else {
			answer += 4500;
		}
	}
	return answer;
}