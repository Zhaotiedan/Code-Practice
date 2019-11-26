#define _CRT_SECURE_NO_WARNINGS 1

/*有一只兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子，假如兔 子都不死，问每个月的兔子总数为多少？

输入描述： 输入int型表示month
输出描述： 输出兔子总数int型

示例

输入 9
输出 34  */

/*思路：第n个月的兔子数量由两部分组成，一部分是上个月的兔子f(n-1)，
另一部是满足3个月大的兔子，会生一只兔子f(n2)。所以第n个月兔子总数： f(n) = f(n -1) +f(n -2)。
本题是在变相考察斐波那契数列*/

#include<iostream>
using namespace std;


int GetNum(int month)
{
	if (month == 1 || month == 2)
	{
		return 1;
	}
	else
	{
		return GetNum(month - 1) + GetNum(month - 2);
	}
}
int main()
{
	int month = 0;
	cin >> month;
	cout << GetNum(month) << endl;
	system("pause");
	return 0;
}