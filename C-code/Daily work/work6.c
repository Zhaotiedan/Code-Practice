//1.判断是否为闰年（函数法）
#include<stdio.h>
#include<stdlib.h>

char Leap_year(int x)
{
	if ((x % 400 == 0) || (x % 100 != 0 && x % 4 == 0))
	{
		return 'T';
	}
	return 'F';
}

int main()
{
	int year = 0;
	char result = 0;
	scanf("%d", &year);
	result = Leap_year(year);
	printf("%c\n", result);
	system("pause");

	return 0;
}

//2.判断一个数是不是素数
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int Is_Prime(int n)
{
	int i = 0;
	for (i = 2; i <= sqrt((double)n); i++)
	{
		if (n%i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int num = 0;
	scanf("%d", &num);
	if (Is_Prime(num) == 1)
	{
		printf("is prime\n");
	}
	printf("Not prime\n");
	system("pause");
	return 0;
}


//3.使用实现两个数的交换
#include<stdio.h>
#include<stdlib.h>

void Swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
int main()
{
	int a = 10;
	int b = 20;
	Swap(&a, &b);
	printf("%d %d\n", a, b);
	system("pause");
	return 0;
}


//4.自己设计一些函数来使用
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//初始化数组
void init(int arr[], int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		arr[i] = i;
	}
}
//清空数组，置为0
void empty(int arr[], int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
}
void swap(int *arr, int left, int right)
{
	int temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;
}
//将数组元素逆置
void reverse(int arr[], int size)
{
	int left = 0;
	int right = size - 1;
	while (left < right)
	{
		swap(arr, left, right);
		left++;
		right--;
	}
}
void print(int arr[], int size)//arr[]=*arr
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d", arr[i]);//[]自带解引用 arr[i]==*(arr+i),即通过数组下标打印。去掉*号是什么类型，则+1后移动几个字节
	}
	printf("\n");
}
int main()
{
	int arr[3];
	int size = sizeof(arr) / sizeof(arr[0]);
	init(arr, size);
	print(arr, size);
	/*empty(arr,size);
	print(arr, size);*/
	reverse(arr, size);
	print(arr, size);
	system("pause");
	return 0;
}

//some thought-provoking questions:
/*
1.数组是在什么时候确定大小的？  编译的时候
2.数组是在什么时候开辟内存的？  运行的时候
3.在哪里开辟内存？   栈
4.最大开辟多少内存？  1M或者2M
*/