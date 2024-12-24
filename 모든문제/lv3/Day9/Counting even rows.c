#include <stdio.h>
#include <stdlib.h>
#define MODULER 10000019

void Calculate_Combination(long long **V, int Row) {
    V[0][0] = 1;
    for (int i = 1; i <= Row; i++) {
        for (int j = 0; j <= Row; j++) {
            if (j == 0) V[i][j] = 1;
            else if (i == j) V[i][j] = 1;
            else V[i][j] = V[i - 1][j - 1] + V[i - 1][j];
            V[i][j] %= MODULER;
        }
    }
}

void Calculate_OneCnt(int *V, int **MAP, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            V[j] += MAP[i][j];
        }
    }
}

int solution(int **a, int rows, int cols) {
    long long **nCr = (long long **)malloc((rows + 1) * sizeof(long long *));
    for (int i = 0; i <= rows; i++) {
        nCr[i] = (long long *)malloc((rows + 1) * sizeof(long long));
        for (int j = 0; j <= rows; j++) nCr[i][j] = 0;
    }
    Calculate_Combination(nCr, rows);

    int *Arr_OneCnt = (int *)malloc((cols + 1) * sizeof(int));
    for (int i = 0; i <= cols; i++) Arr_OneCnt[i] = 0;
    Calculate_OneCnt(Arr_OneCnt, a, rows, cols);

    long long **DP = (long long **)malloc((cols + 2) * sizeof(long long *));
    for (int i = 0; i <= cols + 1; i++) {
        DP[i] = (long long *)malloc((rows + 1) * sizeof(long long));
        for (int j = 0; j <= rows; j++) DP[i][j] = 0;
    }
    DP[1][rows - Arr_OneCnt[0]] = nCr[rows][rows - Arr_OneCnt[0]];

    for (int Column = 1; Column < cols; Column++) {
        int OneCnt = Arr_OneCnt[Column];
        for (int Even_Num = 0; Even_Num <= rows; Even_Num++) {
            if (DP[Column][Even_Num] == 0) continue;
            for (int K = 0; K <= OneCnt; K++) {
                if (Even_Num < K) continue;
                int Be_Even_Row = Even_Num + OneCnt - (2 * K);
                if (Be_Even_Row > rows) continue;
                long long Result = (nCr[Even_Num][K] * nCr[rows - Even_Num][OneCnt - K]) % MODULER;
                DP[Column + 1][Be_Even_Row] = (DP[Column + 1][Be_Even_Row] + DP[Column][Even_Num] * Result) % MODULER;
            }
        }
    }

    int result = DP[cols][rows];

    for (int i = 0; i <= rows; i++) free(nCr[i]);
    free(nCr);
    for (int i = 0; i <= cols + 1; i++) free(DP[i]);
    free(DP);
    free(Arr_OneCnt);

    return result;
}
