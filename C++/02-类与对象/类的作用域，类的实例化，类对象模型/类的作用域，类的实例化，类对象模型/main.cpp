#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//1.类的作用域：类中所有成员都在这个类的作用域中，在类外定义成员需要使用::作用域解析该成员属于哪个类域
//问题一：为什么定义了一个类就是新定义了一个作用域？证明？
//因为需要使用::作用域解析符

//问题2：为什么在类中可以先使用变量后定义？
//1.类中是通过this访问成员，就算后定义，也可以通过this指针找到对应的变量
//2.编译器处理类的过程
class Student
{
public:
	void PrintStudentInfo();
private:
	char _name[20];
	char _gender[3];
	int _age;
};
void Student::PrintStudentInfo()
{
	cout << _name << " " << _gender << " " << _age << endl;
}
//2.类的实例化：就是用类型创造对象的过程
//定义一个类没有分配实际的内存空间，而实例化出来的对象才占用实际的物理空间，存储成员变量
//比如上代码定义一个Student类，下面用Student s定义了一个对象s，就是实例化


//3.类对象模型
//计算类的大小：就是该类中成员变量之和，内存对齐
//实例：
class A2
{
public:
	void f1();
private:
	int _a;
};
class A3
{
public:
	void f2();
};
class A4
{

};
int main()
{
	Student s;
	s.PrintStudentInfo();
	cout << sizeof(A2) << endl;//4
	cout << sizeof(A3) << endl;//1
	cout << sizeof(A4) << endl;//1  注意空类的大小，比较特殊，在vs等主流编译器下面，会给空类一个字节来唯一标识这个类

	system("pause");
	return 0;
}
