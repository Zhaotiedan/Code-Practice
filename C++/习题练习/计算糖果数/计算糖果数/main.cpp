#define _CRT_SECURE_NO_WARNINGS 1

/*链接：https://www.nowcoder.com/questionTerminal/02d8d42b197646a5bbd0a98785bb3a34
来源：牛客网

A,B,C三个人是好朋友,每个人手里都有一些糖果,我们不知道他们每个人手上具体有多少个糖果,但是我们知道以下的信息：
A - B, B - C, A + B, B + C. 这四个数值.每个字母代表每个人所拥有的糖果数.
现在需要通过这四个数值计算出每个人手里有多少个糖果,即A,B,C。这里保证最多只有一组整数A,B,C满足所有题设条件。*/
#include<iostream>
using namespace std;
#include<algorithm>


int main()
{
	int num1, num2, num3, num4 = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	cin >> num1 >> num2 >> num3 >> num4;
	a = num1 + num3;//2A
	b = num2 + num4;//2B
	c = num4 - num2;//2C
	if (a - b == 2 * num1)
	{
		if (b - c == 2 * num2)
		{
			if (a + b == 2 * num3)
			{
				if (b + c == 2 * num4)
				{
					if ((a % 2 == 0) && (b % 2 == 0) && (c % 2 == 0))
					{
						cout << a / 2 << " " << b / 2 << " " << c / 2 << " " << endl;
					}
					else
					{
						cout << "No" << endl;
					}
				}
			}
		}
	}
	else
	{
		cout << "No" << endl;
	}
	system("pause");
	return 0;
}