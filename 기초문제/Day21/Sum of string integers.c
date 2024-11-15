#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(const char* num_str) {
	int answer = 0;
	for (int i = 0; i < strlen(num_str); i++) {
		answer += num_str[i] - 48;
	}
	return answer;
}