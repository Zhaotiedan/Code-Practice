#ifndef _THREE_CHESS_H_
#define _THREE_CHESS_H_

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

#define ROW 3
#define COL 3

void Menu();
void Game();
void ComputerMove(char board[][COL],int row, int col);
void ShowBoard(char board[][COL],int row, int col);
char judge(char board[][COL],int row, int col);
void PlayerMove(char board[][COL],int row,int col);


#endif