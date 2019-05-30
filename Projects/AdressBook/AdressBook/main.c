#define _CRT_SECURE_NO_WARNINGS 1

#include "AdressBook.h"

int main()
{
	contact_t *ct;
	InitAdressBook(&ct);//内存里面已经开辟5个空间

	int quit = 0;
	int select = 0;
	while (!quit)
	{
		Menu();
		sacnf("%d", &select);
		switch (select)
		{
		case 1:
			AddAdressBook(ct);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 0:
			break;
		default:
			break;
		}
	}

	DestoryAdressBook(ct);
	system("pause");
	return 0;
}