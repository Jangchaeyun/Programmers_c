#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(const char* myString) {
	int cnt = 0;
	for (int i = 0; i < strlen(myString); i++) {
		if (myString[i] == 'x') cnt++;
	}
	int* answer = (int*)malloc(sizeof(int) * (1 + cnt));
	int idx = 0, count = 0;
	for (int i = 0; i <= strlen(myString); i++) {
		if (myString[i] == 'x' || i == strlen(myString)) {
			answer[idx] = count;
			count = 0;
			idx++;
		}
		else {
			count++;
		}
	}
	return answer;
}