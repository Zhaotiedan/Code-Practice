#define _CRT_SECURE_NO_WARNINGS 1


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
		return Fib(n - 1) + Fib(n - 2);
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
	int i = 2;
	while (i < n)
	{
		third = second + first;
		first = second;
		second = third;
		i++;
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