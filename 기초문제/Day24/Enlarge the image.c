#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** solution(const char* picture[], size_t picture_len, int k) {
	size_t answer_capacity = picture_len * k;
	char** answer = (char**)malloc(answer_capacity * sizeof(char*));
	size_t answer_index = 0;

	for (size_t i = 0; i < picture_len; ++i) {
		size_t row_len = strlen(picture[i]);
		size_t new_row_len = row_len * k;
		char* expanded_row = (char*)malloc((new_row_len + 1) * sizeof(char));
		expanded_row[new_row_len] = '\0';

		for (size_t j = 0; j < row_len; ++j) {
			for (int l = 0; l < k; ++l) {
				expanded_row[j * k + l] = picture[i][j];
			}
		}
		
		for (int j = 0; j < k; ++j) {
			answer[answer_index] = (char*)malloc((new_row_len + 1) * sizeof(char));
			strcpy(answer[answer_index], expanded_row);
			++answer_index;
		}

		free(expanded_row);
	}
	return answer;
}