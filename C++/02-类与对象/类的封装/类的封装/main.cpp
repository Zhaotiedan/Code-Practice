#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//封装概念：结合数据和操作方法，隐藏一个对象的内部属性和实现细节，通过提供的公有接口来和对象之间进行交互
//封装方法：类+访问权限

//访问权限：private  protected  public
// public: 被public修饰的成员，可以直接在类外被访问
// protected/private: 不能直接在类外进行访问

//问题一：c++中struct和class的区别是什么？
//c++中struct既可以定义结构体，还可以定义类。但struct默认访问成员方式为public，class默认访问成员方式为private

//问题二:面向对象的三大特性？
//封装，继承，多态

int main()
{

	system("pause");
	return 0;
}