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
	cout << s.size() << endl;//size()与length()实现完全相同，size()用的更多
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

	/*总结：1. 如果是将string类中的有效元素缩小，只改变有效元素个数，不会改变底层空间大小
            2. 如果是将string类中的有效元素增多，可能需要扩容 */


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
//newcapacity > oldcapacity(string类旧空间大小)：空间增多--->容量改变(最终容量大小 >= newCapacity，vs下大约以1.5的倍率增长)
// newcapacity < oldcapacity(string类旧空间大小)：空间缩小，不影响容量
//reserve最多只改变容量大小，不会改变有效元素个数
}

//3. 利用reserve提高插入数据的效率，避免增容带来的开销
//未加reserve之前：
void TestPushBack()
{
	string s;
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');//不停地尾插，自动扩容
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}
//加reserve之后：
//因为已经预留了100的空间，所以不会增容了,sz会恒等于capacity。但如果一旦后面需要空间超过100，就会不停地增容
void TestPushBackReserve()
{
	string s;
	s.reserve(100);
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; i++)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "Capacity changed:" << sz << '\n' << endl;
		}
	}
}

//4.string类对象的访问及遍历

//4.1 访问方式
//4.1.1 operator[] 和at()返回pos位置的字符，const string类对象调用
void Test3()
{
	string s1("I love");
	const string s2("my country");
	cout << s1 << " " << s2 << endl;
	cout << s1[0] << " " << s2[0] << endl;

	s1[0] = 'H';
	s1.at(1) = 'h';
	cout << s1 << endl;
	//s2[0]='H'  报错 对象s2被const修饰，不能被修改

	//关于数组越界
	/*cout << s1[10] << endl;   数组越界，assert触发
	cout << s1.at(10) << endl;抛出out_of_range异常*/
}
//4.1.2 begin+ end begin获取一个字符的迭代器 + end获取最后一个字符下一个位置的迭
//4.1.3 rbegin + rend

//4.2 遍历方式：
void Test4()
{
	string s("I am the best");
	//1.for+operator[]
	for (size_t i = 0; i < s.size(); i++)
	{
		cout << s[i];
	}
	cout << '\n';
	//2.迭代器
	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it;
		it++;
	}
	cout << '\n';
	//3.范围for
	for (auto e : s)
	{
		cout << e;
	}
	cout << '\n';
}

//5.string类对象的修改操作
void Test5()
{
	string s;
	s.push_back('z');//在s后面插入一个字符z
	s.append("ss");//在s后面追加一个字符ss
	s += 'n';//在s后面追加一个字符n
	s += "b!";//在s后面加一个字符串"b！"
	cout << s << endl;

	string s2("I love");
	string s3(" pxy");
	s2 += s3;
	s2.append(3,'!');
	cout << s2 << endl;
	cout << s2.c_str() << endl;//以C语言的方式打印字符串

}

int main()
{
	Test1();
	Test2();
	TestPushBack();
	TestPushBackReserve();
	Test3();
	Test4();
	Test5();

	system("pause");
	return 0;
}