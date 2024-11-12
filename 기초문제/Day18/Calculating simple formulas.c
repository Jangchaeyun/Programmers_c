#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(const char* binomal) {
	int answer = 0;
	int n1 = 0, n2 = 0, idx = 0;
	while (binomal[idx] != ' ') {
		n1 = n1 * 10 + (binomal[idx] - '0');
		idx++;
	}
	idx += 3;

	while (binomal[idx] != '\0' || idx < strlen(binomal)) {
		n2 = n2 * 10 + (binomal[idx] - '0');
		idx++;
	}
	for (int i = 0; i < strlen(binomal); i++) {
		if (binomal[i] == '+') {
			answer = n1 + n2;
		}
		else if (binomal[i] == '-') {
			answer = n1 - n2;
		}
		else if (binomal[i] == '*') {
			answer = n1 * n2;
		}
	}
	return answer;
}