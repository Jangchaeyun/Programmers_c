#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool contains(int* unique_values, int unique_count, int value) {
    for (int i = 0; i < unique_count; i++) {
        if (unique_values[i] == value) return true;
    }
    return false;
}

void add_unique(int* unique_values, int* unique_count, int value) {
    if (!contains(unique_values, *unique_count, value)) {
        unique_values[*unique_count] = value;
        (*unique_count)++;
    }
}

int solution(int elements[], size_t elements_len) {
    int answer = 0;
    int* unique_values = (int*)malloc(1000000 * sizeof(int));
    int unique_count = 0;

    for (size_t i = 0; i < elements_len; ++i) {
        int sum = 0;
        for (size_t j = 0; j < elements_len; ++j) {
            size_t idx = (i + j) % elements_len;
            sum += elements[idx];
            add_unique(unique_values, &unique_count, sum);
        }
    }

    answer = unique_count;

    free(unique_values);
    return answer;
}