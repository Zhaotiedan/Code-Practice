#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


//浅拷贝
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d)//如果不自己定义拷贝构造函数，系统会自动生成一个，也可以完成拷贝。
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void Print(const Date& d)
	{
		cout << d._year << " " << d._month << " " << d._day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

//涉及到资源管理的拷贝
class String
{
public:
	String(const char *str = "jack")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}
private:
	char *_str;
};
int main()
{
	Date d1;
	Date d2(d1);
	d1.Print(d1);
	d2.Print(d2);

	String s1("hello");
	String s2(s1);//s1和s2共用同一块内存，s1被释放后，会找不到hello字符串，所以崩溃
	system("pause");
	return 0;
}