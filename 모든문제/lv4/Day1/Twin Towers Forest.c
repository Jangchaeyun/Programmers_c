#include <stdio.h>
#define MOD 1000000007

int solution(int n, int count) {
    long long dp[n + 1][n + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    dp[1][1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i - 1][j] * (i - 1) * 2 + dp[i - 1][j - 1]) % MOD;
        }
    }

    return (int)dp[n][count];
}