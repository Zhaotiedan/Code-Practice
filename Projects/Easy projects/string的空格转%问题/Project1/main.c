#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char* Transfor(char *str)
{
	char *pstr = str;
	char *end = NULL;
	char *newend = NULL;
	int count = 0;
	while (*str != '\0')
	{
		//计算空格数目
		if (*str == ' ')
		{
			count++;
		}
		str++;
	}
	end = str;
	newend = str + 2 * count;//转换后的字符串长度=原来字符串长度+2*空格数目
	//从后往前拷贝
	while (end != newend)//当两个指针指向同一块地址时，停止
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
			newend--;
			end--;
		}
	}
	return pstr;
}
int main()
{
	char str1[10] = "abc sb";
	//scanf("%s", str1);
	char *str2 = Transfor(str1);
	printf("%s", str2);
	system("pause");
	return 0;
}