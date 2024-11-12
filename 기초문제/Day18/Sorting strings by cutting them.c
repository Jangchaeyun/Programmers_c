#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

char** solution(const char* myString) {
    int length = strlen(myString);
    char** answer = (char**)malloc(sizeof(char*) * length);
    char temp[length + 1];
    int tempIndex = 0;
    int count = 0;

    for (int i = 0; i <= length; ++i) {
        if (myString[i] != 'x' && myString[i] != '\0') {
            temp[tempIndex++] = myString[i];
        }
        else {
            if (tempIndex > 0) {
                temp[tempIndex] = '\0';
                answer[count] = (char*)malloc(strlen(temp) + 1);
                strcpy(answer[count], temp);
                count++;
                tempIndex = 0;
            }
        }
    }

    qsort(answer, count, sizeof(char*), compare);

    return answer;
}