#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define CONST_DIV 1000000007

typedef struct Seat {
    int y;
    int x;
    long long cnt;
} Seat;

// Global variables
int** realGrid;
int** rootCnt;
Seat**** rootGoalList;
Seat*** CanSeatList;
Seat**** NCanSeatList;
int gridY, gridX, dSize;
int* realD;
int*** visitedV;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void insertPair(int y, int x, int prevY, int prevX, int nowVisitCnt) {
    Seat cmpS;
    for (int i = 0; i < rootGoalList[y][x][nowVisitCnt]->cnt; i++) {
        cmpS = rootGoalList[y][x][nowVisitCnt][i];
        bool disCheck = false;
        if (nowVisitCnt > 0) {
            for (int j = 0; j < rootGoalList[prevY][prevX][nowVisitCnt - 1]->cnt; j++) {
                if (cmpS.y == rootGoalList[prevY][prevX][nowVisitCnt - 1][j].y &&
                    cmpS.x == rootGoalList[prevY][prevX][nowVisitCnt - 1][j].x) {
                    rootGoalList[prevY][prevX][nowVisitCnt - 1][j].cnt =
                        (rootGoalList[prevY][prevX][nowVisitCnt - 1][j].cnt + cmpS.cnt) % CONST_DIV;
                    disCheck = true;
                }
            }
            if (!disCheck) {
                rootGoalList[prevY][prevX][nowVisitCnt - 1]->cnt++;
                rootGoalList[prevY][prevX][nowVisitCnt - 1] = realloc(rootGoalList[prevY][prevX][nowVisitCnt - 1],
                    rootGoalList[prevY][prevX][nowVisitCnt - 1]->cnt * sizeof(Seat));
                rootGoalList[prevY][prevX][nowVisitCnt - 1][rootGoalList[prevY][prevX][nowVisitCnt - 1]->cnt - 1] = cmpS;
            }
        }
    }
}

void CalcNode(int y, int x, int nowVisitCnt, int prevY, int prevX) {
    int ny, nx;
    if (nowVisitCnt == dSize) {
        Seat goalSeat = {y, x, 1};
        rootGoalList[prevY][prevX][nowVisitCnt - 1]->cnt++;
        rootGoalList[prevY][prevX][nowVisitCnt - 1] = realloc(rootGoalList[prevY][prevX][nowVisitCnt - 1],
            rootGoalList[prevY][prevX][nowVisitCnt - 1]->cnt * sizeof(Seat));
        rootGoalList[prevY][prevX][nowVisitCnt - 1][rootGoalList[prevY][prevX][nowVisitCnt - 1]->cnt - 1] = goalSeat;
        return;
    }

    if (visitedV[y][x][nowVisitCnt] == -1) {
        visitedV[y][x][nowVisitCnt] = 1;
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            if (ny >= 0 && ny < gridY && nx >= 0 && nx < gridX) {
                if (realGrid[y][x] + realD[nowVisitCnt] == realGrid[ny][nx]) {
                    CalcNode(ny, nx, nowVisitCnt + 1, y, x);
                }
            }
        }
        insertPair(y, x, prevY, prevX, nowVisitCnt);
        return;
    } else {
        insertPair(y, x, prevY, prevX, nowVisitCnt);
        return;
    }
}

Seat*** createSeatList(int ySize, int xSize) {
    Seat*** seatList = (Seat***)malloc(ySize * sizeof(Seat**));
    for (int i = 0; i < ySize; i++) {
        seatList[i] = (Seat**)malloc(xSize * sizeof(Seat*));
        for (int j = 0; j < xSize; j++) {
            seatList[i][j] = NULL;
        }
    }
    return seatList;
}

void freeSeatList(Seat*** seatList, int ySize, int xSize) {
    for (int i = 0; i < ySize; i++) {
        for (int j = 0; j < xSize; j++) {
            if (seatList[i][j] != NULL) {
                free(seatList[i][j]);
            }
        }
        free(seatList[i]);
    }
    free(seatList);
}

void SeatSave(Seat*** NewNSeat) {
    static int seatListSize = 0;
    seatListSize++;
    NCanSeatList = realloc(NCanSeatList, seatListSize * sizeof(Seat***));
    NCanSeatList[seatListSize - 1] = NewNSeat;
}

Seat*** AmultiB(Seat*** aSeat, Seat*** bSeat) {
    Seat*** result = createSeatList(gridY, gridX);
    for (int i = 0; i < gridY; i++) {
        for (int j = 0; j < gridX; j++) {
            if (aSeat[i][j] != NULL) {
                for (int k = 0; k < gridY; k++) {
                    if (bSeat[aSeat[i][j]->y][aSeat[i][j]->x] != NULL) {
                        Seat newSeat = {bSeat[aSeat[i][j]->y][aSeat[i][j]->x]->y,
                                         bSeat[aSeat[i][j]->y][aSeat[i][j]->x]->x,
                                         (aSeat[i][j]->cnt * bSeat[aSeat[i][j]->y][aSeat[i][j]->x]->cnt) % CONST_DIV};
                        result[i][j] = realloc(result[i][j], (result[i][j] == NULL ? 1 : result[i][j]->cnt + 1) * sizeof(Seat));
                        result[i][j][result[i][j]->cnt] = newSeat;
                    }
                }
            }
        }
    }
    return result;
}

void AnsCalc(long long k) {
    Seat*** realSeat = createSeatList(gridY, gridX);
    for (int i = 0; i < gridY; i++) {
        for (int j = 0; j < gridX; j++) {
            realSeat[i][j] = NULL;
        }
    }
    int bitIndex = 0;
    while (k > 0) {
        if (k & 1) {
            realSeat = AmultiB(realSeat, NCanSeatList[bitIndex]);
        }
        bitIndex++;
        k >>= 1;
    }
    freeSeatList(realSeat, gridY, gridX);
}

int solution(int** grid, size_t grid_rows, size_t grid_cols, int d[], size_t d_len, int k) {
    gridY = grid_rows;
    gridX = grid_cols;
    dSize = d_len;
    realGrid = grid;
    realD = d;

    visitedV = (int***)malloc(gridY * sizeof(int**));
    for (int i = 0; i < gridY; i++) {
        visitedV[i] = (int**)malloc(gridX * sizeof(int*));
        for (int j = 0; j < gridX; j++) {
            visitedV[i][j] = (int*)malloc(dSize * sizeof(int));
            for (int k = 0; k < dSize; k++) {
                visitedV[i][j][k] = -1;
            }
        }
    }

    NCanSeatList = (Seat****)malloc(sizeof(Seat***));
    NCanSeatList[0] = createSeatList(gridY, gridX);
    AnsCalc(k);

    freeSeatList(NCanSeatList[0], gridY, gridX);
    free(NCanSeatList);

    for (int i = 0; i < gridY; i++) {
        for (int j = 0; j < gridX; j++) {
            free(visitedV[i][j]);
        }
        free(visitedV[i]);
    }
    free(visitedV);

    return 0;
}
