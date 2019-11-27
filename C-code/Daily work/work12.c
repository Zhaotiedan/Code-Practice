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

/*牛客汽水题
链接：https://www.nowcoder.com/questionTerminal/fe298c55694f4ed39e256170ff2c205f
来源：牛客网

“某商店规定：三个空汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶，她最多可以换多少瓶汽水喝？”答案是5瓶，
方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，喝完以后4个空瓶子，用3个再换一瓶，喝掉这瓶满的，这时候剩2个空瓶子。
然后你让老板先借给你一瓶汽水，喝掉这瓶满的，喝完以后用3个空瓶子换一瓶满的还给老板。如果小张手上有n个空汽水瓶，
最多可以换多少瓶汽水喝？

输入描述:
输入文件最多包含10组测试数据，每个数据占一行，仅包含一个正整数n（1<=n<=100），
表示小张手上的空汽水瓶数。n=0表示输入结束，你的程序不应当处理这一行。
输出描述:
对于每组测试数据，输出一行，表示最多可以喝的汽水瓶数。如果一瓶也喝不到，输出0。

示例1
输入
3
10
81
0
输出
1
5
40*/

//C++:
#include<iostream>
using namespace std;

int GetNum(int n)
{
	int sum = 0;
	int total = n;
	while (total >= 3)
	{
		sum += total / 3;
		total = total / 3 + total % 3;
	}
	if (total == 2)
	{
		sum++;
	}
	return sum;
}
int main()
{
	int num = 0;
	while (cin >> num)
	{
		cout << GetNum(num) << endl;
	}
	return 0;
}
//最终公式：total=2*money+1 可快速计算
