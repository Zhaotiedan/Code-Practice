#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

#include<string>

/*1.多态的概念*/
//去完成某个行为，当不同的对象去完成时会产生出不同的形态
//通过继承同一个基类，产生了相关的不同的派生类，与基类中同名的成员函数在不同的派生类中会有不同的实现，也就是说：一个接口、多种方法。

/*2.多态的引入*/

//三种不同情况的卖票，一个卖票方法，对应不同人群的不同应对方式

//普通人
class Person
{
public:
	Person(const string& name, const string& gender, int age)
		:_name(name)
		,_gender(gender)
		,_age(age)
	{}
	virtual void BuyTicket()//virtual的加入
	{
		cout << "全价票" << endl;
	}
protected:
	string _name;
	string _gender;
	int _age;
};

//学生
class Student :public Person
{
public:
	Student(const string& name, const string& gender, int age, int number)
		:Person(name,gender,age)
		,_number(number)
	{}
	virtual void BuyTicket()//virtual的加入,派生类不+virtual关键字时，也可以构成重写成功，但写法不规范
	{
		cout << "半价票" << endl;
	}
private:
	int _number;//学号
};

//军人
class Soilder :public Person
{
public:
	Soilder(const string& name,const string& gender,int age,const string& hornor)
		:Person(name, gender, age)
		,_hornor(hornor)
	{}
	virtual void BuyTicket()//virtual的加入
	{
		cout << "免费票" << endl;
	}
private:
	string _hornor;
};

void TestBuyTicket(Person& p)
{
	p.BuyTicket();
}

//解决方法一：定义三个面向不同人群时使用的不同方法，但太复杂，所以引入了多态
/*
void TestBuyTicket(Person& p)
{
	p.BuyTicket();
}

void TestBuyTicket(Student& p)
{
	p.BuyTicket();
}

void TestBuyTicket(Soilder& p)
{
	p.BuyTicket();
}
*/
void Test1()
{
	Person p("白领", "男", 36);
	Student st("武亦姝", "女", 17, 001);
	Soilder so("战狼", "男", 30, "一等功");

	/*p.BuyTicket();
	st.BuyTicket();
	so.BuyTicket();   直接调，可以实现，但没有意义，不存在一个接口的概念*/

	TestBuyTicket(p);
	TestBuyTicket(st);
	TestBuyTicket(so);
}

#if 0
/*3.函数重写的两个例外*/

//1.协变：基类中虚函数返回基类的引用(指针)，派生类中虚函数返回派生类的引用(指针)  注意，只要是返回基类所返回的基类类型就可以
class A
{};
class B :public A
{};

class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}

	virtual void TestFunc2(int)//参数列表
	{
		cout << "Base::TestFunc2()" << endl;
	}

	void TestFunc3()//无virtual
	{
		cout << "Base::TestFunc3()" << endl;
	}

	virtual void TestFunc4()
	{
		cout << "Base::TestFunc4()" << endl;
	}

	virtual Base* TestFunc5()
	{
		cout << "Base::TestFunc5()" << endl;
		return this;
	}

	//返回的是A 基类 类型
	virtual A& TestFunc6(A& a)
	{
		cout << "Base::TestFunc6()" << endl;
		return a;
	}
};

class Derived : public Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Derived::TestFunc1()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "Derived::TestFunc2()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "Derived::TestFunc3()" << endl;
	}

	void TestFunc4()
	{
		cout << "Derived::TestFunc4()" << endl;
	}

	virtual Derived* TestFunc5()
	{
		cout << "Derived::TestFunc5()" << endl;
		return this;
	}

	virtual B& TestFunc6(A& a)
	{
		cout << "Derived::TestFunc6()" << endl;
		return *(new B);
	}
};

void TestVirtualFunc(Base* pb)
{
	pb->TestFunc1();
	pb->TestFunc2(10);//参数列表都不同
	pb->TestFunc3();//无virtual
	pb->TestFunc4();
	pb->TestFunc5();

	A a;
	pb->TestFunc6(a);
}

void Test2()
{
	Base b;
	Derived d;

	TestVirtualFunc(&b);
	TestVirtualFunc(&d);
}

#endif


//4..析构函数重写:如果基类的析构函数为虚函数，此时派生类析构函数只要定义，无论是否加virtual关键字，
//都与基类的析构函数构成重写
class Base
{
public:
	Base(int b)
		:_b(b)
	{
		cout << "Base::Base()" << endl;
	}
	virtual ~Base()
	{
		cout << "Base::~Base()" << endl;
	}
protected:
	int _b;
};
class Derived : public Base
{
public:
	Derived(int b)
		: Base(b)
		, _p(new int[10])
	{
		cout << "Derived::Derived(int)" << endl;
	}

	~Derived()
	{
		delete[] _p;
		cout << "Derived::~Derived()" << endl;
	}

protected:
	int* _p;
};
//只有派生类Derived的析构函数重写了Base的析构函数，下面的delete对象调用析构函数，
//才能构成多态，才能保证pb1和pb2指向的对象正确的调用析构函数。
void TestDestroy()
{
	Base* pb1 = new Base(10);
	Base* pb2 = new Derived(10);

	delete pb1;
	delete pb2;

}

/*5. C++11 override 和 final*/
//1. final：修饰虚函数，表示该虚函数不能再被继承
class Base1
{
public:
	virtual void TestBase1()
	{
		cout << "TestBase1()" << endl;
	}

	int _b;
};
class Derived2 :public Base1
{
public:
	virtual void TestBase1()
	{
		cout << "Base1::TestBase1()" << endl;
	}

};

int main()
{
	Test1();
	//Test2();
	TestDestroy();

	system("pause");
	return 0;
}