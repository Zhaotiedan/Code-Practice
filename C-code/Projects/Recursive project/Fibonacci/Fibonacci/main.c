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


//斐波那契数列的应用
//青蛙跳楼：一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
/*对于第n个台阶来说，只能从n-1或者n-2的台阶跳上来
当跳的台阶是0或者是1的时候，刚好就有0种或1中。
但是台阶 = 2的时候，有两种可能:可以是从n = 0,跳上来或者是从n = 1跳上来*/

int GetSlution(int n)
{
	if(n<2)
	{
		return 1;
	}
	else if(n==2)
	{
		return 2;
	}
	else
	{
		return GetSlution(n-1)+GetSlution(n-2);
	}
}		
