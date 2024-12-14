#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007

int solution(int n) {
    long long* DP = (long long*)malloc((n + 1) * sizeof(long long));
    long long* nuDP = (long long*)malloc((n + 1) * sizeof(long long));

    DP[0] = 1;
    DP[1] = 1;
    DP[2] = 3;
    DP[3] = 10;

    nuDP[0] = 1;
    nuDP[1] = 1;
    nuDP[2] = 3;
    nuDP[3] = 11;

    for (int i = 4; i <= n; i++) {
        DP[i] = DP[i - 1] + DP[i - 3];
        DP[i] += nuDP[i - 3] * 4;
        DP[i] += nuDP[i - 4] * 2;
        DP[i] += nuDP[i - 2] * 2;
        DP[i] %= MOD;

        nuDP[i] = nuDP[i - 3] + DP[i];
        nuDP[i] %= MOD;
    }

    int result = DP[n] % MOD;
    free(DP);
    free(nuDP);

    return result;
}
