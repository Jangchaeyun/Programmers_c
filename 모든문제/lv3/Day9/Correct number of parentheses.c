#include <stdio.h>
#include <stdlib.h>

int solution(int n) {
    int *dp = (int*)malloc((n + 1) * sizeof(int));

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;

    for (int i = 4; i <= n; i++) {
        dp[i] = 0;
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    int answer = dp[n];

    free(dp);

    return answer;
}