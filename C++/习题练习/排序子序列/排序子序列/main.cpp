#define _CRT_SECURE_NO_WARNINGS 1

/*链接：https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471
来源：牛客网

牛牛定义排序子序列为一个数组中一段连续的子序列,并且这段子序列是非递增或者非递减排序的。牛牛有一个长度为n的整数数组A,
他现在有一个任务是把数组A分为若干段排序子序列,牛牛想知道他最少可以把这个数组分为几段排序子序列.
如样例所示,牛牛可以把数组A划分为[1,2,3]和[2,2,1]两个排序子序列,至少需要划分为2个排序子序列,所以输出2*/
#include<iostream>
using namespace std;
#include<vector>

int main()
{
	int len = 0;
	cin >> len;
	vector<int> v(len);
	for (int i = 0; i < len; i++)
	{
		cin >> v[i];
	}
	int i = 0;
	int count = 0;
	if (len == 1)
	{
		count = 1;
	}

	while (i < len)
	{
		if (v[i + 1] > v[i])
		{
			while (i < len - 1 && v[i + 1] >= v[i])
			{
				i++;
			}
			count++;
			i++;
		}
		else if (v[i + 1] < v[i])
		{
			while (i < len - 1 && v[i + 1] <= v[i])
			{
				i++;
			}
			count++;
			i++;
		}
		else
		{
			i++;
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}