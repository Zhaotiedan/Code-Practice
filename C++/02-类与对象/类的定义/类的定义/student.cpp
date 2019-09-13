#define _CRT_SECURE_NO_WARNINGS 1

#include"student.h"

void Student2::SetStudentInfo(const char * name, const char * gender, int age)
{
	strcpy(_name, name);
	strcpy(_gender, gender);
	_age = age;
}
void Student2::showInfo()
{
	cout << _name << " " << _gender << " " << _age << endl;
}