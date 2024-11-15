#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int num_list[], size_t num_list_len) {
	int* answer = (int*)malloc(num_list_len * sizeof(int));
	int tmp;
	int i;
	for (i = 0; i < num_list_len; i++)
		for (int j = i + 1; j < num_list_len; j++)
			if (num_list[i] > num_list[j])
			{
				tmp = num_list[i];
				num_list[i] = num_list[j];
				num_list[j] = tmp;
			}
	int k = 0;
	for (i = 5; i < num_list_len; i++)
		answer[k++] = num_list[i];
	return answer;
}