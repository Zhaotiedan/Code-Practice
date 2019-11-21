#define _CRT_SECURE_NO_WARNINGS 1


/*根据输入的日期，计算是这一年的第几天。。
详细描述：
输入某年某月某日，判断这一天是这一年的第几天？。
链接：https://www.nowcoder.com/questionTerminal/769d45d455fe40b385ba32f97e7bcded
来源：牛客网

输入描述:
输入三行，分别是年，月，日

输出描述:
成功:返回outDay输出计算后的第几天;   失败:返回-1
 */


#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Get(int year, int month, int day)
{
	vector<int> days{ 31,28,31,30,31,30,31,31,30,31,30,31 };
	int sum = 0;
	int i = 0;
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
	{
		days[1] = 29;
	}
	while (month-1)
	{
		sum += days[i];
		i++;
		month--;
	}
	sum += day;
	return sum;
}
int main()
{
	int year = 0;
	int month = 0;
	int day = 0;
	while (cin >> year >> month >> day)
	{
		cout << Get(year, month, day) << endl;
	}

	system("pause");
	return 0;
}