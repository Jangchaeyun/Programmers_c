#include <stdio.h>
#include <stdlib.h>

int* solution(int num_list[], size_t num_list_len) {
    int l_size = num_list_len - 1;
    int* answer = (int*)malloc((num_list_len + 1) * sizeof(int));

    for (size_t i = 0; i < num_list_len; i++) {
        answer[i] = num_list[i];
    }

    if (num_list[l_size] > num_list[l_size - 1]) {
        answer[num_list_len] = num_list[l_size] - num_list[l_size - 1];
    }
    else {
        answer[num_list_len] = num_list[l_size] * 2;
    }

    return answer;
}