#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
using namespace std;

class Seqlist
{
public:
	//构造函数
	Seqlist(int capacity = 10)
	{
		_pdata = (int *)malloc(capacity * sizeof(int));
		assert(_pdata);
		_size = 0;
		_capacity = capacity;
	}
	//析构函数
	~Seqlist()
	{
		cout << "~Seqlist" << endl;
		if (_pdata)
		{
			free(_pdata);
			_pdata = NULL;
			_capacity = 0;
			_size = 0;
		}
	}

private:
	int * _pdata;
	size_t _size;
	size_t _capacity;
};


class String
{
public:
	String(const char * str = "jack")
	{
		_str = (char *)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		cout << " ~String()" << endl;
		free(_str);
	}
private:
	char * _str;
};
class Person
{
private:
	String _name;
	int _age;
};
int main()
{
	Seqlist s;//在结束cmd窗口时才会调用析构函数

	Person p;//会销毁p中的_name和_age
	system("pause");
	return 0;
}

//析构函数定义：
//与构造函数功能相反，在对象销毁时调用析构函数，完成对类的资源清理工作，但不是完成对对象的销毁，销毁是由编译器完成的。

//析构函数特征：
//1.在类名前加~
//2.无参数，无返回值
//3.一个类只有一个析构函数。若没有显示定义则系统自动生成析构函数
//4.只有在对象生命周期结束时，编译系统自动调用析构函数
//5.析构函数不能重载