#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int arr[], size_t arr_len) {
    int* answer = (int*)malloc(1000 * 2 * sizeof(int));
    int cnt = 2;
    int i;
    while (1) {
        if (cnt >= arr_len) break;
        cnt *= 2;
    }
    for (i = 0; i < arr_len; i++)
        answer[i] = arr[i];
    if (cnt != arr_len)
        for (i = arr_len; i <= cnt; i++)
            answer[i] = 0;
    answer[i] = '\0';

    return answer;
}