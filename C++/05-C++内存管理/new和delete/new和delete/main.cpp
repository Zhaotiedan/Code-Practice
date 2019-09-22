#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

// 1.new/delete操作内置类型
//申请和释放单个内存，用new和delete操作符，申请和释放连续的空间，用new[]和delete[]操作符
void Test1()
{
	int* p1 = new int;//动态申请1个int类型的空间
	int* p2 = new int(10);//动态申请1个int类型的空间,并初始化为10
	int* p3 = new int[10];//动态申请10个int类型的空间(类型为int[10])
	int* p4 = new int[10]{ 1,2,3,4,5,6,7,8,9,0 };//动态申请10个int类型的空间。并初始化为{1~0}

	delete p1;
	delete p2;
	delete[] p3;
	delete[] p4;
}
// 2.如果new和delete没有匹配使用，产生后果?
//结论：如果申请的是内置类型的空间，不会产生任何后果
void Test2()
{
	int* p1 = new int;
	int* p2 = new int[10];
	int* p3 = new int[10];
	delete[] p1;
	delete p2;
	free(p3);

	//...
}

//3.new/delete操作自定义类型
//new会调用构造函数 delete会调用析构函数，清理对象中的资源，而malloc和free不会
class Test
{
public:
	Test()
		:_data(10)
		,_p(new int)
	{
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		delete _p;
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
	int* _p;
};
void Test3()
{
	Test* p1 = new Test;//申请单个Test类型的对象
	delete p1;
	cout << endl;
	Test* p2 = new Test[10];//申请10个Test类型的对象
	delete[] p2;

	Test* p3 = (Test*)malloc(sizeof(Test)); //申请单个Test类型的空间
	//malloc申请空间时不会调用构造函数--申请的是与对象大小相同的一块内存空间，不能将该块内存空间看成一个对象
	free(p3);
	Test* p4 = (Test*)malloc(sizeof(Test) * 10);//申请10个Test类型的空间
	free(p4);
}

//4.如果new和delete没有匹配使用，产生后果?
//只要涉及到[]，必然会崩溃
void Test4()
{
	Test* p1 = new Test;
	free(p1);//不报错

	Test* p2 = new Test[10];
	delete p2;//报错

	Test* p3 = new Test;
	delete[] p3;//报错 崩溃
}

//5. new--->能够将申请空间的信息打印 delete--->能够将释放空间信息打印
void* operator new(size_t size, const char* filename, const char* funName, size_t lineNo)
{
	cout << filename << "-" << funName << "-" << lineNo << "-" << size << endl;
	return malloc(size);
}

void operator delete(void* p, const char* filename, const char* funName, size_t lineNo)
{
	cout << filename << "-" << funName << "-" << lineNo << endl;
	free(p);
}

#define new new(__FILE__, __FUNCDNAME__, __LINE__)
void Test5()
{
	int* p = new int;
	delete p;
}


int main()
{
	Test1();
	Test2();
	Test3();
	//Test4();
	Test5();

	system("pause");
	return 0;
}