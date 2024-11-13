#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char** solution(const char* myStr) {
    char** answer = NULL;
    int answerSize = 0;
    char temp[1000] = { 0 };
    int tempIndex = 0;

    for (int i = 0; myStr[i] != '\0'; ++i) {
        if (myStr[i] != 'a' && myStr[i] != 'b' && myStr[i] != 'c') {
            temp[tempIndex++] = myStr[i];
        }
        else if (tempIndex > 0) {
            temp[tempIndex] = '\0';
            answer = (char**)realloc(answer, (answerSize + 1) * sizeof(char*));
            answer[answerSize] = (char*)malloc((tempIndex + 1) * sizeof(char));
            strcpy(answer[answerSize], temp);
            answerSize++;
            tempIndex = 0;
        }
    }

    if (tempIndex > 0) {
        temp[tempIndex] = '\0';
        answer = (char**)realloc(answer, (answerSize + 1) * sizeof(char*));
        answer[answerSize] = (char*)malloc((tempIndex + 1) * sizeof(char));
        strcpy(answer[answerSize], temp);
        answerSize++;
    }

    if (answerSize == 0) {
        answer = (char**)malloc(sizeof(char*));
        answer[0] = (char*)malloc(6 * sizeof(char));
        strcpy(answer[0], "EMPTY");
        answerSize = 1;
    }

    answer = (char**)realloc(answer, (answerSize + 1) * sizeof(char*));
    answer[answerSize] = NULL;

    return answer;
}