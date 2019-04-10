#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//递归
int Strlen(const char *str)
{
	if (*str == '\0')
		return 0;
	else
		return 1 + Strlen(str+1);
}
int main()
{
	char *arr = "abcd";
	int result = 0;
	result = Strlen(arr);
	printf("%d", result);
	system("pause");
	return 0;
}
//非递归
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
int main()
{
	char *arr = "abcd";
	int result = 0;
	result = Strlen(arr);
	printf("%d", result);
	system("pause");
	return 0;
}