/*1.一个数组中只有两个数字是出现一次， 
其他所有数字都出现了两次。 
找出这两个只出现一次的数字，编程实现。 */
#include<stdio.h>
#include<stdlib.h>

void Find_two_number(int *arr, int len)
{
	int i, j, k = 0;
	int tmp = 0;
	int pos = 0;
	int a,b=0;
	for (i = 0; i < len; i++)//拿到异或结果
	{
		tmp = tmp ^ arr[i];
	}
	for (j = 0; j < 32; j++)//找到异或结果的1出现的位置j
	{
		if ((tmp >> j) & 1 == 1)
		{
			pos = j;//将结果保存在pos里面
			break;
		}
	}
	for (k = 0; k < len; k++)
	{
		if ((arr[k] >> pos) & 1 == 1)//按第一次出现1的位置是否为pos进行分组
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
/*2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水， 
给20元，可以多少汽水。 编程实现。*/ 
#include<stdio.h>
#include<stdlib.h>

int Water_Number(int n)
{
	int num = n;
	int sum = n;
	int empty = n;
	while (empty >= 2)
	{
		sum += empty/ 2;
		empty = empty / 2 + empty % 2;
	}
	return sum;
}
int main()
{
	int money = 0;
	int sum = 0;
	scanf("%d", &money);
	sum=Water_Number(money);
	printf("%d", sum);
	system("pause");
	return 0;
}
//最终公式：total=2*money+1 可快速计算
