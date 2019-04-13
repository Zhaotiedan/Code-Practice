#define _CRT_SECURE_NO_WARNINGS 1
#include"Mine.h"

int main()
{
	int select = 0;
	int quit = 0;
	while (!quit)
	{
		Menu();
		scanf("%d", &select);
		switch (select)
		{
		case1:
			Game();
			break;
		case0:
			quit = 1;
			break;
		default:
			break;
		}
	}
	return 0
}