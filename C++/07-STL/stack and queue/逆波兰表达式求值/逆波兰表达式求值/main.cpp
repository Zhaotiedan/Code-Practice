#define _CRT_SECURE_NO_WARNINGS 1

//逆波兰：后缀表达式 运算符在两个操作数后
//(1+2)*(4-3)--->  1 2 + 4 3- *

#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<stack>

int evalRPN(vector<string>& tokens)
{
	stack<int> s;
	int right = 0;
	int left = 0;
	for (size_t i = 0; i < tokens.size(); i++)
	{
		string& str = tokens[i];
		//为数字 入栈
		if ((str != "+")&&(str != "-")&&(str != "*")&&(str != "/"))
		{
			s.push(atoi(str.c_str()));
		}
		//为操作符 
		else
		{
			right = s.top();
			s.pop();
			left = s.top();
			s.pop();
			switch (str[0])
			{
			case '+':
				s. push(left + right);
				break;
			case '-':
				s.push(left - right);
				break;
			case'*':
				s.push(left*right);
				break;
			case'/':
				s.push(left / right);
				break;
			default:
				break;
			}
		}
	}
	return s.top();
}
int main()
{
	system("pause");
	return 0;
}