#define _CRT_SECURE_NO_WARNINGS 1

#include"student.h"

//类有两种定义方式：
//方式1：声明和类都放在类中定义，但成员函数在类中定义可能会被当成内联函数
class Student1
{
public:
	void SetStudentInfo(const char * name, const char * gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void PrintStudentInfo()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}
	char _name[20];
	char _gender[3];
	int _age;

};

//方式2：声明放在.h头文件里，类的定义放在.cpp文件里
int main()
{
	Student1 s1;
	Student2 s2;
	s1.SetStudentInfo("Peter", "nan", 10);
	s2.SetStudentInfo("Summer", "nan", 4);
	s1.PrintStudentInfo();
	s2.showInfo();
	system("pause");
	return 0;
}