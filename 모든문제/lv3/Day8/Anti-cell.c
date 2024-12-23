#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MOD 1000000007

typedef struct {
    long long key;
    int value;
} Pair;

typedef struct {
    Pair* data;
    size_t size;
    size_t capacity;
} Map;

void map_init(Map* map, size_t capacity) {
    map->data = (Pair*)malloc(sizeof(Pair) * capacity);
    map->size = 0;
    map->capacity = capacity;
}

void map_free(Map* map) {
    free(map->data);
    map->data = NULL;
    map->size = 0;
    map->capacity = 0;
}

int map_find(Map* map, long long key) {
    for (size_t i = 0; i < map->size; i++) {
        if (map->data[i].key == key) {
            return map->data[i].value;
        }
    }
    return -1;
}

void map_insert(Map* map, long long key, int value) {
    if (map->size < map->capacity) {
        map->data[map->size].key = key;
        map->data[map->size].value = value;
        map->size++;
    }
}

long long connect(long long num, int here, int par, Map* levels, long long* sum) {
    if (map_find(&levels[here], num) == -1) {
        map_insert(&levels[here], num, par);
    }

    long long ret = sum[par];
    int parent_value = map_find(&levels[par], num);
    if (parent_value != -1) {
        ret += connect(num * 2, here, parent_value, levels, sum);
        ret %= MOD;
    }

    return ret;
}

int* solution(int a[], size_t a_len, int s[], size_t s_len) {
    static Map levels[200001];
    static long long sum[200001];

    for (int i = 0; i < 200001; i++) {
        map_init(&levels[i], 1000);
    }

    int *answer = (int*)malloc(sizeof(int) * s_len);

    int start = 0, end = 0;
    for (size_t t = 0; t < s_len; t++) {
        int n = s[t];
        start = end;
        end = start + n;

        map_free(&levels[start]);
        map_init(&levels[start], 1000);
        map_insert(&levels[start], -1, -1);
        sum[start] = 1;

        for (int i = start + 1; i <= end; i++) {
            sum[i] = connect(a[i - 1], i, i - 1, levels, sum);
        }

        answer[t] = sum[end];
    }

    for (int i = 0; i < 200001; i++) {
        map_free(&levels[i]);
    }

    return answer;
}