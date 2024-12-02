#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long binary(long long axisY, long long r, int dir) {
    long long answer = 0;
    long long start = 1;
    long long end = r;
    long long middle = 0;

    while (start <= end) {
        middle = (start + end) / 2;

        if (middle * middle > axisY) {
            end = middle - 1;
        }
        else if (middle * middle < axisY) {
            start = middle + 1;
            answer = middle;
        }
        else if (middle * middle == axisY) {
            if (dir == 1) {
                return middle - 1;
            }
            return middle;
        }
    }
    return answer;
}

long long solution(int r1, int r2) {
    long long answer = 0;
    long long r;
    long long axisY1 = 0;
    long long axisY2 = 0;

    r = r2;
    for (long long i = 0; i < r2; i++) {
        axisY2 = r * r - i * i;
        answer += binary(axisY2, r, 2);
    }

    r = r1;
    for (long long i = 0; i < r1; i++) {
        axisY1 = r * r - i * i;
        answer -= binary(axisY1, r, 1);
    }

    answer *= 4;

    return answer;
}