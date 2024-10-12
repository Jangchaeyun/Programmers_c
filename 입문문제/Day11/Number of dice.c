#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int box[], size_t box_len, int n) {
	int answer = 0;
	answer = (box[0] / n) * (box[1] / n) * (box[2] / n);
	return answer;
}