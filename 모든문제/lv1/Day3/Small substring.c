#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(const char* t, const char* p) {
	int answer = 0;

	for (int i = 0; i < strlen(t) - strlen(p) + 1; i++) {
		int k = 0;
		bool isSame = false;

		for (int j = i; j < i + strlen(p); j++) {
			if (t[j] > p[k]) break;
			else if (t[j] < p[k]) {
				answer++;
				break;
			}
			else {
				isSame == true;
				if (j == i + strlen(p) - 1) answer++;
			}
			k++;
		}
	}

	return answer;
}