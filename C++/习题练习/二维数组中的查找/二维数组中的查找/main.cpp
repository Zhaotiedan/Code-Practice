#define _CRT_SECURE_NO_WARNINGS 1


//题目描述
/*在一个二维数组中（每个一维数组的长度相同），
每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。*/
#include<iostream>
using namespace std;
#include<vector>

class Solution
{
public:
	bool Find(int target, vector<vector<int>> array)
	{
		//注意一定要先判空，再求array的size
		if (array.empty())
		{
			return false;
		}
		int len = array.size();
		//int lensize = array[0].size();
		for (size_t i = 0; i < len; i++)
		{
			if (array[i].empty())
			{
				continue;
			}
			if (target == array[i][0])
			{
				return true;
			}
			if (target > array[i][0])
			{
				if (target <= array[i][array[i].size() - 1])
				{
					for (size_t j = 0; j < array[i].size(); j++)
					{
						if (target == array[i][j])
						{
							return true;
						}
					}
				}
			}
		}
		return false;
	}
};
int main()
{
	vector<vector<int>> v{ {10,20,30},{11,22,33},{100},{200},{300},{120,220,330} };
	Solution s;
	if (s.Find(100, v))
	{
		cout << "find it" << endl;
	}
	else
	{
		cout << "can't find" << endl;
	}
	system("pause");
	return 0;
}