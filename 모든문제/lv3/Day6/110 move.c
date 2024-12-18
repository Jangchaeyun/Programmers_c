#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* data;
    int top;
    int capacity;
} Stack;

void initStack(Stack* s, int capacity) {
    s->data = (char*)malloc(capacity * sizeof(char));
    s->top = -1;
    s->capacity = capacity;
}

void freeStack(Stack* s) {
    free(s->data);
}

void push(Stack* s, char c) {
    if (s->top + 1 >= s->capacity) {
        s->capacity *= 2;
        s->data = realloc(s->data, s->capacity * sizeof(char));
    }
    s->data[++s->top] = c;
}

char pop(Stack* s) {
    return s->data[s->top--];
}

bool isEmpty(Stack* s) {
    return s->top == -1;
}

char peek(Stack* s) {
    return s->data[s->top];
}

int stackAndFind(Stack* s, const char* numbers) {
    int result = 0;
    int len = strlen(numbers);

    for (int i = 0; i < len; i++) {
        char third = numbers[i];
        if (s->top < 1) {
            push(s, third);
        } else {
            char second = pop(s);
            char first = pop(s);

            if (first == '1' && second == '1' && third == '0') {
                result++; // 110 찾음
            } else {
                push(s, first);
                push(s, second);
                push(s, third);
            }
        }
    }
    return result;
}

char* changeNumbers(const char* numbers) {
    if (strstr(numbers, "110") == NULL) {
        char* result = (char*)malloc((strlen(numbers) + 1) * sizeof(char));
        strcpy(result, numbers);
        return result;
    }

    Stack s;
    initStack(&s, 100);

    int count = stackAndFind(&s, numbers);
    int idx = s.top + 1;
    bool flag = false;

    char* result = (char*)malloc((strlen(numbers) + count * 3 + 1) * sizeof(char)); // 충분한 크기 할당
    int res_idx = 0;

    while (!isEmpty(&s)) {
        char c = pop(&s);
        if (!flag && c == '0') flag = true;
        if (!flag) idx--;
        result[res_idx++] = c;
    }
    result[res_idx] = '\0';

    for (int i = 0, j = res_idx - 1; i < j; i++, j--) {
        char temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }

    for (int i = 0; i < count; i++) {
        memmove(result + idx + 3, result + idx, strlen(result) - idx + 1);
        memcpy(result + idx, "110", 3);
        idx += 3;
    }

    freeStack(&s);
    return result;
}

char** solution(const char* s[], size_t s_len) {
    char** answer = (char**)malloc(s_len * sizeof(char*));
    for (size_t i = 0; i < s_len; i++) {
        answer[i] = changeNumbers(s[i]);
    }
    return answer;
}

void freeSolution(char** answer, size_t len) {
    for (size_t i = 0; i < len; i++) {
        free(answer[i]);
    }
    free(answer);
}