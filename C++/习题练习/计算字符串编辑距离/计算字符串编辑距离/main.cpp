#define _CRT_SECURE_NO_WARNINGS 1

/*链接：https://www.nowcoder.com/questionTerminal/3959837097c7413a961a135d7104c314
来源：牛客网
Levenshtein 距离，又称编辑距离，指的是两个字符串之间，由一个转换成另一个所需的最少编辑操作次数。
许可的编辑操作包括将一个字符替换成另一个字符，插入一个字符，删除一个字符。
编辑距离的算法是首先由俄国科学家Levenshtein提出的，故又叫Levenshtein Distance。
Ex：

字符串A:abcdefg

字符串B: abcdef

通过增加或是删掉字符”g”的方式达到目的。这两种方案都需要一次操作。把这个操作所需要的次数定义为两个字符串的距离。

要求：

给定任意两个字符串，写出一个算法计算它们的编辑距离。

输入描述:
输入两个字符串
输出描述 :
得到计算结果 */
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

//int main()
//{
//	string s1;
//	string s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	int count = 0;
//	if (strcmp(s1.c_str(), s2.c_str()) == 0)
//	{
//		return 0;
//	}
//	if (s1.size() == s2.size())//只能替换
//	{
//		int i = 0;
//		while (i < s1.size())
//		{
//			if (s1[i] != s2[i])
//			{
//				s1[i] = s2[i];
//				count++;
//			}
//			i++;
//		}
//	}
//	else//替换或者插删
//	{
//		int len1 = s1.size();
//		int len2 = s2.size();
//		//替换
//		if (len1 > len2)//以小的为准
//		{
//			swap(s1, s2);
//		}
//		for (int i = 0; i < s1.size(); i++)
//		{
//			if (s1[i] != s2[i])
//			{
//				s2[i] = s1[i];
//				count++;
//			}
//		}
//		count += abs(len1 - len2);//再加上多出的部分
//	}
//	cout << count << endl;
//	system("pause");
//	return 0;
//}

int GetDis(string s1, string s2) 
{
	int len1 = (int)s1.size(), len2 = (int)s2.size();
	vector<vector<int>>dp(len1 + 1, vector<int>(len2 + 1, 0));
	dp[0][0] = 0;
	for (int i = 1; i <= len2; ++i) 
		dp[0][i] = i;
	for (int i = 1; i <= len1; ++i) 
		dp[i][0] = i;
	for (int i = 1; i <= len1; ++i) 
	{
		for (int j = 1; j <= len2; ++j) 
		{
			int first = dp[i - 1][j] + 1, second = dp[i][j - 1] + 1, third = dp[i - 1][j - 1];
			if (s1[i - 1] != s2[j - 1]) third += 1;
			dp[i][j] = min(min(first, second), third);
		}
	}
	return dp[len1][len2];
}
int main() 
{
	string a, b;
	while (cin >> a >> b)
		cout << GetDis(a, b) << endl;
	return 0;
}