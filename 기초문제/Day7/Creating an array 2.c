#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int* solution(int l, int r) {
	int* answer = (int*)malloc(sizeof(int) * (r - l));
	int index = 0;

	for (int i = l; i <= r; i++) {
		int num = i;
		bool isOkay = false;
		while (num) {
			if (num % 10 == 0 || num % 10 == 5) {
				num /= 10;
				isOkay = true;
			}
			else {
				isOkay = false;
				break;
			}
		}
		if (isOkay)
			answer[index++] = i;
	}

	if (index == 0) {
		answer[index++] = -1;
	}
	answer[index] = '\0';
	return answer;
}