#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


int solution(const char* my_string, const char* is_prefix) {
	int prefix_length = strlen(is_prefix);

	if (strlen(my_string) < prefix_length) {
		return 0;
	}

	for (int i = 0; i < prefix_length; ++i) {
		if (my_string[i] != is_prefix[i]) {
			return 0;
		}
	}

	return 1;
}