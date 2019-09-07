#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//1.引用类型的定义
void Test1()
{
	int a = 10;
	int& ra = a;//定义引用类型，必须和引用实体a一个类型
	cout << &a << endl;
	cout << &ra << endl;
}
//2.引用特性
void Test2()
{
	int a = 10;
	//int &ra;报错，引用定义时必须要初始化
	int& ra = a;
	int& rra = a;//一个变量可以有多个引用
	cout << &ra << endl;
	cout << &rra << endl;
	//引用一旦引用一个实体，就不能再引用其他实体，下面这个ra不是引用了b，而是对ra赋值，a的值也会被改变
	int b = 20;
	ra = 20;
	cout << a << endl;
}
//3.常引用
void Test3()
{
	const int a = 10;//a为常量
	//int& ra = a;报错
	const int& ra = a;

	cout << ra << endl;
	double b = 12.34;
	const double& rb1 = b;
	const int& rb2 = b;
	//rb2引用的是个整型空间，这个空间只接收了b的整数部分，且空间没有名字和地址，具有常性，所以要加const引用
	cout << rb1 << endl;
	cout << rb2 << endl;

}
//4.引用场景
//做参数：
//想通过形参改变外部实参时，形参类型我普通类型引用。不想改变时，形参类型为const类型引用
void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}
//做返回值
int& Test4(int& a)
{
	a += 10;
	return a;
}
int main()
{
	Test1();
	cout << endl;
	Test2();
	cout << endl;
	Test3();
	cout << endl;
	int a=10;
	int&ra = a;
	cout<<Test4(ra)<<endl;
	system("pause");
	return 0;
}