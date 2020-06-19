1. 栈在括号匹配中的应用
链接：https://www.nowcoder.com/questionTerminal/37548e94a270412c8b9fb85643c8ccc2
来源：牛客网

给出一个仅包含字符'(',')','{','}','['和']',的字符串，判断给出的字符串是否是合法的括号序列
括号必须以正确的顺序关闭，"()"和"()[]{}"都是合法的括号序列，但"(]"和"([)]"不合法。

//cpp写法，利用stack容器

class Solution {
public:
    
    bool isValid(string s) {
        /*   //如果括号总数为奇数，直接报错 注意该条件可有可无，因为当扫描到右括号时，如果栈空（代表没有一个左括号）会直接返回false
        if(s.size()%2!=0)
        {
            return false;
        }*/
        
        stack<char> st;
        
        for(int i=0;i<s.size();i++)
        {
            //左括号 直接入栈
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
            {
                st.push(s[i]);
            }
            //右括号
            else
            {
             //如果此时栈空，则直接false
                if(st.empty())
                {
                    return false;
                }
                char temp=st.top();//获取栈顶的左括号
                st.pop();//注意一定要出栈
                
                //不合法的三种情况
                if(s[i]==')')
                {
                    if(temp!='(')
                    {
                        return false;
                    }
                }
                else if(s[i]==']')
                {
                    if(temp!='[')
                    {
                        return false;
                    }
                }
                else if(s[i]=='}')
                {
                    if(temp!='{')
                    {
                        return false;
                    }
                }
            }
        }
        //如果栈为空，则说明全部匹配，合法
        if(st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

链接：https://www.nowcoder.com/questionTerminal/4e7267b55fdf430d9403aa12206572b3
来源：牛客网

将中缀表达式转为后缀表达式，输入 a+b*c/d-a+f/b 输出 abc*d/+a-fb/+
要求：语言不限；输入输出均为单个字符串；操作数用单个小写字母表示，操作符只需支持 +-*/ 按照四则运算顺序确定优先级，不包含括号

输入描述:
一个字符串为合法的中缀表达式
字符串长度不超过200000


输出描述:
对应的后缀表达式
示例1
输入
a+b*c/d-a+f/b
输出
abc*d/+a-fb/+

#include<iostream>
using namespace std;
#include<stack>
#include<string>

//a为栈顶元素，b为当前操作符号 能弹出则返回true
bool priority(const char a, const char b)
{
	if (a == '*' || a == '/')//栈顶a优先级高于或等于b
	{
		return true;
	}
	else//代表a是+或-
	{
		if (b == '*' || b == '/')
		{
			return false;
		}
		return true;
	}
}
int main()
{
	string s;
	cin >> s;
	stack<char> st;
	string res;
	for (int i = 0; i < s.size(); i++)
	{
		//操作数
		if (s[i] >= 97 && s[i] <= 122)
		{
			res.push_back(s[i]);
		}
		//运算符 + - * /
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
		{
			//如果当前栈空，则直接入栈
			if (st.empty())
			{
				st.push(s[i]);
			}
			//栈不为空,判断是否满足弹出条件
			else
			{
				while ((!st.empty())&&priority(st.top(), s[i]))
				{
					res.push_back(st.top());
					st.pop();
				}
				//弹出结束或者不具备弹出条件，当前操作符入栈
				st.push(s[i]);
			}
		}
	}
	while (!st.empty())
	{
		res.push_back(st.top());
		st.pop();
	}
	cout << res;
	system("pause");
	return 0;
}
