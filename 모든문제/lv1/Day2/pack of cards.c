#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* cards1[], size_t cards1_len, const char* cards2[], size_t cards2_len, const char* goal[], size_t goal_len) {
	char* answer = (char*)malloc(1);

	bool isCard;

	int c1 = 0, c2 = 0;
	for (int i = 0; i < goal_len; i++) {
		isCard = false;
		if (c1 != cards1_len && strcmp(goal[i], cards1[c1]) == 0) {
			isCard = true;
			c1++;
		}
		if (isCard == true) continue;
		if (c2 != cards2_len && strcmp(goal[i], cards2[c2]) == 0) {
			isCard = true;
			c2++;
		}
		if (isCard == false) {
			break;
		}
	}
	if (isCard) answer = "Yes";
	else answer = "No";

	return answer;
}