#define _CRT_SECURE_NO_WARNINGS 1

/*题目描述
小易经常沉迷于网络游戏.有一次,他在玩一个打怪升级的游戏,他的角色的初始能力值为 a.
在接下来的一段时间内,他将会依次遇见n个怪物,每个怪物的防御力为b1,b2,b3...bn. 
如果遇到的怪物防御力bi小于等于小易的当前能力值c,那么他就能轻松打败怪物,并 且使得自己的能力值增加bi;
如果bi大于c,那他也能打败怪物,但他的能力值只能增加bi 与c的最大公约数.那么问题来了,在一系列的锻炼后,
小易的最终能力值为多少?

输入描述:
对于每组数据,第一行是两个整数n(1≤n<100000)表示怪物的数量和a表示小易的初始能力值.
第二行n个整数,b1,b2...bn(1≤bi≤n)表示每个怪物的防御力
输出描述:
对于每组数据,输出一行.每行仅包含一个整数,表示小易的最终能力值
示例1
输入
3 50 50 105 200 5 20 30 20 15 40 100
输出
110
205*/

#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>

int GetNum(int a, int n)
{
	if (a > n)
	{
		swap(a, n);
	}
	int max = 0;
	for (int i = 1; i <= a; i++)
	{
		if (n%i == 0 && a%i == 0)
		{
			if (i > max)
			{
				max = i;
			}
		}
	}
	return max;
}
int main()
{
	int n, a = 0;
	cin >> n >> a;
	vector<int> v(n);
	for (int i = 0; i < v.size(); i++)
	{
		cin >> v[i];
	}
	for (int j = 0; j < v.size(); j++)
	{
		if (v[j] <= a)
		{
			a += v[j];
		}
		else
		{
			a += GetNum(a, v[j]);
		}

	}
	cout << a << endl;
	system("pause");
	return 0;
}