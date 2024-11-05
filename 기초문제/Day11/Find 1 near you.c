#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int arr[], size_t arr_len, int idx) {
	int i = 0;
	for (i = idx; i < arr_len; i++)
		if (arr[i] == 1)
			return i;
	if (i > arr_len)
		return -1;
}