#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n, int m, int section[], size_t section_len) {
	int answer = 0;
	int i, j, check[100000] = { 0 };
	for (i = 0; i < section_len; i++) {
		check[section[i] - 1] = 1;
	}
	i = 1;
	while (i <= section[section_len - 1]) {
		for (j = i - 1; j < n; j++) {
			if (check[j]) {
				i = j + 1 + m;
				break;
			}
		}
		answer++;
	}
	return answer;
}