#define _CRT_SECURE_NO_WARNINGS 1

/*题目描述

问题描述：在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。
现要求各位实现字符串通配符的算法。
要求：
实现如下2个通配符：
* ：匹配0个或以上的字符（字符由英文字母和数字0-9组成，不区分大小写。下同）
？：匹配1个字符

输入：

通配符表达式；
一组字符串。
输出：

返回匹配的结果，正确输出true，错误输出false
输入描述:

先输入一个带有通配符的字符串，再输入一个需要匹配的字符串
输出描述:

返回匹配的结果，正确输出true，错误输出false
示例1

输入
te?t*.*
txt12.xls
输出
false    */
#include<iostream>
using namespace std;
#include<string>

bool fun(const char* s1, const char* s2)
{
	if (*s1 == *s2&&*s1 == '\0')
	{
		return true;
	}
	else if (*s1 == '\0' || *s2 == '\0')
	{
		return false;
	}

	//?  向后匹配一个字符
	if (*s1 == '?')
	{
		return fun(s1 + 1, s2 + 1);
	}
	//*，匹配0个1个或者多个
	else if (*s1 == '*')
	{
		return fun(s1, s2 + 1) || fun(s1 + 1, s2 + 1) || fun(s1 + 1, s2 + 1);
	}
	//匹配上了，直接匹配下一个
	else if (*s1 == *s2)
	{
		return fun(s1 + 1, s2 + 1);
	}
	return false;
}
int main()
{
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	cout << fun(s1.c_str(), s2.c_str()) << endl;
	system("pause");
	return 0;
}