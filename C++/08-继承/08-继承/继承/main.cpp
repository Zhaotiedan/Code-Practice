#define _CRT_SECURE_NO_WARNINGS 1



//CSDN:https://blog.csdn.net/qq_42913794/article/details/102987333
#include<iostream>
using namespace std;


/*1.继承的概念*/
//基类person
class Person
{
public:
	void Set(const char* name, int age, int acount)
	{
		_name = name;
		_age = age;
		_acount = acount;
	}
	void Print() 
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
		cout << "acourt" << _acount << endl;
	}
public:
	const char* _name;
protected:
	int _age;
private:
	int _acount;
};
class Student :public Person
{};

void Test()
{

	Person p;
	p.Set("zss", 18, 123456);
	p.Print();
	cout << "p:" << sizeof(p) << endl;

	Student s;
	// 验证：基类中的成员函数释放被子类继承？？？
	s.Set("pxy", 18, 123456);
	s.Print();
	cout << "s:" << sizeof(s) << endl;//通过打印一个student对象的大小，以验证：派生类将基类中的成员变量继承到子类中

	cout << endl;
}

/*2,继承的定义==方式*/
// 访问权限：限定该成员变量是否可以直接在类外进行调用
//2.1 public继承
// 基类中public/protected的成员在子类中权限不变  
// 基类中private的成员在子类中不可见(不能用---该成员变量确实已经继承到子类中)

//基类
class Base1
{
public:
	void Set(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}
	void Print()
	{
		cout << "_pub:" << _pub << endl;
		cout << "_pro:" << _pro << endl;
		cout << "_pri:" << _pri << endl;
	}

public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};
//派生类
class Derived1 :public Base1
{
public:
	void SetDerived(int pubD, int proD, int priD)
	{
		_pubD = pubD;
		_proD - proD;
		_priD = priD;

		_pub = 10;//public 不变
		_pro = 20;//protected 不变
		//_pri = 30;  private 报错，派生类中不能访问基类中私有的成员变量

	}
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};

void Test1()
{
	Derived1 d;
	d.SetDerived(100, 100, 100);

	d._pub = 10;//public成员可以在类外访问
	//d._pro = 20;  protected 报错 基类中的保护成员不能在除了基类和派生类的 类外访问
	cout << d._pubD << endl;
	
	cout << d._pub << endl;
	cout << "d:" << sizeof(d) << endl;
	cout << endl;
}

//2.2 protected继承
// 基类中public的成员在子类中访问权限已经变成protected
// 基类中protected的成员在子类中访问权限不变
// 基类中private的成员在子类中不可见(不能用---该成员变量确实已经继承到子类中)

//基类
class Base2
{
public:
	void Set(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}
	void Print()
	{
		cout << "_pub:" << _pub << endl;
		cout << "_pro:" << _pro << endl;
		cout << "_pri:" << _pri << endl;
	}

public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};
//派生类
class Derived2 :private Base2
{
public:
	void SetDerived(int pubD, int proD, int priD)
	{
		_pubD = pubD;
		_proD - proD;
		_priD = priD;

		_pub = 10;//public->protected 
		_pro = 20;//protected 不变 只能在派生类访问
		//_pri = 30;  private 报错，派生类中不能访问基类中私有的成员变量

	}
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};

void Test2()
{
	Derived2 d;
	d.SetDerived(10, 10, 10);
	//d._pub = 100;  public已经变成protected  
	//cout << d._pub << endl;
	cout << endl;
}

//3.private继承
// 基类中public的成员在子类中访问权限已经变成private
// 基类中protected的成员在子类中访问权限已经变成private
// 基类中private的成员在子类中不可见(不能用---该成员变量确实已经继承到子类中)

//基类
class Base3
{
public:
	void Set(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}
	void Print()
	{
		cout << "_pub:" << _pub << endl;
		cout << "_pro:" << _pro << endl;
		cout << "_pri:" << _pri << endl;
	}

public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};
//派生类
class Derived3 :private Base3
{
public:
	void SetDerived(int pubD, int proD, int priD)
	{
		_pubD = pubD;
		_proD - proD;
		_priD = priD;

		_pub = 10;//public->private 
		_pro = 20;//protected->private
		//_pri = 30;  private 报错，派生类中不能访问基类中私有的成员变量

	}
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};

void Test3()
{
	Derived3 d;
	//d._pub = 100;
	//cout << d._pub << endl;
}

