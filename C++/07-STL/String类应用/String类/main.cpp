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

	s2.resize(6);
	s2.reserve(15);
	cout << s2.size() << endl;//6
	cout << s2.capacity() << endl;//15

  //总结： 
//newcapacity > oldcapacity(string类旧空间大小)：空间增多--->容量改变(最终容量大小 >= newCapacity，vs下大约以1.5的倍率增长)
//newcapacity < oldcapacity(string类旧空间大小)：空间缩小，当size大于capacity初始容量(15),不影响容量,当size小于15时，空间缩小至<=15时，capacity才会变成15
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
//5.1 push_back、append、operator+=、c_str
void Test5()
{
	string s;
	s.push_back('z');//在s后面插入一个字符zl
	s.append("ss");//在s后面追加一个字符ss
	s += 'n';//在s后面追加一个字符n
	s += "b!";//在s后面加一个字符串"b！"
	cout << s << endl;

	string s2("I love");
	string s3(" pxy");
	s2 += s3;
	s2.append(3,'!');
	cout << s2 << endl;
	cout << s2.c_str() << endl;//以C语言的方式打印字符串 返回值为const char*
	cout << atoi(s2.c_str()) << endl;//atoi--函数 把字符串转换成整型数 int atoi(const char *nptr)
}
//5.2 find+npos, rfind, substr,erase
void Test6()
{
	//find+npos 从前往后找

	string s1("I love C++!");
	//查找一个字符，返回下标
	size_t pos = s1.find('C');
	if (pos != string::npos)//string 类将 npos 定义为保证大于任何有效下标的值
	{
		cout << 'C' << " is in s1 " << pos << endl;
	}
	else
	{
		cout << "not in" << endl;
	}
	//查找一个字符串，返回首元素下标
	size_t pos2 = s1.find("love");
	if (pos2 != string::npos)
	{
		cout << "love" << " is in s1 " << pos2 << endl;
	}
	else
	{
		cout << "not in" << endl;
	}


	//rfind从后往前找,substr从pos往后截取n个字符并返回,不定义n时遍历到字符串结尾

	//获取文件的后缀名
	string s2("main.cpp");
	size_t pos3 = s2.rfind('.') + 1;
	cout << s2.substr(pos3) << endl;
	cout << s2.substr(pos3, s2.size() - pos3) << endl;
	//取出一个网站的域名
	string s3("http://www.cplusplus.com/reference/string/string/find/");
	cout << s3 << endl;
	size_t start = s3.find("://");
	if (start == string::npos)
	{
		cout << " not in" << endl;
	}
	start += 3;
	size_t end = s3.find('/', start);
	cout << s3.substr(start, end - start) << endl;

	//erase 擦除
	//删除 s3的协议前缀
	size_t pos4 = s3.find("://");
	s3.erase(0, pos4 + 3);
	cout << s3 << endl;
}

//6.string类的非成员函数 operator+，operator>>, operator<<, getline, relational operators


//7.一些题目
//7.1 翻转字符串
void ReverseString1(string& s)
{
	//指针
	char* begin = (char*)s.c_str();
	char* end = begin + s.size() - 1;
	while (begin < end)
	{
		swap(*begin, *end);
		begin++;
		end -- ;
	}
}
void ReverseString2(string& s)
{
	//库函数
	reverse(s.begin(), s.end());
}
//类封装--下标
class Solution
{
public:
	string ReverseString3(string& s)
	{
		size_t begin = 0;
		size_t end = s.size() - 1;
		while (begin < end)
		{
			swap(s[begin], s[end]);
			begin++;
			end--;
		}
		return s;
	}
};
void Test7()
{
	string s("programing every day");
	//ReverseString1(s);
	//ReverseString2(s);

	Solution s1;
	cout << s1.ReverseString3(s) << endl;

	//cout << s << endl;
}

//7.2找字符串中第一个只出现一次的字符
class Way
{
public:
	char FindFirUp(string& s)
	{
		//先统计每个数字出现的次数
		int count[256] = { 0 };

		/*for (int i = 0; i < s.size(); i++)
		{
			count[s[i]]++;
		}*/
		for (auto e : s)
		{
			count[e]++;
		}

		//再找出第一个出现次数为1 的字符
		for (int i = 0; i < s.size(); i++)
		{
			if (1 == count[s[i]])
			{
				return s[i];
			}
		}
		return -1;
	}
};
void Test8()
{
	string s("apple");
	Way w;
	cout << w.FindFirUp(s) << endl;
}

//7.3 求字符串里面最后一个单词的长度
void Test9()
{
	string s;
	getline(cin, s);// 不能使用cin>>line,因为会它遇到空格就结束了
	size_t pos = s.rfind(' ');
	cout << s.size() - pos - 1 << endl;

}
//7.4 两个字符串相加
class Method
{
public:
	string Add(string s1, string s2)
	{
		size_t str1 = s1.size() - 1;
		size_t str2 = s2.size() - 1;
		int value1, value2, next = 0;
		int valuest = 0;
		string result;
		while (str1 >= 0 || str2 >= 0) 
		{
			if (str1 >= 0)
			{
				value1 = s1[str1] - '0';
				str1--;
			}
			else
			{
				value1 = 0;
			}
			if (str2 >= 0)
			{
				value2 = s2[str2] - '0';
				str2--;
			}
			else
			{
				value2 = 0;
			}
			valuest = value1 + value2 + next;
			if (valuest > 9)
			{
				next = 1;
				valuest -= 10;
			}
			else
			{
				next = 0;
			}
			result += (valuest + '0');	
		}
		if (next == 1)
		{
			result += '1';
		}
		reverse(result.begin(), result.end());
		return result;
	}

};
void Test10()
{
	string s1("1234");
	string s2("234");
	string s3("9999");

	Method m;
	cout << "s1+s2:" << m.Add(s1, s2) << endl;
	//cout << "s1+s3:" << m.Add(s1, s3) << endl;
	//cout << "s2+s3:" << m.Add(s2, s3) << endl;

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
	Test6();
	Test7();
	Test8();
	//Test9();
	Test10();

	system("pause");
	return 0;
}