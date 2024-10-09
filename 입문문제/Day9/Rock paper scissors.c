#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>=

char* solution(const char* rsp) {
    int len = strlen(rsp);
    char* answer = (char*)malloc(rsp + 1);
    for (int i = 0; i < len; i++)
    {
        if (rsp[i] == '2')
        {
            answer[i] = '0';
        }
        else if (rsp[i] == '0')
        {
            answer[i] = '5';
        }
        else
        {
            answer[i] = '2';
        }
    }
    answer[len] = NULL;
    return answer;
}