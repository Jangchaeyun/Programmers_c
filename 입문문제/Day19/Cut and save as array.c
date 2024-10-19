#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** solution(const char* my_str, int n, int* returnSize) {
    int len = strlen(my_str);
    int num_substrings = (len + n - 1) / n;
    *returnSize = num_substrings; 

    char** answer = (char**)malloc(num_substrings * sizeof(char*));

    int count = 0;
    for (int i = 0; i < num_substrings; i++) {
        int substr_len = (count + n < len) ? n : len - count;

        answer[i] = (char*)malloc((substr_len + 1) * sizeof(char));

        strncpy(answer[i], my_str + count, substr_len);
        answer[i][substr_len] = '\0';

        count += n;
    }

    return answer;
}