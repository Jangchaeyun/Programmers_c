#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char** solution(const char* my_string) {
    char** answer = (char**)malloc(strlen(my_string) * sizeof(char*));
    for (int i = 0; i < strlen(my_string); i++)
        answer[i] = (char*)malloc(sizeof(char) * 1000);
    int i = 0;
    int n, m;
    n = 0;
    m = 0;
    while (1) {
        if (i > 0 && m > 0 && my_string[i] == ' ' && my_string[i - 1] != ' ') {
            answer[n][m] = '\0';
            n++;
            m = 0;
        }
        if (my_string[i] != ' ')
            answer[n][m++] = my_string[i];
        i++;
        if (my_string[i] == '\0') {
            answer[n][m] = '\0';
            break;
        }
    }
    return answer;
}