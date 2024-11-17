#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int solution(int date1[], size_t date1_len, int date2[], size_t date2_len) {
	int answer = 0;
	for (int i = 0; i < date1_len; i++) {
		if (date1[i] < date2[i]) {
			answer = 1;
			break;
		}
		if (date1[i] > date2[i]) {
			answer = 0;
			break;
		}
	}
	return answer;
}