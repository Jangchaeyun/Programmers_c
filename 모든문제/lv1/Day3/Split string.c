#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(const char* s) {
	int answer = 0;
	int count;
	for (int i = 0, j; s[i] != '\0'; i++) {
		if (s[i] == s[i + 1]) {
			count = 2;
			for (j = i + 2; s[j] != '\0'; j++) {
				if (s[i] == s[j]) count++;
				else {
					count--;
					if (count == 0) break;
				}
			}
			i = j;
		}
		else if (s[i + 1] != '\0') i++;
		answer++;
	}
	return answer;
}