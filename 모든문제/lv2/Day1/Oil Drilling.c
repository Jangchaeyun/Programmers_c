#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 1000
#define MAX_M 1000

typedef struct {
    int x, y;
} Pos;

typedef struct {
    Pos data[MAX_N * MAX_M];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

void enqueue(Queue* q, int x, int y) {
    q->data[q->rear++] = (Pos){ x, y };
}

Pos dequeue(Queue* q) {
    return q->data[q->front++];
}

bool isQueueEmpty(Queue* q) {
    return q->front == q->rear;
}

int solution(int** land, size_t land_rows, size_t land_cols) {
    int dirX[4] = { 1, -1, 0, 0 };
    int dirY[4] = { 0, 0, 1, -1 };
    int n = (int)land_rows;
    int m = (int)land_cols;
    int answer = 0;
    int num = 1;

    bool visited[MAX_N][MAX_M];
    int oils[MAX_N][MAX_M];
    int oilBlocks[MAX_N * MAX_M];
    memset(visited, 0, sizeof(visited));
    memset(oils, 0, sizeof(oils));
    memset(oilBlocks, 0, sizeof(oilBlocks));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (visited[i][j] || land[i][j] != 1) continue;

            Queue q;
            initQueue(&q);
            enqueue(&q, i, j);
            visited[i][j] = true;
            oils[i][j] = num;

            int oil = 0;
            while (!isQueueEmpty(&q)) {
                Pos curr = dequeue(&q);
                oil++;
                for (int dir = 0; dir < 4; ++dir) {
                    int nx = curr.x + dirX[dir];
                    int ny = curr.y + dirY[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (visited[nx][ny] || land[nx][ny] != 1) continue;
                    enqueue(&q, nx, ny);
                    visited[nx][ny] = true;
                    oils[nx][ny] = num;
                }
            }

            oilBlocks[num++] = oil;
        }
    }

    for (int j = 0; j < m; ++j) {
        int sum = 0;
        bool included[MAX_N * MAX_M] = { false };
        for (int i = 0; i < n; ++i) {
            int oilNum = oils[i][j];
            if (oilNum > 0 && !included[oilNum]) {
                sum += oilBlocks[oilNum];
                included[oilNum] = true;
            }
        }
        if (sum > answer) answer = sum;
    }

    return answer;
}

int main() {
    int land_data[5][5] = {
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1},
        {1, 1, 0, 0, 0}
    };

    size_t land_rows = 5;
    size_t land_cols = 5;

    int** land = (int**)malloc(land_rows * sizeof(int*));
    for (size_t i = 0; i < land_rows; ++i) {
        land[i] = (int*)malloc(land_cols * sizeof(int));
        for (size_t j = 0; j < land_cols; ++j) {
            land[i][j] = land_data[i][j];
        }
    }

    int result = solution(land, land_rows, land_cols);
    printf("최대 석유 시추량: %d\n", result);

    for (size_t i = 0; i < land_rows; ++i) {
        free(land[i]);
    }
    free(land);

    return 0;
}
