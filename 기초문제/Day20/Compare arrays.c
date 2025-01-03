#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int arr1[], size_t arr1_len, int arr2[], size_t arr2_len) {
	int answer = 0;
	int sum1 = 0;
	int sum2 = 0;
	if (arr1_len != arr2_len) {
		if (arr1_len > arr2_len)
			answer = 1;
		else if (arr1_len < arr2_len)
			answer = -1;
		else
			answer = 0;
	}
	else {
		for (int i = 0; i < arr1_len; i++)
			sum1 += arr1[i];
		for (int j = 0; j < arr2_len; j++)
			sum2 += arr2[j];
		if (sum1 > sum2)
			answer = 1;
		else if (sum1 < sum2)
			answer = -1;
		else
			answer = 0;
	}
	return answer;
}