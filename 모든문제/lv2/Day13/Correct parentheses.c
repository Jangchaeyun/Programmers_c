#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(const char* s) {
	int count = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == '(') count++;
		else {
			if (count == 0) return false;
			else count--;
		}
	}
	return (count == 0) ? true : false;
}