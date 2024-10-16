#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(const char* s1[], size_t s1_len, const char* s2[], size_t s2_len) {
	int answer = 0;
	for (int x = 0; x < s1_len; x++) {
		for (int i = 0; i < s2_len; i++) {
			if (!strcmp(s1[x], s2[i]))
			{
				answer++;
			}
		}
	}
	return answer;
}