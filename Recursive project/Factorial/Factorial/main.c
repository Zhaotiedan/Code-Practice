#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//µÝ¹é
int Factorial(int n)
{
	if (n == 1)
		return 1;
	else
		return n * Factorial(n - 1);
}
int main()
{
	int n = 0;
	int result = 0;
	scanf("%d", &n);
	result = Factorial(n);
	printf("%d", result);
	system("pause");
	return 0;
}

//·ÇµÝ¹é
int Factorial(int n)
{
	int i = 0;
	int s = 1;
	for (i = 1; i <= n; i++)
	{
		s *= i;
	}
	return s;
}
int main()
{
	int n = 0;
	int result = 0;
	scanf("%d", &n);
	result = Factorial(n);
	printf("%d\n", result);
	system("pause");
	return 0;
}