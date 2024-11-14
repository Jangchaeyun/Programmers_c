#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int num_list[], size_t num_list_len) {
	int* answer = (int*)malloc(5 * sizeof(int));
	int tmp;
	for (int i = 0; i < num_list_len - 1; i++)
		for (int j = i + 1; j < num_list_len; j++) {
			if (num_list[i] > num_list[j]) {
				tmp = num_list[i];
				num_list[i] = num_list[j];
				num_list[j] = tmp;
			}
		}
	for (int k = 0; k < 5; k++)
		answer[k] = num_list[k];
	return answer;
}