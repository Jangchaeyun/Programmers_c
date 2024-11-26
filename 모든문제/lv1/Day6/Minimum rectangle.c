#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int** sizes, size_t sizes_rows, size_t size_cols)
{
	int answer = 0;
	int width = 0, height = 0, temp;

	for (int i = 0; i < sizes_rows; i++)
	{
		if (sizes[i][0] < sizes[i][1])
		{
			temp = sizes[i][0];
			sizes[i][0] = sizes[i][1];
			sizes[i][1] = temp;
		}
		if (sizes[i][0] > width) width = sizes[i][0];
		if (sizes[i][1] > height) height = sizes[i][1];
	}

	answer = width * height;

	return answer;
}