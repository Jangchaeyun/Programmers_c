#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(const char* spell[], size_t spell_len, const char* dic[], size_t dic_len) {
	int answer = 2;

	for (size_t i = 0; i < dic_len; i++) {
		if (strlen(dic[i]) == spell_len) {
			answer = 1;

			for (size_t j = 0; j < spell_len; j++) {
				if (strstr(dic[i], spell[j]) == NULL) {
					answer = 2;
					break;
				}
			}

			if (answer == 1) {
				return answer;
			}
		}
	}
	return answer;
}