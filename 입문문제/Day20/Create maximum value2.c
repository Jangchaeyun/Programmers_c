#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* solution(const char* polynomial) {
    int x = 0;
    int number = 0;

    char buffer[1000];
    strcpy(buffer, polynomial);

    char* token = strtok(buffer, " ");
    while (token != NULL) {
        if (strcmp(token, "+") == 0) {
        }
        else if (token[strlen(token) - 1] == 'x') {
            if (strcmp(token, "x") == 0) {
                x++;
            }
            else {
                char temp[100];
                strncpy(temp, token, strlen(token) - 1);
                temp[strlen(token) - 1] = '\0';
                x += atoi(temp);
            }
        }
        else {
            number += atoi(token);
        }
        token = strtok(NULL, " ");
    }

    static char answer[100];

    if (x && number) {
        if (x == 1) {
            snprintf(answer, sizeof(answer), "x + %d", number);
        }
        else {
            snprintf(answer, sizeof(answer), "%dx + %d", x, number);
        }
    }
    else if (x && !number) {
        if (x == 1) {
            snprintf(answer, sizeof(answer), "x");
        }
        else {
            snprintf(answer, sizeof(answer), "%dx", x);
        }
    }
    else if (!x && number) {
        snprintf(answer, sizeof(answer), "%d", number);
    }
    else {
        snprintf(answer, sizeof(answer), "0");
    }

    return answer;
}