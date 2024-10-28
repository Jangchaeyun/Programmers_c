#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* solution(const char* str1, const char* str2) {

	int length = strlen(str1);
	char* answer = (char*)malloc((2 * length + 1) * sizeof(char));

	int index = 0;

	for (int i = 0; i < length; i++)
	{
		answer[index++] = str1[i];
		answer[index++] = str2[i];
	}

	answer[index] = '\0';

	return answer;
}

//문자 소문자 여부를 판별하는 함수
int LowerCase(char* str1, char* str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (!islower(*str1) || !islower(*str2))
		{
			return 0;
		}
		str1++;
		str2++;
	}

	if (*str1 != '\0' || *str2 != '\0')
	{
		return 0;
	}

	return 1;
}

int main() {
	const int MAX_LENGTH = 10;

	char* str1 = (char*)malloc(MAX_LENGTH * sizeof(char));
	char* str2 = (char*)malloc(MAX_LENGTH * sizeof(char));

	scanf("%s %s", str1, str2);

	if (LowerCase(str1, str2))
	{
		char* result = solution(str1, str2);
		printf("%s\n", result);
		free(result);
	}
	else
	{
		printf("입력한 문자열의 길이가 다르거나, 대문자가 포함되어 있습니다.");
	}

	free(str1);
	free(str2);
	return 0;
}