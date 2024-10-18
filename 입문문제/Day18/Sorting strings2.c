#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* my_string) {
    char* answer = (char*)malloc(strlen(my_string));
    char tmp;
    int i;
    for (i = 0; i < strlen(my_string); i++)
        answer[i] = tolower(my_string[i]);
    answer[i] = '\0';
    for (int j = 0; j < strlen(my_string) - 1; j++)
        for (int k = j + 1; k < strlen(my_string); k++) {
            if (answer[j] > answer[k])
            {
                tmp = answer[j];
                answer[j] = answer[k];
                answer[k] = tmp;
            }
        }
    return answer;
}