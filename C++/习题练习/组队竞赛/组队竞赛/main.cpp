#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

int GetMax(int group, vector<int> v)
{
	int max = 0;
	sort(v.begin(), v.end());
	while (group)
	{
		for (int i = group; i <= 3 * group - 2; i += 2)
		{
			max += v[i];
		}
	}
	return max;
}
int main()
{
	int group = 0;
	cin >> group;
	vector<int> v(3 * group);
	for (auto e : v)
	{
		cin >> e;
	}
	cout << GetMax(group, v) << endl;
	system("pause");
	return 0;
}