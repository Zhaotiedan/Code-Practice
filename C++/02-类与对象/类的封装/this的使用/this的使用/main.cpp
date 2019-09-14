#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;

//this的引出
//结构体
struct Student
{
	char _name[20];
	char _gender[3];
	int _age;
	void InitStudent(Student *ps)
	{
		strcpy(ps->_name, 0);
		strcpy(ps->_gender, 0);
		ps->_age = 0;
	}
	void SetStudentInfo(Student * ps, const char * name, const char * gender, int age)
	{
		strcpy(ps->_name, name);
		strcpy(ps->_gender, gender);
		ps->_age = age;
	}
	void PrintStudent(Student *ps)
	{
		cout << ps->_name << " " << ps->_gender << " " << ps->_age << endl;
	}
};

//class
class Date
{
public:
	void Show()
	{
		cout << _year << " " << _month << " " << _day << endl;
	}
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};

//this为空的测试
class A
{
public:
	void Print()
	{
		cout << _a << endl;
	}
	void Show()
	{
		cout << "Show()" << endl;
	}
private:
	int _a;
};
int main()
{
	Student s;
	Student t;
	Student *s1=&s;
	Student *t1=&t;
	s1->SetStudentInfo(s1 ,"Tom", " nan", 12);
	t1->SetStudentInfo(t1, "Spring", "nv", 18);
	s1->PrintStudent(s1);
	t1->PrintStudent(t1);
	Date d1, d2;
	d1.SetDate(2019, 9, 14);
	d2.SetDate(2019, 9, 15);

	d1.Show();
	d2.Show();

	A *p = NULL;//p指向的为一个空对象
	p->Show();
	p->Print();//崩溃点，因为this拿到的地址为空
	p->Show();
	system("pause");
	return 0;
}
//问题：s1调用Date时，该函数如何知道应该设置s1对象，而不是设置s2对象呢？
//c++给每个成员变量增加了一个隐藏的指针参数，让这个指针指向这个对象(注意是当前调用该函数的对象)，
//所以该成员变量的操作都通过指针来访问。而这个指针参数就是this


//this指针的特性：
//1.this指针的类型：类的类型*const，是一个指向对象自己的常量指针，不能给this赋值
//2.只能在成员内部使用
//3.对象调用函数时，对象的地址作为实参传递给this
//4.this本质：是一个函数的形参，由编译器通过ecx寄存器传递，不需要自己传递
//5.修改类成员变量或 参数与成员变量名相同时，this->a=a
//6.静态函数中没有this指针，static和const不能同时修饰成员函数

//this指针的探讨：

//问题2：不是所有this都由ecx寄存器传递，比如不定参数，那么怎么判断方法的this由什么传递？
//不写函数的定义，查看报错时的函数约定，_this call

//问题3：this指针在何时被创建的？
//定义一个新对象的时候，具体哪个阶段待探究。

//问题4：this指针存放在哪里？
//this指针因编译器不同，存放位置可能有不同，可能是栈，寄存器，甚至全局变量。我觉得应该取决于this由什么东西进行传递。

//问题5：this指针可以为空吗
//可以，但看this为空是是否会访问成员变量，如果访问了，this拿到的为空地址，程序就会崩溃