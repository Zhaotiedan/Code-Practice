#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _MINE_H_
#define _MINE_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define ROW 12
#define COL 12
#define MINES 20
void Menu();
void Game();
int GetIndex(int start, int end);
void SetMine(char mine_board[][COL], int row, int col);
int GetMineNum(char mine_board[][COL], int i, int j);
void ShowBoard(char show_board[][COL], int row, int col);
void PlayGame(char show_board[][COL], char mine_board[][COL], int row, int col);
#endif 