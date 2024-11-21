#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int* solution(const char* keymap[], size_t keymap_len, const char* targets[], size_t targets_len) {
	int min_press[120];
	for (int i = 0; i < 120; i++) {
		min_press[i] = INT_MAX;
	}

	for (size_t i = 0; i < keymap_len; i++) {
		for (size_t j = 0; keymap[i][j] != '\0'; j++) {
			char key = keymap[i][j];
			if (min_press[(int)key] > (int)(j + 1)) {
				min_press[(int)key] = (int)(j + 1);
			}
		}
	}

	int* answer = (int*)malloc(targets_len * sizeof(int));
	if (!answer) {
		return NULL;
	}

	for (size_t i = 0; i < targets_len; i++) {
		int count = 0;
		bool is_valid = true;

		for (size_t j = 0; targets[i][j] != '\0'; j++) {
			char key = targets[i][j];
			if (min_press[(int)key] == INT_MAX) {
				count = -1;
				is_valid = false;
				break;
			}
			count += min_press[(int)key];
		}
		answer[i] = is_valid ? count : -1;
	}

	return answer;
}