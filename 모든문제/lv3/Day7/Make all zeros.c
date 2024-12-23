#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void DFS(int** graph, long long* sum, int* graph_sizes, int now, int parent, long long* answer) {
    for (int i = 0; i < graph_sizes[now]; ++i) {
        if (graph[now][i] != parent) {
            DFS(graph, sum, graph_sizes, graph[now][i], now, answer);
        }
    }
    sum[parent] += sum[now];
    *answer += llabs(sum[now]);
}

long long solution(int a[], size_t a_len, int** edges, size_t edges_rows, size_t edges_cols) {
    long long answer = 0;

    int** graph = (int**)malloc(a_len * sizeof(int*));
    int* graph_sizes = (int*)calloc(a_len, sizeof(int));

    for (size_t i = 0; i < a_len; ++i) {
        graph[i] = NULL;
    }

    for (size_t i = 0; i < edges_rows; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];

        graph[u] = (int*)realloc(graph[u], (graph_sizes[u] + 1) * sizeof(int));
        graph[v] = (int*)realloc(graph[v], (graph_sizes[v] + 1) * sizeof(int));

        graph[u][graph_sizes[u]++] = v;
        graph[v][graph_sizes[v]++] = u;
    }

    long long* sum = (long long*)malloc(a_len * sizeof(long long));
    for (size_t i = 0; i < a_len; ++i) {
        sum[i] = a[i];
    }

    DFS(graph, sum, graph_sizes, 0, 0, &answer);

    long long result = (sum[0] == 0) ? answer : -1;

    for (size_t i = 0; i < a_len; ++i) {
        free(graph[i]);
    }
    free(graph);
    free(graph_sizes);
    free(sum);

    return result;
}
