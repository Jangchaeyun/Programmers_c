#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int emo = 0;
int price = 0;
int vec[7];
int arr[4] = { 10, 20, 30, 40 };

void dfs(int** users, size_t users_rows, int* emoticons, size_t emoticons_len, int depth) {
	if (depth == emoticons_len) {
		int emo_tmp = 0;
		int price_tmp = 0;

		for (size_t i = 0; i < users_rows; i++) {
			int p = 0;

			for (size_t j = 0; j < emoticons_len; j++) {
				if (users[i][0] <= vec[j]) {
					p += emoticons[j] * (100 - vec[j]) / 100;
				}
			}
			if (p >= users[i][1]) {
				emo_tmp++;
			}
			else {
				price_tmp += p;
			}
		}

		if (emo < emo_tmp || (emo == emo_tmp && price < price_tmp)) {
			emo = emo_tmp;
			price = price_tmp;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		vec[depth] = arr[i];
		dfs(users, users_rows, emoticons, emoticons_len, depth + 1);
	}
}

int* solution(int** users, size_t users_rows, size_t users_cols, int emoticons[], size_t emoticons_len) {
	emo = 0;
	price = 0;
	memset(vec, 0, sizeof(vec));

	dfs(users, users_rows, emoticons, emoticons_len, 0);

	int* answer = (int*)malloc(2 * sizeof(int));
	answer[0] = emo;
	answer[1] = price;
	return answer;
}