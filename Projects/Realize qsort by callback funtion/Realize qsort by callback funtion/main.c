#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//qort的使用
int int_cmp(const void *p1, const void *p2)
{
	return (*(int *)p1 > *(int *)p2);
}

int main()
{
	int arr[] = { 1,3,5,7,9,2,4,6,8,0 };
	int i = 0;
	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d",arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}

//通过回调函数实现(冒泡)
int int_cmp(const void *p1, const void *p2)
{
	return (*(int *)p1 > *(int *)p2);
}
void swap(void *p1, void *p2,int size)//不知道元素类型，要按字节为单位来变换
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		char tmp = *((char *)p1 + i);
		*((char *)p1 + i) = *((char *)p2 + i);
		*((char *)p2 + i) = tmp;
	}
}
void bubble(void *base, int count, int size, int(*cmp)(void * , void *))
{
	assert(base);
	assert(cmp);
	int i = 0;
	int j = 0;
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - 1 - i; j++)
		{
			if (cmp((char *)base + j * size, (char *)base + (j + 1)*size) > 0)
			{
				swap((char *)base + j * size, (char *)base + (j + 1)*size, size);
			}
		}
	}
}
int main()
{
	int arr[] = { 1,3,5,7,9,2,4,6,8,0 };
	int i = 0;
	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf(" %d", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
