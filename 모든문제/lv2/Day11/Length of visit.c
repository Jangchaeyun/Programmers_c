#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int area[11][11][4];

int solution(const char* dirs) {
	int x = 5, y = 5, m;
	int x1 = 5, y1 = 5, m1;
	int n = 0;

	for (int i = 0; dirs[i] != '\0'; i++) {
		char s = dirs[i];
		if (s == 'U' && y < 10) {
			y++;
			m = 1;
			m1 = 0;
		}
		else if (s == 'D' && y > 0) {
			y--;
			m = 0;
			m1 = 1;
		}
		else if (s == 'R' && x < 10) {
			x++;
			m = 3;
			m1 = 2;
		}
		else if (s == 'L' && x > 0) {
			x--;
			m = 2;
			m1 = 3;
		}
		else continue;

		if (area[y1][x1][m1] == 0) {
			area[y1][x1][m1] = 1;
			area[y][x][m] = 1;
			n++;
		}

		x1 = x;
		y1 = y;
	}

	return n;
}