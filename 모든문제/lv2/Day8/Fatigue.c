#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int check[8];
int cnt;

void dfs(int k, int** dungeons, int rows, int n) {
	if (cnt < n) cnt = n;
	for (int i = 0; i < rows && cnt < rows; i++) {
		if (check[i] == 0 && dungeons[i][0] <= k) {
			check[i] = 1;
			dfs(k - dungeons[i][1], dungeons, rows, n + 1);
			check[i] = 0;
		}
	}
}

int solution(int k, int** dungeons, size_t dungeons_rows, size_t dungeons_cols) {
	dfs(k, dungeons, dungeons_rows, 0);
	return cnt;
}