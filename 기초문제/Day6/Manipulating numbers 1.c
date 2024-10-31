#include <stdio.h>
#include <string.h>

int solution(int n, const char* control) {
	int answer = n;

	for (int i = 0; i < strlen(control); ++i) {
		if (control[i] == 'w') {
			answer += 1;
		}
		else if (control[i] == 's') {
			answer -= 1;
		}
		else if (control[i] == 'd') {
			answer += 10;
		}
		else if (control[i] == 'a') {
			answer -= 10;
		}
	}
	return answer;
}