#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int i, int j, int k) {
	int answer = 0;
	char* n;
	int num;
	for (int x = i; x <= j; x++) {
		num = x;
		while (1) {
			if (num % 10 == k) answer++;
			num /= 10;
			if (num == 0) break;
		}
	}
	return answer;
}