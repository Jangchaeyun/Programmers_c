#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(const char* keyinput[], size_t keyinput_len, int board[], size_t board_len) {
	int* answer = (int*)malloc(1);

	int left = -(board[0] / 2);
	int right = board[0] / 2;
	int up = board[1] / 2;
	int down = -(board[1] / 2);

	int x = 0, y = 0;

	for (int i = 0; i < keyinput_len; i++) {
		if (strcmp(keyinput[i], "left") == 0) {
			x--;
			if (x < left) x = left;
		}
		else if (strcmp(keyinput[i], "right") == 0) {
			x++;
			if (x > right) x = right;
		}
		else if (strcmp(keyinput[i], "up") == 0) {
			y++;
			if (y > up) y = up;
		}
		else if (strcmp(keyinput[i], "down") == 0) {
			y--;
			if (y < down) y = down;
		}
	}
	answer[0] = x;
	answer[1] = y;

	return answer;
}