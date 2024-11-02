#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char* solution(const char* my_string, int** queries, size_t queries_rows,
    size_t queries_cols) {
    int len = strlen(my_string);
    char* answer = (char*)malloc(len + 1);
    strcpy(answer, my_string);

    for (int i = 0; i < queries_rows; i++) {
        int a = queries[i][0];
        int b = queries[i][1];

        for (int j = 0; j <= (b - a) / 2; j++) {
            int temp = answer[a + j];
            answer[a + j] = answer[b - j];
            answer[b - j] = temp;
        }
    }
    return answer;
}