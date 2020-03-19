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

//蓝桥杯基础练习--高精度算法
/*
问题描述
　　输入两个整数a和b，输出这两个整数的和。a和b都不超过100位。
算法描述
　　由于a和b都比较大，所以不能直接使用语言中的标准数据类型来存储。对于这种问题，一般使用数组来处理。
　　定义一个数组A，A[0]用于存储a的个位，A[1]用于存储a的十位，依此类推。同样可以用一个数组B来存储b。
　　计算c = a + b的时候，首先将A[0]与B[0]相加，如果有进位产生，则把进位（即和的十位数）存入r，把和的个位数存入C[0]，即C[0]等于(A[0]+B[0])%10。然后计算A[1]与B[1]相加，这时还应将低位进上来的值r也加起来，即C[1]应该是A[1]、B[1]和r三个数的和．如果又有进位产生，则仍可将新的进位存入到r中，和的个位存到C[1]中。依此类推，即可求出C的所有位。
　　最后将C输出即可。
输入格式
　　输入包括两行，第一行为一个非负整数a，第二行为一个非负整数b。两个整数都不超过100位，两数的最高位都不是0。
输出格式
　　输出一行，表示a + b的值。
样例输入
20100122201001221234567890
2010012220100122
样例输出
20100122203011233454668012

#include<iostream>
using namespace std;
#include<string>
#include<vector>

int main()
{
	string s1;
	string s2;
	cin >> s1 >> s2;
	int len = 0;
	int num = 0;
	int distance = 0;
	if (s1.size() >= s2.size())
	{
		len = s1.size();
		distance = s1.size() - s2.size();
	}
	else
	{
		len = s2.size();
		distance = s2.size() - s1.size();
	}
	vector<int> res(len);
	if (distance)
	{
		if (s1.size() > s2.size())
		{
			for (int i = 0; i < distance; i++)
			{
				s2.insert(i, "0");
			}
		}
		else
		{
			for (int j = 0; j < distance; j++)
			{
				s1.insert(j, "0");
			}
		}

	}
	for (int i = len-1; i  >=0; i--)
	{
		int temp = (s1[i] - '0') + (s2[i] - '0') + num;
		res[i] = temp % 10;
		num = temp / 10;
	}
	if (num)
	{
		res.insert(res.begin(), 1);
	}

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
	}
	system("pause");
	return 0;
}
*/
