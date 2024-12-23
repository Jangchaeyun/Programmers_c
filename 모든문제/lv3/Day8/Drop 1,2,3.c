#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NODES 1000

typedef struct Queue {
    int* data;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(size * sizeof(int));
    q->front = 0;
    q->rear = 0;
    q->size = size;
    return q;
}

void enqueue(Queue* q, int value) {
    q->data[q->rear++] = value;
    if (q->rear == q->size) q->rear = 0;
}

int dequeue(Queue* q) {
    int value = q->data[q->front++];
    if (q->front == q->size) q->front = 0;
    return value;
}

bool isQueueEmpty(Queue* q) {
    return q->front == q->rear;
}

void freeQueue(Queue* q) {
    free(q->data);
    free(q);
}

int** nodeV;
Queue** nodeRoad;
int* targetCnt;
int* realTarget;
int nodeCount;

int targetLeaf() {
    int stNode = 1;
    int nowRoad;
    while (!isQueueEmpty(nodeRoad[stNode])) {
        nowRoad = dequeue(nodeRoad[stNode]);
        enqueue(nodeRoad[stNode], nowRoad);
        stNode = nowRoad;
    }
    return stNode;
}

int canMakeLeaf() {
    int returnInt = 0;
    for (int i = 1; i <= nodeCount; i++) {
        if (targetCnt[i] * 3 < realTarget[i]) {
            returnInt = 1;
        }
        if (realTarget[i] < targetCnt[i]) {
            returnInt = 2;
            return returnInt;
        }
    }
    return returnInt;
}

int* solution(int** edges, size_t edges_rows, size_t edges_cols, int target[], size_t target_len) {
    nodeCount = target_len;
    nodeV = (int**)malloc((nodeCount + 1) * sizeof(int*));
    int* nodeSize = (int*)calloc(nodeCount + 1, sizeof(int));
    nodeRoad = (Queue**)malloc((nodeCount + 1) * sizeof(Queue*));
    targetCnt = (int*)calloc(nodeCount + 1, sizeof(int));
    realTarget = (int*)malloc((nodeCount + 1) * sizeof(int));
    realTarget[0] = 0;
    memcpy(&realTarget[1], target, target_len * sizeof(int));

    for (int i = 0; i <= nodeCount; i++) {
        nodeV[i] = NULL;
        nodeRoad[i] = createQueue(MAX_NODES);
    }

    for (size_t i = 0; i < edges_rows; i++) {
        int from = edges[i][0];
        int to = edges[i][1];
        nodeSize[from]++;
        nodeV[from] = (int*)realloc(nodeV[from], nodeSize[from] * sizeof(int));
        nodeV[from][nodeSize[from] - 1] = to;
    }

    for (int i = 1; i <= nodeCount; i++) {
        if (nodeSize[i] > 0) {
            qsort(nodeV[i], nodeSize[i], sizeof(int), (int (*)(const void*, const void*))strcmp);
            for (int j = 0; j < nodeSize[i]; j++) {
                enqueue(nodeRoad[i], nodeV[i][j]);
            }
        }
    }

    int* answer = (int*)malloc(MAX_NODES * sizeof(int));
    int answerIndex = 0;
    int canMake;
    int leafNum;

    while (true) {
        leafNum = targetLeaf();
        answer[answerIndex++] = leafNum;
        targetCnt[leafNum]++;
        canMake = canMakeLeaf();
        if (canMake == 0) {
            break;
        } else if (canMake == 2) {
            free(answer);
            for (int i = 0; i <= nodeCount; i++) {
                free(nodeV[i]);
                freeQueue(nodeRoad[i]);
            }
            free(nodeV);
            free(nodeRoad);
            free(targetCnt);
            free(realTarget);
            int* failAnswer = (int*)malloc(sizeof(int));
            failAnswer[0] = -1;
            return failAnswer;
        }
    }

    for (int i = 0; i < answerIndex; i++) {
        leafNum = answer[i];
        targetCnt[leafNum]--;
        if (targetCnt[leafNum] * 3 >= realTarget[leafNum] - 1) {
            answer[i] = 1;
            realTarget[leafNum] -= 1;
        } else if (targetCnt[leafNum] * 3 >= realTarget[leafNum] - 2) {
            answer[i] = 2;
            realTarget[leafNum] -= 2;
        } else {
            answer[i] = 3;
            realTarget[leafNum] -= 3;
        }
    }

    for (int i = 0; i <= nodeCount; i++) {
        free(nodeV[i]);
        freeQueue(nodeRoad[i]);
    }
    free(nodeV);
    free(nodeRoad);
    free(targetCnt);
    free(realTarget);

    return answer;
}
