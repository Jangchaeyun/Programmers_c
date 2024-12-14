#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_REQS 1010
#define INF 987654321

typedef struct {
	int start;
	int time;
} Request;

int GetWaitTime(Request* reqs, size_t reqs_size, int n) {
    int waitTime = 0;
    int* pq = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        pq[i] = 0;
    }

    for (size_t i = 0; i < reqs_size; i++) {
        int minIndex = 0;
        for (int j = 1; j < n; j++) {
            if (pq[j] < pq[minIndex]) {
                minIndex = j;
            }
        }

        if (pq[minIndex] == 0) {
            pq[minIndex] = reqs[i].start;
        }

        if (pq[minIndex] > reqs[i].start) {
            waitTime += pq[minIndex] - reqs[i].start;
            pq[minIndex] += reqs[i].time;
        }
        else {
            pq[minIndex] = reqs[i].start + reqs[i].time;
        }
    }

    free(pq);
    return waitTime;
}

int solution(int k, int n, int** reqs, size_t reqs_rows, size_t reqs_cols) {
    int answer = 0;

    Request* kReqs[k];
    size_t kReqsSizes[k];
    int watingTimes[k];
    int nCount[k];

    for (int i = 0; i < k; i++) {
        kReqs[i] = (Request*)malloc(MAX_REQS * sizeof(Request));
        kReqsSizes[i] = 0;
        watingTimes[i] = 0;
        nCount[i] = 1;
    }

    for (size_t i = 0; i < reqs_rows; i++) {
        int category = reqs[i][2] - 1;
        kReqs[category][kReqsSizes[category]].start = reqs[i][0];
        kReqs[category][kReqsSizes[category]].time = reqs[i][1];
        kReqsSizes[category]++;
    }

    for (int i = 0; i < k; i++) {
        watingTimes[i] = GetWaitTime(kReqs[i], kReqsSizes[i], nCount[i]);
    }

    n -= k;

    while (n != 0) {
        int tmp[k];
        for (int i = 0; i < k; i++) {
            tmp[i] = 0;
            if (watingTimes[i] > 0) {
                int newWaitTime = GetWaitTime(kReqs[i], kReqsSizes[i], nCount[i] + 1);
                tmp[i] = watingTimes[i] - newWaitTime;
            }
        }

        int maxIdx = 0;
        for (int i = 1; i < k; i++) {
            if (tmp[i] > tmp[maxIdx]) {
                maxIdx = i;
            }
        }

        nCount[maxIdx]++;
        watingTimes[maxIdx] -= tmp[maxIdx];
        n--;
    }

    for (int i = 0; i < k; i++) {
        answer += watingTimes[i];
        free(kReqs[i]);
    }

    return answer;
}
