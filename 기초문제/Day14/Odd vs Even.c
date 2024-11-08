#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num_list[], size_t num_list_len) {
	int answer = 0;
	int odd_sum = 0;
	int even_sum = 0;

	for (size_t i = 0; i < num_list_len; ++i) {
		if (i % 2 == 0) {
			odd_sum += num_list[i];
		}
		else {
			even_sum += num_list[i];
		}
	}

	answer = (odd_sum > even_sum) ? odd_sum : even_sum;
	return answer;
}