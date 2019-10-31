#define _CRT_SECURE_NO_WARNINGS 1

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

/*4.基类和派生类对象赋值转换*/
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

	//4.基类对象不能赋值给派生类
	//B* bp = &a;  报错
	//b = a;

	//5.基类的指针可以通过强制类型转换赋值给派生类的指针,但注意：这种情况转换时虽然可以，但是会存在越界访问的问题
	B* bp = (B*)&a;
	cout << bp->_a << endl;
}

/*5.继承中的作用域*/
//1. 在继承体系中基类和派生类都有独立的作用域。所以同名函数就不会重载
//2. 子类和父类中有同名成员，子类成员将屏蔽父类对同名成员的直接访问，这种情况叫隐藏，也叫重定义。（在子类成员函数中，可以使用 基类::基类成员 显示访问）
//3. 需要注意的是如果是成员函数的隐藏，只需要函数名相同就构成隐藏。
//4. 注意在实际中在继承体系里面最好不要定义同名的成员。

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

int main()
{
	Test();
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();

	system("pause");
	return 0;
}