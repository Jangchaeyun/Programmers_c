#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char** solution(const char* str_list[], size_t str_list_len) {
    char** answer = (char**)malloc(str_list_len * sizeof(char*));
    if (answer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    for (size_t i = 0; i < str_list_len; i++) {
        size_t str_len = strlen(str_list[i]) + 1;
        answer[i] = (char*)malloc(str_len * sizeof(char));
        if (answer[i] == NULL) {
            for (size_t j = 0; j < i; j++) {
                free(answer[j]);
            }
            free(answer);
            fprintf(stderr, "Memory allocation failed\n");
            return NULL;
        }
        strcpy(answer[i], str_list[i]); 
    }

    return answer;
}