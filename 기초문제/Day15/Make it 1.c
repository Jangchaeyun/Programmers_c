#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num_list[], size_t num_list_len) {
	int answer = 0;
	int num;
	for (int i = 0; i < num_list_len; i++) {
		num = num_list[i];
		while (1) {
			if (num % 2 == 0) {
				num = num / 2;
				answer++;
			}
			else if (num != 1) {
				num = (num - 1) / 2;
				answer++;
			}
			if (num == 1) break;
		}
	}
	return answer;
}