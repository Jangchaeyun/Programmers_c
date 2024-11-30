#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* s)
{
	char* answer = (char*)malloc(3);
	int len = strlen(s);
	s += len / 2;

	if (len % 2 == 0)
	{
		s--;
		strncpy(answer, s, 2);
		answer[2] = '\0';
	}
	else
	{
		strncpy(answer, s, 1);
		answer[1] = '\0';
	}
	return answer;
}