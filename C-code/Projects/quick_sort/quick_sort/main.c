#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

void quick_sort(int arr[], int left, int right)
{
	if (left < right)
	{
		int l, r, k;
		l = left;
		r = right;
		k = arr[l];
		while (l < r)
		{
			while(l<r&&arr[r]>k)
			{
				r--;
			}
			if (l < r)
			{
				arr[l++] = arr[r];
			}
			while (l < r&&arr[l]<k)
			{
				l++;
			}
			if (l < r)
			{
				arr[r--] = arr[l];
			}
		}
		arr[l] = k;
		quick_sort(arr,left,l-1);
		quick_sort(arr, l+1, right);
	}
}
int main()
{
	int arr[] = { 10,30,20,3,90,5 };
	int i= 0;
	int left = 0;
	int right = sizeof(arr)/sizeof(arr[0]) - 1;
	printf("before sort:");

	for (i = 0; i < 6; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	quick_sort(arr, 0, right);
	printf("after sort:");
	for (i = 0; i < 6; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}