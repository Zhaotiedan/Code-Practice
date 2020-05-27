让我们定义dn为d（n）=p（n+1）−p（n），
其中pi是第i个素数。显然有d1=1，且对于n>1有d（n）是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N(<10^5)，请计算不超过N的满足猜想的素数对的个数。

输入格式:
输入在一行给出正整数N。

输出格式:
在一行中输出不超过N的满足猜想的素数对的个数。

输入样例:
20
输出样例:
4

  #include<iostream>
using namespace std;
#include<vector>
#include<math.h>

bool IsPrime(int temp)
{
	if (temp == 2)
	{
		return true;
	}
	for (int i = 2; i <= sqrt(temp); i++)
	{
		if (temp%i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int num = 0;
	cin >> num;
	vector<int> v;//存放N以内的素数
	int temp = 2;//当前的素数
	int count = 0;//满足条件的素数对的个数
	for (int i = 0; temp <= num; i++,temp++)
	{
		if (IsPrime(temp))
		{
			v.push_back(temp);
		}
	}
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] - v[i - 1] == 2)
		{
			count++;
		}
	}
	cout << count;
	return 0;
}
