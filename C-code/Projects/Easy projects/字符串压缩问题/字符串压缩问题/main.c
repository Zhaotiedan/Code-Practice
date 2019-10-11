#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

#define MAX 10000

void StrCompress(char *str)
{
	char *p = str;
	char *start = str;
	int num[MAX];
	char word[MAX];
	int i = 0;
	for (;*p==*start; i++)
	{
		int count = 0;
		while (*(p + 1) == *p)
		{
			count++;
			p++;
		}
		num[i] = count;
		word[i] = *p;
	}
}
int main()
{

	system("pause");
	return 0;
}