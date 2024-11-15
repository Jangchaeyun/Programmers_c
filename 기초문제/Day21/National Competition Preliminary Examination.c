#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
	int rank;
	int index;
} RankInfo;

int compare(const void* a, const void* b) {
	RankInfo* r1 = (RankInfo*)a;
	RankInfo* r2 = (RankInfo*)b;
	return r1->rank - r2->rank;
}

int solution(int rank[], size_t rank_len, bool attendance[], size_t attendance_len) {
	RankInfo attended[rank_len];
	int attended_count = 0;

	for (size_t i = 0; i < rank_len; ++i) {
		if (attendance[i]) {
			attended[attended_count].rank = rank[i];
			attended[attended_count].index = i;
			attended_count++;
		}
	}

	qsort(attended, attended_count, sizeof(RankInfo), compare);

	int answer = 10000 * attended[0].index + 100 * attended[1].index + attended[2].index;
	return answer;
}