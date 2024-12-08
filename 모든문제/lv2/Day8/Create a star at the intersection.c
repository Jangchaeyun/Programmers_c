#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long point[1000000][2];
int len;

char** solution(int** line, size_t line_rows, size_t line_cols) {
	long long left, right, top, bottom;
	left = bottom = 10000000000;
	right = top = -10000000000;
	long long num, tmp;
	double numX, numY;
	for (int i = 0; i < line_rows - 1; i++) {
		for (int j = i + 1; j < line_rows; j++) {
			num = (long long)line[i][0] * line[j][1] - (long long)line[i][1] * line[j][0];
			if (num == 0) continue;
			else {
				tmp = (long long)line[i][1] * line[j][2] - (long long)line[i][2] * line[j][1];
				numX = (double)tmp / num;
				tmp = (long long)line[i][2] * line[j][0] - (long long)line[i][0] * line[j][2];
				numY = (double)tmp / num;
				if (numX == (long long)numX && numY == (long long)numY) {
					point[len][0] = numX;
					point[len++][1] = numY;
					if (left > point[len - 1][0]) left = point[len - 1][0];
					if (right < point[len - 1][0]) right = point[len - 1][0];
					if (top < point[len - 1][1]) top = point[len - 1][1];
					if (bottom > point[len - 1][1]) bottom = point[len - 1][1];
				}
			}
		}
	}

	int height, width;
	height = top - bottom + 1;
	width = right - left + 1;

	char** answer = (char**)malloc(sizeof(char*) * height);
	char* ch;
	for (int i = 0; i < height; i++) {
		ch = (char*)malloc(width + 1);
		for (int j = 0; j < width; j++) ch[j] = '.';
		ch[width] = '\0';
		answer[i] = ch;
	}
	int x, y;
	for (int i = 0; i < len; i++) {
		x = point[i][0] - left;
		y = top - point[i][1];
		answer[y][x] = '*';
	}

	return answer;
}