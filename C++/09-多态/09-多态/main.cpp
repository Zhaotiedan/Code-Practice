#define _CRT_SECURE_NO_WARNINGS 1


//https://blog.csdn.net/qq_42913794/article/details/103040839  ---多态总结(上)
//https://blog.csdn.net/qq_42913794/article/details/103793230  ---多态总结(下)
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


/*3.函数重写的两个例外*/

//1.协变：基类中虚函数返回基类的引用(指针)，派生类中虚函数返回派生类的引用(指针)  
//注意，只要是返回基类所返回的基类类型就可以
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




//4..析构函数重写:如果基类的析构函数为虚函数，此时派生类析构函数只要定义，无论是否加virtual关键字，
//都与基类的析构函数构成重写
class Base1
{
public:
	Base1(int b)
		:_b(b)
	{
		cout << "Base1::Base1()" << endl;
	}
	virtual ~Base1()
	{
		cout << "Base1::~Base1()" << endl;
	}
protected:
	int _b;
};
class Derived1 : public Base1
{
public:
	Derived1(int b)
		: Base1(b)
		, _p(new int[10])
	{
		cout << "Derived1::Derived1(int)" << endl;
	}

	~Derived1()
	{
		delete[] _p;
		cout << "Derived1::~Derived1()" << endl;
	}

protected:
	int* _p;
};
//只有派生类Derived的析构函数重写了Base的析构函数，下面的delete对象调用析构函数，
//才能构成多态，才能保证pb1和pb2指向的对象正确的调用析构函数。
void TestDestroy()
{
	Base1* pb1 = new Base1(10);
	Base1* pb2 = new Derived1(10);

	delete pb1;
	delete pb2;

}

/*5. C++11 override 和 final*/
//1. final：修饰虚函数，表示该虚函数不能再被继承
//注意，C++98里不可使用
#if 0
class Base2
{
public:
	virtual void TestBase1()final
	{
		cout << "Base2::TestBase1()" << endl;
	}

	int _b;
};
class Derived2 :public Base2
{
public:
	virtual void TestBase1()
	{
		cout << "Derived2::TestBase1()" << endl;
	}

};
#endif

//2. override: 修饰派生类虚函数
//检测该虚函数是否重写了基类某个虚函数，如果没有重写编译报错
class Base2
{
public:
	virtual void TestBase1()
	{
		cout << "Base2::TestBase1()" << endl;
	}

	int _b;
};
class Derived2 :public Base2
{
public:
	virtual void TestBase1()override
	{}
};
void TestOverVirtualFun(Base2* pb)
{
	pb->TestBase1();
}
void Test3()
{
	Base2 b;
	b.TestBase1();
	Derived2 d;
	d.TestBase1();
	TestOverVirtualFun(&b);
	TestOverVirtualFun(&d);
}

/*6.抽象类*/
//在虚函数的后面写上 = 0 ，则这个函数为纯虚函数。
//包含纯虚函数的类叫做抽象类（也叫接口类），抽象类不能定义对象，但可以定义指针(引用)
//派生类继承后也不能实例化出对象，只有重写纯虚函数，派生类才能实例化出对象。
//纯虚函数规范了派生类必须重写，另外纯虚函数更体现接口继承
class Place
{
	virtual void Describe() = 0;
};

class BeiJing :public Place
{
public:
	void Describe()
	{
		cout << "TianAnMen" << endl;
	}
};

class ShangHai :public Place
{
public:
	void Describe()
	{
		cout << "DongFangMIingZhu" << endl;
	}
};

void Test4()
{
	BeiJing bei;
	bei.Describe();
	BeiJing* pbei = new BeiJing;
	pbei->Describe();

	/*Place* ppbei = new BeiJing;
	ppbei->Describe();  报错*/

	ShangHai sh;
	sh.Describe();
	ShangHai* psh = new ShangHai;
	psh->Describe();

	/*Place* ppsh = new ShangHai;
	ppsh->Describe(); 报错*/
}

/*7.多态的原理*/

/*7.1基类和派生类虚函数表的构建过程*/

//1.看包含虚函数的类的大小是多少
class Base3
{
public:
	virtual void Test1()
	{
		cout << "Base3::Test1()" << endl;
	}
	virtual void Test2()
	{
		cout << "Base3::Test2()" << endl;
	}
	int _b;
};
void Test5()
{
	cout << sizeof(Base3) << endl;//8
}
//结论：//如果一个类中包含有虚函数，类大小会多四个字节
//如果类没有显式定义构造函数，编译器会给该类生成一个默认的构造函数，作用：将虚表指针放在对象的前四个字节里
//如果类显式定义了构造函数，编译器会对用户提供的构造函数进行改写：将虚表指针放在前4个字节里


class Base4
{
public:
	virtual void Test1()
	{
		cout << "Base4::Test1()" << endl;
	}
	virtual void Test2()
	{
		cout << "Base4::Test2()" << endl;
	}
	virtual void Test3()
	{
		cout << "Base4::Test3()" << endl;
	}
	int _b;
};
//结论：基类虚表构建过程：将虚函数按照其在类中的声明次序依次增加到虚表中
//证明：监视查看虚函数表就ok

class Derived4 :public Base4
{
public:
	virtual void Test5()
	{
		cout << "Derived::Test5()" << endl;
	}

	virtual void Test1()
	{
		cout << "Derived::Test1()" << endl;
	}

	virtual void Test3()
	{
		cout << "Derived::Test3()" << endl;
	}

	virtual void Test4()
	{
		cout << "Derived::Test4()" << endl;
	}

