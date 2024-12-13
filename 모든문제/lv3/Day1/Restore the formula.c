#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char** StrSplit(const char* str, size_t* count) {
    char* temp = strdup(str);
    char* token;
    char** retV = (char**)malloc(sizeof(char*) * 100);
    *count = 0;

    token = strtok(temp, " ");
    while (token != NULL) {
        retV[*count] = strdup(token);
        (*count)++;
        token = strtok(NULL, " ");
    }
    free(temp);
    return retV;
}

int convAtoB(int a, int b) {
    int retN = 0;
    int tt = 1;
    while (a > 0) {
        if (a % 10 >= b) {
            return -1;
        }
        retN += (a % 10) * tt;
        tt *= b;
        a /= 10;
    }
    return retN;
}

int conv10toB(int a, int b) {
    int retN = 0;
    int tt = 1;
    while (a > 0) {
        retN += (a % b) * tt;
        tt *= 10;
        a /= b;
    }
    return retN;
}

int* notNLst(char** str, size_t count, size_t* retCount) {
    int A, B, C;
    int* retVi = (int*)malloc(sizeof(int) * 8);
    *retCount = 0;

    for (int i = 2; i < 10; i++) {
        A = convAtoB(atoi(str[0]), i);
        B = convAtoB(atoi(str[2]), i);
        if (strcmp(str[4], "X") == 0) {
            if (A < 0 || B < 0) {
                retVi[(*retCount)++] = i;
            }
        }
        else {
            C = convAtoB(atoi(str[4]), i);
            if (A < 0 || B < 0 || C < 0) {
                retVi[(*retCount)++] = i;
                continue;
            }
            if (strcmp(str[1], "-") == 0) {
                if (A - B != C)
                    retVi[(*retCount)++] = i;
            }
            else {
                if (A + B != C)
                    retVi[(*retCount)++] = i;
            }
        }
    }
    return retVi;
}

char** solution(const char* expressions[], size_t expressions_len) {
    bool visit[10];
    for (int i = 0; i < 10; i++) visit[i] = true;

    size_t tmpAnsCount = 0;
    char*** tmpAns = (char***)malloc(sizeof(char**) * expressions_len);

    for (size_t i = 0; i < expressions_len; i++) {
        size_t count;
        char** tmpS = StrSplit(expressions[i], &count);

        if (strcmp(tmpS[4], "X") == 0) {
            tmpAns[tmpAnsCount++] = tmpS;
        }

        size_t tiCount;
        int* ti = notNLst(tmpS, count, &tiCount);
        for (size_t j = 0; j < tiCount; j++) {
            visit[ti[j]] = false;
        }
        free(ti);
    }

    int canList[8];
    size_t canListCount = 0;
    for (int i = 2; i < 10; i++) {
        if (visit[i]) {
            canList[canListCount++] = i;
        }
    }

    char** answer = (char**)malloc(sizeof(char*) * tmpAnsCount);
    size_t answerCount = 0;

    for (size_t i = 0; i < tmpAnsCount; i++) {
        int A, B, C, cmpC;
        bool flag = true;

        A = convAtoB(atoi(tmpAns[i][0]), canList[0]);
        B = convAtoB(atoi(tmpAns[i][2]), canList[0]);

        if (strcmp(tmpAns[i][1], "+") == 0) {
            C = conv10toB(A + B, canList[0]);
        }
        else {
            C = conv10toB(A - B, canList[0]);
        }

        for (size_t j = 1; j < canListCount; j++) {
            A = convAtoB(atoi(tmpAns[i][0]), canList[j]);
            B = convAtoB(atoi(tmpAns[i][2]), canList[j]);

            if (strcmp(tmpAns[i][1], "+") == 0) {
                cmpC = conv10toB(A + B, canList[j]);
            }
            else {
                cmpC = conv10toB(A - B, canList[j]);
            }

            if (cmpC != C) {
                flag = false;
                strcpy(tmpAns[i][4], "?");
                break;
            }
        }

        if (flag) {
            sprintf(tmpAns[i][4], "%d", C);
        }

        char buffer[256] = { 0 };
        snprintf(buffer, sizeof(buffer), "%s %s %s %s %s",
            tmpAns[i][0], tmpAns[i][1], tmpAns[i][2], tmpAns[i][3], tmpAns[i][4]);

        answer[answerCount++] = strdup(buffer);
    }

    return answer;
}
