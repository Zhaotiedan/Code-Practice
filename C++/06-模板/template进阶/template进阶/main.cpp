#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<string.h>
#include<string>

//1.非类型模板参数
namespace Template
{
	template<class T,size_t N>
	class array
	{
	public:
		array()
		{
			for (size_t i = 0; i < N; ++i)
				_array[i] = 0;
			_size = 0;
		}
		T& operator[](size_t index)
		{
			return _array[index];
		}
		const T& operator[](size_t index)const
		{
			return _array[index];
		}
		void push_back(const T& data)
		{
			/*++_size;
			_array[_size] = data;*/
			_array[_size++] = data;
		}
		size_t size()const
		{
			return _size;
		}
		bool empty()const
		{
			return 0 == _size;
		}

	private:
		T _array[N];
		size_t _size;
	};
}

void Test1()
{
	int a = 10;
	int b = 20;

	//Template::array<int, a+b> arr; 报错，非类型模板参数必须在编译其确认其结果，不能为变量只能为常量。

	Template::array<int, 30> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);

	for (size_t i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//2.模板的特化   
//2.1 函数模板特化
//必须要有一个基础的函数模板
template<class T>
bool IsEqual(T& left, T& right)
{
	return left == right;
}
template<>//template后面加<>
bool IsEqual<char*>(char*& left, char*& right)//函数名后面需要跟需特化的类型，且参数列表与模板参数相同
{
	if (strcmp(left, right) > 0)
	{
		return true;
	}
	return false;
}

class Date
{
public:
	Date(int year,int month,int day)
		:_year(year)
		,_month(month)
		,_day(day)
	{}
	friend ostream& operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day << endl;
		return _cout;
	}
	bool operator>(const Date& d)
	{
		return _day > d._day;
	}
private:
	int _year;
	int _month;
	int _day;
};
void Test2()
{
	//比数字
	int a = 10;
	int b = 20;
	cout <<"数字"<< IsEqual(a, b) << endl;
	//cout << IsEqual(10,20) << endl; 报错

	//比字符串
	const char* p1 = "hello";
	const char* p2 = "worldddd";
	cout <<"字符串"<< IsEqual(p1, p2) << endl;

	//比对象
	/*Date d1(2019, 10, 27);
	Date d2(2019, 10, 28);
	cout <<"对象"<< IsEqual(d1, d2) << endl;*/  //报错
}

