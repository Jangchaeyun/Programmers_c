#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PEOPLE 10000
#define NAME_LEN 20

typedef struct {
    char name[NAME_LEN];
    int profit;
    char referral[NAME_LEN];
} Person;

Person people[MAX_PEOPLE];
int people_count = 0;

int find_index(const char* name) {
    for (int i = 0; i < people_count; i++) {
        if (strcmp(people[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void distribute(const char* seller, int money) {
    if (strcmp(seller, "-") == 0) return;

    int idx = find_index(seller);
    if (idx == -1) return;

    int commission = money / 10;
    people[idx].profit += (money - commission);

    if (commission > 0) {
        distribute(people[idx].referral, commission);
    }
}

int* solution(const char* enroll[], size_t enroll_len, const char* referral[], size_t referral_len, const char* seller[], size_t seller_len, int amount[], size_t amount_len) {
    people_count = 0;
    for (size_t i = 0; i < enroll_len; i++) {
        strcpy(people[people_count].name, enroll[i]);
        people[people_count].profit = 0;
        strcpy(people[people_count].referral, referral[i]);
        people_count++;
    }

    for (size_t i = 0; i < seller_len; i++) {
        int money = amount[i] * 100;
        distribute(seller[i], money);
    }

    int* answer = (int*)malloc(enroll_len * sizeof(int));
    for (size_t i = 0; i < enroll_len; i++) {
        int idx = find_index(enroll[i]);
        answer[i] = people[idx].profit;
    }

    return answer;
}

void free_solution(int* result) {
    free(result);
}
