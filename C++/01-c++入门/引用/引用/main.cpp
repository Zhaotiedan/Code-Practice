#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<time.h>
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
//做返回值:但是不能返回栈上的空间
int& Test4(int& a)
{
	a += 10;
	return a;
}

//5.传值，传址，传引用的效率比较
struct A
{
	int a[1000];
};
void Test5(A a)
{}
void Test6(A& a)
{}
void Test7(A* a)
{}
void Test8()
{
	A a = { 1,23,10 };
	//传值：
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; i++)
	{
		Test5(a);
	}
	size_t end1 = clock();
	//传引用：
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; i++)
	{
		Test6(a);
	}
	size_t end2 = clock();
	//传址：
	size_t begin3 = clock();
	for (size_t i = 0; i < 10000; i++)
	{
		Test7(&a);
	}
	size_t end3 = clock();
	cout << "Test5:" << end1 - begin1 << endl;
	cout << "Test6:" << end2 - begin2 << endl;
	cout << "Test7:" << end3 - begin3 << endl;


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
	cout<<Test4(a)<<endl;
	for (int i = 0; i < 10; i++)
	{
		Test8();
	}
	//6.引用和指针的相同与不同：
	//相同：
	int &ra = a;
	ra = 20;
	int *pa = &a;
	*pa = 20;
	cout << a << endl;//引用和指针都可以改变a的值
	//不同：
	//一。在sizeof中含义不同，指针大小（32位平台）始终为4个字节。其他不同点见教材
	char c = 'c';
	char *pc = &c;
	char& rc = c;
	cout << sizeof(pc) << endl;
	cout << sizeof(rc) << endl;
	system("pause");
	return 0;
}