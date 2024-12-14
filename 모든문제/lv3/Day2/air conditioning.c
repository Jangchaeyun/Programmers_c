#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1010
#define TEMPERATURE_RANGE 50
#define INF 987654321

int cache[MAX][TEMPERATURE_RANGE + 1];

int solution(int temperature, int t1, int t2, int a, int b, int* onboard, size_t onboard_len) {
    if (temperature >= t1 && t2 >= temperature) {
        return 0;
    }

    temperature += 10;
    t1 += 10;
    t2 += 10;

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j <= TEMPERATURE_RANGE; j++) {
            cache[i][j] = INF;
        }
    }

    cache[0][temperature] = 0;

    for (size_t i = 0; i < onboard_len - 1; i++) {
        for (int j = 0; j <= TEMPERATURE_RANGE; j++) {
            if (onboard[i] && (t1 > j || j > t2)) {
                continue;
            }

            int nextTemperature = j;

            if (j < temperature && j < TEMPERATURE_RANGE) {
                nextTemperature++;
            }
            else if (j > temperature && j > 0) {
                nextTemperature--;
            }

            cache[i + 1][nextTemperature] = cache[i + 1][nextTemperature] < cache[i][j] ? cache[i + 1][nextTemperature] : cache[i][j];

            if (j > 0) {
                cache[i + 1][j - 1] = cache[i + 1][j - 1] < a + cache[i][j] ? cache[i + 1][j - 1] : a + cache[i][j];
            }

            if (j < TEMPERATURE_RANGE) {
                cache[i + 1][j + 1] = cache[i + 1][j + 1] < a + cache[i][j] ? cache[i + 1][j + 1] : a + cache[i][j];
            }

            cache[i + 1][j] = cache[i + 1][j] < b + cache[i][j] ? cache[i + 1][j] : b + cache[i][j];
        }
    }

    int result = INF;
    size_t len = onboard_len;

    for (int j = 0; j <= TEMPERATURE_RANGE; j++) {
        if (onboard[len - 1] == 1 && (t1 > j || j > t2)) {
            continue;
        }

        result = result < cache[len - 1][j] ? result : cache[len - 1][j];
    }

    return result;
}
