#include <stdio.h>
#include <stdbool.h>

long long solution(int cap, int n, int deliveries[], size_t deliveries_len, int pickups[], size_t pickups_len) {
	long long answer = 0;
	int box = 0;
	int D_top = deliveries_len - 1;
	int P_top = pickups_len - 1;

	while (D_top >= 0 && deliveries[D_top] == 0)
		D_top--;
	while (P_top >= 0 && pickups[P_top] == 0)
		P_top--;

	while (D_top >= 0 || P_top >= 0) {
		int max_distance = (D_top > P_top ? D_top : P_top) + 1;
		answer += max_distance * 2;

		box = 0;
		while (D_top >= 0 && box < cap) {
			if (deliveries[D_top] + box <= cap) {
				box += deliveries[D_top];
				deliveries[D_top] = 0;
				D_top--;
			}
			else {
				deliveries[D_top] -= (cap - box);
				box = cap;
			}
		}

		box = 0;
		while (P_top >= 0 && box < cap) {
			if (pickups[P_top] + box <= cap) {
				box += pickups[P_top];
				pickups[P_top] = 0;
				P_top--;
			}
			else {
				pickups[P_top] -= (cap - box);
				box = cap;
			}
		}

		while (D_top >= 0 && deliveries[D_top] == 0)
			D_top--;
		while (P_top >= 0 && pickups[P_top] == 0)
			P_top--;
	}
	return answer;
}