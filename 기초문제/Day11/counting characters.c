#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(const char* my_string) {
	int* answer = (int*)malloc(sizeof(int) * 52);
	for (int i = 0; i < 52; i++) answer[i] = 0;

	int i = 0;
	while (my_string[i] != '\0') {
		char ch = my_string[i];
		if ('A' <= ch && ch <= 'Z') answer[ch - 'A'] += 1;
		else if ('a' <= ch && ch <= 'z') answer[26 + ch - 'a'] += 1;
		i++;
	}

	return answer;
}