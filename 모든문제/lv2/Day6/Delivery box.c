#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
	int* data;
	int top;
	int capacity;
} Stack;

void init_stack(Stack* stack, int capacity) {
	stack->data = (int*)malloc(capacity * sizeof(int));
	stack->top = -1;
	stack->capacity = capacity;
}

void free_stack(Stack* stack) {
	free(stack->data);
}

bool is_empty(Stack* stack) {
	return stack->top == -1;
}

void push(Stack* stack, int value) {
	if (stack->top < stack->capacity - 1) {
		stack->data[++stack->top] = value;
	}
}

int pop(Stack* stack) {
	if (!is_empty(stack)) {
		return stack->data[stack->top--];
	}
	return -1;
}

int top(Stack* stack) {
	if (!is_empty(stack)) {
		return stack->data[stack->top];
	}
	return -1;
}

int solution(int order[], size_t order_len) {
	Stack stack;
	init_stack(&stack, order_len);

	int idx = 0;
	for (int i = 1; i <= (int)order_len; i++) {
		if (i < order[idx]) {
			push(&stack, i);
		}
		else if (i == order[idx]) {
			idx++;
		}
		else if (!is_empty(&stack) && top(&stack) == order[idx]) {
			idx++;
			pop(&stack);
		}
		else {
			break;
		}
		while (!is_empty(&stack) && top(&stack) == order[idx]) {
			idx++;
			pop(&stack);
		}
	}
	free_stack(&stack);
	return idx;
}