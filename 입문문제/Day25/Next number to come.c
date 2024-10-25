#include <stdio.h>
#include <stdlib.h>

int solution(int common[], size_t common_len) {
	int answer = 0;
	size_t n = common_len;

    if (common[n - 1] - common[n - 2] == common[n - 2] - common[n - 3]) {
        answer = common[n - 1] + (common[n - 1] - common[n - 2]);
    }

    else if (common[n - 1] / common[n - 2] == common[n - 2] / common[n - 3]) {
        answer = common[n - 1] * (common[n - 1] / common[n - 2]);
    }

    return answer;
}