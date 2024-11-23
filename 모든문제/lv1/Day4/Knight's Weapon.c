#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int get_power(int num) {
	int cnt = 0;
	for (int i = 1; i <= (int)(sqrt(num)); i++) {
		if (num % i == 0) {
			cnt++;
			if (i * i != num)
				cnt++;
		}
	}
	return cnt;
}

int solution(int number, int limit, int power) {
	int answer = 0;
	for (int i = 0; i <= number; i++) {
		int p = get_power(i);
		if (p > limit) {
			answer += power;
		}
		else {
			answer += p;
		}
	}
	return answer;
}