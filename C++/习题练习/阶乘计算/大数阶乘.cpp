/*
问题描述
　　输入一个正整数n，输出n!的值。
　　其中n!=1*2*3*…*n。
算法描述
　　n!可能很大，而计算机能表示的整数范围有限，需要使用高精度计算的方法。使用一个数组A来表示一个大整数a，A[0]表示a的个位，A[1]表示a的十位，依次类推。
　　将a乘以一个整数k变为将数组A的每一个元素都乘以k，请注意处理相应的进位。
　　首先将a设为1，然后乘2，乘3，当乘到n时，即得到了n!的值。
输入格式
　　输入包含一个正整数n，n<=1000。
输出格式
　　输出n!的准确值。
样例输入
10
样例输出
3628800
*/

#include<iostream>
using namespace std;
#include<vector>

int main()
{
	int n = 0;
	cin >> n;
	vector<int> v(3000, 0);
	v[0] = 1;
	int dight = 1;//代表当前数字位数，第一次是1位数
	int temp, num = 0;
	for (int i = 2; i <= n; i++)
	{
		num = 0;//注意每次要将num置0
		for (int j = 0; j < dight; j++)
		{
			temp = v[j] * i + num;
			v[j] = temp % 10;//每一次数字的个位数
			num = temp / 10;
		}
		while (num)//代表不止dight位数，需要将最高位进行存储
		{
			v[dight] = num % 10;
			num /= 10;
			dight++;
		}
	}
	for (int i = dight - 1; i >= 0; i--)
	{
		cout << v[i];
	}
	system("pause");
	return 0;
}
