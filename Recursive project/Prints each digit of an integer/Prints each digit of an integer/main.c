#define _CRT_SECURE_NO_WARNINGS 1

//递归方式实现打印一个整数的每一位 
#include<stdio.h>
#include<stdlib.h>

void Print(int num)
{
	if (num > 9)
	{
		Print(num / 10);
	}
	printf("%d  ", num % 10);
}
int main()
{
	int num = 0;
	scanf("%d", &num);
	Print(num);
	system("pause");
	return 0;
}