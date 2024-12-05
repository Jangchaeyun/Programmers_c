#include <stdio.h>

int solution(int storey) {
	int answer = 0;
	
	while (storey > 0) {
		int n = storey % 10;
		storey /= 10;

		if (n < 5) {
			answer += n;
		}
		else if (n > 5) {
			++storey;
			answer += 10 - n;
		}
		else {
			int next_digit = storey % 10;
			if (next_digit >= 5) {
				++storey;
			}
			answer += n;
		}
	}

	return answer;
}