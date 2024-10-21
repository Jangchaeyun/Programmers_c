#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

int solution(const char* my_string) {
	int answer = 0;
	int n;
	int ten = 1;
	for (int i = strlen(my_string); i >= 0; i--) {
		if (my_string[i] >= '0' && my_string[i] <= '9') {
			n = my_string[i] - '0';
			answer += (ten * n);
			ten *= 10;
		}
		else
			ten = 1;
	}
	return answer;
}