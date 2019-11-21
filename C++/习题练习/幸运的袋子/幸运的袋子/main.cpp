#define _CRT_SECURE_NO_WARNINGS 1

/*链接：https://www.nowcoder.com/questionTerminal/a5190a7c3ec045ce9273beebdfe029ee
来源：牛客网

一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区别的)。如果一个袋子是幸运的当且仅当所有球的号码的和大于所有球的号码的积。
例如：如果袋子里面的球的号码是{1, 1, 2, 3}，这个袋子就是幸运的，因为1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
你可以适当从袋子里移除一些球(可以移除0个,但是别移除完)，要使移除后的袋子是幸运的。现在让你编程计算一下你可以获得的多少种不同的幸运的袋子。
输入描述:
第一行输入一个正整数n(n ≤ 1000)
第二行为n个数正整数xi(xi ≤ 1000)

输出描述:
输出可以产生的幸运的袋子数
示例1
输入
3
1 1 1
输出
2*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void GetCount(int sum, int mul, vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i];
		mul *= v[i];
	}
}
int GetFun(int num, vector<int>& v)
{
	int count = 0;
	auto it = v.begin();
	while (it != v.end())
	{
		int sum = 0;
		int mul = 1;
		it = v.erase(it);
		GetCount(sum, mul, v);
		it++;
	}
	return count;
}
int main()
{
	int num = 0;
	cin >> num;
	vector<int> v(num);
	for (int i = 0; i < v.size(); i++)
	{
		cin >> v[i];
	}
	cout << GetFun(num, v);
	system("pause");
	return 0;
}