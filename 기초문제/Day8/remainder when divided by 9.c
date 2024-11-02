#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(const char* number) {
	int answer = 0;
	int i = 0;
	while (*(number + i)) {
		answer += *(number + i) - '0';
		i++;
	}
	answer %= 9;
	return answer;
}