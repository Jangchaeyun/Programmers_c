#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* solution(const char* X, const char* Y) {
    int countX[10] = { 0 };
    int countY[10] = { 0 };

    for (int i = 0; X[i] != '\0'; i++) {
        countX[X[i] - '0']++;
    }

    for (int i = 0; Y[i] != '\0'; i++) {
        countY[Y[i] - '0']++;
    }

    char* answer = (char*)malloc(1001); 
    int index = 0;

    for (int i = 9; i >= 0; i--) {
        int num = countX[i] < countY[i] ? countX[i] : countY[i];
        for (int j = 0; j < num; j++) {
            answer[index++] = i + '0';
        }
    }

    answer[index] = '\0';

    if (index == 0) {
        free(answer);
        answer = (char*)malloc(3);
        strcpy(answer, "-1");
    }
    else if (answer[0] == '0') {
        free(answer);
        answer = (char*)malloc(2);
        strcpy(answer, "0");
    }

    return answer;
}
