#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* survey[], size_t survey_len, int choices[], size_t choices_len) {
	char str[4] = { 'R', 'C', 'J', 'A' };
	char* answer = (char*)malloc(5);
	int scores[4] = { 0 };

	for (int i = 0; i < survey_len; i++) {
		for (int j = 0; j < 4; j++) {
			if (survey[i][0] == str[j]) {
				scores[j] += 4 - choices[i];
				break;
			}
			if (survey[i][1] == str[j]) {
				scores[j] += choices[i] - 4;
				break;
			}
		}
	}
	
	answer[0] = (scores[0] >= 0) ? 'R' : 'T';
	answer[1] = (scores[1] >= 0) ? 'C' : 'F';
	answer[2] = (scores[2] >= 0) ? 'J' : 'M';
	answer[3] = (scores[3] >= 0) ? 'A' : 'N';
	answer[4] = '\0';

	return answer;
}