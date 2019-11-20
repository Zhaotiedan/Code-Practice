#define _CRT_SECURE_NO_WARNINGS 1

/*链接：https://www.nowcoder.com/questionTerminal/668603dc307e4ef4bb07bcd0615ea677?orderByHotValue=0&done=0&pos=40&onlyReference=false
来源：牛客网

在命令行输入如下命令：
xcopy /s c:\ d:\，

各个参数如下： 
参数1：命令字xcopy 
参数2：字符串/s
参数3：字符串c:\
参数4: 字符串d:\

请编写一个参数解析程序，实现将命令行各个参数解析出来。

解析规则： 
1.参数分隔符为空格 
2.对于用“”包含起来的参数，如果中间有空格，不能解析为多个参数。比如在命令行输入xcopy /s “C:\program files” “d:\”时，参数仍然是4个，第3个参数应该是字符串C:\program files，而不是C:\program，注意输出参数时，需要将“”去掉，引号不存在嵌套情况。
3.参数不定长 
4.输入由用例保证，不会出现不符合要求的输入 

输入描述:
输入一行字符串，可以有空格

输出描述:
输出参数个数，分解后的参数，每个参数都独占一行

示例1
输入
xcopy /s c:\\ d:\\
输出
4
xcopy
/s
c:\\
d:\\*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() 
{
	vector<string> mystr;
	string s;

	while (cin >> s) 
	{
		mystr.push_back(s);
	}
	string each;
	string eve;
	cout << mystr.size() << endl;
	for (int i = 0; i < mystr.size(); i++) 
	{
		each = mystr[i];
		int len = each.size();
		if (each[0] == '\"')
		{
			eve = each.substr(1, len - 2);
		}
		else if (each[len - 1] == '\"') 
		{
			eve = eve + ' ' + each.substr(0, len - 2);
			cout << eve << endl;
			eve.clear();
		}
		else
			cout << each << endl;
	}
	return 0;

}