#define _CRT_SECURE_NO_WARNINGS 1

#include"Three_chess.h"

int main()
{
	int input = 0;
	int quite = 0;
	char result = 'N';
	menu();
	scanf("%d", &input);
	while (!quite)
	{
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			quite = 1;
			break;
		default:
			printf("Plese enter 1 or 0!");
			break;
		}
	}
	return 0;
}