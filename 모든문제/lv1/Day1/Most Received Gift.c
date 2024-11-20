#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findIndex(const char* friends[], size_t friends_len, const char* name) {
	for (size_t i = 0; i < friends_len; i++) {
		if (strcmp(friends[i], name) == 0) {
			return i;
		}
	}
	return -1;
}

int solution(const char* friends[], size_t friends_len, const char* gifts[], size_t gifts_len) {
	int maxPresentCnt = 0;
	int log[50][50] = { 0 };
	int giveCnt[50] = { 0 };
	int receiveCnt[50] = { 0 };

	for (size_t i = 0; i < gifts_len; i++) {
		const char* now = gifts[i];
		char giver[51], receiver[51];

		sscanf(now, "%s %s", giver, receiver);

		int giverIdx = findIndex(friends, friends_len, giver);
		int receiverIdx = findIndex(friends, friends_len, receiver);

		if (giverIdx == -1 || receiverIdx == -1) continue;

		log[giverIdx][receiverIdx]++;

		giveCnt[giverIdx]++;
		giveCnt[receiverIdx]--;
	}

	for (size_t i = 0; i < friends_len; i++) {
		for (size_t j = 0; j < friends_len; j++) {
			if (i == j) continue;

			if (log[i][j] || log[j][i]) {
				if (log[i][j] > log[j][i]) {
					receiveCnt[i]++;
				}
				else if (log[i][j] == log[j][i] && giveCnt[i] > giveCnt[j]) {
					receiveCnt[i]++;
				}
			}
			else {
				if (giveCnt[i] > giveCnt[j]) {
					receiveCnt[i]++;
				}
			}
		}
		if (receiveCnt[i] > maxPresentCnt) {
			maxPresentCnt = receiveCnt[i];
		}
	}

	return maxPresentCnt;
}