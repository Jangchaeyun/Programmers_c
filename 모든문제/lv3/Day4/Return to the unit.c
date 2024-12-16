#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXI 987654321
#define MAX_N 10001

int node[MAX_N][MAX_N];
int node_size[MAX_N];
int dist[MAX_N];

typedef struct {
    int idx;
    int val;
} info;

typedef struct {
    info data[MAX_N];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

bool isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, info item) {
    q->data[q->rear++] = item;
}

info dequeue(Queue* q) {
    return q->data[q->front++];
}

int* solution(int n, int** roads, size_t roads_rows, size_t roads_cols, int* sources, size_t sources_len, int destination) {
    memset(node, 0, sizeof(node));
    memset(node_size, 0, sizeof(node_size));
    for (int i = 1; i <= n; i++) {
        dist[i] = MAXI;
    }

    for (size_t i = 0; i < roads_rows; i++) {
        int a = roads[i][0];
        int b = roads[i][1];
        node[a][node_size[a]++] = b;
        node[b][node_size[b]++] = a;
    }

    Queue q;
    initQueue(&q);
    enqueue(&q, (info) { destination, 0 });
    dist[destination] = 0;

    while (!isEmpty(&q)) {
        info ii = dequeue(&q);
        int cidx = ii.idx;
        int cv = ii.val;

        for (int i = 0; i < node_size[cidx]; i++) {
            int next = node[cidx][i];
            if (dist[next] > cv + 1) {
                dist[next] = cv + 1;
                enqueue(&q, (info) { next, cv + 1 });
            }
        }
    }

    int* answer = (int*)malloc(sources_len * sizeof(int));
    for (size_t i = 0; i < sources_len; i++) {
        answer[i] = (dist[sources[i]] == MAXI) ? -1 : dist[sources[i]];
    }

    return answer;
}
