#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX 102
#define INF 987654321

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int visit[MAX][MAX] = { 0 };
int start[2];
int target[2];
int answer = INF;

void dfs(int now_y, int now_x, int dir, int count) {
    if (now_y == target[0] && now_x == target[1]) {
        if (count - 1 < answer) {
            answer = count - 1;
        }
        return;
    }

    if (answer <= count || visit[now_y][now_x] == -1) {
        return;
    }

    int move_y = now_y;
    int move_x = now_x;

    while (1) {
        move_y += dy[dir];
        move_x += dx[dir];
        if (visit[move_y][move_x] == -1) {
            move_y -= dy[dir];
            move_x -= dx[dir];
            break;
        }
    }

    if (visit[move_y][move_x] <= count && visit[move_y][move_x] != 0) { // 이미 방문한 곳
        return;
    }
    else {
        visit[now_y][now_x] = count;
        for (int i = 0; i < 4; i++) {
            dfs(move_y, move_x, i, count + 1);
        }
    }
    return;
}

int solution(const char* board[], size_t board_len) {
    memset(visit, 0, sizeof(visit));
    answer = INF;

    size_t board_width = strlen(board[0]);

    for (int i = 0; i < board_len + 2; i++) {
        for (int j = 0; j < board_width + 2; j++) {
            if (i == 0 || j == 0 || i == board_len + 1 || j == board_width + 1) {
                visit[i][j] = -1;
            }
            else {
                if (board[i - 1][j - 1] == 'D') {
                    visit[i][j] = -1;
                }
                else if (board[i - 1][j - 1] == 'R') {
                    start[0] = i;
                    start[1] = j;
                }
                else if (board[i - 1][j - 1] == 'G') {
                    target[0] = i;
                    target[1] = j;
                }
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        dfs(start[0], start[1], i, 1);
    }

    if (answer == INF) {
        return -1;
    }

    return answer;
}
