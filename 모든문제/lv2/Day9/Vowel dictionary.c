#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int func(const char* word, int n)
{
	char alpha[6] = { "AEIOU" };
	int cnt = 0;
	for (int i = 0; i < 5; i++)
	{
		if (word[n] == alpha[i])
		{
			if (word[n + 1] != '\0') {
				cnt += func(word, n + 1);
			}
			cnt += 1;
			break;
		}
		else {
			for (int j = 0, d = 1; j < 5 - n; j++, d *= 5) {
				cnt += d;
			}
		}
	}
	return cnt;
}


int solution(const char* word) {
	return func(word, 0);
}