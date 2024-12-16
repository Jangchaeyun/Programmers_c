#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 10001

// 트리 저장 구조
int tree[MAX_N][MAX_N];
int tree_size[MAX_N];
bool visited[MAX_N];
int retAns = 0;

void DFS(int nowNode, int parNode) {
    for (int i = 0; i < tree_size[nowNode]; i++) {
        int nextNode = tree[nowNode][i];
        if (nextNode != parNode) {
            DFS(nextNode, nowNode);
            if (!visited[nowNode] && !visited[nextNode]) {
                visited[nowNode] = true;
                retAns += 1;
            }
        }
    }
}

int solution(int n, int** lighthouse, size_t lighthouse_rows, size_t lighthouse_cols) {
    memset(tree, 0, sizeof(tree));
    memset(tree_size, 0, sizeof(tree_size));
    memset(visited, false, sizeof(visited));
    retAns = 0;

    for (size_t i = 0; i < lighthouse_rows; i++) {
        int a = lighthouse[i][0];
        int b = lighthouse[i][1];
        tree[a][tree_size[a]++] = b;
        tree[b][tree_size[b]++] = a;
    }

    DFS(1, -1);
    return retAns;
}