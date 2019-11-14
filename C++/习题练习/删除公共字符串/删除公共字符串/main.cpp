#define _CRT_SECURE_NO_WARNINGS 1

/*输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，
则删除之后的第一个字符串变成”Thy r stdnts.”*/

#include<iostream>
using namespace std;
#include<string>

int main()
{
	string s1;//原字符串
	string s2;//删除的字符串
	getline(cin, s1);
	getline(cin, s2);
	int count[1000] = { 0 };
	for (int i = 0; i < s2.size(); i++)
	{
		count[s2[i]]++;
	}
	string result;
	for (int j = 0; j < s1.size(); j++)
	{
		if (count[s1[j]] == 0)
		{
			result += s1[j];
		}
	}
	cout << result << endl;
	system("pause");
	return 0;
}