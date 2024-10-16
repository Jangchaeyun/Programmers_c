#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(const char* my_string) {
	int answer = 0;
	int i = 0;
	int num1 = 0;
	int num2 = 0;
	char op;
	while (1) {
		num1 = num1 * 10 + my_string[i] - '0';
		i++;
		if (my_string[i] == ' ') break;
	}

	while (my_string[i] != '\0') {
		i++;
		op = my_string[i];
		i += 2;
		while (1) {
			num2 = num2 * 10 + my_string[i] - '0';
			i++;
			if (my_string[i] == ' ' || my_string[i] == '\0') break;
		}
		printf("%d %d %c\n", num1, num2, op);
		if (op == '+') answer = num1 + num2;
		if (op == '-') answer = num1 - num2;
		num2 = 0;
		num1 = answer;
	}
	return answer;
}