/*1.输入一个整数数组，实现一个函数，
来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
所有偶数位于数组的后半部分。*/
#include<stdio.h>
#include<stdlib.h>

void Sort_odd_even(int *arr, int len)
{
	int *left = arr;
	int *right = arr + len - 1;
	int tmp = 0;
	while (left < right)
	{
		if ((*left) % 2 == 0 && (*right) % 2 == 1)
		{
			tmp = *left;
			*left = *right;
			*right = tmp;

		}
		left++;
		right--;
	}
}
void print(int*arr, int len)
{
	int*p = arr;
	while (*p < arr + len - 1)
	{
		printf(" %d", *p);
		p++;
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Sort_odd_even(arr, len);
	print(arr, len);
	system("pause");
	return 0;
}
/*2.杨氏矩阵 
有一个二维数组. 
数组的每行从左到右是递增的，每列从上到下是递增的. 
在这样的数组中查找一个数字是否存在。 
时间复杂度小于O(N); 

数组： 
1 2 3 
2 3 4 
3 4 5 

*/
#include<stdio.h>
#include<stdlib.h>
#define ROW 3
int Find_number(int(*arr)[ROW], int row, int col, int n)
{
	int i, j;
	for (i = 0, j = 0; j < col; j++)
	{
		if (arr[i][j] == n)
			return 1;
	}
	for (i = 1; i < row; i++)
	{
		j = row - 1;
		if (arr[i][j] == n)
			return 1;
	}
	return 0;

}
int main()
{
	int arr[][3] = { 1,2,3,3,4,5,4,5,6 };
	int result = 0;
	int num = 0;
	scanf("%d", &num);
	result = Find_number(arr, ROW, ROW, num);
	if (result)
	{
		printf("find it\n");
	}
	else
		printf("can't find\n");
	system("pause");
	return 0;
}