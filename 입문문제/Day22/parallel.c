#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int** dots, size_t dots_rows, size_t dots_cols) {
    int answer = 0;

    double a = (double)(dots[0][0] - dots[1][0]);
    double b = (double)(dots[0][1] - dots[1][1]);
    double c = (double)(dots[2][0] - dots[3][0]);
    double d = (double)(dots[2][1] - dots[3][1]);

    if (a / b == c / d) return 1;

    a = (double)(dots[0][0] - dots[2][0]);
    b = (double)(dots[0][1] - dots[2][1]);
    c = (double)(dots[1][0] - dots[3][0]);
    d = (double)(dots[1][1] - dots[3][1]);

    if (a / b == c / d) return 1;

    a = (double)(dots[0][0] - dots[3][0]);
    b = (double)(dots[0][1] - dots[3][1]);
    c = (double)(dots[1][0] - dots[2][0]);
    d = (double)(dots[1][1] - dots[2][1]);

    if (a / b == c / d) return 1;

    return answer;
}