#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n, int slicer[], size_t slicer_len, int num_list[], size_t num_list_len) {
	int* answer = (int*)malloc(num_list_len * sizeof(int));
	int j = 0;
	if (n == 1) {
		for (int i = 0; i <= slicer[1]; i++) {
			answer[j++] = num_list[i];
		}
	}
	if (n == 2) {
		for (int i = slicer[0]; i <= num_list_len; i++) {
			answer[j++] = num_list[i];
		}
	}
	if (n == 3) {
		for (int i = slicer[0]; i <= slicer[1]; i++) {
			answer[j++] = num_list[i];
		}
	}
	if (n == 4) {
		for (int i = slicer[0]; i <= slicer[1]; i+= slicer[2]) {
			answer[j++] = num_list[i];
		}
	}

	return answer;
}