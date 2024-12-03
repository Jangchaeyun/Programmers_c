#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int value) {
    stack->data[++stack->top] = value;
}

int top(Stack* stack) {
    return stack->data[stack->top];
}

void pop(Stack* stack) {
    if (!isEmpty(stack)) {
        stack->top--;
    }
}

void freeStack(Stack* stack) {
    free(stack->data);
    free(stack);
}

int* solution(int numbers[], size_t numbers_len) {
    int* answer = (int*)malloc(numbers_len * sizeof(int));
    Stack* stack = createStack(numbers_len);

    for (int i = numbers_len - 1; i >= 0; i--) {
        while (1) {
            if (isEmpty(stack)) {
                answer[i] = -1;
                break;
            }

            if (top(stack) > numbers[i]) {
                answer[i] = top(stack);
                break;
            }
            pop(stack);
        }
        push(stack, numbers[i]);
    }
    freeStack(stack);
    return answer;
}