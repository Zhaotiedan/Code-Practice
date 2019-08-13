#define _CRT_SECURE_NO_WARNINGS 1

/*写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，
例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19*/
//递推公式：an=n%10+a(n/10)
#include<stdio.h>
#include<stdlib.h>

int DigitSum(int n)
{
	if (n==0)
		return 0;
	else
		return DigitSum(n / 10) + n % 10;//%的值是在返回的时候加起来的
}
int main()
{
	int n = 0;
	int result = 0;
	scanf("%d", &n);
	result=DigitSum(n);
	printf("%d\n", result);
	system("pause");
	return 0;
}									