//2.2 类模板特化
//2.2.1.全特化:是将模板参数类表中所有的参数都确定化。
template<class T1,class T2>
class Data
{
public:
	Data()
	{
		cout << "Date<T1,T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};

template<>
class Data<int, char>
{
public:
	Data()
	{
		cout << "Date<int,char>" << endl;
	}
private:
	int _d1;
	char _d2;
};
//2.2.2.偏特化 :部分特化--->将模板参数列表中部分参数类型化
template <class T1>
class Data<T1,double>
{
public:
	Data()
	{
		cout << "Data<T1,int>" << endl;
	}
private:
	T1 _d1;
	double _d2;
};
//2.2.2 偏特化：参数更进一步的限制
// 2.2.2. 1.两个参数偏特化为指针类型
template <class T1, class T2>
class Data<T1*,T2*>
{
public:
	Data()
	{
		cout << "Data<T1*,T2*>" << endl;
	}
private:
	T1* _d1;
	T2* _d2;
};
// 2.2.2.2.两个参数偏特化为引用类型   为什么这个的构造函数要这样写？
template<class T1, class T2>
class Data<T1&,T2&>
{
public:
	Data(const T1& d1,const T2& d2)
		:_d1(d1)
		,_d2(d2)
	{
		cout << "Data<T1&,T2&>" << endl;

	}
private:
	const T1& _d1;
	const T2& _d2;
};
void Test3()
{
	//全特化
	Data<int, int>d1;
	Data<int, char>d2;

	//偏特化
	Data<double, double>d3;

	Data<int*, int*>d4;
	Data<int&, int&>d5(1,2);
}

//3.类模板特化应用之类型萃取
//问题：如何实现一个通用的拷贝函数？要求效率尽可能高
//方法一：使用memcpy
template<class T>
void Copy1(T* des, const T* sour, size_t size)
{
	memcpy(des, sour, sizeof(T)*size);
}
void Test4()
{
	string s1[3] = { "hello","world","!" };//定义了一个string类型的指针，里面放三个string类型变量，一个为hello，一个为world，一个为！
	string s2[3];
	Copy1(s2, s1, 3);

	/*cout << *s1 << endl;
	cout << *s2 << endl;*/
	//崩溃：拷贝自定义类型对象就可能会出错，因为自定义类型对象有可能会涉及到深拷贝(比如string)，
	//而memcpy属于浅拷贝。如果对象中涉及到资源管理，就只能用赋值。
}
//方法二：使用赋值方式拷贝
template<class T>
void Copy2(T* des, const T* sour, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		des[i] = sour[i];
	}
}
void Test5()
{
	string s1[3] = { "change","world","!" };
	string s2[3];
	Copy2(s2, s1, 3);
	cout << s1 << endl;
	cout << s2 << endl;//使用深拷贝后，两个指针地址才会不一样
	cout << *s1 << endl;
	cout << *s2 << endl;//打印*s1,即打印它首元素的地址

}

/*循环赋值的方式虽然可以，但是代码的效率比较低，而C/C++程序最大的优势就是效率高。那能否将另种
方式的优势结合起来呢？遇到内置类型就用memcpy来拷贝，遇到自定义类型就用循环赋值方式来做呢？*/


//方法三 增加bool类型区分自定义与内置类型
template<class T>
void Copy3(T* des, const T* sour, size_t size, bool IsPODType)
{
	if (IsPODType)// plain old data内置类型
	{
		memcpy(des, sour, sizeof(T)*size);
	}
	else
	{
		for (size_t i = 0; i < size; i++)
		{
			des[i] = sour[i];
		}
	}
}
void Test6()
{
	/*const char* arr1 = "I like";
	char* arr2 = nullptr;*/  //这个为什么不可以？
	const char arr1[2] = { 'a','b' };
	char arr2[2];
	Copy3(arr2, arr1, 1, true);
	string s1[3] = { "practice","code","everday" };
	string s2[3];
	Copy3(s1, s2, 3, false);
	
}
/*通过多增加一个参数，就可将两种拷贝的优势体现结合起来。但缺陷是：用户需要根据所拷贝元素的类型去
传递第三个参数，那出错的可能性就增加。那能否让函数自动去识别所拷贝类型是内置类型或者自定义类型
呢？*/

//方法四：使用函数区分内置于自定义类型
/*因为内置类型的个数是确定的，可以将所有内置类型集合在一起，如果能够将所拷贝对象的类型确定下来，
在内置类型集合中查找其是否存在即可确定所拷贝类型是否为内置类型*/

/*通过typeid来确认所拷贝对象的实际类型，然后再在内置类型集合中枚举其是否出现过，既可确认所拷贝元
素的类型为内置类型或者自定义类型。但缺陷是：枚举需要将所有类型遍历一遍，每次比较都是字符串的比
较，效率比较低。*/
bool IsPODType(const char* type)
{
	const char* arrtype[] = { "int","char","short","long","long long","float","double","long double" };
	int length = sizeof(arrtype) / sizeof(arrtype[0]);
	for (size_t i = 0; i < length; i++)
	{
		if (strcmp(type, arrtype[i]) == 0)
		{
			return true;
		}
	}
	return false;
}
template<class T>
void Copy4(T* des, const T* sour, size_t size)
{
	if (IsPODType(typeid(T).name()))
	{
		memcpy(des, sour, sizeof(T)*size);
	}
	else
	{
		for (size_t i = 0; i < size; i++)
		{
			des[i] = sour[i];
		}
	}
}
void Test7()
{
	/*const char arr1[2] = { 'a','b' };
	char arr2[2];
	Copy4(arr2, arr1, 2);*/
	int array1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int array2[10];
	Copy4(array2, array1, 10);
	cout << *array1 << endl;
	cout << *array2 << endl;
	char arr1[2] = { 'a','b' };
	char arr2[2];
	Copy4(arr2, arr1, 2);
	cout << arr1 << endl;
	cout << arr2 << endl;
	cout << *arr1 << endl;
	cout << *arr2 << endl;

	string s1[3] = { "practice","code","everday" };
	string s2[3];
	Copy4(s2, s1, 3);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << *s1 << endl;
	cout << *s2 << endl;
}

//方法5：最优方法：类型萃取

//两个类分别代表内置类型与自定义类型。

//内置
struct Truetype
{
	static bool Get()
	{
		return true;
	}
};
//自定义
struct Falsetype
{
	static bool Get()
	{
		return false;
	}
};
//模板类     可以按照任意类型实例化该类模板
template<class T>
struct typetrails
{
	typedef Falsetype IsPODType;
};
//对类模板进行实例化
template<>
struct typetrails<char>
{
	typedef Truetype IsPODType;
};
template<>
struct typetrails<int>
{
	typedef Truetype IsPODType;
};
template<>
struct typetrails<short>
{
	typedef Truetype IsPODType;
};
template<>
struct typetrails<long>
{
	typedef Truetype IsPODType;
};
//通过对TypeTraits类模板重写改写方式四中的Copy函数模板，来确认所拷贝对象的实际类型。

/*
T为int：TypeTraits<int>已经特化过，程序运行时就会使用已经特化过的TypeTraits<int>, 该类中的
IsPODType刚好为类TrueType，而TrueType中Get函数返回true，内置类型使用memcpy方式拷贝
T为string：TypeTraits<string>没有特化过，程序运行时使用TypeTraits类模板, 该类模板中的IsPODType
刚好为类FalseType，而FalseType中Get函数返回true，自定义类型使用赋值方式拷贝
*/
template<class T>
void Copy5(T* des, const T* sour, size_t size)
{
	if (typetrails<T>::IsPODType::Get())
		//调用__IsPODType.Get() 时编译器会根据TypeTraits<class T> T 的实际类型调用 	
//__FalseType	 或 Truetype 的 Get()函数  得到不同 bool值			
	{
		memcpy(des, sour, sizeof(T)*size);
	}
	else
	{
		for (size_t i = 0; i < size; i++)
		{
			des[i] = sour[i];
		}
	}
}
void Test8()
{
	int a1[] = { 1,2,3,4,5,6,7,8,9,0 };
	int a2[10];
	Copy5(a2, a1, 10);
	cout << *a1 << endl;
	cout << *a2 << endl;
	string s1[] = { "1111", "2222", "3333", "4444" };
	string s2[4];
	Copy5(s2, s1, 4);
	cout << *s1 << endl;
	cout << *s2 << endl;
}

//4.模板分离编译
// 使用文件IO流用文本及二进制方式演示读写配置文件
struct ServerInfo
{
	char _ip[32]; // ip
	int _port; // 端口
};

//#include <fstream>
//
//struct ConfigManager
//{
//public:
//	ConfigManager(const char* configfile = "bitserver.config")
//		:_configfile(configfile)
//	{}
//
//	void WriteBin(const ServerInfo& info)
//	{
//		// 这里注意使用二进制方式打开写
//		ofstream ofs(_configfile, ifstream::out | ifstream::binary);
//		ofs.write((const char*)&info, sizeof(ServerInfo));
//		ofs.close();
//	}
//
//	void ReadBin(ServerInfo& info)
//	{
//		// 这里注意使用二进制方式打开读
//		ifstream ifs(_configfile, ifstream::in | ifstream::binary);
//		ifs.read((char*)&info, sizeof(ServerInfo));
//		ifs.close();
//	}
//
//	void WriteText(const ServerInfo& info)
//	{
//		// 这里会发现IO流写整形比C语言那套就简单多了，
//		// C 语言得先把整形itoa再写
//		ofstream ofs(_configfile);
//		ofs << info._ip << endl;
//		ofs << info._port << endl;
//		ofs.close();
//	}
//
//	void ReadText(ServerInfo& info)
//	{
//		// 这里会发现IO流读整形比C语言那套就简单多了，
//		// C 语言得先读字符串，再atoi
//		ifstream ifs(_configfile);
//		ifs >> info._ip;
//		ifs >> info._port;
//		ifs.close();
//	}
//
//private:
//	string _configfile; // 配置文件
//};

void Test9()
{
	ConfigManager cfgMgr;
	ServerInfo wtinfo;
	ServerInfo rdinfo;
	strcpy(wtinfo._ip, "127.0.0.1");
	wtinfo._port = 80;
	// 二进制读写
	cfgMgr.WriteBin(wtinfo);
	cfgMgr.ReadBin(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;
	// 文本读写
	cfgMgr.WriteText(wtinfo);
	cfgMgr.ReadText(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;
	return 0;
}
int main()
{
	Test1();
	Test2();
	Test3();
	//Test4();
	Test5();
	Test6();
	Test7();
	Test8();

	system("pause");
	return 0;
}