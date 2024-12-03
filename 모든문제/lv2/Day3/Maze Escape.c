#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define MAX 100
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int r, c;
int dirX[4] = { -1, 1, 0, 0 };
int dirY[4] = { 0, 0, -1, 1 };

typedef struct {
    int x, y, time;
} QueueNode;

typedef struct {
    QueueNode data[MAX * MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

bool isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, int x, int y, int time) {
    q->data[q->rear].x = x;
    q->data[q->rear].y = y;
    q->data[q->rear].time = time;
    q->rear++;
}

QueueNode dequeue(Queue* q) {
    return q->data[q->front++];
}

int getMinTime(int sx, int sy, int dx, int dy, const char maps[MAX][MAX]) {
    Queue q;
    bool visited[MAX][MAX] = { 0 };
    int time = INT_MAX;

    initQueue(&q);
    enqueue(&q, sx, sy, 0);
    visited[sx][sy] = true;

    while (!isEmpty(&q)) {
        QueueNode current = dequeue(&q);
        int cx = current.x;
        int cy = current.y;
        int acc_time = current.time;

        if (cx == dx && cy == dy) {
            time = MIN(time, acc_time);
        }

        for (int i = 0; i < 4; i++) {
            int nx = cx + dirX[i];
            int ny = cy + dirY[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (visited[nx][ny] || maps[nx][ny] == 'X') continue;

            enqueue(&q, nx, ny, acc_time + 1);
            visited[nx][ny] = true;
        }
    }

    return time == INT_MAX ? 0 : time;
}

int solution(const char* maps[], size_t maps_len) {
    char grid[MAX][MAX];
    int start_x, start_y, laber_x, laber_y, dest_x, dest_y;
    int findCount = 0;

    r = maps_len;
    c = strlen(maps[0]);

    for (int i = 0; i < r; i++) {
        strncpy(grid[i], maps[i], c);
        grid[i][c] = '\0';
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (findCount == 3) break;

            if (grid[i][j] == 'S') {
                start_x = i;
                start_y = j;
                findCount++;
            }
            else if (grid[i][j] == 'L') {
                laber_x = i;
                laber_y = j;
                findCount++;
            }
            else if (grid[i][j] == 'E') {
                dest_x = i;
                dest_y = j;
                findCount++;
            }
        }
    }

    int startToLaber = getMinTime(start_x, start_y, laber_x, laber_y, grid);
    int LaberToDest = startToLaber ? getMinTime(laber_x, laber_y, dest_x, dest_y, grid) : -1;

    return (LaberToDest == -1 || !LaberToDest) ? -1 : startToLaber + LaberToDest;
}
