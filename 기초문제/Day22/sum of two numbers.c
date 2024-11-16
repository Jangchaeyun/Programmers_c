#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverse_string(const char* str) {
	int len = strlen(str);
	char* reversed = (char*)malloc(len + 1);
	for (int i = 0; i < len; i++) {
		reversed[i] = str[len - 1 - i];
	}
	reversed[len] = '\0';
	return reversed;
}

char* solution(const char* a, const char* b) {
	char* a_reversed = reverse_string(a);
	char* b_reversed = reverse_string(b);

	int a_len = strlen(a_reversed);
	int b_len = strlen(b_reversed);
	int max_len = a_len > b_len ? a_len : b_len;

	char* answer = (char*)malloc(max_len + 2);
	int carry = 0, i = 0;

	while (i < a_len || i < b_len || carry) {
		int digit_a = (i < a_len) ? a_reversed[i] - '0' : 0;
		int digit_b = (i < b_len) ? b_reversed[i] - '0' : 0;

		int sum = digit_a + digit_b + carry;
		carry = sum / 10;
		answer[i] = (sum % 10) + '0';

		i++;
	}

	answer[i] = '\0';
	free(a_reversed);
	free(b_reversed);

	char* final_answer = reverse_string(answer);
	free(answer);

	return final_answer;
}