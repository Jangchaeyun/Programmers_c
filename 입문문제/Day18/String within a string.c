#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(const char* str1, const char* str2) {
	int str1_len = strlen(str1);
	int str2_len = strlen(str2);
	for (int i = 0; i < str1_len; i++)
	{
		int x;
		for (x = 0; x < str2_len; x++) {
			if (str1[i + x] != str2[x])
				break;
		}
		if (x == str2_len)
			return 1;
	}
	return 2;
}