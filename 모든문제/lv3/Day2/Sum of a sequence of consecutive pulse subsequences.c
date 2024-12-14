#include <stdio.h>
#include <stdlib.h>
#define INF 987654321

long long max1(long long a, long long b) {
	return (a > b) ? a : b;
}


long long solution(int* sequence, size_t sequence_len) {
    long long psum = 0;
    long long ret = -INF;
    long long* arr = (long long*)malloc(sequence_len * sizeof(long long));

    for (size_t i = 0; i < sequence_len; i++) {
        arr[i] = sequence[i];
        if (i % 2 == 1) {
            arr[i] *= -1;
        }
    }

    for (size_t i = 0; i < sequence_len; i++) {
        psum = max1(psum, 0) + arr[i];
        ret = max1(ret, psum);
    }

    psum = 0;
    for (size_t i = 0; i < sequence_len; i++) {
        psum = max1(psum, 0) - arr[i];
        ret = max1(ret, psum);
    }

    free(arr);
    return ret;
}
