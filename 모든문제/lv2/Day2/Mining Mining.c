#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { DIAMOND = 0, IRON = 1, STONE = 2 } MineralType;

int AllList[3][3] = {
    {1, 1, 1},
    {5, 1, 1},
    {25, 5, 1}
};

int* MineralsIntList = NULL;
int ListSize = 0;
int answer = 1250;

void dfs(int picks[], int location, int sum) {
    int sumList[3] = { 0, 0, 0 };
    int savePoint = 0;

    if (ListSize <= location || (picks[0] + picks[1] + picks[2]) == 0) {
        if (sum < answer) {
            answer = sum;
        }
        return;
    }

    for (int i = location; i < location + 5; i++) {
        if (i >= ListSize) {
            savePoint = i;
            break;
        }
        sumList[0] += AllList[0][MineralsIntList[i]];
        sumList[1] += AllList[1][MineralsIntList[i]];
        sumList[2] += AllList[2][MineralsIntList[i]];
        savePoint = i;
    }

    for (int i = 0; i < 3; i++) {
        if (picks[i] != 0) {
            picks[i]--;
            dfs(picks, savePoint + 1, sum + sumList[i]);
            picks[i]++;
        }
    }
}

int solution(int picks[], size_t picks_len, const char* minerals[], size_t minerals_len) {
    ListSize = minerals_len;

    MineralsIntList = (int*)malloc(ListSize * sizeof(int));
    if (MineralsIntList == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return -1;
    }

    for (size_t i = 0; i < minerals_len; i++) {
        if (strcmp(minerals[i], "diamond") == 0) {
            MineralsIntList[i] = DIAMOND;
        }
        else if (strcmp(minerals[i], "iron") == 0) {
            MineralsIntList[i] = IRON;
        }
        else if (strcmp(minerals[i], "stone") == 0) {
            MineralsIntList[i] = STONE;
        }
    }

    dfs(picks, 0, 0);

    free(MineralsIntList);
    return answer;
}