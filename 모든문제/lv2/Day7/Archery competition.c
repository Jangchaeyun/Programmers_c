#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SCORE 11

int g_answer[MAX_SCORE];
int g_maxGap = 0;

bool compLastScore(int lion[]) {
    for (int i = MAX_SCORE - 1; i >= 0; i--) {
        if (lion[i] > g_answer[i]) return true;
        if (lion[i] < g_answer[i]) return false;
    }
    return true;
}

void calScore(int lion[], int apeche[]) {
    int lionScore = 0, apecheScore = 0;

    for (int i = 0; i < MAX_SCORE; i++) {
        if (lion[i] > 0 || apeche[i] > 0) {
            if (lion[i] > apeche[i]) {
                lionScore += 10 - i;
            }
            else {
                apecheScore += 10 - i;
            }
        }
    }

    int scoreGap = lionScore - apecheScore;
    if (scoreGap > 0 && (g_maxGap < scoreGap || (g_maxGap == scoreGap && compLastScore(lion)))) {
        g_maxGap = scoreGap;
        memcpy(g_answer, lion, sizeof(int) * MAX_SCORE);
    }
}

void dfs(int depth, int arrowNum, int lion[], int apeche[]) {
    if (depth == 10 || arrowNum == 0) {
        if (arrowNum > 0) {
            lion[10] = arrowNum;
        }
        calScore(lion, apeche);
        if (arrowNum > 0) {
            lion[10] = 0;
        }
        return;
    }

    if (arrowNum >= apeche[depth] + 1) {
        lion[depth] = apeche[depth] + 1;
        dfs(depth + 1, arrowNum - lion[depth], lion, apeche);
    }

    lion[depth] = 0;
    dfs(depth + 1, arrowNum, lion, apeche);
}

int* solution(int n, int info[], size_t info_len) {
    int lion[MAX_SCORE] = { 0 };

    memset(g_answer, -1, sizeof(g_answer));
    g_maxGap = 0;

    dfs(0, n, lion, info);

    if (g_maxGap == 0) {
        int* answer = (int*)malloc(sizeof(int));
        answer[0] = -1;
        return answer;
    }
    else {
        int* answer = (int*)malloc(sizeof(int) * MAX_SCORE);
        memcpy(answer, g_answer, sizeof(int) * MAX_SCORE);
        return answer;
    }
}
