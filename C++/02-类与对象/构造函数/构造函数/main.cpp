#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//class Date
//{
//public:
//	//通过Set公有方法给对象设置内容，但如果每次创建对象时都调用，就比较麻烦
//	void SetDate(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//默认无参构造函数，用户未定义时自动生成
//	Date()
//	{
//		cout << "nhave" << endl;
//	}
//	//有参构造函数
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		cout << "have" << endl;
//	}
//	//默认全缺省构造函数，与默认无参构造函数矛盾，只能存在一个，一般这种比较多
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		cout << "hhave" << endl;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////默认构造函数的作用
//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//private:
//	int _hour;
//	int	_minute;
//	int	_second;
//};
//void Test()
//{
//	Date d;
//	Date d2(2019, 9, 16);
//}
//int main()
//{
//	//Date d;
//	//d.SetDate(2019, 9, 16);
//	//d.Print();
//
//	Test();
//	system("pause");
//	return 0;
//}

//class Date
//{
//public:
//	/*Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//	Date(int year, int month, int day)//构造函数初始化列表，初始化，只能一次
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{}//构造函数体内赋值，可以多次
//	void Print()
//	{
//		cout << _year << " " << _month << " " << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//包含以下成员必须在列表初始化
//class A
//{
//public:
//	A(int a)
//		: _a(a)
//	{}
//private:
//	int _a;
//};
//class B
//{
//public:
//	B(int a, int ref)
//		:_aobj(a)
//		,_ref(ref)
//		,_n(10)
//	{}
//	void Print2()
//	{
//		cout << _aobj._a << " " << _ref << " " << _n << endl;
//	}
//private:
//	A _aobj;//类类型成员
//	int& _ref;//引用
//	const int _n;//const成员变量
//	//上述三种都必须在初始化列表进行初始化
//};

class Time
{
public:
	Time(int hour = 0)
		:_hour(hour)
	{
		cout << "Time()" << endl;
	}
private:
	int _hour;
};

class Date
{
public:
	Date(int day)
	{}
private:
	int _day;
	Time _t;//自定义类型的成员变量一定会使用初始化列表进行初始化
};

int main()
{
	/*Date d1(1900, 1, 1);
	d1.Print();*/

	//B b(10, 20);
	//b.Print2();

	Date d(1);
	system("pause");
	return 0;
}