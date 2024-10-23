#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(const char* babbling[], size_t babbling_len) {
	int answer = 0;

	for (size_t i = 0; i < babbling_len; i++) {
		bool check = false;
		size_t j = 0;
		size_t len = strlen(babbling[i]);

		while (j < len) {
			if (j + 2 < len && strncmp(babbling[i] + j, "aya", 3) == 0) {
				j += 3;
			}
			else if (j + 1 < len && strncmp(babbling[i] + j, "ye", 2) == 0) {
				j += 2;
			}
			else if (j + 2 < len && strncmp(babbling[i] + j, "woo", 3) == 0) {
				j += 3;
			}
			else if (j + 1 < len && strncmp(babbling[i] + j, "ma", 2) == 0) {
				j += 2;
			}
			else {
				check = true;
				break;
			}
		}

		if (!check) {
			answer++;
		}
	}
	return answer;
}