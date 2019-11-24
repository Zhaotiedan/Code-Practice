#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;
#include<algorithm>

/*题目描述
请设计一个算法完成两个超长正整数的加法。

接口说明：

 /*
 请设计一个算法完成两个超长正整数的加法。
 输入参数：
 String addend：加数
 String augend：被加数
 返回值：加法结果
输入描述:
输入两个字符串数字

输出描述 :
输出相加后的结果，string型

示例1
输入

99999999999999999999999999999999999999999999999999
1
输出

100000000000000000000000000000000000000000000000000*/

int main()
{
	string s1;
	string s2;
	cin >> s1 >> s2;
	int len1 = s1.size();
	int len2 = s2.size();
	string res;
	int s = 0;
	int c = 0;
	int i = len1 - 1;
	int j = len2 - 1;
	while (i >= 0 || j >= 0)
	{
		if (i >= 0)
		{
			s += s1[i] - '0';
		}
		if (j >= 0)
		{
			s += s2[j] - '0';
		}
		s += c;//当前包括进位所得到的值
		res += s % 10+'0';
		c = s / 10;//进位
		s = 0;
		i--;
		j--;
	}
	if (c ==1)
	{
		res += '1';
	}
	reverse(res.begin(),res.end());
	cout << res << endl;

	system("pause");
	return 0;
}