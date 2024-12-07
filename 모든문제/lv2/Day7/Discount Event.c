#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    int count;
} Item;

Item cntMap[MAX_ITEMS];
int itemCount = 0;

void Init(const char* want[], int number[], size_t want_len, const char* discount[], size_t discount_len) {
    for (size_t i = 0; i < want_len; i++) {
        strcpy(cntMap[itemCount].name, want[i]);
        cntMap[itemCount].count = number[i];
        itemCount++;
    }

    for (size_t i = 0; i < 10 && i < discount_len; i++) {
        for (int j = 0; j < itemCount; j++) {
            if (strcmp(cntMap[j].name, discount[i]) == 0) {
                cntMap[j].count--;
                break;
            }
        }
    }
}

bool Check(const char* want[], size_t want_len) {
    for (size_t i = 0; i < want_len; i++) {
        for (int j = 0; j < itemCount; j++) {
            if (strcmp(cntMap[j].name, want[i]) == 0 && cntMap[j].count != 0) {
                return false;
            }
        }
    }
    return true;
}

int solution(const char* want[], size_t want_len, int number[], size_t number_len, const char* discount[], size_t discount_len) {
    int answer = 0;

    Init(want, number, want_len, discount, discount_len);

    if (Check(want, want_len)) {
        answer++;
    }

    for (size_t i = 10; i < discount_len; i++) {
        for (int j = 0; j < itemCount; j++) {
            if (strcmp(cntMap[j].name, discount[i]) == 0) {
                cntMap[j].count--;
                break;
            }
        }

        for (int j = 0; j < itemCount; j++) {
            if (strcmp(cntMap[j].name, discount[i - 10]) == 0) {
                cntMap[j].count++;
                break;
            }
        }

        if (Check(want, want_len)) {
            answer++;
        }
    }

    return answer;
}