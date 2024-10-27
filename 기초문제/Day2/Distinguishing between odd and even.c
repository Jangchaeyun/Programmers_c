#include <stdio.h>

int main(void) {
	int a;
	scanf("%d", &a);

	if (a == 0)
	{
		printf("0은 판별할 수 없습니다.");
	}
	else if (a > 1000) {
		printf("1000보다 큰 값은 판별할 수 없습니다.");
	}
	else if (a % 2 == 0)
	{
		printf("%d is even", a);
	}
	else if (a % 2 == 1) {
		printf("%d is odd", a);
	}
	else
	{
		printf("잘못된 데이터입니다.");
	}
	return 0;
}