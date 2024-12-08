#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int dfs(int start, bool* visited, int** graph, int* graph_sizes) {
    int nodes = 1;
    visited[start] = true;

    for (int i = 0; i < graph_sizes[start]; i++) {
        int node = graph[start][i];
        if (!visited[node]) {
            nodes += dfs(node, visited, graph, graph_sizes);
        }
    }

    return nodes;
}

int solution(int n, int** wires, size_t wires_rows) {
    int answer = n;

    for (size_t i = 0; i < wires_rows; i++) {
        int** graph = (int**)malloc((n + 1) * sizeof(int*));
        int* graph_sizes = (int*)calloc(n + 1, sizeof(int));

        for (int j = 0; j <= n; j++) {
            graph[j] = (int*)malloc(n * sizeof(int));
        }

        for (size_t j = 0; j < wires_rows; j++) {
            if (i != j) {
                int a = wires[j][0];
                int b = wires[j][1];

                graph[a][graph_sizes[a]++] = b;
                graph[b][graph_sizes[b]++] = a;
            }
        }

        bool* visited = (bool*)calloc(n + 1, sizeof(bool));

        int a = wires[i][0];
        int nodesA = dfs(a, visited, graph, graph_sizes);
        int nodesB = n - nodesA;

        int diff = abs(nodesA - nodesB);
        if (diff < answer) {
            answer = diff;
        }

        for (int j = 0; j <= n; j++) {
            free(graph[j]);
        }
        free(graph);
        free(graph_sizes);
        free(visited);
    }

    return answer;
}
