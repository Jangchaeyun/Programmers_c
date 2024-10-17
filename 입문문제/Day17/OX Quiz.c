#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** solution(char** quiz, int quizSize, int* returnSize) {
    char** answer = (char**)malloc(quizSize * sizeof(char*));
    *returnSize = quizSize;

    for (int i = 0; i < quizSize; i++) {
        char* token;
        char* s_list[5];
        int idx = 0;

        char* str = strdup(quiz[i]);
        token = strtok(str, " ");

        while (token != NULL) {
            s_list[idx++] = token;
            token = strtok(NULL, " ");
        }

        int num1 = atoi(s_list[0]);
        int num2 = atoi(s_list[2]);
        int result = atoi(s_list[4]);

        if (strcmp(s_list[1], "+") == 0) {
            if (num1 + num2 == result) {
                answer[i] = strdup("O");
            }
            else {
                answer[i] = strdup("X");
            }
        }
        else if (strcmp(s_list[1], "-") == 0) {
            if (num1 - num2 == result) {
                answer[i] = strdup("O");
            }
            else {
                answer[i] = strdup("X");
            }
        }

        free(str); 
    }

    return answer;
}

int main() {
    char* quiz[] = { "3 + 2 = 5", "4 - 2 = 2", "10 + 3 = 13" };
    int quizSize = sizeof(quiz) / sizeof(quiz[0]);
    int returnSize;
    char** result = solution(quiz, quizSize, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
        free(result[i]); 
    }

    free(result); 
    return 0;
}
