链接：https://www.nowcoder.com/questionTerminal/d8acfa0619814b2d98f12c071aef20d4
来源：牛客网

对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。

给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。

测试样例：
"(()())",6
返回：true
测试样例：
"()a()()",7
返回：false
测试样例：
"()(()()",7
返回：false


//以下代码：牛客测试用例全部通过，但是还存在bug，比如 )()( ,())( 等

#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<string>

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		auto it = A.begin();
		
		//只要出现了除字符“（” 和字符 “）”以外的字符就返回false
		while (it != A.end())
		{
			if (*it != '(' && *it != ')')
			{
				return false;
			}
			it++;
		}
		
		//分别计算字符“（” 和字符 “）”的个数，相等则ture，不相等则false
		int count1 = 0;
		int count2 = 0;
		for (int i = 0; i < n; i++)
		{
			if (A[i] == '(')
			{
				count1++;
			}
			else
			{
				count2++;
			}
		}
		if (count1 == count2)
		{
			return true;
		}
		return false;
	}
};

int main()
{
	string s;
	int length;
	getline(cin, s);
	cin >> length;
	Parenthesis p;
	cout << p.chkParenthesis(s, length) << endl;
	system("pause");
	return 0;
}
