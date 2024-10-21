#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int** board, size_t board_rows, size_t board_cols) {
    int answer = 0;

    int xy[9][2] = { {1, 1}, {1, 0}, {1, -1}, {0, -1}, {0, 0}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1} };

    for (size_t i = 0; i < board_rows; i++) {
        for (size_t j = 0; j < board_cols; j++) {
            int check = 1;

            for (int k = 0; k < 9; k++) {
                int ni = i + xy[k][0];
                int nj = j + xy[k][1];
                if (ni >= 0 && ni < board_rows && nj >= 0 && nj < board_cols && board[ni][nj] == 1) {
                    check = 0;
                    break;
                }
            }
            answer += check;
        }
    }

    return answer;
}
