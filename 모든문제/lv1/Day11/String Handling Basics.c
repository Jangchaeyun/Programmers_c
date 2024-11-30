#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool solution(const char* s)
{
	if (strlen(s) == 4 || strlen(s) == 6)
	{
		int i;
		for (i = 0; i < strlen(s); i++)
		{
			if (s[i] < '0' || s[i] > '9')
			{
				break;
			}
		}
		if (i == strlen(s)) return true;
	}
	return false;
}