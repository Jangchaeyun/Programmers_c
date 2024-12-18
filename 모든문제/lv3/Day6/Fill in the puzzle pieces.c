#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 51

typedef struct {
    int first;
    int second;
} Pair;

int answer = 0;
int N;
bool visit[MAX_N][MAX_N];
Pair queue[MAX_N * MAX_N];
int front, rear;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void initQueue() {
    front = rear = 0;
}

void push(Pair p) {
    queue[rear++] = p;
}

Pair pop() {
    return queue[front++];
}

bool isEmpty() {
    return front == rear;
}

Pair* repos_zero(Pair* pos, int size) {
    int min_i = MAX_N, min_j = MAX_N;

    for (int i = 0; i < size; i++) {
        if (pos[i].first < min_i) min_i = pos[i].first;
        if (pos[i].second < min_j) min_j = pos[i].second;
    }
    for (int i = 0; i < size; i++) {
        pos[i].first -= min_i;
        pos[i].second -= min_j;
    }
    return pos;
}

Pair* bfs(int** map, int value, int i, int j, int* out_size) {
    visit[i][j] = true;
    initQueue();
    push((Pair){i, j});

    Pair* v = (Pair*)malloc(MAX_N * MAX_N * sizeof(Pair));
    int size = 0;

    while (!isEmpty()) {
        Pair curr = pop();
        v[size++] = curr;

        for (int d = 0; d < 4; d++) {
            int ny = curr.first + dy[d];
            int nx = curr.second + dx[d];
            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            if (visit[ny][nx] || map[ny][nx] != value) continue;

            visit[ny][nx] = true;
            push((Pair){ny, nx});
        }
    }

    *out_size = size;
    return repos_zero(v, size);
}

void rot(Pair* pos, int size) {
    int row = 0;
    for (int i = 0; i < size; i++) {
        if (pos[i].first > row) row = pos[i].first;
    }
    for (int i = 0; i < size; i++) {
        int y = pos[i].first;
        int x = pos[i].second;
        pos[i].first = x;
        pos[i].second = row - y;
    }
}

void matching(Pair** empties, int* empty_sizes, int empty_count, Pair** puzzles, int* puzzle_sizes, int puzzle_count) {
    bool* puzzle_visit = (bool*)calloc(puzzle_count, sizeof(bool));

    for (int e_idx = 0; e_idx < empty_count; e_idx++) {
        Pair* empty = empties[e_idx];
        int empty_size = empty_sizes[e_idx];

        for (int p_idx = 0; p_idx < puzzle_count; p_idx++) {
            if (puzzle_visit[p_idx]) continue;

            Pair* puzzle = puzzles[p_idx];
            int puzzle_size = puzzle_sizes[p_idx];
            if (empty_size != puzzle_size) continue;

            bool matched = false;
            for (int r = 0; r < 4; r++) {
                int k = 0;
                for (int i = 0; i < empty_size; i++) {
                    for (int j = 0; j < puzzle_size; j++) {
                        if (empty[i].first == puzzle[j].first && empty[i].second == puzzle[j].second) {
                            k++;
                        }
                    }
                }
                if (k == empty_size) {
                    answer += empty_size;
                    puzzle_visit[p_idx] = true;
                    matched = true;
                    break;
                }
                rot(puzzle, puzzle_size);
            }
            if (matched) break;
        }
    }
    free(puzzle_visit);
}

int solution(int** game_board, size_t game_board_rows, size_t game_board_cols, int** table, size_t table_rows, size_t table_cols) {
    N = game_board_rows;

    Pair* empties[MAX_N * MAX_N];
    int empty_sizes[MAX_N * MAX_N];
    int empty_count = 0;

    memset(visit, false, sizeof(visit));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (game_board[i][j] == 0 && !visit[i][j]) {
                int size;
                empties[empty_count++] = bfs(game_board, 0, i, j, &size);
                empty_sizes[empty_count - 1] = size;
            }
        }
    }

    Pair* puzzles[MAX_N * MAX_N];
    int puzzle_sizes[MAX_N * MAX_N];
    int puzzle_count = 0;

    memset(visit, false, sizeof(visit));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (table[i][j] == 1 && !visit[i][j]) {
                int size;
                puzzles[puzzle_count++] = bfs(table, 1, i, j, &size);
                puzzle_sizes[puzzle_count - 1] = size;
            }
        }
    }

    matching(empties, empty_sizes, empty_count, puzzles, puzzle_sizes, puzzle_count);

    for (int i = 0; i < empty_count; i++) free(empties[i]);
    for (int i = 0; i < puzzle_count; i++) free(puzzles[i]);

    return answer;
}
