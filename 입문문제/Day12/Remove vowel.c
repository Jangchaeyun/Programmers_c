#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* my_string) {
	char* answer = (char*)calloc(1, sizeof(char));
	int k = 0;
	for (int i = 0; i < strlen(my_string); i++) {
		if (my_string[i] == 'a' || my_string[i] == 'e' || my_string[i] == 'u' || my_string[i] == 'o' || my_string[i] == 'i') {
			answer[k] = my_string[i + 1];
		}
		else {
			answer[k] = my_string[i];
			k++;
		}
	}
	return answer;
}