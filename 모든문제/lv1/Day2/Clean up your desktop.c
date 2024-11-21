#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(const char* wallpaper[], size_t wallpaper_len) {
	int minY = 50, maxY = 0, minX = 50, maxX = 0;
	int len = strlen(wallpaper[0]);
	int* answer = (int*)malloc(sizeof(1));

	for (int i = 0; i < wallpaper_len; i++) {
		for (int j = 0; j < len; j++) {
			if (wallpaper[i][j] == '#') {
				if (minY > j) minY = j;
				if (maxY < j) maxY = j;
				if (minX > i) minX = i;
				if (maxX < i) maxX = i;
			}
		}
	}

	answer[0] = minX;
	answer[1] = minY;
	answer[2] = maxX + 1;
	answer[3] = maxY + 1;
	.

	return answer;
}