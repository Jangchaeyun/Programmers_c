#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* bin1, const char* bin2) {
	int max = 0;
	if (strlen(bin1) > strlen(bin2))
		max = strlen(bin1);
	else
		max = strlen(bin2);
	char* answer = (char*)malloc(max + 1);
	char* answer_ivs = (char*)malloc(max + 1);
	int num;
	int index1 = strlen(bin1) - 1;
	int index2 = strlen(bin2) - 1;
	int n = 0;
	int tmp = 0;
	int num1 = bin1[index1] - 48;
	int num2 = bin2[index2] - 48;

	while (1) {
		if (tmp + num1 + num2 < 2)
		{
			num = tmp + num1 + num2;
			tmp = 0;
		}
		else
		{
			num = tmp + num1 + num2 - 2;
			tmp = 1;
		}
		answer_ivs[n++] = num + 48;
		if (index1 == 0 && index2 == 0 && tmp == 0) break;
		if (index1 > 0)
			num1 = bin1[--index1] - 48;
		else
			num1 = 0;
		if (index2 > 0)
			num2 = bin2[--index2] - 48;
		else
			num2 = 0;
	}
	for (int i = 0; i < n; i++)
		answer[i] = answer_ivs[n - i - 1];
	answer[n] = '\0';
	return answer;
}