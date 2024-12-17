#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define INF 1000000000
#define MAX_N 50001
#define HEAP_SIZE 500000

typedef struct {
    int intensity;
    int node;
} Element;

typedef struct {
    Element heap[HEAP_SIZE];
    int size;
} PriorityQueue;

void init(PriorityQueue* pq) {
    pq->size = 0;
}

void push(PriorityQueue* pq, int intensity, int node) {
    pq->heap[pq->size].intensity = intensity;
    pq->heap[pq->size].node = node;
    int i = pq->size++;
    while (i > 0 && pq->heap[i].intensity < pq->heap[(i - 1) / 2].intensity) {
        Element temp = pq->heap[i];
        pq->heap[i] = pq->heap[(i - 1) / 2];
        pq->heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

Element pop(PriorityQueue* pq) {
    Element top = pq->heap[0];
    pq->heap[0] = pq->heap[--pq->size];
    int i = 0;
    while (2 * i + 1 < pq->size) {
        int child = 2 * i + 1;
        if (child + 1 < pq->size && pq->heap[child].intensity > pq->heap[child + 1].intensity) child++;
        if (pq->heap[i].intensity < pq->heap[child].intensity) break;
        Element temp = pq->heap[i];
        pq->heap[i] = pq->heap[child];
        pq->heap[child] = temp;
        i = child;
    }
    return top;
}

bool isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

int dist[MAX_N];
bool isSummit[MAX_N];
int graph[MAX_N][2 * MAX_N];
int edgeCount[MAX_N];

void dijkstra(int gates[], int gates_len, int* result) {
    PriorityQueue pq;
    init(&pq);

    for (int i = 0; i < MAX_N; i++) dist[i] = INF;

    for (int i = 0; i < gates_len; i++) {
        int gate = gates[i];
        push(&pq, 0, gate);
        dist[gate] = 0;
    }

    while (!isEmpty(&pq)) {
        Element curr = pop(&pq);
        int node = curr.node;
        int intensity = curr.intensity;

        if (isSummit[node]) {
            if (result[1] > intensity || (result[1] == intensity && result[0] > node)) {
                result[0] = node;
                result[1] = intensity;
            }
            continue;
        }

        for (int i = 0; i < edgeCount[node]; i += 2) {
            int nextNode = graph[node][i];
            int cost = graph[node][i + 1];
            int newIntensity = intensity > cost ? intensity : cost;

            if (dist[nextNode] > newIntensity) {
                dist[nextNode] = newIntensity;
                push(&pq, newIntensity, nextNode);
            }
        }
    }
}

int* solution(int n, int** paths, size_t paths_rows, size_t paths_cols, int gates[], size_t gates_len, int summits[], size_t summits_len) {
    memset(edgeCount, 0, sizeof(edgeCount));
    memset(isSummit, 0, sizeof(isSummit));

    for (size_t i = 0; i < summits_len; i++) {
        isSummit[summits[i]] = true;
    }

    for (size_t i = 0; i < paths_rows; i++) {
        int n1 = paths[i][0];
        int n2 = paths[i][1];
        int cost = paths[i][2];

        graph[n1][edgeCount[n1]++] = n2;
        graph[n1][edgeCount[n1]++] = cost;

        graph[n2][edgeCount[n2]++] = n1;
        graph[n2][edgeCount[n2]++] = cost;
    }

    int* answer = (int*)malloc(2 * sizeof(int));
    answer[0] = INF;
    answer[1] = INF;

    dijkstra(gates, gates_len, answer);
    return answer;
}
