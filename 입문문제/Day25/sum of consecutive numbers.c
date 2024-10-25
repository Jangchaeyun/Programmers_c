#include <stdio.h>
#include <stdlib.h>

int* solution(int num, int total) {
	int* answer = (int*)malloc(sizeof(int) * num);
	int sum, total_tmp = total;

	while (1) {
		sum = 0;
		for (int j = 0; j < num; j++) {
			sum += total_tmp - j;
		}
		
		if (sum == total) {
			for (int j = 0; j < num; j++) {
				answer[j] = total_tmp - (num - 1) + j;
			}
			break;
		}
		total_tmp--;
	}
	return answer;
}