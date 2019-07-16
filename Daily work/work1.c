//1.打印100~200之间的素数
/*i/2:一个非素数的约数最大的那个值小于等于i/2
sqrt(i):一个非素数的约数两个中小的那个小于sqrt(i)
偶数一定不是素数，所以只算奇数，i+=2*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int i = 0;
	for (i = 101; i <= 200; i++)
	{
		int j = 0;
		for (j = 2; j <= sqrt(i); j++)
		{
			if (i%j == 0)
			{
				break;
			}
		}
		if (j > sqrt(i))
		{
			printf("%d\n", i);
		}
	}
	system("pause");
	return 0;
}
//函数法

int is_prime(int i)//试除法
{
	int j = 0;
	for (j = 2; j < sqrt(i); j++)//标准写一个法：定义一个temp=sqrt(i)，老版本会每一次都重复计算这个值，这样可以杜绝编译器不同影响的效率问题。
	{
		if (i%j == 0)
			return 0;
	}
	return 1;
}
int main()
{
	int i = 0;
	for (i = 100; i <= 200; i++)
	{
		if (is_prime(i) == 1)
		{
			printf("%d\n", i);
		}
	}
	system("pause");
	return 0;
}
//2.判断1000~2000之间的闰年,判断题：先找一定成立的结果
/*闰年：1.能被400整除。2.能被4整除但不能被100整除。二者满足一个即可*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int year = 0;

	for (year = 1000; year <= 2000; year++)
	{
		if (((year % 4 == 0 && year % 100 != 0)) || (year % 400 == 0))
		{
			printf("%d\n", year);
		}
	}
	system("pause");
	return 0;
}
//函数法
int is_leapyear(int i)
{
	return (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0));
	/*if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
		return 1;
	else
		return 0;*/
}
int main()
{
	int year = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if (is_leapyear(year) == 1)
		{
			printf("%d\n", year);
		}
	}
	system("pause");
	return 0;
}

//3.打印乘法口诀表(打印表）
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i, j, q = 0;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
		{
			q = i * j;
			printf("%d*%d=%-2d   ", i, j, q);//-向左对齐
		}
		printf("\n");//putchar('\n');
	}
	system("pause");
	return 0;
}