#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define INF 987654321

int diff[11][11];
int N, M;
int answer = INF;
int vec[11];
int vec_size = 0;

int solve() {
	int ret = 0;
	int temp[11][11];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp[i][j] = diff[i][j];
		}
	}

	for (int i = 0; i < vec_size; i++) {
		int row = vec[i];
		for (int j = 0; j < M; j++) {
			temp[row][j] ^= 1;
		}
		ret++;
	}

	for (int j = 0; j < M; j++) {
		if (temp[0][j] == 1) ret++;
		for (int i = 1; i < N; i++) {
			if (temp[i][j] != temp[0][j]) {
				return INF;
			}
		}
	}

	return ret;
}

void choose(int idx) {
	if (idx == N) {
		int res = solve();
		if (res < answer) {
			answer = res;
		}
		return;
	}

	vec[vec_size++] = idx;
	choose(idx + 1);
	vec_size--;
	choose(idx + 1);
}

int solution(int** beginning, size_t beginning_rows, size_t beginning_cols, int** target, size_t target_rows, size_t target_cols) {
	N = (int)beginning_rows;
	M = (int)beginning_cols;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (beginning[i][j] != target[i][j]) {
				diff[i][j] = 1;
			}
			else {
				diff[i][j] = 0;
			}
		}
	}

	choose(0);

	return (answer == INF) ? -1 : answer;
} 