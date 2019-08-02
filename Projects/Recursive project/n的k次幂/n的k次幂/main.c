#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int My_Pow(int n,int k)
{
	if (k == 0)
	{
		return 1;
	}
	else if (k == 1)
	{
		return n;
	}
	return n * My_Pow(n, k - 1);

}
int main()
{
	int n = 0;
	int k = 0;
	int result = 0;
	scanf("%d %d", &n, &k);
	result = My_Pow(n, k);
	printf("%d\n", result); 
	system("pause");
	return 0;
}