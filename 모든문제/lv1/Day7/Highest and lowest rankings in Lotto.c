#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
	int* answer = (int*)malloc(sizeof(int) * 2);
	int arr[7] = { 6, 6, 5, 4, 3, 2, 1 };
	int zero = 0, match = 0, i, j;

	for (i = 0; i < lottos_len; i++)
	{
		if (lottos[i] == 0)
		{
			zero++;
		}
		else {
			for (j = 0; j < win_nums_len; j++)
			{
				if (lottos[i] == win_nums[j])
				{
					match++;
					break;
				}
			}
		}
	}

	answer[0] = arr[match + zero];
	answer[1] = arr[match];
	return answer;
}