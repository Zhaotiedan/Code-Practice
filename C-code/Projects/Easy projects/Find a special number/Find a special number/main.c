#define _CRT_SECURE_NO_WARNINGS 1

//给定一个组数组元素，只有一个数字只出现了一次，要求：在里面找到这个数字

#include<stdio.h>
#include<stdlib.h>

int Find_Number(int *arr, int len)
{
	int i = 0;
	int tmp = 0;
	for (i = 0; i < len; i++)
	{
		tmp ^= arr[i];//因为所有相同数字异或为0，0异或任何数字都等于这个数字本身。
	}
	return tmp;
}
int main()
{
	int arr[] = { 10,2,10,3,6,2,3 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int result = 0;
	result=Find_Number(arr, len);
	printf("%d\n", result);
	system("pause");
	return 0;
}

//进阶：给定一组数组元素，这个数组里面有两个数字只出现了一次，要求：找到这两个数字

#include<stdio.h>
#include<stdlib.h>
void find_diff_num(int *arr, int len, int* px, int* py)
{
	//1.所有数字异或
	int num = 0;
	int i = 0;
	int pos = 0;
	for (i = 0; i < len; i++)
	{
		num ^= arr[i];
	}

	//2.找num的二进制位中的1的位置
	for (i = 0; i < 32; i++)
	{
		if (((num >> i) & 1) == 1)
		{
			pos = i;
			break;
		}
	}
	//3.按照pos位为0或者1分组
	for (i = 0; i < len; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			*px ^= arr[i];
		}
		else
		{
			*py ^= arr[i];
		}
	}
}


int main()
{
	int arr[] = { 10,2,10,3,6,2,3,1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int n1 = 0;
	int n2 = 0;
	find_diff_num(arr, len, &n1, &n2);
	printf("%d %d", n1, n2);
	system("pause");
	return 0;
}

//3.在字符串中找出第一个只出现一次的字符 输入abaccdef 输出b
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int FindFirst(char *arr, int len)
{
	int i, j, k;
	int str[50];
	for (i = 0; i < len; i++)
	{
		k = 0;
		for (j = 0; j < len; j++)
		{
			if (arr[i] == arr[j])
			{
				k++;
			}
		}
		str[i] = k;
	}
	for (i = 0; i < len; i++)
	{
		if (str[i] == 1)
		{
			return i;
		}
	}
	return 0;
}

int main()
{
	char arr[] = "abaccdeff";
	int num = FindFirst(arr, strlen(arr));
	if (num)
	{
		printf("%c", arr[num]);
	}
	else
	{
		printf("NULL");
	}
	system("pause");
	return 0;
}

//4.在字符串中找到第一次重复出现的字符 输入qywyer23tdd 输出y
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Find_reNumber(char *arr, int len)
{
	int i, j;
	for (i = 0; i < len; i++)
	{
		for (j = i+1; j < len; j++)
		{
			if (arr[i] == arr[j])
			{
				return i;
			}
		}
	}
	return 0;
}

int main()
{
	char arr[] = "qywyer23tdd";
	int num = Find_reNumber(arr, strlen(arr));
	if (num)
	{
		printf("%c", arr[num]);
	}
	else
	{
		printf("NULL");
	}
	system("pause");
	return 0;
}