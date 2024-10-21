#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int sides[], size_t sides_len) {
    int answer = 0;

    int a = sides[0];
    int b = sides[1];

    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    for (int i = 1; i <= b; i++) {
        if (b < a + i) {
            answer++;
        }
    }

    for (int i = b + 1; i < 999999; i++) {
        if (i < a + b) {
            answer++;
        }
        else {
            break;
        }
    }

    return answer;
}
