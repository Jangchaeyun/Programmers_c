#include <stdio.h>
#include <stdlib.h>

int* solution(int target) {
    int* answer = (int*)malloc((target + 1) * sizeof(int));
    if (answer == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    for (int i = 0; i <= target; ++i) {
        answer[i] = target - i;
    }

    return answer;
}