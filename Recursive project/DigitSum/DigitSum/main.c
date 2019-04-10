#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int DigitSum(int n)
{
	if (n<10)
		return n;
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