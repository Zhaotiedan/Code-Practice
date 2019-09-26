#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	bool operator==(const Date& d2)//，左操作数是this指向的调用函数的对象
	{
		return _year == d2._year&&_month == d2._month&&_day == d2._day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2018, 9, 26);
	Date d2(2018, 9, 27);
	cout << (d1 == d2) << endl;
	system("pause");
	return 0;
}