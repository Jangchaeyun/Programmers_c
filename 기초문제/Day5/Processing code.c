#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* code) {
    char* answer = (char*)malloc(strlen(code) + 1);
    int mode = 0;
    int i, j;
    for (i = 0, j = 0; i < strlen(code); i++) {
        if (mode == 1) {
            if (code[i] != '1') {
                if (i % 2) {
                    answer[j] = code[i];
                    j++;
                }

            }
            else { mode = 0; }
        }
        else if (mode == 0) {
            if (code[i] != '1') {
                if (i % 2 == 0) {
                    answer[j] = code[i];
                    j++;
                }
            }
            else { mode = 1; }
        }
    }
    answer[j] = '\0';
    if (j == 0) { return "EMPTY"; }
    return answer;
}