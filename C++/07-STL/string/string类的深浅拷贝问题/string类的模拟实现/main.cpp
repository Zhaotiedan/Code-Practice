#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

/* 一.深拷贝和浅拷贝*/

//1.浅拷贝的string类
class String1
{
	friend ostream& operator<<(ostream& _cout, const String1& s);
public:
	//构造函数
	String1(const char* str = "")
	{
		if (nullptr == str)
		{
			str = "";
		}
		//申请空间
		_str = new char[strlen(str) + 1];
		//存放str的字符
		strcpy(_str, str);
	}

	//编译器自动生成的拷贝构造函数和运算符重载
	String1(const String1& s)
		: _str(s._str)
	{}
	String1& operator=(const String1& s)
	{
		_str = s._str;
		return *this;
	}


	//析构函数
	~String1()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};
ostream& operator<<(ostream& _cout, const String1& s)
{
	_cout << s._str;
	return _cout;
}

void Test1()
{
	String1 s1("HongKong belongs to China!");
	//String1 s2(s1);//编译器调用默认拷贝构造函数，浅拷贝，回引起程序崩溃
	cout << s1 << endl;
	//cout << s2 << endl;//崩溃3

}

//2.深拷贝--传统版string类
class String2
{
	friend ostream& operator<<(ostream& _cout, const String2& s);
public:
	//构造函数
	String2(const char* s = "")
	{
		if (s == nullptr)
		{
			s = "";
		}
		_str = new char[strlen(s) + 1];
		strcpy(_str, s);
	}

	//自定义拷贝构造
	String2(const String2& s)
		:_str(new char[strlen(s._str) + 1])// 申请空间
	{
		strcpy(_str, s._str);// 存放str中的字符
	}

	//自定义运算符重载  s1=s2
	String2& operator=(const String2& s)
	{
		if (this != &s)//不能写s
		{
			char *pstr = new char[strlen(s._str) + 1];
			strcpy(pstr, s._str);
			delete[] _str;
			_str = pstr;
		}
		return *this;
	}

	~String2()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};
ostream& operator<<(ostream& _cout, const String2& s)
{
	_cout << s._str;
	return _cout;
}
void Test2()
{
	String2 s1("I love my country!");
	String2 s2(s1);
	cout << s1 << endl;
	cout << s2 << endl;
}

//3.深拷贝--现代版string类
class String3
{
	friend ostream& operator<<(ostream& _cout, String3 s);
public:
	String3(const char* s = "")
	{
		if (nullptr == s)
		{
			s = "";
		}
		_str = new char[strlen(s) + 1];
		strcpy(_str, s);
	}

	//拷贝构造
	String3(const String3& s)
		:_str(nullptr)//为了不给strtemp传随机值导致无法释放，传一个空值
	{
		String3 strtemp(s._str);//调用构造函数，构造这个临时对象
		swap(_str, strtemp._str);
	}

	//赋值运算符重载--两种方式，一个传引用，一个传对象

	//String3& operator=(const String3& s)
	//{
	//	if (this != &s)
	//	{
	//		String3 stemp(s);//拷贝构造
	//		swap(_str, stemp._str);
	//	}
	//	return *this;
	//}
	String3& operator=(String3 s)//s是对象的一份临时拷贝
	{
		swap(_str, s._str);//这次_str指向的是 拷贝来的这份空间，而原来本身的还是由原来对象的指针指向
		return *this;
	}

	~String3()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

private:
	char* _str;
};
ostream& operator<<(ostream& _cout, String3 s)
{
	_cout << s._str;
	return _cout;
}
void Test3()
{
	String3 s1("I am an Chinese!");
	String3 s2(s1);
	String3 s3;
	s3 = s2;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
}

//4.写时拷贝



/*string类的模拟实现*/

int main()
{
	Test1();
	Test2();
	Test3();

	system("pause");
	return 0;
}