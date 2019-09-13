#define _CRT_SECURE_NO_WARNINGS 1

//输入一个整型数组，有正有负，数组中一个或连续(注意是连续)的多个整数组成一个子数组，求所有子数组和的最大值。O(n)
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

//暴力求解，让每一个数依次成为每一次求和都要相加的起始数。复杂度为O(n^2)
int MaxSum1(int *arr, int len)
{
	int sum, max = INT_MIN;
	int i, j;
	for (i = 0; i < len; i++)
	{
		sum = 0;
		for (j = i; j < len; j++)
		{
			sum += arr[j];
			if (max < sum)
			{
				max = sum;
			}
		}
	}
	return max;
}
//暴力求解的错误实例：只让第一个数成为了为每一次求和都要相加的起始数。
//int MaxSum(int *arr, int len)
// {
//	int sum = 0;
//	int i = 0;
//	int k = 0;
//	int str[MAX];
//	for (i = 0; i < len; i++)
//	{
//		sum += arr[i];
//		str[i] = sum;
//	}
//	int Max = str[0];
//	for (k = 0; k < len; k++)
//	{
//		if (str[k] > Max)
//		{
//			Max = str[k];
//		}
//	}
//	return Max;
//}

//2、借鉴贪心算法：一旦加到某个元素出现sum为负的情况，舍弃前面的所有元素，在下一个元素处重新开始求和。O(n)
int MaxSum2(int *arr, int len)
{
	int sum = 0;
	int max = INT_MIN;
	int i, j;
	for (i = 0; i < len; i++)
	{
		sum += arr[i];
		if (sum < 0)
		{
			sum = 0;
		}
		if (sum > max)
		{
			max = sum;
		}
	}
	return max;
}
int main()
{
	int arr[] = { 1,-2,3,10,-4,7,2,-5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int result = MaxSum2(arr,len);
	printf("%d", result);
	system("pause");
	return 0;
}