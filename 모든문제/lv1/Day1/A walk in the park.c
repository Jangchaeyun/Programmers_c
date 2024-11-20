#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 }; 

int get_direction_index(const char* dir) {
    if (strcmp(dir, "N") == 0) return 0;
    if (strcmp(dir, "S") == 0) return 1;
    if (strcmp(dir, "W") == 0) return 2;
    if (strcmp(dir, "E") == 0) return 3;
    return -1;
}

int* solution(const char* park[], size_t park_len, const char* routes[], size_t routes_len) {
    char** map = (char**)malloc(park_len * sizeof(char*));
    int start_x = 0, start_y = 0;
    for (size_t i = 0; i < park_len; i++) {
        map[i] = strdup(park[i]);
        for (size_t j = 0; j < strlen(park[i]); j++) {
            if (park[i][j] == 'S') {
                start_x = i;
                start_y = j;
            }
        }
    }

    int x = start_x, y = start_y;

    for (size_t i = 0; i < routes_len; i++) {
        char direction[2];
        int move;
        sscanf(routes[i], "%1s %d", direction, &move);
        int dir_idx = get_direction_index(direction);

        if (dir_idx == -1) continue;

        int temp_x = x, temp_y = y;
        bool valid = true;

        for (int j = 0; j < move; j++) {
            temp_x += dx[dir_idx];
            temp_y += dy[dir_idx];

            if (temp_x < 0 || temp_x >= (int)park_len || temp_y < 0 || temp_y >= (int)strlen(park[0])) {
                valid = false;
                break;
            }

            if (map[temp_x][temp_y] == 'X') {
                valid = false;
                break;
            }
        }

        if (valid) {
            x = temp_x;
            y = temp_y;
        }
    }

    int* answer = (int*)malloc(2 * sizeof(int));
    answer[0] = x;
    answer[1] = y;

    for (size_t i = 0; i < park_len; i++) {
        free(map[i]);
    }
    free(map);

    return answer;
}