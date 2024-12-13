#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MOD 10007

int solution(int n, int tops[], size_t tops_len) {
	int aS = 0, S = 1;
	int paS = 0, pS = 1;

	for (size_t i = 0; i < tops_len; i++) {
		aS = (paS + pS) % MOD;
		if (tops[i] == 1) {
			S = (pS * 3 + paS * 2) % MOD;
		}
		else {
			S = (2 * pS + paS) % MOD;
		}
		paS = aS;
		pS = S;
	}
	return (S + aS) % MOD;
}