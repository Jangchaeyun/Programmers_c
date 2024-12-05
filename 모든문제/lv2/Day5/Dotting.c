#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

long long solution(int k, int d) {
	long long answer = 0;

	for (long long i = 0; i <= d; i += k) {
		long long maxY = (long long)sqrt((long long)d * d - i * i);
		answer += (maxY / k) + 1;
	}
	return answer;
}