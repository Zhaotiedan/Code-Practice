#define _CRT_SECURE_NO_WARNINGS 1

/*题目描述见 https://blog.csdn.net/lyl194458/article/details/91545168*/
#include <iostream>
using namespace std;
#include<string>

int main()
{
	int number;//歌曲个数
	while (cin >> number)
	{
		string s;//操纵字符串
		cin >> s;
		int top = 0;//保存当前列表顶部歌曲
		int button = 0;//保存当前列表底部歌曲
		int now = 1;//保存当前光标指向歌曲数

		//光标总数小于=4
		if (number <= 4)
		{
			//初始化三个变量，now还是指向第一位
			top = 1;
			button = number;
			int i = 0;
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] == 'U')
				{
					if (now == 1)
					{
						now = button;
					}
					else
					{
						now--;
					}
				}
				else if (s[i] == 'D')
				{
					if (now == button)
					{
						now = 1;
					}
					else
					{
						now++;
					}
				}
			}
		}
		else//歌曲数大于4   实质上就是光标now在1和光标now在top位置要分两种情况
		{
			top = 1;
			now = 1;
			button = 4;
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] == 'U')
				{
					if (now == 1)
					{
						now = number;
						button = number;
						top = number - 3;
					}
					else if (now == top)
					{
						now--;
						top--;
						button--;
					}
					else
					{
						now--;
					}
				}
				else if (s[i] == 'D')
				{
					if (now == number)
					{
						now = 1;
						top = 1;
						button = now + 3;
					}
					else if (now == button)
					{
						now++;
						top++;
						button++;
					}
					else
					{
						now++;
					}
				}
			}
		}
		//输出列表
		for (int i = top; i < button; i++)
		{
			cout << i << " ";
		}
		cout << button << endl;
		cout << now << endl;
	}
	return 0;
}
