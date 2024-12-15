#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX_LEN 100

char answer[MAX_LEN];
char ret[MAX_LEN] = "impossible";
bool flag = false;

int n, m, x, y, r, c, k;
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, -1, 1, 0 };
char dir[4] = { 'd', 'l', 'r', 'u' };

int get_dist(int x, int y, int a, int b) {
    return abs(x - a) + abs(y - b);
}

void dfs(int cnt, int curx, int cury) {
    if (!flag) {
        int dist = get_dist(curx, cury, r, c);
        if (k - cnt - dist < 0) return;
        if ((k - cnt - dist) % 2 == 1) return;

        if (cnt == k) {
            if (curx == r && cury == c) {
                flag = true;
                strcpy(ret, answer);
            }
            return;
        }

        for (int i = 0; i < 4; i++) {
            int newx = curx + dx[i];
            int newy = cury + dy[i];
            if (newx > 0 && newx <= n && newy > 0 && newy <= m) {
                int len = strlen(answer);
                answer[len] = dir[i];
                answer[len + 1] = '\0';
                dfs(cnt + 1, newx, newy);
                answer[len] = '\0';
            }
        }
    }
}

char* solution(int _n, int _m, int _x, int _y, int _r, int _c, int _k) {
    n = _n;
    m = _m;
    x = _x;
    y = _y;
    r = _r;
    c = _c;
    k = _k;

    flag = false;
    answer[0] = '\0';
    strcpy(ret, "impossible");

    dfs(0, x, y);

    char* result = (char*)malloc(strlen(ret) + 1);
    strcpy(result, ret);
    return result;
}
