#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* letter) {
    char* morse[] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };

    int idx = 0;
    char* answer = (char*)malloc(1000);
    char* cut_morse = strtok(letter, " ");
    memset(answer, 0, 1000);

    while (cut_morse != NULL) {
        for (int i = 0; i < 26; i++) {
            if (strcmp(cut_morse, morse[i]) == 0) {
                answer[idx++] = 97 + i;
                break;
            }
        }
        cut_morse = strtok(NULL, " ");
    }

    return answer;
}