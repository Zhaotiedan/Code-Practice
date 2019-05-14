/* 1.实现一个函数，可以左旋字符串中的k个字符
ABCD左旋一个字符得到BCDA
ABCD左旋两个字符得到CDAB */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#include<string.h>
//暴力算法 函数
void left_move1(char *str, int k)
{
	if (k<0 || k>strlen(str))
	{
		printf("不合法\n");
		return;
	}
	while (k)
	{
		char *cur = str;
		char tmp = *cur;
		while (*(cur + 1))
		{
			*cur = *(cur + 1);
			cur++;
		}
		*cur = tmp;
		k--;
	}
}

//聪明算法 函数
void Reverse(char *left, char *right)
{
	assert(left != NULL && right != NULL);
	while (left < right)
	{
		char tmp = 0;
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void Left_handed(char *arr, int k, int len)
{
	if (k<0 || k>strlen(arr))
	{
		printf("不合法\n");
		return 0;
	}
	int i = 0;
	char *p = arr;
	while (i < k)
	{
		p = arr + i;
		i++;
	}
	Reverse(arr, p);
	Reverse(p + 1, arr + len - 1);
	Reverse(arr, arr + len - 1);
}
int main()
{
	int k = 0;
	char arr[] = "ABCDE";
	int len = sizeof(arr) / sizeof(arr[0]) - 1;
	scanf("%d", &k);
	Left_handed(arr, k, len);

	left_move1(arr, k);

	printf("%s", arr);
	system("pause");
	return 0;
}

/*判断一个字符串是否为另外一个字符串旋转之后的字符串。
例如：给定s1 =AABCD和s2 = BCDAA，返回1
给定s1=abcd和s2=ACBD，返回0.

AABCD左旋一个字符得到ABCDA
AABCD左旋两个字符得到BCDAA

AABCD右旋一个字符得到DAABC*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 10
//strcat:（str1，str2）把str2拼接到str1后面
//strncat：(str1,str2,n)把str2的前n个拼接到str1后面
//查找字符串strstr（str1，str2）在str1里面看能否找到str2
//函数实现
void  Merge_string(char *arr)
{
	arr = strncat(arr, arr, strlen(arr));
	printf("%s\n", arr);
}
int Judge_string(char *arr1, char *arr2)
{
	Merge_string(arr1);
	if (strstr(arr1, arr2) != NULL)
	{
		return 1;
	}
	else
		return 0;
}

//算法实现
void Merge_string(char *arr)
{
	int i = 0;
	for (i = 0; i < N - 5; i++)
	{
		arr[i + 5] = arr[i];
	}
}
int Judge_string(char *arr1, char *arr2)
{
	Merge_string(arr1);
	char *p = arr1;
	char arr3[6];
	int i = 0;
	int j = 0;
	while (*p != *arr2)
	{
		p++;
	}
	for (i = 0; i < 5; i++)
	{
		arr3[i] = *p;
		p++;
	}
	arr3[i] = '\0';
	printf("%s", arr3);
	for (j = 0; j < i; j++)
		if (strcmp(arr3, arr2) == 0)
			return 1;
		else
			return 0;
}
int main()
{
	char arr1[N + 1] = "ABCDE";
	char arr2[N] = "CDEAB";
	int result = 0;
	result = Judge_string(arr1, arr2);
	if (result)
	{
		printf("yes\n");
	}
	else
	{
		printf("No\n");
	}
	system("pause");
	return 0;
}
