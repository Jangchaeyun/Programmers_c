#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int solution(int a[], size_t a_len) {
    if (a_len == 1) {
        return 1;
    }

    int* left = (int*)malloc(a_len * sizeof(int));
    int* right = (int*)malloc(a_len * sizeof(int));

    int lMin = a[0];
    int rMin = a[a_len - 1];

    left[0] = a[0];
    for (size_t i = 1; i < a_len - 1; i++) {
        lMin = (lMin < a[i]) ? lMin : a[i];
        left[i] = lMin;
    }

    right[a_len - 1] = a[a_len - 1];
    for (size_t i = a_len - 2; i >= 1; i--) {
        rMin = (rMin < a[i]) ? rMin : a[i];
        right[i] = rMin;
    }

    int answer = 2;

    for (size_t i = 1; i < a_len - 1; i++) {
        if (left[i - 1] < a[i] && right[i + 1] < a[i]) {
            continue;
        }
        answer++;
    }

    free(left);
    free(right);

    return answer;
}
