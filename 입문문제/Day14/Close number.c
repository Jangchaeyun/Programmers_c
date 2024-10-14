#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int array[], size_t array_len, int n) {
    int answer = 0;
    int dif_min = abs(array[0] - n);
    int min;
    for (int i = 0; i < array_len; i++)
    {
        if (abs(n - array[i]) < dif_min) {
            dif_min = abs(n - array[i]);
            min = array[i];
        }
        if (abs(n - array[i]) == dif_min) {
            dif_min = abs(n - array[i]);
            if (array[i] < min)
                min = array[i];
        }
    }
    answer = min;
    return answer;
}