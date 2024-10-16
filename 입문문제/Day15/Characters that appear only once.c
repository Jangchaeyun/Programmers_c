#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* s) {
	char* answer = (char*)malloc(strlen(s));
	int arr['z' - 'a' + 1] = { 0, };
	int n = 0;
	for (int i = 0; i < strlen(s); i++) {
		arr[s[i] - 'a']++;
	}
	for (int i = 0; i <= 'z' - 'a'; i++)
		if (arr[i] == 1)
			answer[n++] = i + 'a';
	answer[n] = '\0';
	return answer;
}