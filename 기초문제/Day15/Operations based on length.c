#include <stdio.h>
#include <stdlib.h>

int solution(int num_list[], size_t num_list_len) {
	int answer = 1;

	if (num_list_len >= 11) {
		for (size_t i = 0; i < num_list_len; i++) {
			answer += num_list[i];
		}
		answer -= 1;
	}
	else {
		for (size_t i = 0; i < num_list_len; i++) {
			answer *= num_list[i];
		}
	}
	return answer;
}