/*3.stuct和class的默认继承方式*/
//class--默认private
//struct--默认public
class Base4
{
public:
	void Set(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}
	void Print()
	{
		cout << "pub:" << _pub << endl;
		cout << "pro:" << _pro << endl;
		cout << "pri:" << _pri << endl;
	}
public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};
struct Derived4 :Base4
{
public:
	void SetDerived(int pubD, int proD, int priD)
	{
		_pubD = pubD;
		_proD = proD;
		_priD = priD;

		//基类的pub和pro都能访问，所以证明是public继承或者是protected继承方式，最后通过在类外访问来判断是哪种
		_pub = 10;
		_pro = 10;
		//_pri = 10;private不能访问
	}
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};

void Test4()
{
	Derived4 d;
	d._pub = 1000;//基类的pub可以在类外访问，证明是public继承
	//d._pro = 100;报错，基类protected不能在类外访问
	cout << d._pub << endl;
}

/*4.基类和派生类对象赋值转换   前提：public继承*/ 
//4.1 派生类对象 可以赋值给 基类的对象 + 基类的指针 + 基类的引用。
//4.2 基类对象不能赋值给派生类
//4.3 基类的指针可以通过强制类型转换赋值给派生类的指针

class A
{
public:
	void Set(int a)
	{
		_a = a;
	}
public:
	int _a;
};
class B :public A
{
public:
	void Set(int a, int b)
	{
		_a = a;
		_b = b;
	}
protected:
	int _b;
};
void Test5()
{
	A a;
	a.Set(10);
	B b;
	b.Set(20, 30);
	//1.用子类对象给基类对象赋值
	a = b;
	cout << "a._a:" << a._a << endl;

	//2.给基类指针赋值
	A* ap = &b;
	cout << ap->_a<< endl;

	//3.给基类引用赋值
	A& aa = b;
	cout << aa._a << endl;

	//B* bp = &a;  报错
	//4.基类对象不能赋值给派生类
	//b = a;

	//5.基类的指针可以通过强制类型转换赋值给派生类的指针,但注意：这种情况转换时虽然可以，但是会存在越界访问的问题
	B* bp = (B*)&a;
	cout << bp->_a << endl;
}

/*5.继承中的作用域*/
//1. 在继承体系中基类和派生类都有独立的作用域。所以同名函数就不会重载
//2.同名隐藏：派生类和基类中具有相同名称的成员（成员函数和成员变量）
//3.如果使用派生类对象直接访问同名成员，则派生类会优先访问自己的成员，相当于基类的同名成员隐藏
//注意：成员变量同名---->与成员变量类型是否相同无关
//      成员函数同名---->与函数原型是否相同无关
//想要 通过派生类访问基类成员的方法：   使用时，在同名前面+基类的名称和作用域限定符


//同名隐藏
//基类
class Q
{
public:
	void Set(char q)
	{
		_q = q;
	}
//protected:
public:
	char _q;
};
//派生类
class W :public Q
{
public:
	void Set(int q, int w) 
	{
		_q = q;
	}
//protected:
public:
	int _q;
};

void Test6()
{
	cout <<"sizeof(W)"<< sizeof(W) << endl;
	W w;
	w._q = 'a';//同名隐藏，直接访问派生类的元素
	w.Q::_q = 'b';//想访问基类元素，加上命名空间即可
	cout << w._q << endl;
	cout << w.Q::_q << endl;
}

/*6.4.派生类的默认成员函数*/

//1. 派生类的构造函数会调用基类的构造函数初始化基类的那一部分成员。

//1.1如果基类的构造函数是无参或者全缺省的默认构造函数，则派生类初始化列表的位置调用或不调用都可以，如果用户没有调用，则编译器会默认调用
//1.2如果基类没有默认的构造函数(基类自定义了构造函数)，则必须在派生类构造函数的初始化列表阶段显示调用该显式构造函数
//因为显式构造函数后，编译器就找不到默认构造函数了

//验证1.1
class Base7
{
public:
	////无参
	//Base7()
	//	:_b(10)
	//	
	//{
	//	cout << "无参Base7()" << endl;
	//}

	//全缺省
	Base7(int b=100)
		:_b(b)
	{
		cout << "全缺省Base7(int b=100)" << endl;
	}
//protected:
public:
	int _b;
};

class Derived7 : public Base7
{
public:
	Derived7()
		:_d(10)
	{
		cout << "无参Derived7()" << endl;
	}	
//protected:
public:
	int _d;
};

