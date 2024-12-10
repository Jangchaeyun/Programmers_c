#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char str[150000];

int* solution(const char* s) {
	int* answer = (int*)malloc(sizeof(int) * 2);

	answer[0] = answer[1] = 0;
	strcpy(str, s);
	int num, leng = strlen(str);

	while (1)
	{
		answer[0]++;
		num = 0;
		for (int i = 0; i < leng; i++) {
			if (str[i] == '0') answer[1]++;
			else if (str[i] == '1') num++;
		}
		if (num == 1) break;

		leng = 0;
		while (num != 0) {
			str[leng++] = num % 2 + '0';
			num /= 2;
		}
	}

	return answer;
}