#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b, int c) {
	int answer = 0;
    if (a != b && b != c && a != c) {
        answer = a + b + c;
    }
    else if ((a == b && b != c) || (b == c && b != a) || (a == c && c != b)) {
        answer = (a + b + c) * (a * a + b * b + c * c);
    }
    else if (a == b && b == c) {
        answer = (a + b + c) * (a * a + b * b + c * c) * (a * a * a + b * b * b + c * c * c);
    }
    return answer;
}