void Test7()
{
	Base7 b;//调一次构造
	Derived7 d;//调一次基类构造，调一此自身构造
	cout << b._b << endl;
	cout << d._d << endl;
	cout << d._b << endl;
	cout << endl;
}
//验证1.2
class Base8
{
public:
	Base8(int b)
		:_b(b)
	{
		cout << "自定义Base8()" << endl;
	}
//protected:
public:
	int _b;
};

class Derived8 : public Base8
{
public:
	Derived8()
		:Base8(100)
		,_d(10)
	{
		cout << "无参Derived8()" << endl;
	}
//protected:
public:
	int _d;
};

void Test8()
{
	Base8 b(1000);
	Derived8 d;
	cout << b._b << endl;
	cout << d._d << endl;
	cout << endl;
}

//2.派生类的拷贝构造函数会调用基类的拷贝构造完成基类的拷贝初始化。

//2.1基类如果没有显示定义构造函数，则派生类也可以不用定义，即两个类都可以采用默认构造函数，前提：不涉及资源管理
//2.2基类如果显式定义了构造函数，则派生类就必须在里面初始化列表显式调用基类的构造函数


//3.赋值运算符重载：
//3.1如果基类没有显示定义派生类也可以不提供，除非派生类需要作出其他操作，再根据情况给出
//3.2如果基类显式给出了赋值运算符重载，一般派生类也要提供，而且要在其中调用基类的重载

//验证2.1
class Base9
{
public:
	Base9(int b)
		:_b(b)
	{}
	//protected:
public:
	int _b;
};
class Derived9 :public Base9
{
public:
	Derived9(int d)
		:Base9(100)
		,_d(d)
	{}

public:
	int _d;
};

void Test9()
{
	Derived9 d1(1000);
	Derived9 d2(d1);
	cout << d1._d << endl;//1000
	cout << d1._b << endl;//100
	cout << d2._d << endl;//1000
	cout << d2._b << endl;//100
	cout << endl;
}

//验证2.2  3.2
class Base10
{
public:
	Base10(int b)
		: _b(b)
	{}

	Base10(const Base10& b)
		: _b(b._b)
	{}

	Base10& operator=(const Base10& b)
	{
		if (this != &b)
		{
			_b = b._b;
		}

		return *this;
	}
public:
	int _b;
};

class Derived10 : public Base10
{
public:
	Derived10(int b, int d)
		: Base10(b)
		, _d(d)
	{}

	Derived10(const Derived10& d)
		: Base10(d)
		, _d(d._d)
	{}

	Derived10& operator=(const Derived10& d)
	{
		if (this != &d)
		{

			//*this = d;
			// 给基类部分成员赋值
			Base10::operator=(d);
			// 给派生类新增加成员赋值
			_d = d._d;
		}
		return *this;
	}
public:
	int _d;
};

void Test10()
{
	Derived10 d1(1, 2);
	Derived10 d2(d1);

	Derived10 d3(3, 4);
	d2 = d3;
	cout << d1._b << endl;
	cout << d1._d << endl;
	cout << d2._b << endl;
	cout << d2._d << endl;
	cout << d3._b << endl;
	cout << d3._d << endl;
}

//3.派生类和基类构造函数和析构函数的调用次序
class Base11
{
public:
	Base11(int b)
		:_b(b)
	{
		cout << "Base10::Base10(int)" << endl;
	}
	~Base11()
	{
		cout << "Base10::~Base10()" << endl;
	}
public:
	int _b;
};
class Derived11 :public Base11
{
public:
	Derived11(int b, int d)
		: Base11(b)
		, _d(d)
	{
		cout << "Derived::Derived(int,int)" << endl;
	}

	~Derived11()
	{
		cout << "Derived::~Derived()" << endl;
		// call Base::~Base();
	}
public:
	int _d;
};

void Test11()
{
	Derived11 d(10, 20);
}
// 1. 运行结束打印结果
	   /*
	   函数体的执行次序：先调基类构造--->派生类构造--->派生类析构--->基类析构
		  Base::Base(int)
		  Derived::Derived(int,int)
		  Derived::~Derived()
		  Base::~Base()
	   */
	   // 2. 构造和析构的调用次序
	   /*
			 构造次序：
			   派生类构造函数()
				  : 基类构造函数（）
			   {}

			   析构次序：
			   派生类析构函数()
			   {
				  // 释放派生类资源

				  // 编译器在派生类析构函数最后一条有效语句后插了一条汇编代码
				  call 基类析构函数;
			   }
	   */
int main()
{
	Test();
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();
	Test9();
	Test10();
	Test11();

	system("pause");
	return 0;
}