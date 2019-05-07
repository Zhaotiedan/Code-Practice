1.一个数组中只有两个数字是出现一次， 
其他所有数字都出现了两次。 
找出这两个只出现一次的数字，编程实现。 
#include<stdio.h>
#include<stdlib.h>

void Find_two_number(int *arr, int len)
{
	int i, j, k = 0;
	int tmp = 0;
	int pos = 0;
	int a,b=0;
	/*int	b = 0;*/
	for (i = 0; i < len; i++)
	{
		tmp = tmp ^ arr[i];
	}
	for (j = 0; j < 32; j++)
	{
		if ((tmp >> j) & 1 == 1)
		{
			pos = j;
			break;
		}
	}
	for (k = 0; k < len; k++)
	{
		if ((arr[k] >> pos) & 1 == 1)
		{
			a = a ^ arr[k];
		}
		else
			b = b ^ arr[k];
	}
	printf("第一个数字为：%d 第二个数字为：%d",a,b);
}
int main()
{
	int arr[] = { 1,3,6,9,7,9,6,1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Find_two_number(arr, len);
	system("pause");
	return 0;
}
2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水， 
给20元，可以多少汽水。 
编程实现。 
