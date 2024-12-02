#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int y;
    int x;
} Pos;

int GetSquareDir(Pos p1, Pos p2) {
    int dirY = p1.y - p2.y;
    int dirX = p1.x - p2.x;
    return (dirY * dirY) + (dirX * dirX);
}

int* solution(int m, int n, int startX, int startY, int** balls, size_t balls_rows, size_t balls_cols) {
    int* answer = (int*)malloc(balls_rows * sizeof(int));
    if (!answer) {
        perror("Memory allocation failed");
        return NULL;
    }

    Pos startPos = { startY, startX };

    for (size_t i = 0; i < balls_rows; i++) {
        int posY = balls[i][1];
        int posX = balls[i][0];
        Pos movePos;
        int minDir = INT_MAX;

        if (!(posX > startPos.x && posY == startPos.y)) {
            movePos.y = posY;
            movePos.x = 2 * m - posX;
            int dist = GetSquareDir(startPos, movePos);
            if (dist < minDir) {
                minDir = dist;
            }
        }

        if (!(posY > startPos.y && posX == startPos.x)) {
            movePos.y = 2 * n - posY;
            movePos.x = posX;
            int dist = GetSquareDir(startPos, movePos);
            if (dist < minDir) {
                minDir = dist;
            }
        }

        if (!(posY < startPos.y && posX == startPos.x)) {
            movePos.y = -posY;
            movePos.x = posX;
            int dist = GetSquareDir(startPos, movePos);
            if (dist < minDir) {
                minDir = dist;
            }
        }

        if (!(posX < startPos.x && posY == startPos.y)) {
            movePos.y = posY;
            movePos.x = -posX;
            int dist = GetSquareDir(startPos, movePos);
            if (dist < minDir) {
                minDir = dist;
            }
        }

        answer[i] = minDir;
    }

    return answer;
}
