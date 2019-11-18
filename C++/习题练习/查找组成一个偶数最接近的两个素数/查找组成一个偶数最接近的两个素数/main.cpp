#define _CRT_SECURE_NO_WARNINGS 1

/*链接：https://www.nowcoder.com/questionTerminal/f8538f9ae3f1484fb137789dec6eedb9
来源：牛客网

任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，本题目要求输出组成指定偶数的两个素数差值最小的素数对

输入描述:
输入一个偶数



输出描述:
输出两个素数

示例1
输入
20
输出
7
13*/

#include<iostream>
using namespace std;
#include<vector>

bool IsPrime(int num)
{
	if (num == 1)
	{
		return false;
	}
	else
	{
		for (int i = 2; i < num; i++)
		{
			if (num%i == 0)
			{
				return false;
			}
		}
	}
	return true;
}
void Get(int num, int *min, int *max)
{
	vector<int> v(num / 2);
	int distance = num;
	int j = 0;
	int Max = 0;
	int Min = 0;
	for (int i = 1; i <= num; i++)
	{
		if (IsPrime(i))
		{
			v[j] = i;
			j++;
		}
	}
	for (int k = 0; k < v.size(); k++)
	{
		for (int t = 1; t < v.size(); t++)
		{
			if (v[k] + v[t] == num)
			{
				*min = v[k];
				*max = v[t];
				if (distance > abs(*max - *min))
				{
					Max = *max;
					Min = *min;
					distance = abs(*max - *min);
				}
			}
		}
	}
	*max = Max;
	*min = Min;
}
int main()
{
	int num = 0;
	cin >> num;//注意在牛客网上输入时要用while循环输入
	int min = 0;
	int max = 0;
	Get(num, &min, &max);
	cout << min << endl;
	cout << max << endl;
	system("pause");
	return 0;
}