#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_in_skip(char c, const char* skip) {
	while(*skip != '\0') {
		if (*skip == c) {
			return true;
		}
		skip++;
	}
	return false;
}

char* solution(const char* s, const char* skip, int index) {
	int s_len = strlen(s);
	char* answer = (char*)malloc((s_len + 1) * sizeof(char));
	if (answer == NULL) {
		return NULL;
	}

	for (int i = 0; i < s_len; i++) {
		char current_char = s[i];
		int temp_index = index;

		while (temp_index > 0) {
			if (current_char == 'z') {
				current_char = 'a';
			}
			else {
				current_char++;
			}

			if (is_in_skip(current_char, skip)) {
				temp_index++;
			}

			temp_index--;
		}
		answer[i] = current_char;
	}

	answer[s_len] = '\0';
	return answer;
}