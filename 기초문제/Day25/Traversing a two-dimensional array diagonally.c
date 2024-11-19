#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int** board, size_t board_rows, size_t board_cols, int k) {
	int answer = 0;
	for (int i = 0; i < board_rows; i++)
		for (int j = 0; j < board_cols; j++)
			if (i + j <= k)
				answer += board[i][j];
	return answer;
}