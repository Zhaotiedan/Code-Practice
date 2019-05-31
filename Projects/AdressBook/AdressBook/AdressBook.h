#ifndef _ADRESSBOOK_H_
#define _ADRESSBOOK_H_

#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>

#define NAME_SIZE 64
#define TEL_SIZE 16
#define ADDR_SIZE 128

#define LIST_DEFAULT 2
#define INC_SIZE 1

typedef struct person//人结构体
{
	char name[NAME_SIZE];
	char sex;//'f','m'
	unsigned char age;
	char telephone[TEL_SIZE];
	char address[ADDR_SIZE];
}person_t,*person_p,**person_pp;

typedef struct contact//通讯录结构体
{
	int cap;//最大容量
	int size;//当前的数量
	person_t list[0];
}contact_t, *contact_p,**contact_pp;

void Menu();
int FindPos(contact_p ct_p, char *name);

void InitPerson(contact_pp ct_pp);
void ShowPerson(contact_p ct_p);

void AddPerson(contact_pp ct_pp);
void DelPerson(contact_p ct_p);//将最后一个人放到要删除的那个人位置，然后size--
void SearchPerson(contact_p ct_p);
void ModPerson(contact_p ct_p);
void SortPerson(contact_p ct_p);//根据姓名来排序，用q_sort

void ClearPerson(contact_p ct_p);//清空通讯录
//void DestroyContact(contact_p ct_p);//销毁通讯录


#endif
