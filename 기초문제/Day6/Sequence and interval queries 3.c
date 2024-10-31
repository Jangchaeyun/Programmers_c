#include <stdio.h>
#include <stdlib.h>

int* solution(int arr[], size_t arr_len, int** queries, size_t queries_rows, size_t queries_cols) {
    int* answer = (int*)malloc(arr_len * sizeof(int));
    for (size_t i = 0; i < arr_len; i++) {
        answer[i] = arr[i];
    }

    for (size_t i = 0; i < queries_rows; ++i) {
        int temp = answer[queries[i][0]];
        answer[queries[i][0]] = answer[queries[i][1]];
        answer[queries[i][1]] = temp;
    }

    return answer;
}