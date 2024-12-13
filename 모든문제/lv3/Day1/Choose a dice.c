#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100
#define MAX_DICE_COMBINATIONS 1000

int ListA[MAX_DICE_COMBINATIONS][MAX_SIZE];
int ListB[MAX_DICE_COMBINATIONS][MAX_SIZE];
int ListASize[MAX_DICE_COMBINATIONS];
int ListBSize[MAX_DICE_COMBINATIONS];
int listCount = 0;

int SumA[MAX_DICE_COMBINATIONS];
int SumB[MAX_DICE_COMBINATIONS];
int sortnum = 0;
int choice = 0;

void MakeList(int now, int count, int* A, int ASize, int* B, int BSize) {
    if (ASize == count && BSize == count) {
        memcpy(ListA[listCount], A, ASize * sizeof(int));
        memcpy(ListB[listCount], B, BSize * sizeof(int));
        ListASize[listCount] = ASize;
        ListBSize[listCount] = BSize;
        listCount++;
        return;
    }

    if (ASize == count) {
        B[BSize] = now;
        MakeList(now + 1, count, A, ASize, B, BSize + 1);
    }
    else if (BSize == count) {
        A[ASize] = now;
        MakeList(now + 1, count, A, ASize + 1, B, BSize);
    }
    else {
        A[ASize] = now;
        MakeList(now + 1, count, A, ASize + 1, B, BSize);

        B[BSize] = now;
        MakeList(now + 1, count, A, ASize, B, BSize + 1);
    }
}

void sumCal(int count, int maxSum, int* List, int** dice, int dice_cols) {
    if (count == 0) {
        if (sortnum == 0) {
            SumA[listCount] = maxSum;
        }
        else {
            SumB[listCount] = maxSum;
        }
        return;
    }

    int index = List[count - 1];
    for (int i = 0; i < dice_cols; i++) {
        sumCal(count - 1, maxSum + dice[index][i], List, dice, dice_cols);
    }
}

int* diceCal(int** dice, int dice_rows, int dice_cols) {
    int Maxvictory = 0;
    int* MaxList = (int*)malloc(sizeof(int) * choice);

    for (int i = 0; i < listCount; i++) {
        sortnum = 0;
        sumCal(choice, 0, ListA[i], dice, dice_cols);

        sortnum = 1;
        sumCal(choice, 0, ListB[i], dice, dice_cols);

        int maxTemp = 0;
        for (int j = 0; j < MAX_DICE_COMBINATIONS; j++) {
            for (int k = 0; k < MAX_DICE_COMBINATIONS; k++) {
                if (SumA[j] > SumB[k]) {
                    maxTemp += 1;
                }
            }
        }

        if (maxTemp > Maxvictory) {
            Maxvictory = maxTemp;
            memcpy(MaxList, ListA[i], choice * sizeof(int));
        }
    }

    for (int i = 0; i < choice; i++) {
        MaxList[i] += 1;
    }

    return MaxList;
}

int* solution(int** dice, size_t dice_rows, size_t dice_cols) {
    int A[MAX_SIZE], B[MAX_SIZE];

    choice = dice_rows / 2;
    listCount = 0;

    MakeList(0, choice, A, 0, B, 0);

    return diceCal(dice, dice_rows, dice_cols);
}
