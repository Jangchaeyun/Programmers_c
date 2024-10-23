#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const int* a, const int* b, const int* n) {
	int d1 = abs(*n - *a);
	int d2 = abs(*n - *b);

	if(d1 == d2) {
		return *b - *a;
	}
	else {
		return d1 - d2;
	}
};

int* solution(int numlist[], size_t numlist_len, int n) {
	int* answer = (int*)malloc(sizeof(int) * numlist_len);
	for (int i = 0; i < numlist_len; i++) {
		answer[i] = numlist[i];
	}
	qsort_r(answer, numlist_len, sizeof(int), compare, &n);
	return answer;
}