#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

char* solution(const char* my_string, const char* alp) {
	char* answer = (char*)malloc(1000 * sizeof(char));
	int j = 0;
	for (int i = 0; i < strlen(my_string); i++) {
		printf("%c %c\n", my_string[i], *alp);
		if (my_string[i] == *alp)
			answer[j++] = toupper(*alp);
		else
			answer[j++] = my_string[i];
	}
	answer[j] = '\0';
	return answer;
}