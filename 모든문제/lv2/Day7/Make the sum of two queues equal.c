#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int queue1[], size_t queue1_len, int queue2[], size_t queue2_len) {
    long long qSum1 = 0, qSum2 = 0;
    int i = 0, j = 0, answer = 0;
    size_t total_len = queue1_len + queue2_len;

    int* combined = (int*)malloc(total_len * sizeof(int));
    for (size_t k = 0; k < queue1_len; k++) {
        combined[k] = queue1[k];
        qSum1 += queue1[k];
    }
    for (size_t k = 0; k < queue2_len; k++) {
        combined[queue1_len + k] = queue2[k];
        qSum2 += queue2[k];
    }

    while (answer <= total_len * 3) {
        if (qSum1 > qSum2) {
            qSum1 -= combined[i % total_len];
            qSum2 += combined[i % total_len];
            i++;
        }
        else if (qSum1 < qSum2) {
            qSum2 -= combined[j % total_len];
            qSum1 += combined[j % total_len];
            j++;
        }
        else {
            free(combined);
            return answer;
        }
        answer++;
    }

    free(combined);
    return -1;
}