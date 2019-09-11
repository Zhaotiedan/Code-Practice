#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

struct Student
{
	void SetStudentInfo(const char * name, const char * gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void PrintStudentInfo()
	{
		cout << _name << " " << _gender << " " <<_age<< endl;
	}
	char _name[20];//命名时多加一个下划线，与形参进行区别
	char _gender[3];
	int _age;
};
int main()
{
	Student s;//c只能写成struct Student s
	s.SetStudentInfo("Peter", "nan", 18);
	s.PrintStudentInfo();
	system("pause");
	return 0;
}