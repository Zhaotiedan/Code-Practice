#define _CRT_SECURE_NO_WARNINGS 1

//递归和非递归分别实现求第n个斐波那契数。 递推公式a1=1，an=an-1+an-2
//斐波那契数列  1  1  2  3  5  8  13  21  34
#include<stdio.h>
#include<stdlib.h>

//递归  较慢
int Fib(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	else
		return Fib(n - 1) + Fib(n - 2);//连续两项都含n，复杂度为n^2,最好写成循环或者写尾递归。
}
int main()
{
	int n =0;
	int result = 0;
	scanf("%d", &n);
	result = Fib(n);
	printf("%d", result);
	system("pause");
	return 0;
}

//非递归  循环的速度非常快  可取
int Fib(int n)
{
	int first = 1;
	int second = 1;
	int third = 1;
	int i = 0;
	if (n <= 2)
	{
		return 1;
	}
	for (i = 3; i <= n; i++)
	{
		third = second + first;
		first = second;
		second = third;
	}
	return third;
}
int main()
{
	int n = 0;
	int result = 0;
	scanf("%d", &n);
	result = Fib(n);
	printf("%d", result);
	system("pause");
	return 0;
}