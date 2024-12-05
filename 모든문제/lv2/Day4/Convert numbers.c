#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int x, int y, int n) {
	int answer = 0;
	int DP[1000001];

	for (int i = 0; i < 1000001; i++) {
		DP[i] = 1000001;
	}
	DP[y] = 0;

	for (int i = y; i > x; i--) {
		if (DP[i] != 1000001) {
			if (i % 3 == 0) {
				DP[i / 3] = DP[i / 3] < (DP[i] + 1) ? DP[i / 3] : (DP[i] + 1);
			}
			if (i % 2 == 0) {
				DP[i / 2] = DP[i / 2] < (DP[i] + 1) ? DP[i / 2] : (DP[i] + 1);
			}
			if (i - n > 0) {
				DP[i - n] = DP[i - n] < (DP[i] + 1) ? DP[i - n] : (DP[i] + 1);
			}
		}
	}

	if (DP[x] == 1000001) {
		DP[x] = -1;
	}
	answer = DP[x];
	return answer;
}