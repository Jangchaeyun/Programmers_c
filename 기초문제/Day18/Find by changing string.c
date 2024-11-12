#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(const char* myString, const char* pat) {
	int answer = 0;
	char* num = malloc(strlen(myString));
	int i;
	for (i = 0; i < strlen(myString); i++)
	{
		if (myString[i] == 'A')
			num[i] = 'B';
		else
			num[i] = 'A';
	}
	if (strstr(num, pat))
		answer = 1;
	else
		answer = 0;
	return answer;
}