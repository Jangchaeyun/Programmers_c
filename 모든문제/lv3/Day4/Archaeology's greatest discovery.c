#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define INF 10000000

int dy[5] = { 1, -1, 0, 0, 0 };
int dx[5] = { 0, 0, 0, 1, -1 };
int minAns = INF;

void Calc(int maxSize, int nowIndex, int topValue[11][11], int clockHands[11][11]) {
    if (nowIndex < maxSize) {
        for (int i = 0; i <= 3; i++) {
            topValue[0][nowIndex] = i;
            Calc(maxSize, nowIndex + 1, topValue, clockHands);
        }
    }
    else {
        int realClockHands[11][11];
        memcpy(realClockHands, clockHands, sizeof(realClockHands));

        int y = 0, x = 0, ny, nx;
        for (int i = 0; i < maxSize; i++) {
            x = i;
            for (int j = 0; j < 5; j++) {
                ny = y + dy[j];
                nx = x + dx[j];
                if (ny >= 0 && ny < maxSize && nx >= 0 && nx < maxSize) {
                    realClockHands[ny][nx] += topValue[0][i];
                    realClockHands[ny][nx] %= 4;
                }
            }
        }

        for (int i = 0; i < maxSize - 1; i++) {
            y = i + 1;
            for (int j = 0; j < maxSize; j++) {
                x = j;
                if (realClockHands[i][j] != 0) {
                    int vvv = 4 - realClockHands[i][j];
                    topValue[y][j] = vvv;
                    for (int k = 0; k < 5; k++) {
                        ny = y + dy[k];
                        nx = x + dx[k];
                        if (ny >= 0 && ny < maxSize && nx >= 0 && nx < maxSize) {
                            realClockHands[ny][nx] += vvv;
                            realClockHands[ny][nx] %= 4;
                        }
                    }
                }
                else {
                    topValue[y][j] = 0;
                }
            }
        }

        int ttt = 0;
        for (int i = 0; i < maxSize; i++) {
            for (int j = 0; j < maxSize; j++) {
                ttt += topValue[i][j];
                if (realClockHands[i][j] != 0) {
                    return;
                }
            }
        }
        if (ttt < minAns) {
            minAns = ttt;
        }
    }
}

int solution(int** clockHands, size_t clockHands_rows, size_t clockHands_cols) {
    int sss = (int)clockHands_rows;
    int topValue[11][11] = { 0 };
    int clockHandsArr[11][11];

    for (int i = 0; i < sss; i++) {
        for (int j = 0; j < (int)clockHands_cols; j++) {
            clockHandsArr[i][j] = clockHands[i][j];
        }
    }

    Calc(sss, 0, topValue, clockHandsArr);

    return (minAns == INF) ? -1 : minAns;
}
