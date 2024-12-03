#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int visited[MAX][MAX];

typedef struct {
    int x, y;
} QueueNode;

typedef struct {
    QueueNode data[MAX * MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

bool isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, int x, int y) {
    q->data[q->rear].x = x;
    q->data[q->rear].y = y;
    q->rear++;
}

QueueNode dequeue(Queue* q) {
    return q->data[q->front++];
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* solution(const char* maps[], size_t maps_len) {
    int n = maps_len;
    int m = strlen(maps[0]);
    int* answer = (int*)malloc((MAX * MAX + 1) * sizeof(int));
    int answerCount = 0;

    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maps[i][j] != 'X' && visited[i][j] == 0) {
                Queue q;
                initQueue(&q);

                enqueue(&q, i, j);
                visited[i][j] = 1;

                int sum = maps[i][j] - '0';

                while (!isEmpty(&q)) {
                    QueueNode node = dequeue(&q);
                    int curx = node.x;
                    int cury = node.y;

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = curx + dx[dir];
                        int ny = cury + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (maps[nx][ny] == 'X' || visited[nx][ny] == 1) continue;

                        enqueue(&q, nx, ny);
                        visited[nx][ny] = 1;
                        sum += (maps[nx][ny] - '0');
                    }
                }
                answer[++answerCount] = sum;
            }
        }
    }

    if (answerCount == 0) {
        answer[1] = -1;
        answerCount = 1;
    }
    else {
        qsort(answer + 1, answerCount, sizeof(int), compare);
    }

    answer[0] = answerCount;
    return answer;
}
