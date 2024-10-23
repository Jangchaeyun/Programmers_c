#include <stdio.h>
#include <stdlib.h>

int* solution(int** score, size_t score_rows, size_t score_cols) {
    int* total_scores = (int*)malloc(score_rows * sizeof(int));
    int* answer = (int*)malloc(score_rows * sizeof(int));

    for (size_t i = 0; i < score_rows; i++) {
        total_scores[i] = score[i][0] + score[i][1];
    }

    for (size_t i = 0; i < score_rows; i++) {
        int rank = 1;
        for (size_t j = 0; j < score_rows; j++) {
            if (total_scores[i] < total_scores[j]) {
                rank++;
            }
        }
        answer[i] = rank;
    }

    free(total_scores);

    return answer;
}
