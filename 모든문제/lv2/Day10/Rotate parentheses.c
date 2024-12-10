#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int stack[501];

int solution(const char* s)
{
	int answer = 0;
	int len = strlen(s);
	int n;
	char ch;
	bool t;

	for (int i = 0; i < len; i++) {
		n = -1;
		t = true;
		for (int j = i; j < len; j++) {
			ch = s[j];
			if (ch == '(') stack[++n] = 1;
			else if (ch == '{') stack[++n] = 2;
			else if (ch == '[') stack[++n] = 3;
			else if (ch == ')' && stack[n] == 1) n--;
			else if (ch == '}' && stack[n] == 2) n--;
			else if (ch == ']' && stack[n] == 3) n--;
			else {
				t = false;
				break;
			}
		}
		for (int j = 0; j < i && t == true; j++) {
			ch = s[j];
			if (ch == '(') stack[++n] = 1;
			else if (ch == '{') stack[++n] = 2;
			else if (ch == '[') stack[++n] = 3;
			else if (ch == ')' && stack[n] == 1) n--;
			else if (ch == '}' && stack[n] == 2) n--;
			else if (ch == ']' && stack[n] == 3) n--;
			else {
				t = false;
				break;
			}
		}

		if (t == true && n == -1) answer++;
	}

	return answer;
}