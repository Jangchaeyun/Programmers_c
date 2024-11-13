#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* solution(int arr[], size_t arr_len) {
	int* stk = (int*)malloc(arr_len * sizeof(int));
	if (stk == NULL) {
		return NULL;
	}
	size_t stk_size = 0;

	size_t i = 0;
	while (i < arr_len) {
		if (stk_size == 0) {
			stk[stk_size++] = arr[i];
			i++;
		}
		else if (stk[stk_size - 1] == arr[i]) {
			stk_size--;
			i++;
		}
		else {
			stk[stk_size++] = arr[i];
			i++;
		}
	}

	if (stk_size == 0) {
		free(stk);
		stk = (int*)malloc(sizeof(int));
		if (stk == NULL) {
			return NULL;
		}
		stk[0] = -1;
		stk_size = 1;
	}
	else {
		stk = (int*)realloc(stk, stk_size * sizeof(int));
	}

	printf("Result length: %zu\n", stk_size);
	return stk;
}