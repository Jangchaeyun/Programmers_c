#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

bool dfs(int64_t v, const bool* number, int32_t level) {
    if (v % 2 == 1) {
        return true;
    }

    long long pow = 1 << level;
    int left = v - pow / 2;
    int right = v + pow / 2;

    bool left_ret = dfs(left, number, level - 1);
    bool right_ret = dfs(right, number, level - 1);
    bool child = left_ret && right_ret;

    if (!child) {
        return false;
    }

    if (!number[v - 1]) {
        bool left_res = number[left - 1];
        bool right_res = number[right - 1];

        return !(left_res || right_res);
    }

    return true;
}

int* solution(long long numbers[], size_t numbers_len) {
    int* answer = (int*)malloc(numbers_len * sizeof(int));

    for (size_t i = 0; i < numbers_len; i++) {
        long long n = numbers[i];
        long long pow = 1;
        int length = 0;
        long long root = 1;
        int level = 0;

        while (n > pow) {
            pow *= 2;
            length += 1;
        }

        while (length >= root * 2) {
            root *= 2;
            level += 1;
        }

        bool* boolNum = (bool*)calloc(root * 2, sizeof(bool));
        for (int j = 0; j <= length; j++) {
            boolNum[j] = n % 2;
            n /= 2;
        }

        answer[i] = dfs(root, boolNum, level);
        free(boolNum);
    }

    return answer;
}
