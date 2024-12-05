#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

int solution(int k, int tangerine[], size_t tangerine_len) {
    int* v = (int*)calloc(10000001, sizeof(int));
    int answer = 0;

    if (v == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return -1;
    }

    for (size_t i = 0; i < tangerine_len; i++) {
        v[tangerine[i]]++;
    }

    int* frequencies = (int*)malloc(tangerine_len * sizeof(int));
    size_t freq_len = 0;

    for (int i = 0; i <= 10000000; i++) {
        if (v[i] > 0) {
            frequencies[freq_len++] = v[i];
        }
    }

    qsort(frequencies, freq_len, sizeof(int), compare);

    for (size_t i = 0; i < freq_len; i++) {
        k -= frequencies[i];
        answer++;
        if (k <= 0) {
            break;
        }
    }

    free(v);
    free(frequencies);

    return answer;
}