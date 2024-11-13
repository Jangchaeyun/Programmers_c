#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int arr[], size_t arr_len, int k) {
	int* answer = (int*)malloc(sizeof(int) * (k + 1));
	int count = 0;
	for (int i = 0; i < arr_len; i++) {
		int currentNumber = arr[i];

		bool isDistinct = true;
		for (int j = 0; j < count; j++) {
			if (currentNumber == answer[j]) {
				isDistinct = false;
				break;
			}
		}

		if (isDistinct) {
			if (count < k) {
				answer[count] = currentNumber;
				count++;
			}
			else {
				break;
			}
		}
	}

	for (int i = count; i < k; i++) {
		answer[i] = -1;
	}
	return answer;
}