#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

char *Transfor(char *str)
{
	assert(str != NULL);
	char * pstr = str;
	int count = 0;//空格数
	char *end = NULL;
	char *newend = NULL;
	while (*str != '\0')
	{
		if (*str == ' ')
		{
			count++;
		}
		str++;
	}
	end = str;
	newend = end + 2 * count;//新字符串长度=原长度+2*空格个数
	//从后往前开始拷贝
	while (end != newend)
	{
		if (*end == ' ')
		{
			*newend = '0';
			newend--;
			*newend = '2';
			newend--;
			*newend = '%';
			newend--;
			end--;
		}
		else
		{
			*newend = *end;
			end--;
			newend--;
		}
	}
	return pstr;
}
int main()
{
	char str[] = "hello world";
	char *arr = Transfor(str);
	printf("%s", arr);
	system("pause");
	return 0;
}