#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* solution(int numLog[], size_t numLog_len) {
	char* answer = (char*)malloc(numLog_len * sizeof(char));
	int answer_index = 0;

    for (size_t i = 1; i < numLog_len; ++i) {
        if (numLog[i] - numLog[i - 1] == 1) {
            answer[answer_index++] = 'w';
        }
        else if (numLog[i] - numLog[i - 1] == -1) {
            answer[answer_index++] = 's';
        }
        else if (numLog[i] - numLog[i - 1] == 10) {
            answer[answer_index++] = 'd';
        }
        else if (numLog[i] - numLog[i - 1] == -10) {
            answer[answer_index++] = 'a';
        }
    }

    answer[answer_index] = '\0';
    return answer;
}