#include <stdio.h>
#include <stdbool.h>

typedef struct {
	int h, m, s;
} Time;

Time makeTime(int seconds) {
	Time t;
	t.h = seconds / 3600;
	t.m = (seconds % 3600) / 60;
	t.s = (seconds % 3600) % 60;
	return t;
}

int toSeconds(Time t) {
	return t.h * 3600 + t.m * 60 + t.s;
}

int getDegree(Time t, double degree[3]) {
	degree[0] = (t.h % 12) * 30.0 + t.m * 0.5 + t.s * (1 / 120.0);
	degree[1] = t.m * 6.0 + t.s * 0.1;
	degree[2] = t.s * 6.0;
}

bool hourMatch(double cnt[3], double next[3]) {
	if (cnt[0] > cnt[2] && next[0] <= next[2]) {
		return true;
	}
	if (cnt[2] == 354.0 && cnt[0] > 354.0) {
		return true;
	}
	return false;
}

bool minuteMatch(double cnt[3], double next[3]) {
	if (cnt[1] > cnt[2] && next[1] <= next[2]) {
		return true;
	}
	if (cnt[2] == 354.0 && cnt[1] > 354.0) {
		return true;
	}
	return false;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
	int answer = 0;

	int start = toSeconds(makeTime(h1 * 3600 + m1 * 60 + s1));
	int end = toSeconds(makeTime(h2 * 3600 + m2 * 60 + s2));

	for (int i = start; i < end; i++) {
		double cnt[3], next[3];
		getDegree(makeTime(i), cnt);
		getDegree(makeTime(i + 1), next);

		bool hMatch = hourMatch(cnt, next);
		bool mMatch = minuteMatch(cnt, next);

		if (hMatch && mMatch) {
			if (next[0] == next[1]) {
				answer++;
			}
			else {
				answer += 2;
			}
		}
		else if (hMatch || mMatch) {
			answer++;
		}
	}

	if (start == 0 || start == 43200) {
		answer++;
	}

	return answer;
}