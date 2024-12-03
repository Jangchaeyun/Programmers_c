#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int countMark(const char board[3][3], char mark) {
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == mark) count++;
        }
    }
    return count;
}

bool playerWin(const char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if (board[0][i] == player && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }
    if (board[0][0] == player && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if (board[2][0] == player && board[2][0] == board[1][1] && board[1][1] == board[0][2])
        return true;
    return false;
}

bool fairTurn(const char board[3][3]) {
    int countX = 0;
    int countO = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'O') countO++;
            if (board[i][j] == 'X') countX++;
        }
    }
    return !(countO - countX > 1 || countO < countX);
}

int solution(const char* board[], size_t board_len) {
    char boardArray[3][3];

    for (int i = 0; i < 3; i++) {
        strncpy(boardArray[i], board[i], 3);
    }

    int cntO = countMark(boardArray, 'O');
    int cntX = countMark(boardArray, 'X');

    if (!fairTurn(boardArray))
        return 0;

    if (playerWin(boardArray, 'O') && cntO - cntX != 1)
        return 0;

    if (playerWin(boardArray, 'X') && cntO - cntX != 0)
        return 0;

    if (playerWin(boardArray, 'O') && playerWin(boardArray, 'X'))
        return 0;

    return 1;
}
