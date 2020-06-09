问题描述
小张是软件项目经理，他带领3个开发组。工期紧，今天都在加班呢。为鼓舞士气，小张打算给每个组发一袋核桃（据传言能补脑）。他的要求是：

1. 各组的核桃数量必须相同

2. 各组内必须能平分核桃（当然是不能打碎的）

3. 尽量提供满足1,2条件的最小数量（节约闹革命嘛）

输入格式
输入包含三个正整数a, b, c，表示每个组正在加班的人数，用空格分开（a,b,c<30）
输出格式
输出一个正整数，表示每袋核桃的数量。
样例输入1
2 4 5
样例输出1
20
样例输入2
3 1 1
样例输出2
3

#include<iostream>
using namespace std;
#include<vector>


int main()
{
	int count = 0;//所求核桃的总数
	vector<int> v(3);
	for (int i = 0; i < v.size(); i++)
	{
		cin >> v[i];
	}

	int max = v[0];//找最大值
	for (int i = 0; i < v.size(); i++)
	{
		if (max < v[i])
		{
			max = v[i];
		}
	}
//找最小公倍数
	for (int i = max;; i++)
	{
		int j = 0;
		for (; j < v.size(); j++)
		{
			if (!(i%v[j] == 0))//不能整除
			{
				break;
			}
			else
			{
				count = i;
			}
		}
		if (j == v.size())
		{
			break;
		}
	}
	cout << count;
	system("pause");
	return 0;
}
