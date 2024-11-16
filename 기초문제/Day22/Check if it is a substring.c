#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(const char* my_string, const char* target) {
	int answer = 0;
	int j = 0;
	for (int i = 0; i < strlen(my_string); i++)
	{
		if (j > 0 && my_string[i] != target[j])
			j = 0;
		if (my_string[i] == target[j]) {
			printf("%c %c %d %d %d %d\n", my_string[i], target[j], i, j, strlen(target));
			j++;
			if (j == strlen(target))
				answer = 1;
		}
	}
	return answer;
}