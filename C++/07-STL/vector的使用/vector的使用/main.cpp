#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;


//1.构造函数
void Test1()
{
	//无参构造
	vector<int> first;
	//构造并初始化n个值
	vector<int> second(4, 100);
	//拷贝构造
	vector<int> third(second);
	//迭代器初始化构造
	vector<int> fourth(second.begin(), second.end());
}
int main()
{
	Test1();
	system("pause");
	return 0;
}