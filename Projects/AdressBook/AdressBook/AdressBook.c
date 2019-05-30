#define _CRT_SECURE_NO_WARNINGS 1
#include "AdressBook.h"

void Menu()
{
	printf("************************\n");
	printf("***1.Add       2.Del****\n");
	printf("***3.Search    4.Mod****\n");
	printf("***5.Sort      6.List***\n");
	printf("***7.Cls       0.Exit***\n");
	printf("************************\n");
	printf("Please Select:> ");
}
void InitAdressBook(contact_t **pct)//0--FALSE,1--TURE
{
	*pct = (person_pp)malloc(sizeof(contact_t) + sizeof(person_t)*DEFAULT);
	if (NULL != pct)
	{
		printf("%d:%s\n", errno, strerror(errno));
		return 0;
	}
	(*pct)->cap = DEFAULT;
	(*pct)->size = 0;
	return 1;
}

void AddAdressBook(contact_p ct)
{
	person_t p;
	printf("Please Enter Name");
	scanf("%s", p.name);
	printf("Please Enter Sex:");
	scanf("%c", &(p.sex));
	printf("Please Enter Age:");
	scanf("%d", &(p.age));
	printf("Please Enter Telphone:");
	scanf("%s", p.telephone);
	printf("Please Enter Address:");
	scanf("%s", p.address);
	ct->plist[]
}
void DestoryAdressBook(contact_p ct)
{
	free(ct);
	ct = NULL;
}