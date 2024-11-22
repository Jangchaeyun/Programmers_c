#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(const char* s) {
	int* answer = (int*)malloc(sizeof(int) * (strlen(s) + 1));

	int alp[26] = { 0, };
	
	for (int i = 0; i < strlen(s); i++) {
		if (alp[s[i] - 97] == 0) {
			alp[s[i] - 97]++;
			answer[i] = -1;
		}
		else {
			int cnt = 0;
			for (int j = i - 1; j >= 0; j--) {
				cnt++;
				if (s[j] == s[i]) break;
			}
			answer[i] = cnt;
		}
	}
	return answer;
}