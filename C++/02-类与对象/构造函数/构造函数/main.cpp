#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class Date
{
public:
	//通过Set公有方法给对象设置内容，但如果每次创建对象时都调用，就比较麻烦
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//默认无参构造函数，用户未定义时自动生成
	Date()
	{
		cout << "nhave" << endl;
	}
	//有参构造函数
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "have" << endl;
	}
	//默认全缺省构造函数，与默认无参构造函数矛盾，只能存在一个，一般这种比较多
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "hhave" << endl;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

//默认构造函数的作用
class Time
{
public:
	Time()
	{
		cout << "Time()" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	int _hour;
	int	_minute;
	int	_second;
};
void Test()
{
	Date d;
	Date d2(2019, 9, 16);
}
int main()
{
	//Date d;
	//d.SetDate(2019, 9, 16);
	//d.Print();

	Test();
	system("pause");
	return 0;
}