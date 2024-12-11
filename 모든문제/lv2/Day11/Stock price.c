#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int stack[100000];

int* solution(int prices[], size_t prices_len) {
	int* answer = (int*)malloc(prices_len * sizeof(int));
	int top, len = 0;
    for (int i = 0; i < prices_len; i++)
    {
        top = stack[len - 1];
        while (prices[top] > prices[i] && len > 0)
        {
            answer[top] = i - top;
            len--;
            top = stack[len - 1];
        }
        stack[len++] = i;
    }

    for (int i = 0; i < len; i++) {
        answer[stack[i]] = prices_len - 1 - stack[i];
    }

    return answer;
}