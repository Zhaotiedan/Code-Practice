#define _CRT_SECURE_NO_WARNINGS 1


/*  链接：https://www.nowcoder.com/questionTerminal/181a1a71c7574266ad07f9739f791506
来源：牛客网

查找两个字符串a,b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。

输入描述:
输入两个字符串

输出描述:
返回重复出现的字符
示例1
输入
abcdefghijklmnop
abcsafjklmnopqrstuvw
输出
jklmnop    */
#include<iostream>
using namespace std;
#include<string>


string GetStr(string & s1, string & s2)
{
	string res;
	string temp;
	if (s1.size() > s2.size())//以短的为基准
	{
		swap(s1, s2);
	}
	for (int i = 0; i < s1.size(); i++)
	{
		for (int j = i; j < s1.size(); j++)
		{
			temp = s1.substr(i, j - i + 1);
			if ((int)s2.find(temp) < 0)
			{
				break;
			}
			else if (temp.size() > res.size())
			{
				res = temp;
			}
		}
	}
	return res;
}
int main()
{
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	cout << GetStr(s1, s2) << endl;
	system("pause");
	return 0;
}