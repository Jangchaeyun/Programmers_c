#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* my_string) {
	char* answer = (char*)malloc(strlen(my_string) * sizeof(char));
	int i, k;
	int cnt[1000] = { 0, };
	k = 0;
	for (i = 0; i < strlen(my_string); i++) {
		if (cnt[my_string[i] - 32] == 0)
			answer[k++] = my_string[i];
		cnt[my_string[i] - 32]++;
	}
	answer[k] = '\0';
	return answer;
}