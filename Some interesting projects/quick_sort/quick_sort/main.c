#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

#define n 5

void quick_sort(int arr[], int left, int right)
{

}
int main()
{
	int arr[n] = 0;
	int i,j,k = 0;
	int left = 0;
	int right = sizeof(arr[])/sizeof(arr[0]) - 1;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[n]);
	}
	for (j = 0; j < n; j++)
	{
		printf("before:%d", arr[j]);
	}
	quick_sort(arr, left, right);
	for (k = 0; k < n; k++)
	{
		printf("after:%d", arr[k]);
	}
	return 0;
}