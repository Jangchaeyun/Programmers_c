#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int car[10000][2];
int time[10000][3];

int toInteger(char* str, int start, int n) {
	int num = 0;
	str += start;
	for (int i = n - 1, ten = 1; i >= 0; i--, ten *= 10) {
		num += (str[i] - '0') * ten;
	}
	return num;
}

int* solution(int fees[], size_t fees_len, const char* records[], size_t records_len) {
	int h, m, num;
	int count = 0;
	int max = 0;

	for (int i = 0; i < records_len; i++) {
		h = toInteger(records[i], 0, 2);
		m = toInteger(records[i], 3, 2);
		num = toInteger(records[i], 6, 4);
		if (max < num) max = num;

		if (records[i][11] == 'I') {
			if (car[num][0] == 0) {
				car[num][0] = 1;
				count++;
			}
			car[num][1] = 1;
			time[num][0] = h;
			time[num][1] = m;
		}
		else {
			car[num][1] = 0;
			if (time[num][0] == h) {
				time[num][2] += m - time[num][1];
			}
			else {
				time[num][2] += (60 - time[num][1]) + (h - (time[num][0] + 1)) * 60 + m;
			}
		}
	}

	int* answer = (int*)malloc(count * sizeof(int));
	int len = 0;

	for (int i = 0; i <= max; i++) {
		if (car[i][1] == 1) {
			time[i][2] += (59 - time[i][1]) + (24 - (time[i][0] + 1)) * 60;
		}
		if (car[i][0] == 1) {
			if (time[i][2] <= fees[0]) {
				answer[len++] = fees[1];
			}
			else {
				double d = (double)(time[i][2] - fees[0]) / fees[2];
				if (d > (int)d) d = (int)d + 1;
				answer[len++] = fees[1] + d * fees[3];
			}
		}
	}

	return answer;
}