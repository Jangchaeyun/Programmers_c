#include <stdio.h>

int solution(int** dots, size_t dots_rows, size_t dots_cols) {
	int answer = 0, a, b;
	for (int i = 0; i < dots_rows; i++) {
		for (int j = i; j < dots_rows; j++) {
			if (dots[i][0] == dots[j][0] && i != j) {
				b = (dots[i][1] - dots[j][1]);

				if (b < 0) {
					b *= -1;
				}
			}
			if (dots[i][0] != dots[j][0]) {
				a = (dots[i][0] - dots[j][0]);

				if (a < 0) {
					a *= -1;
				}
			}
		}
	}

	answer = a * b;
	return answer;
}