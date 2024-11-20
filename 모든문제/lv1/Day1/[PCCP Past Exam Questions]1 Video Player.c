#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getTime(const char* str) {
	int hour, minute;
	sscanf(str, "%d:%d", &hour, &minute);
	return hour * 60 + minute;
}

char* solution(const char* video_len, const char* pos, const char* op_start, const char* op_end, const char* commands[], size_t commands_len) {
	int maxTime = getTime(video_len);
	int opStartTime = getTime(op_start);
	int opEndTime = getTime(op_end);
	int currTime = getTime(pos);

	if (opStartTime <= currTime && currTime <= opEndTime)
		currTime = opEndTime;

	for (size_t i = 0; i < commands_len; i++) {
		if (strcmp(commands[i], "next") == 0)
			currTime += 10;
		else if (strcmp(commands[i], "prev") == 0)
			currTime -= 10;

		if (currTime < 0)
			currTime = 0;
		else if (currTime > maxTime)
			currTime = maxTime;

		if (opStartTime <= currTime && currTime <= opEndTime)
			currTime = opEndTime;
	}

	char* answer = (char*)malloc(6);
	snprintf(answer, 6, "%02d:%02d", currTime / 60, currTime % 60);
	return answer;
}