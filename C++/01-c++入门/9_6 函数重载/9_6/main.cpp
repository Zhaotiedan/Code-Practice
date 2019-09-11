#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


//函数重载:同一作用域，同名函数，形参列表（参数个数，类型，顺序）不同
int Add(int left, int right)
{
	return left + right;
}
double Add(double left, double right)
{
	return left + right;
}
long Add(long left, long right)
{
	return left + right;
}
//2.函数仅仅返回值类型不同，不构成重载
/*void Test(int a)
{

}
int Test(int a)
{
	return a;
}*/
//3.同名的无参函数和全缺省函数不要同时出现
/*void Test()
{

}
void Test(int a = 10)
{

}
*/
//4.缺省函数和正常函数 也不能构成重载
/*void Test(int a)
{
}
void Test(int a = 10)
{

}*/



int main()
{
	cout << Add(10, 20) << endl;
	cout << Add(10.0, 20.0) << endl;
	cout << Add(10L, 20L) << endl;
	//1.Add(10,20.0);报错，隐式类型转换，转换成int，int或者double，double，不知道调用哪个函数
	system("pause");
	return 0;
}

//一些题目：
/*
1.C语言为什么不支持函数重载？   
     编译过程中，C会直接在每一个函数名前加_，会导致冲突
2.C++中函数重载底层是怎样处理的？  
     C++会引入函数的类型，修饰后的名字由函数名字和函数类型组成，也就是说，名字相同的情况下
	 只要参数列表不同，则编译时修饰的结果也不同，可以保证名字在底层的全局唯一性
3.C++中能否将一个函数按照C风格来写？
     一：将源文件格式改成.c    二：在函数前面+extern "C"
*/