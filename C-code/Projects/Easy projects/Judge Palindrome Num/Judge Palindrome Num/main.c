#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int new = 0;
	int num = 0;
	scanf("%d", &num);
	while (num)
	{
		new = new * 10 + num % 10;
		num /= 10;
	}
	if (num == new)
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}
	system("pause");
	return 0;
}