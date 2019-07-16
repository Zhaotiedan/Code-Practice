#define _CRT_SECURE_NO_WARNINGS 1

//递归方式实现打印一个整数的每一位 
#include<stdio.h>
#include<stdlib.h>

void Print1(int num)
{
	if (num > 9)
	{
		Print1(num / 10);
	}
	printf("%d  ", num % 10);
}
//本质是进制转化问题：m为进制
void Print(int num,int m)
{
	if (num > 9)
	{
		Print(num / m,m);
	}
	putchar("0123456789ABCDEF"[num % m]);//最多能打印16进制
}
int main()
{
	int num = 0;
	int m = 0;
	scanf("%d %d", &num, &m);
	Print(num,m);
	system("pause");
	return 0;
}