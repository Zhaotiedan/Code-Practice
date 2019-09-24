#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

//1.String类对象的常见构造
void Test1()
{
	string s1;//构造空的string类对象，即空字符串
	string s2("hello");//用C-String来构造string类对象
	string s3(10, '*');//用10个*字符来构造string类对象
	string s4(s2);//拷贝构造
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
}

//2.string类对象的容量操作
void Test2()
{
	string s("change world");
	//2.1求字符串有效字符长度和空间总大小
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;

	//2.2检测字符串是否为空串
	if (s.empty())
	{
		cout << "NULL" << endl;
	}
	else
	{
		cout << s << endl;//string类对象支持直接用cin和cout进行输入和输出
	}

	//2.3清空有效字符串,清空时只是将size清0，不改变底层空间的大小
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	if (s.empty())
	{
		cout << "NULL" << endl;
	}
	else
	{
		cout << s << endl;//此时字符串为空
	}

	//2.4将有效字符的个数该成n个，多出字符串截掉，多出的空间用字符c填充
	string s1("be successful");
	cout << s1 << endl;
	cout << s1.size() << endl;//13
	cout << s1.capacity() << endl;//15

	s1.resize(10, '!');
	cout << s1 << endl;//be success
	cout << s1.size() << endl;//10
	cout << s1.capacity() << endl;//15

	s1.resize(20,'*');//如果自己不定义字符，缺省值为‘\0’
	cout << s1 << endl;//be success*********，在原来的基础上变
	cout << s1.size() << endl;//20
	cout << s1.capacity() << endl;//31

	s1.resize(6);
	cout << s1 << endl;//be suc
	cout << s1.size() << endl;//6
	cout << s1.capacity() << endl;//31

	//总结： 1. 如果是将string类中的有效元素缩小，只改变有效元素个数，不会改变底层空间大小
//       2. 如果是将string类中的有效元素增多，可能需要扩容

	//2.5void reserve(size_t newcapacity): 扩容
	string s2(20, '*');
	cout << s2.size() << endl;//20
	cout << s2.capacity() << endl;//31

	s2.reserve(20);
	cout << s2.size() << endl;//20
	cout << s2.capacity() << endl;//31

	s2.reserve(40);
	cout << s2.size() << endl;//20
	cout << s2.capacity() << endl;//47

	s2.reserve(24);
	cout << s2.size() << endl;//20
	cout << s2.capacity() << endl;//47

	s2.reserve(10);
	cout << s2.size() << endl;//20
	cout << s2.capacity() << endl;//47

	//总结： 
//newcapacity > oldcapacity(string类旧空间大小)：空间增多--->容量改变(最终容量大小 >= newCapacity)
// newcapacity < oldcapacity(string类旧空间大小)：空间缩小，该函数直接返回 除非newcapacity < 15
//只改变容量大小，不会改变有效元素个数
}
int main()
{
	Test1();
	Test2();
	system("pause");
	return 0;
}