#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int score;
    int score2;
    int idx;
} Employee;

int cmp(const void* a, const void* b) {
    Employee* e1 = (Employee*)a;
    Employee* e2 = (Employee*)b;
    return e2->score - e1->score;
}

int solution(int** scores, size_t scores_rows, size_t scores_cols) {
    int target = scores[0][0] + scores[0][1];

    Employee employees[scores_rows];

    for (size_t i = 0; i < scores_rows; i++) {
        if (scores[i][0] > scores[0][0] && scores[i][1] > scores[0][1]) {
            return -1;
        }
        employees[i].score = scores[i][0];
        employees[i].score2 = scores[i][1];
        employees[i].idx = i;
    }

    qsort(employees, scores_rows, sizeof(Employee), cmp);

    int sum2cnt[10001] = { 0 };
    int scoreList[scores_rows];
    int scoreListSize = 0;

    for (size_t i = 0; i < scores_rows; i++) {
        bool flag = true;
        Employee e = employees[i];

        for (size_t j = 0; j < i; j++) {
            Employee firstScoreHigherOrEqual = employees[j];

            if (firstScoreHigherOrEqual.score > e.score &&
                firstScoreHigherOrEqual.score2 > e.score2) {
                flag = false;
                break;
            }
        }

        if (!flag) {
            continue;
        }

        int sum = e.score + e.score2;

        if (sum2cnt[sum] == 0) {
            scoreList[scoreListSize++] = sum;
        }

        sum2cnt[sum]++;
    }

    for (int i = 0; i < scoreListSize - 1; i++) {
        for (int j = 0; j < scoreListSize - i - 1; j++) {
            if (scoreList[j] > scoreList[j + 1]) {
                int temp = scoreList[j];
                scoreList[j] = scoreList[j + 1];
                scoreList[j + 1] = temp;
            }
        }
    }

    int answer = 1;

    for (int i = scoreListSize - 1; i >= 0; i--) {
        if (scoreList[i] == target) {
            return answer;
        }
        answer += sum2cnt[scoreList[i]];
    }

    return answer;
}
