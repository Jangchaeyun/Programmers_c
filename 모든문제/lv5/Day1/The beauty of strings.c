#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 300001

typedef struct {
    long long samePoint;
    long long difPoint;
    long long sameCnt;
    long long difCnt;
    int ed;
} Node;

long long solution(const char* s) {
    long long answer = 0;
    int n = strlen(s);

    char prevChar = s[0];
    bool isFirst[26] = {false};
    long long nuHap[MAX_LEN] = {0};
    int sMap[26][MAX_LEN] = {{0}};
    Node nodeInfo[26] = {0};

    int conCnt = 1;

    for (int i = 1; i < n; i++) {
        nuHap[i] = nuHap[i - 1] + i;
        int prevAlpha = prevChar - 'a';
        int prevI = i - 1;

        if (prevChar == s[i]) {
            conCnt += 1;
        } else {
            if (!isFirst[prevAlpha]) {
                isFirst[prevAlpha] = true;
                nodeInfo[prevAlpha].difPoint = nuHap[prevI] - nuHap[conCnt - 1];
                nodeInfo[prevAlpha].sameCnt = conCnt;
                nodeInfo[prevAlpha].difCnt = prevI - conCnt + 1;
                nodeInfo[prevAlpha].ed = prevI;
                sMap[prevAlpha][conCnt] += 1;
            } else {
                int eed = nodeInfo[prevAlpha].ed;
                nodeInfo[prevAlpha].difPoint += (prevI - eed) * nodeInfo[prevAlpha].difCnt + nuHap[prevI - eed - 1] - nuHap[conCnt - 1];
                nodeInfo[prevAlpha].samePoint += (prevI - eed) * nodeInfo[prevAlpha].sameCnt;

                sMap[prevAlpha][conCnt] += 1;

                nodeInfo[prevAlpha].sameCnt += conCnt;
                nodeInfo[prevAlpha].difCnt = prevI + 1 - nodeInfo[prevAlpha].sameCnt;
                nodeInfo[prevAlpha].ed = prevI;
            }
            prevChar = s[i];
            conCnt = 1;
        }

        int nowAlpha = s[i] - 'a';
        long long ccct = 0;

        int eed = nodeInfo[nowAlpha].ed;
        if (!isFirst[nowAlpha]) { // 방문 전이라면
            ccct = nuHap[i] - nuHap[conCnt - 1];
        } else {
            ccct += nodeInfo[nowAlpha].difPoint + (i - eed) * nodeInfo[nowAlpha].difCnt;
            ccct += nuHap[i - eed - 1] - nuHap[conCnt - 1];
        }

        for (int len = 1; len < MAX_LEN; len++) {
            if (sMap[nowAlpha][len] == 0) continue;
            if (conCnt < len) {
                ccct += (nuHap[(i - conCnt) - (eed - len + 1)] - nuHap[i - (eed + 1)]) * sMap[nowAlpha][len];
            }
            ccct += (i - (eed + 1)) * sMap[nowAlpha][len] * (conCnt < len ? conCnt : len);
        }

        ccct += nodeInfo[nowAlpha].samePoint;
        answer += ccct;
    }

    return answer;
}
