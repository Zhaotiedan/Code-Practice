#define _CRT_SECURE_NO_WARNINGS 1

#include "Three_chess.h"

void Menu()
{
	printf("*****************************\n");
	printf("***** choose 1 to play ******\n");
	printf("***** choose 0 to exist *****\n");
	printf("I believe you will choose 1 !\n");
}

void ComputerMove(char board[][COL], int row, int col)
{
	while (1)
	{
		int x = rand() %row ;
		int y = rand() %col ;
		if (board[x][y]==' ')
		{
			board[x][y] = 'O';
			break;
		}
	}
}

void PlayerMove(char board[][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("Please enter your pos(x,y):> ");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x-1][y-1] == ' ')
			{
				board[x-1][y-1] = 'X';
				break;
			}
			else
				printf("This location has aready been occupied by computer! Try again!\n");
		}
		else
			printf("error!please be enter the correct choose!\n");
	}
}

void ShowBoard(char board[][COL], int row, int col)
{
	printf("  1 2 3\n");
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		printf("%d|", i+1);
		for (j = 0; j < col; j++)
		{
			printf("%c|", board[i][j]);
		}
		printf("\n");
	}
}

char Judge(char board[][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[i][0];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]&&board[0][0]!=' ')
	{
		return board[0][0];
	}
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]&&board[0][2]!= ' ')
	{
		return board[0][2];
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 'N';
			}
		}
	}
	return 'E';
}
void Game()
{
	char board [ROW][COL];
	char result = 'N';
	memset(board, ' ', sizeof(board));
	srand((unsigned long)time(NULL));
	while (1)
	{
		ComputerMove(board, ROW, COL);
		ShowBoard(board, ROW, COL);
		result = Judge(board, ROW, COL);
		if (result != 'N')
		{
			break;
		}
		PlayerMove(board, ROW, COL);
		ShowBoard(board, ROW, COL);
		result = Judge(board, ROW, COL);
		if (result != 'N')
		{
			break;
		}
	}
	switch (result)
	{
	case'X':
		printf("YOU WIN!:)恭喜\n");
		break;
	case'O':
		printf("YOU LOOSE!:(再接再厉\n");
		break;
	case'E':
		printf("平局！\n");
		break;
	default:
		break;
	}
	
}