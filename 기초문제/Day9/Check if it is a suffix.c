#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(const char* my_string, const char* is_suffix) {
	if (strlen(my_string) < strlen(is_suffix)) return 0;
	int i = strlen(my_string) - strlen(is_suffix);
	int idx = 0;

	if (my_string[i] == is_suffix[idx]) {
		while (idx < strlen(is_suffix)) {
			if (my_string[i++] != is_suffix[idx++]) return 0;
		}
		return 1;
	}
	return 0;
}