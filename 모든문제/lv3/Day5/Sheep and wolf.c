#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 20
#define MAX_SHEEP 20

int node[MAX_NODES][MAX_NODES];
int nodeCount[MAX_NODES];
int state[MAX_NODES];
int maxSheep;
bool visit[MAX_NODES][MAX_SHEEP][MAX_SHEEP];
int nodeSize;

void makeConnection(int** edges, size_t edges_rows) {
	for (size_t i = 0; i < edges_rows; i++) {
		int a = edges[i][0];
		int b = edges[i][1];
		node[a][nodeCount[a]++] = b;
		node[b][nodeCount[b]++] = a;
	}
}

void dfs(int cur, int sheep, int wolf) {
    if (cur == 0) {
        if (sheep > maxSheep) {
            maxSheep = sheep;
        }
    }

    for (int i = 0; i < nodeCount[cur]; i++) {
        int next = node[cur][i];

        if (state[next] == 0) {
            if (!visit[next][sheep + 1][wolf]) {
                visit[next][sheep + 1][wolf] = true;
                state[next] = -1;
                dfs(next, sheep + 1, wolf);
                state[next] = 0;
                visit[next][sheep + 1][wolf] = false;
            }
        }
        else if (state[next] == 1) {
            if (!visit[next][sheep][wolf + 1] && sheep > wolf + 1) {
                visit[next][sheep][wolf + 1] = true;
                state[next] = -1;
                dfs(next, sheep, wolf + 1);
                state[next] = 1;
                visit[next][sheep][wolf + 1] = false;
            }
        }
        else {
            if (!visit[next][sheep][wolf]) {
                visit[next][sheep][wolf] = true;
                dfs(next, sheep, wolf);
                visit[next][sheep][wolf] = false;
            }
        }
    }
}

int solution(int info[], size_t info_len, int** edges, size_t edges_rows, size_t edges_cols) {
    memset(nodeCount, 0, sizeof(nodeCount));
    memset(visit, false, sizeof(visit));
    makeConnection(edges, edges_rows);

    for (size_t i = 0; i < info_len; i++) {
        state[i] = info[i];
    }

    state[0] = -1;
    visit[0][1][0] = true;
    maxSheep = 0;

    dfs(0, 1, 0);

    return maxSheep;
}