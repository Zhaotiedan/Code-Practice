/*
问题描述
　　求出区间[a,b]中所有整数的质因数分解。
输入格式
　　输入两个整数a，b。
输出格式
　　每行输出一个数的分解，形如k=a1*a2*a3...(a1<=a2<=a3...，k也是从小到大的)(具体可看样例)
样例输入
3 10
样例输出
3=3
4=2*2
5=5
6=2*3
7=7
8=2*2*2
9=3*3
10=2*5
提示
　　先筛出所有素数，然后再分解。
数据规模和约定
　　2<=a<=b<=10000
*/

#include<iostream>
using namespace std;
#include<math.h>

bool IsPrime(int n)
{
	if (n == 1 || n == 2)
	{
		return true;
	}
	else
	{
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n%i == 0)
			{
				return false;
			}
		}
		return true;
	}
}

void Break(int n)
{
	while (n>1)
	{
		int i = 2;
		while (n%i)
		{
			i++;
		}
		while (n%i == 0)
		{
			cout << i;
			n /= i;
			if (n > 1)
			{
				cout << "*";
			}
			else
			{
				break;
			}
		}
	}
}

int main()
{
	int a = 0, b = 0;
	cin >> a >> b;
	for (int i = a; i <= b; i++)
	{
		//筛选素数
		if (IsPrime(i))
		{
			cout << i << "=" << i;
		}
		else
		{
			cout << i << "=";
			Break(i);
		}
		cout << endl;

	}
	system("pause");
	return 0;
}
