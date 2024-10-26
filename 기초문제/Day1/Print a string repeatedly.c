#include <stdio.h>
#define LEN_INPUT 11

int main(void) {
	char str[11];
	int n;
	scanf("%s %d", str, &n);

	for (int i = 0; i < n; i++) {
		printf("%s", str);
	}

	return 0;
}