#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int solution(int num_list[], size_t num_list_len) {
	int odd = 0;
	int even = 0;

	for (int i = 0; i < num_list_len; i++) {
		if (num_list[i] & 1)
			odd = odd * 10 + num_list[i];
		else
			even = even * 10 + num_list[i];
	}
	return odd + even;
}