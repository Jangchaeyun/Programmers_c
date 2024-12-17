#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 5

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int n, m;
bool vis[MAX][MAX];
int block[MAX][MAX];

bool Check(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

int solve(int P1[2], int P2[2]) {
    if (vis[P1[0]][P1[1]]) {
        return 0;
    }

    int ret = 0;

    for (int i = 0; i < 4; i++) {
        int nx = P1[0] + dx[i];
        int ny = P1[1] + dy[i];

        if (Check(nx, ny) || vis[nx][ny] || block[nx][ny] == 0) {
            continue;
        }

        vis[P1[0]][P1[1]] = true;
        int nextP1[2] = { nx, ny };
        int val = solve(P2, nextP1) + 1;
        vis[P1[0]][P1[1]] = false;

        if (ret % 2 == 0 && val % 2 == 1) {
            ret = val;
        }
        else if (ret % 2 == 0 && val % 2 == 0) {
            if (val > ret) ret = val;
        }
        else if (ret % 2 == 1 && val % 2 == 1) {
            if (val < ret) ret = val;
        }
    }
    return ret;
}

int solution(int** board, size_t board_rows, size_t board_cols, int aloc[], size_t aloc_len, int bloc[], size_t bloc_len) {
    n = board_rows;
    m = board_cols;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            block[i][j] = board[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    int P1[2] = { aloc[0], aloc[1] };
    int P2[2] = { bloc[0], bloc[1] };

    return solve(P1, P2);
}
