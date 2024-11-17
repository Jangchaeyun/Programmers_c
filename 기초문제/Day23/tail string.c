#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* str_list[], size_t str_list_len, const char* ex) {
	size_t total_length = 1;
	char* answer = (char*)malloc(total_length);
	answer[0] = '\0';

	for (size_t i = 0; i < str_list_len; ++i) {
		if (strstr(str_list[i], ex) == NULL) {
			total_length += strlen(str_list[i]);
			answer = (char*)realloc(answer, total_length);
			strcat(answer, str_list[i]);
		}
	}

	return answer;
}