#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100

bool visited[MAX] = { false };

int compare(const void* a, const void* b) {
	return *(int*)b - *(int*)a;
}

int solution(int cards[], size_t cards_len) {
	int boxCnts[MAX] = { 0 };
	int boxCntIndex = 0;

	for (size_t i = 0; i < cards_len; i++) {
		int cnt = 0;
		int idx = i;

		while (1) {
			if (visited[idx]) {
				if (cnt > 0) {
					boxCnts[boxCntIndex++] = cnt;
				}
				break;
			}
			cnt++;
			visited[idx] = true;
			idx = cards[idx] - 1;
		}
	}

	if (boxCntIndex <= 1) {
		return 0;
	}

	qsort(boxCnts, boxCntIndex, sizeof(int), compare);

	return boxCnts[0] * boxCnts[1];
}