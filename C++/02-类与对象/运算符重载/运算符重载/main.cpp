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
	bool operator==(const Date& d1, const Date& d2)
	{
		return d1._year == d2.
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

	system("pause");
	return 0;
}