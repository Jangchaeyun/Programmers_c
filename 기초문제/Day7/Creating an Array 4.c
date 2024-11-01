#include <stdio.h>
#include <stdlib.h>

int* solution(int arr[], size_t arr_len, int* returnSize) {
    int* tmp = (int*)malloc(arr_len * sizeof(int));

    if (tmp == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int tmpSize = 0;
    int i = 0;

    while (i < arr_len) {
        if (tmpSize == 0) {
            tmp[tmpSize++] = arr[i++];
        }
        else {
            int last = tmp[tmpSize - 1];
            if (last < arr[i]) {
                tmp[tmpSize++] = arr[i++];
            }
            else {
                tmpSize--;
            }
        }
    }

    int* stk = (int*)malloc(tmpSize * sizeof(int));
    if (stk == NULL) {
        free(tmp);
        *returnSize = 0;
        return NULL;
    }

    for (int k = 0; k < tmpSize; k++) {
        stk[k] = tmp[k];
    }

    free(tmp);
    *returnSize = tmpSize;

    return stk;
}
