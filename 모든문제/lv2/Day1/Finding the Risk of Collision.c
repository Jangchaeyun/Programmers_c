#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1000005


int inde[MAX_NODES];
int outde[MAX_NODES];
int path[MAX_NODES][10];
int path_size[MAX_NODES];
int t8 = 0, t1 = 0, t0 = 0;

void check(int start) {
	int queue[MAX_NODES];
	int front = 0, rear = 0;
	bool is_visited = false;

	queue[rear++] = start;

	while (front < rear) {
		int now = queue[front++];

		if (now == start && is_visited) {
			t0++;
			return;
		}

		if (path_size[now] >= 2) {
			t8++;
			return;
		}

		for (int i = 0; i < path_size[now]; i++) {
			queue[rear++] = path[now][i];
		}
		is_visited = true;
	}
	t1++;
	return;
}

int* solution(int** edges, int edges_rows, int edges_cols, int* return_size) {
	int* answer = (int*)malloc(4 * sizeof(int));

	for (int i = 0; i < MAX_NODES; i++) {
		inde[i] = 0;
		outde[i] = 0;
		path_size[i] = 0;
	}

	for (int i = 0; i < edges_rows; i++) {
		int from = edges[i][0];
		int to = edges[i][0];
		inde[to]++;
		outde[from]++;
		path[from][path_size[from]++] = to;
	}

	int start_nodes[MAX_NODES];
	int start_count = 0;
	
	for (int i = 1; i < MAX_NODES; i++) {
		if (inde[i] == 0 && outde[i] >= 1) {
			start_nodes[start_count++] = i;
		}
	}

	for (int i = 0; i < path_size[start_nodes[0]]; i++) {
		check(path[start_nodes[0]][i]);
	}

	answer[0] = start_nodes[0];
	answer[1] = t0;
	answer[2] = t1;
	answer[3] = t8;
	*return_size = 4;

	return answer;
}