#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101
#define INF 987654321

int visit[MAX][MAX] = { 0 };
int answer = INF;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void find(int a, int b, int ans_a, int ans_b, int count) {
    if (a == ans_a && b == ans_b) {
        if (count < answer) {
            answer = count;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = a + dx[i];
        int ny = b + dy[i];

        if (visit[nx][ny] == 7) {
            visit[nx][ny] = 0;
            find(nx, ny, ans_a, ans_b, count + 1);
            visit[nx][ny] = 7;
        }
    }
}

int solution(int** rectangle, size_t rectangle_row_len, size_t rectangle_col_len, int characterX, int characterY, int itemX, int itemY) {
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;

    for (size_t i = 0; i < rectangle_row_len; i++) {
        for (int a = rectangle[i][0] * 2; a <= rectangle[i][2] * 2; a++) {
            for (int b = rectangle[i][1] * 2; b <= rectangle[i][3] * 2; b++) {
                visit[a][b] = 7;
            }
        }
    }

    for (size_t i = 0; i < rectangle_row_len; i++) {
        for (int a = rectangle[i][0] * 2 + 1; a <= rectangle[i][2] * 2 - 1; a++) {
            for (int b = rectangle[i][1] * 2 + 1; b <= rectangle[i][3] * 2 - 1; b++) {
                visit[a][b] = 0;
            }
        }
    }

    visit[characterX][characterY] = 1;
    find(characterX, characterY, itemX, itemY, 0);

    return answer / 2;
}
