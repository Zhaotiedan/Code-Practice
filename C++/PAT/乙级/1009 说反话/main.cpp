给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

输入格式：
测试输入包含一个测试用例，在一行内给出总长度不超过 80 的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用 1 个空格分开，输入保证句子末尾没有多余的空格。

输出格式：
每个测试用例的输出占一行，输出倒序后的句子。

输入样例：
Hello World Here I Come
输出样例：
Come I Here World Hello

#include<iostream>
using namespace std;
#include<string>
#include<algorithm>

int main()
{
	string s;
	getline(cin, s);
	reverse(s.begin(), s.end());
	int i = 0;
	int k = 0;//逆置起始位置相对于最开始begin的偏移位数
	while (i<s.size())
	{
		while ((s[i]!= ' ') && (i!=s.size()))
		{
			i++;
		}
		reverse(s.begin() + k, s.begin() + i );
		if (s[i] == ' ')
		{
			i++;//当找到一个空格时，要指向下一个不为‘ ’的字符
			k = i;
		}
	}
	cout << s;
	return 0;
}
