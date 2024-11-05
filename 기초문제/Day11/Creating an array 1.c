#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n, int k) {
    int count = n / k;
    int* answer = (int*)malloc(count * sizeof(int));

    for (int i = 0; i < count; i++) {
        answer[i] = k * (i + 1);
    }

    return answer;
}
