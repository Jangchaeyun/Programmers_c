#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(const char* babbling[], size_t babbling_len) {
	char str[4][4] = { "aya", "ye", "woo", "ma" };
	int answer = 0;
	int index, j, same;
	bool t;

	for (int i = 0; i < babbling_len; i++) {
		t = true;
		index = 0;
		same = -1;

		while (t) {
			for (j = 0; j < 4; j++) {
				if (!strncmp(babbling[i] + index, str[j], strlen(str[j])) && same != j) {
					index += strlen(str[j]);
					same = j;
					break;
				}
			}
			
			if (babbling[i][index] == '\0') break;
			if (j == 4) t = false;
		}
		if (t) answer++;
	}
	return answer;
}