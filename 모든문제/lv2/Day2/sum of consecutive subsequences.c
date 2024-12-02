#include <stdio.h>
#include <stdlib.h>

int* solution(int* sequence, size_t sequence_len, int k) {
    int* answer = (int*)malloc(2 * sizeof(int));
    answer[0] = 0;
    answer[1] = sequence_len;

    int s = 0, e = -1;
    int total = 0;

    while (e < (int)sequence_len) {
        if (total == k) {
            if ((e - s) < (answer[1] - answer[0])) {
                answer[0] = s;
                answer[1] = e;
            }
            total -= sequence[s];
            s++;
        }
        else if (total < k) {
            e++;
            if (e < (int)sequence_len) {
                total += sequence[e];
            }
        }
        else {
            total -= sequence[s];
            s++;
        }
    }

    return answer;
}