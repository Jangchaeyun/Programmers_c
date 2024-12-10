#include <stdio.h>

int gcd(int w, int h) {
	int c;
	while (h != 0) {
		c = w % h;
		w = h;
		h = c;
	}
	return w;
}

long long solution(int w, int h) {
	long long answer = 0;
	answer = (long long)w * (long long)h - (w + h - gcd(w, h));
	return answer;
}