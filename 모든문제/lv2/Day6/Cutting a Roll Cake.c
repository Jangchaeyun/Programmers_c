#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int find_max(int arr[], size_t len) {
    int max_val = arr[0];
    for (size_t i = 1; i < len; i++) {
        if (arr[i] > max_val) max_val = arr[i];
    }
    return max_val;
}

int solution(int topping[], size_t topping_len) {
    int answer = 0;

    int max_topping = find_max(topping, topping_len);
    int* brother = (int*)calloc(max_topping + 1, sizeof(int));
    int* cheolsu = (int*)calloc(max_topping + 1, sizeof(int));

    int brotherCount = 0, cheolsuCount = 0;

    for (size_t i = 0; i < topping_len; i++) {
        if (brother[topping[i]] == 0) {
            brotherCount++;
        }
        brother[topping[i]]++;
    }

    for (size_t i = 0; i < topping_len; i++) {
        if (cheolsu[topping[i]] == 0) {
            cheolsuCount++;
        }
        cheolsu[topping[i]]++;

        brother[topping[i]]--;
        if (brother[topping[i]] == 0) {
            brotherCount--;
        }

        if (cheolsuCount == brotherCount) {
            answer++;
        }
    }

    free(brother);
    free(cheolsu);

    return answer;
}
