#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>


//快排思想找到任意k大的数字位置
int  qort(int *arr, int left, int right)
{
	int key = arr[left];
	while (left < right)
	{
		while (left < right&&arr[right] >= key)
		{
			right--;
		}
		arr[left] = arr[right];
		while (left < right&&arr[left] <= key)
		{
			left++;
		}
		arr[right] = arr[left];
	}
	return left;
}
//比较left这个位置与k-1位置
void PreKNum(int *arr, int len,int k)
{
	int left = 0;
	int right = len - 1;
	int pos= qort(arr, left, right);
	while (pos != k - 1)
	{
		if (pos > k - 1)
		{
			right = pos - 1;
			pos = qort(arr, left, right);
		}
		else
		{
			left = pos + 1;
			pos = qort(arr, left, right);
		}
	}
}

int main()
{
	int arr[] = { 1,10,3,14,7,2,9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int k = 0;
	scanf("%d", &k);
	PreKNum(arr, len, k);
	for (i - 0; i < k; i++)
	{
		printf(" %d", arr[i]);
	}
	system("pause");
	return 0;
}