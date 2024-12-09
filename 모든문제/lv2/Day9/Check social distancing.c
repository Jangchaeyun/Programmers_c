#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(const char*** places, size_t places_rows, size_t places_cols) {
	int* answer = (int*)malloc(5 * sizeof(int));
	char** room;
	bool t;

	for (int i = 0; i < 5; i++) {
		room = places[i];
		t = true;
		for (int j = 0; j < 5 && t == true; j++) {
			for (int l = 0; l < 5 && t == true; l++) {
				if (room[j][l] == 'P') {
					if (l <= 3 && room[j][l + 1] != 'X') {
						if (room[j][l + 1] == 'P' || l <= 2 && room[j][l + 2] == 'P' || j <= 3 && room[j + 1][l + 1] == 'P' || j >= 1 && room[j - 1][l + 1] == 'P') {
							t = false;
							break;
						}
					}
					if (j <= 3 && room[j + 1][l] != 'X') {
						if (room[j + 1][l] == 'P' || j <= 2 && room[j + 2][l] == 'P' || l <= 3 && room[j + 1][l + 1] == 'P') {
							t = false;
							break;
						}
					}

					if (l >= 1 && j <= 3 && room[j][l - 1] != 'X' && room[j + 1][l - 1] == 'P') {
						t = false;
						break;
					}
					l++;
				}
			} 
		}
		if (t == true) answer[i] = 1;
		else answer[i] = 0;
	}

	return answer;
}