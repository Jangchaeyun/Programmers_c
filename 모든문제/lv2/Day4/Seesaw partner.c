#include <stdbool.h>
#include <stddef.h>

#define MAX 2001

long long dp[MAX];
bool vis[MAX];

long long solution(int weights[], size_t weights_len) {
	long long answer = 0;

	for (size_t i = 0; i < weights_len; ++i) {
		dp[weights[i]] += 1;
	}

	for (size_t i = 0; i < weights_len; ++i) {
		int weight = weights[i];

		if (dp[weight] > 1 && !vis[weight]) {
			answer += dp[weight] * (dp[weight] - 1) / 2;
			vis[weight] = true;
		}

		if (2 * weight < MAX && dp[2 * weight]) {
			answer += dp[2 * weight];
		}

		if(weight % 3 == 0 && (weight / 3) * 4 < MAX && dp[(weight / 3) * 4]) {
			answer += dp[(weight / 3) * 4];
		}

		if (weight % 2 == 0 && (weight / 2) * 3 < MAX && dp[(weight / 2) * 3]) {
			answer += dp[(weight / 2) * 3];
		}
	}

	return answer;
}