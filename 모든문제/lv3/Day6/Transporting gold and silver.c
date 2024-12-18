#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

bool Search(int a, int b, int* g, int g_len, int* s, int* w, int* t, int t_len, long long Mid) {
    long long Total_Gold = 0;
    long long Total_Silver = 0;
    long long Total_Mineral = 0;

    for (int i = 0; i < g_len; i++) {
        long long Time = t[i];
        long long Round_Time = Time * 2;

        long long Move_Cnt = Mid / Round_Time;
        if (Mid % Round_Time >= Time) Move_Cnt++;

        long long Max_Take = (long long)w[i] * Move_Cnt;

        Total_Gold += min((long long)g[i], Max_Take);
        Total_Silver += min((long long)s[i], Max_Take);
        Total_Mineral += min((long long)g[i] + s[i], Max_Take);
    }

    return (Total_Gold >= a && Total_Silver >= b && Total_Mineral >= a + b);
}

long long solution(int a, int b, int* g, size_t g_len, int* s, size_t s_len, int* w, size_t w_len, int* t, size_t t_len) {
    long long answer = -1;
    long long Start = 0;
    long long End = 10e14 * 3;
    answer = End;

    while (Start <= End) {
        long long Mid = (Start + End) / 2;
        if (Search(a, b, g, g_len, s, w, t, t_len, Mid)) {
            if (Mid < answer) answer = Mid;
            End = Mid - 1;
        } else {
            Start = Mid + 1;
        }
    }

    return answer;
}
