#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(const char* skill, const char* skill_trees[], size_t skill_trees_len) {
	int answer = 0;
	int alpha[26][2];
	int num;

	for (int i = 0; i < skill[i] != '\0'; i++)
	{
		alpha[skill[i] - 'A'][0] = 1;
		alpha[skill[i] - 'A'][1] = i;
	}

	for (int i = 0; i < skill_trees_len; i++)
	{
		num = 0;
		for (int j = 0; j < skill_trees[i][j] != '\0'; j++)
		{
			if (alpha[skill_trees[i][j] - 'A'][0] == 1)
			{
				if (alpha[skill_trees[i][j] - 'A'][1] == num)
				{
					num++;
				}
				else {
					num = -1;
					break;
				}
			}
		}

		if (num > -1) answer++;
	}
	return answer;
}