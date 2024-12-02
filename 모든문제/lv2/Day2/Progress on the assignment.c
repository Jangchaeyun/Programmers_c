#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int time_to_minutes(const char* time_str) {
    int hours = (time_str[0] - '0') * 10 + (time_str[1] - '0');
    int minutes = (time_str[3] - '0') * 10 + (time_str[4] - '0');
    return hours * 60 + minutes;
}

int compare(const void* a, const void* b) {
    const char** plan_a = *(const char***)a;
    const char** plan_b = *(const char***)b;

    int time_a = time_to_minutes(plan_a[1]);
    int time_b = time_to_minutes(plan_b[1]);

    if (time_a == time_b) {
        return strcmp(plan_a[0], plan_b[0]);
    }
    return time_a - time_b;
}

char** solution(const char*** plans, size_t plans_rows, size_t plans_cols) {
    char** answer = (char**)malloc((plans_rows + 1) * sizeof(char*)); // +1 for NULL termination
    int answer_index = 0;

    qsort(plans, plans_rows, sizeof(char**), compare);

    typedef struct {
        char* name;
        int remaining_time;
    } Mission;

    Mission* stack = (Mission*)malloc(plans_rows * sizeof(Mission));
    int stack_size = 0;

    int cur_time = 0;

    for (size_t i = 0; i < plans_rows; i++) {
        int start_time = time_to_minutes(plans[i][1]);

        while (cur_time < start_time) {
            if (stack_size > 0) {
                stack[stack_size - 1].remaining_time--;
                if (stack[stack_size - 1].remaining_time == 0) {
                    answer[answer_index++] = stack[stack_size - 1].name;
                    stack_size--;
                }
            }
            cur_time++;
        }

        stack[stack_size].name = strdup(plans[i][0]);
        stack[stack_size].remaining_time = atoi(plans[i][2]);
        stack_size++;
    }

    while (stack_size > 0) {
        answer[answer_index++] = stack[stack_size - 1].name;
        stack_size--;
    }

    answer[answer_index] = NULL;

    free(stack);
    return answer;
}