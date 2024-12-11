#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char arr[100000][7];
int leng[100000];

int compare(char* a, char* b, int n)
{
	if (a[n] < b[n]) return 1;
	if (a[n] == b[n] && n < 3) return compare(a, b, n + 1);
	return 0;
}

char* solution(int numbers[], size_t numbers_len)
{
    char* answer = (char*)malloc(numbers_len * 4 + 1);
    char temp[5];
    int sum = 0;

    for (int i = 0; i < numbers_len; i++)
    {
        sprintf(arr[i], "%d", numbers[i]);
        strcpy(temp, arr[i]);
        leng[i] = strlen(arr[i]);
        while (strlen(arr[i]) < 4) strcat(arr[i], temp);
        sum += numbers[i];
    }

    if (sum == 0) return 0;

    answer[0] = '\0';

    for (int i = 0, max; i < numbers_len; i++)
    {
        max = i;
        for (int j = i + 1; j < numbers_len; j++) {
            if (compare(arr[max], arr[j], 0)) max = j;
        }

        strncat(answer, arr[max], leng[max]);
        if (max != i) {
            strcpy(arr[max], arr[i]);
            leng[max] = leng[i];
        }
    }

    return answer;
}
