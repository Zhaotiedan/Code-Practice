//1.整型变量的值互换（从中间值到无中间值，一步步优化）
#include<stdio.h>

int main()
{
	int a = 2;
	int b = 3;
	//1.low方法设中间值
	/*int tmp = 0;
	tmp = a;
	a = b;
	b = tmp;*/
	//2.第一次优化
	/*a = a + b;
	b = a - b;
	a = a - b;*/
	//3.最终优化 异或
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("a=%d  b=%d\n", a, b);
	system("pause");
	return 0;
}
//2.求两个数的最大公约数
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 0;
	int b = 0;
	int k = 0;
	scanf("%d%d", &a, &b);
	//辗转相除法
	while (a%b != 0)//a,b的值大小与否都一样
	{
		k = a % b;
		a = b;
		b = k;
	}
	//遍历法
	for (i = 1; i < small(a, b); i++)
	{
		if (a%i == 0 && b%i == 0)
		{
			max = i;
		}
	}
	//最小公倍数：a*b/max
	printf("最大公约数为%d\n", b);
	system("pause");
	return 0;
}

//3.将三个数从大到小输出（暂时不用函数法）
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 20;
	int b = 40;
	int c = 10;
	if (a < b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	if (a < c)
	{
		int tmp = a;
		a = c;
		c = tmp;
	}
	if (b < c)
	{
		int tmp = b;
		b = c;
		c = tmp;
	}
	printf("%d %d %d\n", a, b, c);
	system("pause");
	return 0;
}

//4.在10个整数中求最大值
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[10] = { 0 };
	int max = a[0];//假设第一个数字最大
	int i = 0;
	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	for (i = 1; i < 10; i++)
	{
		if (a[i] >= max)
			max = a[i];
	}
	printf("%d\n", max);
	system("pause");
	return 0;
}