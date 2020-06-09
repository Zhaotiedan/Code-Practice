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
