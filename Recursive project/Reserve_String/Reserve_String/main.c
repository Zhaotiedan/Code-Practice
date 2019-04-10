#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

void Reverse_string(char *str)
{
	int len = strlen(str);
	char tmp = *str;
	*str = *(str + len - 1);
	*(str+ len - 1) = '\0';
	if (strlen(str + 1) > 1)
	{
		Reverse_string(str + 1);
	}
	*(str + len - 1) = tmp;
}
int main()
{
	char arr[]= "abcd";
	Reverse_string(arr);
	printf("%s\n", arr);
	system("pause");
	return 0;
}

//循环  指针
int Strlen(char *str)
{
	int count = 0;
	assert(str != NULL);//断言  遇到指针就要加  是一个宏不是函数 只在Debug条件下管用
	while (*str != '\0')//因为字符串以\0结尾
	{
		count++;
		str++;
	}
	return count;
}

void Reverse_string(char *str)
{
	char *left=str;
	char *right = str+Strlen(str)-1;
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
int main()
{
	char arr[] = "abcd";   //char *arr="abcd"不能用是因为  abcd是一个字符串，放在只读区
	int len = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	Reverse_string(arr);
	for (i = 0; i < len; i++)
	{
		printf("%c", arr[i]);
	}
	system("pause");
	return 0;
}