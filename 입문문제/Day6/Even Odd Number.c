#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int num_list[], size_t num_list_len) {
	int* answer = (int*)malloc(sizeof(int) * 2);
	int even = 0, odd = 0;
	int i;
	for (i = 0; i < num_list_len; i++) {
		if (num_list[i] % 2 == 0)
			even++;
		else if (num_list[i] % 2 != 0)
			odd++;
	}
	answer[0] = even;
	answer[1] = odd;

	return answer;
}