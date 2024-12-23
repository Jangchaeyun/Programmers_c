#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(int a[], size_t a_len) {
    int answer = 0;

    int max_value = 0;
    for (size_t i = 0; i < a_len; ++i) {
        if (a[i] > max_value) {
            max_value = a[i];
        }
    }

    int* cnt = (int*)calloc(max_value + 1, sizeof(int));
    for (size_t i = 0; i < a_len; ++i) {
        cnt[a[i]]++;
    }

    for (int i = 0; i <= max_value; ++i) {
        if (cnt[i] <= answer) {
            continue;
        }
        int result = 0;

        for (size_t j = 0; j < a_len - 1; ++j) {
            if ((a[j] == i || a[j + 1] == i) && a[j] != a[j + 1]) {
                result++;
                j++;
            }
        }

        if (result > answer) {
            answer = result;
        }
    }

    free(cnt);

    return answer * 2;
}