//1.写一个函数返回参数二进制中 1 的个数.比如： 15 0000 1111 4 个 1
#include<stdio.h>
#include<stdlib.h>

int count_one_bits1(unsigned int value)//此方法必须要加unsigned 把负数变成无符号数
{
	int count = 0;
	while (value)
	{
		if (value % 2 == 1)
		{
			count ++;
		}
		value=value >> 1;//value/=2
	}
	return count;
}
int count_one_bits2(int value)//不加unsigned 也OK
{
	int count = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if (((value >> i) & 1) == 1)
			count++;

	}
	return count;
}
int count_one_bits3(unsigned int value)//传入数字变成无符号数
{
	int count = 0;
	while (value)
	{
		value = value & (value - 1);
		count++;
	}
	return count;
}
int main()
{
	int x = 0;
	int result = 0;
	scanf("%d", &x);
	result = count_one_bits3(x);
	printf("%d\n", result);
	system("pause");
	return 0;
}

/*2.获取一个数二进制序列中所有的偶数位和奇数位，
分别输出二进制序列。*/
#include<stdio.h>
#include<stdlib.h>

void Function(int num)
{
	int i = 0;
	printf("偶数位为：");
	for (i = 31; i >= 1; i -= 2)
	{
		printf("%d", (num >> i) & 1);
	}
	printf("\n");
	printf("奇数位为：");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d", (num >> 1) & 1);
	}
}
int main()
{
	int odd = 0;
	int even = 0;
	int num = 0;
	scanf("%d", &num);
	Function(num);
	system("pause");
	return 0;
}
/*3.编程实现：
两个int（32位）整数m和n的二进制表达中，
有多少个位(bit)不同？
输入例子 :
1999 2299
输出例子 : 7*/
#include<stdio.h>
#include<stdlib.h>

int Different_bits(int a, int b)
{
	int tmp = a ^ b;//不一样的进行异或
	int count = 0;
	while (tmp)
	{
		tmp = tmp & (tmp - 1);
		count++;
	}
	return count;
}
int main()
{
	int a, b = 0;
	int result = 0;
	scanf("%d %d", &a, &b);
	result = Different_bits(a, b);
	printf("%d\n", result);
	system("pause");
	return 0;
}

