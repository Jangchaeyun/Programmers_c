#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX 510

int N, M;
bool Visit[MAX][MAX][4];
char MAP[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int Change_Dir(char C, int Dir) {
    if (C == 'L') {
        if (Dir == 0) return 3;
        if (Dir == 1) return 2;
        if (Dir == 2) return 0;
        if (Dir == 3) return 1;
    }
    if (Dir == 0) return 2;
    if (Dir == 1) return 3;
    if (Dir == 2) return 1;
    if (Dir == 3) return 0;
    return Dir;
}

int Simulation(int x, int y, int Dir, int Len) {
    if (Visit[x][y][Dir] == true) return Len;

    Visit[x][y][Dir] = true;

    int nx = x;
    int ny = y;
    int nd = Dir;

    if (MAP[x][y] != 'S') nd = Change_Dir(MAP[x][y], Dir);
    nx = x + dx[nd];
    ny = y + dy[nd];
    if (nx < 0) nx = N - 1;
    if (ny < 0) ny = M - 1;
    if (nx == N) nx = 0;
    if (ny == M) ny = 0;

    return Simulation(nx, ny, nd, Len + 1);
}

int* solution(const char* grid[], size_t grid_len) {
    N = grid_len;
    M = strlen(grid[0]);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            MAP[i][j] = grid[i][j];
        }
    }

    int* answer = (int*)malloc(MAX * MAX * 4 * sizeof(int));
    int index = 0;

    memset(Visit, 0, sizeof(Visit));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 4; k++) {
                int Result = Simulation(i, j, k, 0);
                if (Result != 0) {
                    answer[index++] = Result;
                }
            }
        }
    }

    for (int i = 0; i < index - 1; i++) {
        for (int j = i + 1; j < index; j++) {
            if (answer[i] > answer[j]) {
                int temp = answer[i];
                answer[i] = answer[j];
                answer[j] = temp;
            }
        }
    }

    return answer;
}
