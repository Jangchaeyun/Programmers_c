#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char** solution(const char* todo_list[], size_t todo_list_len, bool finished[], size_t finished_len) {
    char** answer = (char**)malloc(todo_list_len * finished_len * sizeof(char*));
    for (int i = 0; i < todo_list_len; i++)
        answer[i] = (char*)malloc(20 * sizeof(char));
    int n = 0;
    int j;
    for (int i = 0; i < finished_len; i++) {
        if (!finished[i]) {
            for (j = 0; j < strlen(todo_list[i]); j++)
                answer[n][j] = todo_list[i][j];
            answer[n][j] = '\0';
            n++;
        }
    }
    return answer;
}