#pragma once

#include<iostream>
using namespace std;
class Student2
{
public:
	void SetStudentInfo(const char * name, const char * gender, int age);
	void showInfo();
public:
	char _name[20];
	char _gender[3];
	int _age;
};
