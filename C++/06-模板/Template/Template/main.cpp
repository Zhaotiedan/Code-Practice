#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//1.模板格式
template<class T>
void Swap(T& left, T& right)
{
	T temp = left;
	left = right;
	right = temp;
}

template<class T>
T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
}

//2.函数模板的初始化
// 2.1隐式实例化：让编译器根据实参推演模板参数的实际类型
void Test1()
{
	Add(1, 2);//int, int--T==>int 生成intAdd函数--->Add<int>
	Add(1.0, 2.0);//double, double--> T==>double 生成double Add函数--->Add<double>
	Add('1', '2');//char char-->T==char 生成char Add函数--->Add<char>
	//Add(1.0, 2);报错，无法推演实参类型

	//此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化
	Add((int)1.0, 2);
}
//2.2 显式实例化：在函数名后的<>中指定模板参数的实际类型
void Test2()
{
	Add<int>(1.0, 2);
}
int main()
{
	int a = 10, b = 20;
	swap(a, b);
	cout << a << b << endl;

	Add(a, b);

	Test1();

	Test2();
	system("pause");
	return 0;
}