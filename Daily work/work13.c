/*1.实现strcpy*/
#include<stdio.h>
#include<stdlib.h>

void My_strcpy(int *arr1, int *arr2, int len1)
{
	int i = 0;
	int j = 0;
	while (i < len1)
	{
		arr1[i] = arr2[j];
		i++;
		j++;
	}
}
int main()
{
	char arr1[] = { "pig" };
	char arr2[] = { "dog" };
	int len1 = sizeof(arr1) / sizeof(arr1[0]) - 1;
	printf("arr1:%s\n", arr1);
	printf("arr2:%s\n", arr2);
	My_strcpy(arr1, arr2, len1);
	printf("after strcpy:%s\n", arr1);
	system("pause");
	return 0;
}

/*2.实现strcat*/
#include<stdio.h>
#include<stdlib.h>

#define N 20
void My_strcat(char *arr1, char *arr2, char *arr3, int len1, int len2)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < len1; i++)
	{
		arr3[i] = arr1[i];
	}
	for (j = 0; j < len2; j++)
	{
		arr3[j + len1] = arr2[j];
	}
}
//void Print(int *arr,int len)
//{
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		printf("%c", arr[i]);
//	}
//}
int main()
{
	char arr1[] = { "hello" };
	char arr2[] = { " world" };
	char arr3[N] = { 0 };
	int len1 = sizeof(arr1) / sizeof(arr1[0]) - 1;
	int len2 = sizeof(arr2) / sizeof(arr2[0]) - 1;
	My_strcat(arr1, arr2, arr3, len1, len2);
	printf("arr1:%s\n", arr1);
	printf("arr2:%s\n", arr2);
	printf("after strcat:%s\n", arr3);
	//Print(arr3, len1+len2-1);
	system("pause");
	return 0;
}

/*3.实现strstr*/
#include<stdio.h>
#include<stdlib.h>

int My_strstr(char *str1, char *str2)
{
	char *p = str1;
	char *q = str2;
	char *temp = str1;
	while (*p != NULL)
	{
		if (*p == *q)
		{
			temp = p;
			while (*q != NULL)
			{
				if (*p == *q)
				{
					p++;
					q++;
				}
			}
			return temp - str1 + 1;
			break;
		}
		p++;
	}
	return 0;
}

int main()
{
	char arr1[] = "hello,world!";
	char arr2[] = "wor";
	int result = 0;
	result = My_strstr(arr1, arr2);
	if (result)
	{
		printf("%d\n", result);
	}
	else
		printf("can't find\n");
	system("pause");
	return 0;
}

/*4.实现strchr*/
#include<stdio.h>
#include<stdlib.h>

int My_strchr(char *arr, int ch)
{
	char *p = arr;
	while (*p != NULL)
	{
		if (*p == ch)
		{
			return p - arr + 1;
		}
		else
			p++;
	}
	return 0;
}
int main()
{
	char arr1[] = "hello,world!";
	int ch = 'w';
	int result = 0;
	result = My_strchr(arr1, ch);
	if (result)
	{
		printf("%d\n", result);
	}
	else
		printf("can't find\n");
	system("pause");
	return 0;
}

/*5.实现strcmp*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int My_strcmp(char *str1, char *str2)
{
	int i = 0;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int len = 0;
	if (len1 > len2)
	{
		len = len1;
	}
	else
		len = len2;
	for (i = 0; i < len; i++)
	{
		if ((str1[i] == str2[i]) && (str1[i] != '\0'))
		{
			continue;
		}
		if (str1[i] < str2[i])
		{
			return -1;
		}
		if ((str1[i] == '\0') && (str2[i] == '\0'))
		{
			return 0;
		}
		else
		{
			break;
		}
		return 1;
	}

}
int main()
{
	char arr1[] = "hello,world!";
	char arr2[] = "hello,bit!";
	int result = 0;
	result = My_strcmp(arr1, arr2);
	if (result)
	{
		printf("%s greater than %s", arr1, arr2);
	}
	else if (result == 0)
	{
		printf("%s identical to %s", arr1, arr2);
	}
	else
		printf("%s less than %s", arr1, arr2);
	system("pause");
	return 0;
}

/*6.实现memcpy*/
#include<stdio.h>
#include<stdlib.h>

void My_memcpy(char *str1, char *str2, int n)
{
	char *p = str1;
	char *q = str2;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		*p = *q;
		q += 1;
		p += 1;
	}
	printf("%s\n", str1);
}
int main()
{
	char arr1[] = "hello,world!";
	char arr2[] = "bit!bit!";
	int num = 0;
	printf("please enter the change number:\n");
	scanf("%d", &num);
	My_memcpy(arr1, arr2, num);
	system("pause");
	return 0;
}

/*7.实现memmove*/
#include<stdio.h>
#include<stdlib.h>

void My_memmove(char *str1, char *str2, int n)
{
	char *p = str1;
	char *q = str2;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		*p = *q;
		q += 1;
		p += 1;
	}
	printf("%s\n", str1);
}
int main()
{
	char arr1[] = "hello,world!";
	char arr2[] = "bit!bit!";
	int num = 0;
	printf("please enter the change number:\n");
	scanf("%d", &num);
	My_memmove(arr1, arr2, num);
	system("pause");
	return 0;
}