	int _d;
};
//子类虚表构建过程：
//1.将基类虚表中的内容拷贝一份放到子类虚表中
//2.如果派生类重写了基类某个虚函数，派生类用自己的虚函数地址替换相同偏移量地址的基类虚函数入口地址
//3.如果派生类新增加的虚函数，则按照它们的声明次序一一添加到虚表的后面

//证明：由于通过监视窗口不能直接看到派生类新增加的虚函数 
//解决方法：通过记录虚函数表的地址，在内存窗口中查看。
/*发现一共占了五个4字节空间，通过对比，发现前三个依次与基类的虚函数地址相匹配，
那么，现在就需要验证后两个地址是不是派生类新增加的虚函数的。*/
//验证方法一：创建一个类对象，通过该对象调用一次派生类新增加的虚函数，调试转到反汇编，看call指令的函数地址是否与那后两个虚函数地址匹配。
//验证法二：调用该虚函数
  //调用步骤：1.从对象前4个字节中获取表格地址vfptr
            //2.从vfptr指向的空间中获取虚函数的入口地址
            //3.可以调用该函数

#include<string>
typedef void(*PVFT)();//定义一个函数指针

void PrintTable(Base4& b,const string& information)
{
	cout << information << endl;
	PVFT* pVFT = (PVFT*)(*(int*)&b);
	while (*pVFT)
	{
		(*pVFT)();//通过函数指针调用该函数
		pVFT++;
	}
	cout << endl;
}

void Test6()
{
	Base4 b1;
	Base4 b2; //通过在内存中检测b1和b2前4个字节内容：两个对象前4个字节完全相同，所以同一个类不同对象，在底层共享一张虚表
	b1._b = 1;
	Derived4 d;
	d._d = 1;

	//验证法一：
	d.Test5();
	d.Test4();

	//验证法二：
	PrintTable(b1, "Base4 :VFT table");
	PrintTable(d, "Derived4 :VFT table");
}

/*7.2虚函数的调用原理*/
class Base5
{
public:
	virtual void Test1()
	{
		cout << "Base5::Test1()" << endl;
	}
	virtual void Test2()
	{
		cout << "Base5::Test2()" << endl;
	}
	virtual void Test3()
	{
		cout << "Base5::Test3()" << endl;
	}
	void Test4()
	{
		cout << "Base5::Test4()" << endl;
	}
	int _b;
};

class Derived5 :public Base4
{
public:
	virtual void Test1()
	{
		cout << "Derived5::Test1()" << endl;
	}
	virtual void Test2()
	{
		cout << "Derived5::Test2()" << endl;
	}
	virtual void Test3()
	{
		cout << "Derived5::Test3()" << endl;
	}
	int _d;
};

// 虚函数的调用：通过基类的指针或者引用调用虚函数
void TestVritual(Base5* pb)
{
	pb->Test1();
	pb->Test2();
	pb->Test3();
	pb->Test4();
}
void Test7()
{
	Base5 b;
	Derived5 d;
	TestVritual(&b);
	TestVritual((Base5*)&d);
}


/*7.3多继承中虚函数表的构建过程*/
//1.与单继承中派生类虚表的构建过程相同
//2.对于派生类新增加的函数，按照其声明次序增加到第一个虚表最后

//验证
#if 0
class B1
{
public:
	virtual void TestFunc1()
	{
		cout << "B1::TestFunc1()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "B1::TestFunc2()" << endl;
	}
	int _b1;
};

// 8
class B2
{
public:
	virtual void TestFunc3()
	{
		cout << "B2::TestFunc3()" << endl;
	}

	virtual void TestFunc4()
	{
		cout << "B2::TestFunc4()" << endl;
	}
	int _b2;
};

// 20   24
class D : public B1, public B2
{
public:
	virtual void TestFunc1()
	{
		cout << "D::TestFunc1()" << endl;
	}

	virtual void TestFunc4()
	{
		cout << "D::TestFunc4()" << endl;
	}

	virtual void TestFunc5()
	{
		cout << "D::TestFunc5()" << endl;
	}

	int _d;
};


typedef void(*PVFT)();

void PrintVFT1(B1& b, const string& str)
{
	cout << "D重写B1基类的虚表" << endl;
	PVFT* pVFT = (PVFT*)(*(int*)&b);
	while (*pVFT)
	{
		(*pVFT)();
		++pVFT;
	}
	cout << endl;
}

void PrintVFT2(B2& b, const string& str)
{
	cout << str << endl;
	PVFT* pVFT = (PVFT*)(*(int*)&b);
	while (*pVFT)
	{
		(*pVFT)();
		++pVFT;
	}
	cout << endl;
}

void Test8()
{
	cout << sizeof(D) << endl;

	D d;
	d._b1 = 1;
	d._b2 = 2;
	d._d = 3;

	PrintVFT1(d, "D重写B1基类的虚表");
	PrintVFT2(d, "D重写B2基类的虚表");
}
#endif

int main()
{
	cout << "Test1()" << endl;
	Test1();
	cout << endl;
	cout << "Test2()" << endl;
	Test2();
	cout << endl;
	cout << "TestDestroy()" << endl;
	TestDestroy();
	cout << endl;
	cout << "Test3()" << endl;
	Test3();
	cout << endl;
	cout << "Test4()" << endl;
	Test4();
	cout << endl;
	cout << "Test5()" << endl;
	Test5();
	cout << endl;
	cout << "Test6()" << endl;
	Test6();
	cout << endl;
	cout << "Test7()" << endl;
	Test7();
	cout << endl;

	system("pause");
	return 0;
}
