#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int n, int m, int x, int y, int** queries, size_t queries_rows, size_t queries_cols) {
    long long answer = 0;

    long long p1_s = x, p1_e = x;
    long long p2_s = y, p2_e = y;

    for (int i = queries_rows - 1; i >= 0; i--) {
        int dir = queries[i][0];
        int dist = queries[i][1];

        if (dir == 0) {
            if (p2_s != 0) {
                p2_s += dist;
            }
            p2_e += dist;

            if (p2_e > m - 1) {
                p2_e = m - 1;
            }
        }

        else if (dir == 1) {
            p2_s -= dist;

            if (p2_s < 0) {
                p2_s = 0;
            }

            if (p2_e != m - 1) {
                p2_e -= dist;
            }
        }

        else if (dir == 2) {
            if (p1_s != 0) {
                p1_s += dist;
            }
            p1_e += dist;

            if (p1_e > n - 1) {
                p1_e = n - 1;
            }
        }

        else if (dir == 3) {
            p1_s -= dist;
            if (p1_s < 0) {
                p1_s = 0;
            }

            if (p1_e != n - 1) {
                p1_e -= dist;
            }
        }

        if (p1_s > n - 1 || p1_e < 0 || p2_s > m - 1 || p2_e < 0) {
            return answer;
        }
    }

    answer = (p1_e - p1_s + 1) * (p2_e - p2_s + 1);

    return answer;
}