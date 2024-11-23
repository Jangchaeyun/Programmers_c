#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int stack[1000000];

int solution(int ingredient[], size_t ingredient_len) {
	int answer = 0;
	int size = 0;
	for (int i = 0; i < ingredient_len; i++) {
		stack[size++] = ingredient[i];
		if (stack[size - 1] == 1 && size >= 4) {
			if (stack[size - 4] == 1 && stack[size - 3] == 2 && stack[size - 2] == 3) {
				answer++;
				size -= 4;
			}
		}
	}
	return answer;
}