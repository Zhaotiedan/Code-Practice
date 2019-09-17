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

//涉及到资源管理的拷贝，如果继续使用默认拷贝函数
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
	String s2(s1);//s1和s2共用同一块内存空间，s1被释放后，会找不到hello字符串，所以崩溃
	system("pause");
	return 0;
}

//拷贝构造函数概念：
//单个形参，该形参为对本类类型对象的引用，用来创造一个和一个对象一样的新对象。
//说白了，就是将一个对象里的内容原封不动地拷贝到另一个对象里


//拷贝构造函数特征：
//1.是构造函数的重载形式
//2.它的参数只有一个，并且要使用引用传参，不然会引发无穷调用
//3.用户未显示定义时，系统会默认生成,成为浅拷贝
//4.涉及到资源管理时，就不能再用浅拷贝，不然可能程序崩溃和内存泄漏