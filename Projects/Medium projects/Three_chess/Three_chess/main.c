#define _CRT_SECURE_NO_WARNINGS 1

#include"Three_chess.h"

int main()
{
	int input = 0;
	int quite = 0;
	char result = 'N';
		while (!quite)
		{
			Menu();
			scanf("%d", &input);
			switch (input)
			{
			case 1:
				Game();
				break;
			case 0:
				quite = 1;
				printf("bye\n");
				break;
			default:
				printf("Plese enter 1 or 0!");
				break;
			}

		}
		system("pause");
		return 0;
}