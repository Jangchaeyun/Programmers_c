#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int solution(int arr[], size_t arr_len) {
	int* check = (int*)malloc(arr_len * sizeof(int));
	int* temp = (int*)malloc(arr_len * sizeof(int));
	int count = 0;

	for (size_t i = 0; i < arr_len; i++) {
		check[i] = arr[i];
	}

	while (1) {
		for (size_t i = 0; i < arr_len; i++) {
			if (arr[i] >= 50 && arr[i] % 2 == 0) {
				arr[i] /= 2;
			}
			else if (arr[i] < 50 && arr[i] % 2 == 1) {
				arr[i] = arr[i] * 2 + 1;
			}
		}

		count++;

		bool is_same = true;
		for (size_t i = 0; i < arr_len; i++) {
			if (check[i] != arr[i]) {
				is_same = false;
				break;
			}
		}
		
		if (is_same) {
			count--;
			break;
		}

		for (size_t i = 0; i < arr_len; i++) {
			check[i] = arr[i];
		}
	}

	free(check);
	free(temp);

	return count;
}