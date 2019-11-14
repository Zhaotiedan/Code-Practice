#define _CRT_SECURE_NO_WARNINGS 1
/*链接：https://www.nowcoder.com/questionTerminal/bd891093881d4ddf9e56e7cc8416562d
来源：牛客网

读入一个字符串str，输出字符串str中的连续最长的数字串

输入描述:
个测试输入包含1个测试用例，一个字符串str，长度不超过255。


输出描述:
在一行内输出str中里连续最长的数字串。
示例1
输入
abcd12345ed125ss123456789
输出
123456789*/

#include<iostream>
using namespace std;
#include<vector>
#include<string>

int main()
{
	string s;
	getline(cin, s);
	vector<char> v{ '0','1','2','3','4','5','6','7','8','9'};
	string store;
	string result;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0'&&s[i] <= '9')
		{
			for (int j = 0; j < v.size(); j++)
			{
				if (s[i] == v[j])
				{
					store.reserve(1);
					store += s[i];
					i++;
				}
			}
			if (store.size() > result.size())
			{
				result = store;
			}
		}
		store.clear();
	}
	cout << result << endl;
	system("pause");
	return 0;
}