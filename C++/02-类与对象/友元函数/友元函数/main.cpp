#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


//友元函数的引出
class Date
{
	friend ostream& operator<<(ostream& _cout, const Date& d);
public:
	Date(int year, int month, int day)
		:_year(year)
		,_month(month)
		,_day(day)
	{}

	//第一次<<操作符的重载  暂时先把返回值给成void
	//void operator<<(ostream& _cout)//参数传的是<<的左操作数和右操作数，因为第一个参数时this指针，所以只能写d<<cout
	//{
	//	_cout << _year << "-" << _month << "-" << _day << endl;
	//}
	//第二次，假设再传一个参数 对象d，报错，因为只要这个运算符重载是成员函数，就一定会传递一个隐藏参数在第首位，
	//所以再传一个对象d会使得运算符函数的参数太多
	/*void operator<<(ostream& _cout, const Date & d)
	{

	}*/

	//第四次，给了ostream的返回值
	ostream&  operator<<(ostream& _cout)
	{
		_cout << _year << "-" << _month << "-" << _day << endl;
		return _cout;
	}
	
	//第五次，友元函数。
private:
	int _year;
	int _month;
	int _day;
};
//第三次，将运算符重载成全局函数
//报错：类外无法访问对象d的成员void operator<<(ostream &_cout, const Date& _d)

/*{
	cout << d._year << "-" << d._month << "-" << d._day << endl;
}*/

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day << endl;
	return _cout;
}

int main()
{
	Date d1(1900, 1, 1);
	Date d2(1900, 1, 2);

	//cout << d << endl;//报错：不能直接打印一个对象。只能重载操作符<<

	//d2<<d1 << cout;//报错，因为运算符重载无返回值，所以不能连续打印

	cout << d1 << d2 << endl;
	system("pause");
	return 0;
}