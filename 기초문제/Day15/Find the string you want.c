#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

int solution(const char* myString, const char* pat) {
	int answer = 0;
	int j = 0;
	for (int i = 0; i < strlen(myString); i++) {
		if (tolower(myString[i]) == tolower(pat[j])) {
			j++;
			if (j == strlen(pat))
			{
				answer = 1;
				break;
			}
		}
		else {
			if (j > 0)
				j = 0;
		}
	}
	return answer;
}