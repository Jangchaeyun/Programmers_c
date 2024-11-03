#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* my_strings[], size_t my_strings_len, int** parts, size_t parts_rows, size_t parts_cols) {
	char* answer = (char*)malloc(100 * my_strings_len);
	int k = 0;
	for (int i = 0; i < my_strings_len; i++) {
		for (int j = parts[i][0]; j <= parts[i][1]; j++)
			answer[k++] = my_strings[i][j];
	}
	answer[k] = '\0';
	return answer;
}