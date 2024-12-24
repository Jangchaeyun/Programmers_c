#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int sum[2001];

int solution(int cookie[], int cookie_len) {
    int answer = 0;

    for (int i = 0;i < cookie_len; i++){
        sum[i+1] = sum[i] + cookie[i];
    }

    for (int m = 1; m < cookie_len; m++){
        int first_son = sum[m];

        for(int r = m+1; r <= cookie_len; r++){
            int second_son = sum[r] - sum[m];

            if(answer > second_son || second_son > first_son) continue;

            for(int l = 0; l < m; l++){
                if(first_son - sum[l] == second_son && answer < second_son){
                    answer = second_son;
                    break;
                }
            }
        }
    }

    return answer;
}