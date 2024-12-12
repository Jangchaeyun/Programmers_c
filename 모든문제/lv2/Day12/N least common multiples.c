#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int arr[], size_t arr_len)
{
	int answer, num;

	answer = arr[0];
	for (int i = 1; i < arr_len; i++) {
		num = answer;
		while (num % arr[i] != 0) {
			num += answer;
		}
		answer = num;
	}

	return answer;
}