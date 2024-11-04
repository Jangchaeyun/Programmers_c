#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* my_string) {
    int len = strlen(my_string);
    char* answer = (char*)malloc(len + 1);
    int x = 0;
    for (int i = len; i > 0; i--)
    {
        answer[x] = my_string[i - 1];
        x++;
    }
    answer[x] = NULL;
    return answer;
}