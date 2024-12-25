#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point start, end;
} Edge;

#define MAX_NODES 100000

int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int hash_point(Point p) {
    return (p.x + 50000) * 100000 + (p.y + 50000);
}

int hash_edge(Edge e) {
    return hash_point(e.start) * 1000000 + hash_point(e.end);
}

bool node_visit[MAX_NODES] = {false};
bool edge_visit[MAX_NODES] = {false};

int solution(int arrows[], size_t arrows_m) {
    int answer = 0;
    int x = 0, y = 0;

    node_visit[hash_point((Point){x, y})] = true;

    for (size_t i = 0; i < arrows_m; i++) {
        int dir = arrows[i];

        for (int j = 0; j < 2; j++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            Point curr_point = {x, y};
            Point next_point = {nx, ny};
            Edge edge = {curr_point, next_point};

            int edge_hash = hash_edge(edge);
            int reverse_edge_hash = hash_edge((Edge){next_point, curr_point});

            if (node_visit[hash_point(next_point)] && !edge_visit[edge_hash]) {
                edge_visit[edge_hash] = true;
                edge_visit[reverse_edge_hash] = true;
                answer++;
                x = nx;
                y = ny;
                continue;
            }

            node_visit[hash_point(next_point)] = true;
            edge_visit[edge_hash] = true;
            edge_visit[reverse_edge_hash] = true;

            x = nx;
            y = ny;
        }
    }

    return answer;
}
