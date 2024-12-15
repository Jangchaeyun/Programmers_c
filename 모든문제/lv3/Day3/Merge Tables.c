#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX 51
#define EMPTY "EMPTY"

char board[MAX][MAX][20];
int coord2coord[MAX][MAX][2];

void init() {
    for (int y = 0; y < MAX; y++) {
        for (int x = 0; x < MAX; x++) {
            coord2coord[y][x][0] = y;
            coord2coord[y][x][1] = x;
            strcpy(board[y][x], EMPTY);
        }
    }
}

void updateBoard(const char* prev, const char* cur) {
    for (int y = 0; y < MAX; y++) {
        for (int x = 0; x < MAX; x++) {
            if (strcmp(board[y][x], prev) == 0) {
                strcpy(board[y][x], cur);
            }
        }
    }
}

void merge(int rootY, int rootX, int root2Y, int root2X) {
    char value[20], value2[20];
    strcpy(value, board[rootY][rootX]);
    strcpy(value2, board[root2Y][root2X]);

    for (int y = 0; y < MAX; y++) {
        for (int x = 0; x < MAX; x++) {
            if (coord2coord[y][x][0] == root2Y && coord2coord[y][x][1] == root2X) {
                coord2coord[y][x][0] = rootY;
                coord2coord[y][x][1] = rootX;
            }
        }
    }

    if (strcmp(value2, EMPTY) != 0 && strcmp(value, EMPTY) == 0) {
        strcpy(board[rootY][rootX], value2);
    }
    else {
        strcpy(board[root2Y][root2X], value);
    }
}

void unmerge(int rootY, int rootX) {
    for (int y = 0; y < MAX; y++) {
        for (int x = 0; x < MAX; x++) {
            if (coord2coord[y][x][0] == rootY && coord2coord[y][x][1] == rootX) {
                coord2coord[y][x][0] = y;
                coord2coord[y][x][1] = x;
                strcpy(board[y][x], EMPTY);
            }
        }
    }
}

void findRoot(int r, int c, int* rootY, int* rootX) {
    *rootY = coord2coord[r][c][0];
    *rootX = coord2coord[r][c][1];
}

char** solution(const char* commands[], size_t commands_len) {
    init();
    char** answer = (char**)malloc(commands_len * sizeof(char*));
    size_t answer_index = 0;

    for (size_t i = 0; i < commands_len; i++) {
        char command[100];
        strcpy(command, commands[i]);

        char* token = strtok(command, " ");
        char* v[5];
        int v_index = 0;

        while (token != NULL) {
            v[v_index++] = token;
            token = strtok(NULL, " ");
        }

        int r, c, r2, c2;
        char value[20], value2[20];

        if (strcmp(v[0], "UPDATE") == 0) {
            if (v_index == 4) {
                r = atoi(v[1]);
                c = atoi(v[2]);
                strcpy(value, v[3]);

                int rootY, rootX;
                findRoot(r, c, &rootY, &rootX);
                strcpy(board[rootY][rootX], value);
            }
            else {
                strcpy(value, v[1]);
                strcpy(value2, v[2]);
                updateBoard(value, value2);
            }
        }
        else if (strcmp(v[0], "MERGE") == 0) {
            r = atoi(v[1]);
            c = atoi(v[2]);
            r2 = atoi(v[3]);
            c2 = atoi(v[4]);

            int rootY, rootX, root2Y, root2X;
            findRoot(r, c, &rootY, &rootX);
            findRoot(r2, c2, &root2Y, &root2X);

            if (rootY != root2Y || rootX != root2X) {
                merge(rootY, rootX, root2Y, root2X);
            }
        }
        else if (strcmp(v[0], "UNMERGE") == 0) {
            r = atoi(v[1]);
            c = atoi(v[2]);

            int rootY, rootX;
            findRoot(r, c, &rootY, &rootX);
            char temp[20];
            strcpy(temp, board[rootY][rootX]);
            unmerge(rootY, rootX);
            strcpy(board[r][c], temp);
        }
        else if (strcmp(v[0], "PRINT") == 0) {
            r = atoi(v[1]);
            c = atoi(v[2]);

            int rootY, rootX;
            findRoot(r, c, &rootY, &rootX);
            answer[answer_index] = (char*)malloc(20);
            strcpy(answer[answer_index++], board[rootY][rootX]);
        }
    }

    return answer;
}
