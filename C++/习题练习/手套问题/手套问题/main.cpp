#define _CRT_SECURE_NO_WARNINGS 1

/*链接：https://www.nowcoder.com/questionTerminal/365d5722fff640a0b6684391153e58d8?pos=2&orderByHotValue=0&done=0
来源：牛客网

在地下室里放着n种颜色的手套，手套分左右手，但是每种颜色的左右手手套个数不一定相同。A先生现在要出门，所以他要去地下室选手套。但是昏暗的灯光让他无法分辨手套的颜色，只能分辨出左右手。所以他会多拿一些手套，然后选出一双颜色相同的左右手手套。现在的问题是，他至少要拿多少只手套(左手加右手)，才能保证一定能选出一双颜色相同的手套。

给定颜色种数n(1≤n≤13),同时给定两个长度为n的数组left,right,分别代表每种颜色左右手手套的数量。数据保证左右的手套总数均不超过26，且一定存在至少一种合法方案。

测试样例：
4,[0,7,1,6],[1,5,0,6]
返回：10(解释：可以左手手套取2只，右手手套取8只)*/
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		int leftmin = INT_MAX;
		int rightmin = INT_MAX;
		int leftsum = 0;
		int rightsum = 0;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			//// 左边或者右边没有的时候需要全部拿走
			if (left[i] * right[i] == 0)
			{
				sum += left[i] + right[i];
			}
			// 找到左边和右边分别最少的颜色的数量并计算总和
			else
			{
				leftsum += left[i];
				rightsum += right[i];
				leftmin = min(left[i], leftmin);
				rightmin = min(right[i], rightmin);
			}
		}
		// 找到左边和右边中较小的值，在另一边直接拿一个
		return sum + min(leftsum - leftmin + 1, rightsum - rightmin + 1) + 1;
	}
};
int main()
{
	Gloves g;
	int options = 0;
	cin >> options;
	vector<int> left(options);
	for (int i = 0; i < left.size(); i++)
	{
		cin >> left[i];
	}
	vector<int> right(options);
	for (int j = 0; j < right.size(); j++)
	{
		cin >> right[j];
	}
	cout << g.findMinimum(options, left, right);
	system("pause");
	return 0;
}