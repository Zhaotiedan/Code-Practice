#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;


// 设计一个类不能被继承
// C++98

//方法：构造函数私有化，派生类调不到基类的构造函数，就无法继承
class Base1
{
	//要在类外定义对象，但是因为基类构造函数访问权限是private，所以定义一个内部成员来访问基类私有的构造函数
public:
	//要在类外定义对象使用此方法前必须要有一个Base1类型的对象，所以在该方法前加一个static
	static Base1 GetObject(int b)
	{
		return Base1(b);
	}
private:
	Base1(int b)
		:_b(b)
	{}
//protected:
public:
	int _b;
};
void Test1()
{
	//要在类外定义对象
	Base1 b(Base1::GetObject(10));
	cout << b._b << endl;
}
//c++11
// final如果修饰一个类：表示该类不能被继承
class Base final
{
public:
	Base(int b)
		: _b(b)
	{}

protected:
	int _b;
};

/*5.继承与友元*/
//友元关系不能继承，也就是说基类友元不能访问子类私有和保护成员
class Base2
{
	friend void Test2();
public:
	Base2(int b)
		:_b(b)
	{}
	int GetB()
	{
		return _b;
	}
protected:
	int _b;
};
class Derived2 : public Base2
{
public:
	Derived2(int b, int d)
		: Base2(b)
		, _d(d)
	{}

protected:
	int _d;
};

//void Test2()//看基类友元函数不能访问子类私有和保护成员
//{
//	Base2 b(10);
//	cout << b.GetB() << endl;
//	cout << b._b << endl;
//
//	Derived2 d(10, 20);
//	cout << d._d << endl;//崩溃  不能访问
//}



/*6.继承与静态成员*/
// 统计一个类创建了多少个对象
class Person
{
public:
	Person() { ++_count; }
protected:
	string _name; // 姓名
public:
	static int _count; // 统计人的个数。
};
int Person::_count = 0;
class Student : public Person
{
protected:
	int _stuNum; // 学号
};
class Graduate : public Student
{
protected:
	string _seminarCourse; // 研究科目
};
void TestPerson()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << " 人数 :" << Person::_count << endl;
	Student::_count = 0;
	cout << " 人数 :" << Person::_count << endl;
}

//	结论：
//	 1. 基类中静态成员变量可以被子类继承
//	 2. 在整个继承体系中，静态成员变量只有一份

/*8.复杂的菱形继承及菱形虚拟继承*/

//多重继承
#if 0
class B1
{
public:
	int _b1;
};

class B2
{
public:
	int _b2;
};

// 注意：每个基类前必须给出继承权限，否则就是默认的继承权限
class D : public B2, public B1
{
public:
	int _d;
};


void Test3()
{
	cout << sizeof(D) << endl;

	D d;
	d._b1 = 1;
	d._b2 = 2;
	d._d = 3;
}
#endif


class B
{
public:
	int _b;
};

class C1 : public B
{
public:
	int _c1;
};

class C2 : public B
{
public:
	int _c2;
};

class D : public C1, public C2
{
public:
	int _d;
};

void Test4()
{
	cout << sizeof(D) << endl;//20

	D d;
	//d._b = 1;  // 菱形继承缺陷：会存在二义性问题

    //解决方式一：通过作用域访问
	d.C1::_b = 1;
	d._c1 = 2;

	d.C2::_b = 3;
	d._c2 = 4;

	d._d = 5;
}

//解决方式二： 菱形虚拟继承
//class B
//{
//public:
//	int _b;
//};
//
//class C1 : virtual public B
//{
//public:
//	int _c1;
//};
//
//class C2 : virtual public B
//{
//public:
//	int _c2;
//};
//
//class D : public C1, public C2
//{
//public:
//	int _d;
//};
//
//void Test5()
//{
//	cout << sizeof(D) << endl;
//	D d;
//	
//}

int main()
{
	Test1();
	//Test2();
	TestPerson();
	//Test3();
	Test4();
	//Test5();

	system("pause");
	return 0;
}