#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int y;
    int x;
} Direction;

Direction directions[4] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

// 방문 배열 구조체
typedef struct {
    bool first;
    bool second;
} Visited;

Visited** visited;
int answer = INT_MAX;

bool check(int** maze, size_t rows, size_t cols, int y, int x) {
    return y >= 0 && y < rows && x >= 0 && x < cols && maze[y][x] != 5;
}

void DFS(int** maze, size_t rows, size_t cols, int ry, int rx, int by, int bx, int cnt) {
    if (maze[ry][rx] == 3 && maze[by][bx] == 4) {
        if (cnt < answer) {
            answer = cnt;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nry = ry;
        int nrx = rx;

        if (maze[nry][nrx] != 3) {
            nry += directions[i].y;
            nrx += directions[i].x;

            if (!check(maze, rows, cols, nry, nrx) || visited[nry][nrx].first)
                continue;

            visited[nry][nrx].first = true;
        }

        for (int j = 0; j < 4; j++) {
            int nby = by;
            int nbx = bx;

            if (maze[nby][nbx] != 4) {
                nby += directions[j].y;
                nbx += directions[j].x;

                if (!check(maze, rows, cols, nby, nbx) || visited[nby][nbx].second)
                    continue;
            }

            if ((nry == nby && nrx == nbx) || (nry == by && nrx == bx && nby == ry && nbx == rx))
                continue;

            visited[nby][nbx].second = true;
            DFS(maze, rows, cols, nry, nrx, nby, nbx, cnt + 1);
            visited[nby][nbx].second = false;
        }

        visited[nry][nrx].first = false;
    }
}

int solution(int** maze, size_t maze_rows, size_t maze_cols) {
    visited = (Visited**)malloc(maze_rows * sizeof(Visited*));
    for (size_t i = 0; i < maze_rows; i++) {
        visited[i] = (Visited*)malloc(maze_cols * sizeof(Visited));
        for (size_t j = 0; j < maze_cols; j++) {
            visited[i][j].first = false;
            visited[i][j].second = false;
        }
    }

    int ry = 0, rx = 0, by = 0, bx = 0;
    for (size_t i = 0; i < maze_rows; i++) {
        for (size_t j = 0; j < maze_cols; j++) {
            if (maze[i][j] == 1) {
                ry = i;
                rx = j;
            }
            else if (maze[i][j] == 2) {
                by = i;
                bx = j;
            }
        }
    }

    visited[ry][rx].first = true;
    visited[by][bx].second = true;

    DFS(maze, maze_rows, maze_cols, ry, rx, by, bx, 0);

    for (size_t i = 0; i < maze_rows; i++) {
        free(visited[i]);
    }
    free(visited);

    return answer == INT_MAX ? 0 : answer;
}
