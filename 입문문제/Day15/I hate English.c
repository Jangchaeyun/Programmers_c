#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(const char* numbers) {
	long long answer = 0;
	int i = 0;
	while (numbers[i] != '\0') {
        if (strncmp(numbers + i, "one", 3) == 0) {
            answer = answer * 10 + 1;
            i += 3;
        }
        if (strncmp(numbers + i, "two", 3) == 0) {
            answer = answer * 10 + 2;
            i += 3;
        }
        if (strncmp(numbers + i, "three", 5) == 0) {
            answer = answer * 10 + 3;
            i += 5;
        }
        if (strncmp(numbers + i, "four", 4) == 0) {
            answer = answer * 10 + 4;
            i += 4;
        }
        if (strncmp(numbers + i, "five", 4) == 0) {
            answer = answer * 10 + 5;
            i += 4;
        }
        if (strncmp(numbers + i, "six", 3) == 0) {
            answer = answer * 10 + 6;
            i += 3;
        }
        if (strncmp(numbers + i, "seven", 5) == 0) {
            answer = answer * 10 + 7;
            i += 5;
        }
        if (strncmp(numbers + i, "eight", 5) == 0) {
            answer = answer * 10 + 8;
            i += 5;
        }
        if (strncmp(numbers + i, "nine", 4) == 0) {
            answer = answer * 10 + 9;
            i += 4;
        }
        if (strncmp(numbers + i, "zero", 4) == 0) {
            answer = answer * 10;
            i += 4;
        }
	}
    return answer;
}