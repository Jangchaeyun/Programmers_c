#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num, int k) {
	int answer = -1;
	int idx = 0;
	while (num != 0) {
		if (num % 10 == k) answer = idx;
		idx++;
		num /= 10;
	}
	if (answer != -1) answer = idx - answer;

	return answer;
}