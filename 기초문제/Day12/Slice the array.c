#include <stdio.h>
#include <stdlib.h>

int* solution(int arr[], size_t arr_len, int query[], size_t query_len) {
    int* answer = (int*)malloc(arr_len * sizeof(int));
    if (!answer) {
        return NULL;
    }

    for (size_t i = 0; i < arr_len; i++) {
        answer[i] = arr[i];
    }
    size_t current_len = arr_len;

    for (size_t i = 0; i < query_len; i++) {
        if (i % 2 == 0) {
            current_len = query[i] + 1;
        }
        else {
            size_t new_len = current_len - query[i];
            for (size_t j = 0; j < new_len; j++) {
                answer[j] = answer[query[i] + j];
            }
            current_len = new_len;
        }

        answer = (int*)realloc(answer, current_len * sizeof(int));
        if (!answer) {
            return NULL;
        }
    }

    return answer;
}