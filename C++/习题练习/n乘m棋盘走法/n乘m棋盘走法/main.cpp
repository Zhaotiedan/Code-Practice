#define _CRT_SECURE_NO_WARNINGS 1

/*请编写一个函数（允许增加子函数），计算n x m的棋盘格子（n为横向的格子数，m为竖向的格子数）
沿着各自边缘线从左上角走到右下角，
总共有多少种走法，要求不能走回头路，
即：只能往右和往下走，不能往左和往上走。*/
#include<iostream>
using namespace std;


//递归
int GetFun(int n, int m)
{
	if (n == 0 || m == 0)
	{
		return 0;
	}
	if (n == 1 && m >= 1)
	{
		return m + 1;
	}
	if (m == 1 && n >= 1)
	{
		return n + 1;
	}
	if (m > 1 && n > 1)
	{
		return GetFun(n - 1, m) + GetFun(n, m - 1);
	}
}

//循环
int GetFun1(int n, int m)
{
	int count = 0;
	int tempn = n;
	int tempm = m;
	while (tempn)
	{
		for (int i = 1; i <= n + 1; i++)
		{}
		tempn--;
		for (int j = 1; j <= m + 1; j++)
		{}
		count++;
	}
	while (tempm)
	{
		for (int j = 1; j <= m + 1; j++)
		{
		}
		tempm--;
		for (int i = 1; i <= n + 1; i++)
		{
		}
		count++;
	}
	return count;
}
int main()
{
	int n = 0;
	int m = 0;
	while (cin >> n >> m)
	{
		cout << GetFun1(n, m) << endl;
	}
	system("pause");
	return 0;
}

