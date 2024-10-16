#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* my_string, int num1, int num2) {
	char* answer = (char*)malloc(my_string);
	char arr[2];

	arr[0] = my_string[num1];
	arr[1] = my_string[num2];

	answer = my_string;

	answer[num1] = arr[1];
	answer[num2] = arr[0];

	return answer;
}