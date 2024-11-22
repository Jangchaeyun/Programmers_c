#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {

    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}

int* solution(int k, int score[], size_t score_len) {
    int* answer = (int*)malloc(sizeof(int) * score_len);

    int arr[100] = { 0, };
    for (int i = 0; i < 100; i++) {
        arr[i] = 2001;
    }

    for (int i = 0; i < k; i++) {
        if (i >= score_len) break;
        arr[i] = score[i];
        qsort(arr, i + 1, sizeof(int), compare);
        answer[i] = arr[0];
        printf("%d\n", answer[i]);
    }

    for (int i = k; i < score_len; i++) {
        if (score[i] > arr[0]) {
            arr[0] = score[i];
            qsort(arr, k, sizeof(int), compare);
        }
        answer[i] = arr[0];
    }

    return answer;
}