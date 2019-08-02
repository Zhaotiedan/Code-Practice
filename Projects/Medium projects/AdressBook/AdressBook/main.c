#define _CRT_SECURE_NO_WARNINGS 1

#include "AdressBook.h"

int main()
{
	volatile int quit = 0;//volatile:保持内存的可见性 不能在寄存器改变
	int select = 0;
	contact_p ct_p;
	Load(&ct_p);//内存里面已经开辟5个空间
	while (!quit)
	{
		Menu();
		scanf("%d", &select);		
		switch (select)
		{
		case 1:
			AddPerson(&ct_p);
			break;
		case 2:
			DelPerson(ct_p);
			break;
		case 3:
			ModPerson(ct_p);
			break;
		case 4:
			SearchPerson(ct_p);
			break;
		case 5:
			SortPerson(ct_p);
			break;
		case 6:
			ShowPerson(ct_p);
			break;
		case 7:
			ClearPerson(ct_p);
			break;
		case 0:
			Save(ct_p);
			printf("bye!\n");
			quit = 1;
			break;
		default:
			printf("Please Enter The Correct Number!\n");
			break;
		}
	}
	system("pause");
	return 0;
}