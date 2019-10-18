#define _CRT_SECURE_NO_WARNINGS 1


//最小栈：支持 push，pop，top 操作，并能在常数时间0(1)内检索到最小元素的栈。
#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;

//1.两个栈--最优方法
class MinStack1
{
public:
	void push(const int x)
	{
		//数据栈
		s1.push(x);
		//最小值栈

		//栈空||入栈元素<=最小栈顶元素
		if (s2.empty() || x <= s2.top())
		{
			s2.push(x);
		}

	}
	int top()
	{
		return s1.top();
	}
	int GetMin()
	{
		count++;
		return s2.top();
	}
	void pop()
	{
		/*必须要把数据栈放在后面出，不然前面if条件里找不到数据栈栈顶*/
		//最小值栈

		//当最小值栈顶==数据栈栈顶时，出栈
		if (s2.top() == s1.top())
		{
			s2.pop();
		}
		//数据栈
		s1.pop();
	}
private:
	stack<int> s1;//数据栈
	stack<int> s2;//最小值栈
	int count;//监视GetMin()函数调用了几次，看时间复杂度是否为O(1)
};


//2.一次性压两个元素，一个代表本次插入值，一个代表当前栈里最小值
class MinStack2
{
public:
	void push(const int& x)
	{
		if (s.empty() || x <= s.top())
		{
			s.push(x);
			s.push(x);
		}
		else
		{
			int temp = s.top();
			s.push(x);
			s.push(temp);
		}
	}
	int top()
	{
		int ret = 0;
		int temp = s.top();
		s.pop();
		ret = s.top();
		s.push(temp);
		return ret;
	}
	int GetMin()
	{
		count++;
		return s.top();
	}
	void pop()
	{
		s.pop();
		s.pop();
	}
private:
	stack<int> s;
	int count;
};
int main()
{
	MinStack1 s;
	s.push(100);
	s.push(6);
	s.push(4);
	s.push(9);
	s.push(3);
	s.push(5);

	s.pop();
	s.pop();
	cout << s.GetMin() << endl;
	system("pause");
	return 0;
}