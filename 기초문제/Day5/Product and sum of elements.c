#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num_list[], size_t num_list_len) {
    int answer = 0;
    int sum = 0;
    int mul = 1;
    for (int i = 0; i < num_list_len; i++)
    {
        sum += num_list[i];
        mul *= num_list[i];
    }
    if (mul < sum * sum)
        answer = 1;
    else if (mul > sum * sum)
        answer = 0;
    return answer;
}